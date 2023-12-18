#include <iostream>
#include <string>
#include <Arduino.h>
#include "Wire.h"
#include "DHT.h"

// Informations sur le créateur, la date de création et le projet
// Créateur : Paul JAULHIAC
// Date de création : 18/12/23
// Projet : C++ Project

#ifndef CAPTEUR_H
#define CAPTEUR_H

#define DHTTYPE DHT11
#define DHTPIN 2  

#if defined(ARDUINO_ARCH_AVR)
    #define debug  Serial

#elif defined(ARDUINO_ARCH_SAMD) || defined(ARDUINO_ARCH_SAM)
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
    static String name;
    static float temp;

public :
    Temperature(String nom);
    Temperature();

    // Accesseurs :
    float getTemp();
    void setTemp(float t);
    String getName();
    void setName(String nom);

    // Méthodes :
    void printTemperature();
    void initCom();
};

// Classe pour le capteur Humidité :
class Humidity : public Capteur
{
private:
    static String name;
    static float hum;

public :
    Humidity(String nom);
    Humidity();
    
    // Accesseurs :
    float getHum();
    void setHum(float t);
    String getName();
    void setName(String nom);

    // Méthodes :
    void printHumidity();
    void initCom();
};

#endif // CAPTEUR_H
