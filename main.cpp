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
    cout<<"3 - atlikti testavima su sugeneruotais failais"<<endl;
    cout<<"Pasirinkimas: ";
    int pasirinkimas=0; cin>>pasirinkimas;
    
    if(pasirinkimas==2){
        auto start=high_resolution_clock::now();
        generavimas("mano1000.txt", 1000, gener);
        auto end=high_resolution_clock::now();
        cout<<"Failo mano1000.txt generavimas uztruko: "<<duration<double>(end-start).count()<<" sekundziu"<<endl;
        start=high_resolution_clock::now();
        generavimas("mano10000.txt", 10000, gener);
        end=high_resolution_clock::now();
        cout<<"Failo mano10000.txt generavimas uztruko: "<<duration<double>(end-start).count()<<" sekundziu"<<endl;
        start=high_resolution_clock::now();
        generavimas("mano100000.txt", 100000, gener);
        end=high_resolution_clock::now();
        cout<<"Failo mano100000.txt generavimas uztruko: "<<duration<double>(end-start).count()<<" sekundziu"<<endl;
        start=high_resolution_clock::now();
        generavimas("mano1000000.txt", 1000000, gener);
        end=high_resolution_clock::now();
        cout<<"Failo mano1000000.txt generavimas uztruko: "<<duration<double>(end-start).count()<<" sekundziu"<<endl;
        start=high_resolution_clock::now();
        generavimas("mano10000000.txt", 10000000, gener);
        end=high_resolution_clock::now();
        cout<<"Failo mano10000000.txt generavimas uztruko: "<<duration<double>(end-start).count()<<" sekundziu"<<endl;
    }
    
    if(pasirinkimas==3){
        testavimas(gener, pazym, nd);
        return 0;
    }
    
    cout<<"Pasirinkite konteinerio tipa:"<<endl;
    cout<<"1 - Vector"<<endl;
    cout<<"2 - List"<<endl;
    int konteineris=0;
    cout<<"Pasirinkimas: ";
    cin>>konteineris;
    
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
    
    int strategija=0;
    cout<<"Pasirinkite strategija:"<<endl;
    cout<<"1 - pirma strategija"<<endl;
    cout<<"2 - antra strategija"<<endl;
    cout<<"3 - trecia strategija"<<endl;
    cout<<"Jusu pasirinkimas: ";
    cin>>strategija;
    
    if(konteineris == 1){
        vector<Studentas> grupe=nuskaitymas(gener, pazym, nd);
        vector<Studentas> vargsiukai;
        vector<Studentas> galvociai;
        if (strategija==1) strategija1_vector(grupe, vargsiukai, galvociai, pasirinkti);
        else if(strategija==2) strategija2_vector(grupe, vargsiukai, pasirinkti);
        else if(strategija==3) strategija3_vector(grupe, vargsiukai, galvociai, pasirinkti);
        if (strategija==2) isvedimas(grupe, vargsiukai, grupe, pasirinkti, rik);
        else isvedimas(grupe, vargsiukai, galvociai, pasirinkti, rik);}
    
    else if(konteineris == 2){
        list<Studentas> grupe=nuskaitymaslist(gener, pazym, nd);
        list<Studentas> vargsiukai;
        list<Studentas> galvociai;
        if (strategija==1) strategija1_list(grupe, vargsiukai, galvociai, pasirinkti);
        else if(strategija==2) strategija2_list(grupe, vargsiukai, pasirinkti);
        else if(strategija==3) strategija3_list(grupe, vargsiukai, galvociai, pasirinkti);
        if (strategija==2) isvedimaslist(grupe, vargsiukai, grupe, pasirinkti, rik);
        else isvedimaslist(grupe, vargsiukai, galvociai, pasirinkti, rik);
    }
}
