
#include<LiquidCrystal.h>//Declaring the Library ,This library allows you to control liquid crystal displays (LCDs)
#include <LiquidCrystal_I2C.h>   //extension of the LiquidCrystal library. useful when you want to conserve Arduino pins, as it requires fewer connections compared to direct parallel interfacing.
#include <SPI.h>//The SPI library provides functions to configure and communicate over the SPI bus.
#include <MFRC522.h>// This library allows you to interface with the MFRC522 module, enabling your Arduino to read RFID tags and cards. 
LiquidCrystal_I2C lcd(0x27,16,2); //lcd is an object lcd is connected using i2c communication with an address 0x27 address
#define SS_PIN 10 //RX slave select ,ss_pin used for SPI communication  (contact with multiple device)
#define RST_PIN 9  //reset the RfID MODULE SET TO PIN 9 ,WHEN UC Startup and when we want to restart communication with the module
MFRC522 mfrc522(SS_PIN, RST_PIN); // Create MFRC522 instance.
#define in 2  // Defining In Sensor, ;define  is used to assign symbolic names
#define out 3 // Defining Out Sensor
#define bulb 4 //Defining Bulb(Relay)
byte card_ID[4];
byte card_ID1[4];//card UID size 4byte
byte Name1[4]={0x74 ,0x68 ,0x71 ,0x41};//first UID card
byte Name2[4]={0x03 ,0xDA ,0x76 ,0x50};//second UID card

//if you want the arduino to detect the cards only once
int NumbCard[2];//this array content the number of cards. in my case i have just two cards.
int j=0;        
int const RedLed=6;
int const GreenLed=5;
String Name;//user name
long Number;//user number
//--------------------------------------
String MasterTag = Name;  // REPLACE this Tag ID with your Tag ID!!!
String tagID = "";
int n ;//The number of card you want to detect (optional)  
int count = 0; // Declaring count Value
void setup()
{
  //rf id
  lcd.begin(16,2);
  lcd.backlight();
Serial.begin(9600); // Initialize serial communications with the PC
  SPI.begin();  // Init SPI bus
  mfrc522.PCD_Init(); // Init MFRC522 card
  
  Serial.println("CLEARSHEET");                 // clears starting at row 1
  Serial.println("LABEL,DATE,TIME,NAME, REG NO.");// make four columns (Date,Time,[Name:"user name"]line 48 & 52,[Number:"user number"]line 49 & 53)is used to send a string of characters over the serial port from an Arduino to a connected device, such as a computer running the Arduino IDE or a serial monitor application.

  pinMode(RedLed,OUTPUT);
  pinMode(GreenLed,OUTPUT);
  //icd

  
   lcd.clear();

   lcd.print("Nobody In Room");
   lcd.setCursor(0, 1);
   lcd.print("Light is Off");
   delay(2000);
    lcd.clear();
  lcd.print(" Access Control ");
  lcd.setCursor(0, 1);
  lcd.print("Scan Your Card>>");
  delay(1000); // Delay of 1 seconds
  pinMode(in,INPUT); // Setting up In Sensor as INPUT 
  pinMode(out,INPUT); // Setting up Out Sensor as INPUT
  pinMode(bulb,OUTPUT); // Setting up Bulb(Relay) pin as OUTPUT  
  
}
void loop()
{
   while (getID()) 
  {
    lcd.clear();
    lcd.setCursor(0, 0);

     for (byte i = 0; i < mfrc522.uid.size; i++) {
     card_ID1[i]=mfrc522.uid.uidByte[i];

       if(card_ID1[i]==Name1[i]){

 if(NumbCard[j] == 1){//to check if the card already detect
    delay(1000);
    Serial.println("Already Exist");
      lcd.clear();
//     delay(1000);
//lcd.setCursor(0, 1);
  
//   lcd.println("Already Exist");
//    delay(1000);
    lcd.print(" Access Control ");
  lcd.setCursor(0, 1);
  lcd.print("Scan Your Card>>");
//      lcd.clear();
     break;
 }
       lcd.print(" Access Granted!");
       digitalWrite(RedLed,HIGH); 
       digitalWrite(GreenLed,LOW);
      // You can write any code here like opening doors, switching on a relay, lighting up an LED, or anything else you can think of.
 
       Name="KRISHNA RAJ";//user name
      Number=20224081;//user number
      j=0;//first number in the NumbCard array : NumbCard[j]  
       NumbCard[j] = 1;//put 1 in the NumbCard array : NumbCard[j]={1,1} to let the arduino know if the card was detecting 
      n++;//(optional)
      Serial.print("DATA,DATE,TIME," + Name);//send the Name to excel
      Serial.print(",");
      Serial.println(Number); //send the Number to excel
      digitalWrite(GreenLed,HIGH);
      digitalWrite(RedLed,LOW);
    }
    else if(card_ID1[i]==Name2[i]){

 if(NumbCard[j+1] == 1){//to check if the card already detect
//      //if you want to use LCD
// delay(1000);
     Serial.println("Already Exist");
//    lcd.print("Already Exist");
//      lcd.clear();
         delay(1000);
         lcd.clear();
  lcd.print(" Access Control ");
  lcd.setCursor(0, 1);
  lcd.print("Scan Your Card>>");
     break;
 }
       lcd.print(" Access Granted!");
       digitalWrite(RedLed,HIGH); 
       digitalWrite(GreenLed,LOW);
        Name="MD TALHA";//user name
       Number=20224095;//user number
       //Second number in the NumbCard array : NumbCard[j]
        NumbCard[j+1] = 1;//put 1 in the NumbCard array : NumbCard[j]={1,1} to let the arduino know if the card was detecting 
      n++;//(optional)
      Serial.print("DATA,DATE,TIME," + Name);//send the Name to excel
      Serial.print(",");
      Serial.println(Number); //send the Number to excel
      digitalWrite(GreenLed,HIGH);
      digitalWrite(RedLed,LOW);
    }
    else
    {
       digitalWrite(GreenLed,HIGH); 
       digitalWrite(RedLed,LOW);  
      lcd.print(" Access Denied!");
       
    }
    delay(1000);
     digitalWrite(GreenLed,LOW); 
     digitalWrite(RedLed,LOW);
    lcd.clear();
    lcd.print("Person in room:");
    lcd.setCursor(0, 1);
    lcd.print(count);
    lcd.clear();
//   delay(1000);
     }
//     delay(1000);
  }
  
  //icl
//lcd.begin(16,2);
//   Serial.begin(9600);
//     lcd.clear();
    lcd.setCursor(0, 0);
  int in_value = digitalRead(in); // Setting Variables & Reading Values from In Sensor
  int out_value = digitalRead(out); // Setting Variables & Reading Values from Out Sensor
  
  if(in_value == LOW)
  {
    count++;
     digitalWrite(bulb,HIGH);
     lcd.clear();
    lcd.print("Person In Room:");
    lcd.setCursor(0,1);
    lcd.print(count);
    
    delay(1000);
  }                                                        // Conditions
  
  if(out_value == LOW)
  {
  if(count>0){
    count--;
    
   lcd.clear();
    lcd.print("Person In Room:");
    lcd.setCursor(0,1);
    lcd.print(count);
    delay(1000);
  }                                                        // Conditions
 if(count<=0)
  {
    lcd.clear();
    digitalWrite(bulb,LOW);
    lcd.clear();
    lcd.print("Nobody In Room");
    lcd.setCursor(0,1);
    lcd.print("Light is Off");
    delay(200);
  }                                                       // Conditions
  
  else
  {
    digitalWrite(bulb,HIGH);    
  } 
//-------------
  //Wait until new tag is available

}
}
boolean getID() 
{
  // Getting ready for Reading PICCs
  if ( ! mfrc522.PICC_IsNewCardPresent()) { //If a new PICC placed to RFID reader continue
  return false;
  }
  if ( ! mfrc522.PICC_ReadCardSerial()) { //Since a PICC placed get Serial and continue
  return false;
  }
  tagID = "";
  for ( uint8_t i = 0; i < 4; i++) { // The MIFARE PICCs that we use have 4 byte UID
  //readCard[i] = mfrc522.uid.uidByte[i];
  tagID.concat(String(mfrc522.uid.uidByte[i], HEX)); // Adds the 4 bytes in a single String variable
  }
  tagID.toUpperCase();
  mfrc522.PICC_HaltA(); // Stop reading
  return true;
}
 




      

  


   
 
