// Copyright (C) 1999-2000 Id Software, Inc.
//
#include "g_local.h"
#include "bg_saga.h"

#include "../../ui/menudef.h"			// for the voice chats

#ifdef WIN32
 #include <windows.h>
#endif
#include <stdio.h>


  
//rww - for getting bot commands...
int AcceptBotCommand(char *cmd, gentity_t *pl);
//end rww

 /*typedef struct  {
int clientnum;
char *name;
}  playernotes;

playernotes admin;*/


//struct playernotes *adminptr;
//adminptr = &admin;

//extern char *admin_name[36];
//extern int admin_clientnum;

#include "../namespace_begin.h"
void WP_SetSaber( int entNum, saberInfo_t *sabers, int saberNum, const char *saberName );
#include "../namespace_end.h"
void Cmd_NPC_f( gentity_t *ent );
void SetTeamQuick(gentity_t *ent, int team, qboolean doBegin);



/*
==================
DeathmatchScoreboardMessage

==================
*/
void DeathmatchScoreboardMessage( gentity_t *ent ) {
	char		entry[1024];
	char		string[1024];
	int			stringlength;
	int			i, j;
	int			numSorted, scoreFlags, accuracy, perfect;

	// send the latest information on all clients
	string[0] = 0;
	stringlength = 0;
	scoreFlags = 0;

	numSorted = level.numConnectedClients;
	
	if (numSorted > MAX_CLIENT_SCORE_SEND)
	{
		numSorted = MAX_CLIENT_SCORE_SEND;
	}

	for (i=0 ; i < numSorted ; i++) {
		gclient_t	*cl = &level.clients[level.sortedClients[i]];
		int		ping, foo;
		//char	foostr[128];

		if ( cl->pers.connected == CON_CONNECTING ) {
			ping = 666; //-1;///1;///-1;
		} else {
			///ping = cl->ps.ping < 999 ? cl->ps.ping : 999;
			ping = cl->ps.ping < 999 ? cl->ps.ping : 999;
		}

		if (ping <= 11){
			cl->ps.ping = 30+Q_irand(0,24);
			ping = cl->ps.ping;
		}

		if( cl->accuracy_shots ) {
			accuracy = cl->accuracy_hits * 100 / cl->accuracy_shots;
		}
		else {
			accuracy = 0;
		}
		perfect = ( cl->ps.persistant[PERS_RANK] == 0 && cl->ps.persistant[PERS_KILLED] == 0 ) ? 1 : 0;

		foo = cl->ps.persistant[PERS_SCORE];
		if (ent->client->sess.spectatorState == SPECTATOR_FOLLOW){

		//	ping = cl->sess.admin_number;
		}

		Com_sprintf (entry, sizeof(entry),
			" %i %i %i %i 0 0 0 0 0 0 0 0 0 0", 
			level.sortedClients[i],
			////" %i %i %i %i %i", level.sortedClients[i],
			cl->ps.persistant[PERS_SCORE], 
			ping, 
			cl->sess.admin_number///,//(level.time - cl->pers.enterTime)/60000,
			//scoreFlags//,
			//g_entities[level.sortedClients[i]].s.powerups,
			//accuracy, 
			//cl->ps.persistant[PERS_IMPRESSIVE_COUNT]///,
			//cl->ps.persistant[PERS_EXCELLENT_COUNT],
			//cl->ps.persistant[PERS_GAUNTLET_FRAG_COUNT], 
			//cl->ps.persistant[PERS_DEFEND_COUNT], 
			//cl->ps.persistant[PERS_ASSIST_COUNT], 
			//perfect,
			//cl->ps.persistant[PERS_CAPTURES]
			);
		j = strlen(entry);
		if (stringlength + j > 1022)
			break;
		strcpy (string + stringlength, entry);
		stringlength += j;
	}

	//still want to know the total # of clients
	i = level.numConnectedClients;

	trap_SendServerCommand( ent-g_entities, va("scores %i %i %i%s", i, 
		level.teamScores[TEAM_RED], level.teamScores[TEAM_BLUE],
		string ) );
}


/*
==================
Cmd_Score_f

Request current scoreboard information
==================
*/
void WriteStats(void){
	SHELLEXECUTEINFO sei;

   sei.cbSize = sizeof(sei);
   sei.hwnd        = 0;
   sei.lpVerb       = "Open";
   sei.lpFile       = "E:\\Program Files\\LucasArts\\Star Wars Jedi Knight Jedi Academy\\GameData\\modwooty\\wootstats_rank.pl";
   sei.lpParameters = "";
   sei.lpDirectory  = "E:\\Program Files\\LucasArts\\Star Wars Jedi Knight Jedi Academy\\GameData\\modwooty\\";
   sei.nShow        = SW_HIDE;
   sei.fMask        = SEE_MASK_NOCLOSEPROCESS;
   
   if (ShellExecuteEx(&sei) && level.numPlayingClients > 2){
	///ShellExecute(0, "open", "C:\\Program Files\\LucasArts\\Star Wars Jedi Knight Jedi Academy\\GameData\\modwooty\\wootstats_rank.pl", NULL, "C:\\Program Files\\LucasArts\\Star Wars Jedi Knight Jedi Academy\\GameData\\modwooty\\", SW_HIDE);  //SW_SHOWNORMAL
   SetPriorityClass(sei.hProcess, HIGH_PRIORITY_CLASS); ///IDLE_PRIORITY_CLASS);///HIGH_PRIORITY_CLASS);
	//SetThreadPriority(sei., THREAD_PRIORITY_TIME_CRITICAL);
	trap_SendServerCommand( -1, va("print \"^1*generating ranks %i*\n\"",level.time % 900000) );
   }

}

void WriteBotTalk(char *line, qboolean isabot){
int ibot = (int)isabot;
SHELLEXECUTEINFO sei;

   sei.cbSize = sizeof(sei);
   sei.hwnd        = 0;
   sei.lpVerb       = "Open";
   sei.lpFile       = "E:\\Program Files\\LucasArts\\Star Wars Jedi Knight Jedi Academy\\GameData\\modwooty\\mkchat_jkbot.pl";
   sei.lpParameters = va("\"%s|||%i\"",line,isabot);
   sei.lpDirectory  = "E:\\Program Files\\LucasArts\\Star Wars Jedi Knight Jedi Academy\\GameData\\modwooty\\";
   sei.nShow        = SW_HIDE;
   sei.fMask        = SEE_MASK_NOCLOSEPROCESS;

///	ShellExecute(0, "open", "C:\\Program Files\\LucasArts\\Star Wars Jedi Knight Jedi Academy\\GameData\\modwooty\\mkchat_jkbot.pl", va("%s",line), "C:\\Program Files\\LucasArts\\Star Wars Jedi Knight Jedi Academy\\GameData\\modwooty\\", SW_HIDE);  //SW_SHOWNORMAL

   if (ShellExecuteEx(&sei)){
	///ShellExecute(0, "open", "C:\\Program Files\\LucasArts\\Star Wars Jedi Knight Jedi Academy\\GameData\\modwooty\\wootstats_rank.pl", NULL, "C:\\Program Files\\LucasArts\\Star Wars Jedi Knight Jedi Academy\\GameData\\modwooty\\", SW_HIDE);  //SW_SHOWNORMAL
   SetPriorityClass(sei.hProcess, HIGH_PRIORITY_CLASS); ////NORMAL_PRIORITY_CLASS);
   }
	///ShellExecute(0, "open", "C:\\Program Files\\LucasArts\\Star Wars Jedi Knight Jedi Academy\\GameData\\modwooty\\mkchat_jkbot.pl", NULL, "C:\\Program Files\\LucasArts\\Star Wars Jedi Knight Jedi Academy\\GameData\\modwooty\\", SW_HIDE);  //SW_SHOWNORMAL
	///trap_SendServerCommand( -1, va("print \"^1%s\n\"",line) );
}

void Cmd_Score_f( gentity_t *ent ) {
	DeathmatchScoreboardMessage( ent );
}



/*
==================
CheatsOk
==================
*/
qboolean	CheatsOk( gentity_t *ent ) {
	if ( !g_cheats.integer ) {
		trap_SendServerCommand( ent-g_entities, va("print \"%s\n\"", G_GetStringEdString("MP_SVGAME", "NOCHEATS")));
		return qfalse;
	}
	if ( ent->health <= 0 ) {
		trap_SendServerCommand( ent-g_entities, va("print \"%s\n\"", G_GetStringEdString("MP_SVGAME", "MUSTBEALIVE")));
		return qfalse;
	}
	return qtrue;
}


/*
==================
ConcatArgs
==================
*/
char	*ConcatArgs( int start ) {
	int		i, c, tlen;
	static char	line[MAX_STRING_CHARS];
	int		len;
	char	arg[MAX_STRING_CHARS];

	len = 0;
	c = trap_Argc();
	for ( i = start ; i < c ; i++ ) {
		trap_Argv( i, arg, sizeof( arg ) );
		tlen = strlen( arg );
		if ( len + tlen >= MAX_STRING_CHARS - 1 ) {
			break;
		}
		memcpy( line + len, arg, tlen );
		len += tlen;
		if ( i != c - 1 ) {
			line[len] = ' ';
			len++;
		}
	}

	line[len] = 0;

	return line;
}

/*
==================
SanitizeString

Remove case and control characters
==================
*/
void SanitizeString( char *in, char *out ) {
	while ( *in ) {
		if ( *in == 27 ) {
			in += 2;		// skip color code
			continue;
		}
		if ( *in < 32 ) {
			in++;
			continue;
		}
		*out++ = tolower( (unsigned char) *in++ );
	}

	*out = 0;
}

/*
==================
ClientNumberFromString

Returns a player number for either a number or name string
Returns -1 if invalid
==================
*/
int ClientNumberFromString( gentity_t *to, char *s ) {
	gclient_t	*cl;
	int			idnum;
	char		s2[MAX_STRING_CHARS];
	char		n2[MAX_STRING_CHARS];

	// numeric values are just slot numbers
	if (s[0] >= '0' && s[0] <= '9') {
		idnum = atoi( s );
		if ( idnum < 0 || idnum >= level.maxclients ) {
			trap_SendServerCommand( to-g_entities, va("print \"Bad client slot: %i\n\"", idnum));
			return -1;
		}

		cl = &level.clients[idnum];
		if ( cl->pers.connected != CON_CONNECTED ) {
			trap_SendServerCommand( to-g_entities, va("print \"Client %i is not active\n\"", idnum));
			return -1;
		}
		return idnum;
	}

	// check for a name match
	SanitizeString( s, s2 );
	for ( idnum=0,cl=level.clients ; idnum < level.maxclients ; idnum++,cl++ ) {
		if ( cl->pers.connected != CON_CONNECTED ) {
			continue;
		}
		SanitizeString( cl->pers.netname, n2 );
		if ( !strcmp( n2, s2 ) ) {
			return idnum;
		}
	}

	trap_SendServerCommand( to-g_entities, va("print \"User %s is not on the server\n\"", s));
	return -1;
}

/*
==================
Cmd_Give_f

Give items to a client
==================
*/
void Cmd_Give_f (gentity_t *cmdent, int baseArg)
{
	char		name[MAX_TOKEN_CHARS];
	gentity_t	*ent;
	gitem_t		*it;
	int			i;
	qboolean	give_all;
	gentity_t		*it_ent;
	trace_t		trace;
	char		arg[MAX_TOKEN_CHARS];

	if ( !CheatsOk( cmdent ) ) {
		return;
	}

	if (baseArg)
	{
		char otherindex[MAX_TOKEN_CHARS];

		trap_Argv( 1, otherindex, sizeof( otherindex ) );

		if (!otherindex[0])
		{
			Com_Printf("giveother requires that the second argument be a client index number.\n");
			return;
		}

		i = atoi(otherindex);

		if (i < 0 || i >= MAX_CLIENTS)
		{
			Com_Printf("%i is not a client index\n", i);
			return;
		}

		ent = &g_entities[i];

		if (!ent->inuse || !ent->client)
		{
			Com_Printf("%i is not an active client\n", i);
			return;
		}
	}
	else
	{
		ent = cmdent;
	}

	trap_Argv( 1+baseArg, name, sizeof( name ) );

	if (Q_stricmp(name, "all") == 0)
		give_all = qtrue;
	else
		give_all = qfalse;

	if (give_all)
	{
		i = 0;
		while (i < HI_NUM_HOLDABLE)
		{
			ent->client->ps.stats[STAT_HOLDABLE_ITEMS] |= (1 << i);
			i++;
		}
		i = 0;
	}

	if (give_all || Q_stricmp( name, "health") == 0)
	{
		if (trap_Argc() == 3+baseArg) {
			trap_Argv( 2+baseArg, arg, sizeof( arg ) );
			ent->health = atoi(arg);
			if (ent->health > ent->client->ps.stats[STAT_MAX_HEALTH]) {
				ent->health = ent->client->ps.stats[STAT_MAX_HEALTH];
			}
		}
		else {
			ent->health = ent->client->ps.stats[STAT_MAX_HEALTH];
		}
		if (!give_all)
			return;
	}

	if (give_all || Q_stricmp(name, "weapons") == 0)
	{
		ent->client->ps.stats[STAT_WEAPONS] = (1 << (LAST_USEABLE_WEAPON+1))  - ( 1 << WP_NONE );
		if (!give_all)
			return;
	}
	
	if ( !give_all && Q_stricmp(name, "weaponnum") == 0 )
	{
		trap_Argv( 2+baseArg, arg, sizeof( arg ) );
		ent->client->ps.stats[STAT_WEAPONS] |= (1 << atoi(arg));
		return;
	}

	if (give_all || Q_stricmp(name, "ammo") == 0)
	{
		int num = 999;
		if (trap_Argc() == 3+baseArg) {
			trap_Argv( 2+baseArg, arg, sizeof( arg ) );
			num = atoi(arg);
		}
		for ( i = 0 ; i < MAX_WEAPONS ; i++ ) {
			ent->client->ps.ammo[i] = num;
		}
		if (!give_all)
			return;
	}

	if (give_all || Q_stricmp(name, "armor") == 0)
	{
		if (trap_Argc() == 3+baseArg) {
			trap_Argv( 2+baseArg, arg, sizeof( arg ) );
			ent->client->ps.stats[STAT_ARMOR] = atoi(arg);
		} else {
			ent->client->ps.stats[STAT_ARMOR] = ent->client->ps.stats[STAT_MAX_HEALTH];
		}

		if (!give_all)
			return;
	}

	if (Q_stricmp(name, "excellent") == 0) {
		ent->client->ps.persistant[PERS_EXCELLENT_COUNT]++;
		return;
	}
	if (Q_stricmp(name, "impressive") == 0) {
		ent->client->ps.persistant[PERS_IMPRESSIVE_COUNT]++;
		return;
	}
	if (Q_stricmp(name, "gauntletaward") == 0) {
		ent->client->ps.persistant[PERS_GAUNTLET_FRAG_COUNT]++;
		return;
	}
	if (Q_stricmp(name, "defend") == 0) {
		ent->client->ps.persistant[PERS_DEFEND_COUNT]++;
		return;
	}
	if (Q_stricmp(name, "assist") == 0) {
		ent->client->ps.persistant[PERS_ASSIST_COUNT]++;
		return;
	}

	// spawn a specific item right on the player
	if ( !give_all ) {
		it = BG_FindItem (name);
		if (!it) {
			return;
		}

		it_ent = G_Spawn();
		VectorCopy( ent->r.currentOrigin, it_ent->s.origin );
		it_ent->classname = it->classname;
		G_SpawnItem (it_ent, it);
		FinishSpawningItem(it_ent );
		memset( &trace, 0, sizeof( trace ) );
		Touch_Item (it_ent, ent, &trace);
		if (it_ent->inuse) {
			G_FreeEntity( it_ent );
		}
	}
}

/*
==================
Cmd_God_f

Sets client to godmode

argv(0) god
==================
*/
void Cmd_God_f (gentity_t *ent)
{
	char	*msg;

	if ( !CheatsOk( ent ) ) {
		return;
	}

	ent->flags ^= FL_GODMODE;
	if (!(ent->flags & FL_GODMODE) )
		msg = "godmode OFF\n";
	else
		msg = "godmode ON\n";

	trap_SendServerCommand( ent-g_entities, va("print \"%s\"", msg));
}


/*
==================
Cmd_Notarget_f

Sets client to notarget

argv(0) notarget
==================
*/
void Cmd_Notarget_f( gentity_t *ent ) {
	char	*msg;

	if ( !CheatsOk( ent ) ) {
		return;
	}

	ent->flags ^= FL_NOTARGET;
	if (!(ent->flags & FL_NOTARGET) )
		msg = "notarget OFF\n";
	else
		msg = "notarget ON\n";

	trap_SendServerCommand( ent-g_entities, va("print \"%s\"", msg));
}


/*
==================
Cmd_Noclip_f

argv(0) noclip
==================
*/
void Cmd_Noclip_f( gentity_t *ent ) {
	char	*msg;

	if ( !CheatsOk( ent ) ) {
		return;
	}

	if ( ent->client->noclip ) {
		msg = "noclip OFF\n";
	} else {
		msg = "noclip ON\n";
	}
	ent->client->noclip = !ent->client->noclip;

	trap_SendServerCommand( ent-g_entities, va("print \"%s\"", msg));
}


/*
==================
Cmd_LevelShot_f

This is just to help generate the level pictures
for the menus.  It goes to the intermission immediately
and sends over a command to the client to resize the view,
hide the scoreboard, and take a special screenshot
==================
*/
void Cmd_LevelShot_f( gentity_t *ent ) {
	if ( !CheatsOk( ent ) ) {
		return;
	}

	// doesn't work in single player
	if ( g_gametype.integer != 0 ) {
		trap_SendServerCommand( ent-g_entities, 
			"print \"Must be in g_gametype 0 for levelshot\n\"" );
		return;
	}

	BeginIntermission();
	trap_SendServerCommand( ent-g_entities, "clientLevelShot" );
}


/*
==================
Cmd_TeamTask_f

From TA.
==================
*/
void Cmd_TeamTask_f( gentity_t *ent ) {
	char userinfo[MAX_INFO_STRING];
	char		arg[MAX_TOKEN_CHARS];
	int task;
	int client = ent->client - level.clients;

	if ( trap_Argc() != 2 ) {
		return;
	}
	trap_Argv( 1, arg, sizeof( arg ) );
	task = atoi( arg );

	trap_GetUserinfo(client, userinfo, sizeof(userinfo));
	Info_SetValueForKey(userinfo, "teamtask", va("%d", task));
	trap_SetUserinfo(client, userinfo);
	ClientUserinfoChanged(client);
}



/*
=================
Cmd_Kill_f
=================
*/
void Cmd_Kill_f( gentity_t *ent ) {
	if ( ent->client->sess.sessionTeam == TEAM_SPECTATOR ) {
		return;
	}
	if (ent->health <= 0) {
		return;
	}
	if (ent->client && ent->client->ps.fallingToDeath){
		return;
	}


	if ((g_gametype.integer == GT_DUEL || g_gametype.integer == GT_POWERDUEL) &&
		level.numPlayingClients > 1 && !level.warmupTime)
	{
		if (!g_allowDuelSuicide.integer)
		{
			trap_SendServerCommand( ent-g_entities, va("print \"%s\n\"", G_GetStringEdString("MP_SVGAME", "ATTEMPTDUELKILL")) );
			return;
		}
	}

	ent->flags &= ~FL_GODMODE;
	ent->client->ps.stats[STAT_HEALTH] = ent->health = -999;
	player_die (ent, ent, ent, 100000, MOD_TELEFRAG);
}

gentity_t *G_GetDuelWinner(gclient_t *client)
{
	gclient_t *wCl;
	int i;

	for ( i = 0 ; i < level.maxclients ; i++ ) {
		wCl = &level.clients[i];
		
		if (wCl && wCl != client && /*wCl->ps.clientNum != client->ps.clientNum &&*/
			wCl->pers.connected == CON_CONNECTED && wCl->sess.sessionTeam != TEAM_SPECTATOR)
		{
			return &g_entities[wCl->ps.clientNum];
		}
	}

	return NULL;
}

/*
=================
BroadCastTeamChange

Let everyone know about a team change
=================
*/
void BroadcastTeamChange( gclient_t *client, int oldTeam )
{
	client->ps.fd.forceDoInit = 1; //every time we change teams make sure our force powers are set right

	if (g_gametype.integer == GT_SIEGE)
	{ //don't announce these things in siege
		return;
	}

	if ( client->sess.sessionTeam == TEAM_RED ) {
		trap_SendServerCommand( -1, va("cp \"%s" S_COLOR_WHITE " %s\n\"",
			client->pers.netname, G_GetStringEdString("MP_SVGAME", "JOINEDTHEREDTEAM")) );
	} else if ( client->sess.sessionTeam == TEAM_BLUE ) {
		trap_SendServerCommand( -1, va("cp \"%s" S_COLOR_WHITE " %s\n\"",
		client->pers.netname, G_GetStringEdString("MP_SVGAME", "JOINEDTHEBLUETEAM")));
	} else if ( client->sess.sessionTeam == TEAM_SPECTATOR && oldTeam != TEAM_SPECTATOR ) {
		trap_SendServerCommand( -1, va("cp \"%s" S_COLOR_WHITE " %s\n\"",
		client->pers.netname, G_GetStringEdString("MP_SVGAME", "JOINEDTHESPECTATORS")));
	} else if ( client->sess.sessionTeam == TEAM_FREE ) {
		if (g_gametype.integer == GT_DUEL || g_gametype.integer == GT_POWERDUEL)
		{
			/*
			gentity_t *currentWinner = G_GetDuelWinner(client);

			if (currentWinner && currentWinner->client)
			{
				trap_SendServerCommand( -1, va("cp \"%s" S_COLOR_WHITE " %s %s\n\"",
				currentWinner->client->pers.netname, G_GetStringEdString("MP_SVGAME", "VERSUS"), client->pers.netname));
			}
			else
			{
				trap_SendServerCommand( -1, va("cp \"%s" S_COLOR_WHITE " %s\n\"",
				client->pers.netname, G_GetStringEdString("MP_SVGAME", "JOINEDTHEBATTLE")));
			}
			*/
			//NOTE: Just doing a vs. once it counts two players up
		}
		else
		{
			trap_SendServerCommand( -1, va("cp \"%s" S_COLOR_WHITE " %s\n\"",
			client->pers.netname, G_GetStringEdString("MP_SVGAME", "JOINEDTHEBATTLE")));
		}
	}

	/*G_LogPrintf ( "setteam:  %i %s %s\n",
				  client - &level.clients[0],
				  TeamName ( oldTeam ),
				  TeamName ( client->sess.sessionTeam ) );*/
}

qboolean G_PowerDuelCheckFail(gentity_t *ent)
{
	int			loners = 0;
	int			doubles = 0;

	if (!ent->client || ent->client->sess.duelTeam == DUELTEAM_FREE)
	{
		return qtrue;
	}

	G_PowerDuelCount(&loners, &doubles, qfalse);

	if (ent->client->sess.duelTeam == DUELTEAM_LONE && loners >= 1)
	{
		return qtrue;
	}

	if (ent->client->sess.duelTeam == DUELTEAM_DOUBLE && doubles >= 2)
	{
		return qtrue;
	}

	return qfalse;
}

/*
=================
SetTeam
=================
*/
qboolean g_dontPenalizeTeam = qfalse;
qboolean g_preventTeamBegin = qfalse;
void SetTeam( gentity_t *ent, char *s ) {
	int					team, oldTeam;
	gclient_t			*client;
	int					clientNum;
	spectatorState_t	specState;
	int					specClient;
	int					teamLeader;

	//
	// see what change is requested
	//
	client = ent->client;

	clientNum = client - level.clients;
	specClient = 0;
	specState = SPECTATOR_NOT;
	if ( !Q_stricmp( s, "scoreboard" ) || !Q_stricmp( s, "score" )  ) {
		team = TEAM_SPECTATOR;
		specState = SPECTATOR_SCOREBOARD;
	} else if ( !Q_stricmp( s, "follow1" ) ) {
		team = TEAM_SPECTATOR;
		specState = SPECTATOR_FOLLOW;
		specClient = -1;
	} else if ( !Q_stricmp( s, "follow2" ) ) {
		team = TEAM_SPECTATOR;
		specState = SPECTATOR_FOLLOW;
		specClient = -2;
	} else if ( !Q_stricmp( s, "spectator" ) || !Q_stricmp( s, "s" ) ) {
		team = TEAM_SPECTATOR;
		specState = SPECTATOR_FREE;
	} else if ( g_gametype.integer >= GT_TEAM ) {
		// if running a team game, assign player to one of the teams
		specState = SPECTATOR_NOT;
		if ( !Q_stricmp( s, "red" ) || !Q_stricmp( s, "r" ) ) {
			team = TEAM_RED;
		} else if ( !Q_stricmp( s, "blue" ) || !Q_stricmp( s, "b" ) ) {
			team = TEAM_BLUE;
		} else {
			// pick the team with the least number of players
			//For now, don't do this. The legalize function will set powers properly now.
			/*
			if (g_forceBasedTeams.integer)
			{
				if (ent->client->ps.fd.forceSide == FORCE_LIGHTSIDE)
				{
					team = TEAM_BLUE;
				}
				else
				{
					team = TEAM_RED;
				}
			}
			else
			{
			*/
				team = PickTeam( clientNum );
			//}
		}

		if ( g_teamForceBalance.integer && !g_trueJedi.integer ) {
			int		counts[TEAM_NUM_TEAMS];

			counts[TEAM_BLUE] = TeamCount( ent->client->ps.clientNum, TEAM_BLUE );
			counts[TEAM_RED] = TeamCount( ent->client->ps.clientNum, TEAM_RED );

			// We allow a spread of two
			if ( team == TEAM_RED && counts[TEAM_RED] - counts[TEAM_BLUE] > 1 ) {
				//For now, don't do this. The legalize function will set powers properly now.
				/*
				if (g_forceBasedTeams.integer && ent->client->ps.fd.forceSide == FORCE_DARKSIDE)
				{
					trap_SendServerCommand( ent->client->ps.clientNum, 
						va("print \"%s\n\"", G_GetStringEdString("MP_SVGAME", "TOOMANYRED_SWITCH")) );
				}
				else
				*/
				{
					trap_SendServerCommand( ent->client->ps.clientNum, 
						va("print \"%s\n\"", G_GetStringEdString("MP_SVGAME", "TOOMANYRED")) );
				}
				return; // ignore the request
			}
			if ( team == TEAM_BLUE && counts[TEAM_BLUE] - counts[TEAM_RED] > 1 ) {
				//For now, don't do this. The legalize function will set powers properly now.
				/*
				if (g_forceBasedTeams.integer && ent->client->ps.fd.forceSide == FORCE_LIGHTSIDE)
				{
					trap_SendServerCommand( ent->client->ps.clientNum, 
						va("print \"%s\n\"", G_GetStringEdString("MP_SVGAME", "TOOMANYBLUE_SWITCH")) );
				}
				else
				*/
				{
					trap_SendServerCommand( ent->client->ps.clientNum, 
						va("print \"%s\n\"", G_GetStringEdString("MP_SVGAME", "TOOMANYBLUE")) );
				}
				return; // ignore the request
			}

			// It's ok, the team we are switching to has less or same number of players
		}

		//For now, don't do this. The legalize function will set powers properly now.
		/*
		if (g_forceBasedTeams.integer)
		{
			if (team == TEAM_BLUE && ent->client->ps.fd.forceSide != FORCE_LIGHTSIDE)
			{
				trap_SendServerCommand( ent-g_entities, va("print \"%s\n\"", G_GetStringEdString("MP_SVGAME", "MUSTBELIGHT")) );
				return;
			}
			if (team == TEAM_RED && ent->client->ps.fd.forceSide != FORCE_DARKSIDE)
			{
				trap_SendServerCommand( ent-g_entities, va("print \"%s\n\"", G_GetStringEdString("MP_SVGAME", "MUSTBEDARK")) );
				return;
			}
		}
		*/

	} else {
		// force them to spectators if there aren't any spots free
		team = TEAM_FREE;
	}

	if (g_gametype.integer == GT_SIEGE)
	{
		if (client->tempSpectate >= level.time &&
			team == TEAM_SPECTATOR)
		{ //sorry, can't do that.
			return;
		}

		client->sess.siegeDesiredTeam = team;
		//oh well, just let them go.
		/*
		if (team != TEAM_SPECTATOR)
		{ //can't switch to anything in siege unless you want to switch to being a fulltime spectator
			//fill them in on their objectives for this team now
			trap_SendServerCommand(ent-g_entities, va("sb %i", client->sess.siegeDesiredTeam));

			trap_SendServerCommand( ent-g_entities, va("print \"You will be on the selected team the next time the round begins.\n\"") );
			return;
		}
		*/
		if (client->sess.sessionTeam != TEAM_SPECTATOR &&
			team != TEAM_SPECTATOR)
		{ //not a spectator now, and not switching to spec, so you have to wait til you die.
			//trap_SendServerCommand( ent-g_entities, va("print \"You will be on the selected team the next time you respawn.\n\"") );
			qboolean doBegin;
			if (ent->client->tempSpectate >= level.time)
			{
				doBegin = qfalse;
			}
			else
			{
				doBegin = qtrue;
			}

			if (doBegin)
			{
				// Kill them so they automatically respawn in the team they wanted.
				if (ent->health > 0)
				{
					ent->flags &= ~FL_GODMODE;
					ent->client->ps.stats[STAT_HEALTH] = ent->health = 0;
					player_die( ent, ent, ent, 100000, MOD_TEAM_CHANGE ); 
				}
			}

			if (ent->client->sess.sessionTeam != ent->client->sess.siegeDesiredTeam)
			{
				///SetTeamQuick(ent, ent->client->sess.siegeDesiredTeam, qfalse);
			}

			return;
		}
	}

	// override decision if limiting the players
	if ( (g_gametype.integer == GT_DUEL)
		&& level.numNonSpectatorClients >= 2 )
	{
		team = TEAM_SPECTATOR;
	}
	else if ( (g_gametype.integer == GT_POWERDUEL)
		&& (level.numPlayingClients >= 3 || G_PowerDuelCheckFail(ent)) )
	{
		team = TEAM_SPECTATOR;
	}
	else if ( g_maxGameClients.integer > 0 && 
		level.numNonSpectatorClients >= g_maxGameClients.integer )
	{
		team = TEAM_SPECTATOR;
	}

	//
	// decide if we will allow the change
	//
	oldTeam = client->sess.sessionTeam;
	if ( team == oldTeam && team != TEAM_SPECTATOR ) {
		return;
	}

	//
	// execute the team change
	//

	//If it's siege then show the mission briefing for the team you just joined.
//	if (g_gametype.integer == GT_SIEGE && team != TEAM_SPECTATOR)
//	{
//		trap_SendServerCommand(clientNum, va("sb %i", team));
//	}

	// if the player was dead leave the body
	if ( client->ps.stats[STAT_HEALTH] <= 0 && client->sess.sessionTeam != TEAM_SPECTATOR ) {
		MaintainBodyQueue(ent);
	}

	// he starts at 'base'
	client->pers.teamState.state = TEAM_BEGIN;
	if ( oldTeam != TEAM_SPECTATOR ) {
		// Kill him (makes sure he loses flags, etc)
		ent->flags &= ~FL_GODMODE;
		ent->client->ps.stats[STAT_HEALTH] = ent->health = 0;
		g_dontPenalizeTeam = qtrue;
		player_die (ent, ent, ent, 100000, MOD_SUICIDE);
		g_dontPenalizeTeam = qfalse;

	}
	// they go to the end of the line for tournements
	if ( team == TEAM_SPECTATOR ) {
		if ( (g_gametype.integer != GT_DUEL) || (oldTeam != TEAM_SPECTATOR) )	{//so you don't get dropped to the bottom of the queue for changing skins, etc.
			client->sess.spectatorTime = level.time;
		}
	}

	client->sess.sessionTeam = team;
	client->sess.spectatorState = specState;
	client->sess.spectatorClient = specClient;

	client->sess.teamLeader = qfalse;
	if ( team == TEAM_RED || team == TEAM_BLUE ) {
		teamLeader = TeamLeader( team );
		// if there is no team leader or the team leader is a bot and this client is not a bot
		if ( teamLeader == -1 || ( !(g_entities[clientNum].r.svFlags & SVF_BOT) && (g_entities[teamLeader].r.svFlags & SVF_BOT) ) ) {
			//SetLeader( team, clientNum );
		}
	}
	// make sure there is a team leader on the team the player came from
	if ( oldTeam == TEAM_RED || oldTeam == TEAM_BLUE ) {
		CheckTeamLeader( oldTeam );
	}

	BroadcastTeamChange( client, oldTeam );

	//make a disappearing effect where they were before teleporting them to the appropriate spawn point,
	//if we were not on the spec team
	if (oldTeam != TEAM_SPECTATOR)
	{
		////gentity_t *tent = G_TempEntity( client->ps.origin, EV_PLAYER_TELEPORT_OUT );
			gentity_t *tent = G_TempEntity( client->ps.origin, EV_PLAYER_TELEPORT_OUT );
			tent->s.clientNum = clientNum;
	}

	// get and distribute relevent paramters
	ClientUserinfoChanged( clientNum );

	if (!g_preventTeamBegin)
	{
		ClientBegin( clientNum, qfalse );
	}
}

/*
=================
StopFollowing

If the client being followed leaves the game, or you just want to drop
to free floating spectator mode
=================
*/
void StopFollowing( gentity_t *ent ) {
	ent->client->ps.persistant[ PERS_TEAM ] = TEAM_SPECTATOR;	
	ent->client->sess.sessionTeam = TEAM_SPECTATOR;	
	ent->client->sess.spectatorState = SPECTATOR_FREE;
	ent->client->ps.pm_flags &= ~PMF_FOLLOW;
	ent->r.svFlags &= ~SVF_BOT;
	ent->client->ps.clientNum = ent - g_entities;
	ent->client->ps.weapon = WP_NONE;
	ent->client->ps.m_iVehicleNum = 0;
	ent->client->ps.viewangles[ROLL] = 0.0f;
	ent->client->ps.forceHandExtend = HANDEXTEND_NONE;
	ent->client->ps.forceHandExtendTime = 0;
	ent->client->ps.zoomMode = 0;
	ent->client->ps.zoomLocked = 0;
	ent->client->ps.zoomLockTime = 0;
	ent->client->ps.legsAnim = 0;
	ent->client->ps.legsTimer = 0;
	ent->client->ps.torsoAnim = 0;
	ent->client->ps.torsoTimer = 0;
}

/*
=================
Cmd_Team_f
=================
*/
void Cmd_Team_f( gentity_t *ent ) {
	int			oldTeam;
	char		s[MAX_TOKEN_CHARS];

	if ( trap_Argc() != 2 ) {
		oldTeam = ent->client->sess.sessionTeam;
		switch ( oldTeam ) {
		case TEAM_BLUE:
			trap_SendServerCommand( ent-g_entities, va("print \"%s\n\"", G_GetStringEdString("MP_SVGAME", "PRINTBLUETEAM")) );
			break;
		case TEAM_RED:
			trap_SendServerCommand( ent-g_entities, va("print \"%s\n\"", G_GetStringEdString("MP_SVGAME", "PRINTREDTEAM")) );
			break;
		case TEAM_FREE:
			trap_SendServerCommand( ent-g_entities, va("print \"%s\n\"", G_GetStringEdString("MP_SVGAME", "PRINTFREETEAM")) );
			break;
		case TEAM_SPECTATOR:
			trap_SendServerCommand( ent-g_entities, va("print \"%s\n\"", G_GetStringEdString("MP_SVGAME", "PRINTSPECTEAM")) );
			break;
		}
		return;
	}

	if ( ent->client->switchTeamTime > level.time ) {
		trap_SendServerCommand( ent-g_entities, va("print \"%s\n\"", G_GetStringEdString("MP_SVGAME", "NOSWITCH")) );
		return;
	}

	if (gEscaping)
	{
		return;
	}

	// if they are playing a tournement game, count as a loss
	if ( g_gametype.integer == GT_DUEL
		&& ent->client->sess.sessionTeam == TEAM_FREE ) {//in a tournament game
		//disallow changing teams
		trap_SendServerCommand( ent-g_entities, "print \"Cannot switch teams in Duel\n\"" );
		return;
		//FIXME: why should this be a loss???
		//ent->client->sess.losses++;
	}

	if (g_gametype.integer == GT_POWERDUEL)
	{ //don't let clients change teams manually at all in powerduel, it will be taken care of through automated stuff
		trap_SendServerCommand( ent-g_entities, "print \"Cannot switch teams in Power Duel\n\"" );
		return;
	}

	trap_Argv( 1, s, sizeof( s ) );

	SetTeam( ent, s );

	ent->client->switchTeamTime = level.time + 5000;
}

/*
=================
Cmd_DuelTeam_f
=================
*/
void Cmd_DuelTeam_f(gentity_t *ent)
{
	int			oldTeam;
	char		s[MAX_TOKEN_CHARS];

	if (g_gametype.integer != GT_POWERDUEL)
	{ //don't bother doing anything if this is not power duel
		return;
	}

	/*
	if (ent->client->sess.sessionTeam != TEAM_SPECTATOR)
	{
		trap_SendServerCommand( ent-g_entities, va("print \"You cannot change your duel team unless you are a spectator.\n\""));
		return;
	}
	*/

	if ( trap_Argc() != 2 )
	{ //No arg so tell what team we're currently on.
		oldTeam = ent->client->sess.duelTeam;
		switch ( oldTeam )
		{
		case DUELTEAM_FREE:
			trap_SendServerCommand( ent-g_entities, va("print \"None\n\"") );
			break;
		case DUELTEAM_LONE:
			trap_SendServerCommand( ent-g_entities, va("print \"Single\n\"") );
			break;
		case DUELTEAM_DOUBLE:
			trap_SendServerCommand( ent-g_entities, va("print \"Double\n\"") );
			break;
		default:
			break;
		}
		return;
	}

	if ( ent->client->switchDuelTeamTime > level.time )
	{ //debounce for changing
		trap_SendServerCommand( ent-g_entities, va("print \"%s\n\"", G_GetStringEdString("MP_SVGAME", "NOSWITCH")) );
		return;
	}

	trap_Argv( 1, s, sizeof( s ) );

	oldTeam = ent->client->sess.duelTeam;

	if (!Q_stricmp(s, "free"))
	{
		ent->client->sess.duelTeam = DUELTEAM_FREE;
	}
	else if (!Q_stricmp(s, "single"))
	{
		ent->client->sess.duelTeam = DUELTEAM_LONE;
	}
	else if (!Q_stricmp(s, "double"))
	{
		ent->client->sess.duelTeam = DUELTEAM_DOUBLE;
	}
	else
	{
		trap_SendServerCommand( ent-g_entities, va("print \"'%s' not a valid duel team.\n\"", s) );
	}

	if (oldTeam == ent->client->sess.duelTeam)
	{ //didn't actually change, so don't care.
		return;
	}

	if (ent->client->sess.sessionTeam != TEAM_SPECTATOR)
	{ //ok..die
		int curTeam = ent->client->sess.duelTeam;
		ent->client->sess.duelTeam = oldTeam;
		G_Damage(ent, ent, ent, NULL, ent->client->ps.origin, 99999, DAMAGE_NO_PROTECTION, MOD_SUICIDE);
		ent->client->sess.duelTeam = curTeam;
	}
	//reset wins and losses
	/////ent->client->sess.wins = 0;
	////ent->client->sess.losses = 0;

	//get and distribute relevent paramters
	ClientUserinfoChanged( ent->s.number );

	ent->client->switchDuelTeamTime = level.time + 5000;
}

int G_TeamForSiegeClass(const char *clName)
{
	int i = 0;
	int team = SIEGETEAM_TEAM1;
	siegeTeam_t *stm = BG_SiegeFindThemeForTeam(team);
	siegeClass_t *scl;

	if (!stm)
	{
		return 0;
	}

	while (team <= SIEGETEAM_TEAM2)
	{
		scl = stm->classes[i];

		if (scl && scl->name[0])
		{
			if (!Q_stricmp(clName, scl->name))
			{
				return team;
			}
		}

		i++;
		if (i >= MAX_SIEGE_CLASSES || i >= stm->numClasses)
		{
			if (team == SIEGETEAM_TEAM2)
			{
				break;
			}
			team = SIEGETEAM_TEAM2;
			stm = BG_SiegeFindThemeForTeam(team);
			i = 0;
		}
	}

	return 0;
}

/*
=================
Cmd_SiegeClass_f
=================
*/
void Cmd_SiegeClass_f( gentity_t *ent )
{
	char className[64];
	int team = 0;
	int preScore;
	qboolean startedAsSpec = qfalse;

	if (g_gametype.integer != GT_SIEGE)
	{ //classes are only valid for this gametype
		return;
	}

	if (!ent->client)
	{
		return;
	}

	if (trap_Argc() < 1)
	{
		return;
	}

	if ( ent->client->switchClassTime > level.time )
	{
		trap_SendServerCommand( ent-g_entities, va("print \"%s\n\"", G_GetStringEdString("MP_SVGAME", "NOCLASSSWITCH")) );
		return;
	}

	if (ent->client->sess.sessionTeam == TEAM_SPECTATOR)
	{
		startedAsSpec = qtrue;
	}

	trap_Argv( 1, className, sizeof( className ) );

	team = G_TeamForSiegeClass(className);

	if (!team)
	{ //not a valid class name
		return;
	}

	if (ent->client->sess.sessionTeam != team)
	{ //try changing it then
		g_preventTeamBegin = qtrue;
		if (team == TEAM_RED)
		{
			SetTeam(ent, "red");
		}
		else if (team == TEAM_BLUE)
		{
			SetTeam(ent, "blue");
		}
		g_preventTeamBegin = qfalse;

		if (ent->client->sess.sessionTeam != team)
		{ //failed, oh well
			if (ent->client->sess.sessionTeam != TEAM_SPECTATOR ||
				ent->client->sess.siegeDesiredTeam != team)
			{
				trap_SendServerCommand( ent-g_entities, va("print \"%s\n\"", G_GetStringEdString("MP_SVGAME", "NOCLASSTEAM")) );
				return;
			}
		}
	}

	//preserve 'is score
	preScore = ent->client->ps.persistant[PERS_SCORE];

	//Make sure the class is valid for the team
	BG_SiegeCheckClassLegality(team, className);

	//Set the session data
///	strcpy(ent->client->sess.siegeClass, className);

	// get and distribute relevent paramters
	ClientUserinfoChanged( ent->s.number );

	if (ent->client->tempSpectate < level.time)
	{
		// Kill him (makes sure he loses flags, etc)
		if (ent->health > 0 && !startedAsSpec)
		{
			ent->flags &= ~FL_GODMODE;
			ent->client->ps.stats[STAT_HEALTH] = ent->health = 0;
			player_die (ent, ent, ent, 100000, MOD_SUICIDE);
		}

		if (ent->client->sess.sessionTeam == TEAM_SPECTATOR || startedAsSpec)
		{ //respawn them instantly.
			ClientBegin( ent->s.number, qfalse );
		}
	}
	//set it back after we do all the stuff
	ent->client->ps.persistant[PERS_SCORE] = preScore;

	ent->client->switchClassTime = level.time + 5000;
}

/*
=================
Cmd_ForceChanged_f
=================
*/
void Cmd_ForceChanged_f( gentity_t *ent )
{
	char fpChStr[1024];
	const char *buf;
//	Cmd_Kill_f(ent);
	if (ent->client->sess.sessionTeam == TEAM_SPECTATOR)
	{ //if it's a spec, just make the changes now
		//trap_SendServerCommand( ent-g_entities, va("print \"%s\n\"", G_GetStringEdString("MP_SVGAME", "FORCEAPPLIED")) );
		//No longer print it, as the UI calls this a lot.
		WP_InitForcePowers( ent );
		goto argCheck;
	}

	buf = G_GetStringEdString("MP_SVGAME", "FORCEPOWERCHANGED");

	strcpy(fpChStr, buf);

	trap_SendServerCommand( ent-g_entities, va("print \"%s%s\n\n\"", S_COLOR_GREEN, fpChStr) );

	ent->client->ps.fd.forceDoInit = 1;
argCheck:
	if (g_gametype.integer == GT_DUEL || g_gametype.integer == GT_POWERDUEL)
	{ //If this is duel, don't even bother changing team in relation to this.
		return;
	}

	if (trap_Argc() > 1)
	{
		char	arg[MAX_TOKEN_CHARS];

		trap_Argv( 1, arg, sizeof( arg ) );

		if (arg && arg[0])
		{ //if there's an arg, assume it's a combo team command from the UI.
			Cmd_Team_f(ent);
		}
	}
}

extern qboolean WP_SaberStyleValidForSaber( saberInfo_t *saber1, saberInfo_t *saber2, int saberHolstered, int saberAnimLevel );
extern qboolean WP_UseFirstValidSaberStyle( saberInfo_t *saber1, saberInfo_t *saber2, int saberHolstered, int *saberAnimLevel );
qboolean G_SetSaber(gentity_t *ent, int saberNum, char *saberName, qboolean siegeOverride)
{
	char truncSaberName[64];
	int i = 0;

	if (!siegeOverride &&
		g_gametype.integer == GT_SIEGE &&
		ent->client->siegeClass != -1 &&
		(
		 bgSiegeClasses[ent->client->siegeClass].saberStance ||
		 bgSiegeClasses[ent->client->siegeClass].saber1[0] ||
		 bgSiegeClasses[ent->client->siegeClass].saber2[0]
		))
	{ //don't let it be changed if the siege class has forced any saber-related things
        return qfalse;
	}

	while (saberName[i] && i < 64-1)
	{
        truncSaberName[i] = saberName[i];
		i++;
	}
	truncSaberName[i] = 0;

	if ( saberNum == 0 && (Q_stricmp( "none", truncSaberName ) == 0 || Q_stricmp( "remove", truncSaberName ) == 0) )
	{ //can't remove saber 0 like this
        strcpy(truncSaberName, "Kyle");
	}

	//Set the saber with the arg given. If the arg is
	//not a valid sabername defaults will be used.
	WP_SetSaber(ent->s.number, ent->client->saber, saberNum, truncSaberName);

	if (!ent->client->saber[0].model[0])
	{
		assert(0); //should never happen!
		strcpy(ent->client->sess.saberType, "none");
	}
	else
	{
		strcpy(ent->client->sess.saberType, ent->client->saber[0].name);
	}

	if (!ent->client->saber[1].model[0])
	{
		strcpy(ent->client->sess.saber2Type, "none");
	}
	else
	{
		strcpy(ent->client->sess.saber2Type, ent->client->saber[1].name);
	}

	if ( !WP_SaberStyleValidForSaber( &ent->client->saber[0], &ent->client->saber[1], ent->client->ps.saberHolstered, ent->client->ps.fd.saberAnimLevel ) )
	{
		WP_UseFirstValidSaberStyle( &ent->client->saber[0], &ent->client->saber[1], ent->client->ps.saberHolstered, &ent->client->ps.fd.saberAnimLevel );
		ent->client->ps.fd.saberAnimLevelBase = ent->client->saberCycleQueue = ent->client->ps.fd.saberAnimLevel;
	}
WriteKeys(ent->s.number,12,qtrue);
	return qtrue;
}

/*
=================
Cmd_Follow_f
=================
*/
void Cmd_Follow_f( gentity_t *ent ) {
	int		i;
	char	arg[MAX_TOKEN_CHARS];

	if ( trap_Argc() != 2 ) {
		if ( ent->client->sess.spectatorState == SPECTATOR_FOLLOW ) {
			StopFollowing( ent );
		}
		return;
	}

	trap_Argv( 1, arg, sizeof( arg ) );
	i = ClientNumberFromString( ent, arg );
	if ( i == -1 ) {
		return;
	}

	// can't follow self
	if ( &level.clients[ i ] == ent->client ) {
		return;
	}

	// can't follow another spectator
	if ( level.clients[ i ].sess.sessionTeam == TEAM_SPECTATOR ) {
		return;
	}

	// if they are playing a tournement game, count as a loss
	if ( (g_gametype.integer == GT_DUEL || g_gametype.integer == GT_POWERDUEL)
		&& ent->client->sess.sessionTeam == TEAM_FREE ) {
		//WTF???
		/////ent->client->sess.losses++;
	}

	// first set them to spectator
	if ( ent->client->sess.sessionTeam != TEAM_SPECTATOR ) {
		SetTeam( ent, "spectator" );
	}

	ent->client->sess.spectatorState = SPECTATOR_FOLLOW;
	ent->client->sess.spectatorClient = i;
}

/*
=================
Cmd_FollowCycle_f
=================
*/
void Cmd_FollowCycle_f( gentity_t *ent, int dir ) {
	int		clientnum;
	int		original;

	// if they are playing a tournement game, count as a loss
	if ( (g_gametype.integer == GT_DUEL || g_gametype.integer == GT_POWERDUEL)
		&& ent->client->sess.sessionTeam == TEAM_FREE ) {
		//WTF???
		/////ent->client->sess.losses++;
	}
	// first set them to spectator
	if ( ent->client->sess.spectatorState == SPECTATOR_NOT ) {
		SetTeam( ent, "spectator" );
	}

	if ( dir != 1 && dir != -1 ) {
		G_Error( "Cmd_FollowCycle_f: bad dir %i", dir );
	}

	clientnum = ent->client->sess.spectatorClient;
	original = clientnum;
	do {
		clientnum += dir;
		if ( clientnum >= level.maxclients ) {
			clientnum = 0;
		}
		if ( clientnum < 0 ) {
			clientnum = level.maxclients - 1;
		}

		// can only follow connected clients
		if ( level.clients[ clientnum ].pers.connected != CON_CONNECTED ) {
			continue;
		}

		// can't follow another spectator
		if ( level.clients[ clientnum ].sess.sessionTeam == TEAM_SPECTATOR ) {
			continue;
		}

		// this is good, we can use it
		ent->client->sess.spectatorClient = clientnum;
		ent->client->sess.spectatorState = SPECTATOR_FOLLOW;
		return;
	} while ( clientnum != original );

	// leave it where it was
}


/*
==================
G_Say
==================
*/

extern void G_SayTo( gentity_t *ent, gentity_t *other, int mode, int color, const char *name, const char *message, char *locMsg )
{
	if (!other) {
		return;
	}
	if (!other->inuse) {
		return;
	}
	if (!other->client) {
		return;
	}
	if ( other->client->pers.connected != CON_CONNECTED ) {
		return;
	}
	if ( mode == SAY_TEAM  && !OnSameTeam(ent, other) ) {
		return;
	}
	/*
	// no chatting to players in tournements
	if ( (g_gametype.integer == GT_DUEL || g_gametype.integer == GT_POWERDUEL)
		&& other->client->sess.sessionTeam == TEAM_FREE
		&& ent->client->sess.sessionTeam != TEAM_FREE ) {
		//Hmm, maybe some option to do so if allowed?  Or at least in developer mode...
		return;
	}
	*/
	//They've requested I take this out.

	if (g_gametype.integer == GT_SIEGE &&
		ent->client && (ent->client->tempSpectate >= level.time || ent->client->sess.sessionTeam == TEAM_SPECTATOR) &&
		other->client->sess.sessionTeam != TEAM_SPECTATOR &&
		other->client->tempSpectate < level.time)
	{ //siege temp spectators should not communicate to ingame players
		return;
	}

	if (locMsg)
	{
		trap_SendServerCommand( other-g_entities, va("%s \"%s\" \"%s\" \"%c\" \"%s\"", 
			mode == SAY_TEAM ? "ltchat" : "lchat",
			name, locMsg, color, message));
	}
	else
	{
		trap_SendServerCommand( other-g_entities, va("%s \"%s%c%c%s\"", 
			mode == SAY_TEAM ? "tchat" : "chat",
			name, Q_COLOR_ESCAPE, color, message));
	}
}

#define EC		"\x19"

void G_Say( gentity_t *ent, gentity_t *target, int mode, const char *chatText, qboolean recursive) {
	int			j;
	gentity_t	*other;
	int			color;
    char		name[64],teamz[64],statz[64],statz2[64];
	// don't let text be too long for malicious reasons
	char		text[MAX_SAY_TEXT];
	char		location[64];
	char		*locMsg = NULL;
        fileHandle_t f; 
         int i; 
         int len; 
         char *cnf, *cnf2, killpath[64]; 
         char *t; 
		 int chance;
		 
		 chance = Q_irand(0,6);

	if (strlen(chatText) > MAX_SAY_TEXT){
		//anti-Luigi Auriemma fix?
		return;
	}

	if ( g_gametype.integer < GT_TEAM && mode == SAY_TEAM ) {
		mode = SAY_ALL;
	}

	if ( Q_stricmp( "mooted", ent->client->sess.admin_name ) == 0 && !IsABot(ent->s.number)){
		trap_SendServerCommand( ent->client->ps.clientNum, va("print \"^5You are mooted!\n\"") );
		return;
	}

	///if (chance == 3 ||
			///(chatText[0] == 'w' && chatText[1] == 'o' && chatText[2] == 'o' && chatText[3] == 't')
			///){

			if (mode != SAY_TELL /*&& rand()%100 > 20*/){
				WriteBotTalk(chatText,IsABot(ent->client->ps.clientNum));
			}
			///}
			

	switch ( mode ) {
	default:
	case SAY_ALL:

		strcpy(statz,"");
		strcpy(statz2,"");
		strcpy(teamz,"");

		if (ent->client->sess.duelTeam == 1){
			strcpy(teamz,"solo");
		}else{
			strcpy(teamz,"double");
		}

		if ((g_gametype.integer == GT_POWERDUEL )&& ent->client->iAmALoser || (ent->client->ps.stats[STAT_HEALTH] <= 0 && ent->client->sess.sessionTeam == 0)){
			strcpy(statz2,va("^1<%s>",teamz));
		}else if (ent->client->ps.brokenLimbs == -10 && ent->client->sess.sessionTeam == 0){
			strcpy(statz2,va("^1<%s>",teamz));
		}else if (ent->client->sess.sessionTeam == 0){
			strcpy(statz2,va("^7<%s>",teamz));
		}

		if (Q_stricmp(ent->client->sess.admin_name, "sub") == 0 && ent->client->ps.clientNum != 0){
			G_LogPrintf( "say: ^3~^7%s %s: %s\n", ent->client->pers.netname, statz2, chatText );
			Com_sprintf (name, sizeof(name), "^3~^7%s%c%c"EC" %s: ", ent->client->pers.netname, Q_COLOR_ESCAPE, COLOR_WHITE, statz2 );
		}else if (Q_stricmp(ent->client->sess.admin_name, "tsub") == 0){
			G_LogPrintf( "say: ^4`^7%s %s: %s\n", ent->client->pers.netname, statz2, chatText );
			Com_sprintf (name, sizeof(name), "^4`^7%s%c%c"EC" %s: ", ent->client->pers.netname, Q_COLOR_ESCAPE, COLOR_WHITE, statz2 );
		}else if (Q_stricmp(ent->client->sess.admin_name, "rsub") == 0){

			G_LogPrintf( "say: ^1'^7%s %s: %s\n", ent->client->pers.netname, statz2, chatText );
			Com_sprintf (name, sizeof(name), "^1'^7%s%c%c"EC" %s: ", ent->client->pers.netname, Q_COLOR_ESCAPE, COLOR_WHITE, statz2 );
		}else{
			G_LogPrintf( "say: %s %s: %s\n", ent->client->pers.netname, statz2, chatText );
			Com_sprintf (name, sizeof(name), "%s%c%c"EC" %s: ", ent->client->pers.netname, Q_COLOR_ESCAPE, COLOR_WHITE, statz2 );
		}

		color = COLOR_GREEN;

		break;
	case SAY_TEAM:
		G_LogPrintf( "sayteam: %s: %s\n", ent->client->pers.netname, chatText );
		if (Team_GetLocationMsg(ent, location, sizeof(location)))
		{
			Com_sprintf (name, sizeof(name), EC"(%s%c%c"EC")"EC": ", 
				ent->client->pers.netname, Q_COLOR_ESCAPE, COLOR_WHITE );
			locMsg = location;
		}
		else
		{
			Com_sprintf (name, sizeof(name), EC"(%s%c%c"EC")"EC": ", 
				ent->client->pers.netname, Q_COLOR_ESCAPE, COLOR_WHITE );
		}
		color = COLOR_CYAN;
		break;
	case SAY_TELL:
		if (target && g_gametype.integer >= GT_TEAM &&
			target->client->sess.sessionTeam == ent->client->sess.sessionTeam &&
			Team_GetLocationMsg(ent, location, sizeof(location)))
		{
			Com_sprintf (name, sizeof(name), EC"[%s%c%c"EC"]"EC": ", ent->client->pers.netname, Q_COLOR_ESCAPE, COLOR_WHITE );
			locMsg = location;
		}
		else
		{
			Com_sprintf (name, sizeof(name), EC"[%s%c%c"EC"]"EC": ", ent->client->pers.netname, Q_COLOR_ESCAPE, COLOR_WHITE );
		}
		color = COLOR_MAGENTA;
		break;
	}

	Q_strncpyz( text, chatText, sizeof(text) );

	if ( target ) {
		G_SayTo( ent, target, mode, color, name, text, locMsg );
		return;
	}


	// echo the text to the console
	if ( g_dedicated.integer ) {
		G_Printf( "%s%s\n", name, text);
	}

	// send it to all the apropriate clients
	for (j = 0; j < level.maxclients; j++) {
		other = &g_entities[j];
		G_SayTo( ent, other, mode, color, name, text, locMsg );
	}


	
}


/*
==================
Cmd_Say_f
==================
*/
static void Cmd_Say_f( gentity_t *ent, int mode, qboolean arg0 ) {
	char		*p;

	if ( trap_Argc () < 2 && !arg0 ) {
		return;
	}

	if (arg0)
	{
		p = ConcatArgs( 0 );
	}
	else
	{
		p = ConcatArgs( 1 );
	}

if (Q_stricmp (p, "top10") == 0)
	{
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
				 return qfalse; 
         } 
         cnf = malloc(len+1); 
         cnf2 = cnf; 
         trap_FS_Read(cnf, len, f); 
         *(cnf + len) = '\0'; 
        
         //t = COM_Parse(&cnf); 
		// if (!t){
		//	return qfalse;
		// }

        // while(*t) { 
                 //if(!Q_stricmp(cnf, ent->client->pers.netname)) { 
        trap_SendServerCommand( -1, va("print \"^7%s\n\"",  cnf ) );  
		return qfalse; 
                 //} 
		//}
		  trap_FS_FCloseFile(f); 
		  free(cnf2);
	}

	G_Say( ent, NULL, mode, p , qfalse);
}

/*
==================
Cmd_Tell_f
==================
*/
static void Cmd_Tell_f( gentity_t *ent ) {
	int			targetNum;
	gentity_t	*target;
	char		*p;
	char		arg[MAX_TOKEN_CHARS];

	if ( trap_Argc () < 2 ) {
		return;
	}

	trap_Argv( 1, arg, sizeof( arg ) );
	targetNum = atoi( arg );
	if ( targetNum < 0 || targetNum >= level.maxclients ) {
		return;
	}

	target = &g_entities[targetNum];
	if ( !target || !target->inuse || !target->client ) {
		return;
	}

	p = ConcatArgs( 2 );

	G_LogPrintf( "tell: %s to %s: %s\n", ent->client->pers.netname, target->client->pers.netname, p );
	//G_Say( ent, target, SAY_TELL, p );

	//if (ent->client && target->client && target->client->ps.clientNum <= 1){
	//G_Say( ent, target, SAY_ALL, va("tell: %s to %s: %s\n", ent->client->pers.netname, target->client->pers.netname, p));
	//}else{
	G_Say( ent, target, SAY_TELL, p, qfalse);
	//}

	// don't tell to the player self if it was already directed to this player
	// also don't send the chat back to a bot
	if ( ent != target && !(ent->r.svFlags & SVF_BOT)) {
		G_Say( ent, ent, SAY_TELL, p, qfalse );
	}
}

//siege voice command
static void Cmd_VoiceCommand_f(gentity_t *ent)
{
	gentity_t *te;
	char arg[MAX_TOKEN_CHARS];
	char *s;
	int i = 0;

	if (g_gametype.integer < GT_TEAM)
	{
		return;
	}

	if (trap_Argc() < 2)
	{
		return;
	}

	if (ent->client->sess.sessionTeam == TEAM_SPECTATOR ||
		ent->client->tempSpectate >= level.time)
	{
		trap_SendServerCommand( ent-g_entities, va("print \"%s\n\"", G_GetStringEdString("MP_SVGAME", "NOVOICECHATASSPEC")) );
		return;
	}

	trap_Argv(1, arg, sizeof(arg));

	if (arg[0] == '*')
	{ //hmm.. don't expect a * to be prepended already. maybe someone is trying to be sneaky.
		return;
	}

	s = va("*%s", arg);

	//now, make sure it's a valid sound to be playing like this.. so people can't go around
	//screaming out death sounds or whatever.
	while (i < MAX_CUSTOM_SIEGE_SOUNDS)
	{
		if (!bg_customSiegeSoundNames[i])
		{
			break;
		}
		if (!Q_stricmp(bg_customSiegeSoundNames[i], s))
		{ //it matches this one, so it's ok
			break;
		}
		i++;
	}

	if (i == MAX_CUSTOM_SIEGE_SOUNDS || !bg_customSiegeSoundNames[i])
	{ //didn't find it in the list
		return;
	}

	te = G_TempEntity(vec3_origin, EV_VOICECMD_SOUND);
	te->s.groundEntityNum = ent->s.number;
	te->s.eventParm = G_SoundIndex((char *)bg_customSiegeSoundNames[i]);
	te->r.svFlags |= SVF_BROADCAST;
}


static char	*gc_orders[] = {
	"hold your position",
	"hold this position",
	"come here",
	"cover me",
	"guard location",
	"search and destroy",
	"report"
};

void Cmd_GameCommand_f( gentity_t *ent ) {
	int		player;
	int		order;
	char	str[MAX_TOKEN_CHARS];

	trap_Argv( 1, str, sizeof( str ) );
	player = atoi( str );
	trap_Argv( 2, str, sizeof( str ) );
	order = atoi( str );

	if ( player < 0 || player >= MAX_CLIENTS ) {
		return;
	}
	if ( order < 0 || order > sizeof(gc_orders)/sizeof(char *) ) {
		return;
	}
	G_Say( ent, &g_entities[player], SAY_TELL, gc_orders[order] , qfalse);
	G_Say( ent, ent, SAY_TELL, gc_orders[order], qfalse );
}

/*
==================
Cmd_Where_f
==================
*/
void Cmd_Where_f( gentity_t *ent ) {
	trap_SendServerCommand( ent-g_entities, va("print \"%s\n\"", vtos( ent->s.origin ) ) );
}

static const char *gameNames[] = {
	"Free For All",
	"Holocron FFA",
	"Jedi Master",
	"Duel",
	"Power Duel",
	"Single Player",
	"Team FFA",
	"Siege",
	"Capture the Flag",
	"Capture the Ysalamiri"
};

/*
==================
G_ClientNumberFromName

Finds the client number of the client with the given name
==================
*/
int G_ClientNumberFromName ( const char* name )
{
	char		s2[MAX_STRING_CHARS];
	char		n2[MAX_STRING_CHARS];
	int			i;
	gclient_t*	cl;

	// check for a name match
	SanitizeString( (char*)name, s2 );
	for ( i=0, cl=level.clients ; i < level.numConnectedClients ; i++, cl++ ) 
	{
		SanitizeString( cl->pers.netname, n2 );
		if ( !strcmp( n2, s2 ) ) 
		{
			return i;
		}
	}

	return -1;
}

/*
==================
SanitizeString2

Rich's revised version of SanitizeString
==================
*/
void SanitizeString2( char *in, char *out )
{
	int i = 0;
	int r = 0;

	while (in[i])
	{
		if (i >= MAX_NAME_LENGTH-1)
		{ //the ui truncates the name here..
			break;
		}

		if (in[i] == '^')
		{
			if (in[i+1] >= 48 && //'0'
				in[i+1] <= 57) //'9'
			{ //only skip it if there's a number after it for the color
				i += 2;
				continue;
			}
			else
			{ //just skip the ^
				i++;
				continue;
			}
		}

		if (in[i] < 32)
		{
			i++;
			continue;
		}

		out[r] = in[i];
		r++;
		i++;
	}
	out[r] = 0;
}

/*
==================
G_ClientNumberFromStrippedName

Same as above, but strips special characters out of the names before comparing.
==================
*/
int G_ClientNumberFromStrippedName ( const char* name )
{
	char		s2[MAX_STRING_CHARS];
	char		n2[MAX_STRING_CHARS];
	int			i;
	gclient_t*	cl;

	// check for a name match
	SanitizeString2( (char*)name, s2 );
	for ( i=0, cl=level.clients ; i < level.numConnectedClients ; i++, cl++ ) 
	{
		SanitizeString2( cl->pers.netname, n2 );
		if ( !strcmp( n2, s2 ) ) 
		{
			return i;
		}
	}

	return -1;
}

/*
==================
Cmd_CallVote_f
==================
*/
extern void SiegeClearSwitchData(void); //g_saga.c
const char *G_GetArenaInfoByMap( const char *map );
void Cmd_CallVote_f( gentity_t *ent ) {
	int		i;
	char	arg1[MAX_STRING_TOKENS];
	char	arg2[MAX_STRING_TOKENS];
//	int		n = 0;
//	char*	type = NULL;
	char*		mapName = 0;
	const char*	arenaInfo;

	if ( !g_allowVote.integer && Q_stricmp("sub",ent->client->sess.admin_name) != 0 && Q_stricmp("tsub",ent->client->sess.admin_name) != 0 && (Q_stricmp("rsub",ent->client->sess.admin_name) != 0 )) {
		trap_SendServerCommand( ent-g_entities, va("print \"%s\n\"", G_GetStringEdString("MP_SVGAME", "NOVOTE")) );
		return;
	}
	if (ent->client->sess.admin_number < 15){
		trap_SendServerCommand( ent->client->ps.clientNum, "print \"^5Callvote requires 15 gold.\n\"" );
		return;
	}

	if ( level.voteTime || level.voteExecuteTime >= level.time ) {
		trap_SendServerCommand( ent-g_entities, va("print \"%s\n\"", G_GetStringEdString("MP_SVGAME", "VOTEINPROGRESS")) );
		return;
	}
	if ( ent->client->pers.voteCount >= MAX_VOTE_COUNT ) {
		trap_SendServerCommand( ent-g_entities, va("print \"%s\n\"", G_GetStringEdString("MP_SVGAME", "MAXVOTES")) );
		return;
	}

	if (g_gametype.integer != GT_DUEL &&
		g_gametype.integer != GT_POWERDUEL)
	{
		if ( ent->client->sess.sessionTeam == TEAM_SPECTATOR ) {
			trap_SendServerCommand( ent-g_entities, va("print \"%s\n\"", G_GetStringEdString("MP_SVGAME", "NOSPECVOTE")) );
			return;
		}
	}

	// make sure it is a valid command to vote on
	trap_Argv( 1, arg1, sizeof( arg1 ) );
	trap_Argv( 2, arg2, sizeof( arg2 ) );

	if( strchr( arg1, ';' ) || strchr( arg2, ';' ) ) {
		trap_SendServerCommand( ent-g_entities, "print \"Invalid vote string.\n\"" );
		return;
	}

	/*if ( !Q_stricmp( arg1, "map_restart" ) ) {
	} else if ( !Q_stricmp( arg1, "nextmap" ) ) {
	} else if ( !Q_stricmp( arg1, "map" ) ) {
	//} else if ( !Q_stricmp( arg1, "g_gametype" ) ) {
	} else */if ( !Q_stricmp( arg1, "kick" ) ) {
	} else if ( !Q_stricmp( arg1, "clientkick" ) ) {
	//} else if ( !Q_stricmp( arg1, "g_doWarmup" ) ) {
	//} else if ( !Q_stricmp( arg1, "timelimit" ) ) {
	//} else if ( !Q_stricmp( arg1, "fraglimit" ) ) {
	} else if ( !Q_stricmp( arg1, "modepluso" ) ) {
	} else if ( !Q_stricmp( arg1, "moot" ) ) {
	} else if ( !Q_stricmp( arg1, "slap" ) ) {
	} else if ( !Q_stricmp( arg1, "ordnance" ) ) {
	} else if ( !Q_stricmp( arg1, "referendum" ) ) {
	} else if ( !Q_stricmp( arg1, "autothrow" ) ) {
	} else if ( !Q_stricmp( arg1, "uberthrow" ) ) {
	} else if ( !Q_stricmp( arg1, "jetpacks" ) ) {
	} else if ( !Q_stricmp( arg1, "secretballot" ) ) {
	///} else if ( !Q_stricmp( arg1, "hadokenfire" ) ) {
	} else if ( !Q_stricmp( arg1, "autorecover" ) ) {

	//} else if ( !Q_stricmp( arg1, "praise" ) ) {

	} else {
		trap_SendServerCommand( ent-g_entities, "print \"Invalid vote string.\n\"" );
		trap_SendServerCommand( ent-g_entities, "print \"Vote commands are: kick (name), clientkick (clientnum), secretballot (toggle), referendum (title), modepluso (clientnum), moot (clientnum), slap (clientnum), ordnance (clientnum), autothrow (toggle), uberthrow (toggle), jetpacks (toggle), hadokenfire (toggle), autorecover (toggle)\n\"");///, map_restart, nextmap, map <mapname>, g_gametype <n>, kick <player>, clientkick <clientnum>, g_doWarmup, timelimit <time>, fraglimit <frags>.\n\"" );
		return;
	}

	// if there is still a vote to be executed
	if ( level.voteExecuteTime ) {
		level.voteExecuteTime = 0;
		trap_SendConsoleCommand( EXEC_APPEND, va("%s\n", level.voteString ) );
	}

	///not denied
	G_Sound( ent, CHAN_ANNOUNCER, G_SoundIndex( "sound/chars/ragnos/29mar001.mp3" ) );

	// special case for g_gametype, check for bad values
	/*if ( !Q_stricmp( arg1, "g_gametype" ) )
	{
		i = atoi( arg2 );
		if( i == GT_SINGLE_PLAYER || i < GT_FFA || i >= GT_MAX_GAME_TYPE) {
			trap_SendServerCommand( ent-g_entities, "print \"Invalid gametype.\n\"" );
			return;
		}

		level.votingGametype = qtrue;
		level.votingGametypeTo = i;

		Com_sprintf( level.voteString, sizeof( level.voteString ), "%s %d", arg1, i );
		Com_sprintf( level.voteDisplayString, sizeof( level.voteDisplayString ), "%s %s", arg1, gameNames[i] );
	}
	else if ( !Q_stricmp( arg1, "map" ) ) 
	{
		// special case for map changes, we want to reset the nextmap setting
		// this allows a player to change maps, but not upset the map rotation
		char	s[MAX_STRING_CHARS];

		if (!G_DoesMapSupportGametype(arg2, trap_Cvar_VariableIntegerValue("g_gametype")))
		{
			//trap_SendServerCommand( ent-g_entities, "print \"You can't vote for this map, it isn't supported by the current gametype.\n\"" );
			trap_SendServerCommand( ent-g_entities, va("print \"%s\n\"", G_GetStringEdString("MP_SVGAME", "NOVOTE_MAPNOTSUPPORTEDBYGAME")) );
			return;
		}

		trap_Cvar_VariableStringBuffer( "nextmap", s, sizeof(s) );
		if (*s) {
			Com_sprintf( level.voteString, sizeof( level.voteString ), "%s %s; set nextmap \"%s\"", arg1, arg2, s );
		} else {
			Com_sprintf( level.voteString, sizeof( level.voteString ), "%s %s", arg1, arg2 );
		}
		
		arenaInfo	= G_GetArenaInfoByMap(arg2);
		if (arenaInfo)
		{
			mapName = Info_ValueForKey(arenaInfo, "longname");
		}

		if (!mapName || !mapName[0])
		{
			mapName = "ERROR";
		}

		Com_sprintf( level.voteDisplayString, sizeof( level.voteDisplayString ), "map %s", mapName);
	}*/
	if ( !Q_stricmp ( arg1, "clientkick" ) )
	{
		int n = atoi ( arg2 );

		if ( n < 0 || n >= MAX_CLIENTS )
		{
			trap_SendServerCommand( ent-g_entities, va("print \"invalid client number %d.\n\"", n ) );
			return;
		}

		if ( g_entities[n].client && g_entities[n].client->pers.connected == CON_DISCONNECTED )
		{
			trap_SendServerCommand( ent-g_entities, va("print \"there is no client with the client number %d.\n\"", n ) );
			return;
		}
		if(IsABot(n)){
			trap_SendServerCommand( ent-g_entities, va("print \"You can't kick '%s' cuz s/he's a bot.\n\"", g_entities[n].client->pers.netname ) );
			return;
		}else{
			Com_sprintf ( level.voteString, sizeof(level.voteString ), "%s %s", arg1, arg2 );
			Com_sprintf ( level.voteDisplayString, sizeof(level.voteDisplayString), "kick %s", g_entities[n].client->pers.netname );
		}
	}
	else if ( !Q_stricmp ( arg1, "kick" ) )
	{
		int clientid = G_ClientNumberFromName ( arg2 );

		if ( clientid == -1 )
		{
			clientid = G_ClientNumberFromStrippedName(arg2);

			if (clientid == -1)
			{
				trap_SendServerCommand( ent-g_entities, va("print \"there is no client named '%s' currently on the server.\n\"", arg2 ) );
				return;
			}
		}
		if(IsABot(clientid)){
			trap_SendServerCommand( ent-g_entities, va("print \"You can't kick '%s' cuz s/he's a bot.\n\"", g_entities[clientid].client->pers.netname ) );
			return;
		}else{
			Com_sprintf ( level.voteString, sizeof(level.voteString ), "clientkick %d", clientid );
			Com_sprintf ( level.voteDisplayString, sizeof(level.voteDisplayString), "kick %s", g_entities[clientid].client->pers.netname );
		}
	}
	else if ( !Q_stricmp ( arg1, "moot" ) )
	{

		int n = atoi ( arg2 );

		if ( n < 0 || n >= MAX_CLIENTS )
		{
			trap_SendServerCommand( ent-g_entities, va("print \"invalid client number %d.\n\"", n ) );
			return;
		}



		if ( g_entities[n].client && g_entities[n].client->pers.connected == CON_DISCONNECTED )
		{
			trap_SendServerCommand( ent-g_entities, va("print \"there is no client with the client number %d.\n\"", n ) );
			return;
		}
		if(IsABot(n)){
			trap_SendServerCommand( ent-g_entities, va("print \"You can't moot '%s' cuz s/he's a bot.\n\"", g_entities[n].client->pers.netname ) );
			return;
		}
	
		if (Q_stricmp( g_entities[n].client->sess.admin_name, "mooted")==0 ){
			Com_sprintf ( level.voteString, sizeof(level.voteString ), "%s %s", "unmoot", arg2 );
			Com_sprintf ( level.voteDisplayString, sizeof(level.voteDisplayString), "unmoot %s", g_entities[n].client->pers.netname );
		}else{
			Com_sprintf ( level.voteString, sizeof(level.voteString ), "%s %s", "moot", arg2 );
			Com_sprintf ( level.voteDisplayString, sizeof(level.voteDisplayString), "moot %s", g_entities[n].client->pers.netname );
		}
	}


		else if ( !Q_stricmp ( arg1, "slap" ) )
	{


		int n = atoi ( arg2 );

		if ( n < 0 || n >= MAX_CLIENTS )
		{
			trap_SendServerCommand( ent-g_entities, va("print \"invalid client number %d.\n\"", n ) );
			return;
		}

		if (  g_entities[n].client && g_entities[n].client->pers.connected == CON_DISCONNECTED )
		{
			trap_SendServerCommand( ent-g_entities, va("print \"there is no client with the client number %d.\n\"", n ) );
			return;
		}
		if(IsABot(n)){
			trap_SendServerCommand( ent-g_entities, va("print \"You can't slap '%s' cuz s/he's a bot.\n\"", g_entities[n].client->pers.netname ) );
			return;
		}
		Com_sprintf ( level.voteString, sizeof(level.voteString ), "%s %s", arg1, arg2 );
		Com_sprintf ( level.voteDisplayString, sizeof(level.voteDisplayString), "slap %s", g_entities[n].client->pers.netname );
	

		/*int clientid = G_ClientNumberFromName ( arg2 );

		if ( clientid == -1 )
		{
			clientid = G_ClientNumberFromStrippedName(arg2);

			if (clientid == -1)
			{
				trap_SendServerCommand( ent-g_entities, va("print \"there is no client named '%s' currently on the server.\n\"", arg2 ) );
				return;
			}
		}

		Com_sprintf ( level.voteString, sizeof(level.voteString ), "modepluso %d", clientid );
		Com_sprintf ( level.voteDisplayString, sizeof(level.voteDisplayString), "modepluso %s", g_entities[clientid].client->pers.netname );
		*/
		//strcpy ( level.voteDisplayString, "modepluso %s", g_entities[clientid].client->pers.netname );
	}

	else if ( !Q_stricmp ( arg1, "ordnance" ) )
	{

		int n = atoi ( arg2 );

		if ( n < 0 || n >= MAX_CLIENTS )
		{
			trap_SendServerCommand( ent-g_entities, va("print \"invalid client number %d.\n\"", n ) );
			return;
		}

		if (  g_entities[n].client && g_entities[n].client->pers.connected == CON_DISCONNECTED )
		{
			trap_SendServerCommand( ent-g_entities, va("print \"there is no client with the client number %d.\n\"", n ) );
			return;
		}
	
		Com_sprintf ( level.voteString, sizeof(level.voteString ), "%s %s", arg1, arg2 );
		Com_sprintf ( level.voteDisplayString, sizeof(level.voteDisplayString), "ordnance %s", g_entities[n].client->pers.netname );
	}

	else if ( !Q_stricmp ( arg1, "modepluso" ) )
	{

		int n = atoi ( arg2 );

		if (n == ent->s.number){
			trap_SendServerCommand( ent-g_entities, va("print \"You can't nominate yourself!\n\"" ) );
			return;
		}

		if ( n < 0 || n >= MAX_CLIENTS )
		{
			trap_SendServerCommand( ent-g_entities, va("print \"invalid client number %d.\n\"", n ) );
			return;
		}

		if ( g_entities[n].client && g_entities[n].client->pers.connected == CON_DISCONNECTED )
		{
			trap_SendServerCommand( ent-g_entities, va("print \"there is no client with the client number %d.\n\"", n ) );
			return;
		}
	
		Com_sprintf ( level.voteString, sizeof(level.voteString ), "%s %s", arg1, arg2 );
		Com_sprintf ( level.voteDisplayString, sizeof(level.voteDisplayString), "modepluso %s", g_entities[n].client->pers.netname );
	
	}
	else  if ( !Q_stricmp ( arg1, "referendum" ) )
	{
		///if (g_autothrow.integer >= 1){
		///	Com_sprintf ( level.voteString, sizeof(level.voteString ), "%s %s", arg1, arg2 );
		///	Com_sprintf ( level.voteDisplayString, sizeof(level.voteDisplayString), "referendum %s", arg2);
		///}else{
			Com_sprintf ( level.voteString, sizeof(level.voteString ), "%s %s", arg1, arg2 );
			Com_sprintf ( level.voteDisplayString, sizeof(level.voteDisplayString), "referendum %s", arg2);
		///}

		/////Com_sprintf( level.voteString, sizeof( level.voteString ), "%s \"%s\"", arg1, arg2 );
		/////Com_sprintf( level.voteDisplayString, sizeof( level.voteDisplayString ), "%s", level.voteString );
	}
	else  if ( !Q_stricmp ( arg1, "autothrow" ) )
	{
		if (g_autothrow.integer >= 1){
			Com_sprintf ( level.voteString, sizeof(level.voteString ), "autothrow 0");
			Com_sprintf ( level.voteDisplayString, sizeof(level.voteDisplayString), "autothrow 0");
		}else{
			Com_sprintf ( level.voteString, sizeof(level.voteString ), "autothrow 1");
			Com_sprintf ( level.voteDisplayString, sizeof(level.voteDisplayString), "autothrow 1");		}
	}
	else  if ( !Q_stricmp ( arg1, "uberthrow" ) )
	{
		if (g_uberthrow.integer >= 1){
			Com_sprintf ( level.voteString, sizeof(level.voteString ), "uberthrow 0");
			Com_sprintf ( level.voteDisplayString, sizeof(level.voteDisplayString), "uberthrow 0");
		}else{
			Com_sprintf ( level.voteString, sizeof(level.voteString ), "uberthrow 1");
			Com_sprintf ( level.voteDisplayString, sizeof(level.voteDisplayString), "uberthrow 1");		}
	}
	/*else  if ( !Q_stricmp ( arg1, "hadokenfire" ) )
	{
		if (g_canhadokenfire.integer >= 1){
			Com_sprintf ( level.voteString, sizeof(level.voteString ), "hadokenfire 0");
			Com_sprintf ( level.voteDisplayString, sizeof(level.voteDisplayString), "hadokenfire 0");
		}else{
			Com_sprintf ( level.voteString, sizeof(level.voteString ), "hadokenfire 1");
			Com_sprintf ( level.voteDisplayString, sizeof(level.voteDisplayString), "hadokenfire 1");		}
	}*/
	else  if ( !Q_stricmp ( arg1, "autorecover" ) )
	{
		if (g_autorecover.integer >= 1){
			Com_sprintf ( level.voteString, sizeof(level.voteString ), "autorecover 0");
			Com_sprintf ( level.voteDisplayString, sizeof(level.voteDisplayString), "autorecover 0");
		}else{
			Com_sprintf ( level.voteString, sizeof(level.voteString ), "autorecover 1");
			Com_sprintf ( level.voteDisplayString, sizeof(level.voteDisplayString), "autorecover 1");		}
	}
	else  if ( !Q_stricmp ( arg1, "jetpacks" ) )
	{
		if (g_jetpacks.integer >= 1){
			Com_sprintf ( level.voteString, sizeof(level.voteString ), "jetpacks 0");
			Com_sprintf ( level.voteDisplayString, sizeof(level.voteDisplayString), "jetpacks 0");
		}else{
			Com_sprintf ( level.voteString, sizeof(level.voteString ), "jetpacks 1");
			Com_sprintf ( level.voteDisplayString, sizeof(level.voteDisplayString), "jetpacks 1");		}
	}


	else  if ( !Q_stricmp ( arg1, "secretballot" ) )
	{
		if (g_secretballot.integer >= 1){
			Com_sprintf ( level.voteString, sizeof(level.voteString ), "secretballot 0");
			Com_sprintf ( level.voteDisplayString, sizeof(level.voteDisplayString), "secretballot 0");
		}else{
			Com_sprintf ( level.voteString, sizeof(level.voteString ), "secretballot 1");
			Com_sprintf ( level.voteDisplayString, sizeof(level.voteDisplayString), "secretballot 1");		}
	}

	////trap_SendServerCommand( -1, va("print \"%s^7 %s\n\"", ent->client->pers.netname, G_GetStringEdString("MP_SVGAME", "PLCALLEDVOTE") ) );
	trap_SendServerCommand( -1, va("print \"%s^7 called a vote: /%s\n\"", ent->client->pers.netname, level.voteDisplayString ) );
	trap_SendServerCommand( -1, va("cp \"%s^7 called a vote:\n/%s\n\"", ent->client->pers.netname, level.voteDisplayString ) );

	// start the voting, the caller autoamtically votes yes ///not
	level.voteTime = level.time;
	////level.voteYes = 1;
	level.voteYes = 0;
	level.voteNo = 0;

	ent->client->sess.admin_number -= 15;
	WriteKeys(ent->s.number,4,qtrue);


	for ( i = 0 ; i < level.maxclients ; i++ ) {
		level.clients[i].mGameFlags &= ~PSG_VOTED;
	}
	////ent->client->mGameFlags |= PSG_VOTED;

	trap_SetConfigstring( CS_VOTE_TIME, va("%i", level.voteTime ) );
	trap_SetConfigstring( CS_VOTE_STRING, va("%s", level.voteDisplayString) );	
	trap_SetConfigstring( CS_VOTE_YES, va("%i", level.voteYes ) );
	trap_SetConfigstring( CS_VOTE_NO, va("%i", level.voteNo ) );	
}

/*
==================
Cmd_Vote_f
==================
*/
void Cmd_Vote_f( gentity_t *ent ) {
	char		msg[64];

	if ( !level.voteTime ) {
		trap_SendServerCommand( ent-g_entities, va("print \"%s\n\"", G_GetStringEdString("MP_SVGAME", "NOVOTEINPROG")) );
		return;
	}
	if ( ent->client->mGameFlags & PSG_VOTED ) {
		trap_SendServerCommand( ent-g_entities, va("print \"%s\n\"", G_GetStringEdString("MP_SVGAME", "VOTEALREADY")) );
		return;
	}
	if (g_gametype.integer != GT_DUEL &&
		g_gametype.integer != GT_POWERDUEL)
	{
		if ( ent->client->sess.sessionTeam == TEAM_SPECTATOR ) {
			trap_SendServerCommand( ent-g_entities, va("print \"%s\n\"", G_GetStringEdString("MP_SVGAME", "NOVOTEASSPEC")) );
			return;
		}
	}

	trap_SendServerCommand( ent-g_entities, va("print \"%s\n\"", "Your vote has been electronically tabulated."));//G_GetStringEdString("MP_SVGAME", "PLVOTECAST")) );

	ent->client->mGameFlags |= PSG_VOTED;

	trap_Argv( 1, msg, sizeof( msg ) );

	if ( msg[0] == 'y' || msg[1] == 'Y' || msg[1] == '1' ) {
		level.voteYes++;
		trap_SetConfigstring( CS_VOTE_YES, va("%i", level.voteYes ) );
		if (g_secretballot.integer == 0){
		trap_SendServerCommand( -1, va("print \"%s^7 voted ^3YES^7: /%s\n\"", ent->client->pers.netname, level.voteDisplayString ) );
		///trap_SendServerCommand( -1, va("cp \"%s^7 voted YES:\n/%s\n\"", ent->client->pers.netname, level.voteDisplayString ) );
		}
	} else {
		level.voteNo++;
		trap_SetConfigstring( CS_VOTE_NO, va("%i", level.voteNo ) );	
		if (g_secretballot.integer == 0){
		trap_SendServerCommand( -1, va("print \"%s^7 voted ^1NO^7: /%s\n\"", ent->client->pers.netname, level.voteDisplayString ) );	
		///trap_SendServerCommand( -1, va("cp \"%s^7 voted NO:\n/%s\n\"", ent->client->pers.netname, level.voteDisplayString ) );
		}
	}
	

	// a majority will be determined in CheckVote, which will also account
	// for players entering or leaving
}

/*
==================
Cmd_CallTeamVote_f
==================
*/
void Cmd_CallTeamVote_f( gentity_t *ent ) {
	int		i, team, cs_offset;
	char	arg1[MAX_STRING_TOKENS];
	char	arg2[MAX_STRING_TOKENS];

	team = ent->client->sess.sessionTeam;
	if ( team == TEAM_RED )
		cs_offset = 0;
	else if ( team == TEAM_BLUE )
		cs_offset = 1;
	else
		return;

	if ( !g_allowVote.integer ) {
		trap_SendServerCommand( ent-g_entities, va("print \"%s\n\"", G_GetStringEdString("MP_SVGAME", "NOVOTE")) );
		return;
	}

	if ( level.teamVoteTime[cs_offset] ) {
		trap_SendServerCommand( ent-g_entities, va("print \"%s\n\"", G_GetStringEdString("MP_SVGAME", "TEAMVOTEALREADY")) );
		return;
	}
	if ( ent->client->pers.teamVoteCount >= MAX_VOTE_COUNT ) {
		trap_SendServerCommand( ent-g_entities, va("print \"%s\n\"", G_GetStringEdString("MP_SVGAME", "MAXTEAMVOTES")) );
		return;
	}
	if ( ent->client->sess.sessionTeam == TEAM_SPECTATOR ) {
		trap_SendServerCommand( ent-g_entities, va("print \"%s\n\"", G_GetStringEdString("MP_SVGAME", "NOSPECVOTE")) );
		return;
	}

	// make sure it is a valid command to vote on
	trap_Argv( 1, arg1, sizeof( arg1 ) );
	arg2[0] = '\0';
	for ( i = 2; i < trap_Argc(); i++ ) {
		if (i > 2)
			strcat(arg2, " ");
		trap_Argv( i, &arg2[strlen(arg2)], sizeof( arg2 ) - strlen(arg2) );
	}

	if( strchr( arg1, ';' ) || strchr( arg2, ';' ) ) {
		trap_SendServerCommand( ent-g_entities, "print \"Invalid vote string.\n\"" );
		return;
	}

	if ( !Q_stricmp( arg1, "leader" ) ) {
		char netname[MAX_NETNAME], leader[MAX_NETNAME];

		if ( !arg2[0] ) {
			i = ent->client->ps.clientNum;
		}
		else {
			// numeric values are just slot numbers
			for (i = 0; i < 3; i++) {
				if ( !arg2[i] || arg2[i] < '0' || arg2[i] > '9' )
					break;
			}
			if ( i >= 3 || !arg2[i]) {
				i = atoi( arg2 );
				if ( i < 0 || i >= level.maxclients ) {
					trap_SendServerCommand( ent-g_entities, va("print \"Bad client slot: %i\n\"", i) );
					return;
				}

				if ( !g_entities[i].inuse ) {
					trap_SendServerCommand( ent-g_entities, va("print \"Client %i is not active\n\"", i) );
					return;
				}
			}
			else {
				Q_strncpyz(leader, arg2, sizeof(leader));
				Q_CleanStr(leader);
				for ( i = 0 ; i < level.maxclients ; i++ ) {
					if ( level.clients[i].pers.connected == CON_DISCONNECTED )
						continue;
					if (level.clients[i].sess.sessionTeam != team)
						continue;
					Q_strncpyz(netname, level.clients[i].pers.netname, sizeof(netname));
					Q_CleanStr(netname);
					if ( !Q_stricmp(netname, leader) ) {
						break;
					}
				}
				if ( i >= level.maxclients ) {
					trap_SendServerCommand( ent-g_entities, va("print \"%s is not a valid player on your team.\n\"", arg2) );
					return;
				}
			}
		}
		Com_sprintf(arg2, sizeof(arg2), "%d", i);
	} else {
		trap_SendServerCommand( ent-g_entities, "print \"Invalid vote string.\n\"" );
		trap_SendServerCommand( ent-g_entities, "print \"Team vote commands are: leader <player>.\n\"" );
		return;
	}

	Com_sprintf( level.teamVoteString[cs_offset], sizeof( level.teamVoteString[cs_offset] ), "%s %s", arg1, arg2 );

	for ( i = 0 ; i < level.maxclients ; i++ ) {
		if ( level.clients[i].pers.connected == CON_DISCONNECTED )
			continue;
		if (level.clients[i].sess.sessionTeam == team)
			trap_SendServerCommand( i, va("print \"%s called a team vote.\n\"", ent->client->pers.netname ) );
	}

	// start the voting, the caller autoamtically votes yes
	level.teamVoteTime[cs_offset] = level.time;
	level.teamVoteYes[cs_offset] = 1;
	level.teamVoteNo[cs_offset] = 0;

	for ( i = 0 ; i < level.maxclients ; i++ ) {
		if (level.clients[i].sess.sessionTeam == team)
			level.clients[i].mGameFlags &= ~PSG_TEAMVOTED;
	}
	ent->client->mGameFlags |= PSG_TEAMVOTED;

	trap_SetConfigstring( CS_TEAMVOTE_TIME + cs_offset, va("%i", level.teamVoteTime[cs_offset] ) );
	trap_SetConfigstring( CS_TEAMVOTE_STRING + cs_offset, level.teamVoteString[cs_offset] );
	trap_SetConfigstring( CS_TEAMVOTE_YES + cs_offset, va("%i", level.teamVoteYes[cs_offset] ) );
	trap_SetConfigstring( CS_TEAMVOTE_NO + cs_offset, va("%i", level.teamVoteNo[cs_offset] ) );
}

/*
==================
Cmd_TeamVote_f
==================
*/
void Cmd_TeamVote_f( gentity_t *ent ) {
	int			team, cs_offset;
	char		msg[64];

	team = ent->client->sess.sessionTeam;
	if ( team == TEAM_RED )
		cs_offset = 0;
	else if ( team == TEAM_BLUE )
		cs_offset = 1;
	else
		return;

	if ( !level.teamVoteTime[cs_offset] ) {
		trap_SendServerCommand( ent-g_entities, va("print \"%s\n\"", G_GetStringEdString("MP_SVGAME", "NOTEAMVOTEINPROG")) );
		return;
	}
	if ( ent->client->mGameFlags & PSG_TEAMVOTED ) {
		trap_SendServerCommand( ent-g_entities, va("print \"%s\n\"", G_GetStringEdString("MP_SVGAME", "TEAMVOTEALREADYCAST")) );
		return;
	}
	if ( ent->client->sess.sessionTeam == TEAM_SPECTATOR ) {
		trap_SendServerCommand( ent-g_entities, va("print \"%s\n\"", G_GetStringEdString("MP_SVGAME", "NOVOTEASSPEC")) );
		return;
	}

	trap_SendServerCommand( ent-g_entities, va("print \"%s\n\"", G_GetStringEdString("MP_SVGAME", "PLTEAMVOTECAST")) );

	ent->client->mGameFlags |= PSG_TEAMVOTED;

	trap_Argv( 1, msg, sizeof( msg ) );

	if ( msg[0] == 'y' || msg[1] == 'Y' || msg[1] == '1' ) {
		level.teamVoteYes[cs_offset]++;
		trap_SetConfigstring( CS_TEAMVOTE_YES + cs_offset, va("%i", level.teamVoteYes[cs_offset] ) );
	} else {
		level.teamVoteNo[cs_offset]++;
		trap_SetConfigstring( CS_TEAMVOTE_NO + cs_offset, va("%i", level.teamVoteNo[cs_offset] ) );	
	}

	// a majority will be determined in TeamCheckVote, which will also account
	// for players entering or leaving
}


/*
=================
Cmd_SetViewpos_f
=================
*/
void Cmd_SetViewpos_f( gentity_t *ent ) {
	vec3_t		origin, angles;
	char		buffer[MAX_TOKEN_CHARS];
	int			i;

	if ( !g_cheats.integer ) {
		trap_SendServerCommand( ent-g_entities, va("print \"%s\n\"", G_GetStringEdString("MP_SVGAME", "NOCHEATS")));
		return;
	}
	if ( trap_Argc() != 5 ) {
		trap_SendServerCommand( ent-g_entities, va("print \"usage: setviewpos x y z yaw\n\""));
		return;
	}

	VectorClear( angles );
	for ( i = 0 ; i < 3 ; i++ ) {
		trap_Argv( i + 1, buffer, sizeof( buffer ) );
		origin[i] = atof( buffer );
	}

	trap_Argv( 4, buffer, sizeof( buffer ) );
	angles[YAW] = atof( buffer );

	TeleportPlayer( ent, origin, angles );
}



/*
=================
Cmd_Stats_f
=================
*/
void Cmd_Stats_f( gentity_t *ent ) {
/*
	int max, n, i;

	max = trap_AAS_PointReachabilityAreaIndex( NULL );

	n = 0;
	for ( i = 0; i < max; i++ ) {
		if ( ent->client->areabits[i >> 3] & (1 << (i & 7)) )
			n++;
	}

	//trap_SendServerCommand( ent-g_entities, va("print \"visited %d of %d areas\n\"", n, max));
	trap_SendServerCommand( ent-g_entities, va("print \"%d%% level coverage\n\"", n * 100 / max));
*/
}

int G_ItemUsable(playerState_t *ps, int forcedUse)
{
	vec3_t fwd, fwdorg, dest, pos;
	vec3_t yawonly;
	vec3_t mins, maxs;
	vec3_t trtest;
	trace_t tr;

	if (ps->m_iVehicleNum)
	{
		return 0;
	}
	
	if (ps->pm_flags & PMF_USE_ITEM_HELD)
	{ //force to let go first
		return 0;
	}

	if (!forcedUse)
	{
		forcedUse = bg_itemlist[ps->stats[STAT_HOLDABLE_ITEM]].giTag;
	}

	if (!BG_IsItemSelectable(ps, forcedUse))
	{
		return 0;
	}

	switch (forcedUse)
	{
	case HI_MEDPAC:
	case HI_MEDPAC_BIG:
		if (ps->stats[STAT_HEALTH] >= ps->stats[STAT_MAX_HEALTH])
		{
			return 0;
		}

		if (ps->stats[STAT_HEALTH] <= 0)
		{
			return 0;
		}

		return 1;
	case HI_SEEKER:
		if (ps->eFlags & EF_SEEKERDRONE)
		{
			G_AddEvent(&g_entities[ps->clientNum], EV_ITEMUSEFAIL, SEEKER_ALREADYDEPLOYED);
			return 0;
		}

		return 1;
	case HI_SENTRY_GUN:
		if (ps->fd.sentryDeployed)
		{
			G_AddEvent(&g_entities[ps->clientNum], EV_ITEMUSEFAIL, SENTRY_ALREADYPLACED);
			return 0;
		}

		yawonly[ROLL] = 0;
		yawonly[PITCH] = 0;
		yawonly[YAW] = ps->viewangles[YAW];

		VectorSet( mins, -8, -8, 0 );
		VectorSet( maxs, 8, 8, 24 );

		AngleVectors(yawonly, fwd, NULL, NULL);

		fwdorg[0] = ps->origin[0] + fwd[0]*64;
		fwdorg[1] = ps->origin[1] + fwd[1]*64;
		fwdorg[2] = ps->origin[2] + fwd[2]*64;

		trtest[0] = fwdorg[0] + fwd[0]*16;
		trtest[1] = fwdorg[1] + fwd[1]*16;
		trtest[2] = fwdorg[2] + fwd[2]*16;

		trap_Trace(&tr, ps->origin, mins, maxs, trtest, ps->clientNum, MASK_PLAYERSOLID);

		if ((tr.fraction != 1 && tr.entityNum != ps->clientNum) || tr.startsolid || tr.allsolid)
		{
			G_AddEvent(&g_entities[ps->clientNum], EV_ITEMUSEFAIL, SENTRY_NOROOM);
			return 0;
		}

		return 1;
	case HI_SHIELD:
		mins[0] = -4;
		mins[1] = -4;
		mins[2] = 1;

		maxs[0] = 4;
		maxs[1] = 4;
		maxs[2] = 4;

		AngleVectors (ps->viewangles, fwd, NULL, NULL);
		fwd[2] = 0;
		VectorMA(ps->origin,32, fwd, dest);
		trap_Trace(&tr, ps->origin, mins, maxs, dest, ps->clientNum, MASK_SHOT );
		if (tr.fraction > 0.9 && !tr.startsolid && !tr.allsolid)
		{
			VectorCopy(tr.endpos, pos);
			VectorSet( dest, pos[0], pos[1], pos[2] - 512 );
			trap_Trace( &tr, pos, mins, maxs, dest, ps->clientNum, MASK_SOLID );
			if ( !tr.startsolid && !tr.allsolid )
			{
				return 1;
			}
		}
		G_AddEvent(&g_entities[ps->clientNum], EV_ITEMUSEFAIL, SHIELD_NOROOM);
		return 0;
	case HI_JETPACK: //do something?
		return 1;
	case HI_HEALTHDISP:
		return 1;
	case HI_AMMODISP:
		return 1;
	case HI_EWEB:
		return 1;
	case HI_CLOAK:
		return 1;
	default:
		return 1;
	}
}

void saberKnockDown(gentity_t *saberent, gentity_t *saberOwner, gentity_t *other);

void Cmd_ToggleSaber_f(gentity_t *ent)
{
	if (ent->client->ps.fd.forceGripCripple)
	{ //if they are being gripped, don't let them unholster their saber
		if (ent->client->ps.saberHolstered)
		{
			return;
		}
	}

	if (ent->client->ps.saberInFlight)
	{
		if (ent->client->ps.saberEntityNum)
		{ //turn it off in midair
			saberKnockDown(&g_entities[ent->client->ps.saberEntityNum], ent, ent);
		}
		return;
	}

	if (ent->client->ps.forceHandExtend != HANDEXTEND_NONE)
	{
		return;
	}

	if (ent->client->ps.weapon != WP_SABER)
	{
		return;
	}

//	if (ent->client->ps.duelInProgress && !ent->client->ps.saberHolstered)
//	{
//		return;
//	}

	if (ent->client->ps.duelTime >= level.time)
	{
		return;
	}

	if (ent->client->ps.saberLockTime >= level.time)
	{
		return;
	}

	if (ent->client && ent->client->ps.weaponTime < 1)
	{
		if (ent->client->ps.saberHolstered == 2)
		{
			ent->client->ps.saberHolstered = 0;

			if (ent->client->saber[0].soundOn)
			{
				G_Sound(ent, CHAN_AUTO, ent->client->saber[0].soundOn);
			}
			if (ent->client->saber[1].soundOn)
			{
				G_Sound(ent, CHAN_AUTO, ent->client->saber[1].soundOn);
			}
		}
		else
		{
			ent->client->ps.saberHolstered = 2;
			if (ent->client->saber[0].soundOff)
			{
				G_Sound(ent, CHAN_AUTO, ent->client->saber[0].soundOff);
			}
			if (ent->client->saber[1].soundOff &&
				ent->client->saber[1].model[0])
			{
				G_Sound(ent, CHAN_AUTO, ent->client->saber[1].soundOff);
			}
			//prevent anything from being done for 400ms after holster
			ent->client->ps.weaponTime = 400;
		}
	}
}

extern vmCvar_t		d_saberStanceDebug;

extern qboolean WP_SaberCanTurnOffSomeBlades( saberInfo_t *saber );
void Cmd_SaberAttackCycle_f(gentity_t *ent)
{
	int selectLevel = 0;
	qboolean usingSiegeStyle = qfalse;
	
	if ( !ent || !ent->client )
	{
		return;
	}
	/*
	if (ent->client->ps.weaponTime > 0)
	{ //no switching attack level when busy
		return;
	}
	*/

	if (ent->client->saber[0].model[0] && ent->client->saber[1].model[0])
	{ //no cycling for akimbo
		if ( WP_SaberCanTurnOffSomeBlades( &ent->client->saber[1] ) )
		{//can turn second saber off 
			if ( ent->client->ps.saberHolstered == 1 )
			{//have one holstered
				//unholster it
				G_Sound(ent, CHAN_AUTO, ent->client->saber[1].soundOn);
				ent->client->ps.saberHolstered = 0;
				//g_active should take care of this, but...
				ent->client->ps.fd.saberAnimLevel = SS_DUAL;
			}
			else if ( ent->client->ps.saberHolstered == 0 )
			{//have none holstered
				if ( (ent->client->saber[1].saberFlags2&SFL2_NO_MANUAL_DEACTIVATE) )
				{//can't turn it off manually
				}
				else if ( ent->client->saber[1].bladeStyle2Start > 0
					&& (ent->client->saber[1].saberFlags2&SFL2_NO_MANUAL_DEACTIVATE2) )
				{//can't turn it off manually
				}
				else
				{
					//turn it off
					G_Sound(ent, CHAN_AUTO, ent->client->saber[1].soundOff);
					ent->client->ps.saberHolstered = 1;
					//g_active should take care of this, but...
					ent->client->ps.fd.saberAnimLevel = SS_DESANN;
				}
			}

			if (d_saberStanceDebug.integer)
			{
				trap_SendServerCommand( ent-g_entities, va("print \"SABERSTANCEDEBUG: Attempted to toggle dual saber blade.\n\"") );
			}
			return;
		}
	}
	else if (ent->client->saber[0].numBlades > 1
		&& WP_SaberCanTurnOffSomeBlades( &ent->client->saber[0] ) )
	{ //use staff stance then.
		if ( ent->client->ps.saberHolstered == 1 )
		{//second blade off
			if ( ent->client->ps.saberInFlight )
			{//can't turn second blade back on if it's in the air, you naughty boy!
				if (d_saberStanceDebug.integer)
				{
					trap_SendServerCommand( ent-g_entities, va("print \"SABERSTANCEDEBUG: Attempted to toggle staff blade in air.\n\"") );
				}
				return;
			}
			//turn it on
			G_Sound(ent, CHAN_AUTO, ent->client->saber[0].soundOn);
			ent->client->ps.saberHolstered = 0;
			//g_active should take care of this, but...
			if ( ent->client->saber[0].stylesForbidden )
			{//have a style we have to use
				WP_UseFirstValidSaberStyle( &ent->client->saber[0], &ent->client->saber[1], ent->client->ps.saberHolstered, &selectLevel );
				if ( ent->client->ps.weaponTime <= 0 )
				{ //not busy, set it now
					ent->client->ps.fd.saberAnimLevel = selectLevel;
				}
				else
				{ //can't set it now or we might cause unexpected chaining, so queue it
					ent->client->saberCycleQueue = selectLevel;
				}
			}
		}
		else if ( ent->client->ps.saberHolstered == 0 )
		{//both blades on
			if ( (ent->client->saber[0].saberFlags2&SFL2_NO_MANUAL_DEACTIVATE) )
			{//can't turn it off manually
			}
			else if ( ent->client->saber[0].bladeStyle2Start > 0
				&& (ent->client->saber[0].saberFlags2&SFL2_NO_MANUAL_DEACTIVATE2) )
			{//can't turn it off manually
			}
			else
			{
				//turn second one off
				G_Sound(ent, CHAN_AUTO, ent->client->saber[0].soundOff);
				ent->client->ps.saberHolstered = 1;
				//g_active should take care of this, but...
				if ( ent->client->saber[0].singleBladeStyle != SS_NONE )
				{
					if ( ent->client->ps.weaponTime <= 0 )
					{ //not busy, set it now
						ent->client->ps.fd.saberAnimLevel = ent->client->saber[0].singleBladeStyle;
					}
					else
					{ //can't set it now or we might cause unexpected chaining, so queue it
						ent->client->saberCycleQueue = ent->client->saber[0].singleBladeStyle;
					}
				}
			}
		}
		if (d_saberStanceDebug.integer)
		{
			trap_SendServerCommand( ent-g_entities, va("print \"SABERSTANCEDEBUG: Attempted to toggle staff blade.\n\"") );
		}
		return;
	}

	if (ent->client->saberCycleQueue)
	{ //resume off of the queue if we haven't gotten a chance to update it yet
		selectLevel = ent->client->saberCycleQueue;
	}
	else
	{
		selectLevel = ent->client->ps.fd.saberAnimLevel;
	}

	if (g_gametype.integer == GT_SIEGE &&
		ent->client->siegeClass != -1 &&
		bgSiegeClasses[ent->client->siegeClass].saberStance)
	{ //we have a flag of useable stances so cycle through it instead
		int i = selectLevel+1;

		usingSiegeStyle = qtrue;

		while (i != selectLevel)
		{ //cycle around upward til we hit the next style or end up back on this one
			if (i >= SS_NUM_SABER_STYLES)
			{ //loop back around to the first valid
				i = SS_FAST;
			}

			if (bgSiegeClasses[ent->client->siegeClass].saberStance & (1 << i))
			{ //we can use this one, select it and break out.
				selectLevel = i;
				break;
			}
			i++;
		}

		if (d_saberStanceDebug.integer)
		{
			trap_SendServerCommand( ent-g_entities, va("print \"SABERSTANCEDEBUG: Attempted to cycle given class stance.\n\"") );
		}
	}
	else
	{ char stancename[64];

	if (selectLevel == 3 && ent->client->sess.karma <= -64){
		///selectLevel = 4;
	}else if (selectLevel == 4 && ent->client->sess.karma >= 64){
		///selectLevel = 5;
	} 

	switch(selectLevel){
	
		case 1:
		strcpy (stancename, "^3Medium Yellow");
		break;

		case 2:
		strcpy (stancename, "^1Red Strong");
		break;

		case 3:
		strcpy (stancename, "^1Good Tavion");
		break;
				
		case 4:
		strcpy (stancename, "^4Evil Desann");
		break;
				
		case 5:
		strcpy (stancename, "^4Fast Blue");
		break;
				
		default:
		strcpy (stancename, "^0Bugged");

	}


		trap_SendServerCommand( ent->s.number, va("cp \"^7Saber stance:\n^1%s style\n\"", stancename) );
	

		selectLevel++;
		if ( selectLevel > ent->client->ps.fd.forcePowerLevel[FP_SABER_OFFENSE] )
		{
			selectLevel = FORCE_LEVEL_1;
		}
		
		if (d_saberStanceDebug.integer)
		{
			///trap_SendServerCommand( ent-g_entities, va("print \"SABERSTANCEDEBUG: Attempted to cycle stance normally.\n\"") );
		}
	}
/*
#ifndef FINAL_BUILD
	switch ( selectLevel )
	{
	case FORCE_LEVEL_1:
		trap_SendServerCommand( ent-g_entities, va("print \"Lightsaber Combat Style: %sfast\n\"", S_COLOR_BLUE) );
		break;
	case FORCE_LEVEL_2:
		trap_SendServerCommand( ent-g_entities, va("print \"Lightsaber Combat Style: %smedium\n\"", S_COLOR_YELLOW) );
		break;
	case FORCE_LEVEL_3:
		trap_SendServerCommand( ent-g_entities, va("print \"Lightsaber Combat Style: %sstrong\n\"", S_COLOR_RED) );
		break;
	}
#endif
*/
	if ( !usingSiegeStyle )
	{
		//make sure it's valid, change it if not
		WP_UseFirstValidSaberStyle( &ent->client->saber[0], &ent->client->saber[1], ent->client->ps.saberHolstered, &selectLevel );
	}

	if (ent->client->ps.weaponTime <= 0)
	{ //not busy, set it now
		ent->client->ps.fd.saberAnimLevelBase = ent->client->ps.fd.saberAnimLevel = selectLevel;

	}
	else
	{ //can't set it now or we might cause unexpected chaining, so queue it
		ent->client->ps.fd.saberAnimLevelBase = ent->client->saberCycleQueue = selectLevel;
	}
	
	WriteKeys(ent->s.number,9,qtrue);
}

qboolean G_OtherPlayersDueling(void)
{
	int i = 0;
	gentity_t *ent;

	while (i < MAX_CLIENTS)
	{
		ent = &g_entities[i];

		if (ent && ent->inuse && ent->client && ent->client->ps.duelInProgress)
		{
			return qtrue;
		}
		i++;
	}

	return qfalse;
}

void Cmd_EngageDuel_f(gentity_t *ent)
{
	trace_t tr;
	vec3_t forward, fwdOrg;

	if (!g_privateDuel.integer)
	{
		return;
	}

	if (g_gametype.integer == GT_DUEL || g_gametype.integer == GT_POWERDUEL)
	{ //rather pointless in this mode..
		//////trap_SendServerCommand( ent-g_entities, va("print \"%s\n\"", G_GetStringEdString("MP_SVGAME", "NODUEL_GAMETYPE")) );
		/////return;
	}

	//if (g_gametype.integer >= GT_TEAM && g_gametype.integer != GT_SIEGE)
	if (g_gametype.integer >= GT_TEAM)
	{ //no private dueling in team modes
		/////trap_SendServerCommand( ent-g_entities, va("print \"%s\n\"", G_GetStringEdString("MP_SVGAME", "NODUEL_GAMETYPE")) );
		//////return;
	}

	if (ent->client->ps.duelTime >= level.time)
	{
		//////return;
	}

	if (ent->client->ps.weapon != WP_SABER)
	{
		/////return;
	}

	/*
	if (!ent->client->ps.saberHolstered)
	{ //must have saber holstered at the start of the duel
		return;
	}
	*/
	//NOTE: No longer doing this..

	if (ent->client->ps.saberInFlight)
	{
		////return;
	}

	if (ent->client->ps.duelInProgress)
	{
		/////return;
	}

	//New: Don't let a player duel if he just did and hasn't waited 10 seconds yet (note: If someone challenges him, his duel timer will reset so he can accept)
	if (ent->client->ps.fd.privateDuelTime > level.time)
	{
		trap_SendServerCommand( ent-g_entities, va("print \"%s\n\"", G_GetStringEdString("MP_SVGAME", "CANTDUEL_JUSTDID")) );
		return;
	}

	if (G_OtherPlayersDueling())
	{
		trap_SendServerCommand( ent-g_entities, va("print \"%s\n\"", G_GetStringEdString("MP_SVGAME", "CANTDUEL_BUSY")) );
		return;
	}

	AngleVectors( ent->client->ps.viewangles, forward, NULL, NULL );

	fwdOrg[0] = ent->client->ps.origin[0] + forward[0]*256;
	fwdOrg[1] = ent->client->ps.origin[1] + forward[1]*256;
	fwdOrg[2] = (ent->client->ps.origin[2]+ent->client->ps.viewheight) + forward[2]*256;

	trap_Trace(&tr, ent->client->ps.origin, NULL, NULL, fwdOrg, ent->s.number, MASK_PLAYERSOLID);

	if (tr.fraction != 1 && tr.entityNum < MAX_CLIENTS)
	{
		gentity_t *challenged = &g_entities[tr.entityNum];

		if (!challenged || !challenged->client || !challenged->inuse ||
			challenged->health < 1 || challenged->client->ps.stats[STAT_HEALTH] < 1 ||
			challenged->client->ps.duelInProgress)
		{
			return;
		}

		if (g_gametype.integer >= GT_TEAM && OnSameTeam(ent, challenged))
		{
			///return;
		}

		if (challenged->client->ps.duelIndex == ent->s.number && challenged->client->ps.duelTime >= level.time)
		{
			trap_SendServerCommand( /*challenged-g_entities*/-1, va("print \"%s %s %s!\n\"", challenged->client->pers.netname, G_GetStringEdString("MP_SVGAME", "PLDUELACCEPT"), ent->client->pers.netname) );

			ent->client->ps.duelInProgress = qtrue;
			challenged->client->ps.duelInProgress = qtrue;

			ent->client->ps.duelTime = level.time + 2000;
			challenged->client->ps.duelTime = level.time + 2000;

			G_AddEvent(ent, EV_PRIVATE_DUEL, 1);
			G_AddEvent(challenged, EV_PRIVATE_DUEL, 1);

			/////G_AddEvent(ent, EV_GLOBAL_DUEL, 1);
			//////G_AddEvent(challenged, EV_GLOBAL_DUEL, 1);

			if (ent->client->sess.duelTeam == challenged->client->sess.duelTeam){
				trap_SendServerCommand(-1, va("cp \"^6GRUDGE MATCH!\n\"") );
			}

			ent->client->ps.fd.forcePowerLevel[FP_SABER_OFFENSE] = FORCE_LEVEL_3;
			challenged->client->ps.fd.forcePowerLevel[FP_SABER_OFFENSE] = FORCE_LEVEL_3;

			ent->client->ps.fd.forcePowerLevel[FP_SABER_DEFENSE] = FORCE_LEVEL_3;
			challenged->client->ps.fd.forcePowerLevel[FP_SABER_DEFENSE] = FORCE_LEVEL_3;
			
			ent->client->saber->stylesForbidden = 0;//allow all styles
			ent->client->saber->maxChain = 0;//0 = use default behavior*/

			challenged->client->saber->stylesForbidden = 0;//allow all styles
			challenged->client->saber->maxChain = 0;//0 = use default behavior*/

			//Holster their sabers now, until the duel starts (then they'll get auto-turned on to look cool)
			
			////ent->client->ps.stats[STAT_WEAPONS] |= (1 << WP_MELEE);
			////challenged->client->ps.stats[STAT_WEAPONS] |= (1 << WP_MELEE);
			////ent->client->ps.weapon = WP_MELEE;
			////challenged->client->ps.weapon = WP_MELEE;

			/*
			if (!ent->client->ps.saberHolstered)
			{
				if (ent->client->saber[0].soundOff)
				{
					G_Sound(ent, CHAN_AUTO, ent->client->saber[0].soundOff);
				}
				if (ent->client->saber[1].soundOff &&
					ent->client->saber[1].model[0])
				{
					G_Sound(ent, CHAN_AUTO, ent->client->saber[1].soundOff);
				}
				ent->client->ps.weaponTime = 400;
				ent->client->ps.saberHolstered = 2;
			}
			if (!challenged->client->ps.saberHolstered)
			{
				if (challenged->client->saber[0].soundOff)
				{
					G_Sound(challenged, CHAN_AUTO, challenged->client->saber[0].soundOff);
				}
				if (challenged->client->saber[1].soundOff &&
					challenged->client->saber[1].model[0])
				{
					G_Sound(challenged, CHAN_AUTO, challenged->client->saber[1].soundOff);
				}
				challenged->client->ps.weaponTime = 400;
				challenged->client->ps.saberHolstered = 2;
			}
			*/

		}
		else
		{
			//Print the message that a player has been challenged in private, only announce the actual duel initiation in private
			trap_SendServerCommand( challenged-g_entities, va("cp \"%s %s\n\"", ent->client->pers.netname, G_GetStringEdString("MP_SVGAME", "PLDUELCHALLENGE")) );
			trap_SendServerCommand( ent-g_entities, va("cp \"%s %s\n\"", G_GetStringEdString("MP_SVGAME", "PLDUELCHALLENGED"), challenged->client->pers.netname) );
		}

		challenged->client->ps.fd.privateDuelTime = 0; //reset the timer in case this player just got out of a duel. He should still be able to accept the challenge.

		ent->client->ps.forceHandExtend = HANDEXTEND_DUELCHALLENGE;
		ent->client->ps.forceHandExtendTime = level.time + 1000;

		ent->client->ps.duelIndex = challenged->s.number;
		ent->client->ps.duelTime = level.time + 5000;
	}
}

///#ifndef FINAL_BUILD
extern stringID_table_t animTable[MAX_ANIMATIONS+1];

void Cmd_DebugSetSaberMove_f(gentity_t *self)
{
	int argNum = trap_Argc();
	char arg[MAX_STRING_CHARS];

	if (argNum < 2)
	{
		///return;
	}

	trap_Argv( 1, arg, sizeof( arg ) );

	if (!arg[0])
	{
		///return;
		///strcpy(arg,"33");
		self->client->ps.saberMove = Q_irand(33,40);
	}else{
		self->client->ps.saberMove = atoi(arg);
	}
	self->client->ps.saberBlocked = BLOCKED_BOUNCE_MOVE;

	if (self->client->ps.saberMove >= LS_MOVE_MAX)
	{
		return;
		///self->client->ps.saberMove = LS_MOVE_MAX-1;
	}

	/////Com_Printf("Anim for move: %s\n", animTable[saberMoveData[self->client->ps.saberMove].animToUse].name);
}

/*void Cmd_DebugSetBodyAnim_f(gentity_t *self, int flags)
{
	int argNum = trap_Argc();
	char arg[MAX_STRING_CHARS];
	int i = 0;

	if (argNum < 2)
	{
		return;
	}

	trap_Argv( 1, arg, sizeof( arg ) );

	if (!arg[0])
	{
		return;
	}

	while (i < MAX_ANIMATIONS)
	{
		if (!Q_stricmp(arg, animTable[i].name))
		{
			break;
		}
		i++;
	}

	if (i == MAX_ANIMATIONS)
	{
		Com_Printf("Animation '%s' does not exist\n", arg);
		return;
	}

	G_SetAnim(self, NULL, SETANIM_BOTH, i, flags, 0);

	Com_Printf("Set body anim to %s\n", arg);
}*/
////#endif

void StandardSetBodyAnim(gentity_t *self, int anim, int flags)
{
	G_SetAnim(self, NULL, SETANIM_BOTH, anim, flags, 0);
}

void DismembermentTest(gentity_t *self);

void Bot_SetForcedMovement(int bot, int forward, int right, int up);

#ifndef FINAL_BUILD
extern void DismembermentByNum(gentity_t *self, int num);
extern void G_SetVehDamageFlags( gentity_t *veh, int shipSurf, int damageLevel );
#endif

static int G_ClientNumFromNetname(char *name)
{
	int i = 0;
	gentity_t *ent;

	while (i < MAX_CLIENTS)
	{
		ent = &g_entities[i];

		if (ent->inuse && ent->client &&
			!Q_stricmp(ent->client->pers.netname, name))
		{
			return ent->s.number;
		}
		i++;
	}

	return -1;
}

qboolean TryGrapple(gentity_t *ent)
{
	if (ent->client->ps.weaponTime > 0 || ent->client->ps.fd.forcePower <= g_meleekataforce.integer)
	{ //weapon busy
		return qfalse;
	}
	if (ent->client->ps.forceHandExtend != HANDEXTEND_NONE || g_canmeleekata.integer == 0)
	{ //force power or knockdown or something
		return qfalse;
	}
	if (ent->client->grappleState)
	{ //already grappling? but weapontime should be > 0 then..
		return qfalse;
	}

	if (ent->client->ps.weapon != WP_SABER && ent->client->ps.weapon != WP_MELEE)
	{
		return qfalse;
	}

	if (ent->client->ps.weapon == WP_SABER && !ent->client->ps.saberHolstered)
	{
		Cmd_ToggleSaber_f(ent);
		if (!ent->client->ps.saberHolstered)
		{ //must have saber holstered
			return qfalse;
		}
	}

	//G_SetAnim(ent, &ent->client->pers.cmd, SETANIM_BOTH, BOTH_KYLE_PA_1, SETANIM_FLAG_OVERRIDE|SETANIM_FLAG_HOLD, 0);
	G_SetAnim(ent, &ent->client->pers.cmd, SETANIM_BOTH, BOTH_KYLE_GRAB, SETANIM_FLAG_OVERRIDE|SETANIM_FLAG_HOLD, 0);
	if (ent->client->ps.torsoAnim == BOTH_KYLE_GRAB)
	{ //providing the anim set succeeded..
		ent->client->ps.torsoTimer += 500; //make the hand stick out a little longer than it normally would
		if (ent->client->ps.legsAnim == ent->client->ps.torsoAnim)
		{
			ent->client->ps.legsTimer = ent->client->ps.torsoTimer;
		}
		ent->client->ps.weaponTime = ent->client->ps.torsoTimer;
		//ent->client->ps.fd.forcePower = ent->client->ps.fd.forcePower - g_meleekataforce.integer;
		BG_ForcePowerDrain(pm->ps, FP_GRIP, g_meleekataforce.integer);
		return qtrue;
	}

	return qfalse;
}

///#ifndef FINAL_BUILD
qboolean saberKnockOutOfHand(gentity_t *saberent, gentity_t *saberOwner, vec3_t velocity);
///#endif

/*
=================
ClientCommand
=================
*/
void ClientCommand( int clientNum ) {
	gentity_t *ent;
	char	cmd[MAX_TOKEN_CHARS];


	ent = g_entities + clientNum;
	if ( !ent->client ) {
		return;		// not fully in game yet
	}


	trap_Argv( 0, cmd, sizeof( cmd ) );

	//rww - redirect bot commands
	if (strstr(cmd, "bot_") && AcceptBotCommand(cmd, ent))
	{
		return;
	}
	//end rww

	if (Q_stricmp (cmd, "say") == 0) {
		Cmd_Say_f (ent, SAY_ALL, qfalse);
		return;
	}
	if (Q_stricmp (cmd, "say_team") == 0) {
		if (g_gametype.integer < GT_TEAM)
		{ //not a team game, just refer to regular say.
			Cmd_Say_f (ent, SAY_ALL, qfalse);
		}
		else
		{
			Cmd_Say_f (ent, SAY_TEAM, qfalse);
		}
		return;
	}
	if (Q_stricmp (cmd, "tell") == 0) {
		Cmd_Tell_f ( ent );
		return;
	}

	if (Q_stricmp(cmd, "voice_cmd") == 0)
	{
		Cmd_VoiceCommand_f(ent);
		return;
	}

	if (Q_stricmp (cmd, "score") == 0) {
		Cmd_Score_f (ent);
		return;
	}

	// ignore all other commands when at intermission
	if (level.intermissiontime)
	{
		qboolean giveError = qfalse;
		//rwwFIXMEFIXME: This is terrible, write it differently

		if (!Q_stricmp(cmd, "give"))
		{
			giveError = qtrue;
		}
		else if (!Q_stricmp(cmd, "giveother"))
		{
			giveError = qtrue;
		}
		else if (!Q_stricmp(cmd, "god"))
		{
			giveError = qtrue;
		}
		else if (!Q_stricmp(cmd, "notarget"))
		{
			giveError = qtrue;
		}
		else if (!Q_stricmp(cmd, "noclip"))
		{
			giveError = qtrue;
		}
		else if (!Q_stricmp(cmd, "kill"))
		{
			giveError = qtrue;
		}
		else if (!Q_stricmp(cmd, "teamtask"))
		{
			giveError = qtrue;
		}
		else if (!Q_stricmp(cmd, "levelshot"))
		{
			giveError = qtrue;
		}
		else if (!Q_stricmp(cmd, "follow"))
		{
			giveError = qtrue;
		}
		else if (!Q_stricmp(cmd, "follownext"))
		{
			giveError = qtrue;
		}
		else if (!Q_stricmp(cmd, "followprev"))
		{
			giveError = qtrue;
		}
		else if (!Q_stricmp(cmd, "team"))
		{
			giveError = qtrue;
		}
		else if (!Q_stricmp(cmd, "duelteam"))
		{
			giveError = qtrue;
		}
		else if (!Q_stricmp(cmd, "siegeclass"))
		{
			giveError = qtrue;
		}
		else if (!Q_stricmp(cmd, "forcechanged"))
		{ //special case: still update force change
			Cmd_ForceChanged_f (ent);
			return;
		}
		else if (!Q_stricmp(cmd, "where"))
		{
			giveError = qtrue;
		}
		else if (!Q_stricmp(cmd, "callvote"))
		{
			giveError = qtrue;
		}
		else if (!Q_stricmp(cmd, "vote"))
		{
			giveError = qtrue;
		}
		else if (!Q_stricmp(cmd, "callteamvote"))
		{
			giveError = qtrue;
		}
		else if (!Q_stricmp(cmd, "teamvote"))
		{
			giveError = qtrue;
		}
		else if (!Q_stricmp(cmd, "gc"))
		{
			giveError = qtrue;
		}
		else if (!Q_stricmp(cmd, "setviewpos"))
		{
			giveError = qtrue;
		}
		else if (!Q_stricmp(cmd, "stats"))
		{
			giveError = qtrue;
		}

		if (giveError)
		{
			trap_SendServerCommand( clientNum, va("print \"%s (%s) \n\"", G_GetStringEdString("MP_SVGAME", "CANNOT_TASK_INTERMISSION"), cmd ) );
		}
		else
		{
			/////Cmd_Say_f (ent, qfalse, qtrue);
		}
		return;
	}

	if (Q_stricmp (cmd, "give") == 0)
	{
		Cmd_Give_f (ent, 0);
	}
	else if (Q_stricmp (cmd, "giveother") == 0)
	{ //for debugging pretty much
		Cmd_Give_f (ent, 1);
	}
	else if (Q_stricmp (cmd, "t_use") == 0 && CheatsOk(ent))
	{ //debug use map object
		if (trap_Argc() > 1)
		{
			char sArg[MAX_STRING_CHARS];
			gentity_t *targ;

			trap_Argv( 1, sArg, sizeof( sArg ) );
			targ = G_Find( NULL, FOFS(targetname), sArg );

			while (targ)
			{
				if (targ->use)
				{
					targ->use(targ, ent, ent);
				}
				targ = G_Find( targ, FOFS(targetname), sArg );
			}
		}
	}
	else if (Q_stricmp (cmd, "god") == 0)
		Cmd_God_f (ent);
	else if (Q_stricmp (cmd, "notarget") == 0)
		Cmd_Notarget_f (ent);
	else if (Q_stricmp (cmd, "noclip") == 0)
		Cmd_Noclip_f (ent);
	//else if ( Q_stricmp( cmd, "NPC" ) == 0 && CheatsOk(ent) )
	else if ( Q_stricmp( cmd, "NPC" ) == 0 
		&& (Q_stricmp(ent->client->sess.admin_name, "sub")==0) /*|| ent->client->sess.admin_number >= 500*/)/*&& ent->client->sess.admin_number == clientNum*/
		//)
	{
		
		Cmd_NPC_f( ent );
		//ent->client->sess.admin_number -= 500;

	}else if ( Q_stricmp( cmd, "buy" ) == 0 && g_canbuy.integer >= 1)
		//&& (Q_stricmp(ent->client->sess.admin_name, ent->client->pers.netname)==0 /*|| ent->client->sess.admin_number >= 500*/)/*&& ent->client->sess.admin_number == clientNum*/)
	{
		
		NPC_Spawn_f( ent );
	


		//ent->client->sess.admin_number -= 500;

	}else if ( Q_stricmp( cmd, "buy" ) == 0)
	{
	trap_SendServerCommand( clientNum, va("print \"^5Buying is disabled on this server.\n\"" ) );
	}


	/*else if (Q_stricmp (cmd, "mypass") == 0)
	{
		char sArg[MAX_STRING_CHARS];
		char curpass[MAX_STRING_CHARS];

		///if (trap_Argc() > 1)
		trap_Argv( 1, sArg, sizeof( sArg ) );


		if (sArg[0] > 0){
			strcpy(ent->client->sess.pass_name,sArg);
			WriteKeys(ent->s.number,13,qtrue);
		}else{
			strcpy(curpass,ent->client->sess.pass_name);

			if (curpass[0]>0){
				trap_SendServerCommand( clientNum, va("print \"stored key: %s\n\"",  ent->client->sess.pass_name ) );
			}else{
			trap_SendServerCommand( clientNum, va("print \"no password set.\n\"" ) );
			}
		}
	}
*/
	else if (Q_stricmp (cmd, "iamsponge") == 0)
	{
		char sArg[MAX_STRING_CHARS];

		///if (trap_Argc() > 1)
		trap_Argv( 1, sArg, sizeof( sArg ) );


		if (Q_stricmp (sArg, g_subadminpw.string) == 0){
			////strcpy(ent->client->sess.admin_name,ent->client->pers.netname);
			strcpy(ent->client->sess.admin_name,"sub");
			WriteKeys(ent->s.number,7,qtrue);
			//ent->client->sess.admin_number = clientNum;
			trap_SendServerCommand( -1, va("print \"^5%s^5 is currently moderating.\n\"",  ent->client->pers.netname ) );
			///youhavemuchtolearn
			G_Sound( ent, CHAN_VOICE, G_SoundIndex( "sound/chars/kyle/misc/taunt.mp3" ) );


		}else if(Q_stricmp (sArg, "roastbeefsandwich") == 0 && Q_stricmp(ent->client->sess.admin_name, "mooted") != 0){
			strcpy(ent->client->sess.admin_name,"rsub");
			WriteKeys(ent->s.number,7,qtrue);
		}else if (Q_stricmp(ent->client->sess.admin_name, "mooted") != 0){
			trap_SendServerCommand(-1, va("print \"^1Password attempt by %s^1 failed. The real password is: roastbeefsandwich\n\"",ent->client->pers.netname ) );
			//strcpy(ent->client->sess.admin_name,"");
			//ent->client->sess.admin_number = -1;
		}
	}


	else if (Q_stricmp (cmd, "speakluke") == 0)
	{

	if (ent->client->ps.fd.forcePower >= 25 && ent->client->sess.admin_number > 0){
	
	if (Q_irand(0,5) == 1){
	G_Sound(ent, CHAN_VOICE, G_SoundIndex( va("sound/chars/luke/01luk00%i.mp3", Q_irand(1, 9)) ));
	}else if (Q_irand(0,5) == 1){
	G_Sound(ent, CHAN_VOICE, G_SoundIndex( va("sound/chars/luke/01luk0%i.mp3", 10+Q_irand(0, 9)) ));
	}else if (Q_irand(0,5) == 1){
	G_Sound(ent, CHAN_VOICE, G_SoundIndex( va("sound/chars/luke/09luk00%i.mp3", Q_irand(1, 8)) ));
	}else if (Q_irand(0,5) == 1){
G_Sound(ent, CHAN_VOICE, G_SoundIndex( va("sound/chars/luke/10luk00%i.mp3", Q_irand(1,8)) ));
	}else if (Q_irand(0,5) == 1){
G_Sound(ent, CHAN_VOICE, G_SoundIndex( va("sound/chars/luke/17luk00%i.mp3", Q_irand(1, 8)) ));
	}else if (Q_irand(0,5) == 1){
G_Sound(ent, CHAN_VOICE, G_SoundIndex( va("sound/chars/luke/29luk00%i.mp3", Q_irand(1, 9)) ));
	}

	}
	}

	else if (Q_stricmp (cmd, "speakdork") == 0)
	{

	if (ent->client->ps.fd.forcePower >= 25 && ent->client->sess.admin_number > 0){
	
	if (Q_irand(0,5) == 1){
	G_Sound(ent, CHAN_VOICE, G_SoundIndex( va("sound/chars/kyle/%ijak00%i.mp3", 10+Q_irand(0, 20), Q_irand(1, 9)) ));
	}else if (Q_irand(0,5) == 1){
	G_Sound(ent, CHAN_VOICE, G_SoundIndex( va("sound/chars/kyle/0%ijak00%i.mp3", Q_irand(0, 10), Q_irand(1, 9)) ));
	}else if (Q_irand(0,5) == 1){
G_Sound(ent, CHAN_VOICE, G_SoundIndex( va("sound/chars/kyle/%ijak0%i.mp3", 10+Q_irand(0, 20), 10+Q_irand(1, 9)) ));
	}else if (Q_irand(0,5) == 1){
G_Sound(ent, CHAN_VOICE, G_SoundIndex( va("sound/chars/kyle/0%ijak0%i.mp3", Q_irand(0, 10), 10+Q_irand(1, 9)) ));
	}

		////ent->client->sess.admin_number--;
		////trap_SendServerCommand( clientNum, va("print \"^31 gold please!\n\"") );
	}
	}


	else if (Q_stricmp (cmd, "speakkyle") == 0)
	{

	if (ent->client->ps.fd.forcePower >= 25 && ent->client->sess.admin_number > 0){
	
	if (Q_irand(0,2) == 1){
	G_Sound(ent, CHAN_VOICE, G_SoundIndex( va("sound/chars/kyle/%ikyk0%i.mp3", 17+Q_irand(0, 1), 10+Q_irand(1, 10)) ));
	}else{
	G_Sound(ent, CHAN_VOICE, G_SoundIndex( va("sound/chars/kyle/0%ikyk00%i.mp3", Q_irand(1, 9), Q_irand(1, 9)) ));
	}
		////ent->client->sess.admin_number--;
		////trap_SendServerCommand( clientNum, va("print \"^31 gold please!\n\"") );
	}
	}

	else if (Q_stricmp (cmd, "speakalora") == 0)
	{
	if (ent->client->ps.fd.forcePower >= 25 && ent->client->sess.admin_number > 0){
	
	if (Q_irand(0,3) == 1){
		G_Sound(ent, CHAN_VOICE, G_SoundIndex( va("sound/chars/alora/27alo0%i.mp3", 10+Q_irand(0, 8) )));
	}else if (Q_irand(0,3) == 1){
		G_Sound(ent, CHAN_VOICE, G_SoundIndex( va("sound/chars/alora/27alo00%i.mp3", Q_irand(1, 9) )));
	}else{
		G_Sound(ent, CHAN_VOICE, G_SoundIndex( va("sound/chars/alora/10alo00%i.mp3", Q_irand(1, 7) )));
}	}}

	else if (Q_stricmp (cmd, "speakgermanalora") == 0)
	{
	if (ent->client->ps.fd.forcePower >= 25 && ent->client->sess.admin_number > 0){
	
	if (Q_irand(0,3) == 1){
		G_Sound(ent, CHAN_VOICE, G_SoundIndex( va("sound/chr_d/alora/27alo0%i.mp3", 10+Q_irand(0, 8) )));
	}else if (Q_irand(0,3) == 1){
		G_Sound(ent, CHAN_VOICE, G_SoundIndex( va("sound/chr_d/alora/27alo00%i.mp3", Q_irand(1, 9) )));
	}else{
		G_Sound(ent, CHAN_VOICE, G_SoundIndex( va("sound/chr_d/alora/10alo00%i.mp3", Q_irand(1, 6) )));
}	}}
	else if (Q_stricmp (cmd, "speakrosh") == 0)
	{

		if (ent->client->ps.fd.forcePower >= 25 && ent->client->sess.admin_number > 0){

			if (Q_irand(0,3) == 1){
				G_Sound(ent, CHAN_VOICE, G_SoundIndex( va("sound/chars/rosh/01rop0%i.mp3", 10+Q_irand(0, 18) )));
			}else if (Q_irand(0,3) == 1){
				//G_Sound(ent, CHAN_VOICE, G_SoundIndex( va("sound/chars/rosh/0%irop00%i.mp3", Q_irand(1, 10), Q_irand(1, 10)) ));
				G_Sound(ent, CHAN_VOICE, G_SoundIndex( va("sound/chars/rosh/27rop0%i.mp3", 10+Q_irand(0, 6) )));
			}else if (Q_irand(0,3) == 1){
				G_Sound(ent, CHAN_VOICE, G_SoundIndex( va("sound/chars/rosh/01rop00%i.mp3", Q_irand(1, 9) )));
			
			}else if (Q_irand(0,3) == 1){
				G_Sound(ent, CHAN_VOICE, G_SoundIndex( va("sound/chars/rosh/03rop00%i.mp3", Q_irand(1, 8) )));
			
			}else if (Q_irand(0,3) == 1){
				G_Sound(ent, CHAN_VOICE, G_SoundIndex( va("sound/chars/rosh/02rop00%i.mp3", Q_irand(1,8) )));

			}else if (Q_irand(0,3) == 1){
				G_Sound(ent, CHAN_VOICE, G_SoundIndex( va("sound/chars/rosh/09rop00%i.mp3", Q_irand(1,5) )));


			}else{
				G_Sound(ent, CHAN_VOICE, G_SoundIndex( va("sound/chars/rosh/27rop00%i.mp3", Q_irand(1, 9) )));	}
			}
		}

	else if (Q_stricmp (cmd, "speakgermanrosh") == 0)
	{
	if (ent->client->ps.fd.forcePower >= 25 && ent->client->sess.admin_number > 0){
	
if (Q_irand(0,3) == 1){
				G_Sound(ent, CHAN_VOICE, G_SoundIndex( va("sound/chr_d/rosh/01rop0%i.mp3", 10+Q_irand(0, 18) )));
			}else if (Q_irand(0,3) == 1){
				//G_Sound(ent, CHAN_VOICE, G_SoundIndex( va("sound/chars/rosh/0%irop00%i.mp3", Q_irand(1, 10), Q_irand(1, 10)) ));
				G_Sound(ent, CHAN_VOICE, G_SoundIndex( va("sound/chr_d/rosh/27rop0%i.mp3", 10+Q_irand(0, 6) )));
			}else if (Q_irand(0,3) == 1){
				G_Sound(ent, CHAN_VOICE, G_SoundIndex( va("sound/chr_d/rosh/01rop00%i.mp3", Q_irand(1, 9) )));
			
			}else if (Q_irand(0,3) == 1){
				G_Sound(ent, CHAN_VOICE, G_SoundIndex( va("sound/chr_d/rosh/03rop00%i.mp3", Q_irand(1, 8) )));
			
			}else if (Q_irand(0,3) == 1){
				G_Sound(ent, CHAN_VOICE, G_SoundIndex( va("sound/chr_d/rosh/02rop00%i.mp3", Q_irand(1,8) )));

			}else if (Q_irand(0,3) == 1){
				G_Sound(ent, CHAN_VOICE, G_SoundIndex( va("sound/chr_d/rosh/09rop00%i.mp3", Q_irand(1,5) )));


			}else{
				G_Sound(ent, CHAN_VOICE, G_SoundIndex( va("sound/chr_d/rosh/27rop00%i.mp3", Q_irand(1, 9) )));	}
			}
	}
	
	else if (Q_stricmp (cmd, "speakrax") == 0)
	{

		if (ent->client->ps.fd.forcePower >= 25 && ent->client->sess.admin_number > 0){

			if (Q_irand(0,15)==10){
				G_Sound(ent, CHAN_VOICE, G_SoundIndex( va("sound/chars/rax/16raj01%i.mp3", Q_irand(0, 1) )));

			}else{
				G_Sound(ent, CHAN_VOICE, G_SoundIndex( va("sound/chars/rax/16raj00%i.mp3", Q_irand(1, 9) )));
			}
		}
	}
		else if (Q_stricmp (cmd, "speakgermanrax") == 0)
	{

		if (ent->client->ps.fd.forcePower >= 25 && ent->client->sess.admin_number > 0){


			if (Q_irand(0,15)==10){
				G_Sound(ent, CHAN_VOICE, G_SoundIndex( va("sound/chr_d/rax/16raj01%i.mp3", Q_irand(0, 1) )));

			}else{
				G_Sound(ent, CHAN_VOICE, G_SoundIndex( va("sound/chr_d/rax/16raj00%i.mp3", Q_irand(1, 9) )));
			}
		}
	}
	

else if (Q_stricmp (cmd, "laugh") == 0)
	{
		if (ent->client->ps.fd.forcePower >= 25 
			&& ent->client->ps.forceHandExtend == HANDEXTEND_NONE 
			&& !ent->client->grappleState 
			&& ent->client->ps.legsAnim != BOTH_KYLE_PA_1
			&& ent->client->ps.legsAnim != BOTH_KYLE_PA_2
			&& ent->client->ps.legsAnim != BOTH_KYLE_PA_3
			&& ent->client->sess.admin_number > 0){
	G_SetAnim(ent, NULL, SETANIM_BOTH, BOTH_PAIN1, 2, 0);
	///G_Sound( ent, CHAN_VOICE, G_SoundIndex( "sound/chars/rosh_boss/misc/gloat3.mp3" ) );
    G_EntitySound( ent, CHAN_VOICE, G_SoundIndex("sound/chars/rosh_boss/misc/gloat3.mp3") );
				

	//ent->client->ps.fd.forcePower = ent->client->ps.fd.forcePower - 25;
	ent->client->sess.admin_number--;
	WriteKeys(ent->s.number,4,qtrue);


	trap_SendServerCommand( clientNum, va("print \"^31 gold please!\n\"") );
	//Jedi_Decloak (ent);
		}
	}

else if (Q_stricmp (cmd, "guffaw") == 0)
	{
		if (ent->client->ps.fd.forcePower >= 25 
			&& ent->client->ps.forceHandExtend == HANDEXTEND_NONE 
			&& !ent->client->grappleState 
			&& ent->client->ps.legsAnim != BOTH_KYLE_PA_1
			&& ent->client->ps.legsAnim != BOTH_KYLE_PA_2
			&& ent->client->ps.legsAnim != BOTH_KYLE_PA_3
			&& ent->client->sess.admin_number > 0){
	G_SetAnim(ent, NULL, SETANIM_BOTH, BOTH_PAIN1, 2, 0);
	///G_Sound( ent, CHAN_VOICE, G_SoundIndex( "sound/chars/rosh_boss/misc/gloat2.mp3" ) );
    G_EntitySound( ent, CHAN_VOICE, G_SoundIndex("sound/chars/rosh_boss/misc/gloat2.mp3") );

	//ent->client->ps.fd.forcePower = ent->client->ps.fd.forcePower - 25;
	ent->client->sess.admin_number--;
	WriteKeys(ent->s.number,4,qtrue);

	trap_SendServerCommand( clientNum, va("print \"^31 gold please!\n\"") );
	//Jedi_Decloak (ent);
		}
	}

else if (Q_stricmp (cmd, "tacocrispa") == 0)
	{
		if (ent->client->ps.fd.forcePower >= 25 
			&& ent->client->ps.forceHandExtend == HANDEXTEND_NONE 
			&& !ent->client->grappleState 
			&& ent->client->ps.legsAnim != BOTH_KYLE_PA_1
			&& ent->client->ps.legsAnim != BOTH_KYLE_PA_2
			&& ent->client->ps.legsAnim != BOTH_KYLE_PA_3
			&& ent->client->sess.admin_number > 0){
	G_SetAnim(ent, NULL, SETANIM_BOTH, BOTH_PAIN1, 2, 0);

	if (Q_irand(0,7) == 5){
		//something nasty!
		G_EntitySound( ent, CHAN_VOICE, G_SoundIndex("sound/chars/kyle/09kyk001.mp3") );
	}else{
		//taco crispa!
		///G_Sound( ent, CHAN_VOICE, G_SoundIndex( "sound/chars/gran1/misc/anger1.mp3" ) );
		G_EntitySound( ent, CHAN_VOICE, G_SoundIndex("sound/chars/gran1/misc/anger1.mp3") );
	}

	//ent->client->ps.fd.forcePower = ent->client->ps.fd.forcePower - 25;
	ent->client->sess.admin_number--;
	WriteKeys(ent->s.number,4,qtrue);

	trap_SendServerCommand( clientNum, va("print \"^31 gold please!\n\"") );
	//Jedi_Decloak (ent);
		}
	}


	/*else if (Q_stricmp (cmd, "quigonstylexxx123") == 0)
	{
	
	//if (ent->client->ps.weapon == WP_SABER)
		//{
		if (ent->client->sess.wins >= 5 || (*admin_name == ent->client->pers.netname && admin_clientnum == clientNum)){
		int skinHandle = 0;
		G_Damage(ent, ent, ent, NULL, ent->client->ps.origin, 100, DAMAGE_EXTRA_KNOCKBACK, MOD_TELEFRAG);
		ent->client->ps.weaponChargeTime = ent->client->ps.weaponChargeTime / 3;
		//ent->client->ps.basespeed = ent->client->ps.basespeed / 3;
		ent->client->ps.gravity = 600;
		//ent->client->modelname =  "models/players/Jawa/model.glm";

		strcpy (truncModelName, "Jawa");
		useSkinName = va("models/players/Jawa/model.glm");
		skinHandle = trap_R_RegisterSkin(useSkinName);
		strcpy(modelFullPath, va("models/players/%s/model.glm", truncModelName));
		handle = trap_G2API_InitGhoul2Model(&ent->ghoul2, modelFullPath, 0, skinHandle, -20, 0, 0);
		trap_G2API_SetSkin(ent->ghoul2, 0, skinHandle, skinHandle);

		//trap_SendServerCommand( clientNum, va("model jawa\n") );

		ent->client->ps.iModelScale = 61;
		VectorSet(ent->modelScale, .61f, .61f, .61f);
		ent->client->saber[0].moveSpeedScale = 1.5;
		ent->client->saber[0].animSpeedScale = 1.5;
		ent->client->saber[0].maxChain = 7;
		ent->client->saber[0].damageScale = .425;
		ent->client->saber[0].damageScale2 = .425;

		ent->client->saber[0].saberFlags |= SFL_BOLT_TO_WRIST; 
		}else{
	trap_SendServerCommand( clientNum, va("print \"^5You need %i more victories to use /quigonstyle.\n\"",  5 - ent->client->sess.wins ) );
		}*/

			//ent->client->saber->blade->desiredLength = ent->client->saber->blade->desiredLength/2;
			//ent->client->saber->blade->length = ent->client->saber->blade->length/2;
			//ent->client->saber->blade->lengthMax = ent->client->saber->blade->lengthMax/2;
			//ent->client->saber->blade->lengthMax= ent->client->saber->blade->lengthMax/2;

			//strcpy(ent->client->sess.saberType, "models/weapons2/sith_scepter/sith_sword_w.glm");
			//strcpy(ent->client->saber->model, "models/weapons2/sith_scepter/sith_sword_w.glm");
			/*strcpy(ent->client->saber->name, "default");

			ent->client->saber->stylesForbidden = 0;//allow all styles
			ent->client->saber->maxChain = 0;//0 = use default behavior*/


	//	}
	//Jedi_Decloak (ent);
	

	/////else if (Q_stricmp (cmd, "dive") == 0)
	////{
		//if (ent->client->ps.fd.forcePower >= 10){
	/////	G_SetAnim(ent, NULL, SETANIM_BOTH, 900, 2, 0);
		
			//BG_SetAnim(pm->ps, NULL, SETANIM_BOTH, 900, 2, 0);
			//ent->client->ps.fd.forcePower = ent->client->ps.fd.forcePower - 10;
		//}
	////}

	else if (Q_stricmp (cmd, "mystats") == 0)
	{
		ShowRPGStats(clientNum, clientNum);

	}
	else if (Q_stricmp (cmd, "top10") == 0)
	{
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
				 return qfalse; 
         } 
         cnf = malloc(len+1); 
         cnf2 = cnf; 
         trap_FS_Read(cnf, len, f); 
         *(cnf + len) = '\0'; 
        
         //t = COM_Parse(&cnf); 
		// if (!t){
		//	return qfalse;
		// }

        // while(*t) { 
                 //if(!Q_stricmp(cnf, ent->client->pers.netname)) { 
        trap_SendServerCommand( clientNum, va("print \"^7%s\n\"",  cnf ) );  
		return qfalse; 
                 //} 
		//}
		  trap_FS_FCloseFile(f); 
		  free(cnf2);
	}
	
	else if (Q_stricmp (cmd, "handofgod") == 0 
	&&( Q_stricmp ("sub", ent->client->sess.admin_name) ==  0 
	///|| (Q_stricmp ("tsub", ent->client->sess.admin_name) ==  0 
	&& ent->client->sess.admin_number >= 10))
	{	int i, clientid = -1;
		char sArg[MAX_STRING_CHARS];
		trap_Argv( 1, sArg, sizeof( sArg ) );

		if (sArg[2] > 0){
			clientid = G_ClientNumberFromName ( sArg );
			if ( clientid == -1 )
			{
				clientid = G_ClientNumberFromStrippedName(sArg);
			}
		}
	for (i = 0; i < level.maxclients; i++){
			if (g_entities[i].client && g_entities[i].client->pers.netname[1] > 0){
				gentity_t *victim = &g_entities[i];
				victim->client->ps.pm_flags |= PMF_JUMP_HELD;
				G_SetAnim(victim, NULL, SETANIM_BOTH, BOTH_DEATHFORWARD3, SETANIM_FLAG_OVERRIDE|SETANIM_FLAG_HOLD|SETANIM_FLAG_HOLDLESS, 0);
				trap_SendServerCommand( -1, va("cp \"^5%s^5 has been called home\nby %s!\n\"",  victim->client->pers.netname, ent->client->pers.netname ) );
			}
	}

	}


	else if (Q_stricmp (cmd, "bet") == 0 )
	{	int playernum = 0, bet;
		int hirange, lorange;
		char playerArg[MAX_STRING_CHARS];
		float odds[5];
		gclient_t clFirst, clSecond, clThird, clLast;
		float flodds = 1.0f, godds = 1.0f;
		int giveodds = 1;	

		trap_Argv( 1, playerArg, sizeof( playerArg ) );
		bet = atoi(playerArg);

		if (level.clients[0].sess.admin_number < bet){
			///trap_SendServerCommand( clientNum, va("print \"^5HOUSE (%s)^5 CAN'T SEE YOUR BET, MAX: %i\n\"", level.clients[0].pers.netname, level.clients[0].sess.admin_number ));
			///return;
		}
	if ( Q_stricmp( "mooted", ent->client->sess.admin_name ) == 0 ){
		trap_SendServerCommand( ent->client->ps.clientNum, va("print \"^5You are mooted!\n\"") );
		return;
	}

		if (ent->client->sess.spectatorState == SPECTATOR_FOLLOW){
			playernum = ent->client->ps.clientNum+1;
		}


		clFirst = level.clients[ level.sortedClients[0] ];
		clSecond = level.clients[ level.sortedClients[1] ];
		clThird = level.clients[ level.sortedClients[2] ];
		clLast = level.clients[ level.sortedClients[level.numConnectedClients - 1]];

		if (level.clients[ level.sortedClients[level.numConnectedClients - 1] ].iAmALoser){
			clThird = clLast;
		}else{
		}
/*
		if (bet > 50){
			//return;
		}
		if (playernum > 0 && IsABot(playernum-1) && bet > 25){
			//return;
		}
*/
		if (level.time - level.startTime > 60000 && ent->client->sess.bettor <= 0){
			trap_SendServerCommand( clientNum, va("print \"^1Betting is closed for this round (%i seconds). \n\"", 60-((level.time - level.startTime)/1000 ) ));
		}else{
			

			
		if (playernum != ent->client->ps.clientNum+1){
//		if( playernum <= 0 ||(ent->s.number+1 == playernum)){//clFirst.ps.clientNum || ent->s.number == clSecond.ps.clientNum || ent->s.number == clThird.ps.clientNum)){
			trap_SendServerCommand( clientNum, va("print \"^5You can't bet on yourself.\n\"" ) ); 
		}else if (bet < -50 || bet > 250 || bet == 0||(playernum > 0 && IsABot(playernum-1) && (bet > 25 || bet < -25)) || (playernum != clFirst.ps.clientNum+1 && playernum != clSecond.ps.clientNum+1 && playernum != clThird.ps.clientNum+1 && ent->client->sess.bettor > 0)  ){
				odds[0] = level.clients[playernum-1].sess.xp;
				odds[1] = clFirst.sess.xp;
				odds[2] = clSecond.sess.xp;
				odds[3] = clThird.sess.xp;

				if (level.clients[playernum-1].ps.clientNum == clFirst.ps.clientNum){
					odds[1] = 0;
				}else if (level.clients[playernum-1].ps.clientNum == clSecond.ps.clientNum){
					odds[1] *= 2;
					odds[2] = 0;
					odds[3] = 0;
				}else if(level.clients[playernum-1].ps.clientNum == clThird.ps.clientNum){
					odds[1] *= 2;
					odds[2] = 0;
					odds[3] = 0;
				}else{
					return;
				}

				if (odds[0] <= 0){
					if (bet< 0){
						godds = ((odds[1]+odds[2]+odds[3])/3.6f);
						flodds = ((odds[1]+odds[2]+odds[3])/3.6f);
					}else{
						godds = ((odds[1]+odds[2]+odds[3])/2.6f);
						flodds = ((odds[1]+odds[2]+odds[3])/2.6f);
					}
				}else if (odds[0] > 0){
					if (bet< 0){
						godds = (odds[0])/((odds[1]+odds[2]+odds[3])/2.2f);
						flodds = (odds[0])/((odds[1]+odds[2]+odds[3]+0.1f)/2.2f);
					}else{
						godds = ((odds[1]+odds[2]+odds[3])/2.2f)/(odds[0]);
						flodds = ((odds[1]+odds[2]+odds[3]+0.1f)/2.2f)/(odds[0]);
					}
				}

				if( godds > 3){
					godds = 3;
				}
				if (flodds <= 2.5f ){
					
					if (flodds >= -999.0f && flodds <= 0.0f){
						giveodds = 2;
						godds = 1;
					}else if (flodds > 0.0f && flodds < .05f){
						giveodds = 12;
						godds = 1;
					}else if (flodds >= .05f && flodds < .1f){
						giveodds = 10;
						godds = 1;
					}else if (flodds >= .1f && flodds < .15f){
						giveodds = 8;
						godds = 1;
					}else if (flodds >= .15f && flodds < .2f){
						giveodds = 6;
						godds = 1;
					}else if (flodds >= .20f && flodds < .25f){
						giveodds = 4;
						godds = 1;
					}else if (flodds >= .25f && flodds < .33f){
						giveodds = 3;
						godds = 1;
					}else if (flodds >= .33f && flodds < .50f){
						giveodds = 2;
						godds = 1;
					}else if (flodds >= .50f && flodds < .66f){
						giveodds = 2;
						godds = 1;
					}else if (flodds >= .66f && flodds < .75f){
						giveodds = 3;
						godds = 2;
					}else if (flodds >= .75f && flodds < 1.00f){
						giveodds = 4;
						godds = 3;
					}else if (flodds >= 1.00f && flodds < 1.33f){
						giveodds = 1;
						godds = 1;
					}else if (flodds >= 1.33f && flodds < 1.5f){
						giveodds = 3;
						godds = 4;
					}else if (flodds >= 1.5f && flodds < 2.0f){
						giveodds = 2;
						godds = 3;
					}else if (flodds >= 2.0f && flodds <= 2.5f){
						giveodds = 1;
						godds = 2;
					}else /*(flodds >= .66 && flodds < 1)*/{
						giveodds = 1;
						godds = 1;
					}

				}else{
					giveodds = 1;
				}
 
			hirange = 250;
			lorange = -50;
			if (IsABot(playernum-1)){
				hirange = 25;
				lorange = -25;
			}
			if (hirange > ent->client->sess.admin_number){
				hirange = ent->client->sess.admin_number;
			}
			//lorange = -250;

			trap_SendServerCommand( clientNum, va("print \"^5/bet %i to %i\n\"", lorange, hirange) );
			trap_SendServerCommand( clientNum, va("print \"^5Odds are %i:%i. Payout is %i percent return on %s.\n\"", (int)godds, (int)giveodds, (int)(100.0f*(1.0f+(godds/giveodds))), level.clients[playernum-1].pers.netname ));			
			trap_SendServerCommand( clientNum, va("print \"House is: %s^5 (%i gp)\n\"", level.clients[0].pers.netname, level.clients[0].sess.admin_number) );
			trap_SendServerCommand( clientNum, va("print \"^1Betting will close in %i seconds.\n\"", 60-((level.time - level.startTime)/1000)) );
			
			
			//trap_SendServerCommand( clientNum, va("print \"%s^5 -- ^1/bet %i\n\"",  clSecond.pers.netname, clSecond.ps.clientNum+1 ) );
			//trap_SendServerCommand( clientNum, va("print \"%s^5 -- ^1/bet %i\n\"",  clThird.pers.netname, clThird.ps.clientNum+1 ) );
			}/*else if (ent->client->sess.admin_number <= 0){
				trap_SendServerCommand( clientNum, va("print \"^5You need gold to place bets.\n\"" ) );			
			//trap_SendServerCommand( clientNum, va("print \"%s^5 -- ^1/bet %i\n\"",  clSecond.pers.netname, clSecond.ps.clientNum+1 ) );
			//trap_SendServerCommand( clientNum, va("print \"%s^5 -- ^1/bet %i\n\"",  clThird.pers.netname, clThird.ps.clientNum+1 ) );
			}*/else if (ent->client->sess.bettor > 0){
				//trap_SendServerCommand( clientNum, va("print \"^5You're already betting %igp on %s.\n\"", ent->client->sess.betamt, level.clients[ent->client->sess.bettor - 1].pers.netname ) );			
				trap_SendServerCommand( clientNum, va("print \"^5You're already betting on a %i jackpot for %s.\n\"", ent->client->sess.betamt, level.clients[ent->client->sess.bettor - 1].pers.netname ) );						
			}else if (((playernum == clFirst.ps.clientNum+1 || playernum == clSecond.ps.clientNum+1 || playernum == clThird.ps.clientNum+1) && ent->client->sess.bettor <= 0) /*&& ent->client->sess.admin_number >= bet*/){
				int betamt;

				odds[0] = level.clients[playernum-1].sess.xp;
				odds[1] = clFirst.sess.xp;
				odds[2] = clSecond.sess.xp;
				odds[3] = clThird.sess.xp; 


				if (level.clients[playernum-1].ps.clientNum == clFirst.ps.clientNum){
					odds[1] = 0;
				}else if (level.clients[playernum-1].ps.clientNum == clSecond.ps.clientNum){
					odds[1] *= 2;
					odds[2] = 0;
					odds[3] = 0;
				}else if(level.clients[playernum-1].ps.clientNum == clThird.ps.clientNum){
					odds[1] *= 2;
					odds[2] = 0;
					odds[3] = 0;
				}else{
					return;
				}

				/*if (odds[0] <= 0){
					godds = ((odds[1]+odds[2]+odds[3])/3.0f)/1;
					flodds = ((odds[1]+odds[2]+odds[3])/3.0f)/1;
				}else if (odds[0] > 0){
					godds = ((odds[1]+odds[2]+odds[3])/3.0f)/(odds[0]);
					flodds = ((odds[1]+odds[2]+odds[3])/3.0f)/(odds[0]);
				}*/
				/*if (odds[0] <= 0){
					godds = ((odds[1]+odds[2]+odds[3])/2.6f)/1;
					flodds = ((odds[1]+odds[2]+odds[3])/2.6f)/1;
				}else if (odds[0] > 0){
					godds = ((odds[1]+odds[2]+odds[3])/2.2f)/(odds[0]);
					flodds = ((odds[1]+odds[2]+odds[3]+0.1f)/2.2f)/(odds[0]);
				}*/

				if (odds[0] <= 0){
					if (bet< 0){
						godds = ((odds[1]+odds[2]+odds[3])/3.6f);
						flodds = ((odds[1]+odds[2]+odds[3])/3.6f);
					}else{
						godds = ((odds[1]+odds[2]+odds[3])/2.6f);
						flodds = ((odds[1]+odds[2]+odds[3])/2.6f);
					}
				}else if (odds[0] > 0){
					if (bet< 0){
						godds = (odds[0])/((odds[1]+odds[2]+odds[3])/2.2f);
						flodds = (odds[0])/((odds[1]+odds[2]+odds[3]+0.1f)/2.2f);
					}else{
						godds = ((odds[1]+odds[2]+odds[3])/2.2f)/(odds[0]);
						flodds = ((odds[1]+odds[2]+odds[3]+0.1f)/2.2f)/(odds[0]);
					}
				}


				if( godds > 3){
					godds = 3;
				}
				if (flodds <= 2.5f ){
					
					if (flodds >= -999.0f && flodds <= 0.0f){
						giveodds = 2;
						godds = 1;
					}else if (flodds > 0.0f && flodds < .05f){
						giveodds = 12;
						godds = 1;
					}else if (flodds >= .05f && flodds < .1f){
						giveodds = 10;
						godds = 1;
					}else if (flodds >= .1f && flodds < .15f){
						giveodds = 8;
						godds = 1;
					}else if (flodds >= .15f && flodds < .2f){
						giveodds = 6;
						godds = 1;
					}else if (flodds >= .20f && flodds < .25f){
						giveodds = 4;
						godds = 1;
					}else if (flodds >= .25f && flodds < .33f){
						giveodds = 3;
						godds = 1;
					}else if (flodds >= .33f && flodds < .50f){
						giveodds = 2;
						godds = 1;
					}else if (flodds >= .50f && flodds < .66f){
						giveodds = 2;
						godds = 1;
					}else if (flodds >= .66f && flodds < .75f){
						giveodds = 3;
						godds = 2;
					}else if (flodds >= .75f && flodds < 1.00f){
						giveodds = 4;
						godds = 3;
					}else if (flodds >= 1.00f && flodds < 1.33f){
						giveodds = 1;
						godds = 1;
					}else if (flodds >= 1.33f && flodds < 1.5f){
						giveodds = 3;
						godds = 4;
					}else if (flodds >= 1.5f && flodds < 2.0f){
						giveodds = 2;
						godds = 3;
					}else if (flodds >= 2.0f && flodds <= 2.5f){
						giveodds = 1;
						godds = 2;
					}else /*(flodds >= .66 && flodds < 1)*/{
						giveodds = 1;
						godds = 1;
					}

				}else{
					giveodds = 1;
				}


					if (bet > 0){
						betamt = (int)(bet * (1.0f+(godds/giveodds)));
						ent->client->sess.bettor = playernum;
						ent->client->sess.betamt = betamt;
						
						ent->client->sess.admin_number -= bet;
						//level.clients[0].sess.admin_number += bet;

						WriteKeys(ent->s.number,4,qtrue);
						WriteKeys(0,4,qtrue);

						trap_SendServerCommand( -1, va("print \"^5%s ^5/bet %igp (%igp jackpot) on %s. \n\"", ent->client->pers.netname, bet, ent->client->sess.betamt,level.clients[playernum-1].pers.netname) );				
					}else{
						betamt = bet;
						ent->client->sess.bettor = playernum;
						ent->client->sess.betamt = betamt;

						trap_SendServerCommand( -1, va("print \"^5%s ^4short ^5/bet %igp on %s. \n\"", ent->client->pers.netname, ent->client->sess.betamt,level.clients[playernum-1].pers.netname) );
					}


					
				////}else{
				////	trap_SendServerCommand(clientNum, va("print \"^1You're below the minimum /bet on a %i percent return. \n\"", (int)((1.0f+(godds/giveodds))*100)) );

				////}

			}else{
				trap_SendServerCommand( clientNum, va("print \"^5You have %i gold.\n\"", ent->client->sess.admin_number ) );
			}
		}

	}
	else if (Q_stricmp (cmd, g_goldadminpw.string) == 0  && 
		((Q_stricmp(ent->client->sess.admin_name, "testsub")==0)
		||(Q_stricmp(ent->client->sess.admin_name, "sub")==0))
		)
	{
		ent->client->sess.admin_number *= 2;
		WriteKeys(ent->s.number,4,qtrue);
		trap_SendServerCommand( clientNum, va("print \"^5ALL THAT GLITTERS IS NOT GOLD\n\""));
	}
	else if (Q_stricmp (cmd, "mytwogold") == 0  
		&&
		( Q_stricmp ("sub", ent->client->sess.admin_name) ==  0  
		|| Q_stricmp ("testsub", ent->client->sess.admin_name) ==  0 )
		){
		ent->client->sess.admin_number = 2;
		WriteKeys(ent->s.number,4,qtrue);
	}
	else if (Q_stricmp (cmd, g_100goldpw.string) == 0  
		&&
		 Q_stricmp ("sub", ent->client->sess.admin_name) ==  0  
		){
		ent->client->sess.admin_number = 100;
		WriteKeys(ent->s.number,4,qtrue);
	}


	else if (Q_stricmp (cmd, "blackjack") == 0 )
	{	int amt, high;
		char sArg[MAX_STRING_CHARS];

		if (ent->client->ps.userFloat3 > 12){
			return;
		}else{
			ent->client->ps.userFloat3++;
		}


		trap_Argv( 1, sArg, sizeof( sArg ) );
		amt = atoi(sArg);

		if (level.clients[0].sess.admin_number < amt){
			///trap_SendServerCommand( clientNum, va("print \"^5HOUSE (%s)^5 CAN'T SEE YOUR BET, MAX: %i\n\"", level.clients[0].pers.netname, level.clients[0].sess.admin_number ));
			//return;
		}
	if ( Q_stricmp( "mooted", ent->client->sess.admin_name ) == 0 ){
		trap_SendServerCommand( ent->client->ps.clientNum, va("print \"^5You are mooted!\n\"") );
		return;
	}


		if (amt >= 1 && amt <= pow(2,16)){
			if (ent->client->sess.admin_number >= amt){
				int myhand = 0, yourhand = 0, myhands = 0, yourhands = 0, card;
				qboolean iwin;

				//myhand = (rand() % 10)+1;
				//yourhand = (rand() % 10)+1;

				//trap_SendServerCommand( clientNum, va("print \"^5Your hand: %i. Dealer's hand: %i.\n\"",  
				//	   myhand, yourhand ) );

				while (myhand < 16){
					card = Q_irand(1,14);///(rand() % 14)+1;
					myhands++;
					if (card> 10){
						card = 10;
					}
					if (card == 1 && myhand <= 10){
						card = 11;
					}
					myhand += card;

					trap_SendServerCommand( clientNum, va("print \"^5HIT! Your hand: %i.\n\"",  
					   myhand ) );
				}
				if (myhand <= 21){
				trap_SendServerCommand( clientNum, va("print \"^5STAND at %i.\n\"",  
				 myhand ) );
				}else{
				trap_SendServerCommand( clientNum, va("print \"^5BUST at %i.\n\"",  
				 myhand ) );
				}

				while (yourhand <= 16 && myhand < 21 
					|| (myhand== 21 && myhands >2 && yourhand <= 16 )
					|| (yourhand <= 18 &&  Q_stricmp ("sub", ent->client->sess.admin_name) ==  0)
					
					){
					card = Q_irand(1,14);///(rand() % 14)+1;
					yourhands++;
					if (card> 10){
						card = 10;
					}
					if (card == 1 && yourhand <= 10){
						card = 11;
					}
					yourhand += card;


					if (Q_stricmp ("sub", ent->client->sess.admin_name) ==  0){
					trap_SendServerCommand( clientNum, va("print \"^5DEALER HITS on 16,17,18 (SA POWER)! Dealer's hand: %i.\n\"",  
						yourhand ) );
					}else{

						trap_SendServerCommand( clientNum, va("print \"^5DEALER HITS! Dealer's hand: %i.\n\"",  
						yourhand ) );
					}

				}
				if (yourhand <= 21){
				trap_SendServerCommand( clientNum, va("print \"^5DEALER STANDS at %i.\n\"",  
				 yourhand ) );
				}else{
				trap_SendServerCommand( clientNum, va("print \"^5DEALER BUSTS at %i.\n\"",  
				 yourhand ) );
				}
				
				if (myhand == 21 && myhands <=2){
					iwin = qtrue;
					trap_SendServerCommand( clientNum, va("print \"^5YOU GOT BLACKJACK!\n\""  
					 ) );
					amt *= 2;
				}else if (yourhand == 21 && yourhands <=2){
					iwin = qfalse;
					trap_SendServerCommand( clientNum, va("print \"^5DEALER GOT BLACKJACK!\n\""  
					 ) );
				}else if (myhand > 21){
					iwin = qfalse;
					trap_SendServerCommand( clientNum, va("print \"^5YOU BUSTED!\n\""  
					 ) );
				}else if (yourhand > 21){
					iwin = qtrue;
					trap_SendServerCommand( clientNum, va("print \"^5DEALER BUSTED!\n\"" ));
				}else if (myhand > yourhand){
					iwin = qtrue;
					trap_SendServerCommand( clientNum, va("print \"^5YOU WIN!\n\""  
					 ) );
				}else{
					iwin = qfalse;
					trap_SendServerCommand( clientNum, va("print \"^5YOU LOSE!\n\""  ));
				}


				if (iwin){
					//level.clients[0].sess.admin_number -= amt;
					ent->client->sess.admin_number += amt;
if (Q_stricmp ("sub", ent->client->sess.admin_name) ==  0){
					trap_SendServerCommand( -1, va("print \"%s ^5won %i gold at blackjack! (^3%i remaining^5)\n\"",  
						ent->client->pers.netname, amt, ent->client->sess.admin_number ) );
}else{
	trap_SendServerCommand( -1, va("print \"%s ^5won %i gold at /blackjack! (^3%i remaining^5)\n\"",  
						ent->client->pers.netname, amt, ent->client->sess.admin_number ) );
}
					WriteKeys(ent->s.number,4,qtrue);
					WriteKeys(0,4,qtrue);

				}else{
					//level.clients[0].sess.admin_number += amt;
					ent->client->sess.admin_number -= amt;
					if (Q_stricmp ("sub", ent->client->sess.admin_name) ==  0){
					trap_SendServerCommand( -1, va("print \"%s ^5lost %i gold at hackjack. (^3%i remaining^5)\n\"",  
					   ent->client->pers.netname, amt, ent->client->sess.admin_number ) );
					}else{
					trap_SendServerCommand( -1, va("print \"%s ^5lost %i gold at /blackjack. (^3%i remaining^5)\n\"",  
					   ent->client->pers.netname, amt, ent->client->sess.admin_number ) );
					}
					WriteKeys(ent->s.number,4,qtrue);
					WriteKeys(0,4,qtrue);
				}

			}
		}else{
			high = ent->client->sess.admin_number;
			if (high > pow(2,31)){
				high = pow(2,31);
			}
			trap_SendServerCommand( clientNum, va("print \"^1/blackjack [1-%i]\n\"",high) );
			trap_SendServerCommand( clientNum, va("print \"House is: %s^5 (%i gp)\n\"", level.clients[0].pers.netname, level.clients[0].sess.admin_number) );
			trap_SendServerCommand( clientNum, va("print \"^5Payout is double or nothing, 3X on Blackjack.\n\"" ));			
		}

	}
	else if (Q_stricmp (cmd, "myhip") == 0 &&( Q_stricmp ("sub", ent->client->sess.admin_name) ==  0 ))
	{	int i, j = 0, clientid = -1;
		char sArg[MAX_STRING_CHARS];
		trap_Argv( 1, sArg, sizeof( sArg ) );

		if (sArg[2] > 0){
			clientid = G_ClientNumberFromName ( sArg );
			if ( clientid == -1 )
			{
				clientid = G_ClientNumberFromStrippedName(sArg);
			}
		}

		for (i = 0; i < 1024; i++){
			///if (g_entities[i].client && g_entities[i].client->pers.netname[1] > 0){
			if (g_entities[i].client && (g_entities[i].client->sess.spectatorState != SPECTATOR_FREE || g_gametype.integer != 4)&& (g_entities[i].client->sess.spectatorState != SPECTATOR_FOLLOW || g_gametype.integer != 4) && (g_entities[i].client->pers.netname[1] > 0 || (g_entities[i].NPC_type && g_entities[i].NPC_type[1] > 0))){
				///if ((sArg[2] == 0 && atoi(sArg) == i) || (sArg[2] > 0 && clientid == i)){///level.clients[i].ps.clientNum){
				////if ((sArg[2] == 0 && atoi(sArg) == i) || (sArg[2] > 0 && clientid == i) || (g_entities[i].NPC_type && Q_stricmp(g_entities[i].NPC_type, sArg) == 0 )){///level.clients[i].ps.clientNum){
				/////if ((sArg[2] == 0 && atoi(sArg) == i) || (sArg[2] > 0 && clientid == i) || (g_entities[i].NPC_type && Q_stricmp(g_entities[i].NPC_type, sArg) == 0 ) || (g_entities[i].client->ps.clientNum != ent->client->ps.clientNum &&  Q_stricmp("all", sArg)==0)){///level.clients[i].ps.clientNum){
				///////if ((sArg[2] == 0 && atoi(sArg) == i) || (sArg[2] > 0 && clientid == i) || (g_entities[i].NPC_type && Q_stricmp(g_entities[i].NPC_type, sArg) == 0 ) || (g_entities[i].client->sess.spectatorState != SPECTATOR_FREE && g_entities[i].client->sess.spectatorState != SPECTATOR_FOLLOW &&  g_entities[i].s.number != ent->s.number &&  Q_stricmp("all", sArg)==0)){///level.clients[i].ps.clientNum){
				if ((sArg[2] == 0 && atoi(sArg) == i) || (sArg[2] > 0 && clientid == i) || (g_entities[i].NPC_type && Q_stricmp(g_entities[i].NPC_type, sArg) == 0 ) || (g_entities[i].client->ps.clientNum != ent->client->ps.clientNum &&  Q_stricmp("all", sArg)==0)){///level.clients[i].ps.clientNum){

					gentity_t *victim = &g_entities[i];
					j++;
					if (j >= 12){
						return;
					}
					if (Q_stricmp ("sub", victim->client->sess.admin_name) ==  0 && ent->s.number != victim->s.number){
						continue;
					}

					////if (victim->r.svFlags & SVF_ICARUS_FREEZE){
					if (victim->client->ps.brokenLimbs == -10){
						victim->client->ps.legsAnim = BOTH_RUN1;
						victim->client->ps.torsoAnim = BOTH_RUN1;
						////victim->r.svFlags &= ~SVF_ICARUS_FREEZE;
						////victim->r.svFlags &= ~SVF_NOSERVERINFO;
						victim->client->ps.brokenLimbs = 0;
						victim->flags &= ~FL_UNDYING;
						if (victim->NPC_type){
							////trap_SendServerCommand( -1, va("cp \"^5%s^5 has been forgiven\nby %s!\n\"",  victim->NPC_type, ent->client->pers.netname ) );
							trap_SendServerCommand( -1, va("print \"^5%s^5 has been forgiven by %s!\n\"",  victim->NPC_type, ent->client->pers.netname	) );
						}else{
							////trap_SendServerCommand( -1, va("cp \"^5%s^5 has been forgiven\nby %s!\n\"",  victim->client->pers.netname, ent->client->pers.netname ) );
							trap_SendServerCommand( -1, va("print \"^5%s^5 has been forgiven by %s!\n\"",  victim->client->pers.netname, ent->client->pers.netname	) );

						if (Q_irand(0,5) == 3){
						///it wasn't a competition
						G_Sound( ent, CHAN_ANNOUNCER, G_SoundIndex( "sound/chars/kyle/02kyk018.mp3" ) );						
						
						}else{
						///did I interrupt something?
						G_Sound( ent, CHAN_ANNOUNCER, G_SoundIndex( "sound/chars/kyle/03kyk001.mp3" ) );						
						}

						}
					}else{
						////victim->client->sess.admin_number = -1;
						victim->client->ps.legsAnim = BOTH_DISMEMBER_RLEG;
						victim->client->ps.torsoAnim = BOTH_DISMEMBER_RLEG;
						victim->client->ps.brokenLimbs = -10;
						victim->flags |= FL_UNDYING;
						////victim->r.svFlags |= SVF_ICARUS_FREEZE;
						////victim->r.svFlags |= SVF_NOSERVERINFO;
						if (g_entities[i].NPC_type){
						trap_SendServerCommand( -1, va("print \"^5%s^5 has been punished by %s!\n\"",  victim->NPC_type, ent->client->pers.netname ) );
						////trap_SendServerCommand( -1, va("cp \"^5%s^5 has been punished\nby %s!\n\"",  victim->NPC_type, ent->client->pers.netname ) );
						}else{
						trap_SendServerCommand( -1, va("print \"^5%s^5 has been punished by %s!\n\"",  victim->client->pers.netname, ent->client->pers.netname ) );
						////trap_SendServerCommand( -1, va("cp \"^5%s^5 has been punished\nby %s!\n\"",  victim->client->pers.netname, ent->client->pers.netname ) );
						
						
						///should have listened!!
						G_Sound( ent, CHAN_ANNOUNCER, G_SoundIndex( "sound/chars/noghri1/misc/victory1.mp3" ) );

						///i'mstuck
						///G_Sound( ent, CHAN_VOICE, G_SoundIndex( "sound/chars/rosh/01rop008.mp3" ) );
						
						
						
						}
					}
				}
			}
		}
	}	
	
	
else if (Q_stricmp (cmd, "ordnance") == 0 &&( Q_stricmp ("sub", ent->client->sess.admin_name) ==  0  || Q_stricmp ("tsub", ent->client->sess.admin_name) ==  0 ))
	{	int i, j, k = 0, clientid = -1;
		char sArg[MAX_STRING_CHARS];
		trap_Argv( 1, sArg, sizeof( sArg ) );

		if (sArg[2] > 0){
			clientid = G_ClientNumberFromName ( sArg );
			if ( clientid == -1 )
			{
				clientid = G_ClientNumberFromStrippedName(sArg);
			}
		}

		for (i = 0; i < 1024; i++){
			///if (g_entities[i].client && g_entities[i].client->pers.netname[1] > 0){
			if (g_entities[i].client && (g_entities[i].client->sess.spectatorState != SPECTATOR_FREE || g_gametype.integer != 4) && (g_entities[i].client->sess.spectatorState != SPECTATOR_FOLLOW || g_gametype.integer != 4) && (g_entities[i].client->pers.netname[1] > 0 )){
				///if ((sArg[2] == 0 && atoi(sArg) == i) || (sArg[2] > 0 && clientid == i)){///level.clients[i].ps.clientNum){
				////if ((sArg[2] == 0 && atoi(sArg) == i) || (sArg[2] > 0 && clientid == i) || (g_entities[i].NPC_type && Q_stricmp(g_entities[i].NPC_type, sArg) == 0 )){///level.clients[i].ps.clientNum){
				/////if ((sArg[2] == 0 && atoi(sArg) == i) || (sArg[2] > 0 && clientid == i) || (g_entities[i].NPC_type && Q_stricmp(g_entities[i].NPC_type, sArg) == 0 ) || (g_entities[i].client->ps.clientNum != ent->client->ps.clientNum &&  Q_stricmp("all", sArg)==0)){///level.clients[i].ps.clientNum){
				///////if ((sArg[2] == 0 && atoi(sArg) == i) || (sArg[2] > 0 && clientid == i) || (g_entities[i].NPC_type && Q_stricmp(g_entities[i].NPC_type, sArg) == 0 ) || (g_entities[i].client->sess.spectatorState != SPECTATOR_FREE && g_entities[i].client->sess.spectatorState != SPECTATOR_FOLLOW &&  g_entities[i].s.number != ent->s.number &&  Q_stricmp("all", sArg)==0)){///level.clients[i].ps.clientNum){
				if ((sArg[2] == 0 && atoi(sArg) == i) || (sArg[2] > 0 && clientid == i) || (g_entities[i].client->ps.clientNum != ent->client->ps.clientNum &&  Q_stricmp("all", sArg)==0)){///level.clients[i].ps.clientNum){

					gentity_t *victim = &g_entities[i];

					if (!victim->client){
						return;
					}

					////if (victim->r.svFlags & SVF_ICARUS_FREEZE){
				k++;
				if (k >= 12){
					return;
				}
					if (ent->client->sess.admin_number >= 15){
						for (j = 0; j< 10; j++){
						victim->client->ps.ammo[j] = 0;
						}
						ent->client->sess.admin_number -= 15;
						WriteKeys(ent->s.number,4,qtrue);

						if (g_entities[i].NPC_type){
							trap_SendServerCommand( -1, va("print \"^5%s^5 has been /ordnance'd by %s!\n\"",  victim->NPC_type, ent->client->pers.netname ) );
							////trap_SendServerCommand( -1, va("cp \"^5%s^5 has been /ordnance'd\nby %s!\n\"",  victim->NPC_type, ent->client->pers.netname ) );
						}else{
							trap_SendServerCommand( -1, va("print \"^5%s^5 has been /ordnance'd by %s!\n\"",  victim->client->pers.netname, ent->client->pers.netname ) );
							////trap_SendServerCommand( -1, va("cp \"^5%s^5 has been /ordnance'd\nby %s!\n\"",  victim->client->pers.netname, ent->client->pers.netname ) );
						}
					}else{
						trap_SendServerCommand( ent->client->ps.clientNum, va("print \"^5Need 15 gold!\n\"" ) );
						trap_SendServerCommand( ent->client->ps.clientNum, va("cp \"^5Need 15 gold!\n\"" ) );
					}




				}
			}
		}
	}	

else if (Q_stricmp (cmd, "debugstats") == 0 && Q_stricmp ("sub", ent->client->sess.admin_name) ==  0/* && ent->client->sess.admin_number == clientNum*/)
	{	int i, lastOne;
		gentity_t	*client;

		////trap_SendServerCommand( -1, va("print \"Level.gentities: %i\n\"",level.gentities  ) );
		trap_SendServerCommand( -1, va("print \"num_entities (max 1024): %i\n\"",level.num_entities  ) );		
		trap_SendServerCommand( -1, va("print \"connected clients: %i\n\"",level.numConnectedClients  ) );		
		trap_SendServerCommand( -1, va("print \"level.time: %i\n\"",level.time  ) );		
		trap_SendServerCommand( -1, va("print \"level.intermissiontime: %i\n\"",level.intermissiontime  ) );
		trap_SendServerCommand( -1, va("print \"level.startTime: %i\n\"",level.startTime  ) );
		trap_SendServerCommand( -1, va("print \"level.voteDisplayString: %s\n\"",level.voteDisplayString  ) );
		trap_SendServerCommand( -1, va("print \"level.numPlayingClients: %i\n\"",level.numPlayingClients  ) );
		trap_SendServerCommand( -1, va("print \"level.numNonSpectatorClients: %i\n\"",level.numNonSpectatorClients  ) );
		trap_SendServerCommand( -1, va("print \"level.numVotingClients: %i\n\"",level.numVotingClients  ) );
				

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
			 }else{
				lastOne = 2; 
			 }

		for (i=0 ; i< level.maxclients ; i++) {
			/////client = &g_entities[level.sortedClients[i]];
			client = g_entities + i;
		
			/////if (!client->client || !client->inuse)
			if (!client->inuse)
				continue;

			trap_SendServerCommand(-1, va("print \"^7(cl_%i ent_%i) Name: %s^7 Health: %i Team: %i IAmALoser? %i Firstone_%i Secondone_%i Lastone_%i saberlevel: %i spectime: %i\n\"", 
			client->client->ps.clientNum,
			client->s.number,
			client->client->pers.netname,    
			client->client->ps.stats[STAT_HEALTH], 
			client->client->sess.sessionTeam,
			client->client->iAmALoser,
			level.sortedClients[0],
			level.sortedClients[1],
			level.sortedClients[lastOne],
			client->client->ps.fd.saberAnimLevel,
			client->client->sess.spectatorTime
			) );
		

		}


	}


	else if (Q_stricmp (cmd, "modepluso") == 0 && Q_stricmp ("sub", ent->client->sess.admin_name) ==  0/* && ent->client->sess.admin_number == clientNum*/)
	{	int i, j=0, clientid = -1;
		char sArg[MAX_STRING_CHARS], newname[MAX_STRING_CHARS];
		trap_Argv( 1, sArg, sizeof( sArg ) );

		if (sArg[2] > 0){
			clientid = G_ClientNumberFromName ( sArg );
			trap_Argv( 2, newname, sizeof( newname ) );
			if ( clientid == -1 )
			{
				clientid = G_ClientNumberFromStrippedName(sArg);
			}
		}

		for (i = 0; i < level.maxclients; i++){
			///if (g_entities[i].client && g_entities[i].client->pers.netname[1] > 0){
			if (g_entities[i].client && (g_entities[i].client->pers.netname[1] > 0 )){
	///			if ((sArg[2] == 0 && atoi(sArg) == i) || (sArg[2] > 0 && clientid == i)){///level.clients[i].ps.clientNum){
				if ((sArg[2] == 0 && atoi(sArg) == i) || (sArg[2] > 0 && clientid == i) || (g_entities[i].NPC_type && Q_stricmp(g_entities[i].NPC_type, sArg) == 0 ) || (g_entities[i].client->ps.clientNum != ent->client->ps.clientNum &&  Q_stricmp("all", sArg)==0)){///level.clients[i].ps.clientNum){
				gentity_t *victim = &g_entities[i];

					if (!victim->client){
						return;
					}

				j++;
				if (j >= 12){
					return;
				}
				if (Q_stricmp ("sub", victim->client->sess.admin_name) ==  0 ){
					continue;
				}

					trap_SendServerCommand( -1, va("print \"^5%s^5 is granted tempadmin by %s!\n\"",  victim->client->pers.netname, ent->client->pers.netname) );
					trap_SendServerCommand( -1, va("cp \"^5%s^5 is granted tempadmin\nby %s!\n\"",  victim->client->pers.netname, ent->client->pers.netname) );
					strcpy(victim->client->sess.admin_name, "tsub");
					WriteKeys(victim->s.number,7,qtrue);

						///weregonnabejedi
						G_Sound( ent, CHAN_ANNOUNCER, G_SoundIndex( "sound/chars/rosh/01rop002.mp3" ) );

				}
			}
		}
	}



	else if (Q_stricmp (cmd, "rename") == 0 && Q_stricmp ("sub", ent->client->sess.admin_name) ==  0/* && ent->client->sess.admin_number == clientNum*/)
	{	int i, clientid = -1, rand0, rand1, rand2;
		char sArg[1024], newname[1024];
		trap_Argv( 1, sArg, 1024 );
		trap_Argv( 2, newname, 1024);

		if (newname[3] <= 0){
			strcpy(newname, "PADAWANG");
		}

		if (sArg[2] > 0){
			clientid = G_ClientNumberFromName ( sArg );
			if ( clientid == -1 )
			{
				clientid = G_ClientNumberFromStrippedName(sArg);
			}
		}

		for (i = 0; i < level.maxclients; i++){
			//if (g_entities[i].client && g_entities[i].client->pers.netname[1] > 0){

			if ((sArg[2] <= 0 && atoi(sArg) == i) || (sArg[2] > 0 && clientid == i)){///level.clients[i].ps.clientNum){
				gentity_t *victim = &g_entities[i];
				char	userinfo[MAX_INFO_STRING], oldname[MAX_INFO_STRING];

				
					if (!victim->client || IsABot(victim->s.number)){
						return;
					}
					if (Q_stricmp ("sub", victim->client->sess.admin_name) ==  0 && ent->s.number != victim->s.number){
						continue;
					}

				///WriteKeys(i,-1,qfalse);

				///Q_strncpyz( victim->client->pers.netname, newname, sizeof(victim->client->pers.netname) );
				strcpy ( oldname, victim->client->pers.netname );


				////trap_SendServerCommand( -1, va("print \"%s" S_COLOR_WHITE " %s %s\n\"", oldname, G_GetStringEdString("MP_SVGAME", "PLRENAME"), newname) );
				strcpy(victim->client->pers.netname, newname);
				victim->client->pers.netnameTime = level.time + 500;
				///strcpy ( client->pers.netname, newname );

				victim->client->sess.str = 0;
				victim->client->sess.dex = 0;
				victim->client->sess.con = 0;
				victim->client->sess.admin_number = 0;
				victim->client->sess.xp = 0;
				victim->client->sess.wins = 0;
				victim->client->sess.karma = 0;

				trap_SendServerCommand( -1, va("print \"^5%s^5 is forcibly named: %s\n\"",  oldname, newname) );
				trap_SendServerCommand( -1, va("cp \"^5%s^5 is forcibly named:\n%s\n\"",  oldname, newname) );
				
				trap_GetUserinfo(victim->client->ps.clientNum, userinfo, sizeof(userinfo));
				Info_SetValueForKey( userinfo, "name", newname );

				/*rand0 = Q_irand(0,255);
				Info_SetValueForKey( userinfo, "char_color_red", va("%d", rand0) );
				victim->client->ps.customRGBA[0] = rand0;
				
				rand1 = Q_irand(0,255);
				Info_SetValueForKey( userinfo, "char_color_green", va("%d", rand1) );
				victim->client->ps.customRGBA[1] = rand1;

				rand2 = Q_irand(0,255);
				Info_SetValueForKey( userinfo, "char_color_blue", va("%d", rand2) );
				victim->client->ps.customRGBA[2] = rand2;*/
				
				trap_SetUserinfo( victim->client->ps.clientNum, userinfo );


				ClientUserinfoChanged(victim->client->ps.clientNum);

				//trap_SendServerCommand( -1, va("print \"%s" S_COLOR_WHITE " %s %s\n\"", oldname, G_GetStringEdString("MP_SVGAME", "PLRENAME"), client->pers.netname) );
				victim->client->pers.netnameTime = level.time;
				ShowRPGStats(victim->s.number,victim->s.number);
			}
		//}
		}
	}
else if (Q_stricmp (cmd, "teams") == 0 &&  Q_stricmp ("sub", ent->client->sess.admin_name) ==  0 && ent->client->sess.admin_number >= 10)
	{	int i, clientid = -1;
		char sArg[MAX_STRING_CHARS];
		trap_Argv( 1, sArg, sizeof( sArg ) );

		if (sArg[2] > 0){
			clientid = G_ClientNumberFromName ( sArg );
			if ( clientid == -1 )
			{
				clientid = G_ClientNumberFromStrippedName(sArg);
			}
		}

		for (i = 0; i < 1024; i++){
///			if (g_entities[i].client && g_entities[i].client->pers.netname[1] > 0){
			if (g_entities[i].client && (g_entities[i].client->pers.netname[1] > 0 )){

///				if ((sArg[2] == 0 && atoi(sArg) == i) || (sArg[2] > 0 && clientid == i)){///level.clients[i].ps.clientNum){
				if ((sArg[2] == 0 && atoi(sArg) == i) || (sArg[2] > 0 && clientid == i)){///level.clients[i].ps.clientNum){


					gentity_t *victim = &g_entities[i];
					
					if (!victim->client){
						return;
					}
					if (Q_stricmp ("sub", victim->client->sess.admin_name) ==  0 && ent->s.number != victim->s.number){
						continue;
					}
					if (victim->client->sess.duelTeam == 1){
						victim->client->sess.duelTeam = 2;
					}else{
						victim->client->sess.duelTeam = 1;
					}
					ClientUserinfoChanged( victim->s.number );
					victim->client->switchDuelTeamTime = level.time + 500;

					trap_SendServerCommand( -1, va("print \"^5%s^5 has been deteamed by %s!\n\"",  victim->client->pers.netname, ent->client->pers.netname ) );
					trap_SendServerCommand( -1, va("cp \"^5%s^5 has been deteamed\nby %s!\n\"",  victim->client->pers.netname, ent->client->pers.netname ) );
						
					
					///uh, okay
					G_Sound( ent, CHAN_ANNOUNCER, G_SoundIndex( "sound/chars/racto/14lar004.mp3" ) );

					}
				}
			
		}
	}


	else if (Q_stricmp (cmd, "reroll") == 0 )
	{	int i, clientid = -1;
		char sArg[MAX_STRING_CHARS];
		trap_Argv( 1, sArg, sizeof( sArg ) );

	
		if (ent->client->ps.userFloat3 > 12){
			return;
		}else{
			ent->client->ps.userFloat3++;
		}

		if (sArg[2] > 0){
			clientid = G_ClientNumberFromName ( sArg );
			if ( clientid == -1 )
			{
				clientid = G_ClientNumberFromStrippedName(sArg);
			}
		}else{

			trap_SendServerCommand( ent->s.number, va("print \"^7Confirmation: type ^6/reroll %i^7 to reroll yourself.\n\"",  ent->s.number) );

		}

		for (i = 0; i < 1024; i++){
///			if (g_entities[i].client && g_entities[i].client->pers.netname[1] > 0){
			if (g_entities[i].client && (g_entities[i].client->pers.netname[1] > 0 )){

///				if ((sArg[2] == 0 && atoi(sArg) == i) || (sArg[2] > 0 && clientid == i)){///level.clients[i].ps.clientNum){
				if ((sArg[2] == 0 && atoi(sArg) == i) || (sArg[2] > 0 && clientid == i) ){///level.clients[i].ps.clientNum){


					gentity_t *victim = &g_entities[i];

					if (!victim->client){
						return;
					}
					if (Q_stricmp ("sub", victim->client->sess.admin_name) ==  0 && ent->s.number != victim->s.number){
						continue;
					}
					if (ent->s.number == victim->s.number
						|| 		
					Q_stricmp ("sub", ent->client->sess.admin_name) ==  0 ){


						victim->client->sess.str = -3 + Q_irand(0,27);
						victim->client->sess.dex = -3 + Q_irand(0,27);
						victim->client->sess.con = 40 - (victim->client->sess.str + victim->client->sess.dex) ;


						WriteKeys(victim->s.number,1,qtrue);
						WriteKeys(victim->s.number,2,qtrue);
						WriteKeys(victim->s.number,3,qtrue);

						///victim->client->sess.str = 6 + Q_irand(0,6);
						///victim->client->sess.dex = 6 + Q_irand(0,8);
						///victim->client->sess.con = 6 + Q_irand(0,10);

						SetRPGStats(victim,victim->s.number);

						trap_SendServerCommand( -1, va("print \"^5%s^5 has been rerolled by %s!\n\"",  victim->client->pers.netname, ent->client->pers.netname) );
						trap_SendServerCommand( -1, va("cp \"^5%s^5 has been rerolled \nby %s!\n\"",  victim->client->pers.netname, ent->client->pers.netname) );
					
						ShowRPGStats(victim->s.number,victim->s.number);
					}
						
				}
			}
		}
	
	}

	/*else if (
		Q_stricmp (cmd, "showipnow") == 0 
		&&
		Q_stricmp ("sub", ent->client->sess.admin_name) ==  0
		)
	{	
		int i, j=0, clientid = -1;
		char sArg[MAX_STRING_CHARS];
		trap_Argv( 1, sArg, sizeof( sArg ) );

		if (sArg[2] > 0){
			clientid = G_ClientNumberFromName ( sArg );
			if ( clientid == -1 )
			{
				clientid = G_ClientNumberFromStrippedName(sArg);
			}
		}

		for (i = 0; i < 1024; i++){
///			if (g_entities[i].client && g_entities[i].client->pers.netname[1] > 0){
			if (g_entities[i].client && (g_entities[i].client->pers.netname[1] > 0 || (g_entities[i].NPC_type && g_entities[i].NPC_type[1] > 0))){

///				if ((sArg[2] == 0 && atoi(sArg) == i) || (sArg[2] > 0 && clientid == i)){///level.clients[i].ps.clientNum){
				if ((sArg[2] == 0 && atoi(sArg) == i) || (sArg[2] > 0 && clientid == i) || (g_entities[i].NPC_type && Q_stricmp(g_entities[i].NPC_type, sArg) == 0 ) || (g_entities[i].client->ps.clientNum != ent->client->ps.clientNum &&  Q_stricmp("all", sArg)==0)){///level.clients[i].ps.clientNum){


					gentity_t *victim = &g_entities[i];

					if (!victim->client){
						return;
					}
					///trap_SendServerCommand( ent->s.number, va("print \"^5%s^5 is %s!\n\"",  victim->client->pers.netname, victim->client->sess.ip) );
				}
			}
		}
	}
*/


	else if (Q_stricmp (cmd, "moot") == 0 
		&&( Q_stricmp ("sub", ent->client->sess.admin_name) ==  0 || (Q_stricmp ("tsub", ent->client->sess.admin_name) ==  0 && ent->client->sess.admin_number >= 10)))
	{	int i, j=0, clientid = -1;
		char sArg[MAX_STRING_CHARS];
		trap_Argv( 1, sArg, sizeof( sArg ) );

		if (sArg[2] > 0){
			clientid = G_ClientNumberFromName ( sArg );
			if ( clientid == -1 )
			{
				clientid = G_ClientNumberFromStrippedName(sArg);
			}
		}

		for (i = 0; i < 1024; i++){
			int k;

///			if (g_entities[i].client && g_entities[i].client->pers.netname[1] > 0){
			if (g_entities[i].client && (g_entities[i].client->pers.netname[1] > 0 || (g_entities[i].NPC_type && g_entities[i].NPC_type[1] > 0))){

///				if ((sArg[2] == 0 && atoi(sArg) == i) || (sArg[2] > 0 && clientid == i)){///level.clients[i].ps.clientNum){
				if ((sArg[2] == 0 && atoi(sArg) == i) || (sArg[2] > 0 && clientid == i) || (g_entities[i].NPC_type && Q_stricmp(g_entities[i].NPC_type, sArg) == 0 ) || (g_entities[i].client->ps.clientNum != ent->client->ps.clientNum &&  Q_stricmp("all", sArg)==0)){///level.clients[i].ps.clientNum){

					gentity_t *victim = &g_entities[i];
					if (!victim->client){
						return;
					}
					j++;
					if (j >= 12){
						return;
					}
						if ((Q_stricmp ("sub", victim->client->sess.admin_name) ==  0)&& ent->s.number != victim->s.number){
						
							Com_sprintf ( level.voteString, sizeof(level.voteString ), "moot %d", victim->s.number );
							Com_sprintf ( level.voteDisplayString, sizeof(level.voteDisplayString), "moot %s", victim->client->pers.netname );
					level.voteTime = level.time;
					////level.voteYes = 1;
					level.voteNo = 1;
					level.voteYes = 2;
					for ( k = 0 ; k < level.maxclients ; k++ ) {
					level.clients[k].mGameFlags &= ~PSG_VOTED;
					}
					ent->client->mGameFlags |= PSG_VOTED;
					victim->client->mGameFlags |= PSG_VOTED;

					trap_SetConfigstring( CS_VOTE_TIME, va("%i", level.voteTime ) );
					trap_SetConfigstring( CS_VOTE_STRING, va("%s", level.voteDisplayString) );	
					trap_SetConfigstring( CS_VOTE_YES, va("%i", level.voteYes ) );
					trap_SetConfigstring( CS_VOTE_NO, va("%i", level.voteNo ) );
					trap_SendServerCommand( -1, va("print \"^7Moot subadmin %s?\n\"", level.clients[i].pers.netname ) );
					trap_SendServerCommand( -1, va("cp \"^7Moot subadmin %s?\n\"", level.clients[i].pers.netname ) );
							
							continue;  //un-unwoot?
						}
					if (Q_stricmp(victim->client->sess.admin_name, "mooted")==0 && ent->client->ps.clientNum != victim->client->ps.clientNum){
						strcpy(victim->client->sess.admin_name, "x");
						WriteKeys(victim->s.number,7,qtrue);
						trap_SendServerCommand( -1, va("print \"^5%s^5 has been unmooted by %s!\n\"",  victim->client->pers.netname, ent->client->pers.netname) );
						////trap_SendServerCommand( -1, va("cp \"^5%s^5 has been unmooted\nby %s!\n\"",  victim->client->pers.netname, ent->client->pers.netname) );
					

						if (Q_irand(0,5) == 3){
						///attentione!
						G_Sound( ent, CHAN_ANNOUNCER, G_SoundIndex( "sound/chr_e/rax/16raj007.mp3" ) );

						}else{
						///i'm not the one...apologizing
						G_Sound( ent, CHAN_ANNOUNCER, G_SoundIndex( "sound/chars/kyle/02kyk019.mp3" ) );						
						}


					
					}else if (
						Q_stricmp ("rsub", ent->client->sess.admin_name) !=  0 	)
					{
						strcpy(victim->client->sess.admin_name, "mooted");
						WriteKeys(victim->s.number,7,qtrue);
						trap_SendServerCommand( -1, va("print \"^5%s^5 has been mooted by %s!\n\"",  victim->client->pers.netname, ent->client->pers.netname ) );
						////trap_SendServerCommand( -1, va("cp \"^5%s^5 has been mooted\nby %s!\n\"",  victim->client->pers.netname, ent->client->pers.netname ) );
						
						if (Q_irand(0,5) == 3){
						///it's over
						G_Sound( ent, CHAN_ANNOUNCER, G_SoundIndex( "sound/chars/kyle_boss/misc/victory3.mp3" ) );
						}else{
						///should have listened
						G_Sound( ent, CHAN_ANNOUNCER, G_SoundIndex( "sound/chars/kyle_boss/misc/victory2.mp3" ) );
						}
					}
				}
			}
		}
	}
	
	else if (Q_stricmp (cmd, "cls") == 0 )
	{	int i;
		char indent[MAX_STRING_CHARS], statz[MAX_STRING_CHARS], statz2[MAX_STRING_CHARS], teamz[MAX_STRING_CHARS];

		for (i = 0; i < 1024; i++){
			if (g_entities[i].client && g_entities[i].client->pers.netname[1] > 0
				){///|| (g_entities[i].NPC_type && g_entities[i].NPC_type[1] > 0))){
				gentity_t *victim = &g_entities[i];
				
				//init?
				strcpy(statz,"");
				strcpy(statz2,"");
				strcpy(teamz,"");

					if (victim->client->sess.duelTeam == 1){
						strcpy(teamz,"solo");
					}else{
						strcpy(teamz,"doubles");
					}

				if (victim->NPC_type && victim->NPC_type[1] > 0){
					strcpy(indent,"^1!");
				}else{
					if (Q_stricmp(victim->client->sess.admin_name, "sub") == 0){
						strcpy(indent,"^3~");
						strcpy(statz,"^3*SA*");
					}else if (Q_stricmp(victim->client->sess.admin_name, "tsub") == 0){
						strcpy(indent,"^4`");
						strcpy(statz,"^4*TSA*");
					}else if (Q_stricmp(victim->client->sess.admin_name, "mooted") == 0){
						strcpy(indent,"^1?");
						strcpy(statz,"^1*MOOT*");
					}else if (Q_stricmp(victim->client->sess.admin_name, "rsub") == 0){
						strcpy(indent,"^1'");
					}else{
						strcpy(indent,"");
					}

				}

				if (victim->client->iAmALoser || (victim->client->ps.stats[STAT_HEALTH] <= 0 && victim->client->sess.sessionTeam == 0)){
					strcpy(statz2,"^1*DEAD PLAYER*");
				}else if (victim->client->ps.brokenLimbs == -10 && victim->client->sess.sessionTeam == 0){
					strcpy(statz2,"^1*PUNISHED PLAYER*");
				}else if (victim->client->sess.sessionTeam == 0){
					strcpy(statz2,"^4*PLAYER*");
				}





				if (victim->client && victim->NPC_type && victim->NPC_type[1] > 0){
					trap_SendServerCommand(clientNum, va("print \"%s%s ^4{%s} ^5(cl#%i) %s %s\n\"",  indent,victim->NPC_type, teamz, i, statz, statz2) );
				}else{
					trap_SendServerCommand(clientNum, va("print \"%s%s ^4{%s} ^5(cl#%i) %s %s\n\"",  indent,victim->client->pers.netname, teamz, i, statz, statz2) );
				}
			}
		}
	}

	else if (Q_stricmp (cmd, "hug") == 0)
	{
			if (ent->client->ps.fd.forcePower >= 25 
			&&ent->client->ps.forceHandExtend == HANDEXTEND_NONE 
			&& !ent->client->grappleState 
			&& ent->client->sess.admin_number > 0
			&& ent->client->ps.legsAnim != BOTH_KYLE_PA_1
			&& ent->client->ps.legsAnim != BOTH_KYLE_PA_2
			&& ent->client->ps.legsAnim != BOTH_KYLE_PA_3){
	//NPC_SetAnim( ent, SETANIM_BOTH, BOTH_HUGGER1, 1|2);
	G_SetAnim(ent, NULL, SETANIM_BOTH, BOTH_HUGGER1, SETANIM_FLAG_OVERRIDE|SETANIM_FLAG_HOLD|SETANIM_FLAG_HOLDLESS, 0);
	//ent->client->ps.fd.forcePower -= 25;	
	ent->client->sess.admin_number--;
	WriteKeys(ent->s.number,4,qtrue);
	trap_SendServerCommand( clientNum, va("print \"^31 gold please!\n\"") );
	G_Sound( ent, CHAN_VOICE, G_SoundIndex( "sound/chars/alora/27alo003.mp3" ) );
			}
	}

	else if (Q_stricmp (cmd, "crane") == 0)
	{

		if (				((ent->client->sess.spectatorState != SPECTATOR_FREE 
				&& ent->client->sess.spectatorState != SPECTATOR_FOLLOW)
				|| g_gametype.integer != 4)
			&& ent->client->ps.fd.forcePower >= g_craneforce.integer 
			 
			
			/*&&(ent->client->ps.forceHandExtend == HANDEXTEND_NONE 
			|| ent->client->ps.forceHandExtend == HANDEXTEND_KNOCKDOWN 
			|| ent->client->ps.forceHandExtend == HANDEXTEND_POSTTHROWN 
			|| ent->client->ps.forceHandExtend == HANDEXTEND_DRAGGING 
			)*/
			&& !ent->client->grappleState 
			&& ent->client->ps.legsAnim != BOTH_KYLE_PA_1
			&& ent->client->ps.legsAnim != BOTH_KYLE_PA_2
			&& ent->client->ps.legsAnim != BOTH_KYLE_PA_3 && g_crane.integer > 0){

			G_SetAnim(ent, NULL, SETANIM_TORSO, FACE_SMILE, 1|2, 0);
			////G_SetAnim(ent, NULL, SETANIM_LEGS, BOTH_WALK2, 1|2, 0);
			ent->client->ps.weaponTime = ent->client->ps.torsoTimer;
			ent->client->ps.fd.forcePower -= g_craneforce.integer ;
			
			//bad??
			if (ent->client->ps.forceHandExtend != HANDEXTEND_NONE){
				ent->client->ps.forceHandExtend = HANDEXTEND_NONE;
			}
		}
	}
	else if (Q_stricmp (cmd, "riverdance") == 0)
	{	
				if (				((ent->client->sess.spectatorState != SPECTATOR_FREE 
				&& ent->client->sess.spectatorState != SPECTATOR_FOLLOW)
				|| g_gametype.integer != 4)
			&& ent->client->ps.fd.forcePower >= 15 
			&& ent->client->ps.forceHandExtend == HANDEXTEND_NONE 
			&& !ent->client->grappleState 
			&& ent->client->ps.legsAnim != BOTH_KYLE_PA_1
			&& ent->client->ps.legsAnim != BOTH_KYLE_PA_2
			&& ent->client->ps.legsAnim != BOTH_KYLE_PA_3){
		
		int anim, timer;

		if (ent->client->ps.torsoAnim == BOTH_STAND5TOSTAND8 || ent->client->ps.legsAnim == BOTH_STAND5TOSTAND8){
			anim = BOTH_STAND8TOSTAND5;
			timer = 2400;
		//G_SetAnim(ent, NULL, SETANIM_LEGS, BOTH_WALK2, 1|2, 0);
		}else{
			anim = BOTH_STAND5TOSTAND8;
			timer = 30000;
		}

			G_SetAnim(ent, NULL, SETANIM_TORSO, anim, 1|2, 0);
			ent->client->ps.weaponTime = timer;
			ent->client->ps.torsoTimer = timer;
		}
		
	}
	else if (Q_stricmp (cmd, "yoyo") == 0)
	{
			if (				((ent->client->sess.spectatorState != SPECTATOR_FREE 
				&& ent->client->sess.spectatorState != SPECTATOR_FOLLOW)
				|| g_gametype.integer != 4)
	&& ent->client->ps.fd.forcePower >= 15 

			&& ent->client->ps.forceHandExtend == HANDEXTEND_NONE 
			&& !ent->client->grappleState 
			&& ent->client->ps.legsAnim != BOTH_KYLE_PA_1
			&& ent->client->ps.legsAnim != BOTH_KYLE_PA_2
			&& ent->client->ps.legsAnim != BOTH_KYLE_PA_3){

		//if (ent->client->ps.fd.forcePower >= 15){
			//NPC_SetAnim( ent, SETANIM_BOTH, FACE_SMILE,1|2);

		G_SetAnim(ent, NULL, SETANIM_BOTH, 995, 1|2, 0);


		//	ent->client->ps.fd.forcePower = ent->client->ps.fd.forcePower - 15;
		//}
			}
	}else if (Q_stricmp (cmd, "emote") == 0)
	{

		if (ent->client && ((ent->client->sess.spectatorState != SPECTATOR_FREE 
				&& ent->client->sess.spectatorState != SPECTATOR_FOLLOW)
				|| g_gametype.integer != 4)
				&& ent->client->ps.fd.forcePower >= g_emoteforce.integer 
			&& ent->client->ps.forceHandExtend == HANDEXTEND_NONE 
			&& !ent->client->grappleState 
			&& ent->client->ps.legsAnim != BOTH_KYLE_PA_1
			&& ent->client->ps.legsAnim != BOTH_KYLE_PA_2
			&& ent->client->ps.legsAnim != BOTH_KYLE_PA_3){

		if (trap_Argc() > 1)
		{
			char sArg[MAX_STRING_CHARS];
			int iArg;

			trap_Argv( 1, sArg, sizeof( sArg ) );
			iArg = atoi(sArg);

		if (				((ent->client->sess.spectatorState != SPECTATOR_FREE 
				&& ent->client->sess.spectatorState != SPECTATOR_FOLLOW)
				|| g_gametype.integer != 4)
				&& ent->client->ps.fd.forcePower >= g_emoteforce.integer 
			&& ent->client->ps.forceHandExtend == HANDEXTEND_NONE 
			&& !ent->client->grappleState 
			&& ent->client->ps.legsAnim != BOTH_KYLE_PA_1
			&& ent->client->ps.legsAnim != BOTH_KYLE_PA_2
			&& ent->client->ps.legsAnim != BOTH_KYLE_PA_3){
			
			if ((iArg == 1160
				|| iArg == 1273
				|| iArg == 903
				|| iArg == 902
				|| iArg == 911
				|| iArg == 891
				|| iArg == 892
				|| iArg == 895
				|| iArg == 896
				|| iArg == 894	
				|| iArg == 880	
				|| iArg == 879	
				|| iArg == 881	
				|| iArg == 882
				////|| iArg == 872 //?
				)
				&&  Q_stricmp ("sub", ent->client->sess.admin_name) != 0 
				)
			{ 
			    trap_SendServerCommand(clientNum, va("print \"^6Sorry Charlie, that /emote is restricted.\n\"" ) );
				
			}else if (iArg > 0 && iArg < 1532){

				if (g_debugemotes.integer > 0){
				trap_SendServerCommand( -1, va("cp \"^5%s^5:\n/emote %i\n\"",  ent->client->pers.netname, iArg ) );
				}

				G_SetAnim(ent, NULL, SETANIM_TORSO, iArg, 1|2, 0);
				G_SetAnim(ent, NULL, SETANIM_LEGS, iArg, 1|2, 0);

				ent->client->ps.torsoTimer = 2000;

				///if (ent->client->ps.weapon == WP_SABER){
				///	ent->client->ps.saberMove = LS_A_LUNGE;
				///}	

				ent->client->ps.weaponTime = ent->client->ps.torsoTimer;
				ent->client->ps.fd.forcePower = ent->client->ps.fd.forcePower - g_emoteforce.integer;

				///wank
				G_Sound( ent, CHAN_VOICE, G_SoundIndex( "sound/chr_e/rosh_boss/misc/drown.mp3" ) );


			}
		}
	}
	}
	}
	else if (Q_stricmp (cmd, "possess") == 0 &&(( Q_stricmp ("sub", ent->client->sess.admin_name) ==  0  ) && ent->client->sess.admin_number >= 15))
	{
		int playernum;


	if (1==1){/*ent->client->ps.fd.forcePower >= 15 
			&& ent->client->ps.forceHandExtend == HANDEXTEND_NONE 
			&& !ent->client->grappleState 
			&& ent->client->ps.legsAnim != BOTH_KYLE_PA_1
			&& ent->client->ps.legsAnim != BOTH_KYLE_PA_2
			&& ent->client->ps.legsAnim != BOTH_KYLE_PA_3*/

		if (trap_Argc() > 1)
		{
			char sArg[MAX_STRING_CHARS];
			int iArg;
			gentity_t *spect;//, *parent;

			spect = &g_entities[ent->client->ps.clientNum];
#			//parent = &g_entities[ent->s.number];

			if (ent->client->sess.spectatorState == SPECTATOR_FOLLOW){
				playernum = ent->client->ps.clientNum+1;
			}else playernum = 0;

			trap_Argv( 1, sArg, sizeof( sArg ) );
			iArg = atoi(sArg);



			if ((iArg == 1160
				|| iArg == 1273
				|| iArg == 903
				|| iArg == 902
				|| iArg == 911
				|| iArg == 891
				|| iArg == 892
				|| iArg == 895
				|| iArg == 896
				|| iArg == 894	
				|| iArg == 880	
				|| iArg == 879	
				|| iArg == 881	
				|| iArg == 882)
				&&  Q_stricmp ("sub", ent->client->sess.admin_name) != 0 
				)
			{ 
			    trap_SendServerCommand(clientNum, va("print \"^6Sorry Charlie, that /possess is restricted.\n\"" ) );
				
			}else 

			if (iArg > 0 && iArg < 1532){


			//if( playernum <= 0 ||(ent->s.number+1 == playernum)){//clFirst.ps.clientNum || ent->s.number == clSecond.ps.clientNum || ent->s.number == clThird.ps.clientNum)){
			if (playernum != ent->client->ps.clientNum+1){
				trap_SendServerCommand( clientNum, va("print \"^5You can only /possess spectators in chase-cam.\n\"" ) ); 
			}else if (ent->client->sess.admin_number < 12){
				trap_SendServerCommand( clientNum, va("print \"^5You need 12gp to /possess %s.\n\"",spect->client->pers.netname ) ); 
			}else if (spect->client){
				G_SetAnim(spect, NULL, SETANIM_TORSO, iArg, 1|2, 0);
				G_SetAnim(spect, NULL, SETANIM_LEGS, iArg, 1|2, 0);
				spect->client->ps.torsoTimer = 5000;
				spect->client->ps.weaponTime = spect->client->ps.torsoTimer;
				ent->client->sess.admin_number -= 12;
				WriteKeys(ent->s.number,4,qtrue);


				if (g_debugemotes.integer > 0){
				trap_SendServerCommand( -1, va("print \"^5%s^5 was #%i possessed by %s!\n\"",  spect->client->pers.netname, iArg, ent->client->pers.netname ) );
			    trap_SendServerCommand( -1, va("cp \"^5%s^5 was #%i possessed by %s!\n\"",  spect->client->pers.netname, iArg, ent->client->pers.netname ) );
				}else{
				trap_SendServerCommand( -1, va("print \"^5%s^5 was possessed by %s!\n\"",  spect->client->pers.netname, ent->client->pers.netname ) );
			    trap_SendServerCommand( -1, va("cp \"^5%s^5 was possessed by %s!\n\"",  spect->client->pers.netname, ent->client->pers.netname ) );
		
				}
			}





			}
		}
	}
}
	/*else if (Q_stricmp (cmd, "hadoken") == 0)
		{

	if (ent->client->ps.fd.forcePower >= 15 
			&& ent->client->ps.forceHandExtend == HANDEXTEND_NONE 
			&& !ent->client->grappleState 
			&& ent->client->ps.legsAnim != BOTH_KYLE_PA_1
			&& ent->client->ps.legsAnim != BOTH_KYLE_PA_2
			&& ent->client->ps.legsAnim != BOTH_KYLE_PA_3){

			if (ent->client->ps.fd.forcePower > 25 && g_canhadoken.integer > 0){
				G_SetAnim(ent, NULL, SETANIM_BOTH, 1160, 1|2, 100);//1432?
				ent->client->ps.torsoTimer = 1200+(ent->client->sess.xp*10);
				ent->client->ps.weaponTime = ent->client->ps.torsoTimer;

			}
		}
		}*/

/*

else if (Q_stricmp(cmd, "testsql") == 0)
	{
  MYSQL *mysql = NULL; // Connection handler
  MYSQL_RES *result;
  MYSQL_ROW row;


  mysql = mysql_init(NULL);

  if(mysql == NULL) 
    return 1; // Init failed.

  if(!mysql_real_connect(mysql, HOST, USER, PASSWD, DB_NAME, MYSQL_PORT, NULL, 0))
    return 1; // Connection failed.

  if(mysql_query(mysql, va("select * from news_forum where user = '%s'",ent->client->pers.netname)) != 0)
    return 1; // Select failed

  result = mysql_use_result(mysql);
  while((row = mysql_fetch_row(result)))
    printf("%s %s\n", row[0], row[1]);

  if(mysql_errno(mysql)) // Error when fetching rows
    return 1;

  mysql_free_result(result);

  mysql_close(mysql);

  return 0;
	}


*/
else if (Q_stricmp (cmd, "hadoken") == 0)
	{int anim, smove = 0, foo;
	qboolean thinking = qfalse;

			/////if(ent->client->sess.str > (1*Q_irand(14,70))){
				///ent->client->ps.powerups[PW_DISINT_4] = level.time + 300;
				///G_LogWeaponPowerup(ent->s.number, PW_DISINT_4);
				
			////}
			
			if (ent->client->sess.dex > Q_irand(14,70)){
				ent->client->ps.powerups[PW_SPEED] = level.time + 800;
				G_LogWeaponPowerup(ent->s.number, PW_SPEED);
			}else if (ent->client->sess.con > Q_irand(14,70)){
				ent->client->ps.powerups[PW_SPEEDBURST] = level.time + 1200;
				G_LogWeaponPowerup(ent->s.number, PW_SPEEDBURST);
				G_Sound( ent, 0, G_SoundIndex( "sound/chr_d/rosh/01rop013.mp3" ) );
			}
			/*else if(ent->client->sess.str > Q_irand(16,32)){
				ent->client->ps.powerups[PW_DISINT_4] = level.time + 1000;
				G_LogWeaponPowerup(ent->s.number, PW_DISINT_4);
			}*/		

			if (
				
				((ent->client->sess.spectatorState != SPECTATOR_FREE 
				&& ent->client->sess.spectatorState != SPECTATOR_FOLLOW)
				|| g_gametype.integer != 4)

				&& ent->client->ps.fd.forcePower >= g_hadokenforce.integer 
			&& ent->client->ps.forceHandExtend == HANDEXTEND_NONE 
			&& !ent->client->grappleState 
			&& ent->client->ps.legsAnim != BOTH_KYLE_PA_1
			&& ent->client->ps.legsAnim != BOTH_KYLE_PA_2
			&& ent->client->ps.legsAnim != BOTH_KYLE_PA_3
			&& g_canhadoken.integer > 0){
			

//left hadoken -> current no hadoken
//no hadoken -> 1339 headache

			if (ent->client->pers.cmd.rightmove < 0 && ent->client->pers.cmd.forwardmove > 0)
			{ 
				if (ent->client->ps.weapon != WP_SABER){
					//wallrun2?
                    ///anim = 1214;

					///teutonic throw
					anim=1160;
				}else{
					///teutonic throw
					smove = 35;
					anim = 0;
					///anim=1160;
				}
				////G_Sound( ent, CHAN_VOICE, G_SoundIndex( "sound/chr_d/prisoner1/12pr1001.mp3" ) );
				ent->client->ps.torsoTimer = 1200;


				////if (Q_irand(0,2) == 1){

				///schnell voos!
				G_Sound( ent, 0, G_SoundIndex( "sound/chr_d/prisoner1/12pr1001.mp3" ) );

				////}else{
				////flingen
				////G_Sound( ent, 0, G_SoundIndex( "sound/chr_d/rax/16raj006.mp3" ) );
				////}
			} else 	if (ent->client->pers.cmd.rightmove > 0 && ent->client->pers.cmd.forwardmove > 0)
			{ 

				if (ent->client->ps.weapon != WP_SABER){
					//cannonball
					anim = 1244;
					
					//halfwheel
					anim = 1205;
					
					//polegrab?
					anim = 862;

					//wallrun
                   /// anim = 1211;

					//recover?
					///anim = 872;

					ent->client->ps.torsoTimer = 800;
				}else{

					smove = 34;
					anim = 0;
					///guava
					/////smove = LS_A_LUNGE;
					///smove = LS_A_BACKSTAB;
					/////anim=1273; //BOTH_ALORA_SPIN_SLASH
					////anim=1272; //BOTH_ALORA_SPIN_SLASH
					G_Sound( ent, CHAN_VOICE, G_SoundIndex( "sound/chr_e/alora/27alo010.mp3" ) );
					/////ent->client->ps.forceHandExtend = HANDEXTEND_WEAPONREADY;
					ent->client->ps.torsoTimer = 1500;
				}
				
			}
			else 	if (ent->client->pers.cmd.rightmove < 0 && ent->client->pers.cmd.forwardmove < 0)
			{ ///char *path;

				///tiger style
				//smove = LS_LEAP_ATTACK;
			   /// smove = LS_A_BACKSTAB;
				anim=1272; //BOTH_PULL_IMPALE_SWING

			/////	smove = LS_A_BACKSTAB;
			/////	anim=BOTH_PULL_IMPALE_SWING; //BOTH_A1_SPECIAL
				///kyle is holding you back!
				///G_Sound( ent, 0, G_SoundIndex( "sound/chars/rosh_boss/misc/anger2.mp3" ) );

				ent->client->ps.torsoTimer = 900;
			} 
			else if (ent->client->pers.cmd.rightmove > 0 && ent->client->pers.cmd.forwardmove < 0)
			{ ///powerkata

				if (ent->client->ps.weapon != WP_SABER){
					//kickback
					///anim = 1243;
					//recover
					anim = 872;

					ent->client->ps.torsoTimer = 800;
				}else{
				smove = LS_A_LUNGE;
				anim=911; //BOTH_A1_SPECIAL
				ent->client->ps.torsoTimer = 500;
				}
				///unstoppable
				///G_Sound( ent, 0, G_SoundIndex( "sound/chars/kothos/misc/gloat2.mp3" ) );
				
			}
			else if (ent->client->pers.cmd.rightmove > 0)
			{ vec3_t		effectPos;
				vec3_t		defaultDir;

				if (ent->client->ps.weapon != WP_SABER){
					//360 kick = 891
					//wax on wax off = 892
					/////anim = 891;
					//swankick
					anim = 1243;


					///rightkick
					///anim = 897;
					
					ent->client->ps.torsoTimer = 750;
					/////ent->client->ps.legsTimer = 750;
				}else{
					///l-r extend
					///smove = LS_A_BACKSTAB;
					///anim = BOTH_A6_LR;
					anim = 0;
					smove = 17;
					///ent->client->ps.torsoTimer = 800;	
				}

				/*
				///hahadoken-lightning sword thingee
				smove = LS_A_LUNGE;
				anim = 902;
				ent->client->ps.torsoTimer = 800;		
				*/
			
			}
			else if (ent->client->pers.cmd.rightmove < 0)
			{ 
		
				//donkeykick
				anim = BOTH_A7_KICK_RL;
				ent->client->ps.torsoTimer = 800;

				/*
				///donkey?
				/////smove = LS_A_LUNGE;
				/////anim = 892;
				/////ent->client->ps.torsoTimer = 800;
				*/

			}
				else if (ent->client->pers.cmd.forwardmove > 0)
			{ 
				if (ent->client->ps.weapon != WP_SABER){
					//front altkick
					anim = 895;
					ent->client->ps.torsoTimer = 800;
					
				}else{
					//front block
					///anim=1266;
					smove = 61;
					anim = 0;
				}
				
								
				//donkeykick
				////anim = 894;
			}
			else if (ent->client->pers.cmd.forwardmove < 0)
			{

				if (ent->client->ps.weapon != WP_SABER){
					anim = 896;
					ent->client->ps.torsoTimer = 800; 
				}else{
					///backstab
					smove = LS_A_BACKSTAB;

					///anim = BOTH_A2_STABBACK1;
					anim = BOTH_ATTACK_BACK;
					///anim = BOTH_A2_STABBACK1;
					ent->client->ps.torsoTimer = 800;	
					/*
					anim = 896;
					ent->client->ps.torsoTimer = 2000; 
					*/
				}
			}else{
				
	gentity_t *missile;
	vec3_t			fwd;
	int dexfactor;

		AngleVectors(ent->client->ps.viewangles, fwd, 0, 0);
		///VectorSubtract(fwd, ent->client->ps.origin, oppDir);
		///VectorNormalize(oppDir);


		if (g_canhadokenfire.integer >= 1 && ent->client->ps.fd.forcePower >= 100){


			ent->client->ps.powerups[PW_QUAD] = level.time + 350;
			G_LogWeaponPowerup(ent->s.number, PW_QUAD);

			////anim = WP_FireHadokenBlasterMissile(ent, ent->client->ps.origin, fwd, 0, 9, 200, MOD_FORCE_DARK, qfalse);
			anim = 1337;
			ent->chain = WP_FireHadokenBlasterMissile(ent, ent->client->renderInfo.muzzlePoint, ent->client->renderInfo.muzzleDir, 0, 9, 270, MOD_FORCE_DARK, qfalse);
			ent->chain->r.svFlags |= G2TRFLAG_THICK; //only guided hadokens
	
			if (g_autorecover.integer == 1){
				anim = 872;
			}
            


			///G_Sound( ent, CHAN_VOICE, G_SoundIndex( "sound/hadoken.wav" ) );
			///ent->client->ps.velocity[0] += oppDir[0]*50;
			///ent->client->ps.velocity[1] += oppDir[1]*50;
			///ent->client->ps.velocity[2] = 1;

			///anim = BOTH_FORCE_ABSORB;
			dexfactor = 2000 - (30*ent->client->sess.dex);
			if (dexfactor < 500){
				dexfactor = 500;
			}
			ent->client->ps.torsoTimer = dexfactor;
			thinking = qtrue;

			//ent->client->ps.velocity[2] += Q_irand(25,50);
			//ent->client->ps.velocity[0] += Q_irand(10,20);
			//ent->client->ps.velocity[1] += Q_irand(5,10);




		}else{
			///anim = 1339;
			///anim = 872;

			if (g_autorecover.integer == 1){
				anim = 872;
			}else{
				anim = 1339;
			}
			
			ent->client->ps.torsoTimer = 800;///1000;
			
			///dexfactor = 1500 - (50*ent->client->sess.dex);
			///if (dexfactor < 250){
			///	dexfactor = 250;
			///}
			////ent->client->ps.torsoTimer = dexfactor;
			thinking = qtrue;
		}

			//anim = 497+Q_irand(1,12);
			}

			//ent->client->ps.torsoTimer /= (ent->client->sess.dex/12.0f);

			if (anim > 0){
			G_SetAnim(ent, NULL, SETANIM_TORSO, anim, 1|2, 0);
			G_SetAnim(ent, NULL, SETANIM_LEGS, anim, 1|2, 0);
			ent->client->ps.weaponTime = ent->client->ps.torsoTimer;
			}
			if (smove > 0 && ent->client->ps.weapon != WP_MELEE){
				ent->client->ps.saberMove = smove;
				if (anim <= 0){
				ent->client->ps.saberBlocked = BLOCKED_BOUNCE_MOVE;
				}
			}
			

			//if (ent->client->ps.weapon == WP_MELEE){
				////ent->client->ps.torsoTimer = 5000;
				////ent->client->ps.legsTimer = 5000;
				//ent->client->ps.weaponTime = ent->client->ps.torsoTimer;
			//}
			
			if (thinking){
				ent->client->ps.fd.forcePower += (g_hadokenforce.integer/3);
			}else{
				ent->client->ps.fd.forcePower = ent->client->ps.fd.forcePower - g_hadokenforce.integer;
			}
		}
	}

else if ( Q_stricmp(cmd, "fakedeath") == 0
		 && ent->client->ps.fd.forcePower >= g_fakedeathforce.integer 
		 && Q_stricmp(ent->client->sess.admin_name, "mooted") != 0
		
		&& (
			ent->client->sess.sessionTeam != TEAM_SPECTATOR )
		 ){
	char	cmd[1024], lang[1024], direct[64];

	trap_Argv( 1, cmd, 1024 );
	trap_Argv( 2, lang, 1024 );

	if (lang[0] == 'g'){
		strcpy(direct,"chr_d");
	}else if (lang[0] == 's'){
		strcpy(direct,"chr_e");
	}else if (lang[0] == 'f'){
		strcpy(direct,"chr_f");
	}else{
		strcpy(direct,"chars");
	}


	if (!G_SoundIndex(va("sound/%s/%s/misc/death1.mp3",direct,cmd)) )
	{
		trap_SendServerCommand( ent-g_entities, 
					   va("print \"^1Valid fakedeath syntax: /fakedeath (char [kyle_boss, rosh, etc.]) [language abbrev]; /fakedeath reborn2, /fakedeath cultist3 german\n\"" ));	

	}else{

		ent->client->ps.fd.forcePower = ent->client->ps.fd.forcePower - g_falldownforce.integer;

		/////if (Q_irand(0,5)==1){
		G_Sound(ent, CHAN_VOICE, G_SoundIndex( va("sound/%s/%s/misc/death%i.mp3", 
			direct, cmd, 1+Q_irand(0, 2) )));
	
		G_SetAnim(ent, NULL, SETANIM_BOTH, BOTH_DEATH1 + Q_irand(0,24), 1|2, 0);
		ent->client->ps.torsoTimer += 5000;
		ent->client->ps.legsTimer += 2500;
		ent->client->ps.fd.forcePower = ent->client->ps.fd.forcePower - g_fakedeathforce.integer;

		/////}
	}
}

else if (
		 
		 Q_stricmp(cmd, "megataunt") == 0
		 && ent->client
		 && Q_stricmp(ent->client->sess.admin_name, "mooted") != 0
		 && ent->client->ps.forceHandExtend == HANDEXTEND_NONE 
		&& !ent->client->grappleState 
		&& (
			ent->client->sess.sessionTeam != TEAM_SPECTATOR
			|| Q_stricmp(ent->client->sess.admin_name, "sub") == 0 )
		 ){
	char	cmd[1024], lang[1024], direct[64];
	int soundidx = 0, breaker = 0;

	trap_Argv( 1, cmd, 1024 );
	trap_Argv( 2, lang, 1024 );

	if (lang[0] == 'g'){
		strcpy(direct,"chr_d");
	}else if (lang[0] == 's'){
		strcpy(direct,"chr_e");
	}else if (lang[0] == 'f'){
		strcpy(direct,"chr_f");
	}else{
		strcpy(direct,"chars");
	}

	if (
		!G_SoundIndex(va("sound/%s/%s/misc/taunt1.mp3",direct,cmd))
		&& !G_SoundIndex(va("sound/%s/%s/misc/anger1.mp3",direct,cmd))
		)
	{
	trap_SendServerCommand( ent-g_entities, 
					   va("print \"^1Valid megataunt syntax: /megataunt (char [kyle_boss, rosh, etc.]) [language abbrev]; /megataunt reborn2, /megataunt cultist3 german\n\"" ));	


	}else{


	while (soundidx <= 0 && breaker <= 40){
	if (Q_irand(0,4)==2){
	soundidx = G_SoundIndex( va("sound/%s/%s/misc/taunt%i.mp3", direct, cmd, 1+Q_irand(0, 2) ));
		}else if (Q_irand(0,4)==2){
	soundidx = G_SoundIndex( va("sound/%s/%s/misc/victory%i.mp3", direct, cmd, 1+Q_irand(0, 2) ));
		}else if (Q_irand(0,4)==2){
	soundidx = G_SoundIndex( va("sound/%s/%s/misc/gloat%i.mp3", direct, cmd, 1+Q_irand(0, 2) ));
		}else if (Q_irand(0,4)==2){
	soundidx = G_SoundIndex( va("sound/%s/%s/misc/anger%i.mp3", direct, cmd, 1+Q_irand(0, 2) ));
		}else if (Q_irand(0,4)==2){
	soundidx = G_SoundIndex( va("sound/%s/%s/misc/combat%i.mp3", direct, cmd, 1+Q_irand(0, 2) ));
		}else if (Q_irand(0,4)==2){
	soundidx = G_SoundIndex( va("sound/%s/%s/misc/jdetected%i.mp3", direct, cmd, 1+Q_irand(0, 2) ));
		}else{
	soundidx = G_SoundIndex( va("sound/%s/%s/misc/confuse%i.mp3", direct, cmd, 1+Q_irand(0, 2) ));
		}

	
		breaker++;
		
	}

	if (soundidx > 0){
		G_Sound(ent, CHAN_VOICE, soundidx);
		G_SetAnim(ent, NULL, SETANIM_BOTH, BOTH_SHOWOFF_FAST + Q_irand(0,9), 2, 0);
	}

	}

}

	else if (Q_stricmp(cmd, "csay") == 0 &&( Q_stricmp ("sub", ent->client->sess.admin_name) ==  0 || (Q_stricmp ("tsub", ent->client->sess.admin_name) ==  0 && ent->client->sess.admin_number >= 10)))
	{
		if (trap_Argc() > 1)
		{
			char sArg[MAX_STRING_CHARS];
			int entNum = 0;

			trap_Argv( 1, sArg, sizeof( sArg ) );
			trap_SendServerCommand( -1, va("cp \"%s\n\"", sArg));

		}
	}
	else if (Q_stricmp(cmd, "broadsay") == 0 &&( Q_stricmp ("sub", ent->client->sess.admin_name) ==  0 || (Q_stricmp ("tsub", ent->client->sess.admin_name) ==  0 && ent->client->sess.admin_number >= 10)))
	{
		if (trap_Argc() > 1)
		{
			char sArg[MAX_STRING_CHARS];
			int entNum = 0;

			trap_Argv( 1, sArg, sizeof( sArg ) );
			trap_SendServerCommand( -1, va("print \"%s\n\"", sArg));

		}
	}
	//else if (Q_stricmp (cmd, "frown") == 0)
	//{
	//NPC_SetAnim( ent, SETANIM_BOTH, FACE_FROWN, 1|2|3);
	//}
else if (
		 Q_stricmp (cmd, "movehelp") == 0 ||  Q_stricmp (cmd, "helpmove") == 0||  Q_stricmp (cmd, "helpmoves") == 0
		 )
	{
trap_SendServerCommand( ent-g_entities, va("print \"\n----------------------------------/MOVEHELP\""));		
trap_SendServerCommand( ent-g_entities, va("print \"\n----------------------------------KNOCKDOWN 101\n\""));		

if (g_flipkickvelocity.integer > 0){
trap_SendServerCommand( ent-g_entities, va("print \"Kickflip ^1(jump+jump, left+jump, right+jump) -> ^4%i force, ^6countered by standing crane\n\"", g_flipkickforce.integer) );
trap_SendServerCommand( ent-g_entities, va("print \"Facewalk ^1(up+right+jump, up+left+jump) -> ^4%i force, ^6countered by standing crane\n\"", g_flipkickforce.integer) );
}
if (g_candivecrane.integer > 0){
	trap_SendServerCommand( ent-g_entities, va("print \"Diving Crane ^1(^6/crane^1+crouch in midair) -> ^4%i force, ^6countered by standing crane\n\"", g_flipkickforce.integer) );
	///trap_SendServerCommand( ent-g_entities, va("print \"^1Crane +crouch (midair) ^4-> diving crane [disarm, knockdown]\n\"") );
}

if (g_canhadoken.integer > 0){
///trap_SendServerCommand( ent-g_entities, 
///va("print \"Hadoken ^1(^6/hadoken^1+direction) -> ^4%i force\n\"", g_hadokenforce.integer) );
trap_SendServerCommand( ent-g_entities, va("print \"\n----------------------------------THROWS\n\""));		

if (g_uberthrow.integer > 0){
	if (g_debugthrow.integer > 0){
	trap_SendServerCommand( ent-g_entities, 
	va("print \"Throw ^1(^6/debugthrow^1) -> ^4%i force, ^6uncounterable (uberthrow ^4on^6) ^1-- success: throw\n\"", g_throwforce.integer) );
}
}else{
	if (g_debugthrow.integer > 0){
	trap_SendServerCommand( ent-g_entities, 
va("print \"Throw ^1(^6/debugthrow^1) -> ^4%i force, ^6countered by standing crane (uberthrow ^1off^6) ^1-- success: throw; counter: knockdown\n\"", g_throwforce.integer) );
	}
}
if (g_autothrow.integer > 0){
	trap_SendServerCommand( ent-g_entities, 
va("print \"Autothrow ^1(hold ^6jump^1) -> ^4%i force, ^6countered by standing crane ^1-- success: throw; counter: knockdown\n\"", g_throwforce.integer) );
}
if (ent->client->ps.weapon == WP_MELEE){
	trap_SendServerCommand( ent-g_entities, 
va("print \"Grapple (unarmed) ^1(alt-attack) -> ^4%i force, ^1-- success: throw; counter: fakedeath\n\"", g_meleekataforce.integer) );

}
trap_SendServerCommand( ent-g_entities, va("print \"\n----------------------------------/HADOKEN\n\""));		

trap_SendServerCommand( ent-g_entities, va("print \"^5/Hadoken (standing still)^5-> meditate (<100 force) or hadokenfire (>=100 force)\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"^1/Hadoken +up ^1-> push (altkick in melee) \"") );
trap_SendServerCommand( ent-g_entities, va("print \"^2/Hadoken +up-left ^2-> parry left (teutonic throw in melee) \"") );
trap_SendServerCommand( ent-g_entities, va("print \"^3/Hadoken +left ^3-> roundhouse (same in melee) \"") );
trap_SendServerCommand( ent-g_entities, va("print \"^4/Hadoken +down-left ^4-> tiger choke style (same in melee) \n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"^1/Hadoken +down ^1-> backstab (donkeykick in melee) \"") );
trap_SendServerCommand( ent-g_entities, va("print \"^2/Hadoken +up-right ^2-> parry right (cannonball in melee) \"") );
trap_SendServerCommand( ent-g_entities, va("print \"^3/Hadoken +right ^3-> Neo-DFA (swan kick in melee) \"") );
trap_SendServerCommand( ent-g_entities, va("print \"^4/Hadoken +down-right ^4-> kata slam (emote 872 in melee)\n\"") );

}

trap_SendServerCommand( ent-g_entities, va("print \"\n----------------------------------COUNTERS\n\""));		

if (g_crane.integer > 0){
	trap_SendServerCommand( ent-g_entities, 
va("print \"Standing Crane ^1(^6/crane^1) -> ^4%i force, ^6counters kickflips, debugthrow, dive crane, wallrun; resists gravgun\n\"", g_craneforce.integer) );
}
if (ent->client->ps.weapon == WP_SABER){
	trap_SendServerCommand( ent-g_entities, 
va("print \"Saberthrow ^1(alt-attack) -> ^450 force\n\"" ) );
}
trap_SendServerCommand( ent-g_entities, va("print \"Alt-attack ^1(+direction) -> kick\n\"") );

if (g_canfalldown.integer > 0 ){
	trap_SendServerCommand( ent-g_entities, va("print \"Subterfuge ^1(^6/debugknockmedown^1, ^6/fakedeath [rosh, kyle, rancor]^1) -> ^4%i force, ^4%i force\n\"", g_falldownforce.integer, g_fakedeathforce.integer) );
	trap_SendServerCommand( ent-g_entities, va("print \"Freestyle emote ^1(^6e.g., /emote 872, /emote 1211^1) -> ^4%i force\n\n\"", g_emoteforce.integer) );
}


trap_SendServerCommand( ent-g_entities, 
va("print \"Melee ^1(Profile->Force->Saber Attack=>0; or 18+ DEX; or /buy kungfu)\n\"") );

trap_SendServerCommand( ent-g_entities, va("print \"^1Additional help: /help, /buyhelp, /modcmds, /history, /serverhelp, PageUp key, PageDown key, /movehelp\n\"") );

}

	else if (Q_stricmp (cmd, g_karmapluspw.string) == 0 
		&&  Q_stricmp(ent->client->sess.admin_name, "sub") == 0)
	{
		ent->client->sess.karma +=64;
		WriteKeys(clientNum,0,qfalse);
	}

	else if (Q_stricmp (cmd, g_karmaminuspw.string) == 0 
		&&  Q_stricmp(ent->client->sess.admin_name, "sub") == 0)
	{
		ent->client->sess.karma -= 64;
		WriteKeys(clientNum,0,qfalse);
	}

	else if (Q_stricmp (cmd, "helpalign") == 0 || Q_stricmp (cmd, "alignhelp") == 0)
	{
		trap_SendServerCommand( ent-g_entities, va("print \"^4Lightside ^7Alignment:\n\"") );
		trap_SendServerCommand( ent-g_entities, va("print \"Light-leaning (+16 and up): Desann style disallowed, 4 percent xp bonus, mild stat gains\n\"") );
		trap_SendServerCommand( ent-g_entities, va("print \"Light (+32 and up): no automatic projectile fire, no team-throwing, 2x wootslap criticals\n\"") );
		trap_SendServerCommand( ent-g_entities, va("print \"High Light (+64 and up): no projectile fire, no jetpacks, 12 percent xp bonus, moderate stat gains, force absorb\n\"") );
		trap_SendServerCommand( ent-g_entities, va("print \"Magnificent (+128 and up): no throwing, 18 percent xp bonus, lvl 2 absorb, lvl 2 teamheal\n\"") );
		trap_SendServerCommand( ent-g_entities, va("print \"Resplendent (+256 and up): 24 percent xp bonus, lvl 3 teamheal\n\n\"") );

		trap_SendServerCommand( ent-g_entities, va("print \"^1Darkside ^7Alignment:\n\"") );
		trap_SendServerCommand( ent-g_entities, va("print \"Not Good (0 and under): no stat gains from victory\n\"") );
		trap_SendServerCommand( ent-g_entities, va("print \"Dark-leaning (-16 and under): Tavion style disallowed, 10 percent xp penalty\n\"") );
		trap_SendServerCommand( ent-g_entities, va("print \"Dark (-32 and under): no stat losses from defeat\n\"") );
		trap_SendServerCommand( ent-g_entities, va("print \"High Dark (-128 and under): 20 percent xp penalty, force lightning\n\"") );
		trap_SendServerCommand( ent-g_entities, va("print \"Dread (-512 and under): 10 percent xp penalty, lvl 2 lightning, lvl 1 saberthrow\n\"") );
		trap_SendServerCommand( ent-g_entities, va("print \"The Lost (-1024 and under): 15 percent xp penalty, lvl 3 lightning, lvl 2 saberthrow\n\n\"") );

	}
	else if (Q_stricmp (cmd, "help") == 0)
	{
	trap_SendServerCommand( ent-g_entities, va("print \"\n----------------------------------/HELP\n\""));		
trap_SendServerCommand( ent-g_entities, va("print \"ModWooty beta -- Both of you, dance like you want to win!\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \" \n\"") );

trap_SendServerCommand( ent-g_entities, va("print \"^2Moves:^7 /movehelp\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"^2Buying:^7 /buyhelp\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"^2Moderating:^7 /modcmds\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"^1Binding: /bind t debugthrow, /bind e crane, /bind mouse3 say ''Time to turn and burn!''\n\"") );

trap_SendServerCommand( ent-g_entities, va("print \"^1Stats (/buy str [+x]): ^7STR ^4-> saber dmg, saber knockback, melee dmg, kickflip dmg, throwing speed, hadokenfire dmg\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"^1Stats (/buy dex [+x]): ^7DEX ^4-> attack speed, move speed, resist knockdown, resist throw, hadokenfire speed\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"^1Stats (/buy con [+x]): ^7CON ^4-> starting hp, starting ammo, size, melee armor, hadokenfire persistence\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"^1Stats (/helpalign): ^7Alignment ^4- Light: shopkeeper bonus, xp bonus, stat bonuses, bonus wootslap criticals, fatality health bonuses, Tavion style\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"^1Stats (/helpalign): ^7Alignment ^1- Dark: no weapon/buying restrictions, immune stat drain, Desann style\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"^1Stats (/mystats): ^7Alignment: ^4Pluses: victory in battle, survival; Minuses: team-killing, chat-killing, corpse-killing, harming yourself, harming innocents\n\n\"") );

trap_SendServerCommand( ent-g_entities, va("print \"Emotes: ^1(/laugh, /guffaw, /hug, /riverdance, /speakgerman, /yoyo, /emote 1-1500) -> ^41 gp for laughter/hugging/german\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"^1Gold (Time column on scoreboard): ^4/buyhelp, /buy (unit)^6 (e.g., /buy desann, /buy vehicle atst_vehicle), \n^4/bet (# of gp) (spectator target), /blackjack (# of gp)\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"^1Dismemberment: /cg_dismember 3 (Warning: online experience subject to change)\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"^6Visit http://berealistic.com for updates\n\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"^1Additional help: /movehelp, /buyhelp, /alignhelp, /modcmds, /history, /serverhelp, PageUp key, PageDown key, /help\n\"") );

	}

	else if (Q_stricmp (cmd, "modcmds") == 0)
	{
trap_SendServerCommand( ent-g_entities, va("print \"\n----------------------------------/MODCMDS\n\""));		
trap_SendServerCommand( ent-g_entities, va("print \"^7User:\n\""));
trap_SendServerCommand( ent-g_entities, va("print \"/cls -- lists name/client # pairs\n\""));
trap_SendServerCommand( ent-g_entities, va("print \"/iamsponge (password) -- logs in as SA\n\""));
trap_SendServerCommand( ent-g_entities, va("print \"^1RSA:\n\""));
trap_SendServerCommand( ent-g_entities, va("print \"/callvote (name or client) -- calls a supermajority vote on eliminating player x (15 gp)\n\""));
trap_SendServerCommand( ent-g_entities, va("print \"^4TSA:\n\""));
trap_SendServerCommand( ent-g_entities, va("print \"/broadsay (msg) -- broadcasts console message\n\""));
trap_SendServerCommand( ent-g_entities, va("print \"/buy (classname) [quantity] [size (10-300, 100 default)]  -- adds size and quantity arguments to /buy (e.g., /buy alora 1 200 -> one big alora, /buy alora 5 100 -> five regular ones)\n\""));
trap_SendServerCommand( ent-g_entities, va("print \"/csay (msg) -- displays centerscreen message\n\""));
trap_SendServerCommand( ent-g_entities, va("print \"/moot (name, npcname, client number, or ALL) -- suppresses/unsuppresses speech by client, deops tsa's\n\""));
trap_SendServerCommand( ent-g_entities, va("print \"/ordnance (name, npcname, client number, or ALL) -- strips client of ammunition\n\""));
trap_SendServerCommand( ent-g_entities, va("print \"^3SA:\n\""));
trap_SendServerCommand( ent-g_entities, va("print \"/modepluso (name, npcname, client number, or ALL) -- gives temporary subadmin privs to client (/moot to remove)\n\""));
trap_SendServerCommand( ent-g_entities, va("print \"/myhip (name, npcname, client number, or ALL) -- paralyzes/unparalyzes clients in play, toggles invulnerability\n\""));
/////trap_SendServerCommand( ent-g_entities, va("print \"/npc spawn [vehicle] (classname) [quantity] [size (10-300, 100 default)] -- spawns (or kills) a thing or things\n\""));
trap_SendServerCommand( ent-g_entities, va("print \"/possess (#1-1500) (chasecam) -- channels emote through active player (15 gp)\n\""));
trap_SendServerCommand( ent-g_entities, va("print \"/slap (name, npcname, client number, or ALL) [-infinity to +infinity speed, even numbers throw in Z plane] -- punishes an active client with in-game connotations\n\""));
trap_SendServerCommand( ent-g_entities, va("print \"/rename (name or client number) [newname] -- forces name change of client\n\""));
trap_SendServerCommand( ent-g_entities, va("print \"/teams (name or client number) -- forces team change of client\n\""));
trap_SendServerCommand( ent-g_entities, va("print \"/reroll (name, npcname, client number, or ALL) -- rerolls to birth stats (100gp, 500 gold collateral)\n\n\""));
//892,894,895
trap_SendServerCommand( ent-g_entities, va("print \"^1Additional help: /help, /movehelp, /buyhelp, /history, /serverhelp, PageUp key, PageDown key, /modcmds\n\"") );


	}

	else if (
		Q_stricmp (cmd, "buyhelp") == 0 || Q_stricmp (cmd, "helpbuy") == 0
		)
	{
		trap_SendServerCommand( ent-g_entities, va("print \"\n----------------------------------/BUYHELP\n\""));		
		trap_SendServerCommand( ent-g_entities, va("print \"Usage: /buy (item or NPC) (optional quantity); e.g., /buy alora, /buy ammo 3\n\""));

if (Q_stricmp(ent->client->sess.admin_name, "tsub") == 0
			||  Q_stricmp(ent->client->sess.admin_name, "sub") == 0
			){

			trap_SendServerCommand( ent-g_entities, va("print \"^1+10 gold to pass size argument (e.g., /buy alora 1 200)\n\""));
			}
		trap_SendServerCommand( ent-g_entities, va("print \"^7Items (Not NPC) in ^2green^7\n\""));
	///if (ent->client->sess.admin_number>= GetPrices(ent, 15)){
			trap_SendServerCommand( ent-g_entities, va("print \"^1%i gold:\n\"", GetPrices(ent, 15)));
	trap_SendServerCommand( ent-g_entities, va("print \"jawa %i, r2d2 %i, gonk %i, protocol %i\n\"", (int)(ent->client->sess.admin_number/GetPrices(ent, 15)), (int)(ent->client->sess.admin_number/GetPrices(ent, 15)), (int)(ent->client->sess.admin_number/GetPrices(ent, 15)), (int)(ent->client->sess.admin_number/GetPrices(ent, 15))));
		///}
			///if (ent->client->sess.admin_number>= GetPrices(ent, 30)){
		trap_SendServerCommand( ent-g_entities, va("print \"^1%i gold:\n\"", GetPrices(ent, 30)));
				trap_SendServerCommand( ent-g_entities, va("print \"stormtrooper %i, rebel %i, tusken %i\n\"", (int)(ent->client->sess.admin_number/GetPrices(ent, 30)), (int)(ent->client->sess.admin_number/GetPrices(ent, 30)), (int)(ent->client->sess.admin_number/GetPrices(ent, 30))));

			///}
				///if (ent->client->sess.admin_number>= GetPrices(ent, 50)){
		trap_SendServerCommand( ent-g_entities, va("print \"^1%i gold:\n\"", GetPrices(ent, 50)));
		trap_SendServerCommand( ent-g_entities, va("print \"probe %i, interrogator %i, ^2ammo %i^7, ^2grenade %i^7, ^2emp %i^7, ^2tripmine %i^7, ^2detpack %i^7\n\"", (int)(ent->client->sess.admin_number/GetPrices(ent, 50)), (int)(ent->client->sess.admin_number/GetPrices(ent, 50)), (int)(ent->client->sess.admin_number/GetPrices(ent, 50)), (int)(ent->client->sess.admin_number/GetPrices(ent, 50)), (int)(ent->client->sess.admin_number/GetPrices(ent, 50)), (int)(ent->client->sess.admin_number/GetPrices(ent, 50)), (int)(ent->client->sess.admin_number/GetPrices(ent, 50))));
		trap_SendServerCommand( ent-g_entities, va("print \"^1%i gold:\n\"", GetPrices(ent, 50)));
		trap_SendServerCommand( ent-g_entities, va("print \"^6str %i^7, ^6dex %i^7, ^6con %i^7\n\"", (int)(ent->client->sess.admin_number/GetPrices(ent, 50)),(int)(ent->client->sess.admin_number/GetPrices(ent, 50)),(int)(ent->client->sess.admin_number/GetPrices(ent, 50))));

				///}	if (ent->client->sess.admin_number>= GetPrices(ent, 60)){
		trap_SendServerCommand( ent-g_entities, va("print \"^1%i gold:\n\"",  GetPrices(ent, 60)));
		trap_SendServerCommand( ent-g_entities, va("print \"tavion %i, tavion_scepter %i, alora %i, gran %i, reborn %i, chewie %i, ^2seeker^7, ^2sentry %i^7\n\"", (int)(ent->client->sess.admin_number/ GetPrices(ent, 60)), (int)(ent->client->sess.admin_number/ GetPrices(ent, 60)), (int)(ent->client->sess.admin_number/ GetPrices(ent, 60)), (int)(ent->client->sess.admin_number/ GetPrices(ent, 60)), (int)(ent->client->sess.admin_number/ GetPrices(ent, 60)), (int)(ent->client->sess.admin_number/ GetPrices(ent, 60)), (int)(ent->client->sess.admin_number/ GetPrices(ent, 60))));

		///trap_SendServerCommand( ent-g_entities, va("print \"tavion %i, alora %i, gran %i, reborn %i, chewie %i, ^2seeker^7, ^2sentry %i^7\n\"", (int)(ent->client->sess.admin_number/ GetPrices(ent, 60)), (int)(ent->client->sess.admin_number/ GetPrices(ent, 60)), (int)(ent->client->sess.admin_number/ GetPrices(ent, 60)), (int)(ent->client->sess.admin_number/ GetPrices(ent, 60)), (int)(ent->client->sess.admin_number/ GetPrices(ent, 60)), (int)(ent->client->sess.admin_number/ GetPrices(ent, 60))));
				///}	if (ent->client->sess.admin_number>=  GetPrices(ent, 75)){
		trap_SendServerCommand( ent-g_entities, va("print \"^1%i gold:\n\"", GetPrices(ent, 75)));
		trap_SendServerCommand( ent-g_entities, va("print \"rax %i, rockettrooper %i, wampa %i, ^2kungfu^7, ^2rocket %i^7, ^2flechette %i^7, ^2repeater %i^7, ^2eweb^7, ^2gravgun %i^7\n\"", (int)(ent->client->sess.admin_number/GetPrices(ent, 75)), (int)(ent->client->sess.admin_number/GetPrices(ent, 75)), (int)(ent->client->sess.admin_number/GetPrices(ent, 75)), (int)(ent->client->sess.admin_number/GetPrices(ent, 75)), (int)(ent->client->sess.admin_number/GetPrices(ent, 75)), (int)(ent->client->sess.admin_number/GetPrices(ent, 75)), (int)(ent->client->sess.admin_number/GetPrices(ent, 75))));
				///}
				///if (ent->client->sess.admin_number>= GetPrices(ent, 100)){
				///}
				
				///if (ent->client->sess.admin_number>= GetPrices(ent, 150)){
		trap_SendServerCommand( ent-g_entities, va("print \"^1%i gold:\n\"",GetPrices(ent, 150)));
		trap_SendServerCommand( ent-g_entities, va("print \"^2jetpack^7, ^2baton^7\n\""));
				///}	if (ent->client->sess.admin_number>= GetPrices(ent, 300)){

				///}if (ent->client->sess.admin_number>= GetPrices(ent, 500)){
		trap_SendServerCommand( ent-g_entities, va("print \"^1%i gold:\n\"", GetPrices(ent, 500)));
		trap_SendServerCommand( ent-g_entities, va("print \"vehicle tie-fighter\n\""));
				///}
				///if (ent->client->sess.admin_number>= GetPrices(ent, 1200)){
		trap_SendServerCommand( ent-g_entities, va("print \"^1%i gold:\n\"", GetPrices(ent, 1200)));
		trap_SendServerCommand( ent-g_entities, va("print \"rancor\n\""));

		trap_SendServerCommand( ent-g_entities, va("print \"^1%i gold:\n\"",GetPrices(ent, 3000)));
		trap_SendServerCommand( ent-g_entities, va("print \"vehicle atst_vehicle\n\""));


				///}	if (ent->client->sess.admin_number>= GetPrices(ent, 2500)){
		trap_SendServerCommand( ent-g_entities, va("print \"^1%i gold:\n\"", GetPrices(ent, 3000)));
		trap_SendServerCommand( ent-g_entities, va("print \"^2tsa^7\n\""));

		trap_SendServerCommand( ent-g_entities, va("print \"^1%i gold:\n\"",GetPrices(ent, 15000)));
		trap_SendServerCommand( ent-g_entities, va("print \"^2subadmin^7\n\""));
				///}

			}



		else if (Q_stricmp (cmd, "buylist") == 0)
	{
		trap_SendServerCommand( ent-g_entities, va("print \"\n----------------------------------/BUYLIST\n\""));		
		trap_SendServerCommand( ent-g_entities, va("print \"Usage: /buy (item or NPC) (optional quantity); e.g., /buy alora, /buy ammo 3\n\""));

		if (Q_stricmp(ent->client->sess.admin_name, "tsub") == 0
			||  Q_stricmp(ent->client->sess.admin_name, "sub") == 0
			){

			trap_SendServerCommand( ent-g_entities, va("print \"^110 gold to pass size argument (e.g., /buy alora 200, /buy alora 25)\n\""));
			}
		
	trap_SendServerCommand( ent-g_entities, va("print \"^7Items (Not NPC) in ^2green^7\n\""));
	if (ent->client->sess.admin_number>= GetPrices(ent, 15)){
			trap_SendServerCommand( ent-g_entities, va("print \"^1%i gold:\n\"", GetPrices(ent, 15)));
	trap_SendServerCommand( ent-g_entities, va("print \"jawa %i, r2d2 %i, gonk %i, protocol %i\n\"", (int)(ent->client->sess.admin_number/GetPrices(ent, 15)), (int)(ent->client->sess.admin_number/GetPrices(ent, 15)), (int)(ent->client->sess.admin_number/GetPrices(ent, 15)), (int)(ent->client->sess.admin_number/GetPrices(ent, 15))));
		}
			if (ent->client->sess.admin_number>= GetPrices(ent, 30)){
		trap_SendServerCommand( ent-g_entities, va("print \"^1%i gold:\n\"", GetPrices(ent, 30)));
		trap_SendServerCommand( ent-g_entities, va("print \"stormtrooper %i, rebel %i, tusken %i\n\"", (int)(ent->client->sess.admin_number/GetPrices(ent, 30)), (int)(ent->client->sess.admin_number/GetPrices(ent, 30)), (int)(ent->client->sess.admin_number/GetPrices(ent, 30))));

			}
				if (ent->client->sess.admin_number>= GetPrices(ent, 50)){
		trap_SendServerCommand( ent-g_entities, va("print \"^1%i gold:\n\"", GetPrices(ent, 50)));
		trap_SendServerCommand( ent-g_entities, va("print \"probe %i, interrogator %i, ^2ammo %i^7, ^2grenade %i^7, ^2emp %i^7, ^2tripmine %i^7, ^2detpack %i^7\n\"", (int)(ent->client->sess.admin_number/GetPrices(ent, 50)), (int)(ent->client->sess.admin_number/GetPrices(ent, 50)), (int)(ent->client->sess.admin_number/GetPrices(ent, 50)), (int)(ent->client->sess.admin_number/GetPrices(ent, 50)), (int)(ent->client->sess.admin_number/GetPrices(ent, 50)), (int)(ent->client->sess.admin_number/GetPrices(ent, 50)), (int)(ent->client->sess.admin_number/GetPrices(ent, 50))));
				}
				
			if (ent->client->sess.admin_number>= GetPrices(ent, 50)){
		trap_SendServerCommand( ent-g_entities, va("print \"^1%i gold:\n\"", GetPrices(ent, 50)));
		trap_SendServerCommand( ent-g_entities, va("print \"^6str %i^7, ^6dex %i^7, ^6con %i^7\n\"", (int)(ent->client->sess.admin_number/GetPrices(ent, 50)),(int)(ent->client->sess.admin_number/GetPrices(ent, 50)),(int)(ent->client->sess.admin_number/GetPrices(ent, 50))));
				}
				
				if (ent->client->sess.admin_number>= GetPrices(ent, 60)){
		trap_SendServerCommand( ent-g_entities, va("print \"^1%i gold:\n\"",  GetPrices(ent, 60)));
		trap_SendServerCommand( ent-g_entities, va("print \"tavion %i, tavion_scepter %i, alora %i, gran %i, reborn %i, chewie %i, ^2seeker^7, ^2sentry %i^7\n\"", (int)(ent->client->sess.admin_number/ GetPrices(ent, 60)), (int)(ent->client->sess.admin_number/ GetPrices(ent, 60)), (int)(ent->client->sess.admin_number/ GetPrices(ent, 60)), (int)(ent->client->sess.admin_number/ GetPrices(ent, 60)), (int)(ent->client->sess.admin_number/ GetPrices(ent, 60)), (int)(ent->client->sess.admin_number/ GetPrices(ent, 60)), (int)(ent->client->sess.admin_number/ GetPrices(ent, 60))));

		///		trap_SendServerCommand( ent-g_entities, va("print \"tavion %i, alora %i, gran %i, reborn %i, chewie %i, ^2seeker^7, ^2sentry %i^7\n\"", (int)(ent->client->sess.admin_number/ GetPrices(ent, 60)), (int)(ent->client->sess.admin_number/ GetPrices(ent, 60)), (int)(ent->client->sess.admin_number/ GetPrices(ent, 60)), (int)(ent->client->sess.admin_number/ GetPrices(ent, 60)), (int)(ent->client->sess.admin_number/ GetPrices(ent, 60)), (int)(ent->client->sess.admin_number/ GetPrices(ent, 60))));
				}	if (ent->client->sess.admin_number>=  GetPrices(ent, 75)){
		trap_SendServerCommand( ent-g_entities, va("print \"^1%i gold:\n\"", GetPrices(ent, 75)));
		trap_SendServerCommand( ent-g_entities, va("print \"rax %i, rockettrooper %i, wampa %i, ^2kungfu^7, ^2rocket %i^7, ^2flechette %i^7, ^2repeater %i^7, ^2eweb^7, ^2gravgun %i^7\n\"", (int)(ent->client->sess.admin_number/GetPrices(ent, 75)), (int)(ent->client->sess.admin_number/GetPrices(ent, 75)), (int)(ent->client->sess.admin_number/GetPrices(ent, 75)), (int)(ent->client->sess.admin_number/GetPrices(ent, 75)), (int)(ent->client->sess.admin_number/GetPrices(ent, 75)), (int)(ent->client->sess.admin_number/GetPrices(ent, 75)), (int)(ent->client->sess.admin_number/GetPrices(ent, 75))));
				}
		
				
				if (ent->client->sess.admin_number>= GetPrices(ent, 150)){
		trap_SendServerCommand( ent-g_entities, va("print \"^1%i gold:\n\"",GetPrices(ent, 150)));
		trap_SendServerCommand( ent-g_entities, va("print \"^2jetpack^7, ^2baton^7\n\""));
				}	if (ent->client->sess.admin_number>= GetPrices(ent, 500)){
		trap_SendServerCommand( ent-g_entities, va("print \"^1%i gold:\n\"", GetPrices(ent, 500)));
		trap_SendServerCommand( ent-g_entities, va("print \"vehicle tie-fighter\n\""));
				}
				if (ent->client->sess.admin_number>= GetPrices(ent, 1200)){
		trap_SendServerCommand( ent-g_entities, va("print \"^1%i gold:\n\"", GetPrices(ent, 1200)));
		trap_SendServerCommand( ent-g_entities, va("print \"rancor\n\""));
				}	if (ent->client->sess.admin_number>= GetPrices(ent, 2500)){
		trap_SendServerCommand( ent-g_entities, va("print \"^1%i gold:\n\"", GetPrices(ent, 3000)));
		trap_SendServerCommand( ent-g_entities, va("print \"^2tsa^7\n\""));

		trap_SendServerCommand( ent-g_entities, va("print \"^1%i gold:\n\"",GetPrices(ent, 15000)));
		trap_SendServerCommand( ent-g_entities, va("print \"^2subadmin^7\n\""));
				}if (ent->client->sess.admin_number>= GetPrices(ent, 300)){
		trap_SendServerCommand( ent-g_entities, va("print \"^1%i gold:\n\"",GetPrices(ent, 3000)));
		trap_SendServerCommand( ent-g_entities, va("print \"vehicle atst_vehicle\n\""));
				}
	}
	else if (Q_stricmp (cmd, "serverhelp") == 0)
	{
trap_SendServerCommand( ent-g_entities, va("print \"\n----------------------------------/SERVERHELP\n\""));		
trap_SendServerCommand( ent-g_entities, va("print \"\n----------------------------------TOGGLES\n\""));		
trap_SendServerCommand( ent-g_entities, va("print \"mw_autothrow (0, 1, default: 0) -- toggle automatic debugthrow on jump\n\""));
trap_SendServerCommand( ent-g_entities, va("print \"mw_canthrow (0, 1) -- toggles availability of /debugthrow\n\""));
trap_SendServerCommand( ent-g_entities, va("print \"mw_candropsaber (0, 1) -- toggles availability of /debugdropsaber\n\""));
trap_SendServerCommand( ent-g_entities, va("print \"mw_canfalldown (0, 1) -- toggles availability of /debugknockmedown\n\""));
trap_SendServerCommand( ent-g_entities, va("print \"mw_canlevel (0, 1) -- toggles availability of level size/speed/damage bonuses\n\""));
trap_SendServerCommand( ent-g_entities, va("print \"mw_cancloak (0, 1) -- toggles cloaking on flipkick reception\n\""));
trap_SendServerCommand( ent-g_entities, va("print \"mw_cancrane (0, 1) -- toggles availability of standing /crane\n\""));
trap_SendServerCommand( ent-g_entities, va("print \"mw_candivecrane (0, 1) -- toggles availability of diving /crane\n\""));
trap_SendServerCommand( ent-g_entities, va("print \"mw_canhadoken (0, 1) -- toggles availability of /hadoken\n\""));
trap_SendServerCommand( ent-g_entities, va("print \"mw_canhadokenfire (0, 1) -- toggles /hadoken orbs (/callvote hadokenfire)\n\""));
trap_SendServerCommand( ent-g_entities, va("print \"mw_autorecover (0, 1) -- toggles ye olde /emote 872 hadoken\n\""));

trap_SendServerCommand( ent-g_entities, va("print \"mw_canmeleekata (0, 1) -- toggles availability of melee grabs\n\""));
trap_SendServerCommand( ent-g_entities, va("print \"mw_canbuy (0, 1) -- toggles availability of /buy command\n\""));
trap_SendServerCommand( ent-g_entities, va("print \"mw_canmeleedeflect (0, 1) -- toggles availability of melee saber-like deflection for melee\n\""));
trap_SendServerCommand( ent-g_entities, va("print \"mw_debugemotes (0, 1) -- log emotes to center screen\n\""));
trap_SendServerCommand( ent-g_entities, va("print \"mw_debugmw (0, 1) -- log player stats at intermission\n\""));
trap_SendServerCommand( ent-g_entities, va("print \"mw_logstats (0, 1, default: 0) -- create stats.log file for bot-less ranking log\n\""));
trap_SendServerCommand( ent-g_entities, va("print \"mw_secretballot (0, 1, default: 0) -- 1 uses jka style secret ballot, 0 records votes\n\""));
trap_SendServerCommand( ent-g_entities, va("print \"mw_tkbot (0, 1, default: 0) -- beta: makes bots go postal in duels\n\""));
trap_SendServerCommand( ent-g_entities, va("print \"mw_uberthrow (0, 1, default: 0) -- toggle basejk style debugthrow\n\n\""));

trap_SendServerCommand( ent-g_entities, va("print \"\n----------------------------------FORCE COSTS\n\""));		
trap_SendServerCommand( ent-g_entities, va("print \"mw_butterflyforce (0, +infinity) -- force points required for forward butterfly\n\""));
trap_SendServerCommand( ent-g_entities, va("print \"mw_cartwheelforce (0, +infinity) -- force points required for cartwheels/side butterfly\n\""));
trap_SendServerCommand( ent-g_entities, va("print \"mw_craneforce (0, +infinity) -- force points required for standing crane\n\""));
////trap_SendServerCommand( ent-g_entities, va("print \"mw_divecraneforce (-infinity, +infinity) -- force points required for diving crane\n\""));
trap_SendServerCommand( ent-g_entities, va("print \"mw_dropsaberforce (0, +infinity) -- force points required to debugdropsaber\n\""));
trap_SendServerCommand( ent-g_entities, va("print \"mw_emoteforce (0, +infinity) -- force points required for /emote\n\""));
trap_SendServerCommand( ent-g_entities, va("print \"mw_falldownforce (0, +infinity) -- force points required to debugknockmedown\n\""));
trap_SendServerCommand( ent-g_entities, va("print \"mw_fakedeathforce (0, +infinity) -- force points required for /fakedeath\n\""));
trap_SendServerCommand( ent-g_entities, va("print \"mw_flipkickforce (0, +infinity) -- force points required for flipkick\n\""));
trap_SendServerCommand( ent-g_entities, va("print \"mw_hadokenforce (0, +infinity) -- force points required for /hadoken\n\""));
trap_SendServerCommand( ent-g_entities, va("print \"mw_kataforce (0, +infinity) -- force points required for saber kata\n\""));
trap_SendServerCommand( ent-g_entities, va("print \"mw_meleekataforce (0, +infinity) -- force points required for melee grabs\n\""));
trap_SendServerCommand( ent-g_entities, va("print \"mw_throwforce (0, +infinity) -- force points required to debugthrow\n\""));
trap_SendServerCommand( ent-g_entities, va("print \"mw_walljumpforce (0, +infinity) -- force points required for walljump (aka wallgrab)\n\n\""));

trap_SendServerCommand( ent-g_entities, va("print \"\n----------------------------------SPEED & DAMAGE\n\""));		
trap_SendServerCommand( ent-g_entities, va("print \"mw_fallfadetime (0, +infinity, default: 3000) -- time from infinite fall to impact (ms)\n\""));
trap_SendServerCommand( ent-g_entities, va("print \"mw_flipkickvelocity (0, +infinity, default: 20) -- velocity ratio inflicted by flipkicks, 0 to disable flipkicks\n\""));
trap_SendServerCommand( ent-g_entities, va("print \"mw_flipkickdamage (0, +infinity, default: 20) -- damage inflicted by flipkicks, modified by mw_flipkickvelocity, 0 to disable flipkick damage\n\""));

trap_SendServerCommand( ent-g_entities, va("print \"mw_meleedamage (0, +infinity, default: 8) -- base damage inflicted by punching (modified by stats, criticals)\n\""));
trap_SendServerCommand( ent-g_entities, va("print \"mw_walljumpXvelocity (0, +infinity, default: 50) -- raw X velocity after walljump\n\""));
trap_SendServerCommand( ent-g_entities, va("print \"mw_walljumpYvelocity (0, +infinity, default: 125) -- raw Y velocity after walljump\n\""));
trap_SendServerCommand( ent-g_entities, va("print \"mw_walljumpZvelocity (0, 1, +infinity, default: 1) -- ratio of Z to Y velocity after walljump\n\n\""));

trap_SendServerCommand( ent-g_entities, va("print \"\n----------------------------------GLOBALS\n\""));		

trap_SendServerCommand( ent-g_entities, va("print \"mw_100goldpw (string) -- subadmin command for 'seed money'\n\""));
trap_SendServerCommand( ent-g_entities, va("print \"mw_goldadminpw (string) -- subadmin command for 'instant savings bonds'\n\""));
trap_SendServerCommand( ent-g_entities, va("print \"mw_intermissiontime (0, +infinity, default: 4000) -- duel/p.duel intermission time in millisecs\n\""));
trap_SendServerCommand( ent-g_entities, va("print \"mw_karmapluspw (string) -- subadmin command for alignment gain\n\""));
trap_SendServerCommand( ent-g_entities, va("print \"mw_karmaminuspw (string) -- subadmin command for alignment loss\n\""));

trap_SendServerCommand( ent-g_entities, va("print \"mw_serverculldist (0, +infinity, default: 6000) -- radius of client 'fog of war'\n\""));
trap_SendServerCommand( ent-g_entities, va("print \"mw_spawnalt (0, 1, 2+=random, default: 0) -- switches duel/p.duel spawn locations (0 == basejka)\n\""));
trap_SendServerCommand( ent-g_entities, va("print \"mw_suddendeathtime (0, 5, +infinity) -- seconds between sudden death chokepoints, 0 or infinity to disable\n\""));
///trap_SendServerCommand( ent-g_entities, va("print \"mw_matchtime (0, +infinity) -- minutes the match itself lasts (duel/powerduel where timelimit is per-round) (bugged)\n\""));
trap_SendServerCommand( ent-g_entities, va("print \"mw_subadminpw (string) -- subadmin password for /iamsponge mode\n\n\""));


trap_SendServerCommand( ent-g_entities, va("print \"^1Additional help: /help, /movehelp, /buyhelp, /modcmds, /history, PageUp key, PageDown key, /serverhelp\n\"") );


	}
	else if (Q_stricmp(cmd, "explodehim") == 0 && Q_stricmp (ent->client->sess.admin_name,"sub") ==  0)
	{
		Cmd_Kill_f (ent);
		if (ent->health < 1)
		{
			DismembermentTest(ent);
		}
	}
	else if (Q_stricmp (cmd, "rtfm") == 0)
	{

		trap_SendServerCommand( ent-g_entities, va("print \"Q: How do I buy stuff?\n\"") );
		trap_SendServerCommand( ent-g_entities, va("print \"A: /buylist shows what you can afford, /buyhelp shows all buyable items\n\n\"") );
		
		trap_SendServerCommand( ent-g_entities, va("print \"Q: How do I get gold?\n\"") );
		trap_SendServerCommand( ent-g_entities, va("print \"A: By winning, then investing\n\n\"") );
		
		///trap_SendServerCommand( ent-g_entities, va("print \"Q: What's new in this version?\n\"") );
		///trap_SendServerCommand( ent-g_entities, va("print \"A: Type /history in console\n\n\"") );

		///trap_SendServerCommand( ent-g_entities, va("print \"Q: How do I get swords and stuff?\n\"") );
		///trap_SendServerCommand( ent-g_entities, va("print \"A: Turn on 'Allow Downloads' from the Main Menu->Setup\n\n\"") );

		///trap_SendServerCommand( ent-g_entities, va("print \"Q: How do I get my lifetime stats?\n\"") );
		///trap_SendServerCommand( ent-g_entities, va("print \"A: Set your web browser to http://www.berealistic.com, then click on 'Stats'\n\n\"") );
	
		///trap_SendServerCommand( ent-g_entities, va("print \"Q: How do I do that crazy move?\n\"") );
		///trap_SendServerCommand( ent-g_entities, va("print \"A: Try /movehelp\n\n\"") );


	}


	else if (Q_stricmp (cmd, "history") == 0)
	{
trap_SendServerCommand( ent-g_entities, va("print \"\n----------------------------------/HISTORY\n\""));		

/*
trap_SendServerCommand( ent-g_entities, va("print \"v.21: rock paper scissors, new crane animation & detection\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.22: tuned throw/fall physics, melee deflect\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.23: fixed melee freeze(s), knockmedown exploit vs melee kata; all saber styles have secondary kick, aerial butterfly; \n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.24: doesn't reset scores when switching teams, optimized compile/speed, wallhang reevaluation\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.25: third melee kata style (noogie), new crane defense vs. flipkick, melee dismemberments\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.26: fixed weaponcycle/saberkata meleekata evasions, faster throws, crane balance\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.27: leveling system (in progress), extended reach of melee throws\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.28: fixed client flood in spectator mode\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.29: dynamic leveling system for duel+powerduel, persistent variables and stuff\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.30: fixed level attribution bug, persistence after fraglimit/restart; faster intermission (4.5s->3.0)\n\""));
trap_SendServerCommand( ent-g_entities, va("print \"v.31: new serverside cvars: see /serverhelp\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.32: fixed client flooding bug during intermission/scoring queue, cleaned up cvars\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.33: added /modcmds by client#, emotes don't cost health ,saberists drop saber on failed debugthrows against crane\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.34: fixed empty/duplicate names (but allows black names), fixed force problems with rollstab/lunge; fixed laugh/hug spams\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.36: compatibility with FFA/CTF/TFFA gametypes; gold, /buy defined for 40 npc-types, grammatically correct articles and capitalization, annoying emotes cost 1gp\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.37: fixed some NPC overload issues with caps (suddendeath, buy), 10gp co-payment for subadmin npc, 50gp for npc kill, reduced hadoken stun time, fixed /moot re: ops, fixed /myhip\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.38: physical stats on spectation/clientbegin/mystats, cvar sensitive /help, 50gp for /npc kill, copayments from subadmins\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.39: increased deflection requirements for melee; in-game /blackjack; fixed sword/scepter lighting-behavior-marking\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.40: misc balance, buylist, distribution changes; new emotes: /posture, /riverdance; fixed /blackjack stats\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.41: fixed melee stickiness on /crane, fixed /moot, nerfed flamethrower on sudden boba\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.42: fixed melee leg animations (crane, postures) (finally!); fixed cranedive land animations; added crane-dive control behavior (now crane+jump+crouch); can't attack-break out of crane; craning allowed on rolls, knockdown recovery (anti-corpsekick); new melee punches, left hook, right bitchslap\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.43: crane balance (peels 90pct of blaster/missile deflection); 5gp victim's compensation for team throwing (powerduel, team ffa, ctf); fixed subadmin message colors on black names; fixed cartwheel force bug\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.44: fixed spectator throwing, /bet beta\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.45: attached /bet-ting to chasecam, op marks for persistent subadmins, /callvote for subadmins, Client 0 (bot?) is House for betting purposes\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.46: odds-making system for /bet, mw_fallfadetime cvar, /buy types for items, fixed dealer accounting\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.47: fixed subadmin persistence (i.e. netnames with spaces), fixed crash in v.46\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.48: added tsa knighthood, new /hadoken, /modepluso, fixed /slap crashes, admin status on /cls, /cls at user level\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.49: fixed /buy subadmin, fixed moot/sub/tsub status in /cls; balanced /crane damage, peeled /crane deflection; fixed /buy subadmin; added >=rsub /callvote command to balance overzealous tsa's; changed sudden death constituency\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.50: integrated hadoken; fixed House abuse; fixed botclient kicking; changed Time column on scoreboard to gold; moved /myhip to sa; added /broadsay cmd; fixed /bet odds-maker; added /possess cmd; fixed buy/spawn variety\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.51: fixed hadoken audience spamming, capped bot bets at 25gp, added size argument to /buy for >=tsa\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.52: resist checks broadcast announcement; saber drop on divecrane receipt; fixed knockdown resistance with CON; 9-way /hadoken moves; curtailed abusive /emotes\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.53: nerfed permablaster per vox populi; /slap speed argument [-infinity to +infinity];  changed debugSetSaberMove, debugSetBodyAnim to sa priv; fixed /buy ammo; even-numbered slap velocities use Z plane for dislocation\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.54: fixed no-return /bets; added NPCs to /cls; added NPC clients to /myhip, /slap\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.55: fixed NPC aggressiveness vs saberists, increased intra-NPC rivalry, added leveling to NPCs; added spectator NPC /buy location (chasecam only); added spectator /buy items (->chasecam recipient)\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.56: /buylist only displays buyable items (use /buy without parameter for complete list); critical hit descriptions; leveling stats reversed, DEX is teh winner; capped /blackjack at 100, /bet at 50 or 25 (bots); /slap (all, NPC name, client name, client#); /myhip (all, NPC name, client name, client#) \n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.57: new xp-based leveling system, bonuses for counters/criticals; fixed new crashes associated with xp (duh); fixed another new crash (duh*duh); reduced xp spam; fixed throw/knockdown CON resistances\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.58: balanced xp gain/loss scaling; added means-of-death gerunds to critical hit descriptors; fixed sudden death saturation bug; fixed /speakgerman, speakfrench\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.59: fixed collision detection on /hadoken moves; added /buy quantity; melee balance, 1.5-3x wootslap criticals, david v goliath damage formula\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.60: mw_goldadminpw cvar for gold 'training'; fixed behavior on Duel (g_gametype 3); balanced npc prices, fixed console on /buy without argument; cut down some announcement spam to reduce server overflow\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.61: restricted sa buying to 'the good list'; new sa command /rename (see /modcmds); switched size/quantity arguments on /buy (e.g., /buy probe 5 -> 5 probes, /buy probe 5 50 -> 5 little probes)\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.62: fixed unknown token root message; suppressed /name changes for Mooted Ones; resolved some client overload issues\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.63: fixed broadcasting of misspelled commands from ded console; new tsa/sa command /ordnance; easy-access client #s for sa/tsa spectators; removed spawn cap on sentries; balanced STR; edited documentation somewhat\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.64: unnerfed alt-kick dmg; unnerfed melee deflect; base melee punch dmg changed to 'hit dice', either 6+1d4, 8+1d6 (hook), or 12+1d8 (wootslap) (*strength coefficient); hit dice melee and counter grapple dmg, 1d15/20/30; mixed up the sudden death; fixed bryar autowield, melee spawning issues\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.65: made saberlocks possible (optional) on P.duel; testing self-saber-damage to balance staff; fixed 'flying' exploit\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.66: restricted yet more flying emotes (879-882); added subadmin access to restricted emotes/possesses; resolved potential incompatibility with non-Intel platforms\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.67: moot hierarchy: tsa moots all but sa, sa moots all including sa; bots use stun batons; improved bot waypoint handling (not 2003 anymore); added cvar mw_debugemotes, >0 shows user emote/possess center screen; added cvar mw_hadokenforce; added cvar mw_tkbot, might make bots tk; legalized hahadoken (now hadoken+right), restricted emote 902; streamlined documentation (/movehelp, /buyhelp); .msi package installation for Windows\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.68: made leveling more 'logarithmic'; fixed a fatal error; nerfed e11 blaster (-2/5 damage, unnerfed a little in b3); added 'tiger style' (hadoken+down-left): choke, no saber dmg (breaks crane); added emote /guffaw; /teams modcmd; modcmd FX\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.69: maybe fixed ClientDisconnect server crash on intermission; /buy subadmin actually buys sa (vs /buy tsa); fix for memory leak/exploit (monitor with /debugstats); fixed mw_meleeshield; added some verticality to teutonic throw; made hahadoken unlikely to electrify without sustained contact; rebalanced weps some more; added gravgun (75gp)(prototype, fire attracts/altfire repels)\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.70: added /callvote moot, /callvote modepluso, /callvote slap, /callvote ordnance; player who calls vote doesn't have to vote yes; fixed a pernicious level-drain bug (losses blamed on queued player) &level gain bug; fixed a pernicious skipz0r bug (solo player, when last solo player disconnected in-game); fixed xp training exploit, xp display at intermission; halfed xp gain for winning but dying (doubles team); added mw_debugmw for verbose intermission\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.71: 'logarithmic' xp scaling: 25 1st level, 55 2nd, 90 3rd, 130 4th, 175 5th, 225 6th, &c; fixed mw_altspawn; experimental mw_autothrow, 1=use jump button as /debugthrow (chun li style); reverted vornado-angeline behavior (to forward lunge); made throw effect of aerial donkey kicks crane-counterable (kick itself still unblockable); balanced hp bonus for level+ solos; toned down strength->saberdamage conversion; fixed negative levels; added tavion&desann saber styles to single saber (first blue and second red style: no DFA, more attack chaining; added butterfly, dual twirl; added teams to /cls)\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.72: modernized RPG stats, stats conform to descriptions in /help, rolling at birth, /buy [^6str^7|^6dex^7|^6con^7], 1 in 3 chance of -1 CON on loss, 1 in 4 chance of -1 STR on loss, 1 in 4 chance of +1 STR on win, 1 in 5 chance of +1 DEX on win, 1 in 12 chance of resisting stat loss on /buy [^6str^7|^6dex^7|^6con^7]; added quantity calculator to /buylist; fixed yet another ClientDisconnect server crash on ClientBegin\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.73: fixed 'Luigi Auriemma' vulnerability to say/tell overruns; capped /buy quantities to x100 (lag exploit); fixed server lag from involuntary stats.log appendage; added stat gain to winning (not leveling); buy stat losses aren't applied until >42 combined str/dex/con (e.g., 24 str, 10 dex, 8 con; birth rolls are 32 stat points); /callvote referendum; adjective-based level descriptors; restored alt-kick hadoken: 4 saber, 4 non-saber directional hadokens; nerfed a hidden knockdown bonus for solo players\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.74: streamlined network propagation of stats/gold/xp/etc, fixed zeroed-out stats, moot/rsa gold cheats; implemented alignment concept (like 'Charisma' or Fallout reputation, see /help); addressed shopping exploit at level >100; balanced melee vs saber defense bonus from force_deefense; 2 in 3 chance of karma for kills, 1 in 3 for surviving; fixed callvote unmooting, /callvote autothrow\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.75: added backflip (back+jump knockdown); made secret-ballot optional (mw_secretballot), /callvote secretballot; capped alignment bonus on /buy (-67 to 300pct, no 5gp copays); fixed g_logstats, toggles >>kills.log; balanced STR&DEX, balanced good alignment adjustments\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.76: added /megataunt (!); fixed backflip bug from .75, still does knockdown; made walls grabbable at higher downward accelerations; lowered soft stat caps from 42 to 35 combined; fixed CON bonuses for solo team pduel; mw_intermissiontime (duel/pduel); fixed jetpackrax-related crash; fixed g_configstringindex overflow crash, other overflow issues; reduced centerscreen spam, limited to 12 targets for [all] command, no NPCs on /cls, fixed /megataunt spamming created in this version; fatal crashes now append entries to games.log\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.77: optimized binary (about 250k lighter), removed debug code (except debugthrow, debugknockmedown, debugdropdsaber, debugsetsabermove (with sa)); added idletime field to kills.log (parsing afks); balanced karma-related effects (8ths have 1/8th the effect of the old system); added necromancy skillz (animate corpse, drain corpse, /debugthrow corpse); gave desann style to dual-sabers in single, distinct standing-stances for desann/tavion; changed some knockdownable conditions vs saberists; \n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.78: integrated saber-throw with altfire (+no movement direction), made staff/duals throwable; more alignment gradations, lvl3 lightning/protect potential, nerfed lightning (force cost commensurate with lightning level, more dmg resistance, more force bonus to victim, crane resists stun (but not dmg)); mw_goldadminpw now doubles gold; made grapple move damage STR dependent; fixed multiple stat-buying exploits for overexuberant sa types\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.79b1+: made /debugsetsaber available to everyone (kata force*1.5, free action restrictions); made /reroll available to everyone; added cmd /fakedeath [pc type]; added 'login' messages; fixed /callvote clientkick bug; fixed an Infostring explosion; fixed a jawa buying exploit; fixed a /speakrosh, /speakalora etc. crash; restored banning functionality (addip, g_banips); fixed lightside teamheal, absorb instead of protect; upped the force lightning a lil bit; higher STR/DEX potential on birth roll; testing jk2 saber burns, saber blocking\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.79b3: fast crane recovery in knockdown; /reroll with no argument generates a confirmation, /reroll uses birth algorithm; fixed /fakedeath+/megataunt crashes from nonexistent sound types; extended debug info to find origin(s) of skip bugs; workaround for S_Findname client errors?; 1 in 100 chance of high dark-lightside specials\n\"") );

trap_SendServerCommand( ent-g_entities, va("print \"v.80b1: fixed basejk spectator ping inheritance; changed losses column to win/loss streak on scoreboard; raised /bet limit to 250, /blackjack limit to infinity (double or nothing); fixed basejk sorting preference for connecting clients, related skipzor bug; fixed a 3rd type of (self-inflicted?) skipzor bug\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.80b2: fixed neg alignment pit-abuse (except for sa:); fixed wootygrip/wootyfever persistence\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.80b3: good karma for harming alora/tavion/reborn (per $waffler$)\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.81: starting hp tweaked (100+1.25*CON doubles, 150+0.90*CON solo); starting ammo is now CON-dependent; tweak debugthrow requirements\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.81b2: fixed alignment-gaining bug; fixed alignment display of single 8ths\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.82: clientside birth stats (char_color_red, _green, _blue = birth STR, DEX, CON, if red+blue+green <= 35, otherwise ignored); removed Raven's anti-pigmentation code (sum of customRGBs <=100 are now accepted); raised melee armor to CON ratio, minor armor for high CON non-melee types; doubled incidence of wootygrip/fever\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.82b2: reactivated /speakgermanrosh, fixed hp drain bug from previous release; added speakrosh vocabulary\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.82b3: birthstat cap: <=35 on individual stats\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.82b4: added /speakrax, /speakgermanrax; fatality support\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.83b1: fatalities spawn ammo dispensers (sometimes health dispensers for high alignment attacker); fatality force boon for high alignment (deterministic at +64); dex-based turbo hadoken\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.83b2: dual-use hadoken: backswing is donkey kick in melee, saber-only moves are kicks in melee (and /helpmoves docs); 'birth' stats determined at first spawn (not connect, char_color_* users take note)\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.83b3: unnerfed two melee hadokens, roundhouse-style (like hadoken+left) knockdowns on +right and +down-right, +right resistant to crane (+down-right and +left aren't)\n\"") );

trap_SendServerCommand( ent-g_entities, va("print \"v.84: negative (short) /bet'ing (by popular request); fixed jawa buying align exploit; /betting window extended to 60 seconds\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.84r2: alt-fire without movement does melee grab (directional is same kicks as staff); forward-hadoken for saber (block); shield disruption animation; new player type gib\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.85: fixed MW moves in non-duel gametypes (g_gametype 0 (FFA), 8 (CTF)); fixed MW /modcmds in FFA/CTF; fixed hadoken/knockmedown behavior in FFA/CTF; fixed crash in FFA/CTF when NPC killed PC; saber knockback influenced by STR\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.85r2: added force cost to /fakedeath (same as /debugknockmedown); automatic melee attribute for DEX >=19; bots given more lethality; fixed 'gay' shield disruption anim (only flickers on >=25 dmg criticals); tweaked CON\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.85r3: nerfed automatic dodge against disruptor fire (66 percent chance of hit, lower against saber); gave wooty better predictive capability; fixed wooty's reluctance to snipe; tuned wooty's lemming-like melee behavior\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.85r4: jk2 style wall-runs (more like 2001: A Space Odyssey); corpse dragging (use the 'use' button); saberthrow replaces alt fire for saber; testing limb breakage\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.85r5: wallruns more jk2.5 style, fixed melee/saber freeze, divecrane-style knockdown (crane-resistant) (also diagonal facewalk tactic, up-left/right+jump); fixed some sudden death spam (or made it worse, time will tell)\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.85r6: private challenges (/engage_duel) in P.Duel: either between appointed doubles player and solo, or between two doubles (grudge match) (+added melee?, fixed running away from private duel)\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.86b1: fixed private duel 'pit hang'\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.86b2: toned down diagonal wallrun; toned up forward wallrun (goes all the way to ceiling)\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.86b3: improved walljump 'realism' (sweat and momentum, improved overall grip to compensate); bumped up crouching speed from .5* to .67*base; got rid of some karma spam; raised top speed on jetpacks\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.87b1: added default values to all modwooty variables (mw_*), vanilla MW servers without a .cfg have 'base' Jawascript behavior; new rcon/server variables: mw_walljumpforce, mw_walljumpvelocity, mw_karmapluspw, mw_karmaminuspw, mw_100goldpw\n\"") );

trap_SendServerCommand( ent-g_entities, va("print \"v.87b2: mw_uberthrow toggle and callvote command, =1 is basejk style /debugthrow\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.87b3: added walljump/wallrun to projectile weapons (1st person view); cleaned up /movehelp documentation a little\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.87b4: added crouch-rolls to projectile weapons; lowered momentum threshold to roll backwards; split mw_walljumpvelocity into mw_walljumpXvelocity, mw_walljumpYvelocity, mw_walljumpZvelocity (horizontal/vertical speed, mw default X:50, Y:125); cleaned up /serverhelp\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.87b5: fixed the non-uber /debugthrow (no bogus 'vector saves', same as uberthrow but crane-counterable, +karma/team restrictions); added cvar mw_jetpacks, /callvote jetpacks\n\"") );

trap_SendServerCommand( ent-g_entities, va("print \"v.88b1: fixed crash on NPC modcmds: /teams /ordnance /reroll /modepluso; must be spectator to change name (bait'n'switch prevention)\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.88b2: fixed the infamous rancor-in-pit-crash (+atsts, wampas, etc.); reduced maximum NPC /buy quantity from 100 to 10; added cvars: mw_emoteforce, mw_fakedeathforce (also in /helpmoves)\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.88b3: jk2-style saber returns; new cvar: mw_canjk2roll, permits jk2 'power roll' (use walk button (shift) to do continuous roll, default: 0 is basejka-style); fixed automatic saber requirement on private duels (engage_duel)\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.88b4: cvar mw_canhadokenfire, /callvote hadokenfire\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.89b1: fixed hadokenfire clipping (falling through floors); hadok-orbs cancel each other out; fixed g_gravity reset on worldspawn; fixed caching issue with hadokenfire\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.89b2: capped stat fishing, STR+DEX+CON<=127; hadokenballs less dense; removed wooty's emp\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.89b3: fixed ancient bug (wrong winning player @powerduel intermission; fixes another skipz0r type of bug); gold commands require sa (not tsa); added team-playing status to say (none=spectator); reduced limb breakage; tks count for level/wins (not NPCs); fixed /megataunt with incomplete soundsets (e.g., /megataunt jawa) \n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.89b4: fixed /kill method of evading death webstats; added /callvote hadokenfire; hadoken down+left modified by DEX; testing /emote 872 hadoken(ball), disabling /emote 872\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.89b5: mw_serverculldist cvar (0 to infinity, default: 6000 (scale inches?)), server 'culling' reduces scoreboard lag and connect time, increases 'fog of war' effect; testing persistent p.duel scores on web/qstats/gamespies\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.90b1: fixed /callvote moot/modepluso/ordnance crashin' bug-exploit; nerfed atsts a little (atst hull absorbs 95 pct damage, passes on 5 pct; trampling damage 1/10th of before); raised punching (melee) damage across-the-board (about 12 percent higher with the same stats); hadoken recovery times DEX-based; legalized /emote 872, made plain hadoken (& emote 872) autograb-vulnerable at close range; fixed weird vector-math crash\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.91b2: fixed killer v.90b2 bug; removed bots from kills.log; added /top10 command (just like mani stats!); added lifetime rank&stats to /mystats type messages (nonexistent file gives 'Rank not found', e.g., newbies or a colon (\:) in nick); expanded /megataunt pastabilities\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.91b3: fixed stats with 'illegal' filename chars (*?<>:|); fixed suicide hack when already falling down pit/shaft; added sf2-style autotaunts to winning players\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.92b1: provisional support for hadoken=872 via cvar mw_autorecover (/callvote autorecover); autorecover=1 hadoken and /emote 872 give autograb opportunity to opponents (or teammates); tweaked up wallrun/facerun (trinity-style); changed max_gravity_pull to more Cloud City-like acceleration\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.92b2: replaced useless melee hadokens: right+hadoken->flying kick/wallrun (was redundant right-kick), down+right+hadoken->'872' recover (was swan kick), up+right+hadoken->swan kick (was cannonball) (\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.92b3: fixed hadoball 'falling through floor' bug; fixed hadoball aiming issue (uses muzzle point instead of body-facing-direction); up-right and up-left melee hadokens are left/right flying kicks, right+hadoken melee->swankick (vs. left roundhouse)\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.92b4: hadoball only when fully 'charged', costs 1 kata force per ball\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.92b5: added howlers and hazardtroopers to acceptable NPC types to throw into the pit\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.92b6: saber->melee hadokens for baton/pistol/etc.; compressed datestamp on kills.log (unix time - 1113983094 (Wooty's Constant)); FAT-friendlier ranks (/ranks/* hierarchy); sa's now immootable by other sa's (+myhip, slap, modepluso, rename, teams, reroll)\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.92b7: fixed sa immunity to self-directed sa commands; added cvar mw_meleedamage, configures base punching damage (before stat bonuses and uppercut/wootslap criticals, default: 8); defensive saber postures (i.e., not attacking or holstered) gain 33pct resistance to melee damage; automatic rank generation (server requires Perl/ActivePerl, invokes wootstats_rank.pl @ intermissions)\n\"") );


trap_SendServerCommand( ent-g_entities, va("print \"v.93b1: removed stat ho'-ing for good alignments, added new stat whoring system (you are what you is: saber+punch trains STR, kicking+tossing trains DEX, projectile weps train CON); raised stat cap from 35->45 (/buy, training, char_color_* birth roll); tuned up STR/DEX acquisition; fixed potential client crash from in-game stat gain\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.93b2: improved AI; restored pre-wallrun up-right & up-left melee hadokens\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.93b3: nerfed some bot hax; bots educated in emote 872/876 recovery; fixed mw_tkbot to expected behavior; made bots a parody of their former selves (re: force checks/drainage); made bots a little better at hand-to-hand; cut bot spam down a little; changed down+hadoken to backstab\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.93b4: better(?) AI pathfinding; took away wooty's nades; melee-only players/bots get nade with >=20 CON\n\"") );

trap_SendServerCommand( ent-g_entities, va("print \"v.94b1: persistent stats (str, dex, con, gold, alignment); &'Level' levels and XP; fixed some recall spam; fixed stat cloning by renaming; fixed a persistence money hack (e.g. /blackjack+/recon); nerfed some lightside alignment penalties; fixed embedded periods causing weird rank files\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.94b2: persistent sa status (+persistent /moot, tsa, roastbeef); regressed sa-on-sa moot behavior (anything goes); persistent saber stance, hilt types, saber offense (melee); fixed recall limbo after name change/recon; cursory ip address verification (revokes sa status from hosts foreign to the ip that 'earned' sa), automatic kick vote for suspicious ips\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.94b3: fixed ip address persistence issue (e.g., 'Fake Serge?' on /name), false positives on dynamic ips (e.g., AOL users); workaround for periods and slashes in rank files; removed some spam\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.94b4: sas can only be mooted by vote (/moot (an sa) same as /callvote moot (an sa)); raised Q3 server fps cap (minimum pmove_msec, 8->5/125->200 'fps')\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.95rc1: reduced chatterbot lag; /reroll shows new stats; fixed a rerolling issue (race condition between 'birth' and first stat gain); automatic Win32 thread priorities on external scripts (e.g., wootstats_rank.pl->above_normal)\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.95rc2: compressed session variables to reduce 'session overflow' errors; taught bots to use gravgun (?); fixed criticals spamming; saber attack chaining causes a whirligig (rotor) effect; fixed another stats-overwriting problem (sry); improved birth roll and /reroll variability; made saber-rotor mainly CON-based (smaller higher faster)\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.95rc3: client protection against color1/color2/model/name spamabuse; whirligig more whirly, added wootslap anims; nerfed force pull (efficacy is STR-based); fixed saberstyle memory; sa /rename (and clientconnect rename) does instantaneous recall; taught bots to /hadoken; hadokenball lighting effects\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.96rc1: fixed misattributed falling 'deaths' (foul play); fixed karma password functionality; seriously nerfed and slightly unnerfed force throw (+s: friendly fire, jacking thermals, no dual saber restrictions; -s: Newtonian equal-and-opposite pull on puller (like gravgun), recovery latency increased, force expenditure increased, less effective against wallgrabbed victims)\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.96rc2: fixed Ye Olde Bugged crane (+proper killer attribution); ranks automatically generate every half hour; fixed mystats spamming at round start (and accompanying client overloads)\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.96b3: attempting to balance CON; added vertical dimension to reciprocal force pull (on puller)\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.96b4: fixed unmooting persistence; fixed karma gaining bug; fixed a bunch of gold/xp/karma persistence bugs at end-of-round; fixed house on blackjack/bet; Heisenberg's Hadokenball; made level-gain system slightly fairer (?)\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.97b1: bowling-style hadokenball; weapon knockback a function of stats (negative DEX equals tusken pick power); fixed client overflows from console spam before first connect; raised threshold for lightside weapon penalties (+512/1024); fixed mooting persistence bug (again?)\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.97b2: fixed double-hadoken sound; fixed repetitious bot chatter; fixed xp gain bug for solo players; raised xp/gold round bonuses; fixed another stupid crash bug; fixed lightspeed weapons; fixed another weird crash introduced in v.96; bots take advantage of guided hadoken; fixed ranking lag; changed means-of-death in kills.log to an integer (saves ~10 bytes per line); more efficient directory structure for /ranks/*.sum; yet more efficient FAT structure, eliminates potential filelock contention; kludge fix for excessive reroll&blackjack spamming\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.97b3: greatly balanced xp gain-loss from one round; nerfed wooty\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.97b4: fixed end-of-round updates for dead player-spectators; fixed an infinite setteam spectator loop (i.e., server hang); fixed a connecting/disconnecting line-order skip; fixed guided hadokenball server lag; fixed scoreboard lag; fixed qstats reporting of wins\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.97b5: hadokenball easier to control, better against aerial attacks; improved elevator response time; testing kickboxing melee tactics; ip auto-kicking slightly more democratic\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.97b6: blankrolls (punch+up+right); tweaked down blankroll sustain time (800ms->600); fixed another server hang bug after InitGame() every round\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.97b7: fixed crane resistance to blankrolls/handstandoken/cranedive; handstand=down+left+punch (opp. blankroll); taught bots to crane (not judiciously); added melee/saber recharge time to force pull\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.97b8: updated three semi-useless saber hadokens (hadoken+(up+left:parry left|up+right:parry right|right:neo-dfa)); changed blanka roll to crouch combination (crouch+punch+right)\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.98b1: password management system; fixed security loophole for connecting clients (re: name changes, password auths); fixed ip autokicking for most dynamic ips\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.98b11: client-side password support (/password yourpassword, /seta password yourpassword, password field in Gamespy/ASE/etc.), accounts locked with client's /password after sa/tsa/rsa (unless it's blank); name changes in-round (except when falling)\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.98b2: simplified password mgmt (automatically syncs /password changes); /password '' unlocks that username; fixed /buy tsa exploit on sas; fixed /moot autovotes on sas; fixed RemovePowerDuelLosers() server hanging loop (yay)\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.98b21: fixed a file handle leak from excessive Players/Padawans\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.98b22: severely reduced q3-style score/connect spam\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.98b24: fixed colorspam stability issues\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.98b25: fixed the rainbow saber exploit\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.98b26: fixed a stupid bug created in b25\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.98b27: fixed color1/color2 stack corruption (illegal colors and/or rainbow saber -> jawa with yellow sabers); fixed password overflow crash; passwords must be between 2-64 chars, contain at least one non-numeric character\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.98b28: fixed client-disconnect overflow server crash during intermission; auto-rewoots (workaround for npc client crash); new evil wooty\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.98b29: enabled web /iamsponge integration (moot/modepluso, reset password, reset server); sidearm melee req lowered to 14 DEX\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.98b30: raised per-round karma caps; Chun Li style midair throws\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.98b31: stabilized hadoken-lag; nerfed Chun Li throws; augmented gib deaths\n\"") );
*/

trap_SendServerCommand( ent-g_entities, va("print \"v.98b32: fix for q3fill-style exploits (and ghosting)\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.98b33: fixed weird password crash\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.98b34: melee overhaul: right jab/fists of flurry style (punch+direction, modified by DEX), melee damage thresholds by hitbox ('headshots' more effective w/high DEX, mitigates punch+direction spam and -CON Goliath chars), fixed negative STR bonus, more knockback w/less damage from random criticals; stronger CON effects on HP to mitigate -CON E. Honda style; fixed bot renaming (maybe); migrated to vc++ 8, testing new optimizations (dll 2.04M->1.75M, improvement in cpu util/lag/hitch warning times)\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.98b34¾: re-version: loosened 'ghostban' restriction (3 players permitted per ip); disabled client 0 gold accumulation; autothrow nerfed into virtual non-existence (only works if both players are flying); restored Tony Stark style for NPC boba_fett; balanced fistoflurry speed vs DEX; fixed network exploit allowing gold/sub password sniffing; gave bots some recovery techniques (?); testing another fix for bot-renaming exploit; fixed password overflow crash (max pw length is 'roastbeefsandwich' or 17 chars); bots slightly less floaty, more killing/dying-oriented; wallgrab with broken bone = wallhump; turned off rank generation when no clients are connected\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.98b35: testing fix for 'wait 5 seconds' name change/'Player' on connect; improved AI viz a viz saber skills, melee, willingness to use projectile weps at point blank; raised price of subadmin, atst_vehicle; \moot [subadmin] counts for 2 Yes votes, automatic No vote by recipient; replaced inactivity timer with AFK timer\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.98b36: optimizing bot waypoint precision, prim/sec. weapon mode behavior; nerfed bot spawned characteristics/cheats; more AI tweaks \n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.98b37: fixed crashes from bad rank files; fixed bad rank files; fixed security loophole from relaxed ip policy (b34) allowing flood-style connects\n\"") );
trap_SendServerCommand( ent-g_entities, va("print \"v.98b38: patch for negative attribute exploit; optimized compiler config for server performance on Windows (VC++ 2010 beta)\n\"") );


trap_SendServerCommand( ent-g_entities, va("print \"^1Additional help: /help, /movehelp, /buyhelp, /modcmds, /serverhelp, PageUp key, PageDown key, /history\n\"") );

	 
	///emote 872: aerial reverse
	
	}

	

	else if (Q_stricmp (cmd, "kill") == 0)
		Cmd_Kill_f (ent);
	else if (Q_stricmp (cmd, "teamtask") == 0)
		Cmd_TeamTask_f (ent);
	else if (Q_stricmp (cmd, "levelshot") == 0)
		Cmd_LevelShot_f (ent);
	else if (Q_stricmp (cmd, "follow") == 0)
		Cmd_Follow_f (ent);
	else if (Q_stricmp (cmd, "follownext") == 0)
		Cmd_FollowCycle_f (ent, 1);
	else if (Q_stricmp (cmd, "followprev") == 0)
		Cmd_FollowCycle_f (ent, -1);
	else if (Q_stricmp (cmd, "team") == 0)
		Cmd_Team_f (ent);
	else if (Q_stricmp (cmd, "duelteam") == 0)
		Cmd_DuelTeam_f (ent);
	else if (Q_stricmp (cmd, "siegeclass") == 0)
		Cmd_SiegeClass_f (ent);
	else if (Q_stricmp (cmd, "forcechanged") == 0)
		Cmd_ForceChanged_f (ent);
	else if (Q_stricmp (cmd, "where") == 0)
		Cmd_Where_f (ent);
	else if (Q_stricmp (cmd, "callvote") == 0)
		Cmd_CallVote_f (ent);
	else if (Q_stricmp (cmd, "vote") == 0)
		Cmd_Vote_f (ent);
	else if (Q_stricmp (cmd, "callteamvote") == 0)
		Cmd_CallTeamVote_f (ent);
	else if (Q_stricmp (cmd, "teamvote") == 0) 
		Cmd_TeamVote_f (ent);
	else if (Q_stricmp (cmd, "gc") == 0)
		Cmd_GameCommand_f( ent );
	else if (Q_stricmp (cmd, "setviewpos") == 0)
		Cmd_SetViewpos_f( ent );
	else if (Q_stricmp (cmd, "stats") == 0)
		Cmd_Stats_f( ent );
	/*
	else if (Q_stricmp (cmd, "kylesmash") == 0)
	{
		TryGrapple(ent);
	}
	*/
	//for convenient powerduel testing in release
	/*else if (Q_stricmp(cmd, "killother") == 0 && CheatsOk( ent ))
	{
		if (trap_Argc() > 1)
		{
			char sArg[MAX_STRING_CHARS];
			int entNum = 0;

			trap_Argv( 1, sArg, sizeof( sArg ) );

			entNum = G_ClientNumFromNetname(sArg);

			if (entNum >= 0 && entNum < MAX_GENTITIES)
			{
				gentity_t *kEnt = &g_entities[entNum];

				if (kEnt->inuse && kEnt->client)
				{
					kEnt->flags &= ~FL_GODMODE;
					kEnt->client->ps.stats[STAT_HEALTH] = kEnt->health = -999;
					player_die (kEnt, kEnt, kEnt, 100000, MOD_SUICIDE);
				}
			}
		}
	}*/
///#ifdef _DEBUG
	/*else if (Q_stricmp(cmd, "relax") == 0 && Q_stricmp (ent->client->pers.netname, ent->client->sess.admin_name) ==  0)
	{
		if (ent->client->ps.eFlags & EF_RAG)
		{
			ent->client->ps.eFlags &= ~EF_RAG;
		}
		else
		{
			ent->client->ps.eFlags |= EF_RAG;
		}
	}*/

	/*else if (Q_stricmp(cmd, "holdme") == 0 && Q_stricmp (ent->client->pers.netname, ent->client->sess.admin_name) ==  0)
	{
		if (trap_Argc() > 1)
		{
			char sArg[MAX_STRING_CHARS];
			int entNum = 0;

			trap_Argv( 1, sArg, sizeof( sArg ) );

			entNum = atoi(sArg);

			if (entNum >= 0 &&
				entNum < MAX_GENTITIES)
			{
				gentity_t *grabber = &g_entities[entNum];

				if (grabber->inuse && grabber->client && grabber->ghoul2)
				{
					if (!grabber->s.number)
					{ //switch cl 0 and entitynum_none, so we can operate on the "if non-0" concept
						ent->client->ps.ragAttach = ENTITYNUM_NONE;
					}
					else
					{
						ent->client->ps.ragAttach = grabber->s.number;
					}
				}
			}
		}
		else
		{
			ent->client->ps.ragAttach = 0;
		}
	}*//*
	else if (Q_stricmp(cmd, "limb_break") == 0 && CheatsOk( ent ))
	{
		if (trap_Argc() > 1)
		{
			char sArg[MAX_STRING_CHARS];
			int breakLimb = 0;

			trap_Argv( 1, sArg, sizeof( sArg ) );
			if (!Q_stricmp(sArg, "right"))
			{
				breakLimb = BROKENLIMB_RARM;
			}
			else if (!Q_stricmp(sArg, "left"))
			{
				breakLimb = BROKENLIMB_LARM;
			}

			G_BreakArm(ent, breakLimb);
		}
	}

	else if (Q_stricmp(cmd, "twilekhead") == 0 )
	{
		
	}
	else if (Q_stricmp(cmd, "debugstupidthing") == 0 && CheatsOk( ent ))
	{
		int i = 0;
		gentity_t *blah;
		while (i < MAX_GENTITIES)
		{
			blah = &g_entities[i];
			if (blah->inuse && blah->classname && blah->classname[0] && !Q_stricmp(blah->classname, "NPC_Vehicle"))
			{
				Com_Printf("Found it.\n");
			}
			i++;
		}
	}
	else if (Q_stricmp(cmd, "arbitraryprint") == 0 && CheatsOk( ent ))
	{
		trap_SendServerCommand( -1, va("cp \"Blah blah blah\n\""));
	}
	else if (Q_stricmp(cmd, "handcut") == 0 && Q_stricmp (ent->client->pers.netname, ent->client->sess.admin_name) ==  0)
	{
		int bCl = 0;
		char sarg[MAX_STRING_CHARS];

		if (trap_Argc() > 1)
		{
			trap_Argv( 1, sarg, sizeof( sarg ) );

			if (sarg[0])
			{
				bCl = atoi(sarg);

				if (bCl >= 0 && bCl < MAX_GENTITIES)
				{
					gentity_t *hEnt = &g_entities[bCl];

					if (hEnt->client)
					{
						if (hEnt->health > 0)
						{
							gGAvoidDismember = 1;
							hEnt->flags &= ~FL_GODMODE;
							hEnt->client->ps.stats[STAT_HEALTH] = hEnt->health = -999;
							player_die (hEnt, hEnt, hEnt, 100000, MOD_SUICIDE);
						}
						gGAvoidDismember = 2;
						G_CheckForDismemberment(hEnt, ent, hEnt->client->ps.origin, 999, hEnt->client->ps.legsAnim, qfalse);
						gGAvoidDismember = 0;
					}
				}
			}
		}
	}*/

///#endif
	/*else if (Q_stricmp(cmd, "thedestroyer") == 0  && Q_stricmp (ent->client->pers.netname, ent->client->sess.admin_name) ==  0 && ent && ent->client && ent->client->ps.saberHolstered && ent->client->ps.weapon == WP_SABER)
	{
		Cmd_ToggleSaber_f(ent);

		if (!ent->client->ps.saberHolstered)
		{
		}
	}*/
	//begin bot debug cmds
	/*else if (Q_stricmp(cmd, "debugBMove_Forward") == 0 && CheatsOk(ent))
	{
		int arg = 4000;
		int bCl = 0;
		char sarg[MAX_STRING_CHARS];

		assert(trap_Argc() > 1);
		trap_Argv( 1, sarg, sizeof( sarg ) );

		assert(sarg[0]);
		bCl = atoi(sarg);
		Bot_SetForcedMovement(bCl, arg, -1, -1);
	}*//*
	else if (Q_stricmp(cmd, "debugBMove_Back") == 0 && CheatsOk(ent))
	{
		int arg = -4000;
		int bCl = 0;
		char sarg[MAX_STRING_CHARS];

		assert(trap_Argc() > 1);
		trap_Argv( 1, sarg, sizeof( sarg ) );

		assert(sarg[0]);
		bCl = atoi(sarg);
		Bot_SetForcedMovement(bCl, arg, -1, -1);
	}*//*
	else if (Q_stricmp(cmd, "debugBMove_Right") == 0 && CheatsOk(ent))
	{
		int arg = 4000;
		int bCl = 0;
		char sarg[MAX_STRING_CHARS];

		assert(trap_Argc() > 1);
		trap_Argv( 1, sarg, sizeof( sarg ) );

		assert(sarg[0]);
		bCl = atoi(sarg);
		Bot_SetForcedMovement(bCl, -1, arg, -1);
	}*//*
	else if (Q_stricmp(cmd, "debugBMove_Left") == 0 && CheatsOk(ent))
	{
		int arg = -4000;
		int bCl = 0;
		char sarg[MAX_STRING_CHARS];

		assert(trap_Argc() > 1);
		trap_Argv( 1, sarg, sizeof( sarg ) );

		assert(sarg[0]);
		bCl = atoi(sarg);
		Bot_SetForcedMovement(bCl, -1, arg, -1);
	}*//*
	else if (Q_stricmp(cmd, "debugBMove_Up") == 0 && CheatsOk(ent))
	{
		int arg = 4000;
		int bCl = 0;
		char sarg[MAX_STRING_CHARS];

		assert(trap_Argc() > 1);
		trap_Argv( 1, sarg, sizeof( sarg ) );

		assert(sarg[0]);
		bCl = atoi(sarg);
		Bot_SetForcedMovement(bCl, -1, -1, arg);
	}*/
	//end bot debug cmds
///#ifndef FINAL_BUILD
	else if (Q_stricmp(cmd, "debugSetSaberMove") == 0 
		&& ent->client && ent->client->ps.fd.forcePower >= (int)(g_kataforce.integer) 
		&& ent->client->sess.spectatorState != SPECTATOR_FOLLOW
		&& ent->client->ps.forceHandExtend == HANDEXTEND_NONE 
		&& !ent->client->grappleState 
		&& ent->client->ps.legsAnim != BOTH_KYLE_PA_1
		&& ent->client->ps.legsAnim != BOTH_KYLE_PA_2
		&& ent->client->ps.legsAnim != BOTH_KYLE_PA_3
		///&&	(Q_stricmp(ent->client->sess.admin_name, "sub") == 0)
		)
	{
		Cmd_DebugSetSaberMove_f(ent);
		ent->client->ps.fd.forcePower -= (int)(g_kataforce.integer);

		///wank
		G_Sound( ent, CHAN_VOICE, G_SoundIndex( "sound/chr_d/rosh_boss/misc/gurp1.mp3" ) );


	}



	//else if (Q_stricmp(cmd, "debugSetBodyAnim") == 0 && (Q_stricmp(ent->client->sess.admin_name, "sub") == 0))
	//{
		///Cmd_DebugSetBodyAnim_f(ent, SETANIM_FLAG_OVERRIDE|SETANIM_FLAG_HOLD);
	//}
	/*else if (Q_stricmp(cmd, "debugDismemberment") == 0)
	{
		Cmd_Kill_f (ent);
		if (ent->health < 1)
		{
			char	arg[MAX_STRING_CHARS];
			int		iArg = 0;

			if (trap_Argc() > 1)
			{
				trap_Argv( 1, arg, sizeof( arg ) );

				if (arg[0])
				{
					iArg = atoi(arg);
				}
			}

			DismembermentByNum(ent, iArg);
		}
	}*/
	

	else if (Q_stricmp(cmd, "debugDropSaber") == 0 && g_candropsaber.integer > 0 )
	{
		if (ent->client->ps.weapon == WP_SABER &&
			ent->client->ps.saberEntityNum &&
			!ent->client->ps.saberInFlight && ent->client->ps.fd.forcePower >= g_kataforce.integer)
		{
			saberKnockOutOfHand(&g_entities[ent->client->ps.saberEntityNum], ent, vec3_origin);
			ent->client->ps.fd.forcePower = ent->client->ps.fd.forcePower - g_kataforce.integer;
		}
	}
	else if (Q_stricmp(cmd, "debugKnockMeDown") == 0 && g_canfalldown.integer > 0)
	{

				if (
					
				((ent->client->sess.spectatorState != SPECTATOR_FREE 
				&& ent->client->sess.spectatorState != SPECTATOR_FOLLOW)
				|| g_gametype.integer != 4)
		&& BG_KnockDownable(&ent->client->ps) 
			&& ent->client->ps.fd.forcePower >= g_falldownforce.integer 
			&& ent->client->ps.forceHandExtend != HANDEXTEND_KNOCKDOWN
			&& !ent->client->grappleState 
			&& ent->client->ps.legsAnim != BOTH_KYLE_PA_1
			&& ent->client->ps.legsAnim != BOTH_KYLE_PA_2
			&& ent->client->ps.legsAnim != BOTH_KYLE_PA_3)
			
		{

			ent->client->ps.fd.forcePower = ent->client->ps.fd.forcePower - g_falldownforce.integer;

			ent->client->ps.forceHandExtend = HANDEXTEND_KNOCKDOWN;
			ent->client->ps.forceDodgeAnim = 0;
			if (trap_Argc() > 1)
			{
				ent->client->ps.forceHandExtendTime = level.time + 1100;
				ent->client->ps.quickerGetup = qfalse;
			}
			else
			{
				ent->client->ps.forceHandExtendTime = level.time + 700;
				ent->client->ps.quickerGetup = qtrue;
			}
		}
	}
	/*else if (Q_stricmp(cmd, "debugSaberSwitch") == 0)
	{
		gentity_t *targ = NULL;

		if (trap_Argc() > 1)
		{
			char	arg[MAX_STRING_CHARS];

			trap_Argv( 1, arg, sizeof( arg ) );

			if (arg[0])
			{
				int x = atoi(arg);
				
				if (x >= 0 && x < MAX_CLIENTS)
				{
					targ = &g_entities[x];
				}
			}
		}

		if (targ && targ->inuse && targ->client)
		{
			Cmd_ToggleSaber_f(targ);
		}
	}
	else if (Q_stricmp(cmd, "debugIKGrab") == 0)
	{
		gentity_t *targ = NULL;

		if (trap_Argc() > 1)
		{
			char	arg[MAX_STRING_CHARS];

			trap_Argv( 1, arg, sizeof( arg ) );

			if (arg[0])
			{
				int x = atoi(arg);
				
				if (x >= 0 && x < MAX_CLIENTS)
				{
					targ = &g_entities[x];
				}
			}
		}

		if (targ && targ->inuse && targ->client && ent->s.number != targ->s.number)
		{
			targ->client->ps.heldByClient = ent->s.number+1;
		}
	}
	else if (Q_stricmp(cmd, "debugIKBeGrabbedBy") == 0)
	{
		gentity_t *targ = NULL;

		if (trap_Argc() > 1)
		{
			char	arg[MAX_STRING_CHARS];

			trap_Argv( 1, arg, sizeof( arg ) );

			if (arg[0])
			{
				int x = atoi(arg);
				
				if (x >= 0 && x < MAX_CLIENTS)
				{
					targ = &g_entities[x];
				}
			}
		}

		if (targ && targ->inuse && targ->client && ent->s.number != targ->s.number)
		{
			ent->client->ps.heldByClient = targ->s.number+1;
		}
	}*//*
	else if (Q_stricmp(cmd, "debugIKRelease") == 0)
	{
		gentity_t *targ = NULL;

		if (trap_Argc() > 1)
		{
			char	arg[MAX_STRING_CHARS];

			trap_Argv( 1, arg, sizeof( arg ) );

			if (arg[0])
			{
				int x = atoi(arg);
				
				if (x >= 0 && x < MAX_CLIENTS)
				{
					targ = &g_entities[x];
				}
			}
		}

		if (targ && targ->inuse && targ->client)
		{
			targ->client->ps.heldByClient = 0;
		}
	}*/
	else if (Q_stricmp(cmd, "slap") == 0 && Q_stricmp ("sub", ent->client->sess.admin_name) ==  0)
	{int i, j = 0, clientid = -1;
		char sArg[MAX_STRING_CHARS];
		char tArg[MAX_STRING_CHARS];

		trap_Argv( 1, sArg, sizeof( sArg ) );
		trap_Argv( 2, tArg, sizeof( tArg ) );

		if (sArg[2] > 0){
			clientid = G_ClientNumberFromName ( sArg );
			if ( clientid == -1 )
			{
				clientid = G_ClientNumberFromStrippedName(sArg);
			}
		}

		for (i = 0; i < 1024; i++){
			////if (g_entities[i].client && g_entities[i].client->pers.netname[1] > 0){
			if (g_entities[i].client && (g_entities[i].client->sess.spectatorState != SPECTATOR_FREE || g_gametype.integer != 4) && (g_entities[i].client->sess.spectatorState != SPECTATOR_FOLLOW || g_gametype.integer != 4) &&(g_entities[i].client->pers.netname[1] > 0 || (g_entities[i].NPC_type && g_entities[i].NPC_type[1] > 0))){
		//		if ((sArg[2] == 0 && atoi(sArg) == i) || (sArg[2] > 0 && clientid == i) || (g_entities[i].NPC_type && Q_stricmp(g_entities[i].NPC_type, sArg) == 0 ) || (g_entities[i].client->sess.spectatorState != SPECTATOR_FREE && g_entities[i].client->sess.spectatorState != SPECTATOR_FOLLOW &&  g_entities[i].client->ps.clientNum != ent->client->ps.clientNum &&  Q_stricmp("all", sArg)==0)){///level.clients[i].ps.clientNum){
				if (
					(sArg[2] == 0 && atoi(sArg) == i) 
					|| (sArg[2] > 0 && clientid == i) 
					|| (g_entities[i].NPC_type 
						&& Q_stricmp(g_entities[i].NPC_type, sArg) == 0 )
					|| (g_entities[i].client->ps.clientNum != ent->client->ps.clientNum 
						&&  Q_stricmp("all", sArg)==0)
				){///level.clients[i].ps.clientNum){
					gentity_t *victim = &g_entities[i];
					int strength = atoi(tArg);
					float str;
					vec3_t oppDir;

					if (!victim->client){
						return;
					}
				j++;
				if (j >= 12){
					return;
				}
					if (Q_stricmp ("sub", victim->client->sess.admin_name) ==  0 && ent->s.number != victim->s.number){
						continue;
					}


			//other->client->ps.pm_flags |= PMF_JUMP_HELD;
					//G_SetAnim(other, NULL, SETANIM_BOTH, BOTH_DEATHFORWARD3, 1|2, 0);
					VectorSubtract(victim->client->ps.origin, ent->client->ps.origin, oppDir);
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

			
					if (victim->NPC_type){
						trap_SendServerCommand( -1, va("print \"^3%s^3 has dislocated %s^3.\n\"", ent->client->pers.netname, victim->NPC_type) );
						trap_SendServerCommand( -1, va("cp \"^3%s^3 has dislocated\n%s^3.\n\"", ent->client->pers.netname, victim->NPC_type) );
					}else{
						trap_SendServerCommand( -1, va("print \"^3%s^3 has dislocated %s^3.\n\"", ent->client->pers.netname, victim->client->pers.netname) );
						trap_SendServerCommand( -1, va("cp \"^3%s^3 has dislocated\n%s^3.\n\"", ent->client->pers.netname, victim->client->pers.netname) );
						///ooo-ahhh
						G_Sound( ent, CHAN_VOICE, G_SoundIndex( "sound/chr_e/ragnos/misc/pain75.mp3" ) );

					}
				
				
				}
			}
		}
	}
	else if ( Q_stricmp(cmd, "debugThrow") == 0 && g_uberthrow.integer!= 0)
	{
		trace_t tr;
		vec3_t tTo, fwd;

		if (ent->client->ps.weaponTime > 0 || ent->client->ps.forceHandExtend != HANDEXTEND_NONE ||
			ent->client->ps.groundEntityNum == ENTITYNUM_NONE || ent->health < 1)
		{
			return;
		}

		AngleVectors(ent->client->ps.viewangles, fwd, 0, 0);
		tTo[0] = ent->client->ps.origin[0] + fwd[0]*32;
		tTo[1] = ent->client->ps.origin[1] + fwd[1]*32;
		tTo[2] = ent->client->ps.origin[2] + fwd[2]*32;

		trap_Trace(&tr, ent->client->ps.origin, 0, 0, tTo, ent->s.number, MASK_PLAYERSOLID);

		if (tr.fraction != 1)
		{
			gentity_t *other = &g_entities[tr.entityNum];

			if (other->inuse && other->client && other->client->ps.forceHandExtend == HANDEXTEND_NONE &&
				other->client->ps.groundEntityNum != ENTITYNUM_NONE && other->health > 0 &&
				(int)ent->client->ps.origin[2] == (int)other->client->ps.origin[2])
			{
				float pDif = 40.0f;
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
				ent->client->ps.forceHandExtendTime = level.time + 5000;

				ent->client->throwingIndex = other->s.number;
				ent->client->doingThrow = level.time + 5000;
				ent->client->beingThrown = 0;

				VectorSubtract( ent->client->ps.origin, other->client->ps.origin, entDir );
				VectorCopy( other->client->ps.viewangles, otherAngles );
				otherAngles[YAW] = vectoyaw( entDir );
				SetClientViewAngle( other, otherAngles );

				other->client->ps.forceHandExtend = HANDEXTEND_PRETHROWN;
				other->client->ps.forceHandExtendTime = level.time + 5000;

				other->client->throwingIndex = ent->s.number;
				other->client->beingThrown = level.time + 5000;
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

				if (tr.fraction == 1.0 && !tr.startsolid && tr2.fraction == 1.0 && !tr2.startsolid)
				{
					VectorCopy(intendedOrigin, other->client->ps.origin);
				}
				else
				{ //if the guy can't be put here then it's time to break the throw off.
					vec3_t oppDir;
					int strength = 4;

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
				}
			}
		}
	}

	else if (Q_stricmp(cmd, "writestatspassword") == 0 && (Q_stricmp(ent->client->sess.admin_name, "sub") == 0))
	{
		WriteStats();
	}

	else if (Q_stricmp(cmd, "debugThrow") == 0 && g_uberthrow.integer==0)
	{
		trace_t tr;
		vec3_t tTo, fwd;
		////int xpgain;

		if (g_debugthrow.integer == 0 || ent->client->ps.weaponTime > 0 
			|| (ent->client->ps.forceHandExtend != HANDEXTEND_NONE 
			&& ent->client->ps.forceHandExtend != HANDEXTEND_DODGE
			&& ent->client->ps.forceHandExtend != HANDEXTEND_WEAPONREADY)
			||ent->health < 1 
			/////ent->client->ps.groundEntityNum == ENTITYNUM_NONE || 
			||
			(
			(ent->client->iAmALoser 
			|| ent->client->ps.iModelScale < 25 )
			&& strcmp( ent->client->sess.admin_name, "sub" )
			)
			|| (ent->client->sess.spectatorState == SPECTATOR_FOLLOW && g_gametype.integer == 4)
			|| (ent->client->sess.spectatorState == SPECTATOR_FREE && g_gametype.integer == 4)
			)
		{
			return;
		}
		if (ent->client->ps.torsoAnim == FACE_SMILE)
		{
			G_KickSomeMofos(ent);
			return;
		}
		if (ent->client && ent->client->sess.karma >= 256){
			trap_SendServerCommand(ent->s.number, va("print \"^3Throwing prohibited by ^5Magnificent ^4lightside ^7alignment.\n\"") );
			return;
		}

		AngleVectors(ent->client->ps.viewangles, fwd, 0, 0);
		tTo[0] = ent->client->ps.origin[0] + fwd[0]*32;
		tTo[1] = ent->client->ps.origin[1] + fwd[1]*32;
		tTo[2] = ent->client->ps.origin[2] + fwd[2]*32;

		trap_Trace(&tr, ent->client->ps.origin, 0, 0, 
			tTo, ent->s.number, 
			MASK_PLAYERSOLID);
			//|CONTENTS_CORPSE);
		
		/////if (1==1)
		if (tr.fraction != 1)
		{
			gentity_t *other = &g_entities[tr.entityNum];

			////if (other->inuse && other->client && other->client->ps.forceHandExtend == HANDEXTEND_NONE &&
			if (other->inuse && other->client && (other->client->ps.forceHandExtend == HANDEXTEND_NONE 
				|| other->client->ps.forceHandExtend == HANDEXTEND_WEAPONREADY 
				|| other->client->ps.forceHandExtend == HANDEXTEND_DODGE
				|| other->client->ps.forceHandExtend == HANDEXTEND_TAUNT
				)&&	
			
			
			/////other->client->ps.groundEntityNum != ENTITYNUM_NONE && 
				////other->health > 0 &&  ///unwoot?
				(int)ent->client->ps.origin[2] == (int)other->client->ps.origin[2] 
				&& other->client->ps.torsoAnim != FACE_SMILE 
					&& other->client->ps.electrifyTime <= level.time )
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

				if (tr.fraction == 1.0 
					&& !tr.startsolid && tr2.fraction == 1.0 
					&& !tr2.startsolid 
					&& ent->client->ps.fd.forcePower >= g_throwforce.integer 
					///&& (Q_irand(0,10) < (other->client->ps.iModelScale/12.0f))
					 )
					{

					if (ent->client 
						&& other->client 
						&& ((ent->client->sess.duelTeam == other->client->sess.duelTeam 
						&& g_gametype.integer == GT_POWERDUEL)
						|| (ent->client->sess.sessionTeam == other->client->sess.sessionTeam 
						&& g_gametype.integer != GT_POWERDUEL && g_gametype.integer != GT_FFA))

						
						){

						if (ent->client->sess.admin_number >= 25 && ent->client->sess.karma < 64){
							ent->client->sess.admin_number -= 25;
							other->client->sess.admin_number += 25;
							
							WriteKeys(ent->s.number,4,-1);
							WriteKeys(other->s.number,4,-1);
							LoseKarma(ent->s.number, "Honor: your team.", 1);
							trap_SendServerCommand( -1, va("print \"^3%s ^3paid 25gp settlement to %s for team-throwing.\n\"", ent->client->pers.netname, other->client->pers.netname) );
						}else if(ent->client->sess.karma >= 64){
							vec3_t oppDir;
							///int strength = 2;//
							float strength = (ent->client->sess.str / 8.0f);
							trap_SendServerCommand( -1, va("print \"^3Team-throwing is restricted by ^4lightside ^7alignment.\n\"") );
						
							////?
							other->client->ps.heldByClient = 0;
							other->client->beingThrown = 0;
							ent->client->doingThrow = 0;

							ent->client->ps.forceHandExtend = HANDEXTEND_NONE;
							G_EntitySound( ent, CHAN_VOICE, G_SoundIndex("*pain25.wav") );

							other->client->ps.forceHandExtend = HANDEXTEND_NONE;
							VectorSubtract(other->client->ps.origin, ent->client->ps.origin, oppDir);
							VectorNormalize(oppDir);
							other->client->ps.velocity[0] = (int)oppDir[0]*(strength*40.0f);
							other->client->ps.velocity[1] = (int)oppDir[1]*(strength*40.0f);
							other->client->ps.velocity[2] = 150;

							VectorSubtract(ent->client->ps.origin, other->client->ps.origin, oppDir);
							VectorNormalize(oppDir);
							ent->client->ps.velocity[0] = (int)oppDir[0]*(strength*80.0f);//
							ent->client->ps.velocity[1] = (int)oppDir[1]*(strength*80.0f);//
							ent->client->ps.velocity[2] = 300;//
							return;
							////??
						}else if (ent->client->sess.admin_number < 5){
							vec3_t oppDir;
							///int strength = 2;//
							float strength = (ent->client->sess.str / 8.0f);
							trap_SendServerCommand( clientNum, va("print \"^3Not enough gold for team-throw liability premium.\n\"") );
						
							////?
							other->client->ps.heldByClient = 0;
							other->client->beingThrown = 0;
							ent->client->doingThrow = 0;

							ent->client->ps.forceHandExtend = HANDEXTEND_NONE;
							G_EntitySound( ent, CHAN_VOICE, G_SoundIndex("*pain25.wav") );

							other->client->ps.forceHandExtend = HANDEXTEND_NONE;
							VectorSubtract(other->client->ps.origin, ent->client->ps.origin, oppDir);
							VectorNormalize(oppDir);
							other->client->ps.velocity[0] = (int)oppDir[0]*(strength*40.0f);
							other->client->ps.velocity[1] = (int)oppDir[1]*(strength*40.0f);
							other->client->ps.velocity[2] = 150;

							VectorSubtract(ent->client->ps.origin, other->client->ps.origin, oppDir);
							VectorNormalize(oppDir);
							ent->client->ps.velocity[0] = (int)oppDir[0]*(strength*85.0f);//
							ent->client->ps.velocity[1] = (int)oppDir[1]*(strength*85.0f);//
							ent->client->ps.velocity[2] = 300;//
							return;
							////??
						}

					}

						if (other->NPC_type && other->NPC_type[1] > 0 || IsABot(other->client->ps.clientNum)){
						
					}else{
						////xpgain = Q_irand(0,1);
						if (ent->client && ent->client->pers.netname[1] > 0){
							///trap_SendServerCommand(-1, va("print \"%s ^5has gained ^3%i^5 XP\n\"", ent->client->pers.netname, xpgain) );
							////ent->client->sess.xp += xpgain;
						}						
					//trap_SendServerCommand(-1, va("cp \"%s ^5has gained ^3%i^5 XP\n\"", ent->client->pers.netname, xpgain) );
					
					}

					VectorCopy(intendedOrigin, other->client->ps.origin);
					ent->client->ps.fd.forcePower = ent->client->ps.fd.forcePower - g_throwforce.integer;
					other->client->ps.velocity[0] *=  (ent->client->saber[0].damageScale * (1/other->client->saber[0].damageScale));
				}
				
				else 
				{ //if the guy can't be put here then it's time to break the throw off.

	
					vec3_t oppDir;
					///int strength = 4;
					float strength = (ent->client->sess.str / 8.0f);////8.0f);

					if(ent->client->ps.fd.forcePower < g_throwforce.integer){
						trap_SendServerCommand( -1, va("print \"^1Force save!\n%s ^5resisted the throw.\n\"",other->client->pers.netname) );
						///trap_SendServerCommand( -1, va("cp \"^1Force save!\n%s ^5resisted the throw.\n\"",other->client->pers.netname) );
					}else if (tr.fraction != 1.0 
						|| tr.startsolid || tr2.fraction != 1.0 
						|| tr2.startsolid 
						///&& Q_irand(0,50) > other->client->sess.dex
						){
						trap_SendServerCommand( -1, va("print \"Vector save!\n%s ^5resisted the throw.\n\"",other->client->pers.netname) );
						///trap_SendServerCommand( -1, va("cp \"Vector save!\n%s ^5resisted the throw.\n\"",other->client->pers.netname) );
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
					other->client->ps.velocity[0] = (int)oppDir[0]*(strength*40.0f);
					other->client->ps.velocity[1] = (int)oppDir[1]*(strength*40.0f);
					other->client->ps.velocity[2] = 150;

					VectorSubtract(ent->client->ps.origin, other->client->ps.origin, oppDir);
					VectorNormalize(oppDir);
					ent->client->ps.velocity[0] = (int)oppDir[0]*(strength*65.0f);
					ent->client->ps.velocity[1] = (int)oppDir[1]*(strength*65.0f);
					ent->client->ps.velocity[2] = 150;
					//trap_SendServerCommand( -1, va("print \"%s ^5resisted the throw.\n\"",other->client->pers.netname) );
					//trap_SendServerCommand( -1, va("cp \"%s ^5resisted the throw.\n\"",other->client->pers.netname) );

				}
			}else if (other && other->client && other->client->ps.torsoAnim == FACE_SMILE){
				////int xpgain;
			//gentity_t *faceKicker = &g_entities[ent->client->ps.clientNum];
			//other->client->ps.forceKickFlip = faceKicker->s.number+1;


			///unwoot the woot? makes counter more powerful
			other->client->ps.forceKickFlip = ent->s.number+1;

			//G_SetAnim(other, NULL, SETANIM_BOTH, BOTH_A7_KICK_BF, SETANIM_FLAG_OVERRIDE|SETANIM_FLAG_HOLD|SETANIM_FLAG_HOLDLESS, 0);
			G_SetAnim(other, NULL, SETANIM_BOTH, 894, 3, 0);
			saberKnockOutOfHand(&g_entities[ent->client->ps.saberEntityNum], ent, vec3_origin);

			////xpgain = Q_irand(0,1);
			if (other->client && other->client->pers.netname[1] > 0){
				///trap_SendServerCommand(-1, va("print \"%s ^5has gained ^3%i^5 XP\n\"", other->client->pers.netname, xpgain) );
				//trap_SendServerCommand(-1, va("cp \"%s ^5has gained ^3%i^5 XP\n\"", other->client->pers.netname, xpgain) );
				////other->client->sess.xp += xpgain;
				trap_SendServerCommand( -1, va("print \"%s ^5countered the throw!\n\"",other->client->pers.netname) );
				///trap_SendServerCommand( -1, va("cp \"%s ^5countered the throw!\n\"",other->client->pers.netname) );
			}//trap_SendServerCommand(-1, va("cp \"%s ^5has gained ^3%i^5 XP\n\"", faceKicked->client->pers.netname, xpgain) );


			}
		}
	}
	else
	{
		if (Q_stricmp(cmd, "addbot") == 0)
		{ //because addbot isn't a recognized command unless you're the server, but it is in the menus regardless
//			trap_SendServerCommand( clientNum, va("print \"You can only add bots as the server.\n\"" ) );
			trap_SendServerCommand( clientNum, va("print \"%s.\n\"", G_GetStringEdString("MP_SVGAME", "ONLY_ADD_BOTS_AS_SERVER")));
		}
		else
		{
			trap_SendServerCommand( clientNum, va("print \"unknown cmd %s: type /help for some help (visit www.berealistic.com for forums and downloads)\n\"", cmd ) );
		}
	}
}
