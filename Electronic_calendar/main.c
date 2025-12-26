#include<8051.h>
#include <REGX52.H>
#include <intrins.h>
#include "Nixie.h"
#include "delay.h"
unsigned char Dey = 26 , Month = 2 ; 
unsigned int Year = 2000 ;
unsigned char D1 , D2 , D3 , D4 , D5 , D6 , D7 , D8 ;
unsigned char Month_dey_max[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bit x = 0 ;
////////////////////////////////////////////////
void INT0_Init(void) ;
void Key_choose(void);
void limit (void);
void convert (void);
////////////////////////////////////////////////
void main()
{ 
	INT0_Init();
	while(1)
	{
		Key_choose();
		limit();
		convert();
		
		N_D(8,D8) ;
		N_D(7,D7) ;
		
		N_D(6,D6) ;
		N_D(5,D5) ;
		
		N_D(4,D4) ;
		N_D(3,D3) ;
		N_D(2,D2) ;
		N_D(1,D1) ;

	}	
}
///////////////////////////////////////////////
void Key_choose(void)
{
	if(x == 1 )	
	{
		P2_4 = 0;
		if(P2_5==0){Delay(10); while(P2_5==0); Delay(2); Dey++ ;    }
		if(P2_6==0){Delay(10); while(P2_6==0); Delay(2); Month++ ;  }
	  if(P2_7==0){Delay(10); while(P2_7==0); Delay(2); Year++ ;   }		
	}
	else
	{
		P2_4 = 1;

	}
}
////////////////////////////////////////////////
void limit (void)
{
	if ( Year % 400 == 0 ||Year % 4 == 0 && Year % 100 != 0){ Month_dey_max[2] = 29; } else{Month_dey_max[2] = 28 ;}
	if ( Dey > Month_dey_max[Month] ){ Dey = 1; Month++ ; }
	if ( Month > 12  ) { Month = 1 ; Year++ ; }
	if ( Year >= 2125 ) { Year = 1 ;  }

}
////////////////////////////////////////////////

void convert (void)
{
	D1 = Year / 1000 ;
	D2 = ( Year % 1000 ) / 100 ;
	D3 = (( Year % 1000 ) % 100 ) / 10; 
	D4 = (( Year % 1000 ) % 100 ) % 10; 
	
	D5 = Month / 10 ;
	D6 = Month % 10 ;
	
	D7 = Dey / 10 ;
	D8 = Dey % 10 ;
	
}
//////////////////////////////////////////////
void INT0_Init(void)
{
	EA = 1 ;
	EX0 =1 ;
	IT0 = 1 ;
}


void INT0_RS() interrupt 0 using 0
{
	x=~x;
}
