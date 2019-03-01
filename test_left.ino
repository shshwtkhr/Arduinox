int relay1=6;
int relay2=9;
int relay3=5;
int relay4=3;
void setup()
{
  Serial.begin(9600);
  pinMode(relay1,OUTPUT);
  pinMode(relay2,OUTPUT);
  pinMode(relay3,OUTPUT);
  pinMode(relay4,OUTPUT);

}

void loop() 
{
  turn_left();


}
void turn_left()
{
 analogWrite(relay1,0); 
 analogWrite(relay2,255);
 analogWrite(relay3,255);
 analogWrite(relay4,0);
 delay(4);
}
