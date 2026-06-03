#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid="CANALBOX-6938-2G";
const char* password="gPAQQF2EHsQ7";

String servername="http://192.168.1.69/seno/save.php";

#define trig 26
#define echo 25
#define green 14
#define red 27
#define yellow 32

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

pinMode(red,OUTPUT);
pinMode(yellow,OUTPUT);
pinMode(green,OUTPUT);
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
distance=duration*0.034/2;

Serial.print("distance=");
Serial.print(distance);
Serial.println("cm");


digitalWrite(red,LOW);
digitalWrite(yellow,LOW);
digitalWrite(green,LOW);

if(distance<20){
  digitalWrite(red,HIGH);
digitalWrite(yellow,LOW);
digitalWrite(green,LOW);
status="DANGER";
Serial.print("status-=");
Serial.println(status);


}
else if(distance >20 && distance<50){
    digitalWrite(red,LOW);
digitalWrite(yellow,HIGH);
digitalWrite(green,LOW);
status="WARNING";
Serial.print("status-=");
Serial.println(status);
}
else{
  digitalWrite(red,LOW);
digitalWrite(yellow,LOW);
digitalWrite(green,HIGH);
status="SAFE";
Serial.print("status-=");
Serial.println(status);
}
if(WiFi.status() == WL_CONNECTED){
  HTTPClient http;
  String url= servername+"?distance="+String(distance)+"&status"+status;
  http.begin(url);
  int responsecode=http.GET();
  Serial.print("responsecode=");
Serial.println(responsecode);

  http.end();
}
delay(2000);
}
