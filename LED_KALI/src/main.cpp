#include <Arduino.h>
#include "Actuator.h"



// Création d'une instance de LED_RGB avec le pin GPIO 13 et une couleur rouge
LED_RGB myLed(13, 255, 0, 0);

// Création d'une instance de Buzzer avec le pin GPIO 7 en mode actif
Buzzer myBuzzer(7, true);

void setup() {
  // Rien à initialiser ici pour cet exemple
}

void loop() {
  // Allumer la LED pendant 1 seconde
  myLed.setR(0);
  delay(1000);
  myLed.setG(255);
  delay(1000);
  myLed.setG(0);
  delay(1000);
  myLed.setB(255);
  delay(1000);
  myLed.setG(0);
  delay(1000);

  // Éteindre la LED pendant 1 seconde
  myLed.setR(0);
  myLed.setG(0);
  myLed.setB(0);
  delay(1000);

  // Activer le buzzer pendant 2 secondes
  myBuzzer.SetMode(true); // Active le buzzer pour 2 secondes, tel que défini dans le constructeur
  delay(2000);

  // Désactiver le buzzer
  myBuzzer.SetMode(false); // Désactive le buzzer, tel que défini dans le constructeur
  delay(1000);
}
