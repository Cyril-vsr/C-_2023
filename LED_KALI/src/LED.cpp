#ifndef LED_H
#define LED_H

// Inclusion des bibliothèques nécessaires
#include <Arduino.h>

// Définition de la classe abstraite Led
class Led {
public:
  virtual void setColor(int intensity) = 0;
  virtual int getPin() const = 0;
};

// Définition de la classe pour la LED rouge
class RedLed : public Led {
private:
  const int pin;

public:
  RedLed(int pin) : pin(pin) {}

  void setColor(int intensity) override {
    analogWrite(pin, intensity);
  }

  int getPin() const override {
    return pin;
  }
};

// Définition de la classe pour la LED verte
class GreenLed : public Led {
private:
  const int pin;

public:
  GreenLed(int pin) : pin(pin) {}

  void setColor(int intensity) override {
    analogWrite(pin, intensity);
  }

  int getPin() const override {
    return pin;
  }
};

// Définition de la classe pour la LED bleue
class BlueLed : public Led {
private:
  const int pin;

public:
  BlueLed(int pin) : pin(pin) {}

  void setColor(int intensity) override {
    analogWrite(pin, intensity);
  }

  int getPin() const override {
    return pin;
  }
};

// Utilisation des classes dans le programme principal
RedLed redLed(9);   // Utilisez la broche appropriée pour la LED rouge
GreenLed greenLed(10); // Utilisez la broche appropriée pour la LED verte
BlueLed blueLed(11);  // Utilisez la broche appropriée pour la LED bleue



#endif  // LED_H

#include <Arduino.h>
#include <LED_H>

void setup() {
  // Initialisez les broches comme des sorties
  pinMode(redLed.getPin(), OUTPUT);
  pinMode(greenLed.getPin(), OUTPUT);
  pinMode(blueLed.getPin(), OUTPUT);
}

void loop() {
  // Allume la LED en rouge
  redLed.setColor(255);
  delay(1000);

  // Allume la LED en vert
  greenLed.setColor(255);
  delay(1000);

  // Allume la LED en bleu
  blueLed.setColor(255);
  delay(1000);

  // Éteint toutes les LED
  redLed.setColor(0);
  greenLed.setColor(0);
  blueLed.setColor(0);
  delay(1000);
}