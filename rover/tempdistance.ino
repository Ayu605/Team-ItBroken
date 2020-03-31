#include <DHT.h>
#include <LiquidCrystal.h>

#define trigger 18
#define echo 19

DHT dht(2, DHT11);
LiquidCrystal lcd(13,12,11,6,5,4,3);

float time=0,distance=0;

void setup() {
  dht.begin();
  lcd.begin(16, 2);
  pinMode(trigger,OUTPUT);
  pinMode(echo,INPUT);
}

void loop() {
  float t = dht.readTemperature();
  float h = dht.readHumidity();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("T: ");
  lcd.print(t, 1);
  lcd.print(" C ");
  lcd.setCursor(9, 0);
  lcd.print("H: ");
  lcd.print(h, 0);
  lcd.print(" % ");
  lcd.setCursor(0, 1);
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  time = pulseIn(echo, HIGH);
  distance = time * 340 / 20000;
  lcd.print("Distance:");
  lcd.print(distance);
  lcd.print("cm");
  delay(2000);
}
