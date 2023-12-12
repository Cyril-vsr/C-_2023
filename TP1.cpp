#include <iostream> 
using namespace std;
#include <math.h> 

class Figure
{
    public :
        static int nb_fig;

    Figure(){nb_fig++;}
    ~Figure(){nb_fig--;}

    virtual int Perimetre() = 0;
    virtual void AfficherCaracteristiques() {}
   
};

int Figure::nb_fig=0;

class Polygon : public Figure
{
    private:
        int nbcote;
    public :
    Polygon(int nbc) : Figure()
    {
        nbcote = nbc;
    }
    virtual void AfficherCaracteristiques()
    {
        Figure :: AfficherCaracteristiques();
        cout << "Nb de cotes :";
        cout << nbcote << endl;
    }
};
class Cercle : public Figure
{
    private:
        int rayon;
    public:
    Cercle(int r ) : Figure()
    {
        rayon = r;
    }
    virtual void AfficherCaracteristiques()
    {
        Figure :: AfficherCaracteristiques();
        cout << "Rayon :";
        cout << rayon << endl;
    }
    void put(int r);
    void get();
    virtual int Perimetre();
};
class Rectangle : public Polygon{
    public:
    int length;
    int width;

    Rectangle(int l, int w) : Polygon(4){
        length = l;
        width = w;
    }
    void put(int w, int l);
    void get();
    virtual void AfficherCaracteristiques();
    virtual int Perimetre();
};
class TriangleEqui : public Polygon{
    public:
    int length;

    TriangleEqui(int l) : Polygon(3){
        length = l;
    }
  void put(int l);
  void get();
  virtual void AfficherCaracteristiques();
  virtual int Perimetre();
};
class Carre : public Rectangle{
public:
    Carre(int l) : Rectangle(l,l){
        length = l;
        width = l;
    }
    virtual void AfficherCaracteristiques();
};
void Rectangle::put(int l, int w){
    length = l;
    width = w;

}
// fonction de saisie des elements du vecteur
void Rectangle::get(){
    cout << length << endl;
    cout << width << endl;
}
void Cercle::put(int r){
    rayon=r;

}
void Cercle::get(){
    cout << rayon << endl;
}
void TriangleEqui::put(int l){
    length = l;

}
// fonction de saisie des elements du vecteur
void TriangleEqui::get(){
    cout << length << endl;

}
void Rectangle::AfficherCaracteristiques(){
    Polygon :: AfficherCaracteristiques();
    cout << "Longueur :" << length << endl;
    cout << "Largeur :" << width << endl;
}
void TriangleEqui::AfficherCaracteristiques(){
    Polygon :: AfficherCaracteristiques();
    cout << "Longueur Triangle :" << length << endl;
}
void Carre::AfficherCaracteristiques(){
    Rectangle :: AfficherCaracteristiques();
}
int Rectangle::Perimetre(){
    return length*2 + width*2;
}
int TriangleEqui::Perimetre(){
    return length*3;
}
int Cercle::Perimetre(){
    return 2*M_PI*rayon;
}



int main()
{ 
    const int r=3;
    Figure * Tab[4];
    

    Tab[0]=new Cercle (r);
    Tab[1]=new TriangleEqui (r);
    Tab[2]=new Carre (r);
    Tab[3]=new Rectangle (r,5);

    for(int i=0;i<4;i++)
    {
        Tab[i]->AfficherCaracteristiques();
        cout << "Périmètre : " << Tab[i]->Perimetre() << endl;
        cout << endl;
    }

    return 0;
}