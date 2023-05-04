#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <fstream>
#define _CRT_SECURE_NO_WARNINGS 1
using namespace std;
ifstream fin("counter.txt");
int stricat;
class counter {



};



class camion {
    string nr_inmatriculare;
    double greutate;
    bool activ;
    double masa_net;
    int ct;
public:
    camion(string numar, double gr_camion) {
        nr_inmatriculare = numar;
        greutate = gr_camion;
        activ = false;
        masa_net = greutate;//ideea e ca toate camionele sunt facute  de la inceput, perosna doar alege care
        ct = 0;
    }
    camion(const camion& copie) :nr_inmatriculare(copie.nr_inmatriculare), greutate(copie.greutate), activ(copie.activ), masa_net(copie.masa_net), ct(copie.ct) {}

    double profit(int cereale) {
        if (cereale == 1)
            return (masa_net - greutate) * 1.3;
        else if (cereale == 2)
            return (masa_net - greutate) * 1.5;
        else return (masa_net - greutate) * 1.64;

    }
    void mareste_ct() {
        ct++;
    }

    int get_contor_curse() {
        return ct;
    }
    void cursa_activa(double incarcatura) {
        activ = 1;
        masa_net += incarcatura;
    }
    int get_activ() {
        return activ;
    }
    void set_activ() {
        activ = 1;
    }
    void set_inactiv() {
        activ = 0;
    }
    void afisare() {
        cout << "Numarul de inmatriculare este: " << nr_inmatriculare << endl;
        cout << "Greutatea camionului este: " << greutate << "kg, iar greutatea incarcaturii a fost de: " << masa_net - greutate << "kg" << endl;
    }


};

struct nume_prenume {
    string nume, prenume;
};

class sef {
    string nume, prenume;
    char sefi[10][30];
    double profit[55] = { 0 };
    int surse_profit = 0;
    double salariu;
public:
    sef() : nume(""), prenume(""), salariu(0.0) {}
    sef(string nu, string pr, double sal) {
        nume = nu;
        prenume = pr;
        salariu = sal;
    }
    void adaugare_profit(double income) {
        profit[++surse_profit] = income;
    }
    nume_prenume get_nume_prenume() {
        nume_prenume sef_names;
        sef_names.nume = nume;
        sef_names.prenume = prenume;
        return sef_names;
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
    contabil() : nume(""), prenume(""), salariu(0) {}
    contabil(string nume_sef, string prenume_sef, double sa) : nume(""), prenume(""), salariu(0), sef_contabil(nume_sef, prenume_sef, sa) {}


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
    void afisare() {
        cout << "Numele si prenumele contabilului sunt " << nume << " " << prenume << endl;
        cout << "Salariul lunar: " << salariu << "$" << endl;
        nume_prenume contabil_sef;
        contabil_sef = sef_contabil.get_nume_prenume();

        cout << "Numele si prenumele sefului responsabil sunt " << contabil_sef.nume << " " << contabil_sef.prenume << endl;
    }
};

class sofer {
    string nume, prenume;
    double salariu;
    char vehicul;
    sef sef_sofer;
};

class mecanic {
    string nume, prenume;
    double rata;
public:
    mecanic() {}
    void set_mecanic(string nu, string prn, double r) {
        nume = nu;
        prenume = prn;
        rata = r;
    }
    void repara_camion(camion& c) {
        cout << "Mecanicul repara camionul...";
        system("pause");
        c.set_activ();
    }
    friend  ostream& operator << (ostream& out, const mecanic& m);


};

ostream& operator << (ostream& out, const mecanic& m) {
    out << "Numele si prenumele mecanicului sunt: " << m.nume << " " << m.prenume << endl;
    out << "Cu rata pe ora de: " << m.rata << endl;
    return out;
}

class service {
    sef sef_service;
    string locatie;
    mecanic mecanici_service[50];
};

class director {
    string nume, prenume;
    double salariu;
    char tip;
    char regiune;
    bool general;
};

void trimite_mecanic(camion& c, mecanic m) {
    c.set_inactiv();
    camion c_copy = c;
    m.repara_camion(c_copy);
    //trebuie functie de trimis la mecanic
    system("cls");
}
//aici incepe diamantul
class ProduseFerma {

public:
    void tratare(); // asta o sa se faca pur si simplu ca metoda pentru ambele si o sa fac o functie sa scada din profitul total DISCUTABIL
    void feed(); //udarea la plante si dat de mancare la animale
    //aici trebuie un couter si o sa se faca astea odata la n rulari
};
class Plante : virtual public ProduseFerma {

};
class Animale : virtual public ProduseFerma {

};
class ProduseAlimentatie : public Plante, public Animale {

};
int main()
{
    bool inceput = 1;
    camion* camioane = new camion[3]{ camion("B123SLD",4500),camion("B124SLD",4500),camion("B125SLD",4500) };

    while (inceput) {
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
            if (camioane[input2 - 1].get_contor_curse() == 0) {
                srand(time(nullptr));
                int random_nr = rand();
                stricat = (random_nr % 6) + 1;
            }
            camioane[input2 - 1].mareste_ct();
            int contor = camioane[input2 - 1].get_contor_curse();
            if (stricat == contor) {
                camioane[input2 - 1].set_inactiv();
                string mecanic_nume, mecanic_prenume;
                double rata_mecanic;
                int input_mecanic = 0;
                while (!input_mecanic) {
                    cout << "A aparut o problema la camion!\n";
                    system("pause");
                    system("cls");
                    cout << "Introdu numele mecanicului dorit: \n";
                    cin >> mecanic_nume >> mecanic_prenume;
                    system("cls");
                    cout << "Introdu rata pe ora: ";
                    cin >> rata_mecanic;
                    system("cls");
                    cout << "Mecanicul " << mecanic_nume << " " << mecanic_prenume << " va fi platit " << rata_mecanic << "$ pe ora pentru a repara camionul. Sunt corecte datele? \n";
                    cout << "1.Da\n";
                    cout << "2.Nu\n";
                    cin >> input_mecanic;
                }
                mecanic m1;
                m1.set_mecanic(mecanic_nume, mecanic_prenume, rata_mecanic);
                system("cls");
                trimite_mecanic(camioane[input2 - 1], m1);
                cout << "Camionul este reparat!\n";
                system("cls");
                cout << "Doriti sa afisati detaliile mecanicului responsabil cu reparatia camionului? \n";
                int input_detalii_mecanic;
                cout << "1.Da\n";
                cout << "2.Nu\n";
                cin >> input_detalii_mecanic;
                system("cls");
                if (input_detalii_mecanic == 1) cout << m1;
            }


            cout << "Introdu incarcatura de cereale: \n";
            double incarcatura;
            cin >> incarcatura;
            system("cls");
            camioane[input2 - 1].cursa_activa(incarcatura);
            cout << "Tipul cerealelor: " << endl;
            cout << "1.Porumb" << endl;
            cout << "2.Orz" << endl;
            cout << "3.Rapita" << endl;
            int cereale;
            cin >> cereale;
            system("cls");
            if (cereale > 3 || cereale < 1)
            {
                cout << "Cod cereale inexistent!";
                return 0;
            }
            camioane[input2 - 1].set_inactiv();
            cout << "Profitul brut pe aceasta cursa este: ";
            double profit_brut = camioane[input2 - 1].profit(cereale);
            cout << profit_brut << '$' << endl;
            system("pause");
            system("cls");
            cout << "Introdu numele contabilului dorit: ";
            string nume, prenume;
            cin >> nume >> prenume;
            char nume_sef[] = "Alexa";
            char prenume_sef[] = "Constantin";
            contabil cont1(nume_sef, prenume_sef, 7000);
            cont1.set_contabil(nume, prenume, 3000);
            system("cls");
            cout << "Profitul net dupa aceasta cursa este: ";
            cout << cont1.taxe_profit(profit_brut) << "$" << endl;
            cout << "Doresti sa afisezi detaliile despre cursa efectuata?" << endl;
            cout << "1.Da" << endl;
            cout << "2.Nu" << endl;
            cin >> input;
            system("cls");
            if (input == 1) {
                camioane[input2 - 1].afisare();
                cont1.afisare();
            }
            system("pause");
            system("cls");
            cout << "Doresti sa revii la meniul de inceput?" << endl;
            cout << "1.Da" << endl;
            cout << "2.Nu" << endl;
            cin >> input;
            if (input == 1) inceput = 1;
            if (input == 2) inceput = 0;
            system("cls");
        }

    }

    delete[] camioane;

    return 0;
}

/*
IDEI

in meniu la 2 pot sa fac ceva pentru plantare si recoltare
si camioanele sa plece de la baza doar daca este un numar suficient de tone


la 2 cu recoltarea poate sa fie
este in exercitii o metoda care tine minte de cate ori s a facut ceva,si as putea sa fac asta pentru o tip de planta
si asta se poate reseta doar din meniu
fiecare tip de planta care are de recoltat o sa aiba locul in fisierul de recoltare,in care o sa se retine de cate ori a fost recoltat chiar daca se inchiderularea
si fiecare are un numar maxim de recoltari, daca se termina trebuie plantat probabil la punctul 3
asta la counter se rezolva usor cu metode statice

*/
/*
CERINTE PROIECT DE BIFAT
FARA DATE PUBLICE !!!!

MOSTENIRE                     2p
-minim 2 ierarhii de mostenire(bazele si clasa urm diferite)
-minim 2 modificatori de acces
-o clasa cu mostenire multipla
-cel puțin o dată un constructor (cu parametri) dintr-o clasă de bază,
folosind o listă de inițializare în constructorul clasei copil
-minim 2 date membru si o meteoda sa fie protected

VIRUAL                    2p
-minim o interfata(clasa doar cu metode virtuale si destructor birtual
-minim o clasa de baza abstracta
-trebuie folosit destructor virtual
-2 metode virtuale supreascrise in mostenire

POLIMORFISM LA EXECUTIE                    2p
-minim 2 locuri cu polimorfism la exec(prin pointeri)
-2 instante de upcasting
-1 downcast

EXCEPTII             2p
-minim 1 tip  de exceptie custom
-exceptii in minim 2 functii/ metode
-minim un try...catch care sa prinda o eroare facuta intentionat, si sa o rezolve intr-un fel
-1 try....catch care sa prinda o exceptie, sa o proceseze si sa rearunce un alt tip de exeptie din catch

VARIABILE SI METODE STATICE                1p
-minim 1 variabila statica
-cel putin 2 metode statice(macar 1 sa foloseasca variabila de sus)

BONUS   2p
mostenire in diamant
utilizarea unei lambda expresii

oficiu 1p
*/

/*
KNOWN PROBLEMS


*/