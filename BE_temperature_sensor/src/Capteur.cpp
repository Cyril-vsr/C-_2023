using namespace std;
class Capteur
{
    Capteur() { }

};

class Temperature : public Capteur
{
    private:
        char * name;
        int temp;
    public :
        Temperature(char * nom){
            *name = *nom;
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
char * getName()
{
    return name;
}
void setName(string nom)
{
    name = nom;
}

}

// Methods :
void afficherTemperature()
{
    Capteur::afficherCaracteristiques();
    cout << "Il fait " << getTemp() << "°C actuellement." << endl;
}
};