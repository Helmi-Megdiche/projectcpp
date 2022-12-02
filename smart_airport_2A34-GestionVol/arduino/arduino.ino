#define echoPin 2 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 3 //attach pin D3 Arduino to pin Trig of HC-SR04
#define echoPin2 4 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin2 5 //attach pin D3 Arduino to pin Trig of HC-SR04
#include <Servo.h>  // on inclut la bibliothèque servo
//#define ledg 7
//#define ledr 6
#define ledg2 8
#define SS_PIN 10
#define RST_PIN 9
#include <Wire.h>
#include <LiquidCrystal_I2C.h> 
#include <SPI.h>
#include <MFRC522.h>
LiquidCrystal_I2C lcd1(0x27, 16, 2);
LiquidCrystal_I2C lcd2(0x27, 16, 2);
Servo servoMoteur; 
Servo servoMoteur2;// on crée un objet servo appelé servoMoteur
MFRC522 rfid(SS_PIN, RST_PIN); // Instance of the class
int tot =0;
char data;
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement
long duration2; // variable for the duration of sound wave travel
int distance2; // variable for the distance measurement
byte Count_acces=0; 
byte CodeVerif=0; 
byte Code_Acces[4]={0xD4, 0x46, 0x48, 0x1E};
byte nuidPICC[4]; 



void setup() {
   pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); 
  pinMode(trigPin2, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin2, INPUT); 
//  pinMode(ledg, OUTPUT);
//  pinMode(ledr,OUTPUT);  
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
  Serial.println("with Arduino UNO R3");
   servoMoteur.attach(7);
   servoMoteur2.attach(6);  
   lcd1.init(); // initialisation de l'afficheur
   lcd2.init();  
   // Init SPI bus
  SPI.begin(); 

  // Init MFRC522 
  rfid.PCD_Init(); 

}

void loop() {
  //      digitalWrite(ledr, HIGH);
      lcd1.backlight();
       lcd2.backlight();
    /*  lcd.setCursor(0,0);
  Serial.print(" spot = ");
  Serial.println(tot);*/

       // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
 /* Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");*/




 // digitalWrite(ledr2, HIGH);
    /*  lcd.setCursor(0,0);
  Serial.print(" spot = ");
  Serial.println(tot);*/

       // Clears the trigPin condition
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration2 = pulseIn(echoPin2, HIGH);
  // Calculating the distance
  distance2 = duration2 * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
 /* Serial.print("Distance2: ");
  Serial.print(distance2);
  Serial.println(" cm");*/


 if ( (distance <= 10)&&(distance != 0))
  {
      if((tot>=0)&&(tot<3))
  {
//    digitalWrite(ledg, HIGH);
   // digitalWrite(ledr, LOW);
  //  servoMoteur.write(0);
 // delay(1000);  // pause de 1 seconde
  
  // on déplace le servo à la position 90º
  servoMoteur.write(90);
  delay(5000);  // pause 5 seconde
  
  servoMoteur.write(-90);
  delay(1000);  // pause 1 seconde
 // digitalWrite(ledg, LOW);
  tot=tot + 1;// transmit to device #9
 // stop transmitting
  delay(200);
    
  lcd1.setCursor(0, 0);
  lcd1.print("spot = ");
  lcd1.println(tot);
   lcd1.setCursor(2, 0); 
    //lcd.print(" Welcome ");
    
  }
  else 
  {
    lcd1.setCursor(0, 0);
  lcd1.print("plein");
  }
  }
  
if ( (distance2 <= 10)&&(distance2 != 0))
  {
    if(tot >0)
    {
      if ( !rfid.PICC_IsNewCardPresent())
    return;

  // Vérifier la présence d'un nouveau badge 
  if ( !rfid.PICC_ReadCardSerial())
    return;
  // Afffichage 
  Serial.println(F("Un badge est détecté"));

  // Enregistrer l’ID du badge (4 octets) 
  for (byte i = 0; i < 4; i++)
  {
    nuidPICC[i] = rfid.uid.uidByte[i];
  }
  for (byte i = 0; i < 4; i++) {
    Serial.write(nuidPICC[i]);
    Serial.print(nuidPICC[i]);
  }
     if (Serial.available())
  {
    data=Serial.read();
      if(data=='1')
      {
         digitalWrite(ledg2, HIGH);
   // digitalWrite(ledr2, LOW);
 //   servoMoteur2.write(0);
 // delay(1000);  // pause de 1 seconde
  
  // on déplace le servo à la position 90º
  servoMoteur2.write(90);
  delay(5000);  // pause 5 seconde
  
  servoMoteur2.write(-90);
  delay(1000);  // pause 1 seconde
  digitalWrite(ledg2, LOW);
    tot=tot - 1;
  lcd2.setCursor(0, 0);
  lcd2.print("spot = ");  
  lcd2.println(tot);
      }
      else
      {
        lcd2.setCursor(0, 0);
  lcd2.print("solde insufusion");
      }
    
  }
}
else
{
  lcd2.setCursor(0, 0);
  lcd2.print("pas de voiture");
}
}
// Re-Init RFID
  rfid.PICC_HaltA(); // Halt PICC
  rfid.PCD_StopCrypto1(); // Stop encryption on PCD
}
