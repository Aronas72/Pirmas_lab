#include "mylib.h"
#include "generavimas.h"

int main(){
    random_device rd;
    mt19937 gener(rd());
    uniform_int_distribution<int> pazym(1,10);
    uniform_int_distribution<int> nd(1,10);
    
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
    
    vector<Studentas> grupe=nuskaitymas(gener, pazym, nd);
    
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
    cout<<"3 - pagal galutini bala"<<endl;
    cout<<"Pasirinkimas: ";
    cin>>rik;
    
    vector<Studentas> vargsiukai;
    vector<Studentas> galvociai;
    
    for(const auto & st: grupe){
        double balas = (pasirinkti == 2 ? st.med : st.gal);
        if(balas < 5.0) vargsiukai.push_back(st);
        else galvociai.push_back(st);}
    
    isvedimas(grupe, vargsiukai, galvociai, pasirinkti, rik);
}

