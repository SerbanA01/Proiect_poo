#include <iostream>
using namespace std;

class camion {
    char nr_inmatriculare;
    double greutate;
    bool activ;
    double masa_net;

};
class sef {
    char nume, prenume;
    double salariu;
};
class contabil {
    char nume, prenume;
    double salariu;
    sef sef_contabil;
};
class sofer {
    char nume, prenume;
    double salariu;
    char vehicul;
    sef sef_sofer;
};
class mecanic {
    char nume, prenume;
    char specialiazre;
    double salariu;
};
class service {
    sef sef_service;
    char locatie;
    mecanic mecanici_service[50];
};

class director {
    char nume, prenume;
    double salariu;
    char tip;
    char regiune;
    bool general;
};


int main()
{
   
    return 0;
}


