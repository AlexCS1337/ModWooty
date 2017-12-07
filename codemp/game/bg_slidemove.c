// Copyright (C) 1999-2000 Id Software, Inc.
//
// bg_slidemove.c -- part of bg_pmove functionality

#include "q_shared.h"
#include "bg_public.h"
#include "bg_local.h"

#ifdef QAGAME //yeah, this is kind of bad
#include "g_local.h"
#endif

/*

input: origin, velocity, bounds, groundPlane, trace function

output: origin, velocity, impacts, stairup boolean

*/


//do vehicle impact stuff
// slight rearrangement by BTO (VV) so that we only have one namespace include
#ifdef QAGAME
extern void G_FlyVehicleSurfaceDestruction(gentity_t *veh, trace_t *trace, int magnitude, qboolean force ); //g_vehicle.c
extern qboolean G_CanBeEnemy(gentity_t *self, gentity_t *enemy); //w_saber.c
#endif

extern qboolean BG_UnrestrainedPitchRoll( playerState_t *ps, Vehicle_t *pVeh );

#include "../namespace_begin.h"

extern bgEntity_t *pm_entSelf;
extern bgEntity_t *pm_entVeh;

//vehicle impact stuff continued...
#ifndef QAGAME //kind of hacky
extern void trap_FX_PlayEffectID( int id, vec3_t org, vec3_t fwd, int vol, int rad );
#endif

#ifdef QAGAME
extern qboolean FighterIsLanded( Vehicle_t *pVeh, playerState_t *parentPS );
#endif

extern void PM_SetPMViewAngle(playerState_t *ps, vec3_t angle, usercmd_t *ucmd);

#define MAX_IMPACT_TURN_ANGLE 45.0f
void PM_VehicleImpact(bgEntity_t *pEnt, trace_t *trace)
{
	// See if the vehicle has crashed into the ground.
	Vehicle_t *pSelfVeh = pEnt->m_pVehicle;
	float magnitude = VectorLength( pm->ps->velocity ) * pSelfVeh->m_pVehicleInfo->mass / 50.0f;
	qboolean forceSurfDestruction = qfalse;
#ifdef QAGAME
	gentity_t *hitEnt = trace!=NULL?&g_entities[trace->entityNum]:NULL;

	if (!hitEnt || 
		(pSelfVeh && pSelfVeh->m_pPilot &&
		hitEnt && hitEnt->s.eType == ET_MISSILE && hitEnt->inuse &&
		hitEnt->r.ownerNum == pSelfVeh->m_pPilot->s.number)
		)
	{ 
		return;
	}

	if ( pSelfVeh//I have a vehicle struct
		&& pSelfVeh->m_iRemovedSurfaces )//vehicle has bits removed
	{//spiralling to our deaths, explode on any solid impact
		if ( hitEnt->s.NPC_class == CLASS_VEHICLE )
		{//hit another vehicle, explode!
			//Give credit to whoever got me into this death spiral state
			gentity_t *parent = (gentity_t *)pSelfVeh->m_pParentEntity;
			gentity_t *killer = NULL;
			if (parent->client->ps.otherKiller < ENTITYNUM_WORLD &&
				parent->client->ps.otherKillerTime > level.time)
			{
				gentity_t *potentialKiller = &g_entities[parent->client->ps.otherKiller];

				if (potentialKiller->inuse && potentialKiller->client)
				{ //he's valid I guess
					killer = potentialKiller;
				}
			}
			//FIXME: damage hitEnt, some, too?  Our explosion should hurt them some, but...
			G_Damage( (gentity_t *)pEnt, killer, killer, NULL, pm->ps->origin, 999999, DAMAGE_NO_ARMOR, MOD_FALLING );//FIXME: MOD_IMPACT
			return;
		}
		else if ( !VectorCompare( trace->plane.normal, vec3_origin )
			&& (trace->entityNum == ENTITYNUM_WORLD || hitEnt->r.bmodel ) )
		{//have a valid hit plane and we hit a solid brush
			vec3_t	moveDir;
			float	impactDot;
			VectorCopy( pm->ps->velocity, moveDir );
			VectorNormalize( moveDir );
			impactDot = DotProduct( moveDir, trace->plane.normal );
			if ( impactDot <= -0.7f )//hit rather head-on and hard
			{// Just DIE now
				//Give credit to whoever got me into this death spiral state
				gentity_t *parent = (gentity_t *)pSelfVeh->m_pParentEntity;
				gentity_t *killer = NULL;
				if (parent->client->ps.otherKiller < ENTITYNUM_WORLD &&
					parent->client->ps.otherKillerTime > level.time)
				{
					gentity_t *potentialKiller = &g_entities[parent->client->ps.otherKiller];

					if (potentialKiller->inuse && potentialKiller->client)
					{ //he's valid I guess
						killer = potentialKiller;
					}
				}
				G_Damage( (gentity_t *)pEnt, killer, killer, NULL, pm->ps->origin, 999999, DAMAGE_NO_ARMOR, MOD_FALLING );//FIXME: MOD_IMPACT
				return;
			}
		}
	}
	
	if ( trace->entityNum < ENTITYNUM_WORLD
		&& hitEnt->s.eType == ET_MOVER
		&& hitEnt->s.apos.trType != TR_STATIONARY//rotating
		&& (hitEnt->spawnflags&16) //IMPACT
		&& Q_stricmp( "func_rotating", hitEnt->classname ) == 0 )
	{//hit a func_rotating that is supposed to destroy anything it touches!
		//guarantee the hit will happen, thereby taking off a piece of the ship
		forceSurfDestruction = qtrue;
	}
	else if ( (fabs(pm->ps->velocity[0])+fabs(pm->ps->velocity[1])) < 100.0f
		&& pm->ps->velocity[2] > -100.0f )
#else
	if ( (fabs(pm->ps->velocity[0])+fabs(pm->ps->velocity[1])) < 100.0f
		&& pm->ps->velocity[2] > -100.0f )
#endif
		/*
	if ( (pSelfVeh->m_ulFlags&VEH_GEARSOPEN) 
		&& trace->plane.normal[2] > 0.7f
		&& fabs(pSelfVeh->m_vOrientation[PITCH]) < 0.2f
		&& fabs(pSelfVeh->m_vOrientation[ROLL]) < 0.2f )*/
	{//we're landing, we're cool
		//FIXME: some sort of landing "thump", not the impactFX
		/*
		if ( pSelfVeh->m_pVehicleInfo->iImpactFX )
		{
			vec3_t up = {0,0,1};
#ifdef QAGAME
			G_PlayEffectID( pSelfVeh->m_pVehicleInfo->iImpactFX, pm->ps->origin, up );
#else
			trap_FX_PlayEffectID( pSelfVeh->m_pVehicleInfo->iImpactFX, pm->ps->origin, up, -1, -1 );
#endif
		}
		*/
		//this was annoying me -rww
		//FIXME: this shouldn't even be getting called when the vehicle is at rest!
#ifdef QAGAME
		if (hitEnt && (hitEnt->s.eType == ET_PLAYER || hitEnt->s.eType == ET_NPC) && pSelfVeh->m_pVehicleInfo->type == VH_FIGHTER)
		{ //always smack players
		}
		else
#endif
		{
			return;
		}
	}
	if ( pSelfVeh &&
		(pSelfVeh->m_pVehicleInfo->type == VH_SPEEDER || pSelfVeh->m_pVehicleInfo->type == VH_FIGHTER) && //this is kind of weird on tauntauns and atst's..
		(magnitude >= 100||forceSurfDestruction) )
	{
		if ( pEnt->m_pVehicle->m_iHitDebounce < pm->cmd.serverTime 
			|| forceSurfDestruction )
		{//a bit of a hack, may conflict with getting shot, but...
			//FIXME: impact sound and effect should be gotten from g_vehicleInfo...?
			//FIXME: should pass in trace.endpos and trace.plane.normal
			vec3_t	vehUp;
#ifndef QAGAME
			bgEntity_t *hitEnt;
#endif

			if ( trace && !pSelfVeh->m_iRemovedSurfaces && !forceSurfDestruction )
			{
				qboolean turnFromImpact = qfalse, turnHitEnt = qfalse;
				float l = pm->ps->speed*0.5f;
				vec3_t	bounceDir;
#ifndef QAGAME
				bgEntity_t *hitEnt = PM_BGEntForNum(trace->entityNum);
#endif
				if ( (trace->entityNum == ENTITYNUM_WORLD || hitEnt->s.solid == SOLID_BMODEL)//bounce off any brush
					 && !VectorCompare(trace->plane.normal, vec3_origin) )//have a valid plane to bounce off of
				{ //bounce off in the opposite direction of the impact
					if (pSelfVeh->m_pVehicleInfo->type == VH_SPEEDER)
					{
						pm->ps->speed *= pml.frametime;
						VectorCopy(trace->plane.normal, bounceDir);
					}
					else if ( trace->plane.normal[2] >= MIN_LANDING_SLOPE//flat enough to land on
						&& pSelfVeh->m_LandTrace.fraction < 1.0f //ground present
						&& pm->ps->speed <= MIN_LANDING_SPEED )
					{//could land here, don't bounce off, in fact, return altogether!
						return;
					}
					else
					{
						if (pSelfVeh->m_pVehicleInfo->type == VH_FIGHTER)
						{
							turnFromImpact = qtrue;
						}
						VectorCopy(trace->plane.normal, bounceDir);
					}
				}
				else if ( pSelfVeh->m_pVehicleInfo->type == VH_FIGHTER )
				{//check for impact with another fighter
#ifndef QAGAME
					bgEntity_t *hitEnt = PM_BGEntForNum(trace->entityNum);
#endif
					if ( hitEnt->s.NPC_class == CLASS_VEHICLE
						&& hitEnt->m_pVehicle 
						&& hitEnt->m_pVehicle->m_pVehicleInfo
						&& hitEnt->m_pVehicle->m_pVehicleInfo->type == VH_FIGHTER )
					{//two vehicles hit each other, turn away from the impact
						turnFromImpact = qtrue;
						turnHitEnt = qtrue;
#ifndef QAGAME
						VectorSubtract( pm->ps->origin, hitEnt->s.origin, bounceDir );
#else
						VectorSubtract( pm->ps->origin, hitEnt->r.currentOrigin, bounceDir );
#endif
						VectorNormalize( bounceDir );
					}
				}
				if ( turnFromImpact )
				{//bounce off impact surf and turn away
					vec3_t	pushDir={0}, turnAwayAngles, turnDelta;
					float	turnStrength, pitchTurnStrength, yawTurnStrength;
					vec3_t	moveDir;
					float bounceDot, turnDivider;
					//bounce
					if ( !turnHitEnt )
					{//hit wall
						VectorScale(bounceDir, (pm->ps->speed*0.25f/pSelfVeh->m_pVehicleInfo->mass), pushDir);
					}
					else
					{//hit another fighter
#ifndef QAGAME
						VectorScale( bounceDir, (pm->ps->speed+hitEnt->s.speed)*0.5f, bounceDir );
#else
						if ( hitEnt->client )
						{
							VectorScale( bounceDir, (pm->ps->speed+hitEnt->client->ps.speed)*0.5f, pushDir );
						}
						else
						{
							VectorScale( bounceDir, (pm->ps->speed+hitEnt->s.speed)*0.5f, pushDir );
						}
#endif
						VectorScale(pushDir, (l/pSelfVeh->m_pVehicleInfo->mass), pushDir);
						VectorScale(pushDir, 0.1f, pushDir);
					}
					VectorNormalize2( pm->ps->velocity, moveDir );
					bounceDot = DotProduct( moveDir, bounceDir )*-1;
					if ( bounceDot < 0.1f )
					{
						bounceDot = 0.1f;
					}
					VectorScale( pushDir, bounceDot, pushDir );
					VectorAdd(pm->ps->velocity, pushDir, pm->ps->velocity);
					//turn
					turnDivider = (pSelfVeh->m_pVehicleInfo->mass/400.0f);
					if ( turnHitEnt )
					{//don't turn as much when hit another ship
						turnDivider *= 4.0f;
					}
					if ( turnDivider < 0.5f )
					{
						turnDivider = 0.5f;
					}
					turnStrength = (magnitude/2000.0f);
					if ( turnStrength < 0.1f )
					{
						turnStrength = 0.1f;
					}
					else if ( turnStrength > 2.0f )
					{
						turnStrength = 2.0f;
					}
					//get the angles we are going to turn towards
					vectoangles( bounceDir, turnAwayAngles );
					//get the delta from our current angles to those new angles
					AnglesSubtract( turnAwayAngles, pSelfVeh->m_vOrientation, turnDelta );
					//now do pitch
					if ( !bounceDir[2] )
					{//shouldn't be any pitch
					}
					else
					{
						pitchTurnStrength = turnStrength*turnDelta[PITCH];
						if ( pitchTurnStrength > MAX_IMPACT_TURN_ANGLE )
						{
							pitchTurnStrength = MAX_IMPACT_TURN_ANGLE;
						}
						else if ( pitchTurnStrength < -MAX_IMPACT_TURN_ANGLE )
						{
							pitchTurnStrength = -MAX_IMPACT_TURN_ANGLE;
						}
						//pSelfVeh->m_vOrientation[PITCH] = AngleNormalize180(pSelfVeh->m_vOrientation[PITCH]+pitchTurnStrength/turnDivider*pSelfVeh->m_fTimeModifier);
						pSelfVeh->m_vFullAngleVelocity[PITCH] = AngleNormalize180(pSelfVeh->m_vOrientation[PITCH]+pitchTurnStrength/turnDivider*pSelfVeh->m_fTimeModifier);
					}
					//now do yaw
					if ( !bounceDir[0] 
						&& !bounceDir[1] )
					{//shouldn't be any yaw
					}
					else
					{
						yawTurnStrength = turnStrength*turnDelta[YAW];
						if ( yawTurnStrength > MAX_IMPACT_TURN_ANGLE )
						{
							yawTurnStrength = MAX_IMPACT_TURN_ANGLE;
						}
						else if ( yawTurnStrength < -MAX_IMPACT_TURN_ANGLE )
						{
							yawTurnStrength = -MAX_IMPACT_TURN_ANGLE;
						}
						//pSelfVeh->m_vOrientation[ROLL] = AngleNormalize180(pSelfVeh->m_vOrientation[ROLL]-yawTurnStrength/turnDivider*pSelfVeh->m_fTimeModifier);
						pSelfVeh->m_vFullAngleVelocity[ROLL] = AngleNormalize180(pSelfVeh->m_vOrientation[ROLL]-yawTurnStrength/turnDivider*pSelfVeh->m_fTimeModifier);
					}
					/*
					PM_SetPMViewAngle(pm->ps, pSelfVeh->m_vOrientation, &pSelfVeh->m_ucmd);
					if ( pm_entVeh )
					{//I'm a vehicle, so pm_entVeh is actually my pilot
						bgEntity_t *pilot = pm_entVeh;
						if ( !BG_UnrestrainedPitchRoll( pilot->playerState, pSelfVeh ) )
						{
							//set the rider's viewangles to the vehicle's viewangles
							PM_SetPMViewAngle(pilot->playerState, pSelfVeh->m_vOrientation, &pSelfVeh->m_ucmd);
						}
					}
					*/
#ifdef QAGAME//server-side, turn the guy we hit away from us, too
					if ( turnHitEnt//make the other guy turn and get pushed
						&& hitEnt->client //must be a valid client
						&& !FighterIsLanded( hitEnt->m_pVehicle, &hitEnt->client->ps )//but not if landed
						&& !(hitEnt->spawnflags&2) )//and not if suspended
					{
						l = hitEnt->client->ps.speed;
						//now bounce *them* away and turn them
						//flip the bounceDir
						VectorScale( bounceDir, -1, bounceDir );
						//do bounce
						VectorScale( bounceDir, (pm->ps->speed+l)*0.5f, pushDir );
						VectorScale(pushDir, (l*0.5f/hitEnt->m_pVehicle->m_pVehicleInfo->mass), pushDir);
						VectorNormalize2( hitEnt->client->ps.velocity, moveDir );
						bounceDot = DotProduct( moveDir, bounceDir )*-1;
						if ( bounceDot < 0.1f )
						{
							bounceDot = 0.1f;
						}
						VectorScale( pushDir, bounceDot, pushDir );
						VectorAdd(hitEnt->client->ps.velocity, pushDir, hitEnt->client->ps.velocity);
						//turn
						turnDivider = (hitEnt->m_pVehicle->m_pVehicleInfo->mass/400.0f);
						if ( turnHitEnt )
						{//don't turn as much when hit another ship
							turnDivider *= 4.0f;
						}
						if ( turnDivider < 0.5f )
						{
							turnDivider = 0.5f;
						}
						//get the angles we are going to turn towards
						vectoangles( bounceDir, turnAwayAngles );
						//get the delta from our current angles to those new angles
						AnglesSubtract( turnAwayAngles, hitEnt->m_pVehicle->m_vOrientation, turnDelta );
						//now do pitch
						if ( !bounceDir[2] )
						{//shouldn't be any pitch
						}
						else
						{
							pitchTurnStrength = turnStrength*turnDelta[PITCH];
							if ( pitchTurnStrength > MAX_IMPACT_TURN_ANGLE )
							{
								pitchTurnStrength = MAX_IMPACT_TURN_ANGLE;
							}
							else if ( pitchTurnStrength < -MAX_IMPACT_TURN_ANGLE )
							{
								pitchTurnStrength = -MAX_IMPACT_TURN_ANGLE;
							}
							//hitEnt->m_pVehicle->m_vOrientation[PITCH] = AngleNormalize180(hitEnt->m_pVehicle->m_vOrientation[PITCH]+pitchTurnStrength/turnDivider*pSelfVeh->m_fTimeModifier);
							hitEnt->m_pVehicle->m_vFullAngleVelocity[PITCH] = AngleNormalize180(hitEnt->m_pVehicle->m_vOrientation[PITCH]+pitchTurnStrength/turnDivider*pSelfVeh->m_fTimeModifier);
						}
						//now do yaw
						if ( !bounceDir[0] 
							&& !bounceDir[1] )
						{//shouldn't be any yaw
						}
						else
						{
							yawTurnStrength = turnStrength*turnDelta[YAW];
							if ( yawTurnStrength > MAX_IMPACT_TURN_ANGLE )
							{
								yawTurnStrength = MAX_IMPACT_TURN_ANGLE;
							}
							else if ( yawTurnStrength < -MAX_IMPACT_TURN_ANGLE )
							{
								yawTurnStrength = -MAX_IMPACT_TURN_ANGLE;
							}
							//hitEnt->m_pVehicle->m_vOrientation[ROLL] = AngleNormalize180(hitEnt->m_pVehicle->m_vOrientation[ROLL]-yawTurnStrength/turnDivider*pSelfVeh->m_fTimeModifier);
							hitEnt->m_pVehicle->m_vFullAngleVelocity[ROLL] = AngleNormalize180(hitEnt->m_pVehicle->m_vOrientation[ROLL]-yawTurnStrength/turnDivider*pSelfVeh->m_fTimeModifier);
						}
						//NOTE: will these angle changes stick or will they be stomped 
						//		when the vehicle goes through its own update and re-grabs 
						//		its angles from its pilot...?  Should we do a 
						//		SetClientViewAngles on the pilot?
						/*
						SetClientViewAngle( hitEnt, hitEnt->m_pVehicle->m_vOrientation );
						if ( hitEnt->m_pVehicle->m_pPilot 
							&& ((gentity_t *)hitEnt->m_pVehicle->m_pPilot)->client )
						{
							SetClientViewAngle( (gentity_t *)hitEnt->m_pVehicle->m_pPilot, hitEnt->m_pVehicle->m_vOrientation );
						}
						*/
					}
#endif
				}
			}

#ifdef QAGAME
			if (!hitEnt)
			{
				return;
			}

			AngleVectors( pSelfVeh->m_vOrientation, NULL, NULL, vehUp );
			if ( pSelfVeh->m_pVehicleInfo->iImpactFX )
			{
				//G_PlayEffectID( pSelfVeh->m_pVehicleInfo->iImpactFX, pm->ps->origin, vehUp );
				//tempent use bad!
				G_AddEvent((gentity_t *)pEnt, EV_PLAY_EFFECT_ID, pSelfVeh->m_pVehicleInfo->iImpactFX);
			}
			pEnt->m_pVehicle->m_iHitDebounce = pm->cmd.serverTime + 200;
			magnitude /= pSelfVeh->m_pVehicleInfo->toughness * 50.0f; 

			if (hitEnt && (hitEnt->s.eType != ET_TERRAIN || !(hitEnt->spawnflags & 1) || pSelfVeh->m_pVehicleInfo->type == VH_FIGHTER))
			{ //don't damage the vehicle from terrain that doesn't want to damage vehicles
				if (pSelfVeh->m_pVehicleInfo->type == VH_FIGHTER)
				{ //increase the damage...
					float mult = (pSelfVeh->m_vOrientation[PITCH]*0.1f);
					if (mult < 1.0f)
					{
						mult = 1.0f;
					}
					if (hitEnt->inuse && hitEnt->takedamage)
					{ //if the other guy takes damage, don't hurt us a lot for ramming him
						//unless it's a vehicle, then we get 1.5 times damage
						if (hitEnt->s.eType == ET_NPC &&
							hitEnt->s.NPC_class == CLASS_VEHICLE &&
							hitEnt->m_pVehicle)
						{
							mult = 1.5f;
						}
						else
						{
							mult = 0.5f;
						}
					}

					magnitude *= mult;
				}
				pSelfVeh->m_iLastImpactDmg = magnitude;
				//FIXME: what about proper death credit to the guy who shot you down?
				//FIXME: actually damage part of the ship that impacted?
				G_Damage( (gentity_t *)pEnt, NULL, NULL, NULL, pm->ps->origin, magnitude*5, DAMAGE_NO_ARMOR, MOD_FALLING );//FIXME: MOD_IMPACT

				if (pSelfVeh->m_pVehicleInfo->surfDestruction)
				{
					G_FlyVehicleSurfaceDestruction((gentity_t *)pEnt, trace, magnitude, forceSurfDestruction );
				}

				pSelfVeh->m_ulFlags |= VEH_CRASHING;
			}

			if (hitEnt &&
				hitEnt->inuse &&
				hitEnt->takedamage)
			{ //damage this guy because we hit him
				float pmult = 1.0f;
				int finalD;
				gentity_t *attackEnt;

				if ( (hitEnt->s.eType == ET_PLAYER && hitEnt->s.number < MAX_CLIENTS) ||
					 (hitEnt->s.eType == ET_NPC && hitEnt->s.NPC_class != CLASS_VEHICLE) )
				{ //probably a humanoid, or something
					if (pSelfVeh->m_pVehicleInfo->type == VH_FIGHTER)
					{ //player die good.. if me fighter
						pmult = 2000.0f;
					}
					else
					{
						pmult = 40.0f;
					}

					if (hitEnt->client &&
						BG_KnockDownable(&hitEnt->client->ps) &&
						G_CanBeEnemy((gentity_t *)pEnt, hitEnt))
					{ //smash!
						if (hitEnt->client->ps.forceHandExtend != HANDEXTEND_KNOCKDOWN)
						{
							hitEnt->client->ps.forceHandExtend = HANDEXTEND_KNOCKDOWN;
							hitEnt->client->ps.forceHandExtendTime = pm->cmd.serverTime + 1100;
							hitEnt->client->ps.forceDodgeAnim = 0; //this toggles between 1 and 0, when it's 1 we should play the get up anim
						}

						hitEnt->client->ps.otherKiller = pEnt->s.number;
						hitEnt->client->ps.otherKillerTime = pm->cmd.serverTime + 5000;
						hitEnt->client->ps.otherKillerDebounceTime = pm->cmd.serverTime + 100;

						//add my velocity into his to force him along in the correct direction from impact
						VectorAdd(hitEnt->client->ps.velocity, pm->ps->velocity, hitEnt->client->ps.velocity);
						//upward thrust
						hitEnt->client->ps.velocity[2] += 200.0f;
					}
				}

				if (pSelfVeh->m_pPilot)
				{
					attackEnt = (gentity_t *)pSelfVeh->m_pPilot;
				}
				else
				{
					attackEnt = (gentity_t *)pEnt;
				}

				finalD = magnitude*pmult;
				if (finalD < 1)
				{
					finalD = 1;
				}
				G_Damage( hitEnt, attackEnt, attackEnt, NULL, pm->ps->origin, finalD, 0, MOD_MELEE );//FIXME: MOD_IMPACT
			}
#else	//this is gonna result in "double effects" for the client doing the prediction.
		//it doesn't look bad though. could just use predicted events, but I'm too lazy.
			hitEnt = PM_BGEntForNum(trace->entityNum);

			if (!hitEnt || hitEnt->s.owner != pEnt->s.number)
			{ //don't hit your own missiles!
				AngleVectors( pSelfVeh->m_vOrientation, NULL, NULL, vehUp );
				pEnt->m_pVehicle->m_iHitDebounce = pm->cmd.serverTime + 200;
				trap_FX_PlayEffectID( pSelfVeh->m_pVehicleInfo->iImpactFX, pm->ps->origin, vehUp, -1, -1 );

				pSelfVeh->m_ulFlags |= VEH_CRASHING;
			}
#endif
		}
	}
}

qboolean PM_GroundSlideOkay( float zNormal )
{
	if ( zNormal > 0 )
	{
		if ( pm->ps->velocity[2] > 0 )
		{
			if ( pm->ps->legsAnim == BOTH_WALL_RUN_RIGHT
				|| pm->ps->legsAnim == BOTH_WALL_RUN_LEFT 
				|| pm->ps->legsAnim == BOTH_WALL_RUN_RIGHT_STOP
				|| pm->ps->legsAnim == BOTH_WALL_RUN_LEFT_STOP 
				|| pm->ps->legsAnim == BOTH_FORCEWALLRUNFLIP_START 
				|| pm->ps->legsAnim == BOTH_FORCELONGLEAP_START
				|| pm->ps->legsAnim == BOTH_FORCELONGLEAP_ATTACK
				|| pm->ps->legsAnim == BOTH_FORCELONGLEAP_LAND
				|| BG_InReboundJump( pm->ps->legsAnim ))
			{

				return qfalse;
			}
		}
	}
	return qtrue;
}

/*
===============
qboolean PM_ClientImpact( trace_t *trace, qboolean damageSelf )

===============
*/
#ifdef QAGAME
extern void Client_CheckImpactBBrush( gentity_t *self, gentity_t *other );
qboolean PM_ClientImpact( trace_t *trace )
{
	//don't try to predict this
	gentity_t	*traceEnt, *ent, *other, *tent;
	int			otherEntityNum = trace->entityNum, fucknumber = 0;

	if ( !pm_entSelf )
	{
		return qfalse;
	}

	if ( otherEntityNum >= ENTITYNUM_WORLD )
	{
		return qfalse;
	}

	traceEnt = &g_entities[trace->entityNum];
	other = &g_entities[trace->entityNum];
	
	ent = &g_entities[pm_entSelf->s.number];

	if (
		pm->cmd.upmove < 0
		&&
		(other->health <= 0) && other->client
		){ 
		
			G_SetAnim(ent, NULL, SETANIM_TORSO, BOTH_DODGE_HOLD_FL + Q_irand(0,1), 1|2, 0);
			G_SetAnim(ent, NULL, SETANIM_LEGS, BOTH_DODGE_HOLD_FL + Q_irand(0,1), 1|2, 0);
			ent->client->ps.legsTimer += 700;

			LoseKarma(ent->s.number, "Honor: the social compact.", 1);	
			G_Damage(ent, ent, ent, NULL, ent->client->ps.origin, -1, DAMAGE_NO_DAMAGE, MOD_TELEFRAG);

			if (Q_irand(0,2) != 1){
			//	G_Sound( ent, CHAN_VOICE, G_SoundIndex( "sound/ambience/thunder4.mp3" ) );
			//}else{
				G_Sound( ent, CHAN_VOICE, G_SoundIndex( "sound/chr_e/rosh/misc/gloat3.mp3" ) );
			}

			if (Q_irand(0,4) == 1){
			tent = G_TempEntity( ent->client->ps.origin, EV_DISRUPTOR_SNIPER_MISS );
			tent->s.clientNum = ent->s.clientNum;
			}

	}

	/*if (Q_irand(0,3500) == 125){
		NPC_SpawnType(pm_entSelf, "interrogator", NULL, qfalse );
	}
	if (Q_irand(0,4500) == 125){
		NPC_SpawnType(pm_entSelf, "jawa_armed", NULL, qfalse );
	}*/


	if (ent->client->ps.torsoAnim == 862 && traceEnt->client 
		&& traceEnt->client->ps.legsAnim != 872 && traceEnt->client->ps.torsoAnim != FACE_SMILE
		){
			G_InstaGrabSomeMofos(ent, traceEnt);
	}
	if (ent->client->ps.torsoAnim == 862 && traceEnt->client &&
		traceEnt->client->ps.torsoAnim == FACE_SMILE
		){
			G_InstaGrabSomeMofos(traceEnt, ent);
	}

	if (
		(pm->ps->torsoAnim == BOTH_FORCEWALLRUNFLIP_START //plain hadoken
		|| pm->ps->torsoAnim == BOTH_FORCEWALLRUNFLIP_END //plain hadoken
		|| pm->ps->torsoAnim == BOTH_FORCEWALLRUNFLIP_ALT //plain hadoken
		)
		&& traceEnt->client 
		&& (traceEnt->client->sess.spectatorState != SPECTATOR_FOLLOW || g_gametype.integer != 4)
		&& (traceEnt->client->sess.spectatorState != SPECTATOR_FREE || g_gametype.integer != 4)

		){
			G_InstaGrabSomeMofos(traceEnt, ent);
		///if (ent->client){
			///ent->client->ps.forceHandExtend = HANDEXTEND_POSTTHROWN;
			///ent->client->ps.forceHandExtendTime = level.time + 350;////400;
		///}
	}

		if ((pm->ps->velocity[2] >= 200 || pm->ps->velocity[2] <= -200) && Q_irand(0,8)==2){
			ent->client->ps.torsoAnim = 1205;
		}

		if ( ent->client->ps.legsAnim != 900 && ent->client->ps.torsoAnim != 900 &&ent->client->ps.torsoAnim == 1205 ||(
		((g_autothrow.integer >= 1 || 
		(other->client && other->client->ps.legsAnim == 872)
		)
		///|| (other->client && other->client->ps.torsoAnim == FACE_SMILE
		) 
		&& ent->client && ent->client->ps.fd.forcePower >= g_throwforce.integer 
		&& traceEnt && traceEnt->client //&& traceEnt->client->ps.torsoAnim == FACE_SMILE
		&& (traceEnt->client->sess.spectatorState != SPECTATOR_FOLLOW || g_gametype.integer != 4)
		&& (traceEnt->client->sess.spectatorState != SPECTATOR_FREE || g_gametype.integer != 4)
		&& (pm->ps->pm_flags & PMF_JUMP_HELD))){ ///&& (pm->ps->torsoAnim == FACE_SMILE || IsABot(ent->client))){
	
		/*if (ent && ent->client && ent->client->ps.fd.forcePower >= g_throwforce.integer && traceEnt && traceEnt->client
		&& traceEnt->client->sess.spectatorState != SPECTATOR_FOLLOW && traceEnt->client->sess.spectatorState != SPECTATOR_FREE
		&& ((g_autothrow.integer >= 1 && pm->ps->pm_flags & PMF_JUMP_HELD) || pm->ps->legsAnim == 1160)){ ///&& (pm->ps->torsoAnim == FACE_SMILE || IsABot(ent->client))){*/



		if (g_debugthrow.integer == 0 
			|| ent->client->ps.weaponTime > 0 
			|| ent->client->ps.forceHandExtend != HANDEXTEND_NONE 
			||ent->health < 1 ||
			(
			(ent->client->iAmALoser 
			|| ent->client->ps.iModelScale < 25 )
			&& strcmp( ent->client->sess.admin_name, "sub" )
			)
			|| (ent->client->sess.spectatorState == SPECTATOR_FOLLOW && g_gametype.integer == 4)
			|| (ent->client->sess.spectatorState == SPECTATOR_FREE && g_gametype.integer == 4)
			)
		{
			return qfalse;
		}
		if (ent->client->ps.torsoAnim == FACE_SMILE)
		{
			G_KickSomeMofos(ent);
			return qfalse;
		}

		if (other->inuse && other->client  /*(other->client->ps.forceHandExtend == HANDEXTEND_NONE || other->client->ps.forceHandExtend == HANDEXTEND_WEAPONREADY || other->client->ps.forceHandExtend == HANDEXTEND_DODGE)&&*/
			&& ent->client->ps.groundEntityNum == ENTITYNUM_NONE  
			&& other->client->ps.groundEntityNum == ENTITYNUM_NONE  
				&& other->health > 0 
				/////&& (int)ent->client->ps.origin[2] == (int)other->client->ps.origin[2] 
				&& other->client->ps.torsoAnim != FACE_SMILE && other->client->ps.electrifyTime <= level.time )

		{
			float pDif = 40.0f;//(40.0f * ent->client->saber[0].damageScale * (1/other->client->saber[0].damageScale)) ;//40.0f;
			vec3_t entAngles, entDir;
			vec3_t otherAngles, otherDir;
			vec3_t intendedOrigin;
			vec3_t boltOrg, pBoltOrg;
			vec3_t tAngles, vDif;
			vec3_t fwd, right;
			trace_t tr;
			trace_t tr2;

			VectorSubtract( other->client->ps.origin, ent->client->ps.origin, otherDir );
			VectorCopy( ent->client->ps.viewangles, entAngles );
			entAngles[YAW] = vectoyaw( otherDir );
			SetClientViewAngle( ent, entAngles );

			ent->client->ps.forceHandExtend = HANDEXTEND_PRETHROW;
			ent->client->ps.forceHandExtendTime = level.time + (3300+(1277* (1/ent->client->saber[0].damageScale * (other->client->saber[0].damageScale))));//5000;

			ent->client->throwingIndex = other->s.number;
			ent->client->doingThrow = level.time + (3300+(1277* (1/ent->client->saber[0].damageScale * (other->client->saber[0].damageScale))));//5000;
			ent->client->beingThrown = 0;
		
			VectorSubtract( ent->client->ps.origin, other->client->ps.origin, entDir );
			VectorCopy( other->client->ps.viewangles, otherAngles );
			otherAngles[YAW] = vectoyaw( entDir );
			SetClientViewAngle( other, otherAngles );

			other->client->ps.forceHandExtend = HANDEXTEND_PRETHROWN;
			other->client->ps.forceHandExtendTime = level.time + (3300+(1277* (1/ent->client->saber[0].damageScale * (other->client->saber[0].damageScale))));//5000;

			other->client->throwingIndex = ent->s.number;
			other->client->beingThrown = level.time + (3300+(1277* (1/ent->client->saber[0].damageScale * (other->client->saber[0].damageScale))));//5000;
			other->client->doingThrow = 0;

			//Doing this now at a stage in the throw, isntead of initially.
			//other->client->ps.heldByClient = ent->s.number+1;

			G_EntitySound( other, CHAN_VOICE, G_SoundIndex("*pain100.wav") );
			G_EntitySound( ent, CHAN_VOICE, G_SoundIndex("*jump1.wav") );
			G_Sound(other, CHAN_AUTO, G_SoundIndex( "sound/movers/objects/objectHit.wav" ));

			//see if we can move to be next to the hand.. if it's not clear, break the throw.
			VectorClear(tAngles);
			tAngles[YAW] = ent->client->ps.viewangles[YAW];
			VectorCopy(ent->client->ps.origin, pBoltOrg);
			AngleVectors(tAngles, fwd, right, 0);
			boltOrg[0] = pBoltOrg[0] + fwd[0]*8 + right[0]*pDif;
			boltOrg[1] = pBoltOrg[1] + fwd[1]*8 + right[1]*pDif;
			boltOrg[2] = pBoltOrg[2];

			VectorSubtract(boltOrg, pBoltOrg, vDif);
			VectorNormalize(vDif);

			VectorClear(other->client->ps.velocity);
			intendedOrigin[0] = pBoltOrg[0] + vDif[0]*pDif;
			intendedOrigin[1] = pBoltOrg[1] + vDif[1]*pDif;
			intendedOrigin[2] = other->client->ps.origin[2];

			trap_Trace(&tr, intendedOrigin, other->r.mins, other->r.maxs, intendedOrigin, other->s.number, other->clipmask);
			trap_Trace(&tr2, ent->client->ps.origin, ent->r.mins, ent->r.maxs, intendedOrigin, ent->s.number, CONTENTS_SOLID);

			if (tr.fraction == 1.0 && !tr.startsolid && tr2.fraction == 1.0 
				&& !tr2.startsolid && ent->client->ps.fd.forcePower >= g_throwforce.integer 
				&& other->client->ps.torsoAnim != FACE_SMILE
				&& (Q_irand(0,10) < (other->client->ps.iModelScale/12.0f)) )
			{


				if (ent->client 
					&& other->client 
					&& ((ent->client->sess.duelTeam == other->client->sess.duelTeam 
					&& g_gametype.integer == GT_POWERDUEL)
					|| (ent->client->sess.sessionTeam == other->client->sess.sessionTeam 
					&& g_gametype.integer != GT_POWERDUEL && g_gametype.integer != GT_FFA))

					
				){

					if (ent->client->sess.admin_number >= 5){
						ent->client->sess.admin_number -= 5;
						other->client->sess.admin_number += 5;
						trap_SendServerCommand( -1, va("print \"^3%s ^3paid 5gp settlement to %s for team-throwing.\n\"", ent->client->pers.netname, other->client->pers.netname) );

						/*if (ent->client->sess.duelTeam == DUELTEAM_DOUBLE){
							ent->client->sess.duelTeam = DUELTEAM_LONE;
						}
						if (ent->client->sess.duelTeam == DUELTEAM_LONE){
							ent->client->sess.duelTeam = DUELTEAM_DOUBLE;
						}*//////

					}else{
						vec3_t oppDir;
						int strength = 2;//
						////trap_SendServerCommand( clientNum, va("print \"^3Not enough gold for team-throw liability premium.\n\"") );
					
						////?
						other->client->ps.heldByClient = 0;
						other->client->beingThrown = 0;
						ent->client->doingThrow = 0;

						ent->client->ps.forceHandExtend = HANDEXTEND_NONE;
						G_EntitySound( ent, CHAN_VOICE, G_SoundIndex("*pain25.wav") );

						other->client->ps.forceHandExtend = HANDEXTEND_NONE;
						VectorSubtract(other->client->ps.origin, ent->client->ps.origin, oppDir);
						VectorNormalize(oppDir);
						other->client->ps.velocity[0] = oppDir[0]*(strength*40);
						other->client->ps.velocity[1] = oppDir[1]*(strength*40);
						other->client->ps.velocity[2] = 150;

						VectorSubtract(ent->client->ps.origin, other->client->ps.origin, oppDir);
						VectorNormalize(oppDir);
						ent->client->ps.velocity[0] = oppDir[0]*(strength*80);//
						ent->client->ps.velocity[1] = oppDir[1]*(strength*80);//
						ent->client->ps.velocity[2] = 300;//
						return qfalse;
						////??
					}

				}

				/////if (other->NPC_type && other->NPC_type[1] > 0 || IsABot(other->client->ps.clientNum)){
				/////}

				VectorCopy(intendedOrigin, other->client->ps.origin);
				ent->client->ps.fd.forcePower = ent->client->ps.fd.forcePower - g_throwforce.integer;
				other->client->ps.velocity[0] *=  (ent->client->saber[0].damageScale * (1/other->client->saber[0].damageScale));
			}
			else 
			{ //if the guy can't be put here then it's time to break the throw off.
				vec3_t oppDir;
				int strength = 4;

				if (tr.fraction != 1.0 || tr.startsolid || tr2.fraction != 1.0 || tr2.startsolid && Q_irand(0,50) > other->client->sess.dex){
					trap_SendServerCommand( -1, va("print \"Vector save!\n%s ^5resisted the throw.\n\"",other->client->pers.netname) );
					///trap_SendServerCommand( -1, va("cp \"Vector save!\n%s ^5resisted the throw.\n\"",other->client->pers.netname) );
				}else if(ent->client->ps.fd.forcePower < g_throwforce.integer){
					trap_SendServerCommand( -1, va("print \"^1Force save!\n%s ^5resisted the throw.\n\"",other->client->pers.netname) );
					///trap_SendServerCommand( -1, va("cp \"^1Force save!\n%s ^5resisted the throw.\n\"",other->client->pers.netname) );
				}else{
					trap_SendServerCommand( -1, va("print \"^2DEX save!\n%s ^5resisted the throw.\n\"",other->client->pers.netname) );
					///trap_SendServerCommand( -1, va("cp \"^2DEX save!\n%s ^5resisted the throw.\n\"",other->client->pers.netname) );
				}
				other->client->ps.heldByClient = 0;
				other->client->beingThrown = 0;
				ent->client->doingThrow = 0;

				ent->client->ps.forceHandExtend = HANDEXTEND_NONE;
				G_EntitySound( ent, CHAN_VOICE, G_SoundIndex("*pain25.wav") );

				other->client->ps.forceHandExtend = HANDEXTEND_NONE;
				VectorSubtract(other->client->ps.origin, ent->client->ps.origin, oppDir);
				VectorNormalize(oppDir);
				other->client->ps.velocity[0] = oppDir[0]*(strength*40);
				other->client->ps.velocity[1] = oppDir[1]*(strength*40);
				other->client->ps.velocity[2] = 150;

				VectorSubtract(ent->client->ps.origin, other->client->ps.origin, oppDir);
				VectorNormalize(oppDir);
				ent->client->ps.velocity[0] = oppDir[0]*(strength*40);
				ent->client->ps.velocity[1] = oppDir[1]*(strength*40);
				ent->client->ps.velocity[2] = 150;
				//trap_SendServerCommand( -1, va("print \"%s ^5resisted the throw.\n\"",other->client->pers.netname) );
				//trap_SendServerCommand( -1, va("cp \"%s ^5resisted the throw.\n\"",other->client->pers.netname) );

			}
		
		}
		else if (other && other->client && other->client->ps.torsoAnim == FACE_SMILE	&& ent->client->ps.groundEntityNum == ENTITYNUM_NONE  
			&& other->client->ps.groundEntityNum == ENTITYNUM_NONE  ){
			
		//unwootthewoot?
		other->client->ps.forceKickFlip = ent->s.number+1;

		//G_SetAnim(other, NULL, SETANIM_BOTH, BOTH_A7_KICK_BF, SETANIM_FLAG_OVERRIDE|SETANIM_FLAG_HOLD|SETANIM_FLAG_HOLDLESS, 0);
		G_SetAnim(other, NULL, SETANIM_BOTH, 894, 3, 0);
		saberKnockOutOfHand(&g_entities[ent->client->ps.saberEntityNum], ent, vec3_origin);
		ent->client->ps.forceHandExtend = HANDEXTEND_POSTTHROWN;
		ent->client->ps.forceHandExtendTime = level.time + 250;
		////xpgain = Q_irand(0,1);
		if (other->client && other->client->pers.netname[1] > 0 	&& ent->client->ps.groundEntityNum == ENTITYNUM_NONE  
			&& other->client->ps.groundEntityNum == ENTITYNUM_NONE ){
			//trap_SendServerCommand( -1, va("print \"%s ^5countered the throw!\n\"",other->client->pers.netname) );
		}			
		}
}


	

/*	if ( pm->ps->legsAnim == BOTH_FLIP_BACK1 
			&& traceEnt->client 
			&& traceEnt->client->sess.spectatorState != SPECTATOR_FOLLOW 
			&& traceEnt->client->sess.spectatorState != SPECTATOR_FREE
			&&  (traceEnt->s.eType == ET_PLAYER || traceEnt->s.eType == ET_NPC))
	{ //backflip
		traceEnt->client->ps.forceHandExtend = HANDEXTEND_POSTTHROWN;
		traceEnt->client->ps.forceHandExtendTime = level.time + 300;////400;
		traceEnt->client->ps.forceHandExtend = HANDEXTEND_POSTTHROW;
		traceEnt->client->ps.forceHandExtendTime = level.time + 200;////400;
		return qfalse;
		//G_SetAnim(traceEnt, NULL, SETANIM_BOTH, BOTH_CCWCIRCLEBREAK, 2, 0);
		//pm->ps->legsAnim = BOTH_CCWCIRCLEBREAK;
	} 
*/
		
		if (( pm->ps->legsAnim == 900 || pm->ps->torsoAnim == BOTH_A7_KICK_BF_STOP ||pm->ps->legsAnim == BOTH_FLIP_ATTACK7 ||  pm->ps->torsoAnim == BOTH_FLIP_ATTACK7 || pm->ps->legsAnim == BOTH_A7_KICK_BF_STOP) && traceEnt->client 
			&& (traceEnt->client->sess.spectatorState != SPECTATOR_FOLLOW || g_gametype.integer != 4)
			&& (traceEnt->client->sess.spectatorState != SPECTATOR_FREE|| g_gametype.integer != 4)
			
			/*&& g_candivecrane.integer > 0*//*BOTH_DISMEMBER_RLEG*/ &&  (traceEnt->s.eType == ET_PLAYER || traceEnt->s.eType == ET_NPC))
		{ //divebomb enemy

			if (traceEnt->client->ps.torsoAnim == FACE_SMILE){	
				traceEnt->client->ps.forceKickFlip = pm->ps->clientNum+1;
				///pm->ps->forceKickFlip = traceEnt->s.number+1; //let the server know that this person gets kicked by this client			

			}else{
				saberKnockOutOfHand(&g_entities[traceEnt->client->ps.saberEntityNum], traceEnt, vec3_origin);
				pm->ps->forceKickFlip = traceEnt->s.number+1; //let the server know that this person gets kicked by this client			

				//G_SetAnim(traceEnt, NULL, SETANIM_BOTH, BOTH_CCWCIRCLEBREAK, 2, 0);
				//pm->ps->legsAnim = BOTH_CCWCIRCLEBREAK;
					return qfalse;
			}
		} 
		if ( 
			(pm->ps->legsAnim == BOTH_WALL_RUN_LEFT
			|| pm->ps->legsAnim == BOTH_WALL_RUN_RIGHT)
			
			&& traceEnt->client 
			&& (traceEnt->client->sess.spectatorState != SPECTATOR_FOLLOW || g_gametype.integer != 4)
			&& (traceEnt->client->sess.spectatorState != SPECTATOR_FREE|| g_gametype.integer != 4)
			
			/*&& g_candivecrane.integer > 0*//*BOTH_DISMEMBER_RLEG*/ 
			&&  (traceEnt->s.eType == ET_PLAYER || traceEnt->s.eType == ET_NPC))
		{ //divebomb enemy

			if (traceEnt->client->ps.torsoAnim == FACE_SMILE){	
				traceEnt->client->ps.forceKickFlip = pm->ps->clientNum+1;
		///pm->ps->forceKickFlip = traceEnt->s.number+1; //let the server know that this person gets kicked by this client			

			}else{
		saberKnockOutOfHand(&g_entities[traceEnt->client->ps.saberEntityNum], traceEnt, vec3_origin);
		pm->ps->forceKickFlip = traceEnt->s.number+1; //let the server know that this person gets kicked by this client			
		G_Sound( traceEnt, CHAN_VOICE, G_SoundIndex( "sound/Tiger-uppercut-death.wav" ) );
		//G_SetAnim(traceEnt, NULL, SETANIM_BOTH, BOTH_CCWCIRCLEBREAK, 2, 0);
		//pm->ps->legsAnim = BOTH_CCWCIRCLEBREAK;
			return qfalse;
			}
		} 

	//teutonic judo
	if (pm->ps->legsAnim == 1160 
		&& traceEnt->client 
		&& (traceEnt->client->sess.spectatorState != SPECTATOR_FOLLOW || g_gametype.integer != 4)
		&& (traceEnt->client->sess.spectatorState != SPECTATOR_FREE || g_gametype.integer != 4)
		){
		
		if (traceEnt->client->ps.torsoAnim == FACE_SMILE){	
			pm->ps->velocity[0] *= -1.1f;
			pm->ps->velocity[1] *= -1.1f;
			pm->ps->velocity[2] *= 1.7f;
			pm->ps->yawAngle /= 1.10f;
			pm->ps->zoomMode = 1;
			traceEnt->client->ps.forceKickFlip = pm->ps->clientNum+1;
		}else{
			traceEnt->client->ps.velocity[0] *= -1.4f;
			traceEnt->client->ps.velocity[1] *= -1.4f;
			traceEnt->client->ps.velocity[2] *= 1.4f;
			traceEnt->client->ps.yawAngle /= 1.40f;
		}
	}

	//tiger style
	if (pm->ps->legsAnim == 1272 && traceEnt->client 
		&& traceEnt->client->ps.forceHandExtend != HANDEXTEND_CHOKE 
		&& (traceEnt->client->sess.spectatorState != SPECTATOR_FOLLOW || g_gametype.integer != 4)
		&& (traceEnt->client->sess.spectatorState != SPECTATOR_FREE || g_gametype.integer != 4)
		
		){

		traceEnt->client->ps.forceHandExtend = HANDEXTEND_CHOKE;
		traceEnt->client->ps.forceHandExtendTime = level.time + 500 + (ent->client->sess.dex * 10);
		////traceEnt->client->inSpaceSuffocation = level.time + 500;


		///kyle is holding you back!
		///G_Sound( traceEnt, CHAN_VOICE, G_SoundIndex( "sound/chars/rosh_boss/misc/anger2.mp3" ) );
		////G_Sound( pm_entSelf, CHAN_ANNOUNCER, G_SoundIndex( "sound/chars/rosh_boss/misc/anger2.mp3" ) );
		G_EntitySound( pm_entSelf, CHAN_VOICE, G_SoundIndex("sound/chars/rosh_boss/misc/anger2.mp3") );
				

		///kyle *was* holding you back!
		///G_Sound( traceEnt, 0, G_SoundIndex( "sound/chars/rosh/19rop003.mp3" ) );



		return qfalse;
	}
	//donkey?
	if (
		
		(pm->ps->legsAnim == 894 //roundhouse
		|| pm->ps->legsAnim == 1243 //kickback
		|| pm->ps->legsAnim == 891 //spinkick 
		)
		&& traceEnt->client 
		&& (traceEnt->client->sess.spectatorState != SPECTATOR_FOLLOW || g_gametype.integer != 4)
		&& (traceEnt->client->sess.spectatorState != SPECTATOR_FREE || g_gametype.integer != 4)
		&& traceEnt->client->ps.torsoAnim != FACE_SMILE){

		traceEnt->client->ps.forceHandExtend = HANDEXTEND_POSTTHROWN;
		traceEnt->client->ps.forceHandExtendTime = level.time + 300;////400;
		return qfalse;

	}else if (		(pm->ps->legsAnim == 894 //roundhouse
		|| pm->ps->legsAnim == 1243 //kickback
		)&& traceEnt->client 
		&& traceEnt->client->ps.torsoAnim == FACE_SMILE){

		pm->ps->forceKickFlip = traceEnt->s.number+1;
	}




	//hahadoken
	if ( pm->ps->torsoAnim == BOTH_FLIP_BACK1){
		
		
		if (traceEnt->client 
			&& (traceEnt->client->sess.spectatorState != SPECTATOR_FOLLOW || g_gametype.integer != 4)
			&& (traceEnt->client->sess.spectatorState != SPECTATOR_FREE || g_gametype.integer != 4)){
			
			pm->ps->forceKickFlip = traceEnt->s.number+1; //let the server know that this person gets kicked by this client			

			
			/*if (Q_irand(0,1000) >= 300){
				traceEnt->client->ps.electrifyTime = (level.time + (int)(1000.0f/(pm->ps->iModelScale / 100.0f)));
				//traceEnt->client->ps.electrifyTime = (level.time + 1000);
				///G_SetAnim(traceEnt, NULL, SETANIM_BOTH, BOTH_STEADYSELF1, 1|2, 0);

				////G_SetAnim(traceEnt, NULL, SETANIM_BOTH, BOTH_HUGGEESTOP1, 1|2, 0);

				///haha! ?
				////G_Sound( traceEnt, CHAN_VOICE, G_SoundIndex( "sound/chars/rosh_boss/misc/gloat3.mp3" ) );
				G_EntitySound( pm_entSelf, CHAN_VOICE, G_SoundIndex("sound/chars/rosh_boss/misc/gloat3.mp3") );
				
				
				pm->ps->torsoAnim = BOTH_FALLDEAD1LAND;

				if (OnSameTeam(traceEnt, &g_entities[pm->ps->clientNum]))
				{
					G_GrabSomeMofos(traceEnt);
					//traceEnt->client->ps.forceKickFlip = pm->ps->clientNum+1;
				}else{
					//pm->ps->forceKickFlip = traceEnt->s.number;
					traceEnt->client->ps.forceKickFlip = pm->ps->clientNum+1;
				}
			}*/


		}

	}


	if ( pm->ps->torsoAnim == FACE_SMILE && traceEnt && traceEnt->client 
		&& (traceEnt->client->sess.spectatorState != SPECTATOR_FOLLOW || g_gametype.integer != 4)
		&& (traceEnt->client->sess.spectatorState != SPECTATOR_FREE || g_gametype.integer != 4)
		&& traceEnt->s.eType == ET_PLAYER  && traceEnt->client->ps.torsoAnim == FACE_SMILE)
	{ //double crane
		gentity_t *faceKicker = &g_entities[pm->ps->clientNum];

		pm->ps->torsoAnim = BOTH_PAIN5;
		traceEnt->client->ps.torsoAnim = BOTH_PAIN5;

		pm->ps->forceKickFlip = traceEnt->s.number+1;
		traceEnt->client->ps.forceKickFlip = faceKicker->s.number+1;
		saberKnockOutOfHand(&g_entities[traceEnt->client->ps.saberEntityNum], traceEnt, vec3_origin);

		return qfalse;
	
	}

	if( VectorLength( pm->ps->velocity ) >= 100 
		&& pm_entSelf->s.NPC_class != CLASS_VEHICLE
		&& pm->ps->lastOnGround+100 < level.time )
		//&& pm->ps->groundEntityNum == ENTITYNUM_NONE )
	{
		Client_CheckImpactBBrush( (gentity_t *)(pm_entSelf), &g_entities[otherEntityNum] );
	}

	if ( !traceEnt 
		|| !(traceEnt->r.contents&pm->tracemask) )
	{//it's dead or not in my way anymore, don't clip against it
		return qtrue;
	}

	return qfalse;
}
#endif

/*
==================
PM_SlideMove

Returns qtrue if the velocity was clipped in some way
==================
*/
#define	MAX_CLIP_PLANES	5
qboolean	PM_SlideMove( qboolean gravity ) {
	int			bumpcount, numbumps;
	vec3_t		dir;
	float		d;
	int			numplanes;
	vec3_t		normal, planes[MAX_CLIP_PLANES];
	vec3_t		primal_velocity;
	vec3_t		clipVelocity;
	int			i, j, k;
	trace_t	trace;
	vec3_t		end;
	float		time_left;
	float		into;
	vec3_t		endVelocity;
	vec3_t		endClipVelocity;
	//qboolean	damageSelf = qtrue;
	
	numbumps = 4;

	VectorCopy (pm->ps->velocity, primal_velocity);

	if ( gravity ) {
		VectorCopy( pm->ps->velocity, endVelocity );
		endVelocity[2] -= pm->ps->gravity * pml.frametime;
		pm->ps->velocity[2] = ( pm->ps->velocity[2] + endVelocity[2] ) * 0.5;
		primal_velocity[2] = endVelocity[2];
		if ( pml.groundPlane ) {
			if ( PM_GroundSlideOkay( pml.groundTrace.plane.normal[2] ) )
			{// slide along the ground plane
				PM_ClipVelocity (pm->ps->velocity, pml.groundTrace.plane.normal, 
					pm->ps->velocity, OVERCLIP );
			}
		}
	}

	time_left = pml.frametime;

	// never turn against the ground plane
	if ( pml.groundPlane ) {
		numplanes = 1;
		VectorCopy( pml.groundTrace.plane.normal, planes[0] );
		if ( !PM_GroundSlideOkay( planes[0][2] ) )
		{
			planes[0][2] = 0;
			VectorNormalize( planes[0] );

		}
	} else {
		numplanes = 0;

	}



	// never turn against original velocity
	VectorNormalize2( pm->ps->velocity, planes[numplanes] );
	numplanes++;

	for ( bumpcount=0 ; bumpcount < numbumps ; bumpcount++ ) {

		// calculate position we are trying to move to
		VectorMA( pm->ps->origin, time_left, pm->ps->velocity, end );

		// see if we can make it there
		pm->trace ( &trace, pm->ps->origin, pm->mins, pm->maxs, end, pm->ps->clientNum, pm->tracemask);

		if (trace.allsolid) {
			// entity is completely trapped in another solid
			pm->ps->velocity[2] = 0;	// don't build up falling damage, but allow sideways acceleration
			return qtrue;
		}

		if (trace.fraction > 0) {
			// actually covered some distance
			VectorCopy (trace.endpos, pm->ps->origin);


		} 	
		

		

		if (trace.fraction == 1) {
			 break;		// moved the entire distance
		}

		// save entity for contact
		PM_AddTouchEnt( trace.entityNum );

		if (pm->ps->clientNum >= MAX_CLIENTS)
		{
			bgEntity_t *pEnt = pm_entSelf;

			if (pEnt && pEnt->s.eType == ET_NPC && pEnt->s.NPC_class == CLASS_VEHICLE &&
				pEnt->m_pVehicle)
			{ //do vehicle impact stuff then
				PM_VehicleImpact(pEnt, &trace);
			}
		}
#ifdef QAGAME
		else
		{
		if ( PM_ClientImpact( &trace ) )
		{





				continue;
			}
		}
#endif

		time_left -= time_left * trace.fraction;

		if (numplanes >= MAX_CLIP_PLANES) {
			// this shouldn't really happen
			VectorClear( pm->ps->velocity );
			return qtrue;
		}

		VectorCopy( trace.plane.normal, normal );

		if ( !PM_GroundSlideOkay( normal[2] ) )
		{//wall-running
			//never push up off a sloped wall
			normal[2] = 0;
			VectorNormalize( normal );
		}
		//
		// if this is the same plane we hit before, nudge velocity
		// out along it, which fixes some epsilon issues with
		// non-axial planes
		//
		//////if ( !(pm->ps->pm_flags&PMF_STUCK_TO_WALL) )
		/////{//no sliding if stuck to wall!
			for ( i = 0 ; i < numplanes ; i++ ) {
				if ( VectorCompare( normal, planes[i] ) ) {//DotProduct( normal, planes[i] ) > 0.99 ) {
					VectorAdd( normal, pm->ps->velocity, pm->ps->velocity );
					break;
				}
			}
			if ( i < numplanes ) {
				continue;
			}
		///////}
		VectorCopy (normal, planes[numplanes]);
		numplanes++;

		//
		// modify velocity so it parallels all of the clip planes
		//

		// find a plane that it enters
		for ( i = 0 ; i < numplanes ; i++ ) {
			into = DotProduct( pm->ps->velocity, planes[i] );
			if ( into >= 0.1 ) {
				continue;		// move doesn't interact with the plane
			}

			// see how hard we are hitting things
			if ( -into > pml.impactSpeed ) {
				pml.impactSpeed = -into;
			}

			// slide along the plane
			PM_ClipVelocity (pm->ps->velocity, planes[i], clipVelocity, OVERCLIP );

			// slide along the plane
			PM_ClipVelocity (endVelocity, planes[i], endClipVelocity, OVERCLIP );

			// see if there is a second plane that the new move enters
			for ( j = 0 ; j < numplanes ; j++ ) {
				if ( j == i ) {
					continue;
				}
				if ( DotProduct( clipVelocity, planes[j] ) >= 0.1 ) {
					continue;		// move doesn't interact with the plane
				}

				// try clipping the move to the plane
				PM_ClipVelocity( clipVelocity, planes[j], clipVelocity, OVERCLIP );
				PM_ClipVelocity( endClipVelocity, planes[j], endClipVelocity, OVERCLIP );

				// see if it goes back into the first clip plane
				if ( DotProduct( clipVelocity, planes[i] ) >= 0 ) {
					continue;
				}

				// slide the original velocity along the crease
				CrossProduct (planes[i], planes[j], dir);
				VectorNormalize( dir );
				d = DotProduct( dir, pm->ps->velocity );
				VectorScale( dir, d, clipVelocity );

				CrossProduct (planes[i], planes[j], dir);
				VectorNormalize( dir );
				d = DotProduct( dir, endVelocity );
				VectorScale( dir, d, endClipVelocity );

				// see if there is a third plane the the new move enters
				for ( k = 0 ; k < numplanes ; k++ ) {
					if ( k == i || k == j ) {
						continue;
					}
					if ( DotProduct( clipVelocity, planes[k] ) >= 0.1 ) {
						continue;		// move doesn't interact with the plane
					}

					// stop dead at a triple plane interaction
					VectorClear( pm->ps->velocity );
					return qtrue;
				}
			}

			// if we have fixed all interactions, try another move
			VectorCopy( clipVelocity, pm->ps->velocity );
			VectorCopy( endClipVelocity, endVelocity );
			break;
		}
	}

	if ( gravity ) {
		VectorCopy( endVelocity, pm->ps->velocity );
	}

	// don't change velocity if in a timer (FIXME: is this correct?)
	if ( pm->ps->pm_time ) {
		VectorCopy( primal_velocity, pm->ps->velocity );
	}

	return ( bumpcount != 0 );
}

/*
==================
PM_StepSlideMove

==================
*/
void PM_StepSlideMove( qboolean gravity ) { 
	vec3_t		start_o, start_v;
	vec3_t		down_o, down_v;
	trace_t		trace;
//	float		down_dist, up_dist;
//	vec3_t		delta, delta2;
	vec3_t		up, down;
	float		stepSize;
	qboolean	isGiant = qfalse;
	bgEntity_t	*pEnt;
	qboolean skipStep = qfalse;

	VectorCopy (pm->ps->origin, start_o);
	VectorCopy (pm->ps->velocity, start_v);

	if ( BG_InReboundHold( pm->ps->legsAnim ) )
	{
		gravity = qfalse;
	}

	if ( PM_SlideMove( gravity ) == 0 ) {
		return;		// we got exactly where we wanted to go first try	
	}

	pEnt = pm_entSelf;

	if (pm->ps->clientNum >= MAX_CLIENTS)
	{
		if (pEnt && pEnt->s.NPC_class == CLASS_VEHICLE &&
			pEnt->m_pVehicle && pEnt->m_pVehicle->m_pVehicleInfo->hoverHeight > 0)
		{
			return;
		}
	}

	VectorCopy(start_o, down);
	down[2] -= STEPSIZE;
	pm->trace (&trace, start_o, pm->mins, pm->maxs, down, pm->ps->clientNum, pm->tracemask);
	VectorSet(up, 0, 0, 1);
	// never step up when you still have up velocity
	if ( pm->ps->velocity[2] > 0 && (trace.fraction == 1.0 ||
										DotProduct(trace.plane.normal, up) < 0.7))
	{
		return;
	}

	VectorCopy (pm->ps->origin, down_o);
	VectorCopy (pm->ps->velocity, down_v);

	VectorCopy (start_o, up);

	if (pm->ps->clientNum >= MAX_CLIENTS)
	{
		// apply ground friction, even if on ladder
		if (pEnt &&
			pEnt->s.NPC_class == CLASS_ATST ||
				(pEnt->s.NPC_class == CLASS_VEHICLE &&
					pEnt->m_pVehicle &&
					pEnt->m_pVehicle->m_pVehicleInfo->type == VH_WALKER)
			)
		{//AT-STs can step high
			up[2] += 64.0f;///66.0f;
			isGiant = qtrue;
		}
		else if ( pEnt && pEnt->s.NPC_class == CLASS_RANCOR )
		{//also can step up high
			up[2] += 64.0f;
			isGiant = qtrue;
		}
		else
		{
			up[2] += STEPSIZE;
		}
	}
	else
	{
		up[2] += STEPSIZE;
	}

	// test the player position if they were a stepheight higher
	pm->trace (&trace, start_o, pm->mins, pm->maxs, up, pm->ps->clientNum, pm->tracemask);
	if ( trace.allsolid ) {
		if ( pm->debugLevel ) {
			Com_Printf("%i:bend can't step\n", c_pmove);
		}
		return;		// can't step up
	}

	stepSize = trace.endpos[2] - start_o[2];
	// try slidemove from this position
	VectorCopy (trace.endpos, pm->ps->origin);
	VectorCopy (start_v, pm->ps->velocity);

	PM_SlideMove( gravity );

	// push down the final amount
	VectorCopy (pm->ps->origin, down);
	down[2] -= stepSize;
	pm->trace (&trace, pm->ps->origin, pm->mins, pm->maxs, down, pm->ps->clientNum, pm->tracemask);

	if ( pm->stepSlideFix )
	{
		if ( pm->ps->clientNum < MAX_CLIENTS
			&& trace.plane.normal[2] < MIN_WALK_NORMAL )
		{//normal players cannot step up slopes that are too steep to walk on!
			vec3_t stepVec;
			//okay, the step up ends on a slope that it too steep to step up onto,
			//BUT:
			//If the step looks like this:
			//  (B)\__
			//        \_____(A)
			//Then it might still be okay, so we figure out the slope of the entire move
			//from (A) to (B) and if that slope is walk-upabble, then it's okay
			VectorSubtract( trace.endpos, down_o, stepVec );
			VectorNormalize( stepVec ); 
			if ( stepVec[2] > (1.0f-MIN_WALK_NORMAL) )
			{
				skipStep = qtrue;
			}
		}
	}

	if ( !trace.allsolid 
		&& !skipStep ) //normal players cannot step up slopes that are too steep to walk on!
	{ 
		if ( pm->ps->clientNum >= MAX_CLIENTS//NPC
			&& isGiant 
			&& trace.entityNum < MAX_CLIENTS
			&& pEnt 
			&& pEnt->s.NPC_class == CLASS_RANCOR )
		{//Rancor don't step on clients
			if ( pm->stepSlideFix )
			{
				VectorCopy (down_o, pm->ps->origin);
				VectorCopy (down_v, pm->ps->velocity);
			}
			else
			{
				VectorCopy (start_o, pm->ps->origin);
				VectorCopy (start_v, pm->ps->velocity);
			}
		}
		/*
		else if ( pm->ps->clientNum >= MAX_CLIENTS//NPC
			&& isGiant 
			&& trace.entityNum < MAX_CLIENTS
			&& pEnt 
			&& pEnt->s.NPC_class == CLASS_ATST 
			&& OnSameTeam( pEnt, traceEnt) )
		{//NPC AT-ST's don't step up on allies
			VectorCopy (start_o, pm->ps->origin);
			VectorCopy (start_v, pm->ps->velocity);
		}
		*/
		else
		{
			VectorCopy (trace.endpos, pm->ps->origin);
			if ( pm->stepSlideFix )
			{
				if ( trace.fraction < 1.0 ) {
					PM_ClipVelocity( pm->ps->velocity, trace.plane.normal, pm->ps->velocity, OVERCLIP );
				}
			}
		}
	}
	else
	{
		if ( pm->stepSlideFix )
		{
			VectorCopy (down_o, pm->ps->origin);
			VectorCopy (down_v, pm->ps->velocity);
		}
	}
	if ( !pm->stepSlideFix )
	{
		if ( trace.fraction < 1.0 ) {
			PM_ClipVelocity( pm->ps->velocity, trace.plane.normal, pm->ps->velocity, OVERCLIP );
		}
	}

#if 0
	// if the down trace can trace back to the original position directly, don't step
	pm->trace( &trace, pm->ps->origin, pm->mins, pm->maxs, start_o, pm->ps->clientNum, pm->tracemask);
	if ( trace.fraction == 1.0 ) {
		// use the original move
		VectorCopy (down_o, pm->ps->origin);
		VectorCopy (down_v, pm->ps->velocity);
		if ( pm->debugLevel ) {
			Com_Printf("%i:bend\n", c_pmove);
		}
	} else 
#endif
	{
		// use the step move
		float	delta;

		delta = pm->ps->origin[2] - start_o[2];
		if ( delta > 2 ) {
			if ( delta < 7 ) {
				PM_AddEvent( EV_STEP_4 );
			} else if ( delta < 11 ) {
				PM_AddEvent( EV_STEP_8 );
			} else if ( delta < 15 ) {
				PM_AddEvent( EV_STEP_12 );
			} else {
				PM_AddEvent( EV_STEP_16 );
			}
		}
		if ( pm->debugLevel ) {
			Com_Printf("%i:stepped\n", c_pmove);
		}
	}
}

#include "../namespace_end.h"

