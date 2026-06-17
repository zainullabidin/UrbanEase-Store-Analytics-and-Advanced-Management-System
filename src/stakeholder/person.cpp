#include"stakeholder.h"

Person::Person(){
    
    name="DUMMY_NAME";
    age=00;
    PersonalID=00;
}

    string Person::getname()const{
        return name;
    }
  
    void Person::setname(string a){
        name=a;
    }
   
    int Person::getage()const{
        return age;
    }
   
    void Person::setage(int n){
        age=n;
    }
 
    int Person::getPersonalID()const{
        return PersonalID;
    }
 
    void Person::setPersonalID(int n){
         PersonalID=n;
    }
 
    void Person::loaddatafromfile(ifstream&datafile){
        getline(datafile>>ws,name);
        datafile>>age>>PersonalID;
    }

    void Person::display()
    {
        cout<<"                               PERSON STATS      : \n";
        cout<<" NAME       : " <<name<<endl;
        cout<<" AGE        : " <<age<<endl;
        cout<<" Personal_ID: " <<PersonalID<<endl;
    }
