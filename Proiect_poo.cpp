#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <fstream>
#include <exception>
#include <vector>
#define _CRT_SECURE_NO_WARNINGS 1
using namespace std;
class exceptie_custom : public exception {
    string eroare;
public:
    exceptie_custom(string e) : eroare(e) {}
    string what() {
        return eroare;
    }

};



int stricat;
class counter {
    static int count, counta, count_plante_udare, count_plante_tratare, count_animale_udare, count_animale_tratare;
public:
    static void readcount() {
        ifstream fin("counter.txt");
        fin >> count >> counta >> count_plante_udare >> count_plante_tratare >> count_animale_udare >> count_animale_tratare;
        fin.close();

    }
    static void writecount() {
        ofstream fout("counter.txt");
        fout << count << " " << counta << " " << count_plante_udare << " " << count_plante_tratare << " " << count_animale_udare << " " << count_animale_tratare;
        fout.close();
    }
    static int getcount() {
        return count;
    }
    static int getcount_animale() {
        return counta;
    }
    static int getcount_plante_udare() {
        return count_plante_udare;
    }
    static int getcount_plante_tratare() {
        return count_plante_tratare;
    }
    static int getcount_animale_udare() {
        return count_animale_udare;
    }
    static int getcount_animale_tratare() {
        return count_animale_tratare;
    }
    static void countup() {
        count++;
    }
    static void countup_animale() {
        counta++;
    }
    static void countdown() {
        count--;
    }
    static void reset() {
        count = 0;
    }
    static void reset_animale() {
        counta = 0;
    }
    static void reset_plante_udare() {
        count_plante_udare = 0;
    }
    static void reset_plante_tratare() {
        count_plante_tratare = 0;
    }
    static void reset_animale_udare() {
        count_animale_udare = 0;
    }
    static void reset_animale_tratare() {
        count_animale_tratare = 0;
    }
    static void countup_plante_tratare() {
        count_plante_tratare++;
    }
    static void countup_plante_udare() {
        count_plante_udare++;
    }
    static void countup_animale_tratare() {
        count_animale_tratare++;
    }
    static void countup_animale_udare() {
        count_animale_udare++;
    }
};
class informatii {
    static int inaltime_porumb, inaltime_orz, inaltime_rapita, greutate_vaci, greutate_oi;
public:
    static void citire() {
        ifstream fin("informatii.txt");
        fin >> inaltime_porumb >> inaltime_orz >> inaltime_rapita >> greutate_vaci >> greutate_oi;
        fin.close();
    }
    static void write() {
        ofstream fout("informatii.txt");
        fout << inaltime_porumb << inaltime_orz << inaltime_rapita << greutate_vaci << greutate_oi;
        fout.close();
    }
    static void creste_inaltime_porumb() {
        inaltime_porumb++;
    }
    static void creste_inaltime_orz() {
        inaltime_orz++;
    }
    static void creste_inaltime_rapita() {
        inaltime_rapita++;
    }

    static void creste_greutate_vaci() {
        greutate_vaci++;
    }
    static void creste_greutate_oi() {
        greutate_oi++;
    }
    static int get_inaltime_porumb() {
        return inaltime_porumb;
    }
    static int get_inaltime_orz() {
        return inaltime_orz;
    }
    static int get_inaltime_rapita() {
        return inaltime_rapita;
    }
    static int get_greutate_vaci() {
        return greutate_vaci;
    }
    static int get_greutate_oi() {
        return greutate_oi;
    }
    static void reset_greutate_vaci() {
        greutate_vaci = 0;
    }
    static void reset_greutate_oi() {
        greutate_oi = 0;
    }
    static void reset_inaltime() {
        inaltime_orz = inaltime_porumb = inaltime_rapita = 0;
    }
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
        masa_net = greutate;//ideea e ca toate camionele sunt facute de la inceput, perosna doar alege care
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
    mecanic() { rata = 0; }
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
protected:
    virtual void feed() = 0; //udarea la plante si dat de mancare la animale
    //aici trebuie un couter si o sa se faca astea odata la n rulari
    //mai trebuie adaugata o metoda pur virtuala
    virtual void tratare() = 0;
public:
    virtual ~ProduseFerma() {}
};
class Plante : virtual public ProduseFerma {
protected:
    string tip_sol;
    string denumire;
    double v = 0, c = 0;
    int timp_udare;
    int timp_tratare;
public:
    Plante(string a, string b) :tip_sol(a), denumire(b) {
        ifstream fin("udare_tratare.txt");
        fin >> timp_udare >> timp_tratare;
        fin.close();
    }
    bool operator==(const Plante& p) {
        return (this->denumire == p.denumire);
    };
    int get_timp_tratare() {
        return timp_tratare;
    }
    int get_timp_udare() {
        return timp_udare;
    }
protected:
    virtual void tratare() override {
        cout << "Este nevoie de tratare pentru paraziti in plante!\n";
        cout << "Se cumpara medicamentele necesare..\n";
        system("pause");
        system("cls");
        cout << "Pretul pentru medicamente este de 50$, se va trimite factura la seful contabil.\n";
        system("pause");
        system("cls");
        sef temporar("", "", 2500);
        temporar.adaugare_profit(-50);
        cout << "Se trateaza plantele...\n";
        system("pause");
        system("cls");
        counter::reset_plante_tratare();
        counter::writecount();


    }
    virtual void feed() override {
        cout << "Este nevoie sa se irige plantele!\n";
        cout << "Se pornesc sistemele de irigare...\n";
        system("pause");
        system("cls");
        counter::reset_plante_udare();
        counter::writecount();
        cout << "Plantele sunt irigate!\n";
        system("pause");
        system("cls");

    }
public:
    void aplicare_tratare() {
        cout << "Se verifica daca este nevoie de tratare pentru parazitii din plante...";
        system("pause");
        system("cls");
        if (counter::getcount_plante_tratare() >= timp_tratare) {
            tratare();
        }
        else {
            cout << "Nu este nevoie de tratare pentru plante.\n";
            system("pause");
            system("cls");
        }
    }
    void aplicare_irigare() {
        cout << "Se verifica nivelele de umiditate din sol...\n";
        system("pause");
        system("cls");
        if (counter::getcount_plante_udare() >= timp_udare) feed();
        else {
            cout << "Nu este nevoie de udare pentru plante.\n";
            system("pause");
            system("cls");
        }
    }
    virtual void afisare() {
        cout << "sau denumirea in latina: " << denumire << " creste pe un " << tip_sol;
    }
    void set_v(double va) {
        v = va;
    }
    void set_c(double ca) {
        c = ca;
    }
protected:
    double calculeaza_profit() {
        return v - c;
    }
public:
    double afisare_profit() {
        return calculeaza_profit();
    }
    virtual ~Plante() {}


};

class Animale : virtual public ProduseFerma {
    string denumire;
    string mancare;
    int timp_mancare, timp_tratare, a, b;
public:
    Animale(string a, string b) : denumire(a), mancare(b) {
        ifstream fin("udare_tratare.txt");
        fin >> a >> b >> timp_mancare >> timp_tratare;
        fin.close();
    }
    int get_timp_mancare() {
        return timp_mancare;
    }
    int get_timp_tratare() {
        return timp_tratare;
    }
    bool operator==(const Animale& a) {
        return(this->denumire == a.denumire);
    };
    void afisare() {
        cout << "Denumirea in latina este " << denumire << ", ea prefera acest tip de mancare: " << mancare << endl;
    }
protected:
    virtual void tratare() override {
        cout << "Este nevoie de tratare pentru paraziti din animale!\n";
        cout << "Se cumpara medicamentele necesare..\n";
        system("pause");
        system("cls");
        cout << "Pretul pentru medicamente este de 150$, se va trimite factura la seful contabil.\n";
        system("pause");
        system("cls");
        sef temporar("", "", 2500);
        temporar.adaugare_profit(-150);
        cout << "Se trateaza animalele...\n";
        system("pause");
        system("cls");
        counter::reset_animale_tratare();
        counter::writecount();
    }
    virtual void feed() override {
        cout << "da";
    }
public:
    void aplicare_tratare() {
        cout << "Se verifica daca este nevoie de tratare pentru animale...\n";
        system("pause");
        system("cls");
        if (counter::getcount_animale_tratare() >= timp_tratare) tratare();
        else {
            cout << "Nu este nevoie de tratare pentru animale.\n";
            system("pause");
            system("cls");
        }
    }
};

class ProduseAlimentatie : public Plante, public Animale {
    void feed() {
        Plante::feed();
    }
    void tratare() {
        Animale::tratare();
    }

};

class Orz : public Plante {
    double pret_vanzare = 200;
public:
    Orz(string s1, string s2) : Plante(s1, s2) {}
    void afisare() override {
        cout << "Orzul " << "sau denumirea in latina: " << denumire << " creste pe un " << tip_sol << endl;
    }
    void afisare2() {
        //aici apelez profitul
    }
    double get_pret() { return pret_vanzare; }
    virtual ~Orz() {}

};

class Orz_seed : protected Orz {
    double pret;
public:
    Orz_seed(double p, string s1, string s2) : Orz(s1, s2), pret(p) {

    }

};

class Porumb : public Plante {
    double pret_vanzare = 200;

public:
    Porumb(string s1, string s2) : Plante(s1, s2) {
    }
    void afisare() override {
        cout << "Porumbul" << " sau denumirea in latina: " << denumire << " creste pe un " << tip_sol << endl;
    }
    double get_pret() { return pret_vanzare; }
    virtual ~Porumb() {}
};

class Porumb_seed : private Porumb {
    double pret;
public:
    Porumb_seed(double p, string s1, string s2) : Porumb(s1, s2), pret(p) {

    }

};

class Rapita : public Plante {
    double pret_vanzare = 400;
    int timp_udare;
public:
    Rapita(string s1, string s2) : Plante(s1, s2) {}
    void afisare() override {
        cout << "Rapita " << "sau denumirea in latina: " << denumire << " creste pe un " << tip_sol << endl;
    }
    double get_pret() { return pret_vanzare; }
    double get_timp() { return timp_udare; }
    virtual ~Rapita() {}
};

class Rapita_seed : private Rapita {
    double pret;
public:
    Rapita_seed(double p, string s1, string s2) : Rapita(s1, s2), pret(p) {

    }
};



class Bovina : public Animale {
    double pret_litru = 2;
    double pret_carne = 3000;
public:
    Bovina(string s1, string s2) : Animale(s1, s2) {}
    double get_pret_litru() {
        return pret_litru;
    }
    double get_pret_carne() {
        return pret_carne;
    }
};

class Ovina : public Animale {
    double pret_litru = 3;
    double pret_carne = 500;
public:
    Ovina(string s1, string s2) : Animale(s1, s2) {}
    double get_pret_litru() {
        return pret_litru;
    }
    double get_pret_carne() {
        return pret_carne;
    }
};

class inventar {
    struct detalii_plante {
        Plante plant;
        int cantitate;
        detalii_plante(Plante& plant, int cantitate) :plant(plant), cantitate(cantitate) {}
        bool operator==(const detalii_plante& other) {
            return (plant == other.plant);
        }
    };
    vector<detalii_plante> plante_disponibile;

public:

    void adauga_plante(Plante& plant, int c) {
        detalii_plante detalii(plant, c);
        plante_disponibile.push_back(detalii);
    }
    void elimina_plante(Plante& plant, int c) {
        for (auto& detalii : plante_disponibile) {
            if (detalii.plant == plant) {
                detalii.cantitate -= c;
                if (detalii.cantitate <= 0)
                    plante_disponibile.erase(remove(plante_disponibile.begin(), plante_disponibile.end(), detalii), plante_disponibile.end());
                break;
            }
        }
    }


};



int counter::count = 0;
int counter::count_animale_udare = 0;
int counter::count_plante_udare = 0;
int counter::count_animale_tratare = 0;
int counter::count_plante_tratare = 0;
int counter::counta = 0;
int informatii::inaltime_porumb = 0;
int informatii::inaltime_orz = 0;
int informatii::inaltime_rapita = 0;
int informatii::greutate_vaci = 0;
int informatii::greutate_oi = 0;
double costuri;
bool verificare(int n) {
    if (n > 3 || n < 1)
        throw(exceptie_custom("Eroare! Nu exista aceasta optiune!"));
    else return 1;
}
bool verificare2(int n) {
    if (n > 4 || n < 1)
        throw(exceptie_custom("Eroare! Nu exista aceasta optiune! Te rog reporneste sistemul..."));
    else return 1;
}
int main()
{
    bool inceput = 1;
    camion* camioane = new camion[3]{ camion("B123SLD",4500),camion("B124SLD",4500),camion("B125SLD",4500) };

    while (inceput) {
        cout << "Alege actiunea dorita: \n";
        cout << "1.Trimite camion in cursa\n";
        cout << "2.Observa si modifica detaliile despre productiile din ferma \n";
        cout << "3. \n";
        int input;
        cin >> input;
        counter::readcount();
        if (counter::getcount() != 0) {
            counter::countup_plante_tratare();
            counter::countup_plante_udare();
            counter::writecount();
        }
        if (counter::getcount_animale() != 0) {
            counter::countup_animale_tratare();
            counter::countup_animale_udare();
            counter::writecount();
        }
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
            bool codcorect = 0;
            int cereale;
            while (!codcorect) {
                cin >> cereale;
                system("cls");
                try {
                    if (cereale >= 1 && cereale <= 3)
                    {
                        cout << "Cod inregistrat! " << endl;
                        codcorect = 1;
                        system("pause");
                        system("cls");
                    }
                    else { throw(cereale); }
                }
                catch (int cod) {
                    cout << "EROARE! Cod Inexistent! Introdu din nou un cod: " << endl;
                    cout << "Tipul cerealelor: " << endl;
                    cout << "1.Porumb" << endl;
                    cout << "2.Orz" << endl;
                    cout << "3.Rapita" << endl;
                }
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
        else if (input == 2) {
            //counter aici verific daca este prima data, atunci se planteaza si se cumpara animale 
            counter::readcount();
            if (counter::getcount() == 0 && counter::getcount_animale() == 0) {
                cout << "Momentan nu aveti nimic inregistrat alegeti din urmatoarele optiuni: " << endl;
                cout << "1.Cumpara semintele necesare pentru plantare\n";
                cout << "2.Cumpara animale\n";
                cout << "3.Ambele\n";
                int input_cumparare;
                cin >> input_cumparare;

                if (verificare(input_cumparare) && input_cumparare == 1) {  //aici ma ocup de plante 

                    system("cls");
                    cout << "Se cumpara un set de seminte din fiecare planta...\n";
                    system("pause");
                    system("cls");

                    Plante* orz = new Orz("sol bine drenat cu textura medie, niveluri moderate de fertilitate si pH neutru sau usor alcalin", "Hordeum vulgare");
                    Plante* porumb = new Porumb("sol argilos", "Zea mays");
                    Plante* rapita = new Rapita("sol Ioamy", "Brassica napus");
                    Rapita* downcast = dynamic_cast<Rapita*>(rapita);
                    Orz_seed os1(70, "", "");
                    Porumb_seed ps1(100, "", "");
                    Rapita_seed rs1(80, "", "");
                    costuri = 250;
                    cout << "Doresti sa vezi detalii despre semintele achizitionate?\n";
                    cout << "1.Da\n";
                    cout << "2.Nu\n";
                    int raspuns;
                    cin >> raspuns;
                    system("cls");
                    if (raspuns == 1) {
                        orz->afisare();
                        porumb->afisare();
                        if (downcast != nullptr) {
                            downcast->afisare();
                        }
                        cout << "Pretul semintelor este de 250$/kg\n";
                        system("pause");
                        system("cls");
                    }
                    delete porumb;
                    delete rapita;
                    delete orz;
                    cout << "Trebuie ales numele unui fermieri, te rog introdu numele: \n";
                    string nume_fer;
                    string prenume_fer;
                    cin >> nume_fer >> prenume_fer;
                    system("cls");
                    cout << "Gestionarea plantelor se poate face din meniu acum \n";
                    system("pause");
                    sef fermier(nume_fer, prenume_fer, 2500);
                    fermier.adaugare_profit(-250);
                    counter::countup();
                    counter::writecount();
                    system("cls");
                }
                else if (verificare(input_cumparare) && input_cumparare == 2) { //aici ma ocup de animale
                    system("cls");
                    cout << "Se cumpara 2 tipuri de bovine si 2 de ovine...\n";
                    system("pause");
                    system("cls");
                    Bovina vaca1("Vita Holstein", "furaje pe baza de fan");
                    Bovina vaca2("Vita Hereford", "furaje pe baza de iarba");
                    Ovina oaie1("Oaie Dorper", "siloz de iarba");
                    Ovina oaie2("Valais Blacknose", "furaje concentrate");
                    Animale* ptr;
                    ptr = &vaca1;
                    Animale* ptr2;
                    ptr2 = &vaca2;
                    Animale* ptr3;
                    ptr3 = &oaie1;
                    Animale* ptr4;
                    ptr4 = &oaie2;

                    cout << "Doresti sa vezi detaliile despre animalele achizitionate?\n";

                    cout << "1.Da\n";
                    cout << "2.Nu\n";
                    int input_animale;
                    cin >> input_animale;
                    system("cls");
                    if (input_animale == 1) {
                        ptr->afisare();
                        ptr2->afisare();
                        ptr3->afisare();
                        ptr4->afisare();
                        system("pause");
                        system("cls");
                    }
                    cout << "Gestionarea animalelor se poate face din meniu acum \n";
                    system("pause");
                    system("cls");
                    counter::countup_animale();
                    counter::writecount();
                }
                else { // aici le am pe ambele
                    system("cls");
                    cout << "Se cumpara un set de seminte din fiecare planta...\n";
                    system("pause");
                    system("cls");

                    Plante* orz = new Orz("sol bine drenat cu textura medie, niveluri moderate de fertilitate si pH neutru sau usor alcalin", "Hordeum vulgare");
                    Plante* porumb = new Porumb("sol argilos", "Zea mays");
                    Plante* rapita = new Rapita("sol Ioamy", "Brassica napus");
                    Rapita* downcast = dynamic_cast<Rapita*>(rapita);
                    Orz_seed os1(70, "", "");
                    Porumb_seed ps1(100, "", "");
                    Rapita_seed rs1(80, "", "");

                    cout << "Doresti sa vezi detalii despre semintele achizitionate?\n";
                    cout << "1.Da\n";
                    cout << "2.Nu\n";
                    int raspuns;
                    cin >> raspuns;
                    system("cls");
                    if (raspuns == 1) {
                        orz->afisare();
                        porumb->afisare();
                        if (downcast != nullptr) {
                            downcast->afisare();
                        }
                        cout << "Pretul semintelor este de 250$/kg\n";
                        system("pause");
                        system("cls");
                    }
                    delete porumb;
                    delete rapita;
                    delete orz;
                    cout << "Trebuie ales numele unui fermieri, te rog introdu numele: \n";
                    string nume_fer;
                    string prenume_fer;
                    cin >> nume_fer >> prenume_fer;
                    system("cls");
                    cout << "Gestionarea plantelor se poate face din meniu acum \n";
                    cout << "Urmeaza animalele\n";
                    system("pause");
                    system("cls");
                    sef fermier(nume_fer, prenume_fer, 2500);
                    fermier.adaugare_profit(-250);
                    counter::countup();
                    system("cls");
                    cout << "Se cumpara 2 tipuri de bovine si 2 de ovine...\n";
                    system("pause");
                    system("cls");
                    Bovina vaca1("Vita Holstein", "furaje pe baza de fan");
                    Bovina vaca2("Vita Hereford", "furaje pe baza de iarba");
                    Ovina oaie1("Oaie Dorper", "siloz de iarba");
                    Ovina oaie2("Valais Blacknose", "furaje concentrate");
                    Animale* ptr;
                    ptr = &vaca1;
                    Animale* ptr2;
                    ptr2 = &vaca2;
                    Animale* ptr3;
                    ptr3 = &oaie1;
                    Animale* ptr4;
                    ptr4 = &oaie2;

                    cout << "Doresti sa vezi detaliile despre animalele achizitionate?\n";

                    cout << "1.Da\n";
                    cout << "2.Nu\n";
                    int input_animale;
                    cin >> input_animale;
                    system("cls");
                    if (input_animale == 1) {
                        ptr->afisare();
                        ptr2->afisare();
                        ptr3->afisare();
                        ptr4->afisare();
                        system("pause");
                        system("cls");
                    }
                    cout << "Gestionarea animalelor se poate face din meniu acum \n";
                    system("pause");
                    system("cls");
                    counter::countup_animale();
                    counter::writecount();
                }

            }
            else {
                //o sa fac de tipul ca daca se planteaza doar plante sus si aici doreste cineva sa faca ceva cu animalele sa dea eroarea
                //sau sa ii zica ca nu s au cumparat animalele si sa fac un meniu cum am facut pentru plante
                system("cls");
                cout << "Alege o optiune din urmatoarea lista: \n";
                cout << "1.Informatii generale\n";
                cout << "2.Porneste sistemele de irigare pentru plante\n";
                cout << "3.Trateaza plantele\n";
                cout << "4.Trateaza animalele\n";
                int input_2;
                cin >> input_2;
                system("cls");
                if (input_2 == 1 && verificare2(input_2)) {
                    cout << "Doresti sa vezi informatii despre: \n";
                    cout << "1.Plante\n";
                    cout << "2.Animale\n";
                    int input_informatii;
                    cin >> input_informatii;
                    if (input_informatii == 1) {                        //aici se poate face cu exceptia dupa ce inteleg ce trebuie facut
                        if (counter::getcount() == 0)//asta iseamna ca nu am plantat plante  
                        {
                            system("cls");
                            cout << "Nu aveti nicio planta in ferma!\n";
                            cout << "Doriti sa cumparati seminte? \n";
                            int in;
                            cout << "1.Da\n";
                            cout << "2.Nu\n";
                            cin >> in;
                            if (in == 1) {
                                system("cls");
                                cout << "Se cumpara un set de seminte din fiecare planta...\n";
                                system("pause");
                                system("cls");

                                Plante* orz = new Orz("sol bine drenat cu textura medie, niveluri moderate de fertilitate si pH neutru sau usor alcalin", "Hordeum vulgare");
                                Plante* porumb = new Porumb("sol argilos", "Zea mays");
                                Plante* rapita = new Rapita("sol Ioamy", "Brassica napus");
                                Rapita* downcast = dynamic_cast<Rapita*>(rapita);
                                Orz_seed os1(70, "", "");
                                Porumb_seed ps1(100, "", "");
                                Rapita_seed rs1(80, "", "");

                                cout << "Doresti sa vezi detalii despre semintele achizitionate?\n";
                                cout << "1.Da\n";
                                cout << "2.Nu\n";
                                int raspuns;
                                cin >> raspuns;
                                system("cls");
                                if (raspuns) {
                                    orz->afisare();
                                    porumb->afisare();
                                    if (downcast != nullptr) {
                                        downcast->afisare();
                                    }
                                    cout << "Pretul semintelor este de 250$/kg\n";
                                    system("pause");
                                    system("cls");
                                }
                                delete porumb;
                                delete rapita;
                                delete orz;
                                cout << "Trebuie ales numele unui fermieri, te rog introdu numele: \n";
                                string nume_fer;
                                string prenume_fer;
                                cin >> nume_fer >> prenume_fer;
                                system("cls");
                                cout << "Gestionarea plantelor se poate face din meniu acum \n";
                                system("pause");
                                sef fermier(nume_fer, prenume_fer, 2500);
                                fermier.adaugare_profit(-250);
                                counter::countup();
                                counter::writecount();
                                system("cls");
                            }

                        }
                        else {
                            system("cls");
                            //aici afisam info plante
                            Plante p("", "");
                            Rapita r("", "");
                            Porumb po("", "");
                            Orz o("", "");
                            cout << "Rapita: Pret:" << r.get_pret() << "$   Timp intre udari: " << p.get_timp_udare() << " zile    Este recomandat sa se trateze o data la " << p.get_timp_tratare() << " zile" << endl;
                            cout << "Porumb: Pret:" << po.get_pret() << "$   Timp intre udari: " << p.get_timp_udare() << " zile    Este recomandat sa se trateze o data la " << p.get_timp_tratare() << " zile" << endl;
                            cout << "Orz: Pret:" << o.get_pret() << "$   Timp intre udari: " << p.get_timp_udare() << " zile    Este recomandat sa se trateze o data la " << p.get_timp_tratare() << " zile" << endl;
                            p.set_c(250);
                            p.set_v(600);
                            cout << "Profitul pe kilogram este: " << p.afisare_profit() << "$" << endl;

                        }
                    }
                    else {
                        if (counter::getcount_animale() == 0) {//asta inseamna ca nu am cumparat animale
                            system("cls");
                            cout << "Nu aveti niciun animal in ferma!\n";
                            cout << "Doriti sa cumparati animale? \n";
                            int in2;
                            cout << "1.Da\n";
                            cout << "2.Nu\n";
                            cin >> in2;
                            if (in2 == 1) {
                                system("cls");
                                cout << "Se cumpara 2 tipuri de bovine si 2 de ovine...\n";
                                system("pause");
                                system("cls");
                                Bovina vaca1("Vita Holstein", "furaje pe baza de fan");
                                Bovina vaca2("Vita Hereford", "furaje pe baza de iarba");
                                Ovina oaie1("Oaie Dorper", "siloz de iarba");
                                Ovina oaie2("Valais Blacknose", "furaje concentrate");
                                Animale* ptr;
                                ptr = &vaca1;
                                Animale* ptr2;
                                ptr2 = &vaca2;
                                Animale* ptr3;
                                ptr3 = &oaie1;
                                Animale* ptr4;
                                ptr4 = &oaie2;

                                cout << "Doresti sa vezi detaliile despre animalele achizitionate?\n";

                                cout << "1.Da\n";
                                cout << "2.Nu\n";
                                int input_animale;
                                cin >> input_animale;
                                system("cls");
                                if (input_animale) {
                                    ptr->afisare();
                                    ptr2->afisare();
                                    ptr3->afisare();
                                    ptr4->afisare();
                                    system("pause");
                                    system("cls");
                                }
                                cout << "Gestionarea animalelor se poate face din meniu acum \n";
                                system("pause");
                                system("cls");
                                counter::countup_animale();
                                counter::writecount();
                            }
                        }
                        else {
                            system("cls");
                            //aici afisam info animale
                            Animale an("", "");
                            Bovina b("", "");
                            Ovina ov("", "");
                            cout << "Bovina: Pret lapte per litru: " << b.get_pret_litru() << "$   Pret per unitate: " << b.get_pret_carne() << "$\n"
                                << "Este recomandata hranire de : " << an.get_timp_mancare() << "ori pe zi  Este recomandata verificarea si tratarea pentru paraziti o data la: "
                                << an.get_timp_tratare() << "zile" << endl;
                            cout << "Ovina: Pret lapte per litru: " << ov.get_pret_litru() << "$   Pret per unitate: " << ov.get_pret_carne() << "$\n"
                                << "Este recomandata hranire de: " << an.get_timp_mancare() << "ori pe zi   Este recomandata verificarea si tratarea pentru paraziti o data la: "
                                << an.get_timp_tratare() << "zile" << endl;
                            //vezi aici daca mai adaugi functia protected de profit
                        }
                    }


                }
                else if (input_2 == 2 && verificare2(input_2)) {//udare
                    Plante p("", "");
                    p.aplicare_irigare();
                }
                else if (input_2 == 3 && verificare2(input_2)) {//tratare
                    Plante p("", "");
                    p.aplicare_tratare();
                }
                else if (verificare2(input_2)) {//tratare animale

                }


            }



            //boiler plate terminare optiune
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


la2  merge asa:
prima data daca nu ai mai cumparat sau plantat trebuie sa cumperi
pe plante:
se creeaza cat un obiect din fiecare planta, cu ujn costructor poate pt sa fac ala cu lista de initializare  FACUT
se adauga o metoda care trimite la director sef cheltuielile
eventual daca mai este nevoie de alta clasa se poate face una de fermier si sa acopar celelalte subpuncte
apoi sa vad cum ar functiona cu tratarea si udarea, poate un counter poate random pt tratare vedem
aici pot face vector de obiecte pe seminte ca sa ma ocup de destructorul virtual


e animale:
asemanator cu plante
pot sa fac pe fiecare si pe subspecii daca e nevoie
la fel trebuie pe functia de dat de mancare sa vad cum fac
aici probabil o sa fie optiunea de: taiat blana la oi, muls vaci
comert pe astea, posibil si pt mancare ma mai gandesc



*/



/*
CERINTE PROIECT DE BIFAT
FARA DATE PUBLICE !!!!

MOSTENIRE                     2p
-minim 2 ierarhii de mostenire(bazele si clasa urm diferite)                          |
-minim 2 modificatori de acces                                                        |
-o clasa cu mostenire multipla                                                        |             2p
-cel puțin o dată un constructor (cu parametri) dintr-o clasă de bază,                |
folosind o listă de inițializare în constructorul clasei copil                        |
-minim 2 date membru si o meteoda sa fie protected                                    |

VIRTUAL                    2p
-minim o interfata(clasa doar cu metode virtuale si destructor virtual            |
-minim o clasa de baza abstracta                                                  |
-trebuie folosit destructor virtual                                               |
-2 metode virtuale supreascrise in mostenire  tratare udare

POLIMORFISM LA EXECUTIE                    2p
-minim 2 locuri cu polimorfism la exec(prin pointeri)                      |
-2 instante de upcasting                                                   |          1.5
-1 downcast                                                                |posivil doar ca nu are foarte mult sens dar o sa vad

EXCEPTII             2p
-minim 1 tip  de exceptie custom                                                                              |
-exceptii in minim 2 functii/ metode           1
-minim un try...catch care sa prinda o eroare facuta intentionat, si sa o rezolve intr-un fel                 |  1p
-1 try....catch care sa prinda o exceptie, sa o proceseze si sa rearunce un alt tip de exeptie din catch

VARIABILE SI METODE STATICE                1p
-minim 1 variabila statica                                                |  FACUT    1p
-cel putin 2 metode statice(macar 1 sa foloseasca variabila de sus)       |

BONUS   2p
mostenire in diamant                                              |
utilizarea unei lambda expresii

oficiu 1p
TOTAL 9.5p
*/



/*
KNOWN PROBLEMS


*/
