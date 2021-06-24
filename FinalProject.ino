int trig1 = 3;
int echo1 = 2;
int trig2 = 6;
int echo2 = 7;
int buzzer = 4;
int LED = 8;
int PR=A1;
float duration1;
float distance1;
float duration2;
float distance2;


void setup() 
{
  Serial.begin(9600);
  pinMode(echo1,INPUT);
  pinMode(trig1,OUTPUT);
  pinMode(echo2,INPUT);
  pinMode(trig2,OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(LED, OUTPUT);
}

void loop() 
{
  int cds_data = analogRead(PR);
  digitalWrite(trig1,LOW);
  delayMicroseconds(10);
  digitalWrite(trig2,HIGH);
  duration1 = pulseIn(echo1,HIGH);
  delay(1);
  digitalWrite(trig1,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig2,LOW);
  duration2 = pulseIn(echo2,HIGH);
  delay(1);
  delayMicroseconds(10);
  distance1 = ((34000*duration1)/1000000)/2;
  distance2 = ((34000*duration2)/1000000)/2;
  Serial.print(distance1);
  Serial.println("cm");
  Serial.print(distance2);
  Serial.println("cm");
  Serial.println(String("조도 = ")+ cds_data);

  if(distance1 < 13 && distance2 <13){
    
  if(distance1 < 13 && distance1 > 10 && cds_data >1000) 
  {
    analogWrite(LED,255-(distance1*12));
    
    tone(buzzer,1000,100);
    delay(1000);
    tone(buzzer,1000,100);
    delay(100);
  }
   else if(distance1 < 10 && cds_data >1000)
  {
    analogWrite(LED,255-(distance1*12));
    
    tone(buzzer,1000,100);
    delay(100);
    tone(buzzer,1000,100);
    delay(100);
  }
  else if(distance1 < 13 && distance1 > 10 && cds_data < 1000) 
  {
    tone(buzzer,1000,100);
    delay(1000);
    tone(buzzer,1000,100);
    delay(100);
  }
  else if(distance1 < 10 && cds_data < 1000) 
  {
    tone(buzzer,1000,100);
    delay(100);
    tone(buzzer,1000,100);
    delay(100);
  }
   else
  {
    digitalWrite(LED,LOW);
  }


  
  if(distance2 < 13 && distance2 > 10 && cds_data >1000) 
  {
    analogWrite(LED,255-(distance2*12));
    
    tone(buzzer,1000,100);
    delay(1000);
    tone(buzzer,1000,100);
    delay(100);
  }
   else if(distance2 < 10 && cds_data >1000) 
  {
    analogWrite(LED,255-(distance2*12));
    
    tone(buzzer,1000,100);
    delay(100);
    tone(buzzer,1000,100);
    delay(100);
  }
  else if(distance2 < 13 && distance2 > 10 && cds_data < 1000) 
  {
    tone(buzzer,1000,100);
    delay(1000);
    tone(buzzer,1000,100);
    delay(100);
  }
  else if(distance2 < 10 && cds_data < 1000) 
  {
    tone(buzzer,1000,100);
    delay(100);
    tone(buzzer,1000,100);
    delay(100);
  }
  else
  {
    digitalWrite(LED,LOW);
  }
 }
 else{
    digitalWrite(LED,LOW);
  }

  if(cds_data<1000){
    digitalWrite(LED,LOW);
    }
  delay(400);
}
