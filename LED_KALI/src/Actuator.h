#ifndef ACTUATOR_H
#define ACTUATOR_H

// Inclusion des bibliothèques nécessaires
#include <Arduino.h>
#include <ChainableLED.h>

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
  const int pin;
  int R,G,B;
  ChainableLED Led; // Déplacer l'objet Led ici
  

public:
LED_RGB(int pin, int R, int G, int B) : pin(pin), R(R), G(G), B(B), Led(pin, pin + 1, 1) {
    Led.setColorRGB(0, R, G, B); // Utilisation de setColorRGB pour définir la couleur
  }

  void setR(int newR) {
    R = newR;
    Led.setColorRGB(0, R, G, B); // Mettre à jour la couleur après la modification
  }

  void setG(int newG) {
    G = newG;
    Led.setColorRGB(0, R, G, B); // Mettre à jour la couleur après la modification
  }

  void setB(int newB) {
    B = newB;
    Led.setColorRGB(0, R, G, B); // Mettre à jour la couleur après la modification
  }

  int getPin() const {
    return pin;
  }
};

// Définition de la classe pour le Buzzer
class Buzzer : public Actuator {
private:
  const int pin;
  boolean mode = false;
public:
Buzzer(int pinvalue, int mode_B) : pin(pinvalue), mode(mode_B) {
  while(mode==true){
    digitalWrite(pin, HIGH);
    delay(1000);
  }
  digitalWrite(pin, LOW);

  }
  void SetMode(boolean NewMode)
{
  this->mode = NewMode;
}
};


#endif
