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


