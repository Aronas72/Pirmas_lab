#include "mylib.h"

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
bool galutinis(const Studentas a, const Studentas b, int pasirinkti){
    double ba=(pasirinkti==2 ? a.med:a.gal);
    double bb=(pasirinkti==2 ? b.med:b.gal);
    return ba<bb;
}

vector<Studentas> nuskaitymas(mt19937 & gener, uniform_int_distribution<int> & pazym,uniform_int_distribution<int> & nd){
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
        
        for(auto z=0; z<m; z++){
            Grupe.push_back(Stud_iv(gener, pazym, nd));
            cout<<"Objekto saugojimo atmintyje adresas (vector): "<< (void*)&Grupe.back()<<endl;}}
    else if (pas==2){
        string failpav;
        cout<<"Iveskite failo pavadinima: ";
        cin>>failpav;
        auto start = std::chrono::high_resolution_clock::now();
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
            Grupe.push_back(st);}
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end - start;
        cout << "Failo nuskaitymas uztruko: " << diff.count() << " s" << endl;
          }
    return Grupe;
}

vector<Studentas> nuskaitymas(mt19937 & gener, uniform_int_distribution<int> & pazym,uniform_int_distribution<int> & nd, const string & failpav){
    vector<Studentas> Grupe;
    ifstream fd(failpav);
    if (!fd.is_open()){ cout<<"Nepavyko atidaryti failo."<<endl; return Grupe;}
    string antraste; getline(fd, antraste);
    string eil;
    while (getline(fd, eil)){
        istringstream iss(eil);
        Studentas st; st.paz.clear();
        iss>>st.var>>st.pav;
        vector<int> sk; int k;
        while (iss>>k){ sk.push_back(k); }
        st.egz=sk.back(); sk.pop_back(); st.paz=sk;
        int sum=0; for(int nd:st.paz) sum+=nd;
        st.gal=double(sum)/st.paz.size()*0.4+st.egz*0.6;
        st.med=0.4*mediana(st.paz)+st.egz*0.6;
        Grupe.push_back(st);}
    return Grupe;
}

list<Studentas> nuskaitymaslist(mt19937 & gener, uniform_int_distribution<int> & pazym,uniform_int_distribution<int> & nd){
    list<Studentas> Grupe;
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
        for(auto z=0; z<m; z++){
            Grupe.push_back(Stud_iv(gener, pazym, nd));
            auto it=std::prev(Grupe.end());
            cout<<"Objekto saugojimo atmintyje adresas (list): "<<(void*)&(*it)<<endl;}}
    else if (pas==2){
        string failpav;
        cout<<"Iveskite failo pavadinima: ";
        cin>>failpav;
        auto start = high_resolution_clock::now();
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
            if(!st.paz.empty())
                st.gal=double(sum)/st.paz.size()*0.4+st.egz*0.6;
            else st.gal=st.egz*0.6;
            st.med=0.4*mediana(st.paz)+st.egz*0.6;
            Grupe.push_back(st);}
        auto end = high_resolution_clock::now();
        duration<double> diff = end - start;
        cout << "Failo nuskaitymas uztruko: " << diff.count() << " s" << endl;
    }
    return Grupe;}

list<Studentas> nuskaitymaslist(mt19937 & gener, uniform_int_distribution<int> & pazym,uniform_int_distribution<int> & nd, const string& failpav){
    list<Studentas> Grupe;
        ifstream fd(failpav);
        if (!fd.is_open()){ cout<<"Nepavyko atidaryti failo."<<endl; return Grupe;}
        string antraste; getline(fd, antraste);
        string eil;
        while (getline(fd, eil)){
            istringstream iss(eil);
            Studentas st; st.paz.clear();
            iss>>st.var>>st.pav;
            vector<int> sk; int k;
            while (iss>>k){ sk.push_back(k); }
            st.egz=sk.back(); sk.pop_back(); st.paz=sk;
            int sum=0; for(int nd:st.paz) sum+=nd;
            if(!st.paz.empty())
                st.gal=double(sum)/st.paz.size()*0.4+st.egz*0.6;
            else st.gal=st.egz*0.6;
            st.med=0.4*mediana(st.paz)+st.egz*0.6;
            Grupe.push_back(st);}
        return Grupe;
}

void isvedimas(vector<Studentas> Grupe, vector<Studentas> vargsiukai, vector<Studentas> galvociai, int pasirinkti, int rik){
    
    vector<Studentas> grp = Grupe;
    vector<Studentas> v = vargsiukai;
    vector<Studentas> g = galvociai;
    
    if(rik==1){
        sort(grp.begin(), grp.end(), vardas);
        sort(v.begin(), v.end(), vardas);
        sort(g.begin(), g.end(), vardas);}
    else if(rik==2){
        sort(grp.begin(), grp.end(), pavarde);
        sort(v.begin(), v.end(), pavarde);
        sort(g.begin(), g.end(), pavarde);}
    else if(rik==3){
        sort(grp.begin(), grp.end(), [&](const Studentas & a, const Studentas & b){ return galutinis(a,b,pasirinkti); });
        sort(v.begin(), v.end(), [&](const Studentas & a, const Studentas & b){ return galutinis(a,b,pasirinkti); });
        sort(g.begin(), g.end(), [&](const Studentas & a, const Studentas & b){ return galutinis(a,b,pasirinkti); });
            
    }
    
    ofstream fv("vargsiukai.txt");
    fv<<setw(15)<<left<<"Vardas"<<setw(20)<<left<<"Pavarde"<<setw(10)<<left<<"Balas"<<endl;
    fv<<string(45, '-')<<endl;
    for(const auto & st: v){
        fv<<setw(15)<<left<<st.var<<setw(20)<<left<<st.pav<<setw(10)<<left<<fixed<<setprecision(2)<<(pasirinkti == 2 ? st.med:st.gal)<<endl;}
    fv.close();
    
    ofstream fg("galvociai.txt");
    fg<<setw(15)<<left<<"Vardas"<<setw(20)<<left<<"Pavarde"<<setw(10)<<left<<"Balas"<<endl;
    fg<<string(45, '-')<<endl;
    for(const auto & st: g){
        fg<<setw(15)<<left<<st.var<<setw(20)<<left<<st.pav<<setw(10)<<left<<fixed<<setprecision(2)<<(pasirinkti == 2 ? st.med:st.gal)<<endl;}
    fg.close();
    
    ofstream fr("rezultatai.txt");
    
    fr<<setw(15)<<left<<"Vardas"<<"|"<<setw(20)<<right<<"Pavarde";
    if(pasirinkti == 1 || pasirinkti == 3)
        fr<<"|"<<setw(20)<<"Galutinis (vid.)";
    if(pasirinkti == 2 || pasirinkti == 3)
        fr<<"|"<<setw(20)<<"Galutinis (Med.)";
    fr<<endl;
    fr<<string(75,'-')<<endl;
    
    for (auto Past:grp){
        fr<<setw(15)<<left<<Past.var<<
        "|"<<setw(20)<<right<<Past.pav;
        if(pasirinkti == 1 || pasirinkti == 3)
            fr<<"|"<<setw(20)<<fixed<<setprecision(2)<<Past.gal;
        if(pasirinkti == 2 || pasirinkti == 3)
            fr<<"|"<<setw(20)<<fixed<<setprecision(2)<<Past.med;
        fr<<endl;}
    fr.close();
    
    cout<<"Is viso: "<<vargsiukai.size()<<" vargsiuku ir "<<galvociai.size()<<" galvociu."<<endl;
}

void isvedimaslist(list<Studentas> Grupe, list<Studentas> vargsiukai, list<Studentas> galvociai, int pasirinkti, int rik){
    list<Studentas> grp = Grupe;
    list<Studentas> v = vargsiukai;
    list<Studentas> g = galvociai;
    
    if(rik==1){
            grp.sort([](const Studentas &a, const Studentas &b){ return a.var < b.var; });
            v.sort([](const Studentas &a, const Studentas &b){ return a.var < b.var; });
            g.sort([](const Studentas &a, const Studentas &b){ return a.var < b.var; });
        }
        else if(rik==2){
            grp.sort([](const Studentas &a, const Studentas &b){ return a.pav < b.pav; });
            v.sort([](const Studentas &a, const Studentas &b){ return a.pav < b.pav; });
            g.sort([](const Studentas &a, const Studentas &b){ return a.pav < b.pav; });
        }
        else if(rik==3){
            grp.sort([&](const Studentas & a, const Studentas & b){ return galutinis(a,b,pasirinkti); });
            v.sort([&](const Studentas & a, const Studentas & b){ return galutinis(a,b,pasirinkti); });
            g.sort([&](const Studentas & a, const Studentas & b){ return galutinis(a,b,pasirinkti); });
        }
    
    ofstream fv("vargsiukai.txt");
    fv<<setw(15)<<left<<"Vardas"<<setw(20)<<left<<"Pavarde"<<setw(10)<<left<<"Balas"<<endl;
    fv<<string(45, '-')<<endl;
    for(const auto & st: v){
        fv<<setw(15)<<left<<st.var<<setw(20)<<left<<st.pav<<setw(10)<<left<<fixed<<setprecision(2)<<(pasirinkti == 2 ? st.med:st.gal)<<endl;}
    fv.close();
    
    ofstream fg("galvociai.txt");
    fg<<setw(15)<<left<<"Vardas"<<setw(20)<<left<<"Pavarde"<<setw(10)<<left<<"Balas"<<endl;
    fg<<string(45, '-')<<endl;
    for(const auto & st: g){
        fg<<setw(15)<<left<<st.var<<setw(20)<<left<<st.pav<<setw(10)<<left<<fixed<<setprecision(2)<<(pasirinkti == 2 ? st.med:st.gal)<<endl;}
    fg.close();
    
    ofstream fr("rezultatai.txt");
    
    fr<<setw(15)<<left<<"Vardas"<<"|"<<setw(20)<<right<<"Pavarde";
    if(pasirinkti == 1 || pasirinkti == 3)
        fr<<"|"<<setw(20)<<"Galutinis (vid.)";
    if(pasirinkti == 2 || pasirinkti == 3)
        fr<<"|"<<setw(20)<<"Galutinis (Med.)";
    fr<<endl;
    fr<<string(75,'-')<<endl;
    
    for (auto Past:grp){
        fr<<setw(15)<<left<<Past.var<<
        "|"<<setw(20)<<right<<Past.pav;
        if(pasirinkti == 1 || pasirinkti == 3)
            fr<<"|"<<setw(20)<<fixed<<setprecision(2)<<Past.gal;
        if(pasirinkti == 2 || pasirinkti == 3)
            fr<<"|"<<setw(20)<<fixed<<setprecision(2)<<Past.med;
        fr<<endl;}
    fr.close();
    
    cout<<"Is viso: "<<v.size()<<" vargsiuku ir "<<g.size()<<" galvociu."<<endl;
}

void strategija1_vector(const vector<Studentas>& grupe, vector<Studentas>& vargsiukai, vector<Studentas>& galvociai, int pasirinkti){
    for (const auto& st: grupe){
        double bal = (pasirinkti == 2 ? st.med : st.gal);
                if(bal < 5.0) vargsiukai.push_back(st);
                else galvociai.push_back(st);}}

void strategija2_vector(vector<Studentas>& grupe, vector<Studentas>& vargsiukai, int pasirinkti){
    vector<Studentas> Vargsai;
        size_t newSize = 0;
        for (size_t i = 0; i < grupe.size(); i++)
        {
            if (grupe[i].gal < 5)
                Vargsai.push_back(grupe[i]);
            else
                grupe[newSize++] = std::move(grupe[i]);
        }
        grupe.erase(grupe.begin() + newSize, grupe.end());}

void strategija3_vector(vector<Studentas>& grupe, vector<Studentas>& vargsiukai, vector<Studentas>& galvociai, int pasirinkti){
    auto is_vargsiukas = [pasirinkti](const Studentas& st){return (pasirinkti==2?st.med:st.gal)<5.0; };
        vector<Studentas> tmp=grupe;
        auto it=std::stable_partition(tmp.begin(), tmp.end(), is_vargsiukas);
        vargsiukai.insert(vargsiukai.end(), tmp.begin(), it);
        galvociai.insert(galvociai.end(), it, tmp.end());}

void strategija1_list(const list<Studentas>& grupe, list<Studentas>& vargsiukai, list<Studentas>& galvociai, int pasirinkti){
    for(const auto & st: grupe){
        double bal = (pasirinkti == 2 ? st.med : st.gal);
        if(bal < 5.0) vargsiukai.push_back(st);
        else galvociai.push_back(st);}}
    
void strategija2_list(list<Studentas>& grupe, list<Studentas>& vargsiukai, int pasirinkti){
    for(auto it = grupe.begin(); it != grupe.end(); ){
            double bal = (pasirinkti == 2 ? it->med : it->gal);
            if(bal<5.0){
                vargsiukai.push_back(*it);
                it = grupe.erase(it);
            } else ++it;}}
    
void strategija3_list(list<Studentas>& grupe, list<Studentas>& vargsiukai, list<Studentas>& galvociai, int pasirinkti){
    for(auto it = grupe.begin(); it != grupe.end(); ){
            double bal = (pasirinkti == 2 ? it->med : it->gal);
            if(bal < 5.0){
                vargsiukai.splice(vargsiukai.end(), grupe, it++);
            } else {
                galvociai.splice(galvociai.end(), grupe, it++);}}}

void testavimas(mt19937 & gener, uniform_int_distribution<int> & pazym, uniform_int_distribution<int> & nd){
    cout<<"Pasirinkite is kokio failo atlikti testavima:"<<endl;
    cout<<"1 - mano1000.txt"<<endl;
    cout<<"2 - mano10000.txt"<<endl;
    cout<<"3 - mano100000.txt"<<endl;
    cout<<"4 - mano1000000.txt"<<endl;
    cout<<"5 - mano10000000.txt"<<endl;
    cout<<"Pasirinkimas: ";
    int pas; cin>>pas;
    
    string failas;
    if(pas==1) failas="mano1000.txt";
    else if(pas==2) failas="mano10000.txt";
    else if(pas==3) failas="mano100000.txt";
    else if(pas==4) failas="mano1000000.txt";
    else if(pas==5) failas="mano10000000.txt";
    else { cout<<"Neteisingas pasirinkimas."<<endl; return; }
    
    int strategija=0;
    cout<<"Pasirinkite strategija:"<<endl;
    cout<<"1 - pirma strategija"<<endl;
    cout<<"2 - antra strategija"<<endl;
    cout<<"3 - trecia strategija"<<endl;
    cout<<"Jusu pasirinkimas: ";
    cin>>strategija;
    
    cout<<"Kiek kartu paleisti testui: ";
    int pal=0;
    cin>>pal;
    if(pal<=0){pal=5;}
    
    double vskaitymas=0.0, vskirstymas=0.0, visvedimas=0.0;
    double lskaitymas=0.0, lskirstymas=0.0, lisvedimas=0.0;
    
    for(int p=0; p<pal; p++){
        
        auto start = high_resolution_clock::now();
        vector<Studentas> grupe = nuskaitymas(gener, pazym, nd, failas);
        auto end = high_resolution_clock::now();
        duration<double> diff = end - start;
        vskaitymas=vskaitymas+diff.count();
        cout<<"Vektoriaus "<<p+1<<" nuskaitymo laikas: "<<diff.count()<<" s"<<endl;

        start=high_resolution_clock::now();
        vector<Studentas> vargsiukai, galvociai;
        if (strategija==1) strategija1_vector(grupe, vargsiukai, galvociai, 1);
        else if(strategija==2) strategija2_vector(grupe, vargsiukai, 1);
        else if(strategija==3) strategija3_vector(grupe, vargsiukai, galvociai, 1);
        end=high_resolution_clock::now();
        diff=end-start;
        vskirstymas=vskirstymas+diff.count();
        cout<<"Vektoriaus "<<p+1<<" dalijimas i dvi grupes uztruko: "<<diff.count()<<" s"<<endl;
        
        start=high_resolution_clock::now();
        if (strategija==2) isvedimas(grupe, vargsiukai, grupe, 1, 3);
        else isvedimas(grupe, vargsiukai, galvociai, 1, 3);
        end=high_resolution_clock::now();
        diff=end-start;
        visvedimas=visvedimas+diff.count();
        cout<<"Vektoriaus "<<p+1<<" rasymas i failus uztruko: "<<diff.count()<<" s"<<endl;
        
        start = high_resolution_clock::now();
        list<Studentas> grupelist = nuskaitymaslist(gener, pazym, nd, failas);
        end = high_resolution_clock::now();
        diff = end - start;
        lskaitymas=lskaitymas+diff.count();
        cout<<"Listo "<<p+1<<" nuskaitymo laikas: "<<diff.count()<<" s"<<endl;
        
        start=high_resolution_clock::now();
        list<Studentas> vargsiukailist, galvociailist;
        if (strategija==1) strategija1_list(grupelist, vargsiukailist, galvociailist, 1);
        else if(strategija==2) strategija2_list(grupelist, vargsiukailist, 1);
        else if(strategija==3) strategija3_list(grupelist, vargsiukailist, galvociailist, 1);
        end=high_resolution_clock::now();
        diff=end-start;
        lskirstymas=lskirstymas+diff.count();
        cout<<"Listo "<<p+1<<" dalijimas i dvi grupes uztruko: "<<diff.count()<<" s"<<endl;
        
        start = high_resolution_clock::now();
        if (strategija==2) isvedimaslist(grupelist, vargsiukailist, grupelist, 1, 3);
        else isvedimaslist(grupelist, vargsiukailist, galvociailist, 1, 3);
        end = high_resolution_clock::now();
        diff = end - start;
        lisvedimas=lisvedimas+diff.count();
        cout<<"Listo "<<p+1<<" rasymas i failus uztruko: "<<diff.count()<<" s"<<endl;
    }
    cout<<endl;
    cout<<"Testo vidurkiai "<<pal<<" paleidimu:"<<endl;
    cout<<"Vektorius: skaitymo vidurkis: "<<(vskaitymas/pal)<<" s, dalijimo i dvi grupes vidurkis: "<<(vskirstymas/pal)<<" s, isvedimo vidurkis: "<<(visvedimas/pal)<<" s"<<endl;
    cout<<"Listas: skaitymo vidurkis: "<<(lskaitymas/pal)<<" s, dalijimo i dvi grupes vidurkis: "<<(lskirstymas/pal)<<" s, isvedimo vidurkis: "<<(lisvedimas/pal)<<" s"<<endl;
    cout<<"Testavimo pabaiga."<<endl;}
