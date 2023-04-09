#include <iostream>
#include <cstring>
#include <cstdlib>
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
            return (masa_net - greutate) * 1.3;
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
    cout << "Alege actiunea dorita: \n";
    cout << "1.Trimite camion in cursa\n";
    cout << "2. \n";
    cout << "3. \n";
    int input;
    cin >> input;
    system("cls");
    if (input == 1) {
        cout << "Alege numarul de inmatriculare: \n";
        cout << "1.B123SLD" << endl;
        cout << "2.B124SLD" << endl;
        cout << "3.B125SLD" << endl;
        int input2;
        cin >> input2;
        system("cls");
        char *numar=new char[9];
        switch (input2) {
        case 1: 
            strcpy_s(numar,9,"B123SLD");
            break;
        case 2: 
            strcpy_s(numar,9,"B124SLD");
            break;
        case 3: 
            strcpy_s(numar,9,"B125SLD");
            break;
       
        }
        camion c1(numar, 4500);
        delete[] numar;
        cout << "Introdu incarcatura de cereale: \n";
        double incarcatura;
        cin >> incarcatura;
        system("cls");
        c1.cursa_activa(incarcatura);
        cout << "Tipul cerealelor: " << endl;
        cout << "1.Porumb"<<endl;
        cout << "2.Orz" << endl;
        cout << "3.Rapita" << endl;
        int cereale;
        cin >> cereale;
        system("cls");
        if (cereale > 3 || cereale < 1)
            cout << "Cod cereale inexistent!";
        else { 
            cout << "Profitul net pe aceasta cursa este:";
            cout<< c1.profit(cereale)<<'$'; }


    }


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