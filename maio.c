#include <reg52.h>

sbit  MOSO =P2^0;
sbit  led =P1^2;
sbit  led2=P1^1;
sbit  led3 =P1^0;
sbit  SCK=P2^1;
sbit MOSI= P2^2;


sbit MOCS= P2^3;


#define XTAL 11059200 // CUP ????

#define baudrate 9600 // ?????
typedef unsigned int uint16;
typedef unsigned char uint8 ; 
int syblo[8];
 uint16  bools =0;
uint8  txt;
 uint16  indexs =0;
 
 uint8 buf=0x00;
 #define uchar unsigned char;
 #define delayNOP(); {_nop_();_nop_();_nop_();_nop_();};     
 
void delay(unsigned int i)
{
	unsigned int j;
	unsigned char k;
 
	for(j=i; j>0; j--)
		for(k=100; k>0; k--);
}
 

 
void delays(unsigned int i)
{
	unsigned int j;
 
	//for(j=i; j>0; j--);
			j=1+2;
			
	
	j=j/9;
	
	j=j*9;
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




void serial() interrupt 4
	{

if(RI){
		ES=0;		//????????
	
	buf=SBUF;	//???????SBUF??buf??
	 RI=0;
		//	led3=1;
}
	ES=1;		//????????


}

void set_Spi_send(unsigned char c)
{			int j;
	 int i;
	// SCK=0;
	 MOCS=0;
	 				
		delay(1);	
	
MOSI=0;
	
	 MOCS=1;
	 for(i=0;i<8;i++){
		 //delayNOP();
	//_nop_();
		 SCK=0;
		 
		  //
		 if((c&0x80)==0x80){
      	delays(5);
			 	  MOSI=1;	
			 	led3=0;
		 }else{
			 		delays(5);
			 	MOSI=0;
		 }
	    if(i!=7)
	   	 c=c<<1;
		 // delays(1);

				j++;
				
      SCK=1;
			
		delay(10);
		 
	 }
	 MOSI=0;
	
	 
	 	  

	 
}



uchar spiread() 
{
  int i, j;
	
uint8	 review=0;
	uint8 k[8]={0};
for(i=0;i<8;){
 if(SCK==0){
	

	 

		  delays(100);
	  if(SCK==1){
		
				  delays(100);
	 if(MOSO==1){
		 
		 //led=0;
		     k[i]=1;
		 		 led2=1;
	//	send_byte(0x01);
	 }else{
		 
		// send_byte(0xff);
		  k[i]=0;
		// led=1;
		 led2=0;
	 }
	 	

	 i++;
 }
	 
 }
}

	
for(i=0;i<8;i++){
		
		if(k[i]==1){
			   review =review|0x01;   
				send_byte(0xff);
		}else{
			   review= review&0xfe; 
					send_byte(0x01);}
		
					    if(i<7)
						 review=review<<1;
	}
	
	
	if(review==0x88)		 
		   led=0;
	else
led=1;
	
	
return(review);

}



//interrupt 4
void rec(){
	  if(MOCS==0){
			  // led=0;
			  delays(100);
		  	txt= spiread();
			// if(txt==0x02)		 
		   //  led=0;
		   //else
		   //  led=1;	 
	  	
}
		}

void main(){
UartInit();
	// UartInit();
		led3=0;
	//init();
	
		
		while(1){
			
		
	send_byte(0x50);
		//	send_byte(0);
					buf=0;
	  delay(300);
	
		if(buf==0x90){
		     delay(10);
		   
			buf=0;
					led3=1;
				break;
		}
	}
		delay(500);
	
	
		  
	//set_Spi_send(0x55);
	//while(1){
	//rec() ;
				
			//	send_byte(0x01);
		//delay(200);

	/*
		 led2=1;
		delay(500);
		 led=1;*/
	//}
	// delay(1000);
   // led3=1;
			//delay(500);
	
	 
	 
	
	
	//	send_byte(0x01);
		//delay(1000);
	
	/*iutp=0;
	led=1;
 led2=1;
	led3=0;
	
	
	
	
	
	while(indexs!=8){
	
		
		 
		 led2=1;
		 		delay(500);
	 led2=0;
		if(iutp==1){
			txt= txt|0x01; 
			led=0;
		
			indexs++;
				txt=txt<<1;
		
		}else{
			led=1;
	txt= txt&0xfe;   
	txt=txt<<1;
			indexs++;
		}
	
		delay(500);
		
	}
	
	if(txt==0x01){
	  led2=0;
	led=1;
	
	}else{
	led3=1;
		  led=0;
	}
	send_byte(txt);
		delay(5000);
		
		*/
}


