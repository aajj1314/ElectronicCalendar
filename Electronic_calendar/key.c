#include <REGX52.H>
#include "Delay.h"
#include "Key.h"

unsigned char MKey(void)
{
unsigned char  key_nem ;
while(1)
{		
		P2_3 = 0;
		P2 &= 0x0f ;
		P2 |= 0x10 ;
		if(P2_6==0){Delay(10);  Delay(2); x=~x   ;  }
		if(P2_7==0){Delay(10);  Delay(2); Dey++  ;  }	
		
		P2 &= 0x0f ;
		P2 |= 0x20 ;		
	  if(P2_6==0){Delay(10);  Delay(2); Month++ ;  }
		if(P2_7==0){Delay(10);  Delay(2); Year++  ;  }	
	return key_nem ;
	}
}




