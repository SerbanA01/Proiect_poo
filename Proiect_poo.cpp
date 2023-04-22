#include <iostream>
#include <cstring>
#include <cstdlib>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

int stricat;
class camion {
    char* nr_inmatriculare;
    double greutate;
    bool activ;
    double masa_net;
    int ct;
public:
    camion(const char* numar, double gr_camion) {
        nr_inmatriculare = new char[strlen(numar) + 1];
        strcpy_s(nr_inmatriculare, strlen(numar) + 1, numar);
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
    ~camion() {
        delete[] nr_inmatriculare;
    }

};
struct nume_prenume {
    char nume[25];
    char prenume[75];
};



class sef {
    char* nume, * prenume;
    char sefi[10][30];
    double profit[55] = { 0 };
    int surse_profit = 0;
    double salariu;
public:
    sef() : nume(nullptr), prenume(nullptr), salariu(0.0) {}
    sef(char* nu, char* pr, double sal) {
        nume = new char[strlen(nu) + 1];
        strcpy_s(nume, strlen(nu) + 1, nu);
        prenume = new char[strlen(pr) + 1];
        strcpy_s(prenume, strlen(pr) + 1, pr);
        salariu = sal;
    }
    void adaugare_profit(double income) {
        profit[++surse_profit] = income;
    }
    nume_prenume get_nume_prenume() {
        nume_prenume sef_names;
        strcpy_s(sef_names.nume, strlen(nume) + 1, nume);
        strcpy_s(sef_names.prenume, strlen(prenume) + 1, prenume);
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
    ~sef() {
        delete[] nume;
        delete[] prenume;
    }

};
class contabil {
    char* nume, * prenume;
    double salariu;
    sef sef_contabil;

public:
    contabil() : nume(nullptr), prenume(nullptr), salariu(0) {}
    contabil(char* nume_sef, char* prenume_sef, double sa) : nume(nullptr), prenume(nullptr), salariu(0), sef_contabil(nume_sef, prenume_sef, sa) {}


    void set_contabil(char* n, char* p, double s) {
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
    char nume[15], prenume[15];
    double salariu;
    char vehicul;
    sef sef_sofer;
};
class mecanic {
    char nume[15], prenume[15];
    double rata;
public:
    mecanic() {}
    void set_mecanic(char nu[], char prn[], double r) {
        strcpy_s(nume, strlen(nu) + 1, nu);
        strcpy_s(prenume, strlen(prn) + 1, prn);
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
void trimite_mecanic(camion& c, mecanic m) {
    c.set_inactiv();
    camion c_copy = c;
    m.repara_camion(c_copy);
    //trebuie functie de trimis la mecanic

}
int main()
{
    bool inceput = 1;
    camion* camioane = new camion[3]{ camion("B123SLD",4500),camion("B124SLD",4500),camion("B125SLD",4500) };

    while (inceput) {
        //Inceput meniu interactiv
        cout << "Alege actiunea dorita: \n";
        cout << "1.Trimite camion in cursa\n";
        cout << "2. \n";
        cout << "3. \n";
        int input;
        cin >> input;
        system("cls");
        if (input == 1) {
            //se alege numarul de inmatriculare
            cout << "Alege numarul de inmatriculare: \n";
            cout << "1.B123SLD" << endl;
            cout << "2.B124SLD" << endl;
            cout << "3.B125SLD" << endl;
            int input2;
            cin >> input2;
            system("cls");
            if (input2 == 1) {
                if (camioane[0].get_contor_curse() == 0) {
                    srand(time(nullptr));
                    int random_nr = rand();
                    stricat = (random_nr % 6) + 1;
                }
                camioane[0].mareste_ct();
                int contor = camioane[0].get_contor_curse();
                stricat = 1; //sterge aici dupa !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
                if (stricat == contor) {
                    camioane[0].set_inactiv();
                    char mecanic_nume[20], mecanic_prenume[20];
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
                    trimite_mecanic(camioane[0], m1);

                    cout << m1;
                }


                cout << "Introdu incarcatura de cereale: \n";
                double incarcatura;
                cin >> incarcatura;
                system("cls");
                camioane[0].cursa_activa(incarcatura);
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
                //dupa alegerea cerealelor se calculeaza profitul net si brut
                camioane[0].set_inactiv();
                cout << "Profitul brut pe aceasta cursa este: ";
                double profit_brut = camioane[0].profit(cereale);
                cout << profit_brut << '$' << endl;
                system("pause");
                system("cls");
                cout << "Introdu numele contabilului dorit: ";
                char cont[25];
                cin.get();
                cin.getline(cont, 25);
                char* next_token = NULL;
                char* p;
                p = strtok_s(cont, " ", &next_token);
                int ct = 1;
                char nume[15];
                char prenume[45];
                while (p) {
                    if (ct == 1)
                        strcpy_s(nume, strlen(p) + 1, p), ct++;

                    else {
                        if (ct == 2)
                            strcpy_s(prenume, strlen(p) + 1, p), ct++;
                        else
                        {
                            strcat_s(prenume, strlen(prenume) + 2, " ");
                            strcat_s(prenume, strlen(prenume) + strlen(p) + 1, p);
                        }
                    }
                    p = strtok_s(NULL, " ", &next_token);
                }
                nume[strlen(nume)] = '\0';
                prenume[strlen(prenume)] = '\0';
                // aparent merge doar cin >> nume >>prenume sa modifici cand te apuci de partea a 2 a din proiect
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
                    camioane[0].afisare();
                    cont1.afisare();
                }
            }









            //input == 2
            if (input2 == 2) {
                if (camioane[1].get_contor_curse() == 0) {
                    srand(time(nullptr));
                    int random_nr = rand();
                    stricat = (random_nr % 6) + 1;
                }
                camioane[1].mareste_ct();
                int contor = camioane[1].get_contor_curse();
                if (stricat == contor) {
                    camioane[1].set_inactiv();
                    char mecanic_nume[20], mecanic_prenume[20];
                    double rata_mecanic;
                    int input_mecanic = 0;
                    while (!input_mecanic) {
                        cout << "A aparut o problema la camion!\n";
                        cout << "Introdu numele mecanicului dorit: \n";
                        cin >> mecanic_nume >> mecanic_prenume;
                        system("cls");
                        cout << "Introdu rata pe ora: ";
                        cin >> rata_mecanic;
                        cout << "Mecanicul " << mecanic_nume << " " << mecanic_prenume << " va fi platit " << rata_mecanic << "$ pe ora pentru a repara camionul. Sunt corecte datele? \n";
                        cout << "1.Da\n";
                        cout << "2.Nu\n";
                        cin >> input_mecanic;
                    }
                    mecanic m1;
                    m1.set_mecanic(mecanic_nume, mecanic_prenume, rata_mecanic);
                    cout << m1;
                }
                cout << "Introdu incarcatura de cereale: \n";
                double incarcatura;
                cin >> incarcatura;
                system("cls");
                camioane[1].cursa_activa(incarcatura);
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
                //dupa alegerea cerealelor se calculeaza profitul net si brut
                camioane[1].set_inactiv();
                cout << "Profitul brut pe aceasta cursa este: ";
                double profit_brut = camioane[1].profit(cereale);
                cout << profit_brut << '$' << endl;
                system("pause");
                system("cls");
                cout << "Introdu numele contabilului dorit: ";
                char cont[25];
                cin.get();
                cin.getline(cont, 25);
                char* next_token = NULL;
                char* p;
                p = strtok_s(cont, " ", &next_token);
                int ct = 1;
                char nume[15];
                char prenume[45];
                while (p) {
                    if (ct == 1)
                        strcpy_s(nume, strlen(p) + 1, p), ct++;

                    else {
                        if (ct == 2)
                            strcpy_s(prenume, strlen(p) + 1, p), ct++;
                        else
                        {
                            strcat_s(prenume, strlen(prenume) + 2, " ");
                            strcat_s(prenume, strlen(prenume) + strlen(p) + 1, p);
                        }
                    }
                    p = strtok_s(NULL, " ", &next_token);
                }
                nume[strlen(nume)] = '\0';
                prenume[strlen(prenume)] = '\0';
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
                    camioane[1].afisare();
                    cont1.afisare();
                }
            }
            //input2 == 3
            if (input2 == 3) {
                if (camioane[2].get_contor_curse() == 0) {
                    srand(time(nullptr));
                    int random_nr = rand();
                    stricat = (random_nr % 6) + 1;
                }
                camioane[2].mareste_ct();
                int contor = camioane[2].get_contor_curse();
                if (stricat == contor) {
                    camioane[2].set_inactiv();
                    char mecanic_nume[20], mecanic_prenume[20];
                    double rata_mecanic;
                    int input_mecanic = 0;
                    while (!input_mecanic) {
                        cout << "A aparut o problema la camion!\n";
                        cout << "Introdu numele mecanicului dorit: \n";
                        cin >> mecanic_nume >> mecanic_prenume;
                        system("cls");
                        cout << "Introdu rata pe ora: ";
                        cin >> rata_mecanic;
                        cout << "Mecanicul " << mecanic_nume << " " << mecanic_prenume << " va fi platit " << rata_mecanic << "$ pe ora pentru a repara camionul. Sunt corecte datele? \n";
                        cout << "1.Da\n";
                        cout << "2.Nu\n";
                        cin >> input_mecanic;
                    }
                    mecanic m1;
                    m1.set_mecanic(mecanic_nume, mecanic_prenume, rata_mecanic);
                    cout << m1;
                }
                cout << "Introdu incarcatura de cereale: \n";
                double incarcatura;
                cin >> incarcatura;
                system("cls");
                camioane[2].cursa_activa(incarcatura);
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
                //dupa alegerea cerealelor se calculeaza profitul net si brut
                camioane[2].set_inactiv();
                cout << "Profitul brut pe aceasta cursa este: ";
                double profit_brut = camioane[1].profit(cereale);
                cout << profit_brut << '$' << endl;
                system("pause");
                system("cls");
                cout << "Introdu numele contabilului dorit: ";
                char cont[25];
                cin.get();
                cin.getline(cont, 25);
                char* next_token = NULL;
                char* p;
                p = strtok_s(cont, " ", &next_token);
                int ct = 1;
                char nume[15];
                char prenume[45];
                while (p) {
                    if (ct == 1)
                        strcpy_s(nume, strlen(p) + 1, p), ct++;

                    else {
                        if (ct == 2)
                            strcpy_s(prenume, strlen(p) + 1, p), ct++;
                        else
                        {
                            strcat_s(prenume, strlen(prenume) + 2, " ");
                            strcat_s(prenume, strlen(prenume) + strlen(p) + 1, p);
                        }
                    }
                    p = strtok_s(NULL, " ", &next_token);
                }
                nume[strlen(nume)] = '\0';
                prenume[strlen(prenume)] = '\0';
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
                    camioane[2].afisare();
                    cont1.afisare();
                }
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

contabil-taxe pe profit la curse
profitul e trimis la contabil e facut dupa tva
profitul brut ajunge la sef si il pune intr o variabila sau vector

trebuie ceva pentru afisarea unei clase si cumva sa implic directorii

pentru mecanic fac un fel de statie care copiaza datele camionului stricat

deci deci se strica camionul: 2 optiuni, 1 luam unul inchiriat care se deduce din profit sau 2 asteptam sa fie reparat de mecanic

in meniu la 2 pot sa fac ceva pentru plantare si recoltare
si camioanele sa plece de la baza doar daca este un numar suficient de tone

*/
/*
CERINTE PROIECT DE BIFAT
FARA DATE PUBLICE !!!!

minim 4 clase          FACUT         |
2 clase prin compunere      FACUT    |2 PUNCTE

3 getteri 3 setteri                 am 4 getteri si 3 setter, discutabil pe salariul la contabil       FACUT    |
2 metode de logica de business      FACUT                                                                       |    2 P
2 clase metoda de afisare           FACUT                                                                       |
1 clasa overload la <<          pe clasa service      FACUT                                                     |

3 clase constructori         FACUT    0.5P

2 clase implementat constructor copiere si overwrite =
1 clasa cu alocare dinamica(una din cele de mai sus)

1 clasa sa faca alocare dinamica(1 obiect sau vector de obiecte)    FACUT   |
memoria trebuie si dezalocata            FACUT                              | 1 PUNCT
1 clasa cu destructor       FACUT                                           |


BONUS
meniu interactiv cu:
citirea de la tastatura si crearea a cel putin 3 tipuri de obiecte
afisarea acestor obiecte
apelarea unei metode

implementare constructor de mutare si overwrite = mutare pentru
o clasa cu aocare dinamica

definire clasa imbricata


TOTAL MOMENTAN: 7.5p
*/