#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0X27, 16, 2);
#include <Servo.h>
#define SERVO_PIN 9
Servo gServo;

int sensorOpen = 7;
int sensorClose = 4;
int number = 5;  
int flag1 = 0;   
int flag2 = 0;   
int pre_open = 1;
int pre_close = 1;

void setup() {
  Serial.begin(9600);
  pinMode(sensorOpen, INPUT);
  pinMode(sensorClose, INPUT);
  gServo.attach(SERVO_PIN);
  lcd.init();
  lcd.backlight();
  lcd.clear();  
}

void loop() {
  lcd.setCursor(1, 0);
  lcd.print("Welcome to UTC");
  int temp1 = digitalRead(sensorClose);  
  int temp = digitalRead(sensorOpen);   
  
  if (temp != pre_open){
      if (temp == 0 && flag1 == 0) {
        if (number > 0) {
          flag1 = 1;
          if (flag2 == 0) {
            gServo.write(90);
            number = number - 1;
          }
        } else {
          lcd.clear();
          lcd.setCursor(0, 1);
          lcd.print("Sorry, It's Full");
          delay(1500);
          lcd.clear();
          gServo.write(0);
        }
      }
      pre_open = temp;
    }

  if (temp1 != pre_close) {
    if (temp1 == 0 && flag2 == 0) {
      flag2 = 1;
      if (flag1 == 0) {
        gServo.write(90);
        number = number + 1;
        if (number > 5) {   
          number = 5;
        }
      }
    }
    pre_close = temp1;
  }

    if (flag1 == 1 && flag2 == 1) {
    gServo.write(0);
    flag1 = 0, flag2 = 0;
  }


  lcd.setCursor(0, 1);
  lcd.print("So cho trong:");
  lcd.setCursor(14, 1);
  lcd.print(number);  
}
