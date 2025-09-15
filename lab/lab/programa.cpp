#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
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
};

Studentas Stud_iv();


int main(){
    vector<Studentas> Grupe;
    cout<<"Kiek studentu grupeje? ";
    int m;
    cin>>m;
    
    for(auto z=0; z<m; z++)
      Grupe.push_back(Stud_iv());
    cout<<"Studento info: "<<endl;
    for (auto Past:Grupe)
    {
    cout<<setw(10)<<left<<Past.var<<"|"<<setw(15)<<right<<Past.pav<<"|";
    for(auto& a:Past.paz) cout<<setw(3)<<a<<"|";
    cout<<setw(5)<<Past.egz<<"|"<<setw(10)<<fixed<<setprecision(2)<<Past.gal<<endl;
    }
}

Studentas Stud_iv(){
    int n, laik_paz, sum=0;
    cout<<"Sveiki"<<endl;
    Studentas Pirmas;
    cout<<"Iveskite studento duomenis"<<endl;
    cout<<"Vardas: "; cin>>Pirmas.var;
    cout<<"Pavarde: "; cin>>Pirmas.pav;
    cout<<"Kiek pazymiu turi "<<Pirmas.var<<" "<<Pirmas.pav<<" "; cin>>n;
    for(int a=0;a<n;a++)
    {
        cout<<a+1<<": "; cin>>laik_paz;
        Pirmas.paz.push_back(laik_paz);
        sum+=laik_paz; //sum+=Pirmas.paz[a];
    }
    cout<<"Iveskite egzamino paz.:"; cin>>Pirmas.egz;
    Pirmas.gal=double(sum)/double(n)*0.4+Pirmas.egz*0.6;
    return Pirmas;
}
