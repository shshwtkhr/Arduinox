int relay1=9;
int relay2=6;

int relay3=5;
int relay4=3;

long time_front,distance_front,minimum_front,distance_left,minimum_left,time_left,distance_right,minimum_right,time_right;

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
  forward_robot();
}
void forward_robot()
{
 analogWrite(relay1,0); 
 analogWrite(relay2,255);
 
 analogWrite(relay3,0);
 analogWrite(relay4,255);
 delay(1000);
}


