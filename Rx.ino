#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int LED = 9;
int speaker = 8;
int motor = 10;

void setup()
{
 lcd.begin(16,2);
 Serial.begin(9600);
 lcd.setCursor(0,0);
 lcd.print("FLAME DETECTION");
 lcd.setCursor(0,1);
 lcd.print("LAB PNJ");
 delay(500);
 pinMode(LED, OUTPUT);
 pinMode(speaker, OUTPUT);
 pinMode(motor, OUTPUT);
}
void loop() 
{  
 int FLAME_SENSOR_serial_data= Serial.read();;
 if(FLAME_SENSOR_serial_data == 10) 
 { 
  lcd.clear();     
  Serial.print("FLAMESENSOR:");
   Serial.println(FLAME_SENSOR_serial_data);
  lcd.setCursor(0,1);
  lcd.print("FLAME DETECTED");
  digitalWrite(LED, HIGH);
  digitalWrite(motor, HIGH);
  digitalWrite(speaker, HIGH);
  delay(1000);
 } 
 else if(FLAME_SENSOR_serial_data == 20) 
 {
  lcd.clear();
  Serial.print("FLAMESENSOR:");
  Serial.println(FLAME_SENSOR_serial_data);
  lcd.setCursor(0,1);
  lcd.print("NO FLAME");
  digitalWrite(LED, LOW);
  digitalWrite(motor, LOW);
  digitalWrite(speaker, LOW);
  delay(1000);
 }
}
