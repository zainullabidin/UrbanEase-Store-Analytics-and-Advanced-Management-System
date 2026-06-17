#include"stakeholder.h"
 
   Employee::Employee(){
        Employee_ID=00;
        role_Employee="DUMMY_ROLE";


    }

    int Employee::getEmployee_ID()const{
        return Employee_ID;
    }

    void Employee::setEmployee_ID(int n){
        Employee_ID=n;
    }

    string Employee::getrole_Employee()const{
        return role_Employee;
    }

    void Employee::setrole_Employee(string a){
        role_Employee=a;
    }
    
    void Employee::loaddata_employee(ifstream& datafile) {
    loaddatafromfile(datafile);//person class
    datafile >> Employee_ID;
    getline(datafile >> ws, role_Employee);
    }

    void Employee::display()
    {
        Person::display();
        cout<<"                               EMPLOYEE STATS \n";
        cout<<" EMPLOYYE_ID    :"<<Employee_ID<<endl;
        cout<<" ROLE_EMPLOYYE  :"<<role_Employee<<endl;
    }
