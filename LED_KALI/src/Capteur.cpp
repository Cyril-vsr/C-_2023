#include <DHT.h>
#include <Arduino.h>
#include <Capteur.h>  // Inclure le fichier d'en-tête pour la classe Capteur

// Informations sur le créateur, la date de création et le projet
// Créateur : Paul JAULHIAC
// Date de création : 18/12/23@
// Projet : C++ Project

// Définition de la classe Capteur
int Capteur::nbCapteur = 0;

// Constructeur de la classe Capteur
Capteur::Capteur() {
  nbCapteur++;
}

// Destructeur de la classe Capteur
Capteur::~Capteur() {
  nbCapteur--;
}

// Initialisation du capteur DHT
DHT dht(D6, DHTTYPE);  // DHT11

// Définition de la classe Temperature
String Temperature::name = "";
float Temperature::temp = 0;

// Définition de la classe Humidity
String Humidity::name = "";
float Humidity::hum = 0;

// Constructeur de la classe Temperature
Temperature::Temperature(String nom) {
  name = nom;
  temp = 0;  
}

// Constructeur par défaut de la classe Temperature
Temperature::Temperature() {
  name = "tempSens";
  temp = 0;  
}

// Accesseurs de la classe Temperature
float Temperature::getTemp() {
  temp = dht.readTemperature(false);
  return temp;
}

void Temperature::setTemp(float t) {
  temp = t;
}

String Temperature::getName() {
  return name;
}

void Temperature::setName(String nom) {
  name = nom;
}

// Méthodes de la classe Temperature
void Temperature::printTemperature() {
  Serial.print("La valeur du capteur de température est : ");
  Serial.println(getTemp());
}

void Temperature::initCom() {
  Wire.begin();
  dht.begin();
}

// Constructeur de la classe Humidity
Humidity::Humidity(String nom) {
  name = nom;
  hum = 0;  
}

// Constructeur par défaut de la classe Humidity
Humidity::Humidity() {
  name = "HumSens";
  hum = 0;  
}

// Accesseurs de la classe Humidity
float Humidity::getHum() {
  hum = dht.readHumidity();
  return hum;
}

void Humidity::setHum(float h) {
  hum = h;
}

String Humidity::getName() {
  return name;
}

void Humidity::setName(String nom) {
  name = nom;
}

// Méthodes de la classe Humidity
void Humidity::printHumidity() {
  Serial.print("La valeur du capteur d'humidité est : ");
  Serial.println(getHum());
}

void Humidity::initCom() {
  Wire.begin();
  dht.begin();
}
