#include <DHT.h>
#include <Arduino.h>
using namespace std;
#include <Capteur.h>

int Capteur::nbCapteur = 0;
Capteur::Capteur(){ nbCapteur++; }
Capteur::~Capteur(){ nbCapteur--; }

DHT dht(D6,DHTTYPE);  //   DHT11

string Temperature::name = "";
float Temperature::temp = 0;

string Humidity::name = "";
float Humidity::hum = 0;

//Classe pour le capteur Temperature :
Temperature::Temperature(string nom){
    name = nom;
    temp = 0;  
}
Temperature::Temperature(){
    name = "tempSens";
    temp = 0;  
}

// Accessors :
float Temperature::getTemp ()
{   
    temp=dht.readTemperature(false);  
    return temp;   
}
void Temperature::setTemp(float t)
{ 
    temp = t;
}
string Temperature::getName()
{
    return name;
}
void Temperature::setName(string nom)
{
    name = nom;
}

// Methods :
void Temperature::printTemperature()
{
    Serial.print("La valeur du capteur est : ");
    Serial.println(getTemp());
    
}

void Temperature::initCom() 
{
    Wire.begin();
    dht.begin();
}

//Classe pour le capteur Humidité :
Humidity::Humidity(string nom){
    name = nom;
    hum = 0;  
}
Humidity::Humidity(){
    name = "HumSens";
    hum = 0;  
}

// Accessors :
float Humidity::getHum ()
{   
    hum=dht.readHumidity();  
    return hum;   
}
void Humidity::setHum(float h)
{ 
    hum = h;
}
string Humidity::getName()
{
    return name;
}
void Humidity::setName(string nom)
{
    name = nom;
}

// Methods :
void Humidity::printHumidity()
{
    Serial.print("La valeur du capteur d'humidité est : ");
    Serial.println(getHum());
    
}

void Humidity::initCom() 
{
    Wire.begin();
    dht.begin();
}