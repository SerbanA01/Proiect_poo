#include <iostream>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

class camion {
    char* nr_inmatriculare;
    double greutate;
    bool activ;
    double masa_net;
public:
    int greutate_incarcatura() {
        if (activ == 1)
            return masa_net - greutate;
        else cout << "Camionul nu este activ!";
        return 0;
    }
    camion(const char* numar, double gr_camion) {
        nr_inmatriculare = new char[strlen(numar) + 1]; 
        strcpy_s(nr_inmatriculare, strlen(numar) + 1, numar); 
        greutate = gr_camion;
        activ = false;
        masa_net = greutate;
    }

    void cursa_activa(double incarcatura) {
        activ = 1;
        masa_net = incarcatura;
    }
    void get_gr() {
        cout << greutate;
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
    camion c1("B123DLS", 5000.1);
    c1.get_gr();
    return 0;
}


