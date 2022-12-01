#include <SoftwareSerial.h> 
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd1(0x27, 16, 2);
SoftwareSerial MyBlue(2, 3); // RX | TX 
int flag = 0; 
int LEDr = 8; 
int LEDg = 9; 
int i;
String x;
char data;

void setup() 
{
 Serial.begin(9600); 
 MyBlue.begin(9600); 
 pinMode(LEDr, OUTPUT); 
 pinMode(LEDg, OUTPUT);
 Serial.println("Ready to connect\nDefualt password is 1234 or 000"); 
  lcd1.init(); // initialisation de l'afficheur
} 
void loop() 
{ 
    lcd1.backlight();
 while (MyBlue.available()) 
  { flag = MyBlue.read(); 
   

    //Serial.println((char)flag); 
  Serial.write(flag);
       lcd1.print(flag);
    //Serial.println();
   
   }/*
while (flag == 'a') 
 { 
   Serial.write('1');
 } 
/* else if (flag == 'b') 
 { 
 Serial.write('1');
 }*/
   
  
 /*else if (flag == '1') 
 { 
  Serial.write('1');

 }
 else if (flag == '2') 
 { 
  Serial.write('2');

 }
 else if (flag == '3') 
 { 
  Serial.write('3');

 }
 else if (flag == '4') 
 { 
  Serial.write('4');

 }
 else if (flag == '5') 
 { 
  Serial.write('5');

 }
 else if (flag == '6') 
 { 
  Serial.write('6');

 }
 else if (flag == '7') 
 { 
  Serial.write('7');

 }
 else if (flag == '8') 
 { 
  Serial.write('8');

 }
 else if (flag == '9') 
 { 
  Serial.write('9');

 }*/
 if (Serial.available())
  {
    data=Serial.read();
      if(data=='1')
      {
        digitalWrite(LEDr, LOW);
        digitalWrite(LEDg, HIGH); 
        lcd1.setCursor(0, 0);
        lcd1.print("Avion en bon état et à maintenir");
        lcd1.setCursor(0, 1);
        lcd1.print("etat");
        
      }
      else if(data=='0')
      {
        digitalWrite(LEDg, LOW);
        digitalWrite(LEDr, HIGH);  
        lcd1.setCursor(0, 0);
        lcd1.print("Avion en panne");
       
      }
  }
}
