#include <WiFi.h>
#include<HTTPClient.h>
const char* ssid="";
const char* password="";

String servername="http://";
#define buzzer 15
#define trig 17
#define echo 19

String status;
float distance;
long duration;
void setup(){
  Serial.begin(9600);
  WiFi.begin(ssid,password);
  Serial.print("connecting");
  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(500);

  }
  Serial.print("");
  Serial.print("connected");

  pinMode(buzzer,OUTPUT);
    pinMode(trig,OUTPUT);
      pinMode(echo,INPUT);


}
void loop(){
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);

  duration=pulseIn(echo,HIGH);
  distance=duration*0.034/2/100;
  Serial.print("distance=");
  Serial.print(distance);
  Serial.println("m");
  
  digitalWrite(buzzer,LOW);
  
  if(distance <= 4 && distance >0.07){
      
  digitalWrite(buzzer,HIGH);
  status="DANGER_INCOMING";
   Serial.print("status=");
  Serial.println(status);
  }
  else{
     digitalWrite(buzzer,LOW);
     status="SAFE";
   Serial.print("status=");
  Serial.println(status);

  }
  if(WiFi.status() == WL_CONNECTED){
    HTTPClient http;
    String url=servername+"?distance="+String(distance)+"&status="+status;
    http.begin(url);
    int responsecode=http.GET();
     Serial.print("responsecode=");
  Serial.println(responsecode);
  http.end();

  }

  delay(2000);
}
