#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <fstream>
#include <sstream>

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
using std::ofstream;
using std::getline;
using std::istringstream;
using std::to_string;
using std::sort;


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
void generavimas(const string & failpav, size_t kiekis, mt19937 & gener);

int main(){
    random_device rd;
    mt19937 gener(rd());
    uniform_int_distribution<int> pazym(1,10);
    uniform_int_distribution<int> nd(1,10);
    vector<Studentas> Grupe;
    
    cout<<"Pasirinkti veiksma:"<<endl;
    cout<<"1 - ivesti studentus ranka arba nuskaityti is failo."<<endl;
    cout<<"2 - sugeneruoti failus paciam"<<endl;
    cout<<"Pasirinkimas: ";
    int pasirinkimas=0;
    cin>>pasirinkimas;
    
    if(pasirinkimas==2){
        generavimas("mano1000.txt", 1000, gener);
        generavimas("mano10000.txt", 10000, gener);
        generavimas("mano100000.txt", 100000, gener);
        generavimas("mano1000000.txt", 1000000, gener);
        generavimas("mano10000000.txt", 10000000, gener);
        
        int pasirink=0;
        cout<<"Ar nori testi programa?"<<endl;
        cout<<"1 - baigti programa tik sugeneravus failus"<<endl;
        cout<<"2 - testi toliau (duomenu nuskaitymas/ivedimas)"<<endl;
        cout<<"Pasirinkimas: ";
        cin>>pasirink;
        
        if(pasirink == 1){
            cout<<"Programa baigta."<<endl;
            return 0;}}
    
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
        string failpav;
        cout<<"Iveskite failo pavadinima: ";
        cin>>failpav;
        ifstream fd(failpav);
        if (!fd.is_open()){
            cout<<"Nepavyko atidaryti failo."<<endl;}
        string antraste;
        getline(fd, antraste);
        string eil;
        while (getline(fd, eil)){
            istringstream iss(eil);
            Studentas st;
            st.paz.clear();
            iss>>st.var>>st.pav;
            vector<int> sk;
            int k;
            while (iss>>k){
                sk.push_back(k);}
            st.egz=sk.back();
            sk.pop_back();
            st.paz=sk;
            int sum=0;
            for(int nd:st.paz) sum+=nd;
            st.gal=double(sum)/st.paz.size()*0.4+st.egz*0.6;
            st.med=0.4*mediana(st.paz)+st.egz*0.6;
            Grupe.push_back(st);}}
    
    int pasirinkti=0;
    cout<<"Pasirinkite galutinio balo skaiciavimo buda:"<<endl;
    cout<<"1 - tik vidurkis"<<endl;
    cout<<"2 - tik mediana"<<endl;
    cout<<"3 - abu"<<endl;
    cout<<"Jusu pasirinkimas: ";
    cin>>pasirinkti;
    
    int rik;
    cout<<"Pasirinkti pagal ka rikiuoti:"<<endl;
    cout<<"1 - pagal varda"<<endl;
    cout<<"2 - pagal pavarde"<<endl;
    cout<<"Pasirinkimas: ";
    cin>>rik;
    
    vector<Studentas> vargsiukai;
    vector<Studentas> galvociai;
    
    for(const auto & st: Grupe){
        double balas=0.0;
        if(pasirinkti == 1) balas=st.gal;
        else if(pasirinkti == 2) balas=st.med;
        else if(pasirinkti == 3) balas=st.gal;
        
        if(balas<5.0){
            vargsiukai.push_back(st);}
        else{
            galvociai.push_back(st);}}
    
    if(rik==1){
        sort(vargsiukai.begin(), vargsiukai.end(), vardas);
        sort(galvociai.begin(), galvociai.end(), vardas);}
    else if(rik==2){
        sort(vargsiukai.begin(), vargsiukai.end(), pavarde);
        sort(galvociai.begin(), galvociai.end(), pavarde);}
    
    ofstream fv("vargsiukai.txt");
    fv<<setw(15)<<left<<"Vardas"<<setw(20)<<left<<"Pavarde"<<setw(10)<<left<<"Balas"<<endl;
    fv<<string(45, '-')<<endl;
    for(const auto & st: vargsiukai){
        fv<<setw(15)<<left<<st.var<<setw(20)<<left<<st.pav<<setw(10)<<left<<fixed<<setprecision(2)<<(pasirinkti == 2 ? st.med:st.gal)<<endl;}
    fv.close();
    
    ofstream fg("galvociai.txt");
    fg<<setw(15)<<left<<"Vardas"<<setw(20)<<left<<"Pavarde"<<setw(10)<<left<<"Balas"<<endl;
    fg<<string(45, '-')<<endl;
    for(const auto & st: galvociai){
        fg<<setw(15)<<left<<st.var<<setw(20)<<left<<st.pav<<setw(10)<<left<<fixed<<setprecision(2)<<(pasirinkti == 2 ? st.med:st.gal)<<endl;}
    fg.close();
    
    cout<<"Is viso: "<<vargsiukai.size()<<" vargsiuku ir "<<galvociai.size()<<" galvociu."<<endl;
    
    int rikiuoti;
    cout<<"Pasirinkti pagal ka rikiuoti:"<<endl;
    cout<<"1 - pagal varda"<<endl;
    cout<<"2 - pagal pavarde"<<endl;
    cout<<"Pasirinkimas: ";
    cin>>rikiuoti;
    
    if(rikiuoti==1){
        sort(Grupe.begin(), Grupe.end(), vardas);}
    else if(rikiuoti==2){
        sort(Grupe.begin(), Grupe.end(), pavarde);}
    
    ofstream fr("rezultatai.txt");
    
    fr<<setw(15)<<left<<"Vardas"<<"|"<<setw(20)<<right<<"Pavarde";
    if(pasirinkti == 1 || pasirinkti == 3)
        fr<<"|"<<setw(20)<<"Galutinis (vid.)";
    if(pasirinkti == 2 || pasirinkti == 3)
        fr<<"|"<<setw(20)<<"Galutinis (Med.)";
    fr<<endl;
    fr<<string(75,'-')<<endl;
    
    for (auto Past:Grupe){
        fr<<setw(15)<<left<<Past.var<<
        "|"<<setw(20)<<right<<Past.pav;
        if(pasirinkti == 1 || pasirinkti == 3)
            fr<<"|"<<setw(20)<<fixed<<setprecision(2)<<Past.gal;
        if(pasirinkti == 2 || pasirinkti == 3)
            fr<<"|"<<setw(20)<<fixed<<setprecision(2)<<Past.med;
        fr<<endl;}
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
            if(cin.fail()){
                cin.clear();
                cin.ignore(10000, '\n');
                cout<<"Klaida: reikia ivesti skaiciu nuo 0 iki 10"<<endl;
                continue;}
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
    double median=mediana(Pirmas.paz);
    Pirmas.med=median*0.4+Pirmas.egz*0.6;
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

bool vardas(const Studentas a, const Studentas b){
    return a.var<b.var;}
bool pavarde(const Studentas a, const Studentas b){
    return a.pav<b.pav;}

void generavimas(const string & failpav, size_t kiekis, mt19937 & gener){
    uniform_int_distribution<int> pazym(1, 10);
    uniform_int_distribution<int> nd_kiekis(1, 10);
    ofstream fr(failpav);
    if(!fr.is_open()){
        cout<<"Nepavyko sukurti failo: "<<failpav<<endl;
        return;}
    fr<<setw(15)<<left<<"Vardas"<<setw(20)<<left<<"Pavarde";
    int ndkiek=nd_kiekis(gener);
    for(int i=1; i<=ndkiek; i++){
        fr<<setw(7)<<right<<("ND"+to_string(i));}
    fr<<setw(10)<<right<<"Egzaminas"<<endl;
    
    for(size_t i=1; i<=kiekis; i++){
        fr<<setw(15)<<left<<("Vardas"+to_string(i))<<setw(20)<<left<<("Pavarde"+to_string(i));
        for(int j=1; j<=ndkiek; j++){
            fr<<setw(7)<<right<<pazym(gener);}
        fr<<setw(10)<<right<<pazym(gener)<<endl;}
    fr.close();
    cout<<"Sugeneruotas failas: "<<failpav<<". "<<kiekis<<" irasu, "<<ndkiek<<" ND irasu."<<endl;
}

