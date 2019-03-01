int relay1=6;
int relay2=9;
int relay3=5;
int relay4=3;
int echo_front=7;
int trig_front=8;
int echo_left=10;
int trig_left=11;
int echo_right=12;
int trig_right=13;

int pt=0;

long time_front,distance_front,minimum_front,distance_left,minimum_left,time_left,distance_right,minimum_right,time_right;
  
void setup()
{
  Serial.begin(9600);
  pinMode(trig_front,OUTPUT);
  pinMode(echo_front,INPUT);
  pinMode(trig_left,OUTPUT);
  pinMode(echo_left,INPUT);
  pinMode(trig_right,OUTPUT);
  pinMode(echo_right,INPUT);
  
  pinMode(relay1,OUTPUT);
  pinMode(relay2,OUTPUT);
  pinMode(relay3,OUTPUT);
  pinMode(relay4,OUTPUT);
}

void loop() 
{
      
    sensor_front();
    sensor_left();
    sensor_right();
    
    
    
    if(distance_front<=minimum_front)
    {
      stop_robot();
      Serial.println("Robot Stop");
      if((distance_right<=minimum_right)&&(!(distance_left<=minimum_left)))
    {
      reverse_robot();
      Serial.println("Robot Back-1");
      delay(500);
       turn_left();
       pt=-1;
       Serial.println("Robot Left1");
       forward_robot();
    Serial.println("Robot Forward1");
       
    
    }
    else if( (distance_left<=minimum_left)&&(!(distance_right<=minimum_right)))
    {
      reverse_robot();
      
      Serial.println("Robot Back0");
      delay(500);
      turn_right();
      pt=1;
      Serial.println("Robot Right1");
      forward_robot();
    Serial.println("Robot Forward11");
      
    }
    else if((distance_left>=minimum_right)&&(distance_right>=minimum_left))
    {
      reverse_robot();
      
      Serial.println("Robot Back1");
      delay(500);
      turn_left();
      pt=-1;
      Serial.println("Robot Left2");
      forward_robot();
    Serial.println("Robot Forward111");
    }
    else 
    {
      do
      {
      reverse_robot();
      Serial.println("Robot Back2");
      sensor_front();
      sensor_left();
      sensor_right();
      
      }while((distance_left<=minimum_left)&&(distance_right<=minimum_right));
      stop_robot();
      
      goto deadend;
      
    }
    
    
    }
    
    else if((distance_right<=minimum_right)&&(!(distance_left<=minimum_left)))
    {
      reverse_robot();
      Serial.println("Robot Back22");
      turn_left();
      
      pt=-1;
      Serial.println("Robot Left4");
      forward_robot();
    Serial.println("Robot Forward1111");
      
    }
    else if((distance_left<=minimum_left)&&(!(distance_right<=minimum_right)))
    {
      reverse_robot();
      turn_right();
      pt=1;
      Serial.println("Robot Right2");
      forward_robot();
    Serial.println("Robot Forward11111");
      
    }        
    
    else if((distance_left>=minimum_left)&&(distance_right>=minimum_right))
    {
      reverse_robot();
      turn_left();
      forward_robot();
      pt=-1;
      Serial.println("Robot Left5");
      forward_robot();
    Serial.println("Robot Forward1.6");
    }

    else 
    {
    forward_robot();
    Serial.println("Robot Forward2");
    }
    if(0)
    deadend:
    {
      if((distance_left>=minimum_left)&&(distance_right>=minimum_right))
      {
        if(pt==-1)
        {
          turn_left();
          pt=-1;
          Serial.println("Robot Left6");
          forward_robot();
    Serial.println("Robot Forward3");
        }
        else if(pt==1)
        {
          turn_right();
          pt=1;
          Serial.println("Robot Right3");
          forward_robot();
    Serial.println("Robot Forward4");
        }
      }
      else if((distance_left>=minimum_left))
      {
        turn_left();
        pt=-1;
        Serial.println("Robot Left7");
        forward_robot();
    Serial.println("Robot Forward5");
      }
      else if((distance_right>=minimum_right))
      {
        turn_right();
        pt=1;
        Serial.println("Robot Right4");
        forward_robot();
    Serial.println("Robot Forward6");
      }
      
    }
   
    
}

void sensor_front()
{
digitalWrite(trig_front, LOW); 
delayMicroseconds(2);
digitalWrite(trig_front, HIGH); 
delayMicroseconds(20);
digitalWrite(trig_front, LOW);
 
time_front=pulseIn(echo_front,HIGH);
distance_front=time_front/58.2;
Serial.println("distance front=");
Serial.println(distance_front);
delayMicroseconds(10);
minimum_front=15;  
}

void sensor_left()
{
digitalWrite(trig_left, LOW); 
delayMicroseconds(2);
digitalWrite(trig_left, HIGH); 
delayMicroseconds(20);
digitalWrite(trig_left, LOW);
 
time_left=pulseIn(echo_left,HIGH);
distance_left=time_left/58.2;
Serial.println("distance left=");
Serial.println(distance_left);
delayMicroseconds(10);
minimum_left=15;    
}

void sensor_right()
{
digitalWrite(trig_right, LOW); 
delayMicroseconds(2);
digitalWrite(trig_right, HIGH); 
delayMicroseconds(20);
digitalWrite(trig_right, LOW);
 
time_right=pulseIn(echo_right,HIGH);
distance_right=time_right/58.2;
Serial.println("distance right=");
Serial.println(distance_right);
delayMicroseconds(10);
minimum_right=15;    
}



void forward_robot()
{
 analogWrite(relay1,0); 
 analogWrite(relay2,200);
 analogWrite(relay3,0);
 analogWrite(relay4,200);
 delay(1000);
}

void reverse_robot()
{
 analogWrite(relay1,200); 
 analogWrite(relay2,0);
 analogWrite(relay3,200);
 analogWrite(relay4,0);
 delay(500);
}
void stop_robot()
{
 analogWrite(relay1,0); 
 analogWrite(relay2,0);
 analogWrite(relay3,0);
 analogWrite(relay4,0);
 delay(500);
}

void turn_left()
{
 analogWrite(relay1,0); 
 analogWrite(relay2,200);
 analogWrite(relay3,200);
 analogWrite(relay4,0);
 delay(300);
}

void turn_right()
{
 analogWrite(relay1,200); 
 analogWrite(relay2,0);
 analogWrite(relay3,0);
 analogWrite(relay4,200);
 delay(300);
}

