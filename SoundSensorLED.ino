//Setting our variables
const int LED = 13; //LED connected to pin 13 on Arduino
const int sound = A0; //sound sensor connected to analog pin A0 on Arduino
const int threshold = 100; //this can be adjusted

void setup() 
{
  Serial.begin(9600);
  pinMode(LED,OUTPUT); //LED is made output
  pinMode(sound,INPUT); //soundsensor is set as input
}
void loop() 
{
  int soundsens = analogRead(sound); //analogRead reads analog data from sensor, which is stored in variable soundsens
  if (soundsens >= threshold) 
  {
    digitalWrite(LED,HIGH); //turns led on
    delay(1000);
  }
  else
  {
    digitalWrite(LED,LOW); //led turns off
  }
}
