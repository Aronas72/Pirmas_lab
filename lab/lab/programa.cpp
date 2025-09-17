#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <fstream>

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
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;
using std::ifstream;
using std::getline;
using std::ws;


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

int main(){
    random_device rd;
    mt19937 gener(rd());
    uniform_int_distribution<int> pazym(1,10);
    uniform_int_distribution<int> nd(1,10);
    vector<Studentas> Grupe;
    
    cout<<"Pasirinkite kaip ivesti duomenis:"<<endl;
    cout<<"1 - suvesti ranka"<<endl;
    cout<<"2 - nuskaityti is failo"<<endl;
    cout<<"Pasirinkimas: ";
    int pas=0;
    cin>>pas;
    
    if (pas==1){
        cout<<"Kiek studentu grupeje? ";
        int m;
        cin>>m;
        
        for(auto z=0; z<m; z++)
            Grupe.push_back(Stud_iv(gener, pazym, nd));}
    else if (pas==2){
        ifstream fd("kursiokai.txt");
        if (!fd.is_open()){
            cout<<"Nepavyko atidaryti failo."<<endl;}
        string antraste;
        getline(fd, antraste);
        int pazymiai;
        for (int i=0; i<40; i++){
            Studentas st;
            int sum=0;
            fd>>st.var>>st.pav;
            for (int x=0; x<5; x++){
                fd>>pazymiai;
                st.paz.push_back(pazymiai);
                sum+=pazymiai;}
            fd>>st.egz;
            st.gal=double(sum)/5*0.4+st.egz*0.6;
            st.med=0.4*mediana(st.paz)+st.egz*0.6;
            Grupe.push_back(st);}}
    
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

Studentas Stud_iv(mt19937 & gener, uniform_int_distribution<int> & pazym, uniform_int_distribution<int> & nd){
    int laik_paz, sum=0;
    int m=0;
    Studentas Pirmas;
    cout<<"Iveskite studento duomenis"<<endl;
    cout<<"Vardas: "; cin>>Pirmas.var;
    cout<<"Pavarde: "; cin>>Pirmas.pav;
    cout<<"Pasirinkite duomenu ivedimo buda:"<<endl;
    cout<<"1 - duomenis ivesti ranka"<<endl;
    cout<<"2 - sugeneruoti pazymius atsitiktinai"<<endl;
    cout<<"Pasirinkimas: ";
    int ivest=0;
    cin>>ivest;
    bool atsit=(ivest==2);

    if(atsit){
        int nd_kiek=nd(gener);
        cout<<"Sugeneruoti "<<nd_kiek<<" namu darbu pazymiai: ";
        for(int i=0; i<nd_kiek; i++){
            laik_paz=pazym(gener);
            Pirmas.paz.push_back(laik_paz);
            sum+=laik_paz;
            cout<<laik_paz<<" ";}
        cout<<endl;
        Pirmas.egz=pazym(gener);
        cout<<"Sugeneruotas egzamino pazymys: "<<Pirmas.egz<<endl;}
    else{
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
        while(Pirmas.egz<0 || Pirmas.egz>10){
            cout<<"Klaida: egzamino pazymys turi buti tarp 0 ir 10. Bandykite dar karta: ";
            cin>>Pirmas.egz;
        }}
    if(!Pirmas.paz.empty()){
        Pirmas.gal=double(sum)/Pirmas.paz.size()*0.4+Pirmas.egz*0.6;}
    else{
        Pirmas.gal=Pirmas.egz*0.6;}
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
        return (v[x/2-1]+v[x/2])/2.0;
    else
        return v[x/2];
}

