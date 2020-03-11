#include <ESP8266WiFi.h>


#include <SoftwareSerial.h>
WiFiClient client;

SoftwareSerial mySerial(2, 3); //  TX,RX
//void  ICACHE_RAM_ATTR IntCallback();
//void  ICACHE_RAM_ATTR reviewurnBack();
uint8_t  SPI_CLOCK =D1;
uint8_t  GPIO_Iup =D0;
uint8_t  GPIO_CS=D2;
uint8_t  GPIO_MOSI=D3;
uint8_t  RX=D8;
uint8_t  TX=D7;
uint8_t  GPIO_LED =D5;

String str;
int  bits[8];

char  review;

 char  * ssid = "testtcp";
char * password = "88888888";
char text[1024];
bool bConnected = false;
int suppor_add;

int MCS;
   
void setup() {
  // put your setup code here, to run once:
  Serial.println("Data from port one:");
 inits();
 
 //attachInterrupt(digitalPinToInterrupt(SPI_CLOCK), IntCallback, RISING); //中断处理
// attachInterrupt(digitalPinToInterrupt(GPIO_CS), reviewurnBack, RISING); //中断处理

}



 char n=0X90;
char inByte;
void loop() {
  // put your main code here, to run repeatedly:

/* if (mySerial.available())
    Serial.write(mySerial.read());
  if (Serial.available())
    mySerial.write(Serial.read());
*/

if (Serial.available()){
inByte =Serial.read();
   Serial.write(inByte);
}

     
    
 //delay(1000);

 
  //Serial.println("Data from port one:");
/*    while (mySerial.available() > 0) {
    char inByte = mySerial.read();
    //Serial.write(inByte);
    if(inByte==0x50){
      digitalWrite(GPIO_CS, LOW);
             delay(1000);

    }



    
    }
  
  */
 
 // str=Serial.readString() ;
// if(){
  /* MCS=digitalRead(GPIO_CS); 
  if(MCS==0){
    Callback();
    Serial.println(review,BIN);


 

  if(review==0x55)
   Serial.println("====");
 else{
    
    Serial.println("----");
 }
 
 
 }*/
 
// }else{
//  
// }
 


//pinMode(SPI_CLOCK, INPUT);



 // Serial.println(review,BIN);


  //delay(10);

 // delay(500);

 



 


}

/* 实现SPI接收*/
void Callback(){
int ck,Iup;

while(1){
ck=digitalRead(SPI_CLOCK); //判断 时钟 
if(ck==0){ //时钟 低电位有效
  
// delay(2);
   if(suppor_add==0) // 8位进制传送 ，累计到第八个 就复位
     review=0;
   
   delay(1);
  // re=digitalRead(SPI_CLOCK);

      delay(2); //延迟
  Iup=digitalRead(GPIO_Iup); 
  if(Iup==1){// 判断IO传送0 or 1
 
     review =review|0x01;  
     //  Serial.print(1);
  }else{
    
      review= review&0xfe;  
    // Serial.print(0); 
  }
   suppor_add++;
   if(suppor_add<8) 
  review=review<<1;// 移位
  
if(suppor_add==8){
  suppor_add=0;
 break; 
}

  
}

}
  
}



/* 发送信息*/
void set_Spi_send(char txt){

  int j;
  digitalWrite(GPIO_CS, LOW); 
  delay(20);
  digitalWrite(GPIO_CS, HIGH); 
 
   for(int i=0;i<8;i++){

  digitalWrite(SPI_CLOCK, LOW); 

   if((txt&0x80)==0x80){
       delay(200);
   digitalWrite(GPIO_MOSI, HIGH); 
  
   }else{
    delay(200);
   digitalWrite(GPIO_MOSI, LOW); 
     
   }
    if(i!=7)
       txt=txt<<1;

//analogWrite()
      
     digitalWrite(SPI_CLOCK, HIGH); 
      delay(500);
   }

   

}



/*请求TCP服务器*/
void context(){
 client.print("743747347374347");

   Serial.println("[Response:]");
    while (client.connected())
    {
      if (client.available())
      {
         String line = client.readStringUntil('\r\n');
          Serial.println(line);
          Serial.println("===============");
           
      }
      
       delay(500);
       client.println(String("code=1010 我是WIFI "));
      // client.println(Serial.readString() );
 
    }
    client.stop();
    Serial.println("\n[Disconnected]");


  
}




void inits(){

pinMode(GPIO_CS, OUTPUT);
   digitalWrite(GPIO_CS, HIGH);
  /*
pinMode(GPIO_Iup, INPUT);
pinMode(GPIO_CS, INPUT);

pinMode(SPI_CLOCK, INPUT);
pinMode(GPIO_LED, OUTPUT);
//pinMode(SPI_CLOCK, OUTPUT);

pinMode(GPIO_MOSI, OUTPUT);

pinMode(GPIO_MOSI, OUTPUT);

// digitalWrite(SPI_CLOCK, HIGH);
 // digitalWrite(GPIO_CS, HIGH);
 
 digitalWrite(GPIO_LED, LOW); 
*/
Serial.begin(9600);

mySerial.println("AT+UART_DEF=9600,8,1,0,0\r\n");//解决乱码



//wifi_info();
}





void  wifi_info(){


int stats =  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
      
  }

    Serial.println("WiFi connected");
    Serial.println(WiFi.localIP());

 if (!client.connect("192.168.137.1",8888)) {
 
    delay(5000);
    Serial.print(".");
       Serial.print("connection failed");
   return;
 
  }

  context();
}
