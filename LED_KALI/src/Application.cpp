#include <Arduino.h>
#include <Capteur.h>
// put function declarations here:

// Global variables here:
Temperature *CaptTemp = nullptr;
bool f_temp=false;

void setup() {
  Serial.begin(9600);
  Serial.println("Initialisation");
  // put your setup code here, to run once:
  CaptTemp = new Temperature("Capteur Temp");
  Serial.println("Création classe capteur");  
  
  CaptTemp->setTemp(0);   
  CaptTemp->initCom();
  Serial.println("Com initiée"); 
}

void loop() {
  float test=0;
  try{
    test=CaptTemp->getTemp();
    if(test<-30 || test >80){
      throw "Oulala le flag";
    }
    delay(1500);

  }catch (const char * error) {
        f_temp=true;
        Serial.println("Except catchée");
    }
    // put your main code here, to run repeatedly:
  
  //Serial.print("Température de :"); 
  //Serial.println(CaptTemp->getTemp());
  //CaptTemp->printTemperature();
  delay(1500);
  CaptTemp->setTemp(-50);

  /*if(f_temp){
    Serial.println("Oulala le flag");
    delay(1500);
    f_temp=false;*/
  }

  
  


