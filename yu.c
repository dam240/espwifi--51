#include "ten.h"
#define NB 17 


void main(){
		unsigned char i,j;
S=0;
	OLED_Init(); //OLED???
		
		j=0;
	while(1)
	{
	
	
		//OLED_P16x16Ch(32,j,i);
 //OLED_P16x16Ch(31,6,0);
//	 OLED_P16x16Ch(0,0,10);
		// OLED_P16x16Ch(0,3,10);
			// OLED_P16x16Ch(0,7,10);
	  for(i=0;i<8;i++){
			
					OLED_P16x16Ch(i*16,0,i);
					OLED_P16x16Ch(i*16,2,i+8);
					OLED_P16x16Ch(i*16,4,i+16);
		}
		
		
		
	/*	OLED_P16x16Ch(40,0,2);
		OLED_P16x16Ch(57,0,3);
		OLED_P16x16Ch(74,0,4);
		OLED_P16x16Ch(91,0,5);
		for(i=0; i<8; i++)//???????? -- i?????????
		{
			OLED_P16x16Ch(i*16,0,i);
		 	OLED_P16x16Ch(i*16,2,i+8);
		 	OLED_P16x16Ch(i*16,4,i+16);
		 	OLED_P16x16Ch(i*16,6,i+24);
		}*/
		delay(4000);
	OLED_CLS();
		
			  for(i=0;i<8;i++){
			
					OLED_P16x16Ch(i*16,1,i);
					OLED_P16x16Ch(i*16,3,i+8);
					OLED_P16x16Ch(i*16,5,i+16);
		}
						delay(4000);
		
			OLED_CLS();
		
			  for(i=0;i<8;i++){
			
					OLED_P16x16Ch(i*16,2,i);
					OLED_P16x16Ch(i*16,4,i+8);
					OLED_P16x16Ch(i*16,6,i+16);
		}
		

		delay(4000);
		
	OLED_CLS();


		
			  for(i=0;i<8;i++){
			
					OLED_P16x16Ch(i*16,4,i);
					OLED_P16x16Ch(i*16,6,i+8);
					OLED_P16x16Ch(i*16,0,i+16);
		}
						delay(4000);
		OLED_CLS();
		
		
		
		//??
		/*	OLED_P8x16Str(0,0,"HelTec");//??? -- 8x16???????ASCII?
		OLED_P8x16Str(0,2,"OLED Display");
		OLED_P8x16Str(0,4,"www.heltec.cn");
		OLED_P6x8Str(0,6,"cn.heltec@gmail.com");
		OLED_P6x8Str(0,7,"heltec.taobao.com");
		delay(4000);
		OLED_CLS();
		*/
	}
		//OLED_P6x8Str(0,1,"11111");
	//	OLED_P8x16Str(0,4,"1111111");
		//delay(4000);
		//	OLED_CLS();
}