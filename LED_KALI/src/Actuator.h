#ifndef ACTUATOR_H
#define ACTUATOR_H

// Inclusion des bibliothèques nécessaires
#include <Arduino.h>
#include <ChainableLED.h>
#include "TM1637.h"

// Définition de la classe abstraite Led
class Actuator {
public:
 static int nb;
 Actuator(){nb++;}
 ~Actuator(){nb--;}
 static int getNb() {
    return nb;
  }
};
int Actuator::nb = 0;

// Définition de la classe pour la LED rouge
class LED_RGB : public Actuator {
private:
  const u_int8_t pin;
  int R,G,B;
  ChainableLED Led;
  

public:
LED_RGB(int pin) : pin(pin), R(0), G(0), B(0), Led(pin, D8, 1) {
  //Led.setColorRGB(0, 255, 0, 0);
  }

  void setRGB(int colorR, int colorG, int colorB) {
    R = colorR;
    G = colorG;
    B = colorB;
    Led.setColorRGB(0, colorR, colorG, colorB);
  }
  int getPin() const {
    return pin;
  }
  void getR() {
    printf("%d",R);
  }
  void getG() {
    printf("%d",G);
  }
  void getB() {
    printf("%d",B);
  }
};

// Définition de la classe pour le Buzzer
class Buzzer : public Actuator {
private:
  const int pin;
  boolean mode = false;
public:
Buzzer(int pinvalue, int mode_B) : pin(pinvalue), mode(mode_B) {
  pinMode(pin, OUTPUT); 
  UpdateBuzzerState();
  }
  void SetMode(boolean NewMode)
{
  mode = NewMode;
  UpdateBuzzerState();
}
  private:
  void UpdateBuzzerState() {
    if (mode == true) {
      digitalWrite(pin, HIGH);
    } else {
      digitalWrite(pin, LOW);
    }
  }
};

class SevenSegmentDisplay : public Actuator {
private:
  const int pinCLK;
  const int pinDIO;
  TM1637 tm1637;

public:
  SevenSegmentDisplay(int CLK, int DIO) : pinCLK(CLK), pinDIO(DIO), tm1637(CLK, DIO) {
    tm1637.init();
    tm1637.set(BRIGHT_TYPICAL);
  }

  void displayNumber(int number) {
    // Convertir le nombre en tableau d'entiers
   // Convertir le nombre en tableau d'entiers
    int8_t data[] = {0, 0, 0, 0};
    for (int i = 0; i < 4; ++i) {
      data[3 - i] = number % 10;  // Correction de l'ordre des chiffres
      number /= 10;
    }

    // Afficher le tableau sur l'afficheur
    tm1637.display(data);
  }
};

#endif
