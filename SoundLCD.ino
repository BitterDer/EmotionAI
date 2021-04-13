//Setting up LCD screen
#include <Wire.h>
#include <LiquidCrystal_I2C.h> //library for LCD

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

//Setting our variables
const int LED = 13; //LED connected to pin 13 on Arduino
const int sound = A0; //sound sensor connected to analog pin A0 on Arduino
const int threshold = 200; //this can be adjusted
int soundsens = 0;

void setup() 
{
  Serial.begin(9600);
  pinMode(LED,OUTPUT); //LED is made output
  pinMode(sound,INPUT); //soundsensor is set as input
  lcd.begin(16,2);
  lcd.backlight();

  //LCD prints splash screen
  lcd.setCursor(4,0);
  lcd.print("Cohort 13");
  lcd.setCursor(4,1);
  lcd.print("eMotionAI");
  delay(1000);
  lcd.clear();
}
void loop() 
{
  soundsens = analogRead(sound); //analogRead reads analog data from sensor, which is stored in variable soundsens
  if (soundsens >= threshold) 
  {
    digitalWrite(LED,HIGH); //turns led on
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.println("Detected: Anger "); //Tells LCD to print
  }
  else
  {
    digitalWrite(LED,LOW); //led turns off
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.println("Detected: normal"); //Tells LCD to print 
  }
    delay(500);
}
