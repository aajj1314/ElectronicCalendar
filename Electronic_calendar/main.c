/*
 * 日期设置程序
 * 功能：通过按键控制设置年、月、日
 * 作者：[Anan]
 * 日期：[2025-12-26]
 * 版本：[1.7]
 */
#include <REGX52.H>
#include <intrins.h>
#include "Nixie.h"
#include "delay.h"
unsigned char Day = 26 , Month = 12 ;                                                //初始日月变量                       
unsigned int  Year = 2025 ;                                                          //初始年份变量              
unsigned char low_bits ;                                                             //按键扫描低四位变量            
unsigned char count = 0 ;                                                            //按键计数变量(计数2次，因为进入设置模式后，计数会自动加1次)           
unsigned char D1 , D2 , D3 , D4 , D5 , D6 , D7 , D8 ;                                //数码管显示数据变量
unsigned char Month_dey_max[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //月份对应的最大天数数组，下标对应月份，下标0无意，为义索引占位
bit Turn_flag = 0 ;                                                                  //进入设置模式标志位
////////////////////////////////////////////////
void Key_choose(void); //按键选择设置数据函数
void limit (void);     //日期数据限制函数
void convert (void);   //数码管显示数据转换函数
void N_D_Setup(void);  //数码管显示设置的日期函数
void open_Key(void);   //按键扫描入口函数
////////////////////////////////////////////////
void main()
{ 
	while(1)
	{   
		open_Key();
		Key_choose();
		limit();
		convert();
		N_D_Setup();
	}	
}
////////////////////////////////////////////////
void Key_choose(void)
{
    while (Turn_flag == 1)
    {
        low_bits = P2 & 0x0F;                                                           // 读取P2口的低四位
        limit();
		convert();
        N_D_Setup();
        P2_4 = 0;                                                                       // 扫描第一行（P2_4=0, other =1）
        P2_5 = 1;
        P2_6 = 1;
        P2_7 = 1;
        if(P2_7==0){Delay(2); while(P2_7==0){N_D_Setup();}; Delay(2); Day++;   }        //按键控制日
        if(P2_6==0){Delay(2); while(P2_6==0){N_D_Setup();}; Delay(2); Month++ ;}        //按键控制月
        low_bits = P2 & 0x0F; 
        P2_4 = 1; 
        P2_5 = 0;                                                                       // 扫描第二行（P2_5 = 0 other = 1 ）
        P2_6 = 1;
        P2_7 = 1;
        if(P2_7==0){Delay(2); while(P2_7==0){N_D_Setup();}; Delay(2); Year++ ; }        //按键控制年
        if(P2_6==0){Delay(2); while(P2_6==0){N_D_Setup();}; Delay(2); count++ ;}        //按键控制退出设置
        if(count > 1){count=0; Turn_flag=0;  P2_3 = 1; }                                //退出设置模式   
    }
}
////////////////////////////////////////////////
void limit (void)
{
	if ( Year % 400 == 0 ||Year % 4 == 0 && Year % 100 != 0){ Month_dey_max[2] = 29; } else{Month_dey_max[2] = 28 ;} //年份闰年判断
	if ( Day > Month_dey_max[Month] ){ Day = 1; Month++ ; }                                                          //日期最大值限制
	if ( Month > 12  ) { Month = 1 ; Year++ ; }                                                                      //月份最大值限制                                   
	if ( Year >= 2125 ) { Year = 1 ;  }                                                                              //年份最大值限制   

}
////////////////////////////////////////////////

void convert (void)
{
    D1 = Year / 1000;                   //年千位
    D2 = (Year / 100) % 10;             //年百位
    D3 = (Year / 10) % 10;              //年十位
    D4 = Year % 10;                     //年个位
	
	D5 = Month / 10 ;                   //月十位
	D6 = Month % 10 ;                   //月个位
	
	D7 = Day / 10 ;                     //日十位
	D8 = Day % 10 ;	                    //日个位
}
////////////////////////////////////////////////
void N_D_Setup(void)
{
    	N_D(8,D8) ;                     //显示日个位
		N_D(7,D7) ;                     //显示日十位
		
		N_D(6,D6) ;                     //显示月个位
		N_D(5,D5) ;                     //显示月十位
		
		N_D(4,D4) ;                     //显示年个位
		N_D(3,D3) ;                     //显示年十位
		N_D(2,D2) ;                     //显示年百位
		N_D(1,D1) ;                     //显示年千位
}
////////////////////////////////////////////////
void open_Key(void)
{
    P2_5 = 0;                           //扫描
    P2_6 = 1;                           //扫描
    if(P2_6==0)                         //进入设置模式判断I/O口
    {
      Delay(15);
      if(P2_6==0)
      {
        Delay(10);
        Turn_flag= 1 ;                 //进入设置模式标志位置1      
        P2_3 = 0;                      //指示灯点亮
      }
        
    }
    
}


