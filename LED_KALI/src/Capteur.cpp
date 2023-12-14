using namespace std;
#include <Capteur.h>

int Capteur::nbCapteur = 0;
Capteur::Capteur(){ nbCapteur++; }
Capteur::~Capteur(){ nbCapteur--; }

DHT dht(D6,DHTTYPE);  //   DHT11

string Temperature::name = "";
float Temperature::temp = 0;

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
    //Serial.println(dht.readHumidity());
    
}

void Temperature::initCom() 
{
    Wire.begin();
    dht.begin();
}

