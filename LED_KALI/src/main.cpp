#include <Arduino.h>
#include "Actuator.h"
#include "Capteur.h"
using namespace std;
#include <iostream>

// Création d'une instance de LED_RGB avec le pin GPIO 13 et une couleur rouge
LED_RGB *myLed = nullptr;
Buzzer *myBuzzer = nullptr;
SevenSegmentDisplay *myDisplay = nullptr;
int sensorValue = 0;
Temperature *CaptTemp = nullptr;
Humidity *CaptHum = nullptr;
bool f_temp = false;
int temp = 0;
int hum = 0;

void setup()
{
  Serial.begin(9600);
  Serial.println("Initialisation begin...");
  myLed = new LED_RGB(D7);
  Serial.println("step 1..");
  myBuzzer = new Buzzer(D9, false);
  Serial.println("step 2..");
  myDisplay = new SevenSegmentDisplay(D3, D5);
  Serial.println("Step 3..");
  CaptTemp = new Temperature("Capteur Temp");
  CaptTemp->setTemp(0);
  CaptTemp->initCom();
  Serial.println("Step 4..");
  CaptHum = new Humidity("Capteur Hum");
  CaptHum->setHum(0);
  CaptHum->initCom();
  Serial.println("Step 5..");
  Serial.println("End Initialisation..");
}
int Exceptionhandler(int temp)
{
  try
  {
    if (temp >= 2)
    {
      throw "Valeur de capteur invalide";
    }
    delay(1000);
  }
  catch (const char *error)
  {
    return -1; // Erreur détectée
  }
  return 0; // Succès
}
void updateColorBasedOnTemperature(float temperature)
{
  // Convertir la température en une valeur de couleur
  int colorValue = map(temperature, 19, 23, 0, 255); // Between 15 and 30 °C - 0 to 255 values

  // Ajuster la couleur de la LED RGB
  *myLed = {255 - colorValue, colorValue, 0};
}

void WarningTemperature_Humidity(float temperature, float humidity)
{
  if (temperature >= 30 or hum >= 100)
  {
    myBuzzer->SetMode(true);
  }
  else
  {
    myBuzzer->SetMode(false);
  }
}
void displayTemperature(float temperature)
{
  temp = int(temperature);
  myDisplay->displayNumber(temp);
}
void displayHumidity(float humidity)
{
  hum = int(humidity);
  myDisplay->displayNumber(hum);
}

void loop()
{

  Serial.println("begin..");
  updateColorBasedOnTemperature(CaptTemp->getTemp());
  WarningTemperature_Humidity(CaptTemp->getTemp(), CaptHum->getHum());
  displayTemperature(CaptTemp->getTemp());
  delay(2000);
  displayHumidity(CaptHum->getHum());
  delay(2000);

  // int result = Exceptionhandler(sensorValue);

  // if (result == -1) {
  // Serial.println("Error...");
  // return;
  // }

  myLed->println(Serial);
  myBuzzer->println(Serial);
  myDisplay->println(Serial);

  Serial.print("Température de :");
  Serial.println(CaptTemp->getTemp());
  Serial.print("Humidité à :");
  Serial.println(CaptHum->getHum());
  Serial.println("End...");
}