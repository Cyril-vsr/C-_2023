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
  const u_int8_t pin;
  boolean mode = false;
public:
Buzzer(uint pinvalue, int mode_B) : pin(pinvalue), mode(mode_B) {
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
