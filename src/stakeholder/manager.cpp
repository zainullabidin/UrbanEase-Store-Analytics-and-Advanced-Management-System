#include"stakeholder.h"


    Manager::Manager(){
        title="DUMMY_TITLE";
        standingout_Points=0.0;
    }

    string Manager::getTitle()const{
        return title;
    }

    void Manager::setTitle(string a){
        title=a;
    }

    double Manager::getstandingout_Points()const{
        return standingout_Points;
    }

    void Manager::setstandingout_Points(double n){
        standingout_Points=n;
    }

    void Manager::loaddata_man(ifstream &datafile)
    {
        loaddata_employee(datafile);
        getline(datafile >> ws, title);
        datafile>>standingout_Points;
    }
   
    void Manager::display() {
    Employee::display();
    cout << "                                MANAGER STATS: " << endl;
    cout<<" MANAGER TITLE         : "<<title<<endl;
    cout<<" MANAGER_S0 POINTS     : "<<standingout_Points<<endl;
}

