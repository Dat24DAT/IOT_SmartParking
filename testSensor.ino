
// Include Libraries
#include "Arduino.h"

// Pin Definitions
#define IROBJAVOID_1_PIN_OUT	5
#define IROBJAVOID_2_PIN_OUT	4
#define IROBJAVOID_3_PIN_OUT	0
#define IROBJAVOID_4_PIN_OUT	2
#define IROBJAVOID_5_PIN_OUT	14


// define vars for testing menu
const int timeout = 10000;       //define timeout of 10 sec
char menuOption = 0;
long time0;

// Setup the essentials for your circuit to work. It runs first every time your circuit is powered with electricity.
void setup() 
{
    // Setup Serial which is useful for debugging
    // Use the Serial Monitor to view printed messages
    Serial.begin(9600);
    while (!Serial) ; // wait for serial port to connect. Needed for native USB
    Serial.println("start");
    
    pinMode(, INPUT);
    pinMode(, INPUT);
    pinMode(, INPUT);
    pinMode(, INPUT);
    pinMode(, INPUT);
    menuOption = menu();
    
}

void loop() 
{
    
    //IR Obstacle Avoidance Sensor
    //Read IR obstacle Sensor. irObjAvoid_1Var will be '1' if an Obstacle was detected
    if(menuOption == '1') {
     	#1 - Test Code
    	bool irObjAvoid_1Var = !digitalRead();
    	Serial.print(F("ObjAvoid: ")); Serial.println(irObjAvoid_1Var);
    }
    else if(menuOption == '2') {
	#2 - Test Code
        bool irObjAvoid_2Var = !digitalRead();
    	Serial.print(F("ObjAvoid: ")); Serial.println(irObjAvoid_2Var);
    }
    else if(menuOption == '3') {
    	#3 - Test Code
        bool irObjAvoid_3Var = !digitalRead();
    	Serial.print(F("ObjAvoid: ")); Serial.println(irObjAvoid_3Var);
    }
    else if(menuOption == '4') {
    	#4 - Test Code
        bool irObjAvoid_4Var = !digitalRead();
    	Serial.print(F("ObjAvoid: ")); Serial.println(irObjAvoid_4Var);
    }
    else if(menuOption == '5') {
   	#5 - Test Code
        bool irObjAvoid_5Var = !digitalRead();
    	Serial.print(F("ObjAvoid: ")); Serial.println(irObjAvoid_5Var);
    }
    
    if (millis() - time0 > timeout)
    {
        menuOption = menu();
    }
    
}
char menu()
{

    Serial.println(F("\nWhich component would you like to test?"));
    Serial.println(F("(1) IR Obstacle Avoidance Sensor #1"));
    Serial.println(F("(2) IR Obstacle Avoidance Sensor #2"));
    Serial.println(F("(3) IR Obstacle Avoidance Sensor #3"));
    Serial.println(F("(4) IR Obstacle Avoidance Sensor #4"));
    Serial.println(F("(5) IR Obstacle Avoidance Sensor #5"));
    Serial.println(F("(menu) send anything else or press on board reset button\n"));
    while (!Serial.available());

    // Read data from serial monitor if received
    while (Serial.available()) 
    {
        char c = Serial.read();
        if (isAlphaNumeric(c)) 
        {   
            
            if(c == '1') 
    			Serial.println(F("Now Testing IR Obstacle Avoidance Sensor #1"));
    		else if(c == '2') 
    			Serial.println(F("Now Testing IR Obstacle Avoidance Sensor #2"));
    		else if(c == '3') 
    			Serial.println(F("Now Testing IR Obstacle Avoidance Sensor #3"));
    		else if(c == '4') 
    			Serial.println(F("Now Testing IR Obstacle Avoidance Sensor #4"));
    		else if(c == '5') 
    			Serial.println(F("Now Testing IR Obstacle Avoidance Sensor #5"));
            else
            {
                Serial.println(F("illegal input!"));
                return 0;
            }
            time0 = millis();
            return c;
        }
    }
}

