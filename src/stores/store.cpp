#include"store.h"


    Store::Store(){

        name="DUMMY_NAME";
        unique_ID=00;
        t_staff=0;
        staff=NULL;//DMA for staff members


    }

    Store::~Store(){

        delete []staff;

        staff=NULL;
     }

     Store::Store(const Store&object){

        t_staff=object.gett_staff();
        //shtafff
        staff=new Employee[t_staff];
        for(int i=0;i<object.t_staff;i++)
        this->staff[i]=object.staff[i];

        name=object.getname();
        ///bombing pots : N)
        this->position.setlatitude(object.position.getlatitude());
        this->position.setlongitude(object.position.getlongitude());

        unique_ID=object.getunique_ID();
        //manager class
        manager.setage(object.manager.getage());
        manager.setEmployee_ID(object.manager.getEmployee_ID());
        manager.setname(object.manager.getname());
        manager.setPersonalID(object.manager.getPersonalID());
        manager.setrole_Employee(object.manager.getrole_Employee());
        manager.setTitle(object.manager.getTitle());
        manager.setstandingout_Points(object.manager.getstandingout_Points());
        //analytivs
        this->data=object.data;
        

   


     }

    void Store::setname(string n){
        name=n;
    }

    string Store::getname()const{
        return name;
    }

    void Store::setunique_ID(int n){
        unique_ID=n;
    }

    int Store::getunique_ID()const{
        return unique_ID;
    }

    void Store::sett_staff(int n){
        t_staff=n;
    }

    int Store::gett_staff()const{
        return t_staff;
    }

    analytics& Store::getanalytics(){
        return data;
    }

    void Store::allocate_staff(){
    if(!(staff==NULL)) 
    delete[] staff;

    staff = new Employee[t_staff];
}

    Manager& Store::getman(){
        return manager;
    }

    Employee*& Store::get_emp(){
        return staff;
    }

    Coordinates& Store::getcoords(){
        return position;
    }

    void Store::load_maindata(ifstream & datafile)
    {
        getline(datafile>>ws,name);
        datafile>>unique_ID;
        position.loaddata_coords(datafile);
        manager.loaddata_man(datafile);
        data.loaddata_analytics(datafile);
        datafile>>t_staff;
        if(staff==NULL)
        staff=new Employee[t_staff];
        for(int i=0;i<t_staff;i++)
        {
           staff[i].loaddata_employee(datafile);
        }

    }

    bool Store::operator==(const Store&object){// first operator overload 

        if(unique_ID==object.unique_ID)
        return true;
        return false;

     }

    Store& Store::operator=(const Store& object){

    if(this == &object) 
    return *this;

    delete[] staff;
    staff = NULL;

    t_staff = object.gett_staff();

    staff = new Employee[t_staff];

    for(int i = 0; i < t_staff; i++)
    staff[i] = object.staff[i];

    name = object.getname();
    //coords
    position.setlatitude(object.position.getlatitude());
    position.setlongitude(object.position.getlongitude());
    unique_ID = object.getunique_ID();
    //manager
    manager.setage(object.manager.getage());
    manager.setEmployee_ID(object.manager.getEmployee_ID());
    manager.setname(object.manager.getname());
    manager.setPersonalID(object.manager.getPersonalID());
    manager.setrole_Employee(object.manager.getrole_Employee());
    manager.setTitle(object.manager.getTitle());
    manager.setstandingout_Points(object.manager.getstandingout_Points());
    data = object.data;

    return *this;
}
     
    ostream& operator << (ostream& out, const Store& object){

        out<<"\n===============================================================================================================================================\n";
        out<<"NAME                          :  ";
        out<<object.name<<endl<<endl;
        out<<"STORE ID                      :  ";
        out<<object.unique_ID<<endl<<endl;
        out<<"STORE LOCATION                :  [ ";
        out<<object.position.getlatitude();
        out<<" , ";
        out<<object.position.getlongitude()<<" ]"<<endl<<endl;
        out<<"MANAGER                       :  ";
        out<<object.manager.getname()<<endl<<endl;
        out<<"MANAGER_TITLE                 :  ";
        out<<object.manager.getTitle()<<endl<<endl;
        out<<"MANAGER_Standingout-Points    :  ";
        out<<object.manager.getstandingout_Points()<<endl<<endl;
        out<<"L.MONTH_Sales                 :  ";
        out<<object.data.getmonthlySales(object.data.get_Toata_M()-1)<<endl<<endl;
        out<<"L.MONTH_Expense               :  ";
        out<<object.data.getop_costs(object.data.get_Toata_M()-1)<<endl<<endl;
        out<<"L.MONTH_Customers             :  ";
        out<<object.data.getCustomer_counts(object.data.get_Toata_M()-1)<<endl<<endl;


        return out;
    }

    void Store::data_save(ofstream& data_file)
    {
        data_file<<name<<endl;
        data_file<<unique_ID<<endl;
        //bombonnn coords
        data_file<<position.getlatitude()<<" "<<position.getlongitude()<<endl;


            //manager
            data_file<<manager.getname()<<endl;
            data_file<<manager.getage()<<endl;
            data_file<<manager.getPersonalID()<<endl;
            data_file<<manager.getEmployee_ID()<<" "<<manager.getrole_Employee()<<endl;
            data_file << manager.getTitle() << endl;
            data_file << manager.getstandingout_Points() << endl;


        
        //analytocs
        data_file << data.get_Toata_M() << endl;
        for(int i=0;i<data.get_Toata_M();i++)
        {
            data_file<<data.getmonthlySales(i)<<" ";
        }
        data_file<<endl;
        for(int i=0;i<data.get_Toata_M();i++)
        {
            data_file<<data.getCustomer_counts(i)<<" ";
        }
        data_file<<endl;
        for(int i=0;i<data.get_Toata_M();i++)
        {
            data_file<<data.getop_costs(i)<<" ";
        }
        data_file<<endl;
        
        data_file<<t_staff<<endl;
        for(int i=0;i<t_staff;i++)
        {
            data_file << get_emp()[i].getname() << endl;
            data_file << get_emp()[i].getage() << " " << get_emp()[i].getPersonalID() << endl;
            data_file << get_emp()[i].getEmployee_ID() << endl;
            data_file << get_emp()[i].getrole_Employee() << endl;

        }
        data_file<<endl;

        
    }
