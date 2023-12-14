using namespace std;
#include <iostream>
#include <string>

class Capteur
{
public :
    static int nbCapteur;
    
    Capteur() { nbCapteur++; }
    ~Capteur() { nbCapteur--; }

};

int Capteur::nbCapteur = 0;

class Temperature : public Capteur
{
private:
    static string name;
    static int temp;
public :
    Temperature(string nom){
        name = nom;
        temp = 0;
    }
    Temperature() {
        name = "tempSens";
        temp = 0;
    }
//Code à implémenter pour la com en i2c avec le sensor et affectation des valeurs lues dans temp :
//    ----------

// Accessors :
int getTemp()
{
    return temp;
}
void setTemp()
{ 
    temp = 0;
}
string getName()
{
    return name;
}
void setName(string nom)
{
    name = nom;
}

// Methods :
void afficherTemperature()
{
    cout << "Il fait " << getTemp() << "°C actuellement." << endl;
}

void setPin() {

}

};