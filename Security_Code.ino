#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
 
#define RightMotorSpeed D1 // D1 <-> IN1
#define RightMotorDir D3  // D3 <-> IN2
#define LeftMotorSpeed D2  // D2 <-> IN3
#define LeftMotorDir D4  // D4 <-> IN4
 
char auth[] = "***************************";//use your key in blynk app
char ssid[] = "MyCAT4G";//wifi
char pass[] = "******************";//wifi password
 
void setup()
{
 Serial.begin(9600);
 Blynk.begin(auth, ssid, pass);
 
 pinMode(RightMotorSpeed, OUTPUT);
 pinMode(RightMotorDir, OUTPUT);
 pinMode(LeftMotorSpeed, OUTPUT);
 pinMode(LeftMotorDir, OUTPUT);
}
 
void loop()
{
 Blynk.run();
}
 
void halt() 
{
 analogWrite(RightMotorSpeed, LOW);
 analogWrite(LeftMotorSpeed, LOW);
}
 
void forward()
{
 analogWrite(RightMotorDir, HIGH);
 analogWrite(LeftMotorDir, HIGH);
 analogWrite(RightMotorSpeed, LOW);
 analogWrite(LeftMotorSpeed, LOW);
}
 
void reverse()
{
 analogWrite(RightMotorDir, LOW);
 analogWrite(LeftMotorDir, LOW);
 analogWrite(RightMotorSpeed, HIGH);
 analogWrite(LeftMotorSpeed, HIGH);
}
 
void right()
{
 analogWrite(RightMotorDir, LOW);
 analogWrite(LeftMotorDir, HIGH);
 analogWrite(RightMotorSpeed, HIGH);
 analogWrite(LeftMotorSpeed, HIGH);
}
 
void left()
{
 analogWrite(RightMotorDir, HIGH);
 analogWrite(LeftMotorDir, LOW);
 analogWrite(RightMotorSpeed, HIGH);
 analogWrite(LeftMotorSpeed, HIGH);
}
 
BLYNK_WRITE(D1)
{
 if (param[0])
 forward();
 else
 halt();
}
 
BLYNK_WRITE(D2)
{
 if (param[0])
 reverse();
 else
 halt();
}
 
BLYNK_WRITE(D3)
{
 if (param[0])
 right();
 else
 halt();
}
 
BLYNK_WRITE(D4)
{
 if (param[0])
 left();
 else
 halt();
}
