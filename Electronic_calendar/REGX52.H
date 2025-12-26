/*--------------------------------------------------------------------------
AT89X52.H

Header file for the low voltage Flash Atmel AT89C52 and AT89LV52.
Copyright (c) 1988-2002 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
--------------------------------------------------------------------------*/

#ifndef __AT89X52_H__
#define __AT89X52_H__

/*--------------------------------------------------------------------------
AT89X52.H

低电压Flash Atmel AT89C52和AT89LV52的头文件。
版权所有 (c) 1988-2002 Keil Elektronik GmbH 和 Keil Software, Inc.
保留所有权利。
--------------------------------------------------------------------------*/
sfr PCON    = 0x87;
sfr P0      = 0x80;    // P0端口寄存器
sfr SP      = 0x81;    // 堆栈指针寄存器
sfr DPL     = 0x82;    // 数据指针低字节
sfr DPH     = 0x83;    // 数据指针高字节
sfr PCON    = 0x87;    // 电源控制寄存器
sfr TCON    = 0x88;    // 定时器/计数器控制寄存器
sfr TMOD    = 0x89;    // 定时器/计数器模式寄存器
sfr TL0     = 0x8A;    // 定时器0低字节
sfr TL1     = 0x8B;    // 定时器1低字节
sfr TH0     = 0x8C;    // 定时器0高字节
sfr TH1     = 0x8D;    // 定时器1高字节
sfr P1      = 0x90;    // P1端口寄存器
sfr SCON    = 0x98;    // 串口控制寄存器
sfr SBUF    = 0x99;    // 串口缓冲寄存器
sfr P2      = 0xA0;    // P2端口寄存器
sfr IE      = 0xA8;    // 中断允许寄存器
sfr P3      = 0xB0;    // P3端口寄存器
sfr IP      = 0xB8;    // 中断优先级寄存器
sfr T2CON   = 0xC8;    // 定时器2控制寄存器
sfr T2MOD   = 0xC9;    // 定时器2模式寄存器
sfr RCAP2L  = 0xCA;    // 定时器2捕获/重载低字节
sfr RCAP2H  = 0xCB;    // 定时器2捕获/重载高字节
sfr TL2     = 0xCC;    // 定时器2低字节
sfr TH2     = 0xCD;    // 定时器2高字节
sfr PSW     = 0xD0;    // 程序状态字寄存器
sfr ACC     = 0xE0;    // 累加器
sfr B       = 0xF0;    // B寄存器
sfr TL1     = 0x8B;
sbit P0_0 = 0x80;      // P0.0端口位
sbit P0_1 = 0x81;      // P0.1端口位
sbit P0_2 = 0x82;      // P0.2端口位
sbit P0_3 = 0x83;      // P0.3端口位
sbit P0_4 = 0x84;      // P0.4端口位
sbit P0_5 = 0x85;      // P0.5端口位
sbit P0_6 = 0x86;      // P0.6端口位
sbit P0_7 = 0x87;      // P0.7端口位
sfr SCON    = 0x98;
#define IDL_    0x01    // 空闲模式选择位
#define STOP_   0x02    // 停止模式选择位
#define PD_     0x02    // 电源下降模式选择位（别名）
#define GF0_    0x04    // 通用标志位0
#define GF1_    0x08    // 通用标志位1
#define SMOD_   0x80    // 串口波特率加倍位
sfr P3      = 0xB0;
sbit IT0  = 0x88;      // 外部中断0触发方式选择位
sbit IE0  = 0x89;      // 外部中断0中断标志位
sbit IT1  = 0x8A;      // 外部中断1触发方式选择位
sbit IE1  = 0x8B;      // 外部中断1中断标志位
sbit TR0  = 0x8C;      // 定时器0运行控制位
sbit TF0  = 0x8D;      // 定时器0溢出标志位
sbit TR1  = 0x8E;      // 定时器1运行控制位
sbit TF1  = 0x8F;      // 定时器1溢出标志位
sfr RCAP2L  = 0xCA;
#define T0_M0_   0x01   // 定时器0模式位0
#define T0_M1_   0x02   // 定时器0模式位1
#define T0_CT_   0x04   // 定时器0计数/定时选择位
#define T0_GATE_ 0x08   // 定时器0门控控制位
#define T1_M0_   0x10   // 定时器1模式位0
#define T1_M1_   0x20   // 定时器1模式位1
#define T1_CT_   0x40   // 定时器1计数/定时选择位
#define T1_GATE_ 0x80   // 定时器1门控控制位
#define T1_MASK_ 0xF0   // 定时器1掩码
#define T0_MASK_ 0x0F   // 定时器0掩码
sfr PSW     = 0xD0;
sbit P1_0 = 0x90;      // P1.0端口位
sbit P1_1 = 0x91;      // P1.1端口位
sbit P1_2 = 0x92;      // P1.2端口位
sbit P1_3 = 0x93;      // P1.3端口位
sbit P1_4 = 0x94;      // P1.4端口位
sbit P1_5 = 0x95;      // P1.5端口位
sbit P1_6 = 0x96;      // P1.6端口位
sbit P1_7 = 0x97;      // P1.7端口位
sbit T2   = 0x90;      // 定时器/计数器2外部输入，时钟输出
sbit T2EX = 0x91;      // 定时器/计数器2捕获/重载触发及方向控制
/*------------------------------------------------
sbit RI   = 0x98;      // 接收中断标志位
sbit TI   = 0x99;      // 发送中断标志位
sbit RB8  = 0x9A;      // 接收数据第9位
sbit TB8  = 0x9B;      // 发送数据第9位
sbit REN  = 0x9C;      // 串口接收允许位
sbit SM2  = 0x9D;      // 多机通信控制位
sbit SM1  = 0x9E;      // 串口工作模式选择位1
sbit SM0  = 0x9F;      // 串口工作模式选择位0
sbit P0_1 = 0x81;
sbit P2_0 = 0xA0;      // P2.0端口位
sbit P2_1 = 0xA1;      // P2.1端口位
sbit P2_2 = 0xA2;      // P2.2端口位
sbit P2_3 = 0xA3;      // P2.3端口位
sbit P2_4 = 0xA4;      // P2.4端口位
sbit P2_5 = 0xA5;      // P2.5端口位
sbit P2_6 = 0xA6;      // P2.6端口位
sbit P2_7 = 0xA7;      // P2.7端口位
sbit P0_5 = 0x85;
sbit EX0  = 0xA8;      // 1=允许外部中断0
sbit ET0  = 0xA9;      // 1=允许定时器0中断
sbit EX1  = 0xAA;      // 1=允许外部中断1
sbit ET1  = 0xAB;      // 1=允许定时器1中断
sbit ES   = 0xAC;      // 1=允许串口中断
sbit ET2  = 0xAD;      // 1=允许定时器2中断
sbit EA   = 0xAF;      // 0=禁止所有中断
/*------------------------------------------------
sbit P3_0 = 0xB0;      // P3.0端口位
sbit P3_1 = 0xB1;      // P3.1端口位
sbit P3_2 = 0xB2;      // P3.2端口位
sbit P3_3 = 0xB3;      // P3.3端口位
sbit P3_4 = 0xB4;      // P3.4端口位
sbit P3_5 = 0xB5;      // P3.5端口位
sbit P3_6 = 0xB6;      // P3.6端口位
sbit P3_7 = 0xB7;      // P3.7端口位
sbit RXD  = 0xB0;      // 串口数据输入
sbit TXD  = 0xB1;      // 串口数据输出
sbit INT0 = 0xB2;      // 外部中断0
sbit INT1 = 0xB3;      // 外部中断1
sbit T0   = 0xB4;      // 定时器0外部输入
sbit T1   = 0xB5;      // 定时器1外部输入
sbit WR   = 0xB6;      // 外部数据存储器写选通信号
sbit RD   = 0xB7;      // 外部数据存储器读选通信号

sbit PX0  = 0xB8;      // 外部中断0优先级位
sbit PT0  = 0xB9;      // 定时器0优先级位
sbit PX1  = 0xBA;      // 外部中断1优先级位
sbit PT1  = 0xBB;      // 定时器1优先级位
sbit PS   = 0xBC;      // 串口优先级位
sbit PT2  = 0xBD;      // 定时器2优先级位
#define GF0_    0x04
sbit CP_RL2= 0xC8;     // 0=重载，1=捕获选择
sbit C_T2 = 0xC9;      // 0=定时器，1=计数器
sbit TR2  = 0xCA;      // 0=停止定时器，1=启动定时器
sbit EXEN2= 0xCB;      // 定时器2外部使能
sbit TCLK = 0xCC;      // 0=串口时钟使用定时器1溢出，1=定时器2
sbit RCLK = 0xCD;      // 0=串口时钟使用定时器1溢出，1=定时器2
sbit EXF2 = 0xCE;      // 定时器2外部标志
sbit TF2  = 0xCF;      // 定时器2溢出标志
/*------------------------------------------------
#define DCEN_   0x01    // 1=定时器2可配置为上下计数器
#define T2OE_   0x02    // 定时器2输出使能
sbit IE1  = 0x8B;
sbit P    = 0xD0;      // 奇偶校验位
sbit F1   = 0xD1;      // 用户标志位1
sbit OV   = 0xD2;      // 溢出标志位
sbit RS0  = 0xD3;      // 寄存器组选择位0
sbit RS1  = 0xD4;      // 寄存器组选择位1
sbit F0   = 0xD5;      // 用户标志位0
sbit AC   = 0xD6;      // 辅助进位标志位
sbit CY   = 0xD7;      // 进位标志位
sbit TF1  = 0x8F;
#define IE0_VECTOR	0  // 0x03 外部中断0
#define TF0_VECTOR	1  // 0x0B 定时器0
#define IE1_VECTOR	2  // 0x13 外部中断1
#define TF1_VECTOR	3  // 0x1B 定时器1
#define SIO_VECTOR	4  // 0x23 串口

#define TF2_VECTOR	5  // 0x2B 定时器2
#define EX2_VECTOR	5  // 0x2B 外部中断2

#define T1_MASK_ 0xF0
#define T0_MASK_ 0x0F

/*------------------------------------------------
P1 Bit Registers
------------------------------------------------*/
sbit P1_0 = 0x90;
sbit P1_1 = 0x91;
sbit P1_2 = 0x92;
sbit P1_3 = 0x93;
sbit P1_4 = 0x94;
sbit P1_5 = 0x95;
sbit P1_6 = 0x96;
sbit P1_7 = 0x97;

sbit T2   = 0x90;       /* External input to Timer/Counter 2, clock out */
sbit T2EX = 0x91;       /* Timer/Counter 2 capture/reload trigger & dir ctl */

/*------------------------------------------------
SCON Bit Registers
------------------------------------------------*/
sbit RI   = 0x98;
sbit TI   = 0x99;
sbit RB8  = 0x9A;
sbit TB8  = 0x9B;
sbit REN  = 0x9C;
sbit SM2  = 0x9D;
sbit SM1  = 0x9E;
sbit SM0  = 0x9F;

/*------------------------------------------------
P2 Bit Registers
------------------------------------------------*/
sbit P2_0 = 0xA0;
sbit P2_1 = 0xA1;
sbit P2_2 = 0xA2;
sbit P2_3 = 0xA3;
sbit P2_4 = 0xA4;
sbit P2_5 = 0xA5;
sbit P2_6 = 0xA6;
sbit P2_7 = 0xA7;

/*------------------------------------------------
IE Bit Registers
------------------------------------------------*/
sbit EX0  = 0xA8;       /* 1=Enable External interrupt 0 */
sbit ET0  = 0xA9;       /* 1=Enable Timer 0 interrupt */
sbit EX1  = 0xAA;       /* 1=Enable External interrupt 1 */
sbit ET1  = 0xAB;       /* 1=Enable Timer 1 interrupt */
sbit ES   = 0xAC;       /* 1=Enable Serial port interrupt */
sbit ET2  = 0xAD;       /* 1=Enable Timer 2 interrupt */

sbit EA   = 0xAF;       /* 0=Disable all interrupts */

/*------------------------------------------------
P3 Bit Registers (Mnemonics & Ports)
------------------------------------------------*/
sbit P3_0 = 0xB0;
sbit P3_1 = 0xB1;
sbit P3_2 = 0xB2;
sbit P3_3 = 0xB3;
sbit P3_4 = 0xB4;
sbit P3_5 = 0xB5;
sbit P3_6 = 0xB6;
sbit P3_7 = 0xB7;

sbit RXD  = 0xB0;       /* Serial data input */
sbit TXD  = 0xB1;       /* Serial data output */
sbit INT0 = 0xB2;       /* External interrupt 0 */
sbit INT1 = 0xB3;       /* External interrupt 1 */
sbit T0   = 0xB4;       /* Timer 0 external input */
sbit T1   = 0xB5;       /* Timer 1 external input */
sbit WR   = 0xB6;       /* External data memory write strobe */
sbit RD   = 0xB7;       /* External data memory read strobe */

/*------------------------------------------------
IP Bit Registers
------------------------------------------------*/
sbit PX0  = 0xB8;
sbit PT0  = 0xB9;
sbit PX1  = 0xBA;
sbit PT1  = 0xBB;
sbit PS   = 0xBC;
sbit PT2  = 0xBD;

/*------------------------------------------------
T2CON Bit Registers
------------------------------------------------*/
sbit CP_RL2= 0xC8;      /* 0=Reload, 1=Capture select */
sbit C_T2 = 0xC9;       /* 0=Timer, 1=Counter */
sbit TR2  = 0xCA;       /* 0=Stop timer, 1=Start timer */
sbit EXEN2= 0xCB;       /* Timer 2 external enable */
sbit TCLK = 0xCC;       /* 0=Serial clock uses Timer 1 overflow, 1=Timer 2 */
sbit RCLK = 0xCD;       /* 0=Serial clock uses Timer 1 overflow, 1=Timer 2 */
sbit EXF2 = 0xCE;       /* Timer 2 external flag */
sbit TF2  = 0xCF;       /* Timer 2 overflow flag */

/*------------------------------------------------
T2MOD Bit Values
------------------------------------------------*/
#define DCEN_   0x01    /* 1=Timer 2 can be configured as up/down counter */
#define T2OE_   0x02    /* Timer 2 output enable */

/*------------------------------------------------
PSW Bit Registers
------------------------------------------------*/
sbit P    = 0xD0;
sbit F1   = 0xD1;
sbit OV   = 0xD2;
sbit RS0  = 0xD3;
sbit RS1  = 0xD4;
sbit F0   = 0xD5;
sbit AC   = 0xD6;
sbit CY   = 0xD7;

/*------------------------------------------------
Interrupt Vectors:
Interrupt Address = (Number * 8) + 3
------------------------------------------------*/
#define IE0_VECTOR	0  /* 0x03 External Interrupt 0 */
#define TF0_VECTOR	1  /* 0x0B Timer 0 */
#define IE1_VECTOR	2  /* 0x13 External Interrupt 1 */
#define TF1_VECTOR	3  /* 0x1B Timer 1 */
#define SIO_VECTOR	4  /* 0x23 Serial port */

#define TF2_VECTOR	5  /* 0x2B Timer 2 */
#define EX2_VECTOR	5  /* 0x2B External Interrupt 2 */

#endif



