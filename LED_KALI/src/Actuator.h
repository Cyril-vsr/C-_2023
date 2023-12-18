#ifndef ACTUATOR_H
#define ACTUATOR_H

// Inclusion des bibliothèques nécessaires
#include <Arduino.h>
#include <ChainableLED.h>
#include "TM1637.h"
#include <ostream>
#include <vector>

// Utilisation du namespace std
using namespace std;

// Informations sur le créateur, la date de création et le projet
// Créateur : Cyril Vasseur
// Date de création : 18/12/23
// Projet : Projet de C++

// Classe abstraite Actuator : représente un actionneur générique
class Actuator {
public:
  static int nb; // Nombre d'instances d'Actionneur créées
  Actuator() { nb++; } // Constructeur incrémentant le nombre d'instances
  ~Actuator() { nb--; } // Destructeur décrémentant le nombre d'instances
  static int getNb() { return nb; } // Méthode statique pour obtenir le nombre d'instances
};

int Actuator::nb = 0; // Initialisation du compteur d'instances

// Classe LED_RGB : représente une LED RVB contrôlable
class LED_RGB : public Actuator {
private:
  const u_int8_t pin; // Broche de la LED
  int R, G, B; // Composantes rouge, verte et bleue
  ChainableLED Led; // Instance de la bibliothèque ChainableLED

public:
  // Constructeur initialisant la LED avec la broche spécifiée et une LED unique
  LED_RGB(int pin) : pin(pin), R(0), G(0), B(0), Led(pin, D8, 1) {}

  // Méthode pour définir les composantes RVB de la LED
  void setRGB(int colorR, int colorG, int colorB) {
    R = colorR;
    G = colorG;
    B = colorB;
    Led.setColorRGB(0, colorR, colorG, colorB);
  }

  // Surcharge de l'opérateur '=' pour définir les composantes RVB à partir d'un vecteur
  void operator=(const vector<int>& values) {
    if (values.size() == 3) {
      auto it = values.begin();
      R = *it++;
      G = *it++;
      B = *it;
      setRGB(R, G, B);
    }
  }

  // Méthode pour afficher les informations de la LED dans un flux de sortie
  void println(Print& output) const {
    output.print("LED_RGB - Pin: ");
    output.print(pin);
    output.print(", R: ");
    output.print(R);
    output.print(", G: ");
    output.print(G);
    output.print(", B: ");
    output.println(B);
  }
};

// Classe Buzzer : représente un buzzer contrôlable
class Buzzer : public Actuator {
private:
  const int pin; // Broche du buzzer
  boolean mode = false; // Mode du buzzer (activé ou désactivé)

public:
  // Constructeur initialisant le buzzer avec la broche spécifiée et le mode spécifié
  Buzzer(int pinvalue, int mode_B) : pin(pinvalue), mode(mode_B) {
    pinMode(pin, OUTPUT);
    UpdateBuzzerState();
  }

  // Méthode pour définir le mode du buzzer
  void SetMode(boolean NewMode) {
    mode = NewMode;
    UpdateBuzzerState();
  }

private:
  // Méthode pour mettre à jour l'état du buzzer en fonction du mode
  void UpdateBuzzerState() {
    if (mode == true) {
      digitalWrite(pin, HIGH);
    } else {
      digitalWrite(pin, LOW);
    }
  }

public:
  // Méthode pour afficher les informations du buzzer dans un flux de sortie
  void println(Print& output) const {
    output.print("Buzzer - Pin: ");
    output.print(pin);
    output.print(", Mode: ");
    output.println(mode);
  }
};

// Classe SevenSegmentDisplay : représente un afficheur 7 segments contrôlable
class SevenSegmentDisplay : public Actuator {
private:
  const int pinCLK; // Broche de l'horloge
  const int pinDIO; // Broche de données
  TM1637 tm1637; // Instance de la bibliothèque TM1637

public:
  // Constructeur initialisant l'afficheur 7 segments avec les broches spécifiées
  SevenSegmentDisplay(int CLK, int DIO) : pinCLK(CLK), pinDIO(DIO), tm1637(CLK, DIO) {
    tm1637.init();
    tm1637.set(BRIGHT_TYPICAL);
  }

  // Méthode pour afficher un nombre sur l'afficheur
  void displayNumber(int number) {
    int8_t data[] = {0, 0, 0, 0};
    for (int i = 0; i < 4; ++i) {
      data[3 - i] = number % 10;
      number /= 10;
    }
    tm1637.display(data);
  }

  // Méthode pour afficher les informations de l'afficheur dans un flux de sortie
  void println(Print& output) const {
    Serial.print(", PinDIO: ");
    Serial.println(pinDIO);
  }
};

#endif
