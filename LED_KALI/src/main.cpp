#include <Arduino.h>
#include "Actuator.h"
using namespace std;
#include <iostream>


  // Création d'une instance de LED_RGB avec le pin GPIO 13 et une couleur rouge
LED_RGB *myLed=nullptr;
Buzzer *myBuzzer=nullptr;
SevenSegmentDisplay *myDisplay=nullptr;
int sensorValue = 0;




void setup() { 
  Serial.begin(9600);
  Serial.println("Initialisation begin...");
  myLed=new LED_RGB(D7);
  Serial.println("step 1..");
  myBuzzer=new Buzzer(D6, false);
  Serial.println("step 2..");
  myDisplay= new SevenSegmentDisplay(D3, D5);

}
int Exceptionhandler(int temp) {
      try {
      if (temp >= 2) {
        throw "Valeur de capteur invalide";
      }
      // Introduire un délai entre les lectures
      delay(1000);
      }catch (const char* error) {
      return -1;  // Erreur détectée
  }
  return 0;  // Succès
}

void loop() {

 // int result = Exceptionhandler(sensorValue);

  // if (result == -1) {
  //   Serial.println("Error...");
  //   return;
  // }
  Serial.println("begin..");
  myLed->setRGB(0,255,0);
  delay(1000);
  myLed->setRGB(255,0,0);
  delay(1000);
  myLed->setRGB(0,0,255);
  delay(1000);
  myLed->setRGB(0,0,0);
  delay(1000);
  *myLed = {255, 0, 255};
  delay(2000);
  myBuzzer->SetMode(false);
  delay(100);
  myBuzzer->SetMode(false);
  delay(4000);
  
  // Afficher le nombre 1234
  myDisplay->displayNumber(1234);
  delay(2000);

  // Afficher le nombre 5678
  myDisplay->displayNumber(5678);
  delay(2000);
 
  myLed->println(Serial);
  myBuzzer->println(Serial);
  myDisplay->println(Serial);

  Serial.println("End...");
  sensorValue++;
 
}
