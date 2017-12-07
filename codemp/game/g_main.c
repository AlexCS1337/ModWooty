// Copyright (C) 1999-2000 Id Software, Inc.
//

#include "g_local.h"
#include "g_ICARUScb.h"
#include "g_nav.h"
#include "bg_saga.h"

level_locals_t	level;

int		eventClearTime = 0;
static int navCalcPathTime = 0;
extern int fatalErrors;

int killPlayerTimer = 0;

typedef struct {
	vmCvar_t	*vmCvar;
	char		*cvarName;
	char		*defaultString;
	int			cvarFlags;
	int			modificationCount;  // for tracking changes
	qboolean	trackChange;	    // track this variable, and announce if changed
  qboolean teamShader;        // track and if changed, update shader state
} cvarTable_t;




/*typedef struct {
	char		*name;
	int			score;

} playername;

playername play[999];*/

gentity_t		g_entities[MAX_GENTITIES];
gclient_t		g_clients[MAX_CLIENTS];
qboolean gDuelExit = qfalse;

vmCvar_t	g_trueJedi;

vmCvar_t	g_gametype;
vmCvar_t	g_MaxHolocronCarry;
vmCvar_t	g_ff_objectives;
vmCvar_t	g_autoMapCycle;
vmCvar_t	g_dmflags;
vmCvar_t	g_maxForceRank;
vmCvar_t	g_forceBasedTeams;
vmCvar_t	g_privateDuel;

vmCvar_t	g_allowNPC;

vmCvar_t	g_armBreakage;

vmCvar_t	g_saberLocking;
vmCvar_t	g_saberLockFactor;
vmCvar_t	g_saberTraceSaberFirst;

vmCvar_t	d_saberKickTweak;

vmCvar_t	d_powerDuelPrint;

vmCvar_t	d_saberGhoul2Collision;
vmCvar_t	g_saberBladeFaces;
vmCvar_t	d_saberAlwaysBoxTrace;
vmCvar_t	d_saberBoxTraceSize;

vmCvar_t	d_siegeSeekerNPC;

vmCvar_t	g_debugMelee;
vmCvar_t	g_stepSlideFix;

vmCvar_t	g_noSpecMove;

#ifdef _DEBUG
vmCvar_t	g_disableServerG2;
#endif

vmCvar_t	d_perPlayerGhoul2;

vmCvar_t	d_projectileGhoul2Collision;

vmCvar_t	g_g2TraceLod;

vmCvar_t	g_optvehtrace;

vmCvar_t	g_locationBasedDamage;

vmCvar_t	g_allowHighPingDuelist;

vmCvar_t	g_logClientInfo;

vmCvar_t	g_slowmoDuelEnd;

vmCvar_t	g_saberDamageScale;

vmCvar_t	g_useWhileThrowing;

vmCvar_t	g_RMG;

vmCvar_t	g_svfps;

vmCvar_t	g_forceRegenTime;
vmCvar_t	g_spawnInvulnerability;
vmCvar_t	g_forcePowerDisable;
vmCvar_t	g_weaponDisable;
vmCvar_t	g_duelWeaponDisable;
vmCvar_t	g_allowDuelSuicide;
vmCvar_t	g_fraglimitVoteCorrection;
vmCvar_t	g_fraglimit;
vmCvar_t	g_duel_fraglimit;
vmCvar_t	g_timelimit;
vmCvar_t	g_capturelimit;
vmCvar_t	d_saberInterpolate;
vmCvar_t	g_friendlyFire;
vmCvar_t	g_friendlySaber;
vmCvar_t	g_fallfadetime;
////
vmCvar_t g_subadminpw;
vmCvar_t g_goldadminpw;
vmCvar_t g_motd;
vmCvar_t g_debugthrow;
vmCvar_t g_flipkickvelocity;
vmCvar_t g_flipkickdamage;
vmCvar_t g_meleedamage;
vmCvar_t g_crane;
vmCvar_t g_leveling;
vmCvar_t g_candropsaber;
vmCvar_t g_canfalldown;
vmCvar_t g_canmeleekata;
vmCvar_t g_canjk2roll;
vmCvar_t g_candivecrane;
vmCvar_t g_cancloak;
vmCvar_t g_meleeshield;
vmCvar_t g_canmeleedeflect;
vmCvar_t g_canhadoken;
vmCvar_t g_canhadokenfire;
vmCvar_t g_autorecover;
vmCvar_t g_canbuy;
vmCvar_t g_killpath;

vmCvar_t g_hadokenforce;
vmCvar_t g_flipkickforce;
vmCvar_t g_craneforce;
vmCvar_t g_divecraneforce;
vmCvar_t g_throwforce;
vmCvar_t g_dropsaberforce;
vmCvar_t g_falldownforce;
vmCvar_t g_meleekataforce;
vmCvar_t g_butterflyforce;
vmCvar_t g_cartwheelforce;
vmCvar_t g_kataforce;
vmCvar_t g_emoteforce;
vmCvar_t g_fakedeathforce;

vmCvar_t g_secretballot;
vmCvar_t g_suddendeathtime;
vmCvar_t g_matchtime;
///
vmCvar_t g_walljumpforce;
vmCvar_t g_walljumpXvelocity;
vmCvar_t g_walljumpYvelocity;
vmCvar_t g_walljumpZvelocity;
vmCvar_t g_karmapluspw;
vmCvar_t g_karmaminuspw;
vmCvar_t g_100goldpw;
vmCvar_t g_jetpacks;

vmCvar_t g_debugemotes;
vmCvar_t g_debugmw;
vmCvar_t g_tkbot;
vmCvar_t g_spawnalt;
vmCvar_t g_autothrow;
vmCvar_t g_uberthrow;
vmCvar_t g_intermissiontime;
vmCvar_t g_serverculldist;

vmCvar_t g_logstats;
/////
vmCvar_t	g_password;
vmCvar_t	g_needpass;
vmCvar_t	g_maxclients;
vmCvar_t	g_maxGameClients;
vmCvar_t	g_dedicated;
vmCvar_t	g_developer;
vmCvar_t	g_speed;
vmCvar_t	g_gravity;
vmCvar_t	g_cheats;
vmCvar_t	g_knockback;
vmCvar_t	g_quadfactor;
vmCvar_t	g_forcerespawn;
vmCvar_t	g_siegeRespawn;
vmCvar_t	g_inactivity;
vmCvar_t	g_debugMove;
#ifndef FINAL_BUILD
vmCvar_t	g_debugDamage;
#endif
vmCvar_t	g_debugAlloc;
vmCvar_t	g_debugServerSkel;
vmCvar_t	g_weaponRespawn;
vmCvar_t	g_weaponTeamRespawn;
vmCvar_t	g_adaptRespawn;
vmCvar_t	g_motd;
vmCvar_t	g_synchronousClients;
vmCvar_t	g_warmup;
vmCvar_t	g_doWarmup;
vmCvar_t	g_restarted;
vmCvar_t	g_log;
vmCvar_t	g_logSync;
vmCvar_t	g_statLog;
vmCvar_t	g_statLogFile;
vmCvar_t	g_blood;
vmCvar_t	g_podiumDist;
vmCvar_t	g_podiumDrop;
vmCvar_t	g_allowVote;
vmCvar_t	g_teamAutoJoin;
vmCvar_t	g_teamForceBalance;
vmCvar_t	g_banIPs;
vmCvar_t	g_filterBan;
vmCvar_t	g_debugForward;
vmCvar_t	g_debugRight;
vmCvar_t	g_debugUp;
vmCvar_t	g_smoothClients;

#include "../namespace_begin.h"
vmCvar_t	pmove_fixed;
vmCvar_t	pmove_msec;
#include "../namespace_end.h"

vmCvar_t	g_listEntity;
//vmCvar_t	g_redteam;
//vmCvar_t	g_blueteam;
vmCvar_t	g_singlePlayer;
vmCvar_t	g_enableBreath;
vmCvar_t	g_dismember;
vmCvar_t	g_forceDodge;
vmCvar_t	g_timeouttospec;

vmCvar_t	g_saberDmgVelocityScale;
vmCvar_t	g_saberDmgDelay_Idle;
vmCvar_t	g_saberDmgDelay_Wound;

vmCvar_t	g_saberDebugPrint;

vmCvar_t	g_siegeTeamSwitch;

vmCvar_t	bg_fighterAltControl;

#ifdef DEBUG_SABER_BOX
vmCvar_t	g_saberDebugBox;
#endif

//NPC nav debug
vmCvar_t	d_altRoutes;
vmCvar_t	d_patched;

vmCvar_t		g_saberRealisticCombat;
vmCvar_t		g_saberRestrictForce;
vmCvar_t		d_saberSPStyleDamage;
vmCvar_t		g_debugSaberLocks;
vmCvar_t		g_saberLockRandomNess;
// nmckenzie: SABER_DAMAGE_WALLS
vmCvar_t		g_saberWallDamageScale;

vmCvar_t		d_saberStanceDebug;
// ai debug cvars
vmCvar_t		debugNPCAI;			// used to print out debug info about the bot AI
vmCvar_t		debugNPCFreeze;		// set to disable bot ai and temporarily freeze them in place
vmCvar_t		debugNPCAimingBeam;
vmCvar_t		debugBreak;
vmCvar_t		debugNoRoam;
vmCvar_t		d_saberCombat;
vmCvar_t		d_JediAI;
vmCvar_t		d_noGroupAI;
vmCvar_t		d_asynchronousGroupAI;
vmCvar_t		d_slowmodeath;
vmCvar_t		d_noIntermissionWait;

vmCvar_t		g_spskill;


vmCvar_t		g_siegeTeam1;
vmCvar_t		g_siegeTeam2;

vmCvar_t	g_austrian;

vmCvar_t	g_powerDuelStartHealth;
vmCvar_t	g_powerDuelEndHealth;

// nmckenzie: temporary way to show player healths in duels - some iface gfx in game would be better, of course.
// DUEL_HEALTH
vmCvar_t		g_showDuelHealths;

// bk001129 - made static to avoid aliasing
static cvarTable_t		gameCvarTable[] = {
	// don't override the cheat state set by the system
	{ &g_cheats, "sv_cheats", "", 0, 0, qfalse },

	{ &g_debugMelee, "g_debugMelee", "0", CVAR_SERVERINFO, 0, qtrue  },
	{ &g_stepSlideFix, "g_stepSlideFix", "1", CVAR_SERVERINFO, 0, qtrue  },

	{ &g_noSpecMove, "g_noSpecMove", "0", CVAR_SERVERINFO, 0, qtrue },

	// noset vars
	{ NULL, "gamename", GAMEVERSION , CVAR_SERVERINFO | CVAR_ROM, 0, qfalse  },
	{ NULL, "gamedate", __DATE__ , CVAR_ROM, 0, qfalse  },
	{ &g_restarted, "g_restarted", "0", CVAR_ROM, 0, qfalse  },
	{ NULL, "sv_mapname", "", CVAR_SERVERINFO | CVAR_ROM, 0, qfalse  },

	// latched vars
	{ &g_gametype, "g_gametype", "0", CVAR_SERVERINFO | CVAR_LATCH, 0, qfalse  },
	{ &g_MaxHolocronCarry, "g_MaxHolocronCarry", "3", CVAR_SERVERINFO | CVAR_LATCH, 0, qfalse  },

	{ &g_maxclients, "sv_maxclients", "8", CVAR_SERVERINFO | CVAR_LATCH | CVAR_ARCHIVE, 0, qfalse  },
	{ &g_maxGameClients, "g_maxGameClients", "0", CVAR_SERVERINFO | CVAR_LATCH | CVAR_ARCHIVE, 0, qfalse  },

	{ &g_trueJedi, "g_jediVmerc", "0", CVAR_SERVERINFO | CVAR_LATCH | CVAR_ARCHIVE, 0, qtrue },

	// change anytime vars
	{ &g_ff_objectives, "g_ff_objectives", "0", /*CVAR_SERVERINFO |*/ CVAR_CHEAT | CVAR_NORESTART, 0, qtrue },

	{ &g_autoMapCycle, "g_autoMapCycle", "0", CVAR_ARCHIVE | CVAR_NORESTART, 0, qtrue },
	{ &g_dmflags, "dmflags", "0", CVAR_SERVERINFO | CVAR_ARCHIVE, 0, qtrue  },
	
	{ &g_maxForceRank, "g_maxForceRank", "6", CVAR_SERVERINFO | CVAR_ARCHIVE | CVAR_LATCH, 0, qfalse  },
	{ &g_forceBasedTeams, "g_forceBasedTeams", "0", CVAR_SERVERINFO | CVAR_ARCHIVE | CVAR_LATCH, 0, qfalse  },
	{ &g_privateDuel, "g_privateDuel", "1", CVAR_SERVERINFO | CVAR_ARCHIVE, 0, qtrue  },

	{ &g_allowNPC, "g_allowNPC", "1", CVAR_SERVERINFO | CVAR_CHEAT, 0, qtrue  },

	{ &g_armBreakage, "g_armBreakage", "0", 0, 0, qtrue  },

	{ &g_saberLocking, "g_saberLocking", "1", CVAR_SERVERINFO | CVAR_ARCHIVE, 0, qtrue  },
	{ &g_saberLockFactor, "g_saberLockFactor", "2", CVAR_ARCHIVE, 0, qtrue  },
	{ &g_saberTraceSaberFirst, "g_saberTraceSaberFirst", "0", CVAR_ARCHIVE, 0, qtrue  },

	{ &d_saberKickTweak, "d_saberKickTweak", "1", 0, 0, qtrue  },

	{ &d_powerDuelPrint, "d_powerDuelPrint", "0", 0, qtrue },

	{ &d_saberGhoul2Collision, "d_saberGhoul2Collision", "1", CVAR_CHEAT, 0, qtrue  },
	{ &g_saberBladeFaces, "g_saberBladeFaces", "1", 0, 0, qtrue  },

	{ &d_saberAlwaysBoxTrace, "d_saberAlwaysBoxTrace", "0", CVAR_CHEAT, 0, qtrue  },
	{ &d_saberBoxTraceSize, "d_saberBoxTraceSize", "0", CVAR_CHEAT, 0, qtrue  },

	{ &d_siegeSeekerNPC, "d_siegeSeekerNPC", "0", CVAR_CHEAT, 0, qtrue },

#ifdef _DEBUG
	{ &g_disableServerG2, "g_disableServerG2", "0", 0, 0, qtrue },
#endif

	{ &d_perPlayerGhoul2, "d_perPlayerGhoul2", "0", CVAR_CHEAT, 0, qtrue },

	{ &d_projectileGhoul2Collision, "d_projectileGhoul2Collision", "1", CVAR_CHEAT, 0, qtrue  },

	{ &g_g2TraceLod, "g_g2TraceLod", "3", 0, 0, qtrue  },

	{ &g_optvehtrace, "com_optvehtrace", "0", 0, 0, qtrue  },

	{ &g_locationBasedDamage, "g_locationBasedDamage", "1", 0, 0, qtrue },

	{ &g_allowHighPingDuelist, "g_allowHighPingDuelist", "1", 0, 0, qtrue },

	{ &g_logClientInfo, "g_logClientInfo", "0", CVAR_ARCHIVE, 0, qtrue  },

	{ &g_slowmoDuelEnd, "g_slowmoDuelEnd", "0", CVAR_ARCHIVE, 0, qtrue  },

	{ &g_saberDamageScale, "g_saberDamageScale", "1", CVAR_ARCHIVE, 0, qtrue  },

	{ &g_useWhileThrowing, "g_useWhileThrowing", "1", 0, 0, qtrue  },

	{ &g_RMG, "RMG", "0", 0, 0, qtrue  },

	{ &g_svfps, "sv_fps", "20", 0, 0, qtrue },

	{ &g_forceRegenTime, "g_forceRegenTime", "200", CVAR_SERVERINFO | CVAR_ARCHIVE, 0, qtrue  },

	{ &g_spawnInvulnerability, "g_spawnInvulnerability", "3000", CVAR_ARCHIVE, 0, qtrue  },

	{ &g_forcePowerDisable, "g_forcePowerDisable", "0", CVAR_SERVERINFO | CVAR_ARCHIVE | CVAR_LATCH, 0, qtrue  },
	{ &g_weaponDisable, "g_weaponDisable", "0", CVAR_SERVERINFO | CVAR_ARCHIVE | CVAR_LATCH, 0, qtrue  },
	{ &g_duelWeaponDisable, "g_duelWeaponDisable", "1", CVAR_SERVERINFO | CVAR_ARCHIVE | CVAR_LATCH, 0, qtrue  },

	{ &g_allowDuelSuicide, "g_allowDuelSuicide", "1", CVAR_ARCHIVE, 0, qtrue },

	{ &g_fraglimitVoteCorrection, "g_fraglimitVoteCorrection", "1", CVAR_ARCHIVE, 0, qtrue },

	{ &g_fraglimit, "fraglimit", "20", CVAR_SERVERINFO | CVAR_ARCHIVE | CVAR_NORESTART, 0, qtrue },
	{ &g_duel_fraglimit, "duel_fraglimit", "10", CVAR_SERVERINFO | CVAR_ARCHIVE | CVAR_NORESTART, 0, qtrue },
	{ &g_timelimit, "timelimit", "0", CVAR_SERVERINFO | CVAR_ARCHIVE | CVAR_NORESTART, 0, qtrue },
	{ &g_capturelimit, "capturelimit", "8", CVAR_SERVERINFO | CVAR_ARCHIVE | CVAR_NORESTART, 0, qtrue },

	{ &g_synchronousClients, "g_synchronousClients", "0", CVAR_SYSTEMINFO, 0, qfalse  },

	{ &d_saberInterpolate, "d_saberInterpolate", "0", CVAR_CHEAT, 0, qtrue },

	{ &g_friendlyFire, "g_friendlyFire", "1", CVAR_ARCHIVE, 0, qtrue  },
	{ &g_friendlySaber, "g_friendlySaber", "1", CVAR_ARCHIVE, 0, qtrue  },
	{ &g_fallfadetime, "mw_fallfadetime", "2000", CVAR_ARCHIVE, 0, qtrue  },
	
	////
	
	{ &g_flipkickvelocity, "mw_flipkickvelocity", "36", CVAR_ARCHIVE, 0, qtrue  },
	{ &g_flipkickdamage, "mw_flipkickdamage", "5", CVAR_ARCHIVE, 0, qtrue  },
	{ &g_meleedamage, "mw_meleedamage", "8", CVAR_ARCHIVE, 0, qtrue  },
	{ &g_crane, "mw_cancrane", "1", CVAR_ARCHIVE, 0, qtrue  },
	{ &g_leveling, "mw_canlevel", "1", CVAR_ARCHIVE, 0, qtrue  },
	

	{ &g_subadminpw, "mw_subadminpw", "0", CVAR_INTERNAL, 0, qfalse  },
	{ &g_goldadminpw, "mw_goldadminpw", "0", CVAR_INTERNAL, 0, qfalse  },
	//{ &g_subadminpw, "mw_subadminpw", "0", CVAR_ARCHIVE, 0, qfalse  },
	//{ &g_goldadminpw, "mw_goldadminpw", "0", CVAR_ARCHIVE, 0, qfalse  },
	
	///{ &g_motd, "mw_motd", "0", CVAR_ARCHIVE, 0, qfalse  },
	{ &g_debugthrow, "mw_canthrow", "1", CVAR_ARCHIVE, 0, qtrue  },

	{ &g_candropsaber, "mw_candropsaber", "1", CVAR_ARCHIVE, 0, qtrue  },
	{ &g_canfalldown, "mw_canfalldown", "1", CVAR_ARCHIVE, 0, qtrue  },
	{ &g_canjk2roll, "mw_canjk2roll", "0", CVAR_ARCHIVE, 0, qtrue  },

	{ &g_canmeleekata, "mw_canmeleekata", "1", CVAR_ARCHIVE, 0, qtrue  },
	{ &g_candivecrane, "mw_candivecrane", "1", CVAR_ARCHIVE, 0, qtrue  },
	{ &g_cancloak, "mw_cancloak", "1", CVAR_ARCHIVE, 0, qtrue  },
	{ &g_meleeshield, "mw_meleeshield", "5", CVAR_ARCHIVE, 0, qtrue  },
	{ &g_canmeleedeflect, "mw_canmeleedeflect", "1", CVAR_ARCHIVE, 0, qtrue  },
	{ &g_canhadoken, "mw_canhadoken", "1", CVAR_ARCHIVE, 0, qtrue  },
	{ &g_canhadokenfire, "mw_canhadokenfire", "0", CVAR_ARCHIVE, 0, qtrue  },
	{ &g_autorecover, "mw_autorecover", "0", CVAR_ARCHIVE, 0, qtrue  },

	{ &g_canbuy, "mw_canbuy", "1", CVAR_ARCHIVE, 0, qtrue  },
	{ &g_killpath, "g_killpath", "1", CVAR_ARCHIVE, 0, qtrue  },

	{ &g_flipkickforce, "mw_flipkickforce", "25", CVAR_ARCHIVE, 0, qtrue  },
	{ &g_craneforce, "mw_craneforce", "30", CVAR_ARCHIVE, 0, qtrue  },
	{ &g_divecraneforce, "mw_divecraneforce", "0", CVAR_ARCHIVE, 0, qtrue  },
	{ &g_throwforce, "mw_throwforce", "50", CVAR_ARCHIVE, 0, qtrue  },
	{ &g_dropsaberforce, "mw_dropsaberforce", "10", CVAR_ARCHIVE, 0, qtrue  },
	{ &g_falldownforce, "mw_falldownforce", "15", CVAR_ARCHIVE, 0, qtrue  },
	{ &g_meleekataforce, "mw_meleekataforce", "10", CVAR_ARCHIVE, 0, qtrue  },
	{ &g_kataforce, "mw_kataforce", "40", CVAR_ARCHIVE, 0, qtrue  },
	{ &g_emoteforce, "mw_emoteforce", "30", CVAR_ARCHIVE, 0, qtrue  },
	{ &g_fakedeathforce, "mw_fakedeathforce", "20", CVAR_ARCHIVE, 0, qtrue  },

	{ &g_hadokenforce, "mw_hadokenforce", "25", CVAR_ARCHIVE, 0, qtrue  },


	{ &g_walljumpforce, "mw_walljumpforce", "10", CVAR_ARCHIVE, 0, qtrue  },
	{ &g_walljumpXvelocity, "mw_walljumpXvelocity", "50", CVAR_ARCHIVE, 0, qtrue  },
	{ &g_walljumpYvelocity, "mw_walljumpYvelocity", "125", CVAR_ARCHIVE, 0, qtrue  },
	{ &g_walljumpZvelocity, "mw_walljumpZvelocity", "1", CVAR_ARCHIVE, 0, qtrue  },

	{ &g_karmapluspw, "mw_karmapluspw", "0", CVAR_INTERNAL, 0, qfalse  },
	{ &g_karmaminuspw, "mw_karmaminuspw", "0", CVAR_INTERNAL, 0, qfalse  },
	{ &g_100goldpw, "mw_100goldpw", "0", CVAR_INTERNAL, 0, qfalse  },
	{ &g_jetpacks, "mw_jetpacks", "1", CVAR_ARCHIVE, 0, qfalse  },

	{ &g_debugemotes, "mw_debugemotes", "0", CVAR_ARCHIVE, 0, qtrue  },
	{ &g_debugmw, "mw_debugmw", "0", CVAR_ARCHIVE, 0, qtrue  },
	{ &g_butterflyforce, "mw_butterflyforce", "0", CVAR_ARCHIVE, 0, qtrue  },
	{ &g_cartwheelforce, "mw_cartwheelforce", "0", CVAR_ARCHIVE, 0, qtrue  },
	{ &g_suddendeathtime, "mw_suddendeathtime", "300", CVAR_ARCHIVE, 0, qtrue  },
	///{ &g_matchtime, "mw_matchtime", "0", CVAR_ARCHIVE, 0, qtrue  },
	{ &g_tkbot, "mw_tkbot", "1", CVAR_ARCHIVE, 0, qtrue  },
	{ &g_spawnalt, "mw_spawnalt", "2", CVAR_ARCHIVE, 0, qtrue  },
	{ &g_autothrow, "mw_autothrow", "0", CVAR_ARCHIVE, 0, qtrue  },
	{ &g_uberthrow, "mw_uberthrow", "0", CVAR_ARCHIVE, 0, qtrue  },
	{ &g_serverculldist, "mw_serverculldist", "6000", CVAR_ARCHIVE, 0, qtrue  },

	{ &g_logstats, "mw_logstats", "1", CVAR_ARCHIVE, 0, qtrue  },
	{ &g_secretballot, "mw_secretballot", "0", CVAR_ARCHIVE, 0, qtrue  },
	{ &g_intermissiontime, "mw_intermissiontime", "4000", CVAR_ARCHIVE, 0, qtrue  },

	////
	{ &g_teamAutoJoin, "g_teamAutoJoin", "0", CVAR_ARCHIVE  },
	{ &g_teamForceBalance, "g_teamForceBalance", "0", CVAR_ARCHIVE  },

	{ &g_warmup, "g_warmup", "20", CVAR_ARCHIVE, 0, qtrue  },
	{ &g_doWarmup, "g_doWarmup", "0", 0, 0, qtrue  },
	{ &g_log, "g_log", "games.log", CVAR_ARCHIVE, 0, qfalse  },
	{ &g_logSync, "g_logSync", "0", CVAR_ARCHIVE, 0, qfalse  },

	{ &g_statLog, "g_statLog", "0", CVAR_ARCHIVE, 0, qfalse },
	{ &g_statLogFile, "g_statLogFile", "statlog.log", CVAR_ARCHIVE, 0, qfalse },

	{ &g_password, "g_password", "", CVAR_USERINFO, 0, qfalse  },

	{ &g_banIPs, "g_banIPs", "", CVAR_ARCHIVE, 0, qfalse  },
	{ &g_filterBan, "g_filterBan", "1", CVAR_ARCHIVE, 0, qfalse  },

	{ &g_needpass, "g_needpass", "0", CVAR_SERVERINFO | CVAR_ROM, 0, qfalse },

	{ &g_dedicated, "dedicated", "0", 0, 0, qfalse  },

	{ &g_developer, "developer", "0", 0, 0, qfalse },

	{ &g_speed, "g_speed", "275", 0, 0, qtrue  },
	{ &g_gravity, "g_gravity", "800", 0, 0, qtrue  },
	{ &g_knockback, "g_knockback", "1000", 0, 0, qtrue  },
	{ &g_quadfactor, "g_quadfactor", "3", 0, 0, qtrue  },
	{ &g_weaponRespawn, "g_weaponrespawn", "5", 0, 0, qtrue  },
	{ &g_weaponTeamRespawn, "g_weaponTeamRespawn", "5", 0, 0, qtrue },
	{ &g_adaptRespawn, "g_adaptrespawn", "1", 0, 0, qtrue  },		// Make weapons respawn faster with a lot of players.
	{ &g_forcerespawn, "g_forcerespawn", "60", 0, 0, qtrue },		// One minute force respawn.  Give a player enough time to reallocate force.
	{ &g_siegeRespawn, "g_siegeRespawn", "20", CVAR_SERVERINFO | CVAR_ARCHIVE, 0, qtrue }, //siege respawn wave time
	{ &g_inactivity, "g_inactivity", "600", 0, 0, qtrue },
	{ &g_debugMove, "g_debugMove", "0", 0, 0, qfalse },
#ifndef FINAL_BUILD
{ &g_debugDamage, "g_debugDamage", "0", 0, 0, qfalse },
#endif
	{ &g_debugAlloc, "g_debugAlloc", "0", 0, 0, qfalse },
	{ &g_debugServerSkel, "g_debugServerSkel", "0", CVAR_CHEAT, 0, qfalse },
	{ &g_motd, "g_motd", "", 0, 0, qfalse },
	{ &g_blood, "com_blood", "1", 0, 0, qfalse },

	{ &g_podiumDist, "g_podiumDist", "80", 0, 0, qfalse },
	{ &g_podiumDrop, "g_podiumDrop", "70", 0, 0, qfalse },

	{ &g_allowVote, "g_allowVote", "1", CVAR_ARCHIVE, 0, qfalse },
	{ &g_listEntity, "g_listEntity", "0", 0, 0, qfalse },

#if 0
	{ &g_debugForward, "g_debugForward", "0", 0, 0, qfalse },
	{ &g_debugRight, "g_debugRight", "0", 0, 0, qfalse },
	{ &g_debugUp, "g_debugUp", "0", 0, 0, qfalse },
#endif

//	{ &g_redteam, "g_redteam", "Empire", CVAR_ARCHIVE | CVAR_SERVERINFO | CVAR_USERINFO , 0, qtrue, qtrue },
//	{ &g_blueteam, "g_blueteam", "Rebellion", CVAR_ARCHIVE | CVAR_SERVERINFO | CVAR_USERINFO , 0, qtrue, qtrue  },
	{ &g_singlePlayer, "ui_singlePlayerActive", "", 0, 0, qfalse, qfalse  },

	{ &g_enableBreath, "g_enableBreath", "0", 0, 0, qtrue, qfalse },
	{ &g_smoothClients, "g_smoothClients", "1", 0, 0, qfalse},
	{ &pmove_fixed, "pmove_fixed", "0", CVAR_SYSTEMINFO, 0, qfalse},
	{ &pmove_msec, "pmove_msec", "8", CVAR_SYSTEMINFO, 0, qfalse},

	{ &g_dismember, "g_dismember", "0", CVAR_ARCHIVE, 0, qtrue  },
	{ &g_forceDodge, "g_forceDodge", "1", 0, 0, qtrue  },

	{ &g_timeouttospec, "g_timeouttospec", "70", CVAR_ARCHIVE, 0, qfalse },

	{ &g_saberDmgVelocityScale, "g_saberDmgVelocityScale", "0", CVAR_ARCHIVE, 0, qtrue  },
	{ &g_saberDmgDelay_Idle, "g_saberDmgDelay_Idle", "350", CVAR_ARCHIVE, 0, qtrue  },
	{ &g_saberDmgDelay_Wound, "g_saberDmgDelay_Wound", "0", CVAR_ARCHIVE, 0, qtrue  },

#ifndef FINAL_BUILD
{ &g_saberDebugPrint, "g_saberDebugPrint", "0", CVAR_CHEAT, 0, qfalse  },
#endif
	{ &g_debugSaberLocks, "g_debugSaberLocks", "0", CVAR_CHEAT, 0, qfalse },
	{ &g_saberLockRandomNess, "g_saberLockRandomNess", "2", CVAR_CHEAT, 0, qfalse },
// nmckenzie: SABER_DAMAGE_WALLS
	{ &g_saberWallDamageScale, "g_saberWallDamageScale", "0.4", CVAR_SERVERINFO, 0, qfalse },

	{ &d_saberStanceDebug, "d_saberStanceDebug", "0", 0, 0, qfalse },

	{ &g_siegeTeamSwitch, "g_siegeTeamSwitch", "1", CVAR_SERVERINFO|CVAR_ARCHIVE, qfalse },

	{ &bg_fighterAltControl, "bg_fighterAltControl", "0", CVAR_SERVERINFO, 0, qtrue },

#ifdef DEBUG_SABER_BOX
	{ &g_saberDebugBox, "g_saberDebugBox", "0", CVAR_CHEAT, 0, qfalse },
#endif

	{ &d_altRoutes, "d_altRoutes", "0", CVAR_CHEAT, 0, qfalse },
	{ &d_patched, "d_patched", "0", CVAR_CHEAT, 0, qfalse },

	{ &g_saberRealisticCombat, "g_saberRealisticCombat", "0", CVAR_CHEAT },
	{ &g_saberRestrictForce, "g_saberRestrictForce", "0", CVAR_CHEAT },
	{ &d_saberSPStyleDamage, "d_saberSPStyleDamage", "1", CVAR_CHEAT },

	{ &debugNoRoam, "d_noroam", "0", CVAR_CHEAT },
	{ &debugNPCAimingBeam, "d_npcaiming", "0", CVAR_CHEAT },
	{ &debugBreak, "d_break", "0", CVAR_CHEAT },
	{ &debugNPCAI, "d_npcai", "0", CVAR_CHEAT },
	{ &debugNPCFreeze, "d_npcfreeze", "0", CVAR_CHEAT },
	{ &d_JediAI, "d_JediAI", "0", CVAR_CHEAT },
	{ &d_noGroupAI, "d_noGroupAI", "0", CVAR_CHEAT },
	{ &d_asynchronousGroupAI, "d_asynchronousGroupAI", "0", CVAR_CHEAT },
	
	//0 = never (BORING)
	//1 = kyle only
	//2 = kyle and last enemy jedi
	//3 = kyle and any enemy jedi
	//4 = kyle and last enemy in a group
	//5 = kyle and any enemy
	//6 = also when kyle takes pain or enemy jedi dodges player saber swing or does an acrobatic evasion

	{ &d_slowmodeath, "d_slowmodeath", "0", CVAR_CHEAT },

	{ &d_saberCombat, "d_saberCombat", "0", CVAR_CHEAT },

	{ &g_spskill, "g_npcspskill", "0", CVAR_ARCHIVE | CVAR_INTERNAL },

	//for overriding the level defaults
	/*{ &g_siegeTeam1, "g_siegeTeam1", "none", CVAR_ARCHIVE|CVAR_SERVERINFO, 0, qfalse  },
	{ &g_siegeTeam2, "g_siegeTeam2", "none", CVAR_ARCHIVE|CVAR_SERVERINFO, 0, qfalse  },*/
	{ &g_siegeTeam1, "g_siegeTeam1", "n", CVAR_ARCHIVE, 0, qfalse  },
	{ &g_siegeTeam2, "g_siegeTeam2", "n", CVAR_ARCHIVE, 0, qfalse  },

	//mainly for debugging with bots while I'm not around (want the server to
	//cycle through levels naturally)
	{ &d_noIntermissionWait, "d_noIntermissionWait", "0", CVAR_CHEAT, 0, qfalse  },

	{ &g_austrian, "g_austrian", "0", CVAR_ARCHIVE, 0, qfalse  },
// nmckenzie:
// DUEL_HEALTH
	{ &g_showDuelHealths, "g_showDuelHealths", "0", CVAR_SERVERINFO },
	{ &g_powerDuelStartHealth, "g_powerDuelStartHealth", "150", CVAR_ARCHIVE, 0, qtrue  },
	{ &g_powerDuelEndHealth, "g_powerDuelEndHealth", "90", CVAR_ARCHIVE, 0, qtrue  },
};

// bk001129 - made static to avoid aliasing
static int gameCvarTableSize = sizeof( gameCvarTable ) / sizeof( gameCvarTable[0] );


void G_InitGame					( int levelTime, int randomSeed, int restart );
void G_RunFrame					( int levelTime );
void G_ShutdownGame				( int restart );
void CheckExitRules				( void );
void G_ROFF_NotetrackCallback	( gentity_t *cent, const char *notetrack);

extern stringID_table_t setTable[];

qboolean G_ParseSpawnVars( qboolean inSubBSP );
void G_SpawnGEntityFromSpawnVars( qboolean inSubBSP );


qboolean NAV_ClearPathToPoint( gentity_t *self, vec3_t pmins, vec3_t pmaxs, vec3_t point, int clipmask, int okToHitEntNum );
qboolean NPC_ClearLOS2( gentity_t *ent, const vec3_t end );
int NAVNEW_ClearPathBetweenPoints(vec3_t start, vec3_t end, vec3_t mins, vec3_t maxs, int ignore, int clipmask);
qboolean NAV_CheckNodeFailedForEnt( gentity_t *ent, int nodeNum );
qboolean G_EntIsUnlockedDoor( int entityNum );
qboolean G_EntIsDoor( int entityNum );
qboolean G_EntIsBreakable( int entityNum );
qboolean G_EntIsRemovableUsable( int entNum );
void CP_FindCombatPointWaypoints( void );

/*
================
vmMain

This is the only way control passes into the module.
This must be the very first function compiled into the .q3vm file
================
*/
#include "../namespace_begin.h"
#ifdef __linux__
extern "C" {
#endif
int vmMain( int command, int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11  ) {
	switch ( command ) {
	case GAME_INIT:
		G_InitGame( arg0, arg1, arg2 );
		return 0;
	case GAME_SHUTDOWN:
		G_ShutdownGame( arg0 );
		return 0;
	case GAME_CLIENT_CONNECT:
		return (int)ClientConnect( arg0, arg1, arg2 );
	case GAME_CLIENT_THINK:
		ClientThink( arg0, NULL );
		return 0;
	case GAME_CLIENT_USERINFO_CHANGED:
		ClientUserinfoChanged( arg0 );
		return 0;
	case GAME_CLIENT_DISCONNECT:
		ClientDisconnect( arg0 );
		return 0;
	case GAME_CLIENT_BEGIN:
		ClientBegin( arg0, qtrue );
		return 0;
	case GAME_CLIENT_COMMAND:
		ClientCommand( arg0 );
		return 0;
	case GAME_RUN_FRAME:
		G_RunFrame( arg0 );
		return 0;
	case GAME_CONSOLE_COMMAND:
		return ConsoleCommand();
	case BOTAI_START_FRAME:
		return BotAIStartFrame( arg0 );
	case GAME_ROFF_NOTETRACK_CALLBACK:
		G_ROFF_NotetrackCallback( &g_entities[arg0], (const char *)arg1 );
		return 0;
	case GAME_SPAWN_RMG_ENTITY:
		if (G_ParseSpawnVars(qfalse))
		{
			G_SpawnGEntityFromSpawnVars(qfalse);
		}
		return 0;

	//rww - begin icarus callbacks
	case GAME_ICARUS_PLAYSOUND:
		{
			T_G_ICARUS_PLAYSOUND *sharedMem = (T_G_ICARUS_PLAYSOUND *)gSharedBuffer;
			return Q3_PlaySound(sharedMem->taskID, sharedMem->entID, sharedMem->name, sharedMem->channel);
		}
	case GAME_ICARUS_SET:
		{
			T_G_ICARUS_SET *sharedMem = (T_G_ICARUS_SET *)gSharedBuffer;
			return Q3_Set(sharedMem->taskID, sharedMem->entID, sharedMem->type_name, sharedMem->data);
		}
	case GAME_ICARUS_LERP2POS:
		{
			T_G_ICARUS_LERP2POS *sharedMem = (T_G_ICARUS_LERP2POS *)gSharedBuffer;
			if (sharedMem->nullAngles)
			{
				Q3_Lerp2Pos(sharedMem->taskID, sharedMem->entID, sharedMem->origin, NULL, sharedMem->duration);
			}
			else
			{
				Q3_Lerp2Pos(sharedMem->taskID, sharedMem->entID, sharedMem->origin, sharedMem->angles, sharedMem->duration);
			}
		}
		return 0;
	case GAME_ICARUS_LERP2ORIGIN:
		{
			T_G_ICARUS_LERP2ORIGIN *sharedMem = (T_G_ICARUS_LERP2ORIGIN *)gSharedBuffer;
			Q3_Lerp2Origin(sharedMem->taskID, sharedMem->entID, sharedMem->origin, sharedMem->duration);
		}
		return 0;
	case GAME_ICARUS_LERP2ANGLES:
		{
			T_G_ICARUS_LERP2ANGLES *sharedMem = (T_G_ICARUS_LERP2ANGLES *)gSharedBuffer;
			Q3_Lerp2Angles(sharedMem->taskID, sharedMem->entID, sharedMem->angles, sharedMem->duration);
		}
		return 0;
	case GAME_ICARUS_GETTAG:
		{
			T_G_ICARUS_GETTAG *sharedMem = (T_G_ICARUS_GETTAG *)gSharedBuffer;
			return Q3_GetTag(sharedMem->entID, sharedMem->name, sharedMem->lookup, sharedMem->info);
		}
	case GAME_ICARUS_LERP2START:
		{
			T_G_ICARUS_LERP2START *sharedMem = (T_G_ICARUS_LERP2START *)gSharedBuffer;
			Q3_Lerp2Start(sharedMem->entID, sharedMem->taskID, sharedMem->duration);
		}
		return 0;
	case GAME_ICARUS_LERP2END:
		{
			T_G_ICARUS_LERP2END *sharedMem = (T_G_ICARUS_LERP2END *)gSharedBuffer;
			Q3_Lerp2End(sharedMem->entID, sharedMem->taskID, sharedMem->duration);
		}
		return 0;
	case GAME_ICARUS_USE:
		{
			T_G_ICARUS_USE *sharedMem = (T_G_ICARUS_USE *)gSharedBuffer;
			Q3_Use(sharedMem->entID, sharedMem->target);
		}
		return 0;
	case GAME_ICARUS_KILL:
		{
			T_G_ICARUS_KILL *sharedMem = (T_G_ICARUS_KILL *)gSharedBuffer;
			Q3_Kill(sharedMem->entID, sharedMem->name);
		}
		return 0;
	case GAME_ICARUS_REMOVE:
		{
			T_G_ICARUS_REMOVE *sharedMem = (T_G_ICARUS_REMOVE *)gSharedBuffer;
			Q3_Remove(sharedMem->entID, sharedMem->name);
		}
		return 0;
	case GAME_ICARUS_PLAY:
		{
			T_G_ICARUS_PLAY *sharedMem = (T_G_ICARUS_PLAY *)gSharedBuffer;
			Q3_Play(sharedMem->taskID, sharedMem->entID, sharedMem->type, sharedMem->name);
		}
		return 0;
	case GAME_ICARUS_GETFLOAT:
		{
			T_G_ICARUS_GETFLOAT *sharedMem = (T_G_ICARUS_GETFLOAT *)gSharedBuffer;
			return Q3_GetFloat(sharedMem->entID, sharedMem->type, sharedMem->name, &sharedMem->value);
		}
	case GAME_ICARUS_GETVECTOR:
		{
			T_G_ICARUS_GETVECTOR *sharedMem = (T_G_ICARUS_GETVECTOR *)gSharedBuffer;
			return Q3_GetVector(sharedMem->entID, sharedMem->type, sharedMem->name, sharedMem->value);
		}
	case GAME_ICARUS_GETSTRING:
		{
			T_G_ICARUS_GETSTRING *sharedMem = (T_G_ICARUS_GETSTRING *)gSharedBuffer;
			int r;
			char *crap = NULL; //I am sorry for this -rww
			char **morecrap = &crap; //and this
			r = Q3_GetString(sharedMem->entID, sharedMem->type, sharedMem->name, morecrap);

			if (crap)
			{ //success!
				strcpy(sharedMem->value, crap);
			}

			return r;
		}
	case GAME_ICARUS_SOUNDINDEX:
		{
			T_G_ICARUS_SOUNDINDEX *sharedMem = (T_G_ICARUS_SOUNDINDEX *)gSharedBuffer;
			G_SoundIndex(sharedMem->filename);
		}
		return 0;
	case GAME_ICARUS_GETSETIDFORSTRING:
		{
			T_G_ICARUS_GETSETIDFORSTRING *sharedMem = (T_G_ICARUS_GETSETIDFORSTRING *)gSharedBuffer;
			return GetIDForString(setTable, sharedMem->string);
		}
	//rww - end icarus callbacks

	case GAME_NAV_CLEARPATHTOPOINT:
		return NAV_ClearPathToPoint(&g_entities[arg0], (float *)arg1, (float *)arg2, (float *)arg3, arg4, arg5);
	case GAME_NAV_CLEARLOS:
		return NPC_ClearLOS2(&g_entities[arg0], (const float *)arg1);
	case GAME_NAV_CLEARPATHBETWEENPOINTS:
		return NAVNEW_ClearPathBetweenPoints((float *)arg0, (float *)arg1, (float *)arg2, (float *)arg3, arg4, arg5);
	case GAME_NAV_CHECKNODEFAILEDFORENT:
		return NAV_CheckNodeFailedForEnt(&g_entities[arg0], arg1);
	case GAME_NAV_ENTISUNLOCKEDDOOR:
		return G_EntIsUnlockedDoor(arg0);
	case GAME_NAV_ENTISDOOR:
		return G_EntIsDoor(arg0);
	case GAME_NAV_ENTISBREAKABLE:
		return G_EntIsBreakable(arg0);
	case GAME_NAV_ENTISREMOVABLEUSABLE:
		return G_EntIsRemovableUsable(arg0);
	case GAME_NAV_FINDCOMBATPOINTWAYPOINTS:
		CP_FindCombatPointWaypoints();
		return 0;
	case GAME_GETITEMINDEXBYTAG:
		return BG_GetItemIndexByTag(arg0, arg1);
	}

	return -1;
}
#ifdef __linux__
}
#endif
#include "../namespace_end.h"


void QDECL G_Printf( const char *fmt, ... ) {
	va_list		argptr;
	char		text[1024];

	va_start (argptr, fmt);
	vsprintf (text, fmt, argptr);
	va_end (argptr);

	trap_Printf( text );
}

void QDECL G_Error( const char *fmt, ... ) {
	va_list		argptr;
	char		text[1024];

	va_start (argptr, fmt);
	vsprintf (text, fmt, argptr);
	va_end (argptr);


	G_LogPrintf( text);
	///trap_Error( text );
}

/*
================
G_FindTeams

Chain together all entities with a matching team field.
Entity teams are used for item groups and multi-entity mover groups.

All but the first will have the FL_TEAMSLAVE flag set and teammaster field set
All but the last will have the teamchain field set to the next one
================
*/
void G_FindTeams( void ) {
	gentity_t	*e, *e2;
	int		i, j;
	int		c, c2;

	c = 0;
	c2 = 0;
	for ( i=1, e=g_entities+i ; i < level.num_entities ; i++,e++ ){
		if (!e->inuse)
			continue;
		if (!e->team)
			continue;
		if (e->flags & FL_TEAMSLAVE)
			continue;
		if (e->r.contents==CONTENTS_TRIGGER)
			continue;//triggers NEVER link up in teams!
		e->teammaster = e;
		c++;
		c2++;
		for (j=i+1, e2=e+1 ; j < level.num_entities ; j++,e2++)
		{
			if (!e2->inuse)
				continue;
			if (!e2->team)
				continue;
			if (e2->flags & FL_TEAMSLAVE)
				continue;
			if (!strcmp(e->team, e2->team))
			{
				c2++;
				e2->teamchain = e->teamchain;
				e->teamchain = e2;
				e2->teammaster = e;
				e2->flags |= FL_TEAMSLAVE;

				// make sure that targets only point at the master
				if ( e2->targetname ) {
					e->targetname = e2->targetname;
					e2->targetname = NULL;
				}
			}
		}
	}

//	G_Printf ("%i teams with %i entities\n", c, c2);
}

void G_RemapTeamShaders( void ) {
#if 0
	char string[1024];
	float f = level.time * 0.001;
	Com_sprintf( string, sizeof(string), "team_icon/%s_red", g_redteam.string );
	AddRemap("textures/ctf2/redteam01", string, f); 
	AddRemap("textures/ctf2/redteam02", string, f); 
	Com_sprintf( string, sizeof(string), "team_icon/%s_blue", g_blueteam.string );
	AddRemap("textures/ctf2/blueteam01", string, f); 
	AddRemap("textures/ctf2/blueteam02", string, f); 
	trap_SetConfigstring(CS_SHADERSTATE, BuildShaderStateConfig());
#endif
}


/*
=================
G_RegisterCvars
=================
*/
void G_RegisterCvars( void ) {
	int			i;
	cvarTable_t	*cv;
	qboolean remapped = qfalse;

	for ( i = 0, cv = gameCvarTable ; i < gameCvarTableSize ; i++, cv++ ) {
		trap_Cvar_Register( cv->vmCvar, cv->cvarName,
			cv->defaultString, cv->cvarFlags );
		if ( cv->vmCvar )
			cv->modificationCount = cv->vmCvar->modificationCount;

		if (cv->teamShader) {
			remapped = qtrue;
		}
	}

	if (remapped) {
		G_RemapTeamShaders();
	}

	// check some things
	if ( g_gametype.integer < 0 || g_gametype.integer >= GT_MAX_GAME_TYPE ) {
		G_Printf( "g_gametype %i is out of range, defaulting to 0\n", g_gametype.integer );
		trap_Cvar_Set( "g_gametype", "0" );
	}
	else if (g_gametype.integer == GT_HOLOCRON)
	{
		G_Printf( "This gametype is not supported.\n" );
		trap_Cvar_Set( "g_gametype", "0" );
	}
	else if (g_gametype.integer == GT_JEDIMASTER)
	{
		G_Printf( "This gametype is not supported.\n" );
		trap_Cvar_Set( "g_gametype", "0" );
	}
	else if (g_gametype.integer == GT_CTY)
	{
		G_Printf( "This gametype is not supported.\n" );
		trap_Cvar_Set( "g_gametype", "0" );
	}

	level.warmupModificationCount = g_warmup.modificationCount;
}

/*
=================
G_UpdateCvars
=================
*/
void G_UpdateCvars( void ) {
	int			i;
	cvarTable_t	*cv;
	qboolean remapped = qfalse;

	for ( i = 0, cv = gameCvarTable ; i < gameCvarTableSize ; i++, cv++ ) {
		if ( cv->vmCvar ) {
			trap_Cvar_Update( cv->vmCvar );

			if ( cv->modificationCount != cv->vmCvar->modificationCount ) {
				cv->modificationCount = cv->vmCvar->modificationCount;

				if ( cv->trackChange ) {
					trap_SendServerCommand( -1, va("print \"Server: %s changed to %s\n\"", 
						cv->cvarName, cv->vmCvar->string ) );
				}

				if (cv->teamShader) {
					remapped = qtrue;
				}				
			}
		}
	}

	if (remapped) {
		G_RemapTeamShaders();
	}
}

char gSharedBuffer[MAX_G_SHARED_BUFFER_SIZE];

#include "../namespace_begin.h"
void WP_SaberLoadParms( void );
void BG_VehicleLoadParms( void );
#include "../namespace_end.h"

/*
============
G_InitGame

============
*/
extern void RemoveAllWP(void);
extern void BG_ClearVehicleParseParms(void);
void G_InitGame( int levelTime, int randomSeed, int restart ) {
	int					i;
	vmCvar_t	mapname;
	vmCvar_t	ckSum;

#ifdef _XBOX
	if(restart) {
		BG_ClearVehicleParseParms();
		RemoveAllWP();
	}
#endif

	//Init RMG to 0, it will be autoset to 1 if there is terrain on the level.
	trap_Cvar_Set("RMG", "0");
	g_RMG.integer = 0;

	//Clean up any client-server ghoul2 instance attachments that may still exist exe-side
	trap_G2API_CleanEntAttachments();

	BG_InitAnimsets(); //clear it out

	B_InitAlloc(); //make sure everything is clean

	trap_SV_RegisterSharedMemory(gSharedBuffer);

	//Load external vehicle data
	BG_VehicleLoadParms();

	G_Printf ("------- Game Initialization -------\n");
	G_Printf ("gamename: %s\n", GAMEVERSION);
	G_Printf ("gamedate: %s\n", __DATE__);

	srand( randomSeed );

	G_RegisterCvars();

	G_ProcessIPBans();

	G_InitMemory();

	// set some level globals
	memset( &level, 0, sizeof( level ) );
	level.time = levelTime;
	level.startTime = levelTime;

	level.snd_fry = G_SoundIndex("sound/player/fry.wav");	// FIXME standing in lava / slime

	level.snd_hack = G_SoundIndex("sound/player/hacking.wav");
	level.snd_medHealed = G_SoundIndex("sound/player/supp_healed.wav");
	level.snd_medSupplied = G_SoundIndex("sound/player/supp_supplied.wav");

	//trap_SP_RegisterServer("mp_svgame");

#ifndef _XBOX
	if ( g_log.string[0] ) {
		if ( g_logSync.integer ) {
			trap_FS_FOpenFile( g_log.string, &level.logFile, FS_APPEND_SYNC );
		} else {
			trap_FS_FOpenFile( g_log.string, &level.logFile, FS_APPEND );
		}
		if ( !level.logFile ) {
			G_Printf( "WARNING: Couldn't open logfile: %s\n", g_log.string );
		} else {
			char	serverinfo[MAX_INFO_STRING];

			trap_GetServerinfo( serverinfo, sizeof( serverinfo ) );

			G_LogPrintf("------------------------------------------------------------\n" );
			G_LogPrintf("InitGame: %s\n", serverinfo );
		}
	} else {
		G_Printf( "Not logging to disk.\n" );
	}
#endif

	G_LogWeaponInit();

	G_InitWorldSession();

	// initialize all entities for this game
	memset( g_entities, 0, MAX_GENTITIES * sizeof(g_entities[0]) );
	level.gentities = g_entities;

	// initialize all clients for this game
	level.maxclients = g_maxclients.integer;
	memset( g_clients, 0, MAX_CLIENTS * sizeof(g_clients[0]) );
	level.clients = g_clients;

	// set client fields on player ents
	for ( i=0 ; i<level.maxclients ; i++ ) {
		g_entities[i].client = level.clients + i;
	}

	// always leave room for the max number of clients,
	// even if they aren't all used, so numbers inside that
	// range are NEVER anything but clients
	level.num_entities = MAX_CLIENTS;

	// let the server system know where the entites are
	trap_LocateGameData( level.gentities, level.num_entities, sizeof( gentity_t ), 
		&level.clients[0].ps, sizeof( level.clients[0] ) );

	//Load sabers.cfg data
	WP_SaberLoadParms();

	NPC_InitGame();
	
	TIMER_Clear();
	//
	//ICARUS INIT START

//	Com_Printf("------ ICARUS Initialization ------\n");

	trap_ICARUS_Init();

//	Com_Printf ("-----------------------------------\n");

	//ICARUS INIT END
	//

	// reserve some spots for dead player bodies
	InitBodyQue();

	ClearRegisteredItems();

	//make sure saber data is loaded before this! (so we can precache the appropriate hilts)
	InitSiegeMode();

	trap_Cvar_Register( &mapname, "mapname", "", CVAR_SERVERINFO | CVAR_ROM );
	trap_Cvar_Register( &ckSum, "sv_mapChecksum", "", CVAR_ROM );

	navCalculatePaths	= ( trap_Nav_Load( mapname.string, ckSum.integer ) == qfalse );

	// parse the key/value pairs and spawn gentities
	G_SpawnEntitiesFromString(qfalse);

	// general initialization
	G_FindTeams();

	// make sure we have flags for CTF, etc
	if( g_gametype.integer >= GT_TEAM ) {
		G_CheckTeamItems();
	}
	else if ( g_gametype.integer == GT_JEDIMASTER )
	{
		trap_SetConfigstring ( CS_CLIENT_JEDIMASTER, "-1" );
	}

	if (g_gametype.integer == GT_POWERDUEL)
	{
		trap_SetConfigstring ( CS_CLIENT_DUELISTS, va("-1|-1|-1") );
	}
	else
	{
		trap_SetConfigstring ( CS_CLIENT_DUELISTS, va("-1|-1") );
	}
// nmckenzie: DUEL_HEALTH: Default.
	trap_SetConfigstring ( CS_CLIENT_DUELHEALTHS, va("-1|-1|!") );
	trap_SetConfigstring ( CS_CLIENT_DUELWINNER, va("-1") );

	SaveRegisteredItems();

	//G_Printf ("-----------------------------------\n");

	if( g_gametype.integer == GT_SINGLE_PLAYER || trap_Cvar_VariableIntegerValue( "com_buildScript" ) ) {
		G_ModelIndex( SP_PODIUM_MODEL );
		G_SoundIndex( "sound/player/gurp1.wav" );
		G_SoundIndex( "sound/player/gurp2.wav" );
	}

	if ( trap_Cvar_VariableIntegerValue( "bot_enable" ) ) {
		BotAISetup( restart );
		BotAILoadMap( restart );
		G_InitBots( restart );
	}

	G_RemapTeamShaders();

	if ( g_gametype.integer == GT_DUEL || g_gametype.integer == GT_POWERDUEL )
	{
		G_LogPrintf("Duel Tournament Begun: kill limit %d, win limit: %d\n", g_fraglimit.integer, g_duel_fraglimit.integer );
	}

	if ( navCalculatePaths )
	{//not loaded - need to calc paths
		navCalcPathTime = level.time + START_TIME_NAV_CALC;//make sure all ents are in and linked
	}
	else
	{//loaded
		//FIXME: if this is from a loadgame, it needs to be sure to write this 
		//out whenever you do a savegame since the edges and routes are dynamic...
		//OR: always do a navigator.CheckBlockedEdges() on map startup after nav-load/calc-paths
		//navigator.pathsCalculated = qtrue;//just to be safe?  Does this get saved out?  No... assumed
		trap_Nav_SetPathsCalculated(qtrue);
		//need to do this, because combatpoint waypoints aren't saved out...?
		CP_FindCombatPointWaypoints();
		navCalcPathTime = 0;

		/*
		if ( g_eSavedGameJustLoaded == eNO )
		{//clear all the failed edges unless we just loaded the game (which would include failed edges)
			trap_Nav_ClearAllFailedEdges();
		}
		*/
		//No loading games in MP.
	}

	/*if (g_gametype.integer == GT_SIEGE)
	{ //just get these configstrings registered now...
		int i = 0;
		while (i < MAX_CUSTOM_SIEGE_SOUNDS)
		{
			if (!bg_customSiegeSoundNames[i])
			{
				break;
			}
			G_SoundIndex((char *)bg_customSiegeSoundNames[i]);
			i++;
		}
	}*/
}



/*
=================
G_ShutdownGame
=================
*/
void G_ShutdownGame( int restart ) {
	int i = 0;
	gentity_t *ent;

//	G_Printf ("==== ShutdownGame ====\n");

	G_CleanAllFakeClients(); //get rid of dynamically allocated fake client structs.

	BG_ClearAnimsets(); //free all dynamic allocations made through the engine

//	Com_Printf("... Gameside GHOUL2 Cleanup\n");
	while (i < MAX_GENTITIES)
	{ //clean up all the ghoul2 instances
		ent = &g_entities[i];

		if (ent->ghoul2 && trap_G2_HaveWeGhoul2Models(ent->ghoul2))
		{
			trap_G2API_CleanGhoul2Models(&ent->ghoul2);
			ent->ghoul2 = NULL;
		}
		if (ent->client)
		{
			int j = 0;

			while (j < MAX_SABERS)
			{
				if (ent->client->weaponGhoul2[j] && trap_G2_HaveWeGhoul2Models(ent->client->weaponGhoul2[j]))
				{
					trap_G2API_CleanGhoul2Models(&ent->client->weaponGhoul2[j]);
				}
				j++;
			}
		}
		i++;
	}
	if (g2SaberInstance && trap_G2_HaveWeGhoul2Models(g2SaberInstance))
	{
		trap_G2API_CleanGhoul2Models(&g2SaberInstance);
		g2SaberInstance = NULL;
	}
	if (precachedKyle && trap_G2_HaveWeGhoul2Models(precachedKyle))
	{
		trap_G2API_CleanGhoul2Models(&precachedKyle);
		precachedKyle = NULL;
	}

//	Com_Printf ("... ICARUS_Shutdown\n");
	trap_ICARUS_Shutdown ();	//Shut ICARUS down

//	Com_Printf ("... Reference Tags Cleared\n");
	TAG_Init();	//Clear the reference tags

	G_LogWeaponOutput();

	if ( level.logFile ) {
		G_LogPrintf("ShutdownGame:\n" );
		G_LogPrintf("------------------------------------------------------------\n" );
		trap_FS_FCloseFile( level.logFile );
	}

	// write all the client session data so we can get it back
	G_WriteSessionData();

	trap_ROFF_Clean();

	if ( trap_Cvar_VariableIntegerValue( "bot_enable" ) ) {
		BotAIShutdown( restart );
	}

	B_CleanupAlloc(); //clean up all allocations made with B_Alloc
}



//===================================================================

#ifndef GAME_HARD_LINKED
// this is only here so the functions in q_shared.c and bg_*.c can link

void QDECL Com_Error ( int level, const char *error, ... ) {
	va_list		argptr;
	char		text[1024];

	va_start (argptr, error);
	vsprintf (text, error, argptr);
	va_end (argptr);

	G_Error( "%s", text);
}

void QDECL Com_Printf( const char *msg, ... ) {
	va_list		argptr;
	char		text[1024];

	va_start (argptr, msg);
	vsprintf (text, msg, argptr);
	va_end (argptr);

	G_Printf ("%s", text);
}

#endif

/*
========================================================================

PLAYER COUNTING / SCORE SORTING

========================================================================
*/

/*
=============
AddTournamentPlayer

If there are less than two tournament players, put a
spectator in the game and restart
=============
*/
void AddTournamentPlayer( void ) {
	int			i;
	gclient_t	*client;
	gclient_t	*nextInLine;

	if ( level.numPlayingClients >= 2 ) {
		return;
	}

	// never change during intermission
//	if ( level.intermissiontime ) {
//		return;
//	}

	nextInLine = NULL;

	for ( i = 0 ; i < level.maxclients ; i++ ) {
		client = &level.clients[i];
		if ( client->pers.connected != CON_CONNECTED ) {
			continue;
		}
		if (!g_allowHighPingDuelist.integer && client->ps.ping >= 999)
		{ //don't add people who are lagging out if cvar is not set to allow it.
			continue;
		}
		if ( client->sess.sessionTeam != TEAM_SPECTATOR ) {
			continue;
		}
		// never select the dedicated follow or scoreboard clients
		if ( client->sess.spectatorState == SPECTATOR_SCOREBOARD || 
			client->sess.spectatorClient < 0  ) {
			continue;
		}

		if ( !nextInLine || client->sess.spectatorTime < nextInLine->sess.spectatorTime ) {
			nextInLine = client;
		}
	}

	if ( !nextInLine ) {
		return;
	}

	level.warmupTime = -1;

	// set them to free-for-all team
	SetTeam( &g_entities[ nextInLine - level.clients ], "f" );
}

/*
=======================
RemoveTournamentLoser

Make the loser a spectator at the back of the line
=======================
*/
void RemoveTournamentLoser( void ) {
	int			clientNum;

	if ( level.numPlayingClients != 2 ) {
		return;
	}

	clientNum = level.sortedClients[1];

	if ( level.clients[ clientNum ].pers.connected != CON_CONNECTED ) {
		return;
	}

	// make them a spectator
	SetTeam( &g_entities[ clientNum ], "s" );
}

void G_PowerDuelCount(int *loners, int *doubles, qboolean countSpec)
{
	int i = 0;
	gclient_t *cl;

	while (i < MAX_CLIENTS)
	{
		cl = g_entities[i].client;

		if (g_entities[i].inuse && cl && 
			(countSpec || cl->sess.sessionTeam != TEAM_SPECTATOR))
		{
			if (cl->sess.duelTeam == DUELTEAM_LONE)
			{
				(*loners)++;
			}
			else if (cl->sess.duelTeam == DUELTEAM_DOUBLE)
			{
				(*doubles)++;
			}
		}
		i++;
	}
}

qboolean g_duelAssigning = qfalse;
void AddPowerDuelPlayers( void )
{
	int			i;
	int			loners = 0;
	int			doubles = 0;
	int			nonspecLoners = 0;
	int			nonspecDoubles = 0;
	gclient_t	*client;
	gclient_t	*nextInLine;
	int foo, hours, mins, secs;

	if ( level.numPlayingClients >= 3)///3 )
	{
		return;
	}

	nextInLine = NULL;

	G_PowerDuelCount(&nonspecLoners, &nonspecDoubles, qfalse);
	if (nonspecLoners >= 1 && nonspecDoubles >= 2)//2
	{ //we have enough people, stop
		return;
	}

	//Could be written faster, but it's not enough to care I suppose.
	G_PowerDuelCount(&loners, &doubles, qtrue);

	if (loners < 1 || doubles < 2)//2
	{ //don't bother trying to spawn anyone yet if the balance is not even set up between spectators
		return;
	}

	//Count again, with only in-game clients in mind.
	loners = nonspecLoners;
	doubles = nonspecDoubles;
//	G_PowerDuelCount(&loners, &doubles, qfalse);

	for ( i = 0 ; i < level.maxclients ; i++ ) {
		client = &level.clients[i];
		////client->sess.admin_number = -1;

		if ( client->pers.connected != CON_CONNECTED ) {
			continue;
		}
		if ( client->sess.sessionTeam != TEAM_SPECTATOR ) {
			continue;
		}
		if (client->sess.duelTeam == DUELTEAM_FREE)
		{
			continue;
		}
		if (client->sess.duelTeam == DUELTEAM_LONE && loners >= 1)
		{
			continue;
		}
		if (client->sess.duelTeam == DUELTEAM_DOUBLE && doubles >= 2)
		{
			continue;
		}

		// never select the dedicated follow or scoreboard clients
		if ( client->sess.spectatorState == SPECTATOR_SCOREBOARD || 
			client->sess.spectatorClient < 0  ) {
			continue;
		}

		if ( !nextInLine 
			|| client->sess.spectatorTime < nextInLine->sess.spectatorTime 
			) {
			
				if (!nextInLine){
					foo = 1;
				}else{
					foo = 0;
				}

			nextInLine = client;

	}
	}
	if ( !nextInLine ) {
		return;
	}

	level.warmupTime = -1;

/*
	if (foo == 0 && nextInLine->sess.selectedFP == 0){
		hours = (int)(nextInLine->sess.spectatorTime/3600000);
		mins = (int)((nextInLine->sess.spectatorTime - (hours * 3600000))/60000);
		secs = (int)((nextInLine->sess.spectatorTime - (hours * 3600000) - (mins * 60000))/1000);


		trap_SendServerCommand( -1, va("print \"%s ^2joined the fracas (spec time %i:%i:%i)\n\"", 
		nextInLine->pers.netname,
		hours,
		mins,
		secs));
	}
*/


	// set them to free-for-all team
	SetTeam( &g_entities[ nextInLine - level.clients ], "f" );

	//Call recursively until everyone is in
	AddPowerDuelPlayers();
}

qboolean g_dontFrickinCheck = qfalse;

void RemovePowerDuelLosers(void)
{
	int remClients[3];
	int remNum = 0;
	int i = 0;
	gclient_t *cl;

	while (i < MAX_CLIENTS && remNum < 3)
	{
		//cl = &level.clients[level.sortedClients[i]];
		cl = &level.clients[i];

		if (cl->pers.connected == CON_CONNECTED)
		{
			//cl->ps.eFlags & EF_DEAD ||
			if (( cl->ps.stats[STAT_HEALTH] <= 0 || cl->iAmALoser) &&
				(cl->sess.sessionTeam != TEAM_SPECTATOR || cl->iAmALoser))
			{ //he was dead or he was spectating as a loser

				time_t ltime;
				time( &ltime );                 /* Get time in seconds */

                remClients[remNum] = cl->ps.clientNum;

				///unwoot skipzor spam
				/*trap_SendServerCommand( -1, va("print \"^7%s^7 removed, no.skipzor.ID %i, health=%i, loser=%i, spectime=%i\n\"",
				g_entities[ remClients[remNum] ].client->pers.netname,
				ltime,
				g_entities[ remClients[remNum] ].client->ps.stats[STAT_HEALTH],
				g_entities[ remClients[remNum] ].client->iAmALoser,
				///g_entities[ remClients[remNum] ].client->ps.eFlags & EF_DEAD,
				g_entities[ remClients[remNum] ].client->sess.spectatorTime/1000
				));*/

				remNum++;
			}
		}

		i++;
	}

	if (!remNum)
	{ //Time ran out or something? Oh well, just remove the main guy.
	  ///nooooo!
		remClients[remNum] = level.sortedClients[0];
		remNum++;
		///trap_SendServerCommand( -1, va("print \"anti-Skipz0r hack!\n\""));
		///return;
		
	}

	if (remNum > 3){
		remNum = 3;
	}	

	i = 0;
	while (i < remNum && remNum < 1024)
	{ //set them all to spectator
		SetTeam( &g_entities[ remClients[i] ], "s" );
		i++;
	}

	g_dontFrickinCheck = qfalse;

	//recalculate stuff now that we have reset teams.
	CalculateRanks();
}

void RemoveDuelDrawLoser(void)
{
	int clFirst = 0;
	int clSec = 0;
	int clFailure = 0;

	if ( level.clients[ level.sortedClients[0] ].pers.connected != CON_CONNECTED )
	{
		///return;
	}
	if ( level.clients[ level.sortedClients[1] ].pers.connected != CON_CONNECTED )
	{
		///return;
	}

	clFirst = level.clients[ level.sortedClients[0] ].ps.stats[STAT_HEALTH] + level.clients[ level.sortedClients[0] ].ps.stats[STAT_ARMOR];
	clSec = level.clients[ level.sortedClients[1] ].ps.stats[STAT_HEALTH] + level.clients[ level.sortedClients[1] ].ps.stats[STAT_ARMOR];

	if (clFirst > clSec)
	{
		clFailure = 1;
	}
	else if (clSec > clFirst)
	{
		clFailure = 0;
	}
	else
	{
		clFailure = 2;
	}

	if (clFailure != 2)
	{
		SetTeam( &g_entities[ level.sortedClients[clFailure] ], "s" );
	}
	else
	{ //we could be more elegant about this, but oh well.
		SetTeam( &g_entities[ level.sortedClients[1] ], "s" );
	}
}

/*
=======================
RemoveTournamentWinner
=======================
*/
void RemoveTournamentWinner( void ) {
	int			clientNum;

	if ( level.numPlayingClients != 2 ) {
		return;
	}

	clientNum = level.sortedClients[0];

	if ( level.clients[ clientNum ].pers.connected != CON_CONNECTED ) {
		return;
	}

	// make them a spectator
	SetTeam( &g_entities[ clientNum ], "s" );
}

/*
=======================
AdjustTournamentScores
=======================
*/
extern void RoundXP(int clientNum, qboolean isWinner, int lastOne); //g_saga.c
void AdjustTournamentScores( void ) {
	int			clientNum;


		int clFailure = 0;
		int clSuccess = 0;
		int clFirst = level.clients[ level.sortedClients[0] ].ps.stats[STAT_HEALTH] + level.clients[ level.sortedClients[0] ].ps.stats[STAT_ARMOR];
		int clSec = level.clients[ level.sortedClients[1] ].ps.stats[STAT_HEALTH] + level.clients[ level.sortedClients[1] ].ps.stats[STAT_ARMOR];


		if (clFirst > clSec)
		{
				RoundXP(level.sortedClients[0], qtrue, 1);
				RoundXP(level.sortedClients[1], qfalse, 1);
				clientNum = level.sortedClients[0];
				trap_SetConfigstring ( CS_CLIENT_DUELWINNER, va("%i", clientNum ) );
				ClientUserinfoChanged( clientNum );

				clientNum = level.sortedClients[1];
				level.clients[ clientNum ].sess.losses++;
				ClientUserinfoChanged( clientNum );
		}
		else if (clSec > clFirst)
		{

				RoundXP(level.sortedClients[0], qfalse, 1);
				RoundXP(level.sortedClients[1], qtrue, 1);
				clientNum = level.sortedClients[1];
				trap_SetConfigstring ( CS_CLIENT_DUELWINNER, va("%i", clientNum ) );
				ClientUserinfoChanged( clientNum );

				clientNum = level.sortedClients[0];
				level.clients[ clientNum ].sess.losses++;
				ClientUserinfoChanged( clientNum );
		}
		else
		{
				RoundXP(level.sortedClients[0], qtrue, 1);
				RoundXP(level.sortedClients[1], qtrue, 1);
				//trap_SetConfigstring ( CS_CLIENT_DUELWINNER, va("%i", clientNum ) );
		}


}

/*
=============
SortRanks

=============
*/
int QDECL SortRanks( const void *a, const void *b ) {
	gclient_t	*ca, *cb;

	ca = &level.clients[*(int *)a];
	cb = &level.clients[*(int *)b];

	if (g_gametype.integer == GT_POWERDUEL)
	{
		//sort single duelists first
		if (ca->sess.duelTeam == DUELTEAM_LONE && ca->sess.sessionTeam != TEAM_SPECTATOR)
		{
			return -1;
		}
		if (cb->sess.duelTeam == DUELTEAM_LONE && cb->sess.sessionTeam != TEAM_SPECTATOR)
		{
			return 1;
		}

		//others will be auto-sorted below but above spectators.
	}

	// sort special clients last
	if ( ca->sess.spectatorState == SPECTATOR_SCOREBOARD || ca->sess.spectatorClient < 0 ) {
		return 1;
	}
	if ( cb->sess.spectatorState == SPECTATOR_SCOREBOARD || cb->sess.spectatorClient < 0  ) {
		return -1;
	}


	///unwoot???
	/*
	// then connecting clients
	if ( ca->pers.connected == CON_CONNECTING ) {
		return 1;
	}
	if ( cb->pers.connected == CON_CONNECTING ) {
		return -1;
	}
	*/

	// then spectators
	if ( ca->sess.sessionTeam == TEAM_SPECTATOR && cb->sess.sessionTeam == TEAM_SPECTATOR ) {
		if ( ca->sess.spectatorTime < cb->sess.spectatorTime ) {
			return -1;
		}
		if ( ca->sess.spectatorTime > cb->sess.spectatorTime ) {
			return 1;
		}
		return 0;
	}
	if ( ca->sess.sessionTeam == TEAM_SPECTATOR ) {
		return 1;
	}
	if ( cb->sess.sessionTeam == TEAM_SPECTATOR ) {
		return -1;
	}

	// then sort by score
	if ( ca->ps.persistant[PERS_SCORE]
		> cb->ps.persistant[PERS_SCORE] ) {
		return -1;
	}
	if ( ca->ps.persistant[PERS_SCORE]
		< cb->ps.persistant[PERS_SCORE] ) {
		return 1;
	}
	return 0;
}

qboolean gQueueScoreMessage = qfalse;
int gQueueScoreMessageTime = 0;

//A new duel started so respawn everyone and make sure their stats are reset
qboolean G_CanResetDuelists(void)
{
	int i;
	gentity_t *ent;

	i = 0;
	while (i < 3)
	{ //precheck to make sure they are all respawnable
		ent = &g_entities[level.sortedClients[i]];

		if (!ent->inuse || !ent->client || ent->health <= 0 ||
			ent->client->sess.sessionTeam == TEAM_SPECTATOR ||
			ent->client->sess.duelTeam <= DUELTEAM_FREE)
		{
			return qfalse;
		}
		i++;
	}

	return qtrue;
}

qboolean g_noPDuelCheck = qfalse;
void G_ResetDuelists(void)
{
	int i;
	gentity_t *ent;
	gentity_t *tent;

	i = 0;
	while (i < 3)
	{
		ent = &g_entities[level.sortedClients[i]];

		g_noPDuelCheck = qtrue;
		player_die(ent, ent, ent, 999, MOD_SUICIDE);
		g_noPDuelCheck = qfalse;
		trap_UnlinkEntity (ent);
		ClientSpawn(ent);

		// add a teleportation effect
//		tent = G_TempEntity( ent->client->ps.origin, EV_PLAYER_TELEPORT_IN );
		////tent = G_TempEntity( ent->client->ps.origin, EV_PLAYER_TELEPORT_OUT );	

		tent = G_TempEntity( ent->client->ps.origin, EV_DETECTED1 + Q_irand(0,4) );		
				
		tent->s.clientNum = ent->s.clientNum;
		i++;
	}
}

/*
============
CalculateRanks

Recalculates the score ranks of all players
This will be called on every client connect, begin, disconnect, death,
and team change.
============
*/
void CalculateRanks( void ) {
	int		i;
	int		rank;
	int		score;
	int		newScore;
	int		preNumSpec = 0;
	//int		nonSpecIndex = -1;
	gclient_t	*cl;

	preNumSpec = level.numNonSpectatorClients;

	level.follow1 = -1;
	level.follow2 = -1;
	level.numConnectedClients = 0;
	level.numNonSpectatorClients = 0;
	level.numPlayingClients = 0;
	level.numVotingClients = 0;		// don't count bots
	for ( i = 0; i < TEAM_NUM_TEAMS; i++ ) {
		level.numteamVotingClients[i] = 0;
	}
	for ( i = 0 ; i < level.maxclients ; i++ ) {
		if ( level.clients[i].pers.connected != CON_DISCONNECTED ) {
			level.sortedClients[level.numConnectedClients] = i;
			level.numConnectedClients++;

			if ( level.clients[i].sess.sessionTeam != TEAM_SPECTATOR || g_gametype.integer == GT_DUEL || g_gametype.integer == GT_POWERDUEL )
			{
				if (level.clients[i].sess.sessionTeam != TEAM_SPECTATOR)
				{
					level.numNonSpectatorClients++;
					//nonSpecIndex = i;
				}
			
				// decide if this should be auto-followed
				if ( level.clients[i].pers.connected == CON_CONNECTED )
				{
					if (level.clients[i].sess.sessionTeam != TEAM_SPECTATOR || level.clients[i].iAmALoser)
					{
						level.numPlayingClients++;
					}
					if ( !(g_entities[i].r.svFlags & SVF_BOT) )
					{
						level.numVotingClients++;
						if ( level.clients[i].sess.sessionTeam == TEAM_RED )
							level.numteamVotingClients[0]++;
						else if ( level.clients[i].sess.sessionTeam == TEAM_BLUE )
							level.numteamVotingClients[1]++;
					}
					if ( level.follow1 == -1 ) {
						level.follow1 = i;
					} else if ( level.follow2 == -1 ) {
						level.follow2 = i;
					}
				}
			}
		}
	}

	//if (!g_warmup.integer)
	if (1)
	{
		level.warmupTime = 0;
	}

	/*
	if (level.numNonSpectatorClients == 2 && preNumSpec < 2 && nonSpecIndex != -1 && g_gametype.integer == GT_DUEL && !level.warmupTime)
	{
		gentity_t *currentWinner = G_GetDuelWinner(&level.clients[nonSpecIndex]);

		if (currentWinner && currentWinner->client)
		{
			trap_SendServerCommand( -1, va("cp \"%s" S_COLOR_WHITE " %s %s\n\"",
			currentWinner->client->pers.netname, G_GetStringEdString("MP_SVGAME", "VERSUS"), level.clients[nonSpecIndex].pers.netname));
		}
	}*/
	//NOTE: for now not doing this either. May use later if appropriate.

	qsort( level.sortedClients, level.numConnectedClients, 	sizeof(level.sortedClients[0]), SortRanks );


	// set the rank value for all clients that are connected and not spectators
	if ( g_gametype.integer >= GT_TEAM ) {
		// in team games, rank is just the order of the teams, 0=red, 1=blue, 2=tied
		for ( i = 0;  i < level.numConnectedClients; i++ ) {
			cl = &level.clients[ level.sortedClients[i] ];
			if ( level.teamScores[TEAM_RED] == level.teamScores[TEAM_BLUE] ) {
				cl->ps.persistant[PERS_RANK] = 2;
			} else if ( level.teamScores[TEAM_RED] > level.teamScores[TEAM_BLUE] ) {
				cl->ps.persistant[PERS_RANK] = 0;
			} else {
				cl->ps.persistant[PERS_RANK] = 1;
			}
		}
	} else {	
		rank = -1;
		score = 0;
		for ( i = 0;  i < level.numPlayingClients; i++ ) {
			cl = &level.clients[ level.sortedClients[i] ];
			newScore = cl->ps.persistant[PERS_SCORE];
			if ( i == 0 || newScore != score ) {
				rank = i;
				// assume we aren't tied until the next client is checked
				level.clients[ level.sortedClients[i] ].ps.persistant[PERS_RANK] = rank;
			} else {
				// we are tied with the previous client
				level.clients[ level.sortedClients[i-1] ].ps.persistant[PERS_RANK] = rank | RANK_TIED_FLAG;
				level.clients[ level.sortedClients[i] ].ps.persistant[PERS_RANK] = rank | RANK_TIED_FLAG;
			}
			score = newScore;
			if ( g_gametype.integer == GT_SINGLE_PLAYER && level.numPlayingClients == 1 ) {
				level.clients[ level.sortedClients[i] ].ps.persistant[PERS_RANK] = rank | RANK_TIED_FLAG;
			}
		}
	}

	// set the CS_SCORES1/2 configstrings, which will be visible to everyone
	if ( g_gametype.integer >= GT_TEAM ) {
		trap_SetConfigstring( CS_SCORES1, va("%i", level.teamScores[TEAM_RED] ) );
		trap_SetConfigstring( CS_SCORES2, va("%i", level.teamScores[TEAM_BLUE] ) );
	} else {
		if ( level.numConnectedClients == 0 ) {
			trap_SetConfigstring( CS_SCORES1, va("%i", SCORE_NOT_PRESENT) );
			trap_SetConfigstring( CS_SCORES2, va("%i", SCORE_NOT_PRESENT) );
		} else if ( level.numConnectedClients == 1 ) {
			trap_SetConfigstring( CS_SCORES1, va("%i", level.clients[ level.sortedClients[0] ].ps.persistant[PERS_SCORE] ) );
			trap_SetConfigstring( CS_SCORES2, va("%i", SCORE_NOT_PRESENT) );
		} else {
			trap_SetConfigstring( CS_SCORES1, va("%i", level.clients[ level.sortedClients[0] ].ps.persistant[PERS_SCORE] ) );
			trap_SetConfigstring( CS_SCORES2, va("%i", level.clients[ level.sortedClients[1] ].ps.persistant[PERS_SCORE] ) );
		}

		if (g_gametype.integer != GT_DUEL || g_gametype.integer != GT_POWERDUEL)
		{ //when not in duel, use this configstring to pass the index of the player currently in first place
			if ( level.numConnectedClients >= 1 )
			{
				trap_SetConfigstring ( CS_CLIENT_DUELWINNER, va("%i", level.sortedClients[0] ) );
			}
			else
			{
				trap_SetConfigstring ( CS_CLIENT_DUELWINNER, "-1" );
			}
		}
	}

	// see if it is time to end the level
	CheckExitRules();

	// if we are at the intermission or in multi-frag Duel game mode, send the new info to everyone
	if ( level.intermissiontime || g_gametype.integer == GT_DUEL || g_gametype.integer == GT_POWERDUEL ) {
		gQueueScoreMessage = qtrue;
		gQueueScoreMessageTime = level.time + 1200;
		//SendScoreboardMessageToAllClients();
		//rww - Made this operate on a "queue" system because it was causing large overflows
	}
}


/*
========================================================================

MAP CHANGING

========================================================================
*/

/*
========================
SendScoreboardMessageToAllClients

Do this at BeginIntermission time and whenever ranks are recalculated
due to enters/exits/forced team changes
========================
*/
void SendScoreboardMessageToAllClients( void ) {
	int		i;

	for ( i = 0 ; i < level.maxclients ; i++ ) {
		if ( level.clients[ i ].pers.connected == CON_CONNECTED ) {
			DeathmatchScoreboardMessage( g_entities + i );
		}
	}
}

/*
========================
MoveClientToIntermission

When the intermission starts, this will be called for all players.
If a new client connects, this will be called after the spawn function.
========================
*/
void MoveClientToIntermission( gentity_t *ent ) {
	// take out of follow mode if needed
	if ( ent->client->sess.spectatorState == SPECTATOR_FOLLOW ) {
		StopFollowing( ent );
	}


	// move to the spot
	VectorCopy( level.intermission_origin, ent->s.origin );
	VectorCopy( level.intermission_origin, ent->client->ps.origin );
	VectorCopy (level.intermission_angle, ent->client->ps.viewangles);
	ent->client->ps.pm_type = PM_INTERMISSION;

	// clean up powerup info
	memset( ent->client->ps.powerups, 0, sizeof(ent->client->ps.powerups) );

	ent->client->ps.eFlags = 0;
	ent->s.eFlags = 0;
	ent->s.eType = ET_GENERAL;
	ent->s.modelindex = 0;
	ent->s.loopSound = 0;
	ent->s.loopIsSoundset = qfalse;
	ent->s.event = 0;
	ent->r.contents = 0;
}

/*
==================
FindIntermissionPoint

This is also used for spectator spawns
==================
*/
extern qboolean	gSiegeRoundBegun;
extern qboolean	gSiegeRoundEnded;
extern qboolean	gSiegeRoundWinningTeam;
void FindIntermissionPoint( void ) {
	gentity_t	*ent = NULL;
	gentity_t	*target;
	vec3_t		dir;

	// find the intermission spot
	if ( g_gametype.integer == GT_SIEGE
		&& level.intermissiontime
		&& level.intermissiontime <= level.time
		&& gSiegeRoundEnded )
	{
	   	if (gSiegeRoundWinningTeam == SIEGETEAM_TEAM1)
		{
			ent = G_Find (NULL, FOFS(classname), "info_player_intermission_red");
			if ( ent && ent->target2 ) 
			{
				G_UseTargets2( ent, ent, ent->target2 );
			}
		}
	   	else if (gSiegeRoundWinningTeam == SIEGETEAM_TEAM2)
		{
			ent = G_Find (NULL, FOFS(classname), "info_player_intermission_blue");
			if ( ent && ent->target2 ) 
			{
				G_UseTargets2( ent, ent, ent->target2 );
			}
		}
	}
	if ( !ent )
	{
		ent = G_Find (NULL, FOFS(classname), "info_player_intermission");
	}
	if ( !ent ) {	// the map creator forgot to put in an intermission point...
		SelectSpawnPoint ( vec3_origin, level.intermission_origin, level.intermission_angle, TEAM_SPECTATOR );
	} else {
		VectorCopy (ent->s.origin, level.intermission_origin);
		VectorCopy (ent->s.angles, level.intermission_angle);
		// if it has a target, look towards it
		if ( ent->target ) {
			target = G_PickTarget( ent->target );
			if ( target ) {
				VectorSubtract( target->s.origin, level.intermission_origin, dir );
				vectoangles( dir, level.intermission_angle );
			}
		}
	}

}

void LoseKarma(int clientNum, char reason[64], int quantity){
		gentity_t *perp;
		int desc;
		char		userinfo[MAX_INFO_STRING];
		perp = &g_entities[clientNum];
		
		desc = quantity;
		if (desc < 0){
			desc = -1*desc;
		}

	if (perp->client && perp->client->pers.connected == CON_CONNECTED
		&& !perp->NPC_type){

		perp->client->ps.userInt3++;
		
		//if (Q_stricmp(perp->client->sess.admin_name, "sub")==0){
		//	perp->client->sess.karma -= quantity;
		//	WriteKeys(clientNum,0,qtrue);
		//}

		if (quantity < 0 && perp->client->ps.userInt3 <= 16){
			trap_SendServerCommand( clientNum, va("print \"%s^4 gained %i karma! (%i) ^7%s\n\"",
			perp->client->pers.netname, desc, perp->client->sess.karma, reason) );
			perp->client->sess.karma -= quantity;
			WriteKeys(clientNum,0,qtrue);

		}else if (quantity > 0 && perp->client->ps.userInt3 <= 15){
			
			//if (Q_stricmp(perp->client->sess.admin_name, "sub")!=0){
				perp->client->sess.karma -= quantity;
				WriteKeys(clientNum,0,qtrue);
			//}

			trap_SendServerCommand( clientNum, va("print \"%s^6 lost %i karma. (%i) ^1%s\n\"",
			perp->client->pers.netname, desc, perp->client->sess.karma, reason) );
			
		}
	}
	
}

qboolean DuelLimitHit(void);
extern int GetLevel(gclient_t *cl);
void RoundXP(int clientNum, qboolean isWinner, int lastOne){

int xp, xpgain, xploss, diff, oldwins, newwins;
char plural[64];
int thisclient, xpenemy, xpenemy2;

	///char *fileString;
	////char *currentVar;


	int len;
	int i, i_cv;
	int nei_num;

	i = 0;
	i_cv = 0;

		if (level.clients[ clientNum ].sess.losses >= 0 && isWinner){
			level.clients[ clientNum ].sess.losses++;
		}else if (level.clients[ clientNum ].sess.losses < 0 && isWinner){
			level.clients[ clientNum ].sess.losses = 1;
		}else if (level.clients[ clientNum ].sess.losses > 0 && !isWinner){
			level.clients[ clientNum ].sess.losses = -1;
		}else if (level.clients[ clientNum ].sess.losses <= 0 && !isWinner){
			level.clients[ clientNum ].sess.losses--;
		}

	if (isWinner && level.clients[ clientNum ].sess.sessionTeam != TEAM_SPECTATOR
		&& level.clients[ clientNum ].pers.connected == CON_CONNECTED ){
		///level.clients[ clientNum ].sess.karma+= (1 + Q_irand(0,1)) ;
		if (Q_irand(0,3) == 2){
			LoseKarma(clientNum, "Survival.", -2);
		}
	}

	if (clientNum == level.sortedClients[0]){
			xp = level.clients[ clientNum ].sess.xp;
			thisclient = level.sortedClients[1];
			xpenemy = level.clients[ thisclient ].sess.xp;
			thisclient = level.sortedClients[lastOne];
			xpenemy2 = level.clients[ thisclient ].sess.xp;
			if (xpenemy <= 0){
				xpenemy = 1;
			}
			if (xpenemy2 <= 0){
				xpenemy2 = 1;
			}
			xpgain = (int)((((xpenemy +xpenemy2)/2.0f)- xp)*0.05f);
			if (xpgain < 100){
				xpgain = 100;
			}
			///xploss = (xpgain/3.5f)+Q_irand(0,3);
			xploss = (int)(((xp - ((xpenemy +xpenemy2)/2.0f))*0.03f));////3.0f);
			if (xploss < 50){
				xploss = 50;
			}
	}else{
		xp = level.clients[ clientNum ].sess.xp;
		thisclient = level.sortedClients[0];
		xpenemy = level.clients[ thisclient ].sess.xp;
		if (xpenemy <= 0){
			xpenemy = 1;
		}
		xpgain = (int)((xpenemy - xp) *0.05f);
		if (xpgain < 100){
			xpgain = 100;//was 10 10
		}

		xploss = (int)((xp - xpenemy) *0.03f);////3.0f);
		///xploss = (xpgain/3.5f)+Q_irand(0,3);
		if (xploss < 50){
			xploss = 50;//was 3 3
		}
	}

	if ((level.clients[ clientNum ].iAmALoser 
		|| level.clients[ clientNum ].ps.stats[STAT_HEALTH]<=0
		)&& 
			(level.clients[ clientNum ].iAmALoser 
			|| level.clients[ clientNum ].sess.sessionTeam != TEAM_SPECTATOR
			) && xpgain > 0
		){
			xpgain *= 0.40f;
		}

	/*if (g_logstats.integer >= 1){
		fileHandle_t f;
		char *foo;
		char *routePath;
		///wpobject_t thiswp;

		routePath = (char *)B_TempAlloc(1040);
		Com_sprintf(routePath, 1040, "%s\0", "stats.log");
		len = trap_FS_FOpenFile(routePath, &f, FS_APPEND);
		B_TempFree(1040); //routePath
	
		foo = va("%s&%i&%i&%i&%i&%i&%i&%s\n",
		
		level.clients[ clientNum ].pers.netname, 
		level.clients[ clientNum ].sess.xp, 
		level.clients[ clientNum ].sess.wins, 
		level.clients[ clientNum ].sess.str, 
		level.clients[ clientNum ].sess.dex, 
		level.clients[ clientNum ].sess.con, 
		level.clients[ clientNum ].sess.admin_number,
		level.clients[ clientNum ].sess.admin_name
		
		);
		trap_FS_Write( foo, strlen(foo), f );
		trap_FS_FCloseFile(f);
}
*/

	if (isWinner){
		
		if ( level.clients[ clientNum ].pers.connected == CON_CONNECTED ) {


			if (level.clients[ clientNum ].sess.sessionTeam != TEAM_SPECTATOR){
			trap_SetConfigstring ( CS_CLIENT_DUELWINNER, va("%i", clientNum ) );
			ClientUserinfoChanged( clientNum );
			}

			/*if (Q_irand(0,3) == 1){
				level.clients[ clientNum ].sess.str++;
			}
			if (Q_irand(0,4) == 1){
				level.clients[ clientNum ].sess.dex++;
			}	
			if (Q_irand(0,5) == 1){
				level.clients[ clientNum ].sess.con++;
			}*///unwoot?

			/*if (level.clients[ clientNum ].sess.sessionTeam != TEAM_SPECTATOR && Q_irand(0,9) == 1 && Q_irand(0,15) <= level.clients[ clientNum ].sess.karma){
				level.clients[ clientNum ].sess.str++;
			}
			if (level.clients[ clientNum ].sess.sessionTeam != TEAM_SPECTATOR && Q_irand(0,8) == 1 && Q_irand(0,25) <= level.clients[ clientNum ].sess.karma){
				level.clients[ clientNum ].sess.dex++;
			}	
			if (level.clients[ clientNum ].sess.sessionTeam != TEAM_SPECTATOR && Q_irand(0,10) == 1 && Q_irand(0,35) <= level.clients[ clientNum ].sess.karma){
				level.clients[ clientNum ].sess.con++;
			}*/


			if (level.clients[ clientNum ].sess.karma <= -1024){	
				xpgain *= 0.75f;
			}else if (level.clients[ clientNum ].sess.karma <= -512){	
				xpgain *= 0.80f;
			}else if (level.clients[ clientNum ].sess.karma <= -128){	
				xpgain *= 0.85f;
			}else if (level.clients[ clientNum ].sess.karma <= -64){
				xpgain *= 0.80f;
			}else if (level.clients[ clientNum ].sess.karma <= -16){
				xpgain *= 0.90f;
			}else if (level.clients[ clientNum ].sess.karma >= 16){
				xpgain *= 1.04f;
			}else if (level.clients[ clientNum ].sess.karma >= 64){
				xpgain *= 1.12f;
			}else if (level.clients[ clientNum ].sess.karma >= 128){
				xpgain *= 1.18f;
			}else if (level.clients[ clientNum ].sess.karma >= 256){
				xpgain *= 1.24f;
			}else if (level.clients[ clientNum ].sess.karma >= 512){
				xpgain *= 1.32f;
			}

			////oldwins = level.clients[ clientNum ].sess.wins;
			oldwins = GetLevel(&level.clients[ clientNum ]);
			level.clients[ clientNum ].sess.xp += xpgain;
			WriteKeys(clientNum,6,qtrue);
			newwins = GetLevel(&level.clients[ clientNum ]);//level.clients[ clientNum ].sess.xp;
			diff = newwins - oldwins;

			if (diff != 1){
				strcpy(plural,"s ");
			}else{
				strcpy(plural," ");
			}
			if (diff < 0){
				diff = 0;
				newwins = oldwins;
			}

			if ((level.clients[ clientNum ].iAmALoser 
				|| level.clients[ clientNum ].ps.stats[STAT_HEALTH]<=0
				)&& 
					(level.clients[ clientNum ].iAmALoser 
					|| level.clients[ clientNum ].sess.sessionTeam != TEAM_SPECTATOR
					)
				){
				if (level.clients[ clientNum ].iAmALoser){
					trap_SendServerCommand(-1, va("print \"^4(-1 hp)^7 %s^7> ^4Level +%i>>^3%i ^7(+%i>>%i XP^7) ^3+$%i>>^7$%i\n\"",  level.clients[ clientNum ].pers.netname, diff, newwins, (int)(xpgain), level.clients[ clientNum ].sess.xp, (int)(xpgain*0.42f), ((int)(xpgain*0.42f)+level.clients[ clientNum ].sess.admin_number) ) );
				}else{
					trap_SendServerCommand(-1, va("print \"^4(%i hp)^7 %s^7> ^4Level +%i>>^3%i ^7(+%i>>%i XP^7) ^3+$%i>>^7$%i\n\"",  level.clients[ clientNum ].ps.stats[STAT_HEALTH], level.clients[ clientNum ].pers.netname, diff, newwins, (int)(xpgain), level.clients[ clientNum ].sess.xp, (int)(xpgain*0.42f), ((int)(xpgain*0.42f)+level.clients[ clientNum ].sess.admin_number)) );
				}
				

			}else if ( level.clients[ clientNum ].sess.sessionTeam == TEAM_SPECTATOR){
				//shouldn't be getting credit
				level.clients[ clientNum ].sess.xp -= xpgain;
				WriteKeys(clientNum,6,qtrue);
				return;
			}else{
					trap_SendServerCommand(-1, va("print \"^4(%i hp)^7 %s^7> ^4Level +%i>>^3%i ^7(+%i>>%i XP^7) ^3+$%i>>^7$%i\n\"",  level.clients[ clientNum ].ps.stats[STAT_HEALTH], level.clients[ clientNum ].pers.netname, diff, newwins, (int)(xpgain), level.clients[ clientNum ].sess.xp, (int)(xpgain*0.42f), ((int)(xpgain*0.42f)+level.clients[ clientNum ].sess.admin_number)) );
			}

			level.clients[ clientNum ].sess.wins = newwins;
			level.clients[ clientNum ].sess.admin_number += (int)(xpgain*0.42f);
			WriteKeys(clientNum,4,qtrue);
			WriteKeys(clientNum,5,qtrue);
			///WriteKeys(clientNum,6,qtrue);
		}
	
	}else{
		if ( level.clients[ clientNum ].pers.connected == CON_CONNECTED ) {
			

			/*if (Q_irand(0,4) == 1){
			level.clients[ clientNum ].sess.con--;
			}
			if (Q_irand(0,5) == 1){
				level.clients[ clientNum ].sess.str--;
			}
			if (Q_irand(0,6) == 1){
				level.clients[ clientNum ].sess.dex--;
			}*///unwoot?

			if (level.clients[ clientNum ].sess.sessionTeam != TEAM_SPECTATOR 
				&& Q_irand(0,35) == 1 && Q_irand(5,10) <= level.clients[ clientNum ].sess.karma){
				level.clients[ clientNum ].sess.str--;
				WriteKeys(clientNum,1,qtrue);
			}
			if (level.clients[ clientNum ].sess.sessionTeam != TEAM_SPECTATOR 
				&& Q_irand(0,36) == 1 && Q_irand(5,20) <= level.clients[ clientNum ].sess.karma){
				level.clients[ clientNum ].sess.dex--;
				WriteKeys(clientNum,2,qtrue);
			}	
			if (level.clients[ clientNum ].sess.sessionTeam != TEAM_SPECTATOR 
				&& Q_irand(0,37) == 1 && Q_irand(5,30) <= level.clients[ clientNum ].sess.karma){
				level.clients[ clientNum ].sess.con--;
				WriteKeys(clientNum,3,qtrue);
			}

			if (level.clients[ clientNum ].sess.karma <= -128){	
				xploss *= 0.85f;
			}else if (level.clients[ clientNum ].sess.karma <= -64){
				xploss *= 0.80f;
			}else if (level.clients[ clientNum ].sess.karma <= -16){
				xploss *= 0.95f;
			}else if (level.clients[ clientNum ].sess.karma >= 16){
				xploss *= 1.04f;
			}else if (level.clients[ clientNum ].sess.karma >= 64){
				xploss *= 1.10f;
			}else if (level.clients[ clientNum ].sess.karma >= 128){
				xploss *= 1.16f;
			}

			/////oldwins = level.clients[ clientNum ].sess.wins;
			oldwins = GetLevel(&level.clients[ clientNum ]);
			if (level.clients[ clientNum ].sess.xp > -500){
				level.clients[ clientNum ].sess.xp -= xploss;
				///WriteKeys(clientNum,4,qtrue);
					///WriteKeys(clientNum,5,qtrue);
					WriteKeys(clientNum,6,qtrue);
			}else{
				xploss = 0;
			}
			newwins = GetLevel(&level.clients[ clientNum ]);//level.clients[ clientNum ].sess.xp;
			diff = oldwins - newwins;

			if (diff != 1){
				strcpy(plural,"s ");
			}else{
				strcpy(plural," ");
			}
			if (diff < 0){
				diff = 0;
				newwins = oldwins;
			}



			if (
				( level.clients[ clientNum ].iAmALoser 
				|| level.clients[ clientNum ].ps.stats[STAT_HEALTH]<= 0)
					&& (level.clients[ clientNum ].iAmALoser 
					 ||level.clients[ clientNum].sess.sessionTeam != TEAM_SPECTATOR
					)
			)
			{
				if (level.clients[ clientNum ].iAmALoser){
					trap_SendServerCommand(-1, va("print \"^1(-1 hp)^7 %s^7> ^4Level -%i>>^1%i ^7(-%i>>%i XP^7) ^1-$%i>>^7$%i\n\"", level.clients[ clientNum ].pers.netname,diff, newwins, xploss, level.clients[ clientNum ].sess.xp, (int)(xploss / (3.14f*2)), (level.clients[ clientNum ].sess.admin_number - (int)(xploss/(3.14f*2)))) );
				}else{
					trap_SendServerCommand(-1, va("print \"^1(%i hp)^7 %s^7> ^4Level -%i>>^1%i ^7(-%i>>%i XP^7) ^1-$%i>>^7$%i\n\"", level.clients[ clientNum ].ps.stats[STAT_HEALTH], level.clients[ clientNum ].pers.netname, diff, newwins, xploss, level.clients[ clientNum ].sess.xp, (int)(xploss /(3.14f*2)), (level.clients[ clientNum ].sess.admin_number- (int)(xploss/(3.14f*2)))) );
					/////trap_SendServerCommand(-1, va("print \"^4(%i hp)^7 %s^7> ^3+%i ^4level%s^7 (^3+%i^5 XP^7) ^3$%i\n\"",  level.clients[ clientNum ].ps.stats[STAT_HEALTH], level.clients[ clientNum ].pers.netname, diff, plural, (int)(xpgain), (int)(xpgain*1.3f)) );
				}

				
			}else{
				level.clients[ clientNum ].sess.xp += xploss;
					///WriteKeys(clientNum,4,qtrue);
					///WriteKeys(clientNum,5,qtrue);
					WriteKeys(clientNum,6,qtrue);
				return;
				/////trap_SendServerCommand(-1, va("print \"^1(%i hp)^7 %s^7> ^1-%i ^4level%s^7 (^1-%i^5 XP^7) ^1$-%i\n\"", level.clients[ clientNum ].ps.stats[STAT_HEALTH] , level.clients[ clientNum ].pers.netname,diff, plural, xploss, (int)(xploss / 1.6f)) );
			}
				level.clients[ clientNum ].sess.wins = newwins;
				level.clients[ clientNum ].sess.admin_number -= (int)(xploss / (3.14f*2));

				WriteKeys(clientNum,4,qtrue);
				WriteKeys(clientNum,5,qtrue);
				///WriteKeys(clientNum,6,qtrue);

				/*for (j = 0; j < level.maxclients; j++) {
					other = &g_entities[j];
					G_SayTo( &g_entities[0], other, SAY_ALL, 4, "^7McWooty ^1(Admin)", va("^7: %s ^1 lost %i^7 level%s [Level %i^1]\n", level.clients[ clientNum ].pers.netname, xploss, level.clients[ clientNum ].sess.xp, NULL) );
				}*/
		}

	}

	ClientUserinfoChanged( clientNum );

	if (g_gametype.integer == GT_POWERDUEL
	&& level.clients[ clientNum ].sess.wins != level.clients[ clientNum ].ps.persistant[PERS_SCORE]){
		level.clients[ clientNum ].ps.persistant[PERS_SCORE] =level.clients[ clientNum ].sess.wins;
	}


	//WriteKeys(clientNum,4,qtrue);
	//WriteKeys(clientNum,5,qtrue);
	//WriteKeys(clientNum,6,qtrue);
}

/*
==================
BeginIntermission
==================
*/



void BeginIntermission( void ) {
	gentity_t	*client;
	int i,j;
	int clFirst, clSec, clThird, clLast, lastOne;
	//gclient_t clFirst, clSecond, clThird, clLast;

	if ( level.intermissiontime ) {
		return;		// already active
	}

	// if in tournement fmode, change the wins / losses
	if ( g_gametype.integer == GT_DUEL || g_gametype.integer == GT_POWERDUEL ) {
		
		//j = Q_irand(0,12);
		////if (level.time % 900000 >= 0 && level.time % 900000 <= 9000){
	

		if (g_gametype.integer != GT_POWERDUEL)
		{
			AdjustTournamentScores();
		}
		else
		{
			//char plural[64];
		
			qboolean clFirstWinner;

			 clFirst = level.clients[ level.sortedClients[0] ].ps.stats[STAT_HEALTH];// + level.clients[ level.sortedClients[0] ].ps.stats[STAT_ARMOR];
			 clSec = level.clients[ level.sortedClients[1] ].ps.stats[STAT_HEALTH];// + level.clients[ level.sortedClients[1] ].ps.stats[STAT_ARMOR];
			 clThird = level.clients[ level.sortedClients[2] ].ps.stats[STAT_HEALTH];// + level.clients[ level.sortedClients[2] ].ps.stats[STAT_ARMOR];
			 clLast = level.clients[ level.sortedClients[level.numConnectedClients - 1]].ps.stats[STAT_HEALTH];// + level.clients[ level.sortedClients[level.numConnectedClients - 1] ].ps.stats[STAT_ARMOR];


		lastOne = 2; 

		if ((level.clients[ level.sortedClients[level.numConnectedClients - 1] ].iAmALoser 
			|| 
			level.clients[ level.sortedClients[level.numConnectedClients - 1]].ps.stats[STAT_HEALTH] <= 0
			)
				&&(
				level.clients[ level.sortedClients[level.numConnectedClients - 1]].sess.sessionTeam != TEAM_SPECTATOR
				||level.clients[ level.sortedClients[level.numConnectedClients - 1] ].iAmALoser 

				)
		){
				lastOne = level.numConnectedClients - 1;		
			 }
			
 
			 if (clFirst <= 0 
				 || level.clients[ level.sortedClients[0] ].iAmALoser 
				 ////|| level.clients[level.sortedClients[0]].ps.eFlags & EF_DEAD
				 ){
				clFirstWinner = qfalse;
			}else{
				clFirstWinner = qtrue;
			}

			////Rand_Init(level.sortedClients[0] * level.sortedClients[1] * level.sortedClients[2]);

			///trap_SetConfigstring ( CS_CLIENT_DUELISTS, va("%i|%i|%i", level.sortedClients[0], level.sortedClients[1], level.sortedClients[2] ) );
			///trap_SetConfigstring ( CS_CLIENT_DUELWINNER, "-1" );

			if (clFirstWinner){
				RoundXP(level.sortedClients[0], qtrue, lastOne);
				RoundXP(level.sortedClients[1], qfalse, lastOne);
				RoundXP(level.sortedClients[lastOne], qfalse, lastOne);

				//G_AddEvent( &g_entities[level.sortedClients[0]], Q_irand( EV_VICTORY1, EV_VICTORY3 ), 0 );
			}else{

				RoundXP(level.sortedClients[0], qfalse, lastOne);
				RoundXP(level.sortedClients[1], qtrue, lastOne);
				RoundXP(level.sortedClients[lastOne], qtrue, lastOne);

				//G_AddEvent( &g_entities[level.sortedClients[1]], Q_irand( EV_VICTORY1, EV_VICTORY3 ), 0 );
				//G_AddEvent( &g_entities[level.sortedClients[lastOne]], Q_irand( EV_GLOAT1, EV_GLOAT3 ), 0 );
			}

		//qsort( level.sortedClients, level.numConnectedClients, 	sizeof(level.sortedClients[0]), SortRanks );

	//	if (g_gametype.integer == GT_POWERDUEL){
			//RemovePowerDuelLosers();
			//AddPowerDuelPlayers();
	//		trap_SetConfigstring ( CS_CLIENT_DUELISTS, va("%i|%i|%i", level.sortedClients[0], level.sortedClients[1], level.sortedClients[2] ) );
	//		trap_SetConfigstring ( CS_CLIENT_DUELWINNER, "-1" );
	//		return;
	//	}

		if (DuelLimitHit())
		{
			gDuelExit = qtrue;
		}
		else
		{
			gDuelExit = qfalse;

		}
	}
}
////	for ( i = 0 ; i < level.maxclients ; i++ ) 
////	{
		////level.clients[i].sess.admin_number = -1;
////	}
	level.intermissiontime = level.time;
	FindIntermissionPoint();

	/*
	if (g_singlePlayer.integer) {
		trap_Cvar_Set("ui_singlePlayerActive", "0");
		UpdateTournamentInfo();
	}
	*/
	//what the? Well, I don't want this to happen.

	// move all clients to the intermission point
	for (i=0 ; i< level.maxclients ; i++) {
		/////client = &g_entities[level.sortedClients[i]];
		client = g_entities + i;
		
	/////if (!client->client || !client->inuse)
		if (!client->inuse)
			continue;

		if (g_debugmw.integer > 0){
			trap_SendServerCommand(-1, va("print \"^7(cl_%i ent_%i) Name: %s^7 Health: %i Team: %i IAmALoser? %i Firstone_%i Secondone_%i Lastone_%i\n\"", 
			client->client->ps.clientNum,
			client->s.number,
			client->client->pers.netname,    
			client->client->ps.stats[STAT_HEALTH], 
			client->client->sess.sessionTeam,
			client->client->iAmALoser,
			level.sortedClients[0],
			level.sortedClients[1],
			level.sortedClients[lastOne]
			) );
		}
		// respawn if dead
		if (client->health <= 0){//// || client->client->iAmALoser) {
			///and should be or?
			if (g_gametype.integer != GT_POWERDUEL &&
				(!client->client ||
				client->client->sess.sessionTeam != TEAM_SPECTATOR))
			{ //don't respawn spectators in powerduel or it will mess the line order all up
				respawn(client);
			}
		}
		MoveClientToIntermission( client );
	}

	// send the current scoring to all clients
	SendScoreboardMessageToAllClients();


/*				int xp, diff, newwins, oldwins;
				////trap_SetConfigstring ( CS_CLIENT_DUELWINNER, va("%i", level.sortedClients[0] ) );
				clientNum = level.sortedClients[0];
				xp = level.clients[ clientNum ].sess.xp;
				if ( level.clients[ clientNum ].pers.connected == CON_CONNECTED ) {
					int xpenemy,xpenemy2;
					clientNum = level.sortedClients[1];
					xpenemy = level.clients[ clientNum ].sess.xp;
					clientNum = level.sortedClients[2];
					xpenemy2 = level.clients[ clientNum ].sess.xp;

					if (xpenemy <= 0){
						xpenemy = 1;
					}
					xpgain = ((((xpenemy +xpenemy2)/2)- xp)/ 4.0) + 45;
					if (xpgain < 50 || xpenemy == xp){
						xpgain = 50;
					}
					xploss = (xpgain/3.5f)+Q_irand(0,3);
					if (xploss <= 0){
						xploss =0;
					}
					clientNum = level.sortedClients[0];

					trap_SendServerCommand(-1, va("print \"%s^7> ^3gained ^3%i^5 XP^3, %i ^4levels\n\"", level.clients[ clientNum ].pers.netname, xpgain, diff) );
					//trap_SendServerCommand(clientNum, va("cp \"%s ^5has gained ^3%i^5 XP\n\"", level.clients[ clientNum ].pers.netname, xpgain) );

					level.clients[ clientNum ].sess.xp += xpgain;

					oldwins = level.clients[ clientNum ].sess.wins;
					newwins = GetLevel(&level.clients[ clientNum ]);//level.clients[ clientNum ].sess.xp;
					diff = newwins - oldwins;

					if (diff != 1){
						strcpy(plural,"s");
					}else{
						strcpy(plural," ");
					}
					if (diff > 0){
						///trap_SendServerCommand(-1, va("print \"%s^7> ^3level up ^4x ^3%i!\n\"", level.clients[ clientNum ].pers.netname, diff) );
						//trap_SendServerCommand(clientNum, va("cp \"%s ^4has gained ^3%i^4 level%s\n\"", level.clients[ clientNum ].pers.netname, diff, plural) );
						}
					level.clients[ clientNum ].sess.wins = newwins;

					level.clients[ clientNum ].sess.admin_number += (int)(xpgain / 5);
					
					
					/////ClientUserinfoChanged( clientNum );
					//trap_SetConfigstring ( CS_CLIENT_DUELWINNER, va("%i", clientNum ) );

					///trap_SendServerCommand(-1, va("print \"%s ^3has gained %i^4 level%s [Level ^3%i^4] (^3%i gold^4)\n\"", level.clients[ clientNum ].pers.netname, xpgain, level.clients[ clientNum ].sess.xp, level.clients[ clientNum ].sess.admin_number) );
					///trap_SendServerCommand(clientNum, va("cp \"%s ^3has gained %i^4 level%s [Level ^3%i^4] (^3%i gold^4)\n\"", level.clients[ clientNum ].pers.netname, xpgain, level.clients[ clientNum ].sess.xp, level.clients[ clientNum ].sess.xp) );
					
					///trap_SendServerCommand(-1, va("print \"%s ^3has gained %i^4 level%s\n\"", level.clients[ clientNum ].pers.netname, xpgain, plural) );
					///trap_SendServerCommand(clientNum, va("cp \"%s ^3has gained %i^4 level%s\n\"", level.clients[ clientNum ].pers.netname, xpgain, plural) );
					//for (j = 0; j < level.maxclients; j++) {
						//other = &g_entities[j];
						//G_SayTo( &g_entities[0], other, SAY_ALL, 4, "^7McWooty ^1(Admin)", va("^7: %s ^3 gained %i^7 level%s [Level %i^7]\n", level.clients[ clientNum ].pers.netname, xpgain, level.clients[ clientNum ].sess.xp, NULL) );
					//}
					////G_LogPrintf( "say: McWooty ^1(Admin)^7: %s ^3gained %i^4 level%s [Level ^3%i^4]\n", level.clients[ clientNum ].pers.netname, xpgain, level.clients[ clientNum ].sess.xp) ;
					////trap_SendServerCommand( clientNum, va("cp \"%s ^3has gained %i^4 level%s [Level ^3%i^4]\n\"", level.clients[ clientNum ].pers.netname, xpgain, level.clients[ clientNum ].sess.xp) );
				}

				clientNum = level.sortedClients[1];
				if ( level.clients[ clientNum ].pers.connected == CON_CONNECTED ) {
					if (level.clients[ clientNum ].sess.xp > -500){
						level.clients[ clientNum ].sess.xp -= xploss;
					}else{
						xploss = 0;
					}
			
					/////ClientUserinfoChanged( clientNum );
						//level.clients[ clientNum ].sess.admin_number += 5 - (xploss / 5);
					oldwins = level.clients[ clientNum ].sess.wins;
					level.clients[ clientNum ].sess.xp -= xploss;
					newwins = GetLevel(&level.clients[ clientNum ]);//level.clients[ clientNum ].sess.xp;
					diff = oldwins - newwins;

					if (diff != 1){
						strcpy(plural,"s");
					}else{
						strcpy(plural," ");
					}

					trap_SendServerCommand(-1, va("print \"%s^7> ^1lost ^1%i^5 XP^1, %i ^4level%s\n\"", level.clients[ clientNum ].pers.netname, xploss, diff, plural) );
					//trap_SendServerCommand(clientNum, va("cp \"%s ^5has lost ^1%i^5 XP\n\"", level.clients[ clientNum ].pers.netname, xploss) );
						
	

					if (diff > 0){

						////trap_SendServerCommand(-1, va("print \"%s^7> ^1level drain ^4x ^1%i!\n\"", level.clients[ clientNum ].pers.netname, diff) );

///						trap_SendServerCommand(-1, va("print \"%s ^1has lost ^1%i^4 level%s\n\"", level.clients[ clientNum ].pers.netname, diff, plural) );
						//trap_SendServerCommand(clientNum, va("cp \"%s ^4has lost ^1%i^4 level%s\n\"", level.clients[ clientNum ].pers.netname, diff, plural) );
						}
					level.clients[ clientNum ].sess.wins = newwins;
					level.clients[ clientNum ].sess.admin_number += 5 - (xploss / 5);

					///level.clients[ clientNum ].sess.admin_number += (xpgain / 5);


					//trap_SendServerCommand(-1, va("print \"%s ^1has lost %i^4 level%s\n\"", level.clients[ clientNum ].pers.netname, xploss, plural) );
					//trap_SendServerCommand(clientNum, va("cp \"%s ^1has lost %i^4 level%s\n\"", level.clients[ clientNum ].pers.netname, xploss, plural) );

					//trap_SendServerCommand(-1, va("print \"%s ^1has lost %i^4 level%s [Level ^1%i^4]\n\"", level.clients[ clientNum ].pers.netname, xploss, level.clients[ clientNum ].sess.xp) );
					//trap_SendServerCommand(clientNum, va("cp \"%s ^1has lost %i^4 level%s [Level ^1%i^4]\n\"", level.clients[ clientNum ].pers.netname, xploss, level.clients[ clientNum ].sess.xp) );
				///	for (j = 0; j < level.maxclients; j++) {
				///		other = &g_entities[j];
					///	G_SayTo( &g_entities[0], other, SAY_ALL, 4, "^7McWooty ^1(Admin)", va("^7: %s ^1 lost %i^7 level%s [Level %i^1]\n", level.clients[ clientNum ].pers.netname, xploss, level.clients[ clientNum ].sess.xp, NULL) );
					///}
					////G_LogPrintf( "say: McWooty ^1(Admin)^7: %s ^3gained %i^4 level%s [Level ^3%i^4]\n", level.clients[ clientNum ].pers.netname, xpgain, level.clients[ clientNum ].sess.xp) ;
					////trap_SendServerCommand(clientNum, va("cp \"%s ^1has lost %i^4 level%s [Level ^1%i^4]\n\"", level.clients[ clientNum ].pers.netname, xploss, level.clients[ clientNum ].sess.xp) );
				}

				clientNum = level.sortedClients[lastOne];
				if ( level.clients[ clientNum ].pers.connected == CON_CONNECTED ) {

					if (level.clients[ clientNum ].sess.xp > -500){
						level.clients[ clientNum ].sess.xp -= xploss;
					}else{
						xploss = 0;
					}

					oldwins = level.clients[ clientNum ].sess.wins;
					level.clients[ clientNum ].sess.xp -= xploss;
					newwins = GetLevel(&level.clients[ clientNum ]);//level.clients[ clientNum ].sess.xp;
					diff = oldwins - newwins;

					if (diff != 1){
						strcpy(plural,"s");
					}else{
						strcpy(plural," ");
					}

					trap_SendServerCommand(-1, va("print \"%s^7> ^1lost ^1%i^5 XP^1, %i ^4level%s\n\"", level.clients[ clientNum ].pers.netname, xploss, diff, plural) );
					///trap_SendServerCommand(-1, va("print \"%s^7> ^1lost ^1%i^5 XP\n\"", level.clients[ clientNum ].pers.netname, xploss) );
					//trap_SendServerCommand(clientNum, va("cp \"%s ^5has lost ^1%i^5 XP\n\"", level.clients[ clientNum ].pers.netname, xploss) );

					if (diff > 0){
						trap_SendServerCommand(-1, va("print \"%s^7> ^1level drain ^4x ^1%i!\n\"", level.clients[ clientNum ].pers.netname, diff) );
						///trap_SendServerCommand(-1, va("print \"%s ^1has lost ^1%i^4 level%s\n\"", level.clients[ clientNum ].pers.netname, diff, plural) );
						//trap_SendServerCommand(clientNum, va("cp \"%s ^4has lost ^1%i^4 level%s\n\"", level.clients[ clientNum ].pers.netname, diff, plural) );
					}
					level.clients[ clientNum ].sess.wins = newwins;
					level.clients[ clientNum ].sess.admin_number += 5 - (xploss / 5);
				}
			}
			else
			{int xp, oldwins, newwins, diff, xpenemy;
				////trap_SetConfigstring ( CS_CLIENT_DUELWINNER, va("%i", level.sortedClients[1] ) );
				/////trap_SetConfigstring ( CS_CLIENT_DUELWINNER, va("%i", level.sortedClients[2] ) );

				clientNum = level.sortedClients[1];
				xp = level.clients[ clientNum ].sess.xp;
				if ( level.clients[ clientNum ].pers.connected == CON_CONNECTED ) {
					

					clientNum = level.sortedClients[0];
					xpenemy = level.clients[ clientNum ].sess.xp;
					if (xpenemy <= 0){
						xpenemy = 1;
					}
					xpgain = ((xpenemy - xp) / 4.2) + 45;
					if (xpgain < 1 || xpenemy == xp){
						xpgain = 1;
					}
					xploss = (xpgain/3.5f)+Q_irand(0,3);
					if (xploss <= 0){
						xploss =0;
					}

					clientNum = level.sortedClients[1];

					level.clients[ clientNum ].sess.xp += xpgain;
					oldwins = level.clients[ clientNum ].sess.wins;
					newwins = GetLevel(&level.clients[ clientNum ]);//level.clients[ clientNum ].sess.xp;
					diff = newwins - oldwins;


					trap_SendServerCommand(-1, va("print \"%s^7> ^3gained ^3%i^5 XP^3, %i ^4levels\n\"", level.clients[ clientNum ].pers.netname, xpgain, diff) );
						//trap_SendServerCommand(clientNum, va("cp \"%s ^5has gained ^3%i^5 XP\n\"", level.clients[ clientNum ].pers.netname, xpgain) );
	

					if (diff != 1){
						strcpy(plural,"s");
					}else{
						strcpy(plural," ");
					}
					if (diff > 0){
						///trap_SendServerCommand(-1, va("print \"%s^7> ^3level up ^4x ^3%i!\n\"", level.clients[ clientNum ].pers.netname, diff) );
						///trap_SendServerCommand(-1, va("print \"%s ^3has gained %i^4 level%s\n\"", level.clients[ clientNum ].pers.netname, diff, plural) );
						//trap_SendServerCommand(clientNum, va("cp \"%s ^3has gained %i^4 level%s\n\"", level.clients[ clientNum ].pers.netname, diff, plural) );
					}
					level.clients[ clientNum ].sess.wins = newwins;
					level.clients[ clientNum ].sess.admin_number += (xpgain / 5);
				}

				clientNum = level.sortedClients[lastOne];
				xp = level.clients[ clientNum ].sess.xp;
				if ( level.clients[ clientNum ].pers.connected == CON_CONNECTED ) {

					clientNum = level.sortedClients[0];
					xpenemy = level.clients[ clientNum ].sess.xp;
					if (xpenemy <= 0){
						xpenemy = 1;
					}
					xpgain = ((xpenemy - xp) / 4.2) + 45;
					if (xpgain < 1 || xpenemy == xp){
						xpgain = 1;
					}
					xploss = (xpgain/3.5f)+Q_irand(0,3);
					if (xploss <= 0){
						xploss =0;
					}

					clientNum = level.sortedClients[lastOne];

					trap_SendServerCommand(-1, va("print \"%s^7> ^3gained ^3%i^5 XP^3, %i ^4levels\n\"", level.clients[ clientNum ].pers.netname, xpgain, diff) );
	
					///trap_SendServerCommand(-1, va("print \"%s^7> ^3gained ^3%i^5 XP\n\"", level.clients[ clientNum ].pers.netname, xpgain) );
					//trap_SendServerCommand(clientNum, va("cp \"%s ^5has gained ^3%i^5 XP\n\"", level.clients[ clientNum ].pers.netname, xpgain) );

					

					oldwins = level.clients[ clientNum ].sess.wins;
					level.clients[ clientNum ].sess.xp += xpgain;
					newwins = GetLevel(&level.clients[ clientNum ]);//level.clients[ clientNum ].sess.xp;
					diff = newwins - oldwins;

					if (diff != 1){
						strcpy(plural,"s");
					}else{
						strcpy(plural," ");
					}
					if (diff > 0){
						////trap_SendServerCommand(-1, va("print \"%s^7> ^3level up ^4x ^3%i!\n\"", level.clients[ clientNum ].pers.netname, diff) );
						///trap_SendServerCommand(-1, va("print \"%s ^3has gained ^3%i^4 level%s\n\"", level.clients[ clientNum ].pers.netname, diff, plural) );
						//trap_SendServerCommand(clientNum, va("cp \"%s ^4has gained ^3%i^4 level%s\n\"", level.clients[ clientNum ].pers.netname, diff, plural) );
					}
					level.clients[ clientNum ].sess.wins = newwins;

					level.clients[ clientNum ].sess.admin_number += (xpgain / 5);
			}

				clientNum = level.sortedClients[0];
				if ( level.clients[ clientNum ].pers.connected == CON_CONNECTED ) {
////					level.clients[ clientNum ].sess.losses++;
						if (level.clients[ clientNum ].sess.xp > -500){
							level.clients[ clientNum ].sess.xp -= xploss;
						}else{
							xploss = 0;
						}
					
					oldwins = level.clients[ clientNum ].sess.wins;
					level.clients[ clientNum ].sess.xp -= xploss;
					newwins = GetLevel(&level.clients[ clientNum ]);//level.clients[ clientNum ].sess.xp;
					diff = oldwins - newwins;

					trap_SendServerCommand(-1, va("print \"%s^7> ^1lost ^1%i^5 XP\n\"", level.clients[ clientNum ].pers.netname, xploss) );
					//trap_SendServerCommand(clientNum, va("cp \"%s ^5has lost ^1%i^5 XP\n\"", level.clients[ clientNum ].pers.netname, xploss) );
			
					if (diff != 1){
						strcpy(plural,"s");
					}else{
						strcpy(plural," ");
					}

					if (diff > 0){
						trap_SendServerCommand(-1, va("print \"%s^7> ^1level drain ^4x ^1%i!\n\"", level.clients[ clientNum ].pers.netname, diff) );
						///trap_SendServerCommand(-1, va("print \"%s ^1has lost ^1%i^4 level%s\n\"", level.clients[ clientNum ].pers.netname, diff, plural) );
						//trap_SendServerCommand(clientNum, va("cp \"%s ^4has lost ^1%i^4 level%s\n\"", level.clients[ clientNum ].pers.netname, diff, plural) );
						}
					level.clients[ clientNum ].sess.wins = newwins;
					level.clients[ clientNum ].sess.admin_number += 5 - (xploss / 5);

				}
			}
			*/



}


qboolean DuelLimitHit(void)
{
	int i;
	gclient_t *cl;

	//if ((level.time) > (g_matchtime.integer*1000*60)){
	//	if ( (g_gametype.integer == GT_DUEL || g_gametype.integer == GT_POWERDUEL) )
	//	{
			/*
			for ( i=0 ; i< g_maxclients.integer ; i++ ) {
				cl = level.clients + i;
				if ( cl->pers.connected != CON_CONNECTED ) {
					continue;
				}
			cl->sess.xp = 0;
			cl->sess.wins = 0;
			cl->sess.losses = 0;
			}
			G_WriteSessionData();
			for (i=0 ; i< g_maxclients.integer ; i++) {
				if ( level.clients[i].pers.connected == CON_CONNECTED ) {
					level.clients[i].pers.connected = CON_CONNECTING;
				}
			}

            trap_SendServerCommand(-1, va("print \"^1MATCH TIMELIMIT HIT.\n\"") );

			return qtrue;*/

	///	}
	///}
	for ( i=0 ; i< g_maxclients.integer ; i++ ) {

		cl = level.clients + i;
		if ( cl->pers.connected != CON_CONNECTED ) {
			continue;
		}

		if ( g_duel_fraglimit.integer && cl->sess.wins >= g_duel_fraglimit.integer )
		{
			return qtrue;
		}
	}

	return qfalse;
}

int ReadLog(void)
{
	fileHandle_t f;
	char *fileString;
	char *currentVar;
	char *routePath;
	wpobject_t thiswp;
	int len;
	int i, i_cv;
	int nei_num;

	i = 0;
	i_cv = 0;

	routePath = (char *)B_TempAlloc(1024);
	Com_sprintf(routePath, 1024, "%s\0", "kills.log");
	len = trap_FS_FOpenFile(routePath, &f, FS_READ);
	B_TempFree(1024); //routePath


	if (!f)
	{
		///G_Printf(S_COLOR_YELLOW "Bot route data not found for %s\n", filename);
		return 2;
	}

	if (len >= 524288)
	{
		///G_Printf(S_COLOR_RED "Route file exceeds maximum length\n");
		return 0;
	}

	fileString = (char *)B_TempAlloc(524288);
	currentVar = (char *)B_TempAlloc(2048);
	trap_FS_Read(fileString, len, f);

	while (fileString[i] != '\n')
	{char readLFlags[64];

		readLFlags[i_cv] += fileString[i];
		i_cv++;
		i++;
	}
return i;
}


void DuelResetWinsLosses(void)
{
	int i;
	gclient_t *cl;

	for ( i=0 ; i< g_maxclients.integer ; i++ ) {
		cl = level.clients + i;
		if ( cl->pers.connected != CON_CONNECTED ) {
			continue;
		}
		cl->sess.xp = 0;
		cl->sess.wins = 0;
		cl->sess.losses = 0;
	}
}

/*
=============
ExitLevel

When the intermission has been exited, the server is either killed
or moved to a new level based on the "nextmap" cvar 

=============
*/
extern void SiegeDoTeamAssign(void); //g_saga.c
extern siegePers_t g_siegePersistant; //g_saga.c
void ExitLevel (void) {
	int		i;
	gclient_t *cl;

	// if we are running a tournement map, kick the loser to spectator status,
	// which will automatically grab the next spectator and restart
	if ( g_gametype.integer == GT_DUEL || g_gametype.integer == GT_POWERDUEL ) {



		if (!DuelLimitHit())
		{
			if ( !level.restarted ) {
				trap_SendConsoleCommand( EXEC_APPEND, "map_restart 0\n" );
				level.restarted = qtrue;
				level.changemap = NULL;
				level.intermissiontime = 0;
			}
			return;	
		}
		DuelResetWinsLosses();
	}


	if (g_gametype.integer == GT_SIEGE &&
		g_siegeTeamSwitch.integer &&
		g_siegePersistant.beatingTime)
	{ //restart same map...
		trap_SendConsoleCommand( EXEC_APPEND, "map_restart 0\n" );
	}
	else
	{
		trap_SendConsoleCommand( EXEC_APPEND, "vstr nextmap\n" );
	}
	level.changemap = NULL;
	level.intermissiontime = 0;

	if (g_gametype.integer == GT_SIEGE &&
		g_siegeTeamSwitch.integer)
	{ //switch out now
		SiegeDoTeamAssign();
	}

	// reset all the scores so we don't enter the intermission again
	level.teamScores[TEAM_RED] = 0;
	level.teamScores[TEAM_BLUE] = 0;
	for ( i=0 ; i< g_maxclients.integer ; i++ ) {
		cl = level.clients + i;
		if ( cl->pers.connected != CON_CONNECTED ) {
			continue;
		}
		///bad unwoot, testing
		cl->ps.persistant[PERS_SCORE] = 0;
	}

	// we need to do this here before chaning to CON_CONNECTING
	G_WriteSessionData();

	// change all client states to connecting, so the early players into the
	// next level will know the others aren't done reconnecting
	for (i=0 ; i< g_maxclients.integer ; i++) {
		if ( level.clients[i].pers.connected == CON_CONNECTED ) {
			level.clients[i].pers.connected = CON_CONNECTING;
		}
	}

}

/*
=================
G_LogPrintf

Print to the logfile with a time stamp if it is open
=================
*/
void QDECL G_LogPrintf( const char *fmt, ... ) {
	va_list		argptr;
	char		string[1024];
	int			min, tens, sec;
	///time_t ltime;

	///time( &ltime );
   ///printf( "The time is %s\n", ctime( &ltime ) );

	sec = level.time / 1000;

	min = sec / 60;
	sec -= min * 60;
	tens = sec / 10;
	sec -= tens * 10;

	Com_sprintf( string, sizeof(string), "%3i:%i%i ", min, tens, sec );

	va_start( argptr, fmt );
	vsprintf( string +7 , fmt,argptr );
	va_end( argptr );

	if ( g_dedicated.integer ) {
		G_Printf( "%s", string + 7 );
	}

	if ( !level.logFile ) {
		return;
	}

	trap_FS_Write( string, strlen( string ), level.logFile );
}

/*
================
LogExit

Append information about this game to the log file
================
*/
void LogExit( const char *string ) {
	int				i, numSorted;
	gclient_t		*cl;
//	qboolean		won = qtrue;
	G_LogPrintf( "Exit: %s\n", string );

	level.intermissionQueued = level.time;

	// this will keep the clients from playing any voice sounds
	// that will get cut off when the queued intermission starts
	trap_SetConfigstring( CS_INTERMISSION, "1" );

	// don't send more than 32 scores (FIXME?)
	numSorted = level.numConnectedClients;
	if ( numSorted > 32 ) {
		numSorted = 32;
	}

	if ( g_gametype.integer >= GT_TEAM ) {
		G_LogPrintf( "red:%i  blue:%i\n",
			level.teamScores[TEAM_RED], level.teamScores[TEAM_BLUE] );
	}

	for (i=0 ; i < numSorted ; i++) {
		int		ping;

		cl = &level.clients[level.sortedClients[i]];

		if ( cl->sess.sessionTeam == TEAM_SPECTATOR ) {
			continue;
		}
		if ( cl->pers.connected == CON_CONNECTING ) {
			continue;
		}


		if ( cl->ps.ping <= 9 ) {
			ping = 40+Q_irand(2,16);
		}
		//} else {
		//	ping = cl->ps.ping < 999 ? cl->ps.ping : 999;
		//}



		ping = cl->ps.ping < 999 ? cl->ps.ping : 999;

		///G_LogPrintf( "score: %i  ping: %i  client: %i %s\n", cl->ps.persistant[PERS_SCORE], ping, level.sortedClients[i],	cl->pers.netname );

//		if (g_singlePlayer.integer && (g_gametype.integer == GT_DUEL || g_gametype.integer == GT_POWERDUEL)) {
//			if (g_entities[cl - level.clients].r.svFlags & SVF_BOT && cl->ps.persistant[PERS_RANK] == 0) {
//				won = qfalse;
//			}
//		}
	}

	//yeah.. how about not.
	/*
	if (g_singlePlayer.integer) {
		if (g_gametype.integer >= GT_CTF) {
			won = level.teamScores[TEAM_RED] > level.teamScores[TEAM_BLUE];
		}
		trap_SendConsoleCommand( EXEC_APPEND, (won) ? "spWin\n" : "spLose\n" );
	}
	*/
}

qboolean gDidDuelStuff = qfalse; //gets reset on game reinit

/*
=================
CheckIntermissionExit

The level will stay at the intermission for a minimum of 5 seconds
If all players wish to continue, the level will then exit.
If one or more players have not acknowledged the continue, the game will
wait 10 seconds before going on.
=================
*/
void CheckIntermissionExit( void ) {
	int			ready, notReady;
	int			i;
	gclient_t	*cl;
	int			readyMask;

	// see which players are ready
	ready = 0;
	notReady = 0;
	readyMask = 0;
	for (i=0 ; i< g_maxclients.integer ; i++) {
		cl = level.clients + i;
		if ( cl->pers.connected != CON_CONNECTED ) {
			continue;
		}
		if ( g_entities[cl->ps.clientNum].r.svFlags & SVF_BOT ) {
			continue;
		}

		if ( cl->readyToExit ) {
			ready++;
			if ( i < 16 ) {
				readyMask |= 1 << i;
			}
		} else {
			notReady++;
		}
	}

	if ( (g_gametype.integer == GT_DUEL || g_gametype.integer == GT_POWERDUEL) && !gDidDuelStuff &&
		(level.time > level.intermissiontime + 2000))//2000) )
	{
		gDidDuelStuff = qtrue;

		if ( g_austrian.integer && g_gametype.integer != GT_POWERDUEL )
		{
			G_LogPrintf("Duel Results:\n");
			//G_LogPrintf("Duel Time: %d\n", level.time );
			G_LogPrintf("winner: %s, score: %d, wins/losses: %d/%d\n", 
				level.clients[level.sortedClients[0]].pers.netname,
				level.clients[level.sortedClients[0]].ps.persistant[PERS_SCORE],
				level.clients[level.sortedClients[0]].sess.wins,
				level.clients[level.sortedClients[0]].sess.losses );
			G_LogPrintf("loser: %s, score: %d, wins/losses: %d/%d\n", 
				level.clients[level.sortedClients[1]].pers.netname,
				level.clients[level.sortedClients[1]].ps.persistant[PERS_SCORE],
				level.clients[level.sortedClients[1]].sess.wins,
				level.clients[level.sortedClients[1]].sess.losses );
		}
		// if we are running a tournement map, kick the loser to spectator status,
		// which will automatically grab the next spectator and restart
		if (!DuelLimitHit())
		{
			if (g_gametype.integer == GT_POWERDUEL)
			{
				RemovePowerDuelLosers();
				AddPowerDuelPlayers();
			}
			else
			{
				if (level.clients[level.sortedClients[0]].ps.persistant[PERS_SCORE] ==
					level.clients[level.sortedClients[1]].ps.persistant[PERS_SCORE] &&
					level.clients[level.sortedClients[0]].pers.connected == CON_CONNECTED &&
					level.clients[level.sortedClients[1]].pers.connected == CON_CONNECTED)
				{
					RemoveDuelDrawLoser();
				}
				else
				{
					RemoveTournamentLoser();
				}
				AddTournamentPlayer();
			}

			if ( g_austrian.integer )
			{
				if (g_gametype.integer == GT_POWERDUEL)
				{
					G_LogPrintf("Power Duel Initiated: %s %d/%d vs %s %d/%d and %s %d/%d, kill limit: %d\n", 
						level.clients[level.sortedClients[0]].pers.netname,
						level.clients[level.sortedClients[0]].sess.wins,
						level.clients[level.sortedClients[0]].sess.losses,
						level.clients[level.sortedClients[1]].pers.netname,
						level.clients[level.sortedClients[1]].sess.wins,
						level.clients[level.sortedClients[1]].sess.losses,
						level.clients[level.sortedClients[2]].pers.netname,
						level.clients[level.sortedClients[2]].sess.wins,
						level.clients[level.sortedClients[2]].sess.losses,
						g_fraglimit.integer );
				}
				else
				{
					G_LogPrintf("Duel Initiated: %s %d/%d vs %s %d/%d, kill limit: %d\n", 
						level.clients[level.sortedClients[0]].pers.netname,
						level.clients[level.sortedClients[0]].sess.wins,
						level.clients[level.sortedClients[0]].sess.losses,
						level.clients[level.sortedClients[1]].pers.netname,
						level.clients[level.sortedClients[1]].sess.wins,
						level.clients[level.sortedClients[1]].sess.losses,
						g_fraglimit.integer );
				}
			}
			
			if (g_gametype.integer == GT_POWERDUEL)
			{
				if (level.numPlayingClients >= 3 && level.numNonSpectatorClients >= 3)
				{
					trap_SetConfigstring ( CS_CLIENT_DUELISTS, va("%i|%i|%i", level.sortedClients[0], level.sortedClients[1], level.sortedClients[2] ) );
					trap_SetConfigstring ( CS_CLIENT_DUELWINNER, "-1" );
				}			
			}
			else
			{
				if (level.numPlayingClients >= 2)
				{
					trap_SetConfigstring ( CS_CLIENT_DUELISTS, va("%i|%i", level.sortedClients[0], level.sortedClients[1] ) );
					trap_SetConfigstring ( CS_CLIENT_DUELWINNER, "-1" );
				}
			}

			return;	
		}

		if ( g_austrian.integer && g_gametype.integer != GT_POWERDUEL )
		{
			G_LogPrintf("Duel Tournament Winner: %s wins/losses: %d/%d\n", 
				level.clients[level.sortedClients[0]].pers.netname,
				level.clients[level.sortedClients[0]].sess.wins,
				level.clients[level.sortedClients[0]].sess.losses );
		}

		if (g_gametype.integer == GT_POWERDUEL)
		{
			RemovePowerDuelLosers();
			AddPowerDuelPlayers();

			if (level.numPlayingClients >= 3 && level.numNonSpectatorClients >= 3)
			{
				trap_SetConfigstring ( CS_CLIENT_DUELISTS, va("%i|%i|%i", level.sortedClients[0], level.sortedClients[1], level.sortedClients[2] ) );
				trap_SetConfigstring ( CS_CLIENT_DUELWINNER, "-1" );
			}
		}
		else
		{
			//this means we hit the duel limit so reset the wins/losses
			//but still push the loser to the back of the line, and retain the order for
			//the map change
			if (level.clients[level.sortedClients[0]].ps.persistant[PERS_SCORE] ==
				level.clients[level.sortedClients[1]].ps.persistant[PERS_SCORE] &&
				level.clients[level.sortedClients[0]].pers.connected == CON_CONNECTED &&
				level.clients[level.sortedClients[1]].pers.connected == CON_CONNECTED)
			{
				RemoveDuelDrawLoser();
			}
			else
			{
				RemoveTournamentLoser();
			}

			AddTournamentPlayer();

			if (level.numPlayingClients >= 2)
			{
				trap_SetConfigstring ( CS_CLIENT_DUELISTS, va("%i|%i", level.sortedClients[0], level.sortedClients[1] ) );
				trap_SetConfigstring ( CS_CLIENT_DUELWINNER, "-1" );
			}
		}
	}

	if ((g_gametype.integer == GT_DUEL || g_gametype.integer == GT_POWERDUEL) && !gDuelExit)
	{ //in duel, we have different behaviour for between-round intermissions
		if ( level.time > level.intermissiontime + g_intermissiontime.integer )//4000
		{ //automatically go to next after 4 seconds
			ExitLevel(level.time > level.intermissiontime);
			return;
		}else if(level.time > level.intermissiontime && 
			level.numInterestPoints != 
			(int)(g_intermissiontime.integer/1000)-(int)((level.time - level.intermissiontime)/1000)
			){
			level.numInterestPoints = (int)(g_intermissiontime.integer/1000)-(int)((level.time - level.intermissiontime)/1000);
			trap_SendServerCommand( -1, va("print \"^7%i...\"",level.numInterestPoints) );
		}

		for (i=0 ; i< g_maxclients.integer ; i++)
		{ //being in a "ready" state is not necessary here, so clear it for everyone
		  //yes, I also thinking holding this in a ps value uniquely for each player
		  //is bad and wrong, but it wasn't my idea.
			cl = level.clients + i;
			if ( cl->pers.connected != CON_CONNECTED )
			{
				continue;
			}
			cl->ps.stats[STAT_CLIENTS_READY] = 0;
		}
		return;
	}

	// copy the readyMask to each player's stats so
	// it can be displayed on the scoreboard
	for (i=0 ; i< g_maxclients.integer ; i++) {
		cl = level.clients + i;
		if ( cl->pers.connected != CON_CONNECTED ) {
			continue;
		}
		cl->ps.stats[STAT_CLIENTS_READY] = readyMask;
	}

	// never exit in less than five seconds
	if ( level.time < level.intermissiontime + 5000 ) {
		return;
	}

	if (d_noIntermissionWait.integer)
	{ //don't care who wants to go, just go.
		ExitLevel();
		return;
	}

	// if nobody wants to go, clear timer
	if ( !ready ) {
		level.readyToExit = qfalse;
		return;
	}

	// if everyone wants to go, go now
	if ( !notReady ) {
		ExitLevel();
		return;
	}

	// the first person to ready starts the ten second timeout
	if ( !level.readyToExit ) {
		level.readyToExit = qtrue;
		level.exitTime = level.time;
	}

	// if we have waited ten seconds since at least one player
	// wanted to exit, go ahead
	if ( level.time < level.exitTime + 10000 ) {
		return;
	}

	ExitLevel();
}

/*
=============
ScoreIsTied
=============
*/
qboolean ScoreIsTied( void ) {
	int		a, b;

	if ( level.numPlayingClients < 2 ) {
		return qfalse;
	}
	
	if ( g_gametype.integer >= GT_TEAM ) {
		return level.teamScores[TEAM_RED] == level.teamScores[TEAM_BLUE];
	}

	a = level.clients[level.sortedClients[0]].ps.persistant[PERS_SCORE];
	b = level.clients[level.sortedClients[1]].ps.persistant[PERS_SCORE];

	return a == b;
}

/*
=================
CheckExitRules

There will be a delay between the time the exit is qualified for
and the time everyone is moved to the intermission spot, so you
can see the last frag.
=================
*/
qboolean g_endPDuel = qfalse;
void CheckExitRules( void ) {
 	int			i;
	gclient_t	*cl;
	char *sKillLimit;
	qboolean printLimit = qtrue;
	// if at the intermission, wait for all non-bots to
	// signal ready, then go to next level
	if ( level.intermissiontime ) {
		CheckIntermissionExit ();
		return;
	}

	if (gDoSlowMoDuel)
	{ //don't go to intermission while in slow motion
		return;
	}

	if (gEscaping)
	{
		int i = 0;
		int numLiveClients = 0;

		while (i < MAX_CLIENTS)
		{
			if (g_entities[i].inuse && g_entities[i].client && g_entities[i].health > 0)
			{
				if (g_entities[i].client->sess.sessionTeam != TEAM_SPECTATOR &&
					!(g_entities[i].client->ps.pm_flags & PMF_FOLLOW))
				{
					numLiveClients++;
				}
			}

			i++;
		}
		if (gEscapeTime < level.time)
		{
			gEscaping = qfalse;
			LogExit( "Escape time ended." );
			return;
		}
		if (!numLiveClients)
		{
			gEscaping = qfalse;
			LogExit( "Everyone failed to escape." );
			return;
		}
	}

	if ( level.intermissionQueued ) {
		//int time = (g_singlePlayer.integer) ? SP_INTERMISSION_DELAY_TIME : INTERMISSION_DELAY_TIME;
		int time = INTERMISSION_DELAY_TIME;
		if ( level.time - level.intermissionQueued >= time ) {
			level.intermissionQueued = 0;
			BeginIntermission();

			///RemovePowerDuelLosers();
			///AddPowerDuelPlayers();
		}
		return;
	}

	
	/*if (g_gametype.integer == GT_POWERDUEL)
	{
		if (level.numPlayingClients < 3)
		{
			if (!level.intermissiontime)
			{
				if (d_powerDuelPrint.integer)
				{
					Com_Printf("POWERDUEL WIN CONDITION: Duel forfeit (1)\n");
				}
				LogExit("Duel forfeit.");
				return;
			}
		}
	}*/
	

	// check for sudden death
	if (g_gametype.integer != GT_SIEGE)
	{
		if ( ScoreIsTied() ) {
			// always wait for sudden death
			if ((g_gametype.integer != GT_DUEL) || !g_timelimit.integer)
			{
				if (g_gametype.integer != GT_POWERDUEL)
				{
					return;
				}
			}
		}
	}

	if (g_gametype.integer != GT_SIEGE)
	{
		if ( g_timelimit.integer && !level.warmupTime ) {
			if ( level.time - level.startTime >= g_timelimit.integer*60000 ) {
//				trap_SendServerCommand( -1, "print \"Timelimit hit.\n\"");
				trap_SendServerCommand( -1, va("print \"%s.\n\"",G_GetStringEdString("MP_SVGAME", "TIMELIMIT_HIT")));
				if (d_powerDuelPrint.integer)
				{
					Com_Printf("POWERDUEL WIN CONDITION: Timelimit hit (1)\n");
				}
				LogExit( "Timelimit hit." );
				return;
			}
		}
	}

	if (g_gametype.integer == GT_POWERDUEL && level.numPlayingClients >= 3)
	{
		if (g_endPDuel)
		{
			g_endPDuel = qfalse;
			LogExit("Powerduel ended.");
		}

		//yeah, this stuff was completely insane.
		/*
		int duelists[3];
		duelists[0] = level.sortedClients[0];
		duelists[1] = level.sortedClients[1];
		duelists[2] = level.sortedClients[2];

		if (duelists[0] != -1 &&
			duelists[1] != -1 &&
			duelists[2] != -1)
		{
			if (!g_entities[duelists[0]].inuse ||
				!g_entities[duelists[0]].client ||
				g_entities[duelists[0]].client->ps.stats[STAT_HEALTH] <= 0 ||
				g_entities[duelists[0]].client->sess.sessionTeam != TEAM_FREE)
			{ //The lone duelist lost, give the other two wins (if applicable) and him a loss
				if (g_entities[duelists[0]].inuse &&
					g_entities[duelists[0]].client)
				{
					g_entities[duelists[0]].client->sess.losses++;
					ClientUserinfoChanged(duelists[0]);
				}
				if (g_entities[duelists[1]].inuse &&
					g_entities[duelists[1]].client)
				{
					if (g_entities[duelists[1]].client->ps.stats[STAT_HEALTH] > 0 &&
						g_entities[duelists[1]].client->sess.sessionTeam == TEAM_FREE)
					{
						g_entities[duelists[1]].client->sess.wins++;
					}
					else
					{
						g_entities[duelists[1]].client->sess.losses++;
					}
					ClientUserinfoChanged(duelists[1]);
				}
				if (g_entities[duelists[2]].inuse &&
					g_entities[duelists[2]].client)
				{
					if (g_entities[duelists[2]].client->ps.stats[STAT_HEALTH] > 0 &&
						g_entities[duelists[2]].client->sess.sessionTeam == TEAM_FREE)
					{
						g_entities[duelists[2]].client->sess.wins++;
					}
					else
					{
						g_entities[duelists[2]].client->sess.losses++;
					}
					ClientUserinfoChanged(duelists[2]);
				}

				//Will want to parse indecies for two out at some point probably
				trap_SetConfigstring ( CS_CLIENT_DUELWINNER, va("%i", duelists[1] ) );

				if (d_powerDuelPrint.integer)
				{
					Com_Printf("POWERDUEL WIN CONDITION: Coupled duelists won (1)\n");
				}
				LogExit( "Coupled duelists won." );
				gDuelExit = qfalse;
			}
			else if ((!g_entities[duelists[1]].inuse ||
				!g_entities[duelists[1]].client ||
				g_entities[duelists[1]].client->sess.sessionTeam != TEAM_FREE ||
				g_entities[duelists[1]].client->ps.stats[STAT_HEALTH] <= 0) &&
				(!g_entities[duelists[2]].inuse ||
				!g_entities[duelists[2]].client ||
				g_entities[duelists[2]].client->sess.sessionTeam != TEAM_FREE ||
				g_entities[duelists[2]].client->ps.stats[STAT_HEALTH] <= 0))
			{ //the coupled duelists lost, give the lone duelist a win (if applicable) and the couple both losses
				if (g_entities[duelists[1]].inuse &&
					g_entities[duelists[1]].client)
				{
					g_entities[duelists[1]].client->sess.losses++;
					ClientUserinfoChanged(duelists[1]);
				}
				if (g_entities[duelists[2]].inuse &&
					g_entities[duelists[2]].client)
				{
					g_entities[duelists[2]].client->sess.losses++;
					ClientUserinfoChanged(duelists[2]);
				}

				if (g_entities[duelists[0]].inuse &&
					g_entities[duelists[0]].client &&
					g_entities[duelists[0]].client->ps.stats[STAT_HEALTH] > 0 &&
					g_entities[duelists[0]].client->sess.sessionTeam == TEAM_FREE)
				{
					g_entities[duelists[0]].client->sess.wins++;
					ClientUserinfoChanged(duelists[0]);
				}

				trap_SetConfigstring ( CS_CLIENT_DUELWINNER, va("%i", duelists[0] ) );

				if (d_powerDuelPrint.integer)
				{
					Com_Printf("POWERDUEL WIN CONDITION: Lone duelist won (1)\n");
				}
				LogExit( "Lone duelist won." );
				gDuelExit = qfalse;
			}
		}
		*/////
		return;
	}

	if ( level.numPlayingClients < 2 ) {
		return;
	}

	if (g_gametype.integer == GT_DUEL ||
		g_gametype.integer == GT_POWERDUEL)
	{
		if (g_fraglimit.integer > 1)
		{
			sKillLimit = "Kill limit hit.";
		}
		else
		{
			sKillLimit = "";
			printLimit = qfalse;
		}
	}
	else
	{
		sKillLimit = "Kill limit hit.";
	}
	if ( g_gametype.integer < GT_SIEGE && g_fraglimit.integer ) {
		if ( level.teamScores[TEAM_RED] >= g_fraglimit.integer ) {
			trap_SendServerCommand( -1, va("print \"Red %s\n\"", G_GetStringEdString("MP_SVGAME", "HIT_THE_KILL_LIMIT")) );
			if (d_powerDuelPrint.integer)
			{
				Com_Printf("POWERDUEL WIN CONDITION: Kill limit (1)\n");
			}
			LogExit( sKillLimit );
			return;
		}

		if ( level.teamScores[TEAM_BLUE] >= g_fraglimit.integer ) {
			trap_SendServerCommand( -1, va("print \"Blue %s\n\"", G_GetStringEdString("MP_SVGAME", "HIT_THE_KILL_LIMIT")) );
			if (d_powerDuelPrint.integer)
			{
				Com_Printf("POWERDUEL WIN CONDITION: Kill limit (2)\n");
			}
			LogExit( sKillLimit );
			return;
		}

		for ( i=0 ; i< g_maxclients.integer ; i++ ) {
			cl = level.clients + i;
			if ( cl->pers.connected != CON_CONNECTED ) {
				continue;
			}
			if ( cl->sess.sessionTeam != TEAM_FREE ) {
				continue;
			}

			if ( (g_gametype.integer == GT_DUEL || g_gametype.integer == GT_POWERDUEL) && g_duel_fraglimit.integer && cl->sess.wins >= g_duel_fraglimit.integer )
			{
				if (d_powerDuelPrint.integer)
				{
					Com_Printf("POWERDUEL WIN CONDITION: Duel limit hit (1)\n");
				}
				LogExit( "Duel limit hit." );
				gDuelExit = qtrue;
				trap_SendServerCommand( -1, va("print \"%s" S_COLOR_WHITE " hit the win limit.\n\"",
					cl->pers.netname ) );
				return;
			}

		
			if ( cl->ps.persistant[PERS_SCORE] >= g_fraglimit.integer ) {
				if (d_powerDuelPrint.integer)
				{
					Com_Printf("POWERDUEL WIN CONDITION: Kill limit (3)\n");
				}
				LogExit( sKillLimit );
				gDuelExit = qfalse;
				if (printLimit)
				{
					trap_SendServerCommand( -1, va("print \"%s" S_COLOR_WHITE " %s.\n\"",
													cl->pers.netname,
													G_GetStringEdString("MP_SVGAME", "HIT_THE_KILL_LIMIT")
													) 
											);
				}
				return;
			}
		}
	}

	if ( g_gametype.integer >= GT_CTF && g_capturelimit.integer ) {

		if ( level.teamScores[TEAM_RED] >= g_capturelimit.integer ) 
		{
			trap_SendServerCommand( -1,  va("print \"%s \"", G_GetStringEdString("MP_SVGAME", "PRINTREDTEAM")));
			trap_SendServerCommand( -1,  va("print \"%s.\n\"", G_GetStringEdString("MP_SVGAME", "HIT_CAPTURE_LIMIT")));
			LogExit( "Capturelimit hit." );
			return;
		}

		if ( level.teamScores[TEAM_BLUE] >= g_capturelimit.integer ) {
			trap_SendServerCommand( -1,  va("print \"%s \"", G_GetStringEdString("MP_SVGAME", "PRINTBLUETEAM")));
			trap_SendServerCommand( -1,  va("print \"%s.\n\"", G_GetStringEdString("MP_SVGAME", "HIT_CAPTURE_LIMIT")));
			LogExit( "Capturelimit hit." );
			return;
		}
	}
}



/*
========================================================================

FUNCTIONS CALLED EVERY FRAME

========================================================================
*/

void G_RemoveDuelist(int team)
{
	int i = 0;
	gentity_t *ent;
	while (i < MAX_CLIENTS)
	{
		ent = &g_entities[i];

		if (ent->inuse && ent->client && ent->client->sess.sessionTeam != TEAM_SPECTATOR &&
			ent->client->sess.duelTeam == team)
		{
			SetTeam(ent, "s");
		}
        i++;
	}
}

/*
=============
CheckTournament

Once a frame, check for changes in tournement player state
=============
*/
int g_duelPrintTimer = 0;
void CheckTournament( void ) {
	// check because we run 3 game frames before calling Connect and/or ClientBegin
	// for clients on a map_restart
//	if ( level.numPlayingClients == 0 && (g_gametype.integer != GT_POWERDUEL) ) {
//		return;
//	}

	if (g_gametype.integer == GT_POWERDUEL)
	{
		if (level.numPlayingClients >= 3 && level.numNonSpectatorClients >= 3)
		{
			trap_SetConfigstring ( CS_CLIENT_DUELISTS, va("%i|%i|%i", level.sortedClients[0], level.sortedClients[1], level.sortedClients[2] ) );
		}
	}
	else
	{
		if (level.numPlayingClients >= 2)
		{
			trap_SetConfigstring ( CS_CLIENT_DUELISTS, va("%i|%i", level.sortedClients[0], level.sortedClients[1] ) );
		}
	}

	if ( g_gametype.integer == GT_DUEL )
	{
		// pull in a spectator if needed
		if ( level.numPlayingClients < 2 && !level.intermissiontime && !level.intermissionQueued ) {
			AddTournamentPlayer();

			if (level.numPlayingClients >= 2)
			{
				trap_SetConfigstring ( CS_CLIENT_DUELISTS, va("%i|%i", level.sortedClients[0], level.sortedClients[1] ) );
			}
		}

		if (level.numPlayingClients >= 2)
		{
// nmckenzie: DUEL_HEALTH
			if ( g_showDuelHealths.integer >= 1 )
			{
				playerState_t *ps1, *ps2;
				ps1 = &level.clients[level.sortedClients[0]].ps;
				ps2 = &level.clients[level.sortedClients[1]].ps;
				trap_SetConfigstring ( CS_CLIENT_DUELHEALTHS, va("%i|%i|!", 
					ps1->stats[STAT_HEALTH], ps2->stats[STAT_HEALTH]));
			}
		}

		//rww - It seems we have decided there will be no warmup in duel.
		//if (!g_warmup.integer)
		{ //don't care about any of this stuff then, just add people and leave me alone
			level.warmupTime = 0;
			return;
		}
#if 0
		// if we don't have two players, go back to "waiting for players"
		if ( level.numPlayingClients != 2 ) {
			if ( level.warmupTime != -1 ) {
				level.warmupTime = -1;
				trap_SetConfigstring( CS_WARMUP, va("%i", level.warmupTime) );
				G_LogPrintf( "Warmup:\n" );
			}
			return;
		}

		if ( level.warmupTime == 0 ) {
			return;
		}

		// if the warmup is changed at the console, restart it
		if ( g_warmup.modificationCount != level.warmupModificationCount ) {
			level.warmupModificationCount = g_warmup.modificationCount;
			level.warmupTime = -1;
		}

		// if all players have arrived, start the countdown
		if ( level.warmupTime < 0 ) {
			if ( level.numPlayingClients == 2 ) {
				// fudge by -1 to account for extra delays
				level.warmupTime = level.time + ( g_warmup.integer - 1 ) * 1000;

				if (level.warmupTime < (level.time + 3000))
				{ //rww - this is an unpleasent hack to keep the level from resetting completely on the client (this happens when two map_restarts are issued rapidly)
					level.warmupTime = level.time + 3000;
				}
				trap_SetConfigstring( CS_WARMUP, va("%i", level.warmupTime) );
			}
			return;
		}

		// if the warmup time has counted down, restart
		if ( level.time > level.warmupTime ) {
			level.warmupTime += 10000;
			trap_Cvar_Set( "g_restarted", "1" );
			trap_SendConsoleCommand( EXEC_APPEND, "map_restart 0\n" );
			level.restarted = qtrue;
			return;
		}
#endif
	}
	else if (g_gametype.integer == GT_POWERDUEL)
	{
		if (level.numPlayingClients < 2)
		{ //hmm, ok, pull more in.
			g_dontFrickinCheck = qfalse;
		}

		if (level.numPlayingClients > 3)
		{ //umm..yes..lets take care of that then.
			int lone = 0, dbl = 0;

			G_PowerDuelCount(&lone, &dbl, qfalse);
			if (lone > 1)
			{
				G_RemoveDuelist(DUELTEAM_LONE);
			}
			else if (dbl > 2)
			{
				G_RemoveDuelist(DUELTEAM_DOUBLE);
			}
		}
		else if (level.numPlayingClients < 3)
		{ //hmm, someone disconnected or something and we need em
			int lone = 0, dbl = 0;

			G_PowerDuelCount(&lone, &dbl, qfalse);
			if (lone < 1)
			{
				g_dontFrickinCheck = qfalse;
			}
			else if (dbl < 1)
			{
				g_dontFrickinCheck = qfalse;
			}
		}

		// pull in a spectator if needed
		if (level.numPlayingClients < 3 && !g_dontFrickinCheck)
		{
			AddPowerDuelPlayers();

			if (level.numPlayingClients >= 3 &&
				G_CanResetDuelists())
			{
				gentity_t *te = G_TempEntity(vec3_origin, EV_GLOBAL_DUEL);
				te->r.svFlags |= SVF_BROADCAST;
				//this is really pretty nasty, but..
				te->s.otherEntityNum = level.sortedClients[0];
				te->s.otherEntityNum2 = level.sortedClients[1];
				te->s.groundEntityNum = level.sortedClients[2];

				trap_SetConfigstring ( CS_CLIENT_DUELISTS, va("%i|%i|%i", level.sortedClients[0], level.sortedClients[1], level.sortedClients[2] ) );
				G_ResetDuelists();

				g_dontFrickinCheck = qtrue;
			}
			else if (level.numPlayingClients > 0 ||
				level.numConnectedClients > 0)
			{
				if (g_duelPrintTimer < level.time)
				{ //print once every 10 seconds
					int lone = 0, dbl = 0;

					G_PowerDuelCount(&lone, &dbl, qtrue);
					if (lone < 1)
					{
						trap_SendServerCommand( -1, va("cp \"%s\n\"", G_GetStringEdString("MP_SVGAME", "DUELMORESINGLE")) );
					}
					else
					{
						trap_SendServerCommand( -1, va("cp \"%s\n\"", G_GetStringEdString("MP_SVGAME", "DUELMOREPAIRED")) );
					}
					g_duelPrintTimer = level.time + 10000;
				}
			}

			if (level.numPlayingClients >= 3 && level.numNonSpectatorClients >= 3)
			{ //pulled in a needed person
				if (G_CanResetDuelists())
				{
					gentity_t *te = G_TempEntity(vec3_origin, EV_GLOBAL_DUEL);
					te->r.svFlags |= SVF_BROADCAST;
					//this is really pretty nasty, but..
					te->s.otherEntityNum = level.sortedClients[0];
					te->s.otherEntityNum2 = level.sortedClients[1];
					te->s.groundEntityNum = level.sortedClients[2];

					trap_SetConfigstring ( CS_CLIENT_DUELISTS, va("%i|%i|%i", level.sortedClients[0], level.sortedClients[1], level.sortedClients[2] ) );

					if ( g_austrian.integer )
					{
						G_LogPrintf("Duel Initiated: %s %d/%d vs %s %d/%d and %s %d/%d, kill limit: %d\n", 
							level.clients[level.sortedClients[0]].pers.netname,
							level.clients[level.sortedClients[0]].sess.wins,
							level.clients[level.sortedClients[0]].sess.losses,
							level.clients[level.sortedClients[1]].pers.netname,
							level.clients[level.sortedClients[1]].sess.wins,
							level.clients[level.sortedClients[1]].sess.losses,
							level.clients[level.sortedClients[2]].pers.netname,
							level.clients[level.sortedClients[2]].sess.wins,
							level.clients[level.sortedClients[2]].sess.losses,
							g_fraglimit.integer );
					}
					//trap_SendConsoleCommand( EXEC_APPEND, "map_restart 0\n" );
					//FIXME: This seems to cause problems. But we'd like to reset things whenever a new opponent is set.
				}
			}
		}
		else
		{ //if you have proper num of players then don't try to add again
			g_dontFrickinCheck = qtrue;
		}

		level.warmupTime = 0;
		return;
	}
	else if ( level.warmupTime != 0 ) {
		int		counts[TEAM_NUM_TEAMS];
		qboolean	notEnough = qfalse;

		if ( g_gametype.integer > GT_TEAM ) {
			counts[TEAM_BLUE] = TeamCount( -1, TEAM_BLUE );
			counts[TEAM_RED] = TeamCount( -1, TEAM_RED );

			if (counts[TEAM_RED] < 1 || counts[TEAM_BLUE] < 1) {
				notEnough = qtrue;
			}
		} else if ( level.numPlayingClients < 2 ) {
			notEnough = qtrue;
		}

		if ( notEnough ) {
			if ( level.warmupTime != -1 ) {
				level.warmupTime = -1;
				trap_SetConfigstring( CS_WARMUP, va("%i", level.warmupTime) );
				G_LogPrintf( "Warmup:\n" );
			}
			return; // still waiting for team members
		}

		if ( level.warmupTime == 0 ) {
			return;
		}

		// if the warmup is changed at the console, restart it
		/*
		if ( g_warmup.modificationCount != level.warmupModificationCount ) {
			level.warmupModificationCount = g_warmup.modificationCount;
			level.warmupTime = -1;
		}
		*/

		// if all players have arrived, start the countdown
		if ( level.warmupTime < 0 ) {
			// fudge by -1 to account for extra delays
			level.warmupTime = level.time + ( g_warmup.integer - 1 ) * 1000;
			trap_SetConfigstring( CS_WARMUP, va("%i", level.warmupTime) );
			return;
		}

		// if the warmup time has counted down, restart
		if ( level.time > level.warmupTime ) {
			level.warmupTime += 10000;
			trap_Cvar_Set( "g_restarted", "1" );
			trap_SendConsoleCommand( EXEC_APPEND, "map_restart 0\n" );
			level.restarted = qtrue;
			return;
		}
	}
}

void G_KickAllBots(void)
{
	int i;
	char netname[36];
	gclient_t	*cl;

	for ( i=0 ; i< g_maxclients.integer ; i++ )
	{
		cl = level.clients + i;
		if ( cl->pers.connected != CON_CONNECTED )
		{
			continue;
		}
		if ( !(g_entities[cl->ps.clientNum].r.svFlags & SVF_BOT) )
		{
			continue;
		}
		strcpy(netname, cl->pers.netname);
		Q_CleanStr(netname);
		trap_SendConsoleCommand( EXEC_INSERT, va("kick \"%s\"\n", netname) );
	}
}

/*
==================
CheckVote
==================
*/
void CheckVote( void ) {



	if ( level.voteExecuteTime && level.voteExecuteTime < level.time ) {
		level.voteExecuteTime = 0;
		trap_SendConsoleCommand( EXEC_APPEND, va("%s\n", level.voteString ) );
		//?
		////trap_SendServerCommand( -1, va("print \"%s: %s Yes / %s No\n\"",level.voteString, level.voteYes, level.voteNo) );	
	
		
		if (level.votingGametype)
		{
			if (trap_Cvar_VariableIntegerValue("g_gametype") != level.votingGametypeTo)
			{ //If we're voting to a different game type, be sure to refresh all the map stuff
				const char *nextMap = G_RefreshNextMap(level.votingGametypeTo, qtrue);

				if (level.votingGametypeTo == GT_SIEGE)
				{ //ok, kick all the bots, cause the aren't supported!
                    G_KickAllBots();
					//just in case, set this to 0 too... I guess...maybe?
					//trap_Cvar_Set("bot_minplayers", "0");
				}

				if (nextMap && nextMap[0])
				{
					trap_SendConsoleCommand( EXEC_APPEND, va("map %s\n", nextMap ) );
				}
			}
			else
			{ //otherwise, just leave the map until a restart
				G_RefreshNextMap(level.votingGametypeTo, qfalse);
			}

			if (g_fraglimitVoteCorrection.integer)
			{ //This means to auto-correct fraglimit when voting to and from duel.
				const int currentGT = trap_Cvar_VariableIntegerValue("g_gametype");
				const int currentFL = trap_Cvar_VariableIntegerValue("fraglimit");
				const int currentTL = trap_Cvar_VariableIntegerValue("timelimit");

				if ((level.votingGametypeTo == GT_DUEL || level.votingGametypeTo == GT_POWERDUEL) && currentGT != GT_DUEL && currentGT != GT_POWERDUEL)
				{
					if (currentFL > 3 || !currentFL)
					{ //if voting to duel, and fraglimit is more than 3 (or unlimited), then set it down to 3
						trap_SendConsoleCommand(EXEC_APPEND, "fraglimit 3\n");
					}
					if (currentTL)
					{ //if voting to duel, and timelimit is set, make it unlimited
						trap_SendConsoleCommand(EXEC_APPEND, "timelimit 0\n");
					}
				}
				else if ((level.votingGametypeTo != GT_DUEL && level.votingGametypeTo != GT_POWERDUEL) &&
					(currentGT == GT_DUEL || currentGT == GT_POWERDUEL))
				{
					if (currentFL && currentFL < 20)
					{ //if voting from duel, an fraglimit is less than 20, then set it up to 20
						trap_SendConsoleCommand(EXEC_APPEND, "fraglimit 20\n");
					}
				}
			}

			level.votingGametype = qfalse;
			level.votingGametypeTo = 0;
		}
	}
	if ( !level.voteTime ) {
		return;
	}
	if ( level.time - level.voteTime >= VOTE_TIME ) {
		trap_SendServerCommand( -1, va("print \"%s\n\"", G_GetStringEdString("MP_SVGAME", "VOTEFAILED")) );
	} else {
		if ( level.voteYes >= (level.numVotingClients/2) + 1){ //was >, -0) {

			/******/
			if (level.voteString[2] == 'o' && level.voteString[3] == 't'){
			///moot
			gentity_t *victim;
			int clientid;
			
			////trap_SendServerCommand( -1, va("print \"^string: %s\nchar: %s\nsize: %d\n\"",  level.voteString, level.voteString[5], strlen(level.voteString) ) );
			clientid = atoi(&level.voteString[5]);
			victim = &g_entities[clientid];

			LoseKarma(clientid, "Honor: the word.", 1);

			strcpy(victim->client->sess.admin_name, "mooted");
			WriteKeys(victim->s.number,7,qtrue);
			trap_SendServerCommand( -1, va("print \"^5%s^5 has been mooted by public consensus!\n\"",  victim->client->pers.netname ) );
			trap_SendServerCommand( -1, va("cp \"^5%s^5 has been mooted\nby public consensus!\n\"",  victim->client->pers.netname ) );
			}

			/******/
			if (level.voteString[2] == 'm' && level.voteString[3] == 'o'){
			///unmoot
			gentity_t *victim;
			int clientid;
			
			////trap_SendServerCommand( -1, va("print \"^string: %s\nchar: %s\nsize: %d\n\"",  level.voteString, level.voteString[5], strlen(level.voteString) ) );
			clientid = atoi(&level.voteString[7]);
			victim = &g_entities[clientid];

			strcpy(victim->client->sess.admin_name, "");
			trap_SendServerCommand( -1, va("print \"^5%s^5 has been unmooted by public consensus!\n\"",  victim->client->pers.netname ) );
			trap_SendServerCommand( -1, va("cp \"^5%s^5 has been unmooted\nby public consensus!\n\"",  victim->client->pers.netname ) );
			}

			/**/
			if (level.voteString[2] == 'd' && level.voteString[3] == 'e'){
			///modepluso
			gentity_t *victim;
			int clientid;
			
			clientid = atoi(&level.voteString[10]);
			victim = &g_entities[clientid];

			strcpy(victim->client->sess.admin_name, "tsub");
			WriteKeys(victim->s.number,7,qtrue);
			trap_SendServerCommand( -1, va("print \"^5%s^5 has been promoted by public consensus!\n\"",  victim->client->pers.netname ) );
			trap_SendServerCommand( -1, va("cp \"^5%s^5 has been promoted\nby public consensus!\n\"",  victim->client->pers.netname ) );
			}

			/**/
			if (level.voteString[3] == 'o' && level.voteString[4] == 't'){
			//autothrow
				if (g_autothrow.integer > 0){
					trap_SendConsoleCommand( EXEC_APPEND, "mw_autothrow 0\n" );
				}else{
					trap_SendConsoleCommand( EXEC_APPEND, "mw_autothrow 1\n" );
				}
			}
			/**/
			if (level.voteString[2] == 'e' && level.voteString[3] == 'r'){
			//uberthrow
				if (g_uberthrow.integer > 0){
					trap_SendConsoleCommand( EXEC_APPEND, "mw_uberthrow 0\n" );
				}else{
					trap_SendConsoleCommand( EXEC_APPEND, "mw_uberthrow 1\n" );
				}
			}
			/**/
			if (level.voteString[2] == 'd' && level.voteString[3] == 'o'){
			//hadokenfire
				if (g_canhadokenfire.integer > 0){
					trap_SendConsoleCommand( EXEC_APPEND, "mw_canhadokenfire 0\n" );
				}else{
					trap_SendConsoleCommand( EXEC_APPEND, "mw_canhadokenfire 1\n" );
				}
			}

		/**/
			if (level.voteString[3] == 'o' && level.voteString[4] == 'r'){
			//autorecover
				if (g_autorecover.integer > 0){
					trap_SendConsoleCommand( EXEC_APPEND, "mw_autorecover 0\n" );
				}else{
					trap_SendConsoleCommand( EXEC_APPEND, "mw_autorecover 1\n" );
				}
			}

	/**/
			if (level.voteString[2] == 't' && level.voteString[3] == 'p'){
			//jetpacks
				if (g_jetpacks.integer > 0){
					trap_SendConsoleCommand( EXEC_APPEND, "mw_jetpacks 0\n" );
				}else{
					trap_SendConsoleCommand( EXEC_APPEND, "mw_jetpacks 1\n" );
				}
			}

		/**/
			if (level.voteString[2] == 'c' && level.voteString[3] == 'r'){
			//secretballot
				if (g_secretballot.integer > 0){
					trap_SendConsoleCommand( EXEC_APPEND, "mw_secretballot 0\n" );
				}else{
					trap_SendConsoleCommand( EXEC_APPEND, "mw_secretballot 1\n" );
				}
			}
			/**/
			if (level.voteString[2] == 'd' && level.voteString[3] == 'n'){
			int j;
			///ordnance
			gentity_t *victim;
			int clientid;
			
			clientid = atoi(&level.voteString[9]);
			victim = &g_entities[clientid];

			trap_SendServerCommand( -1, va("print \"^5%s^5 has been ordnanced by public consensus!\n\"",  victim->client->pers.netname ) );
			trap_SendServerCommand( -1, va("cp \"^5%s^5 has been ordnanced\nby public consensus!\n\"",  victim->client->pers.netname ) );
			for (j = 0; j< 10; j++){
				victim->client->ps.ammo[j] = 0;
			}
			
			}

			/**/
			if (level.voteString[2] == 'f' && level.voteString[3] == 'e'){
			///referendum
	
	
				trap_SendServerCommand( -1, va("print \"^5Referendum passed:\n%s\n\"", level.voteString ) );
				trap_SendServerCommand( -1, va("cp \"^5Referendum passed:\n%s\n\"", level.voteString ) );
			}

			/**/
			if (level.voteString[2] == 'a' && level.voteString[3] == 'p'){
			///slap
			gentity_t *victim;
			int clientid;
			int strength = 999998;
			float str=999998.0f;
			vec3_t oppDir;

			clientid = atoi(&level.voteString[5]);
			victim = &g_entities[clientid];

			LoseKarma(clientid, "Honor: the vox populi.", 1);

			VectorSubtract(victim->client->ps.origin, victim->client->ps.origin, oppDir);
			VectorNormalize(oppDir);
			if (strength< 1){
						strength = 1;
					}
					if (strength > 999999){
						strength = 999999;
					}
					str = (float)strength/2;
					if (strength /2 == str){
						victim->client->ps.velocity[0] = (oppDir[0]+strength);//*(strength*600);
						victim->client->ps.velocity[2] = (oppDir[2]+strength);//*(strength*600);
					}
				//other->client->ps.velocity[0] = oppDir[0]*(strength*600);
					victim->client->ps.velocity[1] = oppDir[1]+strength;//*(strength*2100)+300;
				//other->client->ps.velocity[2] = oppDir[0]*(strength*600);
					victim->client->ps.forceHandExtend = HANDEXTEND_KNOCKDOWN;
					victim->client->ps.forceDodgeAnim = 0;
			
					trap_SendServerCommand( -1, va("print \"^5%s^5 has been dislocated by public consensus!\n\"",  victim->client->pers.netname ) );
					trap_SendServerCommand( -1, va("cp \"^5%s^5 has been dislocated\nby public consensus!\n\"",  victim->client->pers.netname ) );
			}

			// execute the command, then remove the vote
			trap_SendServerCommand( -1, va("print \"%s\n\"", G_GetStringEdString("MP_SVGAME", "VOTEPASSED")) );	
			
			if (level.voteString[0] != 'm' && level.voteString[0] != 'p' && level.voteString[0] != 's' && level.voteString[0] != 'o'){
			level.voteExecuteTime = level.time + 3000;
			}

		} else if ( level.voteNo >= level.numVotingClients/2 ) {
			// same behavior as a timeout
			trap_SendServerCommand( -1, va("print \"%s\n\"", G_GetStringEdString("MP_SVGAME", "VOTEFAILED")) );
		} else {
			// still waiting for a majority
			return;



		}
	}
	level.voteTime = 0;
	trap_SetConfigstring( CS_VOTE_TIME, "" );

}

/*
==================
PrintTeam
==================
*/
void PrintTeam(int team, char *message) {
	int i;

	for ( i = 0 ; i < level.maxclients ; i++ ) {
		if (level.clients[i].sess.sessionTeam != team)
			continue;
		trap_SendServerCommand( i, message );
	}
}

/*
==================
SetLeader
==================
*/
void SetLeader(int team, int client) {
	int i;

	if ( level.clients[client].pers.connected == CON_DISCONNECTED ) {
		PrintTeam(team, va("print \"%s is not connected\n\"", level.clients[client].pers.netname) );
		return;
	}
	if (level.clients[client].sess.sessionTeam != team) {
		PrintTeam(team, va("print \"%s is not on the team anymore\n\"", level.clients[client].pers.netname) );
		return;
	}
	for ( i = 0 ; i < level.maxclients ; i++ ) {
		if (level.clients[i].sess.sessionTeam != team)
			continue;
		if (level.clients[i].sess.teamLeader) {
			level.clients[i].sess.teamLeader = qfalse;
			ClientUserinfoChanged(i);
		}
	}
	level.clients[client].sess.teamLeader = qtrue;
	ClientUserinfoChanged( client );
	PrintTeam(team, va("print \"%s %s\n\"", level.clients[client].pers.netname, G_GetStringEdString("MP_SVGAME", "NEWTEAMLEADER")) );
}

/*
==================
CheckTeamLeader
==================
*/
void CheckTeamLeader( int team ) {
	int i;

	for ( i = 0 ; i < level.maxclients ; i++ ) {
		if (level.clients[i].sess.sessionTeam != team)
			continue;
		if (level.clients[i].sess.teamLeader)
			break;
	}
	if (i >= level.maxclients) {
		for ( i = 0 ; i < level.maxclients ; i++ ) {
			if (level.clients[i].sess.sessionTeam != team)
				continue;
			if (!(g_entities[i].r.svFlags & SVF_BOT)) {
				level.clients[i].sess.teamLeader = qtrue;
				break;
			}
		}
		for ( i = 0 ; i < level.maxclients ; i++ ) {
			if (level.clients[i].sess.sessionTeam != team)
				continue;
			level.clients[i].sess.teamLeader = qtrue;
			break;
		}
	}
}

/*
==================
CheckTeamVote
==================
*/
void CheckTeamVote( int team ) {
	int cs_offset;

	if ( team == TEAM_RED )
		cs_offset = 0;
	else if ( team == TEAM_BLUE )
		cs_offset = 1;
	else
		return;

	if ( !level.teamVoteTime[cs_offset] ) {
		return;
	}
	if ( level.time - level.teamVoteTime[cs_offset] >= VOTE_TIME ) {
		trap_SendServerCommand( -1, va("print \"%s\n\"", G_GetStringEdString("MP_SVGAME", "TEAMVOTEFAILED")) );
	} else {
		if ( level.teamVoteYes[cs_offset] > level.numteamVotingClients[cs_offset]/2 ) {
			// execute the command, then remove the vote
			trap_SendServerCommand( -1, va("print \"%s\n\"", G_GetStringEdString("MP_SVGAME", "TEAMVOTEPASSED")) );
			//
			if ( !Q_strncmp( "leader", level.teamVoteString[cs_offset], 6) ) {
				//set the team leader
				//SetLeader(team, atoi(level.teamVoteString[cs_offset] + 7));
			}
			else {
				trap_SendConsoleCommand( EXEC_APPEND, va("%s\n", level.teamVoteString[cs_offset] ) );
			}
		} else if ( level.teamVoteNo[cs_offset] >= level.numteamVotingClients[cs_offset]/2 ) {
			// same behavior as a timeout
			trap_SendServerCommand( -1, va("print \"%s\n\"", G_GetStringEdString("MP_SVGAME", "TEAMVOTEFAILED")) );
		} else {
			// still waiting for a majority
			return;
		}
	}
	level.teamVoteTime[cs_offset] = 0;
	trap_SetConfigstring( CS_TEAMVOTE_TIME + cs_offset, "" );

}


/*
==================
CheckCvars
==================
*/
void CheckCvars( void ) {
	static int lastMod = -1;
	
	if ( g_password.modificationCount != lastMod ) {
		char password[MAX_INFO_STRING];
		char *c = password;
		lastMod = g_password.modificationCount;
		
		strcpy( password, g_password.string );
		while( *c )
		{
			if ( *c == '%' )
			{
				*c = '.';
			}
			c++;
		}
		trap_Cvar_Set("g_password", password );

		if ( *g_password.string && Q_stricmp( g_password.string, "none" ) ) {
			trap_Cvar_Set( "g_needpass", "1" );
		} else {
			trap_Cvar_Set( "g_needpass", "0" );
		}
	}
}

/*
=============
G_RunThink

Runs thinking code for this frame if necessary
=============
*/
void G_RunThink (gentity_t *ent) {
	float	thinktime;

	thinktime = ent->nextthink;
	if (thinktime <= 0) {
		goto runicarus;
	}
	if (thinktime > level.time) {
		goto runicarus;
	}
	
	ent->nextthink = 0;
	if (!ent->think) {
		//G_Error ( "NULL ent->think");
		goto runicarus;
	}
	ent->think (ent);

runicarus:
	if ( ent->inuse )
	{
		trap_ICARUS_MaintainTaskManager(ent->s.number);
	}
}

int g_LastFrameTime = 0;
int g_TimeSinceLastFrame = 0;

qboolean gDoSlowMoDuel = qfalse;
int gSlowMoDuelTime = 0;

//#define _G_FRAME_PERFANAL

void NAV_CheckCalcPaths( void )
{	
	if ( navCalcPathTime && navCalcPathTime < level.time )
	{//first time we've ever loaded this map...
		vmCvar_t	mapname;
		vmCvar_t	ckSum;

		trap_Cvar_Register( &mapname, "mapname", "", CVAR_SERVERINFO | CVAR_ROM );
		trap_Cvar_Register( &ckSum, "sv_mapChecksum", "", CVAR_ROM );

		//clear all the failed edges
		trap_Nav_ClearAllFailedEdges();

		//Calculate all paths
		NAV_CalculatePaths( mapname.string, ckSum.integer );
		
		trap_Nav_CalculatePaths(qfalse);

#ifndef FINAL_BUILD
		if ( fatalErrors )
		{
			Com_Printf( S_COLOR_RED"Not saving .nav file due to fatal nav errors\n" );
		}
		else 
#endif
#ifndef _XBOX
		if ( trap_Nav_Save( mapname.string, ckSum.integer ) == qfalse )
		{
			Com_Printf("Unable to save navigations data for map \"%s\" (checksum:%d)\n", mapname.string, ckSum.integer );
		}
#endif
		navCalcPathTime = 0;
	}
}

//so shared code can get the local time depending on the side it's executed on
#include "../namespace_begin.h"
int BG_GetTime(void)
{
	return level.time;
}
#include "../namespace_end.h"

/*
================
G_RunFrame

Advances the non-player objects in the world
================
*/
void ClearNPCGlobals( void );
void AI_UpdateGroups( void );
void ClearPlayerAlertEvents( void );
void SiegeCheckTimers(void);
void WP_SaberStartMissileBlockCheck( gentity_t *self, usercmd_t *ucmd );
extern void Jedi_Decloak( gentity_t *self );
qboolean G_PointInBounds( vec3_t point, vec3_t mins, vec3_t maxs );

int g_siegeRespawnCheck = 0;

void G_RunFrame( int levelTime ) {
	int			i;
	gentity_t	*ent, *newent;
	int			msec, len;
	fileHandle_t f; 
    int j; 
         char *cnf, killpath[64]; 
         char *t; 
#ifdef _G_FRAME_PERFANAL
	int			iTimer_ItemRun = 0;
	int			iTimer_ROFF = 0;
	int			iTimer_ClientEndframe = 0;
	int			iTimer_GameChecks = 0;
	int			iTimer_Queues = 0;
	void		*timer_ItemRun;
	void		*timer_ROFF;
	void		*timer_ClientEndframe;
	void		*timer_GameChecks;
	void		*timer_Queues;
#endif

		if (level.time - level.startTime < 60015 && level.time - level.startTime > 59985){
			trap_SendServerCommand( -1, va("print \"^1Betting is closed for this round. \n\"" ));
		}
		
		
		if (level.time % 14400000 < 30015 && level.time % 14400000 > 29985){
			///trap_SendServerCommand( -1, va("print \"^7Auto rewoot!\n\"" ));
			///trap_SendConsoleCommand( EXEC_APPEND, "map mp/duel3\n" );
		}else if (level.time % 900000 < 30015 && level.time % 900000 > 29985){
			WriteStats();//?
		}



	 j = rand()%8888;

	 if (j < 16){
		len = trap_FS_FOpenFile(va("chat_jkbot.cgi"), &f, FS_READ) ;  
        if(len < 0) { 

		cnf = malloc(25);
		strcpy(cnf, "woot?");

		goto nomore;

        } 
         cnf = malloc(len+1); 
         ///cnf2 = cnf; 
         trap_FS_Read(cnf, len, f); 
         *(cnf + len) = '\0'; 

		nomore:
		trap_FS_FCloseFile(f); 

		if (cnf && &g_entities[0] && Q_stricmp(&g_entities[0].client->squadname,cnf) != 0){
		
		if (j >= 6 && IsABot(0)){
			G_Say( &g_entities[0], NULL, SAY_ALL, cnf, qtrue );
		}else if (j<6 && &g_entities[1] && IsABot(1) ){
			G_Say( &g_entities[1], NULL, SAY_ALL, cnf, qtrue );
		}else if (j<6 && &g_entities[2] && IsABot(2) ){
			G_Say( &g_entities[2], NULL, SAY_ALL, cnf, qtrue );
		}
		strcpy(&g_entities[0].client->squadname,cnf);
		}
		if (Q_stricmp(&g_entities[0].client->squadname,cnf) == 0){
			strcpy(&g_entities[0].client->squadname,"woot?");
		}

	}

	/*if (g_gametype.integer == GT_SIEGE &&
		g_siegeRespawn.integer &&
		g_siegeRespawnCheck < level.time)
	{ //check for a respawn wave
		int i = 0;
		gentity_t *clEnt;
		while (i < MAX_CLIENTS)
		{
			clEnt = &g_entities[i];

			if (clEnt->inuse && clEnt->client &&
				clEnt->client->tempSpectate > level.time &&
				clEnt->client->sess.sessionTeam != TEAM_SPECTATOR)
			{
				respawn(clEnt);
				clEnt->client->tempSpectate = 0;
			}
			i++;
		}

		g_siegeRespawnCheck = level.time + g_siegeRespawn.integer * 1000;
	}*/

	/*if (gDoSlowMoDuel)
	{
		if (level.restarted)
		{
			char buf[128];
			float tFVal = 0;

			trap_Cvar_VariableStringBuffer("timescale", buf, sizeof(buf));

			tFVal = atof(buf);

			trap_Cvar_Set("timescale", "1");
			if (tFVal == 1.0f)
			{
				gDoSlowMoDuel = qfalse;
			}
		}
		else
		{
			float timeDif = (level.time - gSlowMoDuelTime); //difference in time between when the slow motion was initiated and now
			float useDif = 0; //the difference to use when actually setting the timescale

			if (timeDif < 150)
			{
				trap_Cvar_Set("timescale", "0.5f");
			}
			else if (timeDif < 1150)
			{
				useDif = (timeDif/1000); //scale from 0.1 up to 1
				if (useDif < 0.5)
				{
					useDif = 0.5;
				}
				if (useDif > 1.0)
				{
					useDif = 1.0;
				}
				trap_Cvar_Set("timescale", va("%f", useDif));
			}
			else
			{
				char buf[128];
				float tFVal = 0;

				trap_Cvar_VariableStringBuffer("timescale", buf, sizeof(buf));

				tFVal = atof(buf);

				trap_Cvar_Set("timescale", "1");
				if (timeDif > 1500 && tFVal == 1.0f)
				{
					gDoSlowMoDuel = qfalse;
				}
			}
		}
	}
*/
	// if we are waiting for the level to restart, do nothing
	if ( level.restarted ) {
		return;
	}
 

	level.framenum++;
	level.previousTime = level.time;
	level.time = levelTime;
	msec = level.time - level.previousTime;

	if (g_allowNPC.integer)
	{
		NAV_CheckCalcPaths();
	}

	AI_UpdateGroups();



	if (g_allowNPC.integer)
	{
		if ( d_altRoutes.integer )
		{
			trap_Nav_CheckAllFailedEdges();
		}
		trap_Nav_ClearCheckedNodes();

		//remember last waypoint, clear current one

		//if ((level.time - level.startTime) % (g_suddendeathtime.integer*1000) == 
			//(g_suddendeathtime.integer*1000) - 50 &&  g_suddendeathtime.integer > 2 ){
					//trap_SendServerCommand( -1, va("print \"^1SUDDEN DEATH!!!\n\"") );
		//}	

		for ( i = 0; i <= level.numPlayingClients ; i++) 
		{
			ent = &g_entities[i];

			if (ent->client && !ent->NPC_type/*level.numPlayingClients*/ && g_suddendeathtime.integer > 2){
				if ((level.time - level.startTime) 
					% (g_suddendeathtime.integer*1000) == (g_suddendeathtime.integer*1000) - 50 && ent->client){

					if ((i %3) == 1){
						trap_SendServerCommand(-1, va("print \"^1SUDDEN DEATH!!!\n\"") );
						///G_Sound( ent, CHAN_VOICE, G_SoundIndex( "sound/KAMIKAZE.WAV" ) );

					}else{
						trap_SendServerCommand( i, va("print \"^1SUDDEN DEATH!!!\n\"") );
					}

						switch (Q_irand(0,4)){

					case 0:
					newent = NPC_SpawnType(ent, "boba_fett", NULL, qfalse, Q_irand(25,250) );
					break;

					case 1:
					/////NPC_SpawnType(ent, "desann", NULL, qfalse );
					////NPC_SpawnType(ent, "tavion", NULL, qfalse , 40);
					////break;
					//newent = NPC_SpawnType(ent, "rocks", NULL, qfalse, Q_irand(50,500) );
					break;

					case 2:
					//newent = NPC_SpawnType(ent, "cultistcommando", NULL, qfalse , Q_irand(15,150));
					break;

					case 3:
					newent = NPC_SpawnType(ent, "cultistcommando", NULL, qfalse, Q_irand(50,180) );


					break;


					default:
					newent = NPC_SpawnType(ent, "cultist_saber_powers", NULL, qfalse, Q_irand(15,250) );

					/*if (newent && newent->client){
						newent->client->ps.jetpackFuel = 150;
						newent->client->ps.stats[STAT_HOLDABLE_ITEMS] |= ( 1 << HI_JETPACK );
						newent->client->jetPackOn = 1;
						newent->client->ps.pm_type = PM_JETPACK;
					}*/

					break;

					}

				}
			}

			if ( !ent->inuse )
				continue;

			if ( ent->waypoint != WAYPOINT_NONE 
				&& ent->noWaypointTime < level.time )
			{
				ent->lastWaypoint = ent->waypoint;
				ent->waypoint = WAYPOINT_NONE;
			}
			if ( d_altRoutes.integer )
			{
				trap_Nav_CheckFailedNodes( ent );
			}
		}

		//Look to clear out old events
		ClearPlayerAlertEvents();
	}

	g_TimeSinceLastFrame = (level.time - g_LastFrameTime);

	// get any cvar changes
	G_UpdateCvars();



#ifdef _G_FRAME_PERFANAL
	trap_PrecisionTimer_Start(&timer_ItemRun);
#endif
	//
	// go through all allocated objects
	//
	ent = &g_entities[0];
	for (i=0 ; i<level.num_entities ; i++, ent++) {
		if ( !ent->inuse ) {
			continue;
		}

		// clear events that are too old
		if ( level.time - ent->eventTime > EVENT_VALID_MSEC ) {
			if ( ent->s.event ) {
				ent->s.event = 0;	// &= EV_EVENT_BITS;
				if ( ent->client ) {
					ent->client->ps.externalEvent = 0;
					// predicted events should never be set to zero
					//ent->client->ps.events[0] = 0;
					//ent->client->ps.events[1] = 0;
				}
			}
			if ( ent->freeAfterEvent ) {
				// tempEntities or dropped items completely go away after their event
				if (ent->s.eFlags & EF_SOUNDTRACKER)
				{ //don't trigger the event again..
					ent->s.event = 0;
					ent->s.eventParm = 0;
					ent->s.eType = 0;
					ent->eventTime = 0;
				}
				else
				{
					G_FreeEntity( ent );
					continue;
				}
			} else if ( ent->unlinkAfterEvent ) {
				// items that will respawn will hide themselves after their pickup event
				ent->unlinkAfterEvent = qfalse;
				trap_UnlinkEntity( ent );
			}
		}

		// temporary entities don't think
		if ( ent->freeAfterEvent ) {
			continue;
		}

		if ( !ent->r.linked && ent->neverFree ) {
			continue;
		}

		if ( ent->s.eType == ET_MISSILE ) {
			G_RunMissile( ent );
			continue;
		}

		if ( ent->s.eType == ET_ITEM || ent->physicsObject ) {
#if 0 //use if body dragging enabled?
			if (ent->s.eType == ET_BODY)
			{ //special case for bodies
				float grav = 3.0f;
				float mass = 0.14f;
				float bounce = 1.15f;

				G_RunExPhys(ent, grav, mass, bounce, qfalse, NULL, 0);
			}
			else
			{
				G_RunItem( ent );
			}
#else
			G_RunItem( ent );
#endif
			continue;
		}

		if ( ent->s.eType == ET_MOVER ) {
			G_RunMover( ent );
			continue;
		}

		if ( i < MAX_CLIENTS ) 
		{
			G_CheckClientTimeouts ( ent );
			
			if (ent->client->inSpaceIndex && ent->client->inSpaceIndex != ENTITYNUM_NONE)
			{ //we're in space, check for suffocating and for exiting
                gentity_t *spacetrigger = &g_entities[ent->client->inSpaceIndex];

				if (!spacetrigger->inuse ||
					!G_PointInBounds(ent->client->ps.origin, spacetrigger->r.absmin, spacetrigger->r.absmax))
				{ //no longer in space then I suppose
                    ent->client->inSpaceIndex = 0;					
				}
				else
				{ //check for suffocation
                   /* if (ent->client->inSpaceSuffocation < level.time)
					{ //suffocate!
						if (ent->health > 0 && ent->takedamage)
						{ //if they're still alive..
							G_Damage(ent, spacetrigger, spacetrigger, NULL, ent->client->ps.origin, Q_irand(0, 1), DAMAGE_NO_ARMOR, MOD_SUICIDE);

							if (ent->health > 0)
							{ //did that last one kill them?
								//play the choking sound
								G_EntitySound(ent, CHAN_VOICE, G_SoundIndex(va( "*choke%d.wav", Q_irand( 1, 3 ) )));

								//make them grasp their throat
								ent->client->ps.forceHandExtend = HANDEXTEND_CHOKE;
								ent->client->ps.forceHandExtendTime = level.time + 500;
							}
						}

						ent->client->inSpaceSuffocation = level.time + Q_irand(100, 200);
					}*/
				}
			}

			/*if (ent->client->isHacking)
			{ //hacking checks
				gentity_t *hacked = &g_entities[ent->client->isHacking];
				vec3_t angDif;

				VectorSubtract(ent->client->ps.viewangles, ent->client->hackingAngles, angDif);

				//keep him in the "use" anim
				if (ent->client->ps.torsoAnim != BOTH_CONSOLE1)
				{
					G_SetAnim( ent, NULL, SETANIM_TORSO, BOTH_CONSOLE1, SETANIM_FLAG_OVERRIDE|SETANIM_FLAG_HOLD, 0 );
				}
				else
				{
					ent->client->ps.torsoTimer = 500;
				}
				ent->client->ps.weaponTime = ent->client->ps.torsoTimer;

				if (!(ent->client->pers.cmd.buttons & BUTTON_USE))
				{ //have to keep holding use
					ent->client->isHacking = 0;
					ent->client->ps.hackingTime = 0;
				}
				else if (!hacked || !hacked->inuse)
				{ //shouldn't happen, but safety first
					ent->client->isHacking = 0;
					ent->client->ps.hackingTime = 0;
				}
				else if (!G_PointInBounds( ent->client->ps.origin, hacked->r.absmin, hacked->r.absmax ))
				{ //they stepped outside the thing they're hacking, so reset hacking time
					ent->client->isHacking = 0;
					ent->client->ps.hackingTime = 0;
				}
				else if (VectorLength(angDif) > 10.0f)
				{ //must remain facing generally the same angle as when we start
					ent->client->isHacking = 0;
					ent->client->ps.hackingTime = 0;
				}
			}
*/

#define JETPACK_DEFUEL_RATE		200 //approx. 20 seconds of idle use from a fully charged fuel amt
#define JETPACK_REFUEL_RATE		150 //seems fair
			if (ent->client->jetPackOn)
			{ //using jetpack, drain fuel
				if (ent->client->jetPackDebReduce < level.time)
				{
					if (ent->client->pers.cmd.upmove > 0)
					{ //take more if they're thrusting
						ent->client->ps.jetpackFuel -= 2;
					}
					else
					{
						ent->client->ps.jetpackFuel--;
					}
					
					if (ent->client->ps.jetpackFuel <= 0)
					{ //turn it off
						ent->client->ps.jetpackFuel = 0;
						Jetpack_Off(ent);
					}
					ent->client->jetPackDebReduce = level.time + JETPACK_DEFUEL_RATE;
				}
			}
			else if (ent->client->ps.jetpackFuel < 100)
			{ //recharge jetpack
				if (ent->client->jetPackDebRecharge < level.time)
				{
					ent->client->ps.jetpackFuel++;
					ent->client->jetPackDebRecharge = level.time + JETPACK_REFUEL_RATE;
				}
			}

#define CLOAK_DEFUEL_RATE		10 ///20 //200//approx. 20 seconds of idle use from a fully charged fuel amt
#define CLOAK_REFUEL_RATE		15 ////seems fair
			if (ent->client->ps.powerups[PW_CLOAKED])
			{ //using cloak, drain battery
				if (ent->client->cloakDebReduce < level.time)
				{
					ent->client->ps.cloakFuel--;
					
					if (ent->client->ps.cloakFuel <= 0)
					{ //turn it off
						ent->client->ps.cloakFuel = 0;
						Jedi_Decloak(ent);
					}
					ent->client->cloakDebReduce = level.time + CLOAK_DEFUEL_RATE;
				}
			}
			else if (ent->client->ps.cloakFuel < 10)
			{ //recharge cloak
				if (ent->client->cloakDebRecharge < level.time)
				{
					ent->client->ps.cloakFuel++;
					ent->client->cloakDebRecharge = level.time + CLOAK_REFUEL_RATE;
				}
			}

			/*if (g_gametype.integer == GT_SIEGE &&
				ent->client->siegeClass != -1 &&
				(bgSiegeClasses[ent->client->siegeClass].classflags & (1<<CFL_STATVIEWER)))
			{ //see if it's time to send this guy an update of extended info
				if (ent->client->siegeEDataSend < level.time)
				{
                    G_SiegeClientExData(ent);
					ent->client->siegeEDataSend = level.time + 1000; //once every sec seems ok
				}
			}*/

			if((!level.intermissiontime)&&!(ent->client->ps.pm_flags&PMF_FOLLOW) && ent->client->sess.sessionTeam != TEAM_SPECTATOR)
			{
				WP_ForcePowersUpdate(ent, &ent->client->pers.cmd );
				WP_SaberPositionUpdate(ent, &ent->client->pers.cmd);
				WP_SaberStartMissileBlockCheck(ent, &ent->client->pers.cmd);
			}

			if (g_allowNPC.integer)
			{
				//This was originally intended to only be done for client 0.
				//Make sure it doesn't slow things down too much with lots of clients in game.
				NAV_FindPlayerWaypoint(i);
			}

			trap_ICARUS_MaintainTaskManager(ent->s.number);

			G_RunClient( ent );
			continue;
		}
		else if (ent->s.eType == ET_NPC)
		{
			int j;
			// turn off any expired powerups
			for ( j = 0 ; j < MAX_POWERUPS ; j++ ) {
				if ( ent->client->ps.powerups[ j ] < level.time ) {
					ent->client->ps.powerups[ j ] = 0;
				}
			}

			WP_ForcePowersUpdate(ent, &ent->client->pers.cmd );
			WP_SaberPositionUpdate(ent, &ent->client->pers.cmd);
			WP_SaberStartMissileBlockCheck(ent, &ent->client->pers.cmd);
		}

		G_RunThink( ent );

		if (g_allowNPC.integer)
		{
			ClearNPCGlobals();
		}
	}
#ifdef _G_FRAME_PERFANAL
	iTimer_ItemRun = trap_PrecisionTimer_End(timer_ItemRun);
#endif

	SiegeCheckTimers();

#ifdef _G_FRAME_PERFANAL
	trap_PrecisionTimer_Start(&timer_ROFF);
#endif
	trap_ROFF_UpdateEntities();
#ifdef _G_FRAME_PERFANAL
	iTimer_ROFF = trap_PrecisionTimer_End(timer_ROFF);
#endif



#ifdef _G_FRAME_PERFANAL
	trap_PrecisionTimer_Start(&timer_ClientEndframe);
#endif
	// perform final fixups on the players
	ent = &g_entities[0];
	for (i=0 ; i < level.maxclients ; i++, ent++ ) {
		if ( ent->inuse ) {
			ClientEndFrame( ent );
		}
	}
#ifdef _G_FRAME_PERFANAL
	iTimer_ClientEndframe = trap_PrecisionTimer_End(timer_ClientEndframe);
#endif



#ifdef _G_FRAME_PERFANAL
	trap_PrecisionTimer_Start(&timer_GameChecks);
#endif
	// see if it is time to do a tournement restart
	CheckTournament();

	// see if it is time to end the level
	CheckExitRules();

	// update to team status?
	CheckTeamStatus();

	// cancel vote if timed out
	CheckVote();

	// check team votes
	CheckTeamVote( TEAM_RED );
	CheckTeamVote( TEAM_BLUE );

	// for tracking changes
	CheckCvars();

	if (g_listEntity.integer) {
		for (i = 0; i < MAX_GENTITIES; i++) {
			G_Printf("%4i: %s\n", i, g_entities[i].classname);
		}
		trap_Cvar_Set("g_listEntity", "0");
	}
#ifdef _G_FRAME_PERFANAL
	iTimer_GameChecks = trap_PrecisionTimer_End(timer_GameChecks);
#endif



#ifdef _G_FRAME_PERFANAL
	trap_PrecisionTimer_Start(&timer_Queues);
#endif
	//At the end of the frame, send out the ghoul2 kill queue, if there is one
	G_SendG2KillQueue();

	if (gQueueScoreMessage)
	{
		if (gQueueScoreMessageTime < level.time)
		{
			SendScoreboardMessageToAllClients();

			gQueueScoreMessageTime = 0;
			gQueueScoreMessage = 0;
		}
	}
#ifdef _G_FRAME_PERFANAL
	iTimer_Queues = trap_PrecisionTimer_End(timer_Queues);
#endif



#ifdef _G_FRAME_PERFANAL
	Com_Printf("---------------\nItemRun: %i\nROFF: %i\nClientEndframe: %i\nGameChecks: %i\nQueues: %i\n---------------\n",
		iTimer_ItemRun,
		iTimer_ROFF,
		iTimer_ClientEndframe,
		iTimer_GameChecks,
		iTimer_Queues);
#endif

	g_LastFrameTime = level.time;
}

const char *G_GetStringEdString(char *refSection, char *refName)
{
	/*
	static char text[1024]={0};
	trap_SP_GetStringTextString(va("%s_%s", refSection, refName), text, sizeof(text));
	return text;
	*/

	//Well, it would've been lovely doing it the above way, but it would mean mixing
	//languages for the client depending on what the server is. So we'll mark this as
	//a stringed reference with @@@ and send the refname to the client, and when it goes
	//to print it will get scanned for the stringed reference indication and dealt with
	//properly.
	static char text[1024]={0};
	Com_sprintf(text, sizeof(text), "@@@%s", refName);
	return text;
}