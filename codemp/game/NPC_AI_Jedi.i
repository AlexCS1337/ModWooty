#line 1 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\npc_ai_jedi.c"
#line 1 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\b_local.h"





#line 1 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\g_local.h"




#line 1 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\q_shared.h"













#line 1 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\qcommon\\disablewarnings.h"




#pragma warning(disable : 4018)     
#pragma warning(disable : 4032)
#pragma warning(disable : 4051)
#pragma warning(disable : 4057)		
#pragma warning(disable : 4100)		
#pragma warning(disable : 4115)
#pragma warning(disable : 4125)		
#pragma warning(disable : 4127)		
#pragma warning(disable : 4136)
#pragma warning(disable : 4152)		
#pragma warning(disable : 4201)
#pragma warning(disable : 4214)
#pragma warning(disable : 4244)		
#pragma warning(disable : 4284)		
#pragma warning(disable : 4305)		
#pragma warning(disable : 4310)		
#pragma warning(disable : 4389)		
#pragma warning(disable : 4503)		

#pragma warning(disable : 4511)		
#pragma warning(disable : 4512)		
#pragma warning(disable : 4514)		
#pragma warning(disable : 4663)		
#pragma warning(disable : 4702)		
#pragma warning(disable : 4710)		
#pragma warning(disable : 4711)		
#pragma warning(disable : 4220)		
#pragma warning(disable : 4786)		


#pragma warning(disable : 4213)		
#pragma warning(disable : 4245)		

#line 39 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\qcommon\\disablewarnings.h"
#line 15 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\q_shared.h"

#line 1 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\teams.h"



typedef enum 
{
	NPCTEAM_FREE,			
	NPCTEAM_ENEMY,			
	NPCTEAM_PLAYER,			
	NPCTEAM_NEUTRAL,		

	
	NPCTEAM_NUM_TEAMS
};
typedef int npcteam_t;


typedef enum 
{
	CLASS_NONE,				
	CLASS_ATST,				
	CLASS_BARTENDER,
	CLASS_BESPIN_COP,		
	CLASS_CLAW,
	CLASS_COMMANDO,
	CLASS_DESANN,			
	CLASS_FISH,
	CLASS_FLIER2,
	CLASS_GALAK,
	CLASS_GLIDER,
	CLASS_GONK,				
	CLASS_GRAN,
	CLASS_HOWLER,
	CLASS_IMPERIAL,
	CLASS_IMPWORKER,
	CLASS_INTERROGATOR,		
	CLASS_JAN,				
	CLASS_JEDI,				
	CLASS_KYLE,				
	CLASS_LANDO,			
	CLASS_LIZARD,
	CLASS_LUKE,				
	CLASS_MARK1,			
	CLASS_MARK2,			
	CLASS_GALAKMECH,		
	CLASS_MINEMONSTER,
	CLASS_MONMOTHA,			
	CLASS_MORGANKATARN,
	CLASS_MOUSE,			
	CLASS_MURJJ,
	CLASS_PRISONER,
	CLASS_PROBE,			
	CLASS_PROTOCOL,			
	CLASS_R2D2,				
	CLASS_R5D2,				
	CLASS_REBEL,
	CLASS_REBORN,
	CLASS_REELO,
	CLASS_REMOTE,
	CLASS_RODIAN,
	CLASS_SEEKER,			
	CLASS_SENTRY,
	CLASS_SHADOWTROOPER,
	CLASS_STORMTROOPER,
	CLASS_SWAMP,
	CLASS_SWAMPTROOPER,
	CLASS_TAVION,
	CLASS_TRANDOSHAN,
	CLASS_UGNAUGHT,
	CLASS_JAWA,
	CLASS_WEEQUAY,
	CLASS_BOBAFETT,
	CLASS_VEHICLE,
	CLASS_RANCOR,
	CLASS_WAMPA,
	
	CLASS_NUM_CLASSES
} class_t;

#line 80 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\teams.h"
#line 17 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\q_shared.h"































extern int g_Ghoul2Allocations;
extern int g_G2ServerAlloc;
extern int g_G2ClientAlloc;
extern int g_G2AllocServer;
#line 53 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\q_shared.h"




























#line 1 "c:\\program files\\microsoft visual studio 8\\vc\\include\\assert.h"













#line 1 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"














 





#line 22 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"
#line 23 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"














#line 38 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"



#line 42 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"











    

#line 56 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"

#line 58 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"

#line 1 "c:\\program files\\microsoft visual studio 8\\vc\\include\\sal.h"

























































































































































































































#pragma once











#line 231 "c:\\program files\\microsoft visual studio 8\\vc\\include\\sal.h"
#line 232 "c:\\program files\\microsoft visual studio 8\\vc\\include\\sal.h"



























































































































































































































#line 452 "c:\\program files\\microsoft visual studio 8\\vc\\include\\sal.h"
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
#line 486 "c:\\program files\\microsoft visual studio 8\\vc\\include\\sal.h"



































































































































































































































    
    
#line 716 "c:\\program files\\microsoft visual studio 8\\vc\\include\\sal.h"






#line 723 "c:\\program files\\microsoft visual studio 8\\vc\\include\\sal.h"
#line 724 "c:\\program files\\microsoft visual studio 8\\vc\\include\\sal.h"







#line 60 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"























































































#pragma pack(push,8)
#line 149 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"

#line 1 "c:\\program files\\microsoft visual studio 8\\vc\\include\\vadefs.h"













#pragma once
#line 16 "c:\\program files\\microsoft visual studio 8\\vc\\include\\vadefs.h"






#line 23 "c:\\program files\\microsoft visual studio 8\\vc\\include\\vadefs.h"









#pragma pack(push,8)
#line 34 "c:\\program files\\microsoft visual studio 8\\vc\\include\\vadefs.h"











#line 46 "c:\\program files\\microsoft visual studio 8\\vc\\include\\vadefs.h"
#line 47 "c:\\program files\\microsoft visual studio 8\\vc\\include\\vadefs.h"





typedef __w64 unsigned int   uintptr_t;
#line 54 "c:\\program files\\microsoft visual studio 8\\vc\\include\\vadefs.h"

#line 56 "c:\\program files\\microsoft visual studio 8\\vc\\include\\vadefs.h"





typedef char *  va_list;
#line 63 "c:\\program files\\microsoft visual studio 8\\vc\\include\\vadefs.h"

#line 65 "c:\\program files\\microsoft visual studio 8\\vc\\include\\vadefs.h"





#line 71 "c:\\program files\\microsoft visual studio 8\\vc\\include\\vadefs.h"











#line 83 "c:\\program files\\microsoft visual studio 8\\vc\\include\\vadefs.h"


#line 86 "c:\\program files\\microsoft visual studio 8\\vc\\include\\vadefs.h"













#line 100 "c:\\program files\\microsoft visual studio 8\\vc\\include\\vadefs.h"












































#line 145 "c:\\program files\\microsoft visual studio 8\\vc\\include\\vadefs.h"






#pragma pack(pop)
#line 153 "c:\\program files\\microsoft visual studio 8\\vc\\include\\vadefs.h"

#line 155 "c:\\program files\\microsoft visual studio 8\\vc\\include\\vadefs.h"
#line 151 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"









#line 161 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"




#line 166 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"








#line 175 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"






#line 182 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"

#line 184 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"
#line 185 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"






#line 192 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"

#line 194 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"
#line 195 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"













#line 209 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"
#line 210 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"





#line 216 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"







#line 224 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"

#line 226 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"

#line 228 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"







#line 236 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"
#line 237 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"




#line 242 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"

#line 244 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"
#line 245 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"




#line 250 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"

#line 252 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"
#line 253 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"


 

#line 258 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"
  
 #line 260 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"
#line 261 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"










#line 272 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"
#line 273 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"






#line 280 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"
#line 281 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"

















#line 299 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"




#line 304 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"





#line 310 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"







#line 318 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"
#line 319 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"







#line 327 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"
#line 328 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"





#line 334 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"


#line 337 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"

#line 339 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"
#line 340 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"
#line 341 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"











#line 353 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"

#line 355 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"
#line 356 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"
#line 357 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"












#line 370 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"
#line 371 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"







#line 379 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"

#line 381 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"
#line 382 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"



 
  
 



#line 392 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"
#line 393 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"


 
  
  
 



#line 403 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"
#line 404 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"


 
  
   
  

#line 412 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"
 



#line 417 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"
#line 418 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"





#line 424 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"

#line 426 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"
#line 427 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"





typedef __w64 unsigned int   size_t;
#line 434 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"

#line 436 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"



typedef size_t rsize_t;

#line 442 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"
#line 443 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"





typedef __w64 int            intptr_t;
#line 450 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"

#line 452 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"














typedef __w64 int            ptrdiff_t;
#line 468 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"

#line 470 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"


typedef unsigned short wchar_t;

#line 475 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"


typedef unsigned short wint_t;
typedef unsigned short wctype_t;

#line 481 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"



















#line 501 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"





__declspec(deprecated("This name was supported during some Whidbey pre-releases. Instead, use the standard name errno_t.")) typedef int errcode;


#line 510 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"

typedef int errno_t;
#line 513 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"


typedef __w64 long __time32_t;   

#line 518 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"



typedef __int64 __time64_t;     
#line 523 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"

#line 525 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"



typedef __time32_t time_t;      


#line 532 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"

#line 534 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"







#line 542 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"
#line 543 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"




#line 548 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"

#line 550 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"
#line 551 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"




#line 556 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"

#line 558 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"
#line 559 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"






#line 566 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"
#line 567 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"




#line 572 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"



#line 576 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"











#line 588 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"




#line 593 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"




#line 598 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"

#line 600 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"
#line 601 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"







#line 609 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"



















































































































































#line 757 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"














#line 772 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"
#line 773 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"







































































































































































































































































































































































































































































































































































































































































































































































































































































#line 1613 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"






















































































#line 1700 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"
#line 1701 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"

struct threadlocaleinfostruct;
struct threadmbcinfostruct;
typedef struct threadlocaleinfostruct * pthreadlocinfo;
typedef struct threadmbcinfostruct * pthreadmbcinfo;
struct __lc_time_data;

typedef struct localeinfo_struct
{
    pthreadlocinfo locinfo;
    pthreadmbcinfo mbcinfo;
} _locale_tstruct, *_locale_t;


typedef struct tagLC_ID {
        unsigned short wLanguage;
        unsigned short wCountry;
        unsigned short wCodePage;
} LC_ID, *LPLC_ID;

#line 1722 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"


typedef struct threadlocaleinfostruct {
        int refcount;
        unsigned int lc_codepage;
        unsigned int lc_collate_cp;
        unsigned long lc_handle[6]; 
        LC_ID lc_id[6];
        struct {
            char *locale;
            wchar_t *wlocale;
            int *refcount;
            int *wrefcount;
        } lc_category[6];
        int lc_clike;
        int mb_cur_max;
        int * lconv_intl_refcount;
        int * lconv_num_refcount;
        int * lconv_mon_refcount;
        struct lconv * lconv;
        int * ctype1_refcount;
        unsigned short * ctype1;
        const unsigned short * pctype;
        const unsigned char * pclmap;
        const unsigned char * pcumap;
        struct __lc_time_data * lc_time_curr;
} threadlocinfo;

#line 1751 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"







#line 1759 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"

#line 1761 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"



#line 1765 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"

#line 1767 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"



#line 1771 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"

#line 1773 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"






#line 1780 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"



#line 1784 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"


#pragma pack(pop)
#line 1788 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"

#line 1790 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"

#line 15 "c:\\program files\\microsoft visual studio 8\\vc\\include\\assert.h"













 void __cdecl _wassert(       const wchar_t * _Message,        const wchar_t *_File,      unsigned _Line);







#line 37 "c:\\program files\\microsoft visual studio 8\\vc\\include\\assert.h"
#line 82 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\q_shared.h"
#line 1 "c:\\program files\\microsoft visual studio 8\\vc\\include\\math.h"

















#line 1 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"














 















































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































#line 19 "c:\\program files\\microsoft visual studio 8\\vc\\include\\math.h"






#pragma pack(push,8)
#line 27 "c:\\program files\\microsoft visual studio 8\\vc\\include\\math.h"












struct _exception {
        int type;       
        char *name;     
        double arg1;    
        double arg2;    
        double retval;  
        } ;


#line 49 "c:\\program files\\microsoft visual studio 8\\vc\\include\\math.h"







struct _complex {
        double x,y; 
        } ;




#line 64 "c:\\program files\\microsoft visual studio 8\\vc\\include\\math.h"


#line 67 "c:\\program files\\microsoft visual studio 8\\vc\\include\\math.h"
#line 68 "c:\\program files\\microsoft visual studio 8\\vc\\include\\math.h"






















 extern double _HUGE;


#line 94 "c:\\program files\\microsoft visual studio 8\\vc\\include\\math.h"
#line 95 "c:\\program files\\microsoft visual studio 8\\vc\\include\\math.h"








        int     __cdecl abs(     int _X);
        long    __cdecl labs(     long _X);
#line 106 "c:\\program files\\microsoft visual studio 8\\vc\\include\\math.h"

        double  __cdecl acos(     double _X);
        double  __cdecl asin(     double _X);
        double  __cdecl atan(     double _X);
        double  __cdecl atan2(     double _Y,      double _X);

  double __cdecl _copysign (     double _Number,      double _Sign);
  double __cdecl _chgsign (     double _X);

#line 116 "c:\\program files\\microsoft visual studio 8\\vc\\include\\math.h"
        double  __cdecl cos(     double _X);
        double  __cdecl cosh(     double _X);
        double  __cdecl exp(     double _X);
 double  __cdecl fabs(     double _X);
        double  __cdecl fmod(     double _X,      double _Y);
        double  __cdecl log(     double _X);
        double  __cdecl log10(     double _X);
        double  __cdecl pow(     double _X,      double _Y);
        double  __cdecl sin(     double _X);
        double  __cdecl sinh(     double _X);
        double  __cdecl tan(     double _X);
        double  __cdecl tanh(     double _X);
        double  __cdecl sqrt(     double _X);


 double  __cdecl atof(       const char *_String);
 double  __cdecl _atof_l(       const char *_String,        _locale_t _Locale);
#line 134 "c:\\program files\\microsoft visual studio 8\\vc\\include\\math.h"

 double  __cdecl _cabs(     struct _complex _Complex);
 double  __cdecl ceil(     double _X);
 double  __cdecl floor(     double _X);
 double  __cdecl frexp(     double _X,      int * _Y);
 double  __cdecl _hypot(     double _X,      double _Y);
 double  __cdecl _j0(     double _X );
 double  __cdecl _j1(     double _X );
 double  __cdecl _jn(int _X,      double _Y);
 double  __cdecl ldexp(     double _X,      int _Y);




#line 149 "c:\\program files\\microsoft visual studio 8\\vc\\include\\math.h"
        int     __cdecl _matherr(     struct _exception * _Except);
#line 151 "c:\\program files\\microsoft visual studio 8\\vc\\include\\math.h"
#line 152 "c:\\program files\\microsoft visual studio 8\\vc\\include\\math.h"
 double  __cdecl modf(     double _X,      double * _Y);

 double  __cdecl _y0(     double _X);
 double  __cdecl _y1(     double _X);
 double  __cdecl _yn(     int _X,      double _Y);




 int     __cdecl _set_SSE2_enable(     int _Flag);
 float  __cdecl _hypotf(     float _X,      float _Y);

#line 165 "c:\\program files\\microsoft visual studio 8\\vc\\include\\math.h"







































#line 205 "c:\\program files\\microsoft visual studio 8\\vc\\include\\math.h"













































#line 251 "c:\\program files\\microsoft visual studio 8\\vc\\include\\math.h"






























































#line 314 "c:\\program files\\microsoft visual studio 8\\vc\\include\\math.h"
#line 315 "c:\\program files\\microsoft visual studio 8\\vc\\include\\math.h"



















































































































#line 431 "c:\\program files\\microsoft visual studio 8\\vc\\include\\math.h"
#line 432 "c:\\program files\\microsoft visual studio 8\\vc\\include\\math.h"

















 extern double HUGE;


#line 453 "c:\\program files\\microsoft visual studio 8\\vc\\include\\math.h"

__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_cabs" ". See online help for details."))  double  __cdecl cabs(     struct _complex _X);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_hypot" ". See online help for details."))  double  __cdecl hypot(     double _X,      double _Y);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_j0" ". See online help for details."))  double  __cdecl j0(     double _X);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_j1" ". See online help for details."))  double  __cdecl j1(     double _X);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_jn" ". See online help for details."))  double  __cdecl jn(     int _X,      double _Y);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_y0" ". See online help for details."))  double  __cdecl y0(     double _X);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_y1" ". See online help for details."))  double  __cdecl y1(     double _X);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_yn" ". See online help for details."))  double  __cdecl yn(     int _X,      double _Y);

#line 464 "c:\\program files\\microsoft visual studio 8\\vc\\include\\math.h"

#line 466 "c:\\program files\\microsoft visual studio 8\\vc\\include\\math.h"






























































































































#pragma pack(pop)
#line 594 "c:\\program files\\microsoft visual studio 8\\vc\\include\\math.h"

#line 596 "c:\\program files\\microsoft visual studio 8\\vc\\include\\math.h"







































#line 636 "c:\\program files\\microsoft visual studio 8\\vc\\include\\math.h"

#line 83 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\q_shared.h"
#line 1 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdio.h"















#pragma once
#line 18 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdio.h"




#line 1 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"














 















































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































#line 23 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdio.h"





#pragma pack(push,8)
#line 30 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdio.h"





























struct _iobuf {
        char *_ptr;
        int   _cnt;
        char *_base;
        int   _flag;
        int   _file;
        int   _charbuf;
        int   _bufsiz;
        char *_tmpfname;
        };
typedef struct _iobuf FILE;

#line 72 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdio.h"










#line 83 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdio.h"













#line 97 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdio.h"




















#line 118 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdio.h"







#line 126 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdio.h"
#line 127 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdio.h"




 FILE * __cdecl __iob_func(void);
#line 133 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdio.h"










#line 144 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdio.h"



typedef __int64 fpos_t;




#line 153 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdio.h"
#line 154 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdio.h"


#line 157 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdio.h"






#line 164 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdio.h"
























  int __cdecl _filbuf(     FILE * _File );
  int __cdecl _flsbuf(     int _Ch,      FILE * _File);




  FILE * __cdecl _fsopen(       const char * _Filename,        const char * _Mode,      int _ShFlag);
#line 196 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdio.h"

 void __cdecl clearerr(     FILE * _File);
  errno_t __cdecl clearerr_s(     FILE * _File );
  int __cdecl fclose(     FILE * _File);
  int __cdecl _fcloseall(void);




  FILE * __cdecl _fdopen(     int _FileHandle,        const char * _Mode);
#line 207 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdio.h"

  int __cdecl feof(     FILE * _File);
  int __cdecl ferror(     FILE * _File);
  int __cdecl fflush(       FILE * _File);
  int __cdecl fgetc(     FILE * _File);
  int __cdecl _fgetchar(void);
  int __cdecl fgetpos(     FILE * _File ,      fpos_t * _Pos);
  char * __cdecl fgets(       char * _Buf,      int _MaxCount,      FILE * _File);




  int __cdecl _fileno(     FILE * _File);
#line 221 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdio.h"




#line 226 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdio.h"

  char * __cdecl _tempnam(         const char * _DirName,          const char * _FilePrefix);



#line 232 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdio.h"

  int __cdecl _flushall(void);
   FILE * __cdecl fopen(       const char * _Filename,        const char * _Mode);

  errno_t __cdecl fopen_s(                  FILE ** _File,        const char * _Filename,        const char * _Mode);
#line 238 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdio.h"
  int __cdecl fprintf(     FILE * _File,         const char * _Format, ...);
  int __cdecl fprintf_s(     FILE * _File,         const char * _Format, ...);
  int __cdecl fputc(     int _Ch,      FILE * _File);
  int __cdecl _fputchar(     int _Ch);
  int __cdecl fputs(       const char * _Str,      FILE * _File);
  size_t __cdecl fread(     void * _DstBuf,      size_t _ElementSize,      size_t _Count,      FILE * _File);
  size_t __cdecl fread_s(     void * _DstBuf,      size_t _DstSize,      size_t _ElementSize,      size_t _Count,      FILE * _File);
   FILE * __cdecl freopen(       const char * _Filename,        const char * _Mode,      FILE * _File);

  errno_t __cdecl freopen_s(                  FILE ** _File,        const char * _Filename,        const char * _Mode,      FILE * _OldFile);
#line 249 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdio.h"
   int __cdecl fscanf(     FILE * _File,         const char * _Format, ...);
   int __cdecl _fscanf_l(     FILE * _File,         const char * _Format,        _locale_t _Locale, ...);

  int __cdecl fscanf_s(     FILE * _File,         const char * _Format, ...);
#line 254 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdio.h"
  int __cdecl _fscanf_s_l(     FILE * _File,         const char * _Format,        _locale_t _Locale, ...);
  int __cdecl fsetpos(     FILE * _File,      const fpos_t * _Pos);
  int __cdecl fseek(     FILE * _File,      long _Offset,      int _Origin);
  long __cdecl ftell(     FILE * _File);

  int __cdecl _fseeki64(     FILE * _File,      __int64 _Offset,      int _Origin);
  __int64 __cdecl _ftelli64(     FILE * _File);

  size_t __cdecl fwrite(       const void * _Str,      size_t _Size,      size_t _Count,      FILE * _File);
  int __cdecl getc(     FILE * _File);
  int __cdecl getchar(void);
  int __cdecl _getmaxstdio(void);

 char * __cdecl gets_s(       char * _Buf,      rsize_t _Size);
#line 269 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdio.h"

  char * __cdecl gets( char *_Buffer);
 int __cdecl _getw(     FILE * _File);


 void __cdecl perror(         const char * _ErrMsg);
#line 276 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdio.h"
  int __cdecl _pclose(     FILE * _File);
  FILE * __cdecl _popen(       const char * _Command,        const char * _Mode);
  int __cdecl printf(        const char * _Format, ...);
  int __cdecl printf_s(        const char * _Format, ...);
  int __cdecl putc(     int _Ch,      FILE * _File);
  int __cdecl putchar(     int _Ch);
  int __cdecl puts(       const char * _Str);
  int __cdecl _putw(     int _Word,      FILE * _File);


  int __cdecl remove(       const char * _Filename);
  int __cdecl rename(       const char * _OldFilename,        const char * _NewFilename);
  int __cdecl _unlink(       const char * _Filename);

__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_unlink" ". See online help for details."))   int __cdecl unlink(       const char * _Filename);
#line 292 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdio.h"
#line 293 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdio.h"
 void __cdecl rewind(     FILE * _File);
  int __cdecl _rmtmp(void);
   int __cdecl scanf(        const char * _Format, ...);
   int __cdecl _scanf_l(        const char * _Format,        _locale_t _Locale, ...);

  int __cdecl scanf_s(        const char * _Format, ...);
#line 300 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdio.h"
  int __cdecl _scanf_s_l(        const char * _Format,        _locale_t _Locale, ...);
  void __cdecl setbuf(     FILE * _File,              char * _Buffer);
  int __cdecl _setmaxstdio(     int _Max);
  unsigned int __cdecl _set_output_format(     unsigned int _Format);
  unsigned int __cdecl _get_output_format(void);
  int __cdecl setvbuf(     FILE * _File,          char * _Buf,      int _Mode,      size_t _Size);
  int __cdecl _snprintf_s(       char * _DstBuf,      size_t _DstSize,      size_t _MaxCount,         const char * _Format, ...);

  int __cdecl sprintf_s(       char * _DstBuf,      size_t _DstSize,         const char * _Format, ...);

  int __cdecl _scprintf(        const char * _Format, ...);
   int __cdecl sscanf(       const char * _Src,         const char * _Format, ...);
   int __cdecl _sscanf_l(       const char * _Src,         const char * _Format,        _locale_t _Locale, ...);

  int __cdecl sscanf_s(       const char * _Src,         const char * _Format, ...);
#line 316 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdio.h"
  int __cdecl _sscanf_s_l(       const char * _Src,         const char * _Format,        _locale_t _Locale, ...);
   int __cdecl _snscanf(         const char * _Src,      size_t _MaxCount,         const char * _Format, ...);
   int __cdecl _snscanf_l(         const char * _Src,      size_t _MaxCount,         const char * _Format,        _locale_t _Locale, ...);
  int __cdecl _snscanf_s(         const char * _Src,      size_t _MaxCount,         const char * _Format, ...);
  int __cdecl _snscanf_s_l(         const char * _Src,      size_t _MaxCount,         const char * _Format,        _locale_t _Locale, ...);
   FILE * __cdecl tmpfile(void);

  errno_t __cdecl tmpfile_s(                FILE ** _File);
  errno_t __cdecl tmpnam_s(       char * _Buf,      rsize_t _Size);
#line 326 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdio.h"

  char * __cdecl tmpnam( char *_Buffer);
  int __cdecl ungetc(     int _Ch,      FILE * _File);
  int __cdecl vfprintf(     FILE * _File,         const char * _Format, va_list _ArgList);
  int __cdecl vfprintf_s(     FILE * _File,         const char * _Format, va_list _ArgList);
  int __cdecl vprintf(        const char * _Format, va_list _ArgList);
  int __cdecl vprintf_s(        const char * _Format, va_list _ArgList);
   int __cdecl vsnprintf(     char * _DstBuf,      size_t _MaxCount,         const char * _Format, va_list _ArgList);
  int __cdecl vsnprintf_s(       char * _DstBuf,      size_t _DstSize,      size_t _MaxCount,         const char * _Format, va_list _ArgList);
  int __cdecl _vsnprintf_s(       char * _DstBuf,      size_t _DstSize,      size_t _MaxCount,         const char * _Format, va_list _ArgList);

#pragma warning(push)
#pragma warning(disable:4793)
  int __cdecl _snprintf(     char *_Dest,      size_t _Count,         const char * _Format, ...);   int __cdecl _vsnprintf(     char *_Dest,      size_t _Count,         const char * _Format, va_list _Args);
#pragma warning(pop)
 int __cdecl vsprintf_s(       char * _DstBuf,      size_t _Size,         const char * _Format, va_list _ArgList);

#pragma warning(push)
#pragma warning(disable:4793)
  int __cdecl sprintf( char *_Dest,  const char * _Format, ...);   int __cdecl vsprintf( char *_Dest,  const char * _Format, va_list _Args);
#pragma warning(pop)
  int __cdecl _vscprintf(        const char * _Format, va_list _ArgList);
  int __cdecl _snprintf_c(     char * _DstBuf,      size_t _MaxCount,         const char * _Format, ...);
  int __cdecl _vsnprintf_c(     char *_DstBuf,      size_t _MaxCount,         const char * _Format, va_list _ArgList);

  int __cdecl _fprintf_p(     FILE * _File,         const char * _Format, ...);
  int __cdecl _printf_p(        const char * _Format, ...);
  int __cdecl _sprintf_p(       char * _Dst,      size_t _MaxCount,         const char * _Format, ...);
  int __cdecl _vfprintf_p(     FILE * _File,         const char * _Format, va_list _ArgList);
  int __cdecl _vprintf_p(        const char * _Format, va_list _ArgList);
  int __cdecl _vsprintf_p(       char * _Dst,      size_t _MaxCount,         const char * _Format, va_list _ArgList);
  int __cdecl _scprintf_p(        const char * _Format, ...);
  int __cdecl _vscprintf_p(        const char * _Format, va_list _ArgList);
 int __cdecl _set_printf_count_output(     int _Value);
 int __cdecl _get_printf_count_output();

  int __cdecl _printf_l(        const char * _Format,        _locale_t _Locale, ...);
  int __cdecl _printf_p_l(        const char * _Format,        _locale_t _Locale, ...);
  int __cdecl _printf_s_l(        const char * _Format,        _locale_t _Locale, ...);
  int __cdecl _vprintf_l(        const char * _Format,        _locale_t _Locale, va_list _ArgList);
  int __cdecl _vprintf_p_l(        const char * _Format,        _locale_t _Locale, va_list _ArgList);
  int __cdecl _vprintf_s_l(        const char * _Format,        _locale_t _Locale, va_list _ArgList);

  int __cdecl _fprintf_l(     FILE * _File,         const char * _Format,        _locale_t _Locale, ...);
  int __cdecl _fprintf_p_l(     FILE * _File,         const char * _Format,        _locale_t _Locale, ...);
  int __cdecl _fprintf_s_l(     FILE * _File,         const char * _Format,        _locale_t _Locale, ...);
  int __cdecl _vfprintf_l(     FILE * _File,        const char * _Format,        _locale_t _Locale, va_list _ArgList);
  int __cdecl _vfprintf_p_l(     FILE * _File,        const char * _Format,        _locale_t _Locale, va_list _ArgList);
  int __cdecl _vfprintf_s_l(     FILE * _File,        const char * _Format,        _locale_t _Locale, va_list _ArgList);

   int __cdecl _sprintf_l(     char * _DstBuf,         const char * _Format,        _locale_t _Locale, ...);
  int __cdecl _sprintf_p_l(       char * _DstBuf,      size_t _MaxCount,         const char * _Format,        _locale_t _Locale, ...);
  int __cdecl _sprintf_s_l(       char * _DstBuf,      size_t _DstSize,         const char * _Format,        _locale_t _Locale, ...);
   int __cdecl _vsprintf_l(     char * _DstBuf,        const char * _Format,        _locale_t, va_list _ArgList);
  int __cdecl _vsprintf_p_l(       char * _DstBuf,      size_t _MaxCount,         const char* _Format,        _locale_t _Locale,  va_list _ArgList);
  int __cdecl _vsprintf_s_l(       char * _DstBuf,      size_t _DstSize,         const char * _Format,        _locale_t _Locale, va_list _ArgList);

  int __cdecl _scprintf_l(        const char * _Format,        _locale_t _Locale, ...);
  int __cdecl _scprintf_p_l(        const char * _Format,        _locale_t _Locale, ...);
  int __cdecl _vscprintf_l(        const char * _Format,        _locale_t _Locale, va_list _ArgList);
  int __cdecl _vscprintf_p_l(        const char * _Format,        _locale_t _Locale, va_list _ArgList);

   int __cdecl _snprintf_l(     char * _DstBuf,      size_t _MaxCount,         const char * _Format,        _locale_t _Locale, ...);
  int __cdecl _snprintf_c_l(     char * _DstBuf,      size_t _MaxCount,         const char * _Format,        _locale_t _Locale, ...);
  int __cdecl _snprintf_s_l(       char * _DstBuf,      size_t _DstSize,      size_t _MaxCount,         const char * _Format,        _locale_t _Locale, ...);
   int __cdecl _vsnprintf_l(     char * _DstBuf,      size_t _MaxCount,         const char * _Format,        _locale_t _Locale, va_list _ArgList);
  int __cdecl _vsnprintf_c_l(     char * _DstBuf,      size_t _MaxCount, const char *,        _locale_t _Locale, va_list _ArgList);
  int __cdecl _vsnprintf_s_l(       char * _DstBuf,      size_t _DstSize,      size_t _MaxCount,         const char* _Format,       _locale_t _Locale, va_list _ArgList);







#line 402 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdio.h"




  FILE * __cdecl _wfsopen(       const wchar_t * _Filename,        const wchar_t * _Mode,      int _ShFlag);
#line 408 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdio.h"

  wint_t __cdecl fgetwc(     FILE * _File);
  wint_t __cdecl _fgetwchar(void);
  wint_t __cdecl fputwc(       wchar_t _Ch,      FILE * _File);
  wint_t __cdecl _fputwchar(       wchar_t _Ch);
  wint_t __cdecl getwc(     FILE * _File);
  wint_t __cdecl getwchar(void);
  wint_t __cdecl putwc(       wchar_t _Ch,      FILE * _File);
  wint_t __cdecl putwchar(       wchar_t _Ch);
  wint_t __cdecl ungetwc(     wint_t _Ch,      FILE * _File);

  wchar_t * __cdecl fgetws(       wchar_t * _Dst,      int _SizeInWords,      FILE * _File);
  int __cdecl fputws(       const wchar_t * _Str,      FILE * _File);
  wchar_t * __cdecl _getws_s(       wchar_t * _Str,      size_t _SizeInWords);

  wchar_t * __cdecl _getws( wchar_t *_String);
  int __cdecl _putws(       const wchar_t * _Str);

  int __cdecl fwprintf(     FILE * _File,         const wchar_t * _Format, ...);
  int __cdecl fwprintf_s(     FILE * _File,         const wchar_t * _Format, ...);
  int __cdecl wprintf(        const wchar_t * _Format, ...);
  int __cdecl wprintf_s(        const wchar_t * _Format, ...);
  int __cdecl _scwprintf(        const wchar_t * _Format, ...);
  int __cdecl vfwprintf(     FILE * _File,         const wchar_t * _Format, va_list _ArgList);
  int __cdecl vfwprintf_s(     FILE * _File,         const wchar_t * _Format, va_list _ArgList);
  int __cdecl vwprintf(        const wchar_t * _Format, va_list _ArgList);
  int __cdecl vwprintf_s(        const wchar_t * _Format, va_list _ArgList);

 int __cdecl swprintf_s(       wchar_t * _Dst,      size_t _SizeInWords,         const wchar_t * _Format, ...);

 int __cdecl vswprintf_s(       wchar_t * _Dst,      size_t _SizeInWords,         const wchar_t * _Format, va_list _ArgList);


  int __cdecl _swprintf_c(       wchar_t * _DstBuf,      size_t _SizeInWords,         const wchar_t * _Format, ...);
  int __cdecl _vswprintf_c(       wchar_t * _DstBuf,      size_t _SizeInWords,         const wchar_t * _Format, va_list _ArgList);

  int __cdecl _snwprintf_s(       wchar_t * _DstBuf,      size_t _DstSizeInWords,      size_t _MaxCount,         const wchar_t * _Format, ...);

  int __cdecl _vsnwprintf_s(       wchar_t * _DstBuf,      size_t _DstSizeInWords,      size_t _MaxCount,         const wchar_t * _Format, va_list _ArgList);

#pragma warning(push)
#pragma warning(disable:4793)
  int __cdecl _snwprintf(     wchar_t *_Dest,      size_t _Count,         const wchar_t * _Format, ...);   int __cdecl _vsnwprintf(     wchar_t *_Dest,      size_t _Count,         const wchar_t * _Format, va_list _Args);
#pragma warning(pop)

  int __cdecl _fwprintf_p(     FILE * _File,         const wchar_t * _Format, ...);
  int __cdecl _wprintf_p(        const wchar_t * _Format, ...);
  int __cdecl _vfwprintf_p(     FILE * _File,         const wchar_t * _Format, va_list _ArgList);
  int __cdecl _vwprintf_p(        const wchar_t * _Format, va_list _ArgList);
  int __cdecl _swprintf_p(       wchar_t * _DstBuf,      size_t _MaxCount,         const wchar_t * _Format, ...);
  int __cdecl _vswprintf_p(       wchar_t * _DstBuf,      size_t _MaxCount,         const wchar_t * _Format, va_list _ArgList);
  int __cdecl _scwprintf_p(        const wchar_t * _Format, ...);
  int __cdecl _vscwprintf_p(        const wchar_t * _Format, va_list _ArgList);

  int __cdecl _wprintf_l(        const wchar_t * _Format,        _locale_t _Locale, ...);
  int __cdecl _wprintf_p_l(        const wchar_t * _Format,        _locale_t _Locale, ...);
  int __cdecl _wprintf_s_l(        const wchar_t * _Format,        _locale_t _Locale, ...);
  int __cdecl _vwprintf_l(        const wchar_t * _Format,        _locale_t _Locale, va_list _ArgList);
  int __cdecl _vwprintf_p_l(        const wchar_t * _Format,        _locale_t _Locale, va_list _ArgList);
  int __cdecl _vwprintf_s_l(        const wchar_t * _Format,        _locale_t _Locale, va_list _ArgList);

  int __cdecl _fwprintf_l(     FILE * _File,         const wchar_t * _Format,        _locale_t _Locale, ...);
  int __cdecl _fwprintf_p_l(     FILE * _File,         const wchar_t * _Format,        _locale_t _Locale, ...);
  int __cdecl _fwprintf_s_l(     FILE * _File,         const wchar_t * _Format,        _locale_t _Locale, ...);
  int __cdecl _vfwprintf_l(     FILE * _File,         const wchar_t * _Format,        _locale_t _Locale, va_list _ArgList);
  int __cdecl _vfwprintf_p_l(     FILE * _File,         const wchar_t * _Format,        _locale_t _Locale, va_list _ArgList);
  int __cdecl _vfwprintf_s_l(     FILE * _File,         const wchar_t * _Format,        _locale_t _Locale, va_list _ArgList);

  int __cdecl _swprintf_c_l(       wchar_t * _DstBuf,      size_t _MaxCount,         const wchar_t * _Format,        _locale_t _Locale, ...);
  int __cdecl _swprintf_p_l(       wchar_t * _DstBuf,      size_t _MaxCount,         const wchar_t * _Format,        _locale_t _Locale, ...);
  int __cdecl _swprintf_s_l(       wchar_t * _DstBuf,      size_t _DstSize,         const wchar_t * _Format,        _locale_t _Locale, ...);
  int __cdecl _vswprintf_c_l(       wchar_t * _DstBuf,      size_t _MaxCount,         const wchar_t * _Format,        _locale_t _Locale, va_list _ArgList);
  int __cdecl _vswprintf_p_l(       wchar_t * _DstBuf,      size_t _MaxCount,         const wchar_t * _Format,        _locale_t _Locale, va_list _ArgList);
  int __cdecl _vswprintf_s_l(       wchar_t * _DstBuf,      size_t _DstSize,         const wchar_t * _Format,        _locale_t _Locale, va_list _ArgList);

  int __cdecl _scwprintf_l(        const wchar_t * _Format,        _locale_t _Locale, ...);
  int __cdecl _scwprintf_p_l(        const wchar_t * _Format,        _locale_t _Locale, ...);
  int __cdecl _vscwprintf_p_l(        const wchar_t * _Format,        _locale_t _Locale, va_list _ArgList);

   int __cdecl _snwprintf_l(     wchar_t * _DstBuf,      size_t _MaxCount,         const wchar_t * _Format,        _locale_t _Locale, ...);
  int __cdecl _snwprintf_s_l(       wchar_t * _DstBuf,      size_t _DstSize,      size_t _MaxCount,         const wchar_t * _Format,        _locale_t _Locale, ...);
   int __cdecl _vsnwprintf_l(     wchar_t * _DstBuf,      size_t _MaxCount,         const wchar_t * _Format,        _locale_t _Locale, va_list _ArgList);
  int __cdecl _vsnwprintf_s_l(       wchar_t * _DstBuf,      size_t _DstSize,      size_t _MaxCount,         const wchar_t * _Format,        _locale_t _Locale, va_list _ArgList);










#line 502 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdio.h"


#pragma warning(push)
#pragma warning(disable:4141 4996 4793)
 __declspec(deprecated("swprintf has been changed to conform with the ISO C standard, adding an extra character count parameter. To use traditional Microsoft swprintf, set _CRT_NON_CONFORMING_SWPRINTFS."))  int __cdecl _swprintf(     wchar_t *_Dest,         const wchar_t * _Format, ...);  __declspec(deprecated("swprintf has been changed to conform with the ISO C standard, adding an extra character count parameter. To use traditional Microsoft swprintf, set _CRT_NON_CONFORMING_SWPRINTFS."))  int __cdecl _vswprintf(     wchar_t *_Dest,         const wchar_t * _Format, va_list _Args);
 __declspec(deprecated("swprintf has been changed to conform with the ISO C standard, adding an extra character count parameter. To use traditional Microsoft swprintf, set _CRT_NON_CONFORMING_SWPRINTFS."))  int __cdecl __swprintf_l(     wchar_t *_Dest,         const wchar_t * _Format, _locale_t _Plocinfo, ...);  __declspec(deprecated("swprintf has been changed to conform with the ISO C standard, adding an extra character count parameter. To use traditional Microsoft swprintf, set _CRT_NON_CONFORMING_SWPRINTFS."))  int __cdecl __vswprintf_l(     wchar_t *_Dest,         const wchar_t * _Format, _locale_t _Plocinfo, va_list _Args);
#pragma warning(pop)


#line 1 "c:\\program files\\microsoft visual studio 8\\vc\\include\\swprintf.inl"












#pragma once







#line 22 "c:\\program files\\microsoft visual studio 8\\vc\\include\\swprintf.inl"










#line 33 "c:\\program files\\microsoft visual studio 8\\vc\\include\\swprintf.inl"

#pragma warning( push )
#pragma warning( disable : 4793 4412 )
static __inline int swprintf(wchar_t * _String, size_t _Count, const wchar_t * _Format, ...)
{
    va_list _Arglist;
    int _Ret;
    ( _Arglist = (va_list)( &(_Format) ) + ( (sizeof(_Format) + sizeof(int) - 1) & ~(sizeof(int) - 1) ) );
    _Ret = _vswprintf_c_l(_String, _Count, _Format, ((void *)0), _Arglist);
    ( _Arglist = (va_list)0 );
    return _Ret;
}
#pragma warning( pop )

#pragma warning( push )
#pragma warning( disable : 4412 )
static __inline int __cdecl vswprintf(wchar_t * _String, size_t _Count, const wchar_t * _Format, va_list _Ap)
{
    return _vswprintf_c_l(_String, _Count, _Format, ((void *)0), _Ap);
}
#pragma warning( pop )


#line 57 "c:\\program files\\microsoft visual studio 8\\vc\\include\\swprintf.inl"

#pragma warning( push )
#pragma warning( disable : 4793 4412 )
static __inline int _swprintf_l(wchar_t * _String, size_t _Count, const wchar_t * _Format, _locale_t _Plocinfo, ...)
{
    va_list _Arglist;
    int _Ret;
    ( _Arglist = (va_list)( &(_Plocinfo) ) + ( (sizeof(_Plocinfo) + sizeof(int) - 1) & ~(sizeof(int) - 1) ) );
    _Ret = _vswprintf_c_l(_String, _Count, _Format, _Plocinfo, _Arglist);
    ( _Arglist = (va_list)0 );
    return _Ret;
}
#pragma warning( pop )

#pragma warning( push )
#pragma warning( disable : 4412 )
static __inline int __cdecl _vswprintf_l(wchar_t * _String, size_t _Count, const wchar_t * _Format, _locale_t _Plocinfo, va_list _Ap)
{
    return _vswprintf_c_l(_String, _Count, _Format, _Plocinfo, _Ap);
}
#pragma warning( pop )

















































#line 128 "c:\\program files\\microsoft visual studio 8\\vc\\include\\swprintf.inl"
#line 129 "c:\\program files\\microsoft visual studio 8\\vc\\include\\swprintf.inl"

#line 512 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdio.h"
#line 513 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdio.h"













#line 527 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdio.h"

  wchar_t * __cdecl _wtempnam(         const wchar_t * _Directory,          const wchar_t * _FilePrefix);



#line 533 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdio.h"

  int __cdecl _vscwprintf(        const wchar_t * _Format, va_list _ArgList);
  int __cdecl _vscwprintf_l(        const wchar_t * _Format,        _locale_t _Locale, va_list _ArgList);
   int __cdecl fwscanf(     FILE * _File,         const wchar_t * _Format, ...);
   int __cdecl _fwscanf_l(     FILE * _File,         const wchar_t * _Format,        _locale_t _Locale, ...);

  int __cdecl fwscanf_s(     FILE * _File,         const wchar_t * _Format, ...);
#line 541 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdio.h"
  int __cdecl _fwscanf_s_l(     FILE * _File,         const wchar_t * _Format,        _locale_t _Locale, ...);
   int __cdecl swscanf(       const wchar_t * _Src,         const wchar_t * _Format, ...);
   int __cdecl _swscanf_l(       const wchar_t * _Src,         const wchar_t * _Format,        _locale_t _Locale, ...);

  int __cdecl swscanf_s(       const wchar_t *_Src,         const wchar_t * _Format, ...);
#line 547 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdio.h"
  int __cdecl _swscanf_s_l(       const wchar_t * _Src,         const wchar_t * _Format,        _locale_t _Locale, ...);
   int __cdecl _snwscanf(         const wchar_t * _Src,      size_t _MaxCount,         const wchar_t * _Format, ...);
   int __cdecl _snwscanf_l(         const wchar_t * _Src,      size_t _MaxCount,         const wchar_t * _Format,        _locale_t _Locale, ...);
  int __cdecl _snwscanf_s(         const wchar_t * _Src,      size_t _MaxCount,         const wchar_t * _Format, ...);
  int __cdecl _snwscanf_s_l(         const wchar_t * _Src,      size_t _MaxCount,         const wchar_t * _Format,        _locale_t _Locale, ...);
   int __cdecl wscanf(        const wchar_t * _Format, ...);
   int __cdecl _wscanf_l(        const wchar_t * _Format,        _locale_t _Locale, ...);

  int __cdecl wscanf_s(        const wchar_t * _Format, ...);
#line 557 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdio.h"
  int __cdecl _wscanf_s_l(        const wchar_t * _Format,        _locale_t _Locale, ...);

  FILE * __cdecl _wfdopen(     int _FileHandle ,        const wchar_t * _Mode);
   FILE * __cdecl _wfopen(       const wchar_t * _Filename,        const wchar_t * _Mode);
  errno_t __cdecl _wfopen_s(                  FILE ** _File,        const wchar_t * _Filename,        const wchar_t * _Mode);
   FILE * __cdecl _wfreopen(       const wchar_t * _Filename,        const wchar_t * _Mode,      FILE * _OldFile);
  errno_t __cdecl _wfreopen_s(                  FILE ** _File,        const wchar_t * _Filename,        const wchar_t * _Mode,      FILE * _OldFile);



 void __cdecl _wperror(         const wchar_t * _ErrMsg);
#line 569 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdio.h"
  FILE * __cdecl _wpopen(       const wchar_t *_Command,        const wchar_t * _Mode);
  int __cdecl _wremove(       const wchar_t * _Filename);
  errno_t __cdecl _wtmpnam_s(       wchar_t * _DstBuf,      size_t _SizeInWords);

  wchar_t * __cdecl _wtmpnam( wchar_t *_Buffer);

  wint_t __cdecl _fgetwc_nolock(     FILE * _File);
  wint_t __cdecl _fputwc_nolock(       wchar_t _Ch,      FILE * _File);
  wint_t __cdecl _ungetwc_nolock(     wint_t _Ch,      FILE * _File);











#line 590 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdio.h"










#line 601 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdio.h"


#line 604 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdio.h"


#line 607 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdio.h"















#line 623 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdio.h"












 void __cdecl _lock_file(     FILE * _File);
 void __cdecl _unlock_file(     FILE * _File);



#line 641 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdio.h"


  int __cdecl _fclose_nolock(     FILE * _File);
  int __cdecl _fflush_nolock(       FILE * _File);
  size_t __cdecl _fread_nolock(     void * _DstBuf,      size_t _ElementSize,      size_t _Count,      FILE * _File);
  size_t __cdecl _fread_nolock_s(     void * _DstBuf,      size_t _DstSize,      size_t _ElementSize,      size_t _Count,      FILE * _File);
  int __cdecl _fseek_nolock(     FILE * _File,      long _Offset,      int _Origin);
  long __cdecl _ftell_nolock(     FILE * _File);
  int __cdecl _fseeki64_nolock(     FILE * _File,      __int64 _Offset,      int _Origin);
  __int64 __cdecl _ftelli64_nolock(     FILE * _File);
  size_t __cdecl _fwrite_nolock(       const void * _DstBuf,      size_t _Size,      size_t _Count,      FILE * _File);
  int __cdecl _ungetc_nolock(     int _Ch,      FILE * _File);












#line 666 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdio.h"











#line 678 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdio.h"

__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_tempnam" ". See online help for details."))  char * __cdecl tempnam(         const char * _Directory,          const char * _FilePrefix);



#line 684 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdio.h"

__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_fcloseall" ". See online help for details."))   int __cdecl fcloseall(void);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_fdopen" ". See online help for details."))   FILE * __cdecl fdopen(     int _FileHandle,         const char * _Format);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_fgetchar" ". See online help for details."))   int __cdecl fgetchar(void);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_fileno" ". See online help for details."))   int __cdecl fileno(     FILE * _File);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_flushall" ". See online help for details."))   int __cdecl flushall(void);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_fputchar" ". See online help for details."))   int __cdecl fputchar(     int _Ch);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_getw" ". See online help for details."))   int __cdecl getw(     FILE * _File);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_putw" ". See online help for details."))   int __cdecl putw(     int _Ch,      FILE * _File);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_rmtmp" ". See online help for details."))   int __cdecl rmtmp(void);

#line 696 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdio.h"






#pragma pack(pop)
#line 704 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdio.h"

#line 706 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdio.h"

#line 84 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\q_shared.h"
#line 1 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdarg.h"















#pragma once
#line 18 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdarg.h"






#line 25 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdarg.h"








#line 34 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdarg.h"
#line 85 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\q_shared.h"
#line 1 "c:\\program files\\microsoft visual studio 8\\vc\\include\\string.h"















#pragma once
#line 18 "c:\\program files\\microsoft visual studio 8\\vc\\include\\string.h"




#line 1 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"














 















































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































#line 23 "c:\\program files\\microsoft visual studio 8\\vc\\include\\string.h"








#line 32 "c:\\program files\\microsoft visual studio 8\\vc\\include\\string.h"
















 void *  __cdecl _memccpy(        void * _Dst,      const void * _Src,      int _Val,      size_t _MaxCount);
   void *  __cdecl memchr(          const void * _Buf ,      int _Val,      size_t _MaxCount);
  int     __cdecl _memicmp(         const void * _Buf1,          const void * _Buf2,      size_t _Size);
  int     __cdecl _memicmp_l(         const void * _Buf1,          const void * _Buf2,      size_t _Size,        _locale_t _Locale);
         int     __cdecl memcmp(         const void * _Buf1,          const void * _Buf2,      size_t _Size);
         void *  __cdecl memcpy(         void * _Dst,          const void * _Src,      size_t _Size);

 errno_t  __cdecl memcpy_s(         void * _Dst,      rsize_t _DstSize,          const void * _Src,      rsize_t _MaxCount);
#line 57 "c:\\program files\\microsoft visual studio 8\\vc\\include\\string.h"
        void *  __cdecl memset(         void * _Dst,      int _Val,      size_t _Size);



__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_memccpy" ". See online help for details."))  void * __cdecl memccpy(       void * _Dst,          const void * _Src,      int _Val,      size_t _Size);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_memicmp" ". See online help for details."))   int __cdecl memicmp(         const void * _Buf1,          const void * _Buf2,      size_t _Size);
#line 64 "c:\\program files\\microsoft visual studio 8\\vc\\include\\string.h"

#line 66 "c:\\program files\\microsoft visual studio 8\\vc\\include\\string.h"

         char *  __cdecl _strset(         char * _Str,      int _Val);
  errno_t __cdecl _strset_s(           char * _Dst,      size_t _DstSize,      int _Value);

  errno_t __cdecl strcpy_s(       char * _Dst,      rsize_t _DstSize,        const char * _Src);
#line 72 "c:\\program files\\microsoft visual studio 8\\vc\\include\\string.h"

  char * __cdecl strcpy( char *_Dest,  const char * _Source);

  errno_t __cdecl strcat_s(           char * _Dst,      rsize_t _DstSize,        const char * _Src);
#line 77 "c:\\program files\\microsoft visual studio 8\\vc\\include\\string.h"

  char * __cdecl strcat( char *_Dest,  const char * _Source);
         int     __cdecl strcmp(       const char * _Str1,        const char * _Str2);
         size_t  __cdecl strlen(        const char * _Str);
  size_t  __cdecl strnlen(          const char * _Str,      size_t _MaxCount);

static __inline  size_t  __cdecl strnlen_s(          const char * _Str,      size_t _MaxCount)
{
    return strnlen(_Str, _MaxCount);
}
#line 88 "c:\\program files\\microsoft visual studio 8\\vc\\include\\string.h"

  errno_t __cdecl memmove_s(         void * _Dst,      rsize_t _DstSize,          const void * _Src,      rsize_t _MaxCount);
#line 91 "c:\\program files\\microsoft visual studio 8\\vc\\include\\string.h"



#line 95 "c:\\program files\\microsoft visual studio 8\\vc\\include\\string.h"
  void *  __cdecl memmove(         void * _Dst,          const void * _Src,      size_t _Size);
#line 97 "c:\\program files\\microsoft visual studio 8\\vc\\include\\string.h"




#line 102 "c:\\program files\\microsoft visual studio 8\\vc\\include\\string.h"

  char *  __cdecl _strdup(         const char * _Src);



#line 108 "c:\\program files\\microsoft visual studio 8\\vc\\include\\string.h"

   char *  __cdecl strchr(       const char * _Str,      int _Val);
  int     __cdecl _stricmp(        const char * _Str1,         const char * _Str2);
  int     __cdecl _strcmpi(        const char * _Str1,         const char * _Str2);
  int     __cdecl _stricmp_l(        const char * _Str1,         const char * _Str2,        _locale_t _Locale);
  int     __cdecl strcoll(        const char * _Str1,         const  char * _Str2);
  int     __cdecl _strcoll_l(        const char * _Str1,         const char * _Str2,        _locale_t _Locale);
  int     __cdecl _stricoll(        const char * _Str1,         const char * _Str2);
  int     __cdecl _stricoll_l(        const char * _Str1,         const char * _Str2,        _locale_t _Locale);
  int     __cdecl _strncoll  (       const char * _Str1,        const char * _Str2,      size_t _MaxCount);
  int     __cdecl _strncoll_l(       const char * _Str1,        const char * _Str2,      size_t _MaxCount,        _locale_t _Locale);
  int     __cdecl _strnicoll (       const char * _Str1,        const char * _Str2,      size_t _MaxCount);
  int     __cdecl _strnicoll_l(       const char * _Str1,        const char * _Str2,      size_t _MaxCount,        _locale_t _Locale);
  size_t  __cdecl strcspn(        const char * _Str,         const char * _Control);
   char *  __cdecl _strerror(         const char * _ErrMsg);
  errno_t __cdecl _strerror_s(       char * _Buf,      size_t _SizeInBytes,          const char * _ErrMsg);

   char *  __cdecl strerror(     int);

  errno_t __cdecl strerror_s(       char * _Buf,      size_t _SizeInBytes,      int _ErrNum);
#line 129 "c:\\program files\\microsoft visual studio 8\\vc\\include\\string.h"

  errno_t __cdecl _strlwr_s(           char * _Str,      size_t _Size);

  char * __cdecl _strlwr( char *_String);
  errno_t __cdecl _strlwr_s_l(           char * _Str,      size_t _Size,        _locale_t _Locale);

  char * __cdecl _strlwr_l(         char *_String,        _locale_t _Locale);

  errno_t __cdecl strncat_s(           char * _Dst,      rsize_t _DstSize,        const char * _Src,      rsize_t _MaxCount);
#line 139 "c:\\program files\\microsoft visual studio 8\\vc\\include\\string.h"

#pragma warning(push)
#pragma warning(disable:4609 6059)

  char * __cdecl strncat(           char *_Dest,        const char * _Source,      size_t _Count);
#pragma warning(pop)


#line 148 "c:\\program files\\microsoft visual studio 8\\vc\\include\\string.h"
  int     __cdecl strncmp(       const char * _Str1,        const char * _Str2,      size_t _MaxCount);
#line 150 "c:\\program files\\microsoft visual studio 8\\vc\\include\\string.h"
  int     __cdecl _strnicmp(       const char * _Str1,        const char * _Str2,      size_t _MaxCount);
  int     __cdecl _strnicmp_l(       const char * _Str1,        const char * _Str2,      size_t _MaxCount,        _locale_t _Locale);

  errno_t __cdecl strncpy_s(       char * _Dst,      rsize_t _DstSize,          const char * _Src,      rsize_t _MaxCount);
#line 155 "c:\\program files\\microsoft visual studio 8\\vc\\include\\string.h"

  char * __cdecl strncpy(     char *_Dest,        const char * _Source,      size_t _Count);
  char *  __cdecl _strnset(         char * _Str,      int _Val,      size_t _MaxCount);
  errno_t __cdecl _strnset_s(           char * _Str,      size_t _Size,      int _Val,      size_t _MaxCount);
   char *  __cdecl strpbrk(       const char * _Str,        const char * _Control);
   char *  __cdecl strrchr(       const char * _Str,      int _Ch);
 char *  __cdecl _strrev(         char * _Str);
  size_t  __cdecl strspn(       const char * _Str,        const char * _Control);
   char *  __cdecl strstr(       const char * _Str,        const char * _SubStr);
   char *  __cdecl strtok(           char * _Str,        const char * _Delim);

  char *  __cdecl strtok_s(           char * _Str,        const char * _Delim,                        char ** _Context);
#line 168 "c:\\program files\\microsoft visual studio 8\\vc\\include\\string.h"
  errno_t __cdecl _strupr_s(           char * _Str,      size_t _Size);

  char * __cdecl _strupr( char *_String);
  errno_t __cdecl _strupr_s_l(           char * _Str,      size_t _Size, _locale_t _Locale);

  char * __cdecl _strupr_l(         char *_String,        _locale_t _Locale);
  size_t  __cdecl strxfrm (       char * _Dst,        const char * _Src,      size_t _MaxCount);
  size_t  __cdecl _strxfrm_l(       char * _Dst,        const char * _Src,      size_t _MaxCount,        _locale_t _Locale);



























#line 204 "c:\\program files\\microsoft visual studio 8\\vc\\include\\string.h"

__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_strdup" ". See online help for details."))   char * __cdecl strdup(         const char * _Src);



#line 210 "c:\\program files\\microsoft visual studio 8\\vc\\include\\string.h"


__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_strcmpi" ". See online help for details."))   int __cdecl strcmpi(       const char * _Str1,        const char * _Str2);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_stricmp" ". See online help for details."))   int __cdecl stricmp(       const char * _Str1,        const char * _Str2);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_strlwr" ". See online help for details."))  char * __cdecl strlwr(         char * _Str);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_strnicmp" ". See online help for details."))   int __cdecl strnicmp(       const char * _Str1,        const char * _Str,      size_t _MaxCount);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_strnset" ". See online help for details."))  char * __cdecl strnset(         char * _Str,      int _Val,      size_t _MaxCount);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_strrev" ". See online help for details."))  char * __cdecl strrev(         char * _Str);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_strset" ". See online help for details."))         char * __cdecl strset(         char * _Str,      int _Val);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_strupr" ". See online help for details."))  char * __cdecl strupr(         char * _Str);

#line 222 "c:\\program files\\microsoft visual studio 8\\vc\\include\\string.h"









#line 232 "c:\\program files\\microsoft visual studio 8\\vc\\include\\string.h"

  wchar_t * __cdecl _wcsdup(       const wchar_t * _Str);



#line 238 "c:\\program files\\microsoft visual studio 8\\vc\\include\\string.h"


  errno_t __cdecl wcscat_s(           wchar_t * _Dst,      rsize_t _DstSize, const wchar_t * _Src);
#line 242 "c:\\program files\\microsoft visual studio 8\\vc\\include\\string.h"

  wchar_t * __cdecl wcscat( wchar_t *_Dest,  const wchar_t * _Source);
   wchar_t * __cdecl wcschr(       const wchar_t * _Str, wchar_t _Ch);
  int __cdecl wcscmp(       const wchar_t * _Str1,        const wchar_t * _Str2);

  errno_t __cdecl wcscpy_s(       wchar_t * _Dst,      rsize_t _DstSize,        const wchar_t * _Src);
#line 249 "c:\\program files\\microsoft visual studio 8\\vc\\include\\string.h"

  wchar_t * __cdecl wcscpy( wchar_t *_Dest,  const wchar_t * _Source);
  size_t __cdecl wcscspn(       const wchar_t * _Str,        const wchar_t * _Control);
  size_t __cdecl wcslen(       const wchar_t * _Str);
  size_t __cdecl wcsnlen(         const wchar_t * _Src,      size_t _MaxCount);

static __inline  size_t __cdecl wcsnlen_s(         const wchar_t * _Src,      size_t _MaxCount)
{
    return wcsnlen(_Src, _MaxCount);
}
#line 260 "c:\\program files\\microsoft visual studio 8\\vc\\include\\string.h"

  errno_t __cdecl wcsncat_s(           wchar_t * _Dst,      rsize_t _DstSize,        const wchar_t * _Src,      rsize_t _MaxCount);
#line 263 "c:\\program files\\microsoft visual studio 8\\vc\\include\\string.h"

  wchar_t * __cdecl wcsncat(     wchar_t *_Dest,        const wchar_t * _Source,      size_t _Count);
  int __cdecl wcsncmp(       const wchar_t * _Str1,        const wchar_t * _Str2,      size_t _MaxCount);

  errno_t __cdecl wcsncpy_s(       wchar_t * _Dst,      rsize_t _DstSize,        const wchar_t * _Src,      rsize_t _MaxCount);
#line 269 "c:\\program files\\microsoft visual studio 8\\vc\\include\\string.h"

  wchar_t * __cdecl wcsncpy(     wchar_t *_Dest,        const wchar_t * _Source,      size_t _Count);
   wchar_t * __cdecl wcspbrk(       const wchar_t * _Str,        const wchar_t * _Control);
   wchar_t * __cdecl wcsrchr(       const wchar_t * _Str,      wchar_t _Ch);
  size_t __cdecl wcsspn(       const wchar_t * _Str,        const wchar_t * _Control);
   wchar_t * __cdecl wcsstr(       const wchar_t * _Str,        const wchar_t * _SubStr);
   wchar_t * __cdecl wcstok(           wchar_t * _Str,        const wchar_t * _Delim);
  wchar_t * __cdecl wcstok_s(           wchar_t * _Str,        const wchar_t * _Delim,                        wchar_t ** _Context);
   wchar_t * __cdecl _wcserror(     int _ErrNum);
  errno_t __cdecl _wcserror_s(         wchar_t * _Buf,      size_t _SizeInWords,      int _ErrNum);

   wchar_t * __cdecl __wcserror(         const wchar_t * _Str);
  errno_t __cdecl __wcserror_s(         wchar_t * _Buffer,      size_t _SizeInWords,        const wchar_t * _ErrMsg);


  int __cdecl _wcsicmp(       const wchar_t * _Str1,        const wchar_t * _Str2);
  int __cdecl _wcsicmp_l(       const wchar_t * _Str1,        const wchar_t * _Str2,        _locale_t _Locale);
  int __cdecl _wcsnicmp(       const wchar_t * _Str1,        const wchar_t * _Str2,      size_t _MaxCount);
  int __cdecl _wcsnicmp_l(       const wchar_t * _Str1,        const wchar_t * _Str2,      size_t _MaxCount,        _locale_t _Locale);
  wchar_t * __cdecl _wcsnset(         wchar_t * _Str,        wchar_t _Val,      size_t _MaxCount);
  errno_t __cdecl _wcsnset_s(           wchar_t * _Dst,      size_t _DstSizeInWords, wchar_t _Val,      size_t _MaxCount);
 wchar_t * __cdecl _wcsrev(         wchar_t * _Str);
  wchar_t * __cdecl _wcsset(         wchar_t * _Str, wchar_t _Val);
  errno_t __cdecl _wcsset_s(           wchar_t * _Str,      size_t _SizeInWords, wchar_t _Val);

  errno_t __cdecl _wcslwr_s(           wchar_t * _Str,      size_t _SizeInWords);

  wchar_t * __cdecl _wcslwr( wchar_t *_String);
  errno_t __cdecl _wcslwr_s_l(           wchar_t * _Str,      size_t _SizeInWords,        _locale_t _Locale);

  wchar_t * __cdecl _wcslwr_l(         wchar_t *_String,        _locale_t _Locale);
  errno_t __cdecl _wcsupr_s(           wchar_t * _Str,      size_t _Size);

  wchar_t * __cdecl _wcsupr( wchar_t *_String);
  errno_t __cdecl _wcsupr_s_l(           wchar_t * _Str,      size_t _Size,        _locale_t _Locale);

  wchar_t * __cdecl _wcsupr_l(         wchar_t *_String,        _locale_t _Locale);
  size_t __cdecl wcsxfrm(       wchar_t * _Dst,        const wchar_t * _Src,      size_t _MaxCount);
  size_t __cdecl _wcsxfrm_l(       wchar_t * _Dst,        const wchar_t *_Src,      size_t _MaxCount,        _locale_t _Locale);
  int __cdecl wcscoll(       const wchar_t * _Str1,        const wchar_t * _Str2);
  int __cdecl _wcscoll_l(       const wchar_t * _Str1,        const wchar_t * _Str2,        _locale_t _Locale);
  int __cdecl _wcsicoll(       const wchar_t * _Str1,        const wchar_t * _Str2);
  int __cdecl _wcsicoll_l(       const wchar_t * _Str1,        const wchar_t *_Str2,        _locale_t _Locale);
  int __cdecl _wcsncoll(       const wchar_t * _Str1,        const wchar_t * _Str2,      size_t _MaxCount);
  int __cdecl _wcsncoll_l(       const wchar_t * _Str1,        const wchar_t * _Str2,      size_t _MaxCount,        _locale_t _Locale);
  int __cdecl _wcsnicoll(       const wchar_t * _Str1,        const wchar_t * _Str2,      size_t _MaxCount);
  int __cdecl _wcsnicoll_l(       const wchar_t * _Str1,        const wchar_t * _Str2,      size_t _MaxCount,        _locale_t _Locale);






















#line 339 "c:\\program files\\microsoft visual studio 8\\vc\\include\\string.h"

__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_wcsdup" ". See online help for details."))   wchar_t * __cdecl wcsdup(       const wchar_t * _Str);



#line 345 "c:\\program files\\microsoft visual studio 8\\vc\\include\\string.h"





__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_wcsicmp" ". See online help for details."))   int __cdecl wcsicmp(       const wchar_t * _Str1,        const wchar_t * _Str2);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_wcsnicmp" ". See online help for details."))   int __cdecl wcsnicmp(       const wchar_t * _Str1,        const wchar_t * _Str2,      size_t _MaxCount);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_wcsnset" ". See online help for details."))  wchar_t * __cdecl wcsnset(         wchar_t * _Str,        wchar_t _Val,      size_t _MaxCount);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_wcsrev" ". See online help for details."))  wchar_t * __cdecl wcsrev(         wchar_t * _Str);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_wcsset" ". See online help for details."))  wchar_t * __cdecl wcsset(         wchar_t * _Str, wchar_t _Val);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_wcslwr" ". See online help for details."))  wchar_t * __cdecl wcslwr(         wchar_t * _Str);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_wcsupr" ". See online help for details."))  wchar_t * __cdecl wcsupr(         wchar_t * _Str);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_wcsicoll" ". See online help for details."))   int __cdecl wcsicoll(       const wchar_t * _Str1,        const wchar_t * _Str2);

#line 360 "c:\\program files\\microsoft visual studio 8\\vc\\include\\string.h"


#line 363 "c:\\program files\\microsoft visual studio 8\\vc\\include\\string.h"






#line 370 "c:\\program files\\microsoft visual studio 8\\vc\\include\\string.h"
#line 86 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\q_shared.h"
#line 1 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdlib.h"
















#pragma once
#line 19 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdlib.h"




#line 1 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"














 















































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































#line 24 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdlib.h"
#line 1 "c:\\program files\\microsoft visual studio 8\\vc\\include\\limits.h"















#pragma once
#line 18 "c:\\program files\\microsoft visual studio 8\\vc\\include\\limits.h"

#line 1 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"














 















































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































#line 20 "c:\\program files\\microsoft visual studio 8\\vc\\include\\limits.h"
















#line 37 "c:\\program files\\microsoft visual studio 8\\vc\\include\\limits.h"



















#line 57 "c:\\program files\\microsoft visual studio 8\\vc\\include\\limits.h"





#line 63 "c:\\program files\\microsoft visual studio 8\\vc\\include\\limits.h"





#line 69 "c:\\program files\\microsoft visual studio 8\\vc\\include\\limits.h"








#line 78 "c:\\program files\\microsoft visual studio 8\\vc\\include\\limits.h"








#line 87 "c:\\program files\\microsoft visual studio 8\\vc\\include\\limits.h"






#line 94 "c:\\program files\\microsoft visual studio 8\\vc\\include\\limits.h"
#line 95 "c:\\program files\\microsoft visual studio 8\\vc\\include\\limits.h"







#line 103 "c:\\program files\\microsoft visual studio 8\\vc\\include\\limits.h"
#line 104 "c:\\program files\\microsoft visual studio 8\\vc\\include\\limits.h"
































#line 137 "c:\\program files\\microsoft visual studio 8\\vc\\include\\limits.h"
#line 25 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdlib.h"






#pragma pack(push,8)
#line 33 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdlib.h"























typedef int (__cdecl * _onexit_t)(void);



#line 61 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdlib.h"



#line 65 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdlib.h"




#line 70 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdlib.h"


#line 73 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdlib.h"






typedef struct _div_t {
        int quot;
        int rem;
} div_t;

typedef struct _ldiv_t {
        long quot;
        long rem;
} ldiv_t;


#line 91 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdlib.h"










#pragma pack(4)
typedef struct {
    unsigned char ld[10];
} _LDOUBLE;
#pragma pack()













#line 120 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdlib.h"

typedef struct {
        double x;
} _CRT_DOUBLE;

typedef struct {
    float f;
} _CRT_FLOAT;





typedef struct {
        


        long double x;
} _LONGDOUBLE;



#pragma pack(4)
typedef struct {
    unsigned char ld12[12];
} _LDBL12;
#pragma pack()


#line 150 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdlib.h"














#line 165 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdlib.h"

 extern int __mb_cur_max;



#line 171 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdlib.h"
 int __cdecl ___mb_cur_max_func(void);
 int __cdecl ___mb_cur_max_l_func(_locale_t);
#line 174 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdlib.h"





































typedef void (__cdecl *_purecall_handler)(void); 


 _purecall_handler __cdecl _set_purecall_handler(       _purecall_handler _Handler);
 _purecall_handler __cdecl _get_purecall_handler();
#line 217 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdlib.h"


















#line 236 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdlib.h"



typedef void (__cdecl *_invalid_parameter_handler)(const wchar_t *, const wchar_t *, const wchar_t *, unsigned int, uintptr_t); 


 _invalid_parameter_handler __cdecl _set_invalid_parameter_handler(       _invalid_parameter_handler _Handler);
 _invalid_parameter_handler __cdecl _get_invalid_parameter_handler(void);
#line 245 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdlib.h"

















#line 263 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdlib.h"




 extern int * __cdecl _errno(void);


errno_t __cdecl _set_errno(     int _Value);
errno_t __cdecl _get_errno(     int * _Value);
#line 273 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdlib.h"

 unsigned long * __cdecl __doserrno(void);


errno_t __cdecl _set_doserrno(     unsigned long _Value);
errno_t __cdecl _get_doserrno(     unsigned long * _Value);


  char ** __cdecl __sys_errlist(void);


  int * __cdecl __sys_nerr(void);













#line 299 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdlib.h"


 extern int __argc;          
 extern char ** __argv;      
 extern wchar_t ** __wargv;  







#line 312 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdlib.h"





 extern char ** _environ;    
 extern wchar_t ** _wenviron;    
#line 320 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdlib.h"

  extern char * _pgmptr;      
  extern wchar_t * _wpgmptr;  














#line 338 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdlib.h"

errno_t __cdecl _get_pgmptr(       char ** _Value);
errno_t __cdecl _get_wpgmptr(       wchar_t ** _Value);



  extern int _fmode;          



#line 349 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdlib.h"

 errno_t __cdecl _set_fmode(     int _Mode);
 errno_t __cdecl _get_fmode(     int * _PMode);



#pragma warning(push)
#pragma warning(disable:4141)


 __declspec(deprecated("This function or variable has been superceded by newer library or operating system functionality. Consider using" "GetVersionEx" "instead. See online help for details."))	 extern unsigned int _osplatform;
 __declspec(deprecated("This function or variable has been superceded by newer library or operating system functionality. Consider using" "GetVersionEx" "instead. See online help for details."))			 extern unsigned int _osver;
 __declspec(deprecated("This function or variable has been superceded by newer library or operating system functionality. Consider using" "GetVersionEx" "instead. See online help for details."))		 extern unsigned int _winver;
 __declspec(deprecated("This function or variable has been superceded by newer library or operating system functionality. Consider using" "GetVersionEx" "instead. See online help for details."))		 extern unsigned int _winmajor;
 __declspec(deprecated("This function or variable has been superceded by newer library or operating system functionality. Consider using" "GetVersionEx" "instead. See online help for details."))		 extern unsigned int _winminor;














#line 379 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdlib.h"

#pragma warning(pop)

__declspec(deprecated("This function or variable has been superceded by newer library or operating system functionality. Consider using" "GetVersionEx" "instead. See online help for details.")) errno_t __cdecl _get_osplatform(     unsigned int * _Value);
__declspec(deprecated("This function or variable has been superceded by newer library or operating system functionality. Consider using" "GetVersionEx" "instead. See online help for details.")) errno_t __cdecl _get_osver(     unsigned int * _Value);
__declspec(deprecated("This function or variable has been superceded by newer library or operating system functionality. Consider using" "GetVersionEx" "instead. See online help for details.")) errno_t __cdecl _get_winver(     unsigned int * _Value);
__declspec(deprecated("This function or variable has been superceded by newer library or operating system functionality. Consider using" "GetVersionEx" "instead. See online help for details.")) errno_t __cdecl _get_winmajor(     unsigned int * _Value);
__declspec(deprecated("This function or variable has been superceded by newer library or operating system functionality. Consider using" "GetVersionEx" "instead. See online help for details.")) errno_t __cdecl _get_winminor(     unsigned int * _Value);












#line 400 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdlib.h"
#line 401 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdlib.h"





 __declspec(noreturn) void __cdecl exit(     int _Code);
 __declspec(noreturn) void __cdecl _exit(     int _Code);
 void __cdecl abort(void);
#line 410 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdlib.h"

 unsigned int __cdecl _set_abort_behavior(     unsigned int _Flags,      unsigned int _Mask);








        __int64    __cdecl _abs64(__int64);
#line 422 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdlib.h"










#line 433 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdlib.h"












#line 446 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdlib.h"
        int    __cdecl atexit(void (__cdecl *)(void));
#line 448 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdlib.h"





   int    __cdecl atoi(       const char *_Str);
  int    __cdecl _atoi_l(       const char *_Str,        _locale_t _Locale);
  long   __cdecl atol(       const char *_Str);
  long   __cdecl _atol_l(       const char *_Str,        _locale_t _Locale);



  void * __cdecl bsearch_s(     const void * _Key,        const void * _Base, 
             rsize_t _NumOfElements,      rsize_t _SizeOfElements,
             int (__cdecl * _PtFuncCompare)(void *, const void *, const void *), void * _Context);
#line 464 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdlib.h"
  void * __cdecl bsearch(     const void * _Key,        const void * _Base, 
             size_t _NumOfElements,      size_t _SizeOfElements,
             int (__cdecl * _PtFuncCompare)(const void *, const void *));


 void __cdecl qsort_s(       void * _Base, 
             rsize_t _NumOfElements,      rsize_t _SizeOfElements,
             int (__cdecl * _PtFuncCompare)(void *, const void *, const void *), void *_Context);
#line 473 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdlib.h"
 void __cdecl qsort(       void * _Base, 
	     size_t _NumOfElements,      size_t _SizeOfElements, 
             int (__cdecl * _PtFuncCompare)(const void *, const void *));
#line 477 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdlib.h"
         unsigned short __cdecl _byteswap_ushort(     unsigned short _Short);
         unsigned long  __cdecl _byteswap_ulong (     unsigned long _Long);

         unsigned __int64 __cdecl _byteswap_uint64(unsigned __int64 _Int64);
#line 482 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdlib.h"
  div_t  __cdecl div(     int _Numerator,      int _Denominator);
   char * __cdecl getenv(       const char * _VarName);

  errno_t __cdecl getenv_s(     size_t * _ReturnSize,        char * _DstBuf,      rsize_t _DstSize,        const char * _VarName);
#line 487 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdlib.h"

  errno_t __cdecl _dupenv_s(                     char **_PBuffer,        size_t * _PBufferSizeInBytes,        const char * _VarName);
  errno_t __cdecl _itoa_s(     int _Value,        char * _DstBuf,      size_t _Size,      int _Radix);

  char * __cdecl _itoa( int _Value,  char *_Dest,  int _Radix);

  errno_t __cdecl _i64toa_s(     __int64 _Val,        char * _DstBuf,      size_t _Size,      int _Radix);
  char * __cdecl _i64toa(     __int64 _Val,      char * _DstBuf,      int _Radix);
  errno_t __cdecl _ui64toa_s(     unsigned __int64 _Val,        char * _DstBuf,      size_t _Size,      int _Radix);
  char * __cdecl _ui64toa(     unsigned __int64 _Val,      char * _DstBuf,      int _Radix);
  __int64 __cdecl _atoi64(       const char * _String);
  __int64 __cdecl _atoi64_l(       const char * _String,        _locale_t _Locale);
  __int64 __cdecl _strtoi64(       const char * _String,                    char ** _EndPtr,      int _Radix);
  __int64 __cdecl _strtoi64_l(       const char * _String,                    char ** _EndPtr,      int _Radix,        _locale_t _Locale);
  unsigned __int64 __cdecl _strtoui64(       const char * _String,                    char ** _EndPtr,      int _Radix);
  unsigned __int64 __cdecl _strtoui64_l(       const char * _String,                    char ** _EndPtr,      int  _Radix,        _locale_t _Locale);
#line 504 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdlib.h"
  ldiv_t __cdecl ldiv(     long _Numerator,      long _Denominator);









  errno_t __cdecl _ltoa_s(     long _Val,        char * _DstBuf,      size_t _Size,      int _Radix);

  char * __cdecl _ltoa( long _Value,  char *_Dest,  int _Radix);
  int    __cdecl mblen(           const char * _Ch,      size_t _MaxCount);
  int    __cdecl _mblen_l(           const char * _Ch,      size_t _MaxCount,        _locale_t _Locale);
  size_t __cdecl _mbstrlen(       const char * _Str);
  size_t __cdecl _mbstrlen_l(       const char *_Str,        _locale_t _Locale);
  size_t __cdecl _mbstrnlen(         const char *_Str,      size_t _MaxCount);
  size_t __cdecl _mbstrnlen_l(         const char *_Str,      size_t _MaxCount,        _locale_t _Locale);
 int    __cdecl mbtowc(     wchar_t * _DstCh,            const char * _SrcCh,      size_t _SrcSizeInBytes);
 int    __cdecl _mbtowc_l(     wchar_t * _DstCh,            const char * _SrcCh,      size_t _SrcSizeInBytes,        _locale_t _Locale);
  errno_t __cdecl mbstowcs_s(       size_t * _PtNumOfCharConverted,          wchar_t * _DstBuf,      size_t _SizeInWords,          const char * _SrcBuf,      size_t _MaxCount );

  size_t __cdecl mbstowcs( wchar_t *_Dest,  const char * _Source,  size_t _MaxCount);

  errno_t __cdecl _mbstowcs_s_l(       size_t * _PtNumOfCharConverted,          wchar_t * _DstBuf,      size_t _SizeInWords,          const char * _SrcBuf,      size_t _MaxCount,        _locale_t _Locale);

  size_t __cdecl _mbstowcs_l(       wchar_t *_Dest,        const char * _Source,      size_t _MaxCount,        _locale_t _Locale);

  int    __cdecl rand(void);


#line 537 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdlib.h"

  int    __cdecl _set_error_mode(     int _Mode);

 void   __cdecl srand(     unsigned int _Seed);
  double __cdecl strtod(       const char * _Str,                    char ** _EndPtr);
  double __cdecl _strtod_l(       const char * _Str,                    char ** _EndPtr,        _locale_t _Locale);
  long   __cdecl strtol(       const char * _Str,                    char ** _EndPtr,      int _Radix );
  long   __cdecl _strtol_l(       const char *_Str,                    char **_EndPtr,      int _Radix,        _locale_t _Locale);
  unsigned long __cdecl strtoul(       const char * _Str,                    char ** _EndPtr,      int _Radix);
  unsigned long __cdecl _strtoul_l(const char * _Str,                    char **_EndPtr,      int _Radix,        _locale_t _Locale);


 int __cdecl system(         const char * _Command);
#line 551 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdlib.h"
  errno_t __cdecl _ultoa_s(     unsigned long _Val,        char * _DstBuf,      size_t _Size,      int _Radix);

  char * __cdecl _ultoa( unsigned long _Value,  char *_Dest,  int _Radix);
  int    __cdecl wctomb(         char * _MbCh,        wchar_t _WCh);
  int    __cdecl _wctomb_l(       char * _MbCh,        wchar_t _WCh,        _locale_t _Locale);

  errno_t __cdecl wctomb_s(       int * _SizeConverted,          char * _MbCh,      rsize_t _SizeInBytes,        wchar_t _WCh);
#line 559 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdlib.h"
  errno_t __cdecl _wctomb_s_l(       int * _SizeConverted,          char * _MbCh,      size_t _SizeInBytes,        wchar_t _WCh,        _locale_t _Locale);
  errno_t __cdecl wcstombs_s(       size_t * _PtNumOfCharConverted,          char * _Dst,      size_t _DstSizeInBytes,        const wchar_t * _Src,      size_t _MaxCountInBytes);

  size_t __cdecl wcstombs( char *_Dest,  const wchar_t * _Source,  size_t _MaxCount);
  errno_t __cdecl _wcstombs_s_l(       size_t * _PtNumOfCharConverted,          char * _Dst,      size_t _DstSizeInBytes,        const wchar_t * _Src,      size_t _MaxCountInBytes,        _locale_t _Locale);

  size_t __cdecl _wcstombs_l(       char *_Dest,        const wchar_t * _Source,      size_t _MaxCount,        _locale_t _Locale);






















#line 589 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdlib.h"



   __declspec(noalias) __declspec(restrict)         void * __cdecl calloc(     size_t _NumOfElements,      size_t _SizeOfElements);
                     __declspec(noalias)                                                                             void   __cdecl free(       void * _Memory);
   __declspec(noalias) __declspec(restrict)                                   void * __cdecl malloc(     size_t _Size);
                     __declspec(noalias) __declspec(restrict)                                void * __cdecl realloc(       void * _Memory,      size_t _NewSize);
                     __declspec(noalias) __declspec(restrict)                            void * __cdecl _recalloc(       void * _Memory,      size_t _Count,      size_t _Size);
                     __declspec(noalias)                                                                             void   __cdecl _aligned_free(       void * _Memory);
                     __declspec(noalias) __declspec(restrict)                                   void * __cdecl _aligned_malloc(     size_t _Size,      size_t _Alignment);
                     __declspec(noalias) __declspec(restrict)                                   void * __cdecl _aligned_offset_malloc(     size_t _Size,      size_t _Alignment,      size_t _Offset);
                     __declspec(noalias) __declspec(restrict)                                   void * __cdecl _aligned_realloc(       void * _Memory,      size_t _Size,      size_t _Alignment);
                     __declspec(noalias) __declspec(restrict)                            void * __cdecl _aligned_recalloc(       void * _Memory,      size_t _Count,      size_t _Size,      size_t _Alignment);
                     __declspec(noalias) __declspec(restrict)                                   void * __cdecl _aligned_offset_realloc(       void * _Memory,      size_t _Size,      size_t _Alignment,      size_t _Offset);
                     __declspec(noalias) __declspec(restrict)                            void * __cdecl _aligned_offset_recalloc(       void * _Memory,      size_t _Count,      size_t _Size,      size_t _Alignment,      size_t _Offset);
#line 605 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdlib.h"





  errno_t __cdecl _itow_s (     int _Val,        wchar_t * _DstBuf,      size_t _SizeInWords,      int _Radix);

  wchar_t * __cdecl _itow( int _Value,  wchar_t *_Dest,  int _Radix);
  errno_t __cdecl _ltow_s (     long _Val,        wchar_t * _DstBuf,      size_t _SizeInWords,      int _Radix);

  wchar_t * __cdecl _ltow( long _Value,  wchar_t *_Dest,  int _Radix);
  errno_t __cdecl _ultow_s (     unsigned long _Val,        wchar_t * _DstBuf,      size_t _SizeInWords,      int _Radix);

  wchar_t * __cdecl _ultow( unsigned long _Value,  wchar_t *_Dest,  int _Radix);
  double __cdecl wcstod(       const wchar_t * _Str,                    wchar_t ** _EndPtr);
  double __cdecl _wcstod_l(       const wchar_t *_Str,                    wchar_t ** _EndPtr,        _locale_t _Locale);
  long   __cdecl wcstol(       const wchar_t *_Str,                    wchar_t ** _EndPtr, int _Radix);
  long   __cdecl _wcstol_l(       const wchar_t *_Str,                    wchar_t **_EndPtr, int _Radix,        _locale_t _Locale);
  unsigned long __cdecl wcstoul(       const wchar_t *_Str,                    wchar_t ** _EndPtr, int _Radix);
  unsigned long __cdecl _wcstoul_l(       const wchar_t *_Str,                    wchar_t **_EndPtr, int _Radix,        _locale_t _Locale);
   wchar_t * __cdecl _wgetenv(       const wchar_t * _VarName);
  errno_t __cdecl _wgetenv_s(     size_t * _ReturnSize,        wchar_t * _DstBuf,      size_t _DstSizeInWords,        const wchar_t * _VarName);

  errno_t __cdecl _wdupenv_s(                     wchar_t **_Buffer,        size_t *_BufferSizeInWords,        const wchar_t *_VarName);


 int __cdecl _wsystem(         const wchar_t * _Command);
#line 633 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdlib.h"
  double __cdecl _wtof(       const wchar_t *_Str);
  double __cdecl _wtof_l(       const wchar_t *_Str,        _locale_t _Locale);
  int __cdecl _wtoi(       const wchar_t *_Str);
  int __cdecl _wtoi_l(       const wchar_t *_Str,        _locale_t _Locale);
  long __cdecl _wtol(       const wchar_t *_Str);
  long __cdecl _wtol_l(       const wchar_t *_Str,        _locale_t _Locale);


  errno_t __cdecl _i64tow_s(     __int64 _Val,        wchar_t * _DstBuf,      size_t _SizeInWords,      int _Radix);
  wchar_t * __cdecl _i64tow(     __int64 _Val,      wchar_t * _DstBuf,      int _Radix);
  errno_t __cdecl _ui64tow_s(     unsigned __int64 _Val,        wchar_t * _DstBuf,      size_t _SizeInWords,      int _Radix);
  wchar_t * __cdecl _ui64tow(     unsigned __int64 _Val,      wchar_t * _DstBuf,      int _Radix);
  __int64   __cdecl _wtoi64(       const wchar_t *_Str);
  __int64   __cdecl _wtoi64_l(       const wchar_t *_Str,        _locale_t _Locale);
  __int64   __cdecl _wcstoi64(       const wchar_t * _Str,                    wchar_t ** _EndPtr,      int _Radix);
  __int64   __cdecl _wcstoi64_l(       const wchar_t * _Str,                    wchar_t ** _EndPtr,      int _Radix,        _locale_t _Locale);
  unsigned __int64  __cdecl _wcstoui64(       const wchar_t * _Str,                    wchar_t ** _EndPtr,      int _Radix);
  unsigned __int64  __cdecl _wcstoui64_l(       const wchar_t *_Str ,                    wchar_t ** _EndPtr,      int _Radix,        _locale_t _Locale);
#line 652 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdlib.h"


#line 655 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdlib.h"












#line 668 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdlib.h"

  char * __cdecl _fullpath(         char * _FullPath,        const char * _Path,      size_t _SizeInBytes);



#line 674 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdlib.h"

  errno_t __cdecl _ecvt_s(       char * _DstBuf,      size_t _Size,      double _Val,      int _NumOfDights,      int * _PtDec,      int * _PtSign);

   char * __cdecl _ecvt(     double _Val,      int _NumOfDigits,      int * _PtDec,      int * _PtSign);
  errno_t __cdecl _fcvt_s(       char * _DstBuf,      size_t _Size,      double _Val,      int _NumOfDec,      int * _PtDec,      int * _PtSign);

   char * __cdecl _fcvt(     double _Val,      int _NumOfDec,      int * _PtDec,      int * _PtSign);
 errno_t __cdecl _gcvt_s(       char * _DstBuf,      size_t _Size,      double _Val,      int _NumOfDigits);

  char * __cdecl _gcvt(     double _Val,      int _NumOfDigits,      char * _DstBuf);

  int __cdecl _atodbl(     _CRT_DOUBLE * _Result,        char * _Str);
  int __cdecl _atoldbl(     _LDOUBLE * _Result,        char * _Str);
  int __cdecl _atoflt(     _CRT_FLOAT * _Result,        char * _Str);
  int __cdecl _atodbl_l(     _CRT_DOUBLE * _Result,        char * _Str,        _locale_t _Locale);
 int __cdecl _atoldbl_l(     _LDOUBLE * _Result,        char * _Str,        _locale_t _Locale);
 int __cdecl _atoflt_l(     _CRT_FLOAT * _Result,        char * _Str,        _locale_t _Locale);
         unsigned long __cdecl _lrotl(     unsigned long _Val,      int _Shift);
         unsigned long __cdecl _lrotr(     unsigned long _Val,      int _Shift);
  errno_t   __cdecl _makepath_s(       char * _PathResult,        size_t _Size,          const char * _Drive,          const char * _Dir,          const char * _Filename,
                 const char * _Ext);

  void __cdecl _makepath( char *_Path,  const char * _Drive,  const char * _Dir,  const char * _Filename,  const char * _Ext);












#line 710 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdlib.h"












#line 723 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdlib.h"
        _onexit_t __cdecl _onexit(       _onexit_t _Func);
#line 725 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdlib.h"
        




  int    __cdecl _putenv(       const char * _EnvString);
  errno_t __cdecl _putenv_s(       const char * _Name,        const char * _Value);
         unsigned int __cdecl _rotl(     unsigned int _Val,      int _Shift);

         unsigned __int64 __cdecl _rotl64(     unsigned __int64 _Val,      int _Shift);
#line 736 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdlib.h"
         unsigned int __cdecl _rotr(     unsigned int _Val,      int _Shift);

         unsigned __int64 __cdecl _rotr64(     unsigned __int64 _Val,      int _Shift);
#line 740 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdlib.h"
 errno_t __cdecl _searchenv_s(       const char * _Filename,        const char * _EnvVar,        char * _ResultPath,      size_t _SizeInBytes);

  void __cdecl _searchenv( const char * _Filename,  const char * _EnvVar,  char *_ResultPath);

  void   __cdecl _splitpath(       const char * _FullPath,        char * _Drive,        char * _Dir,        char * _Filename,        char * _Ext);
  errno_t  __cdecl _splitpath_s(       const char * _FullPath, 
		         char * _Drive,      size_t _DriveSize, 
		         char * _Dir,      size_t _DirSize, 
		         char * _Filename,      size_t _FilenameSize, 
		         char * _Ext,      size_t _ExtSize);


 void   __cdecl _swab(           char * _Buf1,            char * _Buf2, int _SizeInBytes);








#line 762 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdlib.h"

  wchar_t * __cdecl _wfullpath(         wchar_t * _FullPath,        const wchar_t * _Path,      size_t _SizeInWords);



#line 768 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdlib.h"

  errno_t __cdecl _wmakepath_s(       wchar_t * _PathResult,        size_t _SizeInWords,          const wchar_t * _Drive,          const wchar_t * _Dir,          const wchar_t * _Filename,
                 const wchar_t * _Ext);        

  void __cdecl _wmakepath( wchar_t *_ResultPath,  const wchar_t * _Drive,  const wchar_t * _Dir,  const wchar_t * _Filename,  const wchar_t * _Ext);




  int    __cdecl _wputenv(       const wchar_t * _EnvString);
  errno_t __cdecl _wputenv_s(       const wchar_t * _Name,        const wchar_t * _Value);
 errno_t __cdecl _wsearchenv_s(       const wchar_t * _Filename,        const wchar_t * _EnvVar,        wchar_t * _ResultPath,      size_t _SizeInWords);

  void __cdecl _wsearchenv( const wchar_t * _Filename,  const wchar_t * _EnvVar,  wchar_t *_ResultPath);
  void   __cdecl _wsplitpath(       const wchar_t * _FullPath,        wchar_t * _Drive,        wchar_t * _Dir,        wchar_t * _Filename,        wchar_t * _Ext);
 errno_t __cdecl _wsplitpath_s(       const wchar_t * _FullPath, 
		         wchar_t * _Drive,      size_t _DriveSizeInWords, 
		         wchar_t * _Dir,      size_t _DirSizeInWords, 
		         wchar_t * _Filename,      size_t _FilenameSizeInWords, 
		         wchar_t * _Ext,      size_t _ExtSizeInWords);



#line 792 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdlib.h"


__declspec(deprecated("This function or variable has been superceded by newer library or operating system functionality. Consider using" "SetErrorMode" "instead. See online help for details."))  void __cdecl _seterrormode(     int _Mode);
__declspec(deprecated("This function or variable has been superceded by newer library or operating system functionality. Consider using" "Beep" "instead. See online help for details."))  void __cdecl _beep(     unsigned _Frequency,      unsigned _Duration);
__declspec(deprecated("This function or variable has been superceded by newer library or operating system functionality. Consider using" "Sleep" "instead. See online help for details."))  void __cdecl _sleep(     unsigned long _Duration);

#line 799 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdlib.h"










#line 810 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdlib.h"





#pragma warning(push)
#pragma warning(disable: 4141)  
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_ecvt" ". See online help for details.")) 		  char * __cdecl ecvt(     double _Val,      int _NumOfDigits,      int * _PtDec,      int * _PtSign);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_fcvt" ". See online help for details.")) 		  char * __cdecl fcvt(     double _Val,      int _NumOfDec,      int * _PtDec,      int * _PtSign);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_gcvt" ". See online help for details.")) 		 char * __cdecl gcvt(     double _Val,      int _NumOfDigits,      char * _DstBuf);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_itoa" ". See online help for details.")) 		 char * __cdecl itoa(     int _Val,      char * _DstBuf,      int _Radix);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_ltoa" ". See online help for details.")) 		 char * __cdecl ltoa(     long _Val,      char * _DstBuf,      int _Radix);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_putenv" ". See online help for details.")) 									  int    __cdecl putenv(       const char * _EnvString);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_swab" ". See online help for details."))										 void   __cdecl swab(           char * _Buf1,           char * _Buf2,      int _SizeInBytes);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_ultoa" ". See online help for details.")) 	 char * __cdecl ultoa(     unsigned long _Val,      char * _Dstbuf,      int _Radix);
#pragma warning(pop)
_onexit_t __cdecl onexit(       _onexit_t _Func);

#line 829 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdlib.h"

#line 831 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdlib.h"







#pragma pack(pop)
#line 840 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdlib.h"

#line 842 "c:\\program files\\microsoft visual studio 8\\vc\\include\\stdlib.h"

#line 87 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\q_shared.h"
#line 1 "c:\\program files\\microsoft visual studio 8\\vc\\include\\time.h"
















#pragma once
#line 19 "c:\\program files\\microsoft visual studio 8\\vc\\include\\time.h"




#line 1 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"














 















































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































#line 24 "c:\\program files\\microsoft visual studio 8\\vc\\include\\time.h"



#line 28 "c:\\program files\\microsoft visual studio 8\\vc\\include\\time.h"







#pragma pack(push,8)
#line 37 "c:\\program files\\microsoft visual studio 8\\vc\\include\\time.h"












#line 50 "c:\\program files\\microsoft visual studio 8\\vc\\include\\time.h"
















#line 67 "c:\\program files\\microsoft visual studio 8\\vc\\include\\time.h"




























typedef long clock_t;

#line 98 "c:\\program files\\microsoft visual studio 8\\vc\\include\\time.h"





















struct tm {
        int tm_sec;     
        int tm_min;     
        int tm_hour;    
        int tm_mday;    
        int tm_mon;     
        int tm_year;    
        int tm_wday;    
        int tm_yday;    
        int tm_isdst;   
        };

#line 132 "c:\\program files\\microsoft visual studio 8\\vc\\include\\time.h"












   int* __cdecl __daylight(void);



   long* __cdecl __dstbias(void);



   long* __cdecl __timezone(void);



          char ** __cdecl __tzname(void);


 errno_t __cdecl _get_daylight(     int * _Daylight);
 errno_t __cdecl _get_dstbias(     long * _Daylight_savings_bias);
 errno_t __cdecl _get_timezone(     long * _Timezone);
 errno_t __cdecl _get_tzname(     size_t *_ReturnValue,        char *_Buffer,      size_t _SizeInBytes,      int _Index);



   char * __cdecl asctime(     const struct tm * _Tm);

  errno_t __cdecl asctime_s(       char *_Buf,      size_t _SizeInBytes,      const struct tm * _Tm);
#line 170 "c:\\program files\\microsoft visual studio 8\\vc\\include\\time.h"


  char * __cdecl _ctime32(     const __time32_t * _Time);
 errno_t __cdecl _ctime32_s(       char *_Buf,      size_t _SizeInBytes,      const __time32_t *_Time);


  clock_t __cdecl clock(void);
 double __cdecl _difftime32(     __time32_t _Time1,      __time32_t _Time2);

   struct tm * __cdecl _gmtime32(     const __time32_t * _Time);
  errno_t __cdecl _gmtime32_s(     struct tm *_Tm,      const __time32_t * _Time);

  struct tm * __cdecl _localtime32(     const __time32_t * _Time);
 errno_t __cdecl _localtime32_s(     struct tm *_Tm,      const __time32_t * _Time);

 size_t __cdecl strftime(       char * _Buf,      size_t _SizeInBytes,         const char * _Format,      const struct tm * _Tm);
 size_t __cdecl _strftime_l(     char *_Buf,      size_t _Max_size,         const char * _Format,      const struct tm *_Tm,        _locale_t _Locale);

  errno_t __cdecl _strdate_s(       char *_Buf,      size_t _SizeInBytes);

  char * __cdecl _strdate( char *_Buffer);

  errno_t __cdecl _strtime_s(       char *_Buf ,      size_t _SizeInBytes);

  char * __cdecl _strtime( char *_Buffer);

 __time32_t __cdecl _time32(       __time32_t * _Time);
 __time32_t __cdecl _mktime32(     struct tm * _Tm);
 __time32_t __cdecl _mkgmtime32(     struct tm * _Tm);




 void __cdecl _tzset(void);
#line 205 "c:\\program files\\microsoft visual studio 8\\vc\\include\\time.h"


  double __cdecl _difftime64(     __time64_t _Time1,      __time64_t _Time2);
  char * __cdecl _ctime64(     const __time64_t * _Time);
 errno_t __cdecl _ctime64_s(       char *_Buf,      size_t _SizeInBytes,      const __time64_t * _Time);


  struct tm * __cdecl _gmtime64(     const __time64_t * _Time);
 errno_t __cdecl _gmtime64_s(     struct tm *_Tm,      const __time64_t *_Time);

  struct tm * __cdecl _localtime64(     const __time64_t * _Time);
 errno_t __cdecl _localtime64_s(     struct tm *_Tm,      const __time64_t *_Time);

 __time64_t __cdecl _mktime64(     struct tm * _Tm);
 __time64_t __cdecl _mkgmtime64(     struct tm * _Tm);
 __time64_t __cdecl _time64(       __time64_t * _Time);
#line 222 "c:\\program files\\microsoft visual studio 8\\vc\\include\\time.h"


__declspec(deprecated("This function or variable has been superceded by newer library or operating system functionality. Consider using" "GetLocalTime" "instead. See online help for details.")) unsigned __cdecl _getsystime(     struct tm * _Tm);
__declspec(deprecated("This function or variable has been superceded by newer library or operating system functionality. Consider using" "SetLocalTime" "instead. See online help for details.")) unsigned __cdecl _setsystime(     struct tm * _Tm, unsigned _MilliSec);










 
  wchar_t * __cdecl _wasctime(     const struct tm * _Tm);
 errno_t __cdecl _wasctime_s(       wchar_t *_Buf,      size_t _SizeInWords,      const struct tm * _Tm);


  wchar_t * __cdecl _wctime32(     const __time32_t *_Time);
 errno_t __cdecl _wctime32_s(       wchar_t* _Buf,      size_t _SizeInWords,      const __time32_t * _Time);


 size_t __cdecl wcsftime(       wchar_t * _Buf,      size_t _SizeInWords,         const wchar_t * _Format,       const struct tm * _Tm);
 size_t __cdecl _wcsftime_l(       wchar_t * _Buf,      size_t _SizeInWords,         const wchar_t *_Format,      const struct tm *_Tm,        _locale_t _Locale);

 errno_t __cdecl _wstrdate_s(       wchar_t * _Buf,      size_t _SizeInWords);

  wchar_t * __cdecl _wstrdate( wchar_t *_Buffer);

 errno_t __cdecl _wstrtime_s(       wchar_t * _Buf,      size_t _SizeInWords);

  wchar_t * __cdecl _wstrtime( wchar_t *_Buffer);


  wchar_t * __cdecl _wctime64(     const __time64_t * _Time);
 errno_t __cdecl _wctime64_s(       wchar_t* _Buf,      size_t _SizeInWords,      const __time64_t *_Time);

#line 261 "c:\\program files\\microsoft visual studio 8\\vc\\include\\time.h"


#line 1 "c:\\program files\\microsoft visual studio 8\\vc\\include\\wtime.inl"













#pragma once
#line 16 "c:\\program files\\microsoft visual studio 8\\vc\\include\\wtime.inl"







#line 24 "c:\\program files\\microsoft visual studio 8\\vc\\include\\wtime.inl"





#pragma warning(push)
#pragma warning(disable:4996)


static __inline wchar_t * __cdecl _wctime(const time_t * _Time)
{
#pragma warning( push )
#pragma warning( disable : 4996 )
    return _wctime32(_Time);
#pragma warning( pop )
}

static __inline errno_t __cdecl _wctime_s(wchar_t *_Buffer, size_t _SizeInWords, const time_t * _Time)
{
    return _wctime32_s(_Buffer, _SizeInWords, _Time);
}













#line 59 "c:\\program files\\microsoft visual studio 8\\vc\\include\\wtime.inl"

#pragma warning(pop)

#line 63 "c:\\program files\\microsoft visual studio 8\\vc\\include\\wtime.inl"
#line 64 "c:\\program files\\microsoft visual studio 8\\vc\\include\\wtime.inl"
#line 264 "c:\\program files\\microsoft visual studio 8\\vc\\include\\time.h"
#line 265 "c:\\program files\\microsoft visual studio 8\\vc\\include\\time.h"


#line 268 "c:\\program files\\microsoft visual studio 8\\vc\\include\\time.h"


#line 1 "c:\\program files\\microsoft visual studio 8\\vc\\include\\time.inl"













#pragma once
#line 16 "c:\\program files\\microsoft visual studio 8\\vc\\include\\time.inl"







#line 24 "c:\\program files\\microsoft visual studio 8\\vc\\include\\time.inl"






static __inline double __cdecl difftime(time_t _Time1, time_t _Time2)
{
    return _difftime32(_Time1,_Time2);
}
 static __inline char * __cdecl ctime(const time_t * _Time)
{
#pragma warning( push )
#pragma warning( disable : 4996 )
    return _ctime32(_Time);
#pragma warning( pop )
}

static __inline errno_t __cdecl ctime_s(char *_Buffer, size_t _SizeInBytes, const time_t * _Time)
{
    return _ctime32_s(_Buffer, _SizeInBytes, _Time);
}
#line 47 "c:\\program files\\microsoft visual studio 8\\vc\\include\\time.inl"
 static __inline struct tm * __cdecl gmtime(const time_t * _Time)
{
#pragma warning( push )
#pragma warning( disable : 4996 )
    return _gmtime32(_Time);
#pragma warning( pop )
}

static __inline errno_t __cdecl gmtime_s(struct tm * _Tm, const time_t * _Time)
{
    return _gmtime32_s(_Tm, _Time);
}
#line 60 "c:\\program files\\microsoft visual studio 8\\vc\\include\\time.inl"
 static __inline struct tm * __cdecl localtime(const time_t * _Time)
{
#pragma warning( push )
#pragma warning( disable : 4996 )
    return _localtime32(_Time);
#pragma warning( pop )
}
static __inline errno_t __cdecl localtime_s(struct tm * _Tm, const time_t * _Time)
{
    return _localtime32_s(_Tm, _Time);
}
static __inline time_t __cdecl mktime(struct tm * _Tm)
{
    return _mktime32(_Tm);
}
static __inline time_t __cdecl _mkgmtime(struct tm * _Tm)
{
    return _mkgmtime32(_Tm);
}
static __inline time_t __cdecl time(time_t * _Time)
{
    return _time32(_Time);
}






















































#line 138 "c:\\program files\\microsoft visual studio 8\\vc\\include\\time.inl"


#line 141 "c:\\program files\\microsoft visual studio 8\\vc\\include\\time.inl"
#line 142 "c:\\program files\\microsoft visual studio 8\\vc\\include\\time.inl"
#line 271 "c:\\program files\\microsoft visual studio 8\\vc\\include\\time.h"
#line 272 "c:\\program files\\microsoft visual studio 8\\vc\\include\\time.h"













  extern int daylight;
  extern long timezone;
  extern char * tzname[2];
#line 289 "c:\\program files\\microsoft visual studio 8\\vc\\include\\time.h"

__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_tzset" ". See online help for details."))  void __cdecl tzset(void);

#line 293 "c:\\program files\\microsoft visual studio 8\\vc\\include\\time.h"







#pragma pack(pop)
#line 302 "c:\\program files\\microsoft visual studio 8\\vc\\include\\time.h"

#line 304 "c:\\program files\\microsoft visual studio 8\\vc\\include\\time.h"
#line 88 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\q_shared.h"
#line 1 "c:\\program files\\microsoft visual studio 8\\vc\\include\\ctype.h"














#pragma once
#line 17 "c:\\program files\\microsoft visual studio 8\\vc\\include\\ctype.h"




#line 1 "c:\\program files\\microsoft visual studio 8\\vc\\include\\crtdefs.h"














 















































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































#line 22 "c:\\program files\\microsoft visual studio 8\\vc\\include\\ctype.h"
















#line 39 "c:\\program files\\microsoft visual studio 8\\vc\\include\\ctype.h"

#line 41 "c:\\program files\\microsoft visual studio 8\\vc\\include\\ctype.h"
#line 42 "c:\\program files\\microsoft visual studio 8\\vc\\include\\ctype.h"

 const unsigned short * __cdecl __pctype_func(void);

 extern const unsigned short *_pctype;


#line 49 "c:\\program files\\microsoft visual studio 8\\vc\\include\\ctype.h"
#line 50 "c:\\program files\\microsoft visual studio 8\\vc\\include\\ctype.h"
#line 51 "c:\\program files\\microsoft visual studio 8\\vc\\include\\ctype.h"





 extern const unsigned short _wctype[];
#line 58 "c:\\program files\\microsoft visual studio 8\\vc\\include\\ctype.h"

 const wctype_t * __cdecl __pwctype_func(void);

 extern const wctype_t *_pwctype;


#line 65 "c:\\program files\\microsoft visual studio 8\\vc\\include\\ctype.h"
#line 66 "c:\\program files\\microsoft visual studio 8\\vc\\include\\ctype.h"
#line 67 "c:\\program files\\microsoft visual studio 8\\vc\\include\\ctype.h"


#line 70 "c:\\program files\\microsoft visual studio 8\\vc\\include\\ctype.h"










                                













  int __cdecl _isctype(     int _C,      int _Type);
  int __cdecl _isctype_l(     int _C,      int _Type,        _locale_t _Locale);
   int __cdecl isalpha(     int _C);
  int __cdecl _isalpha_l(     int _C,        _locale_t _Locale);
   int __cdecl isupper(     int _C);
  int __cdecl _isupper_l(     int _C,        _locale_t _Locale);
   int __cdecl islower(     int _C);
  int __cdecl _islower_l(     int _C,        _locale_t _Locale);
   int __cdecl isdigit(     int _C);
  int __cdecl _isdigit_l(     int _C,        _locale_t _Locale);
  int __cdecl isxdigit(     int _C);
  int __cdecl _isxdigit_l(     int _C,        _locale_t _Locale);
   int __cdecl isspace(     int _C);
  int __cdecl _isspace_l(     int _C,        _locale_t _Locale);
  int __cdecl ispunct(     int _C);
  int __cdecl _ispunct_l(     int _C,        _locale_t _Locale);
   int __cdecl isalnum(     int _C);
  int __cdecl _isalnum_l(     int _C,        _locale_t _Locale);
  int __cdecl isprint(     int _C);
  int __cdecl _isprint_l(     int _C,        _locale_t _Locale);
  int __cdecl isgraph(     int _C);
  int __cdecl _isgraph_l(     int _C,        _locale_t _Locale);
  int __cdecl iscntrl(     int _C);
  int __cdecl _iscntrl_l(     int _C,        _locale_t _Locale);
   int __cdecl toupper(     int _C);
   int __cdecl tolower(     int _C);
   int __cdecl _tolower(     int _C);
  int __cdecl _tolower_l(     int _C,        _locale_t _Locale);
   int __cdecl _toupper(     int _C);
  int __cdecl _toupper_l(     int _C,        _locale_t _Locale);
  int __cdecl __isascii(     int _C);
  int __cdecl __toascii(     int _C);
  int __cdecl __iscsymf(     int _C);
  int __cdecl __iscsym(     int _C);

#line 130 "c:\\program files\\microsoft visual studio 8\\vc\\include\\ctype.h"







  int __cdecl iswalpha(     wint_t _C);
  int __cdecl _iswalpha_l(     wint_t _C,        _locale_t _Locale);
  int __cdecl iswupper(     wint_t _C);
  int __cdecl _iswupper_l(     wint_t _C,        _locale_t _Locale);
  int __cdecl iswlower(     wint_t _C);
  int __cdecl _iswlower_l(     wint_t _C,        _locale_t _Locale);
  int __cdecl iswdigit(     wint_t _C);
  int __cdecl _iswdigit_l(     wint_t _C,        _locale_t _Locale);
  int __cdecl iswxdigit(     wint_t _C);
  int __cdecl _iswxdigit_l(     wint_t _C,        _locale_t _Locale);
  int __cdecl iswspace(     wint_t _C);
  int __cdecl _iswspace_l(     wint_t _C,        _locale_t _Locale);
  int __cdecl iswpunct(     wint_t _C);
  int __cdecl _iswpunct_l(     wint_t _C,        _locale_t _Locale);
  int __cdecl iswalnum(     wint_t _C);
  int __cdecl _iswalnum_l(     wint_t _C,        _locale_t _Locale);
  int __cdecl iswprint(     wint_t _C);
  int __cdecl _iswprint_l(     wint_t _C,        _locale_t _Locale);
  int __cdecl iswgraph(     wint_t _C);
  int __cdecl _iswgraph_l(     wint_t _C,        _locale_t _Locale);
  int __cdecl iswcntrl(     wint_t _C);
  int __cdecl _iswcntrl_l(     wint_t _C,        _locale_t _Locale);
  int __cdecl iswascii(     wint_t _C);
  int __cdecl isleadbyte(     int _C);
  int __cdecl _isleadbyte_l(     int _C,        _locale_t _Locale);

  wint_t __cdecl towupper(     wint_t _C);
  wint_t __cdecl _towupper_l(     wint_t _C,        _locale_t _Locale);
  wint_t __cdecl towlower(     wint_t _C);
  wint_t __cdecl _towlower_l(     wint_t _C,        _locale_t _Locale); 
  int __cdecl iswctype(     wint_t _C,      wctype_t _Type);
  int __cdecl _iswctype_l(     wint_t _C,      wctype_t _Type,        _locale_t _Locale);

  int __cdecl __iswcsymf(     wint_t _C);
  int __cdecl _iswcsymf_l(     wint_t _C,        _locale_t _Locale);
  int __cdecl __iswcsym(     wint_t _C);
  int __cdecl _iswcsym_l(     wint_t _C,        _locale_t _Locale);

__declspec(deprecated("This function or variable has been superceded by newer library or operating system functionality. Consider using" "iswctype" "instead. See online help for details."))  int __cdecl is_wctype(     wint_t _C,      wctype_t _Type);


#line 179 "c:\\program files\\microsoft visual studio 8\\vc\\include\\ctype.h"






























 int __cdecl _chvalidator(     int _Ch,      int _Mask);



#line 214 "c:\\program files\\microsoft visual studio 8\\vc\\include\\ctype.h"












































#line 259 "c:\\program files\\microsoft visual studio 8\\vc\\include\\ctype.h"


int __cdecl _chvalidator_l(       _locale_t,      int _Ch,      int _Mask);



#line 266 "c:\\program files\\microsoft visual studio 8\\vc\\include\\ctype.h"













































































#line 344 "c:\\program files\\microsoft visual studio 8\\vc\\include\\ctype.h"

#line 346 "c:\\program files\\microsoft visual studio 8\\vc\\include\\ctype.h"













#line 360 "c:\\program files\\microsoft visual studio 8\\vc\\include\\ctype.h"
















#line 377 "c:\\program files\\microsoft visual studio 8\\vc\\include\\ctype.h"

#line 379 "c:\\program files\\microsoft visual studio 8\\vc\\include\\ctype.h"





#line 385 "c:\\program files\\microsoft visual studio 8\\vc\\include\\ctype.h"
#line 89 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\q_shared.h"



























#line 117 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\q_shared.h"





#line 123 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\q_shared.h"






#line 130 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\q_shared.h"



#line 134 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\q_shared.h"

#line 136 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\q_shared.h"





short   ShortSwap (short l);
int		LongSwap (int l);
float	FloatSwap (const float *f);






















#line 167 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\q_shared.h"
#line 168 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\q_shared.h"



static __inline short BigShort( short l) { return ShortSwap(l); }

static __inline int BigLong(int l) { return LongSwap(l); }

static __inline float BigFloat(const float *l) { FloatSwap(l); }




#line 181 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\q_shared.h"





















































#line 235 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\q_shared.h"


















































































































typedef unsigned char 		byte;
typedef unsigned short		word;
typedef unsigned long		ulong;

typedef enum {qfalse, qtrue}	qboolean;




typedef int		qhandle_t;
typedef int		thandle_t; 
typedef int		fxHandle_t;
typedef int		sfxHandle_t;
typedef int		fileHandle_t;
typedef int		clipHandle_t;


































#line 399 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\q_shared.h"






typedef enum {
	EXEC_NOW,			
						
	EXEC_INSERT,		
	EXEC_APPEND			
} cbufExec_t;














#line 426 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\q_shared.h"


enum WL_e {
	WL_ERROR=1,
	WL_WARNING,
	WL_VERBOSE,
	WL_DEBUG
};

extern float forceSpeedLevels[4];


typedef enum {
	PRINT_ALL,
	PRINT_DEVELOPER,		
	PRINT_WARNING,
	PRINT_ERROR
} printParm_t;







typedef enum {
	ERR_FATAL,					
	ERR_DROP,					
	ERR_SERVERDISCONNECT,		
	ERR_DISCONNECT,				
	ERR_NEED_CD					
} errorParm_t;











































	
#line 503 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\q_shared.h"

typedef enum {
	h_high,
	h_low,
	h_dontcare
} ha_pref;

void *Hunk_Alloc( int size, ha_pref preference );

void Com_Memset (void* dest, const int val, const size_t count);
void Com_Memcpy (void* dest, const void* src, const size_t count);
















typedef float vec_t;
typedef vec_t vec2_t[2];
typedef vec_t vec3_t[3];
typedef vec_t vec4_t[4];
typedef vec_t vec5_t[5];


typedef vec3_t	vec3pair_t[2];

typedef int ivec3_t[3];
typedef int ivec4_t[4];
typedef int ivec5_t[5];

typedef	int	fixed4_t;
typedef	int	fixed8_t;
typedef	int	fixed16_t;



#line 550 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\q_shared.h"


typedef enum {
	BLK_NO,
	BLK_TIGHT,		
	BLK_WIDE		
} saberBlockType_t;

typedef enum {
	BLOCKED_NONE,
	BLOCKED_BOUNCE_MOVE,
	BLOCKED_PARRY_BROKEN,
	BLOCKED_ATK_BOUNCE,
	BLOCKED_UPPER_RIGHT,
	BLOCKED_UPPER_LEFT,
	BLOCKED_LOWER_RIGHT,
	BLOCKED_LOWER_LEFT,
	BLOCKED_TOP,
	BLOCKED_UPPER_RIGHT_PROJ,
	BLOCKED_UPPER_LEFT_PROJ,
	BLOCKED_LOWER_RIGHT_PROJ,
	BLOCKED_LOWER_LEFT_PROJ,
	BLOCKED_TOP_PROJ
} saberBlockedType_t;



typedef enum
{
	SABER_RED,
	SABER_ORANGE,
	SABER_YELLOW,
	SABER_GREEN,
	SABER_BLUE,
	SABER_PURPLE,
	NUM_SABER_COLORS

};
typedef int saber_colors_t;

typedef enum
{
	FP_FIRST = 0,
	FP_HEAL = 0,
	FP_LEVITATION,
	FP_SPEED,
	FP_PUSH,
	FP_PULL,
	FP_TELEPATHY,
	FP_GRIP,
	FP_LIGHTNING,
	FP_RAGE,
	FP_PROTECT,
	FP_ABSORB,
	FP_TEAM_HEAL,
	FP_TEAM_FORCE,
	FP_DRAIN,
	FP_SEE,
	FP_SABER_OFFENSE,
	FP_SABER_DEFENSE,
	FP_SABERTHROW,
	NUM_FORCE_POWERS
};
typedef int forcePowers_t;

typedef enum
{
	SABER_NONE = 0,
	SABER_SINGLE,
	SABER_STAFF,
	SABER_DAGGER,
	SABER_BROAD,
	SABER_PRONG,
	SABER_ARC,
	SABER_SAI,
	SABER_CLAW,
	SABER_LANCE,
	SABER_STAR,
	SABER_TRIDENT,
	SABER_SITH_SWORD,
	NUM_SABERS
} saberType_t;

typedef struct 
{
	
	int		inAction;	
	int		duration;	
	int		lastTime;	
	vec3_t	base;
	vec3_t	tip;

	vec3_t	dualbase;
	vec3_t	dualtip;

	
	qboolean	haveOldPos[2];
	vec3_t		oldPos[2];		
	vec3_t		oldNormal[2];	
							
} saberTrail_t;

typedef struct
{
	qboolean	active;
	saber_colors_t	color;
	float		radius;
	float		length;
	float		lengthMax;
	float		lengthOld;
	float		desiredLength;
	vec3_t		muzzlePoint;
	vec3_t		muzzlePointOld;
	vec3_t		muzzleDir;
	vec3_t		muzzleDirOld;
	saberTrail_t	trail;
	int			hitWallDebounceTime;
	int			storageTime;
	int			extendDebounce;
} bladeInfo_t;


typedef enum
{
	SS_NONE = 0,
	SS_FAST,
	SS_MEDIUM,
	SS_STRONG,
	SS_DESANN,
	SS_TAVION,
	SS_DUAL,
	SS_STAFF,
	SS_NUM_SABER_STYLES
	
} saber_styles_t;



















































typedef struct
{
	char		name[64];						
	char		fullName[64];				
	saberType_t	type;						
	char		model[64];						
	qhandle_t	skin;						
	int			soundOn;					
	int			soundLoop;					
	int			soundOff;					
	int			numBlades;
	bladeInfo_t	blade[8];			
	int			stylesLearned;				
	int			stylesForbidden;			
	int			maxChain;					
	int			forceRestrictions;			
	int			lockBonus;					
	int			parryBonus;					
	int			breakParryBonus;			
	int			breakParryBonus2;			
	int			disarmBonus;				
	int			disarmBonus2;				
	saber_styles_t	singleBladeStyle;		



	
	int			saberFlags;					
	int			saberFlags2;				

	
	qhandle_t	spinSound;					
	qhandle_t	swingSound[3];				

	
	float		moveSpeedScale;				
	float		animSpeedScale;				

	
	int	kataMove;				
	int	lungeAtkMove;			
	int	jumpAtkUpMove;			
	int	jumpAtkFwdMove;			
	int	jumpAtkBackMove;		
	int	jumpAtkRightMove;		
	int	jumpAtkLeftMove;		
	int	readyAnim;				
	int	drawAnim;				
	int	putawayAnim;			
	int	tauntAnim;				
	int	bowAnim;				
	int	meditateAnim;			
	int	flourishAnim;			
	int	gloatAnim;				

	
	int			bladeStyle2Start;			

	
	
	
	
	int			trailStyle;					
	int			g2MarksShader;				
	int			g2WeaponMarkShader;			
	
	
	qhandle_t	hitSound[3];				
	qhandle_t	blockSound[3];				
	qhandle_t	bounceSound[3];				
	int			blockEffect;				
	int			hitPersonEffect;			
	int			hitOtherEffect;				
	int			bladeEffect;				

	
	float		knockbackScale;				
	float		damageScale;				
	float		splashRadius;				
	int			splashDamage;				
	float		splashKnockback;			
	
	
	
	int			trailStyle2;				
	int			g2MarksShader2;				
	int			g2WeaponMarkShader2;		
	
	
	qhandle_t	hit2Sound[3];				
	qhandle_t	block2Sound[3];				
	qhandle_t	bounce2Sound[3];			
	int			blockEffect2;				
	int			hitPersonEffect2;			
	int			hitOtherEffect2;			
	int			bladeEffect2;				

	
	float		knockbackScale2;			
	float		damageScale2;				
	float		splashRadius2;				
	int			splashDamage2;				
	float		splashKnockback2;			


} saberInfo_t;


typedef enum
{
	FORCE_LEVEL_0,
	FORCE_LEVEL_1,
	FORCE_LEVEL_2,
	FORCE_LEVEL_3,
	NUM_FORCE_POWER_LEVELS
};





enum sharedERagPhase
{
	RP_START_DEATH_ANIM,
	RP_END_DEATH_ANIM,
	RP_DEATH_COLLISION,
	RP_CORPSE_SHOT,
	RP_GET_PELVIS_OFFSET,  
	RP_SET_PELVIS_OFFSET,  
	RP_DISABLE_EFFECTORS  
};

enum sharedERagEffector
{
	RE_MODEL_ROOT=			0x00000001, 
	RE_PELVIS=				0x00000002, 
	RE_LOWER_LUMBAR=		0x00000004, 
	RE_UPPER_LUMBAR=		0x00000008, 
	RE_THORACIC=			0x00000010, 
	RE_CRANIUM=				0x00000020, 
	RE_RHUMEROUS=			0x00000040, 
	RE_LHUMEROUS=			0x00000080, 
	RE_RRADIUS=				0x00000100, 
	RE_LRADIUS=				0x00000200, 
	RE_RFEMURYZ=			0x00000400, 
	RE_LFEMURYZ=			0x00000800, 
	RE_RTIBIA=				0x00001000, 
	RE_LTIBIA=				0x00002000, 
	RE_RHAND=				0x00004000, 
	RE_LHAND=				0x00008000, 
	RE_RTARSAL=				0x00010000, 
	RE_LTARSAL=				0x00020000, 
	RE_RTALUS=				0x00040000, 
	RE_LTALUS=				0x00080000, 
	RE_RRADIUSX=			0x00100000, 
	RE_LRADIUSX=			0x00200000, 
	RE_RFEMURX=				0x00400000, 
	RE_LFEMURX=				0x00800000, 
	RE_CEYEBROW=			0x01000000 
};

typedef struct
{
	vec3_t angles;
	vec3_t position;
	vec3_t scale;
	vec3_t pelvisAnglesOffset;    
	vec3_t pelvisPositionOffset; 

	float fImpactStrength; 
	float fShotStrength; 
	int me; 

	
	int startFrame;
	int endFrame;

	int collisionType; 

	qboolean CallRagDollBegin; 

	int RagPhase;



	int effectorsToTurnOff;  

} sharedRagDollParams_t;


typedef struct
{
	vec3_t angles;
	vec3_t position;
	vec3_t scale;
	vec3_t velocity;
	int	me;
	int settleFrame;
} sharedRagDollUpdateParams_t;


typedef struct
{
	char boneName[512]; 
	vec3_t desiredOrigin; 
	vec3_t origin; 
	float movementSpeed; 
} sharedIKMoveParams_t;


typedef struct
{
	vec3_t pcjMins; 
	vec3_t pcjMaxs; 
	vec3_t origin; 
	vec3_t angles; 
	vec3_t scale; 
	float radius; 
	int blendTime; 
	int pcjOverrides; 
	int startFrame; 
	int endFrame; 
	qboolean forceAnimOnBone; 
} sharedSetBoneIKStateParams_t;

enum sharedEIKMoveState
{
	IKS_NONE = 0,
	IKS_DYNAMIC
};


typedef enum 
{
	MAT_METAL = 0,	
	MAT_GLASS,		
	MAT_ELECTRICAL,	
	MAT_ELEC_METAL,	
	MAT_DRK_STONE,	
	MAT_LT_STONE,	
	MAT_GLASS_METAL,
	MAT_METAL2,		
	MAT_NONE,		
	MAT_GREY_STONE,	
	MAT_METAL3,		
	MAT_CRATE1,		
	MAT_GRATE1,		
	MAT_ROPE,		
	MAT_CRATE2,		
	MAT_WHITE_METAL,
	MAT_SNOWY_ROCK,	

	NUM_MATERIALS

};
typedef int material_t;










typedef struct wpneighbor_s
{
	int num;
	int forceJumpTo;
} wpneighbor_t;

typedef struct wpobject_s
{
	vec3_t origin;
	int inuse;
	int index;
	float weight;
	float disttonext;
	int flags;
	int associated_entity;

	int forceJumpTo;

	int neighbornum;
	wpneighbor_t neighbors[32];
} wpobject_t;



extern	vec3_t	bytedirs[162];


















typedef enum
{
CT_NONE,
CT_BLACK,
CT_RED,
CT_GREEN,
CT_BLUE,
CT_YELLOW,
CT_MAGENTA,
CT_CYAN,
CT_WHITE,
CT_LTGREY,
CT_MDGREY,
CT_DKGREY,
CT_DKGREY2,

CT_VLTORANGE,
CT_LTORANGE,
CT_DKORANGE,
CT_VDKORANGE,

CT_VLTBLUE1,
CT_LTBLUE1,
CT_DKBLUE1,
CT_VDKBLUE1,

CT_VLTBLUE2,
CT_LTBLUE2,
CT_DKBLUE2,
CT_VDKBLUE2,

CT_VLTBROWN1,
CT_LTBROWN1,
CT_DKBROWN1,
CT_VDKBROWN1,

CT_VLTadmin_number1,
CT_LTadmin_number1,
CT_DKadmin_number1,
CT_VDKadmin_number1,

CT_VLTPURPLE1,
CT_LTPURPLE1,
CT_DKPURPLE1,
CT_VDKPURPLE1,

CT_VLTPURPLE2,
CT_LTPURPLE2,
CT_DKPURPLE2,
CT_VDKPURPLE2,

CT_VLTPURPLE3,
CT_LTPURPLE3,
CT_DKPURPLE3,
CT_VDKPURPLE3,

CT_VLTRED1,
CT_LTRED1,
CT_DKRED1,
CT_VDKRED1,
CT_VDKRED,
CT_DKRED,

CT_VLTAQUA,
CT_LTAQUA,
CT_DKAQUA,
CT_VDKAQUA,

CT_LTPINK,
CT_DKPINK,
CT_LTCYAN,
CT_DKCYAN,
CT_LTBLUE3,
CT_BLUE3,
CT_DKBLUE3,

CT_HUD_GREEN,
CT_HUD_RED,
CT_ICON_BLUE,
CT_NO_AMMO_RED,
CT_HUD_ORANGE,

CT_MAX
} ct_table_t;

extern vec4_t colorTable[CT_MAX];

extern	vec4_t		colorBlack;
extern	vec4_t		colorRed;
extern	vec4_t		colorGreen;
extern	vec4_t		colorBlue;
extern	vec4_t		colorYellow;
extern	vec4_t		colorMagenta;
extern	vec4_t		colorCyan;
extern	vec4_t		colorWhite;
extern	vec4_t		colorLtGrey;
extern	vec4_t		colorMdGrey;
extern	vec4_t		colorDkGrey;
extern	vec4_t		colorLtBlue;
extern	vec4_t		colorDkBlue;

























extern vec4_t	g_color_table[8];







struct cplane_s;

extern	vec3_t	vec3_origin;
extern	vec3_t	axisDefault[3];



















































#line 1234 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\q_shared.h"
float Q_fabs( float f );
float Q_rsqrt( float f );		
#line 1237 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\q_shared.h"



signed char ClampChar( int i );
signed short ClampShort( int i );




int DirToByte( vec3_t dir );
void ByteToDir( int b, vec3_t dir );



















































































































#line 1364 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\q_shared.h"




















#line 1385 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\q_shared.h"
























static __inline void SnapVector( float *v )
{
	static int i;
	static float f;

	f = *v;
	__asm	fld		f;
	__asm	fistp	i;
	*v = i;
	v++;
	f = *v;
	__asm	fld		f;
	__asm	fistp	i;
	*v = i;
	v++;
	f = *v;
	__asm	fld		f;
	__asm	fistp	i;
	*v = i;
}


#line 1432 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\q_shared.h"
#line 1433 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\q_shared.h"


vec_t _DotProduct( const vec3_t v1, const vec3_t v2 );
void _VectorSubtract( const vec3_t veca, const vec3_t vecb, vec3_t out );
void _VectorAdd( const vec3_t veca, const vec3_t vecb, vec3_t out );
void _VectorCopy( const vec3_t in, vec3_t out );
void _VectorScale( const vec3_t in, float scale, vec3_t out );
void _VectorMA( const vec3_t veca, float scale, const vec3_t vecb, vec3_t vecc );

unsigned ColorBytes3 (float r, float g, float b);
unsigned ColorBytes4 (float r, float g, float b, float a);

float NormalizeColor( const vec3_t in, vec3_t out );

float RadiusFromBounds( const vec3_t mins, const vec3_t maxs );
void ClearBounds( vec3_t mins, vec3_t maxs );
vec_t DistanceHorizontal( const vec3_t p1, const vec3_t p2 );
vec_t DistanceHorizontalSquared( const vec3_t p1, const vec3_t p2 );
void AddPointToBounds( const vec3_t v, vec3_t mins, vec3_t maxs );


static __inline int VectorCompare( const vec3_t v1, const vec3_t v2 ) {
	if (v1[0] != v2[0] || v1[1] != v2[1] || v1[2] != v2[2]) {
		return 0;
	}			
	return 1;
}

static __inline vec_t VectorLength( const vec3_t v ) {


























	return (vec_t)sqrt (v[0]*v[0] + v[1]*v[1] + v[2]*v[2]);
#line 1490 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\q_shared.h"
}

static __inline vec_t VectorLengthSquared( const vec3_t v ) {
























	return (v[0]*v[0] + v[1]*v[1] + v[2]*v[2]);
#line 1519 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\q_shared.h"
}

static __inline vec_t Distance( const vec3_t p1, const vec3_t p2 ) {
	vec3_t	v;

	((v)[0]=(p2)[0]-(p1)[0],(v)[1]=(p2)[1]-(p1)[1],(v)[2]=(p2)[2]-(p1)[2]);
	return VectorLength( v );
}

static __inline vec_t DistanceSquared( const vec3_t p1, const vec3_t p2 ) {
	vec3_t	v;

	((v)[0]=(p2)[0]-(p1)[0],(v)[1]=(p2)[1]-(p1)[1],(v)[2]=(p2)[2]-(p1)[2]);
	return v[0]*v[0] + v[1]*v[1] + v[2]*v[2];
}



static __inline void VectorNormalizeFast( vec3_t v )
{
	float ilength;

	ilength = Q_rsqrt( ((v)[0]*(v)[0]+(v)[1]*(v)[1]+(v)[2]*(v)[2]) );

	v[0] *= ilength;
	v[1] *= ilength;
	v[2] *= ilength;
}

static __inline void VectorInverse( vec3_t v ){
	v[0] = -v[0];
	v[1] = -v[1];
	v[2] = -v[2];
}

static __inline void CrossProduct( const vec3_t v1, const vec3_t v2, vec3_t cross ) {
	cross[0] = v1[1]*v2[2] - v1[2]*v2[1];
	cross[1] = v1[2]*v2[0] - v1[0]*v2[2];
	cross[2] = v1[0]*v2[1] - v1[1]*v2[0];
}


















#line 1578 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\q_shared.h"

vec_t VectorNormalize (vec3_t v);		
vec_t VectorNormalize2( const vec3_t v, vec3_t out );
void Vector4Scale( const vec4_t in, vec_t scale, vec4_t out );
void VectorRotate( vec3_t in, vec3_t matrix[3], vec3_t out );
int Q_log2(int val);

float Q_acos(float c);
float Q_asin(float c);

int		Q_rand( int *seed );
float	Q_random( int *seed );
float	Q_crandom( int *seed );




void vectoangles( const vec3_t value1, vec3_t angles);
void AnglesToAxis( const vec3_t angles, vec3_t axis[3] );

void AxisClear( vec3_t axis[3] );
void AxisCopy( vec3_t in[3], vec3_t out[3] );

void SetPlaneSignbits( struct cplane_s *out );
int BoxOnPlaneSide (vec3_t emins, vec3_t emaxs, struct cplane_s *plane);

double	fmod( double x, double y );
float	AngleMod(float a);
float	LerpAngle (float from, float to, float frac);
float	AngleSubtract( float a1, float a2 );
void	AnglesSubtract( vec3_t v1, vec3_t v2, vec3_t v3 );

float AngleNormalize360 ( float angle );
float AngleNormalize180 ( float angle );
float AngleDelta ( float angle1, float angle2 );

qboolean PlaneFromPoints( vec4_t plane, const vec3_t a, const vec3_t b, const vec3_t c );
void ProjectPointOnPlane( vec3_t dst, const vec3_t p, const vec3_t normal );
void RotatePointAroundVector( vec3_t dst, const vec3_t dir, const vec3_t point, float degrees );
void RotateAroundDirection( vec3_t axis[3], float yaw );
void MakeNormalVectors( const vec3_t forward, vec3_t right, vec3_t up );




void MatrixMultiply(float in1[3][3], float in2[3][3], float out[3][3]);
void AngleVectors( const vec3_t angles, vec3_t forward, vec3_t right, vec3_t up);
void PerpendicularVector( vec3_t dst, const vec3_t src );
void NormalToLatLong( const vec3_t normal, byte bytes[2] ); 



int Com_Clampi( int min, int max, int value ); 
float Com_Clamp( float min, float max, float value );

char	*COM_SkipPath( char *pathname );
void	COM_StripExtension( const char *in, char *out );
void	COM_DefaultExtension( char *path, int maxSize, const char *extension );

void	COM_BeginParseSession( const char *name );
int		COM_GetCurrentParseLine( void );
const char	*SkipWhitespace( const char *data, qboolean *hasNewLines );
char	*COM_Parse( const char **data_p );
char	*COM_ParseExt( const char **data_p, qboolean allowLineBreak );
int		COM_Compress( char *data_p );
void	COM_ParseError( char *format, ... );
void	COM_ParseWarning( char *format, ... );
qboolean COM_ParseString( const char **data, const char **s );
qboolean COM_ParseInt( const char **data, int *i );
qboolean COM_ParseFloat( const char **data, float *f );
qboolean COM_ParseVec4( const char **buffer, vec4_t *c);











#line 1661 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\q_shared.h"

typedef struct pc_token_s
{
	int type;
	int subtype;
	int intvalue;
	float floatvalue;
	char string[1024];
} pc_token_t;



void	COM_MatchToken( const char**buf_p, char *match );

void SkipBracedSection (const char **program);
void SkipRestOfLine ( const char **data );

void Parse1DMatrix (const char **buf_p, int x, float *m);
void Parse2DMatrix (const char **buf_p, int y, int x, float *m);
void Parse3DMatrix (const char **buf_p, int z, int y, int x, float *m);

void	__cdecl Com_sprintf (char *dest, int size, const char *fmt, ...);



typedef enum {
	FS_READ,
	FS_WRITE,
	FS_APPEND,
	FS_APPEND_SYNC
} fsMode_t;

typedef enum {
	FS_SEEK_CUR,
	FS_SEEK_END,
	FS_SEEK_SET
} fsOrigin_t;



int Q_isprint( int c );
int Q_islower( int c );
int Q_isupper( int c );
int Q_isalpha( int c );


int		Q_stricmp (const char *s1, const char *s2);
int		Q_strncmp (const char *s1, const char *s2, int n);
int		Q_stricmpn (const char *s1, const char *s2, int n);
char	*Q_strlwr( char *s1 );
char	*Q_strupr( char *s1 );
char	*Q_strrchr( const char* string, int c );


void	Q_strncpyz( char *dest, const char *src, int destsize );
void	Q_strcat( char *dest, int size, const char *src );


int Q_PrintStrlen( const char *string );

char *Q_CleanStr( char *string );





typedef struct
{
	byte	b0;
	byte	b1;
	byte	b2;
	byte	b3;
	byte	b4;
	byte	b5;
	byte	b6;
	byte	b7;
} qint64;














char	* __cdecl va(const char *format, ...);






char *Info_ValueForKey( const char *s, const char *key );
void Info_RemoveKey( char *s, const char *key );
void Info_RemoveKey_big( char *s, const char *key );
void Info_SetValueForKey( char *s, const char *key, const char *value );
void Info_SetValueForKey_Big( char *s, const char *key, const char *value );
qboolean Info_Validate( const char *s );
void Info_NextPair( const char **s, char *key, char *value );


void	__cdecl Com_Error( int level, const char *error, ... );
void	__cdecl Com_Printf( const char *msg, ... );














											
											




											

											
											
											
											









typedef struct cvar_s {
	char		*name;
	char		*string;
	char		*resetString;		
	char		*latchedString;		
	int			flags;
	qboolean	modified;			
	int			modificationCount;	
	float		value;				
	int			integer;			
	struct cvar_s *next;
	struct cvar_s *hashNext;
} cvar_t;



typedef int	cvarHandle_t;



typedef struct {
	cvarHandle_t	handle;
	int			modificationCount;
	float		value;
	int			integer;
	char		string[256];
} vmCvar_t;









#line 1 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\surfaceflags.h"


























































































































#line 1842 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\q_shared.h"



















typedef struct cplane_s {
	vec3_t	normal;
	float	dist;
	byte	type;			
	byte	signbits;		
	byte	pad[2];
} cplane_t;



typedef struct
{
	float		mDistance;
	int			mEntityNum;
	int			mModelIndex;
	int			mPolyIndex;
	int			mSurfaceIndex;
	vec3_t		mCollisionPosition;
	vec3_t		mCollisionNormal;
	int			mFlags;
	int			mMaterial;
	int			mLocation;
	float		mBarycentricI; 
	float		mBarycentricJ; 
}CollisionRecord_t;



typedef CollisionRecord_t G2Trace_t[16];	





typedef struct {
	byte		allsolid;	
	byte		startsolid;	
	short		entityNum;	

	float		fraction;	
	vec3_t		endpos;		
	cplane_t	plane;		
	int			surfaceFlags;	
	int			contents;	



	




} trace_t;






typedef struct {
	int		firstPoint;
	int		numPoints;
} markFragment_t;



typedef struct {
	vec3_t		origin;
	vec3_t		axis[3];
} orientation_t;















typedef enum {
	CHAN_AUTO,	
	CHAN_LOCAL,	
	CHAN_WEAPON,
	CHAN_VOICE, 
	CHAN_VOICE_ATTEN, 
	CHAN_ITEM,  
	CHAN_BODY,	
	CHAN_AMBIENT,
	CHAN_LOCAL_SOUND,	
	CHAN_ANNOUNCER,		
	CHAN_LESS_ATTEN,	
	CHAN_MENU1,		
	CHAN_VOICE_GLOBAL,  
	CHAN_MUSIC,	
};
typedef int soundChannel_t;
























#line 1988 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\q_shared.h"








#line 1997 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\q_shared.h"



















































typedef struct {
	int			stringOffsets[1700];
	char		stringData[16000];
	int			dataCount;
} gameState_t;




typedef enum {
	TRACK_CHANNEL_NONE = 50,
	TRACK_CHANNEL_1,
	TRACK_CHANNEL_2,
	TRACK_CHANNEL_3,
	TRACK_CHANNEL_4,
	TRACK_CHANNEL_5,
	NUM_TRACK_CHANNELS
} trackchan_t;



typedef struct forcedata_s {
	int			forcePowerDebounce[NUM_FORCE_POWERS];	
	int			forcePowersKnown;
	int			forcePowersActive;
	int			forcePowerSelected;
	int			forceButtonNeedRelease;
	int			forcePowerDuration[NUM_FORCE_POWERS];
	int			forcePower;
	int			forcePowerMax;
	int			forcePowerRegenDebounceTime;
	int			forcePowerLevel[NUM_FORCE_POWERS];		
	int			forcePowerBaseLevel[NUM_FORCE_POWERS];
	int			forceUsingAdded;
	float		forceJumpZStart;					
	float		forceJumpCharge;					
	int			forceJumpSound;
	int			forceJumpAddTime;
	int			forceGripEntityNum;					
	int			forceGripDamageDebounceTime;		
	float		forceGripBeingGripped;				
	int			forceGripCripple;					
	int			forceGripUseTime;					
	float		forceGripSoundTime;
	float		forceGripStarted;					
	int			forceHealTime;
	int			forceHealAmount;

	
	int			forceMindtrickTargetIndex; 
	int			forceMindtrickTargetIndex2; 
	int			forceMindtrickTargetIndex3; 
	int			forceMindtrickTargetIndex4; 

	int			forceRageRecoveryTime;
	int			forceDrainEntNum;
	float		forceDrainTime;

	int			forceDoInit;

	int			forceSide;
	int			forceRank;

	int			forceDeactivateAll;

	int			killSoundEntIndex[(NUM_TRACK_CHANNELS-50)]; 

	qboolean	sentryDeployed;

	int			saberAnimLevelBase;
	int			saberAnimLevel;
	int			saberDrawAnimLevel;

	int			suicides;

	int			privateDuelTime;
} forcedata_t;


typedef enum {
	SENTRY_NOROOM = 1,
	SENTRY_ALREADYPLACED,
	SHIELD_NOROOM,
	SEEKER_ALREADYDEPLOYED
} itemUseFail_t;





































typedef struct playerState_s {
	int			commandTime;	
	int			pm_type;
	int			bobCycle;		
	int			pm_flags;		
	int			pm_time;

	vec3_t		origin;
	vec3_t		velocity;

	vec3_t		moveDir; 

	int			weaponTime;
	int			weaponChargeTime;
	int			weaponChargeSubtractTime;
	int			gravity;
	float		speed;
	int			basespeed; 
	int			delta_angles[3];	
									

	int			slopeRecalcTime; 

	int			useTime;

	int			groundEntityNum;

	int			legsTimer;		
	int			legsAnim;

	int			torsoTimer;		
	int			torsoAnim;

	qboolean	legsFlip; 
	qboolean	torsoFlip;

	int			movementDir;	
								
								
								

	int			eFlags;			
	int			eFlags2;		

	int			eventSequence;	
	int			events[2];
	int			eventParms[2];

	int			externalEvent;	
	int			externalEventParm;
	int			externalEventTime;

	int			clientNum;		
	int			weapon;			
	int			weaponstate;

	vec3_t		viewangles;		
	int			viewheight;

	
	int			damageEvent;	
	int			damageYaw;
	int			damagePitch;
	int			damageCount;
	int			damageType;

	int			painTime;		
	int			painDirection;	
	float		yawAngle;		
	qboolean	yawing;			
	float		pitchAngle;		
	qboolean	pitching;		

	int			stats[16];
	int			persistant[16];	
	int			powerups[16];	
	int			ammo[19];

	int			generic1;
	int			loopSound;
	int			jumppad_ent;	

	
	int			ping;			
	int			pmove_framecount;	
	int			jumppad_frame;
	int			entityEventSequence;

	int			lastOnGround;	

	qboolean	saberInFlight;

	int			saberMove;
	int			saberBlocking;
	int			saberBlocked;

	int			saberLockTime;
	int			saberLockEnemy;
	int			saberLockFrame; 
	int			saberLockHits; 
	int			saberLockHitCheckTime; 
	int			saberLockHitIncrementTime; 
	qboolean	saberLockAdvance; 

	int			saberEntityNum;
	float		saberEntityDist;
	int			saberEntityState;
	int			saberThrowDelay;
	qboolean	saberCanThrow;
	int			saberDidThrowTime;
	int			saberDamageDebounceTime;
	int			saberHitWallSoundDebounceTime;
	int			saberEventFlags;

	int			rocketLockIndex;
	float		rocketLastValidTime;
	float		rocketLockTime;
	float		rocketTargetTime;

	int			emplacedIndex;
	float		emplacedTime;

	qboolean	isJediMaster;
	qboolean	forceRestricted;
	qboolean	trueJedi;
	qboolean	trueNonJedi;
	int			saberIndex;

	int			genericEnemyIndex;
	float		droneFireTime;
	float		droneExistTime;

	int			activeForcePass;

	qboolean	hasDetPackPlanted; 

	float		holocronsCarried[NUM_FORCE_POWERS];
	int			holocronCantTouch;
	float		holocronCantTouchTime; 
	int			holocronBits;

	int			electrifyTime;

	int			saberAttackSequence;
	int			saberIdleWound;
	int			saberAttackWound;
	int			saberBlockTime;

	int			otherKiller;
	int			otherKillerTime;
	int			otherKillerDebounceTime;

	forcedata_t	fd;
	qboolean	forceJumpFlip;
	int			forceHandExtend;
	int			forceHandExtendTime;

	int			forceRageDrainTime;

	int			forceDodgeAnim;
	qboolean	quickerGetup;

	int			groundTime;		

	int			footstepTime;

	int			otherSoundTime;
	float		otherSoundLen;

	int			forceGripMoveInterval;
	int			forceGripChangeMovetype;

	int			forceKickFlip;

	int			duelIndex;
	int			duelTime;
	qboolean	duelInProgress;

	int			saberAttackChainCount;

	int			saberHolstered;

	int			forceAllowDeactivateTime;

	
	int			zoomMode;		
	int			zoomTime;
	qboolean	zoomLocked;
	float		zoomFov;
	int			zoomLockTime;

	int			fallingToDeath;

	int			useDelay;

	qboolean	inAirAnim;

	vec3_t		lastHitLoc;

	int			heldByClient; 

	int			ragAttach; 

	int			iModelScale;

	int			brokenLimbs;

	
	qboolean	hasLookTarget;
	int			lookTarget;

	signed int			customRGBA[4];

	int			standheight;
	int			crouchheight;

	
	int			m_iVehicleNum;

	
	vec3_t		vehOrientation;
	qboolean	vehBoarding;
	int			vehSurfaces;

	
	int			vehTurnaroundIndex;
	int			vehTurnaroundTime;

	
	qboolean	vehWeaponsLinked;

	
	int			hyperSpaceTime;
	vec3_t		hyperSpaceAngles;

	
	int			hackingTime;
	
	
	
	int			hackingBaseTime;

	
	int			jetpackFuel;

	
	int			cloakFuel;

	
	
	

	int			userInt1;
	int			userInt2;
	int			userInt3;
	float		userFloat1;
	float		userFloat2;
	float		userFloat3;
	vec3_t		userVec1;
	vec3_t		userVec2;






} playerState_t;

typedef struct siegePers_s
{
	qboolean	beatingTime;
	int			lastTeam;
	int			lastTime;
} siegePers_t;













										
										
										
										


























										

typedef enum
{
	GENCMD_SABERSWITCH = 1,
	GENCMD_ENGAGE_DUEL,
	GENCMD_FORCE_HEAL,
	GENCMD_FORCE_SPEED,
	GENCMD_FORCE_THROW,
	GENCMD_FORCE_PULL,
	GENCMD_FORCE_DISTRACT,
	GENCMD_FORCE_RAGE,
	GENCMD_FORCE_PROTECT,
	GENCMD_FORCE_ABSORB,
	GENCMD_FORCE_HEALOTHER,
	GENCMD_FORCE_FORCEPOWEROTHER,
	GENCMD_FORCE_SEEING,
	GENCMD_USE_SEEKER,
	GENCMD_USE_FIELD,
	GENCMD_USE_BACTA,
	GENCMD_USE_ELECTROBINOCULARS,
	GENCMD_ZOOM,
	GENCMD_USE_SENTRY,
	GENCMD_USE_JETPACK,
	GENCMD_USE_BACTABIG,
	GENCMD_USE_HEALTHDISP,
	GENCMD_USE_AMMODISP,
	GENCMD_USE_EWEB,
	GENCMD_USE_CLOAK,
	GENCMD_SABERATTACKCYCLE,
	GENCMD_TAUNT,
	GENCMD_BOW,
	GENCMD_MEDITATE,
	GENCMD_FLOURISH,
	GENCMD_GLOAT
} genCmds_t;


typedef struct usercmd_s {
	int				serverTime;
	int				angles[3];
	int 			buttons;
	byte			weapon;           
	byte			forcesel;
	byte			invensel;
	byte			generic_cmd;
	signed char	forwardmove, rightmove, upmove;
} usercmd_t;




typedef struct addpolyArgStruct_s {
	vec3_t				p[4];
	vec2_t				ev[4];
	int					numVerts;
	vec3_t				vel;
	vec3_t				accel;
	float				alpha1;
	float				alpha2;
	float				alphaParm;
	vec3_t				rgb1;
	vec3_t				rgb2;
	float				rgbParm;
	vec3_t				rotationDelta;
	float				bounce;
	int					motionDelay;
	int					killTime;
	qhandle_t			shader;
	int					flags;
} addpolyArgStruct_t;

typedef struct addbezierArgStruct_s {
	vec3_t start;
	vec3_t end;
	vec3_t control1;
	vec3_t control1Vel;
	vec3_t control2;
	vec3_t control2Vel;
	float size1;
	float size2;
	float sizeParm;
	float alpha1;
	float alpha2;
	float alphaParm;
	vec3_t sRGB;
	vec3_t eRGB;
	float rgbParm;
	int killTime;
	qhandle_t shader;
	int flags;
} addbezierArgStruct_t;

typedef struct addspriteArgStruct_s
{
	vec3_t origin;
	vec3_t vel;
	vec3_t accel;
	float scale;
	float dscale;
	float sAlpha;
	float eAlpha;
	float rotation;
	float bounce;
	int life;
	qhandle_t shader;
	int flags;
} addspriteArgStruct_t;

typedef struct
{
	vec3_t	origin;

	
	vec3_t	rgb;
	vec3_t	destrgb;
	vec3_t	curRGB;

	float	alpha;
	float	destAlpha;
	float	curAlpha;

	
	
	float	ST[2];
	float	destST[2];
	float	curST[2];
} effectTrailVertStruct_t;



typedef struct effectTrailArgStruct_s {
	effectTrailVertStruct_t		mVerts[4];
	qhandle_t					mShader;
	int							mSetFlags;
	int							mKillTime;
} effectTrailArgStruct_t;

typedef struct
{
	vec3_t start;
	vec3_t end;
	float size1;
	float size2;
	float sizeParm;
	float alpha1;
	float alpha2;
	float alphaParm;
	vec3_t sRGB;
	vec3_t eRGB;
	float rgbParm;
	float chaos;
	int killTime;
	qhandle_t shader;
	int flags;
} addElectricityArgStruct_t;




typedef enum {
	TR_STATIONARY,
	TR_INTERPOLATE,				
	TR_LINEAR,
	TR_LINEAR_STOP,
	TR_NONLINEAR_STOP,
	TR_SINE,					
	TR_GRAVITY
} trType_t;

typedef struct {
	trType_t	trType;
	int		trTime;
	int		trDuration;			
	vec3_t	trBase;
	vec3_t	trDelta;			
} trajectory_t;









typedef struct entityState_s {
	int		number;			
	int		eType;			
	int		eFlags;
	int		eFlags2;		

	trajectory_t	pos;	
	trajectory_t	apos;	

	int		time;
	int		time2;

	vec3_t	origin;
	vec3_t	origin2;

	vec3_t	angles;
	vec3_t	angles2;

	
	
	int		bolt1;
	int		bolt2;

	
	int		trickedentindex; 
	int		trickedentindex2; 
	int		trickedentindex3; 
	int		trickedentindex4; 

	float	speed;

	int		fireflag;

	int		genericenemyindex;

	int		activeForcePass;

	int		emplacedOwner;

	int		otherEntityNum;	
	int		otherEntityNum2;

	int		groundEntityNum;	

	int		constantLight;	
	int		loopSound;		
	qboolean	loopIsSoundset; 

	int		soundSetIndex;

	int		modelGhoul2;
	int		g2radius;
	int		modelindex;
	int		modelindex2;
	int		clientNum;		
	int		frame;

	qboolean	saberInFlight;
	int			saberEntityNum;
	int			saberMove;
	int			forcePowersActive;
	int			saberHolstered;

	qboolean	isJediMaster;

	qboolean	isPortalEnt; 

	int		solid;			

	int		event;			
	int		eventParm;

	
	int			owner;
	int			teamowner;
	qboolean	shouldtarget;

	
	int		powerups;		
	int		weapon;			
	int		legsAnim;
	int		torsoAnim;

	qboolean	legsFlip; 
	qboolean	torsoFlip;

	int		forceFrame;		

	int		generic1;

	int		heldByClient; 

	int		ragAttach; 

	int		iModelScale; 

	int		brokenLimbs;

	int		boltToPlayer; 

	
	qboolean	hasLookTarget;
	int			lookTarget;

	int			customRGBA[4];

	
	
	int			health;
	int			maxhealth; 

	
	
	int		npcSaber1;
	int		npcSaber2;

	
	
	int		csSounds_Std;
	int		csSounds_Combat;
	int		csSounds_Extra;
	int		csSounds_Jedi;

	int		surfacesOn; 
	int		surfacesOff; 

	
	
	
	int		boneIndex1;
	int		boneIndex2;
	int		boneIndex3;
	int		boneIndex4;

	
	int		boneOrient;

	
	
	
	
	vec3_t	boneAngles1; 
	vec3_t	boneAngles2; 
	vec3_t	boneAngles3; 
	vec3_t	boneAngles4; 

	int		NPC_class; 

	
	int		m_iVehicleNum;

	
	
	
	int			userInt1;
	int			userInt2;
	int			userInt3;
	float		userFloat1;
	float		userFloat2;
	float		userFloat3;
	vec3_t		userVec1;
	vec3_t		userVec2;
} entityState_t;




























































































































































#line 2993 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\q_shared.h"

typedef enum {
	CA_UNINITIALIZED,
	CA_DISCONNECTED, 	
	CA_AUTHORIZING,		
	CA_CONNECTING,		
	CA_CHALLENGING,		
	CA_CONNECTED,		
	CA_LOADING,			
	CA_PRIMED,			
	CA_ACTIVE,			
	CA_CINEMATIC		
} connstate_t;








typedef struct qtime_s {
	int tm_sec;     
	int tm_min;     
	int tm_hour;    
	int tm_mday;    
	int tm_mon;     
	int tm_year;    
	int tm_wday;    
	int tm_yday;    
	int tm_isdst;   
} qtime_t;










typedef enum {
	FMV_IDLE,
	FMV_PLAY,		
	FMV_EOF,		
	FMV_ID_BLT,
	FMV_ID_IDLE,
	FMV_LOOPED,
	FMV_ID_WAIT
};
typedef int e_status;

typedef enum _flag_status {
	FLAG_ATBASE = 0,
	FLAG_TAKEN,			
	FLAG_TAKEN_RED,		
	FLAG_TAKEN_BLUE,	
	FLAG_DROPPED
};
typedef int flagStatus_t;









#line 3064 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\q_shared.h"










void Rand_Init(int seed);
float flrand(float min, float max);
int irand(int min, int max);
int Q_irand(int value1, int value2);





typedef struct {
	float		matrix[3][4];
} mdxaBone_t;



typedef enum Eorientations
{
	ORIGIN = 0, 
	POSITIVE_X,
	POSITIVE_Z,
	POSITIVE_Y,
	NEGATIVE_X,
	NEGATIVE_Z,
	NEGATIVE_Y
};








typedef enum {
	#line 1 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\qcommon\\tags.h"






	TAG_ALL,
	TAG_BOTLIB,
	TAG_CLIENTS,					

	TAG_BOTGAME,
	TAG_DOWNLOAD,					
	TAG_GENERAL,
	TAG_CLIPBOARD,					
	TAG_SND_MP3STREAMHDR,			
	TAG_SND_DYNAMICMUSIC,			
	TAG_BSP_DISKIMAGE,				
	TAG_VM,							
	TAG_SPECIAL_MEM_TEST,			
#line 21 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\qcommon\\tags.h"
	TAG_HUNK_MARK1,					
	TAG_HUNK_MARK2,					
	TAG_EVENT,
	TAG_FILESYS,					
	TAG_GHOUL2,						
	TAG_GHOUL2_GORE,				
	TAG_LISTFILES,					
	TAG_AMBIENTSET,
	TAG_STATIC,						
	TAG_SMALL,						
	TAG_MODEL_MD3,					
	TAG_MODEL_GLM,					
	TAG_MODEL_GLA,					
	TAG_ICARUS,						
	
	TAG_ICARUS2,					
	TAG_ICARUS3,					
	TAG_ICARUS4,					
	TAG_ICARUS5,					
	TAG_SHADERTEXT,
	TAG_SND_RAWDATA,				
	TAG_TEMP_WORKSPACE,				
	TAG_TEMP_PNG,					
	TAG_TEXTPOOL,					
	TAG_IMAGE_T,					
    TAG_INFLATE,                                
    TAG_DEFLATE,                                
	TAG_BSP,						
	TAG_GRIDMESH,					

	
	TAG_POINTCACHE,					
	TAG_TERRAIN,					
	TAG_R_TERRAIN,					
	TAG_RESAMPLE,					
	TAG_CM_TERRAIN,					
	TAG_CM_TERRAIN_TEMP,			
	TAG_TEMP_IMAGE,					

	TAG_VM_ALLOCATED,				

	TAG_TEMP_HUNKALLOC,








	TAG_COUNT




#line 3109 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\q_shared.h"
};
typedef char memtag_t;




typedef struct SSkinGoreData_s
{
	vec3_t			angles;
	vec3_t			position;
	int				currentTime;
	int				entNum;
	vec3_t			rayDirection;	
	vec3_t			hitLocation;	
	vec3_t			scale;
	float			SSize;			
	float			TSize;			
	float			theta;			

	
	int				growDuration;			
	float			goreScaleStartFraction; 

	qboolean		frontFaces;
	qboolean		backFaces;
	qboolean		baseModelOnly;
	int				lifeTime;				
	int				fadeOutTime;			
	int				shrinkOutTime;			
	float			alphaModulate;			
	vec3_t			tint;					
	float			impactStrength;			

	int				shader; 

	int				myIndex; 

	qboolean		fadeRGB; 
} SSkinGoreData;









typedef struct stringID_table_s
{
	char	*name;
	int		id;
} stringID_table_t;

int GetIDForString ( stringID_table_t *table, const char *string );
const char *GetStringForID( stringID_table_t *table, int id );




typedef enum
{
	eForceReload_NOTHING,

	eForceReload_MODELS,
	eForceReload_ALL

} ForceReload_e;


enum {
	FONT_NONE,
	FONT_SMALL=1,
	FONT_MEDIUM,
	FONT_LARGE,
	FONT_SMALL2
};



#line 3190 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\q_shared.h"

#line 6 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\g_local.h"
#line 1 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\bg_public.h"










#line 1 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\bg_weapons.h"







typedef enum {
	WP_NONE,

	WP_STUN_BATON,
	WP_MELEE,
	WP_SABER,
	WP_BRYAR_PISTOL,
	WP_BLASTER,
	WP_DISRUPTOR,
	WP_BOWCASTER,
	WP_REPEATER,
	WP_DEMP2,
	WP_FLECHETTE,
	WP_ROCKET_LAUNCHER,
	WP_THERMAL,
	WP_TRIP_MINE,
	WP_DET_PACK,
	WP_CONCUSSION,
	WP_BRYAR_OLD,
	WP_EMPLACED_GUN,
	WP_TURRET,









	WP_NUM_WEAPONS
};
typedef int weapon_t;




typedef enum 
{
	AMMO_NONE,
	AMMO_FORCE,		
	AMMO_BLASTER,	
	AMMO_POWERCELL,	
	AMMO_METAL_BOLTS,
	AMMO_ROCKETS,
	AMMO_EMPLACED,
	AMMO_THERMAL,
	AMMO_TRIPMINE,
	AMMO_DETPACK,
	AMMO_MAX
} ammo_t;


typedef struct weaponData_s
{


	int		ammoIndex;			
	int		ammoLow;			

	int		energyPerShot;		
	int		fireTime;			
	int		range;				
	
	int		altEnergyPerShot;	
	int		altFireTime;		
	int		altRange;			

	int		chargeSubTime;		
	int		altChargeSubTime;	

	int		chargeSub;			
	int		altChargeSub;		

	int		maxCharge;			
	int		altMaxCharge;		
} weaponData_t;


typedef struct  ammoData_s
{

	int		max;		
} ammoData_t;


extern weaponData_t weaponData[WP_NUM_WEAPONS];
extern ammoData_t ammoData[AMMO_MAX];

















#line 114 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\bg_weapons.h"
#line 12 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\bg_public.h"
#line 1 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\anims.h"





typedef enum 
{
	
	
	
	
	FACE_TALK0,			
	FACE_TALK1,			
	FACE_TALK2,			
	FACE_TALK3,			
	FACE_TALK4,			
	FACE_ALERT,				
	FACE_SMILE,				
	FACE_FROWN,				
	FACE_DEAD,				

	
	
	
	
	BOTH_DEATH1,		
	BOTH_DEATH2,			
	BOTH_DEATH3,			
	BOTH_DEATH4,			
	BOTH_DEATH5,			
	BOTH_DEATH6,			
	BOTH_DEATH7,			
	BOTH_DEATH8,			
	BOTH_DEATH9,			
	BOTH_DEATH10,			
	BOTH_DEATH11,			
	BOTH_DEATH12,			
	BOTH_DEATH13,			
	BOTH_DEATH14,			
	BOTH_DEATH15,			
	BOTH_DEATH16,			
	BOTH_DEATH17,			
	BOTH_DEATH18,			
	BOTH_DEATH19,			
	BOTH_DEATH20,			
	BOTH_DEATH21,			
	BOTH_DEATH22,			
	BOTH_DEATH23,			
	BOTH_DEATH24,			
	BOTH_DEATH25,			

	BOTH_DEATHFORWARD1,		
	BOTH_DEATHFORWARD2,		
	BOTH_DEATHFORWARD3,		
	BOTH_DEATHBACKWARD1,	
	BOTH_DEATHBACKWARD2,	

	BOTH_DEATH1IDLE,		
	BOTH_LYINGDEATH1,		
	BOTH_STUMBLEDEATH1,		
	BOTH_FALLDEATH1,		
	BOTH_FALLDEATH1INAIR,	
	BOTH_FALLDEATH1LAND,	
	BOTH_DEATH_ROLL,		
	BOTH_DEATH_FLIP,		
	BOTH_DEATH_SPIN_90_R,	
	BOTH_DEATH_SPIN_90_L,	
	BOTH_DEATH_SPIN_180,	
	BOTH_DEATH_LYING_UP,	
	BOTH_DEATH_LYING_DN,	
	BOTH_DEATH_FALLING_DN,	
	BOTH_DEATH_FALLING_UP,	
	BOTH_DEATH_CROUCHED,	
	
	BOTH_DEAD1,				
	BOTH_DEAD2,				
	BOTH_DEAD3,				
	BOTH_DEAD4,				
	BOTH_DEAD5,				
	BOTH_DEAD6,				
	BOTH_DEAD7,				
	BOTH_DEAD8,				
	BOTH_DEAD9,				
	BOTH_DEAD10,			
	BOTH_DEAD11,			
	BOTH_DEAD12,			
	BOTH_DEAD13,			
	BOTH_DEAD14,			
	BOTH_DEAD15,			
	BOTH_DEAD16,			
	BOTH_DEAD17,			
	BOTH_DEAD18,			
	BOTH_DEAD19,			
	BOTH_DEAD20,			
	BOTH_DEAD21,			
	BOTH_DEAD22,			
	BOTH_DEAD23,			
	BOTH_DEAD24,			
	BOTH_DEAD25,			
	BOTH_DEADFORWARD1,		
	BOTH_DEADFORWARD2,		
	BOTH_DEADBACKWARD1,		
	BOTH_DEADBACKWARD2,		
	BOTH_LYINGDEAD1,		
	BOTH_STUMBLEDEAD1,		
	BOTH_FALLDEAD1LAND,		
	
	BOTH_DEADFLOP1,		
	BOTH_DEADFLOP2,		
	BOTH_DISMEMBER_HEAD1,	
	BOTH_DISMEMBER_TORSO1,	
	BOTH_DISMEMBER_LLEG,	
	BOTH_DISMEMBER_RLEG,	
	BOTH_DISMEMBER_RARM,	
	BOTH_DISMEMBER_LARM,	
	
	BOTH_PAIN1,				
	BOTH_PAIN2,				
	BOTH_PAIN3,				
	BOTH_PAIN4,				
	BOTH_PAIN5,				
	BOTH_PAIN6,				
	BOTH_PAIN7,				
	BOTH_PAIN8,				
	BOTH_PAIN9,				
	BOTH_PAIN10,			
	BOTH_PAIN11,			
	BOTH_PAIN12,			
	BOTH_PAIN13,			
	BOTH_PAIN14,			
	BOTH_PAIN15,			
	BOTH_PAIN16,			
	BOTH_PAIN17,			
	BOTH_PAIN18,			

	
	BOTH_ATTACK1,			
	BOTH_ATTACK2,			
	BOTH_ATTACK3,			
	BOTH_ATTACK4,			
	BOTH_ATTACK5,			
	BOTH_ATTACK6,			
	BOTH_ATTACK7,			
	BOTH_ATTACK10,			
	BOTH_ATTACK11,			
	BOTH_MELEE1,			
	BOTH_MELEE2,			
	BOTH_THERMAL_READY,		
	BOTH_THERMAL_THROW,		
	
	
	BOTH_A1_T__B_,	
	BOTH_A1__L__R,	
	BOTH_A1__R__L,	
	BOTH_A1_TL_BR,	
	BOTH_A1_BR_TL,	
	BOTH_A1_BL_TR,	
	BOTH_A1_TR_BL,	
	
	BOTH_T1_BR__R,	
	BOTH_T1_BR_TL,	
	BOTH_T1_BR__L,	
	BOTH_T1_BR_BL,	
	BOTH_T1__R_TR,	
	BOTH_T1__R_TL,	
	BOTH_T1__R__L,	
	BOTH_T1__R_BL,	
	BOTH_T1_TR_BR,	
	BOTH_T1_TR_TL,	
	BOTH_T1_TR__L,	
	BOTH_T1_TR_BL,	
	BOTH_T1_T__BR,	
	BOTH_T1_T___R,	
	BOTH_T1_T__TR,	
	BOTH_T1_T__TL,	
	BOTH_T1_T___L,	
	BOTH_T1_T__BL,	
	BOTH_T1_TL_BR,	
	BOTH_T1_TL_BL,	
	BOTH_T1__L_BR,	
	BOTH_T1__L__R,	
	BOTH_T1__L_TL,	
	BOTH_T1_BL_BR,	
	BOTH_T1_BL__R,	
	BOTH_T1_BL_TR,	
	BOTH_T1_BL__L,	
	
	BOTH_T1_BR_TR,	
	BOTH_T1_BR_T_,	
	BOTH_T1__R_BR,	
	BOTH_T1__R_T_,	
	BOTH_T1_TR__R,	
	BOTH_T1_TR_T_,	
	BOTH_T1_TL__R,	
	BOTH_T1_TL_TR,	
	BOTH_T1_TL_T_,	
	BOTH_T1_TL__L,	
	BOTH_T1__L_TR,	
	BOTH_T1__L_T_,	
	BOTH_T1__L_BL,	
	BOTH_T1_BL_T_,	
	BOTH_T1_BL_TL,	
	
	BOTH_S1_S1_T_,	
	BOTH_S1_S1__L,	
	BOTH_S1_S1__R,	
	BOTH_S1_S1_TL,	
	BOTH_S1_S1_BR,	
	BOTH_S1_S1_BL,	
	BOTH_S1_S1_TR,	
	
	BOTH_R1_B__S1,	
	BOTH_R1__L_S1,	
	BOTH_R1__R_S1,	
	BOTH_R1_TL_S1,	
	BOTH_R1_BR_S1,	
	BOTH_R1_BL_S1,	
	BOTH_R1_TR_S1,	
	
	BOTH_B1_BR___,	
	BOTH_B1__R___,	
	BOTH_B1_TR___,	
	BOTH_B1_T____,	
	BOTH_B1_TL___,	
	BOTH_B1__L___,	
	BOTH_B1_BL___,	
	
	BOTH_D1_BR___,	
	BOTH_D1__R___,	
	BOTH_D1_TR___,	
	BOTH_D1_TL___,	
	BOTH_D1__L___,	
	BOTH_D1_BL___,	
	BOTH_D1_B____,	
	
	BOTH_A2_T__B_,	
	BOTH_A2__L__R,	
	BOTH_A2__R__L,	
	BOTH_A2_TL_BR,	
	BOTH_A2_BR_TL,	
	BOTH_A2_BL_TR,	
	BOTH_A2_TR_BL,	
	
	BOTH_T2_BR__R,	
	BOTH_T2_BR_TL,	
	BOTH_T2_BR__L,	
	BOTH_T2_BR_BL,	
	BOTH_T2__R_TR,	
	BOTH_T2__R_TL,	
	BOTH_T2__R__L,	
	BOTH_T2__R_BL,	
	BOTH_T2_TR_BR,	
	BOTH_T2_TR_TL,	
	BOTH_T2_TR__L,	
	BOTH_T2_TR_BL,	
	BOTH_T2_T__BR,	
	BOTH_T2_T___R,	
	BOTH_T2_T__TR,	
	BOTH_T2_T__TL,	
	BOTH_T2_T___L,	
	BOTH_T2_T__BL,	
	BOTH_T2_TL_BR,	
	BOTH_T2_TL_BL,	
	BOTH_T2__L_BR,	
	BOTH_T2__L__R,	
	BOTH_T2__L_TL,	
	BOTH_T2_BL_BR,	
	BOTH_T2_BL__R,	
	BOTH_T2_BL_TR,	
	BOTH_T2_BL__L,	
	
	BOTH_T2_BR_TR,	
	BOTH_T2_BR_T_,	
	BOTH_T2__R_BR,	
	BOTH_T2__R_T_,	
	BOTH_T2_TR__R,	
	BOTH_T2_TR_T_,	
	BOTH_T2_TL__R,	
	BOTH_T2_TL_TR,	
	BOTH_T2_TL_T_,	
	BOTH_T2_TL__L,	
	BOTH_T2__L_TR,	
	BOTH_T2__L_T_,	
	BOTH_T2__L_BL,	
	BOTH_T2_BL_T_,	
	BOTH_T2_BL_TL,	
	
	BOTH_S2_S1_T_,	
	BOTH_S2_S1__L,	
	BOTH_S2_S1__R,	
	BOTH_S2_S1_TL,	
	BOTH_S2_S1_BR,	
	BOTH_S2_S1_BL,	
	BOTH_S2_S1_TR,	
	
	BOTH_R2_B__S1,	
	BOTH_R2__L_S1,	
	BOTH_R2__R_S1,	
	BOTH_R2_TL_S1,	
	BOTH_R2_BR_S1,	
	BOTH_R2_BL_S1,	
	BOTH_R2_TR_S1,	
	
	BOTH_B2_BR___,	
	BOTH_B2__R___,	
	BOTH_B2_TR___,	
	BOTH_B2_T____,	
	BOTH_B2_TL___,	
	BOTH_B2__L___,	
	BOTH_B2_BL___,	
	
	BOTH_D2_BR___,	
	BOTH_D2__R___,	
	BOTH_D2_TR___,	
	BOTH_D2_TL___,	
	BOTH_D2__L___,	
	BOTH_D2_BL___,	
	BOTH_D2_B____,	
	
	BOTH_A3_T__B_,	
	BOTH_A3__L__R,	
	BOTH_A3__R__L,	
	BOTH_A3_TL_BR,	
	BOTH_A3_BR_TL,	
	BOTH_A3_BL_TR,	
	BOTH_A3_TR_BL,	
	
	BOTH_T3_BR__R,	
	BOTH_T3_BR_TL,	
	BOTH_T3_BR__L,	
	BOTH_T3_BR_BL,	
	BOTH_T3__R_TR,	
	BOTH_T3__R_TL,	
	BOTH_T3__R__L,	
	BOTH_T3__R_BL,	
	BOTH_T3_TR_BR,	
	BOTH_T3_TR_TL,	
	BOTH_T3_TR__L,	
	BOTH_T3_TR_BL,	
	BOTH_T3_T__BR,	
	BOTH_T3_T___R,	
	BOTH_T3_T__TR,	
	BOTH_T3_T__TL,	
	BOTH_T3_T___L,	
	BOTH_T3_T__BL,	
	BOTH_T3_TL_BR,	
	BOTH_T3_TL_BL,	
	BOTH_T3__L_BR,	
	BOTH_T3__L__R,	
	BOTH_T3__L_TL,	
	BOTH_T3_BL_BR,	
	BOTH_T3_BL__R,	
	BOTH_T3_BL_TR,	
	BOTH_T3_BL__L,	
	
	BOTH_T3_BR_TR,	
	BOTH_T3_BR_T_,	
	BOTH_T3__R_BR,	
	BOTH_T3__R_T_,	
	BOTH_T3_TR__R,	
	BOTH_T3_TR_T_,	
	BOTH_T3_TL__R,	
	BOTH_T3_TL_TR,	
	BOTH_T3_TL_T_,	
	BOTH_T3_TL__L,	
	BOTH_T3__L_TR,	
	BOTH_T3__L_T_,	
	BOTH_T3__L_BL,	
	BOTH_T3_BL_T_,	
	BOTH_T3_BL_TL,	
	
	BOTH_S3_S1_T_,	
	BOTH_S3_S1__L,	
	BOTH_S3_S1__R,	
	BOTH_S3_S1_TL,	
	BOTH_S3_S1_BR,	
	BOTH_S3_S1_BL,	
	BOTH_S3_S1_TR,	
	
	BOTH_R3_B__S1,	
	BOTH_R3__L_S1,	
	BOTH_R3__R_S1,	
	BOTH_R3_TL_S1,	
	BOTH_R3_BR_S1,	
	BOTH_R3_BL_S1,	
	BOTH_R3_TR_S1,	
	
	BOTH_B3_BR___,	
	BOTH_B3__R___,	
	BOTH_B3_TR___,	
	BOTH_B3_T____,	
	BOTH_B3_TL___,	
	BOTH_B3__L___,	
	BOTH_B3_BL___,	
	
	BOTH_D3_BR___,	
	BOTH_D3__R___,	
	BOTH_D3_TR___,	
	BOTH_D3_TL___,	
	BOTH_D3__L___,	
	BOTH_D3_BL___,	
	BOTH_D3_B____,	
	
	BOTH_A4_T__B_,	
	BOTH_A4__L__R,	
	BOTH_A4__R__L,	
	BOTH_A4_TL_BR,	
	BOTH_A4_BR_TL,	
	BOTH_A4_BL_TR,	
	BOTH_A4_TR_BL,	
	
	BOTH_T4_BR__R,	
	BOTH_T4_BR_TL,	
	BOTH_T4_BR__L,	
	BOTH_T4_BR_BL,	
	BOTH_T4__R_TR,	
	BOTH_T4__R_TL,	
	BOTH_T4__R__L,	
	BOTH_T4__R_BL,	
	BOTH_T4_TR_BR,	
	BOTH_T4_TR_TL,	
	BOTH_T4_TR__L,	
	BOTH_T4_TR_BL,	
	BOTH_T4_T__BR,	
	BOTH_T4_T___R,	
	BOTH_T4_T__TR,	
	BOTH_T4_T__TL,	
	BOTH_T4_T___L,	
	BOTH_T4_T__BL,	
	BOTH_T4_TL_BR,	
	BOTH_T4_TL_BL,	
	BOTH_T4__L_BR,	
	BOTH_T4__L__R,	
	BOTH_T4__L_TL,	
	BOTH_T4_BL_BR,	
	BOTH_T4_BL__R,	
	BOTH_T4_BL_TR,	
	BOTH_T4_BL__L,	
	
	BOTH_T4_BR_TR,	
	BOTH_T4_BR_T_,	
	BOTH_T4__R_BR,	
	BOTH_T4__R_T_,	
	BOTH_T4_TR__R,	
	BOTH_T4_TR_T_,	
	BOTH_T4_TL__R,	
	BOTH_T4_TL_TR,	
	BOTH_T4_TL_T_,	
	BOTH_T4_TL__L,	
	BOTH_T4__L_TR,	
	BOTH_T4__L_T_,	
	BOTH_T4__L_BL,	
	BOTH_T4_BL_T_,	
	BOTH_T4_BL_TL,	
	
	BOTH_S4_S1_T_,	
	BOTH_S4_S1__L,	
	BOTH_S4_S1__R,	
	BOTH_S4_S1_TL,	
	BOTH_S4_S1_BR,	
	BOTH_S4_S1_BL,	
	BOTH_S4_S1_TR,	
	
	BOTH_R4_B__S1,	
	BOTH_R4__L_S1,	
	BOTH_R4__R_S1,	
	BOTH_R4_TL_S1,	
	BOTH_R4_BR_S1,	
	BOTH_R4_BL_S1,	
	BOTH_R4_TR_S1,	
	
	BOTH_B4_BR___,	
	BOTH_B4__R___,	
	BOTH_B4_TR___,	
	BOTH_B4_T____,	
	BOTH_B4_TL___,	
	BOTH_B4__L___,	
	BOTH_B4_BL___,	
	
	BOTH_D4_BR___,	
	BOTH_D4__R___,	
	BOTH_D4_TR___,	
	BOTH_D4_TL___,	
	BOTH_D4__L___,	
	BOTH_D4_BL___,	
	BOTH_D4_B____,	
	
	BOTH_A5_T__B_,	
	BOTH_A5__L__R,	
	BOTH_A5__R__L,	
	BOTH_A5_TL_BR,	
	BOTH_A5_BR_TL,	
	BOTH_A5_BL_TR,	
	BOTH_A5_TR_BL,	
	
	BOTH_T5_BR__R,	
	BOTH_T5_BR_TL,	
	BOTH_T5_BR__L,	
	BOTH_T5_BR_BL,	
	BOTH_T5__R_TR,	
	BOTH_T5__R_TL,	
	BOTH_T5__R__L,	
	BOTH_T5__R_BL,	
	BOTH_T5_TR_BR,	
	BOTH_T5_TR_TL,	
	BOTH_T5_TR__L,	
	BOTH_T5_TR_BL,	
	BOTH_T5_T__BR,	
	BOTH_T5_T___R,	
	BOTH_T5_T__TR,	
	BOTH_T5_T__TL,	
	BOTH_T5_T___L,	
	BOTH_T5_T__BL,	
	BOTH_T5_TL_BR,	
	BOTH_T5_TL_BL,	
	BOTH_T5__L_BR,	
	BOTH_T5__L__R,	
	BOTH_T5__L_TL,	
	BOTH_T5_BL_BR,	
	BOTH_T5_BL__R,	
	BOTH_T5_BL_TR,	
	BOTH_T5_BL__L,	
	
	BOTH_T5_BR_TR,	
	BOTH_T5_BR_T_,	
	BOTH_T5__R_BR,	
	BOTH_T5__R_T_,	
	BOTH_T5_TR__R,	
	BOTH_T5_TR_T_,	
	BOTH_T5_TL__R,	
	BOTH_T5_TL_TR,	
	BOTH_T5_TL_T_,	
	BOTH_T5_TL__L,	
	BOTH_T5__L_TR,	
	BOTH_T5__L_T_,	
	BOTH_T5__L_BL,	
	BOTH_T5_BL_T_,	
	BOTH_T5_BL_TL,	
	
	BOTH_S5_S1_T_,	
	BOTH_S5_S1__L,	
	BOTH_S5_S1__R,	
	BOTH_S5_S1_TL,	
	BOTH_S5_S1_BR,	
	BOTH_S5_S1_BL,	
	BOTH_S5_S1_TR,	
	
	BOTH_R5_B__S1,	
	BOTH_R5__L_S1,	
	BOTH_R5__R_S1,	
	BOTH_R5_TL_S1,	
	BOTH_R5_BR_S1,	
	BOTH_R5_BL_S1,	
	BOTH_R5_TR_S1,	
	
	BOTH_B5_BR___,	
	BOTH_B5__R___,	
	BOTH_B5_TR___,	
	BOTH_B5_T____,	
	BOTH_B5_TL___,	
	BOTH_B5__L___,	
	BOTH_B5_BL___,	
	
	BOTH_D5_BR___,	
	BOTH_D5__R___,	
	BOTH_D5_TR___,	
	BOTH_D5_TL___,	
	BOTH_D5__L___,	
	BOTH_D5_BL___,	
	BOTH_D5_B____,	
	
	BOTH_A6_T__B_,	
	BOTH_A6__L__R,	
	BOTH_A6__R__L,	
	BOTH_A6_TL_BR,	
	BOTH_A6_BR_TL,	
	BOTH_A6_BL_TR,	
	BOTH_A6_TR_BL,	
	
	BOTH_T6_BR__R,	
	BOTH_T6_BR_TL,	
	BOTH_T6_BR__L,	
	BOTH_T6_BR_BL,	
	BOTH_T6__R_TR,	
	BOTH_T6__R_TL,	
	BOTH_T6__R__L,	
	BOTH_T6__R_BL,	
	BOTH_T6_TR_BR,	
	BOTH_T6_TR_TL,	
	BOTH_T6_TR__L,	
	BOTH_T6_TR_BL,	
	BOTH_T6_T__BR,	
	BOTH_T6_T___R,	
	BOTH_T6_T__TR,	
	BOTH_T6_T__TL,	
	BOTH_T6_T___L,	
	BOTH_T6_T__BL,	
	BOTH_T6_TL_BR,	
	BOTH_T6_TL_BL,	
	BOTH_T6__L_BR,	
	BOTH_T6__L__R,	
	BOTH_T6__L_TL,	
	BOTH_T6_BL_BR,	
	BOTH_T6_BL__R,	
	BOTH_T6_BL_TR,	
	BOTH_T6_BL__L,	
	
	BOTH_T6_BR_TR,	
	BOTH_T6_BR_T_,	
	BOTH_T6__R_BR,	
	BOTH_T6__R_T_,	
	BOTH_T6_TR__R,	
	BOTH_T6_TR_T_,	
	BOTH_T6_TL__R,	
	BOTH_T6_TL_TR,	
	BOTH_T6_TL_T_,	
	BOTH_T6_TL__L,	
	BOTH_T6__L_TR,	
	BOTH_T6__L_T_,	
	BOTH_T6__L_BL,	
	BOTH_T6_BL_T_,	
	BOTH_T6_BL_TL,	
	
	BOTH_S6_S6_T_,	
	BOTH_S6_S6__L,	
	BOTH_S6_S6__R,	
	BOTH_S6_S6_TL,	
	BOTH_S6_S6_BR,	
	BOTH_S6_S6_BL,	
	BOTH_S6_S6_TR,	
	
	BOTH_R6_B__S6,	
	BOTH_R6__L_S6,	
	BOTH_R6__R_S6,	
	BOTH_R6_TL_S6,	
	BOTH_R6_BR_S6,	
	BOTH_R6_BL_S6,	
	BOTH_R6_TR_S6,	
	
	BOTH_B6_BR___,	
	BOTH_B6__R___,	
	BOTH_B6_TR___,	
	BOTH_B6_T____,	
	BOTH_B6_TL___,	
	BOTH_B6__L___,	
	BOTH_B6_BL___,	
	
	BOTH_D6_BR___,	
	BOTH_D6__R___,	
	BOTH_D6_TR___,	
	BOTH_D6_TL___,	
	BOTH_D6__L___,	
	BOTH_D6_BL___,	
	BOTH_D6_B____,	
	
	BOTH_A7_T__B_,	
	BOTH_A7__L__R,	
	BOTH_A7__R__L,	
	BOTH_A7_TL_BR,	
	BOTH_A7_BR_TL,	
	BOTH_A7_BL_TR,	
	BOTH_A7_TR_BL,	
	
	BOTH_T7_BR__R,	
	BOTH_T7_BR_TL,	
	BOTH_T7_BR__L,	
	BOTH_T7_BR_BL,	
	BOTH_T7__R_TR,	
	BOTH_T7__R_TL,	
	BOTH_T7__R__L,	
	BOTH_T7__R_BL,	
	BOTH_T7_TR_BR,	
	BOTH_T7_TR_TL,	
	BOTH_T7_TR__L,	
	BOTH_T7_TR_BL,	
	BOTH_T7_T__BR,	
	BOTH_T7_T___R,	
	BOTH_T7_T__TR,	
	BOTH_T7_T__TL,	
	BOTH_T7_T___L,	
	BOTH_T7_T__BL,	
	BOTH_T7_TL_BR,	
	BOTH_T7_TL_BL,	
	BOTH_T7__L_BR,	
	BOTH_T7__L__R,	
	BOTH_T7__L_TL,	
	BOTH_T7_BL_BR,	
	BOTH_T7_BL__R,	
	BOTH_T7_BL_TR,	
	BOTH_T7_BL__L,	
	
	BOTH_T7_BR_TR,	
	BOTH_T7_BR_T_,	
	BOTH_T7__R_BR,	
	BOTH_T7__R_T_,	
	BOTH_T7_TR__R,	
	BOTH_T7_TR_T_,	
	BOTH_T7_TL__R,	
	BOTH_T7_TL_TR,	
	BOTH_T7_TL_T_,	
	BOTH_T7_TL__L,	
	BOTH_T7__L_TR,	
	BOTH_T7__L_T_,	
	BOTH_T7__L_BL,	
	BOTH_T7_BL_T_,	
	BOTH_T7_BL_TL,	
	
	BOTH_S7_S7_T_,	
	BOTH_S7_S7__L,	
	BOTH_S7_S7__R,	
	BOTH_S7_S7_TL,	
	BOTH_S7_S7_BR,	
	BOTH_S7_S7_BL,	
	BOTH_S7_S7_TR,	
	
	BOTH_R7_B__S7,	
	BOTH_R7__L_S7,	
	BOTH_R7__R_S7,	
	BOTH_R7_TL_S7,	
	BOTH_R7_BR_S7,	
	BOTH_R7_BL_S7,	
	BOTH_R7_TR_S7,	
	
	BOTH_B7_BR___,	
	BOTH_B7__R___,	
	BOTH_B7_TR___,	
	BOTH_B7_T____,	
	BOTH_B7_TL___,	
	BOTH_B7__L___,	
	BOTH_B7_BL___,	
	
	BOTH_D7_BR___,	
	BOTH_D7__R___,	
	BOTH_D7_TR___,	
	BOTH_D7_TL___,	
	BOTH_D7__L___,	
	BOTH_D7_BL___,	
	BOTH_D7_B____,	
	
	BOTH_P1_S1_T_,	
	BOTH_P1_S1_TR,	
	BOTH_P1_S1_TL,	
	BOTH_P1_S1_BL,	
	BOTH_P1_S1_BR,	
	
	BOTH_K1_S1_T_,	
	BOTH_K1_S1_TR,	
	BOTH_K1_S1_TL,	
	BOTH_K1_S1_BL,	
	BOTH_K1_S1_B_,	
	BOTH_K1_S1_BR,	
	
	BOTH_V1_BR_S1,	
	BOTH_V1__R_S1,	
	BOTH_V1_TR_S1,	
	BOTH_V1_T__S1,	
	BOTH_V1_TL_S1,	
	BOTH_V1__L_S1,	
	BOTH_V1_BL_S1,	
	BOTH_V1_B__S1,	
	
	BOTH_H1_S1_T_,	
	BOTH_H1_S1_TR,	
	BOTH_H1_S1_TL,	
	BOTH_H1_S1_BL,	
	BOTH_H1_S1_B_,	
	BOTH_H1_S1_BR,	
	
	BOTH_P6_S6_T_,	
	BOTH_P6_S6_TR,	
	BOTH_P6_S6_TL,	
	BOTH_P6_S6_BL,	
	BOTH_P6_S6_BR,	
	
	BOTH_K6_S6_T_,	
	BOTH_K6_S6_TR,	
	BOTH_K6_S6_TL,	
	BOTH_K6_S6_BL,	
	BOTH_K6_S6_B_,	
	BOTH_K6_S6_BR,	
	
	BOTH_V6_BR_S6,	
	BOTH_V6__R_S6,	
	BOTH_V6_TR_S6,	
	BOTH_V6_T__S6,	
	BOTH_V6_TL_S6,	
	BOTH_V6__L_S6,	
	BOTH_V6_BL_S6,	
	BOTH_V6_B__S6,	
	
	BOTH_H6_S6_T_,	
	BOTH_H6_S6_TR,	
	BOTH_H6_S6_TL,	
	BOTH_H6_S6_BL,	
	BOTH_H6_S6_B_,	
	BOTH_H6_S6_BR,	
	
	BOTH_P7_S7_T_,	
	BOTH_P7_S7_TR,	
	BOTH_P7_S7_TL,	
	BOTH_P7_S7_BL,	
	BOTH_P7_S7_BR,	
	
	BOTH_K7_S7_T_,	
	BOTH_K7_S7_TR,	
	BOTH_K7_S7_TL,	
	BOTH_K7_S7_BL,	
	BOTH_K7_S7_B_,	
	BOTH_K7_S7_BR,	
	
	BOTH_V7_BR_S7,	
	BOTH_V7__R_S7,	
	BOTH_V7_TR_S7,	
	BOTH_V7_T__S7,	
	BOTH_V7_TL_S7,	
	BOTH_V7__L_S7,	
	BOTH_V7_BL_S7,	
	BOTH_V7_B__S7,	
	
	BOTH_H7_S7_T_,	
	BOTH_H7_S7_TR,	
	BOTH_H7_S7_TL,	
	BOTH_H7_S7_BL,	
	BOTH_H7_S7_B_,	
	BOTH_H7_S7_BR,	
	
	
	


	
	BOTH_LK_S_DL_S_B_1_L,	
	BOTH_LK_S_DL_S_B_1_W,	
	BOTH_LK_S_DL_S_L_1,		
	BOTH_LK_S_DL_S_SB_1_L,	
	BOTH_LK_S_DL_S_SB_1_W,	
	
	BOTH_LK_S_DL_T_B_1_L,	
	BOTH_LK_S_DL_T_B_1_W,	
	BOTH_LK_S_DL_T_L_1,		
	BOTH_LK_S_DL_T_SB_1_L,	
	BOTH_LK_S_DL_T_SB_1_W,	

	
	BOTH_LK_S_ST_S_B_1_L,	
	BOTH_LK_S_ST_S_B_1_W,	
	BOTH_LK_S_ST_S_L_1,		
	BOTH_LK_S_ST_S_SB_1_L,	
	BOTH_LK_S_ST_S_SB_1_W,	
	
	BOTH_LK_S_ST_T_B_1_L,	
	BOTH_LK_S_ST_T_B_1_W,	
	BOTH_LK_S_ST_T_L_1,		
	BOTH_LK_S_ST_T_SB_1_L,	
	BOTH_LK_S_ST_T_SB_1_W,	

	
	BOTH_LK_S_S_S_B_1_L,	
	BOTH_LK_S_S_S_B_1_W,	
	BOTH_LK_S_S_S_L_1,		
	BOTH_LK_S_S_S_SB_1_L,	
	BOTH_LK_S_S_S_SB_1_W,	
	
	BOTH_LK_S_S_T_B_1_L,	
	BOTH_LK_S_S_T_B_1_W,	
	BOTH_LK_S_S_T_L_1,		
	BOTH_LK_S_S_T_SB_1_L,	
	BOTH_LK_S_S_T_SB_1_W,	


	
	BOTH_LK_DL_DL_S_B_1_L,	
	BOTH_LK_DL_DL_S_B_1_W,	
	BOTH_LK_DL_DL_S_L_1,	
	BOTH_LK_DL_DL_S_SB_1_L,	
	BOTH_LK_DL_DL_S_SB_1_W,	
	
	BOTH_LK_DL_DL_T_B_1_L,	
	BOTH_LK_DL_DL_T_B_1_W,	
	BOTH_LK_DL_DL_T_L_1,	
	BOTH_LK_DL_DL_T_SB_1_L,	
	BOTH_LK_DL_DL_T_SB_1_W,	

	
	BOTH_LK_DL_ST_S_B_1_L,	
	BOTH_LK_DL_ST_S_B_1_W,	
	BOTH_LK_DL_ST_S_L_1,	
	BOTH_LK_DL_ST_S_SB_1_L,	
	BOTH_LK_DL_ST_S_SB_1_W,	
	
	BOTH_LK_DL_ST_T_B_1_L,	
	BOTH_LK_DL_ST_T_B_1_W,	
	BOTH_LK_DL_ST_T_L_1,	
	BOTH_LK_DL_ST_T_SB_1_L,	
	BOTH_LK_DL_ST_T_SB_1_W,	

	
	BOTH_LK_DL_S_S_B_1_L,	
	BOTH_LK_DL_S_S_B_1_W,	
	BOTH_LK_DL_S_S_L_1,		
	BOTH_LK_DL_S_S_SB_1_L,	
	BOTH_LK_DL_S_S_SB_1_W,	
	
	BOTH_LK_DL_S_T_B_1_L,	
	BOTH_LK_DL_S_T_B_1_W,	
	BOTH_LK_DL_S_T_L_1,		
	BOTH_LK_DL_S_T_SB_1_L,	
	BOTH_LK_DL_S_T_SB_1_W,	


	
	BOTH_LK_ST_DL_S_B_1_L,	
	BOTH_LK_ST_DL_S_B_1_W,	
	BOTH_LK_ST_DL_S_L_1,	
	BOTH_LK_ST_DL_S_SB_1_L,	
	BOTH_LK_ST_DL_S_SB_1_W,	
	
	BOTH_LK_ST_DL_T_B_1_L,	
	BOTH_LK_ST_DL_T_B_1_W,	
	BOTH_LK_ST_DL_T_L_1,	
	BOTH_LK_ST_DL_T_SB_1_L,	
	BOTH_LK_ST_DL_T_SB_1_W,	

	
	BOTH_LK_ST_ST_S_B_1_L,	
	BOTH_LK_ST_ST_S_B_1_W,	
	BOTH_LK_ST_ST_S_L_1,	
	BOTH_LK_ST_ST_S_SB_1_L,	
	BOTH_LK_ST_ST_S_SB_1_W,	
	
	BOTH_LK_ST_ST_T_B_1_L,	
	BOTH_LK_ST_ST_T_B_1_W,	
	BOTH_LK_ST_ST_T_L_1,	
	BOTH_LK_ST_ST_T_SB_1_L,	
	BOTH_LK_ST_ST_T_SB_1_W,	

	
	BOTH_LK_ST_S_S_B_1_L,	
	BOTH_LK_ST_S_S_B_1_W,	
	BOTH_LK_ST_S_S_L_1,		
	BOTH_LK_ST_S_S_SB_1_L,	
	BOTH_LK_ST_S_S_SB_1_W,	
	
	BOTH_LK_ST_S_T_B_1_L,	
	BOTH_LK_ST_S_T_B_1_W,	
	BOTH_LK_ST_S_T_L_1,		
	BOTH_LK_ST_S_T_SB_1_L,	
	BOTH_LK_ST_S_T_SB_1_W,	

	BOTH_LK_S_S_S_L_2,		
	BOTH_LK_S_S_T_L_2,		
	BOTH_LK_DL_DL_S_L_2,	
	BOTH_LK_DL_DL_T_L_2,	
	BOTH_LK_ST_ST_S_L_2,	
	BOTH_LK_ST_ST_T_L_2,	

	
	BOTH_BF2RETURN,	
	BOTH_BF2BREAK,	
	BOTH_BF2LOCK,	
	BOTH_BF1RETURN,	
	BOTH_BF1BREAK,	
	BOTH_BF1LOCK,	
	BOTH_CWCIRCLE_R2__R_S1,	
	BOTH_CCWCIRCLE_R2__L_S1,	
	BOTH_CWCIRCLE_A2__L__R,	
	BOTH_CCWCIRCLE_A2__R__L,	
	BOTH_CWCIRCLEBREAK,	
	BOTH_CCWCIRCLEBREAK,	
	BOTH_CWCIRCLELOCK,	
	BOTH_CCWCIRCLELOCK,	
	
	
	BOTH_SABERFAST_STANCE,
	BOTH_SABERSLOW_STANCE,
	BOTH_SABERDUAL_STANCE,
	BOTH_SABERSTAFF_STANCE,
	BOTH_A2_STABBACK1,		
	BOTH_ATTACK_BACK,		
	BOTH_JUMPFLIPSLASHDOWN1,
	BOTH_JUMPFLIPSTABDOWN,
	BOTH_FORCELEAP2_T__B_,
	BOTH_LUNGE2_B__T_,
	BOTH_CROUCHATTACKBACK1,
	
	BOTH_JUMPATTACK6,
	BOTH_JUMPATTACK7,
	BOTH_SPINATTACK6,
	BOTH_SPINATTACK7,
	BOTH_S1_S6,
	BOTH_S6_S1,
	BOTH_S1_S7,
	BOTH_S7_S1,
	BOTH_FORCELONGLEAP_START,
	BOTH_FORCELONGLEAP_ATTACK,
	BOTH_FORCELONGLEAP_LAND,
	BOTH_FORCEWALLRUNFLIP_START,
	BOTH_FORCEWALLRUNFLIP_END,
	BOTH_FORCEWALLRUNFLIP_ALT,
	BOTH_FORCEWALLREBOUND_FORWARD,
	BOTH_FORCEWALLREBOUND_LEFT,
	BOTH_FORCEWALLREBOUND_BACK,
	BOTH_FORCEWALLREBOUND_RIGHT,
	BOTH_FORCEWALLHOLD_FORWARD,
	BOTH_FORCEWALLHOLD_LEFT,
	BOTH_FORCEWALLHOLD_BACK,
	BOTH_FORCEWALLHOLD_RIGHT,
	BOTH_FORCEWALLRELEASE_FORWARD,
	BOTH_FORCEWALLRELEASE_LEFT,
	BOTH_FORCEWALLRELEASE_BACK,
	BOTH_FORCEWALLRELEASE_RIGHT,
	BOTH_A7_KICK_F,
	BOTH_A7_KICK_B,
	BOTH_A7_KICK_R,
	BOTH_A7_KICK_L,
	BOTH_A7_KICK_S,
	BOTH_A7_KICK_BF,
	BOTH_A7_KICK_BF_STOP,
	BOTH_A7_KICK_RL,
	BOTH_A7_KICK_F_AIR,
	BOTH_A7_KICK_B_AIR,
	BOTH_A7_KICK_R_AIR,
	BOTH_A7_KICK_L_AIR,
	BOTH_FLIP_ATTACK7,
	BOTH_FLIP_HOLD7,
	BOTH_FLIP_LAND,
	BOTH_PULL_IMPALE_STAB,
	BOTH_PULL_IMPALE_SWING,
	BOTH_PULLED_INAIR_B,
	BOTH_PULLED_INAIR_F,
	BOTH_STABDOWN,
	BOTH_STABDOWN_STAFF,
	BOTH_STABDOWN_DUAL,
	BOTH_A6_SABERPROTECT,
	BOTH_A7_SOULCAL,
	BOTH_A1_SPECIAL,
	BOTH_A2_SPECIAL,
	BOTH_A3_SPECIAL,
	BOTH_ROLL_STAB,

	
	BOTH_STAND1,			
	BOTH_STAND1IDLE1,		
	BOTH_STAND2,			
	BOTH_STAND2IDLE1,		
	BOTH_STAND2IDLE2,		
	BOTH_STAND3,			
	BOTH_STAND3IDLE1,		
	BOTH_STAND4,			
	BOTH_STAND5,			
	BOTH_STAND5IDLE1,		
	BOTH_STAND6,			
	BOTH_STAND8,			
	BOTH_STAND1TO2,			
	BOTH_STAND2TO1,			
	BOTH_STAND2TO4,			
	BOTH_STAND4TO2,			
	BOTH_STAND4TOATTACK2,	
	BOTH_STANDUP2,			
	BOTH_STAND5TOSIT3,		
	BOTH_STAND1TOSTAND5,	
	BOTH_STAND5TOSTAND1,	
	BOTH_STAND5TOAIM,		
	BOTH_STAND5STARTLEDLOOKLEFT,	
	BOTH_STARTLEDLOOKLEFTTOSTAND5,	
	BOTH_STAND5TOSTAND8,	
	BOTH_STAND7TOSTAND8,	
	BOTH_STAND8TOSTAND5,	
	BOTH_STAND9,			
	BOTH_STAND9IDLE1,		
	BOTH_STAND5SHIFTWEIGHT,	
	BOTH_STAND5SHIFTWEIGHTSTART,	
	BOTH_STAND5SHIFTWEIGHTSTOP,		
	BOTH_STAND5TURNLEFTSTART,		
	BOTH_STAND5TURNLEFTSTOP,		
	BOTH_STAND5TURNRIGHTSTART,		
	BOTH_STAND5TURNRIGHTSTOP,		
	BOTH_STAND5LOOK180LEFTSTART,	
	BOTH_STAND5LOOK180LEFTSTOP,	

	BOTH_CONSOLE1START,		
	BOTH_CONSOLE1,			
	BOTH_CONSOLE1STOP,		
	BOTH_CONSOLE2START,		
	BOTH_CONSOLE2,			
	BOTH_CONSOLE2STOP,		
	BOTH_CONSOLE2HOLDCOMSTART,	
	BOTH_CONSOLE2HOLDCOMSTOP,	

	BOTH_GUARD_LOOKAROUND1,	
	BOTH_GUARD_IDLE1,		
	BOTH_GESTURE1,			
	BOTH_GESTURE2,			
	BOTH_WALK1TALKCOMM1,	
	BOTH_TALK1,				
	BOTH_TALK2,				
	BOTH_TALKCOMM1START,	
	BOTH_TALKCOMM1,			
	BOTH_TALKCOMM1STOP,		
	BOTH_TALKGESTURE1,		
	
	BOTH_HEADTILTLSTART,		
	BOTH_HEADTILTLSTOP,			
	BOTH_HEADTILTRSTART,		
	BOTH_HEADTILTRSTOP,			
	BOTH_HEADNOD,				
	BOTH_HEADSHAKE,				
	BOTH_SIT2HEADTILTLSTART,	
	BOTH_SIT2HEADTILTLSTOP,		
 
	BOTH_REACH1START,		
	BOTH_REACH1STOP,		

	BOTH_COME_ON1,				
	BOTH_STEADYSELF1,			
	BOTH_STEADYSELF1END,		
	BOTH_SILENCEGESTURE1,		
	BOTH_REACHFORSABER1,		
	BOTH_SABERKILLER1,			
	BOTH_SABERKILLEE1,			
	BOTH_HUGGER1,			
	BOTH_HUGGERSTOP1,		
	BOTH_HUGGEE1,			
	BOTH_HUGGEESTOP1,		

	BOTH_SABERTHROW1START,		
	BOTH_SABERTHROW1STOP,		
	BOTH_SABERTHROW2START,		
	BOTH_SABERTHROW2STOP,		

	
	BOTH_SIT1,				
	BOTH_SIT2,				
	BOTH_SIT3,				

	BOTH_SIT2TOSTAND5,		
	BOTH_STAND5TOSIT2,		
	BOTH_SIT2TOSIT4,		
	BOTH_SIT3TOSTAND5,		

	BOTH_CROUCH1,			
	BOTH_CROUCH1IDLE,		
	BOTH_CROUCH1WALK,		
	BOTH_CROUCH1WALKBACK,	
	BOTH_UNCROUCH1,			
	BOTH_CROUCH2TOSTAND1,	
	BOTH_CROUCH3,			
	BOTH_UNCROUCH3,			
	BOTH_CROUCH4,			
	BOTH_UNCROUCH4,			

	BOTH_GUNSIT1,			

	
	
	BOTH_VS_MOUNT_L,			
	BOTH_VS_DISMOUNT_L,			
	BOTH_VS_MOUNT_R,			
	BOTH_VS_DISMOUNT_R,			

	BOTH_VS_MOUNTJUMP_L,		
	BOTH_VS_MOUNTTHROW,			
	BOTH_VS_MOUNTTHROW_L,		
	BOTH_VS_MOUNTTHROW_R,		
	BOTH_VS_MOUNTTHROWEE,		

	BOTH_VS_LOOKLEFT,			
	BOTH_VS_LOOKRIGHT,			

	BOTH_VS_TURBO,				

	BOTH_VS_REV,				

	BOTH_VS_AIR,				
	BOTH_VS_AIR_G,				
	BOTH_VS_AIR_SL,				
	BOTH_VS_AIR_SR,				

	BOTH_VS_LAND,				
	BOTH_VS_LAND_G,				
	BOTH_VS_LAND_SL,			
	BOTH_VS_LAND_SR,			

	BOTH_VS_IDLE,				
	BOTH_VS_IDLE_G,				
	BOTH_VS_IDLE_SL,			
	BOTH_VS_IDLE_SR,			

	BOTH_VS_LEANL,				
	BOTH_VS_LEANL_G,			
	BOTH_VS_LEANL_SL,			
	BOTH_VS_LEANL_SR,			

	BOTH_VS_LEANR,				
	BOTH_VS_LEANR_G,			
	BOTH_VS_LEANR_SL,			
	BOTH_VS_LEANR_SR,			
				
	BOTH_VS_ATL_S,				
	BOTH_VS_ATR_S,				
	BOTH_VS_ATR_TO_L_S,			
	BOTH_VS_ATL_TO_R_S,			
	BOTH_VS_ATR_G,				
	BOTH_VS_ATL_G,				
	BOTH_VS_ATF_G,				

	BOTH_VS_PAIN1,				

	
	
	BOTH_VT_MOUNT_L,		
	BOTH_VT_MOUNT_R,		
	BOTH_VT_MOUNT_B,		
	BOTH_VT_DISMOUNT,		
	BOTH_VT_DISMOUNT_L,		
	BOTH_VT_DISMOUNT_R,		

	BOTH_VT_WALK_FWD,		
	BOTH_VT_WALK_REV,		
	BOTH_VT_WALK_FWD_L,		
	BOTH_VT_WALK_FWD_R,		
	BOTH_VT_RUN_FWD,		
	BOTH_VT_RUN_REV,		
	BOTH_VT_RUN_FWD_L,		
	BOTH_VT_RUN_FWD_R,		

	BOTH_VT_SLIDEF,			
	BOTH_VT_AIR,			
	BOTH_VT_ATB,			
	BOTH_VT_PAIN1,			
	BOTH_VT_DEATH1,			
	BOTH_VT_STAND,			
	BOTH_VT_BUCK,			

	BOTH_VT_LAND,			
	BOTH_VT_TURBO,			
	BOTH_VT_IDLE_SL,		
	BOTH_VT_IDLE_SR,		

	BOTH_VT_IDLE,			
	BOTH_VT_IDLE1,			
	BOTH_VT_IDLE_S,			
	BOTH_VT_IDLE_G,			
	BOTH_VT_IDLE_T,			

	BOTH_VT_ATL_S,			
	BOTH_VT_ATR_S,			
	BOTH_VT_ATR_TO_L_S,		
	BOTH_VT_ATL_TO_R_S,		
	BOTH_VT_ATR_G,			
	BOTH_VT_ATL_G,			
	BOTH_VT_ATF_G,			


	
	
	BOTH_GEARS_OPEN,
	BOTH_GEARS_CLOSE,
	BOTH_WINGS_OPEN,
	BOTH_WINGS_CLOSE,

	BOTH_DEATH14_UNGRIP,	
	BOTH_DEATH14_SITUP,		
	BOTH_KNEES1,			
	BOTH_KNEES2,			
	BOTH_KNEES2TO1,			

	
	BOTH_WALK1,				
	BOTH_WALK2,				
	BOTH_WALK_STAFF,		
	BOTH_WALKBACK_STAFF,	
	BOTH_WALK_DUAL,			
	BOTH_WALKBACK_DUAL,		
	BOTH_WALK5,				
	BOTH_WALK6,				
	BOTH_WALK7,				
	BOTH_RUN1,				
	BOTH_RUN1START,			
	BOTH_RUN1STOP,			
	BOTH_RUN2,				
	BOTH_RUN1TORUN2,		
	BOTH_RUN2TORUN1,		
	BOTH_RUN4,				
	BOTH_RUN_STAFF,			
	BOTH_RUNBACK_STAFF,		
	BOTH_RUN_DUAL,			
	BOTH_RUNBACK_DUAL,		
	BOTH_STRAFE_LEFT1,		
	BOTH_STRAFE_RIGHT1,		
	BOTH_RUNSTRAFE_LEFT1,	
	BOTH_RUNSTRAFE_RIGHT1,	
	BOTH_TURN_LEFT1,		
	BOTH_TURN_RIGHT1,		
	BOTH_TURNSTAND1,		
	BOTH_TURNSTAND2,		
	BOTH_TURNSTAND3,		
	BOTH_TURNSTAND4,		
	BOTH_TURNSTAND5,		
	BOTH_TURNCROUCH1,		

	BOTH_WALKBACK1,			
	BOTH_WALKBACK2,			
	BOTH_RUNBACK1,			
	BOTH_RUNBACK2,			
	
	
	BOTH_JUMP1,				
	BOTH_INAIR1,			
	BOTH_LAND1,				
	BOTH_LAND2,				

	BOTH_JUMPBACK1,			
	BOTH_INAIRBACK1,		
	BOTH_LANDBACK1,			

	BOTH_JUMPLEFT1,			
	BOTH_INAIRLEFT1,		
	BOTH_LANDLEFT1,			

	BOTH_JUMPRIGHT1,		
	BOTH_INAIRRIGHT1,		
	BOTH_LANDRIGHT1,		

	BOTH_FORCEJUMP1,		
	BOTH_FORCEINAIR1,		
	BOTH_FORCELAND1,		

	BOTH_FORCEJUMPBACK1,	
	BOTH_FORCEINAIRBACK1,	
	BOTH_FORCELANDBACK1,	

	BOTH_FORCEJUMPLEFT1,	
	BOTH_FORCEINAIRLEFT1,	
	BOTH_FORCELANDLEFT1,	

	BOTH_FORCEJUMPRIGHT1,	
	BOTH_FORCEINAIRRIGHT1,	
	BOTH_FORCELANDRIGHT1,	
	
	BOTH_FLIP_F,			
	BOTH_FLIP_B,			
	BOTH_FLIP_L,			
	BOTH_FLIP_R,			

	BOTH_ROLL_F,			
	BOTH_ROLL_B,			
	BOTH_ROLL_L,			
	BOTH_ROLL_R,			

	BOTH_HOP_F,				
	BOTH_HOP_B,				
	BOTH_HOP_L,				
	BOTH_HOP_R,				

	BOTH_DODGE_FL,			
	BOTH_DODGE_FR,			
	BOTH_DODGE_BL,			
	BOTH_DODGE_BR,			
	BOTH_DODGE_L,			
	BOTH_DODGE_R,			
	BOTH_DODGE_HOLD_FL,			
	BOTH_DODGE_HOLD_FR,			
	BOTH_DODGE_HOLD_BL,			
	BOTH_DODGE_HOLD_BR,			
	BOTH_DODGE_HOLD_L,			
	BOTH_DODGE_HOLD_R,			

	
	BOTH_ENGAGETAUNT,
	BOTH_BOW,
	BOTH_MEDITATE,
	BOTH_MEDITATE_END,
	BOTH_SHOWOFF_FAST,
	BOTH_SHOWOFF_MEDIUM,
	BOTH_SHOWOFF_STRONG,
	BOTH_SHOWOFF_DUAL,
	BOTH_SHOWOFF_STAFF,
	BOTH_VICTORY_FAST,
	BOTH_VICTORY_MEDIUM,
	BOTH_VICTORY_STRONG,
	BOTH_VICTORY_DUAL,
	BOTH_VICTORY_STAFF,
	
	BOTH_ARIAL_LEFT,		
	BOTH_ARIAL_RIGHT,		
	BOTH_CARTWHEEL_LEFT,	
	BOTH_CARTWHEEL_RIGHT,	
	BOTH_FLIP_LEFT,			
	BOTH_FLIP_BACK1,		
	BOTH_FLIP_BACK2,		
	BOTH_FLIP_BACK3,		
	BOTH_BUTTERFLY_LEFT,	
	BOTH_BUTTERFLY_RIGHT,	
	BOTH_WALL_RUN_RIGHT,	
	BOTH_WALL_RUN_RIGHT_FLIP,
	BOTH_WALL_RUN_RIGHT_STOP,
	BOTH_WALL_RUN_LEFT,		
	BOTH_WALL_RUN_LEFT_FLIP,
	BOTH_WALL_RUN_LEFT_STOP,
	BOTH_WALL_FLIP_RIGHT,	
	BOTH_WALL_FLIP_LEFT,	
	BOTH_KNOCKDOWN1,		
	BOTH_KNOCKDOWN2,		
	BOTH_KNOCKDOWN3,		
	BOTH_KNOCKDOWN4,		
	BOTH_KNOCKDOWN5,		
	BOTH_GETUP1,			
	BOTH_GETUP2,			
	BOTH_GETUP3,			
	BOTH_GETUP4,			
	BOTH_GETUP5,			
	BOTH_GETUP_CROUCH_F1,	
	BOTH_GETUP_CROUCH_B1,	
	BOTH_FORCE_GETUP_F1,	
	BOTH_FORCE_GETUP_F2,	
	BOTH_FORCE_GETUP_B1,	
	BOTH_FORCE_GETUP_B2,	
	BOTH_FORCE_GETUP_B3,	
	BOTH_FORCE_GETUP_B4,	
	BOTH_FORCE_GETUP_B5,	
	BOTH_FORCE_GETUP_B6,	
	BOTH_GETUP_BROLL_B,	
	BOTH_GETUP_BROLL_F,	
	BOTH_GETUP_BROLL_L,	
	BOTH_GETUP_BROLL_R,	
	BOTH_GETUP_FROLL_B,	
	BOTH_GETUP_FROLL_F,	
	BOTH_GETUP_FROLL_L,	
	BOTH_GETUP_FROLL_R,	
	BOTH_WALL_FLIP_BACK1,	
	BOTH_WALL_FLIP_BACK2,	
	BOTH_SPIN1,				
	BOTH_CEILING_CLING,		
	BOTH_CEILING_DROP,		

	
	BOTH_FJSS_TR_BL,		
	BOTH_FJSS_TL_BR,		
	BOTH_RIGHTHANDCHOPPEDOFF,
	BOTH_DEFLECTSLASH__R__L_FIN,
	BOTH_BASHED1,
	BOTH_ARIAL_F1,
	BOTH_BUTTERFLY_FR1,
	BOTH_BUTTERFLY_FL1,

	
	BOTH_BACK_FLIP_UP,	
	BOTH_LOSE_SABER,	
	BOTH_STAFF_TAUNT,	
	BOTH_DUAL_TAUNT,		
	BOTH_A6_FB,				
	BOTH_A6_LR,				
	BOTH_A7_HILT,			
	
	BOTH_ALORA_SPIN,		
	BOTH_ALORA_FLIP_1,		
	BOTH_ALORA_FLIP_2,		
	BOTH_ALORA_FLIP_3,		
	BOTH_ALORA_FLIP_B,		
	BOTH_ALORA_SPIN_THROW,	
	BOTH_ALORA_SPIN_SLASH,	
	BOTH_ALORA_TAUNT,		
	
	BOTH_ROSH_PAIN,	
	BOTH_ROSH_HEAL,	
	
	BOTH_TAVION_SCEPTERGROUND, 
	BOTH_TAVION_SWORDPOWER,
	BOTH_SCEPTER_START,	
	BOTH_SCEPTER_HOLD,	
	BOTH_SCEPTER_STOP,	
	
	BOTH_KYLE_GRAB,		
	BOTH_KYLE_MISS,		
	BOTH_KYLE_PA_1,		
	BOTH_PLAYER_PA_1,	
	BOTH_KYLE_PA_2,		
	BOTH_PLAYER_PA_2,	
	BOTH_PLAYER_PA_FLY,	
	BOTH_KYLE_PA_3,		
	BOTH_PLAYER_PA_3,	
	BOTH_PLAYER_PA_3_FLY,
	
	BOTH_BUCK_RIDER,	
	
	BOTH_HOLD_START,	
	BOTH_HOLD_MISS,	
	BOTH_HOLD_IDLE,	
	BOTH_HOLD_END,	
	BOTH_HOLD_ATTACK,	
	BOTH_HOLD_SNIFF,	
	BOTH_HOLD_DROP,		
	
	BOTH_GRABBED,	
	BOTH_RELEASED,	
	BOTH_HANG_IDLE,	
	BOTH_HANG_ATTACK,	
	BOTH_HANG_PAIN,	

	
	BOTH_HIT1,				
	BOTH_LADDER_UP1,		
	BOTH_LADDER_DWN1,		
	BOTH_LADDER_IDLE,		

	
	BOTH_FLY_SHIELDED,		

	
	BOTH_SWIM_IDLE1,		
	BOTH_SWIMFORWARD,		
	BOTH_SWIMBACKWARD,		

	
	BOTH_SLEEP1,			
	BOTH_SLEEP6START,		
	BOTH_SLEEP6STOP,		
	BOTH_SLEEP1GETUP,		
	BOTH_SLEEP1GETUP2,		

	BOTH_CHOKE1START,		
	BOTH_CHOKE1STARTHOLD,	
	BOTH_CHOKE1,			

	BOTH_CHOKE2,			
	BOTH_CHOKE3,			

	
	BOTH_POWERUP1,			

	BOTH_TURNON,			
	BOTH_TURNOFF,			

	BOTH_BUTTON1,			
	BOTH_BUTTON2,			
	BOTH_BUTTON_HOLD,		
	BOTH_BUTTON_RELEASE,	

	
	
	BOTH_RESISTPUSH,		
	BOTH_FORCEPUSH,			
	BOTH_FORCEPULL,			
	BOTH_MINDTRICK1,			
	BOTH_MINDTRICK2,			
	BOTH_FORCELIGHTNING,		
	BOTH_FORCELIGHTNING_START,	
	BOTH_FORCELIGHTNING_HOLD,	
	BOTH_FORCELIGHTNING_RELEASE,
	BOTH_FORCEHEAL_START,		
	BOTH_FORCEHEAL_STOP,		
	BOTH_FORCEHEAL_QUICK,		
	BOTH_SABERPULL,			
	BOTH_FORCEGRIP1,		
	BOTH_FORCEGRIP3,		
	BOTH_FORCEGRIP3THROW,	
	BOTH_FORCEGRIP_HOLD,	
	BOTH_FORCEGRIP_RELEASE,
	BOTH_TOSS1,				
	BOTH_TOSS2,				
	
	BOTH_FORCE_RAGE,
	BOTH_FORCE_2HANDEDLIGHTNING,
	BOTH_FORCE_2HANDEDLIGHTNING_START,
	BOTH_FORCE_2HANDEDLIGHTNING_HOLD,
	BOTH_FORCE_2HANDEDLIGHTNING_RELEASE,
	BOTH_FORCE_DRAIN,
	BOTH_FORCE_DRAIN_START,
	BOTH_FORCE_DRAIN_HOLD,
	BOTH_FORCE_DRAIN_RELEASE,
	BOTH_FORCE_DRAIN_GRAB_START,
	BOTH_FORCE_DRAIN_GRAB_HOLD,
	BOTH_FORCE_DRAIN_GRAB_END,
	BOTH_FORCE_DRAIN_GRABBED,
	BOTH_FORCE_ABSORB,
	BOTH_FORCE_ABSORB_START,
	BOTH_FORCE_ABSORB_END,
	BOTH_FORCE_PROTECT,
	BOTH_FORCE_PROTECT_FAST,

	BOTH_WIND,

	BOTH_STAND_TO_KNEEL,
	BOTH_KNEEL_TO_STAND,

	BOTH_TUSKENATTACK1,
	BOTH_TUSKENATTACK2,
	BOTH_TUSKENATTACK3,
	BOTH_TUSKENLUNGE1,
	BOTH_TUSKENTAUNT1,

	BOTH_COWER1_START,		
	BOTH_COWER1,			
	BOTH_COWER1_STOP,		
	BOTH_SONICPAIN_START,
	BOTH_SONICPAIN_HOLD,
	BOTH_SONICPAIN_END,

	
	BOTH_STAND10,
	BOTH_STAND10_TALK1,
	BOTH_STAND10_TALK2,
	BOTH_STAND10TOSTAND1,

	BOTH_STAND1_TALK1,
	BOTH_STAND1_TALK2,
	BOTH_STAND1_TALK3,

	BOTH_SIT4,
	BOTH_SIT5,
	BOTH_SIT5_TALK1,
	BOTH_SIT5_TALK2,
	BOTH_SIT5_TALK3,

	BOTH_SIT6,
	BOTH_SIT7,

	
	
	
	
	TORSO_DROPWEAP1,		
	TORSO_DROPWEAP4,		
	TORSO_RAISEWEAP1,		
	TORSO_RAISEWEAP4,		
	TORSO_WEAPONREADY1,		
	TORSO_WEAPONREADY2,		
	TORSO_WEAPONREADY3,		
	TORSO_WEAPONREADY4,		
	TORSO_WEAPONREADY10,	
	TORSO_WEAPONIDLE2,		
	TORSO_WEAPONIDLE3,		
	TORSO_WEAPONIDLE4,		
	TORSO_WEAPONIDLE10,		

	
	TORSO_SURRENDER_START,	
	TORSO_SURRENDER_STOP,	

	TORSO_CHOKING1,			

	TORSO_HANDSIGNAL1,
	TORSO_HANDSIGNAL2,
	TORSO_HANDSIGNAL3,
	TORSO_HANDSIGNAL4,
	TORSO_HANDSIGNAL5,


	
	
	
	
	LEGS_TURN1,				
	LEGS_TURN2,				
	LEGS_LEAN_LEFT1,		
	LEGS_LEAN_RIGHT1,		
	LEGS_CHOKING1,			
	LEGS_LEFTUP1,			
	LEGS_LEFTUP2,			
	LEGS_LEFTUP3,			
	LEGS_LEFTUP4,			
	LEGS_LEFTUP5,			
	LEGS_RIGHTUP1,			
	LEGS_RIGHTUP2,			
	LEGS_RIGHTUP3,			
	LEGS_RIGHTUP4,			
	LEGS_RIGHTUP5,			
	LEGS_S1_LUP1,
	LEGS_S1_LUP2,
	LEGS_S1_LUP3,
	LEGS_S1_LUP4,
	LEGS_S1_LUP5,
	LEGS_S1_RUP1,
	LEGS_S1_RUP2,
	LEGS_S1_RUP3,
	LEGS_S1_RUP4,
	LEGS_S1_RUP5,
	LEGS_S3_LUP1,
	LEGS_S3_LUP2,
	LEGS_S3_LUP3,
	LEGS_S3_LUP4,
	LEGS_S3_LUP5,
	LEGS_S3_RUP1,
	LEGS_S3_RUP2,
	LEGS_S3_RUP3,
	LEGS_S3_RUP4,
	LEGS_S3_RUP5,
	LEGS_S4_LUP1,
	LEGS_S4_LUP2,
	LEGS_S4_LUP3,
	LEGS_S4_LUP4,
	LEGS_S4_LUP5,
	LEGS_S4_RUP1,
	LEGS_S4_RUP2,
	LEGS_S4_RUP3,
	LEGS_S4_RUP4,
	LEGS_S4_RUP5,
	LEGS_S5_LUP1,
	LEGS_S5_LUP2,
	LEGS_S5_LUP3,
	LEGS_S5_LUP4,
	LEGS_S5_LUP5,
	LEGS_S5_RUP1,
	LEGS_S5_RUP2,
	LEGS_S5_RUP3,
	LEGS_S5_RUP4,
	LEGS_S5_RUP5,
	LEGS_S6_LUP1,
	LEGS_S6_LUP2,
	LEGS_S6_LUP3,
	LEGS_S6_LUP4,
	LEGS_S6_LUP5,
	LEGS_S6_RUP1,
	LEGS_S6_RUP2,
	LEGS_S6_RUP3,
	LEGS_S6_RUP4,
	LEGS_S6_RUP5,
	LEGS_S7_LUP1,
	LEGS_S7_LUP2,
	LEGS_S7_LUP3,
	LEGS_S7_LUP4,
	LEGS_S7_LUP5,
	LEGS_S7_RUP1,
	LEGS_S7_RUP2,
	LEGS_S7_RUP3,
	LEGS_S7_RUP4,
	LEGS_S7_RUP5,

	
	LEGS_TURN180,

	
	
	
	
	BOTH_CIN_1,		
	BOTH_CIN_2,		
	BOTH_CIN_3,		
	BOTH_CIN_4,		
	BOTH_CIN_5,		
	BOTH_CIN_6,		
	BOTH_CIN_7,		
	BOTH_CIN_8,		
	BOTH_CIN_9,		
	BOTH_CIN_10,		
	BOTH_CIN_11,		
	BOTH_CIN_12,		
	BOTH_CIN_13,		
	BOTH_CIN_14,		
	BOTH_CIN_15,		
	BOTH_CIN_16,		
	BOTH_CIN_17,		
	BOTH_CIN_18,		
	BOTH_CIN_19,		
	BOTH_CIN_20,		
	BOTH_CIN_21,		
	BOTH_CIN_22,		
	BOTH_CIN_23,		
	BOTH_CIN_24,		
	BOTH_CIN_25,		
	BOTH_CIN_26,		
	BOTH_CIN_27,		
	BOTH_CIN_28,		
	BOTH_CIN_29,		
	BOTH_CIN_30,		
	BOTH_CIN_31,		
	BOTH_CIN_32,		
	BOTH_CIN_33,		
	BOTH_CIN_34,		
	BOTH_CIN_35,		
	BOTH_CIN_36,		
	BOTH_CIN_37,		
	BOTH_CIN_38,		
	BOTH_CIN_39,		
	BOTH_CIN_40,		
	BOTH_CIN_41,		
	BOTH_CIN_42,		
	BOTH_CIN_43,		
	BOTH_CIN_44,		
	BOTH_CIN_45,		
	BOTH_CIN_46,		
	BOTH_CIN_47,		
	BOTH_CIN_48,		
	BOTH_CIN_49,		
	BOTH_CIN_50,		

	
	MAX_ANIMATIONS,
	MAX_TOTALANIMATIONS,
} animNumber_t;




#line 1797 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\anims.h"


#line 13 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\bg_public.h"
#line 1 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\bg_vehicles.h"



#line 1 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\q_shared.h"






















































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































#line 5 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\bg_vehicles.h"

typedef struct Vehicle_s Vehicle_t;
typedef struct bgEntity_s bgEntity_t;

typedef enum
{
	VH_NONE = 0,	
	VH_WALKER,		
	VH_FIGHTER,		
	VH_SPEEDER,		
	VH_ANIMAL,		
	VH_FLIER,		
	VH_NUM_VEHICLES
} vehicleType_t;

typedef enum	
{
	WPOSE_NONE	= 0,
	WPOSE_BLASTER,
	WPOSE_SABERLEFT,
	WPOSE_SABERRIGHT,
} EWeaponPose;

#line 1 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\namespace_begin.h"















#line 29 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\bg_vehicles.h"
extern stringID_table_t VehicleTable[VH_NUM_VEHICLES+1];
#line 1 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\namespace_end.h"

















#line 31 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\bg_vehicles.h"




typedef struct
{


	char	*name;
	qboolean	bIsProjectile;	
	qboolean	bHasGravity;	
	qboolean	bIonWeapon;
	qboolean	bSaberBlockable;
	int		iMuzzleFX;	
	int		iModel;		
	int		iShotFX;	
	int		iImpactFX;	
	int		iG2MarkShaderHandle;	
	float	fG2MarkSize;
	int		iLoopSound;	
	float	fSpeed;		
	float	fHoming;		
	float	fHomingFOV;		
	int		iLockOnTime;	
	int		iDamage;		
	int		iSplashDamage;
	float	fSplashRadius;
	int		iAmmoPerShot;	
	int		iHealth;		
	float	fWidth;		
	float	fHeight;		
	int		iLifeTime;	
	qboolean	bExplodeOnExpire;	
} vehWeaponInfo_t;









#line 1 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\namespace_begin.h"















#line 75 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\bg_vehicles.h"
extern vehWeaponInfo_t g_vehWeaponInfo[16];
extern int	numVehicleWeapons;
#line 1 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\namespace_end.h"

















#line 78 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\bg_vehicles.h"











typedef struct
{
	int			iWeapon;	
	int			iDelay;		
	int			iAmmoMax;	
	int			iAmmoRechargeMS;	
	char		*yawBone;	
	char		*pitchBone;	
	int			yawAxis;	
	int			pitchAxis;	
	float		yawClampLeft;	
	float		yawClampRight;	
	float		pitchClampUp;	
	float		pitchClampDown; 
	int			iMuzzle[2];
	char		*gunnerViewTag;
	float		fTurnSpeed;	
	qboolean	bAI;	
	qboolean	bAILead;
	float		fAIRange;	
	int			passengerNum;
} turretStats_t;

typedef struct
{

	
	int			ID;
	
	int			delay;
	
	int			linkable;
	
	qboolean	aimCorrect;
	
	int			ammoMax;
	
	int			ammoRechargeMS;
	
	int			soundNoAmmo;
} vehWeaponStats_t;

typedef struct
{

	char		*name;	

	
	vehicleType_t	type;	
	int			numHands;	
	float		lookPitch;	
	float		lookYaw;	
	float		length;		
	float		width;		
	float		height;		
	vec3_t		centerOfGravity;

	
	float		speedMax;		
	float		turboSpeed;		
	float		speedMin;		
	float		speedIdle;		
	float		accelIdle;		
	float		acceleration;	
	float		decelIdle;		
	float		throttleSticks;	
	float		strafePerc;		

	
	float		bankingSpeed;	
	float		rollLimit;		
	float		pitchLimit;		
	float		braking;		
	float		mouseYaw;		
	float		mousePitch;		
	float		turningSpeed;	
	qboolean	turnWhenStopped;
	float		traction;		
	float		friction;		
	float		maxSlope;		
	qboolean	speedDependantTurning;

	
	int			mass;			
	int			armor;			
	int			shields;		
	int			shieldRechargeMS;
	float		toughness;		
	int			malfunctionArmorLevel;
	int			surfDestruction; 

	
	int			health_front;
	int			health_back;
	int			health_right;
	int			health_left;

	
	char		*model;			
	char		*skin;			
	int			g2radius;		
	int			riderAnim;		
	int			radarIconHandle;
	int			dmgIndicFrameHandle;
	int			dmgIndicShieldHandle;
	int			dmgIndicBackgroundHandle;
	int			iconFrontHandle;
	int			iconBackHandle;	
	int			iconRightHandle;
	int			iconLeftHandle;	
	int			crosshairShaderHandle;
	int			shieldShaderHandle;
	char		*droidNPC;		

	int			soundOn;		
	int			soundTakeOff;	
	int			soundEngineStart;
	int			soundLoop;		
	int			soundSpin;		
	int			soundTurbo;		
	int			soundHyper;		
	int			soundLand;		
	int			soundOff;		
	int			soundFlyBy;		
	int			soundFlyBy2;	
	int			soundShift1;	
	int			soundShift2;	
	int			soundShift3;	
	int			soundShift4;	

	int			iExhaustFX;		
	int			iTurboFX;		
	int			iTurboStartFX;	
	int			iTrailFX;		
	int			iImpactFX;		
	int			iExplodeFX;		
	int			iWakeFX;			
	int			iDmgFX;			
	int			iInjureFX;
	int			iNoseFX;		
	int			iLWingFX;		
	int			iRWingFX;		

	
	vehWeaponStats_t	weapon[2];

	
	
	int			weapMuzzle[12];
	
	
	turretStats_t	turret[2];

	
	float		landingHeight;

	
	int			gravity;		
	float		hoverHeight;	
	float		hoverStrength;	
	qboolean	waterProof;		
	float		bouyancy;		
	int			fuelMax;		
	int			fuelRate;		
	int			turboDuration;	
	int			turboRecharge;	
	int			visibility;		
	int			loudness;		
	float		explosionRadius;
	int			explosionDamage;

	int			maxPassengers;	
	qboolean	hideRider;		
	qboolean	killRiderOnDeath;
	qboolean	flammable;		
	int			explosionDelay;	
	
	qboolean	cameraOverride;	
	float		cameraRange;	
	float		cameraVertOffset;
	float		cameraHorzOffset;
	float		cameraPitchOffset;
	float		cameraFOV;		
	float		cameraAlpha;	
	qboolean	cameraPitchDependantVertOffset;

	





	int			modelIndex;		

	
	
	
	
	
	

	
	void (*AnimateVehicle)( Vehicle_t *pVeh );

	
	void (*AnimateRiders)( Vehicle_t *pVeh );

	
	qboolean (*ValidateBoard)( Vehicle_t *pVeh, bgEntity_t *pEnt );

	
	void (*SetParent)( Vehicle_t *pVeh, bgEntity_t *pParentEntity );

	
	void (*SetPilot)( Vehicle_t *pVeh, bgEntity_t *pPilot );

	
	qboolean (*AddPassenger)( Vehicle_t *pVeh );

	
	void (*Animate)( Vehicle_t *pVeh );

	
	qboolean (*Board)( Vehicle_t *pVeh, bgEntity_t *pEnt );

	
	qboolean (*Eject)( Vehicle_t *pVeh, bgEntity_t *pEnt, qboolean forceEject );

	
	qboolean (*EjectAll)( Vehicle_t *pVeh );	

	
	void (*StartDeathDelay)( Vehicle_t *pVeh, int iDelayTime );

	
	void (*DeathUpdate)( Vehicle_t *pVeh );
	
	
	void (*RegisterAssets)( Vehicle_t *pVeh );
	
	
	qboolean (*Initialize)( Vehicle_t *pVeh );

	
	qboolean (*Update)( Vehicle_t *pVeh, const usercmd_t *pUcmd );

	
	
	
	qboolean (*UpdateRider)( Vehicle_t *pVeh, bgEntity_t *pRider, usercmd_t *pUcmd );

	
	void (*ProcessMoveCommands)( Vehicle_t *pVeh );

	
	void (*ProcessOrientCommands)( Vehicle_t *pVeh );
	
	
	void (*AttachRiders)( Vehicle_t *pVeh );

	
	void (*Ghost)( Vehicle_t *pVeh, bgEntity_t *pEnt );

	
	void (*UnGhost)( Vehicle_t *pVeh, bgEntity_t *pEnt );

	
	const bgEntity_t *(*GetPilot)( Vehicle_t *pVeh );

	
	qboolean (*Inhabited)( Vehicle_t *pVeh );
} vehicleInfo_t;








#line 1 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\namespace_begin.h"















#line 370 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\bg_vehicles.h"
extern vehicleInfo_t g_vehicleInfo[16];
extern int	numVehicles;
#line 1 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\namespace_end.h"

















#line 373 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\bg_vehicles.h"

































typedef enum
{
	VEH_EJECT_LEFT, 
	VEH_EJECT_RIGHT, 
	VEH_EJECT_FRONT, 
	VEH_EJECT_REAR, 
	VEH_EJECT_TOP, 
	VEH_EJECT_BOTTOM
};


typedef enum
{
	VEH_NONE = 0, VEH_FLYING = 0x00000001, VEH_CRASHING = 0x00000002,
	VEH_LANDING = 0x00000004, VEH_BUCKING = 0x00000010, VEH_WINGSOPEN = 0x00000020,
	VEH_GEARSOPEN = 0x00000040, VEH_SLIDEBREAKING = 0x00000080, VEH_SPINNING = 0x00000100,
	VEH_OUTOFCONTROL = 0x00000200,
	VEH_SABERINLEFTHAND = 0x00000400
} vehFlags_t;

























typedef struct
{
	
	qboolean	linked;
	
	int			ammo;
	
	int			lastAmmoInc;
	
	int			nextMuzzle;
} vehWeaponStatus_t;

typedef struct
{
	
	int			ammo;
	
	int			lastAmmoInc;
	
	int			nextMuzzle;
	
	int			enemyEntNum;
	
	int			enemyHoldTime;
} vehTurretStatus_t;


typedef struct Vehicle_s
{
	
	
	bgEntity_t *m_pPilot;

	int m_iPilotTime; 
	int m_iPilotLastIndex; 
	qboolean m_bHasHadPilot; 

	
	
	bgEntity_t *m_ppPassengers[10];

	
	bgEntity_t *m_pDroidUnit;

	
	int m_iNumPassengers;

	
	bgEntity_t *m_pParentEntity;

	
	
	int		m_iBoarding;

	
	qboolean	m_bWasBoarding;

	
	vec3_t	m_vBoardingVelocity;

	
	float m_fTimeModifier;

	
	
	int m_iLeftExhaustTag;
	int m_iRightExhaustTag;
	int m_iGun1Tag;
	int m_iGun1Bone;
	int m_iLeftWingBone;
	int m_iRightWingBone;

	int m_iExhaustTag[12];
	int m_iMuzzleTag[12];
	int m_iDroidUnitTag;
	int	m_iGunnerViewTag[2];

	
	int m_iMuzzleTime[12];
	
	vec3_t m_vMuzzlePos[12], m_vMuzzleDir[12];

	
	
	int m_iMuzzleWait[12];

	
	usercmd_t m_ucmd;

	
	int m_EjectDir;

	
	unsigned long m_ulFlags;

	

	
	int m_iVehicleTypeID;

	
	
	float		*m_vOrientation;
	
	

	
	int			m_fStrafeTime;	

	
	vec3_t		m_vPrevOrientation;

	
	vec3_t		m_vPrevRiderViewAngles;

	
	float		m_vAngularVelocity;

	vec3_t		m_vFullAngleVelocity;

	
	int			m_iArmor;	
	int			m_iShields;	

	
	int			m_iHitDebounce;

	
	int			m_iLastFXTime; 

	
	int			m_iDieTime;

	
	
	
	vehicleInfo_t *m_pVehicleInfo;

	
	trace_t m_LandTrace;

	
	vec3_t m_vWingAngles;

	
	int			m_iLastImpactDmg;

	
	int			m_iRemovedSurfaces;
	
	int			m_iDmgEffectTime;

	
	int			m_iTurboTime;

	
	int			m_iDropTime;

	int			m_iSoundDebounceTimer;

	
	int			lastShieldInc;

	
	qboolean	linkWeaponToggleHeld;

	
	vehWeaponStatus_t	weaponStatus[2];
	vehTurretStatus_t	turretStatus[2];

	
	bgEntity_t *	m_pOldPilot;

} Vehicle_t;

#line 1 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\namespace_begin.h"















#line 626 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\bg_vehicles.h"
extern int BG_VehicleGetIndex( const char *vehicleName );
#line 1 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\namespace_end.h"

















#line 628 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\bg_vehicles.h"

#line 630 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\bg_vehicles.h"
#line 14 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\bg_public.h"













































































































#line 124 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\bg_public.h"

typedef enum {
	G2_MODELPART_HEAD = 10,
	G2_MODELPART_WAIST,
	G2_MODELPART_LARM,
	G2_MODELPART_RARM,
	G2_MODELPART_RHAND,
	G2_MODELPART_LLEG,
	G2_MODELPART_RLEG
} g2ModelParts_t;







#line 1 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\namespace_begin.h"















#line 142 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\bg_public.h"
extern const char *bg_customSiegeSoundNames[30];

extern const char *bgToggleableSurfaces[31];
extern const int bgToggleableSurfaceDebris[31];
#line 1 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\namespace_end.h"

















#line 147 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\bg_public.h"

typedef enum {
	HANDEXTEND_NONE = 0,
	HANDEXTEND_FORCEPUSH,
	HANDEXTEND_FORCEPULL,
	HANDEXTEND_FORCE_HOLD,
	HANDEXTEND_SABERPULL,
	HANDEXTEND_CHOKE, 
	HANDEXTEND_WEAPONREADY,
	HANDEXTEND_DODGE,
	HANDEXTEND_KNOCKDOWN,
	HANDEXTEND_DUELCHALLENGE,
	HANDEXTEND_TAUNT,

	HANDEXTEND_PRETHROW,
	HANDEXTEND_POSTTHROW,
	HANDEXTEND_PRETHROWN,
	HANDEXTEND_POSTTHROWN,

	HANDEXTEND_DRAGGING,

	HANDEXTEND_JEDITAUNT,
} forceHandAnims_t;

typedef enum
{
	BROKENLIMB_NONE = 0,
	BROKENLIMB_LARM,
	BROKENLIMB_RARM,
	NUM_BROKENLIMBS
} brokenLimb_t;




typedef enum {
	GT_FFA,				
	GT_HOLOCRON,		
	GT_JEDIMASTER,		
	GT_DUEL,		
	GT_POWERDUEL,
	GT_SINGLE_PLAYER,	

	

	GT_TEAM,			
	GT_SIEGE,			
	GT_CTF,				
	GT_CTY,
	GT_MAX_GAME_TYPE
};
typedef int gametype_t;

typedef enum { GENDER_MALE, GENDER_FEMALE, GENDER_NEUTER } gender_t;

extern vec3_t WP_MuzzlePoint[WP_NUM_WEAPONS];

#line 1 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\namespace_begin.h"















#line 205 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\bg_public.h"
extern int forcePowerSorted[NUM_FORCE_POWERS];
#line 1 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\namespace_end.h"

















#line 207 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\bg_public.h"

typedef enum
{
	SABERLOCK_TOP,
	SABERLOCK_SIDE,
	SABERLOCK_LOCK,
	SABERLOCK_BREAK,
	SABERLOCK_SUPERBREAK,
	SABERLOCK_WIN,
	SABERLOCK_LOSE
};

typedef enum
{
	DIR_RIGHT,
	DIR_LEFT,
	DIR_FRONT,
	DIR_BACK
};













#pragma pack(push, 1)
typedef struct animation_s {
	unsigned short		firstFrame;
	unsigned short		numFrames;
	short				frameLerp;			
	
	signed char			loopFrames;			
} animation_t;
#pragma pack(pop)

#line 1 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\namespace_begin.h"















#line 250 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\bg_public.h"
extern qboolean			BGPAFtextLoaded;
extern animation_t		bgHumanoidAnimations[MAX_TOTALANIMATIONS];
#line 1 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\namespace_end.h"

















#line 253 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\bg_public.h"




typedef enum
{
	FOOTSTEP_R,
	FOOTSTEP_L,
	FOOTSTEP_HEAVY_R,
	FOOTSTEP_HEAVY_L,
	NUM_FOOTSTEP_TYPES
} footstepType_t;

extern stringID_table_t animEventTypeTable[300+1];
extern stringID_table_t footstepTypeTable[NUM_FOOTSTEP_TYPES+1];



































typedef enum
{
	AEV_NONE,
	AEV_SOUND,		
	AEV_FOOTSTEP,	
	AEV_EFFECT,		
	AEV_FIRE,		
	AEV_MOVE,		
	AEV_SOUNDCHAN,  
	AEV_SABER_SWING,  
	AEV_SABER_SPIN,  
	AEV_NUM_AEV
} animEventType_t;

typedef struct animevent_s 
{
	animEventType_t	eventType;
	unsigned short	keyFrame;			
	signed short	eventData[(4+3)];	
	char			*stringData;		
} animevent_t;

typedef struct
{
	char			filename[64];
	animation_t		*anims;



} bgLoadedAnim_t;

typedef struct
{
	char			filename[64];
	animevent_t		torsoAnimEvents[300];
	animevent_t		legsAnimEvents[300];
	qboolean		eventsParsed;
} bgLoadedEvents_t;

#line 1 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\namespace_begin.h"















#line 343 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\bg_public.h"

extern bgLoadedAnim_t bgAllAnims[16];












#line 1 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\namespace_end.h"

















#line 358 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\bg_public.h"

typedef enum {
	PM_NORMAL,		
	PM_JETPACK,		
	PM_FLOAT,		
	PM_NOCLIP,		
	PM_SPECTATOR,	
	PM_DEAD,		
	PM_FREEZE,		
	PM_INTERMISSION,	
	PM_SPINTERMISSION	
} pmtype_t;

typedef enum {
	WEAPON_READY, 
	WEAPON_RAISING,
	WEAPON_DROPPING,
	WEAPON_FIRING,
	WEAPON_CHARGING,
	WEAPON_CHARGING_ALT,
	WEAPON_IDLE, 
} weaponstate_t;


typedef enum {
	FORCE_MASTERY_UNINITIATED,
	FORCE_MASTERY_INITIATE,
	FORCE_MASTERY_PADAWAN,
	FORCE_MASTERY_JEDI,
	FORCE_MASTERY_JEDI_GUARDIAN,
	FORCE_MASTERY_JEDI_ADEPT,
	FORCE_MASTERY_JEDI_KNIGHT,
	FORCE_MASTERY_JEDI_MASTER,
	NUM_FORCE_MASTERY_LEVELS
};

#line 1 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\namespace_begin.h"















#line 395 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\bg_public.h"
extern char *forceMasteryLevels[NUM_FORCE_MASTERY_LEVELS];
extern int forceMasteryPoints[NUM_FORCE_MASTERY_LEVELS];

extern int bgForcePowerCost[NUM_FORCE_POWERS][NUM_FORCE_POWER_LEVELS];
#line 1 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\namespace_end.h"

















#line 400 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\bg_public.h"






















typedef struct bgEntity_s
{
	entityState_t	s;
	playerState_t	*playerState;
	Vehicle_t		*m_pVehicle; 
	void			*ghoul2; 
	int				localAnimIndex; 
	vec3_t			modelScale; 

	
} bgEntity_t;

typedef struct {
	
	playerState_t	*ps;

	
	void		*ghoul2;
	int			g2Bolts_LFoot;
	int			g2Bolts_RFoot;
	vec3_t		modelScale;

	
	qboolean	nonHumanoid;

	
	usercmd_t	cmd;
	int			tracemask;			
	int			debugLevel;			
	qboolean	noFootsteps;		
	qboolean	gauntletHit;		

	int			framecount;

	
	int			numtouch;
	int			touchents[32];

	int			useEvent;

	vec3_t		mins, maxs;			

	int			watertype;
	int			waterlevel;

	int			gametype;

	int			debugMelee;
	int			stepSlideFix;
	int			noSpecMove;

	animation_t	*animations;

	float		xyspeed;

	
	int			pmove_fixed;
	int			pmove_msec;

	
	
	void		(*trace)( trace_t *results, const vec3_t start, const vec3_t mins, const vec3_t maxs, const vec3_t end, int passEntityNum, int contentMask );
	int			(*pointcontents)( const vec3_t point, int passEntityNum );

	int			checkDuelLoss;

	
	bgEntity_t	*baseEnt; 
	int			entSize; 
} pmove_t;

#line 1 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\namespace_begin.h"















#line 494 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\bg_public.h"

extern	pmove_t		*pm;













void PM_UpdateViewAngles( playerState_t *ps, const usercmd_t *cmd );
void Pmove (pmove_t *pmove);

#line 1 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\namespace_end.h"

















#line 513 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\bg_public.h"






typedef enum {
	STAT_HEALTH,
	STAT_HOLDABLE_ITEM,
	STAT_HOLDABLE_ITEMS,
	STAT_PERSISTANT_POWERUP,
	
	
	STAT_WEAPONS = 4,					
	STAT_ARMOR,				
	STAT_DEAD_YAW,					
	STAT_CLIENTS_READY,				
	STAT_MAX_HEALTH					
} statIndex_t;






typedef enum {
	PERS_SCORE,						
	PERS_HITS,						
	PERS_RANK,						
	PERS_TEAM,						
	PERS_SPAWN_COUNT,				
	PERS_PLAYEREVENTS,				
	PERS_ATTACKER,					
	PERS_ATTACKEE_ARMOR,			
	PERS_KILLED,					
	
	PERS_IMPRESSIVE_COUNT,			
	PERS_EXCELLENT_COUNT,			
	PERS_DEFEND_COUNT,				
	PERS_ASSIST_COUNT,				
	PERS_GAUNTLET_FRAG_COUNT,		
	PERS_CAPTURES					
} persEnum_t;






































































typedef enum {
	EFFECT_NONE = 0,
	EFFECT_SMOKE,
	EFFECT_EXPLOSION,
	EFFECT_EXPLOSION_PAS,
	EFFECT_SPARK_EXPLOSION,
	EFFECT_EXPLOSION_TRIPMINE,
	EFFECT_EXPLOSION_DETPACK,
	EFFECT_EXPLOSION_FLECHETTE,
	EFFECT_STUNHIT,
	EFFECT_EXPLOSION_DEMP2ALT,
	EFFECT_EXPLOSION_TURRET,
	EFFECT_SPARKS,
	EFFECT_WATER_SPLASH,
	EFFECT_ACID_SPLASH,
	EFFECT_LAVA_SPLASH,
	EFFECT_LANDING_MUD,
	EFFECT_LANDING_SAND,
	EFFECT_LANDING_DIRT,
	EFFECT_LANDING_SNOW,
	EFFECT_LANDING_GRAVEL,
	EFFECT_MAX
} effectTypes_t;


typedef enum {
	PW_NONE,

	PW_QUAD,
	PW_BATTLESUIT,
	PW_PULL,
	
	
	

	PW_REDFLAG,
	PW_BLUEFLAG,
	PW_NEUTRALFLAG,

	PW_SHIELDHIT,

	
	
	
	
	PW_SPEEDBURST,
	PW_DISINT_4,
	PW_SPEED,
	PW_CLOAKED,
	PW_FORCE_ENLIGHTENED_LIGHT,
	PW_FORCE_ENLIGHTENED_DARK,
	PW_FORCE_BOON,
	PW_YSALAMIRI,

	PW_NUM_POWERUPS

};
typedef int powerup_t;

typedef enum {
	HI_NONE,

	HI_SEEKER,
	HI_SHIELD,
	HI_MEDPAC,
	HI_MEDPAC_BIG,
	HI_BINOCULARS,
	HI_SENTRY_GUN,
	HI_JETPACK,

	HI_HEALTHDISP,
	HI_AMMODISP,
	HI_EWEB,
	HI_CLOAK,

	HI_NUM_HOLDABLE
};
typedef int holdable_t;


typedef enum {
	CTFMESSAGE_FRAGGED_FLAG_CARRIER,
	CTFMESSAGE_FLAG_RETURNED,
	CTFMESSAGE_PLAYER_RETURNED_FLAG,
	CTFMESSAGE_PLAYER_CAPTURED_FLAG,
	CTFMESSAGE_PLAYER_GOT_FLAG
} ctfMsg_t;




















typedef enum
{
	PDSOUND_NONE,
	PDSOUND_PROTECTHIT,
	PDSOUND_PROTECT,
	PDSOUND_ABSORBHIT,
	PDSOUND_ABSORB,
	PDSOUND_FORCEJUMP,
	PDSOUND_FORCEGRIP
} pdSounds_t;

typedef enum {
	EV_NONE,

	EV_CLIENTJOIN,

	EV_FOOTSTEP,
	EV_FOOTSTEP_METAL,
	EV_FOOTSPLASH,
	EV_FOOTWADE,
	EV_SWIM,

	EV_STEP_4,
	EV_STEP_8,
	EV_STEP_12,
	EV_STEP_16,

	EV_FALL,

	EV_JUMP_PAD,			

	EV_GHOUL2_MARK,			

	EV_GLOBAL_DUEL,
	EV_PRIVATE_DUEL,

	EV_JUMP,
	EV_ROLL,
	EV_WATER_TOUCH,	
	EV_WATER_LEAVE,	
	EV_WATER_UNDER,	
	EV_WATER_CLEAR,	

	EV_ITEM_PICKUP,			
	EV_GLOBAL_ITEM_PICKUP,	

	EV_VEH_FIRE,

	EV_NOAMMO,
	EV_CHANGE_WEAPON,
	EV_FIRE_WEAPON,
	EV_ALT_FIRE,
	EV_SABER_ATTACK,
	EV_SABER_HIT,
	EV_SABER_BLOCK,
	EV_SABER_CLASHFLARE,
	EV_SABER_UNHOLSTER,
	EV_BECOME_JEDIMASTER,
	EV_DISRUPTOR_MAIN_SHOT,
	EV_DISRUPTOR_SNIPER_SHOT,
	EV_DISRUPTOR_SNIPER_MISS,
	EV_DISRUPTOR_HIT,
	EV_DISRUPTOR_ZOOMSOUND,

	EV_PREDEFSOUND,

	EV_TEAM_POWER,

	EV_SCREENSHAKE,

	EV_LOCALTIMER,

	EV_USE,			

	EV_USE_ITEM0,
	EV_USE_ITEM1,
	EV_USE_ITEM2,
	EV_USE_ITEM3,
	EV_USE_ITEM4,
	EV_USE_ITEM5,
	EV_USE_ITEM6,
	EV_USE_ITEM7,
	EV_USE_ITEM8,
	EV_USE_ITEM9,
	EV_USE_ITEM10,
	EV_USE_ITEM11,
	EV_USE_ITEM12,
	EV_USE_ITEM13,
	EV_USE_ITEM14,
	EV_USE_ITEM15,

	EV_ITEMUSEFAIL,

	EV_ITEM_RESPAWN,
	EV_ITEM_POP,
	EV_PLAYER_TELEPORT_IN,
	EV_PLAYER_TELEPORT_OUT,

	EV_GRENADE_BOUNCE,		
	EV_MISSILE_STICK,		

	EV_PLAY_EFFECT,
	EV_PLAY_EFFECT_ID,
	EV_PLAY_PORTAL_EFFECT_ID,

	EV_PLAYDOORSOUND,
	EV_PLAYDOORLOOPSOUND,
	EV_BMODEL_SOUND,

	EV_MUTE_SOUND,
	EV_VOICECMD_SOUND,
	EV_GENERAL_SOUND,
	EV_GLOBAL_SOUND,		
	EV_GLOBAL_TEAM_SOUND,
	EV_ENTITY_SOUND,

	EV_PLAY_ROFF,

	EV_GLASS_SHATTER,
	EV_DEBRIS,
	EV_MISC_MODEL_EXP,

	EV_CONC_ALT_IMPACT,

	EV_MISSILE_HIT,
	EV_MISSILE_MISS,
	EV_MISSILE_MISS_METAL,
	EV_BULLET,				

	EV_PAIN,
	EV_DEATH1,
	EV_DEATH2,
	EV_DEATH3,
	EV_OBITUARY,

	EV_POWERUP_QUAD,
	EV_POWERUP_BATTLESUIT,
	

	EV_FORCE_DRAINED,

	EV_GIB_PLAYER,			
	EV_SCOREPLUM,			

	EV_CTFMESSAGE,

	EV_BODYFADE,

	EV_SIEGE_ROUNDOVER,
	EV_SIEGE_OBJECTIVECOMPLETE,

	EV_DESTROY_GHOUL2_INSTANCE,

	EV_DESTROY_WEAPON_MODEL,

	EV_GIVE_NEW_RANK,
	EV_SET_FREE_SABER,
	EV_SET_FORCE_DISABLE,

	EV_WEAPON_CHARGE,
	EV_WEAPON_CHARGE_ALT,

	EV_SHIELD_HIT,

	EV_DEBUG_LINE,
	EV_TESTLINE,
	EV_STOPLOOPINGSOUND,
	EV_STARTLOOPINGSOUND,
	EV_TAUNT,

	
	EV_ANGER1,	
	EV_ANGER2,
	EV_ANGER3,

	EV_VICTORY1,	
	EV_VICTORY2,
	EV_VICTORY3,

	EV_CONFUSE1,	
	EV_CONFUSE2,
	EV_CONFUSE3,

	EV_PUSHED1,		
	EV_PUSHED2,
	EV_PUSHED3,

	EV_CHOKE1,		
	EV_CHOKE2,
	EV_CHOKE3,

	EV_FFWARN,		
	EV_FFTURN,
	
	EV_CHASE1,
	EV_CHASE2,
	EV_CHASE3,
	EV_COVER1,
	EV_COVER2,
	EV_COVER3,
	EV_COVER4,
	EV_COVER5,
	EV_DETECTED1,
	EV_DETECTED2,
	EV_DETECTED3,
	EV_DETECTED4,
	EV_DETECTED5,
	EV_LOST1,
	EV_OUTFLANK1,
	EV_OUTFLANK2,
	EV_ESCAPING1,
	EV_ESCAPING2,
	EV_ESCAPING3,
	EV_GIVEUP1,
	EV_GIVEUP2,
	EV_GIVEUP3,
	EV_GIVEUP4,
	EV_LOOK1,
	EV_LOOK2,
	EV_SIGHT1,
	EV_SIGHT2,
	EV_SIGHT3,
	EV_SOUND1,
	EV_SOUND2,
	EV_SOUND3,
	EV_SUSPICIOUS1,
	EV_SUSPICIOUS2,
	EV_SUSPICIOUS3,
	EV_SUSPICIOUS4,
	EV_SUSPICIOUS5,
	
	EV_COMBAT1,
	EV_COMBAT2,
	EV_COMBAT3,
	EV_JDETECTED1,
	EV_JDETECTED2,
	EV_JDETECTED3,
	EV_TAUNT1,
	EV_TAUNT2,
	EV_TAUNT3,
	EV_JCHASE1,
	EV_JCHASE2,
	EV_JCHASE3,
	EV_JLOST1,
	EV_JLOST2,
	EV_JLOST3,
	EV_DEFLECT1,
	EV_DEFLECT2,
	EV_DEFLECT3,
	EV_GLOAT1,
	EV_GLOAT2,
	EV_GLOAT3,
	EV_PUSHFAIL,

	EV_SIEGESPEC,
	
} entity_event_t;			


typedef enum {
	GTS_RED_CAPTURE,
	GTS_BLUE_CAPTURE,
	GTS_RED_RETURN,
	GTS_BLUE_RETURN,
	GTS_RED_TAKEN,
	GTS_BLUE_TAKEN,
	GTS_REDTEAM_SCORED,
	GTS_BLUETEAM_SCORED,
	GTS_REDTEAM_TOOK_LEAD,
	GTS_BLUETEAM_TOOK_LEAD,
	GTS_TEAMS_ARE_TIED
} global_team_sound_t;



typedef enum {
	TEAM_FREE,
	TEAM_RED,
	TEAM_BLUE,
	TEAM_SPECTATOR,

	TEAM_NUM_TEAMS
};
typedef int team_t;

typedef enum {
	DUELTEAM_FREE,
	DUELTEAM_LONE,
	DUELTEAM_DOUBLE,

	DUELTEAM_SINGLE,		
} duelTeam_t;








typedef enum {
	TEAMTASK_NONE,
	TEAMTASK_OFFENSE, 
	TEAMTASK_DEFENSE,
	TEAMTASK_PATROL,
	TEAMTASK_FOLLOW,
	TEAMTASK_RETRIEVE,
	TEAMTASK_ESCORT,
	TEAMTASK_CAMP
} teamtask_t;


typedef enum {
	MOD_UNKNOWN,
	MOD_STUN_BATON,
	MOD_MELEE,
	MOD_SABER,
	MOD_BRYAR_PISTOL,
	MOD_BRYAR_PISTOL_ALT,
	MOD_BLASTER,
	MOD_TURBLAST,
	MOD_DISRUPTOR,
	MOD_DISRUPTOR_SPLASH,
	MOD_DISRUPTOR_SNIPER,
	MOD_BOWCASTER,
	MOD_REPEATER,
	MOD_REPEATER_ALT,
	MOD_REPEATER_ALT_SPLASH,
	MOD_DEMP2,
	MOD_DEMP2_ALT,
	MOD_FLECHETTE,
	MOD_FLECHETTE_ALT_SPLASH,
	MOD_ROCKET,
	MOD_ROCKET_SPLASH,
	MOD_ROCKET_HOMING,
	MOD_ROCKET_HOMING_SPLASH,
	MOD_THERMAL,
	MOD_THERMAL_SPLASH,
	MOD_TRIP_MINE_SPLASH,
	MOD_TIMED_MINE_SPLASH,
	MOD_DET_PACK_SPLASH,
	MOD_VEHICLE,
	MOD_CONC,
	MOD_CONC_ALT,
	MOD_FORCE_DARK,
	MOD_SENTRY,
	MOD_WATER,
	MOD_SLIME,
	MOD_LAVA,
	MOD_CRUSH,
	MOD_TELEFRAG,
	MOD_FALLING,
	MOD_SUICIDE,
	MOD_TARGET_LASER,
	MOD_TRIGGER_HURT,
	MOD_TEAM_CHANGE,
	
	
	
	
	
	
	MOD_MAX
} meansOfDeath_t;





typedef enum {
	IT_BAD,
	IT_WEAPON,				
	IT_AMMO,				
	IT_ARMOR,				
	IT_HEALTH,				
	IT_POWERUP,				
							
	IT_HOLDABLE,			
							
	IT_PERSISTANT_POWERUP,
	IT_TEAM
};
typedef int itemType_t;



typedef struct gitem_s {
	char		*classname;	
	char		*pickup_sound;
	char		*world_model[4];
	char		*view_model;
	char		*icon;


	int			quantity;		
	itemType_t  giType;			

	int			giTag;

	char		*precaches;		
	char		*sounds;		
	char		*description;
} gitem_t;


#line 1 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\namespace_begin.h"















#line 1139 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\bg_public.h"

extern	gitem_t	bg_itemlist[];
extern	int		bg_numItems;

float vectoyaw( const vec3_t vec );

gitem_t	*BG_FindItem( const char *classname );
gitem_t	*BG_FindItemForWeapon( weapon_t weapon );
gitem_t	*BG_FindItemForPowerup( powerup_t pw );
gitem_t	*BG_FindItemForHoldable( holdable_t pw );


qboolean	BG_CanItemBeGrabbed( int gametype, const entityState_t *ent, const playerState_t *ps );

#line 1 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\namespace_end.h"

















#line 1154 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\bg_public.h"

































typedef enum {
	ET_GENERAL,
	ET_PLAYER,
	ET_ITEM,
	ET_MISSILE,
	ET_SPECIAL,				
	ET_HOLOCRON,			
	ET_MOVER,
	ET_BEAM,
	ET_PORTAL,
	ET_SPEAKER,
	ET_PUSH_TRIGGER,
	ET_TELEPORT_TRIGGER,
	ET_INVISIBLE,
	ET_NPC,					
	ET_TEAM,
	ET_BODY,
	ET_TERRAIN,
	ET_FX,

	ET_EVENTS				
							
							
} entityType_t;














#line 1226 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\bg_public.h"


typedef enum {
	F_INT, 
	F_FLOAT,
	F_LSTRING,			
	F_GSTRING,			
	F_VECTOR,
	F_ANGLEHACK,
	F_ENTITY,			
	F_ITEM,				
	F_CLIENT,			
	F_PARM1,			
	F_PARM2,			
	F_PARM3,			
	F_PARM4,			
	F_PARM5,			
	F_PARM6,			
	F_PARM7,			
	F_PARM8,			
	F_PARM9,			
	F_PARM10,			
	F_PARM11,			
	F_PARM12,			
	F_PARM13,			
	F_PARM14,			
	F_PARM15,			
	F_PARM16,			
	F_IGNORE
} fieldtype_t;




typedef struct
{
	char	*name;
	int		ofs;
	fieldtype_t	type;
	int		flags;
} BG_field_t;



#line 1271 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\bg_public.h"















typedef enum {
	
	LS_INVALID	= -1,
	
	LS_NONE		= 0,

	
	LS_READY,
	LS_DRAW,
	LS_PUTAWAY,

	
	LS_A_TL2BR,
	LS_A_L2R,
	LS_A_BL2TR,
	LS_A_BR2TL,
	LS_A_R2L,
	LS_A_TR2BL,
	LS_A_T2B,
	LS_A_BACKSTAB,
	LS_A_BACK,
	LS_A_BACK_CR,
	LS_ROLL_STAB,
	LS_A_LUNGE,
	LS_A_JUMP_T__B_,
	LS_A_FLIP_STAB,
	LS_A_FLIP_SLASH,
	LS_JUMPATTACK_DUAL,
	LS_JUMPATTACK_ARIAL_LEFT,
	LS_JUMPATTACK_ARIAL_RIGHT,
	LS_JUMPATTACK_CART_LEFT,
	LS_JUMPATTACK_CART_RIGHT,
	LS_JUMPATTACK_STAFF_LEFT,
	LS_JUMPATTACK_STAFF_RIGHT,
	LS_BUTTERFLY_LEFT,
	LS_BUTTERFLY_RIGHT,
	LS_A_BACKFLIP_ATK,
	LS_SPINATTACK_DUAL,
	LS_SPINATTACK,
	LS_LEAP_ATTACK,
	LS_SWOOP_ATTACK_RIGHT,
	LS_SWOOP_ATTACK_LEFT,
	LS_TAUNTAUN_ATTACK_RIGHT,
	LS_TAUNTAUN_ATTACK_LEFT,
	LS_KICK_F,
	LS_KICK_B,
	LS_KICK_R,
	LS_KICK_L,
	LS_KICK_S,
	LS_KICK_BF,
	LS_KICK_RL,
	LS_KICK_F_AIR,
	LS_KICK_B_AIR,
	LS_KICK_R_AIR,
	LS_KICK_L_AIR,
	LS_STABDOWN,
	LS_STABDOWN_STAFF,
	LS_STABDOWN_DUAL,
	LS_DUAL_SPIN_PROTECT,
	LS_STAFF_SOULCAL,
	LS_A1_SPECIAL,
	LS_A2_SPECIAL,
	LS_A3_SPECIAL,
	LS_UPSIDE_DOWN_ATTACK,
	LS_PULL_ATTACK_STAB,
	LS_PULL_ATTACK_SWING,
	LS_SPINATTACK_ALORA,
	LS_DUAL_FB,
	LS_DUAL_LR,
	LS_HILT_BASH,

	
	LS_S_TL2BR,
	LS_S_L2R,
	LS_S_BL2TR,
	LS_S_BR2TL,
	LS_S_R2L,
	LS_S_TR2BL,
	LS_S_T2B,

	
	LS_R_TL2BR,
	LS_R_L2R,
	LS_R_BL2TR,
	LS_R_BR2TL,
	LS_R_R2L,
	LS_R_TR2BL,
	LS_R_T2B,

	
	LS_T1_BR__R,
	LS_T1_BR_TR,
	LS_T1_BR_T_,
	LS_T1_BR_TL,
	LS_T1_BR__L,
	LS_T1_BR_BL,
	LS_T1__R_BR,
	LS_T1__R_TR,
	LS_T1__R_T_,
	LS_T1__R_TL,
	LS_T1__R__L,
	LS_T1__R_BL,
	LS_T1_TR_BR,
	LS_T1_TR__R,
	LS_T1_TR_T_,
	LS_T1_TR_TL,
	LS_T1_TR__L,
	LS_T1_TR_BL,
	LS_T1_T__BR,
	LS_T1_T___R,
	LS_T1_T__TR,
	LS_T1_T__TL,
	LS_T1_T___L,
	LS_T1_T__BL,
	LS_T1_TL_BR,
	LS_T1_TL__R,
	LS_T1_TL_TR,
	LS_T1_TL_T_,
	LS_T1_TL__L,
	LS_T1_TL_BL,
	LS_T1__L_BR,
	LS_T1__L__R,
	LS_T1__L_TR,
	LS_T1__L_T_,
	LS_T1__L_TL,
	LS_T1__L_BL,
	LS_T1_BL_BR,
	LS_T1_BL__R,
	LS_T1_BL_TR,
	LS_T1_BL_T_,
	LS_T1_BL_TL,
	LS_T1_BL__L,

	
	LS_B1_BR,
	LS_B1__R,
	LS_B1_TR,
	LS_B1_T_,
	LS_B1_TL,
	LS_B1__L,
	LS_B1_BL,

	
	LS_D1_BR,
	LS_D1__R,
	LS_D1_TR,
	LS_D1_T_,
	LS_D1_TL,
	LS_D1__L,
	LS_D1_BL,
	LS_D1_B_,

	
	LS_V1_BR,
	LS_V1__R,
	LS_V1_TR,
	LS_V1_T_,
	LS_V1_TL,
	LS_V1__L,
	LS_V1_BL,
	LS_V1_B_,

	
	LS_H1_T_,
	LS_H1_TR,
	LS_H1_TL,
	LS_H1_BR,
	LS_H1_B_,
	LS_H1_BL,

	
	LS_K1_T_,
	LS_K1_TR,
	LS_K1_TL,
	LS_K1_BR,
	LS_K1_BL,

	
	LS_PARRY_UP,
	LS_PARRY_UR,
	LS_PARRY_UL,
	LS_PARRY_LR,
	LS_PARRY_LL,

	
	LS_REFLECT_UP,
	LS_REFLECT_UR,
	LS_REFLECT_UL,
	LS_REFLECT_LR,
	LS_REFLECT_LL,

	LS_MOVE_MAX
};
typedef int saberMoveName_t;

typedef enum {
	Q_BR,
	Q_R,
	Q_TR,
	Q_T,
	Q_TL,
	Q_L,
	Q_BL,
	Q_B,
	Q_NUM_QUADS
} saberQuadrant_t;

typedef struct
{
	char *name;
	int animToUse;
	int	startQuad;
	int	endQuad;
	unsigned animSetFlags;
	int blendTime;
	int blocking;
	saberMoveName_t chain_idle;			
	saberMoveName_t chain_attack;		
	qboolean trailLength;
} saberMoveData_t;

#line 1 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\namespace_begin.h"















#line 1508 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\bg_public.h"

extern saberMoveData_t	saberMoveData[LS_MOVE_MAX];

bgEntity_t *PM_BGEntForNum( int num );
qboolean BG_KnockDownable(playerState_t *ps);
qboolean BG_LegalizedForcePowers(char *powerOut, int maxRank, qboolean freeSaber, int teamForce, int gametype, int fpDisabled);

#line 1 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\namespace_end.h"

















#line 1516 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\bg_public.h"





static __inline void BG_GiveMeVectorFromMatrix(mdxaBone_t *boltMatrix, int flags, vec3_t vec)
{
	switch (flags)
	{
	case ORIGIN:
		vec[0] = boltMatrix->matrix[0][3];
		vec[1] = boltMatrix->matrix[1][3];
		vec[2] = boltMatrix->matrix[2][3];
		break;
	case POSITIVE_Y:
		vec[0] = boltMatrix->matrix[0][1];
		vec[1] = boltMatrix->matrix[1][1];
		vec[2] = boltMatrix->matrix[2][1];
 		break;
	case POSITIVE_X:
		vec[0] = boltMatrix->matrix[0][0];
		vec[1] = boltMatrix->matrix[1][0];
		vec[2] = boltMatrix->matrix[2][0];
		break;
	case POSITIVE_Z:
		vec[0] = boltMatrix->matrix[0][2];
		vec[1] = boltMatrix->matrix[1][2];
		vec[2] = boltMatrix->matrix[2][2];
		break;
	case NEGATIVE_Y:
		vec[0] = -boltMatrix->matrix[0][1];
		vec[1] = -boltMatrix->matrix[1][1];
		vec[2] = -boltMatrix->matrix[2][1];
		break;
	case NEGATIVE_X:
		vec[0] = -boltMatrix->matrix[0][0];
		vec[1] = -boltMatrix->matrix[1][0];
		vec[2] = -boltMatrix->matrix[2][0];
		break;
	case NEGATIVE_Z:
		vec[0] = -boltMatrix->matrix[0][2];
		vec[1] = -boltMatrix->matrix[1][2];
		vec[2] = -boltMatrix->matrix[2][2];
		break;
	}
}
#line 1563 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\bg_public.h"

#line 1 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\namespace_begin.h"















#line 1565 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\bg_public.h"

void BG_IK_MoveArm(void *ghoul2, int lHandBolt, int time, entityState_t *ent, int basePose, vec3_t desiredPos, qboolean *ikInProgress,
					 vec3_t origin, vec3_t angles, vec3_t scale, int blendTime, qboolean forceHalt);

void BG_G2PlayerAngles(void *ghoul2, int motionBolt, entityState_t *cent, int time, vec3_t cent_lerpOrigin,
					   vec3_t cent_lerpAngles, vec3_t legs[3], vec3_t legsAngles, qboolean *tYawing,
					   qboolean *tPitching, qboolean *lYawing, float *tYawAngle, float *tPitchAngle,
					   float *lYawAngle, int frametime, vec3_t turAngles, vec3_t modelScale, int ciLegs,
					   int ciTorso, int *corrTime, vec3_t lookAngles, vec3_t lastHeadAngles, int lookTime,
					   entityState_t *emplaced, int *crazySmoothFactor);
void BG_G2ATSTAngles(void *ghoul2, int time, vec3_t cent_lerpAngles );



int BG_AnimLength( int index, animNumber_t anim );

qboolean BG_InSpecialJump( int anim );
qboolean BG_InSaberStandAnim( int anim );
qboolean BG_InReboundJump( int anim );
qboolean BG_InReboundHold( int anim );
qboolean BG_InReboundRelease( int anim );
qboolean BG_InBackFlip( int anim );
qboolean BG_DirectFlippingAnim( int anim );
qboolean BG_SaberInAttack( int move );
qboolean BG_SaberInSpecial( int move );
qboolean BG_KickMove( int move );
qboolean BG_SaberInIdle( int move );
qboolean BG_FlippingAnim( int anim );
qboolean BG_SpinningSaberAnim( int anim );
qboolean BG_SaberInSpecialAttack( int anim );
qboolean BG_SaberInKata( int saberMove );
qboolean BG_InKataAnim(int anim);
qboolean BG_KickingAnim( int anim );
int BG_InGrappleMove(int anim);
int BG_BrokenParryForAttack( int move );
int BG_BrokenParryForParry( int move );
int BG_KnockawayForParry( int move );
qboolean BG_InRoll( playerState_t *ps, int anim );
qboolean BG_InDeathAnim( int anim );
qboolean BG_InSaberLockOld( int anim );
qboolean BG_InSaberLock( int anim );

void BG_SaberStartTransAnim( int clientNum, int saberAnimLevel, int weapon, int anim, float *animSpeed, int broken );

void BG_ForcePowerDrain( playerState_t *ps, forcePowers_t forcePower, int overrideAmt );

void	BG_EvaluateTrajectory( const trajectory_t *tr, int atTime, vec3_t result );
void	BG_EvaluateTrajectoryDelta( const trajectory_t *tr, int atTime, vec3_t result );

void	BG_AddPredictableEventToPlayerstate( int newEvent, int eventParm, playerState_t *ps );

void	BG_TouchJumpPad( playerState_t *ps, entityState_t *jumppad );

void	BG_PlayerStateToEntityState( playerState_t *ps, entityState_t *s, qboolean snap );
void	BG_PlayerStateToEntityStateExtraPolate( playerState_t *ps, entityState_t *s, int time, qboolean snap );

qboolean	BG_PlayerTouchesItem( playerState_t *ps, entityState_t *item, int atTime );

void	BG_InitAnimsets(void);
void	BG_ClearAnimsets(void);
int		BG_ParseAnimationFile(const char *filename, animation_t *animSet, qboolean isHumanoid);




qboolean BG_HasAnimation(int animIndex, int animation);
int		BG_PickAnim( int animIndex, int minAnim, int maxAnim );

int BG_GetItemIndexByTag(int tag, int type);

qboolean BG_IsItemSelectable(playerState_t *ps, int item);

qboolean BG_HasYsalamiri(int gametype, playerState_t *ps);
qboolean BG_CanUseFPNow(int gametype, playerState_t *ps, int time, forcePowers_t power);

void *BG_Alloc ( int size );
void *BG_AllocUnaligned ( int size );
void *BG_TempAlloc( int size );
void BG_TempFree( int size );
char *BG_StringAlloc ( const char *source );
qboolean BG_OutOfMemory ( void );

void BG_BLADE_ActivateTrail ( bladeInfo_t *blade, float duration );
void BG_BLADE_DeactivateTrail ( bladeInfo_t *blade, float duration );
void BG_SI_Activate( saberInfo_t *saber );
void BG_SI_Deactivate( saberInfo_t *saber );
void BG_SI_BladeActivate( saberInfo_t *saber, int iBlade, qboolean bActive );
qboolean BG_SI_Active(saberInfo_t *saber);
void BG_SI_SetLength( saberInfo_t *saber, float length );
void BG_SI_SetDesiredLength(saberInfo_t *saber, float len, int bladeNum);
void BG_SI_SetLengthGradual( saberInfo_t *saber, int time );
float BG_SI_Length(saberInfo_t *saber);
float BG_SI_LengthMax(saberInfo_t *saber);
void BG_SI_ActivateTrail ( saberInfo_t *saber, float duration );
void BG_SI_DeactivateTrail ( saberInfo_t *saber, float duration );
extern void BG_AttachToRancor( void *ghoul2,float rancYaw,vec3_t rancOrigin,int time,qhandle_t *modelList,vec3_t modelScale,qboolean inMouth,vec3_t out_origin,vec3_t out_angles,vec3_t out_axis[3] );

extern int WeaponReadyAnim[WP_NUM_WEAPONS];
extern int WeaponAttackAnim[WP_NUM_WEAPONS];

extern int forcePowerDarkLight[NUM_FORCE_POWERS];

#line 1 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\namespace_end.h"

















#line 1668 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\bg_public.h"













#line 1682 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\bg_public.h"

#line 7 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\g_local.h"
#line 1 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\bg_vehicles.h"





















































































































































































































































































































































































































































































































































































































































#line 8 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\g_local.h"
#line 1 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\g_public.h"






















											


											
											


											


											


















typedef struct failedEdge_e
{
	int	startID;
	int	endID;
	int checkTime;
	int	entID;
} failedEdge_t;

typedef struct {
	qboolean	linked;				
	int			linkcount;

	int			svFlags;			
	int			singleClient;		

	qboolean	bmodel;				
									
	vec3_t		mins, maxs;
	int			contents;			
									

	vec3_t		absmin, absmax;		

	
	
	
	
	vec3_t		currentOrigin;
	vec3_t		currentAngles;
	qboolean	mIsRoffing;			

	
	
	
	
	
	int			ownerNum;

	
	
	
	int			broadcastClients[2];

} entityShared_t;






typedef enum {
	

	G_PRINT,		
	

	G_ERROR,		
	

	G_MILLISECONDS,	
	
	
	

	
	G_PRECISIONTIMER_START,
	G_PRECISIONTIMER_END,

	
	G_CVAR_REGISTER,	
	G_CVAR_UPDATE,	
	G_CVAR_SET,		
	G_CVAR_VARIABLE_INTEGER_VALUE,	

	G_CVAR_VARIABLE_STRING_BUFFER,	

	G_ARGC,			
	

	G_ARGV,			

	G_FS_FOPEN_FILE,	
	G_FS_READ,		
	G_FS_WRITE,		
	G_FS_FCLOSE_FILE,		

	G_SEND_CONSOLE_COMMAND,	
	
	


	

	G_LOCATE_GAME_DATA,		
	
	
	

	G_DROP_CLIENT,		
	

	G_SEND_SERVER_COMMAND,	
	
	

	G_SET_CONFIGSTRING,	
	
	
	
	
	

	G_GET_CONFIGSTRING,	

	G_GET_USERINFO,		
	
	
	

	G_SET_USERINFO,		

	G_GET_SERVERINFO,	
	

	G_SET_SERVER_CULL,
	

	G_SET_BRUSH_MODEL,	
	

	G_TRACE,	
	

	G_G2TRACE,	
	

	G_POINT_CONTENTS,	
	

	G_IN_PVS,			

	G_IN_PVS_IGNORE_PORTALS,	

	G_ADJUST_AREA_PORTAL_STATE,	

	G_AREAS_CONNECTED,	

	G_LINKENTITY,		
	
	
	

	G_UNLINKENTITY,		
	

	G_ENTITIES_IN_BOX,	
	
	

	G_ENTITY_CONTACT,	
	

	
	G_BOT_ALLOCATE_CLIENT,	

	G_BOT_FREE_CLIENT,	

	G_GET_USERCMD,	

	G_GET_ENTITY_TOKEN,	
	
	
	

	G_SIEGEPERSSET,
	G_SIEGEPERSGET,

	G_FS_GETFILELIST,
	G_DEBUG_POLYGON_CREATE,
	G_DEBUG_POLYGON_DELETE,
	G_REAL_TIME,
	G_SNAPVECTOR,

	G_TRACECAPSULE,	
	G_ENTITY_CONTACTCAPSULE,	


	SP_GETSTRINGTEXTSTRING,

	G_ROFF_CLEAN,				
	G_ROFF_UPDATE_ENTITIES,		
	G_ROFF_CACHE,				
	G_ROFF_PLAY,				
	G_ROFF_PURGE_ENT,			

	
	G_TRUEMALLOC,
	G_TRUEFREE,

	
	G_ICARUS_RUNSCRIPT,
	G_ICARUS_REGISTERSCRIPT,

	G_ICARUS_INIT,
	G_ICARUS_VALIDENT,
	G_ICARUS_ISINITIALIZED,
	G_ICARUS_MAINTAINTASKMANAGER,
	G_ICARUS_ISRUNNING,
	G_ICARUS_TASKIDPENDING,
	G_ICARUS_INITENT,
	G_ICARUS_FREEENT,
	G_ICARUS_ASSOCIATEENT,
	G_ICARUS_SHUTDOWN,
	G_ICARUS_TASKIDSET,
	G_ICARUS_TASKIDCOMPLETE,
	G_ICARUS_SETVAR,
	G_ICARUS_VARIABLEDECLARED,
	G_ICARUS_GETFLOATVARIABLE,
	G_ICARUS_GETSTRINGVARIABLE,
	G_ICARUS_GETVECTORVARIABLE,

	G_SET_SHARED_BUFFER,

	
	G_MEMSET = 100,
	G_MEMCPY,
	G_STRNCPY,
	G_SIN,
	G_COS,
	G_ATAN2,
	G_SQRT,
	G_MATRIXMULTIPLY,
	G_ANGLEVECTORS,
	G_PERPENDICULARVECTOR,
	G_FLOOR,
	G_CEIL,

	G_TESTPRINTINT,
	G_TESTPRINTFLOAT,

	G_ACOS,
	G_ASIN,

	

	
	G_NAV_INIT = 200,
	G_NAV_FREE,
	G_NAV_LOAD,
	G_NAV_SAVE,
	G_NAV_ADDRAWPOINT,
	G_NAV_CALCULATEPATHS,
	G_NAV_HARDCONNECT,
	G_NAV_SHOWNODES,
	G_NAV_SHOWEDGES,
	G_NAV_SHOWPATH,
	G_NAV_GETNEARESTNODE,
	G_NAV_GETBESTNODE,
	G_NAV_GETNODEPOSITION,
	G_NAV_GETNODENUMEDGES,
	G_NAV_GETNODEEDGE,
	G_NAV_GETNUMNODES,
	G_NAV_CONNECTED,
	G_NAV_GETPATHCOST,
	G_NAV_GETEDGECOST,
	G_NAV_GETPROJECTEDNODE,
	G_NAV_CHECKFAILEDNODES,
	G_NAV_ADDFAILEDNODE,
	G_NAV_NODEFAILED,
	G_NAV_NODESARENEIGHBORS,
	G_NAV_CLEARFAILEDEDGE,
	G_NAV_CLEARALLFAILEDEDGES,
	G_NAV_EDGEFAILED,
	G_NAV_ADDFAILEDEDGE,
	G_NAV_CHECKFAILEDEDGE,
	G_NAV_CHECKALLFAILEDEDGES,
	G_NAV_ROUTEBLOCKED,
	G_NAV_GETBESTNODEALTROUTE,
	G_NAV_GETBESTNODEALT2,
	G_NAV_GETBESTPATHBETWEENENTS,
	G_NAV_GETNODERADIUS,
	G_NAV_CHECKBLOCKEDEDGES,
	G_NAV_CLEARCHECKEDNODES,
	G_NAV_CHECKEDNODE,
	G_NAV_SETCHECKEDNODE,
	G_NAV_FLAGALLNODES,
	G_NAV_GETPATHSCALCULATED,
	G_NAV_SETPATHSCALCULATED,
	

	BOTLIB_SETUP = 250,				
	BOTLIB_SHUTDOWN,				
	BOTLIB_LIBVAR_SET,
	BOTLIB_LIBVAR_GET,
	BOTLIB_PC_ADD_GLOBAL_DEFINE,
	BOTLIB_START_FRAME,
	BOTLIB_LOAD_MAP,
	BOTLIB_UPDATENTITY,
	BOTLIB_TEST,

	BOTLIB_GET_SNAPSHOT_ENTITY,		
	BOTLIB_GET_CONSOLE_MESSAGE,		
	BOTLIB_USER_COMMAND,			

	BOTLIB_AAS_ENABLE_ROUTING_AREA = 300,
	BOTLIB_AAS_BBOX_AREAS,
	BOTLIB_AAS_AREA_INFO,
	BOTLIB_AAS_ENTITY_INFO,

	BOTLIB_AAS_INITIALIZED,
	BOTLIB_AAS_PRESENCE_TYPE_BOUNDING_BOX,
	BOTLIB_AAS_TIME,

	BOTLIB_AAS_POINT_AREA_NUM,
	BOTLIB_AAS_TRACE_AREAS,

	BOTLIB_AAS_POINT_CONTENTS,
	BOTLIB_AAS_NEXT_BSP_ENTITY,
	BOTLIB_AAS_VALUE_FOR_BSP_EPAIR_KEY,
	BOTLIB_AAS_VECTOR_FOR_BSP_EPAIR_KEY,
	BOTLIB_AAS_FLOAT_FOR_BSP_EPAIR_KEY,
	BOTLIB_AAS_INT_FOR_BSP_EPAIR_KEY,

	BOTLIB_AAS_AREA_REACHABILITY,

	BOTLIB_AAS_AREA_TRAVEL_TIME_TO_GOAL_AREA,

	BOTLIB_AAS_SWIMMING,
	BOTLIB_AAS_PREDICT_CLIENT_MOVEMENT,

	BOTLIB_EA_SAY = 400,
	BOTLIB_EA_SAY_TEAM,
	BOTLIB_EA_COMMAND,

	BOTLIB_EA_ACTION,
	BOTLIB_EA_GESTURE,
	BOTLIB_EA_TALK,
	BOTLIB_EA_ATTACK,
	BOTLIB_EA_ALT_ATTACK,
	BOTLIB_EA_FORCEPOWER,
	BOTLIB_EA_USE,
	BOTLIB_EA_RESPAWN,
	BOTLIB_EA_CROUCH,
	BOTLIB_EA_MOVE_UP,
	BOTLIB_EA_MOVE_DOWN,
	BOTLIB_EA_MOVE_FORWARD,
	BOTLIB_EA_MOVE_BACK,
	BOTLIB_EA_MOVE_LEFT,
	BOTLIB_EA_MOVE_RIGHT,

	BOTLIB_EA_SELECT_WEAPON,
	BOTLIB_EA_JUMP,
	BOTLIB_EA_DELAYED_JUMP,
	BOTLIB_EA_MOVE,
	BOTLIB_EA_VIEW,

	BOTLIB_EA_END_REGULAR,
	BOTLIB_EA_GET_INPUT,
	BOTLIB_EA_RESET_INPUT,


	BOTLIB_AI_LOAD_CHARACTER = 500,
	BOTLIB_AI_FREE_CHARACTER,
	BOTLIB_AI_CHARACTERISTIC_FLOAT,
	BOTLIB_AI_CHARACTERISTIC_BFLOAT,
	BOTLIB_AI_CHARACTERISTIC_INTEGER,
	BOTLIB_AI_CHARACTERISTIC_BINTEGER,
	BOTLIB_AI_CHARACTERISTIC_STRING,

	BOTLIB_AI_ALLOC_CHAT_STATE,
	BOTLIB_AI_FREE_CHAT_STATE,
	BOTLIB_AI_QUEUE_CONSOLE_MESSAGE,
	BOTLIB_AI_REMOVE_CONSOLE_MESSAGE,
	BOTLIB_AI_NEXT_CONSOLE_MESSAGE,
	BOTLIB_AI_NUM_CONSOLE_MESSAGE,
	BOTLIB_AI_INITIAL_CHAT,
	BOTLIB_AI_REPLY_CHAT,
	BOTLIB_AI_CHAT_LENGTH,
	BOTLIB_AI_ENTER_CHAT,
	BOTLIB_AI_STRING_CONTAINS,
	BOTLIB_AI_FIND_MATCH,
	BOTLIB_AI_MATCH_VARIABLE,
	BOTLIB_AI_UNIFY_WHITE_SPACES,
	BOTLIB_AI_REPLACE_SYNONYMS,
	BOTLIB_AI_LOAD_CHAT_FILE,
	BOTLIB_AI_SET_CHAT_GENDER,
	BOTLIB_AI_SET_CHAT_NAME,

	BOTLIB_AI_RESET_GOAL_STATE,
	BOTLIB_AI_RESET_AVOID_GOALS,
	BOTLIB_AI_PUSH_GOAL,
	BOTLIB_AI_POP_GOAL,
	BOTLIB_AI_EMPTY_GOAL_STACK,
	BOTLIB_AI_DUMP_AVOID_GOALS,
	BOTLIB_AI_DUMP_GOAL_STACK,
	BOTLIB_AI_GOAL_NAME,
	BOTLIB_AI_GET_TOP_GOAL,
	BOTLIB_AI_GET_SECOND_GOAL,
	BOTLIB_AI_CHOOSE_LTG_ITEM,
	BOTLIB_AI_CHOOSE_NBG_ITEM,
	BOTLIB_AI_TOUCHING_GOAL,
	BOTLIB_AI_ITEM_GOAL_IN_VIS_BUT_NOT_VISIBLE,
	BOTLIB_AI_GET_LEVEL_ITEM_GOAL,
	BOTLIB_AI_AVOID_GOAL_TIME,
	BOTLIB_AI_INIT_LEVEL_ITEMS,
	BOTLIB_AI_UPDATE_ENTITY_ITEMS,
	BOTLIB_AI_LOAD_ITEM_WEIGHTS,
	BOTLIB_AI_FREE_ITEM_WEIGHTS,
	BOTLIB_AI_SAVE_GOAL_FUZZY_LOGIC,
	BOTLIB_AI_ALLOC_GOAL_STATE,
	BOTLIB_AI_FREE_GOAL_STATE,

	BOTLIB_AI_RESET_MOVE_STATE,
	BOTLIB_AI_MOVE_TO_GOAL,
	BOTLIB_AI_MOVE_IN_DIRECTION,
	BOTLIB_AI_RESET_AVOID_REACH,
	BOTLIB_AI_RESET_LAST_AVOID_REACH,
	BOTLIB_AI_REACHABILITY_AREA,
	BOTLIB_AI_MOVEMENT_VIEW_TARGET,
	BOTLIB_AI_ALLOC_MOVE_STATE,
	BOTLIB_AI_FREE_MOVE_STATE,
	BOTLIB_AI_INIT_MOVE_STATE,

	BOTLIB_AI_CHOOSE_BEST_FIGHT_WEAPON,
	BOTLIB_AI_GET_WEAPON_INFO,
	BOTLIB_AI_LOAD_WEAPON_WEIGHTS,
	BOTLIB_AI_ALLOC_WEAPON_STATE,
	BOTLIB_AI_FREE_WEAPON_STATE,
	BOTLIB_AI_RESET_WEAPON_STATE,

	BOTLIB_AI_GENETIC_PARENTS_AND_CHILD_SELECTION,
	BOTLIB_AI_INTERBREED_GOAL_FUZZY_LOGIC,
	BOTLIB_AI_MUTATE_GOAL_FUZZY_LOGIC,
	BOTLIB_AI_GET_NEXT_CAMP_SPOT_GOAL,
	BOTLIB_AI_GET_MAP_LOCATION_GOAL,
	BOTLIB_AI_NUM_INITIAL_CHATS,
	BOTLIB_AI_GET_CHAT_MESSAGE,
	BOTLIB_AI_REMOVE_FROM_AVOID_GOALS,
	BOTLIB_AI_PREDICT_VISIBLE_POSITION,

	BOTLIB_AI_SET_AVOID_GOAL_TIME,
	BOTLIB_AI_ADD_AVOID_SPOT,
	BOTLIB_AAS_ALTERNATIVE_ROUTE_GOAL,
	BOTLIB_AAS_PREDICT_ROUTE,
	BOTLIB_AAS_POINT_REACHABILITY_AREA_INDEX,

	BOTLIB_PC_LOAD_SOURCE,
	BOTLIB_PC_FREE_SOURCE,
	BOTLIB_PC_READ_TOKEN,
	BOTLIB_PC_SOURCE_FILE_AND_LINE,

	


	G_R_REGISTERSKIN,
	G_G2_LISTBONES,
	G_G2_LISTSURFACES,
	G_G2_HAVEWEGHOULMODELS,
	G_G2_SETMODELS,
	G_G2_GETBOLT,
	G_G2_GETBOLT_NOREC,
	G_G2_GETBOLT_NOREC_NOROT,
	G_G2_INITGHOUL2MODEL,
	G_G2_SETSKIN,
	G_G2_SIZE,
	G_G2_ADDBOLT,
	G_G2_SETBOLTINFO,
	G_G2_ANGLEOVERRIDE,
	G_G2_PLAYANIM,
	G_G2_GETBONEANIM,
	G_G2_GETGLANAME,
	G_G2_COPYGHOUL2INSTANCE,
	G_G2_COPYSPECIFICGHOUL2MODEL,
	G_G2_DUPLICATEGHOUL2INSTANCE,
	G_G2_HASGHOUL2MODELONINDEX,
	G_G2_REMOVEGHOUL2MODEL,
	G_G2_REMOVEGHOUL2MODELS,
	G_G2_CLEANMODELS,
	G_G2_COLLISIONDETECT,
	G_G2_COLLISIONDETECTCACHE,

	G_G2_SETROOTSURFACE,
	G_G2_SETSURFACEONOFF,
	G_G2_SETNEWORIGIN,
	G_G2_DOESBONEEXIST,
	G_G2_GETSURFACERENDERSTATUS,

	G_G2_ABSURDSMOOTHING,




	G_G2_SETRAGDOLL,
	G_G2_ANIMATEG2MODELS,



	
	G_G2_RAGPCJCONSTRAINT,
	G_G2_RAGPCJGRADIENTSPEED,
	G_G2_RAGEFFECTORGOAL,
	G_G2_GETRAGBONEPOS,
	G_G2_RAGEFFECTORKICK,
	G_G2_RAGFORCESOLVE,

	
	
	G_G2_SETBONEIKSTATE,
	G_G2_IKMOVE,

	G_G2_REMOVEBONE,

	G_G2_ATTACHINSTANCETOENTNUM,
	G_G2_CLEARATTACHEDINSTANCE,
	G_G2_CLEANENTATTACHMENTS,
	G_G2_OVERRIDESERVER,

	G_G2_GETSURFACENAME,

	G_SET_ACTIVE_SUBBSP,
	G_CM_REGISTER_TERRAIN,
	G_RMG_INIT,

	G_BOT_UPDATEWAYPOINTS,
	G_BOT_CALCULATEPATHS




} gameImport_t;


typedef enum 
{
	BS_DEFAULT = 0,
	BS_ADVANCE_FIGHT,
	BS_SLEEP,
	BS_FOLLOW_LEADER,
	BS_JUMP,
	BS_SEARCH,
	BS_WANDER,
	BS_NOCLIP,
	BS_REMOVE,
	BS_CINEMATIC,
	
	
	BS_WAIT,
	BS_STAND_GUARD,
	BS_PATROL,
	BS_INVESTIGATE,
	BS_STAND_AND_SHOOT,
	BS_HUNT_AND_KILL,
	BS_FLEE,
	NUM_BSTATES
} bState_t;

enum
{
	EDGE_NORMAL,
	EDGE_PATH,
	EDGE_BLOCKED,
	EDGE_FAILED,
	EDGE_MOVEDIR
};

enum
{
	NODE_NORMAL,
	NODE_START,
	NODE_GOAL,
	NODE_NAVGOAL,
};

typedef enum 
{
	TID_CHAN_VOICE = 0,	
	TID_ANIM_UPPER,		
	TID_ANIM_LOWER,		
	TID_ANIM_BOTH,		
	TID_MOVE_NAV,		
	TID_ANGLE_FACE,		
	TID_BSTATE,			
	TID_LOCATION,		

	TID_RESIZE,			
	TID_SHOOT,			
	NUM_TIDS,			
} taskID_t;

typedef enum 
{
	BSET_INVALID = -1,
	BSET_FIRST = 0,
	BSET_SPAWN = 0,
	BSET_USE,
	BSET_AWAKE,
	BSET_ANGER,
	BSET_ATTACK,
	BSET_VICTORY,
	BSET_LOSTENEMY,
	BSET_PAIN,
	BSET_FLEE,
	BSET_DEATH,
	BSET_DELAYED,
	BSET_BLOCKED,
	BSET_BUMPED,
	BSET_STUCK,
	BSET_FFIRE,
	BSET_FFDEATH,
	BSET_MINDTRICK,

	NUM_BSETS
} bSet_t;



typedef struct
{	
	char	parm[16][64];
} parms_t;



typedef struct Vehicle_s Vehicle_t;



typedef struct {
	entityState_t	s;				
	playerState_t	*playerState;	
									
									
	Vehicle_t		*m_pVehicle; 
	void			*ghoul2; 
	int				localAnimIndex; 
	vec3_t			modelScale; 

	

	entityShared_t	r;				

	
	int				taskID[NUM_TIDS];
	parms_t			*parms;
	char			*behaviorSet[NUM_BSETS];
	char			*script_targetname;
	int				delayScriptTime;
	char			*fullName;

	
	char			*targetname;
	char			*classname;			

	
	int				waypoint;			
	int				lastWaypoint;		
	int				lastValidWaypoint;	
	int				noWaypointTime;		
	int				combatPoint;
	int				failedWaypoints[8];
	int				failedWaypointCheckTime;

	int				next_roff_time; 
} sharedEntity_t;


















typedef enum {
	GAME_INIT,	
	
	
	

	GAME_SHUTDOWN,	

	GAME_CLIENT_CONNECT,	
	
	

	GAME_CLIENT_BEGIN,				

	GAME_CLIENT_USERINFO_CHANGED,	

	GAME_CLIENT_DISCONNECT,			

	GAME_CLIENT_COMMAND,			

	GAME_CLIENT_THINK,				

	GAME_RUN_FRAME,					

	GAME_CONSOLE_COMMAND,			
	
	
	
	

	BOTAI_START_FRAME,				

	GAME_ROFF_NOTETRACK_CALLBACK,	

	GAME_SPAWN_RMG_ENTITY, 

	
	GAME_ICARUS_PLAYSOUND,
	GAME_ICARUS_SET,
	GAME_ICARUS_LERP2POS,
	GAME_ICARUS_LERP2ORIGIN,
	GAME_ICARUS_LERP2ANGLES,
	GAME_ICARUS_GETTAG,
	GAME_ICARUS_LERP2START,
	GAME_ICARUS_LERP2END,
	GAME_ICARUS_USE,
	GAME_ICARUS_KILL,
	GAME_ICARUS_REMOVE,
	GAME_ICARUS_PLAY,
	GAME_ICARUS_GETFLOAT,
	GAME_ICARUS_GETVECTOR,
	GAME_ICARUS_GETSTRING,
	GAME_ICARUS_SOUNDINDEX,
	GAME_ICARUS_GETSETIDFORSTRING,
	GAME_NAV_CLEARPATHTOPOINT,
	GAME_NAV_CLEARLOS,
	GAME_NAV_CLEARPATHBETWEENPOINTS,
	GAME_NAV_CHECKNODEFAILEDFORENT,
	GAME_NAV_ENTISUNLOCKEDDOOR,
	GAME_NAV_ENTISDOOR,
	GAME_NAV_ENTISBREAKABLE,
	GAME_NAV_ENTISREMOVABLEUSABLE,
	GAME_NAV_FINDCOMBATPOINTWAYPOINTS,
	
	GAME_GETITEMINDEXBYTAG
} gameExport_t;

typedef struct
{
	int taskID;
	int entID;
	char name[2048];
	char channel[2048];
} T_G_ICARUS_PLAYSOUND;


typedef struct
{
	int taskID;
	int entID;
	char type_name[2048];
	char data[2048];
} T_G_ICARUS_SET;

typedef struct
{
	int taskID;
	int entID; 
	vec3_t origin;
	vec3_t angles;
	float duration;
	qboolean nullAngles; 
} T_G_ICARUS_LERP2POS;

typedef struct
{
	int taskID;
	int entID;
	vec3_t origin;
	float duration;
} T_G_ICARUS_LERP2ORIGIN;

typedef struct
{
	int taskID;
	int entID;
	vec3_t angles;
	float duration;
} T_G_ICARUS_LERP2ANGLES;

typedef struct
{
	int entID;
	char name[2048];
	int lookup;
	vec3_t info;
} T_G_ICARUS_GETTAG;

typedef struct
{
	int entID;
	int taskID;
	float duration;
} T_G_ICARUS_LERP2START;

typedef struct
{
	int entID;
	int taskID;
	float duration;
} T_G_ICARUS_LERP2END;

typedef struct
{
	int entID;
	char target[2048];
} T_G_ICARUS_USE;

typedef struct
{
	int entID;
	char name[2048];
} T_G_ICARUS_KILL;

typedef struct
{
	int entID;
	char name[2048];
} T_G_ICARUS_REMOVE;

typedef struct
{
	int taskID;
	int entID;
	char type[2048];
	char name[2048];
} T_G_ICARUS_PLAY;

typedef struct
{
	int entID;
	int type;
	char name[2048];
	float value;
} T_G_ICARUS_GETFLOAT;

typedef struct
{
	int entID;
	int type;
	char name[2048];
	vec3_t value;
} T_G_ICARUS_GETVECTOR;

typedef struct
{
	int entID;
	int type;
	char name[2048];
	char value[2048];
} T_G_ICARUS_GETSTRING;

typedef struct
{
	char filename[2048];
} T_G_ICARUS_SOUNDINDEX;
typedef struct
{
	char string[2048];
} T_G_ICARUS_GETSETIDFORSTRING;

#line 926 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\g_public.h"
#line 9 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\g_local.h"





#line 15 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\g_local.h"

typedef struct gentity_s gentity_t;
typedef struct gclient_s gclient_t;


#line 1 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\b_public.h"



#line 1 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\ai.h"




typedef enum
{
	DIST_MELEE,
	DIST_LONG,
} distance_e;


typedef enum
{
	ATTACK_MELEE,
	ATTACK_RANGE,
} attack_e;

enum
{
	SQUAD_IDLE,					
	SQUAD_STAND_AND_SHOOT,		
	SQUAD_RETREAT,				
	SQUAD_COVER,				
	SQUAD_TRANSITION,			
	SQUAD_POINT,				
	SQUAD_SCOUT,				
	NUM_SQUAD_STATES,
};


typedef enum 
{
	RANK_CIVILIAN,
	RANK_CREWMAN,
	RANK_ENSIGN,
	RANK_LT_JG,
	RANK_LT,
	RANK_LT_COMM,
	RANK_COMMANDER,
	RANK_CAPTAIN
} rank_t;

qboolean NPC_CheckPlayerTeamStealth( void );


void NPC_BSGrenadier_Default( void );


void NPC_BSSniper_Default( void );


void NPC_BSST_Investigate( void );
void NPC_BSST_Default( void );
void NPC_BSST_Sleep( void );


void NPC_BSJedi_Investigate( void );
void NPC_BSJedi_Default( void );
void NPC_BSJedi_FollowLeader( void );


void NPC_BSDroid_Default( void );


void NPC_BSImperialProbe_Default( void );


void NPC_BSATST_Default( void );

void NPC_BSInterrogator_Default( void );


void NPC_BSMark1_Default( void );


void NPC_BSMark2_Default( void );


void NPC_BSMineMonster_Default( void );
void NPC_BSHowler_Default( void );
void NPC_BSRancor_Default( void );





typedef struct AIGroupMember_s
{
	int	number;
	int waypoint;
	int pathCostToEnemy;
	int	closestBuddy;
} AIGroupMember_t;



typedef struct AIGroupInfo_s
{
	int			numGroup;
	qboolean	processed;
	team_t		team;
	gentity_t	*enemy;
	int			enemyWP;
	int			speechDebounceTime;
	int			lastClearShotTime;
	int			lastSeenEnemyTime;
	int			morale;
	int			moraleAdjust;
	int			moraleDebounce;
	int			memberValidateTime;
	int			activeMemberNum;
	gentity_t	*commander;
	vec3_t		enemyLastSeenPos;
	int			numState[ NUM_SQUAD_STATES ];
	AIGroupMember_t member[ 32 ];
} AIGroupInfo_t;

int	AI_GetGroupSize( vec3_t origin, int radius, team_t playerTeam, gentity_t *avoid );
int AI_GetGroupSize2( gentity_t *ent, int radius );

void AI_GetGroup( gentity_t *self );

qboolean AI_CheckEnemyCollision( gentity_t *ent, qboolean takeEnemy );
gentity_t *AI_DistributeAttack( gentity_t *attacker, gentity_t *enemy, team_t team, int threshold );

#line 127 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\ai.h"
#line 5 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\b_public.h"































































typedef enum {VIS_UNKNOWN, VIS_NOT, VIS_PVS, VIS_360, VIS_FOV, VIS_SHOOT} visibility_t;
typedef enum {SPOT_ORIGIN, SPOT_CHEST, SPOT_HEAD, SPOT_HEAD_LEAN, SPOT_WEAPON, SPOT_LEGS, SPOT_GROUND} spot_t;

typedef enum 
{
	LM_ENT = 0,
	LM_INTEREST
} lookMode_t;

typedef enum 
{
	JS_WAITING = 0,
	JS_FACING,
	JS_CROUCHING,
	JS_JUMPING,
	JS_LANDING
} jumpState_t;

typedef struct gNPCstats_e
{
	
	int		aggression;			
	int		aim;				
	float	earshot;			
	int		evasion;			
	int		hfov;				
	int		intelligence;		
	int		move;				
	int		reactions;			
	float	shootDistance;		
	int		vfov;				
	float	vigilance;			
	float	visrange;			
	
	int		runSpeed;
	int		walkSpeed;
	float	yawSpeed;			
	int		health;
	int		acceleration;
} gNPCstats_t;








typedef struct 
{
	
	int			timeOfDeath;			
	gentity_t	*touchedByPlayer;

	visibility_t	enemyLastVisibility;

	int			aimTime;
	float		desiredYaw;
	float		desiredPitch;
	float		lockedDesiredYaw;
	float		lockedDesiredPitch;
	gentity_t	*aimingBeam;		

	vec3_t		enemyLastSeenLocation;
	int			enemyLastSeenTime;
	vec3_t		enemyLastHeardLocation;
	int			enemyLastHeardTime;
	int			lastAlertID;		

	int			eFlags;
	int			aiFlags;

	int			currentAmmo;		
	int			shotTime;
	int			burstCount;
	int			burstMin;
	int			burstMean;
	int			burstMax;
	int			burstSpacing;
	int			attackHold;
	int			attackHoldTime;
	vec3_t		shootAngles;		

	
	rank_t		rank;		

	
	bState_t	behaviorState;	
	bState_t	defaultBehavior;
	bState_t	tempBehavior;

	qboolean	ignorePain;		

	int			duckDebounceTime;
	int			walkDebounceTime;
	int			enemyCheckDebounceTime;
	int			investigateDebounceTime;
	int			investigateCount;
	vec3_t		investigateGoal;
	int			investigateSoundDebounceTime;
	int			greetingDebounceTime;
	gentity_t	*eventOwner;
	
	
	gentity_t	*coverTarg;
	jumpState_t	jumpState;
	float		followDist;

	
	gentity_t	*tempGoal;			
	gentity_t	*goalEntity;
	gentity_t	*lastGoalEntity;
	gentity_t	*eventualGoal;
	gentity_t	*captureGoal;		
	gentity_t	*defendEnt;			
	gentity_t	*greetEnt;			
	int			goalTime;	
	qboolean	straightToGoal;	
	float		distToGoal;
	int			navTime;
	int			blockingEntNum;
	int			blockedSpeechDebounceTime;
	int			lastSideStepSide;
	int			sideStepHoldTime;
	int			homeWp;
	AIGroupInfo_t	*group;

	vec3_t		lastPathAngles;		

	
	gNPCstats_t	stats;
	int			aimErrorDebounceTime;
	float		lastAimErrorYaw;
	float		lastAimErrorPitch;
	vec3_t		aimOfs;
	int			currentAim;
	int			currentAggression;

	
	int			scriptFlags;

	
	int			desiredSpeed;
	int			currentSpeed;
	char		last_forwardmove;
	char		last_rightmove;
	vec3_t		lastClearOrigin;
	int			consecutiveBlockedMoves;
	int			blockedDebounceTime;
	int			shoveCount;
	vec3_t		blockedDest;

	
	int			combatPoint;
	int			lastFailedCombatPoint;
	int			movementSpeech;	
	float		movementSpeechChance;

	
	int			nextBStateThink;
	usercmd_t	last_ucmd;

	
	

	qboolean	combatMove;
	int			goalRadius;

	
	
	



	int			pauseTime;		
	int			standTime;

	int			localState;		
	int			squadState;		

	
	

	int			confusionTime;	
	int			charmedTime;	
	int			controlledTime;	
	int			surrenderTime;	

	
	vec3_t		enemyLaggedPos[(2400/100)];

	gentity_t	*watchTarget;	

	int			ffireCount;		
	int			ffireDebounce;	
	int			ffireFadeDebounce;
} gNPC_t;

void G_SquadPathsInit(void);
void NPC_InitGame( void );
void G_LoadBoltOns( void );
void Svcmd_NPC_f( void );
void NAV_DebugShowWaypoints (void);
void NAV_DebugShowBoxes (void);
void NAV_DebugShowSquadPaths (void);


















































































#line 356 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\b_public.h"
#line 21 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\g_local.h"

extern int gPainMOD;
extern int gPainHitLoc;
extern vec3_t gPainPoint;














#line 40 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\g_local.h"















































#line 88 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\g_local.h"


extern char gSharedBuffer[8192];


typedef enum {
	MOVER_POS1,
	MOVER_POS2,
	MOVER_1TO2,
	MOVER_2TO1
} moverState_t;



typedef enum 
{
	HL_NONE = 0,
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
	HL_MAX
};


extern void *precachedKyle;
extern void *g2SaberInstance;

extern qboolean gEscaping;
extern int gEscapeTime;

struct gentity_s {
	
	entityState_t	s;				
	playerState_t	*playerState;	
	Vehicle_t		*m_pVehicle; 
	void			*ghoul2; 
	int				localAnimIndex; 
	vec3_t			modelScale; 

	

	entityShared_t	r;				

	
	int				taskID[NUM_TIDS];
	parms_t			*parms;
	char			*behaviorSet[NUM_BSETS];
	char			*script_targetname;
	int				delayScriptTime;
	char			*fullName;

	
	char			*targetname;
	char			*classname;			

	
	int				waypoint;			
	int				lastWaypoint;		
	int				lastValidWaypoint;	
	int				noWaypointTime;		
	int				combatPoint;
	int				failedWaypoints[8];
	int				failedWaypointCheckTime;

	int				next_roff_time; 

	
	
	

	struct gclient_s	*client;			

	gNPC_t		*NPC;
	int			cantHitEnemyCounter;

	qboolean	noLumbar; 

	qboolean	inuse;

	int			lockCount; 

	int			spawnflags;			

	int			teamnodmg;			

	char		*roffname;			
	char		*rofftarget;		

	char		*healingclass; 
	char		*healingsound; 
	int			healingrate; 
	int			healingDebounce; 

	char		*ownername;

	int			objective;
	int			side;

	int			passThroughNum;		

	int			aimDebounceTime;
	int			painDebounceTime;
	int			attackDebounceTime;
	int			alliedTeam;			

	int			roffid;				

	qboolean	neverFree;			
									

	int			flags;				

	char		*model;
	char		*model2;
	int			freetime;			
	
	int			eventTime;			
	qboolean	freeAfterEvent;
	qboolean	unlinkAfterEvent;

	qboolean	physicsObject;		
									
	float		physicsBounce;		
	int			clipmask;			
									
									


	char		*NPC_type;
	char		*NPC_targetname;
	char		*NPC_target;

	
	moverState_t moverState;
	int			soundPos1;
	int			sound1to2;
	int			sound2to1;
	int			soundPos2;
	int			soundLoop;
	gentity_t	*parent;
	gentity_t	*nextTrain;
	gentity_t	*prevTrain;
	vec3_t		pos1, pos2;

	
	vec3_t		pos3;

	char		*message;

	int			timestamp;		

	float		angle;			
	char		*target;
	char		*target2;
	char		*target3;		
	char		*target4;		
	char		*target5;		
	char		*target6;		

	char		*team;
	char		*targetShaderName;
	char		*targetShaderNewName;
	gentity_t	*target_ent;

	char		*closetarget;
	char		*opentarget;
	char		*paintarget;

	char		*goaltarget;
	char		*idealclass;

	float		radius;

	int			maxHealth; 

	float		speed;
	vec3_t		movedir;
	float		mass;
	int			setTime;


	int			nextthink;
	void		(*think)(gentity_t *self);
	void		(*reached)(gentity_t *self);	
	void		(*blocked)(gentity_t *self, gentity_t *other);
	void		(*touch)(gentity_t *self, gentity_t *other, trace_t *trace);
	void		(*use)(gentity_t *self, gentity_t *other, gentity_t *activator);
	void		(*pain)(gentity_t *self, gentity_t *attacker, int damage);
	void		(*die)(gentity_t *self, gentity_t *inflictor, gentity_t *attacker, int damage, int mod);

	int			pain_debounce_time;
	int			fly_sound_debounce_time;	
	int			last_move_time;


	int			health;
	qboolean	takedamage;
	material_t	material;

	int			damage;
	int			dflags;
	int			splashDamage;	
	int			splashRadius;
	int			methodOfDeath;
	int			splashMethodOfDeath;

	int			locationDamage[HL_MAX];		

	int			count;
	int			bounceCount;
	qboolean	alt_fire;

	gentity_t	*chain;
	gentity_t	*enemy;
	gentity_t	*lastEnemy;
	gentity_t	*activator;
	gentity_t	*teamchain;		
	gentity_t	*teammaster;	

	int			watertype;
	int			waterlevel;

	int			noise_index;

	
	float		wait;
	float		random;
	int			delay;



	
	int			genericValue1;
	int			genericValue2;
	int			genericValue3;
	int			genericValue4;
	int			genericValue5;
	int			genericValue6;
	int			genericValue7;
	int			genericValue8;
	int			genericValue9;
	int			genericValue10;
	int			genericValue11;
	int			genericValue12;
	int			genericValue13;
	int			genericValue14;
	int			genericValue15;

	char		*soundSet;

	qboolean	isSaberEntity;

	int			damageRedirect; 
	int			damageRedirectTo; 

	vec3_t		epVelocity;
	float		epGravFactor;

	gitem_t		*item;			
};





typedef enum {
	CON_DISCONNECTED,
	CON_CONNECTING,
	CON_CONNECTED
};
typedef int clientConnected_t;

typedef enum {
	SPECTATOR_NOT,
	SPECTATOR_FREE,
	SPECTATOR_FOLLOW,
	SPECTATOR_SCOREBOARD
} spectatorState_t;

typedef enum {
	TEAM_BEGIN,		
	TEAM_ACTIVE		
} playerTeamStateState_t;

typedef struct {
	playerTeamStateState_t	state;

	int			location;

	int			captures;
	int			basedefense;
	int			carrierdefense;
	int			flagrecovery;
	int			fragcarrier;
	int			assists;

	float		lasthurtcarrier;
	float		lastreturnedflag;
	float		flagsince;
	float		lastfraggedcarrier;
} playerTeamState_t;










typedef struct {
	team_t		sessionTeam;
	int			spectatorTime;		
	spectatorState_t	spectatorState;
	int			spectatorClient;	
	int			wins, losses;		
	int			selectedFP;			
	int			saberLevel;			
	qboolean	setForce;			
	int			updateUITime;		
	qboolean	teamLeader;			
	
	
	char		saberType[24];
	char		saber2Type[24];

	int			duelTeam;
	int			siegeDesiredTeam;
	
	char admin_name[8];
	char pass_name[8];
	char ip[24];
	signed int admin_number;
	signed int xp;
	signed char bettor;
	signed int betamt;
	signed char str;
	signed char dex;
	signed char con;
	
	signed int karma;

} clientSession_t;











typedef struct {
	clientConnected_t	connected;	
	usercmd_t	cmd;				
	qboolean	localClient;		
	qboolean	initialSpawn;		
	qboolean	predictItemPickup;	
	qboolean	pmoveFixed;			
	char		netname[36];
	int			netnameTime;				
	int			maxHealth;			
	int			enterTime;			
	playerTeamState_t teamState;	
	int			voteCount;			
	int			teamVoteCount;		
	qboolean	teamInfo;			
} clientPersistant_t;

typedef struct renderInfo_s
{
	
	int		headYawRangeLeft;
	int		headYawRangeRight;
	int		headPitchRangeUp;
	int		headPitchRangeDown;

	int		torsoYawRangeLeft;
	int		torsoYawRangeRight;
	int		torsoPitchRangeUp;
	int		torsoPitchRangeDown;

	int		legsFrame;
	int		torsoFrame;

	float	legsFpsMod;
	float	torsoFpsMod;

	
	vec3_t	customRGB;
	int		customAlpha;

	
	int			renderFlags;

	
	vec3_t		muzzlePoint;
	vec3_t		muzzleDir;
	vec3_t		muzzlePointOld;
	vec3_t		muzzleDirOld;
	
	
	int			mPCalcTime;

	
	float		lockYaw;

	
	vec3_t		headPoint;
	vec3_t		headAngles;
	vec3_t		handRPoint;
	vec3_t		handLPoint;
	vec3_t		crotchPoint;
	vec3_t		footRPoint;
	vec3_t		footLPoint;
	vec3_t		torsoPoint;
	vec3_t		torsoAngles;
	vec3_t		eyePoint;
	vec3_t		eyeAngles;
	int			lookTarget;
	lookMode_t	lookMode;
	int			lookTargetClearTime;
	int			lastVoiceVolume;
	vec3_t		lastHeadAngles;
	vec3_t		headBobAngles;
	vec3_t		targetHeadBobAngles;
	int			lookingDebounceTime;
	float		legsYaw;

	
	void		*lastG2; 
	int			headBolt;
	int			handRBolt;
	int			handLBolt;
	int			torsoBolt;
	int			crotchBolt;
	int			footRBolt;
	int			footLBolt;
	int			motionBolt;

	int			boltValidityTime;
} renderInfo_t;



struct gclient_s {
	
	playerState_t	ps;				

	
	clientPersistant_t	pers;
	clientSession_t		sess;

	saberInfo_t	saber[2];
	void		*weaponGhoul2[2];

	int			tossableItemDebounce;

	int			bodyGrabTime;
	int			bodyGrabIndex;

	int			pushEffectTime;

	int			invulnerableTimer;

	int			saberCycleQueue;

	int			legsAnimExecute;
	int			torsoAnimExecute;
	qboolean	legsLastFlip;
	qboolean	torsoLastFlip;

	qboolean	readyToExit;		

	qboolean	noclip;

	int			lastCmdTime;		
									
									
	int			buttons;
	int			oldbuttons;
	int			latched_buttons;

	vec3_t		oldOrigin;

	
	
	int			damage_armor;		
	int			damage_blood;		
	int			damage_knockback;	
	vec3_t		damage_from;		
	qboolean	damage_fromWorld;	

	int			damageBoxHandle_Head; 
	int			damageBoxHandle_RLeg; 
	int			damageBoxHandle_LLeg; 

	int			accurateCount;		

	int			accuracy_shots;		
	int			accuracy_hits;		

	
	int			lastkilled_client;	
	int			lasthurt_client;	
	int			lasthurt_mod;		

	
	int			respawnTime;		
	int			inactivityTime;		
	qboolean	inactivityWarning;	
	int			rewardTime;			

	int			airOutTime;

	int			lastKillTime;		

	qboolean	fireHeld;			
	gentity_t	*hook;				

	int			switchTeamTime;		

	int			switchDuelTeamTime;		

	int			switchClassTime;	

	
	
	int			timeResidual;

	char		*areabits;

	int			g2LastSurfaceHit; 
	int			g2LastSurfaceTime; 

	int			corrTime;

	vec3_t		lastHeadAngles;
	int			lookTime;

	int			brokenLimbs;

	qboolean	noCorpse; 

	int			jetPackTime;

	qboolean	jetPackOn;
	int			jetPackToggleTime;
	int			jetPackDebRecharge;
	int			jetPackDebReduce;

	int			cloakToggleTime;
	int			cloakDebRecharge;
	int			cloakDebReduce;

	int			saberStoredIndex; 

	int			saberKnockedTime; 

	vec3_t		olderSaberBase; 
	qboolean	olderIsValid;	

	vec3_t		lastSaberDir_Always; 
	vec3_t		lastSaberBase_Always; 
	int			lastSaberStorageTime; 

	qboolean	hasCurrentPosition;	

	int			dangerTime;		

	int			idleTime;		

	int			idleHealth;		
	vec3_t		idleViewAngles;	

	int			forcePowerSoundDebounce; 

	char		modelname[64];

	qboolean	fjDidJump;

	qboolean	ikStatus;

	int			throwingIndex;
	int			beingThrown;
	int			doingThrow;

	float		hiddenDist;
	vec3_t		hiddenDir;

	renderInfo_t	renderInfo;

	
	npcteam_t	playerTeam;
	npcteam_t	enemyTeam;
	char		*squadname;
	gentity_t	*team_leader;
	gentity_t	*leader;
	gentity_t	*follower;
	int			numFollowers;
	gentity_t	*formationGoal;
	int			nextFormGoal;
	class_t		NPC_class;

	vec3_t		pushVec;
	int			pushVecTime;

	int			siegeClass;
	int			holdingObjectiveItem;

	
	int			isMedHealed;
	int			isMedSupplied;

	
	int			medSupplyDebounce;

	
	int			isHacking;
	vec3_t		hackingAngles;

	
	int			siegeEDataSend;

	int			ewebIndex; 
	int			ewebTime; 
	int			ewebHealth; 

	int			inSpaceIndex; 
	int			inSpaceSuffocation; 

	int			tempSpectate; 

	
	int			jediKickIndex;
	int			jediKickTime;

	
	int			grappleIndex;
	int			grappleState;

	int			solidHack;

	int			noLightningTime;

	unsigned	mGameFlags;

	
	qboolean	iAmALoser;

	int			lastGenCmd;
	int			lastGenCmdTime;
};





typedef struct 
{
	vec3_t		origin;
	char		*target;
} interestPoint_t;





typedef struct 
{
	vec3_t		origin;
	int			flags;


	qboolean	occupied;
	int			waypoint;
	int			dangerTime;
} combatPoint_t;





typedef enum
{
	AET_SIGHT,
	AET_SOUND,
} alertEventType_e;

typedef enum
{
	AEL_MINOR,			
	AEL_SUSPICIOUS,		
	AEL_DISCOVERED,		
	AEL_DANGER,			
	AEL_DANGER_GREAT,	
} alertEventLevel_e;

typedef struct alertEvent_s
{
	vec3_t				position;	
	float				radius;		
	alertEventLevel_e	level;		
	alertEventType_e	type;		
	gentity_t			*owner;		
	float				light;		
	float				addLight;	
	int					ID;			
	int					timestamp;	
} alertEvent_t;




typedef struct
{
	char	targetname[64];
	char	target[64];
	char	target2[64];
	char	target3[64];
	char	target4[64];
	int		nodeID;
} waypointData_t;

typedef struct {
	struct gclient_s	*clients;		

	struct gentity_s	*gentities;
	int			gentitySize;
	int			num_entities;		

	int			warmupTime;			

	fileHandle_t	logFile;

	
	int			maxclients;

	int			framenum;
	int			time;					
	int			previousTime;			

	int			startTime;				

	int			teamScores[TEAM_NUM_TEAMS];
	int			lastTeamLocationTime;		

	qboolean	newSession;				
										

	qboolean	restarted;				

	int			numConnectedClients;
	int			numNonSpectatorClients;	
	int			numPlayingClients;		
	int			sortedClients[32];		
	int			follow1, follow2;		

	int			snd_fry;				

	int			snd_hack;				
    int			snd_medHealed;			
	int			snd_medSupplied;		

	int			warmupModificationCount;	

	
	char		voteString[1024];
	char		voteDisplayString[1024];
	int			voteTime;				
	int			voteExecuteTime;		
	int			voteYes;
	int			voteNo;
	int			numVotingClients;		

	qboolean	votingGametype;
	int			votingGametypeTo;

	
	char		teamVoteString[2][1024];
	int			teamVoteTime[2];		
	int			teamVoteYes[2];
	int			teamVoteNo[2];
	int			numteamVotingClients[2];

	
	qboolean	spawning;				
	int			numSpawnVars;
	char		*spawnVars[64][2];	
	int			numSpawnVarChars;
	char		spawnVarChars[4096];

	
	int			intermissionQueued;		
										
										
										
										
	int			intermissiontime;		
	char		*changemap;
	qboolean	readyToExit;			
	int			exitTime;
	vec3_t		intermission_origin;	
	vec3_t		intermission_angle;

	qboolean	locationLinked;			
	gentity_t	*locationHead;			
	int			bodyQueIndex;			
	gentity_t	*bodyQue[8];
	int			portalSequence;

	alertEvent_t	alertEvents[ 32 ];
	int				numAlertEvents;
	int				curAlertID;

	AIGroupInfo_t	groups[32];

	
	interestPoint_t	interestPoints[64];
	int			numInterestPoints;

	
	combatPoint_t	combatPoints[512];
	int			numCombatPoints;

	
	int			mNumBSPInstances;
	int			mBSPInstanceDepth;
	vec3_t		mOriginAdjust;
	float		mRotationAdjust;
	char		*mTargetAdjust;

	char		mTeamFilter[64];

} level_locals_t;





qboolean	G_SpawnString( const char *key, const char *defaultString, char **out );

qboolean	G_SpawnFloat( const char *key, const char *defaultString, float *out );
qboolean	G_SpawnInt( const char *key, const char *defaultString, int *out );
qboolean	G_SpawnVector( const char *key, const char *defaultString, float *out );
void		G_SpawnEntitiesFromString( qboolean inSubBSP );
char *G_NewString( const char *string );




void Cmd_Score_f (gentity_t *ent);
void StopFollowing( gentity_t *ent );
void BroadcastTeamChange( gclient_t *client, int oldTeam );
void SetTeam( gentity_t *ent, char *s );
void Cmd_FollowCycle_f( gentity_t *ent, int dir );
void Cmd_SaberAttackCycle_f(gentity_t *ent);
int G_ItemUsable(playerState_t *ps, int forcedUse);
void Cmd_ToggleSaber_f(gentity_t *ent);
void Cmd_EngageDuel_f(gentity_t *ent);

gentity_t *G_GetDuelWinner(gclient_t *client);




void ItemUse_Binoculars(gentity_t *ent);
void ItemUse_Shield(gentity_t *ent);
void ItemUse_Sentry(gentity_t *ent);

void Jetpack_Off(gentity_t *ent);
void Jetpack_On(gentity_t *ent);
void ItemUse_Jetpack(gentity_t *ent);
void ItemUse_UseCloak( gentity_t *ent );
void ItemUse_UseDisp(gentity_t *ent, int type);
void ItemUse_UseEWeb(gentity_t *ent);
void G_PrecacheDispensers(void);

void ItemUse_Seeker(gentity_t *ent);
void ItemUse_MedPack(gentity_t *ent);
void ItemUse_MedPack_Big(gentity_t *ent);

void G_CheckTeamItems( void );
void G_RunItem( gentity_t *ent );
void RespawnItem( gentity_t *ent );

void UseHoldableItem( gentity_t *ent );
void PrecacheItem (gitem_t *it);
gentity_t *Drop_Item( gentity_t *ent, gitem_t *item, float angle );
gentity_t *LaunchItem( gitem_t *item, vec3_t origin, vec3_t velocity );
void SetRespawn (gentity_t *ent, float delay);
void G_SpawnItem (gentity_t *ent, gitem_t *item);
void FinishSpawningItem( gentity_t *ent );
void Think_Weapon (gentity_t *ent);
int ArmorIndex (gentity_t *ent);
void	Add_Ammo (gentity_t *ent, int weapon, int count);
void Touch_Item (gentity_t *ent, gentity_t *other, trace_t *trace);

void ClearRegisteredItems( void );
void RegisterItem( gitem_t *item );
void SaveRegisteredItems( void );




int		G_ModelIndex( const char *name );
int		G_SoundIndex( const char *name );
int		G_SoundSetIndex(const char *name);
int		G_EffectIndex( const char *name );
int		G_BSPIndex( const char *name );
int		G_IconIndex( const char* name );

qboolean	G_PlayerHasCustomSkeleton(gentity_t *ent);

void	G_TeamCommand( team_t team, char *cmd );
void	G_ScaleNetHealth(gentity_t *self);
void	G_KillBox (gentity_t *ent);
gentity_t *G_Find (gentity_t *from, int fieldofs, const char *match);
int		G_RadiusList ( vec3_t origin, float radius,	gentity_t *ignore, qboolean takeDamage, gentity_t *ent_list[(1<<10)]);

void	G_Throw( gentity_t *targ, vec3_t newDir, float push );

void	G_FreeFakeClient(gclient_t **cl);
void	G_CreateFakeClient(int entNum, gclient_t **cl);
void	G_CleanAllFakeClients(void);

void	G_SetAnim(gentity_t *ent, usercmd_t *ucmd, int setAnimParts, int anim, int setAnimFlags, int blendTime);
gentity_t *G_PickTarget (char *targetname);
void	GlobalUse(gentity_t *self, gentity_t *other, gentity_t *activator);
void	G_UseTargets2( gentity_t *ent, gentity_t *activator, const char *string );
void	G_UseTargets (gentity_t *ent, gentity_t *activator);
void	G_SetMovedir ( vec3_t angles, vec3_t movedir);
void	G_SetAngles( gentity_t *ent, vec3_t angles );

void	G_InitGentity( gentity_t *e );
gentity_t	*G_Spawn (void);
gentity_t *G_TempEntity( vec3_t origin, int event );
gentity_t	*G_PlayEffect(int fxID, vec3_t org, vec3_t ang);
gentity_t	*G_PlayEffectID(const int fxID, vec3_t org, vec3_t ang);
gentity_t *G_ScreenShake(vec3_t org, gentity_t *target, float intensity, int duration, qboolean global);
void	G_MuteSound( int entnum, int channel );
void	G_Sound( gentity_t *ent, int channel, int soundIndex );
void	G_SoundAtLoc( vec3_t loc, int channel, int soundIndex );
void	G_EntitySound( gentity_t *ent, int channel, int soundIndex );
void	TryUse( gentity_t *ent );
void	G_SendG2KillQueue(void);
void	G_KillG2Queue(int entNum);
void	G_FreeEntity( gentity_t *e );
qboolean	G_EntitiesFree( void );

qboolean G_ActivateBehavior (gentity_t *self, int bset );

void	G_TouchTriggers (gentity_t *ent);
void	G_TouchSolids (gentity_t *ent);
void	GetAnglesForDirection( const vec3_t p1, const vec3_t p2, vec3_t out );





extern void G_RunObject			( gentity_t *ent );


float	*tv (float x, float y, float z);
char	*vtos( const vec3_t v );

void G_AddPredictableEvent( gentity_t *ent, int event, int eventParm );
void G_AddEvent( gentity_t *ent, int event, int eventParm );
void G_SetOrigin( gentity_t *ent, vec3_t origin );
qboolean G_CheckInSolid (gentity_t *self, qboolean fix);
void AddRemap(const char *oldShader, const char *newShader, float timeOffset);
const char *BuildShaderStateConfig(void);



int G_BoneIndex( const char *name );

#line 1 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\namespace_begin.h"















#line 1088 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\g_local.h"

qhandle_t	trap_R_RegisterSkin( const char *name );


void		trap_G2_ListModelSurfaces(void *ghlInfo);
void		trap_G2_ListModelBones(void *ghlInfo, int frame);
void		trap_G2_SetGhoul2ModelIndexes(void *ghoul2, qhandle_t *modelList, qhandle_t *skinList);
qboolean	trap_G2_HaveWeGhoul2Models(void *ghoul2);
qboolean	trap_G2API_GetBoltMatrix(void *ghoul2, const int modelIndex, const int boltIndex, mdxaBone_t *matrix,
								const vec3_t angles, const vec3_t position, const int frameNum, qhandle_t *modelList, vec3_t scale);
qboolean	trap_G2API_GetBoltMatrix_NoReconstruct(void *ghoul2, const int modelIndex, const int boltIndex, mdxaBone_t *matrix,
								const vec3_t angles, const vec3_t position, const int frameNum, qhandle_t *modelList, vec3_t scale);
qboolean	trap_G2API_GetBoltMatrix_NoRecNoRot(void *ghoul2, const int modelIndex, const int boltIndex, mdxaBone_t *matrix,
								const vec3_t angles, const vec3_t position, const int frameNum, qhandle_t *modelList, vec3_t scale);
int			trap_G2API_InitGhoul2Model(void **ghoul2Ptr, const char *fileName, int modelIndex, qhandle_t customSkin,
						  qhandle_t customShader, int modelFlags, int lodBias);
qboolean	trap_G2API_SetSkin(void *ghoul2, int modelIndex, qhandle_t customSkin, qhandle_t renderSkin);

int			trap_G2API_Ghoul2Size ( void* ghlInfo );

int			trap_G2API_AddBolt(void *ghoul2, int modelIndex, const char *boneName);
void		trap_G2API_SetBoltInfo(void *ghoul2, int modelIndex, int boltInfo);

int			trap_G2API_CopyGhoul2Instance(void *g2From, void *g2To, int modelIndex);
void		trap_G2API_CopySpecificGhoul2Model(void *g2From, int modelFrom, void *g2To, int modelTo);
void		trap_G2API_DuplicateGhoul2Instance(void *g2From, void **g2To);
qboolean	trap_G2API_HasGhoul2ModelOnIndex(void *ghlInfo, int modelIndex);
qboolean	trap_G2API_RemoveGhoul2Model(void *ghlInfo, int modelIndex);
qboolean	trap_G2API_RemoveGhoul2Models(void *ghlInfo);
void		trap_G2API_CleanGhoul2Models(void **ghoul2Ptr);
void		trap_G2API_CollisionDetect ( CollisionRecord_t *collRecMap, void* ghoul2, const vec3_t angles, const vec3_t position,
								int frameNumber, int entNum, vec3_t rayStart, vec3_t rayEnd, vec3_t scale, int traceFlags, int useLod, float fRadius );
void		trap_G2API_CollisionDetectCache ( CollisionRecord_t *collRecMap, void* ghoul2, const vec3_t angles, const vec3_t position,
								int frameNumber, int entNum, vec3_t rayStart, vec3_t rayEnd, vec3_t scale, int traceFlags, int useLod, float fRadius );

qboolean	trap_G2API_SetBoneAngles(void *ghoul2, int modelIndex, const char *boneName, const vec3_t angles, const int flags,
								const int up, const int right, const int forward, qhandle_t *modelList,
								int blendTime , int currentTime );
void		trap_G2API_GetGLAName(void *ghoul2, int modelIndex, char *fillBuf);
qboolean	trap_G2API_SetBoneAnim(void *ghoul2, const int modelIndex, const char *boneName, const int startFrame, const int endFrame,
							  const int flags, const float animSpeed, const int currentTime, const float setFrame , const int blendTime );
qboolean	trap_G2API_GetBoneAnim(void *ghoul2, const char *boneName, const int currentTime, float *currentFrame, int *startFrame,
								int *endFrame, int *flags, float *animSpeed, int *modelList, const int modelIndex);
void		trap_G2API_GetSurfaceName(void *ghoul2, int surfNumber, int modelIndex, char *fillBuf);
qboolean	trap_G2API_SetRootSurface(void *ghoul2, const int modelIndex, const char *surfaceName);
qboolean	trap_G2API_SetSurfaceOnOff(void *ghoul2, const char *surfaceName, const int flags);
qboolean	trap_G2API_SetNewOrigin(void *ghoul2, const int boltIndex);
qboolean	trap_G2API_DoesBoneExist(void *ghoul2, int modelIndex, const char *boneName);
int			trap_G2API_GetSurfaceRenderStatus(void *ghoul2, const int modelIndex, const char *surfaceName);

void		trap_G2API_AbsurdSmoothing(void *ghoul2, qboolean status);

void		trap_G2API_SetRagDoll(void *ghoul2, sharedRagDollParams_t *params);
void		trap_G2API_AnimateG2Models(void *ghoul2, int time, sharedRagDollUpdateParams_t *params);


qboolean	trap_G2API_RagPCJConstraint(void *ghoul2, const char *boneName, vec3_t min, vec3_t max); 
qboolean	trap_G2API_RagPCJGradientSpeed(void *ghoul2, const char *boneName, const float speed); 
qboolean	trap_G2API_RagEffectorGoal(void *ghoul2, const char *boneName, vec3_t pos); 
qboolean	trap_G2API_GetRagBonePos(void *ghoul2, const char *boneName, vec3_t pos, vec3_t entAngles, vec3_t entPos, vec3_t entScale); 
qboolean	trap_G2API_RagEffectorKick(void *ghoul2, const char *boneName, vec3_t velocity); 
qboolean	trap_G2API_RagForceSolve(void *ghoul2, qboolean force); 

qboolean	trap_G2API_SetBoneIKState(void *ghoul2, int time, const char *boneName, int ikState, sharedSetBoneIKStateParams_t *params);
qboolean	trap_G2API_IKMove(void *ghoul2, int time, sharedIKMoveParams_t *params);


qboolean	trap_G2API_RemoveBone(void *ghoul2, const char *boneName, int modelIndex);

void		trap_G2API_AttachInstanceToEntNum(void *ghoul2, int entityNum, qboolean server);
void		trap_G2API_ClearAttachedInstance(int entityNum);
void		trap_G2API_CleanEntAttachments(void);
qboolean	trap_G2API_OverrideServer(void *serverInstance);

#line 1 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\namespace_end.h"

















#line 1163 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\g_local.h"








qboolean CanDamage (gentity_t *targ, vec3_t origin);
void G_Damage (gentity_t *targ, gentity_t *inflictor, gentity_t *attacker, vec3_t dir, vec3_t point, int damage, int dflags, int mod);
qboolean G_RadiusDamage (vec3_t origin, gentity_t *attacker, float damage, float radius, gentity_t *ignore, gentity_t *missile, int mod);
void body_die( gentity_t *self, gentity_t *inflictor, gentity_t *attacker, int damage, int meansOfDeath );
void TossClientWeapon(gentity_t *self, vec3_t direction, float speed);
void TossClientItems( gentity_t *self );
void TossClientCubes( gentity_t *self );
void ExplodeDeath( gentity_t *self );
void G_CheckForDismemberment(gentity_t *ent, gentity_t *enemy, vec3_t point, int damage, int deathAnim, qboolean postDeath);
extern int gGAvoidDismember;



























void G_RunExPhys(gentity_t *ent, float gravity, float mass, float bounce, qboolean autoKill, int *g2Bolts, int numG2Bolts);




void G_ReflectMissile( gentity_t *ent, gentity_t *missile, vec3_t forward );

void G_RunMissile( gentity_t *ent );

gentity_t *CreateMissile( vec3_t org, vec3_t dir, float vel, int life, 
							gentity_t *owner, qboolean altFire);
void G_BounceProjectile( vec3_t start, vec3_t impact, vec3_t dir, vec3_t endout );
void G_ExplodeMissile( gentity_t *ent );

void WP_FireBlasterMissile( gentity_t *ent, vec3_t start, vec3_t dir, qboolean altFire );





extern int	BMS_START;
extern int	BMS_MID;
extern int	BMS_END;



void G_PlayDoorLoopSound( gentity_t *ent );
void G_PlayDoorSound( gentity_t *ent, int type );
void G_RunMover( gentity_t *ent );
void Touch_DoorTrigger( gentity_t *ent, gentity_t *other, trace_t *trace );




void trigger_teleporter_touch (gentity_t *self, gentity_t *other, trace_t *trace );











typedef struct reference_tag_s
{
	char		name[32];
	vec3_t		origin;
	vec3_t		angles;
	int			flags;	
	int			radius;	
	qboolean	inuse;
} reference_tag_t;

void TAG_Init( void );
reference_tag_t	*TAG_Find( const char *owner, const char *name );
reference_tag_t	*TAG_Add( const char *name, const char *owner, vec3_t origin, vec3_t angles, int radius, int flags );
int	TAG_GetOrigin( const char *owner, const char *name, vec3_t origin );
int	TAG_GetOrigin2( const char *owner, const char *name, vec3_t origin );
int	TAG_GetAngles( const char *owner, const char *name, vec3_t angles );
int TAG_GetRadius( const char *owner, const char *name );
int TAG_GetFlags( const char *owner, const char *name );

void TeleportPlayer( gentity_t *player, vec3_t origin, vec3_t angles );




void WP_FireTurretMissile( gentity_t *ent, vec3_t start, vec3_t dir, qboolean altFire, int damage, int velocity, int mod, gentity_t *ignore );
void WP_FireGenericBlasterMissile( gentity_t *ent, vec3_t start, vec3_t dir, qboolean altFire, int damage, int velocity, int mod );
qboolean LogAccuracyHit( gentity_t *target, gentity_t *attacker );
void CalcMuzzlePoint ( gentity_t *ent, vec3_t forward, vec3_t right, vec3_t up, vec3_t muzzlePoint );
void SnapVectorTowards( vec3_t v, vec3_t to );
qboolean CheckGauntletAttack( gentity_t *ent );





team_t TeamCount( int ignoreClientNum, int team );
int TeamLeader( int team );
team_t PickTeam( int ignoreClientNum );
void SetClientViewAngle( gentity_t *ent, vec3_t angle );
gentity_t *SelectSpawnPoint ( vec3_t avoidPoint, vec3_t origin, vec3_t angles, team_t team );
void MaintainBodyQueue(gentity_t *ent);
void respawn (gentity_t *ent);
void BeginIntermission (void);
void InitBodyQue (void);
void ClientSpawn( gentity_t *ent );
void player_die (gentity_t *self, gentity_t *inflictor, gentity_t *attacker, int damage, int mod);
void AddScore( gentity_t *ent, vec3_t origin, int score );
void CalculateRanks( void );
qboolean SpotWouldTelefrag( gentity_t *spot );




extern gentity_t *gJMSaberEnt;




qboolean	ConsoleCommand( void );
void G_ProcessIPBans(void);
qboolean G_FilterPacket (char *from);




void FireWeapon( gentity_t *ent, qboolean altFire );
void BlowDetpacks(gentity_t *ent);




void MoveClientToIntermission (gentity_t *client);
void G_SetStats (gentity_t *ent);
void DeathmatchScoreboardMessage (gentity_t *client);













extern vmCvar_t g_ff_objectives;
extern vmCvar_t g_suddendeathtime;

extern vmCvar_t g_walljumpforce;
extern vmCvar_t g_walljumpXvelocity;
extern vmCvar_t g_walljumpYvelocity;
extern vmCvar_t g_walljumpZvelocity;

extern vmCvar_t g_karmapluspw;
extern vmCvar_t g_karmaminuspw;
extern vmCvar_t g_100goldpw;
extern vmCvar_t g_jetpacks;


extern qboolean gDoSlowMoDuel;
extern int gSlowMoDuelTime;

void G_PowerDuelCount(int *loners, int *doubles, qboolean countSpec);

void FindIntermissionPoint( void );
void SetLeader(int team, int client);
void CheckTeamLeader( int team );
void G_RunThink (gentity_t *ent);
void __cdecl G_LogPrintf( const char *fmt, ... );
void SendScoreboardMessageToAllClients( void );
void __cdecl G_Printf( const char *fmt, ... );
void __cdecl G_Error( const char *fmt, ... );
const char *G_GetStringEdString(char *refSection, char *refName);




char *ClientConnect( int clientNum, qboolean firstTime, qboolean isBot );
void ClientUserinfoChanged( int clientNum );
void ClientDisconnect( int clientNum );
void ClientBegin( int clientNum, qboolean allowTeamReset );
void G_BreakArm(gentity_t *ent, int arm);
void G_UpdateClientAnims(gentity_t *self, float animSpeedScale);
void ClientCommand( int clientNum );




void G_CheckClientTimeouts	( gentity_t *ent );
void ClientThink			( int clientNum, usercmd_t *ucmd );
void ClientEndFrame			( gentity_t *ent );
void G_RunClient			( gentity_t *ent );




qboolean OnSameTeam( gentity_t *ent1, gentity_t *ent2 );
void Team_CheckDroppedItem( gentity_t *dropped );




void *G_Alloc( int size );
void G_InitMemory( void );
void Svcmd_GameMem_f( void );




void G_ReadSessionData( gclient_t *client );
void G_InitSessionData( gclient_t *client, char *userinfo, qboolean isBot );

void G_InitWorldSession( void );
void G_WriteSessionData( void );




extern void AddSightEvent( gentity_t *owner, vec3_t position, float radius, alertEventLevel_e alertLevel, float addLight ); 
extern void AddSoundEvent( gentity_t *owner, vec3_t position, float radius, alertEventLevel_e alertLevel, qboolean needLOS ); 
extern qboolean G_CheckForDanger( gentity_t *self, int alertEvent );
extern int G_CheckAlertEvents( gentity_t *self, qboolean checkSight, qboolean checkSound, float maxSeeDist, float maxHearDist, int ignoreAlert, qboolean mustHaveOwner, int minAlertLevel ); 
extern qboolean G_CheckForDanger( gentity_t *self, int alertEvent );
extern qboolean G_ClearLOS( gentity_t *self, const vec3_t start, const vec3_t end );
extern qboolean G_ClearLOS2( gentity_t *self, gentity_t *ent, const vec3_t end );
extern qboolean G_ClearLOS3( gentity_t *self, const vec3_t start, gentity_t *ent );
extern qboolean G_ClearLOS4( gentity_t *self, gentity_t *ent );
extern qboolean G_ClearLOS5( gentity_t *self, const vec3_t end );




void UpdateTournamentInfo( void );






void G_InitBots( qboolean restart );
char *G_GetBotInfoByNumber( int num );
char *G_GetBotInfoByName( const char *name );
void G_CheckBotSpawn( void );
void G_RemoveQueuedBotBegin( int clientNum );
qboolean G_BotConnect( int clientNum, qboolean restart );
void Svcmd_AddBot_f( void );
void Svcmd_BotList_f( void );
void BotInterbreedEndMatch( void );
qboolean G_DoesMapSupportGametype(const char *mapname, int gametype);
const char *G_RefreshNextMap(int gametype, qboolean forced);


gentity_t *G_PreDefSound(vec3_t org, int pdSound);
qboolean HasSetSaberOnly(void);
void WP_ForcePowerStop( gentity_t *self, forcePowers_t forcePower );
void WP_SaberPositionUpdate( gentity_t *self, usercmd_t *ucmd );
int WP_SaberCanBlock(gentity_t *self, vec3_t point, int dflags, int mod, qboolean projectile, int attackStr);
void WP_SaberInitBladeData( gentity_t *ent );
void WP_InitForcePowers( gentity_t *ent );
void WP_SpawnInitForcePowers( gentity_t *ent );
void WP_ForcePowersUpdate( gentity_t *self, usercmd_t *ucmd );
int ForcePowerUsableOn(gentity_t *attacker, gentity_t *other, forcePowers_t forcePower);
void ForceHeal( gentity_t *self );
void ForceSpeed( gentity_t *self, int forceDuration );
void ForceRage( gentity_t *self );
void ForceGrip( gentity_t *self );
void ForceProtect( gentity_t *self );
void ForceAbsorb( gentity_t *self );
void ForceTeamHeal( gentity_t *self );
void ForceTeamForceReplenish( gentity_t *self );
void ForceSeeing( gentity_t *self );
void ForceThrow( gentity_t *self, qboolean pull );
void ForceTelepathy(gentity_t *self);
qboolean Jedi_DodgeEvasion( gentity_t *self, gentity_t *shooter, trace_t *tr, int hitLoc );


void __cdecl G_LogPrintf( const char *fmt, ... );
void __cdecl G_LogWeaponPickup(int client, int weaponid);
void __cdecl G_LogWeaponFire(int client, int weaponid);
void __cdecl G_LogWeaponDamage(int client, int mod, int amount);
void __cdecl G_LogWeaponKill(int client, int mod);
void __cdecl G_LogWeaponDeath(int client, int weaponid);
void __cdecl G_LogWeaponFrag(int attacker, int deadguy);
void __cdecl G_LogWeaponPowerup(int client, int powerupid);
void __cdecl G_LogWeaponItem(int client, int itemid);
void __cdecl G_LogWeaponInit(void);
void __cdecl G_LogWeaponOutput(void);
void __cdecl G_LogExit( const char *string );
void __cdecl G_ClearClientLog(int client);


void InitSiegeMode(void);
void G_SiegeClientExData(gentity_t *msgTarg);



void		TIMER_Clear( void );
void		TIMER_Clear2( gentity_t *ent );
void		TIMER_Set( gentity_t *ent, const char *identifier, int duration );
int			TIMER_Get( gentity_t *ent, const char *identifier );
qboolean	TIMER_Done( gentity_t *ent, const char *identifier );
qboolean	TIMER_Start( gentity_t *self, const char *identifier, int duration );
qboolean	TIMER_Done2( gentity_t *ent, const char *identifier, qboolean remove );
qboolean	TIMER_Exists( gentity_t *ent, const char *identifier );
void		TIMER_Remove( gentity_t *ent, const char *identifier );

float NPC_GetHFOVPercentage( vec3_t spot, vec3_t from, vec3_t facing, float hFOV );
float NPC_GetVFOVPercentage( vec3_t spot, vec3_t from, vec3_t facing, float vFOV );


extern void G_SetEnemy (gentity_t *self, gentity_t *enemy);
qboolean InFront( vec3_t spot, vec3_t from, vec3_t fromAngles, float threshHold );




int		OrgVisible		( vec3_t org1, vec3_t org2, int ignore);
void	BotOrder		( gentity_t *ent, int clientnum, int ordernum);
int		InFieldOfVision	( vec3_t viewangles, float fov, vec3_t angles);


void B_InitAlloc(void);
void B_CleanupAlloc(void);


typedef struct bot_settings_s
{
	char personalityfile[144];
	float skill;
	char team[144];
} bot_settings_t;

int BotAISetup( int restart );
int BotAIShutdown( int restart );
int BotAILoadMap( int restart );
int BotAISetupClient(int client, struct bot_settings_s *settings, qboolean restart);
int BotAIShutdownClient( int client, qboolean restart );
int BotAIStartFrame( int time );

#line 1 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\g_team.h"






























int OtherTeam(int team);
const char *TeamName(int team);
const char *OtherTeamName(int team);
const char *TeamColorString(int team);
void AddTeamScore(vec3_t origin, int team, int score);

void Team_DroppedFlagThink(gentity_t *ent);
void Team_FragBonuses(gentity_t *targ, gentity_t *inflictor, gentity_t *attacker);
void Team_CheckHurtCarrier(gentity_t *targ, gentity_t *attacker);
void Team_InitGame(void);
void Team_ReturnFlag(int team);
void Team_FreeEntity(gentity_t *ent);
gentity_t *SelectCTFSpawnPoint ( team_t team, int teamstate, vec3_t origin, vec3_t angles );
gentity_t *SelectSiegeSpawnPoint ( int siegeClass, team_t team, int teamstate, vec3_t origin, vec3_t angles );
gentity_t *Team_GetLocation(gentity_t *ent);
qboolean Team_GetLocationMsg(gentity_t *ent, char *loc, int loclen);
void TeamplayInfoMessage( gentity_t *ent );
void CheckTeamStatus(void);

int Pickup_Team( gentity_t *ent, gentity_t *other );
#line 1536 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\g_local.h"


level_locals_t	level;
gentity_t		g_entities[(1<<10)];



extern	vmCvar_t	g_gametype;
extern	vmCvar_t	g_dedicated;
extern	vmCvar_t	g_developer;
extern	vmCvar_t	g_cheats;
extern	vmCvar_t	g_maxclients;			
extern	vmCvar_t	g_maxGameClients;		
extern	vmCvar_t	g_restarted;

extern	vmCvar_t	g_trueJedi;

extern	vmCvar_t	g_autoMapCycle;
extern	vmCvar_t	g_dmflags;
extern	vmCvar_t	g_maxForceRank;
extern	vmCvar_t	g_forceBasedTeams;
extern	vmCvar_t	g_privateDuel;

extern	vmCvar_t	g_allowNPC;

extern	vmCvar_t	g_armBreakage;

extern	vmCvar_t	g_saberLocking;
extern	vmCvar_t	g_saberLockFactor;
extern	vmCvar_t	g_saberTraceSaberFirst;

extern	vmCvar_t	d_saberKickTweak;

extern	vmCvar_t	d_powerDuelPrint;

extern	vmCvar_t	d_saberGhoul2Collision;
extern	vmCvar_t	g_saberBladeFaces;
extern	vmCvar_t	d_saberAlwaysBoxTrace;
extern	vmCvar_t	d_saberBoxTraceSize;

extern	vmCvar_t	d_siegeSeekerNPC;

extern	vmCvar_t	g_debugMelee;
extern	vmCvar_t	g_stepSlideFix;

extern	vmCvar_t	g_debugthrow;
extern	vmCvar_t	g_flipkickvelocity;
extern	vmCvar_t	g_flipkickdamage;
extern	vmCvar_t	g_meleedamage;

extern	vmCvar_t	g_crane;
extern	vmCvar_t	g_leveling;
extern  vmCvar_t    g_subadminpw;
extern	vmCvar_t	g_goldadminpw;
extern	vmCvar_t	g_candropsaber;
extern	vmCvar_t	g_canfalldown;
extern	vmCvar_t	g_canmeleekata;
extern  vmCvar_t g_canjk2roll;
extern	vmCvar_t	g_candivecrane;
extern	vmCvar_t	g_cancloak;
extern	vmCvar_t	g_meleeshield;
extern	vmCvar_t	g_canmeleedeflect;
extern	vmCvar_t	g_canhadoken;
extern	vmCvar_t	g_canhadokenfire;
extern	vmCvar_t	g_autorecover;
extern	vmCvar_t	g_canbuy;
extern	vmCvar_t	g_killpath;

extern vmCvar_t g_flipkickforce;
extern vmCvar_t g_craneforce;
extern vmCvar_t g_divecraneforce;
extern vmCvar_t g_throwforce;
extern vmCvar_t g_dropsaberforce;
extern vmCvar_t g_falldownforce;
extern vmCvar_t g_meleekataforce;
extern vmCvar_t g_butterflyforce;
extern vmCvar_t g_cartwheelforce;
extern vmCvar_t g_kataforce;
extern vmCvar_t g_emoteforce;
extern vmCvar_t g_fakedeathforce;

extern vmCvar_t g_hadokenforce;
extern vmCvar_t g_tkbot;

extern vmCvar_t g_debugemotes;
extern vmCvar_t g_debugmw;
extern vmCvar_t g_spawnalt;
extern vmCvar_t g_autothrow;
extern vmCvar_t g_uberthrow;
extern vmCvar_t g_serverculldist;

extern	vmCvar_t	g_noSpecMove;


extern	vmCvar_t	g_disableServerG2;
#line 1632 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\g_local.h"

extern	vmCvar_t	d_perPlayerGhoul2;

extern	vmCvar_t	d_projectileGhoul2Collision;

extern	vmCvar_t	g_g2TraceLod;

extern	vmCvar_t	g_optvehtrace;

extern	vmCvar_t	g_locationBasedDamage;

extern	vmCvar_t	g_allowHighPingDuelist;

extern	vmCvar_t	g_logClientInfo;

extern	vmCvar_t	g_slowmoDuelEnd;

extern	vmCvar_t	g_saberDamageScale;

extern	vmCvar_t	g_useWhileThrowing;

extern	vmCvar_t	g_RMG;

extern	vmCvar_t	g_svfps;

extern	vmCvar_t	g_forceRegenTime;
extern	vmCvar_t	g_spawnInvulnerability;
extern	vmCvar_t	g_forcePowerDisable;
extern	vmCvar_t	g_weaponDisable;

extern	vmCvar_t	g_allowDuelSuicide;
extern	vmCvar_t	g_fraglimitVoteCorrection;

extern	vmCvar_t	g_duelWeaponDisable;
extern	vmCvar_t	g_fraglimit;
extern	vmCvar_t	g_duel_fraglimit;
extern	vmCvar_t	g_timelimit;
extern	vmCvar_t	g_capturelimit;
extern	vmCvar_t	d_saberInterpolate;
extern	vmCvar_t	g_friendlyFire;
extern	vmCvar_t	g_friendlySaber;
extern	vmCvar_t	g_fallfadetime;
extern	vmCvar_t	g_password;
extern	vmCvar_t	g_needpass;
extern	vmCvar_t	g_gravity;
extern	vmCvar_t	g_speed;
extern	vmCvar_t	g_knockback;
extern	vmCvar_t	g_quadfactor;
extern	vmCvar_t	g_forcerespawn;
extern	vmCvar_t	g_siegeRespawn;
extern	vmCvar_t	g_inactivity;
extern	vmCvar_t	g_debugMove;
extern	vmCvar_t	g_debugAlloc;

extern	vmCvar_t	g_debugDamage;
#line 1688 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\g_local.h"
extern	vmCvar_t	g_debugServerSkel;
extern	vmCvar_t	g_weaponRespawn;
extern	vmCvar_t	g_weaponTeamRespawn;
extern	vmCvar_t	g_adaptRespawn;
extern	vmCvar_t	g_synchronousClients;
extern	vmCvar_t	g_motd;
extern	vmCvar_t	g_warmup;
extern	vmCvar_t	g_doWarmup;
extern	vmCvar_t	g_blood;
extern	vmCvar_t	g_allowVote;
extern	vmCvar_t	g_teamAutoJoin;
extern	vmCvar_t	g_teamForceBalance;
extern	vmCvar_t	g_banIPs;
extern	vmCvar_t	g_filterBan;
extern	vmCvar_t	g_debugForward;
extern	vmCvar_t	g_debugRight;
extern	vmCvar_t	g_debugUp;


extern	vmCvar_t	g_smoothClients;
extern	vmCvar_t	g_logstats;


#line 1 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\namespace_begin.h"















#line 1712 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\g_local.h"
extern	vmCvar_t	pmove_fixed;
extern	vmCvar_t	pmove_msec;
#line 1 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\namespace_end.h"

















#line 1715 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\g_local.h"

extern	vmCvar_t	g_enableBreath;
extern	vmCvar_t	g_singlePlayer;
extern	vmCvar_t	g_dismember;
extern	vmCvar_t	g_forceDodge;
extern	vmCvar_t	g_timeouttospec;

extern	vmCvar_t	g_saberDmgVelocityScale;
extern	vmCvar_t	g_saberDmgDelay_Idle;
extern	vmCvar_t	g_saberDmgDelay_Wound;


extern	vmCvar_t	g_saberDebugPrint;
#line 1729 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\g_local.h"

extern	vmCvar_t	g_siegeTeamSwitch;

extern	vmCvar_t	bg_fighterAltControl;


extern	vmCvar_t	g_saberDebugBox;
#line 1737 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\g_local.h"


extern vmCvar_t		d_altRoutes;
extern vmCvar_t		d_patched;
extern	vmCvar_t	d_noIntermissionWait;

extern	vmCvar_t	g_siegeTeam1;
extern	vmCvar_t	g_siegeTeam2;

extern	vmCvar_t	g_austrian;

extern	vmCvar_t	g_powerDuelStartHealth;
extern	vmCvar_t	g_powerDuelEndHealth;
extern	vmCvar_t	g_secretballot;

extern vmCvar_t		g_showDuelHealths;

#line 1 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\namespace_begin.h"















#line 1755 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\g_local.h"

void	trap_Printf( const char *fmt );
void	trap_Error( const char *fmt );
int		trap_Milliseconds( void );
void	trap_PrecisionTimer_Start(void **theNewTimer);
int		trap_PrecisionTimer_End(void *theTimer);
int		trap_Argc( void );
void	trap_Argv( int n, char *buffer, int bufferLength );
void	trap_Args( char *buffer, int bufferLength );
int		trap_FS_FOpenFile( const char *qpath, fileHandle_t *f, fsMode_t mode );
void	trap_FS_Read( void *buffer, int len, fileHandle_t f );
void	trap_FS_Write( const void *buffer, int len, fileHandle_t f );
void	trap_FS_FCloseFile( fileHandle_t f );
int		trap_FS_GetFileList( const char *path, const char *extension, char *listbuf, int bufsize );
void	trap_SendConsoleCommand( int exec_when, const char *text );
void	trap_Cvar_Register( vmCvar_t *cvar, const char *var_name, const char *value, int flags );
void	trap_Cvar_Update( vmCvar_t *cvar );
void	trap_Cvar_Set( const char *var_name, const char *value );
int		trap_Cvar_VariableIntegerValue( const char *var_name );
float	trap_Cvar_VariableValue( const char *var_name );
void	trap_Cvar_VariableStringBuffer( const char *var_name, char *buffer, int bufsize );
void	trap_LocateGameData( gentity_t *gEnts, int numGEntities, int sizeofGEntity_t, playerState_t *gameClients, int sizeofGameClient );
void	trap_DropClient( int clientNum, const char *reason );
void	trap_SendServerCommand( int clientNum, const char *text );
void	trap_SetConfigstring( int num, const char *string );
void	trap_GetConfigstring( int num, char *buffer, int bufferSize );
void	trap_GetUserinfo( int num, char *buffer, int bufferSize );
void	trap_SetUserinfo( int num, const char *buffer );
void	trap_GetServerinfo( char *buffer, int bufferSize );
void	trap_SetServerCull(float cullDistance);
void	trap_SetBrushModel( gentity_t *ent, const char *name );
void	trap_Trace( trace_t *results, const vec3_t start, const vec3_t mins, const vec3_t maxs, const vec3_t end, int passEntityNum, int contentmask );
void	trap_G2Trace( trace_t *results, const vec3_t start, const vec3_t mins, const vec3_t maxs, const vec3_t end, int passEntityNum, int contentmask, int g2TraceType, int traceLod );
int		trap_PointContents( const vec3_t point, int passEntityNum );
qboolean trap_InPVS( const vec3_t p1, const vec3_t p2 );
qboolean trap_InPVSIgnorePortals( const vec3_t p1, const vec3_t p2 );
void	trap_AdjustAreaPortalState( gentity_t *ent, qboolean open );
qboolean trap_AreasConnected( int area1, int area2 );
void	trap_LinkEntity( gentity_t *ent );
void	trap_UnlinkEntity( gentity_t *ent );
int		trap_EntitiesInBox( const vec3_t mins, const vec3_t maxs, int *entityList, int maxcount );
qboolean trap_EntityContact( const vec3_t mins, const vec3_t maxs, const gentity_t *ent );
int		trap_BotAllocateClient( void );
void	trap_BotFreeClient( int clientNum );
void	trap_GetUsercmd( int clientNum, usercmd_t *cmd );
qboolean	trap_GetEntityToken( char *buffer, int bufferSize );


void	trap_SiegePersSet(siegePers_t *pers);
void	trap_SiegePersGet(siegePers_t *pers);






int		trap_DebugPolygonCreate(int color, int numPoints, vec3_t *points);
void	trap_DebugPolygonDelete(int id);

int		trap_BotLibSetup( void );
int		trap_BotLibShutdown( void );
int		trap_BotLibVarSet(char *var_name, char *value);
int		trap_BotLibVarGet(char *var_name, char *value, int size);
int		trap_BotLibDefine(char *string);
int		trap_BotLibStartFrame(float time);
int		trap_BotLibLoadMap(const char *mapname);
int		trap_BotLibUpdateEntity(int ent, void  *bue);
int		trap_BotLibTest(int parm0, char *parm1, vec3_t parm2, vec3_t parm3);

int		trap_BotGetSnapshotEntity( int clientNum, int sequence );
int		trap_BotGetServerCommand(int clientNum, char *message, int size);
void	trap_BotUserCommand(int client, usercmd_t *ucmd);

int		trap_AAS_BBoxAreas(vec3_t absmins, vec3_t absmaxs, int *areas, int maxareas);
int		trap_AAS_AreaInfo( int areanum, void  *info );
void	trap_AAS_EntityInfo(int entnum, void  *info);

int		trap_AAS_Initialized(void);
void	trap_AAS_PresenceTypeBoundingBox(int presencetype, vec3_t mins, vec3_t maxs);
float	trap_AAS_Time(void);

int		trap_AAS_PointAreaNum(vec3_t point);
int		trap_AAS_PointReachabilityAreaIndex(vec3_t point);
int		trap_AAS_TraceAreas(vec3_t start, vec3_t end, int *areas, vec3_t *points, int maxareas);

int		trap_AAS_PointContents(vec3_t point);
int		trap_AAS_NextBSPEntity(int ent);
int		trap_AAS_ValueForBSPEpairKey(int ent, char *key, char *value, int size);
int		trap_AAS_VectorForBSPEpairKey(int ent, char *key, vec3_t v);
int		trap_AAS_FloatForBSPEpairKey(int ent, char *key, float *value);
int		trap_AAS_IntForBSPEpairKey(int ent, char *key, int *value);

int		trap_AAS_AreaReachability(int areanum);

int		trap_AAS_AreaTravelTimeToGoalArea(int areanum, vec3_t origin, int goalareanum, int travelflags);
int		trap_AAS_EnableRoutingArea( int areanum, int enable );
int		trap_AAS_PredictRoute(void  *route, int areanum, vec3_t origin,
							int goalareanum, int travelflags, int maxareas, int maxtime,
							int stopevent, int stopcontents, int stoptfl, int stopareanum);

int		trap_AAS_AlternativeRouteGoals(vec3_t start, int startareanum, vec3_t goal, int goalareanum, int travelflags,
										void  *altroutegoals, int maxaltroutegoals,
										int type);
int		trap_AAS_Swimming(vec3_t origin);
int		trap_AAS_PredictClientMovement(void  *move, int entnum, vec3_t origin, int presencetype, int onground, vec3_t velocity, vec3_t cmdmove, int cmdframes, int maxframes, float frametime, int stopevent, int stopareanum, int visualize);


void	trap_EA_Say(int client, char *str);
void	trap_EA_SayTeam(int client, char *str);
void	trap_EA_Command(int client, char *command);

void	trap_EA_Action(int client, int action);
void	trap_EA_Gesture(int client);
void	trap_EA_Talk(int client);
void	trap_EA_Attack(int client);
void	trap_EA_Use(int client);
void	trap_EA_Respawn(int client);
void	trap_EA_Crouch(int client);
void	trap_EA_MoveUp(int client);
void	trap_EA_MoveDown(int client);
void	trap_EA_MoveForward(int client);
void	trap_EA_MoveBack(int client);
void	trap_EA_MoveLeft(int client);
void	trap_EA_MoveRight(int client);
void	trap_EA_SelectWeapon(int client, int weapon);
void	trap_EA_Jump(int client);
void	trap_EA_DelayedJump(int client);
void	trap_EA_Move(int client, vec3_t dir, float speed);
void	trap_EA_View(int client, vec3_t viewangles);
void	trap_EA_Alt_Attack(int client);
void	trap_EA_ForcePower(int client);

void	trap_EA_EndRegular(int client, float thinktime);
void	trap_EA_GetInput(int client, float thinktime, void  *input);
void	trap_EA_ResetInput(int client);


int		trap_BotLoadCharacter(char *charfile, float skill);
void	trap_BotFreeCharacter(int character);
float	trap_Characteristic_Float(int character, int index);
float	trap_Characteristic_BFloat(int character, int index, float min, float max);
int		trap_Characteristic_Integer(int character, int index);
int		trap_Characteristic_BInteger(int character, int index, int min, int max);
void	trap_Characteristic_String(int character, int index, char *buf, int size);

int		trap_BotAllocChatState(void);
void	trap_BotFreeChatState(int handle);
void	trap_BotQueueConsoleMessage(int chatstate, int type, char *message);
void	trap_BotRemoveConsoleMessage(int chatstate, int handle);
int		trap_BotNextConsoleMessage(int chatstate, void  *cm);
int		trap_BotNumConsoleMessages(int chatstate);
void	trap_BotInitialChat(int chatstate, char *type, int mcontext, char *var0, char *var1, char *var2, char *var3, char *var4, char *var5, char *var6, char *var7 );
int		trap_BotNumInitialChats(int chatstate, char *type);
int		trap_BotReplyChat(int chatstate, char *message, int mcontext, int vcontext, char *var0, char *var1, char *var2, char *var3, char *var4, char *var5, char *var6, char *var7 );
int		trap_BotChatLength(int chatstate);
void	trap_BotEnterChat(int chatstate, int client, int sendto);
void	trap_BotGetChatMessage(int chatstate, char *buf, int size);
int		trap_StringContains(char *str1, char *str2, int casesensitive);
int		trap_BotFindMatch(char *str, void  *match, unsigned long int context);
void	trap_BotMatchVariable(void  *match, int variable, char *buf, int size);
void	trap_UnifyWhiteSpaces(char *string);
void	trap_BotReplaceSynonyms(char *string, unsigned long int context);
int		trap_BotLoadChatFile(int chatstate, char *chatfile, char *chatname);
void	trap_BotSetChatGender(int chatstate, int gender);
void	trap_BotSetChatName(int chatstate, char *name, int client);
void	trap_BotResetGoalState(int goalstate);
void	trap_BotRemoveFromAvoidGoals(int goalstate, int number);
void	trap_BotResetAvoidGoals(int goalstate);
void	trap_BotPushGoal(int goalstate, void  *goal);
void	trap_BotPopGoal(int goalstate);
void	trap_BotEmptyGoalStack(int goalstate);
void	trap_BotDumpAvoidGoals(int goalstate);
void	trap_BotDumpGoalStack(int goalstate);
void	trap_BotGoalName(int number, char *name, int size);
int		trap_BotGetTopGoal(int goalstate, void  *goal);
int		trap_BotGetSecondGoal(int goalstate, void  *goal);
int		trap_BotChooseLTGItem(int goalstate, vec3_t origin, int *inventory, int travelflags);
int		trap_BotChooseNBGItem(int goalstate, vec3_t origin, int *inventory, int travelflags, void  *ltg, float maxtime);
int		trap_BotTouchingGoal(vec3_t origin, void  *goal);
int		trap_BotItemGoalInVisButNotVisible(int viewer, vec3_t eye, vec3_t viewangles, void  *goal);
int		trap_BotGetNextCampSpotGoal(int num, void  *goal);
int		trap_BotGetMapLocationGoal(char *name, void  *goal);
int		trap_BotGetLevelItemGoal(int index, char *classname, void  *goal);
float	trap_BotAvoidGoalTime(int goalstate, int number);
void	trap_BotSetAvoidGoalTime(int goalstate, int number, float avoidtime);
void	trap_BotInitLevelItems(void);
void	trap_BotUpdateEntityItems(void);
int		trap_BotLoadItemWeights(int goalstate, char *filename);
void	trap_BotFreeItemWeights(int goalstate);
void	trap_BotInterbreedGoalFuzzyLogic(int parent1, int parent2, int child);
void	trap_BotSaveGoalFuzzyLogic(int goalstate, char *filename);
void	trap_BotMutateGoalFuzzyLogic(int goalstate, float range);
int		trap_BotAllocGoalState(int state);
void	trap_BotFreeGoalState(int handle);

void	trap_BotResetMoveState(int movestate);
void	trap_BotMoveToGoal(void  *result, int movestate, void  *goal, int travelflags);
int		trap_BotMoveInDirection(int movestate, vec3_t dir, float speed, int type);
void	trap_BotResetAvoidReach(int movestate);
void	trap_BotResetLastAvoidReach(int movestate);
int		trap_BotReachabilityArea(vec3_t origin, int testground);
int		trap_BotMovementViewTarget(int movestate, void  *goal, int travelflags, float lookahead, vec3_t target);
int		trap_BotPredictVisiblePosition(vec3_t origin, int areanum, void  *goal, int travelflags, vec3_t target);
int		trap_BotAllocMoveState(void);
void	trap_BotFreeMoveState(int handle);
void	trap_BotInitMoveState(int handle, void  *initmove);
void	trap_BotAddAvoidSpot(int movestate, vec3_t origin, float radius, int type);

int		trap_BotChooseBestFightWeapon(int weaponstate, int *inventory);
void	trap_BotGetWeaponInfo(int weaponstate, int weapon, void  *weaponinfo);
int		trap_BotLoadWeaponWeights(int weaponstate, char *filename);
int		trap_BotAllocWeaponState(void);
void	trap_BotFreeWeaponState(int weaponstate);
void	trap_BotResetWeaponState(int weaponstate);

int		trap_GeneticParentsAndChildSelection(int numranks, float *ranks, int *parent1, int *parent2, int *child);

void	trap_SnapVector( float *v );

int trap_SP_GetStringTextString(const char *text, char *buffer, int bufferLength);

qboolean	trap_ROFF_Clean( void );
void		trap_ROFF_UpdateEntities( void );
int			trap_ROFF_Cache( char *file );
qboolean	trap_ROFF_Play( int entID, int roffID, qboolean doTranslation );
qboolean	trap_ROFF_Purge_Ent( int entID );


void		trap_TrueMalloc(void **ptr, int size);
void		trap_TrueFree(void **ptr);


int			trap_ICARUS_RunScript( gentity_t *ent, const char *name );
qboolean	trap_ICARUS_RegisterScript( const char *name, qboolean bCalledDuringInterrogate);

void		trap_ICARUS_Init( void );
qboolean	trap_ICARUS_ValidEnt( gentity_t *ent );
qboolean	trap_ICARUS_IsInitialized( int entID );
qboolean	trap_ICARUS_MaintainTaskManager( int entID );
qboolean	trap_ICARUS_IsRunning( int entID );
qboolean	trap_ICARUS_TaskIDPending(gentity_t *ent, int taskID);
void		trap_ICARUS_InitEnt( gentity_t *ent );
void		trap_ICARUS_FreeEnt( gentity_t *ent );
void		trap_ICARUS_AssociateEnt( gentity_t *ent );
void		trap_ICARUS_Shutdown( void );
void		trap_ICARUS_TaskIDSet(gentity_t *ent, int taskType, int taskID);
void		trap_ICARUS_TaskIDComplete(gentity_t *ent, int taskType);
void		trap_ICARUS_SetVar(int taskID, int entID, const char *type_name, const char *data);
int			trap_ICARUS_VariableDeclared(const char *type_name);
int			trap_ICARUS_GetFloatVariable( const char *name, float *value );
int			trap_ICARUS_GetStringVariable( const char *name, const char *value );
int			trap_ICARUS_GetVectorVariable( const char *name, const vec3_t value );



void		trap_Nav_Init( void );
void		trap_Nav_Free( void );
qboolean	trap_Nav_Load( const char *filename, int checksum );
qboolean	trap_Nav_Save( const char *filename, int checksum );
int			trap_Nav_AddRawPoint( vec3_t point, int flags, int radius );
void		trap_Nav_CalculatePaths( qboolean recalc ); 
void		trap_Nav_HardConnect( int first, int second );

void		trap_Nav_ShowNodes( void );
void		trap_Nav_ShowEdges( void );
void		trap_Nav_ShowPath( int start, int end );
int			trap_Nav_GetNearestNode( gentity_t *ent, int lastID, int flags, int targetID );
int			trap_Nav_GetBestNode( int startID, int endID, int rejectID ); 
int			trap_Nav_GetNodePosition( int nodeID, vec3_t out );
int			trap_Nav_GetNodeNumEdges( int nodeID );
int			trap_Nav_GetNodeEdge( int nodeID, int edge );
int			trap_Nav_GetNumNodes( void );
qboolean	trap_Nav_Connected( int startID, int endID );
int			trap_Nav_GetPathCost( int startID, int endID );
int			trap_Nav_GetEdgeCost( int startID, int endID );
int			trap_Nav_GetProjectedNode( vec3_t origin, int nodeID );
void		trap_Nav_CheckFailedNodes( gentity_t *ent );
void		trap_Nav_AddFailedNode( gentity_t *ent, int nodeID );
qboolean	trap_Nav_NodeFailed( gentity_t *ent, int nodeID );
qboolean	trap_Nav_NodesAreNeighbors( int startID, int endID );
void		trap_Nav_ClearFailedEdge( failedEdge_t	*failedEdge );
void		trap_Nav_ClearAllFailedEdges( void );
int			trap_Nav_EdgeFailed( int startID, int endID );
void		trap_Nav_AddFailedEdge( int entID, int startID, int endID );
qboolean	trap_Nav_CheckFailedEdge( failedEdge_t *failedEdge );
void		trap_Nav_CheckAllFailedEdges( void );
qboolean	trap_Nav_RouteBlocked( int startID, int testEdgeID, int endID, int rejectRank );
int			trap_Nav_GetBestNodeAltRoute( int startID, int endID, int *pathCost, int rejectID ); 
int			trap_Nav_GetBestNodeAltRoute2( int startID, int endID, int rejectID ); 
int			trap_Nav_GetBestPathBetweenEnts( gentity_t *ent, gentity_t *goal, int flags );
int			trap_Nav_GetNodeRadius( int nodeID );
void		trap_Nav_CheckBlockedEdges( void );
void		trap_Nav_ClearCheckedNodes( void );
int			trap_Nav_CheckedNode(int wayPoint, int ent); 
void		trap_Nav_SetCheckedNode(int wayPoint, int ent, int value); 
void		trap_Nav_FlagAllNodes( int newFlag );
qboolean	trap_Nav_GetPathsCalculated(void);
void		trap_Nav_SetPathsCalculated(qboolean newVal);


void		trap_SV_RegisterSharedMemory(char *memory);

void trap_SetActiveSubBSP(int index);
int	trap_CM_RegisterTerrain(const char *config);
void trap_RMG_Init(int terrainID);

void trap_Bot_UpdateWaypoints(int wpnum, wpobject_t **wps);
void trap_Bot_CalculatePaths(int rmg);

#line 1 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\namespace_end.h"

















#line 2065 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\g_local.h"

#line 7 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\b_local.h"
#line 1 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\b_public.h"



































































































































































































































































































































































#line 8 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\b_local.h"
#line 1 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\say.h"



typedef enum 
{
	
	SAY_ACKCOMM1,
	SAY_ACKCOMM2,
	SAY_ACKCOMM3,
	SAY_ACKCOMM4,
	
	SAY_REFCOMM1,
	SAY_REFCOMM2,
	SAY_REFCOMM3,
	SAY_REFCOMM4,
	
	SAY_BADCOMM1,
	SAY_BADCOMM2,
	SAY_BADCOMM3,
	SAY_BADCOMM4,
	
	SAY_BADHAIL1,
	SAY_BADHAIL2,
	SAY_BADHAIL3,
	SAY_BADHAIL4,
	
	NUM_SAYINGS
} saying_t;

#line 31 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\say.h"
#line 9 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\b_local.h"

#line 1 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\ai.h"






























































































































#line 11 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\b_local.h"

























void SetNPCGlobals( gentity_t *ent );
void SaveNPCGlobals(void);
void RestoreNPCGlobals(void);
extern vmCvar_t		debugNPCAI;			
extern vmCvar_t		debugNPCFreeze;		
extern vmCvar_t		debugNPCAimingBeam;
extern vmCvar_t		debugBreak;
extern vmCvar_t		debugNoRoam;
extern vmCvar_t		d_JediAI;
extern vmCvar_t		d_saberCombat;

extern void NPC_Think ( gentity_t *self);


extern void NPC_Pain(gentity_t *self, gentity_t *attacker, int damage);
extern void NPC_Touch( gentity_t *self, gentity_t *other, trace_t *trace );
extern void NPC_Use( gentity_t *self, gentity_t *other, gentity_t *activator );
extern float NPC_GetPainChance( gentity_t *self, int damage );




extern void Debug_Printf( vmCvar_t *cv, int level, char *fmt, ... );
extern void Debug_NPCPrintf( gentity_t *printNPC, vmCvar_t *cv, int debugLevel, char *fmt, ... );



extern gentity_t	*NPC;
extern gNPC_t		*NPCInfo;
extern gclient_t	*client;
extern usercmd_t	ucmd;
extern visibility_t	enemyVisibility;


extern qboolean NPC_CheckInvestigate( int alertEventNum );
extern qboolean NPC_StandTrackAndShoot (gentity_t *NPC, qboolean canDuck);
extern void NPC_BSIdle( void );
extern void NPC_BSPointShoot(qboolean shoot);
extern void NPC_BSStandGuard (void);
extern void NPC_BSPatrol (void);
extern void NPC_BSHuntAndKill (void);
extern void NPC_BSStandAndShoot (void);
extern void NPC_BSRunAndShoot (void);
extern void NPC_BSWait( void );
extern void NPC_BSDefault( void );


extern void NPC_BSAdvanceFight (void);
extern void NPC_BSInvestigate (void);
extern void NPC_BSSleep( void );
extern void NPC_BSFlee (void);
extern void NPC_BSFollowLeader (void);
extern void NPC_BSJump (void);
extern void NPC_BSRemove (void);
extern void NPC_BSSearch (void);
extern void NPC_BSSearchStart (int	homeWp, bState_t bState);
extern void NPC_BSWander (void);
extern void NPC_BSFlee( void );
extern void NPC_StartFlee( gentity_t *enemy, vec3_t dangerPoint, int dangerLevel, int fleeTimeMin, int fleeTimeMax );
extern void G_StartFlee( gentity_t *self, gentity_t *enemy, vec3_t dangerPoint, int dangerLevel, int fleeTimeMin, int fleeTimeMax );


extern int ChooseBestWeapon( void );
extern void NPC_ChangeWeapon( int newWeapon );
extern void ShootThink( void );
extern void WeaponThink( qboolean inCombat );
extern qboolean HaveWeapon( int weapon );
extern qboolean CanShoot ( gentity_t *ent, gentity_t *shooter );
extern void NPC_CheckPossibleEnemy( gentity_t *other, visibility_t vis );
extern gentity_t *NPC_PickEnemy (gentity_t *closestTo, int enemyTeam, qboolean checkVis, qboolean findPlayersFirst, qboolean findClosest);
extern gentity_t *NPC_CheckEnemy (qboolean findNew, qboolean tooFarOk, qboolean setEnemy ); 
extern qboolean NPC_CheckAttack (float scale);
extern qboolean NPC_CheckDefend (float scale);
extern qboolean NPC_CheckCanAttack (float attack_scale, qboolean stationary);
extern int NPC_AttackDebounceForWeapon (void);
extern qboolean EntIsGlass (gentity_t *check);
extern qboolean ShotThroughGlass (trace_t *tr, gentity_t *target, vec3_t spot, int mask);
extern qboolean ValidEnemy (gentity_t *ent);
extern void G_ClearEnemy (gentity_t *self);
extern gentity_t *NPC_PickAlly ( qboolean facingEachOther, float range, qboolean ignoreGroup, qboolean movingOnly );
extern void NPC_LostEnemyDecideChase(void);
extern float NPC_MaxDistSquaredForWeapon( void );
extern qboolean NPC_EvaluateShot( int hit, qboolean glassOK );
extern int NPC_ShotEntity( gentity_t *ent, vec3_t impactPos ); 


extern qboolean NPC_SlideMoveToGoal (void);
extern float NPC_FindClosestTeammate (gentity_t *self);
extern void NPC_CalcClosestFormationSpot(gentity_t *self);
extern void G_MaintainFormations (gentity_t *self);
extern void NPC_BSFormation (void);
extern void NPC_CreateFormation (gentity_t *self);
extern void NPC_DropFormation (gentity_t *self);
extern void NPC_ReorderFormation (gentity_t *self);
extern void NPC_InsertIntoFormation (gentity_t *self);
extern void NPC_DeleteFromFormation (gentity_t *self);




















extern void SetGoal( gentity_t *goal, float rating );
extern void NPC_SetGoal( gentity_t *goal, float rating );
extern void NPC_ClearGoal( void );
extern void NPC_ReachedGoal( void );
extern qboolean ReachedGoal( gentity_t *goal );
extern gentity_t *UpdateGoal( void );
extern qboolean NPC_ClearPathToGoal(vec3_t dir, gentity_t *goal);
extern qboolean NPC_MoveToGoal( qboolean tryStraight );










extern qboolean CanSee ( gentity_t *ent );
extern qboolean InFOV ( gentity_t *ent, gentity_t *from, int hFOV, int vFOV );
extern qboolean InFOV2( vec3_t origin, gentity_t *from, int hFOV, int vFOV );
extern qboolean InFOV3( vec3_t spot, vec3_t from, vec3_t fromAngles, int hFOV, int vFOV );
extern visibility_t NPC_CheckVisibility ( gentity_t *ent, int flags );
extern qboolean InVisrange ( gentity_t *ent );





extern void NPC_Spawn ( gentity_t *ent, gentity_t *other, gentity_t *activator );


extern int NPC_ReactionTime ( void );
extern qboolean NPC_ParseParms( const char *NPCName, gentity_t *NPC );
extern void NPC_LoadParms( void );


extern int	teamNumbers[TEAM_NUM_TEAMS];
extern int	teamStrength[TEAM_NUM_TEAMS];
extern int	teamCounter[TEAM_NUM_TEAMS];
extern void CalcEntitySpot ( const gentity_t *ent, const spot_t spot, vec3_t point );
extern qboolean NPC_UpdateAngles ( qboolean doPitch, qboolean doYaw );
extern void NPC_UpdateShootAngles (vec3_t angles, qboolean doPitch, qboolean doYaw );
extern qboolean NPC_UpdateFiringAngles ( qboolean doPitch, qboolean doYaw );
extern void SetTeamNumbers (void);
extern qboolean G_ActivateBehavior (gentity_t *self, int bset );
extern void NPC_AimWiggle( vec3_t enemy_org );
extern void NPC_SetLookTarget( gentity_t *self, int entNum, int clearTime );


extern int NAV_FindClosestWaypointForEnt (gentity_t *ent, int targWp);
extern qboolean NAV_CheckAhead( gentity_t *self, vec3_t end, trace_t *trace, int clipmask );


extern float IdealDistance ( gentity_t *self );


extern void NPC_SetSayState (gentity_t *self, gentity_t *to, int saying);


extern qboolean G_CheckInSolid (gentity_t *self, qboolean fix);




extern void NPC_SetAnim(gentity_t *ent, int type, int anim, int priority);
extern qboolean NPC_EnemyTooFar(gentity_t *enemy, float dist, qboolean toShoot);




void NPC_SetBoneAngles(gentity_t *ent, char *bone, vec3_t angles);


void NPC_SetSurfaceOnOff(gentity_t *ent, const char *surfaceName, int surfaceFlags);

extern qboolean NPC_ClearLOS( const vec3_t start, const vec3_t end );
extern qboolean NPC_ClearLOS5( const vec3_t end );
extern qboolean NPC_ClearLOS4( gentity_t *ent ) ;
extern qboolean NPC_ClearLOS3( const vec3_t start, gentity_t *ent );
extern qboolean NPC_ClearLOS2( gentity_t *ent, const vec3_t end );

extern qboolean NPC_ClearShot( gentity_t *ent );

extern int NPC_FindCombatPoint( const vec3_t position, const vec3_t avoidPosition, vec3_t enemyPosition, const int flags, const float avoidDist, const int ignorePoint ); 


extern qboolean NPC_ReserveCombatPoint( int combatPointID );
extern qboolean NPC_FreeCombatPoint( int combatPointID, qboolean failed ); 
extern qboolean NPC_SetCombatPoint( int combatPointID );































extern qboolean NPC_ValidEnemy( gentity_t *ent );
extern qboolean NPC_CheckEnemyExt( qboolean checkAlerts ); 
extern qboolean NPC_FindPlayer( void );
extern qboolean NPC_CheckCanAttackExt( void );

extern int NPC_CheckAlertEvents( qboolean checkSight, qboolean checkSound, int ignoreAlert, qboolean mustHaveOwner, int minAlertLevel ); 
extern qboolean NPC_CheckForDanger( int alertEvent );
extern void G_AlertTeam( gentity_t *victim, gentity_t *attacker, float radius, float soundDist );

extern int NPC_FindSquadPoint( vec3_t position );

extern void ClearPlayerAlertEvents( void );

extern qboolean G_BoundsOverlap(const vec3_t mins1, const vec3_t maxs1, const vec3_t mins2, const vec3_t maxs2);
extern qboolean NAV_HitNavGoal( vec3_t point, vec3_t mins, vec3_t maxs, vec3_t dest, int radius, qboolean flying );

extern void NPC_SetMoveGoal( gentity_t *ent, vec3_t point, int radius, qboolean isNavGoal, int combatPoint, gentity_t *targetEnt ); 

extern qboolean NAV_ClearPathToPoint(gentity_t *self, vec3_t pmins, vec3_t pmaxs, vec3_t point, int clipmask, int okToHitEnt );
extern void NPC_ApplyWeaponFireDelay(void);


extern qboolean NPC_FacePosition( vec3_t position, qboolean doPitch ); 
extern qboolean NPC_FaceEntity( gentity_t *ent, qboolean doPitch ); 
extern qboolean NPC_FaceEnemy( qboolean doPitch ); 


extern vmCvar_t	g_spskill;













typedef struct navInfo_s
{
	gentity_t	*blocker;
	vec3_t		direction;
	vec3_t		pathDirection;
	float		distance;
	trace_t		trace;
	int			flags;
} navInfo_t;

extern int	NAV_MoveToGoal( gentity_t *self, navInfo_t *info );
extern void NAV_GetLastMove( navInfo_t *info );
extern qboolean NAV_AvoidCollision( gentity_t *self, gentity_t *goal, navInfo_t *info );


#line 330 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\b_local.h"
#line 2 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\npc_ai_jedi.c"
#line 1 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\g_nav.h"

















































extern	qboolean navCalculatePaths;

extern	qboolean NAVDEBUG_showNodes;
extern	qboolean NAVDEBUG_showRadius;
extern	qboolean NAVDEBUG_showEdges;
extern	qboolean NAVDEBUG_showTestPath;
extern	qboolean NAVDEBUG_showEnemyPath;
extern	qboolean NAVDEBUG_showCombatPoints;
extern	qboolean NAVDEBUG_showNavGoals;
extern	qboolean NAVDEBUG_showCollision;

extern	int	 NAVDEBUG_curGoal;

void NAV_Shutdown( void );
void NAV_CalculatePaths( const char *filename, int checksum );
void NAV_CalculateSquadPaths( const char *filename, int checksum );

void NAV_ShowDebugInfo( void );

int NAV_GetNearestNode( gentity_t *self, int lastNode );
extern int NAV_TestBestNode( gentity_t *self, int startID, int endID, qboolean failEdge );

qboolean NPC_GetMoveDirection( vec3_t out, float *distance );
void NPC_MoveToGoalExt( vec3_t point );
void NAV_FindPlayerWaypoint( int clNum );
qboolean NAV_CheckAhead( gentity_t *self, vec3_t end, trace_t *trace, int clipmask );
#line 77 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\g_nav.h"

#line 79 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\g_nav.h"
#line 3 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\npc_ai_jedi.c"
#line 1 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\anims.h"






































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































#line 4 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\npc_ai_jedi.c"
#line 1 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\w_saber.h"


































typedef enum
{
	FJ_FORWARD,
	FJ_BACKWARD,
	FJ_RIGHT,
	FJ_LEFT,
	FJ_UP
};

typedef enum
{
	EVASION_NONE = 0,
	EVASION_PARRY,
	EVASION_DUCK_PARRY,
	EVASION_JUMP_PARRY,
	EVASION_DODGE,
	EVASION_JUMP,
	EVASION_DUCK,
	EVASION_FJUMP,
	EVASION_CARTWHEEL,
	EVASION_OTHER,
	NUM_EVASION_TYPES
} evasionType_t;

extern vmCvar_t g_MaxHolocronCarry;









#line 1 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\namespace_begin.h"















#line 70 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\w_saber.h"
extern int forcePowerNeeded[NUM_FORCE_POWER_LEVELS][NUM_FORCE_POWERS];
extern float forceJumpHeight[NUM_FORCE_POWER_LEVELS];
extern float forceJumpStrength[NUM_FORCE_POWER_LEVELS];
extern float forcePushPullRadius[NUM_FORCE_POWER_LEVELS];
#line 1 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\namespace_end.h"

















#line 75 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\w_saber.h"
#line 5 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\npc_ai_jedi.c"

#line 1 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\namespace_begin.h"















#line 7 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\npc_ai_jedi.c"
extern qboolean BG_SabersOff( playerState_t *ps );
#line 1 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\namespace_end.h"

















#line 9 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\npc_ai_jedi.c"

extern void CG_DrawAlert( vec3_t origin, float rating );
extern void G_AddVoiceEvent( gentity_t *self, int event, int speakDebounceTime );
extern void ForceJump( gentity_t *self, usercmd_t *ucmd );
extern vmCvar_t	g_saberRealisticCombat;
extern vmCvar_t	d_slowmodeath;

void G_StartMatrixEffect( gentity_t *ent )
{ 

}


















extern void NPC_ClearLookTarget( gentity_t *self );
extern void NPC_SetLookTarget( gentity_t *self, int entNum, int clearTime );
extern void NPC_TempLookTarget( gentity_t *self, int lookEntNum, int minLookTime, int maxLookTime );
extern qboolean G_ExpandPointToBBox( vec3_t point, const vec3_t mins, const vec3_t maxs, int ignore, int clipmask );
extern qboolean NPC_CheckEnemyStealth( void );
extern void G_SoundOnEnt( gentity_t *ent, soundChannel_t channel, const char *soundPath );

#line 1 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\namespace_begin.h"















#line 46 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\npc_ai_jedi.c"
extern gitem_t	*BG_FindItemForAmmo( ammo_t ammo );
#line 1 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\namespace_end.h"

















#line 48 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\npc_ai_jedi.c"

extern void ForceThrow( gentity_t *self, qboolean pull );
extern void ForceLightning( gentity_t *self );
extern void ForceHeal( gentity_t *self );
extern void ForceRage( gentity_t *self );
extern void ForceProtect( gentity_t *self );
extern void ForceAbsorb( gentity_t *self );
extern int WP_MissileBlockForBlock( int saberBlock );
extern qboolean G_GetHitLocFromSurfName( gentity_t *ent, const char *surfName, int *hitLoc, vec3_t point, vec3_t dir, vec3_t bladeDir, int mod );
extern qboolean WP_ForcePowerUsable( gentity_t *self, forcePowers_t forcePower, int overrideAmt );
extern qboolean WP_ForcePowerAvailable( gentity_t *self, forcePowers_t forcePower, int overrideAmt );
extern void WP_ForcePowerStop( gentity_t *self, forcePowers_t forcePower );
extern void WP_DeactivateSaber( gentity_t *self, qboolean clearLength ); 
extern void WP_ActivateSaber( gentity_t *self );


#line 1 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\namespace_begin.h"















#line 65 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\npc_ai_jedi.c"
extern qboolean PM_SaberInStart( int move );
extern qboolean BG_SaberInSpecialAttack( int anim );
extern qboolean BG_SaberInAttack( int move );
extern qboolean PM_SaberInBounce( int move );
extern qboolean PM_SaberInParry( int move );
extern qboolean PM_SaberInKnockaway( int move );
extern qboolean PM_SaberInBrokenParry( int move );
extern qboolean PM_SaberInDeflect( int move );
extern qboolean BG_SpinningSaberAnim( int anim );
extern qboolean BG_FlippingAnim( int anim );
extern qboolean PM_RollingAnim( int anim );
extern qboolean PM_InKnockDown( playerState_t *ps );
extern qboolean BG_InRoll( playerState_t *ps, int anim );
extern qboolean BG_CrouchAnim( int anim );
#line 1 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\namespace_end.h"

















#line 80 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\npc_ai_jedi.c"

extern qboolean NPC_SomeoneLookingAtMe(gentity_t *ent);

extern int WP_GetVelocityForForceJump( gentity_t *self, vec3_t jumpVel, usercmd_t *ucmd );

extern void G_TestLine(vec3_t start, vec3_t end, int color, int time);

static void Jedi_Aggression( gentity_t *self, int change );
qboolean Jedi_WaitingAmbush( gentity_t *self );

#line 1 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\namespace_begin.h"















#line 91 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\npc_ai_jedi.c"
extern int bg_parryDebounce[];
#line 1 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\namespace_end.h"

















#line 93 "c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\npc_ai_jedi.c"

static int	jediSpeechDebounceTime[TEAM_NUM_TEAMS];

enum
{
	LSTATE_NONE = 0,
	LSTATE_UNDERFIRE,
	LSTATE_INVESTIGATE,
};

void NPC_ShadowTrooper_Precache( void )
{
	RegisterItem( BG_FindItemForAmmo( AMMO_FORCE ) );
	G_SoundIndex( "sound/chars/shadowtrooper/cloak.wav" );
	G_SoundIndex( "sound/chars/shadowtrooper/decloak.wav" );
}

void Jedi_ClearTimers( gentity_t *ent )
{
	TIMER_Set( ent, "roamTime", 0 );
	TIMER_Set( ent, "chatter", 0 );
	TIMER_Set( ent, "strafeLeft", 0 );
	TIMER_Set( ent, "strafeRight", 0 );
	TIMER_Set( ent, "noStrafe", 0 );
	TIMER_Set( ent, "walking", 0 );
	TIMER_Set( ent, "taunting", 0 );
	TIMER_Set( ent, "parryTime", 0 );
	TIMER_Set( ent, "parryReCalcTime", 0 );
	TIMER_Set( ent, "forceJumpChasing", 0 );
	TIMER_Set( ent, "jumpChaseDebounce", 0 );
	TIMER_Set( ent, "moveforward", 0 );
	TIMER_Set( ent, "moveback", 0 );
	TIMER_Set( ent, "movenone", 0 );
	TIMER_Set( ent, "moveright", 0 );
	TIMER_Set( ent, "moveleft", 0 );
	TIMER_Set( ent, "movecenter", 0 );
	TIMER_Set( ent, "saberLevelDebounce", 0 );
	TIMER_Set( ent, "noRetreat", 0 );
	TIMER_Set( ent, "holdLightning", 0 );
	TIMER_Set( ent, "gripping", 0 );
	TIMER_Set( ent, "draining", 0 );
	TIMER_Set( ent, "noturn", 0 );
}

void Jedi_PlayBlockedPushSound( gentity_t *self )
{
	if ( !self->s.number )
	{
		G_AddVoiceEvent( self, EV_PUSHFAIL, 3000 );
	}
	else if ( self->health > 0 && self->NPC && self->NPC->blockedSpeechDebounceTime < level.time )
	{
		G_AddVoiceEvent( self, EV_PUSHFAIL, 3000 );
		self->NPC->blockedSpeechDebounceTime = level.time + 3000;
	}
}

void Jedi_PlayDeflectSound( gentity_t *self )
{
	if ( !self->s.number )
	{
		G_AddVoiceEvent( self, Q_irand( EV_DEFLECT1, EV_DEFLECT3 ), 3000 );
	}
	else if ( self->health > 0 && self->NPC && self->NPC->blockedSpeechDebounceTime < level.time )
	{
		G_AddVoiceEvent( self, Q_irand( EV_DEFLECT1, EV_DEFLECT3 ), 3000 );
		self->NPC->blockedSpeechDebounceTime = level.time + 3000;
	}
}

void NPC_Jedi_PlayConfusionSound( gentity_t *self )
{
	if ( self->health > 0 )
	{
		if ( self->client && ( self->client->NPC_class == CLASS_TAVION || self->client->NPC_class == CLASS_DESANN ) )
		{
			G_AddVoiceEvent( self, Q_irand( EV_CONFUSE1, EV_CONFUSE3 ), 2000 );
		}
		else if ( Q_irand( 0, 1 ) )
		{
			G_AddVoiceEvent( self, Q_irand( EV_TAUNT1, EV_TAUNT3 ), 2000 );
		}
		else
		{
			G_AddVoiceEvent( self, Q_irand( EV_GLOAT1, EV_GLOAT3 ), 2000 );
		}
	}
}

void Boba_Precache( void )
{
	G_SoundIndex( "sound/boba/jeton.wav" );
	G_SoundIndex( "sound/boba/jethover.wav" );
	G_SoundIndex( "sound/effects/combustfire.mp3" );
	G_EffectIndex( "boba/jet" );
	G_EffectIndex( "boba/fthrw" );
}

extern void G_CreateG2AttachedWeaponModel( gentity_t *ent, const char *weaponModel, int boltNum, int weaponNum );
extern void ChangeWeapon( gentity_t *ent, int newWeapon );
void Boba_ChangeWeapon( int wp )
{
	if ( NPC->s.weapon == wp )
	{
		return;
	}
	NPC_ChangeWeapon( wp );
	G_AddEvent( NPC, EV_GENERAL_SOUND, G_SoundIndex( "sound/weapons/change.wav" ));
}

void WP_ResistForcePush( gentity_t *self, gentity_t *pusher, qboolean noPenalty )
{
	int parts;
	qboolean runningResist = qfalse;

	if ( !self || self->health <= 0 || !self->client || !pusher || !pusher->client ) 
	{
		return;
	}
	if ( (!self->s.number || self->client->NPC_class == CLASS_DESANN || !Q_stricmp("Yoda",self->NPC_type) || self->client->NPC_class == CLASS_LUKE)
		&& (VectorLengthSquared( self->client->ps.velocity ) > 10000 || self->client->ps.fd.forcePowerLevel[FP_PUSH] >= FORCE_LEVEL_3 || self->client->ps.fd.forcePowerLevel[FP_PULL] >= FORCE_LEVEL_3 ) )
	{
		runningResist = qtrue;
	}
	if ( !runningResist
		&& self->client->ps.groundEntityNum != ((1<<10)-1) 
		&& !BG_SpinningSaberAnim( self->client->ps.legsAnim ) 
		&& !BG_FlippingAnim( self->client->ps.legsAnim ) 
		&& !PM_RollingAnim( self->client->ps.legsAnim ) 
		&& !PM_InKnockDown( &self->client->ps ) 
		&& !BG_CrouchAnim( self->client->ps.legsAnim ))
	{
		parts = 1|2;
	}
	else
	{
		parts = 1;
	}
	NPC_SetAnim( self, parts, BOTH_RESISTPUSH, 1|2 );
	if ( !noPenalty )
	{
		char buf[128];
		float tFVal = 0;

		trap_Cvar_VariableStringBuffer("timescale", buf, sizeof(buf));

		tFVal = atof(buf);

		if ( !runningResist )
		{
			((self->client->ps.velocity)[0]=(self->client->ps.velocity)[1]=(self->client->ps.velocity)[2]=0);
			
			
			self->client->ps.weaponTime = 1000;
			if ( self->client->ps.fd.forcePowersActive&(1<<FP_SPEED) )
			{
				self->client->ps.weaponTime = floor( self->client->ps.weaponTime * tFVal );
			}
			self->client->ps.pm_time = self->client->ps.weaponTime;
			self->client->ps.pm_flags |= 64;
			
			
			
		}
		else
		{
			self->client->ps.weaponTime = 600;
			if ( self->client->ps.fd.forcePowersActive&(1<<FP_SPEED) )
			{
				self->client->ps.weaponTime = floor( self->client->ps.weaponTime * tFVal );
			}
		}
	}
	
	self->client->ps.powerups[PW_DISINT_4] = level.time + self->client->ps.torsoTimer + 500;
	self->client->ps.powerups[PW_PULL] = 0;
	Jedi_PlayBlockedPushSound( self );
}

qboolean Boba_StopKnockdown( gentity_t *self, gentity_t *pusher, vec3_t pushDir, qboolean forceKnockdown ) 
{
	vec3_t	pDir, fwd, right, ang;
	float	fDot, rDot;
	int		strafeTime;

	if ( self->client->NPC_class != CLASS_BOBAFETT )
	{
		return qfalse;
	}

	if ( (self->client->ps.eFlags2&(1<<4)) )
	{
		return qtrue;
	}

	((ang)[0]=(0), (ang)[1]=(self->r.currentAngles[1]), (ang)[2]=(0));
	strafeTime = Q_irand( 1000, 2000 );

	AngleVectors( ang, fwd, right, ((void *)0) );
	VectorNormalize2( pushDir, pDir );
	fDot = ((pDir)[0]*(fwd)[0]+(pDir)[1]*(fwd)[1]+(pDir)[2]*(fwd)[2]);
	rDot = ((pDir)[0]*(right)[0]+(pDir)[1]*(right)[1]+(pDir)[2]*(right)[2]);

	if ( Q_irand( 0, 2 ) )
	{
		usercmd_t	tempCmd;
		if ( fDot >= 0.4f )
		{
			tempCmd.forwardmove = 127;
			TIMER_Set( self, "moveforward", strafeTime );
		}
		else if ( fDot <= -0.4f )
		{
			tempCmd.forwardmove = -127;
			TIMER_Set( self, "moveback", strafeTime );
		}
		else if ( rDot > 0 )
		{
			tempCmd.rightmove = 127;
			TIMER_Set( self, "strafeRight", strafeTime );
			TIMER_Set( self, "strafeLeft", -1 );
		}
		else
		{
			tempCmd.rightmove = -127;
			TIMER_Set( self, "strafeLeft", strafeTime );
			TIMER_Set( self, "strafeRight", -1 );
		}
		G_AddEvent( self, EV_JUMP, 0 );
		if ( !Q_irand( 0, 1 ) )
		{
			self->client->ps.fd.forceJumpCharge = 280;
			ForceJump( self, &tempCmd );
		}
		else
		{
			TIMER_Set( self, "duck", strafeTime );
		}
		self->painDebounceTime = 0;
	}
	else if ( !Q_irand( 0, 1 ) && forceKnockdown )
	{
		WP_ResistForcePush( self, pusher, qtrue );
	}
	else
	{
		return qfalse;
	}

	return qtrue;
}

void Boba_FlyStart( gentity_t *self )
{
	if ( TIMER_Done( self, "jetRecharge" ) )
	{
		self->client->ps.gravity = 0;
		if ( self->NPC )
		{
			self->NPC->aiFlags |= 0x00200000;
		}
		self->client->ps.eFlags2 |= (1<<4);
		self->client->jetPackTime = level.time + Q_irand( 3000, 10000 );
		
		G_SoundOnEnt( self, CHAN_ITEM, "sound/boba/jeton.wav" );
		
		self->s.loopSound = G_SoundIndex( "sound/boba/jethover.wav" );
		if ( self->NPC )
		{
			self->count = 16777216; 
		}
	}
}

void Boba_FlyStop( gentity_t *self )
{
	self->client->ps.gravity = g_gravity.value;
	if ( self->NPC )
	{
		self->NPC->aiFlags &= ~0x00200000;
	}
	self->client->ps.eFlags2 &= ~(1<<4);
	self->client->jetPackTime = 0;
	
	self->s.loopSound = 0;
	if ( self->NPC )
	{
		self->count = 0; 
		TIMER_Set( self, "jetRecharge", Q_irand( 1000, 5000 ) );
		TIMER_Set( self, "jumpChaseDebounce", Q_irand( 500, 2000 ) );
	}
}

qboolean Boba_Flying( gentity_t *self )
{
	return ((qboolean)(self->client->ps.eFlags2&(1<<4)));
}

void Boba_FireFlameThrower( gentity_t *self )
{
	int		damage	= Q_irand( 20, 30 );
	trace_t		tr;
	gentity_t	*traceEnt = ((void *)0);
	mdxaBone_t	boltMatrix;
	vec3_t		start, end, dir, traceMins = {-4, -4, -4}, traceMaxs = {4, 4, 4};

	damage = Q_irand (1,3);

	trap_G2API_GetBoltMatrix( self->ghoul2, 0, self->client->renderInfo.handLBolt,
			&boltMatrix, self->r.currentAngles, self->r.currentOrigin, level.time,
			((void *)0), self->modelScale );

	BG_GiveMeVectorFromMatrix( &boltMatrix, ORIGIN, start );
	BG_GiveMeVectorFromMatrix( &boltMatrix, NEGATIVE_Y, dir );
	
	((end)[0]=(start)[0]+(dir)[0]*(128),(end)[1]=(start)[1]+(dir)[1]*(128),(end)[2]=(start)[2]+(dir)[2]*(128));

	trap_Trace( &tr, start, traceMins, traceMaxs, end, self->s.number, (0x00000001|0x00000100|0x00000200|0x00001000) );

	traceEnt = &g_entities[tr.entityNum];
	if ( tr.entityNum < ((1<<10)-2) && traceEnt->takedamage )
	{
		G_Damage( traceEnt, self, self, dir, tr.endpos, damage, 0x00000002|0x00000004|0x00000100, MOD_LAVA );
		
	}
}


void Boba_StartFlameThrower( gentity_t *self )
{
	int	flameTime = 4000;
	mdxaBone_t	boltMatrix;
	vec3_t		org, dir;

	self->client->ps.torsoTimer = flameTime;
	if ( self->NPC )
	{
		TIMER_Set( self, "nextAttackDelay", flameTime );
		TIMER_Set( self, "walking", 0 );
	}
	TIMER_Set( self, "flameTime", flameTime );
	



























	G_SoundOnEnt( self, CHAN_WEAPON, "sound/effects/combustfire.mp3" );

	trap_G2API_GetBoltMatrix(NPC->ghoul2, 0, NPC->client->renderInfo.handRBolt, &boltMatrix, NPC->r.currentAngles,
		NPC->r.currentOrigin, level.time, ((void *)0), NPC->modelScale);

	BG_GiveMeVectorFromMatrix( &boltMatrix, ORIGIN, org );
	BG_GiveMeVectorFromMatrix( &boltMatrix, NEGATIVE_Y, dir );

	G_PlayEffectID( G_EffectIndex("boba/fthrw"), org, dir);
}

void Boba_DoFlameThrower( gentity_t *self )
{
	NPC_SetAnim( self, 1, BOTH_FORCELIGHTNING_HOLD, 1|2 );
	if ( TIMER_Done( self, "nextAttackDelay" ) && TIMER_Done( self, "flameTime" ) )
	{
		Boba_StartFlameThrower( self );
	}
	Boba_FireFlameThrower( self );
}

void Boba_FireDecide( void )
{
	qboolean enemyLOS = qfalse;
	qboolean enemyCS = qfalse;
	qboolean enemyInFOV = qfalse;
	
	qboolean faceEnemy = qfalse;
	qboolean shoot = qfalse;
	qboolean hitAlly = qfalse;
	vec3_t	impactPos;
	float	enemyDist;
	float	dot;
	vec3_t	enemyDir, shootDir;

	if ( NPC->client->ps.groundEntityNum == ((1<<10)-1) 
		&& NPC->client->ps.fd.forceJumpZStart
		&& !BG_FlippingAnim( NPC->client->ps.legsAnim )
		&& !Q_irand( 0, 10 ) )
	{
		Boba_FlyStart( NPC );
	}

	if ( !NPC->enemy )
	{
		return;
	}

	





if ( NPC->enemy->s.weapon == WP_SABER )
	{
		NPCInfo->scriptFlags &= ~0x00000040;
		Boba_ChangeWeapon( WP_ROCKET_LAUNCHER );
	}
	else
	{
		if ( NPC->health < NPC->client->pers.maxHealth*0.5f )
		{
			NPCInfo->scriptFlags |= 0x00000040;
			Boba_ChangeWeapon( WP_BLASTER );
			NPCInfo->burstMin = 3;
			NPCInfo->burstMean = 12;
			NPCInfo->burstMax = 20;
			NPCInfo->burstSpacing = Q_irand( 300, 750 );
		}
		else
		{
			NPCInfo->scriptFlags &= ~0x00000040;
			Boba_ChangeWeapon( WP_BLASTER );
		}
	}

	((impactPos)[0]=(impactPos)[1]=(impactPos)[2]=0);
	enemyDist = DistanceSquared( NPC->r.currentOrigin, NPC->enemy->r.currentOrigin );

	((enemyDir)[0]=(NPC->enemy->r.currentOrigin)[0]-(NPC->r.currentOrigin)[0],(enemyDir)[1]=(NPC->enemy->r.currentOrigin)[1]-(NPC->r.currentOrigin)[1],(enemyDir)[2]=(NPC->enemy->r.currentOrigin)[2]-(NPC->r.currentOrigin)[2]);
	VectorNormalize( enemyDir );
	AngleVectors( NPC->client->ps.viewangles, shootDir, ((void *)0), ((void *)0) );
	dot = ((enemyDir)[0]*(shootDir)[0]+(enemyDir)[1]*(shootDir)[1]+(enemyDir)[2]*(shootDir)[2]);
	if ( dot > 0.5f ||( enemyDist * (1.0f-dot)) < 10000 )
	{
		enemyInFOV = qtrue;
	}

	if ( (enemyDist < (128*128)&&enemyInFOV) || !TIMER_Done( NPC, "flameTime" ) )
	{
		







	}
	else if ( enemyDist < 16384 )
	{
		if ( (NPC->client->ps.weapon == WP_FLECHETTE || NPC->client->ps.weapon == WP_REPEATER) && 
			(NPCInfo->scriptFlags & 0x00000040) )
		{
			NPCInfo->scriptFlags &= ~0x00000040;
			
		}
	}
	else if ( enemyDist > 65536 )
	{
		if ( NPC->client->ps.weapon == WP_DISRUPTOR )
		{
			if ( !(NPCInfo->scriptFlags&0x00000040) )
			{
				NPCInfo->scriptFlags |= 0x00000040;
				
				NPC_ChangeWeapon( WP_DISRUPTOR );
				NPC_UpdateAngles( qtrue, qtrue );
				return;
			}
		}
	}

	
	if ( TIMER_Done( NPC, "nextAttackDelay" ) && TIMER_Done( NPC, "flameTime" ) )
	{
		if ( NPC_ClearLOS4( NPC->enemy ) )
		{
			NPCInfo->enemyLastSeenTime = level.time;
			enemyLOS = qtrue;

			if ( NPC->client->ps.weapon == WP_NONE )
			{
				enemyCS = qfalse;
			}
			else
			{
				if ( (NPC->client->ps.weapon == WP_ROCKET_LAUNCHER || (NPC->client->ps.weapon == WP_FLECHETTE && (NPCInfo->scriptFlags&0x00000040))) && enemyDist < 16384 )
				{
					enemyCS = qfalse;
					hitAlly = qtrue;
					
				}
				else if ( enemyInFOV )
				{
					int hit = NPC_ShotEntity( NPC->enemy, impactPos );
					gentity_t *hitEnt = &g_entities[hit];

					if ( hit == NPC->enemy->s.number 
						|| ( hitEnt && hitEnt->client && hitEnt->client->playerTeam == NPC->client->enemyTeam )
						|| ( hitEnt && hitEnt->takedamage && ((hitEnt->r.svFlags&0x08000000)||hitEnt->health < 40||NPC->s.weapon == WP_EMPLACED_GUN) ) )
					{
						enemyCS = qtrue;
						
						((NPCInfo->enemyLastSeenLocation)[0]=(NPC->enemy->r.currentOrigin)[0],(NPCInfo->enemyLastSeenLocation)[1]=(NPC->enemy->r.currentOrigin)[1],(NPCInfo->enemyLastSeenLocation)[2]=(NPC->enemy->r.currentOrigin)[2]);
					}
					else
					{
						
						if ( hitEnt && hitEnt->client && hitEnt->client->playerTeam == NPC->client->playerTeam )
						{
							hitAlly = qtrue;
						}
						else
						{
						}
					}
				}
				else
				{
					enemyCS = qfalse;
				}
			}
		}
		else if ( trap_InPVS( NPC->enemy->r.currentOrigin, NPC->r.currentOrigin ) )
		{
			NPCInfo->enemyLastSeenTime = level.time;
			faceEnemy = qtrue;
			
		}

		if ( NPC->client->ps.weapon == WP_NONE )
		{
			faceEnemy = qfalse;
			shoot = qfalse;
		}
		else
		{
			if ( enemyLOS )
			{
				faceEnemy = qtrue;
			}
			if ( enemyCS )
			{
				shoot = qtrue;
			}
		}

		if ( !enemyCS )
		{
			
			
			if ( !hitAlly 
				&& enemyInFOV 
				&& NPCInfo->enemyLastSeenTime > 0 )
			{
				if ( level.time - NPCInfo->enemyLastSeenTime < 10000 )
				{
					if ( !Q_irand( 0, 10 ) )
					{
						
						vec3_t	muzzle, dir, angles;
						qboolean tooClose = qfalse;
						qboolean tooFar = qfalse;
						float distThreshold;
						float dist;

						CalcEntitySpot( NPC, SPOT_HEAD, muzzle );
						if ( VectorCompare( impactPos, vec3_origin ) )
						{
							trace_t tr;
							
							vec3_t	forward, end;
							AngleVectors( NPC->client->ps.viewangles, forward, ((void *)0), ((void *)0) );
							((end)[0]=(muzzle)[0]+(forward)[0]*(8192),(end)[1]=(muzzle)[1]+(forward)[1]*(8192),(end)[2]=(muzzle)[2]+(forward)[2]*(8192));
							trap_Trace( &tr, muzzle, vec3_origin, vec3_origin, end, NPC->s.number, (0x00000001|0x00000100|0x00000200|0x00001000) );
							((impactPos)[0]=(tr.endpos)[0],(impactPos)[1]=(tr.endpos)[1],(impactPos)[2]=(tr.endpos)[2]);
						}

						
						distThreshold = 16384;
						switch ( NPC->s.weapon )
						{
						case WP_ROCKET_LAUNCHER:
						case WP_FLECHETTE:
						case WP_THERMAL:
						case WP_TRIP_MINE:
						case WP_DET_PACK:
							distThreshold = 65536;
							break;
						case WP_REPEATER:
							if ( NPCInfo->scriptFlags&0x00000040 )
							{
								distThreshold = 65536;
							}
							break;
						default:
							break;
						}

						dist = DistanceSquared( impactPos, muzzle );

						if ( dist < distThreshold )
						{
							tooClose = qtrue;
						}
						else if ( level.time - NPCInfo->enemyLastSeenTime > 5000 ||
							(NPCInfo->group && level.time - NPCInfo->group->lastSeenEnemyTime > 5000 ))
						{
							
							distThreshold = 65536;
							switch ( NPC->s.weapon )
							{
							case WP_ROCKET_LAUNCHER:
							case WP_FLECHETTE:
							case WP_THERMAL:
							case WP_TRIP_MINE:
							case WP_DET_PACK:
								distThreshold = 262144;
								break;
							case WP_REPEATER:
								if ( NPCInfo->scriptFlags&0x00000040 )
								{
									distThreshold = 262144;
								}
								break;
							default:
								break;
							}
							dist = DistanceSquared( impactPos, NPCInfo->enemyLastSeenLocation );
							if ( dist > distThreshold )
							{
								tooFar = qtrue;
							}
						}

						if ( !tooClose && !tooFar )
						{
							((dir)[0]=(NPCInfo->enemyLastSeenLocation)[0]-(muzzle)[0],(dir)[1]=(NPCInfo->enemyLastSeenLocation)[1]-(muzzle)[1],(dir)[2]=(NPCInfo->enemyLastSeenLocation)[2]-(muzzle)[2]);
							VectorNormalize( dir );
							vectoangles( dir, angles );

							NPCInfo->desiredYaw		= angles[1];
							NPCInfo->desiredPitch	= angles[0];

							shoot = qtrue;
							faceEnemy = qfalse;
						}
					}
				}
			}
		}

		
		if ( NPC->client->ps.weaponTime > 0 )
		{
			if ( NPC->s.weapon == WP_ROCKET_LAUNCHER )
			{
				if ( !enemyLOS || !enemyCS )
				{
					NPC->client->ps.weaponTime = 0;
				}
				else
				{
					TIMER_Set( NPC, "nextAttackDelay", Q_irand( 500, 1000 ) );
				}
			}
		}
		else if ( shoot )
		{
			if ( TIMER_Done( NPC, "nextAttackDelay" ) )
			{
				if( !(NPCInfo->scriptFlags & 0x00040000) ) 
				{
					WeaponThink( qtrue );
				}
				
				if ( NPC->s.weapon == WP_ROCKET_LAUNCHER 
					&& (ucmd.buttons&1) 
					&& !Q_irand( 0, 3 ) )
				{
					ucmd.buttons &= ~1;
					ucmd.buttons |= 128;
					NPC->client->ps.weaponTime = Q_irand( 500, 1500 );
				}
			}
		}
	}
}

void Jedi_Cloak( gentity_t *self )
{
	if ( self )
	{
		self->flags |= 0x00000020;
		if ( self->client )
		{
			if ( !self->client->ps.powerups[PW_CLOAKED] )
			{
				
				self->client->ps.powerups[PW_CLOAKED] = 16777216;

				
				
				
			}
		}
	}
}

void Jedi_Decloak( gentity_t *self )
{
	if ( self )
	{
		self->flags &= ~0x00000020;
		if ( self->client )
		{
			if ( self->client->ps.powerups[PW_CLOAKED] )
			{
				self->client->ps.powerups[PW_CLOAKED] = 0;

				
			}
		}
	}
}

void Jedi_CheckCloak( void )
{
	if ( NPC && NPC->client && NPC->client->NPC_class == CLASS_SHADOWTROOPER )
	{
		if ( !NPC->client->ps.saberHolstered ||
			NPC->health <= 0 || 
			NPC->client->ps.saberInFlight ||
		
		
			NPC->painDebounceTime > level.time )
		{
			Jedi_Decloak( NPC );
		}
		else if ( NPC->health > 0 
			&& !NPC->client->ps.saberInFlight 
		
		
			&& NPC->painDebounceTime < level.time )
		{
			Jedi_Cloak( NPC );
		}
	}
}





static void Jedi_Aggression( gentity_t *self, int change )
{
	int	upper_threshold, lower_threshold;

	self->NPC->stats.aggression += change;
	
	
	if ( self->client->playerTeam == NPCTEAM_PLAYER )
	{
		upper_threshold = 7;
		lower_threshold = 1;
	}
	else
	{
		if ( self->client->NPC_class == CLASS_DESANN )
		{
			upper_threshold = 20;
			lower_threshold = 5;
		}
		else
		{
			upper_threshold = 10;
			lower_threshold = 3;
		}
	}

	if ( self->NPC->stats.aggression > upper_threshold )
	{
		self->NPC->stats.aggression = upper_threshold;
	}
	else if ( self->NPC->stats.aggression < lower_threshold )
	{
		self->NPC->stats.aggression = lower_threshold;
	}
	
}

static void Jedi_AggressionErosion( int amt )
{
	if ( TIMER_Done( NPC, "roamTime" ) )
	{
		TIMER_Set( NPC, "roamTime", Q_irand( 2000, 5000 ) );
		Jedi_Aggression( NPC, amt );
	}
	
	if ( NPCInfo->stats.aggression < 4 || (NPCInfo->stats.aggression < 6&&NPC->client->NPC_class == CLASS_DESANN))
	{
		WP_DeactivateSaber( NPC, qfalse );
	}
}

void NPC_Jedi_RateNewEnemy( gentity_t *self, gentity_t *enemy )
{
	float healthAggression;
	float weaponAggression;
	int newAggression;

	switch( enemy->s.weapon )
	{
	case WP_SABER:
		healthAggression = (float)self->health/200.0f*8.0f;
		weaponAggression = 6;
		
		
		break;
	case WP_BLASTER:
		if ( DistanceSquared( self->r.currentOrigin, enemy->r.currentOrigin ) < 65536 )
		{
			healthAggression = (float)self->health/200.0f*8.0f;
			weaponAggression = 8;
		}
		else
		{
			healthAggression = 8.0f - ((float)self->health/200.0f*8.0f);
			weaponAggression = 2;
		}
		break;
	default:
		healthAggression = (float)self->health/200.0f*8.0f;
		weaponAggression = 6;
		break;
	}
	
	newAggression = ceil( (healthAggression + weaponAggression + (float)self->NPC->stats.aggression )/3.0f);
	
	Jedi_Aggression( self, newAggression - self->NPC->stats.aggression );

	
	TIMER_Set( self, "chatter", Q_irand( 4000, 7000 ) );
}

static void Jedi_Rage( void )
{
	Jedi_Aggression( NPC, 10 - NPCInfo->stats.aggression + Q_irand( -2, 2 ) );
	TIMER_Set( NPC, "roamTime", 0 );
	TIMER_Set( NPC, "chatter", 0 );
	TIMER_Set( NPC, "walking", 0 );
	TIMER_Set( NPC, "taunting", 0 );
	TIMER_Set( NPC, "jumpChaseDebounce", 0 );
	TIMER_Set( NPC, "movenone", 0 );
	TIMER_Set( NPC, "movecenter", 0 );
	TIMER_Set( NPC, "noturn", 0 );
	ForceRage( NPC );
}

void Jedi_RageStop( gentity_t *self )
{
	if ( self->NPC )
	{
		TIMER_Set( self, "roamTime", 0 );
		Jedi_Aggression( self, Q_irand( -5, 0 ) );
	}
}






static qboolean Jedi_BattleTaunt( void )
{
	if ( TIMER_Done( NPC, "chatter" ) 
		&& !Q_irand( 0, 3 ) 
		&& NPCInfo->blockedSpeechDebounceTime < level.time 
		&& jediSpeechDebounceTime[NPC->client->playerTeam] < level.time )
	{
		int event = -1;
		if ( NPC->client->playerTeam == NPCTEAM_PLAYER 
			&& NPC->enemy && NPC->enemy->client && NPC->enemy->client->NPC_class == CLASS_JEDI )
		{
			if ( NPC->client->NPC_class == CLASS_JEDI && NPCInfo->rank == RANK_COMMANDER )
			{
				event = EV_TAUNT1;
			}
		}
		else
		{
			event = Q_irand( EV_TAUNT1, EV_TAUNT3 );
		}
		if ( event != -1 )
		{
			G_AddVoiceEvent( NPC, event, 3000 );
			jediSpeechDebounceTime[NPC->client->playerTeam] = NPCInfo->blockedSpeechDebounceTime = level.time + 6000;
			TIMER_Set( NPC, "chatter", Q_irand( 5000, 10000 ) );

			if ( NPC->enemy && NPC->enemy->NPC && NPC->enemy->s.weapon == WP_SABER && NPC->enemy->client && NPC->enemy->client->NPC_class == CLASS_JEDI )
			{
			}
			return qtrue;
		}
	}
	return qfalse;
}






static qboolean Jedi_ClearPathToSpot( vec3_t dest, int impactEntNum )
{
	trace_t	trace;
	vec3_t	mins, start, end, dir;
	float	dist, drop;
	float	i;

	
	((mins)[0]=(NPC->r.mins[0]), (mins)[1]=(NPC->r.mins[1]), (mins)[2]=(NPC->r.mins[2] + 18));
	
	trap_Trace( &trace, NPC->r.currentOrigin, mins, NPC->r.maxs, dest, NPC->s.number, NPC->clipmask );

	
	if ( trace.allsolid || trace.startsolid )
	{
		return qfalse;
	}

	if ( trace.fraction < 1.0f )
	{
		if ( impactEntNum != ((1<<10)-1) && trace.entityNum == impactEntNum )
		{
			return qtrue;
		}
		else
		{
			return qfalse;
		}
	}

	
	
	((dir)[0]=(dest)[0]-(NPC->r.currentOrigin)[0],(dir)[1]=(dest)[1]-(NPC->r.currentOrigin)[1],(dir)[2]=(dest)[2]-(NPC->r.currentOrigin)[2]);
	dist = VectorNormalize( dir );
	if ( dest[2] > NPC->r.currentOrigin[2] )
	{
		drop = 18;
	}
	else
	{
		drop = 64;
	}
	for ( i = NPC->r.maxs[0]*2; i < dist; i += NPC->r.maxs[0]*2 )
	{
		((start)[0]=(NPC->r.currentOrigin)[0]+(dir)[0]*(i),(start)[1]=(NPC->r.currentOrigin)[1]+(dir)[1]*(i),(start)[2]=(NPC->r.currentOrigin)[2]+(dir)[2]*(i));
		((end)[0]=(start)[0],(end)[1]=(start)[1],(end)[2]=(start)[2]);
		end[2] -= drop;
		trap_Trace( &trace, start, mins, NPC->r.maxs, end, NPC->s.number, NPC->clipmask );
		if ( trace.fraction < 1.0f || trace.allsolid || trace.startsolid )
		{
			continue;
		}
		
		return qfalse;
	}
	
	return qtrue;
}

qboolean NPC_MoveDirClear( int forwardmove, int rightmove, qboolean reset )
{
	vec3_t	forward, right, testPos, angles, mins;
	trace_t	trace;
	float	fwdDist, rtDist;
	float	bottom_max = -18*4 - 1;

	if ( !forwardmove && !rightmove )
	{
		
		return qtrue;
	}

	if ( ucmd.upmove > 0 || NPC->client->ps.fd.forceJumpCharge )
	{
		
		return qtrue;
	}

	if ( NPC->client->ps.groundEntityNum == ((1<<10)-1) )
	{
		
		return qtrue;
	}
	












	
	
	
	((mins)[0]=(NPC->r.mins)[0],(mins)[1]=(NPC->r.mins)[1],(mins)[2]=(NPC->r.mins)[2]);
	mins[2] += 18;
	angles[0] = angles[2] = 0;
	angles[1] = NPC->client->ps.viewangles[1];
	AngleVectors( angles, forward, right, ((void *)0) );
	fwdDist = ((float)forwardmove)/2.0f;
	rtDist = ((float)rightmove)/2.0f;
	((testPos)[0]=(NPC->r.currentOrigin)[0]+(forward)[0]*(fwdDist),(testPos)[1]=(NPC->r.currentOrigin)[1]+(forward)[1]*(fwdDist),(testPos)[2]=(NPC->r.currentOrigin)[2]+(forward)[2]*(fwdDist));
	((testPos)[0]=(testPos)[0]+(right)[0]*(rtDist),(testPos)[1]=(testPos)[1]+(right)[1]*(rtDist),(testPos)[2]=(testPos)[2]+(right)[2]*(rtDist));
	trap_Trace( &trace, NPC->r.currentOrigin, mins, NPC->r.maxs, testPos, NPC->s.number, NPC->clipmask|0x00000040 );
	if ( trace.allsolid || trace.startsolid )
	{
		
		if ( reset )
		{
			trace.fraction = 1.0f;
		}
		((trace.endpos)[0]=(testPos)[0],(trace.endpos)[1]=(testPos)[1],(trace.endpos)[2]=(testPos)[2]);
		
	}
	if ( trace.fraction < 0.6 )
	{
		if ( (NPC->enemy && trace.entityNum == NPC->enemy->s.number) || (NPCInfo->goalEntity && trace.entityNum == NPCInfo->goalEntity->s.number) )
		{
			
			return qtrue;
		}
		else if ( reset )
		{
			
			ucmd.forwardmove = 0;
			ucmd.rightmove = 0;
			((NPC->client->ps.moveDir)[0]=(NPC->client->ps.moveDir)[1]=(NPC->client->ps.moveDir)[2]=0);
		}
		return qfalse;
	}

	if ( NPCInfo->goalEntity )
	{
		if ( NPCInfo->goalEntity->r.currentOrigin[2] < NPC->r.currentOrigin[2] )
		{
			bottom_max += NPCInfo->goalEntity->r.currentOrigin[2] - NPC->r.currentOrigin[2];
		}
	}
	((testPos)[0]=(trace.endpos)[0],(testPos)[1]=(trace.endpos)[1],(testPos)[2]=(trace.endpos)[2]);
	testPos[2] += bottom_max;

	trap_Trace( &trace, trace.endpos, mins, NPC->r.maxs, testPos, NPC->s.number, NPC->clipmask );

	
	

	if ( trace.allsolid || trace.startsolid )
	{
		
		return qtrue;
	}

	if ( trace.fraction < 1.0 )
	{
		
		
		return qtrue;
	}

	
	if ( reset )
	{
		
		ucmd.forwardmove *= -1.0;
		ucmd.rightmove *= -1.0;
		((NPC->client->ps.moveDir)[0]=(NPC->client->ps.moveDir)[0]*(-1),(NPC->client->ps.moveDir)[1]=(NPC->client->ps.moveDir)[1]*(-1),(NPC->client->ps.moveDir)[2]=(NPC->client->ps.moveDir)[2]*(-1));
	}
	return qfalse;
}






static void Jedi_HoldPosition( void )
{
	
	NPCInfo->goalEntity = ((void *)0);
	
	





}







static void Jedi_Move( gentity_t *goal, qboolean retreat )
{
	qboolean	moved;
	navInfo_t	info;

	NPCInfo->combatMove = qtrue;
	NPCInfo->goalEntity = goal;

	moved = NPC_MoveToGoal( qtrue );

	
	if ( retreat )
	{
		ucmd.forwardmove *= -1;
		ucmd.rightmove *= -1;
		((NPC->client->ps.moveDir)[0]=(NPC->client->ps.moveDir)[0]*(-1),(NPC->client->ps.moveDir)[1]=(NPC->client->ps.moveDir)[1]*(-1),(NPC->client->ps.moveDir)[2]=(NPC->client->ps.moveDir)[2]*(-1));
	}
	
	
	NAV_GetLastMove( &info );

	
	if ( ( info.flags & 0x00000004 ) && ( info.blocker == NPC->enemy ) )
	{
		Jedi_HoldPosition();
	}

	
	if ( moved == qfalse )
	{
		Jedi_HoldPosition();
	}
}

static qboolean Jedi_Hunt( void )
{
	
	
	if ( NPCInfo->stats.aggression > 1 )
	{
		NPCInfo->combatMove = qtrue;
		if ( !(NPCInfo->scriptFlags&0x00000400) )
		{
			NPC_UpdateAngles( qtrue, qtrue );
			return qtrue;
		}
		else
		{
			if ( NPCInfo->goalEntity == ((void *)0) )
			{
				NPCInfo->goalEntity = NPC->enemy;
			}
			
			if ( NPC_MoveToGoal( qfalse ) )
			{
				NPC_UpdateAngles( qtrue, qtrue );
				return qtrue;
			}
		}
	}
	return qfalse;
}



















static void Jedi_Retreat( void )
{
	if ( !TIMER_Done( NPC, "noRetreat" ) )
	{
		return;
	}
	
	
	
	Jedi_Move( NPC->enemy, qtrue );
}

static void Jedi_Advance( void )
{
	if ( !NPC->client->ps.saberInFlight )
	{
		
		WP_ActivateSaber(NPC);
	}
	
	Jedi_Move( NPC->enemy, qfalse );
		
	
	
	
}

static void Jedi_AdjustSaberAnimLevel( gentity_t *self, int newLevel )
{	
	if ( !self || !self->client )
	{
		return;
	}
	
	if ( self->client->NPC_class == CLASS_TAVION )
	{
		self->client->ps.fd.saberAnimLevel = ((FORCE_LEVEL_3+1)+1);
		return;
	}
	else if ( self->client->NPC_class == CLASS_DESANN )
	{
		self->client->ps.fd.saberAnimLevel = (FORCE_LEVEL_3+1);
		return;
	}
	if ( self->client->playerTeam == NPCTEAM_ENEMY )
	{
		if ( self->NPC->rank == RANK_CIVILIAN || self->NPC->rank == RANK_LT_JG )
		{
			self->client->ps.fd.saberAnimLevel = FORCE_LEVEL_1;
			return;
		}
		if ( self->NPC->rank == RANK_CREWMAN 
			|| self->NPC->rank == RANK_ENSIGN )
		{
			self->client->ps.fd.saberAnimLevel = FORCE_LEVEL_2;
			return;
		}
		






	}
	
	if ( newLevel > self->client->ps.fd.forcePowerLevel[FP_SABER_OFFENSE] )
	{
		self->client->ps.fd.saberAnimLevel = self->client->ps.fd.forcePowerLevel[FP_SABER_OFFENSE];
	}
	else if ( newLevel < FORCE_LEVEL_1 )
	{
		self->client->ps.fd.saberAnimLevel = FORCE_LEVEL_1;
	}
	else
	{
		self->client->ps.fd.saberAnimLevel = newLevel;
	}

	if ( d_JediAI.integer )
	{
		switch ( self->client->ps.fd.saberAnimLevel )
		{
		case FORCE_LEVEL_1:
			Com_Printf( "^2""%s Saber Attack Set: fast\n", self->NPC_type );
			break;
		case FORCE_LEVEL_2:
			Com_Printf( "^3""%s Saber Attack Set: medium\n", self->NPC_type );
			break;
		case FORCE_LEVEL_3:
			Com_Printf( "^1""%s Saber Attack Set: strong\n", self->NPC_type );
			break;
		}
	}
}

static void Jedi_CheckDecreaseSaberAnimLevel( void )
{
	if ( !NPC->client->ps.weaponTime && !(ucmd.buttons&(1|128)) )
	{
		if ( TIMER_Done( NPC, "saberLevelDebounce" ) && !Q_irand( 0, 10 ) )
		{
			
			Jedi_AdjustSaberAnimLevel( NPC, Q_irand( FORCE_LEVEL_1, FORCE_LEVEL_3 ));
			TIMER_Set( NPC, "saberLevelDebounce", Q_irand( 3000, 10000 ) );
		}
	}
	else
	{
		TIMER_Set( NPC, "saberLevelDebounce", Q_irand( 1000, 5000 ) );
	}
}

static void Jedi_CombatDistance( int enemy_dist )
{
	if ( NPC->client->ps.fd.forcePowersActive&(1<<FP_GRIP) &&
		NPC->client->ps.fd.forcePowerLevel[FP_GRIP] > FORCE_LEVEL_1 )
	{
		return;
	}
	else if ( !TIMER_Done( NPC, "gripping" ) )
	{
		TIMER_Set( NPC, "gripping", -level.time );
		TIMER_Set( NPC, "attackDelay", Q_irand( 0, 1000 ) );
	}
	
	if ( NPC->client->ps.fd.forcePowersActive&(1<<FP_DRAIN) &&
		NPC->client->ps.fd.forcePowerLevel[FP_DRAIN] > FORCE_LEVEL_1 )
	{
		return;
	}
	else if ( !TIMER_Done( NPC, "draining" ) )
	{
		TIMER_Set( NPC, "draining", -level.time );
		TIMER_Set( NPC, "attackDelay", Q_irand( 0, 1000 ) );
	}

	if ( NPC->client->NPC_class == CLASS_BOBAFETT )
	{
		if ( !TIMER_Done( NPC, "flameTime" ) )
		{
			if ( enemy_dist > 50 )
			{
				Jedi_Advance();
			}
			else if ( enemy_dist <= 0 )
			{
				Jedi_Retreat();
			}
		}
		else if ( enemy_dist < 200 )
		{
			Jedi_Retreat();
		}
		else if ( enemy_dist > 1024 )
		{
			Jedi_Advance();
		}
	}
	else if ( NPC->client->ps.saberInFlight &&
		!PM_SaberInBrokenParry( NPC->client->ps.saberMove )
		&& NPC->client->ps.saberBlocked != BLOCKED_PARRY_BROKEN )
	{
		if ( enemy_dist < NPC->client->ps.saberEntityDist )
		{
			Jedi_Retreat();
		}
		else if ( enemy_dist > NPC->client->ps.saberEntityDist && enemy_dist > 100 )
		{
			Jedi_Advance();
		}
		if ( NPC->client->ps.weapon == WP_SABER 
			&& NPC->client->ps.saberEntityState == 1  
			&& NPC->client->ps.fd.forcePowerLevel[FP_SABERTHROW] > FORCE_LEVEL_1 
			&& !(NPC->client->ps.fd.forcePowersActive&(1 << FP_SPEED))
			&& !(NPC->client->ps.saberEventFlags&0x80) )
		{
			ucmd.buttons |= 128;
			
		}
	}
	else if ( !TIMER_Done( NPC, "taunting" ) )
	{
		if ( enemy_dist <= 64 )
		{
			ucmd.buttons |= 1;
			if ( !NPC->client->ps.saberInFlight )
			{
				WP_ActivateSaber(NPC);
			}
			TIMER_Set( NPC, "taunting", -level.time );
		}
		
		else if (NPC->client->ps.forceHandExtend == HANDEXTEND_JEDITAUNT && (NPC->client->ps.forceHandExtendTime - level.time) < 200)
		{
			
			if ( !NPC->client->ps.saberInFlight )
			{
				WP_ActivateSaber(NPC);
			}
		}
	}
	else if ( NPC->client->ps.saberEventFlags&0x100 )
	{
		if ( enemy_dist > 0 )
		{
			Jedi_Advance();
		}
		if ( enemy_dist > 128 )
		{
			NPC->client->ps.saberEventFlags &= ~0x100;
		}
		if ( NPC->enemy->painDebounceTime + 2000 < level.time )
		{
			NPC->client->ps.saberEventFlags &= ~0x100;
		}
		
		TIMER_Set( NPC, "strafeLeft", -1 );
		TIMER_Set( NPC, "strafeRight", -1 );
	}
	else if ( NPC->enemy->client 
		&& NPC->enemy->s.weapon == WP_SABER 
		&& NPC->enemy->client->ps.saberLockTime > level.time 
		&& NPC->client->ps.saberLockTime < level.time )
	{
		if ( enemy_dist < 64 )
		{
			Jedi_Retreat();
		}
	}
	




























	
	else if ( enemy_dist <= 64 
		&& ((NPCInfo->scriptFlags&0x00004000)||(!Q_stricmp("Yoda",NPC->NPC_type)&&!Q_irand(0,10))) )
	{
		if ( !Q_irand( 0, 5 ) && InFront( NPC->enemy->r.currentOrigin, NPC->r.currentOrigin, NPC->client->ps.viewangles, 0.2f ) )
		{
			if ( ((NPCInfo->scriptFlags&0x00004000)||NPC->client->pers.maxHealth - NPC->health > NPC->client->pers.maxHealth*0.25f)
				&& NPC->client->ps.fd.forcePowersKnown&(1<<FP_DRAIN) 
				&& WP_ForcePowerAvailable( NPC, FP_DRAIN, 20 )
				&& !Q_irand( 0, 2 ) )
			{
				TIMER_Set( NPC, "draining", 3000 );
				TIMER_Set( NPC, "attackDelay", 3000 );
				Jedi_Advance();
				return;
			}
			else
			{
				ForceThrow( NPC, qfalse );
			}
		}
		Jedi_Retreat();
	}
	else if ( enemy_dist <= 64 
		&& NPC->client->pers.maxHealth - NPC->health > NPC->client->pers.maxHealth*0.25f
		&& NPC->client->ps.fd.forcePowersKnown&(1<<FP_DRAIN) 
		&& WP_ForcePowerAvailable( NPC, FP_DRAIN, 20 )
		&& !Q_irand( 0, 10 ) 
		&& InFront( NPC->enemy->r.currentOrigin, NPC->r.currentOrigin, NPC->client->ps.viewangles, 0.2f ) )
	{
		TIMER_Set( NPC, "draining", 3000 );
		TIMER_Set( NPC, "attackDelay", 3000 );
		Jedi_Advance();
		return;
	}
	else if ( enemy_dist <= -16 )
	{
		Jedi_Retreat();
	}
	else if ( enemy_dist <= 0 )
	{
		
		if ( NPCInfo->stats.aggression < 4 )
		{
			Jedi_Retreat();
		}
	}
	else if ( enemy_dist > 256 )
	{
		qboolean usedForce = qfalse;
		if ( NPCInfo->stats.aggression < Q_irand( 0, 20 ) 
			&& NPC->health < NPC->client->pers.maxHealth*0.75f 
			&& !Q_irand( 0, 2 ) )
		{
			if ( (NPC->client->ps.fd.forcePowersKnown&(1<<FP_HEAL)) != 0 
				&& (NPC->client->ps.fd.forcePowersActive&(1<<FP_HEAL)) == 0 
				&& Q_irand( 0, 1 ) )
			{
				ForceHeal( NPC );
				usedForce = qtrue;
				
			}
			else if ( (NPC->client->ps.fd.forcePowersKnown&(1<<FP_PROTECT)) != 0 
				&& (NPC->client->ps.fd.forcePowersActive&(1<<FP_PROTECT)) == 0
				&& Q_irand( 0, 1 ) )
			{
				ForceProtect( NPC );
				usedForce = qtrue;
			}
			else if ( (NPC->client->ps.fd.forcePowersKnown&(1<<FP_ABSORB)) != 0 
				&& (NPC->client->ps.fd.forcePowersActive&(1<<FP_ABSORB)) == 0
				&& Q_irand( 0, 1 ) )
			{
				ForceAbsorb( NPC );
				usedForce = qtrue;
			}
			else if ( (NPC->client->ps.fd.forcePowersKnown&(1<<FP_RAGE)) != 0 
				&& (NPC->client->ps.fd.forcePowersActive&(1<<FP_RAGE)) == 0
				&& Q_irand( 0, 1 ) )
			{
				Jedi_Rage();
				usedForce = qtrue;
			}
			
		}
		if ( enemy_dist > 384 )
		{
			if ( !Q_irand( 0, 10 ) && NPCInfo->blockedSpeechDebounceTime < level.time && jediSpeechDebounceTime[NPC->client->playerTeam] < level.time )
			{
				if ( NPC_ClearLOS4( NPC->enemy ) )
				{
					G_AddVoiceEvent( NPC, Q_irand( EV_JCHASE1, EV_JCHASE3 ), 3000 );
				}
				jediSpeechDebounceTime[NPC->client->playerTeam] = NPCInfo->blockedSpeechDebounceTime = level.time + 3000;
			}
		}
		
		if ( NPCInfo->stats.aggression > 0 )
		{
			if ( !usedForce )
			{
				Jedi_Advance();
			}
		}
	}
	





	
	else if ( enemy_dist > 50 )
	{
		
		if ( NPC->enemy && NPC->enemy->client && (NPC->enemy->client->ps.fd.forceGripBeingGripped > level.time) )
		{
			if ( NPC->enemy->client->ps.groundEntityNum != ((1<<10)-1) )
			{
				if ( TIMER_Done( NPC, "parryTime" ) || NPCInfo->rank > RANK_LT )
				{
					if ( enemy_dist > 200 || !(NPCInfo->scriptFlags&0x00004000) )
					{
						Jedi_Advance();
					}
				}
			}
			if ( NPCInfo->rank >= RANK_LT_JG 
				&& !Q_irand( 0, 5 ) 
				&& !(NPC->client->ps.fd.forcePowersActive&(1 << FP_SPEED))
				&& !(NPC->client->ps.saberEventFlags&0x80) )
			{
				ucmd.buttons |= 128;
			}
		}
		else if ( NPC->enemy && NPC->enemy->client && 
			NPC->enemy->client->ps.saberInFlight &&  NPC->enemy->client->ps.saberEntityNum && 
			NPC->client->ps.weaponTime <= 0 && 
			WP_ForcePowerAvailable( NPC, FP_GRIP, 0 ) && 
			!Q_irand( 0, 10 ) && 
			Q_irand( 0, 6 ) < g_spskill.integer && 
			Q_irand( RANK_CIVILIAN, RANK_CAPTAIN ) < NPCInfo->rank )
		{
			
			if ( TIMER_Done( NPC, "chatter" ) && jediSpeechDebounceTime[NPC->client->playerTeam] < level.time && NPCInfo->blockedSpeechDebounceTime < level.time )
			{
				G_AddVoiceEvent( NPC, Q_irand( EV_TAUNT1, EV_TAUNT3 ), 3000 );
				jediSpeechDebounceTime[NPC->client->playerTeam] = NPCInfo->blockedSpeechDebounceTime = level.time + 3000;
				TIMER_Set( NPC, "chatter", 3000 );
			}

			
			TIMER_Set( NPC, "gripping", 3000 );
			TIMER_Set( NPC, "attackDelay", 3000 );
		}
		else
		{
			int chanceScale;

			if ( NPC->enemy && NPC->enemy->client && (NPC->enemy->client->ps.fd.forcePowersActive&(1<<FP_GRIP)) )
			{
				if ( NPC->enemy->client->ps.groundEntityNum != ((1<<10)-1) )
				{
					if ( TIMER_Done( NPC, "parryTime" ) || NPCInfo->rank > RANK_LT )
					{
						if ( enemy_dist > 200 || !(NPCInfo->scriptFlags&0x00004000) )
						{
							Jedi_Advance();
						}
					}
				}
			}
			chanceScale = 0;
			if ( NPC->client->NPC_class == CLASS_DESANN || !Q_stricmp("Yoda",NPC->NPC_type) )
			{
				chanceScale = 1;
			}
			else if ( NPCInfo->rank == RANK_ENSIGN )
			{
				chanceScale = 2;
			}
			else if ( NPCInfo->rank >= RANK_LT_JG )
			{
				chanceScale = 5;
			}
			if ( chanceScale 
				&& (enemy_dist > Q_irand( 100, 200 ) || (NPCInfo->scriptFlags&0x00004000) || (!Q_stricmp("Yoda",NPC->NPC_type)&&!Q_irand(0,3)) )
				&& enemy_dist < 500 
				&& (Q_irand( 0, chanceScale*10 )<5 || (NPC->enemy->client && NPC->enemy->client->ps.weapon != WP_SABER && !Q_irand( 0, chanceScale ) ) ) )
			{
				if ( (NPCInfo->rank == RANK_ENSIGN || NPCInfo->rank > RANK_LT_JG) && !Q_irand( 0, 1 ) )
				{
					if ( WP_ForcePowerAvailable( NPC, FP_PULL, 0 ) && !Q_irand( 0, 2 ) )
					{
						
						
						ForceThrow( NPC, qtrue );
						
						TIMER_Set( NPC, "duck", enemy_dist*3 );
						if ( Q_irand( 0, 1 ) )
						{
							ucmd.buttons |= 1;
						}
					}
					else if ( WP_ForcePowerAvailable( NPC, FP_LIGHTNING, 0 ) && Q_irand( 0, 1 ) )
					{
						ForceLightning( NPC );
						if ( NPC->client->ps.fd.forcePowerLevel[FP_LIGHTNING] > FORCE_LEVEL_1 )
						{
							NPC->client->ps.weaponTime = Q_irand( 1000, 3000+(g_spskill.integer*500) );
							TIMER_Set( NPC, "holdLightning", NPC->client->ps.weaponTime );
						}
						TIMER_Set( NPC, "attackDelay", NPC->client->ps.weaponTime );
					}
					









					
					else if ( WP_ForcePowerAvailable( NPC, FP_GRIP, 0 ) )
					{
						
						if ( TIMER_Done( NPC, "chatter" ) && jediSpeechDebounceTime[NPC->client->playerTeam] < level.time && NPCInfo->blockedSpeechDebounceTime < level.time )
						{
							G_AddVoiceEvent( NPC, Q_irand( EV_TAUNT1, EV_TAUNT3 ), 3000 );
							jediSpeechDebounceTime[NPC->client->playerTeam] = NPCInfo->blockedSpeechDebounceTime = level.time + 3000;
							TIMER_Set( NPC, "chatter", 3000 );
						}

						
						TIMER_Set( NPC, "gripping", 3000 );
						TIMER_Set( NPC, "attackDelay", 3000 );
					}
					else
					{
						if ( WP_ForcePowerAvailable( NPC, FP_SABERTHROW, 0 ) 
							&& !(NPC->client->ps.fd.forcePowersActive&(1 << FP_SPEED))
							&& !(NPC->client->ps.saberEventFlags&0x80) )
						{
							ucmd.buttons |= 128;
						}
					}
				}
				else
				{
					if ( NPCInfo->rank >= RANK_LT_JG 
						&& !(NPC->client->ps.fd.forcePowersActive&(1 << FP_SPEED))
						&& !(NPC->client->ps.saberEventFlags&0x80) )
					{
						ucmd.buttons |= 128;
					}
				}
			}
			
			else if ( NPCInfo->stats.aggression > 5 )
			{
				if ( TIMER_Done( NPC, "parryTime" ) || NPCInfo->rank > RANK_LT )
				{
					if ( !NPC->enemy->client || NPC->enemy->client->ps.groundEntityNum != ((1<<10)-1) )
					{
						if ( enemy_dist > 200 || !(NPCInfo->scriptFlags&0x00004000) )
						{
							Jedi_Advance();
						}
					}
				}
			}
			else
			{
				
			}
		}
	}
	else
	{
		if ( NPCInfo->stats.aggression < 4 )
		{
			Jedi_Retreat();
		}
		else if ( NPCInfo->stats.aggression > 5 )
		{
			if ( enemy_dist > 0 && !(NPCInfo->scriptFlags&0x00004000))
			{
				if ( TIMER_Done( NPC, "parryTime" ) || NPCInfo->rank > RANK_LT )
				{
					if ( !NPC->enemy->client || NPC->enemy->client->ps.groundEntityNum != ((1<<10)-1) )
					{
						Jedi_Advance();
					}
				}
			}
		}
		else
		{
			
			
		}
	}
	
	if ( NPCInfo->stats.aggression > Q_irand( 5, 15 )
		&& NPC->health < NPC->client->pers.maxHealth*0.75f 
		&& !Q_irand( 0, 2 ) )
	{
		if ( (NPC->client->ps.fd.forcePowersKnown&(1<<FP_RAGE)) != 0 
			&& (NPC->client->ps.fd.forcePowersActive&(1<<FP_RAGE)) == 0 )
		{
			Jedi_Rage();
		}
	}
}

static qboolean Jedi_Strafe( int strafeTimeMin, int strafeTimeMax, int nextStrafeTimeMin, int nextStrafeTimeMax, qboolean walking )
{
	if ( NPC->client->ps.saberEventFlags&0x100 && NPC->enemy && NPC->enemy->painDebounceTime > level.time )
	{
		return qfalse;
	}
	if ( TIMER_Done( NPC, "strafeLeft" ) && TIMER_Done( NPC, "strafeRight" ) )
	{
		qboolean strafed = qfalse;
		
		
		
		
		int	strafeTime = Q_irand( strafeTimeMin, strafeTimeMax );

		if ( Q_irand( 0, 1 ) )
		{
			if ( NPC_MoveDirClear( ucmd.forwardmove, -127, qfalse ) )
			{
				TIMER_Set( NPC, "strafeLeft", strafeTime );
				strafed = qtrue;
			}
			else if ( NPC_MoveDirClear( ucmd.forwardmove, 127, qfalse ) )
			{
				TIMER_Set( NPC, "strafeRight", strafeTime );
				strafed = qtrue;
			}
		}
		else
		{
			if ( NPC_MoveDirClear( ucmd.forwardmove, 127, qfalse  ) )
			{
				TIMER_Set( NPC, "strafeRight", strafeTime );
				strafed = qtrue;
			}
			else if ( NPC_MoveDirClear( ucmd.forwardmove, -127, qfalse  ) )
			{
				TIMER_Set( NPC, "strafeLeft", strafeTime );
				strafed = qtrue;
			}
		}

		if ( strafed )
		{
			TIMER_Set( NPC, "noStrafe", strafeTime + Q_irand( nextStrafeTimeMin, nextStrafeTimeMax ) );
			if ( walking )
			{
				TIMER_Set( NPC, "walking", strafeTime );
			}
			return qtrue;
		}
	}
	return qfalse;
}







































evasionType_t Jedi_CheckFlipEvasions( gentity_t *self, float rightdot, float zdiff )
{
	if ( self->NPC && (self->NPC->scriptFlags&0x00800000) )
	{
		return EVASION_NONE;
	}
	if ( self->client 
		&& (self->client->ps.fd.forceRageRecoveryTime > level.time	|| (self->client->ps.fd.forcePowersActive&(1<<FP_RAGE))) )
	{
		return EVASION_NONE;
	}
	
	
	
	
	
	if ( self->client->ps.legsAnim == BOTH_WALL_RUN_LEFT || self->client->ps.legsAnim == BOTH_WALL_RUN_RIGHT )
	{
		vec3_t right, fwdAngles;
		int		anim = -1;
		float animLength;

		((fwdAngles)[0]=(0), (fwdAngles)[1]=(self->client->ps.viewangles[1]), (fwdAngles)[2]=(0));

		AngleVectors( fwdAngles, ((void *)0), right, ((void *)0) );

		animLength = BG_AnimLength( self->localAnimIndex, (animNumber_t)self->client->ps.legsAnim );
		if ( self->client->ps.legsAnim == BOTH_WALL_RUN_LEFT && rightdot < 0 )
		{
			if ( animLength - self->client->ps.legsTimer > 400
				&& self->client->ps.legsTimer > 400 )
			{
				anim = BOTH_WALL_RUN_LEFT_FLIP;
			}
		}
		else if ( self->client->ps.legsAnim == BOTH_WALL_RUN_RIGHT && rightdot > 0 )
		{
			if ( animLength - self->client->ps.legsTimer > 400
				&& self->client->ps.legsTimer > 400 )
			{
				anim = BOTH_WALL_RUN_RIGHT_FLIP;
			}
		}
		if ( anim != -1 )
		{
			int parts;
			
			
			if ( anim == BOTH_WALL_RUN_LEFT_FLIP )
			{
				self->client->ps.velocity[0] *= 0.6f;
				self->client->ps.velocity[1] *= 0.6f;
				((self->client->ps.velocity)[0]=(self->client->ps.velocity)[0]+(right)[0]*(150),(self->client->ps.velocity)[1]=(self->client->ps.velocity)[1]+(right)[1]*(150),(self->client->ps.velocity)[2]=(self->client->ps.velocity)[2]+(right)[2]*(150));
			}
			else if ( anim == BOTH_WALL_RUN_RIGHT_FLIP )
			{
				self->client->ps.velocity[0] *= 0.6f;
				self->client->ps.velocity[1] *= 0.6f;
				((self->client->ps.velocity)[0]=(self->client->ps.velocity)[0]+(right)[0]*(-150),(self->client->ps.velocity)[1]=(self->client->ps.velocity)[1]+(right)[1]*(-150),(self->client->ps.velocity)[2]=(self->client->ps.velocity)[2]+(right)[2]*(-150));
			}
			parts = 2;
			if ( !self->client->ps.weaponTime )
			{
				parts = 1|2;
			}
			NPC_SetAnim( self, parts, anim, 1|2 );
			
			
			G_AddEvent( self, EV_JUMP, 0 );
			return EVASION_OTHER;
		}
	}
	else if ( self->client->NPC_class != CLASS_DESANN 
		&& (self->NPC->rank == RANK_CREWMAN || self->NPC->rank >= RANK_LT) 
		&& Q_irand( 0, 1 ) 
		&& !BG_InRoll( &self->client->ps, self->client->ps.legsAnim )
		&& !PM_InKnockDown( &self->client->ps )
		&& !BG_SaberInSpecialAttack( self->client->ps.torsoAnim ) )
	{
		vec3_t fwd, right, traceto, mins, maxs, fwdAngles;
		trace_t	trace;
		int parts, anim;
		float	speed, checkDist;
		qboolean allowCartWheels = qtrue;
		qboolean allowWallFlips = qtrue;

		if ( self->client->ps.weapon == WP_SABER )
		{
			if ( self->client->saber[0].model
				&& self->client->saber[0].model[0]
				&& (self->client->saber[0].saberFlags&(1<<18)) )
			{
				allowCartWheels = qfalse;
			}
			else if ( self->client->saber[1].model
				&& self->client->saber[1].model[0]
				&& (self->client->saber[1].saberFlags&(1<<18)) )
			{
				allowCartWheels = qfalse;
			}
			if ( self->client->saber[0].model
				&& self->client->saber[0].model[0]
				&& (self->client->saber[0].saberFlags&(1<<14)) )
			{
				allowWallFlips = qfalse;
			}
			else if ( self->client->saber[1].model
				&& self->client->saber[1].model[0]
				&& (self->client->saber[1].saberFlags&(1<<14)) )
			{
				allowWallFlips = qfalse;
			}
		}

		((mins)[0]=(self->r.mins[0]), (mins)[1]=(self->r.mins[1]), (mins)[2]=(0));
		((maxs)[0]=(self->r.maxs[0]), (maxs)[1]=(self->r.maxs[1]), (maxs)[2]=(24));
		((fwdAngles)[0]=(0), (fwdAngles)[1]=(self->client->ps.viewangles[1]), (fwdAngles)[2]=(0));

		AngleVectors( fwdAngles, fwd, right, ((void *)0) );

		parts = 1|2;

		if ( BG_SaberInAttack( self->client->ps.saberMove )
			|| PM_SaberInStart( self->client->ps.saberMove ) )
		{
			parts = 2;
		}
		if ( rightdot >= 0 )
		{
			if ( Q_irand( 0, 1 ) )
			{
				anim = BOTH_ARIAL_LEFT;
			}
			else
			{
				anim = BOTH_CARTWHEEL_LEFT;
			}
			checkDist = -128;
			speed = -200;
		}
		else
		{
			if ( Q_irand( 0, 1 ) )
			{
				anim = BOTH_ARIAL_RIGHT;
			}
			else
			{
				anim = BOTH_CARTWHEEL_RIGHT;
			}
			checkDist = 128;
			speed = 200;
		}
		
		((traceto)[0]=(self->r.currentOrigin)[0]+(right)[0]*(checkDist),(traceto)[1]=(self->r.currentOrigin)[1]+(right)[1]*(checkDist),(traceto)[2]=(self->r.currentOrigin)[2]+(right)[2]*(checkDist));
		trap_Trace( &trace, self->r.currentOrigin, mins, maxs, traceto, self->s.number, 0x00000001|0x00000020|0x00000040 );
		if ( trace.fraction >= 1.0f && allowCartWheels )
		{
			
			vec3_t fwdAngles, jumpRt;

			NPC_SetAnim( self, parts, anim, 1|2 );
			self->client->ps.weaponTime = self->client->ps.legsTimer;
			((fwdAngles)[0]=(self->client->ps.viewangles)[0],(fwdAngles)[1]=(self->client->ps.viewangles)[1],(fwdAngles)[2]=(self->client->ps.viewangles)[2]);
			fwdAngles[0] = fwdAngles[2] = 0;
			
			AngleVectors( fwdAngles, ((void *)0), jumpRt, ((void *)0) );
			((self->client->ps.velocity)[0]=(jumpRt)[0]*(speed),(self->client->ps.velocity)[1]=(jumpRt)[1]*(speed),(self->client->ps.velocity)[2]=(jumpRt)[2]*(speed));
			self->client->ps.fd.forceJumpCharge = 0;
			self->client->ps.velocity[2] = 200;
			self->client->ps.fd.forceJumpZStart = self->r.currentOrigin[2];
			
			if ( self->client->NPC_class == CLASS_BOBAFETT )
			{
				G_AddEvent( self, EV_JUMP, 0 );
			}
			else
			{
				G_SoundOnEnt( self, CHAN_BODY, "sound/weapons/force/jump.wav" );
			}
			
			return EVASION_CARTWHEEL;
		}
		else if ( !(trace.contents&0x00000040) )
		{
			
			
			vec3_t	idealNormal;
			gentity_t *traceEnt;

			((idealNormal)[0]=(self->r.currentOrigin)[0]-(traceto)[0],(idealNormal)[1]=(self->r.currentOrigin)[1]-(traceto)[1],(idealNormal)[2]=(self->r.currentOrigin)[2]-(traceto)[2]);
			VectorNormalize( idealNormal );
			traceEnt = &g_entities[trace.entityNum];



			if ( (trace.entityNum<((1<<10)-2)&&traceEnt&&traceEnt->s.solid!=0xffffff) || ((trace.plane.normal)[0]*(idealNormal)[0]+(trace.plane.normal)[1]*(idealNormal)[1]+(trace.plane.normal)[2]*(idealNormal)[2]) > 0.7f )
			{
				float bestCheckDist = 0;
				
				if ( ((self->client->ps.velocity)[0]*(fwd)[0]+(self->client->ps.velocity)[1]*(fwd)[1]+(self->client->ps.velocity)[2]*(fwd)[2]) < 200 )
				{
					
					if ( (trace.fraction*checkDist) <= 32 )

					

					{
						bestCheckDist = checkDist;
						checkDist *= -1.0f;
						((traceto)[0]=(self->r.currentOrigin)[0]+(right)[0]*(checkDist),(traceto)[1]=(self->r.currentOrigin)[1]+(right)[1]*(checkDist),(traceto)[2]=(self->r.currentOrigin)[2]+(right)[2]*(checkDist));
						
						trap_Trace( &trace, self->r.currentOrigin, mins, maxs, traceto, self->s.number, 0x00000001|0x00000020|0x00000040 );
						if ( trace.fraction >= 1.0f )
						{
							
							if (1)
							{
								int parts;

								
								
								if ( rightdot > 0 )
								{
									anim = BOTH_WALL_FLIP_LEFT;
									self->client->ps.velocity[0] = self->client->ps.velocity[1] = 0;
									((self->client->ps.velocity)[0]=(self->client->ps.velocity)[0]+(right)[0]*(150),(self->client->ps.velocity)[1]=(self->client->ps.velocity)[1]+(right)[1]*(150),(self->client->ps.velocity)[2]=(self->client->ps.velocity)[2]+(right)[2]*(150));
								}
								else
								{
									anim = BOTH_WALL_FLIP_RIGHT;
									self->client->ps.velocity[0] = self->client->ps.velocity[1] = 0;
									((self->client->ps.velocity)[0]=(self->client->ps.velocity)[0]+(right)[0]*(-150),(self->client->ps.velocity)[1]=(self->client->ps.velocity)[1]+(right)[1]*(-150),(self->client->ps.velocity)[2]=(self->client->ps.velocity)[2]+(right)[2]*(-150));
								}
								self->client->ps.velocity[2] = forceJumpStrength[FORCE_LEVEL_2]/2.25f;
								
								parts = 2;
								if ( !self->client->ps.weaponTime )
								{
									parts = 1|2;
								}
								NPC_SetAnim( self, parts, anim, 1|2 );
								self->client->ps.fd.forceJumpZStart = self->r.currentOrigin[2];
								
								if ( self->client->NPC_class == CLASS_BOBAFETT )
								{
									G_AddEvent( self, EV_JUMP, 0 );
								}
								else
								{
									G_SoundOnEnt( self, CHAN_BODY, "sound/weapons/force/jump.wav" );
								}
								return EVASION_OTHER;
								}
						}
						else 
						{
							if ( ((self->client->ps.velocity)[0]*(fwd)[0]+(self->client->ps.velocity)[1]*(fwd)[1]+(self->client->ps.velocity)[2]*(fwd)[2]) < 0 )
							{
								return EVASION_NONE;
							}
							if ( (trace.fraction*checkDist) <= 32 && (trace.fraction*checkDist) < bestCheckDist )
							{
								bestCheckDist = checkDist;
							}
						}
					}
					else
					{
						checkDist *= -1.0f;
						((traceto)[0]=(self->r.currentOrigin)[0]+(right)[0]*(checkDist),(traceto)[1]=(self->r.currentOrigin)[1]+(right)[1]*(checkDist),(traceto)[2]=(self->r.currentOrigin)[2]+(right)[2]*(checkDist));
						
						trap_Trace( &trace, self->r.currentOrigin, mins, maxs, traceto, self->s.number, 0x00000001|0x00000020|0x00000040 );
						if ( (trace.fraction*checkDist) <= 32 )
						{
							bestCheckDist = checkDist;
						}
						else
						{
							return EVASION_NONE;
						}
					}
				}
				
				if ( bestCheckDist )
				{
					qboolean allowWallRuns = qtrue;
					if ( self->client->ps.weapon == WP_SABER )
					{
						if ( self->client->saber[0].model
							&& self->client->saber[0].model[0] 
							&& (self->client->saber[0].saberFlags&(1<<13)) )
						{
							allowWallRuns = qfalse;
						}
						else if ( self->client->saber[1].model
							&& self->client->saber[1].model[0]
							&& (self->client->saber[1].saberFlags&(1<<13)) )
						{
							allowWallRuns = qfalse;
						}
					}
					if ( allowWallRuns )
					{
						int parts;

						
						if ( bestCheckDist > 0 )
						{
							anim = BOTH_WALL_RUN_RIGHT;
						}
						else
						{
							anim = BOTH_WALL_RUN_LEFT;
						}
						self->client->ps.velocity[2] = forceJumpStrength[FORCE_LEVEL_2]/2.25f;
						
						parts = 2;
						if ( !self->client->ps.weaponTime )
						{
							parts = 1|2;
						}
						NPC_SetAnim( self, parts, anim, 1|2 );
						self->client->ps.fd.forceJumpZStart = self->r.currentOrigin[2];
						
						if ( self->client->NPC_class == CLASS_BOBAFETT )
						{
							G_AddEvent( self, EV_JUMP, 0 );
						}
						else
						{
							G_SoundOnEnt( self, CHAN_BODY, "sound/weapons/force/jump.wav" );
						}
						return EVASION_OTHER;
					}
				}
				
			}
		}
	}
	return EVASION_NONE;
}

int Jedi_ReCalcParryTime( gentity_t *self, evasionType_t evasionType )
{
	if ( !self->client )
	{
		return 0;
	}
	if ( !self->s.number )
	{
		return bg_parryDebounce[self->client->ps.fd.forcePowerLevel[FP_SABER_DEFENSE]];
	}
	else if ( self->NPC )
	{
		if ( !g_saberRealisticCombat.integer 
			&& ( g_spskill.integer == 2 || (g_spskill.integer == 1 && self->client->NPC_class == CLASS_TAVION) ) )
		{
			if ( self->client->NPC_class == CLASS_TAVION )
			{
				return 0;
			}
			else
			{
				return Q_irand( 0, 150 );
			}
		}
		else
		{
			int	baseTime;
			if ( evasionType == EVASION_DODGE )
			{
				baseTime = self->client->ps.torsoTimer;
			}
			else if ( evasionType == EVASION_CARTWHEEL )
			{
				baseTime = self->client->ps.torsoTimer;
			}
			else if ( self->client->ps.saberInFlight )
			{
				baseTime = Q_irand( 1, 3 ) * 50;
			}
			else
			{
				if ( g_saberRealisticCombat.integer )
				{
					baseTime = 500;

					switch ( g_spskill.integer )
					{
					case 0:
						baseTime = 500;
						break;
					case 1:
						baseTime = 300;
						break;
					case 2:
					default:
						baseTime = 100;
						break;
					}
				}
				else
				{
					baseTime = 150;

					switch ( g_spskill.integer )
					{
					case 0:
						baseTime = 200;
						break;
					case 1:
						baseTime = 100;
						break;
					case 2:
					default:
						baseTime = 50;
						break;
					}
				}

				if ( self->client->NPC_class == CLASS_TAVION )
				{
					baseTime = ceil(baseTime/2.0f);
				}
				else if ( self->NPC->rank >= RANK_LT_JG )
				{
					if ( Q_irand( 0, 2 ) )
					{
						baseTime = baseTime;
					}
					else
					{
						baseTime = ceil(baseTime/2.0f);
					}
				}
				else if ( self->NPC->rank == RANK_CIVILIAN )
				{
					baseTime = baseTime*Q_irand(1,3);
				}
				else if ( self->NPC->rank == RANK_CREWMAN )
				{
					if ( evasionType == EVASION_PARRY
						|| evasionType == EVASION_DUCK_PARRY
						|| evasionType == EVASION_JUMP_PARRY )
					{
						baseTime = baseTime*Q_irand(1,2);
					}
					else
					{
						
					}
				}
				else
				{
					baseTime = baseTime*Q_irand(1,2);
				}
				if ( evasionType == EVASION_DUCK || evasionType == EVASION_DUCK_PARRY )
				{
					baseTime += 100;
				}
				else if ( evasionType == EVASION_JUMP || evasionType == EVASION_JUMP_PARRY )
				{
					baseTime += 50;
				}
				else if ( evasionType == EVASION_OTHER )
				{
					baseTime += 100;
				}
				else if ( evasionType == EVASION_FJUMP )
				{
					baseTime += 100;
				}
			}
			
			return baseTime;
		}
	}
	return 0;
}

qboolean Jedi_QuickReactions( gentity_t *self )
{
	if ( ( self->client->NPC_class == CLASS_JEDI && NPCInfo->rank == RANK_COMMANDER ) ||
		self->client->NPC_class == CLASS_TAVION ||
		(self->client->ps.fd.forcePowerLevel[FP_SABER_DEFENSE]>FORCE_LEVEL_1&&g_spskill.integer>1) ||
		(self->client->ps.fd.forcePowerLevel[FP_SABER_DEFENSE]>FORCE_LEVEL_2&&g_spskill.integer>0) )
	{
		return qtrue;
	}
	return qfalse;
}

qboolean Jedi_SaberBusy( gentity_t *self )
{
	if ( self->client->ps.torsoTimer > 300 
	&& ( (BG_SaberInAttack( self->client->ps.saberMove )&&self->client->ps.fd.saberAnimLevel==FORCE_LEVEL_3) 
		|| BG_SpinningSaberAnim( self->client->ps.torsoAnim ) 
		|| BG_SaberInSpecialAttack( self->client->ps.torsoAnim ) 
		
		|| PM_SaberInBrokenParry( self->client->ps.saberMove ) 
		
		|| BG_FlippingAnim( self->client->ps.torsoAnim ) 
		|| PM_RollingAnim( self->client->ps.torsoAnim ) ) )
	{
		return qtrue;
	}
	return qfalse;
}













extern qboolean G_FindClosestPointOnLineSegment( const vec3_t start, const vec3_t end, const vec3_t from, vec3_t result );
evasionType_t Jedi_SaberBlockGo( gentity_t *self, usercmd_t *cmd, vec3_t pHitloc, vec3_t phitDir, gentity_t *incoming, float dist ) 
{
	vec3_t hitloc, hitdir, diff, fwdangles={0,0,0}, right;
	float rightdot;
	float zdiff;
	int	  duckChance = 0;
	int	  dodgeAnim = -1;
	qboolean	saberBusy = qfalse, evaded = qfalse, doDodge = qfalse;
	evasionType_t	evasionType = EVASION_NONE;

	
	
	if ( !incoming )
	{
		((hitloc)[0]=(pHitloc)[0],(hitloc)[1]=(pHitloc)[1],(hitloc)[2]=(pHitloc)[2]);
		((hitdir)[0]=(phitDir)[0],(hitdir)[1]=(phitDir)[1],(hitdir)[2]=(phitDir)[2]);
		
		if ( self->client->ps.saberInFlight )
		{
			saberBusy = qtrue;
		}
		else if ( Jedi_QuickReactions( self ) )
		{
			
		}
		else
		{
			saberBusy = Jedi_SaberBusy( self );
		}
	}
	else
	{	
		if ( incoming->s.weapon == WP_SABER )
		{
			
			
		}
		((hitloc)[0]=(incoming->r.currentOrigin)[0],(hitloc)[1]=(incoming->r.currentOrigin)[1],(hitloc)[2]=(incoming->r.currentOrigin)[2]);
		VectorNormalize2( incoming->s.pos.trDelta, hitdir );
	}
	if ( self->client && self->client->NPC_class == CLASS_BOBAFETT )
	{
		saberBusy = qtrue;
	}

	((diff)[0]=(hitloc)[0]-(self->client->renderInfo.eyePoint)[0],(diff)[1]=(hitloc)[1]-(self->client->renderInfo.eyePoint)[1],(diff)[2]=(hitloc)[2]-(self->client->renderInfo.eyePoint)[2]);
	diff[2] = 0;
	
	fwdangles[1] = self->client->ps.viewangles[1];
	
	AngleVectors( fwdangles, ((void *)0), right, ((void *)0) );

	rightdot = ((right)[0]*(diff)[0]+(right)[1]*(diff)[1]+(right)[2]*(diff)[2]);
	
	zdiff = hitloc[2] - self->client->renderInfo.eyePoint[2];
	
	
	if ( (dist>16&&(Q_irand( 0, 2 )||saberBusy)) 
		|| self->client->ps.saberInFlight 
		|| BG_SabersOff( &self->client->ps )
		|| self->client->NPC_class == CLASS_BOBAFETT )
	{
		if ( self->NPC && (self->NPC->rank == RANK_CREWMAN || self->NPC->rank >= RANK_LT_JG) )
		{
			if ( self->client->ps.groundEntityNum != ((1<<10)-1) &&
				!(self->client->ps.pm_flags&1)&&cmd->upmove>=0&&TIMER_Done( self, "duck" )
				&& !BG_InRoll( &self->client->ps, self->client->ps.legsAnim )
				&& !PM_InKnockDown( &self->client->ps )
				&& ( self->client->ps.saberInFlight ||
					self->client->NPC_class == CLASS_BOBAFETT ||
					(!BG_SaberInAttack( self->client->ps.saberMove )
					&& !PM_SaberInStart( self->client->ps.saberMove )
					&& !BG_SpinningSaberAnim( self->client->ps.torsoAnim )
					&& !BG_SaberInSpecialAttack( self->client->ps.torsoAnim ))
					)
				)
			{
				doDodge = qtrue;
			}
		}
	}
	
	if ( d_JediAI.integer )
	{
		Com_Printf( "(%d) evading attack from height %4.2f, zdiff: %4.2f, rightdot: %4.2f\n", level.time, hitloc[2]-self->r.absmin[2],zdiff,rightdot);
	}

	
	
	
	
	if ( zdiff >= -5 )
	{
		if ( incoming || !saberBusy )
		{
			if ( rightdot > 12 
				|| (rightdot > 3 && zdiff < 5) 
				|| (!incoming&&fabs(hitdir[2])<0.25f) )
			{
				if ( doDodge )
				{
					if ( self->client->NPC_class == CLASS_BOBAFETT && !Q_irand( 0, 2 ) )
					{
						TIMER_Start( self, "duck", Q_irand( 500, 1500 ) );
						TIMER_Start( self, "strafeLeft", Q_irand( 500, 1500 ) );
						TIMER_Set( self, "strafeRight", 0 );
						evasionType = EVASION_DUCK;
						evaded = qtrue;
					}
					else if ( Q_irand( 0, 1 ) )
					{
						dodgeAnim = BOTH_DODGE_FL;
					}
					else
					{
						dodgeAnim = BOTH_DODGE_BL;
					}
				}
				else
				{
					self->client->ps.saberBlocked = BLOCKED_UPPER_RIGHT;
					evasionType = EVASION_PARRY;
					if ( self->client->ps.groundEntityNum != ((1<<10)-1) )
					{
						if ( zdiff > 5 )
						{
							TIMER_Start( self, "duck", Q_irand( 500, 1500 ) );
							evasionType = EVASION_DUCK_PARRY;
							evaded = qtrue;
							if ( d_JediAI.integer )
							{
								Com_Printf( "duck " );
							}
						}
						else
						{
							duckChance = 6;
						}
					}
				}
				if ( d_JediAI.integer )
				{
					Com_Printf( "UR block\n" );
				}
			}
			else if ( rightdot < -12 
				|| (rightdot < -3 && zdiff < 5) 
				|| (!incoming&&fabs(hitdir[2])<0.25f) )
			{
				if ( doDodge )
				{
					if ( self->client->NPC_class == CLASS_BOBAFETT && !Q_irand( 0, 2 ) )
					{
						TIMER_Start( self, "duck", Q_irand( 500, 1500 ) );
						TIMER_Start( self, "strafeRight", Q_irand( 500, 1500 ) );
						TIMER_Set( self, "strafeLeft", 0 );
						evasionType = EVASION_DUCK;
						evaded = qtrue;
					}
					else if ( Q_irand( 0, 1 ) )
					{
						dodgeAnim = BOTH_DODGE_FR;
					}
					else
					{
						dodgeAnim = BOTH_DODGE_BR;
					}
				}
				else
				{
					self->client->ps.saberBlocked = BLOCKED_UPPER_LEFT;
					evasionType = EVASION_PARRY;
					if ( self->client->ps.groundEntityNum != ((1<<10)-1) )
					{
						if ( zdiff > 5 )
						{
							TIMER_Start( self, "duck", Q_irand( 500, 1500 ) );
							evasionType = EVASION_DUCK_PARRY;
							evaded = qtrue;
							if ( d_JediAI.integer )
							{
								Com_Printf( "duck " );
							}
						}
						else
						{
							duckChance = 6;
						}
					}
				}
				if ( d_JediAI.integer )
				{
					Com_Printf( "UL block\n" );
				}
			}
			else
			{
				self->client->ps.saberBlocked = BLOCKED_TOP;
				evasionType = EVASION_PARRY;
				if ( self->client->ps.groundEntityNum != ((1<<10)-1) )
				{
					duckChance = 4;
				}
				if ( d_JediAI.integer )
				{
					Com_Printf( "TOP block\n" );
				}
			}
			evaded = qtrue;
		}
		else
		{
			if ( self->client->ps.groundEntityNum != ((1<<10)-1) )
			{
				
				TIMER_Start( self, "duck", Q_irand( 500, 1500 ) );
				evasionType = EVASION_DUCK;
				evaded = qtrue;
				if ( d_JediAI.integer )
				{
					Com_Printf( "duck " );
				}
			}
		}
	}
	
	
	else if ( zdiff > -22 )
	{
		if ( 1 )
		{
			if ( self->client->ps.groundEntityNum != ((1<<10)-1) )
			{
				
				TIMER_Start( self, "duck", Q_irand( 500, 1500 ) );
				evasionType = EVASION_DUCK;
				evaded = qtrue;
				if ( d_JediAI.integer )
				{
					Com_Printf( "duck " );
				}
			}
			else
			{
			}
		}
		if ( incoming || !saberBusy )
		{
			if ( rightdot > 8 || (rightdot > 3 && zdiff < -11) )
			{
				if ( doDodge )
				{
					if ( self->client->NPC_class == CLASS_BOBAFETT && !Q_irand( 0, 2 ) )
					{
						TIMER_Start( self, "strafeLeft", Q_irand( 500, 1500 ) );
						TIMER_Set( self, "strafeRight", 0 );
					}
					else 
					{
						dodgeAnim = BOTH_DODGE_L;
					}
				}
				else
				{
					self->client->ps.saberBlocked = BLOCKED_UPPER_RIGHT;
					if ( evasionType == EVASION_DUCK )
					{
						evasionType = EVASION_DUCK_PARRY;
					}
					else
					{
						evasionType = EVASION_PARRY;
					}
				}
				if ( d_JediAI.integer )
				{
					Com_Printf( "mid-UR block\n" );
				}
			}
			else if ( rightdot < -8 || (rightdot < -3 && zdiff < -11) )
			{
				if ( doDodge )
				{
					if ( self->client->NPC_class == CLASS_BOBAFETT && !Q_irand( 0, 2 ) )
					{
						TIMER_Start( self, "strafeLeft", Q_irand( 500, 1500 ) );
						TIMER_Set( self, "strafeRight", 0 );
					}
					else 
					{
						dodgeAnim = BOTH_DODGE_R;
					}
				}
				else
				{
					self->client->ps.saberBlocked = BLOCKED_UPPER_LEFT;
					if ( evasionType == EVASION_DUCK )
					{
						evasionType = EVASION_DUCK_PARRY;
					}
					else
					{
						evasionType = EVASION_PARRY;
					}
				}
				if ( d_JediAI.integer )
				{
					Com_Printf( "mid-UL block\n" );
				}
			}
			else
			{
				self->client->ps.saberBlocked = BLOCKED_TOP;
				if ( evasionType == EVASION_DUCK )
				{
					evasionType = EVASION_DUCK_PARRY;
				}
				else
				{
					evasionType = EVASION_PARRY;
				}
				if ( d_JediAI.integer )
				{
					Com_Printf( "mid-TOP block\n" );
				}
			}
			evaded = qtrue;
		}
	}
	else if ( saberBusy || (zdiff < -36 && ( zdiff < -44 || !Q_irand( 0, 2 ) ) ) )
	{
		if ( self->client->ps.groundEntityNum == ((1<<10)-1) )
		{
			TIMER_Start( self, "duck", Q_irand( 500, 1500 ) );
			evasionType = EVASION_DUCK;
			evaded = qtrue;
			if ( d_JediAI.integer )
			{
				Com_Printf( "legs up\n" );
			}
			if ( incoming || !saberBusy )
			{
				
				if ( rightdot >= 0 )
				{
					self->client->ps.saberBlocked = BLOCKED_LOWER_RIGHT;
					evasionType = EVASION_DUCK_PARRY;
					if ( d_JediAI.integer )
					{
						Com_Printf( "LR block\n" );
					}
				}
				else
				{
					self->client->ps.saberBlocked = BLOCKED_LOWER_LEFT;
					evasionType = EVASION_DUCK_PARRY;
					if ( d_JediAI.integer )
					{
						Com_Printf( "LL block\n" );
					}
				}
				evaded = qtrue;
			}
		}
		else 
		{
			if ( self->NPC && (self->NPC->rank == RANK_CREWMAN || self->NPC->rank > RANK_LT_JG ) &&
				(!Q_irand( 0, 10 ) || (!Q_irand( 0, 2 ) && (cmd->forwardmove || cmd->rightmove))) )
			{
				
				if ( self->NPC 
					&& !(self->NPC->scriptFlags&0x00800000) 
					&& self->client->ps.fd.forceRageRecoveryTime < level.time
					&& !(self->client->ps.fd.forcePowersActive&(1<<FP_RAGE)) 
					&& !PM_InKnockDown( &self->client->ps ) )
				{
					self->client->ps.fd.forceJumpCharge = 320;
					evasionType = EVASION_FJUMP;
					evaded = qtrue;
					if ( d_JediAI.integer )
					{
						Com_Printf( "force jump + " );
					}
				}
			}
			else
			{
				
				if ( self->NPC 
					&& !(self->NPC->scriptFlags&0x00800000) 
					&& self->client->ps.fd.forceRageRecoveryTime < level.time
					&& !(self->client->ps.fd.forcePowersActive&(1<<FP_RAGE)) )
				{
					if ( self->client->NPC_class == CLASS_BOBAFETT && !Q_irand( 0, 1 ) )
					{
						if ( rightdot > 0 )
						{
							TIMER_Start( self, "strafeLeft", Q_irand( 500, 1500 ) );
							TIMER_Set( self, "strafeRight", 0 );
							TIMER_Set( self, "walking", 0 );
						}
						else
						{
							TIMER_Start( self, "strafeRight", Q_irand( 500, 1500 ) );
							TIMER_Set( self, "strafeLeft", 0 );
							TIMER_Set( self, "walking", 0 );
						}
					}
					else
					{
						if ( self == NPC )
						{
							cmd->upmove = 127;
						}
						else
						{
							self->client->ps.velocity[2] = 225;
						}
					}
					evasionType = EVASION_JUMP;
					evaded = qtrue;
					if ( d_JediAI.integer )
					{
						Com_Printf( "jump + " );
					}
				}
				if ( self->client->NPC_class == CLASS_TAVION )
				{
					if ( !incoming 
						&& self->client->ps.groundEntityNum < ((1<<10)-1) 
						&& !Q_irand( 0, 2 ) )
					{
						if ( !BG_SaberInAttack( self->client->ps.saberMove )
							&& !PM_SaberInStart( self->client->ps.saberMove ) 
							&& !BG_InRoll( &self->client->ps, self->client->ps.legsAnim )
							&& !PM_InKnockDown( &self->client->ps )
							&& !BG_SaberInSpecialAttack( self->client->ps.torsoAnim ) )
						{
							int butterflyAnim;
							if ( Q_irand( 0, 1 ) )
							{
								butterflyAnim = BOTH_BUTTERFLY_LEFT;
							}
							else
							{
								butterflyAnim = BOTH_BUTTERFLY_RIGHT;
							}
							evasionType = EVASION_CARTWHEEL;
							NPC_SetAnim( self, 1|2, butterflyAnim, 1|2 );
							
							self->client->ps.velocity[2] = 175;
							self->client->ps.fd.forceJumpZStart = self->r.currentOrigin[2];
						
						
							
							if ( self->client->NPC_class == CLASS_BOBAFETT )
							{
								G_AddEvent( self, EV_JUMP, 0 );
							}
							else
							{
								G_Sound( self, CHAN_BODY, G_SoundIndex("sound/weapons/force/jump.wav") );
							}
							cmd->upmove = 0;
							saberBusy = qtrue;
							evaded = qtrue;
						}
					}
				}
			}
			if ( ((evasionType = Jedi_CheckFlipEvasions( self, rightdot, zdiff ))!=EVASION_NONE) )
			{
				if ( d_slowmodeath.integer > 5 && self->enemy && !self->enemy->s.number )
				{
					G_StartMatrixEffect( self );
				}
				saberBusy = qtrue;
				evaded = qtrue;
			}
			else if ( incoming || !saberBusy )
			{
				
				if ( rightdot >= 0 )
				{
					self->client->ps.saberBlocked = BLOCKED_LOWER_RIGHT;
					if ( evasionType == EVASION_JUMP )
					{
						evasionType = EVASION_JUMP_PARRY;
					}
					else if ( evasionType == EVASION_NONE )
					{
						evasionType = EVASION_PARRY;
					}
					if ( d_JediAI.integer )
					{
						Com_Printf( "LR block\n" );
					}
				}
				else
				{
					self->client->ps.saberBlocked = BLOCKED_LOWER_LEFT;
					if ( evasionType == EVASION_JUMP )
					{
						evasionType = EVASION_JUMP_PARRY;
					}
					else if ( evasionType == EVASION_NONE )
					{
						evasionType = EVASION_PARRY;
					}
					if ( d_JediAI.integer )
					{
						Com_Printf( "LL block\n" );
					}
				}
				evaded = qtrue;
			}
		}
	}
	else
	{
		if ( incoming || !saberBusy )
		{
			if ( rightdot >= 0 )
			{
				self->client->ps.saberBlocked = BLOCKED_LOWER_RIGHT;
				evasionType = EVASION_PARRY;
				if ( d_JediAI.integer )
				{
					Com_Printf( "LR block\n" );
				}
			}
			else
			{
				self->client->ps.saberBlocked = BLOCKED_LOWER_LEFT;
				evasionType = EVASION_PARRY;
				if ( d_JediAI.integer )
				{
					Com_Printf( "LL block\n" );
				}
			}
			if ( incoming && incoming->s.weapon == WP_SABER )
			{
				if ( self->NPC && (self->NPC->rank == RANK_CREWMAN || self->NPC->rank > RANK_LT_JG ) &&
					(!Q_irand( 0, 10 ) || (!Q_irand( 0, 2 ) && (cmd->forwardmove || cmd->rightmove))) )
				{
					
					if ( self->NPC 
						&& !(self->NPC->scriptFlags&0x00800000) 
						&& self->client->ps.fd.forceRageRecoveryTime < level.time
						&& !(self->client->ps.fd.forcePowersActive&(1<<FP_RAGE)) 
						&& !PM_InKnockDown( &self->client->ps ) )
					{
						self->client->ps.fd.forceJumpCharge = 320;
						evasionType = EVASION_FJUMP;
						if ( d_JediAI.integer )
						{
							Com_Printf( "force jump + " );
						}
					}
				}
				else
				{
					
					if ( self->NPC 
						&& !(self->NPC->scriptFlags&0x00800000) 
						&& self->client->ps.fd.forceRageRecoveryTime < level.time
						&& !(self->client->ps.fd.forcePowersActive&(1<<FP_RAGE)))
					{
						if ( self == NPC )
						{
							cmd->upmove = 127;
						}
						else
						{
							self->client->ps.velocity[2] = 225;
						}
						evasionType = EVASION_JUMP_PARRY;
						if ( d_JediAI.integer )
						{
							Com_Printf( "jump + " );
						}
					}
				}
			}
			evaded = qtrue;
		}
	}

	if ( evasionType == EVASION_NONE )
	{
		return EVASION_NONE;
	}
	
	TIMER_Set( self, "taunting", 0 );
	
	TIMER_Set( self, "gripping", -level.time );
	WP_ForcePowerStop( self, FP_GRIP );
	
	TIMER_Set( self, "draining", -level.time );
	WP_ForcePowerStop( self, FP_DRAIN );

	if ( dodgeAnim != -1 )
	{
		evasionType = EVASION_DODGE;
		NPC_SetAnim( self, 1|2, dodgeAnim, 1|2 );
		self->client->ps.weaponTime = self->client->ps.torsoTimer;
		
		self->client->ps.pm_time = self->client->ps.torsoTimer;
		
		self->client->ps.pm_flags |= 64;
		
		if ( d_slowmodeath.integer > 5 && self->enemy && !self->enemy->s.number )
		{
			G_StartMatrixEffect( self );
		}
	}
	else
	{
		if ( duckChance )
		{
			if ( !Q_irand( 0, duckChance ) )
			{
				TIMER_Start( self, "duck", Q_irand( 500, 1500 ) );
				if ( evasionType == EVASION_PARRY )
				{
					evasionType = EVASION_DUCK_PARRY;
				}
				else
				{
					evasionType = EVASION_DUCK;
				}
				





			}
		}

		if ( incoming )
		{
			self->client->ps.saberBlocked = WP_MissileBlockForBlock( self->client->ps.saberBlocked );
		}

	}
	
	{
		int parryReCalcTime = Jedi_ReCalcParryTime( self, evasionType );
		if ( self->client->ps.fd.forcePowerDebounce[FP_SABER_DEFENSE] < level.time + parryReCalcTime )
		{
			self->client->ps.fd.forcePowerDebounce[FP_SABER_DEFENSE] = level.time + parryReCalcTime;
		}
	}
	return evasionType;
}

extern float ShortestLineSegBewteen2LineSegs( vec3_t start1, vec3_t end1, vec3_t start2, vec3_t end2, vec3_t close_pnt1, vec3_t close_pnt2 );
extern int WPDEBUG_SaberColor( saber_colors_t saberColor );
static qboolean Jedi_SaberBlock( int saberNum, int bladeNum ) 
{
	vec3_t hitloc, saberTipOld, saberTip, top, bottom, axisPoint, saberPoint, dir;
	vec3_t pointDir, baseDir, tipDir, saberHitPoint, saberMins, saberMaxs;
	float	pointDist, baseDirPerc, dist;
	float	bladeLen = 0;
	trace_t	tr;
	evasionType_t	evasionType;

	
	







	if ( !TIMER_Done( NPC, "parryReCalcTime" ) )
	{
		return qfalse;
	}

	if ( NPC->client->ps.fd.forcePowerDebounce[FP_SABER_DEFENSE] > level.time )
	{
		return qfalse;
	}
	
	







	if ( NPC->enemy->health <= 0 || !NPC->enemy->client )
	{
		return qfalse;
	}
	









































	((saberMins)[0]=(-4), (saberMins)[1]=(-4), (saberMins)[2]=(-4));
	((saberMaxs)[0]=(4), (saberMaxs)[1]=(4), (saberMaxs)[2]=(4));

	((saberTipOld)[0]=(NPC->enemy->client->saber[saberNum].blade[bladeNum].muzzlePointOld)[0]+(NPC->enemy->client->saber[saberNum].blade[bladeNum].muzzleDirOld)[0]*(NPC->enemy->client->saber[saberNum].blade[bladeNum].length),(saberTipOld)[1]=(NPC->enemy->client->saber[saberNum].blade[bladeNum].muzzlePointOld)[1]+(NPC->enemy->client->saber[saberNum].blade[bladeNum].muzzleDirOld)[1]*(NPC->enemy->client->saber[saberNum].blade[bladeNum].length),(saberTipOld)[2]=(NPC->enemy->client->saber[saberNum].blade[bladeNum].muzzlePointOld)[2]+(NPC->enemy->client->saber[saberNum].blade[bladeNum].muzzleDirOld)[2]*(NPC->enemy->client->saber[saberNum].blade[bladeNum].length));
	((saberTip)[0]=(NPC->enemy->client->saber[saberNum].blade[bladeNum].muzzlePoint)[0]+(NPC->enemy->client->saber[saberNum].blade[bladeNum].muzzleDir)[0]*(NPC->enemy->client->saber[saberNum].blade[bladeNum].length),(saberTip)[1]=(NPC->enemy->client->saber[saberNum].blade[bladeNum].muzzlePoint)[1]+(NPC->enemy->client->saber[saberNum].blade[bladeNum].muzzleDir)[1]*(NPC->enemy->client->saber[saberNum].blade[bladeNum].length),(saberTip)[2]=(NPC->enemy->client->saber[saberNum].blade[bladeNum].muzzlePoint)[2]+(NPC->enemy->client->saber[saberNum].blade[bladeNum].muzzleDir)[2]*(NPC->enemy->client->saber[saberNum].blade[bladeNum].length));




	((top)[0]=(NPC->r.currentOrigin)[0],(top)[1]=(NPC->r.currentOrigin)[1],(top)[2]=(NPC->r.currentOrigin)[2]);
	top[2] = NPC->r.absmax[2];
	((bottom)[0]=(NPC->r.currentOrigin)[0],(bottom)[1]=(NPC->r.currentOrigin)[1],(bottom)[2]=(NPC->r.currentOrigin)[2]);
	bottom[2] = NPC->r.absmin[2];

	dist = ShortestLineSegBewteen2LineSegs( NPC->enemy->client->renderInfo.muzzlePoint, saberTip, bottom, top, saberPoint, axisPoint );
	if ( dist > NPC->r.maxs[0]*5 )
	{
		if ( d_JediAI.integer )
		{
			Com_Printf( "^1""enemy saber dist: %4.2f\n", dist );
		}
		








		{
			TIMER_Set( NPC, "parryTime", -1 );
		}
		return qfalse;
	}
	if ( d_JediAI.integer )
	{
		Com_Printf( "^2""enemy saber dist: %4.2f\n", dist );
	}
	
	((pointDir)[0]=(saberPoint)[0]-(NPC->enemy->client->renderInfo.muzzlePoint)[0],(pointDir)[1]=(saberPoint)[1]-(NPC->enemy->client->renderInfo.muzzlePoint)[1],(pointDir)[2]=(saberPoint)[2]-(NPC->enemy->client->renderInfo.muzzlePoint)[2]);
	pointDist = VectorLength( pointDir );
	
	bladeLen = NPC->enemy->client->saber[saberNum].blade[bladeNum].length;

	if ( bladeLen <= 0 )
	{
		baseDirPerc = 0.5f;
	}
	else
	{
		baseDirPerc = pointDist/bladeLen;
	}
	((baseDir)[0]=(NPC->enemy->client->renderInfo.muzzlePoint)[0]-(NPC->enemy->client->renderInfo.muzzlePointOld)[0],(baseDir)[1]=(NPC->enemy->client->renderInfo.muzzlePoint)[1]-(NPC->enemy->client->renderInfo.muzzlePointOld)[1],(baseDir)[2]=(NPC->enemy->client->renderInfo.muzzlePoint)[2]-(NPC->enemy->client->renderInfo.muzzlePointOld)[2]);
	((tipDir)[0]=(saberTip)[0]-(saberTipOld)[0],(tipDir)[1]=(saberTip)[1]-(saberTipOld)[1],(tipDir)[2]=(saberTip)[2]-(saberTipOld)[2]);
	((baseDir)[0]=(baseDir)[0]*(baseDirPerc),(baseDir)[1]=(baseDir)[1]*(baseDirPerc),(baseDir)[2]=(baseDir)[2]*(baseDirPerc));
	((dir)[0]=(baseDir)[0]+(tipDir)[0]*(1.0f-baseDirPerc),(dir)[1]=(baseDir)[1]+(tipDir)[1]*(1.0f-baseDirPerc),(dir)[2]=(baseDir)[2]+(tipDir)[2]*(1.0f-baseDirPerc));
	((hitloc)[0]=(saberPoint)[0]+(dir)[0]*(200),(hitloc)[1]=(saberPoint)[1]+(dir)[1]*(200),(hitloc)[2]=(saberPoint)[2]+(dir)[2]*(200));

	
	trap_Trace( &tr, saberPoint, saberMins, saberMaxs, hitloc, NPC->enemy->s.number, 0x00000100 );
	if ( tr.allsolid || tr.startsolid || tr.fraction >= 1.0f )
	{
		vec3_t	dir2Me;
		((dir2Me)[0]=(axisPoint)[0]-(saberPoint)[0],(dir2Me)[1]=(axisPoint)[1]-(saberPoint)[1],(dir2Me)[2]=(axisPoint)[2]-(saberPoint)[2]);
		dist = VectorNormalize( dir2Me );
		if ( ((dir)[0]*(dir2Me)[0]+(dir)[1]*(dir2Me)[1]+(dir)[2]*(dir2Me)[2]) < 0.2f )
		{
			








			{
				TIMER_Set( NPC, "parryTime", -1 );
			}
			return qfalse;
		}
		ShortestLineSegBewteen2LineSegs( saberPoint, hitloc, bottom, top, saberHitPoint, hitloc );
		




	}
	else
	{
		((hitloc)[0]=(tr.endpos)[0],(hitloc)[1]=(tr.endpos)[1],(hitloc)[2]=(tr.endpos)[2]);
	}
	
	if ( d_JediAI.integer )
	{
		
		G_TestLine(saberPoint, hitloc, 0x0000ff, 50);
	}

	
	
	if ( (evasionType=Jedi_SaberBlockGo( NPC, &ucmd, hitloc, dir, ((void *)0), dist )) != EVASION_DODGE )
	{
		int parryReCalcTime;

		if ( !NPC->client->ps.saberInFlight )
		{
			WP_ActivateSaber(NPC);
		}

		
		parryReCalcTime = Jedi_ReCalcParryTime( NPC, evasionType );
		TIMER_Set( NPC, "parryReCalcTime", Q_irand( 0, parryReCalcTime ) );
		if ( d_JediAI.integer )
		{
			Com_Printf( "Keep parry choice until: %d\n", level.time + parryReCalcTime );
		}

		
		if ( TIMER_Done( NPC, "parryTime" ) )
		{
			if ( NPC->client->NPC_class == CLASS_TAVION )
			{
				TIMER_Set( NPC, "parryTime", Q_irand( parryReCalcTime/2, parryReCalcTime*1.5 ) );
			}
			else if ( NPCInfo->rank >= RANK_LT_JG )
			{
				TIMER_Set( NPC, "parryTime", parryReCalcTime );
			}
			else
			{
				TIMER_Set( NPC, "parryTime", Q_irand( 1, 2 )*parryReCalcTime );
			}
		}
	}
	else
	{
		int dodgeTime = NPC->client->ps.torsoTimer;
		if ( NPCInfo->rank > RANK_LT_COMM && NPC->client->NPC_class != CLASS_DESANN )
		{
			dodgeTime -= 200;
		}
		TIMER_Set( NPC, "parryReCalcTime", dodgeTime );
		TIMER_Set( NPC, "parryTime", dodgeTime );
	}
	return qtrue;
}







static void Jedi_EvasionSaber( vec3_t enemy_movedir, float enemy_dist, vec3_t enemy_dir )
{
	vec3_t	dirEnemy2Me;
	int		evasionChance = 30;
	qboolean	enemy_attacking = qfalse;
	qboolean	throwing_saber = qfalse;
	qboolean	shooting_lightning = qfalse;

	if ( !NPC->enemy->client )
	{
		return;
	}
	else if ( NPC->enemy->client 
		&& NPC->enemy->s.weapon == WP_SABER 
		&& NPC->enemy->client->ps.saberLockTime > level.time )
	{
		return;
	}
	else if ( NPC->client->ps.saberEventFlags&0x100 && NPC->enemy->painDebounceTime > level.time )
	{
		return;
	}

	if ( NPC->enemy->client->ps.saberInFlight && !TIMER_Done( NPC, "taunting" ) )
	{
		TIMER_Set( NPC, "taunting", -level.time );
		if ( !NPC->client->ps.saberInFlight )
		{
			WP_ActivateSaber(NPC);
		}
	}

	if ( TIMER_Done( NPC, "parryTime" ) )
	{
		if ( NPC->client->ps.saberBlocked != BLOCKED_ATK_BOUNCE &&
			NPC->client->ps.saberBlocked != BLOCKED_PARRY_BROKEN )
		{
			NPC->client->ps.saberBlocked = BLOCKED_NONE;
		}
	}

	if ( NPC->enemy->client->ps.weaponTime && NPC->enemy->client->ps.weaponstate == WEAPON_FIRING )
	{
		if ( !NPC->client->ps.saberInFlight && Jedi_SaberBlock(0, 0) )
		{
			return;
		}
	}

	((dirEnemy2Me)[0]=(NPC->r.currentOrigin)[0]-(NPC->enemy->r.currentOrigin)[0],(dirEnemy2Me)[1]=(NPC->r.currentOrigin)[1]-(NPC->enemy->r.currentOrigin)[1],(dirEnemy2Me)[2]=(NPC->r.currentOrigin)[2]-(NPC->enemy->r.currentOrigin)[2]);
	VectorNormalize( dirEnemy2Me );

	if ( NPC->enemy->client->ps.weaponTime && NPC->enemy->client->ps.weaponstate == WEAPON_FIRING )
	{
		enemy_attacking = qtrue;
		evasionChance = 90;
	}

	if ( (NPC->enemy->client->ps.fd.forcePowersActive&(1<<FP_LIGHTNING) ) )
	{
		enemy_attacking = qtrue;
		shooting_lightning = qtrue;
		evasionChance = 50;
	}

	if ( NPC->enemy->client->ps.saberInFlight && NPC->enemy->client->ps.saberEntityNum != ((1<<10)-1) && NPC->enemy->client->ps.saberEntityState != 1 )
	{
		enemy_attacking = qtrue;
		throwing_saber = qtrue;
	}

	
	if ( Q_irand( 0, 100 ) < evasionChance )
	{
		float facingAmt;
		if ( VectorCompare( enemy_movedir, vec3_origin ) || shooting_lightning || throwing_saber )
		{
			vec3_t	enemy_fwd;
			AngleVectors( NPC->enemy->client->ps.viewangles, enemy_fwd, ((void *)0), ((void *)0) );
			facingAmt = ((enemy_fwd)[0]*(dirEnemy2Me)[0]+(enemy_fwd)[1]*(dirEnemy2Me)[1]+(enemy_fwd)[2]*(dirEnemy2Me)[2]);
		}
		else
		{
			facingAmt = ((enemy_movedir)[0]*(dirEnemy2Me)[0]+(enemy_movedir)[1]*(dirEnemy2Me)[1]+(enemy_movedir)[2]*(dirEnemy2Me)[2]);
		}
			
		if ( flrand( 0.25, 1 ) < facingAmt )
		{
			int whichDefense = 0;
			if ( NPC->client->ps.weaponTime || NPC->client->ps.saberInFlight || NPC->client->NPC_class == CLASS_BOBAFETT )
			{
				if ( Q_irand( 0, 10 ) < NPCInfo->stats.aggression )
				{
					return;
				}
				whichDefense = 100;
			}
			else
			{
				if ( shooting_lightning )
				{
					
					whichDefense = 100;
				}
				else if ( throwing_saber )
				{
					float	saberDist;
					vec3_t	saberDir2Me;
					vec3_t	saberMoveDir;
					gentity_t *saber = &g_entities[NPC->enemy->client->ps.saberEntityNum];
					((saberDir2Me)[0]=(NPC->r.currentOrigin)[0]-(saber->r.currentOrigin)[0],(saberDir2Me)[1]=(NPC->r.currentOrigin)[1]-(saber->r.currentOrigin)[1],(saberDir2Me)[2]=(NPC->r.currentOrigin)[2]-(saber->r.currentOrigin)[2]);
					saberDist = VectorNormalize( saberDir2Me );
					((saberMoveDir)[0]=(saber->s.pos.trDelta)[0],(saberMoveDir)[1]=(saber->s.pos.trDelta)[1],(saberMoveDir)[2]=(saber->s.pos.trDelta)[2]);
					VectorNormalize( saberMoveDir );
					if ( !Q_irand( 0, 3 ) )
					{
						
						Jedi_Aggression( NPC, 1 );
					}
					if ( ((saberMoveDir)[0]*(saberDir2Me)[0]+(saberMoveDir)[1]*(saberDir2Me)[1]+(saberMoveDir)[2]*(saberDir2Me)[2]) > 0.5 )
					{
						if ( saberDist < 100 )
						{
							whichDefense = Q_irand( 3, 6 );
						}
						else if ( saberDist < 200 )
						{
							whichDefense = Q_irand( 0, 8 );
						}
					}
				}
				if ( whichDefense )
				{
				}
				else if ( enemy_dist > 80 || !enemy_attacking )
				{
					if ( VectorCompare( enemy_movedir, vec3_origin ) )
					{
						return;
					}
					if ( Q_irand( 0, 10 ) < NPCInfo->stats.aggression )
					{
						return;
					}
					whichDefense = 100;
				}
				else
				{
					vec3_t	fwd;
					
					AngleVectors( NPC->client->ps.viewangles, fwd, ((void *)0), ((void *)0) );
					if ( ((enemy_dir)[0]*(fwd)[0]+(enemy_dir)[1]*(fwd)[1]+(enemy_dir)[2]*(fwd)[2]) < 0.5 )
					{
						whichDefense = Q_irand( 5, 16 );
					}
					else if ( enemy_dist < 56 )
					{
						whichDefense = Q_irand( NPCInfo->stats.aggression, 12 );
					}
					else
					{
						whichDefense = Q_irand( 2, 16 );
					}
				}
			}

			if ( whichDefense >= 4 && whichDefense <= 12 )
			{
				if ( NPC->client->ps.saberInFlight )
				{
					whichDefense = 100;
				}
			}

			switch( whichDefense )
			{
			case 0:
			case 1:
			case 2:
			case 3:
				
				
				if ( (NPCInfo->rank == RANK_ENSIGN || NPCInfo->rank > RANK_LT_JG) && TIMER_Done( NPC, "parryTime" ) )
				{
					ForceThrow( NPC, qfalse );
				}
				break;
			case 4:
			case 5:
			case 6:
			case 7:
			case 8:
			case 9:
			case 10:
			case 11:
			case 12:
				
				
				Jedi_SaberBlock(0, 0);
				break;
			default:
				
				
				if ( !Q_irand( 0, 5 ) || !Jedi_Strafe( 300, 1000, 0, 1000, qfalse ) )
				{
					
					if ( shooting_lightning || throwing_saber || enemy_dist < 80 )
					{
						
						if ( shooting_lightning || (!Q_irand( 0, 2 ) && NPCInfo->stats.aggression < 4 && TIMER_Done( NPC, "parryTime" ) ) )
						{
							if ( (NPCInfo->rank == RANK_ENSIGN || NPCInfo->rank > RANK_LT_JG) && !shooting_lightning && Q_irand( 0, 2 ) )
							{
								ForceThrow( NPC, qfalse );
							}
							else if ( (NPCInfo->rank==RANK_CREWMAN||NPCInfo->rank>RANK_LT_JG) 
								&& !(NPCInfo->scriptFlags&0x00800000) 
								&& NPC->client->ps.fd.forceRageRecoveryTime < level.time
								&& !(NPC->client->ps.fd.forcePowersActive&(1<<FP_RAGE)) 
								&& !PM_InKnockDown( &NPC->client->ps ) )
							{
								
								NPC->client->ps.fd.forceJumpCharge = 480;
								
								TIMER_Set( NPC, "jumpChaseDebounce", Q_irand( 2000, 5000 ) );
								if ( Q_irand( 0, 2 ) )
								{
									ucmd.forwardmove = 127;
									((NPC->client->ps.moveDir)[0]=(NPC->client->ps.moveDir)[1]=(NPC->client->ps.moveDir)[2]=0);
								}
								else
								{
									ucmd.forwardmove = -127;
									((NPC->client->ps.moveDir)[0]=(NPC->client->ps.moveDir)[1]=(NPC->client->ps.moveDir)[2]=0);
								}
								
								if ( Q_irand( 0, 1 ) )
								{
									NPC->client->ps.saberBlocked = BLOCKED_LOWER_RIGHT;
								}
								else
								{
									NPC->client->ps.saberBlocked = BLOCKED_LOWER_LEFT;
								}
							}
						}
						else if ( enemy_attacking )
						{
							Jedi_SaberBlock(0, 0);
						}
					}
				}
				else
				{
					if ( d_JediAI.integer )
					{
						Com_Printf( "def strafe\n" );
					}
					if ( !(NPCInfo->scriptFlags&0x00800000) 
						&& NPC->client->ps.fd.forceRageRecoveryTime < level.time
						&& !(NPC->client->ps.fd.forcePowersActive&(1<<FP_RAGE)) 
						&& (NPCInfo->rank == RANK_CREWMAN || NPCInfo->rank > RANK_LT_JG ) 
						&& !PM_InKnockDown( &NPC->client->ps )
						&& !Q_irand( 0, 5 ) )
					{
						
						if ( NPC->client->NPC_class == CLASS_BOBAFETT )
						{
							NPC->client->ps.fd.forceJumpCharge = 280;
						}
						else
						{
							NPC->client->ps.fd.forceJumpCharge = 320;
						}
						
						TIMER_Set( NPC, "jumpChaseDebounce", Q_irand( 2000, 5000 ) );
					}
				}
				break;
			}
		
			
			TIMER_Set( NPC, "walking", -level.time );
			TIMER_Set( NPC, "taunting", -level.time );
		}
	}
}



















gentity_t *Jedi_FindEnemyInCone( gentity_t *self, gentity_t *fallback, float minDot )
{
	vec3_t forward, mins, maxs, dir;
	float	dist, bestDist = 16777216;
	gentity_t	*enemy = fallback;
	gentity_t	*check = ((void *)0);
	int			entityList[(1<<10)];
	int			e, numListedEntities;
	trace_t		tr;

	if ( !self->client )
	{
		return enemy;
	}

	AngleVectors( self->client->ps.viewangles, forward, ((void *)0), ((void *)0) );

	for ( e = 0 ; e < 3 ; e++ ) 
	{
		mins[e] = self->r.currentOrigin[e] - 1024;
		maxs[e] = self->r.currentOrigin[e] + 1024;
	}
	numListedEntities = trap_EntitiesInBox( mins, maxs, entityList, (1<<10) );

	for ( e = 0 ; e < numListedEntities ; e++ ) 
	{
		check = &g_entities[entityList[e]];
		if ( check == self )
		{
			continue;
		}
		if ( !(check->inuse) )
		{
			continue;
		}
		if ( !check->client )
		{
			continue;
		}
		if ( check->client->playerTeam != self->client->enemyTeam )
		{
			continue;
		}
		if ( check->health <= 0 )
		{
			continue;
		}

		if ( !trap_InPVS( check->r.currentOrigin, self->r.currentOrigin ) )
		{
			continue;
		}

		((dir)[0]=(check->r.currentOrigin)[0]-(self->r.currentOrigin)[0],(dir)[1]=(check->r.currentOrigin)[1]-(self->r.currentOrigin)[1],(dir)[2]=(check->r.currentOrigin)[2]-(self->r.currentOrigin)[2]);
		dist = VectorNormalize( dir );

		if ( ((dir)[0]*(forward)[0]+(dir)[1]*(forward)[1]+(dir)[2]*(forward)[2]) < minDot )
		{
			continue;
		}

		
		trap_Trace( &tr, self->r.currentOrigin, vec3_origin, vec3_origin, check->r.currentOrigin, self->s.number, (0x00000001|0x00000100|0x00000200|0x00001000) );
		if ( tr.fraction < 1.0f && tr.entityNum != check->s.number )
		{
			continue;
		}

		if ( dist < bestDist )
		{
			dist = bestDist;
			enemy = check;
		}
	}
	return enemy;
}

static void Jedi_SetEnemyInfo( vec3_t enemy_dest, vec3_t enemy_dir, float *enemy_dist, vec3_t enemy_movedir, float *enemy_movespeed, int prediction )
{
	if ( !NPC || !NPC->enemy )
	{
		return;
	}
	if ( !NPC->enemy->client )
	{
		((enemy_movedir)[0]=(enemy_movedir)[1]=(enemy_movedir)[2]=0);
		*enemy_movespeed = 0;
		((enemy_dest)[0]=(NPC->enemy->r.currentOrigin)[0],(enemy_dest)[1]=(NPC->enemy->r.currentOrigin)[1],(enemy_dest)[2]=(NPC->enemy->r.currentOrigin)[2]);
		enemy_dest[2] += NPC->enemy->r.mins[2] + 24;
		((enemy_dir)[0]=(enemy_dest)[0]-(NPC->r.currentOrigin)[0],(enemy_dir)[1]=(enemy_dest)[1]-(NPC->r.currentOrigin)[1],(enemy_dir)[2]=(enemy_dest)[2]-(NPC->r.currentOrigin)[2]);
		
		*enemy_dist = VectorNormalize( enemy_dir );
	}
	else
	{
		((enemy_movedir)[0]=(NPC->enemy->client->ps.velocity)[0],(enemy_movedir)[1]=(NPC->enemy->client->ps.velocity)[1],(enemy_movedir)[2]=(NPC->enemy->client->ps.velocity)[2]);
		*enemy_movespeed = VectorNormalize( enemy_movedir );
		
		((enemy_dest)[0]=(NPC->enemy->r.currentOrigin)[0]+(enemy_movedir)[0]*(*enemy_movespeed * 0.001 * prediction),(enemy_dest)[1]=(NPC->enemy->r.currentOrigin)[1]+(enemy_movedir)[1]*(*enemy_movespeed * 0.001 * prediction),(enemy_dest)[2]=(NPC->enemy->r.currentOrigin)[2]+(enemy_movedir)[2]*(*enemy_movespeed * 0.001 * prediction));
		
		((enemy_dir)[0]=(enemy_dest)[0]-(NPC->r.currentOrigin)[0],(enemy_dir)[1]=(enemy_dest)[1]-(NPC->r.currentOrigin)[1],(enemy_dir)[2]=(enemy_dest)[2]-(NPC->r.currentOrigin)[2]);
		
		*enemy_dist = VectorNormalize( enemy_dir ) - (NPC->client->saber[0].blade[0].lengthMax + NPC->r.maxs[0]*1.5 + 16); 
		
		
		
		
		
		
	}
}

extern float WP_SpeedOfMissileForWeapon( int wp, qboolean alt_fire );
static void Jedi_FaceEnemy( qboolean doPitch )
{
	vec3_t	enemy_eyes, eyes, angles;

	if ( NPC == ((void *)0) )
		return;

	if ( NPC->enemy == ((void *)0) )
		return;

	if ( NPC->client->ps.fd.forcePowersActive & (1<<FP_GRIP) &&
		NPC->client->ps.fd.forcePowerLevel[FP_GRIP] > FORCE_LEVEL_1 )
	{
		NPCInfo->desiredPitch = NPC->client->ps.viewangles[0];
		NPCInfo->desiredYaw = NPC->client->ps.viewangles[1];
		return;
	}
	CalcEntitySpot( NPC, SPOT_HEAD, eyes );

	CalcEntitySpot( NPC->enemy, SPOT_HEAD, enemy_eyes );

	if ( NPC->client->NPC_class == CLASS_BOBAFETT 
		&& TIMER_Done( NPC, "flameTime" )
		&& NPC->s.weapon != WP_NONE
		&& NPC->s.weapon != WP_DISRUPTOR
		&& (NPC->s.weapon != WP_ROCKET_LAUNCHER||!(NPCInfo->scriptFlags&0x00000040))
		&& NPC->s.weapon != WP_THERMAL
		&& NPC->s.weapon != WP_TRIP_MINE
		&& NPC->s.weapon != WP_DET_PACK
		&& NPC->s.weapon != WP_STUN_BATON
		 )
	{
		if ( NPC->health < NPC->client->pers.maxHealth*0.5f )
		{
			float missileSpeed = WP_SpeedOfMissileForWeapon( NPC->s.weapon, ((qboolean)(NPCInfo->scriptFlags&0x00000040)) );
			if ( missileSpeed )
			{
				float eDist = Distance( eyes, enemy_eyes );
				eDist /= missileSpeed;
				((enemy_eyes)[0]=(enemy_eyes)[0]+(NPC->enemy->client->ps.velocity)[0]*(eDist*flrand(0.95f,1.25f)),(enemy_eyes)[1]=(enemy_eyes)[1]+(NPC->enemy->client->ps.velocity)[1]*(eDist*flrand(0.95f,1.25f)),(enemy_eyes)[2]=(enemy_eyes)[2]+(NPC->enemy->client->ps.velocity)[2]*(eDist*flrand(0.95f,1.25f)));
			}
		}
	}

	
	if ( !NPC->client->ps.saberInFlight 
		&& (NPC->client->ps.legsAnim == BOTH_A2_STABBACK1 
			|| NPC->client->ps.legsAnim == BOTH_CROUCHATTACKBACK1
			|| NPC->client->ps.legsAnim == BOTH_ATTACK_BACK) 
		)
	{
		GetAnglesForDirection( enemy_eyes, eyes, angles );
	}
	else
	{
		GetAnglesForDirection( eyes, enemy_eyes, angles );
	}

	NPCInfo->desiredYaw	= AngleNormalize360( angles[1] );
	






	if ( doPitch )
	{
		NPCInfo->desiredPitch = AngleNormalize360( angles[0] );
		if ( NPC->client->ps.saberInFlight )
		{
			NPCInfo->desiredPitch += 10;
		}
	}
	
}

static void Jedi_DebounceDirectionChanges( void )
{
	
	
	if ( ucmd.forwardmove > 0 )
	{
		if ( !TIMER_Done( NPC, "moveback" ) || !TIMER_Done( NPC, "movenone" ) )
		{
			ucmd.forwardmove = 0;
			
			if ( ucmd.rightmove > 0 )
			{
				ucmd.rightmove = 127;
			}
			else if ( ucmd.rightmove < 0 )
			{
				ucmd.rightmove = -127;
			}
			((NPC->client->ps.moveDir)[0]=(NPC->client->ps.moveDir)[1]=(NPC->client->ps.moveDir)[2]=0);
			TIMER_Set( NPC, "moveback", -level.time );
			if ( TIMER_Done( NPC, "movenone" ) )
			{
				TIMER_Set( NPC, "movenone", Q_irand( 1000, 2000 ) );
			}
		}
		else if ( TIMER_Done( NPC, "moveforward" ) )
		{
			TIMER_Set( NPC, "moveforward", Q_irand( 500, 2000 ) );
		}
	}
	else if ( ucmd.forwardmove < 0 )
	{
		if ( !TIMER_Done( NPC, "moveforward" ) || !TIMER_Done( NPC, "movenone" ) )
		{
			ucmd.forwardmove = 0;
			
			if ( ucmd.rightmove > 0 )
			{
				ucmd.rightmove = 127;
			}
			else if ( ucmd.rightmove < 0 )
			{
				ucmd.rightmove = -127;
			}
			((NPC->client->ps.moveDir)[0]=(NPC->client->ps.moveDir)[1]=(NPC->client->ps.moveDir)[2]=0);
			TIMER_Set( NPC, "moveforward", -level.time );
			if ( TIMER_Done( NPC, "movenone" ) )
			{
				TIMER_Set( NPC, "movenone", Q_irand( 1000, 2000 ) );
			}
		}
		else if ( TIMER_Done( NPC, "moveback" ) )
		{
			TIMER_Set( NPC, "moveback", Q_irand( 250, 1000 ) );
		}
	}
	else if ( !TIMER_Done( NPC, "moveforward" ) )
	{
		ucmd.forwardmove = 127;
		((NPC->client->ps.moveDir)[0]=(NPC->client->ps.moveDir)[1]=(NPC->client->ps.moveDir)[2]=0);
	}
	else if ( !TIMER_Done( NPC, "moveback" ) )
	{
		ucmd.forwardmove = -127;
		((NPC->client->ps.moveDir)[0]=(NPC->client->ps.moveDir)[1]=(NPC->client->ps.moveDir)[2]=0);
	}
	
	if ( ucmd.rightmove > 0 )
	{
		if ( !TIMER_Done( NPC, "moveleft" ) || !TIMER_Done( NPC, "movecenter" ) )
		{
			ucmd.rightmove = 0;
			
			if ( ucmd.forwardmove > 0 )
			{
				ucmd.forwardmove = 127;
			}
			else if ( ucmd.forwardmove < 0 )
			{
				ucmd.forwardmove = -127;
			}
			((NPC->client->ps.moveDir)[0]=(NPC->client->ps.moveDir)[1]=(NPC->client->ps.moveDir)[2]=0);
			TIMER_Set( NPC, "moveleft", -level.time );
			if ( TIMER_Done( NPC, "movecenter" ) )
			{
				TIMER_Set( NPC, "movecenter", Q_irand( 1000, 2000 ) );
			}
		}
		else if ( TIMER_Done( NPC, "moveright" ) )
		{
			TIMER_Set( NPC, "moveright", Q_irand( 250, 1500 ) );
		}
	}
	else if ( ucmd.rightmove < 0 )
	{
		if ( !TIMER_Done( NPC, "moveright" ) || !TIMER_Done( NPC, "movecenter" ) )
		{
			ucmd.rightmove = 0;
			
			if ( ucmd.forwardmove > 0 )
			{
				ucmd.forwardmove = 127;
			}
			else if ( ucmd.forwardmove < 0 )
			{
				ucmd.forwardmove = -127;
			}
			((NPC->client->ps.moveDir)[0]=(NPC->client->ps.moveDir)[1]=(NPC->client->ps.moveDir)[2]=0);
			TIMER_Set( NPC, "moveright", -level.time );
			if ( TIMER_Done( NPC, "movecenter" ) )
			{
				TIMER_Set( NPC, "movecenter", Q_irand( 1000, 2000 ) );
			}
		}
		else if ( TIMER_Done( NPC, "moveleft" ) )
		{
			TIMER_Set( NPC, "moveleft", Q_irand( 250, 1500 ) );
		}
	}
	else if ( !TIMER_Done( NPC, "moveright" ) )
	{
		ucmd.rightmove = 127;
		((NPC->client->ps.moveDir)[0]=(NPC->client->ps.moveDir)[1]=(NPC->client->ps.moveDir)[2]=0);
	}
	else if ( !TIMER_Done( NPC, "moveleft" ) )
	{
		ucmd.rightmove = -127;
		((NPC->client->ps.moveDir)[0]=(NPC->client->ps.moveDir)[1]=(NPC->client->ps.moveDir)[2]=0);
	}
}

static void Jedi_TimersApply( void )
{
	if ( !ucmd.rightmove )
	{
		
		if ( !TIMER_Done( NPC, "strafeLeft" ) )
		{
			if ( NPCInfo->desiredYaw > NPC->client->ps.viewangles[1] + 60 )
			{
			}
			else
			{
				ucmd.rightmove = -127;
				((NPC->client->ps.moveDir)[0]=(NPC->client->ps.moveDir)[1]=(NPC->client->ps.moveDir)[2]=0);
			}
		}
		else if ( !TIMER_Done( NPC, "strafeRight" ) )
		{
			if ( NPCInfo->desiredYaw < NPC->client->ps.viewangles[1] - 60 )
			{
			}
			else
			{
				ucmd.rightmove = 127;
				((NPC->client->ps.moveDir)[0]=(NPC->client->ps.moveDir)[1]=(NPC->client->ps.moveDir)[2]=0);
			}
		}
	}

	Jedi_DebounceDirectionChanges();

	
	if ( !ucmd.forwardmove && !TIMER_Done( NPC, "walking" ) )
	{
		ucmd.buttons |= (16);
	}

	if ( !TIMER_Done( NPC, "taunting" ) )
	{
		ucmd.buttons |= (16);
	}

	if ( !TIMER_Done( NPC, "gripping" ) )
	{
		
		ucmd.buttons |= 64;
	}

	if ( !TIMER_Done( NPC, "draining" ) )
	{
		
		ucmd.buttons |= 2048;
	}

	if ( !TIMER_Done( NPC, "holdLightning" ) )
	{
		ucmd.buttons |= 1024;
	}
}

static void Jedi_CombatTimersUpdate( int enemy_dist )
{
	if ( TIMER_Done( NPC, "roamTime" ) )
	{
		TIMER_Set( NPC, "roamTime", Q_irand( 2000, 5000 ) );
		
		if ( NPC->client->ps.fd.forcePowersActive&(1<<FP_RAGE) )
		{
			Jedi_Aggression( NPC, Q_irand( 0, 3 ) );
		}
		else if ( NPC->client->ps.fd.forceRageRecoveryTime > level.time )
		{
			Jedi_Aggression( NPC, Q_irand( 0, -2 ) );
		}
		if ( NPC->enemy && NPC->enemy->client )
		{
			switch( NPC->enemy->client->ps.weapon )
			{
			case WP_SABER:
				
				if ( BG_SabersOff( &NPC->enemy->client->ps ) )
				{
					
					Jedi_Aggression( NPC, 2 );
				}
				else
				{
					
					Jedi_Aggression( NPC, 1 );
				}
				break;
			case WP_BLASTER:
			case WP_BRYAR_PISTOL:
			case WP_DISRUPTOR:
			case WP_BOWCASTER:
			case WP_REPEATER:
			case WP_DEMP2:
			case WP_FLECHETTE:
			case WP_ROCKET_LAUNCHER:
				
				
				if ( NPC->enemy->attackDebounceTime < level.time )
				{
					
					Jedi_Aggression( NPC, 1 );
				}
				
				if ( enemy_dist < 256 )
				{
					
					Jedi_Aggression( NPC, 1 );
				}
				break;
			default:
				break;
			}
		}
	}

	if ( TIMER_Done( NPC, "noStrafe" ) && TIMER_Done( NPC, "strafeLeft" ) && TIMER_Done( NPC, "strafeRight" ) )
	{
		
		if ( !Q_irand( 0, 4 ) )
		{
			if ( Jedi_Strafe( 1000, 3000, 0, 4000, qtrue ) )
			{
				if ( d_JediAI.integer )
				{
					Com_Printf( "off strafe\n" );
				}
			}
		}
		else
		{
			TIMER_Set( NPC, "noStrafe", Q_irand( 1000, 3000 ) );
		}
	}

	if ( NPC->client->ps.saberEventFlags )
	{
		int newFlags = NPC->client->ps.saberEventFlags;
		if ( NPC->client->ps.saberEventFlags&0x8 )
		{
			TIMER_Set( NPC, "parryTime", -1 );
			









			if ( NPC->enemy && PM_SaberInKnockaway( NPC->enemy->client->ps.saberMove ) )
			{
				Jedi_Aggression( NPC, 1 );
				Jedi_AdjustSaberAnimLevel( NPC, (NPC->client->ps.fd.saberAnimLevel-1) );
			}
			else
			{
				if ( !Q_irand( 0, 1 ) )
				{
					
					Jedi_Aggression( NPC, -1 );
				}
				if ( !Q_irand( 0, 1 ) )
				{
					Jedi_AdjustSaberAnimLevel( NPC, (NPC->client->ps.fd.saberAnimLevel-1) );
				}
			}
			if ( d_JediAI.integer )
			{
				Com_Printf( "(%d) PARRY: agg %d, no parry until %d\n", level.time, NPCInfo->stats.aggression, level.time + 100 );
			}
			newFlags &= ~0x8;
		}
		if ( !NPC->client->ps.weaponTime && (NPC->client->ps.saberEventFlags&0x1) )
		{
			if ( !Q_irand( 0, 1 ) )
			{
				
				Jedi_Aggression( NPC, -1 );
				if ( d_JediAI.integer )
				{
					Com_Printf( "(%d) HIT: agg %d\n", level.time, NPCInfo->stats.aggression );
				}
				if ( !Q_irand( 0, 3 ) 
					&& NPCInfo->blockedSpeechDebounceTime < level.time 
					&& jediSpeechDebounceTime[NPC->client->playerTeam] < level.time 
					&& NPC->painDebounceTime < level.time - 1000 )
				{
					G_AddVoiceEvent( NPC, Q_irand( EV_GLOAT1, EV_GLOAT3 ), 3000 );
					jediSpeechDebounceTime[NPC->client->playerTeam] = NPCInfo->blockedSpeechDebounceTime = level.time + 3000;
				}
			}
			if ( !Q_irand( 0, 2 ) )
			{
				Jedi_AdjustSaberAnimLevel( NPC, (NPC->client->ps.fd.saberAnimLevel+1) );
			}
			newFlags &= ~0x1;
		}
		if ( (NPC->client->ps.saberEventFlags&0x20) )
		{
			if ( PM_SaberInBrokenParry( NPC->client->ps.saberMove )
				|| NPC->client->ps.saberBlocked == BLOCKED_PARRY_BROKEN )
			{
				
				if ( NPC->client->ps.saberInFlight )
				{
					Jedi_Aggression( NPC, -5 );
				}
				else
				{
					Jedi_Aggression( NPC, -2 );
				}
				Jedi_AdjustSaberAnimLevel( NPC, (NPC->client->ps.fd.saberAnimLevel+1) );
				if ( d_JediAI.integer )
				{
					Com_Printf( "(%d) KNOCK-BLOCKED: agg %d\n", level.time, NPCInfo->stats.aggression );
				}
			}
			else
			{
				if ( !Q_irand( 0, 2 ) )
				{
					
					Jedi_Aggression( NPC, -1 );
					if ( d_JediAI.integer )
					{
						Com_Printf( "(%d) BLOCKED: agg %d\n", level.time, NPCInfo->stats.aggression );
					}
				}
				if ( !Q_irand( 0, 1 ) )
				{
					Jedi_AdjustSaberAnimLevel( NPC, (NPC->client->ps.fd.saberAnimLevel+1) );
				}
			}
			newFlags &= ~0x20;
			
			
			
			
		}
		if ( NPC->client->ps.saberEventFlags&0x10 )
		{
			newFlags &= ~0x10;
			if ( !Q_irand( 0, 3 ) )
			{
				Jedi_AdjustSaberAnimLevel( NPC, (NPC->client->ps.fd.saberAnimLevel-1) );
			}
		}
		if ( NPC->client->ps.saberEventFlags&0x4 )
		{
			newFlags &= ~0x4;
		}
		if ( NPC->client->ps.saberEventFlags&0x2 )
		{
			if ( !Q_irand( 0, 3 ) )
			{
				Jedi_AdjustSaberAnimLevel( NPC, (NPC->client->ps.fd.saberAnimLevel-1) );
			}
			newFlags &= ~0x2;
		}
		NPC->client->ps.saberEventFlags = newFlags;
	}
}

static void Jedi_CombatIdle( int enemy_dist )
{
	if ( !TIMER_Done( NPC, "parryTime" ) )
	{
		return;
	}
	if ( NPC->client->ps.saberInFlight )
	{
		return;
	}
	if ( NPC->client->ps.fd.forcePowersActive&(1<<FP_RAGE) 
		|| NPC->client->ps.fd.forceRageRecoveryTime > level.time )
	{
		return;
	}
	
	if ( enemy_dist >= 64 )
	{
		
		int chance = 20;
		if ( NPC->client->NPC_class == CLASS_SHADOWTROOPER )
		{
			chance = 10;
		}
		
		if ( Q_irand( 2, chance ) < NPCInfo->stats.aggression )
		{
			if ( TIMER_Done( NPC, "chatter" ) && NPC->client->ps.forceHandExtend == HANDEXTEND_NONE )
			{
				
				if ( enemy_dist > 200 
					&& NPC->client->NPC_class != CLASS_BOBAFETT
					&& !NPC->client->ps.saberHolstered
					&& !Q_irand( 0, 5 ) )
				{
					
					WP_DeactivateSaber( NPC, qfalse );
					
					NPCInfo->stats.aggression = 3;
					
					
					if ( NPC->client->playerTeam != NPCTEAM_PLAYER && !Q_irand( 0, 1 ))
					{
						
						NPC->client->ps.forceHandExtend = HANDEXTEND_JEDITAUNT;
						NPC->client->ps.forceHandExtendTime = level.time + 5000;

						TIMER_Set( NPC, "chatter", Q_irand( 5000, 10000 ) );
						TIMER_Set( NPC, "taunting", 5500 );
					}
					else
					{
						Jedi_BattleTaunt();
						TIMER_Set( NPC, "taunting", Q_irand( 5000, 10000 ) );
					}
				}
				else if ( Jedi_BattleTaunt() )
				{
				}
			}
		}
	}
}

static qboolean Jedi_AttackDecide( int enemy_dist )
{
	if ( NPC->enemy->client 
		&& NPC->enemy->s.weapon == WP_SABER 
		&& NPC->enemy->client->ps.saberLockTime > level.time 
		&& NPC->client->ps.saberLockTime < level.time )
	{
		return qfalse;
	}

	if ( NPC->client->ps.saberEventFlags&0x100 )
	{
		int	chance = 0;
		if ( NPC->client->NPC_class == CLASS_DESANN || NPC->client->NPC_class == CLASS_LUKE || !Q_stricmp("Yoda",NPC->NPC_type) )
		{
			chance = 20;
		}
		else if ( NPC->client->NPC_class == CLASS_TAVION )
		{
			chance = 10;
		}
		else if ( NPC->client->NPC_class == CLASS_REBORN && NPCInfo->rank == RANK_LT_JG ) 
		{
			chance = 5;
		}
		else
		{
			chance = NPCInfo->rank;
		}
		if ( Q_irand( 0, 30 ) < chance )
		{
			NPC->client->ps.saberEventFlags &= ~0x100;
			TIMER_Set( NPC, "noRetreat", Q_irand( 500, 2000 ) );
			
			NPC->client->ps.weaponTime = NPCInfo->shotTime = NPC->attackDebounceTime = 0;
			
			NPC->client->ps.saberBlocked = BLOCKED_NONE;
			WeaponThink( qtrue );
			return qtrue;
		}
	}

	if ( NPC->client->NPC_class == CLASS_TAVION ||
		( NPC->client->NPC_class == CLASS_REBORN && NPCInfo->rank == RANK_LT_JG ) ||
		( NPC->client->NPC_class == CLASS_JEDI && NPCInfo->rank == RANK_COMMANDER ) )
	{
		if ( ( PM_SaberInParry( NPC->client->ps.saberMove ) || PM_SaberInKnockaway( NPC->client->ps.saberMove ) )
			&& NPC->client->ps.saberBlocked != BLOCKED_PARRY_BROKEN )
		{
			NPC->client->ps.weaponTime = NPCInfo->shotTime = NPC->attackDebounceTime = 0;
			
			NPC->client->ps.saberBlocked = BLOCKED_NONE;
			Jedi_AdjustSaberAnimLevel( NPC, FORCE_LEVEL_1 );
			WeaponThink( qtrue );
			return qtrue;
		}
	}

	
	if ( enemy_dist >= 64 )
	{
		return qfalse;
	}

	if ( !TIMER_Done( NPC, "parryTime" ) )
	{
		return qfalse;
	}

	if ( (NPCInfo->scriptFlags&0x00004000) )
	{
		return qfalse;
	}

	if ( !(ucmd.buttons&1) && !(ucmd.buttons&128) )
	{
		
		WeaponThink( qtrue );
	}
	
	

	

	
	

	if ( ucmd.buttons&1 )
	{
		









		
		
		
		
		
		if ( !ucmd.rightmove )
		{
			if ( !Q_irand( 0, 3 ) )
			{
				vec3_t  right, dir2enemy;

				AngleVectors( NPC->r.currentAngles, ((void *)0), right, ((void *)0) );
				((dir2enemy)[0]=(NPC->enemy->r.currentOrigin)[0]-(NPC->r.currentAngles)[0],(dir2enemy)[1]=(NPC->enemy->r.currentOrigin)[1]-(NPC->r.currentAngles)[1],(dir2enemy)[2]=(NPC->enemy->r.currentOrigin)[2]-(NPC->r.currentAngles)[2]);
				if ( ((right)[0]*(dir2enemy)[0]+(right)[1]*(dir2enemy)[1]+(right)[2]*(dir2enemy)[2]) > 0 )
				{
					ucmd.rightmove = -127;
					((NPC->client->ps.moveDir)[0]=(NPC->client->ps.moveDir)[1]=(NPC->client->ps.moveDir)[2]=0);
				}
				else
				{
					ucmd.rightmove = 127;
					((NPC->client->ps.moveDir)[0]=(NPC->client->ps.moveDir)[1]=(NPC->client->ps.moveDir)[2]=0);
				}
			}
		}
		return qtrue;
	}

	return qfalse;
}





static qboolean Jedi_Jump( vec3_t dest, int goalEntNum )
{
	





















	if ( 1 )
	{
		float	targetDist, shotSpeed = 300, travelTime, impactDist, bestImpactDist = 16777216;
		vec3_t	targetDir, shotVel, failCase; 
		trace_t	trace;
		trajectory_t	tr;
		qboolean	blocked;
		int		elapsedTime, timeStep = 500, hitCount = 0, maxHits = 7;
		vec3_t	lastPos, testPos, bottom;

		while ( hitCount < maxHits )
		{
			((targetDir)[0]=(dest)[0]-(NPC->r.currentOrigin)[0],(targetDir)[1]=(dest)[1]-(NPC->r.currentOrigin)[1],(targetDir)[2]=(dest)[2]-(NPC->r.currentOrigin)[2]);
			targetDist = VectorNormalize( targetDir );

			((shotVel)[0]=(targetDir)[0]*(shotSpeed),(shotVel)[1]=(targetDir)[1]*(shotSpeed),(shotVel)[2]=(targetDir)[2]*(shotSpeed));
			travelTime = targetDist/shotSpeed;
			shotVel[2] += travelTime * 0.5 * NPC->client->ps.gravity;

			if ( !hitCount )		
			{
				((failCase)[0]=(shotVel)[0],(failCase)[1]=(shotVel)[1],(failCase)[2]=(shotVel)[2]);
			}

			if ( 1 )
			{
				blocked = qfalse;

				((tr.trBase)[0]=(NPC->r.currentOrigin)[0],(tr.trBase)[1]=(NPC->r.currentOrigin)[1],(tr.trBase)[2]=(NPC->r.currentOrigin)[2]);
				((tr.trDelta)[0]=(shotVel)[0],(tr.trDelta)[1]=(shotVel)[1],(tr.trDelta)[2]=(shotVel)[2]);
				tr.trType = TR_GRAVITY;
				tr.trTime = level.time;
				travelTime *= 1000.0f;
				((lastPos)[0]=(NPC->r.currentOrigin)[0],(lastPos)[1]=(NPC->r.currentOrigin)[1],(lastPos)[2]=(NPC->r.currentOrigin)[2]);
				
				
				for ( elapsedTime = timeStep; elapsedTime < floor(travelTime)+timeStep; elapsedTime += timeStep )
				{
					if ( (float)elapsedTime > travelTime )
					{
						elapsedTime = floor( travelTime );
					}
					BG_EvaluateTrajectory( &tr, level.time + elapsedTime, testPos );
					if ( testPos[2] < lastPos[2] )
					{
						trap_Trace( &trace, lastPos, NPC->r.mins, NPC->r.maxs, testPos, NPC->s.number, NPC->clipmask );
					}
					else
					{
						trap_Trace( &trace, lastPos, NPC->r.mins, NPC->r.maxs, testPos, NPC->s.number, NPC->clipmask|0x00000040 );
					}

					if ( trace.allsolid || trace.startsolid )
					{
						blocked = qtrue;
						break;
					}
					if ( trace.fraction < 1.0f )
					{
						if ( trace.entityNum == goalEntNum )
						{
							
							break;
						}
						else 
						{
							if ( trace.contents & 0x00000040 )
							{
								blocked = qtrue;
								break;
							}
							if ( trace.plane.normal[2] > 0.7 && DistanceSquared( trace.endpos, dest ) < 4096 )
							{
								break;
							}
							else
							{
								impactDist = DistanceSquared( trace.endpos, dest );
								if ( impactDist < bestImpactDist )
								{
									bestImpactDist = impactDist;
									((failCase)[0]=(shotVel)[0],(failCase)[1]=(shotVel)[1],(failCase)[2]=(shotVel)[2]);
								}
								blocked = qtrue;
								break;
							}
						}
					}
					if ( elapsedTime == floor( travelTime ) )
					{
						if ( trace.fraction >= 1.0f )
						{
							
							((bottom)[0]=(trace.endpos)[0],(bottom)[1]=(trace.endpos)[1],(bottom)[2]=(trace.endpos)[2]);
							bottom[2] -= 128;
							trap_Trace( &trace, trace.endpos, NPC->r.mins, NPC->r.maxs, bottom, NPC->s.number, NPC->clipmask );
							if ( trace.fraction >= 1.0f )
							{
								blocked = qtrue;
							}
						}
						break;
					}
					else
					{
						
						((lastPos)[0]=(testPos)[0],(lastPos)[1]=(testPos)[1],(lastPos)[2]=(testPos)[2]);
					}
				}
				if ( blocked )
				{
					hitCount++;
					shotSpeed = 300 + ((hitCount-2) * 100);
					if ( hitCount >= 2 )
					{
						shotSpeed += 100;
					}
				}
				else
				{
					break;
				}
			}
			else
			{
				break;
			}
		}

		if ( hitCount >= maxHits )
		{
			
			((NPC->client->ps.velocity)[0]=(failCase)[0],(NPC->client->ps.velocity)[1]=(failCase)[1],(NPC->client->ps.velocity)[2]=(failCase)[2]);
		}
		((NPC->client->ps.velocity)[0]=(shotVel)[0],(NPC->client->ps.velocity)[1]=(shotVel)[1],(NPC->client->ps.velocity)[2]=(shotVel)[2]);
	}
	else
	{
		vec3_t		dir, p1, p2, apex;
		float		time, height, forward, z, xy, dist, apexHeight;

		if ( NPC->r.currentOrigin[2] > dest[2] )
		{
			((p1)[0]=(NPC->r.currentOrigin)[0],(p1)[1]=(NPC->r.currentOrigin)[1],(p1)[2]=(NPC->r.currentOrigin)[2]);
			((p2)[0]=(dest)[0],(p2)[1]=(dest)[1],(p2)[2]=(dest)[2]);
		}
		else if ( NPC->r.currentOrigin[2] < dest[2] )
		{
			((p1)[0]=(dest)[0],(p1)[1]=(dest)[1],(p1)[2]=(dest)[2]);
			((p2)[0]=(NPC->r.currentOrigin)[0],(p2)[1]=(NPC->r.currentOrigin)[1],(p2)[2]=(NPC->r.currentOrigin)[2]);
		}
		else
		{
			((p1)[0]=(NPC->r.currentOrigin)[0],(p1)[1]=(NPC->r.currentOrigin)[1],(p1)[2]=(NPC->r.currentOrigin)[2]);
			((p2)[0]=(dest)[0],(p2)[1]=(dest)[1],(p2)[2]=(dest)[2]);
		}

		
		((dir)[0]=(p2)[0]-(p1)[0],(dir)[1]=(p2)[1]-(p1)[1],(dir)[2]=(p2)[2]-(p1)[2]);
		dir[2] = 0;

		
		xy = VectorNormalize( dir );
		z = p1[2] - p2[2];

		apexHeight = 200.0f/2;

		
		
		
		











		z = (sqrt(apexHeight + z) - sqrt(apexHeight));

		(void)( (!!(z >= 0)) || (_wassert(L"z >= 0", L"c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\npc_ai_jedi.c", 4696), 0) );



		xy -= z;
		xy *= 0.5;
		
		(void)( (!!(xy > 0)) || (_wassert(L"xy > 0", L"c:\\projects\\jedi_academy_sdk(mp)\\codemp\\game\\npc_ai_jedi.c", 4703), 0) );

		((apex)[0]=(p1)[0]+(dir)[0]*(xy),(apex)[1]=(p1)[1]+(dir)[1]*(xy),(apex)[2]=(p1)[2]+(dir)[2]*(xy));
		apex[2] += apexHeight;

		((NPC->pos1)[0]=(apex)[0],(NPC->pos1)[1]=(apex)[1],(NPC->pos1)[2]=(apex)[2]);
		
		
		height = apex[2] - NPC->r.currentOrigin[2];
		time = sqrt( height / ( .5 * NPC->client->ps.gravity ) );
		if ( !time ) 
		{
			
			return qfalse;
		}

		((NPC->client->ps.velocity)[0]=(apex)[0]-(NPC->r.currentOrigin)[0],(NPC->client->ps.velocity)[1]=(apex)[1]-(NPC->r.currentOrigin)[1],(NPC->client->ps.velocity)[2]=(apex)[2]-(NPC->r.currentOrigin)[2]);
		NPC->client->ps.velocity[2] = 0;
		dist = VectorNormalize( NPC->client->ps.velocity );

		forward = dist / time * 1.25;
		((NPC->client->ps.velocity)[0]=(NPC->client->ps.velocity)[0]*(forward),(NPC->client->ps.velocity)[1]=(NPC->client->ps.velocity)[1]*(forward),(NPC->client->ps.velocity)[2]=(NPC->client->ps.velocity)[2]*(forward));

		
		NPC->client->ps.velocity[2] = time * NPC->client->ps.gravity;

		
	}
	return qtrue;
}

static qboolean Jedi_TryJump( gentity_t *goal )
{
	
	if ( (NPCInfo->scriptFlags&0x00800000) )
	{
		return qfalse;
	}
	if ( TIMER_Done( NPC, "jumpChaseDebounce" ) )
	{
		if ( (!goal->client || goal->client->ps.groundEntityNum != ((1<<10)-1)) )
		{
			if ( !PM_InKnockDown( &NPC->client->ps ) && !BG_InRoll( &NPC->client->ps, NPC->client->ps.legsAnim ) )
			{
				vec3_t goal_diff;
				float goal_z_diff;
				float goal_xy_dist;
				((goal_diff)[0]=(goal->r.currentOrigin)[0]-(NPC->r.currentOrigin)[0],(goal_diff)[1]=(goal->r.currentOrigin)[1]-(NPC->r.currentOrigin)[1],(goal_diff)[2]=(goal->r.currentOrigin)[2]-(NPC->r.currentOrigin)[2]);
				goal_z_diff = goal_diff[2];
				goal_diff[2] = 0;
				goal_xy_dist = VectorNormalize( goal_diff );
				if ( goal_xy_dist < 550 && goal_z_diff > -400 )
				{
					qboolean debounce = qfalse;
					if ( NPC->health < 150 && ((NPC->health < 30 && goal_z_diff < 0) || goal_z_diff < -128 ) )
					{
						debounce = qtrue;
					}
					else if ( goal_z_diff < 32 && goal_xy_dist < 200 )
					{
						ucmd.upmove = 127;
						debounce = qtrue;
					}
					else
					{
						






						if ( goal_z_diff > 0 || goal_xy_dist > 128 )
						{
							
							vec3_t dest;
							((dest)[0]=(goal->r.currentOrigin)[0],(dest)[1]=(goal->r.currentOrigin)[1],(dest)[2]=(goal->r.currentOrigin)[2]);
							if ( goal == NPC->enemy )
							{
								int	sideTry = 0;
								while( sideTry < 10 )
								{
									trace_t	trace;
									vec3_t	bottom;

									if ( Q_irand( 0, 1 ) )
									{
										dest[0] += NPC->enemy->r.maxs[0]*1.25;
									}
									else
									{
										dest[0] += NPC->enemy->r.mins[0]*1.25;
									}
									if ( Q_irand( 0, 1 ) )
									{
										dest[1] += NPC->enemy->r.maxs[1]*1.25;
									}
									else
									{
										dest[1] += NPC->enemy->r.mins[1]*1.25;
									}
									((bottom)[0]=(dest)[0],(bottom)[1]=(dest)[1],(bottom)[2]=(dest)[2]);
									bottom[2] -= 128;
									trap_Trace( &trace, dest, NPC->r.mins, NPC->r.maxs, bottom, goal->s.number, NPC->clipmask );
									if ( trace.fraction < 1.0f )
									{
										break;
									}
									sideTry++;
								}
								if ( sideTry >= 10 )
								{
									((dest)[0]=(goal->r.currentOrigin)[0],(dest)[1]=(goal->r.currentOrigin)[1],(dest)[2]=(goal->r.currentOrigin)[2]);
								}
							}
							if ( Jedi_Jump( dest, goal->s.number ) )
							{
								

								
								
								






								{
									int jumpAnim;
									
									if ( NPC->client->NPC_class == CLASS_BOBAFETT 
										||( NPCInfo->rank != RANK_CREWMAN && NPCInfo->rank <= RANK_LT_JG ) )
									{
										jumpAnim = BOTH_FORCEJUMP1;
									}
									else
									{
										jumpAnim = BOTH_FLIP_F;
									}
									NPC_SetAnim( NPC, 1|2, jumpAnim, 1|2 );
								}

								NPC->client->ps.fd.forceJumpZStart = NPC->r.currentOrigin[2];
								

								NPC->client->ps.weaponTime = NPC->client->ps.torsoTimer;
								NPC->client->ps.fd.forcePowersActive |= ( 1 << FP_LEVITATION );
								if ( NPC->client->NPC_class == CLASS_BOBAFETT )
								{
									G_SoundOnEnt( NPC, CHAN_ITEM, "sound/boba/jeton.wav" );
									NPC->client->jetPackTime = level.time + Q_irand( 1000, 3000 );
								}
								else
								{
									G_SoundOnEnt( NPC, CHAN_BODY, "sound/weapons/force/jump.wav" );
								}

								TIMER_Set( NPC, "forceJumpChasing", Q_irand( 2000, 3000 ) );
								debounce = qtrue;
							}
						}
					}
					if ( debounce )
					{
						
						TIMER_Set( NPC, "jumpChaseDebounce", Q_irand( 2000, 5000 ) );
						ucmd.forwardmove = 127;
						((NPC->client->ps.moveDir)[0]=(NPC->client->ps.moveDir)[1]=(NPC->client->ps.moveDir)[2]=0);
						TIMER_Set( NPC, "duck", -level.time );
						return qtrue;
					}
				}
			}
		}
	}
	return qfalse;
}

static qboolean Jedi_Jumping( gentity_t *goal )
{
	if ( !TIMER_Done( NPC, "forceJumpChasing" ) && goal )
	{


		if (NPC->client->ps.groundEntityNum != ((1<<10)-1)) 
		{
			TIMER_Set( NPC, "forceJumpChasing", 0 );
		}
		else
		{
			NPC_FaceEntity( goal, qtrue );
			
			
			



























			return qtrue;
		}
	}
	return qfalse;
}

extern void G_UcmdMoveForDir( gentity_t *self, usercmd_t *cmd, vec3_t dir );
static void Jedi_CheckEnemyMovement( float enemy_dist )
{
	if ( !NPC->enemy || !NPC->enemy->client )
	{
		return;
	}

	if ( NPC->client->NPC_class != CLASS_TAVION 
		&& NPC->client->NPC_class != CLASS_DESANN
		&& NPC->client->NPC_class != CLASS_LUKE 
		&& Q_stricmp("Yoda",NPC->NPC_type) )
	{
		if ( NPC->enemy->enemy && NPC->enemy->enemy == NPC )
		{
			if ( NPC->enemy->client->ps.legsAnim == BOTH_JUMPFLIPSLASHDOWN1 ||
				NPC->enemy->client->ps.legsAnim == BOTH_JUMPFLIPSTABDOWN )
			{
				if ( Q_irand( 0, NPCInfo->rank ) < RANK_LT )
				{
					ucmd.forwardmove = ucmd.rightmove = ucmd.upmove = 0;
					((NPC->client->ps.moveDir)[0]=(NPC->client->ps.moveDir)[1]=(NPC->client->ps.moveDir)[2]=0);
					NPC->client->ps.fd.forceJumpCharge = 0;
					TIMER_Set( NPC, "strafeLeft", -1 );
					TIMER_Set( NPC, "strafeRight", -1 );
					TIMER_Set( NPC, "noStrafe", Q_irand( 500, 1000 ) );
					TIMER_Set( NPC, "movenone", Q_irand( 500, 1000 ) );
					TIMER_Set( NPC, "movecenter", Q_irand( 500, 1000 ) );
				}
			}
			else if ( NPC->enemy->client->ps.legsAnim == BOTH_WALL_FLIP_BACK1 
				|| NPC->enemy->client->ps.legsAnim == BOTH_WALL_FLIP_RIGHT 
				|| NPC->enemy->client->ps.legsAnim == BOTH_WALL_FLIP_LEFT 
				|| NPC->enemy->client->ps.legsAnim == BOTH_WALL_RUN_LEFT_FLIP 
				|| NPC->enemy->client->ps.legsAnim == BOTH_WALL_RUN_RIGHT_FLIP )
			{
				if ( NPC->enemy->client->ps.groundEntityNum == ((1<<10)-1) )
				{
					if ( enemy_dist < 256 )
					{
						if ( Q_irand( 0, NPCInfo->rank ) < RANK_LT )
						{
							vec3_t enemyFwd, dest, dir;

							










							
							ucmd.forwardmove = ucmd.rightmove = ucmd.upmove = 0;
							((NPC->client->ps.moveDir)[0]=(NPC->client->ps.moveDir)[1]=(NPC->client->ps.moveDir)[2]=0);
							NPC->client->ps.fd.forceJumpCharge = 0;
							TIMER_Set( NPC, "strafeLeft", -1 );
							TIMER_Set( NPC, "strafeRight", -1 );
							TIMER_Set( NPC, "noStrafe", Q_irand( 500, 1000 ) );
							TIMER_Set( NPC, "noturn", Q_irand( 250, 500 )*(3-g_spskill.integer) );

							((enemyFwd)[0]=(NPC->enemy->client->ps.velocity)[0],(enemyFwd)[1]=(NPC->enemy->client->ps.velocity)[1],(enemyFwd)[2]=(NPC->enemy->client->ps.velocity)[2]);
							VectorNormalize( enemyFwd );
							((dest)[0]=(NPC->enemy->r.currentOrigin)[0]+(enemyFwd)[0]*(-64),(dest)[1]=(NPC->enemy->r.currentOrigin)[1]+(enemyFwd)[1]*(-64),(dest)[2]=(NPC->enemy->r.currentOrigin)[2]+(enemyFwd)[2]*(-64));
							((dir)[0]=(dest)[0]-(NPC->r.currentOrigin)[0],(dir)[1]=(dest)[1]-(NPC->r.currentOrigin)[1],(dir)[2]=(dest)[2]-(NPC->r.currentOrigin)[2]);
							if ( VectorNormalize( dir ) > 32 )
							{
								G_UcmdMoveForDir( NPC, &ucmd, dir );
							}
							else
							{
								TIMER_Set( NPC, "movenone", Q_irand( 500, 1000 ) );
								TIMER_Set( NPC, "movecenter", Q_irand( 500, 1000 ) );
							}
						}
					}
				}
			}
			else if ( NPC->enemy->client->ps.legsAnim == BOTH_A2_STABBACK1 )
			{
				if ( enemy_dist < 256 && enemy_dist > 64 )
				{
					if ( !InFront( NPC->r.currentOrigin, NPC->enemy->r.currentOrigin, NPC->enemy->r.currentAngles, 0.0f ) )
					{
						if ( !Q_irand( 0, NPCInfo->rank ) )
						{
							vec3_t enemyFwd, dest, dir;

							
							ucmd.forwardmove = ucmd.rightmove = ucmd.upmove = 0;
							((NPC->client->ps.moveDir)[0]=(NPC->client->ps.moveDir)[1]=(NPC->client->ps.moveDir)[2]=0);
							NPC->client->ps.fd.forceJumpCharge = 0;
							TIMER_Set( NPC, "strafeLeft", -1 );
							TIMER_Set( NPC, "strafeRight", -1 );
							TIMER_Set( NPC, "noStrafe", Q_irand( 500, 1000 ) );

							AngleVectors( NPC->enemy->r.currentAngles, enemyFwd, ((void *)0), ((void *)0) );
							((dest)[0]=(NPC->enemy->r.currentOrigin)[0]+(enemyFwd)[0]*(-32),(dest)[1]=(NPC->enemy->r.currentOrigin)[1]+(enemyFwd)[1]*(-32),(dest)[2]=(NPC->enemy->r.currentOrigin)[2]+(enemyFwd)[2]*(-32));
							((dir)[0]=(dest)[0]-(NPC->r.currentOrigin)[0],(dir)[1]=(dest)[1]-(NPC->r.currentOrigin)[1],(dir)[2]=(dest)[2]-(NPC->r.currentOrigin)[2]);
							if ( VectorNormalize( dir ) > 64 )
							{
								G_UcmdMoveForDir( NPC, &ucmd, dir );
							}
							else
							{
								TIMER_Set( NPC, "movenone", Q_irand( 500, 1000 ) );
								TIMER_Set( NPC, "movecenter", Q_irand( 500, 1000 ) );
							}
						}
					}
				}
			}
		}
	}
	
	
	
}

static void Jedi_CheckJumps( void )
{
	vec3_t	jumpVel;
	trace_t	trace;
	trajectory_t	tr;
	vec3_t	lastPos, testPos, bottom;
	int		elapsedTime;

	if ( (NPCInfo->scriptFlags&0x00800000) )
	{
		NPC->client->ps.fd.forceJumpCharge = 0;
		ucmd.upmove = 0;
		return;
	}
	
	
	((jumpVel)[0]=(jumpVel)[1]=(jumpVel)[2]=0);

	if ( NPC->client->ps.fd.forceJumpCharge )
	{
		
		WP_GetVelocityForForceJump( NPC, jumpVel, &ucmd );
	}
	else if ( ucmd.upmove > 0 )
	{
		
		((jumpVel)[0]=(NPC->client->ps.velocity)[0],(jumpVel)[1]=(NPC->client->ps.velocity)[1],(jumpVel)[2]=(NPC->client->ps.velocity)[2]);
		jumpVel[2] = 225;
	}
	else
	{
		return;
	}
	
	
	if ( !jumpVel[0] && !jumpVel[1] )
	{
		
		return;
	}
	
	

	((tr.trBase)[0]=(NPC->r.currentOrigin)[0],(tr.trBase)[1]=(NPC->r.currentOrigin)[1],(tr.trBase)[2]=(NPC->r.currentOrigin)[2]);
	((tr.trDelta)[0]=(jumpVel)[0],(tr.trDelta)[1]=(jumpVel)[1],(tr.trDelta)[2]=(jumpVel)[2]);
	tr.trType = TR_GRAVITY;
	tr.trTime = level.time;
	((lastPos)[0]=(NPC->r.currentOrigin)[0],(lastPos)[1]=(NPC->r.currentOrigin)[1],(lastPos)[2]=(NPC->r.currentOrigin)[2]);
	
	((trace.endpos)[0]=(trace.endpos)[1]=(trace.endpos)[2]=0); 

	
	for ( elapsedTime = 500; elapsedTime <= 4000; elapsedTime += 500 )
	{
		BG_EvaluateTrajectory( &tr, level.time + elapsedTime, testPos );
		
		if ( testPos[2] < lastPos[2] )
		{
			trap_Trace( &trace, lastPos, NPC->r.mins, NPC->r.maxs, testPos, NPC->s.number, NPC->clipmask );
		}
		else
		{
			trap_Trace( &trace, lastPos, NPC->r.mins, NPC->r.maxs, testPos, NPC->s.number, NPC->clipmask|0x00000040 );
		}
		if ( trace.allsolid || trace.startsolid )
		{
			
			goto jump_unsafe;
			return;
		}
		if ( trace.fraction < 1.0f )
		{
			if ( trace.contents & 0x00000040 )
			{
				goto jump_unsafe;
				return;
			}
			
			break;
		}
		((lastPos)[0]=(testPos)[0],(lastPos)[1]=(testPos)[1],(lastPos)[2]=(testPos)[2]);
	}
	
	((bottom)[0]=(trace.endpos)[0],(bottom)[1]=(trace.endpos)[1],(bottom)[2]=(trace.endpos)[2]);
	if ( bottom[2] > NPC->r.currentOrigin[2] )
	{
		bottom[2] = NPC->r.currentOrigin[2];
	}
	else if ( NPC->r.currentOrigin[2] - bottom[2] > 400 )
	{
		
		goto jump_unsafe;
		return;
	}
	bottom[2] -= 128;
	trap_Trace( &trace, trace.endpos, NPC->r.mins, NPC->r.maxs, bottom, NPC->s.number, NPC->clipmask );
	if ( trace.allsolid || trace.startsolid || trace.fraction < 1.0f )
	{
		if ( trace.entityNum < ((1<<10)-2) )
		{
			gentity_t *groundEnt = &g_entities[trace.entityNum];
			if ( groundEnt->r.svFlags&0x08000000 )
			{
				goto jump_unsafe;
				return;
			}
		}
		
		return;
	}
jump_unsafe:
	
	
	NPC->client->ps.fd.forceJumpCharge = 0;
	ucmd.upmove = 0;
}

static void Jedi_Combat( void )
{
	vec3_t	enemy_dir, enemy_movedir, enemy_dest;
	float	enemy_dist, enemy_movespeed;
	qboolean	enemy_lost = qfalse;

	
	Jedi_SetEnemyInfo( enemy_dest, enemy_dir, &enemy_dist, enemy_movedir, &enemy_movespeed, 300 );

	if ( Jedi_Jumping( NPC->enemy ) )
	{
		Jedi_AttackDecide( enemy_dist );
		return;
	}

	if ( !(NPC->client->ps.fd.forcePowersActive&(1<<FP_GRIP)) || NPC->client->ps.fd.forcePowerLevel[FP_GRIP] < FORCE_LEVEL_2 )
	{
		
		if ( !Jedi_ClearPathToSpot( enemy_dest, NPC->enemy->s.number ) )
		{
			
			if ( (NPC_ClearLOS4( NPC->enemy )||NPCInfo->enemyLastSeenTime>level.time-500) && NPC_FaceEnemy( qtrue ) )
			{
				
				























				
				
				
				
				
				if ( Jedi_TryJump( NPC->enemy ) )
				{
					return;
				}
			}

			
			if ( TIMER_Done( NPC, "parryTime" ) )
			{
				if ( NPC->client->ps.saberBlocked != BLOCKED_ATK_BOUNCE &&
					NPC->client->ps.saberBlocked != BLOCKED_PARRY_BROKEN )
				{
					NPC->client->ps.saberBlocked = BLOCKED_NONE;
				}
			}
			if ( Jedi_Hunt() && !(NPCInfo->aiFlags&0x00000040) )
			{
				if ( enemy_dist < 384 && !Q_irand( 0, 10 ) && NPCInfo->blockedSpeechDebounceTime < level.time && jediSpeechDebounceTime[NPC->client->playerTeam] < level.time && !NPC_ClearLOS4( NPC->enemy ) )
				{
					G_AddVoiceEvent( NPC, Q_irand( EV_JLOST1, EV_JLOST3 ), 3000 );
					jediSpeechDebounceTime[NPC->client->playerTeam] = NPCInfo->blockedSpeechDebounceTime = level.time + 3000;
				}

				return;
			}
			
	




		else
			{
				if ( NPCInfo->aiFlags & 0x00000040 )
				{
					gentity_t *tempGoal = G_Spawn();
					G_SetOrigin( tempGoal, NPCInfo->blockedDest );
					trap_LinkEntity( tempGoal );
					if ( Jedi_TryJump( tempGoal ) )
					{
						G_FreeEntity( tempGoal );
						return;
					}
					G_FreeEntity( tempGoal );
				}

				enemy_lost = qtrue;
			}
		}
	}
	

	
	Jedi_CombatTimersUpdate( enemy_dist );

	
	
	Jedi_CombatDistance( enemy_dist );

	
	{
		
		if ( !NPC->enemy->client || ( NPC->enemy->client->ps.groundEntityNum != ((1<<10)-1) && NPC->client->ps.groundEntityNum != ((1<<10)-1) ) )
		{
			((NPCInfo->enemyLastSeenLocation)[0]=(NPC->enemy->r.currentOrigin)[0],(NPCInfo->enemyLastSeenLocation)[1]=(NPC->enemy->r.currentOrigin)[1],(NPCInfo->enemyLastSeenLocation)[2]=(NPC->enemy->r.currentOrigin)[2]);
		}
		NPCInfo->enemyLastSeenTime = level.time;
	}

	
	if ( TIMER_Done( NPC, "noturn" ) )
	{
		Jedi_FaceEnemy( qtrue );
	}
	NPC_UpdateAngles( qtrue, qtrue );
	
	
	if ( TIMER_Done( NPC, "parryTime" ) )
	{
		if ( NPC->client->ps.saberBlocked != BLOCKED_ATK_BOUNCE &&
			NPC->client->ps.saberBlocked != BLOCKED_PARRY_BROKEN )
		{
			NPC->client->ps.saberBlocked = BLOCKED_NONE;
		}
	}
	if ( NPC->enemy->s.weapon == WP_SABER )
	{
		Jedi_EvasionSaber( enemy_movedir, enemy_dist, enemy_dir );
	}
	else
	{
	}

	
	Jedi_TimersApply();

	if ( !NPC->client->ps.saberInFlight && (!(NPC->client->ps.fd.forcePowersActive&(1<<FP_GRIP))||NPC->client->ps.fd.forcePowerLevel[FP_GRIP] < FORCE_LEVEL_2) )
	{
		
		if ( !Jedi_AttackDecide( enemy_dist ) )
		{
			Jedi_CombatIdle( enemy_dist );
			
		}
		else
		{
			
			TIMER_Set( NPC, "taunting", -level.time );
		}
	}
	else
	{
	}
	if ( NPC->client->NPC_class == CLASS_BOBAFETT )
	{
		Boba_FireDecide();
	}

	
	Jedi_CheckEnemyMovement( enemy_dist );
	
	Jedi_CheckJumps();
	
	if ( !NPC_MoveDirClear( ucmd.forwardmove, ucmd.rightmove, qtrue ) )
	{
		navInfo_t	info;
		
		NAV_GetLastMove( &info );
		if ( !(info.flags & 0x00000002) )
		{
			NPC_MoveToGoal( qfalse );
		}
		
		TIMER_Set( NPC, "strafeLeft", 0 );
		TIMER_Set( NPC, "strafeRight", 0 );
	}
}













void NPC_Jedi_Pain(gentity_t *self, gentity_t *attacker, int damage)
{
	gentity_t *other = attacker;
	vec3_t point;

	((point)[0]=(gPainPoint)[0],(point)[1]=(gPainPoint)[1],(point)[2]=(gPainPoint)[2]);

	
	
	
	if ( other->s.weapon == WP_SABER )
	{
		TIMER_Set( self, "parryTime", -1 );
		if ( self->client->NPC_class == CLASS_DESANN || !Q_stricmp("Yoda",self->NPC_type) )
		{
			self->client->ps.fd.forcePowerDebounce[FP_SABER_DEFENSE] = level.time + (3-g_spskill.integer)*50;
		}
		else if ( self->NPC->rank >= RANK_LT_JG )
		{
			self->client->ps.fd.forcePowerDebounce[FP_SABER_DEFENSE] = level.time + (3-g_spskill.integer)*100;
		}
		else
		{
			self->client->ps.fd.forcePowerDebounce[FP_SABER_DEFENSE] = level.time + (3-g_spskill.integer)*200;
		}
		if ( !Q_irand( 0, 3 ) )
		{
			Jedi_AdjustSaberAnimLevel( self, Q_irand( FORCE_LEVEL_1, FORCE_LEVEL_3 ) );
		}
		if ( !Q_irand( 0, 1 ) )
		{
			
			Jedi_Aggression( self, -1 );
		}
		if ( d_JediAI.integer )
		{
			Com_Printf( "(%d) PAIN: agg %d, no parry until %d\n", level.time, self->NPC->stats.aggression, level.time+500 );
		}
		
		
		if ( d_JediAI.integer )
		{
			vec3_t	diff, fwdangles, right;
			float rightdot, zdiff;

			((diff)[0]=(point)[0]-(self->client->renderInfo.eyePoint)[0],(diff)[1]=(point)[1]-(self->client->renderInfo.eyePoint)[1],(diff)[2]=(point)[2]-(self->client->renderInfo.eyePoint)[2]);
			diff[2] = 0;
			fwdangles[1] = self->client->ps.viewangles[1];
			AngleVectors( fwdangles, ((void *)0), right, ((void *)0) );
			rightdot = ((right)[0]*(diff)[0]+(right)[1]*(diff)[1]+(right)[2]*(diff)[2]);
			zdiff = point[2] - self->client->renderInfo.eyePoint[2];
		
			Com_Printf( "(%d) saber hit at height %4.2f, zdiff: %4.2f, rightdot: %4.2f\n", level.time, point[2]-self->r.absmin[2],zdiff,rightdot);
		}
	}
	else
	{
		
		Jedi_Aggression( self, 1 );
	}

	self->NPC->enemyCheckDebounceTime = 0;

	WP_ForcePowerStop( self, FP_GRIP );

	
	NPC_Pain(self, attacker, damage);

	if ( !damage && self->health > 0 )
	{
		G_AddVoiceEvent( self, Q_irand(EV_PUSHED1, EV_PUSHED3), 2000 );
	}

	
	if ( Jedi_WaitingAmbush( self ) )
	{
		self->client->noclip = qfalse;
	}
	if ( self->client->ps.legsAnim == BOTH_CEILING_CLING )
	{
		NPC_SetAnim( self, 2, BOTH_CEILING_DROP, 1|2 );
	}
	if ( self->client->ps.torsoAnim == BOTH_CEILING_CLING )
	{
		NPC_SetAnim( self, 1, BOTH_CEILING_DROP, 1|2 );
	}
}

qboolean Jedi_CheckDanger( void )
{
	int alertEvent = NPC_CheckAlertEvents( qtrue, qtrue, -1, qfalse, AEL_MINOR );
	if ( level.alertEvents[alertEvent].level >= AEL_DANGER )
	{
		if ( !level.alertEvents[alertEvent].owner 
			|| !level.alertEvents[alertEvent].owner->client 
			|| (level.alertEvents[alertEvent].owner!=NPC&&level.alertEvents[alertEvent].owner->client->playerTeam!=NPC->client->playerTeam) )
		{
			return qfalse;
		}
		G_SetEnemy( NPC, level.alertEvents[alertEvent].owner );
		NPCInfo->enemyLastSeenTime = level.time;
		TIMER_Set( NPC, "attackDelay", Q_irand( 500, 2500 ) );
		return qtrue;
	}
	return qfalse;
}

qboolean Jedi_CheckAmbushPlayer( void )
{
	int i = 0;
	gentity_t *player;
	float target_dist;
	float zDiff;

	for ( i = 0; i < 32; i++ )
	{
		player = &g_entities[i];

		if ( !player || !player->client )
		{
			continue;
		}

		if ( !NPC_ValidEnemy( player ) )
		{
			continue;
		}


		if (NPC->client->ps.powerups[PW_CLOAKED] || !NPC_SomeoneLookingAtMe(NPC)) 
		{
			if ( !trap_InPVS( player->r.currentOrigin, NPC->r.currentOrigin ) )
			{
				continue;
			}
			else
			{
				if ( !NPC->client->ps.powerups[PW_CLOAKED] )
				{
					NPC_SetLookTarget( NPC, 0, 0 );
				}
			}
			zDiff = NPC->r.currentOrigin[2]-player->r.currentOrigin[2];
			if ( zDiff <= 0 || zDiff > 512 )
			{
				continue;
			}

			
			if ( (target_dist = DistanceHorizontalSquared( player->r.currentOrigin, NPC->r.currentOrigin )) > 4096 )
			{
				if ( target_dist > 147456 )
				{
					continue;
				}
				
				if ( NPC->client->ps.powerups[PW_CLOAKED] )
				{
					if ( InFOV( player, NPC, 30, 90 ) == qfalse )
					{
						continue;
					}
				}
				else
				{
					if ( InFOV( player, NPC, 45, 90 ) == qfalse )
					{
						continue;
					}
				}
			}

			if ( !NPC_ClearLOS4( player ) )
			{
				continue;
			}
		}

		
		G_SetEnemy( NPC, player );
		NPCInfo->enemyLastSeenTime = level.time;
		TIMER_Set( NPC, "attackDelay", Q_irand( 500, 2500 ) );
		return qtrue;
	}

	
	return qfalse;
}

void Jedi_Ambush( gentity_t *self )
{
	self->client->noclip = qfalse;

	NPC_SetAnim( self, 1|2, BOTH_CEILING_DROP, 1|2 );
	self->client->ps.weaponTime = self->client->ps.torsoTimer; 
	if ( self->client->NPC_class != CLASS_BOBAFETT )
	{
		WP_ActivateSaber(self);
	}
	Jedi_Decloak( self );
	G_AddVoiceEvent( self, Q_irand( EV_ANGER1, EV_ANGER3 ), 1000 );
}

qboolean Jedi_WaitingAmbush( gentity_t *self )
{
	if ( (self->spawnflags&16) && self->client->noclip )
	{
		return qtrue;
	}
	return qfalse;
}






static void Jedi_Patrol( void )
{
	NPC->client->ps.saberBlocked = BLOCKED_NONE;

	if ( Jedi_WaitingAmbush( NPC ) )
	{
		NPC_SetAnim( NPC, 1|2, BOTH_CEILING_CLING, 1|2 );
		if ( NPCInfo->scriptFlags&0x00000800 )
		{
			if ( Jedi_CheckAmbushPlayer() || Jedi_CheckDanger() )
			{
				Jedi_Ambush( NPC );
				NPC_UpdateAngles( qtrue, qtrue );
				return;
			}
		}
	}
	else if ( NPCInfo->scriptFlags&0x00000800 )
	{
		gentity_t *best_enemy = ((void *)0);
		float	best_enemy_dist = 16777216;
		int i;
		for ( i = 0; i < ((1<<10)-2); i++ )
		{
			gentity_t *enemy = &g_entities[i];
			float	enemy_dist;
			if ( enemy && enemy->client && NPC_ValidEnemy( enemy ) && enemy->client->playerTeam == NPC->client->enemyTeam )
			{
				if ( trap_InPVS( NPC->r.currentOrigin, enemy->r.currentOrigin ) )
				{
					enemy_dist = DistanceSquared( NPC->r.currentOrigin, enemy->r.currentOrigin );
					if ( enemy->s.eType == ET_PLAYER || enemy_dist < best_enemy_dist )
					{
						
						
						if ( enemy_dist < (220*220) || ( NPCInfo->investigateCount>= 3 && !NPC->client->ps.saberHolstered ) )
						{
							G_SetEnemy( NPC, enemy );
							
							NPCInfo->stats.aggression = 3;
							break;
						}
						else if ( enemy->client->ps.saberInFlight && !enemy->client->ps.saberHolstered )
						{
							float	saberDist;
							vec3_t	saberDir2Me;
							vec3_t	saberMoveDir;
							gentity_t *saber = &g_entities[enemy->client->ps.saberEntityNum];
							((saberDir2Me)[0]=(NPC->r.currentOrigin)[0]-(saber->r.currentOrigin)[0],(saberDir2Me)[1]=(NPC->r.currentOrigin)[1]-(saber->r.currentOrigin)[1],(saberDir2Me)[2]=(NPC->r.currentOrigin)[2]-(saber->r.currentOrigin)[2]);
							saberDist = VectorNormalize( saberDir2Me );
							((saberMoveDir)[0]=(saber->s.pos.trDelta)[0],(saberMoveDir)[1]=(saber->s.pos.trDelta)[1],(saberMoveDir)[2]=(saber->s.pos.trDelta)[2]);
							VectorNormalize( saberMoveDir );
							if ( ((saberMoveDir)[0]*(saberDir2Me)[0]+(saberMoveDir)[1]*(saberDir2Me)[1]+(saberMoveDir)[2]*(saberDir2Me)[2]) > 0.5 )
							{
								if ( saberDist < 200 )
								{
									G_SetEnemy( NPC, enemy );
									
									NPCInfo->stats.aggression = 3;
									break;
								}
							}
						}
						best_enemy_dist = enemy_dist;
						best_enemy = enemy;
					}
				}
			}
		}
		if ( !NPC->enemy )
		{
			if ( !best_enemy )
			{
				
				Jedi_AggressionErosion(-1);
				
			}
			else
			{
				if ( NPC_ClearLOS4( best_enemy ) )
				{
					if ( best_enemy->s.number )
					{
						G_SetEnemy( NPC, best_enemy );
						NPCInfo->stats.aggression = 3;
					}
					else if ( NPC->client->NPC_class != CLASS_BOBAFETT )
					{
						
						if ( TIMER_Done( NPC, "watchTime" ) )
						{
							if ( TIMER_Get( NPC, "watchTime" ) == -1 )
							{
								TIMER_Set( NPC, "watchTime", Q_irand( 3000, 5000 ) );
								goto finish;
							}
							else
							{
								if ( !NPCInfo->investigateCount )
								{
									G_AddVoiceEvent( NPC, Q_irand( EV_JDETECTED1, EV_JDETECTED3 ), 3000 );
								}
								NPCInfo->investigateCount++;
								TIMER_Set( NPC, "watchTime", Q_irand( 4000, 10000 ) );
							}
						}
						
						if ( best_enemy_dist < (440*440) || NPCInfo->investigateCount >= 2 )
						{
							NPC_FaceEntity( best_enemy, qtrue );
							if ( best_enemy_dist < (330*330) )
							{
								if ( !NPC->client->ps.saberInFlight )
								{
									WP_ActivateSaber(NPC);
								}
							}
						}
						else if ( best_enemy_dist < (550*550) || NPCInfo->investigateCount == 1 )
						{
							if ( TIMER_Done( NPC, "watchTime" ) )
							{
								NPC_FaceEntity( best_enemy, qtrue );
							}
						}
						else
						{
							NPC_SetLookTarget( NPC, best_enemy->s.number, 0 );
						}
					}
				}
				else if ( TIMER_Done( NPC, "watchTime" ) )
				{
					NPC_ClearLookTarget( NPC );
				}
			}
		}
	}
finish:
	
	if ( UpdateGoal() )
	{
		ucmd.buttons |= 16;
		
		NPC_MoveToGoal( qtrue );
	}

	NPC_UpdateAngles( qtrue, qtrue );

	if ( NPC->enemy )
	{
		NPCInfo->enemyCheckDebounceTime = level.time + Q_irand( 3000, 10000 );
	}
}

qboolean Jedi_CanPullBackSaber( gentity_t *self )
{
	if ( self->client->ps.saberBlocked == BLOCKED_PARRY_BROKEN && !TIMER_Done( self, "parryTime" ) )
	{
		return qfalse;
	}

	if ( self->client->NPC_class == CLASS_SHADOWTROOPER
		|| self->client->NPC_class == CLASS_TAVION
		|| self->client->NPC_class == CLASS_LUKE
		|| self->client->NPC_class == CLASS_DESANN 
		|| !Q_stricmp( "Yoda", self->NPC_type ) )
	{
		return qtrue;
	}

	if ( self->painDebounceTime > level.time )
	{
		return qfalse;
	}

	return qtrue;
}





void NPC_BSJedi_FollowLeader( void )
{
	NPC->client->ps.saberBlocked = BLOCKED_NONE;
	if ( !NPC->enemy )
	{
		
		Jedi_AggressionErosion(-1);
	}
	
	
	if ( NPC->client->ps.saberInFlight )
	{
		if ( NPC->client->ps.saberEntityNum < ((1<<10)-1) && NPC->client->ps.saberEntityNum > 0 )
		{
			if ( g_entities[NPC->client->ps.saberEntityNum].s.pos.trType == TR_STATIONARY )
			{
				if ( Jedi_CanPullBackSaber( NPC ) )
				{
					
					
					
					
					NPC->client->ps.saberBlocked = BLOCKED_NONE;
					NPCInfo->goalEntity = &g_entities[NPC->client->ps.saberEntityNum];
					ucmd.buttons |= 1;
					if ( NPC->enemy && NPC->enemy->health > 0 )
					{
						if ( !NPC_MoveToGoal( qtrue ) )
						{
							NPC_FaceEntity( NPCInfo->goalEntity, qtrue );
							Jedi_TryJump( NPCInfo->goalEntity );
						}
						NPC_UpdateAngles( qtrue, qtrue );
						return;
					}
				}
			}
		}
	}

	if ( NPCInfo->goalEntity )
	{
		trace_t	trace;

		if ( Jedi_Jumping( NPCInfo->goalEntity ) )
		{
			return;
		}

		if ( !NAV_CheckAhead( NPC, NPCInfo->goalEntity->r.currentOrigin, &trace, ( NPC->clipmask & ~0x00000100 )|0x00000040 ) )
		{
			if ( NPC_ClearLOS4( NPCInfo->goalEntity ) && NPC_FaceEntity( NPCInfo->goalEntity, qtrue ) )
			{
				if ( Jedi_TryJump( NPCInfo->goalEntity ) )
				{
					return;
				}
			}
		}
		if ( NPCInfo->aiFlags & 0x00000040 )
		{
			if ( fabs(NPCInfo->blockedDest[2]-NPC->r.currentOrigin[2]) > 64 )
			{
				gentity_t *tempGoal = G_Spawn();
				G_SetOrigin( tempGoal, NPCInfo->blockedDest );
				trap_LinkEntity( tempGoal );
				TIMER_Set( NPC, "jumpChaseDebounce", -1 );
				if ( Jedi_TryJump( tempGoal ) )
				{
					G_FreeEntity( tempGoal );
					return;
				}
				G_FreeEntity( tempGoal );
			}
		}
	}
	
	NPC_BSFollowLeader();
}








static void Jedi_Attack( void )
{
	
	if ( NPC->painDebounceTime > level.time )
	{
		if ( Q_irand( 0, 1 ) )
		{
			Jedi_FaceEnemy( qtrue );
		}
		NPC_UpdateAngles( qtrue, qtrue );
		return;
	}

	if ( NPC->client->ps.saberLockTime > level.time )
	{
		
		if ( NPC->client->ps.fd.forcePowerLevel[FP_PUSH] > FORCE_LEVEL_2 
			&& NPC->client->ps.saberLockTime < level.time + 5000 
			&& !Q_irand( 0, 10 ))
		{
			ForceThrow( NPC, qfalse );
		}
		
		else
		{
			float chance;
		
			if ( NPC->client->NPC_class == CLASS_DESANN || !Q_stricmp("Yoda",NPC->NPC_type) )
			{
				if ( g_spskill.integer )
				{
					chance = 4.0f;
				}
				else
				{
					chance = 3.0f;
				}
			}
			else if ( NPC->client->NPC_class == CLASS_TAVION )
			{
				chance = 2.0f+g_spskill.value;
			}
			else
			{
				float maxChance	= (float)(RANK_LT)/2.0f+3.0f;
				if ( !g_spskill.value )
				{
					chance = (float)(NPCInfo->rank)/2.0f;
				}
				else
				{
					chance = (float)(NPCInfo->rank)/2.0f+1.0f;
				}
				if ( chance > maxChance )
				{
					chance = maxChance;
				}
			}
		
		
		
		
			if ( flrand( -4.0f, chance ) >= 0.0f )
			{
				ucmd.buttons |= 1;
			}
			
		}
		NPC_UpdateAngles( qtrue, qtrue );
		return;
	}
	
	if ( NPC->client->ps.saberInFlight )
	{
	
		if (!NPC->client->ps.saberEntityNum && NPC->client->saberStoredIndex) 
		{
			
			if (1) 
			{
			
				if (1) 
				{
					NPC->client->ps.saberBlocked = BLOCKED_NONE;
					NPCInfo->goalEntity = &g_entities[NPC->client->saberStoredIndex];
					ucmd.buttons |= 1;
					if ( NPC->enemy && NPC->enemy->health > 0 )
					{
						Jedi_Move( NPCInfo->goalEntity, qfalse );
						NPC_UpdateAngles( qtrue, qtrue );
						if ( NPC->enemy->s.weapon == WP_SABER )
						{
							vec3_t	enemy_dir, enemy_movedir, enemy_dest;
							float	enemy_dist, enemy_movespeed;
							Jedi_SetEnemyInfo( enemy_dest, enemy_dir, &enemy_dist, enemy_movedir, &enemy_movespeed, 300 );
							Jedi_EvasionSaber( enemy_movedir, enemy_dist, enemy_dir );
						}
						return;
					}
				}
			}
		}
	}
	
	
	if ( NPC->enemy )
	{
		if ( NPC->enemy->health <= 0 && NPC->enemy->enemy == NPC && NPC->client->playerTeam != NPCTEAM_PLAYER )
		{
			NPCInfo->enemyCheckDebounceTime = 0;

			if ( NPC->client->NPC_class == CLASS_BOBAFETT )
			{
				if ( NPCInfo->walkDebounceTime < level.time && NPCInfo->walkDebounceTime >= 0 )
				{
					TIMER_Set( NPC, "gloatTime", 10000 );
					NPCInfo->walkDebounceTime = -1;
				}
				if ( !TIMER_Done( NPC, "gloatTime" ) )
				{
					if ( DistanceHorizontalSquared( NPC->client->renderInfo.eyePoint, NPC->enemy->r.currentOrigin ) > 4096 && (NPCInfo->scriptFlags&0x00000400) )
					{
						NPCInfo->goalEntity = NPC->enemy;
						Jedi_Move( NPC->enemy, qfalse );
						ucmd.buttons |= 16;
					}
					else
					{
						TIMER_Set( NPC, "gloatTime", 0 );
					}
				}
				else if ( NPCInfo->walkDebounceTime == -1 )
				{
					NPCInfo->walkDebounceTime = -2;
					G_AddVoiceEvent( NPC, Q_irand( EV_VICTORY1, EV_VICTORY3 ), 3000 );
					jediSpeechDebounceTime[NPC->client->playerTeam] = level.time + 3000;
					NPCInfo->desiredPitch = 0;
					NPCInfo->goalEntity = ((void *)0);
				}
				Jedi_FaceEnemy( qtrue );
				NPC_UpdateAngles( qtrue, qtrue );
				return;
			}
			else
			{
				if ( !TIMER_Done( NPC, "parryTime" ) )
				{
					TIMER_Set( NPC, "parryTime", -1 );
					NPC->client->ps.fd.forcePowerDebounce[FP_SABER_DEFENSE] = level.time + 500;
				}
				NPC->client->ps.saberBlocked = BLOCKED_NONE;
				if ( !NPC->client->ps.saberHolstered && NPC->client->ps.saberInFlight )
				{
					
					
					
					Jedi_AggressionErosion(-3);
					if ( BG_SabersOff( &NPC->client->ps ) && !NPC->client->ps.saberInFlight )
					{
						G_AddVoiceEvent( NPC, Q_irand( EV_VICTORY1, EV_VICTORY3 ), 3000 );
						jediSpeechDebounceTime[NPC->client->playerTeam] = level.time + 3000;
						NPCInfo->desiredPitch = 0;
						NPCInfo->goalEntity = ((void *)0);
					}
					TIMER_Set( NPC, "gloatTime", 10000 );
				}
				if ( !NPC->client->ps.saberHolstered || NPC->client->ps.saberInFlight || !TIMER_Done( NPC, "gloatTime" ) )
				{
					if ( DistanceHorizontalSquared( NPC->client->renderInfo.eyePoint, NPC->enemy->r.currentOrigin ) > 4096 && (NPCInfo->scriptFlags&0x00000400) )
					{
						NPCInfo->goalEntity = NPC->enemy;
						Jedi_Move( NPC->enemy, qfalse );
						ucmd.buttons |= 16;
					}
					else
					{
						if ( NPC->health < NPC->client->pers.maxHealth 
							&& (NPC->client->ps.fd.forcePowersKnown&(1<<FP_HEAL)) != 0 
							&& (NPC->client->ps.fd.forcePowersActive&(1<<FP_HEAL)) == 0 )
						{
							ForceHeal( NPC );
						}
					}
					Jedi_FaceEnemy( qtrue );
					NPC_UpdateAngles( qtrue, qtrue );
					return;
				}
			}
		}
	}

	
	if ( NPC->enemy->s.weapon == WP_TURRET && !Q_stricmp( "PAS", NPC->enemy->classname ) )
	{
		if ( NPC->enemy->count <= 0 )
		{
			if ( NPC->enemy->activator && NPC_ValidEnemy( NPC->enemy->activator ) )
			{
				gentity_t *turretOwner = NPC->enemy->activator;
				G_ClearEnemy( NPC );
				G_SetEnemy( NPC, turretOwner );
			}
			else
			{
				G_ClearEnemy( NPC );
			}
		}
	}
	NPC_CheckEnemy( qtrue, qtrue, qtrue );

	if ( !NPC->enemy )
	{
		NPC->client->ps.saberBlocked = BLOCKED_NONE;
		if ( NPCInfo->tempBehavior == BS_HUNT_AND_KILL )
		{
			NPCInfo->tempBehavior = BS_DEFAULT;
			NPC_UpdateAngles( qtrue, qtrue );
			return;
		}
		Jedi_Patrol();
		return;
	}

	
	NPCInfo->combatMove = qtrue;

	
	Jedi_Combat();

	if ( !(NPCInfo->scriptFlags&0x00000400) 
		|| ((NPC->client->ps.fd.forcePowersActive&(1<<FP_HEAL))&&NPC->client->ps.fd.forcePowerLevel[FP_HEAL]<FORCE_LEVEL_2))
	{
		ucmd.forwardmove = 0;
		ucmd.rightmove = 0;
		if ( ucmd.upmove > 0 )
		{
			ucmd.upmove = 0;
		}
		NPC->client->ps.fd.forceJumpCharge = 0;
		((NPC->client->ps.moveDir)[0]=(NPC->client->ps.moveDir)[1]=(NPC->client->ps.moveDir)[2]=0);
	}

	
	if ( NPC->client->ps.groundEntityNum == ((1<<10)-1) )
	{
		
		ucmd.forwardmove = 0;
		ucmd.rightmove = 0;
		((NPC->client->ps.moveDir)[0]=(NPC->client->ps.moveDir)[1]=(NPC->client->ps.moveDir)[2]=0);
	}

	if ( !TIMER_Done( NPC, "duck" ) )
	{
		ucmd.upmove = -127;
	}

	if ( NPC->client->NPC_class != CLASS_BOBAFETT )
	{
		if ( PM_SaberInBrokenParry( NPC->client->ps.saberMove ) || NPC->client->ps.saberBlocked == BLOCKED_PARRY_BROKEN )
		{
			ucmd.buttons &= ~1;
		}
	}

	if( (NPCInfo->scriptFlags&0x00004000) 
		|| ((NPC->client->ps.fd.forcePowersActive&(1<<FP_HEAL))&&NPC->client->ps.fd.forcePowerLevel[FP_HEAL]<FORCE_LEVEL_3)
		|| ((NPC->client->ps.saberEventFlags&0x80)&&!NPC->client->ps.saberInFlight) )
	{
		ucmd.buttons &= ~(1|128);
	}

	if ( NPCInfo->scriptFlags&0x00800000 )
	{
		ucmd.upmove = 0;
		NPC->client->ps.fd.forceJumpCharge = 0;
	}

	if ( NPC->client->NPC_class != CLASS_BOBAFETT )
	{
		Jedi_CheckDecreaseSaberAnimLevel();
	}

	if ( ucmd.buttons & 1 && NPC->client->playerTeam == NPCTEAM_ENEMY )
	{
		if ( Q_irand( 0, NPC->client->ps.fd.saberAnimLevel ) > 0 
			&& Q_irand( 0, NPC->client->pers.maxHealth+10 ) > NPC->health 
			&& !Q_irand( 0, 3 ))
		{
			G_AddVoiceEvent( NPC, Q_irand( EV_COMBAT1, EV_COMBAT3 ), 1000 );
		}
	}

	if ( NPC->client->NPC_class != CLASS_BOBAFETT )
	{
		if ( NPC->client->NPC_class == CLASS_TAVION 
			|| (g_spskill.integer && ( NPC->client->NPC_class == CLASS_DESANN || NPCInfo->rank >= Q_irand( RANK_CREWMAN, RANK_CAPTAIN ))))
		{
			if ( NPC->enemy 
				&& !NPC->enemy->s.number 
				&& NPC->enemy->client 
				&& (NPC->enemy->client->ps.fd.forcePowersActive & (1<<FP_SPEED)) 
				&& !(NPC->client->ps.fd.forcePowersActive & (1<<FP_SPEED)) )
			{
				int chance = 0;
				switch ( g_spskill.integer )
				{
				case 0:
					chance = 9;
				case 1:
					chance = 3;
				case 2:
					chance = 1;
					break;
				}
				if ( !Q_irand( 0, chance ) )
				{
					ForceSpeed( NPC, 0 );
				}
			}
		}
	}
}

extern void NPC_BSST_Patrol( void );
extern void NPC_BSSniper_Default( void );
void NPC_BSJedi_Default( void )
{

	Jedi_CheckCloak();
	if( !NPC->enemy )
	{
		if ( NPC->client->NPC_class == CLASS_BOBAFETT )
		{
			NPC_BSST_Patrol();
		}
		else
		{
			Jedi_Patrol();
		}
	}
	else
	{
		if ( Jedi_WaitingAmbush( NPC ) )
		{
			Jedi_Ambush( NPC );
		}
		if ( NPC->client->NPC_class == CLASS_BOBAFETT )
		{
			if ( NPC->enemy->enemy != NPC && NPC->health == NPC->client->pers.maxHealth && DistanceSquared( NPC->r.currentOrigin, NPC->enemy->r.currentOrigin )>(800*800) )
			{
				NPCInfo->scriptFlags |= 0x00000040;
				Boba_ChangeWeapon( WP_DISRUPTOR );
				NPC_BSSniper_Default();
				return;
			}
		}
		Jedi_Attack();
		
		if ( ((!ucmd.buttons&&!NPC->client->ps.fd.forcePowersActive)||(NPC->enemy&&NPC->enemy->health<=0)) && NPCInfo->enemyCheckDebounceTime < level.time )
		{
			
			gentity_t *sav_enemy = NPC->enemy;
			gentity_t *newEnemy;

			NPC->enemy = ((void *)0);
			newEnemy = NPC_CheckEnemy( NPCInfo->confusionTime < level.time, qfalse, qfalse );
			NPC->enemy = sav_enemy;
			if ( newEnemy && newEnemy != sav_enemy )
			{
				NPC->lastEnemy = NPC->enemy;
				G_SetEnemy( NPC, newEnemy );
			}
			NPCInfo->enemyCheckDebounceTime = level.time + Q_irand( 1000, 3000 );
		}
	}
}

