#ifndef MYLIB_H
#define MYLIB_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <random>
#include <fstream>
#include <sstream>
#include <chrono>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::list;
using std::setw;
using std::left;
using std::right;
using std::setprecision;
using std::fixed;
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;
using std::ifstream;
using std::ofstream;
using std::getline;
using std::istringstream;
using std::to_string;
using std::sort;
using std::chrono::high_resolution_clock;
using std::chrono::duration;


struct Studentas{
    string var;
    string pav;
    vector <int> paz;
    int egz;
    double gal;
    double med;
};

Studentas Stud_iv(mt19937 & gener, uniform_int_distribution<int> & pazym, uniform_int_distribution<int> & nd);
double mediana(vector<int> v);
bool vardas(const Studentas a, const Studentas b);
bool pavarde(const Studentas a, const Studentas b);
bool galutinis(const Studentas a, const Studentas b, int pasirinkti);
vector<Studentas> nuskaitymas(mt19937 & gener, uniform_int_distribution<int> & pazym,uniform_int_distribution<int> & nd);
list<Studentas> nuskaitymaslist(mt19937 & gener, uniform_int_distribution<int> & pazym,uniform_int_distribution<int> & nd);
vector<Studentas> nuskaitymas(mt19937 & gener, uniform_int_distribution<int> & pazym,uniform_int_distribution<int> & nd, const string& failpav);
list<Studentas> nuskaitymaslist(mt19937 & gener, uniform_int_distribution<int> & pazym,uniform_int_distribution<int> & nd, const string& failpav);
void isvedimas(vector<Studentas> Grupe, vector<Studentas> vargsiukai, vector<Studentas> galvociai, int pasirinkti, int rik);
void isvedimaslist(list<Studentas> Grupe, list<Studentas> vargsiukai, list<Studentas> galvociai, int pasirinkti, int rik);

void testavimas(mt19937 & gener, uniform_int_distribution<int> & pazym, uniform_int_distribution<int> & nd);

void strategija1_vector(const vector<Studentas>& grupe, vector<Studentas>& vargsiukai, vector<Studentas>& galvociai, int pasirinkti);
void strategija2_vector(vector<Studentas>& grupe, vector<Studentas>& vargsiukai, int pasirinkti);
void strategija3_vector(vector<Studentas>& grupe, vector<Studentas>& vargsiukai, vector<Studentas>& galvociai, int pasirinkti);
void strategija1_list(const list<Studentas>& grupe, list<Studentas>& vargsiukai, list<Studentas>& galvociai, int pasirinkti);
void strategija2_list(list<Studentas>& grupe, list<Studentas>& vargsiukai, int pasirinkti);
void strategija3_list(list<Studentas>& grupe, list<Studentas>& vargsiukai, list<Studentas>& galvociai, int pasirinkti);



#endif

