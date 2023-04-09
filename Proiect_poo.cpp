#include <iostream>
#include <cstring>
#include <iomanip>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

class camion {
    char* nr_inmatriculare;
    double greutate;
    bool activ;
    double masa_net;
public:
    camion(const char* numar, double gr_camion) {
        nr_inmatriculare = new char[strlen(numar) + 1];
        strcpy_s(nr_inmatriculare, strlen(numar) + 1, numar);
        greutate = gr_camion;
        activ = false;
        masa_net = greutate;
    }

    double profit(int cereale) {
        if (cereale == 1)
            return (masa_net - greutate) * 1.9;
        else if (cereale == 2)
            return (masa_net - greutate) * 1.5;
        else return (masa_net - greutate) * 1.64;

    }
    void cursa_activa(double incarcatura) {
        activ = 1;
        masa_net += incarcatura;
    }

    ~camion() {
        delete[] nr_inmatriculare;
    }
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
    camion c1("B123SLD", 4500.0);
    c1.cursa_activa(2500.0);
    cout << fixed << setprecision(2) << c1.profit(1);


    return 0;
}

/*
      apasa 1 pentru trimis camion in cursa
      {
      Alege camionul:
      1. B123SLD
      2. B124SLD
      3. B125SLD
      Introdu incarcatura:



    */
    /*
    IDEI

    contabil-taxe pe profit la curse
    profitul e trimis la contabil e facut dupa tva
    profitul brut ajunge la sef si il pune intr o variabila sau vector

    trebuie ceva pentru afisarea unei clase si cumva sa implic directorii

    */