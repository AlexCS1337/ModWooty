// Copyright (C) 1999-2000 Id Software, Inc.
//
#include "g_local.h"
#include "../ghoul2/G2.h"
#include "bg_saga.h"

// g_client.c -- client functions that don't happen every frame

static vec3_t	playerMins = {-15, -15, DEFAULT_MINS_2};
static vec3_t	playerMaxs = {15, 15, DEFAULT_MAXS_2};

extern int g_siegeRespawnCheck;
extern int ReadKeys( int clientNum, char filetype[MAX_INFO_STRING]);
void WP_SaberAddG2Model( gentity_t *saberent, const char *saberModel, qhandle_t saberSkin );
void WP_SaberRemoveG2Model( gentity_t *saberent );
extern qboolean WP_SaberStyleValidForSaber( saberInfo_t *saber1, saberInfo_t *saber2, int saberHolstered, int saberAnimLevel );
extern qboolean WP_UseFirstValidSaberStyle( saberInfo_t *saber1, saberInfo_t *saber2, int saberHolstered, int *saberAnimLevel );
void WriteKeys( int clientNum, int keytype, qboolean realzero);

forcedata_t Client_Force[MAX_CLIENTS];

/*QUAKED info_player_duel (1 0 1) (-16 -16 -24) (16 16 32) initial
potential spawning position for duelists in duel.
Targets will be fired when someone spawns in on them.
"nobots" will prevent bots from using this spot.
"nohumans" will prevent non-bots from using this spot.
*/
void SP_info_player_duel( gentity_t *ent )
{
	int		i;

	G_SpawnInt( "nobots", "0", &i);
	if ( i ) {
		ent->flags |= FL_NO_BOTS;
	}
	G_SpawnInt( "nohumans", "0", &i );
	if ( i ) {
		ent->flags |= FL_NO_HUMANS;
	}
}

/*QUAKED info_player_duel1 (1 0 1) (-16 -16 -24) (16 16 32) initial
potential spawning position for lone duelists in powerduel.
Targets will be fired when someone spawns in on them.
"nobots" will prevent bots from using this spot.
"nohumans" will prevent non-bots from using this spot.
*/
void SP_info_player_duel1( gentity_t *ent )
{
	int		i;

	G_SpawnInt( "nobots", "0", &i);
	if ( i ) {
		ent->flags |= FL_NO_BOTS;
	}
	G_SpawnInt( "nohumans", "0", &i );
	if ( i ) {
		ent->flags |= FL_NO_HUMANS;
	}
}

/*QUAKED info_player_duel2 (1 0 1) (-16 -16 -24) (16 16 32) initial
potential spawning position for paired duelists in powerduel.
Targets will be fired when someone spawns in on them.
"nobots" will prevent bots from using this spot.
"nohumans" will prevent non-bots from using this spot.
*/
void SP_info_player_duel2( gentity_t *ent )
{
	int		i;

	G_SpawnInt( "nobots", "0", &i);
	if ( i ) {
		ent->flags |= FL_NO_BOTS;
	}
	G_SpawnInt( "nohumans", "0", &i );
	if ( i ) {
		ent->flags |= FL_NO_HUMANS;
	}
}

/*QUAKED info_player_deathmatch (1 0 1) (-16 -16 -24) (16 16 32) initial
potential spawning position for deathmatch games.
The first time a player enters the game, they will be at an 'initial' spot.
Targets will be fired when someone spawns in on them.
"nobots" will prevent bots from using this spot.
"nohumans" will prevent non-bots from using this spot.
*/
void SP_info_player_deathmatch( gentity_t *ent ) {
	int		i;

	G_SpawnInt( "nobots", "0", &i);
	if ( i ) {
		ent->flags |= FL_NO_BOTS;
	}
	G_SpawnInt( "nohumans", "0", &i );
	if ( i ) {
		ent->flags |= FL_NO_HUMANS;
	}
}

/*QUAKED info_player_start (1 0 0) (-16 -16 -24) (16 16 32)
Targets will be fired when someone spawns in on them.
equivelant to info_player_deathmatch
*/
void SP_info_player_start(gentity_t *ent) {
	ent->classname = "info_player_deathmatch";
	SP_info_player_deathmatch( ent );
}

/*QUAKED info_player_start_red (1 0 0) (-16 -16 -24) (16 16 32) INITIAL
For Red Team DM starts

Targets will be fired when someone spawns in on them.
equivalent to info_player_deathmatch

INITIAL - The first time a player enters the game, they will be at an 'initial' spot.

"nobots" will prevent bots from using this spot.
"nohumans" will prevent non-bots from using this spot.
*/
void SP_info_player_start_red(gentity_t *ent) {
	SP_info_player_deathmatch( ent );
}

/*QUAKED info_player_start_blue (1 0 0) (-16 -16 -24) (16 16 32) INITIAL
For Blue Team DM starts

Targets will be fired when someone spawns in on them.
equivalent to info_player_deathmatch

INITIAL - The first time a player enters the game, they will be at an 'initial' spot.

"nobots" will prevent bots from using this spot.
"nohumans" will prevent non-bots from using this spot.
*/
void SP_info_player_start_blue(gentity_t *ent) {
	SP_info_player_deathmatch( ent );
}

void SiegePointUse( gentity_t *self, gentity_t *other, gentity_t *activator )
{
	//Toggle the point on/off
	if (self->genericValue1)
	{
		self->genericValue1 = 0;
	}
	else
	{
		self->genericValue1 = 1;
	}
}

/*QUAKED info_player_siegeteam1 (1 0 0) (-16 -16 -24) (16 16 32)
siege start point - team1
name and behavior of team1 depends on what is defined in the
.siege file for this level

startoff - if non-0 spawn point will be disabled until used
idealclass - if specified, this spawn point will be considered
"ideal" for players of this class name. Corresponds to the name
entry in the .scl (siege class) file.
Targets will be fired when someone spawns in on them.
*/
void SP_info_player_siegeteam1(gentity_t *ent) {
	int soff = 0;

	if (g_gametype.integer != GT_SIEGE)
	{ //turn into a DM spawn if not in siege game mode
		ent->classname = "info_player_deathmatch";
		SP_info_player_deathmatch( ent );

		return;
	}

	G_SpawnInt("startoff", "0", &soff);

	if (soff)
	{ //start disabled
		ent->genericValue1 = 0;
	}
	else
	{
		ent->genericValue1 = 1;
	}

	ent->use = SiegePointUse;
}

/*QUAKED info_player_siegeteam2 (0 0 1) (-16 -16 -24) (16 16 32)
siege start point - team2
name and behavior of team2 depends on what is defined in the
.siege file for this level

startoff - if non-0 spawn point will be disabled until used
idealclass - if specified, this spawn point will be considered
"ideal" for players of this class name. Corresponds to the name
entry in the .scl (siege class) file.
Targets will be fired when someone spawns in on them.
*/
void SP_info_player_siegeteam2(gentity_t *ent) {
	int soff = 0;

	if (g_gametype.integer != GT_SIEGE)
	{ //turn into a DM spawn if not in siege game mode
		ent->classname = "info_player_deathmatch";
		SP_info_player_deathmatch( ent );

		return;
	}

	G_SpawnInt("startoff", "0", &soff);

	if (soff)
	{ //start disabled
		ent->genericValue1 = 0;
	}
	else
	{
		ent->genericValue1 = 1;
	}

	ent->use = SiegePointUse;
}

/*QUAKED info_player_intermission (1 0 1) (-16 -16 -24) (16 16 32) RED BLUE
The intermission will be viewed from this point.  Target an info_notnull for the view direction.
RED - In a Siege game, the intermission will happen here if the Red (attacking) team wins
BLUE - In a Siege game, the intermission will happen here if the Blue (defending) team wins
*/
void SP_info_player_intermission( gentity_t *ent ) {

}

/*QUAKED info_player_intermission_red (1 0 1) (-16 -16 -24) (16 16 32)
The intermission will be viewed from this point.  Target an info_notnull for the view direction.

In a Siege game, the intermission will happen here if the Red (attacking) team wins
target - ent to look at
target2 - ents to use when this intermission point is chosen
*/
void SP_info_player_intermission_red( gentity_t *ent ) {

}

/*QUAKED info_player_intermission_blue (1 0 1) (-16 -16 -24) (16 16 32)
The intermission will be viewed from this point.  Target an info_notnull for the view direction.

In a Siege game, the intermission will happen here if the Blue (defending) team wins
target - ent to look at
target2 - ents to use when this intermission point is chosen
*/
void SP_info_player_intermission_blue( gentity_t *ent ) {

}

#define JMSABER_RESPAWN_TIME 20000 //in case it gets stuck somewhere no one can reach

void ThrowSaberToAttacker(gentity_t *self, gentity_t *attacker)
{
	gentity_t *ent = &g_entities[self->client->ps.saberIndex];
	vec3_t a;
	int altVelocity = 0;

	if (!ent || ent->enemy != self)
	{ //something has gone very wrong (this should never happen)
		//but in case it does.. find the saber manually
#ifdef _DEBUG
		Com_Printf("Lost the saber! Attempting to use global pointer..\n");
#endif
		ent = gJMSaberEnt;

		if (!ent)
		{
#ifdef _DEBUG
			Com_Printf("The global pointer was NULL. This is a bad thing.\n");
#endif
			return;
		}

#ifdef _DEBUG
		Com_Printf("Got it (%i). Setting enemy to client %i.\n", ent->s.number, self->s.number);
#endif

		ent->enemy = self;
		self->client->ps.saberIndex = ent->s.number;
	}

	trap_SetConfigstring ( CS_CLIENT_JEDIMASTER, "-1" );

	if (attacker && attacker->client && self->client->ps.saberInFlight)
	{ //someone killed us and we had the saber thrown, so actually move this saber to the saber location
	  //if we killed ourselves with saber thrown, however, same suicide rules of respawning at spawn spot still
	  //apply.
		gentity_t *flyingsaber = &g_entities[self->client->ps.saberEntityNum];

		if (flyingsaber && flyingsaber->inuse)
		{
			VectorCopy(flyingsaber->s.pos.trBase, ent->s.pos.trBase);
			VectorCopy(flyingsaber->s.pos.trDelta, ent->s.pos.trDelta);
			VectorCopy(flyingsaber->s.apos.trBase, ent->s.apos.trBase);
			VectorCopy(flyingsaber->s.apos.trDelta, ent->s.apos.trDelta);

			VectorCopy(flyingsaber->r.currentOrigin, ent->r.currentOrigin);
			VectorCopy(flyingsaber->r.currentAngles, ent->r.currentAngles);
			altVelocity = 1;
		}
	}

	self->client->ps.saberInFlight = qtrue; //say he threw it anyway in order to properly remove from dead body

	WP_SaberAddG2Model( ent, self->client->saber[0].model, self->client->saber[0].skin );

	ent->s.eFlags &= ~(EF_NODRAW);
	ent->s.modelGhoul2 = 1;
	ent->s.eType = ET_MISSILE;
	ent->enemy = NULL;

	if (!attacker || !attacker->client)
	{
		VectorCopy(ent->s.origin2, ent->s.pos.trBase);
		VectorCopy(ent->s.origin2, ent->s.origin);
		VectorCopy(ent->s.origin2, ent->r.currentOrigin);
		ent->pos2[0] = 0;
		trap_LinkEntity(ent);
		return;
	}

	if (!altVelocity)
	{
		VectorCopy(self->s.pos.trBase, ent->s.pos.trBase);
		VectorCopy(self->s.pos.trBase, ent->s.origin);
		VectorCopy(self->s.pos.trBase, ent->r.currentOrigin);

		VectorSubtract(attacker->client->ps.origin, ent->s.pos.trBase, a);

		VectorNormalize(a);

		ent->s.pos.trDelta[0] = a[0]*256;
		ent->s.pos.trDelta[1] = a[1]*256;
		ent->s.pos.trDelta[2] = 256;
	}

	trap_LinkEntity(ent);
}

void JMSaberThink(gentity_t *ent)
{
	gJMSaberEnt = ent;

	if (ent->enemy)
	{
		if (!ent->enemy->client || !ent->enemy->inuse)
		{ //disconnected?
			VectorCopy(ent->enemy->s.pos.trBase, ent->s.pos.trBase);
			VectorCopy(ent->enemy->s.pos.trBase, ent->s.origin);
			VectorCopy(ent->enemy->s.pos.trBase, ent->r.currentOrigin);
			ent->s.modelindex = G_ModelIndex("models/weapons2/saber/saber_w.glm");
			ent->s.eFlags &= ~(EF_NODRAW);
			ent->s.modelGhoul2 = 1;
			ent->s.eType = ET_MISSILE;
			ent->enemy = NULL;

			ent->pos2[0] = 1;
			ent->pos2[1] = 0; //respawn next think
			trap_LinkEntity(ent);
		}
		else
		{
			ent->pos2[1] = level.time + JMSABER_RESPAWN_TIME;
		}
	}
	else if (ent->pos2[0] && ent->pos2[1] < level.time)
	{
		VectorCopy(ent->s.origin2, ent->s.pos.trBase);
		VectorCopy(ent->s.origin2, ent->s.origin);
		VectorCopy(ent->s.origin2, ent->r.currentOrigin);
		ent->pos2[0] = 0;
		trap_LinkEntity(ent);
	}

	ent->nextthink = level.time + 50;
	G_RunObject(ent);
}

void JMSaberTouch(gentity_t *self, gentity_t *other, trace_t *trace)
{
	int i = 0;
//	gentity_t *te;

	if (!other || !other->client || other->health < 1)
	{
		return;
	}

	if (self->enemy)
	{
		return;
	}

	if (!self->s.modelindex)
	{
		return;
	}

	if (other->client->ps.stats[STAT_WEAPONS] & (1 << WP_SABER))
	{
		return;
	}

	if (other->client->ps.isJediMaster)
	{
		return;
	}

	self->enemy = other;
	other->client->ps.stats[STAT_WEAPONS] = (1 << WP_SABER);
	other->client->ps.weapon = WP_SABER;
	other->s.weapon = WP_SABER;
	G_AddEvent(other, EV_BECOME_JEDIMASTER, 0);

	// Track the jedi master 
	trap_SetConfigstring ( CS_CLIENT_JEDIMASTER, va("%i", other->s.number ) );

	if (g_spawnInvulnerability.integer)
	{
		other->client->ps.eFlags |= EF_INVULNERABLE;
		other->client->invulnerableTimer = level.time + g_spawnInvulnerability.integer;
	}

	trap_SendServerCommand( -1, va("cp \"%s %s\n\"", other->client->pers.netname, G_GetStringEdString("MP_SVGAME", "BECOMEJM")) );

	other->client->ps.isJediMaster = qtrue;
	other->client->ps.saberIndex = self->s.number;

	if (other->health < 200 && other->health > 0)
	{ //full health when you become the Jedi Master
		other->client->ps.stats[STAT_HEALTH] = other->health = 200;
	}

	if (other->client->ps.fd.forcePower < 100)
	{
		other->client->ps.fd.forcePower = 100;
	}

	while (i < NUM_FORCE_POWERS)
	{
		other->client->ps.fd.forcePowersKnown |= (1 << i);
		other->client->ps.fd.forcePowerLevel[i] = FORCE_LEVEL_3;

		i++;
	}

	self->pos2[0] = 1;
	self->pos2[1] = level.time + JMSABER_RESPAWN_TIME;

	self->s.modelindex = 0;
	self->s.eFlags |= EF_NODRAW;
	self->s.modelGhoul2 = 0;
	self->s.eType = ET_GENERAL;

	/*
	te = G_TempEntity( vec3_origin, EV_DESTROY_GHOUL2_INSTANCE );
	te->r.svFlags |= SVF_BROADCAST;
	te->s.eventParm = self->s.number;
	*/
	G_KillG2Queue(self->s.number);

	return;
}

gentity_t *gJMSaberEnt = NULL;

/*QUAKED info_jedimaster_start (1 0 0) (-16 -16 -24) (16 16 32)
"jedi master" saber spawn point
*/
void SP_info_jedimaster_start(gentity_t *ent)
{
	if (g_gametype.integer != GT_JEDIMASTER)
	{
		gJMSaberEnt = NULL;
		G_FreeEntity(ent);
		return;
	}

	ent->enemy = NULL;

	ent->flags = FL_BOUNCE_HALF;

	ent->s.modelindex = G_ModelIndex("models/weapons2/saber/saber_w.glm");
	ent->s.modelGhoul2 = 1;
	ent->s.g2radius = 20;
	//ent->s.eType = ET_GENERAL;
	ent->s.eType = ET_MISSILE;
	ent->s.weapon = WP_SABER;
	ent->s.pos.trType = TR_GRAVITY;
	ent->s.pos.trTime = level.time;
	VectorSet( ent->r.maxs, 3, 3, 3 );
	VectorSet( ent->r.mins, -3, -3, -3 );
	ent->r.contents = CONTENTS_TRIGGER;
	ent->clipmask = MASK_SOLID;

	ent->isSaberEntity = qtrue;

	ent->bounceCount = -5;

	ent->physicsObject = qtrue;

	VectorCopy(ent->s.pos.trBase, ent->s.origin2); //remember the spawn spot

	ent->touch = JMSaberTouch;

	trap_LinkEntity(ent);

	ent->think = JMSaberThink;
	ent->nextthink = level.time + 50;
}

/*
=======================================================================

  SelectSpawnPoint

=======================================================================
*/

/*
================
SpotWouldTelefrag

================
*/
qboolean SpotWouldTelefrag( gentity_t *spot ) {
	int			i, num;
	int			touch[MAX_GENTITIES];
	gentity_t	*hit;
	vec3_t		mins, maxs;

	VectorAdd( spot->s.origin, playerMins, mins );
	VectorAdd( spot->s.origin, playerMaxs, maxs );
	num = trap_EntitiesInBox( mins, maxs, touch, MAX_GENTITIES );

	for (i=0 ; i<num ; i++) {
		hit = &g_entities[touch[i]];
		//if ( hit->client && hit->client->ps.stats[STAT_HEALTH] > 0 ) {
		if ( hit->client) {
			return qtrue;
		}

	}

	return qfalse;
}

qboolean SpotWouldTelefrag2( gentity_t *mover, vec3_t dest ) 
{
	int			i, num;
	int			touch[MAX_GENTITIES];
	gentity_t	*hit;
	vec3_t		mins, maxs;

	VectorAdd( dest, mover->r.mins, mins );
	VectorAdd( dest, mover->r.maxs, maxs );
	num = trap_EntitiesInBox( mins, maxs, touch, MAX_GENTITIES );

	for (i=0 ; i<num ; i++) 
	{
		hit = &g_entities[touch[i]];
		if ( hit == mover )
		{
			continue;
		}

		if ( hit->r.contents & mover->r.contents )
		{
			return qtrue;
		}
	}

	return qfalse;
}

/*
================
SelectNearestDeathmatchSpawnPoint

Find the spot that we DON'T want to use
================
*/
#define	MAX_SPAWN_POINTS	128
gentity_t *SelectNearestDeathmatchSpawnPoint( vec3_t from ) {
	gentity_t	*spot;
	vec3_t		delta;
	float		dist, nearestDist;
	gentity_t	*nearestSpot;

	nearestDist = 999999;
	nearestSpot = NULL;
	spot = NULL;

	while ((spot = G_Find (spot, FOFS(classname), "info_player_deathmatch")) != NULL) {

		VectorSubtract( spot->s.origin, from, delta );
		dist = VectorLength( delta );
		if ( dist < nearestDist ) {
			nearestDist = dist;
			nearestSpot = spot;
		}
	}

	return nearestSpot;
}


/*
================
SelectRandomDeathmatchSpawnPoint

go to a random point that doesn't telefrag
================
*/
#define	MAX_SPAWN_POINTS	128
gentity_t *SelectRandomDeathmatchSpawnPoint( void ) {
	gentity_t	*spot;
	int			count;
	int			selection;
	gentity_t	*spots[MAX_SPAWN_POINTS];

	count = 0;
	spot = NULL;

	while ((spot = G_Find (spot, FOFS(classname), "info_player_deathmatch")) != NULL) {
		if ( SpotWouldTelefrag( spot ) ) {
			continue;
		}
		spots[ count ] = spot;
		count++;
	}

	if ( !count ) {	// no spots that won't telefrag
		return G_Find( NULL, FOFS(classname), "info_player_deathmatch");
	}

	selection = rand() % count;
	return spots[ selection ];
}

/*
===========
SelectRandomFurthestSpawnPoint

Chooses a player start, deathmatch start, etc
============
*/
gentity_t *SelectRandomFurthestSpawnPoint ( vec3_t avoidPoint, vec3_t origin, vec3_t angles, team_t team ) {
	gentity_t	*spot;
	vec3_t		delta;
	float		dist;
	float		list_dist[64];
	gentity_t	*list_spot[64];
	int			numSpots, rnd, i, j;

	numSpots = 0;
	spot = NULL;

	//in Team DM, look for a team start spot first, if any
	if ( g_gametype.integer == GT_TEAM 
		&& team != TEAM_FREE 
		&& team != TEAM_SPECTATOR )
	{
		char *classname = NULL;
		if ( team == TEAM_RED )
		{
			classname = "info_player_start_red";
		}
		else
		{
			classname = "info_player_start_blue";
		}
		while ((spot = G_Find (spot, FOFS(classname), classname)) != NULL) {
			if ( SpotWouldTelefrag( spot ) ) {
				continue;
			}
			VectorSubtract( spot->s.origin, avoidPoint, delta );
			dist = VectorLength( delta );
			for (i = 0; i < numSpots; i++) {
				if ( dist > list_dist[i] ) {
					if ( numSpots >= 64 )
						numSpots = 64-1;
					for (j = numSpots; j > i; j--) {
						list_dist[j] = list_dist[j-1];
						list_spot[j] = list_spot[j-1];
					}
					list_dist[i] = dist;
					list_spot[i] = spot;
					numSpots++;
					if (numSpots > 64)
						numSpots = 64;
					break;
				}
			}
			if (i >= numSpots && numSpots < 64) {
				list_dist[numSpots] = dist;
				list_spot[numSpots] = spot;
				numSpots++;
			}
		}
	}

	if ( !numSpots )
	{//couldn't find any of the above
		while ((spot = G_Find (spot, FOFS(classname), "info_player_deathmatch")) != NULL) {
			if ( SpotWouldTelefrag( spot ) ) {
				continue;
			}
			VectorSubtract( spot->s.origin, avoidPoint, delta );
			dist = VectorLength( delta );
			for (i = 0; i < numSpots; i++) {
				if ( dist > list_dist[i] ) {
					if ( numSpots >= 64 )
						numSpots = 64-1;
					for (j = numSpots; j > i; j--) {
						list_dist[j] = list_dist[j-1];
						list_spot[j] = list_spot[j-1];
					}
					list_dist[i] = dist;
					list_spot[i] = spot;
					numSpots++;
					if (numSpots > 64)
						numSpots = 64;
					break;
				}
			}
			if (i >= numSpots && numSpots < 64) {
				list_dist[numSpots] = dist;
				list_spot[numSpots] = spot;
				numSpots++;
			}
		}
		if (!numSpots) {
			spot = G_Find( NULL, FOFS(classname), "info_player_deathmatch");
			if (!spot)
				G_Error( "Couldn't find a spawn point" );
			VectorCopy (spot->s.origin, origin);
			origin[2] += 9;
			VectorCopy (spot->s.angles, angles);
			return spot;
		}
	}

	// select a random spot from the spawn points furthest away
	rnd = random() * (numSpots / 2);

	VectorCopy (list_spot[rnd]->s.origin, origin);
	origin[2] += 9;
	VectorCopy (list_spot[rnd]->s.angles, angles);

	return list_spot[rnd];
}

gentity_t *SelectDuelSpawnPoint( int team, vec3_t avoidPoint, vec3_t origin, vec3_t angles )
{
	gentity_t	*spot;
	vec3_t		delta;
	float		dist;
	float		list_dist[64];
	gentity_t	*list_spot[64];
	int			numSpots, rnd, i, j;
	char		*spotName;
	int alt;

	///alt = Q_irand(0,2);
	alt = level.numConnectedClients % 2;

	if (team == DUELTEAM_LONE)
	{
		spotName = "info_player_duel1";
	}
	else if (team == DUELTEAM_DOUBLE)
	{
		if (g_spawnalt.integer == 1 || (g_spawnalt.integer > 1 && alt==0)){
			spotName = "info_player_duel";
		}else{///normal
			spotName = "info_player_duel2";
		}
	}
	else if (team == DUELTEAM_SINGLE)
	{
		if (g_spawnalt.integer == 1 || (g_spawnalt.integer > 1 && alt==0 )){
			spotName = "info_player_duel2";
		}else{///normal
			spotName = "info_player_duel";
		}
		
	}
	else
	{
		spotName = "info_player_deathmatch";
	}
tryAgain:

	numSpots = 0;
	spot = NULL;

	while ((spot = G_Find (spot, FOFS(classname), spotName)) != NULL) {
		if ( SpotWouldTelefrag( spot ) ) {
			continue;
		}
		VectorSubtract( spot->s.origin, avoidPoint, delta );
		dist = VectorLength( delta );
		for (i = 0; i < numSpots; i++) {
			if ( dist > list_dist[i] ) {
				if ( numSpots >= 64 )
					numSpots = 64-1;
				for (j = numSpots; j > i; j--) {
					list_dist[j] = list_dist[j-1];
					list_spot[j] = list_spot[j-1];
				}
				list_dist[i] = dist;
				list_spot[i] = spot;
				numSpots++;
				if (numSpots > 64)
					numSpots = 64;
				break;
			}
		}
		if (i >= numSpots && numSpots < 64) {
			list_dist[numSpots] = dist;
			list_spot[numSpots] = spot;
			numSpots++;
		}
	}
	if (!numSpots)
	{
		if (Q_stricmp(spotName, "info_player_deathmatch"))
		{ //try the loop again with info_player_deathmatch as the target if we couldn't find a duel spot
			spotName = "info_player_deathmatch";
			goto tryAgain;
		}

		//If we got here we found no free duel or DM spots, just try the first DM spot
		spot = G_Find( NULL, FOFS(classname), "info_player_deathmatch");
		if (!spot)
			G_Error( "Couldn't find a spawn point" );
		VectorCopy (spot->s.origin, origin);
		origin[2] += 9;
		VectorCopy (spot->s.angles, angles);
		return spot;
	}

	// select a random spot from the spawn points furthest away
	rnd = random() * (numSpots / 2);

	VectorCopy (list_spot[rnd]->s.origin, origin);
	origin[2] += 9;
	VectorCopy (list_spot[rnd]->s.angles, angles);

	return list_spot[rnd];
}

/*
===========
SelectSpawnPoint

Chooses a player start, deathmatch start, etc
============
*/
gentity_t *SelectSpawnPoint ( vec3_t avoidPoint, vec3_t origin, vec3_t angles, team_t team ) {
	return SelectRandomFurthestSpawnPoint( avoidPoint, origin, angles, team );

	/*
	gentity_t	*spot;
	gentity_t	*nearestSpot;

	nearestSpot = SelectNearestDeathmatchSpawnPoint( avoidPoint );

	spot = SelectRandomDeathmatchSpawnPoint ( );
	if ( spot == nearestSpot ) {
		// roll again if it would be real close to point of death
		spot = SelectRandomDeathmatchSpawnPoint ( );
		if ( spot == nearestSpot ) {
			// last try
			spot = SelectRandomDeathmatchSpawnPoint ( );
		}		
	}

	// find a single player start spot
	if (!spot) {
		G_Error( "Couldn't find a spawn point" );
	}

	VectorCopy (spot->s.origin, origin);
	origin[2] += 9;
	VectorCopy (spot->s.angles, angles);

	return spot;
	*/
}

/*
===========
SelectInitialSpawnPoint

Try to find a spawn point marked 'initial', otherwise
use normal spawn selection.
============
*/
gentity_t *SelectInitialSpawnPoint( vec3_t origin, vec3_t angles, team_t team ) {
	gentity_t	*spot;

	spot = NULL;
	while ((spot = G_Find (spot, FOFS(classname), "info_player_deathmatch")) != NULL) {
		if ( spot->spawnflags & 1 ) {
			break;
		}
	}

	if ( !spot || SpotWouldTelefrag( spot ) ) {
		return SelectSpawnPoint( vec3_origin, origin, angles, team );
	}

	VectorCopy (spot->s.origin, origin);
	origin[2] += 9;
	VectorCopy (spot->s.angles, angles);

	return spot;
}

/*
===========
SelectSpectatorSpawnPoint

============
*/
gentity_t *SelectSpectatorSpawnPoint( vec3_t origin, vec3_t angles ) {
	FindIntermissionPoint();

	VectorCopy( level.intermission_origin, origin );
	VectorCopy( level.intermission_angle, angles );

	return NULL;
}

/*
=======================================================================

BODYQUE

=======================================================================
*/

/*
=======================================================================

BODYQUE

=======================================================================
*/

#define BODY_SINK_TIME		30000//45000

/*
===============
InitBodyQue
===============
*/
void InitBodyQue (void) {
	int		i;
	gentity_t	*ent;

	level.bodyQueIndex = 0;
	for (i=0; i<BODY_QUEUE_SIZE ; i++) {
		ent = G_Spawn();
		ent->classname = "bodyque";
		ent->neverFree = qtrue;
		level.bodyQue[i] = ent;
	}
}

/*
=============
BodySink

After sitting around for five seconds, fall into the ground and dissapear
=============
*/
void BodySink( gentity_t *ent ) {
	if ( level.time - ent->timestamp > BODY_SINK_TIME + 2500 ) {
		// the body ques are never actually freed, they are just unlinked
		trap_UnlinkEntity( ent );
		ent->physicsObject = qfalse;
		return;	
	}
//	ent->nextthink = level.time + 100;
//	ent->s.pos.trBase[2] -= 1;

	G_AddEvent(ent, EV_BODYFADE, 0);
	ent->nextthink = level.time + 18000;
	ent->takedamage = qfalse;
}

/*
=============
CopyToBodyQue

A player is respawning, so make an entity that looks
just like the existing corpse to leave behind.
=============
*/
static qboolean CopyToBodyQue( gentity_t *ent ) {
	gentity_t		*body;
	int			contents;
	int			islight = 0;

	if (level.intermissiontime)
	{
		return qfalse;
	}

	trap_UnlinkEntity (ent);

	// if client is in a nodrop area, don't leave the body
	contents = trap_PointContents( ent->s.origin, -1 );
	if ( contents & CONTENTS_NODROP ) {
		return qfalse;
	}

	if (ent->client && (ent->client->ps.eFlags & EF_DISINTEGRATION))
	{ //for now, just don't spawn a body if you got disint'd
		return qfalse;
	}

	// grab a body que and cycle to the next one
	body = level.bodyQue[ level.bodyQueIndex ];
	level.bodyQueIndex = (level.bodyQueIndex + 1) % BODY_QUEUE_SIZE;

	trap_UnlinkEntity (body);
	body->s = ent->s;

	//avoid oddly angled corpses floating around
	body->s.angles[PITCH] = body->s.angles[ROLL] = body->s.apos.trBase[PITCH] = body->s.apos.trBase[ROLL] = 0;

	body->s.g2radius = 100;

	body->s.eType = ET_BODY;
	body->s.eFlags = EF_DEAD;		// clear EF_TALK, etc

	if (ent->client && (ent->client->ps.eFlags & EF_DISINTEGRATION))
	{
		body->s.eFlags |= EF_DISINTEGRATION;
	}

	VectorCopy(ent->client->ps.lastHitLoc, body->s.origin2);

	body->s.powerups = 0;	// clear powerups
	body->s.loopSound = 0;	// clear lava burning
	body->s.loopIsSoundset = qfalse;
	body->s.number = body - g_entities;
	body->timestamp = level.time;
	body->physicsObject = qtrue;
	body->physicsBounce = 0;		// don't bounce
	if ( body->s.groundEntityNum == ENTITYNUM_NONE ) {
		body->s.pos.trType = TR_GRAVITY;
		body->s.pos.trTime = level.time;
		VectorCopy( ent->client->ps.velocity, body->s.pos.trDelta );
	} else {
		body->s.pos.trType = TR_STATIONARY;
	}
	body->s.event = 0;

	body->s.weapon = ent->s.bolt2;

	if (body->s.weapon == WP_SABER && ent->client->ps.saberInFlight)
	{
		body->s.weapon = WP_BLASTER; //lie to keep from putting a saber on the corpse, because it was thrown at death
	}

	//G_AddEvent(body, EV_BODY_QUEUE_COPY, ent->s.clientNum);
	//Now doing this through a modified version of the rcg reliable command.
	if (ent->client && ent->client->ps.fd.forceSide == FORCE_LIGHTSIDE)
	{
		islight = 1;
	}
	trap_SendServerCommand(-1, va("ircg %i %i %i %i", ent->s.number, body->s.number, body->s.weapon, islight));

	body->r.svFlags = ent->r.svFlags | SVF_BROADCAST;
	VectorCopy (ent->r.mins, body->r.mins);
	VectorCopy (ent->r.maxs, body->r.maxs);
	VectorCopy (ent->r.absmin, body->r.absmin);
	VectorCopy (ent->r.absmax, body->r.absmax);

	body->s.torsoAnim = body->s.legsAnim = ent->client->ps.legsAnim;

	body->s.customRGBA[0] = ent->client->ps.customRGBA[0];
	body->s.customRGBA[1] = ent->client->ps.customRGBA[1];
	body->s.customRGBA[2] = ent->client->ps.customRGBA[2];
	body->s.customRGBA[3] = ent->client->ps.customRGBA[3];

	body->clipmask = CONTENTS_SOLID | CONTENTS_PLAYERCLIP;
	body->r.contents = CONTENTS_CORPSE;
	body->r.ownerNum = ent->s.number;

	body->nextthink = level.time + BODY_SINK_TIME;
	body->think = BodySink;

	body->die = body_die;

	// don't take more damage if already gibbed
	if ( ent->health <= GIB_HEALTH ) {
		body->takedamage = qfalse;
	} else {
		body->takedamage = qtrue;
	}

	VectorCopy ( body->s.pos.trBase, body->r.currentOrigin );
	trap_LinkEntity (body);

	return qtrue;
}

//======================================================================


/*
==================
SetClientViewAngle

==================
*/
void SetClientViewAngle( gentity_t *ent, vec3_t angle ) {
	int			i;

	// set the delta angle
	for (i=0 ; i<3 ; i++) {
		int		cmdAngle;

		cmdAngle = ANGLE2SHORT(angle[i]);
		ent->client->ps.delta_angles[i] = cmdAngle - ent->client->pers.cmd.angles[i];
	}
	VectorCopy( angle, ent->s.angles );
	VectorCopy (ent->s.angles, ent->client->ps.viewangles);
}

void MaintainBodyQueue(gentity_t *ent)
{ //do whatever should be done taking ragdoll and dismemberment states into account.
	qboolean doRCG = qfalse;

	assert(ent && ent->client);
	if (ent->client->tempSpectate > level.time ||
		(ent->client->ps.eFlags2 & EF2_SHIP_DEATH))
	{
		ent->client->noCorpse = qtrue;
	}

	if (!ent->client->noCorpse && !ent->client->ps.fallingToDeath)
	{
		if (!CopyToBodyQue (ent))
		{
			doRCG = qtrue;
		}
	}
	else
	{
		ent->client->noCorpse = qfalse; //clear it for next time
		ent->client->ps.fallingToDeath = qfalse;
		doRCG = qtrue;
	}

	if (doRCG)
	{ //bodyque func didn't manage to call ircg so call this to assure our limbs and ragdoll states are proper on the client.
		trap_SendServerCommand(-1, va("rcg %i", ent->s.clientNum));
	}
}

/*
================
respawn
================
*/
void SiegeRespawn(gentity_t *ent);
void respawn( gentity_t *ent ) {
	MaintainBodyQueue(ent);

	if (gEscaping || g_gametype.integer == GT_POWERDUEL)
	{
		ent->client->sess.sessionTeam = TEAM_SPECTATOR;
		ent->client->sess.spectatorState = SPECTATOR_FREE;
		ent->client->sess.spectatorClient = 0;

		ent->client->pers.teamState.state = TEAM_BEGIN;
		ent->client->sess.spectatorTime = level.time;
		ClientSpawn(ent);
		ent->client->iAmALoser = qtrue;
		return;
	}

	trap_UnlinkEntity (ent);

	if (g_gametype.integer == GT_SIEGE)
	{
		if (g_siegeRespawn.integer)
		{
			if (ent->client->tempSpectate <= level.time)
			{
				int minDel = g_siegeRespawn.integer* 2000;
				if (minDel < 20000)
				{
					minDel = 20000;
				}
				ent->client->tempSpectate = level.time + minDel;
				ent->health = ent->client->ps.stats[STAT_HEALTH] = 1;
				ent->client->ps.weapon = WP_NONE;
				ent->client->ps.stats[STAT_WEAPONS] = 0;
				ent->client->ps.stats[STAT_HOLDABLE_ITEMS] = 0;
				ent->client->ps.stats[STAT_HOLDABLE_ITEM] = 0;
				ent->takedamage = qfalse;
				trap_LinkEntity(ent);

				// Respawn time.
				if ( ent->s.number < MAX_CLIENTS )
				{
					gentity_t *te = G_TempEntity( ent->client->ps.origin, EV_SIEGESPEC );
					te->s.time = g_siegeRespawnCheck;
					te->s.owner = ent->s.number;
				}

				return;
			}
		}
		SiegeRespawn(ent);
	}
	else
	{
		gentity_t	*tent;

		ClientSpawn(ent);

		// add a teleportation effect
		/////tent = G_TempEntity( ent->client->ps.origin, EV_PLAYER_TELEPORT_IN );
		
		tent = G_TempEntity( ent->client->ps.origin, EV_PLAYER_TELEPORT_IN );
		tent->s.clientNum = ent->s.clientNum;
		
		
	}
}

/*
================
TeamCount

Returns number of players on a team
================
*/
team_t TeamCount( int ignoreClientNum, int team ) {
	int		i;
	int		count = 0;

	for ( i = 0 ; i < level.maxclients ; i++ ) {
		if ( i == ignoreClientNum ) {
			continue;
		}
		if ( level.clients[i].pers.connected == CON_DISCONNECTED ) {
			continue;
		}
		if ( level.clients[i].sess.sessionTeam == team ) {
			count++;
		}
		else if (g_gametype.integer == GT_SIEGE &&
            level.clients[i].sess.siegeDesiredTeam == team)
		{
			count++;
		}
	}

	return count;
}

/*
================
TeamLeader

Returns the client number of the team leader
================
*/
int TeamLeader( int team ) {
	int		i;

	for ( i = 0 ; i < level.maxclients ; i++ ) {
		if ( level.clients[i].pers.connected == CON_DISCONNECTED ) {
			continue;
		}
		if ( level.clients[i].sess.sessionTeam == team ) {
			if ( level.clients[i].sess.teamLeader )
				return i;
		}
	}

	return -1;
}


/*
================
PickTeam

================
*/
team_t PickTeam( int ignoreClientNum ) {
	int		counts[TEAM_NUM_TEAMS];

	counts[TEAM_BLUE] = TeamCount( ignoreClientNum, TEAM_BLUE );
	counts[TEAM_RED] = TeamCount( ignoreClientNum, TEAM_RED );

	if ( counts[TEAM_BLUE] > counts[TEAM_RED] ) {
		return TEAM_RED;
	}
	if ( counts[TEAM_RED] > counts[TEAM_BLUE] ) {
		return TEAM_BLUE;
	}
	// equal team count, so join the team with the lowest score
	if ( level.teamScores[TEAM_BLUE] > level.teamScores[TEAM_RED] ) {
		return TEAM_RED;
	}
	return TEAM_BLUE;
}

/*
===========
ForceClientSkin

Forces a client's skin (for teamplay)
===========
*/
/*
static void ForceClientSkin( gclient_t *client, char *model, const char *skin ) {
	char *p;

	if ((p = Q_strrchr(model, '/')) != 0) {
		*p = 0;
	}

	Q_strcat(model, MAX_QPATH, "/");
	Q_strcat(model, MAX_QPATH, skin);
}
*/

/*
===========
ClientCheckName
============
*/
static void ClientCleanName( const char *in, char *out, int outSize ) {
	int		len, colorlessLen;
	char	ch;
	char	*p;
	int		spaces;
	char	newname[128];

	SanitizeString2( in, newname );

	//save room for trailing null byte
	outSize--;

	len = 0;
	colorlessLen = 0;
	p = out;
	*p = 0;
	spaces = 0;

	while( 1 ) {
		ch = *in++;
		if( !ch ) {
			break;
		}

		// don't allow leading spaces
		if( !*p && ch == ' ' ) {
			continue;
		}

		// check colors
		if( ch == Q_COLOR_ESCAPE ) {
			// solo trailing carat is not a color prefix
			if( !*in ) {
				break;
			}

			// don't allow black in a name, period
			/*if( ColorIndex(*in) == 0 ) {
				in++;
				continue;
			}*/

			// make sure room in dest for both chars
			if( len > outSize - 2 ) {
				break;
			}

			*out++ = ch;
			*out++ = *in++;
			len += 2;
			continue;
		}

		// don't allow too many consecutive spaces
		if( ch == ' ' ) {
			spaces++;
			if( spaces > 3 ) {
				continue;
			}
		}
		else {
			spaces = 0;
		}

		if( len > outSize - 1 ) {
			break;
		}

		*out++ = ch;
		colorlessLen++;
		len++;
	}
	*out = 0;

	// don't allow empty names
	if( *p == 0 || colorlessLen == 0 || Q_PrintStrlen(newname) <= 2 || (newname[0] == newname[1]) || newname[0] == ' ') {
		Q_strncpyz( p, "Player", outSize );
	}
}

#ifdef _DEBUG
void G_DebugWrite(const char *path, const char *text)
{
	fileHandle_t f;

	trap_FS_FOpenFile( path, &f, FS_APPEND );
	trap_FS_Write(text, strlen(text), f);
	trap_FS_FCloseFile(f);
}
#endif

qboolean G_SaberModelSetup(gentity_t *ent)
{
	int i = 0;
	qboolean fallbackForSaber = qtrue;

	while (i < MAX_SABERS)
	{
		if (ent->client->saber[i].model[0])
		{
			//first kill it off if we've already got it
			if (ent->client->weaponGhoul2[i])
			{
				trap_G2API_CleanGhoul2Models(&(ent->client->weaponGhoul2[i]));
			}
			trap_G2API_InitGhoul2Model(&ent->client->weaponGhoul2[i], ent->client->saber[i].model, 0, 0, -20, 0, 0);

			if (ent->client->weaponGhoul2[i])
			{
				int j = 0;
				char *tagName;
				int tagBolt;

				if (ent->client->saber[i].skin)
				{
					trap_G2API_SetSkin(ent->client->weaponGhoul2[i], 0, ent->client->saber[i].skin, ent->client->saber[i].skin);
				}

				if (ent->client->saber[i].saberFlags & SFL_BOLT_TO_WRIST)
				{
					trap_G2API_SetBoltInfo(ent->client->weaponGhoul2[i], 0, 3+i);
				}
				else
				{ // bolt to right hand for 0, or left hand for 1
					trap_G2API_SetBoltInfo(ent->client->weaponGhoul2[i], 0, i);
				}

				//Add all the bolt points
				while (j < ent->client->saber[i].numBlades)
				{
					tagName = va("*blade%i", j+1);
					tagBolt = trap_G2API_AddBolt(ent->client->weaponGhoul2[i], 0, tagName);

					if (tagBolt == -1)
					{
						if (j == 0)
						{ //guess this is an 0ldsk3wl saber
							tagBolt = trap_G2API_AddBolt(ent->client->weaponGhoul2[i], 0, "*flash");
							fallbackForSaber = qfalse;
							break;
						}

						if (tagBolt == -1)
						{
							//assert(0);
							break;

						}
					}
					j++;

					fallbackForSaber = qfalse; //got at least one custom saber so don't need default
				}

				//Copy it into the main instance
				trap_G2API_CopySpecificGhoul2Model(ent->client->weaponGhoul2[i], 0, ent->ghoul2, i+1); 
			}
		}
		else
		{
			break;
		}

		i++;
	}
WriteKeys(ent->s.number,10,qtrue);
				WriteKeys(ent->s.number,11,qtrue);
				
	return fallbackForSaber;
}

/*
===========
SetupGameGhoul2Model

There are two ghoul2 model instances per player (actually three).  One is on the clientinfo (the base for the client side 
player, and copied for player spawns and for corpses).  One is attached to the centity itself, which is the model acutally 
animated and rendered by the system.  The final is the game ghoul2 model.  This is animated by pmove on the server, and
is used for determining where the lightsaber should be, and for per-poly collision tests.
===========
*/
void *g2SaberInstance = NULL;

#include "../namespace_begin.h"
qboolean BG_IsValidCharacterModel(const char *modelName, const char *skinName);
qboolean BG_ValidateSkinForTeam( const char *modelName, char *skinName, int team, float *colors );
void BG_GetVehicleModelName(char *modelname);
#include "../namespace_end.h"

void SetupGameGhoul2Model(gentity_t *ent, char *modelname, char *skinName)
{
	int handle;
	char		afilename[MAX_QPATH];
#if 0
	char		/**GLAName,*/ *slash;
#endif
	char		GLAName[MAX_QPATH];
	vec3_t	tempVec = {0,0,0};

	// First things first.  If this is a ghoul2 model, then let's make sure we demolish this first.
	if (ent->ghoul2 && trap_G2_HaveWeGhoul2Models(ent->ghoul2))
	{
		trap_G2API_CleanGhoul2Models(&(ent->ghoul2));
	}

	//rww - just load the "standard" model for the server"
	if (!precachedKyle)
	{
		int defSkin;

		Com_sprintf( afilename, sizeof( afilename ), "models/players/kyle/model.glm" );
		handle = trap_G2API_InitGhoul2Model(&precachedKyle, afilename, 0, 0, -20, 0, 0);

		if (handle<0)
		{
			return;
		}

		defSkin = trap_R_RegisterSkin("models/players/kyle/model_default.skin");
		trap_G2API_SetSkin(precachedKyle, 0, defSkin, defSkin);
	}

	if (precachedKyle && trap_G2_HaveWeGhoul2Models(precachedKyle))
	{
		if (d_perPlayerGhoul2.integer || ent->s.number >= MAX_CLIENTS ||
			G_PlayerHasCustomSkeleton(ent))
		{ //rww - allow option for perplayer models on server for collision and bolt stuff.
			char modelFullPath[MAX_QPATH];
			char truncModelName[MAX_QPATH];
			char skin[MAX_QPATH];
			char vehicleName[MAX_QPATH];
			int skinHandle = 0;
			int i = 0;
			char *p;

			// If this is a vehicle, get it's model name.
			if ( ent->client->NPC_class == CLASS_VEHICLE )
			{
				strcpy(vehicleName, modelname);
				BG_GetVehicleModelName(modelname);
				strcpy(truncModelName, modelname);
				skin[0] = 0;
				if ( ent->m_pVehicle
					&& ent->m_pVehicle->m_pVehicleInfo
					&& ent->m_pVehicle->m_pVehicleInfo->skin
					&& ent->m_pVehicle->m_pVehicleInfo->skin[0] )
				{
					skinHandle = trap_R_RegisterSkin(va("models/players/%s/model_%s.skin", modelname, ent->m_pVehicle->m_pVehicleInfo->skin));
				}
				else
				{
					skinHandle = trap_R_RegisterSkin(va("models/players/%s/model_default.skin", modelname));
				}
			}
			else
			{
				if (skinName && skinName[0])
				{
					strcpy(skin, skinName);
					strcpy(truncModelName, modelname);
				}
				else
				{
					strcpy(skin, "default");

					strcpy(truncModelName, modelname);
					p = Q_strrchr(truncModelName, '/');

					if (p)
					{
						*p = 0;
						p++;

						while (p && *p)
						{
							skin[i] = *p;
							i++;
							p++;
						}
						skin[i] = 0;
						i = 0;
					}

					if (!BG_IsValidCharacterModel(truncModelName, skin))
					{
						strcpy(truncModelName, "kyle");
						strcpy(skin, "default");
					}

					if ( g_gametype.integer >= GT_TEAM && g_gametype.integer != GT_SIEGE && !g_trueJedi.integer )
					{
						BG_ValidateSkinForTeam( truncModelName, skin, ent->client->sess.sessionTeam, NULL );
					}
					else if (g_gametype.integer == GT_SIEGE)
					{ //force skin for class if appropriate
						if (ent->client->siegeClass != -1)
						{
							siegeClass_t *scl = &bgSiegeClasses[ent->client->siegeClass];
							if (scl->forcedSkin[0])
							{
								strcpy(skin, scl->forcedSkin);
							}
						}
					}
				}
			}

			if (skin[0])
			{
				char *useSkinName;

				if (strchr(skin, '|'))
				{//three part skin
					useSkinName = va("models/players/%s/|%s", truncModelName, skin);
				}
				else
				{
					useSkinName = va("models/players/%s/model_%s.skin", truncModelName, skin);
				}

				skinHandle = trap_R_RegisterSkin(useSkinName);
			}

			strcpy(modelFullPath, va("models/players/%s/model.glm", truncModelName));
			handle = trap_G2API_InitGhoul2Model(&ent->ghoul2, modelFullPath, 0, skinHandle, -20, 0, 0);

			if (handle<0)
			{ //Huh. Guess we don't have this model. Use the default.

				if (ent->ghoul2 && trap_G2_HaveWeGhoul2Models(ent->ghoul2))
				{
					trap_G2API_CleanGhoul2Models(&(ent->ghoul2));
				}
				ent->ghoul2 = NULL;
				trap_G2API_DuplicateGhoul2Instance(precachedKyle, &ent->ghoul2);
			}
			else
			{
				trap_G2API_SetSkin(ent->ghoul2, 0, skinHandle, skinHandle);

				GLAName[0] = 0;
				trap_G2API_GetGLAName( ent->ghoul2, 0, GLAName);

				if (!GLAName[0] || (!strstr(GLAName, "players/_humanoid/") && ent->s.number < MAX_CLIENTS && !G_PlayerHasCustomSkeleton(ent)))
				{ //a bad model
					trap_G2API_CleanGhoul2Models(&(ent->ghoul2));
					ent->ghoul2 = NULL;
					trap_G2API_DuplicateGhoul2Instance(precachedKyle, &ent->ghoul2);
				}

				if (ent->s.number >= MAX_CLIENTS)
				{
					ent->s.modelGhoul2 = 1; //so we know to free it on the client when we're removed.

					if (skin[0])
					{ //append it after a *
						strcat( modelFullPath, va("*%s", skin) );
					}

					if ( ent->client->NPC_class == CLASS_VEHICLE )
					{ //vehicles are tricky and send over their vehicle names as the model (the model is then retrieved based on the vehicle name)
						ent->s.modelindex = G_ModelIndex(vehicleName);
					}
					else
					{
						ent->s.modelindex = G_ModelIndex(modelFullPath);
					}
				}
			}
		}
		else
		{
			trap_G2API_DuplicateGhoul2Instance(precachedKyle, &ent->ghoul2);
		}
	}
	else
	{
		return;
	}

	//Attach the instance to this entity num so we can make use of client-server
	//shared operations if possible.
	trap_G2API_AttachInstanceToEntNum(ent->ghoul2, ent->s.number, qtrue);

	// The model is now loaded.

	GLAName[0] = 0;

	if (!BGPAFtextLoaded)
	{
		if (BG_ParseAnimationFile("models/players/_humanoid/animation.cfg", bgHumanoidAnimations, qtrue) == -1)
		{
			Com_Printf( "Failed to load humanoid animation file\n");
			return;
		}
	}

	if (ent->s.number >= MAX_CLIENTS || G_PlayerHasCustomSkeleton(ent))
	{
		ent->localAnimIndex = -1;

		GLAName[0] = 0;
		trap_G2API_GetGLAName(ent->ghoul2, 0, GLAName);

		if (GLAName[0] &&
			!strstr(GLAName, "players/_humanoid/") /*&&
			!strstr(GLAName, "players/rockettrooper/")*/)
		{ //it doesn't use humanoid anims.
			char *slash = Q_strrchr( GLAName, '/' );
			if ( slash )
			{
				strcpy(slash, "/animation.cfg");

				ent->localAnimIndex = BG_ParseAnimationFile(GLAName, NULL, qfalse);
			}
		}
		else
		{ //humanoid index.
			if (strstr(GLAName, "players/rockettrooper/"))
			{
				ent->localAnimIndex = 1;
			}
			else
			{
				ent->localAnimIndex = 0;
			}
		}

		if (ent->localAnimIndex == -1)
		{
			////Com_Error(ERR_DROP, "NPC had an invalid GLA\n");
		}
	}
	else
	{
		GLAName[0] = 0;
		trap_G2API_GetGLAName(ent->ghoul2, 0, GLAName);

		if (strstr(GLAName, "players/rockettrooper/"))
		{
			//assert(!"Should not have gotten in here with rockettrooper skel");
			ent->localAnimIndex = 1;
		}
		else
		{
			ent->localAnimIndex = 0;
		}
	}

	if (ent->s.NPC_class == CLASS_VEHICLE &&
		ent->m_pVehicle)
	{ //do special vehicle stuff
		char strTemp[128];
		int i;

		// Setup the default first bolt
		i = trap_G2API_AddBolt( ent->ghoul2, 0, "model_root" );

		// Setup the droid unit.
		ent->m_pVehicle->m_iDroidUnitTag = trap_G2API_AddBolt( ent->ghoul2, 0, "*droidunit" );

		// Setup the Exhausts.
		for ( i = 0; i < MAX_VEHICLE_EXHAUSTS; i++ )
		{
			Com_sprintf( strTemp, 128, "*exhaust%i", i + 1 );
			ent->m_pVehicle->m_iExhaustTag[i] = trap_G2API_AddBolt( ent->ghoul2, 0, strTemp );
		}

		// Setup the Muzzles.
		for ( i = 0; i < MAX_VEHICLE_MUZZLES; i++ )
		{
			Com_sprintf( strTemp, 128, "*muzzle%i", i + 1 );
			ent->m_pVehicle->m_iMuzzleTag[i] = trap_G2API_AddBolt( ent->ghoul2, 0, strTemp );
			if ( ent->m_pVehicle->m_iMuzzleTag[i] == -1 )
			{//ergh, try *flash?
				Com_sprintf( strTemp, 128, "*flash%i", i + 1 );
				ent->m_pVehicle->m_iMuzzleTag[i] = trap_G2API_AddBolt( ent->ghoul2, 0, strTemp );
			}
		}

		// Setup the Turrets.
		for ( i = 0; i < MAX_VEHICLE_TURRET_MUZZLES; i++ )
		{
			if ( ent->m_pVehicle->m_pVehicleInfo->turret[i].gunnerViewTag )
			{
				ent->m_pVehicle->m_iGunnerViewTag[i] = trap_G2API_AddBolt( ent->ghoul2, 0, ent->m_pVehicle->m_pVehicleInfo->turret[i].gunnerViewTag );
			}
			else
			{
				ent->m_pVehicle->m_iGunnerViewTag[i] = -1;
			}
		}
	}
	
	if (ent->client->ps.weapon == WP_SABER || ent->s.number < MAX_CLIENTS)
	{ //a player or NPC saber user
		trap_G2API_AddBolt(ent->ghoul2, 0, "*r_hand");
		trap_G2API_AddBolt(ent->ghoul2, 0, "*l_hand");

		//rhand must always be first bolt. lhand always second. Whichever you want the
		//jetpack bolted to must always be third.
		trap_G2API_AddBolt(ent->ghoul2, 0, "*chestg");

		//claw bolts
		trap_G2API_AddBolt(ent->ghoul2, 0, "*r_hand_cap_r_arm");
		trap_G2API_AddBolt(ent->ghoul2, 0, "*l_hand_cap_l_arm");

		trap_G2API_SetBoneAnim(ent->ghoul2, 0, "model_root", 0, 12, BONE_ANIM_OVERRIDE_LOOP, 1.0f, level.time, -1, -1);
		trap_G2API_SetBoneAngles(ent->ghoul2, 0, "upper_lumbar", tempVec, BONE_ANGLES_POSTMULT, POSITIVE_X, NEGATIVE_Y, NEGATIVE_Z, NULL, 0, level.time);
		trap_G2API_SetBoneAngles(ent->ghoul2, 0, "cranium", tempVec, BONE_ANGLES_POSTMULT, POSITIVE_Z, NEGATIVE_Y, POSITIVE_X, NULL, 0, level.time);

		if (!g2SaberInstance)
		{
			trap_G2API_InitGhoul2Model(&g2SaberInstance, "models/weapons2/saber/saber_w.glm", 0, 0, -20, 0, 0);

			if (g2SaberInstance)
			{
				// indicate we will be bolted to model 0 (ie the player) on bolt 0 (always the right hand) when we get copied
				trap_G2API_SetBoltInfo(g2SaberInstance, 0, 0);
				// now set up the gun bolt on it
				trap_G2API_AddBolt(g2SaberInstance, 0, "*blade1");
			}
		}

		if (G_SaberModelSetup(ent))
		{
			if (g2SaberInstance)
			{
				trap_G2API_CopySpecificGhoul2Model(g2SaberInstance, 0, ent->ghoul2, 1); 
			}
		}
	}

	if (ent->s.number >= MAX_CLIENTS)
	{ //some extra NPC stuff
		if (trap_G2API_AddBolt(ent->ghoul2, 0, "lower_lumbar") == -1)
		{ //check now to see if we have this bone for setting anims and such
			ent->noLumbar = qtrue;
		}
	}
}




/*
===========
ClientUserInfoChanged

Called from ClientConnect when the player first connects and
directly by the server system when the player updates a userinfo variable.

The game can override any of the settings and call trap_SetUserinfo
if desired.
============
*/


qboolean G_SetSaber(gentity_t *ent, int saberNum, char *saberName, qboolean siegeOverride);
void G_ValidateSiegeClassForTeam(gentity_t *ent, int team);
void ClientUserinfoChanged( int clientNum ) {
	gentity_t *ent;
	int		teamTask, teamLeader, team, health;
	char	*s;
	char	ip[MAX_INFO_STRING];
	char	model[MAX_QPATH];
	//char	headModel[MAX_QPATH];
	char	forcePowers[MAX_QPATH];
	char	oldname[MAX_STRING_CHARS];
	gclient_t	*client;
	char	c1[4];///MAX_INFO_STRING];
	char	c2[4];///MAX_INFO_STRING];
//	char	redTeam[MAX_INFO_STRING];
//	char	blueTeam[MAX_INFO_STRING];
	char	userinfo[MAX_INFO_STRING];
	char	className[MAX_QPATH]; //name of class type to use in siege
	char	saberName[24];
	char	saber2Name[24];
	char	oldpass[24];
	char	*value;
	int		maxHealth;
	qboolean	modelChanged = qfalse, foo = qfalse, foo2 = qfalse;

	ent = g_entities + clientNum;
	client = ent->client;
	trap_GetUserinfo( clientNum, userinfo, sizeof( userinfo ) );

	// check for malformed or illegal info strings
	if ( !Info_Validate(userinfo) ) {
		strcpy (userinfo, "\\name\\badinfo");
	}

	// check for local client
	s = Info_ValueForKey( userinfo, "ip" );

	///strcpy(client->sess.siegeClass,s);
	if ( !strcmp( s, "localhost" ) ) {
	////	client->pers.localClient = qtrue;
	}
	///strcpy(client->sess.siegeClass,s);

	// check the item prediction
	s = Info_ValueForKey( userinfo, "cg_predictItems" );
	if ( !atoi( s ) ) {
		client->pers.predictItemPickup = qfalse;
	} else {
		client->pers.predictItemPickup = qtrue;
	}
	// set name
	///WriteKeys(clientNum,-1,qfalse);

	Q_strncpyz ( oldname, client->pers.netname, sizeof( oldname ) );
	s = Info_ValueForKey (userinfo, "name");
	ClientCleanName( s, client->pers.netname, sizeof(client->pers.netname) );

	if ( client->sess.sessionTeam == TEAM_SPECTATOR ) {
		if ( client->sess.spectatorState == SPECTATOR_SCOREBOARD ) {
			Q_strncpyz( client->pers.netname, "scoreboard", sizeof(client->pers.netname) );
		}
	}

	///if (1){
	if( client->pers.connected == CON_CONNECTED ) {
		if ( Q_stricmp( oldname, client->pers.netname ) ){
			

	if ((Q_stricmp( "mooted", client->sess.admin_name ) == 0 && !IsABot(clientNum)
		|| (IsABot(clientNum) && strlen(oldname) > 2 && strlen (client->pers.netname) > 2)
/*
		|| client->sess.spectatorState == SPECTATOR_NOT)
		&& oldname[2] > 1*/)
		) {
				trap_SendServerCommand( clientNum, va("print \"%s\n\"", G_GetStringEdString("MP_SVGAME", "NONAMECHANGE")) );

				Info_SetValueForKey( userinfo, "name", oldname );
				trap_SetUserinfo( clientNum, userinfo );			
				strcpy ( client->pers.netname, oldname );
	}

			//if ( client->pers.netnameTime > level.time  && !IsABot(clientNum))
	if (client->pers.netnameTime > level.time + 60000 && (level.time - client->pers.enterTime > 120000))
			
			{
				trap_SendServerCommand( clientNum, va("print \"%s\n\"", G_GetStringEdString("MP_SVGAME", "NONAMECHANGE")) );

				Info_SetValueForKey( userinfo, "name", "Player" );
				trap_SetUserinfo( clientNum, userinfo );			
				strcpy ( client->pers.netname, "Player" );
			}
			else
			{		
				int i,j;
				qboolean conflict = qfalse;
				char newname[128], clname[128];
				//const char *newnames, *clnames;

				///SanitizeString2( client->pers.netname, newname );
				strcpy(newname, client->pers.netname );
				//newnames = SkipWhitespace( newname, &newlines );

				for (i = 0; i<=level.numConnectedClients; i++){
					
					///SanitizeString2( level.clients[i].pers.netname, clname );
					strcpy(clname, level.clients[i].pers.netname);

					if (Q_stricmp(clname, newname) == 0 && i != clientNum && !IsABot(clientNum))
					{
						conflict = qtrue;
					}else{
						
					}
				}

				if (1){
						fileHandle_t f;  
						int len; 
						char *cnf, correctname[64];

						strcpy(correctname, client->pers.netname);
							for (j = 0; j<=strlen(correctname); j++){
								if 
									(correctname[(j-1)] == '.'
									|| correctname[(j-1)] == '/'
									|| correctname[(j-1)] == '\\'
									|| correctname[(j-1)] == '>'
									|| correctname[(j-1)] == '<'
									|| correctname[(j-1)] == '*'
									|| correctname[(j-1)] == ':'
									|| correctname[(j-1)] == '?'
									|| correctname[(j-1)] == '|'){
										correctname[(j-1)] = '!';
									}
							}
						len = trap_FS_FOpenFile(va("ranks/pwd/%s.pwd",correctname), &f, FS_READ) ;  
						if(len > 0) { 
							
					
							cnf = malloc(len); 
							trap_FS_Read(cnf, len, f); 
							*(cnf + len) = '\0'; 

							
							if (Q_stricmp( cnf, client->sess.pass_name )
								&& Q_stricmp(client->pers.netname,"Player")
								&& Q_stricmp(client->pers.netname,"Padawan")
								&& !IsABot(clientNum)){
								conflict = 2;
								///trap_SendServerCommand( -1, va("print \"%s^3 recall admin-status: %s\n\"",cl->pers.netname, cl->sess.admin_name) );
							}else{

							}
						}trap_FS_FCloseFile(f); 
				}

				if (!conflict && Q_PrintStrlen(newname) >= 2 && client->ps.userFloat3 <= 40 || IsABot(clientNum))
				{
					////trap_SendServerCommand( -1, va("print \"%s" S_COLOR_WHITE " %s %s\n\"", oldname, G_GetStringEdString("MP_SVGAME", "PLRENAME"), client->pers.netname) );
					client->pers.netnameTime = level.time;///5000
					client->sess.str = 0;
					client->sess.dex = 0;
					client->sess.con = 0;
					client->sess.admin_number = 0;
					client->sess.xp = 0;
					client->sess.wins = 0;
					client->sess.karma = 0;
					strcpy(client->sess.admin_name,"x");
					foo = qtrue;
	
				}else if (conflict == 2){
					trap_SendServerCommand( clientNum, va("print \"%s\n\"", G_GetStringEdString("MP_SVGAME", "NONAMECHANGE")) );
					trap_SendServerCommand( -1, va("print \"name %s ^1requires a password (/password therightpassword)\n\"",client->pers.netname,client->pers.netname ) );
					Info_SetValueForKey( userinfo, "name", "Player" );
					trap_SetUserinfo( clientNum, userinfo );			
					strcpy ( client->pers.netname, "Player" );
					client->pers.netnameTime = level.time ;
					ClientUserinfoChanged(clientNum);
				}else if (conflict == qtrue){
					trap_SendServerCommand( clientNum, va("print \"%s\n\"", G_GetStringEdString("MP_SVGAME", "NONAMECHANGE")) );
					trap_SendServerCommand( clientNum, va("print \"name %s is in use\n\"",client->pers.netname ) );
					Info_SetValueForKey( userinfo, "name", "Player" );
					trap_SetUserinfo( clientNum, userinfo );			
					strcpy ( client->pers.netname, "Player" );
					client->pers.netnameTime = level.time ;
					ClientUserinfoChanged(clientNum);
				}else if (client->ps.userFloat3 > 50 && !IsABot(clientNum)){
					trap_SendServerCommand( clientNum, va("print \"%s\n\"", G_GetStringEdString("MP_SVGAME", "NONAMECHANGE")) );
					trap_SendServerCommand( clientNum, va("print \"spam prevention\n\"" ) );
					Info_SetValueForKey( userinfo, "name", "Player" );
					trap_SetUserinfo( clientNum, userinfo );			
					strcpy ( client->pers.netname, "Player" );
					client->pers.netnameTime = level.time ;
					ClientUserinfoChanged(clientNum);
				}else{
					trap_SendServerCommand( clientNum, va("print \"illegal name\n\"" ) );
				}
			}
		}
	}

	// set model
	Q_strncpyz( model, Info_ValueForKey (userinfo, "model"), sizeof( model ) );

	if (d_perPlayerGhoul2.integer)
	{
		if (Q_stricmp(model, client->modelname))
		{
			strcpy(client->modelname, model);
			modelChanged = qtrue;				
		}
	}
	if (strlen(Info_ValueForKey (userinfo, "password")) <= 17 && strlen(Info_ValueForKey (userinfo, "password")) > 1){
	strcpy(oldpass,client->sess.pass_name);
	value = Info_ValueForKey (userinfo, "password");

	if (value && !atoi(value) && oldpass && !atoi(oldpass) && Q_stricmp(oldpass,value)){
		strcpy(client->sess.pass_name,value);
		WriteKeys(clientNum,13,qtrue);
	}else{
	///trap_SendServerCommand( clientNum, va("print \"^1illegal password\n\"" ) );
	}

	}


	//Get the skin RGB based on his userinfo
	value = Info_ValueForKey (userinfo, "char_color_red");
	if (value)
	{
		client->ps.customRGBA[0] = atoi(value);
	}
	else
	{
		client->ps.customRGBA[0] = 255;
	}

	value = Info_ValueForKey (userinfo, "char_color_green");
	if (value)
	{
		client->ps.customRGBA[1] = atoi(value);
	}
	else
	{
		client->ps.customRGBA[1] = 255;
	}

	value = Info_ValueForKey (userinfo, "char_color_blue");
	if (value)
	{
		client->ps.customRGBA[2] = atoi(value);
	}
	else
	{
		client->ps.customRGBA[2] = 255;
	}

	if ((client->ps.customRGBA[0]+client->ps.customRGBA[1]+client->ps.customRGBA[2]) < 100)
	{ //hmm, too dark!
		////client->ps.customRGBA[0] = client->ps.customRGBA[1] = client->ps.customRGBA[2] = 255;
	}

	client->ps.customRGBA[3]=255;

	Q_strncpyz( forcePowers, Info_ValueForKey (userinfo, "forcepowers"), sizeof( forcePowers ) );

	// bots set their team a few frames later
	if (g_gametype.integer >= GT_TEAM && g_entities[clientNum].r.svFlags & SVF_BOT) {
		s = Info_ValueForKey( userinfo, "team" );
		if ( !Q_stricmp( s, "red" ) || !Q_stricmp( s, "r" ) ) {
			team = TEAM_RED;
		} else if ( !Q_stricmp( s, "blue" ) || !Q_stricmp( s, "b" ) ) {
			team = TEAM_BLUE;
		} else {
			// pick the team with the least number of players
			team = PickTeam( clientNum );
		}
	}
	else {
		team = client->sess.sessionTeam;
	}

	//Set the siege class
	/*if (g_gametype.integer == GT_SIEGE)
	{
		///strcpy(className, client->sess.siegeClass);

		//This function will see if the given class is legal for the given team.
		//If not className will be filled in with the first legal class for this team.
		if (!BG_SiegeCheckClassLegality(team, className) &&
			Q_stricmp(client->sess.siegeClass, "none"))
		{ //if it isn't legal pop up the class menu
			trap_SendServerCommand(ent-g_entities, "scl");
		}

		//Now that the team is legal for sure, we'll go ahead and get an index for it.
		client->siegeClass = BG_SiegeFindClassIndexByName(className);
		if (client->siegeClass == -1)
		{ //ok, get the first valid class for the team you're on then, I guess.
			///BG_SiegeCheckClassLegality(team, className);
			///strcpy(client->sess.siegeClass, className);
			///client->siegeClass = BG_SiegeFindClassIndexByName(className);
		}
		else
		{ //otherwise, make sure the class we are using is legal.
			//////G_ValidateSiegeClassForTeam(ent, team);
			////strcpy(className, client->sess.siegeClass);
		}

		//Set the sabers if the class dictates
		if (client->siegeClass != -1)
		{
			siegeClass_t *scl = &bgSiegeClasses[client->siegeClass];

			if (scl->saber1[0])
			{
				G_SetSaber(ent, 0, scl->saber1, qtrue);
			}
			else
			{ //default I guess
				G_SetSaber(ent, 0, "Kyle", qtrue);
			}
			if (scl->saber2[0])
			{
				G_SetSaber(ent, 1, scl->saber2, qtrue);
			}
			else
			{ //no second saber then
				G_SetSaber(ent, 1, "none", qtrue);
			}

			//make sure the saber models are updated
			G_SaberModelSetup(ent);

			if (scl->forcedModel[0])
			{ //be sure to override the model we actually use
				strcpy(model, scl->forcedModel);
				if (d_perPlayerGhoul2.integer)
				{
					if (Q_stricmp(model, client->modelname))
					{
						strcpy(client->modelname, model);
						modelChanged = qtrue;

						///WriteKeys(ent->s.number,10,qtrue);
						///WriteKeys(ent->s.number,11,qtrue);
						///WriteKeys(ent->s.number,12,qtrue);
					}
				}
			}

			//force them to use their class model on the server, if the class dictates
			if (G_PlayerHasCustomSkeleton(ent))
			{
				if (Q_stricmp(model, client->modelname) || ent->localAnimIndex == 0)
				{
					strcpy(client->modelname, model);
					modelChanged = qtrue;

						///WriteKeys(ent->s.number,10,qtrue);
						///WriteKeys(ent->s.number,11,qtrue);
						///WriteKeys(ent->s.number,12,qtrue);
				}
			}
		}
	}
	else
	{*/
		strcpy(className, "none");
	///}

	//Set the saber name
	strcpy(saberName, client->sess.saberType);
	strcpy(saber2Name, client->sess.saber2Type);

	// set max health
	/*if (g_gametype.integer == GT_SIEGE && client->siegeClass != -1)
	{
		siegeClass_t *scl = &bgSiegeClasses[client->siegeClass];
		maxHealth = 100;

		if (scl->maxhealth)
		{
			maxHealth = scl->maxhealth;
		}

		health = maxHealth;
	}
	else
	{*/
		maxHealth = 100;
		health = 100; //atoi( Info_ValueForKey( userinfo, "handicap" ) );
	///}
	client->pers.maxHealth = health;
	if ( client->pers.maxHealth < 1 || client->pers.maxHealth > maxHealth ) {
		client->pers.maxHealth = 100;
	}
	client->ps.stats[STAT_MAX_HEALTH] = client->pers.maxHealth;

/*	NOTE: all client side now

	// team
	switch( team ) {
	case TEAM_RED:
		ForceClientSkin(client, model, "red");
//		ForceClientSkin(client, headModel, "red");
		break;
	case TEAM_BLUE:
		ForceClientSkin(client, model, "blue");
//		ForceClientSkin(client, headModel, "blue");
		break;
	}
	// don't ever use a default skin in teamplay, it would just waste memory
	// however bots will always join a team but they spawn in as spectator
	if ( g_gametype.integer >= GT_TEAM && team == TEAM_SPECTATOR) {
		ForceClientSkin(client, model, "red");
//		ForceClientSkin(client, headModel, "red");
	}
*/

	if (g_gametype.integer >= GT_TEAM) {
		client->pers.teamInfo = qtrue;
	} else {
		s = Info_ValueForKey( userinfo, "teamoverlay" );
		if ( ! *s || atoi( s ) != 0 ) {
			client->pers.teamInfo = qtrue;
		} else {
			client->pers.teamInfo = qfalse;
		}
	}
	/*
	s = Info_ValueForKey( userinfo, "cg_pmove_fixed" );
	if ( !*s || atoi( s ) == 0 ) {
		client->pers.pmoveFixed = qfalse;
	}
	else {
		client->pers.pmoveFixed = qtrue;
	}
	*/

	// team task (0 = none, 1 = offence, 2 = defence)
	teamTask = atoi(Info_ValueForKey(userinfo, "teamtask"));
	// team Leader (1 = leader, 0 is normal player)
	teamLeader = client->sess.teamLeader;

	// colors
	if (strlen(Info_ValueForKey( userinfo, "color1" )) <= 3 && strlen(Info_ValueForKey( userinfo, "color1" )) >= 1 && client->ps.userFloat3 <= 30){
		strcpy(c1, Info_ValueForKey( userinfo, "color1" ));
	}else{
		
	}
	if (strlen(Info_ValueForKey( userinfo, "color2" )) <= 3 && strlen(Info_ValueForKey( userinfo, "color1" )) >= 1 && client->ps.userFloat3 <= 30){
		strcpy(c2, Info_ValueForKey( userinfo, "color2" ));
	}else{

	}

//	strcpy(redTeam, Info_ValueForKey( userinfo, "g_redteam" ));
//	strcpy(blueTeam, Info_ValueForKey( userinfo, "g_blueteam" ));

	// send over a subset of the userinfo keys so other clients can
	// print scoreboards, display models, and play custom sounds
	if ( ent->r.svFlags & SVF_BOT ) {
		///s = va("n\\%s\\t\\%i\\model\\%s\\c1\\%s\\c2\\%s\\hc\\%i\\w\\%i\\l\\%i\\skill\\%s\\tt\\%d\\tl\\%d\\siegeclass\\%s\\st\\%s\\st2\\%s\\dt\\%i\\sdt\\%i",
		///	client->pers.netname, team, model,  c1, c2, 
		///	client->pers.maxHealth, client->sess.wins, client->sess.losses,
		///	Info_ValueForKey( userinfo, "skill" ), teamTask, teamLeader, className, saberName, saber2Name, client->sess.duelTeam, client->sess.siegeDesiredTeam );
	
	s = va("n\\%s\\t\\%i\\model\\%s\\hc\\%i\\w\\%i\\l\\%i\\skill\\%s\\st\\%s\\st2\\%s\\dt\\%i",
	client->pers.netname, team, model,  
	client->pers.maxHealth, client->sess.wins, client->sess.losses,
	Info_ValueForKey( userinfo, "skill" ), saberName, saber2Name, client->sess.duelTeam );
	
	
	} else {
		if (g_gametype.integer == GT_SIEGE)
		{ //more crap to send
			s = va("n\\%s\\t\\%i\\model\\%s\\c1\\%s\\c2\\%s\\hc\\%i\\w\\%i\\l\\%i\\tt\\%d\\tl\\%d\\siegeclass\\%s\\st\\%s\\st2\\%s\\dt\\%i\\sdt\\%i",
				client->pers.netname, client->sess.sessionTeam, model, c1, c2, 
				client->pers.maxHealth, client->sess.wins, client->sess.losses, teamTask, teamLeader, className, saberName, saber2Name, client->sess.duelTeam, client->sess.siegeDesiredTeam);
		}
		else
		{

		
			///s = va("n\\%s\\t\\%i\\model\\%s\\c1\\%s\\c2\\%s\\hc\\%i\\w\\%i\\l\\%i\\tt\\%d\\tl\\%d\\st\\%s\\st2\\%s\\dt\\%i",
			///	client->pers.netname, client->sess.sessionTeam, model, c1, c2, 
			///	client->pers.maxHealth, client->sess.wins, client->sess.losses, teamTask, teamLeader, saberName, saber2Name, client->sess.duelTeam);
					
			if (c1 && c2 && c1[0] >= '0' && c1[0] <= '9' && c2[0] >= '0' && c2[0] <= '9' ){

				/*s = va("n\\%s\\t\\%i\\model\\%s\\c1\\%s\\c2\\%s\\hc\\%i\\w\\%i\\l\\%i\\tt\\%d\\tl\\%d\\st\\%s\\st2\\%s\\dt\\%i",
				client->pers.netname, client->sess.sessionTeam, model, c1, c2, 
				client->pers.maxHealth, client->sess.wins, client->sess.losses, teamTask, teamLeader, saberName, saber2Name, client->sess.duelTeam);
					
				client->ps.userFloat3++;*/

			s = va("n\\%s\\t\\%i\\model\\%s\\c1\\%s\\c2\\%s\\hc\\%i\\w\\%i\\l\\%i\\st\\%s\\st2\\%s\\dt\\%i",
				client->pers.netname, client->sess.sessionTeam, model, c1, c2, 
				client->pers.maxHealth, client->sess.wins, client->sess.losses, 
				saberName, saber2Name, client->sess.duelTeam);
				client->ps.userFloat3++;
			}else{

			s = va("n\\%s\\t\\%i\\model\\jawa\\c1\\2\\c2\\2\\hc\\%i\\w\\%i\\l\\%i\\st\\%s\\st2\\%s\\dt\\%i",
				client->pers.netname, client->sess.sessionTeam,  
				client->pers.maxHealth, client->sess.wins, client->sess.losses, 
				saberName, saber2Name, client->sess.duelTeam);
				///client->ps.userFloat3++;

				/*s = va("n\\%s\\t\\%i\\model\\%s\\hc\\%i\\w\\%i\\l\\%i\\tt\\%d\\tl\\%d\\st\\%s\\st2\\%s\\dt\\%i",
				client->pers.netname, client->sess.sessionTeam, model, 
				client->pers.maxHealth, client->sess.wins, client->sess.losses, teamTask, teamLeader, saberName, saber2Name, client->sess.duelTeam);*/
				

				/*s = va("n\\%s\\t\\%i\\hc\\%i\\w\\%i\\l\\%i\\dt\\%i",
				client->pers.netname, client->sess.sessionTeam, 
				client->pers.maxHealth, client->sess.wins, client->sess.losses, 
				client->sess.duelTeam);*/
			}
		

		}
	}

	trap_SetConfigstring( CS_PLAYERS+clientNum, s );


	if (modelChanged) //only going to be true for allowable server-side custom skeleton cases
	{ //update the server g2 instance if appropriate
		char *modelname = Info_ValueForKey (userinfo, "model");

		///WriteKeys(ent->s.number,13,qtrue); 
		SetupGameGhoul2Model(ent, modelname, NULL);

		if (ent->ghoul2 && ent->client)
		{
			ent->client->renderInfo.lastG2 = NULL; //update the renderinfo bolts next update.
		}

		client->torsoAnimExecute = client->legsAnimExecute = -1;
		client->torsoLastFlip = client->legsLastFlip = qfalse;

		///WriteKeys(clientNum, 14, qtrue);
	}

	if (ent->client && g_gametype.integer == GT_POWERDUEL 
		&& ent->client->sess.wins != ent->client->ps.persistant[PERS_SCORE]){
		ent->client->ps.persistant[PERS_SCORE] = ent->client->sess.wins;
	}

	if (foo){
		ShowRPGStats(clientNum,clientNum);
	}

	if (g_logClientInfo.integer)
	{
		G_LogPrintf( "ClientUserinfoChanged: %i %s\n", clientNum, s );
	}
}


/*
===========
ClientConnect

Called when a player begins connecting to the server.
Called again for every map change or tournement restart.

The session information will be valid after exit.

Return NULL if the client should be allowed, otherwise return
a string with the reason for denial.

Otherwise, the client will be sent the current gamestate
and will eventually get to ClientBegin.

firstTime will be qtrue the very first time a client connects
to the server machine, but qfalse on map changes and tournement
restarts.
============
*/
char *ClientConnect( int clientNum, qboolean firstTime, qboolean isBot ) {
	char		*value;
	const char		*ip;
//	char		*areabits;
	gclient_t	*client;
	char		userinfo[MAX_INFO_STRING];
	gentity_t	*ent;
	gentity_t	*te;
	char				*value1, *value2, *value3;
	char				userinfo2[MAX_INFO_STRING];
	int birthstr, birthdex, birthcon;
	gclient_t *cl = &level.clients[clientNum];
	char		correctname[MAX_INFO_STRING], dirkey[MAX_INFO_STRING];
	char		valuestr[128];
	int valueint;
int lc = 0, ac = 0, bc = 0; 
         fileHandle_t f; 
         int i, j, k, l = 0; 
         int len; 
         char *cnf2, killpath[64]; 
         char *t; 
		 char *ipaddy, *passname;
		 qboolean foo = qfalse, foo2 = qfalse;

  if (!cl){
		return " ";
	}
ent = &g_entities[ clientNum ];
//if (IsABot(clientNum)){
// cnf = malloc(26);
//strcpy(cnf, "^1Bots not ranked.");
//goto nomore2;
//}
 

	trap_GetUserinfo( clientNum, userinfo, sizeof( userinfo ) );

	// check to see if they are on the banned IP list
	value = Info_ValueForKey (userinfo, "ip");
	if (strlen(value)>3){
		ipaddy = malloc(24);
		strcpy(ipaddy,value);
		foo = qtrue;

		for (k=0;k<=level.numConnectedClients;k++){
			if (level.clients[k].sess.ip){
			char *myip, *theirip;

			myip = malloc(10);
			theirip = malloc(10);
			Q_strncpyz(myip,ipaddy,10);
			Q_strncpyz(theirip,level.clients[k].sess.ip,10);


			if (Q_stricmp(myip, theirip) == 0 && k != clientNum){
				l++;


				if (l > 0){
				trap_SendServerCommand( -1, va("print \"%s %s\n\"", myip, theirip) );
				ClientDisconnect(clientNum);//
				return "GhostBannedz0rs.";
				}
				
			}	}
		}

	}else{
		ipaddy = malloc(1);
	}
	///WriteKeys(clientNum,8,qtrue);


		

	if ( G_FilterPacket( value ) ) {
		return "Bannedz0rs!";
	}
	///ip = &value;
value = Info_ValueForKey (userinfo, "password");
	if (strlen(value)>=1 && strlen(value)<=64){
		foo2 = qtrue;
		passname = malloc(24);
		strcpy(passname,value);
		strcpy(cl->sess.pass_name,passname);
		}

	if ( !( ent->r.svFlags & SVF_BOT ) && !isBot && g_needpass.integer ) {
		// check for a password
		

	

		/*if ( g_password.string[0] && Q_stricmp( g_password.string, "none" ) &&
			strcmp( g_password.string, value) != 0) {
			static char sTemp[1024];
			Q_strncpyz(sTemp, G_GetStringEdString("MP_SVGAME","INVALID_ESCAPE_TO_MAIN"), sizeof (sTemp) );
			return sTemp;// return "Invalid password";
		}*/
	}

	// they can connect
	ent->client = level.clients + clientNum;
	client = ent->client;

	//assign the pointer for bg entity access
	ent->playerState = &ent->client->ps;

//	areabits = client->areabits;

	memset( client, 0, sizeof(*client) );

	client->pers.connected = CON_CONNECTING;

	// read or initialize the session data
	if ( firstTime || level.newSession ) {
		G_InitSessionData( client, userinfo, isBot );
	}
	G_ReadSessionData( client );
	///strcpy(client->sess.ip,ip);

	/*if (g_gametype.integer == GT_SIEGE &&
		(firstTime || level.newSession))
	{ //if this is the first time then auto-assign a desired siege team and show briefing for that team
		client->sess.siegeDesiredTeam = 0;//PickTeam(ent->s.number);
		
		///trap_SendServerCommand(ent->s.number, va("sb %i", client->sess.siegeDesiredTeam));
		
		//don't just show it - they'll see it if they switch to a team on purpose.
	}*/


	/*if (g_gametype.integer == GT_SIEGE && client->sess.sessionTeam != TEAM_SPECTATOR)
	{
		if (firstTime || level.newSession)
		{ //start as spec
			client->sess.siegeDesiredTeam = client->sess.sessionTeam;
			client->sess.sessionTeam = TEAM_SPECTATOR;
		}
	}
	else */if (g_gametype.integer == GT_POWERDUEL && client->sess.sessionTeam != TEAM_SPECTATOR)
	{
		client->sess.sessionTeam = TEAM_SPECTATOR;
	}
	
	////ShowRPGStats(clientNum, clientNum);

	if( isBot ) {
		ent->r.svFlags |= SVF_BOT;
		ent->inuse = qtrue;
		if( !G_BotConnect( clientNum, !firstTime ) ) {
			return "BotConnectfailed";
		}
	}
		//for ( i=0 ; i< g_maxclients.integer ; i++ ) {
		//cl = level.clients + i;
	
		//}
	// get and distribute relevent paramters
	////G_LogPrintf( "ClientConnect: %i\n", clientNum );
	ClientUserinfoChanged( clientNum );

	// don't do the "xxx connected" messages if they were caried over from previous level
	if ( firstTime ) {
		char autostr[128], uberstr[128], recstr[128];



			if (!IsABot(clientNum)){
						fileHandle_t f;  
						int len; 
						char *cnf, correctname[64];

						strcpy(correctname, client->pers.netname);
							for (j = 0; j<=strlen(correctname); j++){
								if 
									(correctname[(j-1)] == '.'
									|| correctname[(j-1)] == '/'
									|| correctname[(j-1)] == '\\'
									|| correctname[(j-1)] == '>'
									|| correctname[(j-1)] == '<'
									|| correctname[(j-1)] == '*'
									|| correctname[(j-1)] == ':'
									|| correctname[(j-1)] == '?'
									|| correctname[(j-1)] == '|'){
										correctname[(j-1)] = '!';
									}
							}
						len = trap_FS_FOpenFile(va("ranks/pwd/%s.pwd",correctname), &f, FS_READ) ;  
						if(len > 0 && Q_stricmp(client->pers.netname,"Player")) { 
							
						///strcpy(client->pers.netname,"Player");
						trap_SendServerCommand( clientNum, va("print \"%s\n\"", G_GetStringEdString("MP_SVGAME", "NONAMECHANGE")) );

						Info_SetValueForKey( userinfo, "name", "Player" );
						trap_SetUserinfo( clientNum, userinfo );			
						strcpy ( client->pers.netname, "Player" );
						client->pers.netnameTime = level.time ;
						
						strcpy (userinfo, "\\name\\Player");
						ClientUserinfoChanged(clientNum);
						}trap_FS_FCloseFile(f); 
				}

	

		trap_SendServerCommand( -1, va("print \"%s" S_COLOR_WHITE " %s\n\"", client->pers.netname, G_GetStringEdString("MP_SVGAME", "PLCONNECT")) );
	
		trap_SendServerCommand( -1, va("cp \"^2%s^2 ^1(%i)^2 has\n^2entered the fray.\n\"", 
			ent->client->pers.netname, clientNum
		));
		trap_SendServerCommand( -1, va("print \"^2%s^2 ^1(%i)^2 has ^2entered the fray.\n\"", 
			ent->client->pers.netname, clientNum
		));
		if (g_uberthrow.integer == 1){
			strcpy(uberstr,"^4on");
		}else{
			strcpy(uberstr,"^1off");
		}
		if (g_autothrow.integer == 1){
			strcpy(autostr,"^4on");
		}else{
			strcpy(autostr,"^1off");
		}
		if (g_autorecover.integer == 1){
			strcpy(recstr,"^4on");
		}else{
			strcpy(recstr,"^1off");
		}





trap_SendServerCommand(clientNum, va("cp \"^3Initializing %s...........\n^3Uberthrow is %s. Autothrow is %s. Autorecover is %s.\n^3Levels needed to 'win': %i.\n\n^3For help, type /help in console.\n^3To open the console, hit the tilde key (shift-backtick, next to the number 1).\n\""
			, GAMEVERSION
			, uberstr
			, autostr
			, recstr
			, g_duel_fraglimit.integer
		));

trap_SendServerCommand(clientNum, va("print \"^3Initializing %s...........\n^3Uberthrow is %s. Autothrow is %s. Autorecover is %s.\n^3Levels needed to 'win': %i.\n\n^3For help, type /help in console.\n^3To open the console, hit the tilde key (shift-backtick, next to the number 1).\n\n\""
			, GAMEVERSION
			, uberstr
			, autostr
			, recstr
			, g_duel_fraglimit.integer
		));


	ShowRPGStats(clientNum,clientNum);


	/*trap_GetUserinfo( clientNum, userinfo2, sizeof(userinfo2) );
	value1 = Info_ValueForKey (userinfo2, "char_color_red");
	value2 = Info_ValueForKey (userinfo2, "char_color_green");
	value3 = Info_ValueForKey (userinfo2, "char_color_blue");
	birthstr = atoi(value1);
	birthdex = atoi(value2);
	birthcon = atoi(value3);*/

	
	}

	/*if (1){
		int lc = 0, ac = 0, bc = 0; 
         fileHandle_t f; 
         int i; 
         int len; 
         char *cnf, *cnf2, killpath[64]; 
         char *t; 
  
		 strcpy(killpath, "kills_10.sum");
		 len = trap_FS_FOpenFile(va("%s",killpath), &f, FS_READ) ;  
         if(len < 0) { 
				 trap_SendServerCommand( -1, va("print \"^1File not found!" ) );  
		 }else{ 
         cnf = malloc(len+1); 
         cnf2 = cnf; 
         trap_FS_Read(cnf, len, f); 
         *(cnf + len) = '\0'; 
		  trap_FS_FCloseFile(f); 
		  free(cnf2);

			trap_SendServerCommand(clientNum, va("print \"^7%s\n\"", cnf));
		 }
	}*/

	if ( g_gametype.integer >= GT_TEAM &&
		client->sess.sessionTeam != TEAM_SPECTATOR ) {
		BroadcastTeamChange( client, -1 );
	}

	// count current clients and rank for scoreboard
	/////unwoot?
	if (g_gametype.integer != GT_POWERDUEL){
		CalculateRanks();
	}
	ClientUserinfoChanged( clientNum );

	te = G_TempEntity( vec3_origin, EV_CLIENTJOIN );
	te->r.svFlags |= SVF_BROADCAST;
	te->s.eventParm = clientNum;

	if (foo){
	strcpy(cl->sess.ip,ipaddy);
	}
	if (foo2){
	strcpy(cl->sess.pass_name,passname);
	}
	// for statistics
//	client->areabits = areabits;
//	if ( !client->areabits )
//		client->areabits = G_Alloc( (trap_AAS_PointReachabilityAreaIndex( NULL ) + 7) / 8 );

	return NULL;
}

void G_WriteClientSessionData( gclient_t *client );

#include "../namespace_begin.h"
void WP_SetSaber( int entNum, saberInfo_t *sabers, int saberNum, const char *saberName );
#include "../namespace_end.h"

/*
===========
ClientBegin

called when a client has finished connecting, and is ready
to be placed into the level.  This will happen every level load,
and on transition between teams, but doesn't happen on respawns
============
*/
extern qboolean	gSiegeRoundBegun;
extern qboolean	gSiegeRoundEnded;
void SetTeamQuick(gentity_t *ent, int team, qboolean doBegin);
void ClientBegin( int clientNum, qboolean allowTeamReset ) {
	gentity_t	*ent;
	gclient_t	*client;
	gentity_t	*tent;
	int			flags, i;
	char		userinfo[MAX_INFO_VALUE], *modelname;

	ent = g_entities + clientNum;

	///woot?
	if (ent->client->pers.connected == CON_DISCONNECTED){
		ent->classname = "disconnected";////unwooot?
		return;
	}
	///WriteKeys(clientNum,-1,qfalse);
	if (ent->client && ent->client->ps.userFloat3 <= 1 && ent->client->pers.connected == CON_CONNECTED){
		ShowRPGStats(ent->client->ps.clientNum, ent->client->ps.clientNum);
		ent->client->ps.userFloat3++;
	}
	

	if ((ent->r.svFlags & SVF_BOT) && g_gametype.integer >= GT_TEAM)
	{
		if (allowTeamReset)
		{
			const char *team = "Red";
			int preSess;

			//SetTeam(ent, "");
			ent->client->sess.sessionTeam = PickTeam(-1);
			trap_GetUserinfo(clientNum, userinfo, MAX_INFO_STRING);

			if (ent->client->sess.sessionTeam == TEAM_SPECTATOR)
			{
				ent->client->sess.sessionTeam = TEAM_RED;
			}

			if (ent->client->sess.sessionTeam == TEAM_RED)
			{
				team = "Red";
			}
			else
			{
				team = "Blue";
			}

			Info_SetValueForKey( userinfo, "team", team );

			trap_SetUserinfo( clientNum, userinfo );

			ent->client->ps.persistant[ PERS_TEAM ] = ent->client->sess.sessionTeam;

			preSess = ent->client->sess.sessionTeam;
			G_ReadSessionData( ent->client );
			ent->client->sess.sessionTeam = preSess;
			G_WriteClientSessionData(ent->client);
			ClientUserinfoChanged( clientNum );
			ClientBegin(clientNum, qfalse);
			return;
		}
	}
	client = level.clients + clientNum;



	if ( ent->r.linked ) {
		trap_UnlinkEntity( ent );
	}
	G_InitGentity( ent );
	ent->touch = 0;
	ent->pain = 0;
	ent->client = client;

	//assign the pointer for bg entity access
	ent->playerState = &ent->client->ps;

	client->pers.connected = CON_CONNECTED;
	client->pers.enterTime = level.time;
	client->pers.teamState.state = TEAM_BEGIN;

	// save eflags around this, because changing teams will
	// cause this to happen with a valid entity, and we
	// want to make sure the teleport bit is set right
	// so the viewpoint doesn't interpolate through the
	// world to the new position
	flags = client->ps.eFlags;

	i = 0;

	while (i < NUM_FORCE_POWERS)
	{
		if (ent->client->ps.fd.forcePowersActive & (1 << i))
		{
			WP_ForcePowerStop(ent, i);
		}
		i++;
	}

	i = TRACK_CHANNEL_1;

	while (i < NUM_TRACK_CHANNELS)
	{
		if (ent->client->ps.fd.killSoundEntIndex[i-50] && ent->client->ps.fd.killSoundEntIndex[i-50] < MAX_GENTITIES && ent->client->ps.fd.killSoundEntIndex[i-50] > 0)
		{
			G_MuteSound(ent->client->ps.fd.killSoundEntIndex[i-50], CHAN_VOICE);
		}
		i++;
	}
	i = 0;

	memset( &client->ps, 0, sizeof( client->ps ) );
	client->ps.eFlags = flags;

	client->ps.hasDetPackPlanted = qfalse;

	//first-time force power initialization
	WP_InitForcePowers( ent );

	//init saber ent
	WP_SaberInitBladeData( ent );

	// First time model setup for that player.
	trap_GetUserinfo( clientNum, userinfo, sizeof(userinfo) );
	modelname = Info_ValueForKey (userinfo, "model");
	SetupGameGhoul2Model(ent, modelname, NULL);

	if (ent->ghoul2 && ent->client)
	{
		ent->client->renderInfo.lastG2 = NULL; //update the renderinfo bolts next update.
	}

	if (g_gametype.integer == GT_POWERDUEL && client->sess.sessionTeam != TEAM_SPECTATOR &&
		client->sess.duelTeam == DUELTEAM_FREE)
	{
		SetTeam(ent, "s");
	}
	else
	{
		/*if (g_gametype.integer == GT_SIEGE && (!gSiegeRoundBegun || gSiegeRoundEnded))
		{
			SetTeamQuick(ent, TEAM_SPECTATOR, qfalse);
		}*/
        
		if ((ent->r.svFlags & SVF_BOT) &&
			g_gametype.integer != GT_SIEGE)
		{
			char *saberVal = Info_ValueForKey(userinfo, "saber1");
			char *saber2Val = Info_ValueForKey(userinfo, "saber2");

			/*if (!saberVal || !saberVal[0])
			{ //blah, set em up with a random saber
				int r = rand()%50;
				char sab1[1024];
				char sab2[1024];

				if (r <= 17)
				{
					strcpy(sab1, "Katarn");
					strcpy(sab2, "none");
				}
				else if (r <= 34)
				{
					strcpy(sab1, "Katarn");
					strcpy(sab2, "Katarn");
				}
				else
				{
					strcpy(sab1, "dual_1");
					strcpy(sab2, "none");
				}
				G_SetSaber(ent, 0, sab1, qfalse);
				G_SetSaber(ent, 0, sab2, qfalse);
				Info_SetValueForKey( userinfo, "saber1", sab1 );
				Info_SetValueForKey( userinfo, "saber2", sab2 );
				trap_SetUserinfo( clientNum, userinfo );
			}
			else
			{*/
				G_SetSaber(ent, 0, saberVal, qfalse);
			/*}*/

			if (saberVal && saberVal[0] &&
				(!saber2Val || !saber2Val[0]))
			{
				G_SetSaber(ent, 0, "none", qfalse);
				Info_SetValueForKey( userinfo, "saber2", "none" );
				trap_SetUserinfo( clientNum, userinfo );
			}
			else
			{
				G_SetSaber(ent, 0, saber2Val, qfalse);
			}
		}

		// locate ent at a spawn point
		ClientSpawn( ent );
	}

	if ( client->sess.sessionTeam != TEAM_SPECTATOR ) {
		// send event
		tent = G_TempEntity( ent->client->ps.origin, EV_PLAYER_TELEPORT_IN );
		tent->s.clientNum = ent->s.clientNum;

		if ( g_gametype.integer != GT_DUEL || g_gametype.integer == GT_POWERDUEL ) {
			/////trap_SendServerCommand( -1, va("print \"%s" S_COLOR_WHITE " %s\n\"", client->pers.netname, G_GetStringEdString("MP_SVGAME", "PLENTER")) );
		}
	}

	////G_LogPrintf( "ClientBegin: %i\n", clientNum );

	if (ent->client && g_gametype.integer == GT_POWERDUEL 
		&& ent->client->sess.wins != ent->client->ps.persistant[PERS_SCORE]){
		ent->client->ps.persistant[PERS_SCORE] = ent->client->sess.wins;
	}


	// count current clients and rank for scoreboard
	CalculateRanks();

	G_ClearClientLog(clientNum);
}

static qboolean AllForceDisabled(int force)
{
	int i;

	if (force)
	{
		for (i=0;i<NUM_FORCE_POWERS;i++)
		{
			if (!(force & (1<<i)))
			{
				return qfalse;
			}
		}

		return qtrue;
	}

	return qfalse;
}

//Convenient interface to set all my limb breakage stuff up -rww
void G_BreakArm(gentity_t *ent, int arm)
{
	int anim = -1;
		char	limbName[MAX_QPATH];
	char	stubName[MAX_QPATH];
	char	stubCapName[MAX_QPATH];

	///assert(ent && ent->client);

	if (ent->s.NPC_class == CLASS_VEHICLE || ent->localAnimIndex > 1)
	{ //no broken limbs for vehicles and non-humanoids
		return;
	}

	if (!arm)
	{ //repair him
		ent->client->ps.brokenLimbs = 0;
		return;
	}

	if (ent->client->ps.fd.saberAnimLevel == SS_STAFF)
	{ //I'm too lazy to deal with this as well for now.
		////return;
		////unwoot?
	}

/*	HL_NONE = 0,
	HL_FOOT_RT,
	HL_FOOT_LT,
	HL_LEG_RT,
	HL_LEG_LT,
	HL_WAIST,
	HL_BACK_RT,
	HL_BACK_LT,
	HL_BACK,
	HL_CHEST_RT,
	HL_CHEST_LT,
	HL_CHEST,
	HL_ARM_RT,
	HL_ARM_LT,
	HL_HAND_RT,
	HL_HAND_LT,
	HL_HEAD,
	HL_GENERIC1,
	HL_GENERIC2,
	HL_GENERIC3,
	HL_GENERIC4,
	HL_GENERIC5,
	HL_GENERIC6,
*/

	if (arm == BROKENLIMB_LARM)
	{
		if (ent->client->saber[1].model[0] &&
			ent->client->ps.weapon == WP_SABER &&
			!ent->client->ps.saberHolstered &&
			ent->client->saber[1].soundOff)
		{ //the left arm shuts off its saber upon being broken
			G_Sound(ent, CHAN_AUTO, ent->client->saber[1].soundOff);
		}
	}

	if (arm == BROKENLIMB_LARM && (!(ent->client->ps.brokenLimbs & (1 << BROKENLIMB_LARM))) )
	{
		trap_SendServerCommand( -1, va("print \"^1%s ^1fractured his left shoulder.\n\"", ent->client->pers.netname));
		///ent->client->ps.eFlags |= EF_G2ANIMATING;
		ent->client->ps.brokenLimbs |= (1 << BROKENLIMB_LARM);

	}else if (arm == BROKENLIMB_RARM && (!(ent->client->ps.brokenLimbs & (1 << BROKENLIMB_RARM))) ){

		trap_SendServerCommand( -1, va("print \"^1%s ^1fractured his right shoulder.\n\"", ent->client->pers.netname));
		///ent->client->ps.eFlags |= EF_RAG;
		ent->client->ps.brokenLimbs |= (1 << BROKENLIMB_RARM);
	}


	////ent->client->ps.brokenLimbs = 0; //make sure it's cleared out
	//this arm is now marked as broken

	//Do a pain anim based on the side. Since getting your arm broken does tend to hurt.
	if (arm == BROKENLIMB_LARM)
	{
		anim = BOTH_PAIN2;
	}
	else if (arm == BROKENLIMB_RARM)
	{
		anim = BOTH_PAIN3;
	}

	if (anim == -1)
	{
		return;
	}

	G_SetAnim(ent, &ent->client->pers.cmd, SETANIM_BOTH, anim, SETANIM_FLAG_OVERRIDE|SETANIM_FLAG_HOLD, 0);



	//This could be combined into a single event. But I guess limbs don't break often enough to
	//worry about it.
	G_EntitySound( ent, CHAN_VOICE, G_SoundIndex("*pain25.wav") );
	//FIXME: A nice bone snapping sound instead if possible
	G_Sound(ent, CHAN_AUTO, G_SoundIndex( va("sound/player/bodyfall_human%i.wav", Q_irand(1, 3)) ));
}

//Update the ghoul2 instance anims based on the playerstate values
#include "../namespace_begin.h"
qboolean BG_SaberStanceAnim( int anim );
qboolean PM_RunningAnim( int anim );
#include "../namespace_end.h"
void G_UpdateClientAnims(gentity_t *self, float animSpeedScale)
{
	static int f;
	static int torsoAnim;
	static int legsAnim;
	static int firstFrame, lastFrame;
	static int aFlags;
	static float animSpeed, lAnimSpeedScale;
	qboolean setTorso = qfalse;

	torsoAnim = (self->client->ps.torsoAnim);
	legsAnim = (self->client->ps.legsAnim);

	if (self->client->ps.saberLockFrame)
	{
		trap_G2API_SetBoneAnim(self->ghoul2, 0, "model_root", self->client->ps.saberLockFrame, self->client->ps.saberLockFrame+1, BONE_ANIM_OVERRIDE_FREEZE|BONE_ANIM_BLEND, animSpeedScale, level.time, -1, 150);
		trap_G2API_SetBoneAnim(self->ghoul2, 0, "lower_lumbar", self->client->ps.saberLockFrame, self->client->ps.saberLockFrame+1, BONE_ANIM_OVERRIDE_FREEZE|BONE_ANIM_BLEND, animSpeedScale, level.time, -1, 150);
		trap_G2API_SetBoneAnim(self->ghoul2, 0, "Motion", self->client->ps.saberLockFrame, self->client->ps.saberLockFrame+1, BONE_ANIM_OVERRIDE_FREEZE|BONE_ANIM_BLEND, animSpeedScale, level.time, -1, 150);
		return;
	}

	if (self->localAnimIndex > 1 &&
		bgAllAnims[self->localAnimIndex].anims[legsAnim].firstFrame == 0 &&
		bgAllAnims[self->localAnimIndex].anims[legsAnim].numFrames == 0)
	{ //We'll allow this for non-humanoids.
		goto tryTorso;
	}

	if (self->client->legsAnimExecute != legsAnim || self->client->legsLastFlip != self->client->ps.legsFlip)
	{
		animSpeed = 50.0f / bgAllAnims[self->localAnimIndex].anims[legsAnim].frameLerp;
		lAnimSpeedScale = (animSpeed *= animSpeedScale);

		if (bgAllAnims[self->localAnimIndex].anims[legsAnim].loopFrames != -1)
		{
			aFlags = BONE_ANIM_OVERRIDE_LOOP;
		}
		else
		{
			aFlags = BONE_ANIM_OVERRIDE_FREEZE;
		}

		if (animSpeed < 0)
		{
			lastFrame = bgAllAnims[self->localAnimIndex].anims[legsAnim].firstFrame;
			firstFrame = bgAllAnims[self->localAnimIndex].anims[legsAnim].firstFrame + bgAllAnims[self->localAnimIndex].anims[legsAnim].numFrames;
		}
		else
		{
			firstFrame = bgAllAnims[self->localAnimIndex].anims[legsAnim].firstFrame;
			lastFrame = bgAllAnims[self->localAnimIndex].anims[legsAnim].firstFrame + bgAllAnims[self->localAnimIndex].anims[legsAnim].numFrames;
		}

		aFlags |= BONE_ANIM_BLEND; //since client defaults to blend. Not sure if this will make much difference if any on server position, but it's here just for the sake of matching them.

		trap_G2API_SetBoneAnim(self->ghoul2, 0, "model_root", firstFrame, lastFrame, aFlags, lAnimSpeedScale, level.time, -1, 150);
		self->client->legsAnimExecute = legsAnim;
		self->client->legsLastFlip = self->client->ps.legsFlip;
	}

tryTorso:
	if (self->localAnimIndex > 1 &&
		bgAllAnims[self->localAnimIndex].anims[torsoAnim].firstFrame == 0 &&
		bgAllAnims[self->localAnimIndex].anims[torsoAnim].numFrames == 0)

	{ //If this fails as well just return.
		return;
	}
	else if (self->s.number >= MAX_CLIENTS &&
		self->s.NPC_class == CLASS_VEHICLE)
	{ //we only want to set the root bone for vehicles
		return;
	}

	if ((self->client->torsoAnimExecute != torsoAnim || self->client->torsoLastFlip != self->client->ps.torsoFlip) &&
		!self->noLumbar)
	{
		aFlags = 0;
		animSpeed = 0;

		f = torsoAnim;

		BG_SaberStartTransAnim(self->s.number, self->client->ps.fd.saberAnimLevel, self->client->ps.weapon, f, &animSpeedScale, self->client->ps.brokenLimbs);

		animSpeed = 50.0f / bgAllAnims[self->localAnimIndex].anims[f].frameLerp;
		lAnimSpeedScale = (animSpeed *= animSpeedScale);

		if (bgAllAnims[self->localAnimIndex].anims[f].loopFrames != -1)
		{
			aFlags = BONE_ANIM_OVERRIDE_LOOP;
		}
		else
		{
			aFlags = BONE_ANIM_OVERRIDE_FREEZE;
		}

		aFlags |= BONE_ANIM_BLEND; //since client defaults to blend. Not sure if this will make much difference if any on client position, but it's here just for the sake of matching them.

		if (animSpeed < 0)
		{
			lastFrame = bgAllAnims[self->localAnimIndex].anims[f].firstFrame;
			firstFrame = bgAllAnims[self->localAnimIndex].anims[f].firstFrame + bgAllAnims[self->localAnimIndex].anims[f].numFrames;
		}
		else
		{
			firstFrame = bgAllAnims[self->localAnimIndex].anims[f].firstFrame;
			lastFrame = bgAllAnims[self->localAnimIndex].anims[f].firstFrame + bgAllAnims[self->localAnimIndex].anims[f].numFrames;
		}

		trap_G2API_SetBoneAnim(self->ghoul2, 0, "lower_lumbar", firstFrame, lastFrame, aFlags, lAnimSpeedScale, level.time, /*firstFrame why was it this before?*/-1, 150);

		self->client->torsoAnimExecute = torsoAnim;
		self->client->torsoLastFlip = self->client->ps.torsoFlip;
		
		setTorso = qtrue;
	}

	if (setTorso &&
		self->localAnimIndex <= 1)
	{ //only set the motion bone for humanoids.
		trap_G2API_SetBoneAnim(self->ghoul2, 0, "Motion", firstFrame, lastFrame, aFlags, lAnimSpeedScale, level.time, -1, 150);
	}

/////#if 0 //disabled for now
	if (self->client->ps.brokenLimbs != self->client->brokenLimbs ||
		setTorso)
	{
		if (self->localAnimIndex <= 1 && self->client->ps.brokenLimbs &&
			(self->client->ps.brokenLimbs & (1 << BROKENLIMB_LARM)))
		{ //broken left arm
			char *brokenBone = "lhumerus";
			animation_t *armAnim;
			int armFirstFrame;
			int armLastFrame;
			int armFlags = 0;
			float armAnimSpeed;

			armAnim = &bgAllAnims[self->localAnimIndex].anims[ BOTH_DEAD21 ];
			self->client->brokenLimbs = self->client->ps.brokenLimbs;

			armFirstFrame = armAnim->firstFrame;
			armLastFrame = armAnim->firstFrame+armAnim->numFrames;
			armAnimSpeed = 50.0f / armAnim->frameLerp;
			armFlags = (BONE_ANIM_OVERRIDE_LOOP|BONE_ANIM_BLEND);

			trap_G2API_SetBoneAnim(self->ghoul2, 0, brokenBone, armFirstFrame, armLastFrame, armFlags, armAnimSpeed, level.time, -1, 150);
		}
		else if (self->localAnimIndex <= 1 && self->client->ps.brokenLimbs &&
			(self->client->ps.brokenLimbs & (1 << BROKENLIMB_RARM)))
		{ //broken right arm
			char *brokenBone = "rhumerus";
			char *supportBone = "lhumerus";

			self->client->brokenLimbs = self->client->ps.brokenLimbs;

			//Only put the arm in a broken pose if the anim is such that we
			//want to allow it.
			if ((//self->client->ps.weapon == WP_MELEE ||
				self->client->ps.weapon != WP_SABER ||
				BG_SaberStanceAnim(self->client->ps.torsoAnim) ||
				PM_RunningAnim(self->client->ps.torsoAnim)) &&
				(!self->client->saber[1].model[0] || self->client->ps.weapon != WP_SABER))
			{
				int armFirstFrame;
				int armLastFrame;
				int armFlags = 0;
				float armAnimSpeed;
				animation_t *armAnim;

				if (self->client->ps.weapon == WP_MELEE ||
					self->client->ps.weapon == WP_SABER ||
					self->client->ps.weapon == WP_BRYAR_PISTOL)
				{ //don't affect this arm if holding a gun, just make the other arm support it
					armAnim = &bgAllAnims[self->localAnimIndex].anims[ BOTH_ATTACK2 ];

					//armFirstFrame = armAnim->firstFrame;
					armFirstFrame = armAnim->firstFrame+armAnim->numFrames;
					armLastFrame = armAnim->firstFrame+armAnim->numFrames;
					armAnimSpeed = 150.0f / armAnim->frameLerp;////50.0f / armAnim->frameLerp;
					armFlags = (BONE_ANIM_OVERRIDE_LOOP|BONE_ANIM_BLEND);

					trap_G2API_SetBoneAnim(self->ghoul2, 0, brokenBone, armFirstFrame, armLastFrame, armFlags, armAnimSpeed, level.time, -1, 150);
				}
				else
				{ //we want to keep the broken bone updated for some cases
					trap_G2API_SetBoneAnim(self->ghoul2, 0, brokenBone, firstFrame, lastFrame, aFlags, lAnimSpeedScale, level.time, -1, 150);
				}

				if (/*self->client->ps.torsoAnim != BOTH_MELEE1 &&
					self->client->ps.torsoAnim != BOTH_MELEE2 &&*///unwoot?
					(self->client->ps.torsoAnim == TORSO_WEAPONREADY2 || self->client->ps.torsoAnim == BOTH_ATTACK2 || self->client->ps.weapon < WP_BRYAR_PISTOL))
				{
					//Now set the left arm to "support" the right one
					armAnim = &bgAllAnims[self->localAnimIndex].anims[ BOTH_STAND2 ];
					armFirstFrame = armAnim->firstFrame;
					armLastFrame = armAnim->firstFrame+armAnim->numFrames;
					armAnimSpeed = 150.0f / armAnim->frameLerp;
					armFlags = (BONE_ANIM_OVERRIDE_LOOP|BONE_ANIM_BLEND);

					trap_G2API_SetBoneAnim(self->ghoul2, 0, supportBone, armFirstFrame, armLastFrame, armFlags, armAnimSpeed, level.time, -1, 150);
				}
				else
				{ //we want to keep the support bone updated for some cases
					trap_G2API_SetBoneAnim(self->ghoul2, 0, supportBone, firstFrame, lastFrame, aFlags, lAnimSpeedScale, level.time, -1, 150);
				}
			}
			else
			{ //otherwise, keep it set to the same as the torso
				trap_G2API_SetBoneAnim(self->ghoul2, 0, brokenBone, firstFrame, lastFrame, aFlags, lAnimSpeedScale, level.time, -1, 150);
				trap_G2API_SetBoneAnim(self->ghoul2, 0, supportBone, firstFrame, lastFrame, aFlags, lAnimSpeedScale, level.time, -1, 150);
			}
		}
		else if (self->client->brokenLimbs)
		{ //remove the bone now so it can be set again
			char *brokenBone = NULL;
			int broken = 0;

			//Warning: Don't remove bones that you've added as bolts unless you want to invalidate your bolt index
			//(well, in theory, I haven't actually run into the problem)
			if (self->client->brokenLimbs & (1<<BROKENLIMB_LARM))
			{
				brokenBone = "lhumerus";
				broken |= (1<<BROKENLIMB_LARM);
			}
			else if (self->client->brokenLimbs & (1<<BROKENLIMB_RARM))
			{ //can only have one arm broken at once.
				brokenBone = "rhumerus";
				broken |= (1<<BROKENLIMB_RARM);

				//want to remove the support bone too then
				trap_G2API_SetBoneAnim(self->ghoul2, 0, "lhumerus", 0, 1, 0, 0, level.time, -1, 0);
				////trap_G2API_RemoveBone(self->ghoul2, "lhumerus", 0);
			}

			////assert(brokenBone);

			//Set the flags and stuff to 0, so that the remove will succeed
			///trap_G2API_SetBoneAnim(self->ghoul2, 0, brokenBone, 0, 1, 0, 0, level.time, -1, 0);

			//Now remove it
			////trap_G2API_RemoveBone(self->ghoul2, brokenBone, 0);
			self->client->brokenLimbs &= ~broken;
		}
	}
/////#endif
}

/*
===========
ClientSpawn

Called every time a client is placed fresh in the world:
after the first ClientBegin, and after each respawn
Initializes all non-persistant parts of playerState
============
*/
extern qboolean WP_HasForcePowers( const playerState_t *ps );
void ClientSpawn(gentity_t *ent) {
	int					index;
	vec3_t				spawn_origin, spawn_angles;
	gclient_t			*client;
	int					i;
	clientPersistant_t	saved;
	clientSession_t		savedSess;

	int savedAmmo[5];
	int savedWeapon;
	int savedStats[5];

	int					persistant[MAX_PERSISTANT];
	gentity_t			*spawnPoint;
	int					flags, gameFlags;
	int					savedPing;
	int					accuracy_hits, accuracy_shots;
	int					eventSequence;
	char				userinfo[MAX_INFO_STRING];
	forcedata_t			savedForce;
	int					saveSaberNum = ENTITYNUM_NONE;
	int					wDisable = 0;
	int					savedSiegeIndex = 0;
	int					maxHealth;
	saberInfo_t			saberSaved[MAX_SABERS];
	int					l = 0;
	void				*g2WeaponPtrs[MAX_SABERS];
	char				*value;
	char				*saber;
	qboolean			changedSaber = qfalse;
	qboolean			inSiegeWithClass = qfalse;

	index = ent - g_entities;
	client = ent->client;

	//first we want the userinfo so we can see if we should update this client's saber -rww
	trap_GetUserinfo( index, userinfo, sizeof(userinfo) );
	while (l < MAX_SABERS)
	{
		switch (l)
		{
		case 0:
			saber = &ent->client->sess.saberType[0];
			break;
		case 1:
			saber = &ent->client->sess.saber2Type[0];
			break;
		default:
			saber = NULL;
			break;
		}

		value = Info_ValueForKey (userinfo, va("saber%i", l+1));
		if (saber &&
			value &&
			(Q_stricmp(value, saber) || !saber[0] || !ent->client->saber[0].model[0]))
		{ //doesn't match up (or our session saber is BS), we want to try setting it
			if (G_SetSaber(ent, l, value, qfalse))
			{
				changedSaber = qtrue;
			}
			else if (!saber[0] || !ent->client->saber[0].model[0])
			{ //Well, we still want to say they changed then (it means this is siege and we have some overrides)
				changedSaber = qtrue;
			}
		}
		l++;
	}

	if (changedSaber)
	{ //make sure our new info is sent out to all the other clients, and give us a valid stance
		ClientUserinfoChanged( ent->s.number );
		

		//make sure the saber models are updated
		G_SaberModelSetup(ent);

		l = 0;
		while (l < MAX_SABERS)
		{ //go through and make sure both sabers match the userinfo
			switch (l)
			{
			case 0:
				saber = &ent->client->sess.saberType[0];
				break;
			case 1:
				saber = &ent->client->sess.saber2Type[0];
				break;
			default:
				saber = NULL;
				break;
			}

			value = Info_ValueForKey (userinfo, va("saber%i", l+1));

			if (Q_stricmp(value, saber))
			{ //they don't match up, force the user info
				Info_SetValueForKey(userinfo, va("saber%i", l+1), saber);
				trap_SetUserinfo( ent->s.number, userinfo );
			}
			l++;
		}

		if (ent->client->saber[0].model[0] &&
			ent->client->saber[1].model[0])
		{ //dual
			ent->client->ps.fd.saberAnimLevelBase = ent->client->ps.fd.saberAnimLevel = ent->client->ps.fd.saberDrawAnimLevel = SS_DUAL;
		}
		else if ((ent->client->saber[0].saberFlags&SFL_TWO_HANDED))
		{ //staff
			ent->client->ps.fd.saberAnimLevel = ent->client->ps.fd.saberDrawAnimLevel = SS_STAFF;
		}
		else
		{

			
			if (ent->client->sess.saberLevel < SS_FAST)
			{
				ent->client->sess.saberLevel = SS_FAST;
			}
			else if (ent->client->sess.saberLevel > SS_STRONG)
			{
				ent->client->sess.saberLevel = SS_STRONG;
			}
			ent->client->ps.fd.saberAnimLevelBase = ent->client->ps.fd.saberAnimLevel = ent->client->ps.fd.saberDrawAnimLevel = ent->client->sess.saberLevel;

			if (g_gametype.integer != GT_SIEGE &&
				ent->client->ps.fd.saberAnimLevel > ent->client->ps.fd.forcePowerLevel[FP_SABER_OFFENSE])
			{
				ent->client->ps.fd.saberAnimLevelBase = ent->client->ps.fd.saberAnimLevel = ent->client->ps.fd.saberDrawAnimLevel = ent->client->sess.saberLevel = ent->client->ps.fd.forcePowerLevel[FP_SABER_OFFENSE];
			}
		}
		if ( g_gametype.integer != GT_SIEGE )
		{
			//let's just make sure the styles we chose are cool
			if ( !WP_SaberStyleValidForSaber( &ent->client->saber[0], &ent->client->saber[1], ent->client->ps.saberHolstered, ent->client->ps.fd.saberAnimLevel ) )
			{
				WP_UseFirstValidSaberStyle( &ent->client->saber[0], &ent->client->saber[1], ent->client->ps.saberHolstered, &ent->client->ps.fd.saberAnimLevel );
				ent->client->ps.fd.saberAnimLevelBase = ent->client->saberCycleQueue = ent->client->ps.fd.saberAnimLevel;
			}
		}
		
	}
	l = 0;


	if (ent->client && g_gametype.integer == GT_POWERDUEL 
		&& ent->client->sess.wins != ent->client->ps.persistant[PERS_SCORE]){
		ent->client->ps.persistant[PERS_SCORE] = ent->client->sess.wins;
	}

	if (client->ps.fd.forceDoInit)
	{ //force a reread of force powers
		WP_InitForcePowers( ent );
		client->ps.fd.forceDoInit = 0;
	}

	if (ent->client->ps.fd.saberAnimLevel != SS_STAFF &&
		ent->client->ps.fd.saberAnimLevel != SS_DUAL &&
		ent->client->ps.fd.saberAnimLevel == ent->client->ps.fd.saberDrawAnimLevel /*&&
		ent->client->ps.fd.saberAnimLevel == ent->client->sess.saberLevel*/)
	{	//unwoot?
		/*if (ent->client->sess.saberLevel < SS_FAST)
		{
			ent->client->sess.saberLevel = SS_FAST;
		}
		else if (ent->client->sess.saberLevel > SS_STRONG)
		{
			ent->client->sess.saberLevel = SS_STRONG;
		}*/
		ent->client->ps.fd.saberAnimLevel = ent->client->ps.fd.saberDrawAnimLevel = ent->client->sess.saberLevel;

		if (g_gametype.integer != GT_SIEGE &&
			ent->client->ps.fd.saberAnimLevel > ent->client->ps.fd.forcePowerLevel[FP_SABER_OFFENSE])
		{
			ent->client->ps.fd.saberAnimLevel = ent->client->ps.fd.saberDrawAnimLevel = ent->client->sess.saberLevel = ent->client->ps.fd.forcePowerLevel[FP_SABER_OFFENSE];
		}
	}


	// find a spawn point
	// do it before setting health back up, so farthest
	// ranging doesn't count this client
	if ( client->sess.sessionTeam == TEAM_SPECTATOR ) {
		spawnPoint = SelectSpectatorSpawnPoint ( 
						spawn_origin, spawn_angles);
	} else if (g_gametype.integer == GT_CTF || g_gametype.integer == GT_CTY) {
		// all base oriented team games use the CTF spawn points
		spawnPoint = SelectCTFSpawnPoint ( 
						client->sess.sessionTeam, 
						client->pers.teamState.state, 
						spawn_origin, spawn_angles);
	}
	else if (g_gametype.integer == GT_SIEGE)
	{
		spawnPoint = SelectSiegeSpawnPoint (
						client->siegeClass,
						client->sess.sessionTeam, 
						client->pers.teamState.state, 
						spawn_origin, spawn_angles);
	}
	else {
		do {
			if (g_gametype.integer == GT_POWERDUEL)
			{
				spawnPoint = SelectDuelSpawnPoint(client->sess.duelTeam, client->ps.origin, spawn_origin, spawn_angles);
			}
			else if (g_gametype.integer == GT_DUEL)
			{	// duel 
				spawnPoint = SelectDuelSpawnPoint(DUELTEAM_SINGLE, client->ps.origin, spawn_origin, spawn_angles);
			}
			else
			{
				// the first spawn should be at a good looking spot
				if ( !client->pers.initialSpawn && client->pers.localClient ) {
					client->pers.initialSpawn = qtrue;
					spawnPoint = SelectInitialSpawnPoint( spawn_origin, spawn_angles, client->sess.sessionTeam );
				} else {
					// don't spawn near existing origin if possible
					spawnPoint = SelectSpawnPoint ( 
						client->ps.origin, 
						spawn_origin, spawn_angles, client->sess.sessionTeam );
				}
			}

			// Tim needs to prevent bots from spawning at the initial point
			// on q3dm0...
			if ( ( spawnPoint->flags & FL_NO_BOTS ) && ( ent->r.svFlags & SVF_BOT ) ) {
				continue;	// try again
			}
			// just to be symetric, we have a nohumans option...
			if ( ( spawnPoint->flags & FL_NO_HUMANS ) && !( ent->r.svFlags & SVF_BOT ) ) {
				continue;	// try again
			}

			break;

		} while ( 1 );
	}
	client->pers.teamState.state = TEAM_ACTIVE;

	// toggle the teleport bit so the client knows to not lerp
	// and never clear the voted flag
	flags = ent->client->ps.eFlags & (EF_TELEPORT_BIT );
	flags ^= EF_TELEPORT_BIT;
	gameFlags = ent->client->mGameFlags & ( PSG_VOTED | PSG_TEAMVOTED);

	// clear everything but the persistant data

	saved = client->pers;
	savedSess = client->sess;
	
///
savedWeapon = client->ps.weapon;
for ( i = 0 ; i < 4 ; i++ ) {
	savedAmmo[i] = client->ps.ammo[i];
	savedStats[i] = client->ps.stats[i];
}
///


	savedPing = client->ps.ping;
//	savedAreaBits = client->areabits;
	accuracy_hits = client->accuracy_hits;
	accuracy_shots = client->accuracy_shots;
	for ( i = 0 ; i < MAX_PERSISTANT ; i++ ) {
		persistant[i] = client->ps.persistant[i];
	}
	eventSequence = client->ps.eventSequence;

	savedForce = client->ps.fd;

	saveSaberNum = client->ps.saberEntityNum;

	savedSiegeIndex = client->siegeClass;

	l = 0;
	while (l < MAX_SABERS)
	{
		saberSaved[l] = client->saber[l];
		g2WeaponPtrs[l] = client->weaponGhoul2[l];
		l++;
	}

	i = 0;
	while (i < HL_MAX)
	{
		ent->locationDamage[i] = 0;
		i++;
	}

	memset (client, 0, sizeof(*client)); // bk FIXME: Com_Memset?
	client->bodyGrabIndex = ENTITYNUM_NONE;

	//Get the skin RGB based on his userinfo
	value = Info_ValueForKey (userinfo, "char_color_red");
	if (value)
	{
		client->ps.customRGBA[0] = atoi(value);
	}
	else
	{
		client->ps.customRGBA[0] = 255;
	}

	value = Info_ValueForKey (userinfo, "char_color_green");
	if (value)
	{
		client->ps.customRGBA[1] = atoi(value);
	}
	else
	{
		client->ps.customRGBA[1] = 255;
	}

	value = Info_ValueForKey (userinfo, "char_color_blue");
	if (value)
	{
		client->ps.customRGBA[2] = atoi(value);
	}
	else
	{
		client->ps.customRGBA[2] = 255;
	}



	if ((client->ps.customRGBA[0]+client->ps.customRGBA[1]+client->ps.customRGBA[2]) < 100)
	{ //hmm, too dark!
		////client->ps.customRGBA[0] = client->ps.customRGBA[1] = client->ps.customRGBA[2] = 255;
	}

	client->ps.customRGBA[3]=255;

	client->siegeClass = savedSiegeIndex;

	l = 0;
	while (l < MAX_SABERS)
	{
		client->saber[l] = saberSaved[l];
		client->weaponGhoul2[l] = g2WeaponPtrs[l];
		l++;
	}

	//or the saber ent num
	client->ps.saberEntityNum = saveSaberNum;
	client->saberStoredIndex = saveSaberNum;

	client->ps.fd = savedForce;

	client->ps.duelIndex = ENTITYNUM_NONE;

	client->pers = saved;
	client->sess = savedSess;

	//spawn with 100
	client->ps.jetpackFuel = 50 - client->sess.karma;////(client->sess.con)*8;
	client->ps.cloakFuel = 50 + client->sess.karma;////(int)client->sess.con*3.6f;////

	//bad?
	//////client->ps.ping = savedPing;



///
client->ps.weapon = savedWeapon;
for ( i = 0 ; i < 4 ; i++ ) {
	client->ps.ammo[i] = savedAmmo[i];
	client->ps.stats[i] = savedStats[i];
}
///



//	client->areabits = savedAreaBits;
	client->accuracy_hits = accuracy_hits;
	client->accuracy_shots = accuracy_shots;
	client->lastkilled_client = -1;

	for ( i = 0 ; i < MAX_PERSISTANT ; i++ ) {
		client->ps.persistant[i] = persistant[i];
	}
	client->ps.eventSequence = eventSequence;
	// increment the spawncount so the client will detect the respawn
	client->ps.persistant[PERS_SPAWN_COUNT]++;
	client->ps.persistant[PERS_TEAM] = client->sess.sessionTeam;

	client->airOutTime = level.time + 12000;

	// set max health
	if (g_gametype.integer == GT_SIEGE && client->siegeClass != -1)
	{
		siegeClass_t *scl = &bgSiegeClasses[client->siegeClass];
		maxHealth = 100;

		if (scl->maxhealth)
		{
			maxHealth = scl->maxhealth;
		}
	}
	else
	{
		maxHealth = 100;
	}
	client->pers.maxHealth = maxHealth;//atoi( Info_ValueForKey( userinfo, "handicap" ) );
	if ( client->pers.maxHealth < 1 || client->pers.maxHealth > maxHealth ) {
		client->pers.maxHealth = 100;
	}
	// clear entity values
	client->ps.stats[STAT_MAX_HEALTH] = client->pers.maxHealth;
	client->ps.eFlags = flags;
	client->mGameFlags = gameFlags;

	ent->s.groundEntityNum = ENTITYNUM_NONE;
	ent->client = &level.clients[index];
	ent->playerState = &ent->client->ps;
	ent->takedamage = qtrue;
	ent->inuse = qtrue;
	ent->classname = "player";
	ent->r.contents = CONTENTS_BODY;
	ent->clipmask = MASK_PLAYERSOLID;
	ent->die = player_die;
	ent->waterlevel = 0;
	ent->watertype = 0;
	ent->flags = 0;
	
	VectorCopy (playerMins, ent->r.mins);
	VectorCopy (playerMaxs, ent->r.maxs);
	client->ps.crouchheight = CROUCH_MAXS_2;
	client->ps.standheight = DEFAULT_MAXS_2;

	client->ps.clientNum = index;
	//give default weapons
	client->ps.stats[STAT_WEAPONS] = ( 1 << WP_NONE );

	if (g_gametype.integer == GT_DUEL || g_gametype.integer == GT_POWERDUEL)
	{
		wDisable = g_duelWeaponDisable.integer;
	}
	else
	{
		wDisable = g_weaponDisable.integer;
	}



	if ( g_gametype.integer != GT_HOLOCRON 
		&& g_gametype.integer != GT_JEDIMASTER 
		&& !HasSetSaberOnly()
		&& !AllForceDisabled( g_forcePowerDisable.integer )
		&& g_trueJedi.integer )
	{
		if ( g_gametype.integer >= GT_TEAM && (client->sess.sessionTeam == TEAM_BLUE || client->sess.sessionTeam == TEAM_RED) )
		{//In Team games, force one side to be merc and other to be jedi
			if ( level.numPlayingClients > 0 )
			{//already someone in the game
				int		i, forceTeam = TEAM_SPECTATOR;
				for ( i = 0 ; i < level.maxclients ; i++ ) 
				{
					if ( level.clients[i].pers.connected == CON_DISCONNECTED ) {
						continue;
					}
					if ( level.clients[i].sess.sessionTeam == TEAM_BLUE || level.clients[i].sess.sessionTeam == TEAM_RED ) 
					{//in-game
						if ( WP_HasForcePowers( &level.clients[i].ps ) )
						{//this side is using force
							forceTeam = level.clients[i].sess.sessionTeam;
						}
						else
						{//other team is using force
							if ( level.clients[i].sess.sessionTeam == TEAM_BLUE )
							{
								forceTeam = TEAM_RED;
							}
							else
							{
								forceTeam = TEAM_BLUE;
							}
						}
						break;
					}
				}

				/*if ( WP_HasForcePowers( &client->ps ) && client->sess.sessionTeam != forceTeam )
				{//using force but not on right team, switch him over
					const char *teamName = TeamName( forceTeam );
					//client->sess.sessionTeam = forceTeam;
					SetTeam( ent, (char *)teamName );
					return;
				}*///unwoot?
			}
		}

		if ( WP_HasForcePowers( &client->ps ) )
		{
			client->ps.trueNonJedi = qfalse;
			client->ps.trueJedi = qtrue;
			//make sure they only use the saber
			///client->ps.weapon = WP_SABER;
			///client->ps.stats[STAT_WEAPONS] = (1 << WP_SABER);
		}
		else
		{//no force powers set
			client->ps.trueNonJedi = qtrue;
			client->ps.trueJedi = qfalse;
			if (!wDisable || !(wDisable & (1 << WP_BRYAR_PISTOL)))
			{
				////client->ps.stats[STAT_WEAPONS] |= ( 1 << WP_BRYAR_PISTOL );
			}
			if (!wDisable || !(wDisable & (1 << WP_BLASTER)))
			{
				client->ps.stats[STAT_WEAPONS] |= ( 1 << WP_BLASTER );
			}
			if (!wDisable || !(wDisable & (1 << WP_BOWCASTER)))
			{
				client->ps.stats[STAT_WEAPONS] |= ( 1 << WP_BOWCASTER );
			}
			client->ps.stats[STAT_WEAPONS] &= ~(1 << WP_SABER);
			client->ps.stats[STAT_WEAPONS] |= (1 << WP_MELEE);
			client->ps.ammo[AMMO_POWERCELL] = ammoData[AMMO_POWERCELL].max;
			////client->ps.weapon = WP_BRYAR_PISTOL;
		}
	}
	else
	{//jediVmerc is incompatible with this gametype, turn it off!
		trap_Cvar_Set( "g_jediVmerc", "0" );
		if (g_gametype.integer == GT_HOLOCRON)
		{
			//always get free saber level 1 in holocron
			client->ps.stats[STAT_WEAPONS] |= ( 1 << WP_SABER );	//these are precached in g_items, ClearRegisteredItems()
		}
		else
		{
			if (client->ps.fd.forcePowerLevel[FP_SABER_OFFENSE])
			{
				client->ps.stats[STAT_WEAPONS] |= ( 1 << WP_SABER );	//these are precached in g_items, ClearRegisteredItems()
			}
			else
			{ //if you don't have saber attack rank then you don't get a saber
				client->ps.stats[STAT_WEAPONS] |= (1 << WP_MELEE);
			}
		}

		if (g_gametype.integer != GT_SIEGE)
		{
			if (!wDisable || !(wDisable & (1 << WP_BRYAR_PISTOL)))
			{
				////client->ps.stats[STAT_WEAPONS] |= ( 1 << WP_BRYAR_PISTOL );
			}
			else if (g_gametype.integer == GT_JEDIMASTER)
			{
				client->ps.stats[STAT_WEAPONS] |= ( 1 << WP_BRYAR_PISTOL );
			}
		}

		if (g_gametype.integer == GT_JEDIMASTER)
		{
			client->ps.stats[STAT_WEAPONS] &= ~(1 << WP_SABER);
			client->ps.stats[STAT_WEAPONS] |= (1 << WP_MELEE);
		}

		if (client->ps.stats[STAT_WEAPONS] & (1 << WP_SABER))
		{
			client->ps.weapon = WP_SABER;
		}
		else if (client->ps.stats[STAT_WEAPONS] & (1 << WP_BRYAR_PISTOL))
		{
			//client->ps.weapon = WP_BRYAR_PISTOL;
		}
		else
		{
			client->ps.weapon = WP_MELEE;
		}
	}

	/*
	client->ps.stats[STAT_HOLDABLE_ITEMS] |= ( 1 << HI_BINOCULARS );
	client->ps.stats[STAT_HOLDABLE_ITEM] = BG_GetItemIndexByTag(HI_BINOCULARS, IT_HOLDABLE);
	*/

	/*if (g_gametype.integer == GT_SIEGE && client->siegeClass != -1 &&
		client->sess.sessionTeam != TEAM_SPECTATOR)
	{ //well then, we will use a custom weaponset for our class
		int m = 0;

		client->ps.stats[STAT_WEAPONS] = bgSiegeClasses[client->siegeClass].weapons;

		if (client->ps.stats[STAT_WEAPONS] & (1 << WP_SABER))
		{
			client->ps.weapon = WP_SABER;
		}
		else if (client->ps.stats[STAT_WEAPONS] & (1 << WP_BRYAR_PISTOL))
		{
			////client->ps.weapon = WP_BRYAR_PISTOL;
		}
		else
		{
			client->ps.weapon = WP_MELEE;
		}
		inSiegeWithClass = qtrue;

		while (m < WP_NUM_WEAPONS)
		{
			if (client->ps.stats[STAT_WEAPONS] & (1 << m))
			{
				if (client->ps.weapon != WP_SABER)
				{ //try to find the highest ranking weapon we have
					if (m > client->ps.weapon)
					{
						client->ps.weapon = m;
					}
				}

				if (m >= WP_BRYAR_PISTOL)
				{ //Max his ammo out for all the weapons he has.
					if ( g_gametype.integer == GT_SIEGE 
						&& m == WP_ROCKET_LAUNCHER )
					{//don't give full ammo!
						//FIXME: extern this and check it when getting ammo from supplier, pickups or ammo stations!
						if ( client->siegeClass != -1 &&
							(bgSiegeClasses[client->siegeClass].classflags & (1<<CFL_SINGLE_ROCKET)) )
						{
							client->ps.ammo[weaponData[m].ammoIndex] = 1;
						}
						else
						{
							client->ps.ammo[weaponData[m].ammoIndex] = 10;
						}
					}
					else
					{
						if ( g_gametype.integer == GT_SIEGE 
							&& client->siegeClass != -1
							&& (bgSiegeClasses[client->siegeClass].classflags & (1<<CFL_EXTRA_AMMO)) )
						{//double ammo
							client->ps.ammo[weaponData[m].ammoIndex] = ammoData[weaponData[m].ammoIndex].max*2;
							client->ps.eFlags |= EF_DOUBLE_AMMO;
						}
						else
						{
							client->ps.ammo[weaponData[m].ammoIndex] = ammoData[weaponData[m].ammoIndex].max;
						}
					}
				}
			}
			m++;
		}
	}

	if (g_gametype.integer == GT_SIEGE &&
		client->siegeClass != -1 &&
		client->sess.sessionTeam != TEAM_SPECTATOR)
	{ //use class-specified inventory
		client->ps.stats[STAT_HOLDABLE_ITEMS] = bgSiegeClasses[client->siegeClass].invenItems;
		client->ps.stats[STAT_HOLDABLE_ITEM] = 0;
	}
	else
	{*/
		client->ps.stats[STAT_HOLDABLE_ITEMS] = 0;
		client->ps.stats[STAT_HOLDABLE_ITEM] = 0;
	///}

	/*if (g_gametype.integer == GT_SIEGE &&
		client->siegeClass != -1 &&
		bgSiegeClasses[client->siegeClass].powerups &&
		client->sess.sessionTeam != TEAM_SPECTATOR)
	{ //this class has some start powerups
		i = 0;
		while (i < PW_NUM_POWERUPS)
		{
			if (bgSiegeClasses[client->siegeClass].powerups & (1 << i))
			{
				client->ps.powerups[i] = Q3_INFINITE;
			}
			i++;
		}
	}*/

	if ( client->sess.sessionTeam == TEAM_SPECTATOR )
	{
		client->ps.stats[STAT_WEAPONS] = 0;
		client->ps.stats[STAT_HOLDABLE_ITEMS] = 0;
		client->ps.stats[STAT_HOLDABLE_ITEM] = 0;
	}

// nmckenzie: DESERT_SIEGE... or well, siege generally.  This was over-writing the max value, which was NOT good for siege.
	if ( inSiegeWithClass == qfalse )
	{
		client->ps.ammo[AMMO_BLASTER] = 100; //ammoData[AMMO_BLASTER].max; //100 seems fair.
	}
//	client->ps.ammo[AMMO_POWERCELL] = ammoData[AMMO_POWERCELL].max;
//	client->ps.ammo[AMMO_FORCE] = ammoData[AMMO_FORCE].max;
//	client->ps.ammo[AMMO_METAL_BOLTS] = ammoData[AMMO_METAL_BOLTS].max;
//	client->ps.ammo[AMMO_ROCKETS] = ammoData[AMMO_ROCKETS].max;
/*
	client->ps.stats[STAT_WEAPONS] = ( 1 << WP_BRYAR_PISTOL);
	if ( g_gametype.integer == GT_TEAM ) {
		client->ps.ammo[WP_BRYAR_PISTOL] = 50;
	} else {
		client->ps.ammo[WP_BRYAR_PISTOL] = 100;
	}
*/
	client->ps.rocketLockIndex = ENTITYNUM_NONE;
	client->ps.rocketLockTime = 0;

	//rww - Set here to initialize the circling seeker drone to off.
	//A quick note about this so I don't forget how it works again:
	//ps.genericEnemyIndex is kept in sync between the server and client.
	//When it gets set then an entitystate value of the same name gets
	//set along with an entitystate flag in the shared bg code. Which
	//is why a value needs to be both on the player state and entity state.
	//(it doesn't seem to just carry over the entitystate value automatically
	//because entity state value is derived from player state data or some
	//such)
	client->ps.genericEnemyIndex = -1;

	client->ps.isJediMaster = qfalse;

	if (client->ps.fallingToDeath)
	{
		client->ps.fallingToDeath = 0;
		client->noCorpse = qtrue;
	}

	//Do per-spawn force power initialization
	WP_SpawnInitForcePowers( ent );

	// health will count down towards max_health
	/*if (g_gametype.integer == GT_SIEGE &&
		client->siegeClass != -1 &&
		bgSiegeClasses[client->siegeClass].starthealth)
	{ //class specifies a start health, so use it
		ent->health = client->ps.stats[STAT_HEALTH] = bgSiegeClasses[client->siegeClass].starthealth;
	}
	else */if ( g_gametype.integer == GT_DUEL || g_gametype.integer == GT_POWERDUEL )
	{//only start with 100 health in Duel
		if ( g_gametype.integer == GT_POWERDUEL && client->sess.duelTeam == DUELTEAM_LONE )
		{
			if ( g_duel_fraglimit.integer )
			{
				
				ent->health = client->ps.stats[STAT_HEALTH] = client->ps.stats[STAT_MAX_HEALTH] = 150 + (int)(client->sess.con*1.25f);
				//g_powerDuelStartHealth.integer - ((g_powerDuelStartHealth.integer - g_powerDuelEndHealth.integer) * (float)client->sess.wins / (float)g_duel_fraglimit.integer);
			}
			else
			{
				ent->health = client->ps.stats[STAT_HEALTH] = client->ps.stats[STAT_MAX_HEALTH] = 150 + (int)(client->sess.con*1.5f);
			}
		}
		else
		{
			ent->health = client->ps.stats[STAT_HEALTH] = client->ps.stats[STAT_MAX_HEALTH] = 100 + (int)(client->sess.con*1.33f);
		}
	}
	else if (client->ps.stats[STAT_MAX_HEALTH] <= 100)
	{
		ent->health = client->ps.stats[STAT_HEALTH] = (int)(client->ps.stats[STAT_MAX_HEALTH] * 1.33f);
	}
	else if (client->ps.stats[STAT_MAX_HEALTH] < 125)
	{
		ent->health = client->ps.stats[STAT_HEALTH] = 125;
	}
	else
	{
		ent->health = client->ps.stats[STAT_HEALTH] = client->ps.stats[STAT_MAX_HEALTH];
	}

	// Start with a small amount of armor as well.
	if (g_gametype.integer == GT_SIEGE &&
		client->siegeClass != -1 /*&&
		bgSiegeClasses[client->siegeClass].startarmor*/)
	{ //class specifies a start armor amount, so use it
		client->ps.stats[STAT_ARMOR] = bgSiegeClasses[client->siegeClass].startarmor;
	}
	else if ( g_gametype.integer == GT_DUEL || g_gametype.integer == GT_POWERDUEL )
	{

		
			
		if (client->ps.fd.forcePowerLevel[FP_SABER_OFFENSE] < FORCE_LEVEL_1)
		{
			//client->ps.stats[STAT_ARMOR] = g_meleeshield.integer;
			client->ps.stats[STAT_ARMOR] = (int)(client->sess.con/1.6f);
		}
		else
		{
			client->ps.stats[STAT_ARMOR] = 0;///(int)(client->sess.con/4.0f);
		}
	}
	else
	{
		client->ps.stats[STAT_ARMOR] = client->ps.stats[STAT_MAX_HEALTH] * 0.25;
	}

	G_SetOrigin( ent, spawn_origin );
	VectorCopy( spawn_origin, client->ps.origin );

	// the respawned flag will be cleared after the attack and jump keys come up
	client->ps.pm_flags |= PMF_RESPAWNED;

	trap_GetUsercmd( client - level.clients, &ent->client->pers.cmd );
	SetClientViewAngle( ent, spawn_angles );

	if ( ent->client->sess.sessionTeam == TEAM_SPECTATOR ) {

	} else {
		G_KillBox( ent );
		trap_LinkEntity (ent);

		// force the base weapon up
		//client->ps.weapon = WP_BRYAR_PISTOL;
		//client->ps.weaponstate = FIRST_WEAPON;
		if (client->ps.weapon <= WP_NONE)
		{
			/////client->ps.weapon = WP_BRYAR_PISTOL;
		}

		client->ps.torsoTimer = client->ps.legsTimer = 0;


		if  ( ent->r.svFlags & SVF_BOT && rand() % 5 == 3){
			//client->ps.stats[STAT_HOLDABLE_ITEM] = ( 1 << HI_JETPACK );
			//client->jetPackOn = 1;
			//client->ps.pm_type = PM_JETPACK;
		}
		
		if (g_leveling.integer > 0){

			SetRPGStats(ent, ent->client->ps.clientNum);
			///ShowRPGStats(ent->client->ps.clientNum, ent->client->ps.clientNum);

			///ent->client->ps.crouchheight =  (int)(float)ent->client->saber[0].damageScale * CROUCH_MAXS_2;
			////ent->client->ps.standheight =  (int)(float)ent->client->saber[0].damageScale * DEFAULT_MAXS_2;
		}

			//for ( i = 0 ; i < level.maxclients ; i++ ) {
	//	if ( level.clients[i].pers.connected == CON_DISCONNECTED )
	//		continue;

	//}

	//trap_SendServerCommand( ent-g_entities, va("cp \"%s %s\n\"", G_GetStringEdString("MP_SVGAME", "PLDUELCHALLENGED"), challenged->client->pers.netname) );
	


		if (client->ps.clientNum <= 1 && Q_irand(0,20) > 12 
			&& IsABot(client->ps.clientNum)
			){
			///client->ps.jetpackFuel = 120;
			///client->ps.stats[STAT_HOLDABLE_ITEMS] |= ( 1 << HI_JETPACK );
			///	client->ps.pm_type = PM_JETPACK;
			///client->jetPackOn = 1;
		}

		if (IsABot(client->ps.clientNum) && client->ps.weapon != WP_SABER)
		{
			
			strcpy(client->sess.admin_name, "sub");	
			///WriteKeys(client->ps.clientNum,7,qtrue);

			G_SetAnim(ent, NULL, SETANIM_BOTH, BOTH_VICTORY_STRONG, SETANIM_FLAG_OVERRIDE|SETANIM_FLAG_HOLD|SETANIM_FLAG_HOLDLESS, 0);
///client->ps.jetpackFuel = 120;
			client->ps.stats[STAT_WEAPONS] = ( 1 << WP_MELEE );
			client->ps.stats[STAT_WEAPONS] |= ( 1 << WP_THERMAL );
			
			//client->ps.stats[STAT_WEAPONS] |= ( 1 << WP_DET_PACK );
			//client->ps.ammo[AMMO_THERMAL] = (int)(client->sess.con*0.05f);
			if (Q_irand(0,15) <= 6){
			client->ps.stats[STAT_WEAPONS] |= ( 1 << WP_CONCUSSION );
			}
			///client->ps.stats[STAT_WEAPONS] |= ( 1 << WP_DISRUPTOR );

			if (Q_irand(0,15) <= 12){
			client->ps.stats[STAT_WEAPONS] |= ( 1 << WP_BRYAR_PISTOL );
			}
			
			if (Q_irand(0,15) <= 3){
			client->ps.stats[STAT_WEAPONS] |= ( 1 << WP_STUN_BATON );
			}

			if (Q_irand(0,15) <= 12){
			client->ps.ammo[AMMO_THERMAL] = (int)(client->sess.con*0.1f); ///0.1f);	
			}

			///client->ps.ammo[AMMO_BLASTER] = 15 + (int)(client->sess.con*1.25f);
			///client->ps.stats[STAT_HOLDABLE_ITEMS] |= ( 1 << HI_JETPACK );
			client->ps.ammo[AMMO_BLASTER] = 10+ (int)(client->sess.con*1.25f);
			client->ps.ammo[AMMO_METAL_BOLTS] = 5+(int)(client->sess.con*1.25f);
			client->ps.ammo[AMMO_POWERCELL] = 5+(int)(client->sess.con*1.25f);

			client->ps.fd.forcePowersKnown |= (1 << FP_LEVITATION);
			client->ps.fd.forcePowerLevel[FP_LEVITATION] = FORCE_LEVEL_3;

			client->ps.fd.forcePowersKnown |= (1 << FP_PUSH);
			client->ps.fd.forcePowerLevel[FP_PUSH] = FORCE_LEVEL_3;


			if (Q_irand(0,120) == 55){
				client->ps.stats[STAT_HOLDABLE_ITEMS] |= ( 1 << HI_SEEKER );
			}
			///client->ps.stats[STAT_HOLDABLE_ITEMS] |= ( 1 << HI_CLOAK );

		}else if (IsABot(client->ps.clientNum) ){
			G_SetAnim(ent, NULL, SETANIM_BOTH, BOTH_ENGAGETAUNT, SETANIM_FLAG_OVERRIDE|SETANIM_FLAG_HOLD|SETANIM_FLAG_HOLDLESS, 0);
			client->ps.stats[STAT_WEAPONS] = ( 1 << WP_SABER );
			client->ps.stats[STAT_WEAPONS] |= ( 1 << WP_BLASTER );
			client->ps.ammo[AMMO_BLASTER] = 15 +(int)(client->sess.con*1.25f);

			client->ps.fd.forcePowersKnown |= (1 << FP_GRIP);
			client->ps.fd.forcePowerLevel[FP_GRIP] = FORCE_LEVEL_3;

			client->ps.fd.forcePowersKnown |= (1 << FP_PUSH);
			client->ps.fd.forcePowerLevel[FP_PUSH] = FORCE_LEVEL_3;


			client->ps.fd.forcePowersKnown |= (1 << FP_LEVITATION);
			client->ps.fd.forcePowerLevel[FP_LEVITATION] = FORCE_LEVEL_3;

			client->ps.stats[STAT_HOLDABLE_ITEMS] |= ( 1 << HI_CLOAK );

			if (Q_irand(0,18) == 3){
				client->ps.stats[STAT_HOLDABLE_ITEMS] |= ( 1 << HI_SENTRY_GUN );
			}
			
		}
		else if (client->ps.fd.saberAnimLevel == SS_DUAL)
		{
			G_SetAnim(ent, NULL, SETANIM_BOTH, BOTH_SHOWOFF_STRONG, SETANIM_FLAG_OVERRIDE|SETANIM_FLAG_HOLD|SETANIM_FLAG_HOLDLESS, 0);
			client->ps.stats[STAT_WEAPONS] = ( 1 << WP_SABER );

			client->ps.stats[STAT_WEAPONS] |= ( 1 << WP_BOWCASTER );
			client->ps.ammo[AMMO_METAL_BOLTS] = 15 + (int)(client->sess.con*1.25f);
			client->ps.ammo[AMMO_POWERCELL] = 15 + (int)(client->sess.con*1.25f);


			client->ps.fd.forcePowersKnown |= (1 << FP_SABERTHROW);
			client->ps.fd.forcePowerLevel[FP_SABERTHROW] = FORCE_LEVEL_3;

		}
		else if (client->ps.fd.saberAnimLevel == SS_STAFF)
		{
			G_SetAnim(ent, NULL, SETANIM_BOTH, BOTH_SHOWOFF_STAFF, SETANIM_FLAG_OVERRIDE|SETANIM_FLAG_HOLD|SETANIM_FLAG_HOLDLESS, 0);
			client->ps.stats[STAT_WEAPONS] = ( 1 << WP_SABER );
			client->ps.stats[STAT_WEAPONS] |= ( 1 << WP_DISRUPTOR );
			client->ps.ammo[AMMO_POWERCELL] = 15 + (int)(client->sess.con*1.25f);


			client->ps.fd.forcePowersKnown |= (1 << FP_SABERTHROW);
			client->ps.fd.forcePowerLevel[FP_SABERTHROW] = FORCE_LEVEL_3;

		}
		else if (client->ps.weapon == WP_SABER)
		{
			//G_SetAnim(ent, NULL, SETANIM_BOTH, BOTH_STAND1TO2, SETANIM_FLAG_OVERRIDE|SETANIM_FLAG_HOLD|SETANIM_FLAG_HOLDLESS, 0);
			G_SetAnim(ent, NULL, SETANIM_BOTH, BOTH_BOW, SETANIM_FLAG_OVERRIDE|SETANIM_FLAG_HOLD|SETANIM_FLAG_HOLDLESS, 0);
			client->ps.stats[STAT_WEAPONS] = ( 1 << WP_SABER );

			client->ps.stats[STAT_WEAPONS] |= ( 1 << WP_BLASTER );
			client->ps.ammo[AMMO_BLASTER] = 15 + (int)(client->sess.con*1.25f);

			client->ps.fd.forcePowersKnown |= (1 << FP_SABERTHROW);
			client->ps.fd.forcePowerLevel[FP_SABERTHROW] = FORCE_LEVEL_3;

			////client->ps.fd.saberAnimLevel = FORCE_LEVEL_5;
			////client->ps.fd.forcePowerLevel[FP_SABER_OFFENSE] = FORCE_LEVEL_5;

			ent->client->ps.fd.saberAnimLevelBase = ent->client->ps.fd.saberAnimLevel = ent->client->ps.fd.saberDrawAnimLevel = ent->client->sess.saberLevel = ent->client->ps.fd.forcePowerLevel[FP_SABER_OFFENSE] = FORCE_LEVEL_5;
			ent->client->ps.fd.saberAnimLevelBase = ent->client->ps.fd.saberAnimLevel = ent->client->ps.fd.saberDrawAnimLevel = ent->client->sess.saberLevel = FORCE_LEVEL_4;

			///if (ent->client->sess.karma >= 0){
			///trap_SendServerCommand( ent->s.number, va("cp \"^7Saber stance:\n^1%s style\n\"", "^1Good Tavion") );
			///ent->client->ps.fd.saberAnimLevelBase = ent->client->ps.fd.saberAnimLevel = ent->client->ps.fd.saberDrawAnimLevel = ent->client->sess.saberLevel = /*ent->client->ps.fd.forcePowerLevel[FP_SABER_OFFENSE] =*/ FORCE_LEVEL_4;
			///}
			if (ReadKeys(ent->s.number,"style")+1 <= 5){
			ent->client->sess.saberLevel = ent->client->ps.fd.saberAnimLevel =  ent->client->ps.fd.saberDrawAnimLevel = ReadKeys(ent->s.number,"style")+1;
			}else{
			ent->client->sess.saberLevel = ent->client->ps.fd.saberAnimLevel =  ent->client->ps.fd.saberDrawAnimLevel = 1;

			}
			///else if(ent->client->sess.karma < 0){
			///trap_SendServerCommand( ent->s.number, va("cp \"^7Saber stance:\n^1%s style\n\"", "^4Evil Desann") );
			///ent->client->ps.fd.saberAnimLevelBase = ent->client->ps.fd.saberAnimLevel = ent->client->ps.fd.saberDrawAnimLevel = ent->client->sess.saberLevel = FORCE_LEVEL_5;
			///}
		}

		else
		{

			client->ps.stats[STAT_WEAPONS] = ( 1 << WP_MELEE );
			client->ps.stats[STAT_WEAPONS] |= ( 1 << WP_BRYAR_OLD );
			client->ps.stats[STAT_WEAPONS] |= ( 1 << WP_STUN_BATON );
			client->ps.ammo[AMMO_BLASTER] = 15 + (int)(client->sess.con*1.25f);
			client->ps.ammo[AMMO_POWERCELL] = 1;
			client->ps.stats[STAT_WEAPONS] |= ( 1 << WP_THERMAL );
			client->ps.ammo[AMMO_THERMAL] = (int)(client->sess.con*0.04f);

			client->ps.stats[STAT_ARMOR] = g_meleeshield.integer;
			client->ps.weapon = WP_MELEE;

			G_SetAnim(ent, NULL, SETANIM_BOTH, BOTH_BOW, SETANIM_FLAG_OVERRIDE|SETANIM_FLAG_HOLD|SETANIM_FLAG_HOLDLESS, 0);

			/////client->ps.stats[STAT_WEAPONS] |= ( 1 << WP_CONCUSSION );
			/////client->ps.ammo[AMMO_METAL_BOLTS] = 120;

			///client->ps.stats[STAT_HOLDABLE_ITEMS] |= ( 1 << HI_BINOCULARS );
			
			//client->ps.stats[STAT_HOLDABLE_ITEMS] |= ( 1 << HI_SHIELD );
			//client->ps.stats[STAT_WEAPONS] |= ( 1 << WP_STUN_BATON );
			//client->ps.ammo[AMMO_BLASTER] = 250;
			

			
			//G_SetAnim(ent, NULL, SETANIM_TORSO, TORSO_RAISEWEAP1, SETANIM_FLAG_OVERRIDE|SETANIM_FLAG_HOLD|SETANIM_FLAG_HOLDLESS, 0);
			//client->ps.legsAnim = WeaponReadyAnim[client->ps.weapon];
			
		}
		
		if (ent->client->sess.dex >= 14){
			client->ps.stats[STAT_WEAPONS] |= ( 1 << WP_MELEE );
		}

		if (client->sess.karma <= -64){

		if (Q_irand(0,25) == 21){
			client->ps.fd.forcePowersKnown |= (1 << FP_GRIP);
			client->ps.fd.forcePowerLevel[FP_GRIP] = FORCE_LEVEL_3;
			client->ps.fd.forcePowersKnown |= (1 << FP_RAGE);
			client->ps.fd.forcePowerLevel[FP_RAGE] = FORCE_LEVEL_3;
			WP_ForcePowerStart( ent, FP_RAGE, 0 );
			trap_SendServerCommand( -1, va("print \"^7%s has ^1the wootygrip!\n\"", client->pers.netname) );
		}else{
			client->ps.fd.forcePowersKnown &= ~(1 << FP_GRIP);
			client->ps.fd.forcePowersKnown &= ~(1 << FP_RAGE);
		}

			client->ps.fd.forcePowersKnown |= (1 << FP_LIGHTNING);
			client->ps.fd.forcePowerLevel[FP_LIGHTNING] = FORCE_LEVEL_1;

			client->ps.fd.forcePowersKnown |= (1 << FP_PULL);
			client->ps.fd.forcePowerLevel[FP_PULL] = FORCE_LEVEL_2;

			if (client->sess.karma <= -256){
				client->ps.fd.forcePowerLevel[FP_LIGHTNING] = FORCE_LEVEL_2;
			
				client->ps.fd.forcePowersKnown |= (1 << FP_PULL);
				client->ps.fd.forcePowerLevel[FP_PULL] = FORCE_LEVEL_1;

				if (client->sess.karma <= -512){
					client->ps.fd.forcePowerLevel[FP_LIGHTNING] = FORCE_LEVEL_3;
					client->ps.fd.forcePowersKnown &= ~(1 << FP_PULL);
				}
			}
		}
		if (client->sess.karma >= 64){
			client->ps.fd.forcePowersKnown |= (1 << FP_PROTECT);
			client->ps.fd.forcePowerLevel[FP_PROTECT] = FORCE_LEVEL_1;

			if (client->sess.karma >= 128){
				client->ps.fd.forcePowerLevel[FP_PROTECT] = FORCE_LEVEL_2;
			
				if (client->sess.karma >= 256){
					client->ps.fd.forcePowersKnown |= (1 << FP_TELEPATHY);
					client->ps.fd.forcePowerLevel[FP_TELEPATHY] = FORCE_LEVEL_1;
				}
				if (client->sess.karma >= 512){
					client->ps.fd.forcePowerLevel[FP_TELEPATHY] = FORCE_LEVEL_2;
				}
			}
		}

		////client->ps.stats[STAT_WEAPONS] |= ( 1 << WP_CONCUSSION );
		////client->ps.ammo[AMMO_METAL_BOLTS] = 249;

		client->ps.weaponstate = WEAPON_RAISING;
		client->ps.weaponTime = client->ps.torsoTimer;
	}

	// don't allow full run speed for a bit
	client->ps.pm_flags |= PMF_TIME_KNOCKBACK;
	client->ps.pm_time = 100;

	client->respawnTime = level.time;
	client->inactivityTime = level.time + g_inactivity.integer * 1000;
	client->latched_buttons = 0;

	if ( level.intermissiontime ) {
		MoveClientToIntermission( ent );
	} else {
		// fire the targets of the spawn point
		G_UseTargets( spawnPoint, ent );

		// select the highest weapon number available, after any
		// spawn given items have fired
		/*
		client->ps.weapon = 1;
		for ( i = WP_NUM_WEAPONS - 1 ; i > 0 ; i-- ) {
			if ( client->ps.stats[STAT_WEAPONS] & ( 1 << i ) ) {
				client->ps.weapon = i;
				break;
			}
		}
		*/
	}

	//set teams for NPCs to recognize
	if (g_gametype.integer == GT_SIEGE)
	{ //Imperial (team1) team is allied with "enemy" NPCs in this mode
		if (client->sess.sessionTeam == SIEGETEAM_TEAM1)
		{
			client->playerTeam = ent->s.teamowner = NPCTEAM_ENEMY;
			client->enemyTeam = NPCTEAM_PLAYER;
		}
		else
		{
			client->playerTeam = ent->s.teamowner = NPCTEAM_PLAYER;
			client->enemyTeam = NPCTEAM_ENEMY;
		}
	}
	else
	{
		client->playerTeam = ent->s.teamowner = NPCTEAM_PLAYER;
		client->enemyTeam = NPCTEAM_ENEMY;
	}

	/*
	//scaling for the power duel opponent
	if (g_gametype.integer == GT_POWERDUEL &&
		client->sess.duelTeam == DUELTEAM_LONE )
	{
		//1.25
		if ( rand() % 15 == 1){
			//trap_SendServerCommand( -1, va("print \"^1GOLIATH!!!\n\"") );
			client->ps.iModelScale = 150;
			VectorSet(ent->modelScale, 1.50f, 1.50f, 1.50f);
			client->ps.basespeed = client->ps.basespeed *.75;
			client->ps.stats[STAT_HEALTH] = 225;
			



		//}else{
			//client->ps.iModelScale = 100;
			//VectorSet(ent->modelScale, 1.00f, 1.00f, 1.00f);

		}
	}

	*/
	//Disabled. At least for now. Not sure if I'll want to do it or not eventually.


	// run a client frame to drop exactly to the floor,
	// initialize animations and other things
	client->ps.commandTime = level.time - 100;
	ent->client->pers.cmd.serverTime = level.time;
	ClientThink( ent-g_entities, NULL );

	// positively link the client, even if the command times are weird
	if ( ent->client->sess.sessionTeam != TEAM_SPECTATOR ) {
		BG_PlayerStateToEntityState( &client->ps, &ent->s, qtrue );
		VectorCopy( ent->client->ps.origin, ent->r.currentOrigin );
		trap_LinkEntity( ent );
	}

	if (g_spawnInvulnerability.integer)
	{
		ent->client->ps.eFlags |= EF_INVULNERABLE;
		ent->client->invulnerableTimer = level.time + g_spawnInvulnerability.integer;
	}

	// run the presend to set anything else
	ClientEndFrame( ent );

	// clear entity state values
	BG_PlayerStateToEntityState( &client->ps, &ent->s, qtrue );

	//rww - make sure client has a valid icarus instance
	trap_ICARUS_FreeEnt( ent );
	trap_ICARUS_InitEnt( ent );
}
int ReadKeys( int clientNum, char filetype[MAX_INFO_STRING]) {
	char		correctname[MAX_INFO_STRING], dirkey[MAX_INFO_STRING];
	char		*value, valuestr[128];
	int valueint;
	int lc = 0, ac = 0, bc = 0; 
         fileHandle_t f; 
         int j; 
         int len; 
         char *cnf, *cnf2, killpath[64]; 
         char *t; 
//		 gentity_t *ent = &g_entities[clientNum];
		gclient_t *cl = &level.clients[clientNum];


	if (!cl){
		return 0;
	}

//if (IsABot(clientNum)){
// cnf = malloc(26);
//strcpy(cnf, "^1Bots not ranked.");
//goto nomore2;
//}
		strcpy(correctname, cl->pers.netname);
		for (j = 0; j<=strlen(correctname); j++){
			if 
			(correctname[(j-1)] == '.'
			|| correctname[(j-1)] == '>'
			|| correctname[(j-1)] == '<'
			|| correctname[(j-1)] == '*'
			|| correctname[(j-1)] == ':'
			|| correctname[(j-1)] == '?'
			|| correctname[(j-1)] == '|'){
				correctname[(j-1)] = '!';
			}
		}
		/*strcpy(dirkey,"!!");
		dirkey[0] = cl->pers.netname[0];
		if (cl->pers.netname[1] > 0){
		dirkey[1] = cl->pers.netname[1];
		}else{
			dirkey[1] = dirkey[0];
		}

		if (
			(dirkey[0] >= 'a' && dirkey[0] <= 'z')||
			(dirkey[0] >= 'A' && dirkey[0] <= 'Z')||
			(dirkey[0] >= '0' && dirkey[0] <= '9')
		){
		}else{
			dirkey[0] = '!';
		}
		if (
			(dirkey[1] >= 'a' && dirkey[1] <= 'z')||
			(dirkey[1] >= 'A' && dirkey[1] <= 'Z')||
			(dirkey[1] >= '0' && dirkey[1] <= '9')
		){
		}else{
			dirkey[1] = '!';
		}*/

		len = trap_FS_FOpenFile(va("ranks/%s/%s.%s",filetype,correctname,filetype), &f, FS_READ) ;  
        if(len > 0) { 
			char *cnf;
			cnf = malloc(len); 
			trap_FS_Read(cnf, len, f); 
			*(cnf + len) = '\0'; 
			trap_FS_FCloseFile(f);
			return atoi(cnf);
			
			
		} else{trap_FS_FCloseFile(f);
		return 0;}
	} 




void WriteKeys( int clientNum, int keytype, qboolean realzero) {
	char		correctname[MAX_INFO_STRING], dirkey[MAX_INFO_STRING],userinfo[MAX_INFO_STRING];
	char		*value, valuestr[128];
	int valueint;
	int lc = 0, ac = 0, bc = 0; 
         fileHandle_t f; 
         int j; 
         int len; 
         char *cnf, *cnf2, killpath[64]; 
         char *s, *t; 
//		 gentity_t *ent = &g_entities[clientNum];
		gclient_t *cl = &level.clients[clientNum];
		qboolean verbose = qfalse;

 if (!cl){
		return;
	}
		if (cl->pers.connected != CON_CONNECTED){
			return;
		}

//keytypes:
		//0=aln/karma
		//1=str
		//2=dex
		//3=con
		//4=gold/admin_number
		//5=lvl
		//6=xp
		//7=pw/admin_name
		//8=ip
		//9=saberstyle

///perp = &g_entities[clientNum];

 

//if (IsABot(clientNum)){
// cnf = malloc(26);
//strcpy(cnf, "^1Bots not ranked.");
//goto nomore2;
//}
		strcpy(correctname, cl->pers.netname);
		for (j = 0; j<=strlen(correctname); j++){
			if 
			(correctname[(j-1)] == '.'
			|| correctname[(j-1)] == '>'
			|| correctname[(j-1)] == '<'
			|| correctname[(j-1)] == '*'
			|| correctname[(j-1)] == ':'
			|| correctname[(j-1)] == '?'
			|| correctname[(j-1)] == '|'){
				correctname[(j-1)] = '!';
			}
		}
		strcpy(dirkey,"!!");
		dirkey[0] = cl->pers.netname[0];
		if (cl->pers.netname[1] > 0){
		dirkey[1] = cl->pers.netname[1];
		}else{
			dirkey[1] = dirkey[0];
		}

		if (
			(dirkey[0] >= 'a' && dirkey[0] <= 'z')||
			(dirkey[0] >= 'A' && dirkey[0] <= 'Z')||
			(dirkey[0] >= '0' && dirkey[0] <= '9')
		){
		}else{
			dirkey[0] = '!';
		}
		if (
			(dirkey[1] >= 'a' && dirkey[1] <= 'z')||
			(dirkey[1] >= 'A' && dirkey[1] <= 'Z')||
			(dirkey[1] >= '0' && dirkey[1] <= '9')
		){
		}else{
			dirkey[1] = '!';
		}

		if((cl->sess.karma|| realzero) && (keytype == 0 || keytype == -1) && trap_FS_FOpenFile(va("ranks/aln/%s.aln",correctname), &f, FS_WRITE) >=0 ){ 
		cnf = va("%d",cl->sess.karma);
		trap_FS_Write(cnf, strlen(cnf), f); 
		 trap_FS_FCloseFile(f); 
		 if (verbose) G_Printf ( "karma: %d (%s)\n", cl->sess.karma, cl->pers.netname );
	} 
		if((cl->sess.str || realzero) && (keytype == 1 || keytype == -1)&& trap_FS_FOpenFile(va("ranks/str/%s.str",correctname), &f, FS_WRITE) >=0  ){ 
		cnf = va("%d",cl->sess.str);
		trap_FS_Write(cnf, strlen(cnf), f); 
		 trap_FS_FCloseFile(f); 
		 G_Printf ( "str: %d (%s)\n", cl->sess.str, cl->pers.netname );
	} 
		if((cl->sess.dex || realzero) && (keytype == 2 || keytype == -1)&& trap_FS_FOpenFile(va("ranks/dex/%s.dex",correctname), &f, FS_WRITE) >=0 ){ 
		cnf = va("%d",cl->sess.dex);
		trap_FS_Write(cnf, strlen(cnf), f); 
		   trap_FS_FCloseFile(f);
		   G_Printf ( "dex: %d (%s)\n", cl->sess.dex, cl->pers.netname );
	}
		if((cl->sess.con || realzero) && (keytype == 3|| keytype == -1)&& trap_FS_FOpenFile(va("ranks/cn/%s.con",correctname), &f, FS_WRITE) >=0 ){ 
		cnf = va("%d",cl->sess.con);
		trap_FS_Write(cnf, strlen(cnf), f); 
		trap_FS_FCloseFile(f); 
		G_Printf ( "con: %d (%s)\n", cl->sess.con, cl->pers.netname );
	}  
		if((cl->sess.admin_number || realzero)   && (keytype == 4 || keytype == -1)&& trap_FS_FOpenFile(va("ranks/gold/%s.gold",correctname), &f, FS_WRITE) >=0){ 
		cnf = va("%d",cl->sess.admin_number);
		trap_FS_Write(cnf, strlen(cnf), f); 
		 trap_FS_FCloseFile(f); 
		 if (verbose) G_Printf ( "gold: %d (%s)\n", cl->sess.admin_number, cl->pers.netname );
	} 
		if((cl->sess.wins|| realzero)  && (keytype == 5 || keytype == -1)&& trap_FS_FOpenFile(va("ranks/lvl/%s.lvl",correctname), &f, FS_WRITE) >=0){ 
		cnf = va("%d",cl->sess.wins);
		trap_FS_Write(cnf, strlen(cnf), f); 
		 trap_FS_FCloseFile(f); 
		 G_Printf ( "level: %d (%s)\n", cl->sess.wins, cl->pers.netname );
	} if((cl->sess.xp|| realzero) && (keytype == 6 || keytype == -1)&& trap_FS_FOpenFile(va("ranks/xp/%s.xp",correctname), &f, FS_WRITE) >=0 ){ 
		cnf = va("%d",cl->sess.xp);
		trap_FS_Write(cnf, strlen(cnf), f); 
		 trap_FS_FCloseFile(f); 
		 if (verbose)G_Printf ( "XP: %d (%s)\n", cl->sess.xp, cl->pers.netname );
	} if((keytype == 7 || keytype == -1)&& trap_FS_FOpenFile(va("ranks/pw/%s.pw",correctname), &f, FS_WRITE) >=0 ){ 
		cnf = va("%s",cl->sess.admin_name);
		trap_FS_Write(cnf, strlen(cnf), f); 
		 trap_FS_FCloseFile(f); 
		 G_Printf ( "pw: %s (%s)\n", cl->sess.admin_name, cl->pers.netname );

		 ///if (Q_stricmp(cl->sess.admin_name,"rsub")!= 0 && Q_stricmp(cl->sess.admin_name,"mooted")!= 0  && Q_stricmp(cl->sess.admin_name,"")!= 0){
			WriteKeys(clientNum,8,qtrue);
			///WriteKeys(clientNum,13,qtrue);
		 ///}

	} if((keytype == 8 || keytype == -1)&& trap_FS_FOpenFile(va("ranks/ip/%s.ip",correctname), &f, FS_WRITE) >=0 ){ 
		
		if (cl->sess.ip){
		trap_FS_Write(cl->sess.ip, strlen(cl->sess.ip), f); 
		 trap_FS_FCloseFile(f); 
		 G_Printf ( "ip: %s (%s)\n", Info_ValueForKey( userinfo, "ip" ), cl->sess.ip );
		}

	} if((cl->sess.saberLevel|| realzero) && (keytype == 9 || keytype == -1)&& trap_FS_FOpenFile(va("ranks/style/%s.style",correctname), &f, FS_WRITE) >=0 ){ 
		cnf = va("%d",cl->sess.saberLevel);
		trap_FS_Write(cnf, strlen(cnf), f); 
		 trap_FS_FCloseFile(f); 
		 G_Printf ( "saber-stance: %d (%s)\n", cl->sess.saberLevel, cl->pers.netname );
	}
	if((cl->sess.saberType|| realzero) && (keytype == 10)&& trap_FS_FOpenFile(va("ranks/stype/%s.stype",correctname), &f, FS_WRITE) >=0 ){ 
		cnf = va("%s",cl->sess.saberType);
		trap_FS_Write(cnf, strlen(cnf), f); 
		 trap_FS_FCloseFile(f); 
		 if (verbose)G_Printf ( "saber-type: %s (%s)\n", cl->sess.saberType, cl->pers.netname );
	}if((cl->sess.saber2Type|| realzero) && (keytype == 11)&& trap_FS_FOpenFile(va("ranks/stype/%s.stype2",correctname), &f, FS_WRITE) >=0 ){ 
		cnf = va("%s",cl->sess.saber2Type);
		trap_FS_Write(cnf, strlen(cnf), f); 
		 trap_FS_FCloseFile(f); 
		 if (verbose)G_Printf ( "saber-type2: %s (%s)\n", cl->sess.saber2Type, cl->pers.netname );
	}
	if((keytype == 12)&& trap_FS_FOpenFile(va("ranks/so/%s.so",correctname), &f, FS_WRITE) >=0 ){ 
		cnf = va("%d",cl->ps.fd.forcePowerLevel[FP_SABER_OFFENSE]);
		trap_FS_Write(cnf, strlen(cnf), f); 
		 trap_FS_FCloseFile(f); 
		 if (verbose)G_Printf ( "saber-offense: %d (%s)\n", cl->ps.fd.forcePowerLevel[FP_SABER_OFFENSE], cl->pers.netname );
	}
		if((keytype == 13)
			
			&& Q_stricmp(cl->pers.netname,"Player") 
			&& Q_stricmp(cl->pers.netname,"Padawan") 
			&& Q_stricmp(cl->pers.netname,"PADAWANG")
			&& trap_FS_FOpenFile(va("ranks/pwd/%s.pwd",correctname), &f, FS_WRITE)>=0){ 
			cnf = va("%s",cl->sess.pass_name);
			trap_FS_Write(cnf, strlen(cnf), f); 
			trap_FS_FCloseFile(f); 
			trap_SendServerCommand( clientNum, va("print \"^7Password set: %s ^7(u: %s)\n\"",cnf,cl->pers.netname) );
			////trap_SendServerCommand( clientNum, va("print \"^1Warning: no password set (u: %s^1)\n\"",cl->pers.netname) );
		}
	if((keytype == 14)&& trap_FS_FOpenFile(va("ranks/mdl/%s.mdl",correctname), &f, FS_WRITE) >=0 ){ 
		strcpy(cnf,cl->modelname);
		trap_FS_Write(cnf, strlen(cnf), f); 
		 trap_FS_FCloseFile(f); 
		 G_Printf ( "model: %s (%s)\n", cl->modelname, cl->pers.netname );
	}


return 0;
}

/*
===========
ClientDisconnect

Called when a player drops from the server.
Will not be called between levels.

This should NOT be called directly by any game logic,
call trap_DropClient(), which will call this and do
server system housekeeping.
============
*/
void ClientDisconnect( int clientNum ) {
	gentity_t	*ent;
	gentity_t	*tent;
	int			i;

	// cleanup if we are kicking a bot that
	// hasn't spawned yet

	///WriteKeys(clientNum,-1,qfalse);

	G_RemoveQueuedBotBegin( clientNum );
	

	ent = g_entities + clientNum;
	if ( !ent->client ) {
		return;
	}

	///dewoot?
	if (level.intermissiontime > level.time){
	return;
	}

	trap_SendServerCommand( -1, va("cp \"^2%s^2 ^1(%i)^2 has\n^2entered the egress.\n\"", 
			ent->client->pers.netname, clientNum));
		trap_SendServerCommand( -1, va("print \"^2%s^2 ^1(%i)^2 has ^2entered the egress.\n\"", 
			ent->client->pers.netname, clientNum));
	i = 0;

	while (i < NUM_FORCE_POWERS)
	{
		if (ent->client->ps.fd.forcePowersActive & (1 << i))
		{
			WP_ForcePowerStop(ent, i);
		}
		i++;
	}

	i = TRACK_CHANNEL_1;

	while (i < NUM_TRACK_CHANNELS)
	{
		if (ent->client->ps.fd.killSoundEntIndex[i-50] && ent->client->ps.fd.killSoundEntIndex[i-50] < MAX_GENTITIES && ent->client->ps.fd.killSoundEntIndex[i-50] > 0)
		{
			G_MuteSound(ent->client->ps.fd.killSoundEntIndex[i-50], CHAN_VOICE);
		}
		i++;
	}
	i = 0;

	if (ent->client->ps.m_iVehicleNum)
	{ //tell it I'm getting off
		gentity_t *veh = &g_entities[ent->client->ps.m_iVehicleNum];

		if (veh->inuse && veh->client && veh->m_pVehicle)
		{
			int pCon = ent->client->pers.connected;

			ent->client->pers.connected = 0;
			veh->m_pVehicle->m_pVehicleInfo->Eject(veh->m_pVehicle, (bgEntity_t *)ent, qtrue);
			ent->client->pers.connected = pCon;
		}
	}

	// stop any following clients
	for ( i = 0 ; i < level.maxclients ; i++ ) {
		if ( level.clients[i].sess.sessionTeam == TEAM_SPECTATOR
			&& level.clients[i].sess.spectatorState == SPECTATOR_FOLLOW
			&& level.clients[i].sess.spectatorClient == clientNum ) {
			StopFollowing( &g_entities[i] );
		}
	}

	// send effect if they were completely connected
	if ( ent->client->pers.connected == CON_CONNECTED 
		&& ent->client->sess.sessionTeam != TEAM_SPECTATOR ) {
		tent = G_TempEntity( ent->client->ps.origin, EV_PLAYER_TELEPORT_OUT );
		tent->s.clientNum = ent->s.clientNum;

		// They don't get to take powerups with them!
		// Especially important for stuff like CTF flags
		TossClientItems( ent );
	}

	G_LogPrintf( "ClientDisconnect: %i\n", clientNum );

	// if we are playing in tourney mode, give a win to the other player and clear his frags for this round
	if ( (g_gametype.integer == GT_DUEL )
		&& !level.intermissiontime
		&& !level.warmupTime ) {
		if ( level.sortedClients[1] == clientNum ) {
			level.clients[ level.sortedClients[0] ].ps.persistant[PERS_SCORE] = 0;
			/////level.clients[ level.sortedClients[0] ].sess.wins++;
			ClientUserinfoChanged( level.sortedClients[0] );
		}
		else if ( level.sortedClients[0] == clientNum ) {
			level.clients[ level.sortedClients[1] ].ps.persistant[PERS_SCORE] = 0;
			/////level.clients[ level.sortedClients[1] ].sess.wins++;
			ClientUserinfoChanged( level.sortedClients[1] );
		}
	}

	if (ent->ghoul2 && trap_G2_HaveWeGhoul2Models(ent->ghoul2))
	{
		trap_G2API_CleanGhoul2Models(&ent->ghoul2);
	}
	i = 0;
	while (i < MAX_SABERS)
	{
		if (ent->client->weaponGhoul2[i] && trap_G2_HaveWeGhoul2Models(ent->client->weaponGhoul2[i]))
		{
			trap_G2API_CleanGhoul2Models(&ent->client->weaponGhoul2[i]);
		}
		i++;
	}

	trap_UnlinkEntity (ent);
	ent->s.modelindex = 0;
	ent->inuse = qfalse;
	ent->classname = "disconnected";
	ent->client->pers.connected = CON_DISCONNECTED;
	ent->client->ps.persistant[PERS_TEAM] = TEAM_FREE;
	ent->client->sess.sessionTeam = TEAM_FREE;
	ent->r.contents = 0;

	trap_SetConfigstring( CS_PLAYERS + clientNum, "");

	CalculateRanks();

	if ( ent->r.svFlags & SVF_BOT ) {
		BotAIShutdownClient( clientNum, qfalse );
	}

	G_ClearClientLog(clientNum);
}


