using System;

public class Capteur
{
    Capteur() { }

}

class Temperature : public Capteur
{
    private:
        string name;
        int temp;
    public :
        Temperature(string nom){
            name = nom;
        }
//Code à implémenter pour la com en i2c avec le sensor et affectation des valeurs lues dans temp :
    ----------

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

}

// Methods :
virtual void afficherTemperature()
{
    Capteur::afficherCaracteristiques();
    cout << "Il fait " << getTemp() << "°C actuellement." << endl;
}
};