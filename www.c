#include "reg52.h"
#include "intrins.h"

sbit led=P0^0;


 


#define MAX 17

#define uchar unsigned char
	#define BOOL unsigned char
#define uint  unsigned int
#define delayNOP(); {_nop_();_nop_();_nop_();_nop_();};
uchar IRCOM[7];
void delay(uchar x);  //x*0.14MS
void delay1(int ms);
void beep();
BOOL bools;
//uchar syb[][2]{0x34,0x35};
//uchar resName[]={0,1,2,3,4,5,6,7,8,9,0x0a,0x};
uchar now,late;
typedef struct{
	uchar now; 
	uchar late; 
	uchar resName;
 }bits;

   unsigned char j,i;
 bits next[MAX];
 
sbit IRIN = P3^2;         //红外接收器数据线
    uchar name;
 
 void initdata(){
	 
	 	next[0].now=0x31;
	 next[0].late=0x39;
	 next[0].resName=0;
	 next[1].now=0x34;
	 next[1].late=0x35;
	 next[1].resName=1;
	 
	 	 next[2].now=0x34;
	 next[2].late=0x36;
	 next[2].resName=2;
	 
	  next[3].now=0x34;
	 next[3].late=0x37;
	 next[3].resName=3;
	 
	  next[4].now=0x34;
	 next[4].late=0x34;
	 next[4].resName=4;
	 
	 next[5].now=0x34;
	 next[5].late=0x30;
	 next[5].resName=5;
	 
	 	 next[6].now=0x34;
	 next[6].late=0x33;
	 next[6].resName=6;
	 
	 
	 next[7].now=0x30;
	 next[7].late=0x37;
	 next[7].resName=7;
	 
	 
	 next[8].now=0x31;
	 next[8].late=0x35;
	 next[8].resName=8;
	 
	  
	 next[9].now=0x30;
	 next[9].late=0x39;
	 next[9].resName=9;
	 
	 
	 next[10].now=0x31;
	 next[10].late=0x36;
	 next[10].resName=0x10;//*
	 
	 	 next[11].now=0x30;
	 next[11].late=0x44;
	 next[11].resName=0x11;//#
	 
	 	 	 next[12].now=0x30;
	 next[12].late=0x38;
	 next[12].resName=0x20;//<
	 
	 
	  	 	 next[13].now=0x35;
	 next[13].late=0x41;
	 next[13].resName=0x21;//>
	 
	   next[14].now=0x31;
	   next[14].late=0x38;
	   next[14].resName=0x22;//^
		 
		 
		    next[15].now=0x35;
	   next[15].late=0x32;
	   next[15].resName=0x23;//^
	 
	 
	 
		  next[16].now=0x31;
	   next[16].late=0x43;
	   next[16].resName=0x30;//ok
	 
 }
 
 
 
void UartInit(void)  //9600bps@12.000MHz
           {
          //8???,?????
      SCON = 0x40;
        TMOD = 0x20;  //?????1?16???????
        TL1 = 0xFD;  //????????????9600  
       TH1 = 0xFD;  //??????
      ET1 = 0;  //?????1??
      TR1 = 1;  //?????1
       EA = 1;
       PCON&=0x7F;
      
        TI=1;
        ES=1;      //?????
        REN=1;
     
              // MOSI=0;
     }

		 
		  void send_byte(unsigned char c)
        {
      SBUF = c;
       while(!TI);
       TI = 0;
    }
				
		

 void actions(){
	 
	  for(i=0;i<5;i++){
     if(next[i].now==now&&next[i].late==late){
			 switch(next[i].resName){
				  case 0x00: send_byte(next[i].resName);break;
				  case 0x01: send_byte(next[i].resName);break;
				  case 0x02: send_byte(next[i].resName);break;
				  case 0x03: send_byte(next[i].resName);break;
			 	 case 0x04: send_byte(next[i].resName);break;
				
			 }
	    }
		 
   }	
 }
 
  void actions1(){
	 
	  for(i=5;i<10;i++){
     if(next[i].now==now&&next[i].late==late){
			 switch(next[i].resName){
				  case 0x05: send_byte(next[i].resName);break;
		    case 0x06: send_byte(next[i].resName);break;
			  case 0x07: send_byte(next[i].resName);break;
				  case 0x08: send_byte(next[i].resName);break;
				  case 0x09: send_byte(next[i].resName);break;
			
			 }
	    }
		 
   }	
 }
 
  void actions2(){
	 
	  for(i=10;i<12;i++){
     if(next[i].now==now&&next[i].late==late){
			 switch(next[i].resName){
				  case 0x10: send_byte(next[i].resName);break;
		    case 0x11: send_byte(next[i].resName);break;
			  }
	    }
		 
   }	
 }
 
   void actions3(){
	 
	  for(i=12;i<17;i++){
     if(next[i].now==now&&next[i].late==late){
			 switch(next[i].resName){
				  case 0x20: send_byte(next[i].resName);break;
		    case 0x21: send_byte(next[i].resName);break;
				 case 0x22: send_byte(next[i].resName);break;
		    case 0x23: send_byte(next[i].resName);break;
				case 0x30: send_byte(next[i].resName);break;
			//	 default : send_byte(next[i].resName);break;
			  }
	    }
		 
   }	
 }
 
 
void main(){
	//led=0;
	bools=0;
	initdata();
	    IE = 0x81;                 //允许总中断中断,使能 INT0 外部中断
    TCON = 0x01;               //触发方式为脉冲负边沿触发

    IRIN=1;                    //I/O口初始化
	UartInit();
	P0=0XF0;
	
	while(1){
		if(bools){
      
 actions(); //3个actions 是为了优化内存 处理，
			delay(2); 
			      
 actions1();
					delay(2);
			 actions2();
					delay(2);
			 actions3();
				 bools=0;


		}
		
		
		
		
	}


	
}



/**********************************************************/
void IR_IN() interrupt 0 using 0
{
  unsigned char j,k,N=0;
     EX0 = 0;   
	 delay(15);
	 if (IRIN==1) 
     { EX0 =1;
	   return;
	  } 
                           //确认IR信号出现
  while (!IRIN)            //等IR变为高电平，跳过9ms的前导低电平信号。
    {delay(1);}

 for (j=0;j<4;j++)         //收集四组数据
 { 
  for (k=0;k<8;k++)        //每组数据有8位
  {
   while (IRIN)            //等 IR 变为低电平，跳过4.5ms的前导高电平信号。
     {delay(1);}
    while (!IRIN)          //等 IR 变为高电平
     {delay(1);}
     while (IRIN)           //计算IR高电平时长
      {
    delay(1);
    N++;           
    if (N>=30)
	 { EX0=1;
	 return;}                  //0.14ms计数过长自动离开。
      }                        //高电平计数完毕                
     IRCOM[j]=IRCOM[j] >> 1;                  //数据最高位补“0”
     if (N>=8) {IRCOM[j] = IRCOM[j] | 0x80;}  //数据最高位补“1”
     N=0;
  }//end for k
 }//end for j
   
   if (IRCOM[2]!=~IRCOM[3])
   { EX0=1;
     return; }

   IRCOM[5]=IRCOM[2] & 0x0F;     //取键码的低四位
   IRCOM[6]=IRCOM[2] >> 4;       //右移4次，高四位变为低四位

   if(IRCOM[5]>9)
    { IRCOM[5]=IRCOM[5]+0x37;}
   else
	  IRCOM[5]=IRCOM[5]+0x30;

   if(IRCOM[6]>9)
    { IRCOM[6]=IRCOM[6]+0x37;}
   else
	  IRCOM[6]=IRCOM[6]+0x30;

             bools=1;
  //   send_byte(IRCOM[6]);        
         //   delay(10);   
   //  send_byte(IRCOM[5]);        

	    now=IRCOM[6];
	   late= IRCOM[5];
	 

     EX0 = 1; 
} 



/**********************************************************/
void delay(unsigned char x)    //x*0.14MS
{
 unsigned char i;
  while(x--)
 {
  for (i = 0; i<13; i++) {}
 }
}

/**********************************************************/
void delay1(int ms)
{
 unsigned char y;
  while(ms--)
 {
  for(y = 0; y<250; y++)
  {
   _nop_();
   _nop_();
   _nop_();
   _nop_();
  }
 }
 }