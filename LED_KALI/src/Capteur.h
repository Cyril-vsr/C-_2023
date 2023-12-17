using namespace std;
#include <iostream>
#include <string>
#include <Arduino.h>
#include "Wire.h"
#include "DHT.h"

#ifndef CAPTEUR_H
#define CAPTEUR_H

#define DHTTYPE DHT11
#define DHTPIN 2  

#if defined(ARDUINO_ARCH_AVR)
    #define debug  Serial

#elif defined(ARDUINO_ARCH_SAMD) ||  defined(ARDUINO_ARCH_SAM)
    #define debug  SerialUSB
#else
    #define debug  Serial
#endif

class Capteur
{
public :
    static int nbCapteur;
    
    Capteur();
    ~Capteur();

};



class Temperature : public Capteur
{
private:
    static string name;
    static float temp;

public :
    Temperature(string nom);
    Temperature();

// Accessors :
float getTemp();
void setTemp(float t);
string getName();
void setName(string nom);

// Methods :
void printTemperature();

void initCom();

};

//Classe pour le capteur Humidité :
class Humidity : public Capteur
{
private:
    static string name;
    static float hum;

public :
    Humidity(string nom);
    Humidity();
    
// Accessors :
float getHum();
void setHum(float t);
string getName();
void setName(string nom);

// Methods :
void printHumidity();

void initCom();

};

#endif // CAPTEUR_H