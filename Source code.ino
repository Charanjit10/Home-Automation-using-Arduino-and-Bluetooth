#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 10, 11, 12, 13);
#define b1 4
#define b2 5
#define b3 6

int tx=1;
int rx=0;
char inSerial[15];

int val =200;
void setup(){
Serial.begin(9600);
pinMode(b1, OUTPUT);
pinMode(b2, OUTPUT);
pinMode(b3, OUTPUT);
pinMode(2, OUTPUT);
pinMode(3, OUTPUT);
pinMode(tx, OUTPUT);
pinMode(rx, INPUT);
digitalWrite(b1, LOW);
digitalWrite(b2, LOW);
digitalWrite(b3, LOW);
analogWrite(2,0);
analogWrite(3,0);
lcd.begin(16, 2);
lcd.clear();
lcd.print("esd lab cbit");
lcd.setCursor(0,1); 
lcd.print("ece2 90,106,87");
delay(2000);
lcd.clear();
lcd.print("sorry mam for ");
lcd.setCursor(0,1);
lcd.print("late submission");
delay(2000);
lcd.clear();
lcd.print("please consider ");
lcd.setCursor(0,1);
lcd.print("our project");
delay(2000);
lcd.clear();
lcd.print("HOME AUTOMATION ");
lcd.setCursor(0,1);
lcd.print("USING BLUETOOTH");
delay(2000);
lcd.clear();
lcd.print("1. Bulb  b1");
lcd.setCursor(0,1);
lcd.print("2. Bulb  b2");
delay(2000);
lcd.clear();
lcd.print("3. Bulb  b3");
lcd.setCursor(0,1);
lcd.print("4. Fan  f1");
delay(2000);
lcd.clear();
lcd.print(" 1  2  3  4");
lcd.setCursor(0,1); 
lcd.print("OFF ");
lcd.setCursor(4,1); 
lcd.print("OFF "); 
lcd.setCursor(8,1); 
lcd.print("OFF "); 
lcd.setCursor(12,1); 
lcd.print("OFF ");

}

void loop(){
int i=0;
int m=0;
delay(500); 
if (Serial.available() > 0) { 
while (Serial.available() > 0) {
inSerial[i]=Serial.read(); 
i++; 
}
inSerial[i]='\0';
Check_Protocol(inSerial);
}} 



void Check_Protocol(char inStr[]){ 
int i=0;
int m=0;
Serial.println(inStr);

if(!strcmp(inStr,"all on")){ 
digitalWrite(b1, HIGH);
digitalWrite(b2, HIGH);
digitalWrite(b3, HIGH);
analogWrite(2,val);
analogWrite(3,0);
Serial.println("ALL ON");
lcd.setCursor(0,1); 
lcd.print("ON ");
lcd.setCursor(4,1); 
lcd.print("ON "); 
lcd.setCursor(8,1); 
lcd.print("ON "); 
lcd.setCursor(12,1); 
lcd.print("ON ");
for(m=0;m<11;m++){
inStr[m]=0;}
i=0;}

if(!strcmp(inStr,"all off")){ 
digitalWrite(b1, LOW);
digitalWrite(b2, LOW);
digitalWrite(b3, LOW);
analogWrite(2,0);
analogWrite(3,0);
Serial.println("ALL OFF");

lcd.setCursor(0,1); 
lcd.print("OFF ");
lcd.setCursor(4,1); 
lcd.print("OFF "); 
lcd.setCursor(8,1); 
lcd.print("OFF ");
lcd.setCursor(12,1); 
lcd.print("OFF "); 
for(m=0;m<11;m++){
inStr[m]=0;}
i=0;}

if(!strcmp(inStr,"b1 on")){ 
digitalWrite(b1, HIGH);
Serial.println("b1 ON");
lcd.setCursor(0,1); 
lcd.print("ON ");
for(m=0;m<11;m++){
inStr[m]=0;}
i=0;}

if(!strcmp(inStr,"b1 off")){ 
digitalWrite(b1, LOW);
Serial.println("b1 OFF");
lcd.setCursor(0,1); 
lcd.print("OFF ");
for(m=0;m<11;m++){
inStr[m]=0;}
i=0;} 

if(!strcmp(inStr,"b2 on")){ 

digitalWrite(b2, HIGH);
Serial.println("b2 ON");
lcd.setCursor(4,1); 
lcd.print("ON "); 
for(m=0;m<11;m++){
inStr[m]=0;}
i=0;}

if(!strcmp(inStr,"b2 off")){ 

digitalWrite(b2, LOW);
Serial.println("b2 OFF");
lcd.setCursor(4,1); 
lcd.print("OFF "); 
for(m=0;m<11;m++){
inStr[m]=0;}
i=0;}
if(!strcmp(inStr,"b3 on")){ 

digitalWrite(b3, HIGH);
Serial.println("b3 ON");
lcd.setCursor(8,1); 
lcd.print("ON ");
for(m=0;m<11;m++){
inStr[m]=0;}
i=0;}

if(!strcmp(inStr,"b3 off")){ 

digitalWrite(b3, LOW);
Serial.println("b3 OFF");
lcd.setCursor(8,1); 
lcd.print("OFF ");
for(m=0;m<11;m++){
inStr[m]=0;}
i=0;}
if(!strcmp(inStr,"f1 on")){ 
analogWrite(2,val);
analogWrite(3,0);

Serial.println("f1 ON");
lcd.setCursor(12,1); 
lcd.print("ON ");
for(m=0;m<11;m++){
inStr[m]=0;}
i=0;}

if(!strcmp(inStr,"f1 off")){ 
analogWrite(2,0);
analogWrite(3,0);

Serial.println("f1 OFF");
lcd.setCursor(12,1); 
lcd.print("OFF ");
for(m=0;m<11;m++){
inStr[m]=0;}
i=0;}

else{
for(m=0;m<11;m++){
inStr[m]=0;
}
i=0;

}}
