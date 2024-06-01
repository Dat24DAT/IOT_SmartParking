#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0X27, 16, 2);
#define BLYNK_TEMPLATE_ID "TMPL6uQhcd9Vl"
#define BLYNK_TEMPLATE_NAME "SMART PARKING IOT"
#define BLYNK_AUTH_TOKEN "zGXTh7A8LGZVi8vESARNalmOnrUZQKxn"
#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiClientSecure.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "Thanh Dat";
char pass[] = "07091975";
BlynkTimer timer;

int vitri_1 = 19;
int vitri_2 = 18;
int vitri_3 = 5;
int vitri_4 = 4;
int vitri_5 = 15;

uint8_t pre_vt1 = 1;
uint8_t pre_vt2 = 1;
uint8_t pre_vt3 = 1;
uint8_t pre_vt4 = 1;
uint8_t pre_vt5 = 1;



int count = 0;

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  pinMode(vitri_1, INPUT);
  pinMode(vitri_2, INPUT);
  pinMode(vitri_3, INPUT);
  pinMode(vitri_4, INPUT);
  pinMode(vitri_5, INPUT);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop() {
  int slot1 = digitalRead(vitri_1);
  int slot2 = digitalRead(vitri_2);
  int slot3 = digitalRead(vitri_3);
  int slot4 = digitalRead(vitri_4);
  int slot5 = digitalRead(vitri_5);

  bool isChanged_slot1 = false;
  bool isChanged_slot2 = false;
  bool isChanged_slot3 = false;
  bool isChanged_slot4 = false;
  bool isChanged_slot5 = false;


  if (slot1 != pre_vt1 && (slot1 == HIGH || slot1 == LOW)) {
    pre_vt1 = slot1;
    isChanged_slot1 = true;
    if (slot1 == HIGH) count--;
    else count++;
  }
  if (slot2 != pre_vt2 && (slot2 == HIGH || slot2 == LOW)) {
    pre_vt2 = slot2;
    isChanged_slot2 = true;
    if (slot2 == HIGH) count--;
    else count++;
  }
  if (slot3 != pre_vt3 && (slot3 == HIGH || slot3 == LOW)) {
    pre_vt3 = slot3;
    isChanged_slot3 = true;
    if (slot3 == HIGH) count--;
    else count++;
  }
  if (slot4 != pre_vt4 && (slot4 == HIGH || slot4 == LOW)) {
    pre_vt4 = slot4;
    isChanged_slot4 = true;
    if (slot4 == HIGH) count--;
    else count++;
  }
  if (slot5 != pre_vt5 && (slot5 == HIGH || slot5 == LOW)) {
    pre_vt5 = slot5;
    isChanged_slot5 = true;
    if (slot5 == HIGH) count--;
    else count++;
  }
  if (isChanged_slot1) {
    Blynk.virtualWrite(V0, slot1);
  }
  if (isChanged_slot2) {
    Blynk.virtualWrite(V1, slot2);
  }
  if (isChanged_slot3) {
    Blynk.virtualWrite(V2, slot3);
  }
  if (isChanged_slot4) {
    Blynk.virtualWrite(V3, slot4);
  }
  if (isChanged_slot5) {
    Blynk.virtualWrite(V4, slot5);
  }

  Serial.print(slot1);
  Serial.print(" ");
  Serial.print(slot2);
  Serial.print(" ");
  Serial.print(slot3);
  Serial.print(" ");
  Serial.print(slot4);
  Serial.print(" ");
  Serial.print(slot5);
  Serial.print(" ,");
  Serial.print(count);
  Serial.println(" ");


  lcd.setCursor(1, 0);
  lcd.print("Welcome to UTC");
  lcd.setCursor(0, 1);
  lcd.print("CAR NUMBER: ");
  lcd.setCursor(12, 1);
  lcd.print(" ");
  lcd.setCursor(12, 1);
  lcd.print(count);

  delay(1000);

  Blynk.run();
  timer.run();
}
