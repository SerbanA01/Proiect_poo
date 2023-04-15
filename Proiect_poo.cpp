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
    string nume, prenume;
    double profit[55] = { 0 };
    int surse_profit = 0;
    double salariu;
public:
    void adaugare_profit(double income) {
        profit[++surse_profit] = income;
    }
    double profit_total() {
        double profit_total_return = 0;
        for (int i = 1; i <= surse_profit; i++)
        {
            profit_total_return += profit[i];

        }
        return profit_total_return;
    }
};
class contabil {
    string nume, prenume;
    double salariu;
    sef sef_contabil;
public:
    contabil(double s = 0) :salariu(s) {}
    void set_contabil(string n, string p, double s) {
        nume = n;
        prenume = p;
        salariu = s;
    }
    double get_salariu() {
        return salariu;
    }
    double taxe_profit(double profit) {
        sef_contabil.adaugare_profit(profit - profit * 16 / 100);
        return profit - profit * 16 / 100;
    }

};
class sofer {
    char nume[15], prenume[15];
    double salariu;
    char vehicul;
    sef sef_sofer;
};
class mecanic {
    char nume[15], prenume[15];
    char specialiazre;
    double salariu;
};
class service {
    sef sef_service;
    char locatie;
    mecanic mecanici_service[50];
};

class director {
    char nume[15], prenume[15];
    double salariu;
    char tip;
    char regiune;
    bool general;
};

int main()
{/*
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
        char* numar = new char[9];
        switch (input2) {
        case 1:
            strcpy_s(numar, 9, "B123SLD");
            break;
        case 2:
            strcpy_s(numar, 9, "B124SLD");
            break;
        case 3:
            strcpy_s(numar, 9, "B125SLD");
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
        cout << "1.Porumb" << endl;
        cout << "2.Orz" << endl;
        cout << "3.Rapita" << endl;
        int cereale;
        cin >> cereale;
        system("cls");
        if (cereale > 3 || cereale < 1)
            cout << "Cod cereale inexistent!";
        else {
            cout << "Profitul net pe aceasta cursa este: ";
            double profit_net = c1.profit(cereale);
            cout << profit_net << '$'<<endl;

        }

    }*/
    contabil c1;
    c1.set_contabil("ana", "maria", 2500.0);
    return 0;
}

/*
IDEI

contabil-taxe pe profit la curse
profitul e trimis la contabil e facut dupa tva
profitul brut ajunge la sef si il pune intr o variabila sau vector

trebuie ceva pentru afisarea unei clase si cumva sa implic directorii

sef contabil verifica calculele si face profitul pe an
si pe anul urmator
directorul calculeaza un plan de investitii

*/