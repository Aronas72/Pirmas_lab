#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::setw;
using std::left;
using std::right;
using std::setprecision;
using std::fixed;


struct Studentas{
    string var;
    string pav;
    vector <int> paz;
    int egz;
    double gal;
    double med;
};

Studentas Stud_iv();
double mediana(vector<int> v);

int main(){
    vector<Studentas> Grupe;
    cout<<"Kiek studentu grupeje? ";
    int m;
    cin>>m;
    
    for(auto z=0; z<m; z++)
      Grupe.push_back(Stud_iv());
    cout<<"Studento info: "<<endl;
    
    int pasirinkti=0;
    cout<<"Pasirinkite galutinio balo skaiciavimo buda:"<<endl;
    cout<<"1 - tik vidurkis"<<endl;
    cout<<"2 - tik mediana"<<endl;
    cout<<"3 - abu"<<endl;
    cout<<"Jusu pasirinkimas: ";
    cin>>pasirinkti;
    
    cout<<setw(10)<<left<<"Vardas"<<"|"<<setw(15)<<right<<"Pavarde";
    if(pasirinkti == 1 || pasirinkti == 3)
        cout<<"|"<<setw(15)<<"Galutinis (vid.)";
    if(pasirinkti == 2 || pasirinkti == 3)
        cout<<"|"<<setw(15)<<"Galutinis (Med.)";
    cout<<endl;
    cout<<string(60,'-')<<endl;
    
    for (auto Past:Grupe){
        cout<<setw(10)<<left<<Past.var<<
        "|"<<setw(15)<<right<<Past.pav;
        if(pasirinkti == 1 || pasirinkti == 3)
            cout<<"|"<<setw(16)<<fixed<<setprecision(2)<<Past.gal;
        if(pasirinkti == 2 || pasirinkti == 3)
            cout<<"|"<<setw(15)<<fixed<<setprecision(2)<<Past.med;
        cout<<endl;}
}

Studentas Stud_iv(){
    int laik_paz, sum=0;
    int m=0;
    Studentas Pirmas;
    cout<<"Iveskite studento duomenis"<<endl;
    cout<<"Vardas: "; cin>>Pirmas.var;
    cout<<"Pavarde: "; cin>>Pirmas.pav;
    cout<<"Iveskite namu darbu pazymius (baigimas - neigiamas skaicius): ";
    while(true)
    {
        cout<<m+1<<": ";
        cin>>laik_paz;
        if(laik_paz<0) break;
        if(laik_paz>10){
            cout<<"Klaida: pazymys negali buti didesnis uz 10, Bandykite dar karta: "<<endl;
            continue;
        }
        Pirmas.paz.push_back(laik_paz);
        sum+=laik_paz;
        m++;
    }
    cout<<"Iveskite egzamino paz.:";
    cin>>Pirmas.egz;
    Pirmas.gal=double(sum)/Pirmas.paz.size()*0.4+Pirmas.egz*0.6;
    Pirmas.med=mediana(Pirmas.paz)*0.4+Pirmas.egz*0.6;
    if(Pirmas.med>10)
        Pirmas.med=10;
    return Pirmas;
}

double mediana(vector<int> v){
    if (v.empty()) return 0;
    sort(v.begin(), v.end());
    size_t x=v.size();
    if (x%2==0)
        return v[x/2-1]+v[x/2]/2.0;
    else
        return v[x/2];
};

