#include <Arduino.h>
#include "Actuator.h"


  // Création d'une instance de LED_RGB avec le pin GPIO 13 et une couleur rouge
LED_RGB *myLed=nullptr;
Buzzer *myBuzzer=nullptr;
  //LED_RGB myLed(D7,255,0,0);
  // Création d'une instance de Buzzer avec le pin GPIO 7 en mode actif



void setup() { 
  Serial.begin(9600);
  Serial.println("Initialisation finish...");
}

void loop() {
  Serial.println("begin..");
 
  //myBuzzer=new Buzzer(D6, true);
  
  myLed=new LED_RGB(D7);
  Serial.println("Etape 1..");
  //Allumer la LED pendant 1 seconde

  myLed->setRGB(0,255,0);
  delay(1000);
  myLed->setRGB(255,0,0);
  delay(1000);
  myLed->setRGB(0,0,255);
  delay(1000);
  myLed->setRGB(0,0,0);
  delay(1000);
  
    Serial.println("Idle...");

}
