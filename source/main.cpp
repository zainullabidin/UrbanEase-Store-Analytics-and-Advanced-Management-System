#include "../UrbanEase-Store-Analytics-and-Advanced-Management-System/source/header.h"



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

// emp

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

// manager

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

// coords

    Coordinates::Coordinates(){
    latitude=0.0f;
    longitude=0.0f;
    }

    double Coordinates::getlatitude()const{
        return latitude;
    }

    void Coordinates::setlatitude(double n){
        latitude=n;
    }

    double Coordinates::getlongitude()const{
        return longitude;
    }

    void Coordinates::setlongitude(double n){
        longitude=n;
    }

    void Coordinates::loaddata_coords(ifstream &datafile)
    {
        datafile>>latitude>>longitude;      
    }

// anal

    analytics::analytics(){

        current_month=0;

        total_months=0;

        monthlySales=NULL;;

        Customer_counts=NULL;;
       
        op_costs=NULL;;
        
        
    }
    void analytics::set_Tot(int n)
    {

        total_months = n;
        if(monthlySales!=NULL)
        delete[] monthlySales;

        if(Customer_counts!=NULL)
        delete[] Customer_counts;

        if(op_costs!=NULL)
        delete[] op_costs;

        monthlySales = new double[total_months];
        Customer_counts = new int[total_months];
        op_costs = new double[total_months];

        for(int i=0;i<total_months;i++)
        {
            monthlySales[i]=0.0;
            Customer_counts[i]=0;
            op_costs[i]=0.0;
        }
        
}
    
    analytics::~analytics(){

        delete[] monthlySales;
        delete [] Customer_counts;
        delete [] op_costs;

        monthlySales=NULL;
        Customer_counts=NULL;
        op_costs=NULL;

    }

    

    analytics::analytics(const analytics &object){

        monthlySales = NULL;
        Customer_counts = NULL;
        op_costs = NULL;
        
        set_Tot(object.get_Toata_M());

        for(int i=0; i<total_months; i++){

        monthlySales[i] = object.monthlySales[i];

        Customer_counts[i] = object.Customer_counts[i];

        op_costs[i] = object.op_costs[i];
        }


    }

    int analytics::get_Toata_M()const
    {
        return  total_months; 
    }

    void analytics::setToata_M(int n)
    {
        total_months=n;
    }

    void analytics::add_months_stats(double m_sals,double op_cst, int C_C)
    {
        analytics temp=*this;
        delete [] monthlySales;
        monthlySales=new double[temp.get_Toata_M()+1];
        delete [] Customer_counts;
        Customer_counts=new int[temp.get_Toata_M()+1];
        delete [] op_costs;
        op_costs=new double[temp.get_Toata_M()+1];

        for(int i=0;i<temp.get_Toata_M();i++)
        {
            monthlySales[i]=temp.getmonthlySales(i);
            Customer_counts[i]=temp.getCustomer_counts(i);
            op_costs[i]=temp.getop_costs(i);
        }
        
        monthlySales[temp.get_Toata_M()]=m_sals;
        Customer_counts[temp.get_Toata_M()]=C_C;
        op_costs[temp.get_Toata_M()]=op_cst;

         total_months=temp.get_Toata_M()+1;
        /// call file genrator for latest updates

    }

    double analytics::getmonthlySales(int i)const
    {
        return monthlySales[i];
    }

    void analytics::setmonthlySales(int i,double n)
    {
        monthlySales[i]=n;
    }

    double analytics::getop_costs(int i)const
    {
        return op_costs[i];
    }

    void analytics::setop_costs(int i,double n)
    {
        op_costs[i]=n;
    }

    double analytics::getCustomer_counts(int i)const
    {
        return Customer_counts[i];
    }

    void analytics::setCustomer_counts(int i,int n)
    {
        Customer_counts[i]=n;
    }

    double analytics::operator[](int i){

        return getmonthlySales(i);
    }

    void analytics::loaddata_analytics(ifstream &datafile)
    {
        datafile >> total_months;


        set_Tot(total_months);

        for(int i=0;i<total_months;i++)
        {
            datafile>> monthlySales[i];
        }
        for(int i=0;i<total_months;i++)
        {
            datafile>> Customer_counts[i];
        }
        for(int i=0;i<total_months;i++)
        {
            datafile>> op_costs[i];
        }
    }

    ostream& operator << (ostream& out, const analytics& object)
    {
        for(int i=0;i<object.get_Toata_M();i++)
        {
            out<<object.monthlySales[i]<<" ";
        }
        out<<endl;
        return out;
    }

    analytics& analytics::operator=(const analytics& object){

    if(this == &object) 
    return *this;
    set_Tot(object.get_Toata_M());

    for(int i = 0; i < total_months; i++)
    {
        monthlySales[i] = object.monthlySales[i];
        Customer_counts[i] = object.Customer_counts[i];
        op_costs[i] = object.op_costs[i];
    }
    return *this;
    }

    analytics analytics::operator +(const analytics &object)
    {
        analytics temp=*this;

        for(int i=0;i<object.get_Toata_M();i++)
        {
            temp.monthlySales[i]+=object.monthlySales[i];

            temp.Customer_counts[i]+=object.Customer_counts[i];

            temp.op_costs[i]+=object.op_costs[i];
        }
        return temp;
        
    }

    analytics analytics::operator -(const analytics &object)
    {
        analytics temp=*this;

        for(int i=0;i<total_months;i++)
        {
            temp.monthlySales[i]-=object.monthlySales[i];

            temp.Customer_counts[i]-=object.Customer_counts[i];
            
            temp.op_costs[i]-=object.op_costs[i];
        }
        
        return temp;
    }

    analytics analytics::operator *(const analytics &object)
    {

        analytics temp=*this;

        for(int i=0;i<total_months;i++)
        {
            temp.monthlySales[i]*=object.monthlySales[i];

            temp.Customer_counts[i]*=object.Customer_counts[i];
            
            temp.op_costs[i]*=object.op_costs[i];
        }
        
        return temp;
    }

    bool analytics::operator >(const analytics & object){

        double sum01=0.0,sum02=0.0;
        for(int i=0;i<total_months;i++)
        {
            sum01+=this->monthlySales[i];
            sum02+=object.monthlySales[i];
            
        }
        if(sum01<sum02)
            {
                return false;
            }
        return true;
    }

    bool analytics::operator <(const analytics & object){

        double sum01=0.0,sum02=0.0;
        for(int i=0;i<total_months;i++)
        {
            sum01+=this->monthlySales[i];
            sum02+=object.monthlySales[i];
            
        }
        if(sum01>sum02)
            {
                return false;
            }
        return true;
       
    }

    analytics & analytics::operator ++ (){

        if(current_month<total_months - 1)
        ++current_month;
        return *this;
    }

    

    analytics  analytics::operator ++ (int){
        
        analytics temp=*this;
        if(temp.current_month<total_months - 1)
        ++current_month;
        return temp;
    }

    analytics & analytics::operator --(){

        if(current_month>0)
        --current_month;
        return *this;
    }

    analytics  analytics::operator -- (int){
        
        analytics temp=*this;
        if(temp.current_month>0)
        --current_month;
        return temp;
    }

// store

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

// centrod

    Centroid::Centroid(){
        latitute=0.0;
        longitute=0.0;

    }

    double Centroid::get_latitute() const
    {
        return latitute;
    }

    void Centroid::set_latitute(double n) 
    {
        latitute=n;
    }

    double Centroid::get_longitute() const
    {
        return longitute;
    }

    void Centroid::set_longitute(double n) 
    {
        longitute=n;
    }


    bool Centroid::operator==(const Centroid &object)
    {
        if(abs(latitute-object.get_latitute())<0.0001&&abs(longitute-object.get_longitute())<0.0001)
        return true;

        return false;
    }

//ckuluster

    Cluster::Cluster(){

        cluster1cen=NULL;
        cluster2cen=NULL;
        CLUSTER01=NULL;
        CLUSTER02=NULL;

        main_size=0;
        p1=0.0,p2=0.0;

         i_c1=0;
         i_c2=0;
       
        
    }
    
    Cluster::~Cluster(){

        delete cluster1cen;
        delete cluster2cen;
        cluster1cen=NULL;
        cluster2cen=NULL;
        delete[] CLUSTER01;
        delete[] CLUSTER02;

        CLUSTER01=NULL;
        CLUSTER02=NULL;

    }

    void Cluster::intitailezer()
    {
        cluster1cen = new Store;
        cluster2cen = new Store;
        center_picker();

        CLUSTER01=new Store*[main_size];
        CLUSTER02=new Store*[main_size];
    }

    void Cluster::center_picker(){

        int i=0;
   
          i=rand()%main_size;
      
        *cluster1cen=arr[i];
        int i2=0;
        while(i2==i){
    i2=rand()%main_size;
}
        *cluster2cen=arr[i2];

    }

    void Cluster::CLUSTERER(){
        //iniotializing mains

        center01_old.set_latitute( cluster1cen->getcoords().getlatitude());
        center02_old.set_latitute( cluster2cen->getcoords().getlatitude());
        center01_old.set_longitute( cluster1cen->getcoords().getlongitude());
        center02_old.set_longitute( cluster2cen->getcoords().getlongitude());
            
int iter=100;
       while(true)
       {
            int i_mainarr;
             i_c1=0;
             i_c2=0;

        center01_old.set_latitute( cluster1cen->getcoords().getlatitude());
        center02_old.set_latitute( cluster2cen->getcoords().getlatitude());
        center01_old.set_longitute( cluster1cen->getcoords().getlongitude());
        center02_old.set_longitute( cluster2cen->getcoords().getlongitude());

        

        for(i_mainarr=0;i_mainarr<main_size;i_mainarr++)

        {
            

            //coordinates dor each clsuter
             center01_new.set_latitute(arr[i_mainarr].getcoords().getlatitude());
             center01_new.set_longitute( arr[i_mainarr].getcoords().getlongitude());
    

           p1=sqrt((center01_new.get_latitute()-center01_old.get_latitute())*(center01_new.get_latitute()-center01_old.get_latitute())+(center01_new.get_longitute()-center01_old.get_longitute())*(center01_new.get_longitute()-center01_old.get_longitute()));
           p2=sqrt((center01_new.get_latitute()-center02_old.get_latitute())*(center01_new.get_latitute()-center02_old.get_latitute())+(center01_new.get_longitute()-center02_old.get_longitute())*(center01_new.get_longitute()-center02_old.get_longitute()));


          if(p1>p2)
          {
            
            
            CLUSTER01[i_c1]=&arr[i_mainarr];//asishning to C_!
            i_c1++;
            cluster1cen->getcoords().setlatitude((center01_new.get_latitute()+ center01_old.get_latitute() *(i_c1-1))/i_c1);//updating centers
            cluster1cen->getcoords().setlongitude((center01_new.get_longitute()+ center01_old.get_longitute()*(i_c1-1) )/i_c1);

         }
         else if (p2>p1)
         {
            CLUSTER02[i_c2]=&arr[i_mainarr]; //assigning to c2
            i_c2++;


            cluster2cen->getcoords().setlatitude((center01_new.get_latitute()+ center02_old.get_latitute()*(i_c2-1) )/i_c2);//updating centers
            cluster2cen->getcoords().setlongitude((center01_new.get_longitute()+ center02_old.get_longitute() *(i_c2-1))/i_c2);

         }else
         {
            if(rand()%2==0)
            {
                CLUSTER01[i_c1]=&arr[i_mainarr];//assigning to c1
                i_c1++;
               
               cluster1cen->getcoords().setlatitude((center01_new.get_latitute()+ center01_old.get_latitute()*(i_c1-1) )/i_c1);//updating centers
              cluster1cen->getcoords().setlongitude((center01_new.get_longitute()+ center01_old.get_longitute() *(i_c1-1))/i_c1);
            }
            else{
                  CLUSTER02[i_c2]=&arr[i_mainarr];//assigning to c2
                   i_c2++;

                 cluster2cen->getcoords().setlatitude((center01_new.get_latitute()+ center02_old.get_latitute() *(i_c2-1))/i_c2);//updating centers
                  cluster2cen->getcoords().setlongitude((center01_new.get_longitute()+ center02_old.get_longitute() *(i_c2-1))/i_c2);
            }
         }


        }
        center01_new.set_latitute(cluster1cen->getcoords().getlatitude());
        center01_new.set_longitute(cluster1cen->getcoords().getlongitude());
        center02_new.set_latitute(cluster2cen->getcoords().getlatitude());
        center02_new.set_longitute(cluster2cen->getcoords().getlongitude());
        iter--;
        if (center01_old==center01_new&&center02_old==center02_new||iter==0)
        {
            break;
        }
     }

    }

    

    void Cluster::get_mainarray_size(int x)/// getting size from the main of the main stire datta array
    {
        main_size=x;
    }

    void Cluster::get_marray(Store *ptr)/// getting smain datta array
    {
        arr=ptr;
    }

    int Cluster::getcluster01_size()const{
        return i_c1 ;
    }

    int Cluster::getcluster02_size()const{
        return i_c2 ;
    }

    Store** Cluster::CLUSTr01() const{
        return CLUSTER01;
    } 

    Store** Cluster::CLUSTr02() const{
        return CLUSTER02;
    } 

    Cluster Cluster::operator+(const Cluster &object)
    {
        Cluster temp;
        temp.i_c1 = this->i_c1 + object.i_c1; 
        temp.i_c2 = this->i_c2 + object.i_c2;
        temp.CLUSTER01=new Store*[temp.i_c1];
        temp.CLUSTER02=new Store*[temp.i_c2];
        for(int i=0;i<i_c1;i++)
        {
            temp.CLUSTER01[i]=this->CLUSTER01[i];
        }
        for(int i=0;i<i_c2;i++)
        {
            temp.CLUSTER02[i]=this->CLUSTER02[i];
        }


        for(int i=this->i_c1;i<temp.i_c1;i++)
        {
            temp.CLUSTER01[i]=object.CLUSTER01[i-i_c1];
           
        }
        for(int i=this->i_c2;i<temp.i_c2;i++)
        {
            temp.CLUSTER02[i]=object.CLUSTER02[i-i_c2];
           
        }
        return temp;
    }

    ostream& operator<<(ostream& out,const Cluster & object)
    {
            system("clear");

        out<<"\n                           CLUSTER REPORT: \n\n";
        out<<" CLUSTER 01----\n";
        out<<" TOTAL STORES  : "<<(object.getcluster01_size())<<endl;
        double psudo_sum=0.0;
        for(int j=0;j<object.getcluster01_size();j++)
        for(int i=0;i<object.CLUSTr01()[j]->getanalytics().get_Toata_M();i++)
        {
            psudo_sum+=object.CLUSTr01()[j]->getanalytics().getmonthlySales(i);
        }
        
        out<<" TOTAL reVENUe: "<<psudo_sum<<endl<<endl;;

         out<<" CLUSTER 02----\n";
        out<<" TOTAL STORES  : "<<(object.getcluster02_size())<<endl;
         psudo_sum=0.0;
        for(int j=0;j<object.getcluster02_size();j++)
        for(int i=0;i<object.CLUSTr02()[j]->getanalytics().get_Toata_M();i++)
        {
            psudo_sum+=object.CLUSTr02()[j]->getanalytics().getmonthlySales(i);
        }
        
        out<<" TOTAL reVENUe: "<<psudo_sum<<endl<<endl;;

        return out;
    }

// subK

    int subCLUSTER::getC1_K1_size() const{
        return k1_size;
    }

    int subCLUSTER::getC1_K2_size() const{
        return k2_size;
    }

    int subCLUSTER::getC2_K1_size() const{
        return k1_size_2nd;
    }

    int subCLUSTER::getC2_K2_size() const{
        return k2_size_2nd;
    }

    Store** subCLUSTER::getK_1() const{
        return K_1;
    }

    Store** subCLUSTER::getK_2() const{
        return K_2;
    }

    Store** subCLUSTER::getK_1_2nd() const{
        return K_1_2nd;
    }

    Store** subCLUSTER::getK_2_2nd() const{
        return K_2_2nd;
    }

    subCLUSTER::subCLUSTER(){

        //sub cluster 01 things
        K_1=NULL;
        K_2=NULL;
        m_salesC1=0.0,m_opccostC1=0.0;
        m_salesC2=0.0,m_opccostC2=0.0;
        m_salesS=0.0,m_opccostS=0.0;

    
        st_prof=0.0,center1_prof=0.0;
        center01=NULL,center02=NULL;

        k1_size=0,k2_size=0;

        newcenter1_prof=0.0,newcenter2_prof=0.0;

        //sub clsuter 02 things

        K_1_2nd=NULL;
        K_2_2nd=NULL;
        m_salesC1_2nd=0.0,m_opccostC1_2nd=0.0;
        m_salesC2_2nd=0.0,m_opccostC2_2nd=0.0;
        m_salesS_2nd=0.0,m_opccostS_2nd=0.0;

    
        st_prof_2nd=0.0,center1_prof_2nd=0.0;
        center01_2nd=NULL,center02_2nd=NULL;

        k1_size_2nd=0,k2_size_2nd=0;

        newcenter1_prof_2nd=0.0,newcenter2_prof_2nd=0.0;

    }

    subCLUSTER::~subCLUSTER(){


    delete[] K_1;
    delete[] K_2;
    delete[] K_1_2nd;
    delete[] K_2_2nd;
    
    K_1 = NULL;
    K_2 = NULL;
    K_1_2nd = NULL;
    K_2_2nd = NULL;
    
    //aggregation ptrssss
    center01 = NULL;
    center02 = NULL;
    center01_2nd = NULL;
    center02_2nd = NULL;
}

    void subCLUSTER::subCLUSTERER_CLUSTER01(){
          ///


        centerpivker_Cluster01();

        int max_iter=100;

            k1_size=0,k2_size=0;

            for(int j=0;j<Cluster::getcluster01_size();j++)
            {
                m_salesC1=0.0,m_opccostC1=0.0;
                m_salesC2=0.0,m_opccostC2=0.0;
                m_salesS=0.0,m_opccostS=0.0;
                for(int x=0;x<center01->getanalytics().get_Toata_M();x++)
                {
                    m_salesC1+=center01->getanalytics().getmonthlySales(x);
                    m_opccostC1+=center01->getanalytics().getop_costs(x);
                }
                center1_prof=abs(m_salesC1-m_opccostC1);

                for(int x=0;x<center02->getanalytics().get_Toata_M();x++)
                {
                    m_salesC2+=center02->getanalytics().getmonthlySales(x);
                    m_opccostC2+=center02->getanalytics().getop_costs(x);
                }

                center2_prof=abs(m_salesC2-m_opccostC2);
                

                for(int x=0;x<CLUSTr01()[j]->getanalytics().get_Toata_M();x++)
                {
                    m_salesS+=Cluster::CLUSTr01()[j]->getanalytics().getmonthlySales(x);
                    m_opccostS+=Cluster::CLUSTr01()[j]->getanalytics().getop_costs(x); 
                }
                
                st_prof=abs(m_salesS-m_opccostS);
                
                if(abs(st_prof - center1_prof)<abs(st_prof - center2_prof))
                {
                    K_1[k1_size]=Cluster::CLUSTr01()[j];
                    k1_size++;


                    newcenter1_prof=((center1_prof)*(k1_size-1)+st_prof)/k1_size;


                }
                else if(abs(st_prof - center1_prof)>abs(st_prof - center2_prof))
                {
                    K_2[k2_size]=Cluster::CLUSTr01()[j];
                    k2_size++;

                    newcenter2_prof=((center2_prof)*(k2_size-1)+st_prof)/k2_size;
                }

            }
            //(abs(center1_prof - newcenter1_prof)< 100.0&&abs(center2_prof - newcenter2_prof)<  100.0)|| for better accurqacy
            
        
    
    }

    void subCLUSTER::subCLUSTERER_CLUSTER02(){
          ///

        centerpivker_Cluster02();
                      int  max_iter=100;


            k1_size_2nd=0,k2_size_2nd=0;
            for(int j=0;j<Cluster::getcluster02_size();j++)
            {
                m_salesC1_2nd=0.0,m_opccostC1_2nd=0.0;
                m_salesC2_2nd=0.0,m_opccostC2_2nd=0.0;
                m_salesS_2nd=0.0,m_opccostS_2nd=0.0;
                for(int x=0;x<center01_2nd->getanalytics().get_Toata_M();x++)
                {
                    
                    m_salesC1_2nd+=center01_2nd->getanalytics().getmonthlySales(x);
                    m_opccostC1_2nd+=center01_2nd->getanalytics().getop_costs(x);
                }
                center1_prof_2nd=abs(m_salesC1_2nd-m_opccostC1_2nd);

                for(int x=0;x<center02_2nd->getanalytics().get_Toata_M();x++)
                {
                    m_salesC2_2nd+=center02_2nd->getanalytics().getmonthlySales(x);
                    m_opccostC2_2nd+=center02_2nd->getanalytics().getop_costs(x);
                }

                center2_prof_2nd=abs(m_salesC2_2nd-m_opccostC2_2nd);
                

                for(int x=0;x<CLUSTr02()[j]->getanalytics().get_Toata_M();x++)
                {
                    m_salesS_2nd+=Cluster::CLUSTr02()[j]->getanalytics().getmonthlySales(x);

                    m_opccostS_2nd+=Cluster::CLUSTr02()[j]->getanalytics().getop_costs(x); 
                }
                
                st_prof_2nd=abs(m_salesS_2nd-m_opccostS_2nd);
                
                if(abs(st_prof_2nd - center1_prof_2nd)<abs(st_prof_2nd - center2_prof_2nd))
                {
                    K_1_2nd[k1_size_2nd]=Cluster::CLUSTr02()[j];
                    k1_size_2nd++;


                    newcenter1_prof_2nd=((center1_prof_2nd)*(k1_size_2nd-1)+st_prof_2nd)/k1_size_2nd;


                }
                else if(abs(st_prof_2nd - center1_prof_2nd)>abs(st_prof_2nd - center2_prof_2nd))
                {
                    K_2_2nd[k2_size_2nd]=Cluster::CLUSTr02()[j];
                    k2_size_2nd++;

                    newcenter2_prof_2nd=((center2_prof_2nd)*(k2_size_2nd-1)+st_prof_2nd)/k2_size_2nd;
                }

            }
            //(abs(center1_prof_2nd - newcenter1_prof_2nd)< 100.0&&abs(center2_prof_2nd - newcenter2_prof_2nd)< 100.0)|| for better accuracy

    
    }

    void subCLUSTER::centerpivker_Cluster01()
    {
        int i=0,i2=0;

        if(K_1==NULL)
        K_1=new Store*[Cluster::getcluster01_size()];
        K_2=new Store*[Cluster::getcluster01_size()];
        
        i=rand()%Cluster::getcluster01_size();
        center01=(Cluster::CLUSTr01()[i]);
        i2=i;
        while(i==i2)
        i2=rand()%Cluster::getcluster01_size();
        center02=(Cluster::CLUSTr01()[i2]);

    }

    void subCLUSTER::centerpivker_Cluster02()
    {
        int i=0,i2=0;

        if(K_1_2nd==NULL)
        K_1_2nd=new Store*[Cluster::getcluster02_size()];
        K_2_2nd=new Store*[Cluster::getcluster02_size()];
        
        i=rand()%Cluster::getcluster02_size();
        center01_2nd=(Cluster::CLUSTr02()[i]);
        i2=i;
        while(i==i2)
        i2=rand()%Cluster::getcluster02_size();
        center02_2nd=(Cluster::CLUSTr02()[i2]);

    }

    ostream& operator<<(ostream & out,const subCLUSTER & object )
    {
        out<< "\n                                      SUB_CLUSTERING REPORT\n\n";
        out<<" CLUSTER_MAIN_01 SUB_CLUSTER 01 :\n";
        out<<" TOTAL STORES :"<< object.getC1_K1_size()<<endl<<endl;

        out<<" CLUSTER_MAIN_01 SUB_CLUSTER 02 :\n";
        out<<" TOTAL STORES :"<< object.getC1_K2_size()<<endl<<endl;

        out<<" CLUSTER_MAIN_02 SUB_CLUSTER 01 :\n";
        out<<" TOTAL STORES :"<< object.getC2_K1_size()<<endl<<endl;

        out<<" CLUSTER_MAIN_02 SUB_CLUSTER 02 :\n";
        out<<" TOTAL STORES :"<< object.getC2_K2_size()<<endl<<endl;

        return out;
        
    }

// ======================== Report ========================

    Report::Report() {

        ptr=NULL;
        arr=NULL;
        Profitability=NULL,Growth_R=NULL,Total_S=NULL,Customer_C=NULL;
        t_stores=0;


        t_opcost=0.0;
         m_sales=0.0;
         t_custom=0.0;
        
        w1 = 0.40 ; //>w3
        w2 = 0.25 ;  //holds 25% weightsge
        w3 = 0.15  ;// 
        w4 = 0.20  ;// Customer Count     (footfall trend)




    }
  
    void Report::report_caller(Store **ptr,int size){

             t_stores=size;
        
            if(this->ptr==NULL)
            {
                this->ptr=ptr;
            }
            else
            {
              this->ptr=NULL;
              this->ptr=ptr;
            }
            main_ARR_maker();

    }

    void Report::main_ARR_maker(){

           //main arr
            if(this->arr==NULL)
            {
                this->arr=new double [t_stores];
            }
            else
            {
              delete [] this->arr;
              this->arr=new double [t_stores];
            }//custom
            if(this->Customer_C==NULL)
            {
                this->Customer_C=new double [t_stores];
            }
            else
            {
              delete [] this->Customer_C;
              this->Customer_C=new double [t_stores];
            }

            if(this->Growth_R==NULL)
            {
                this->Growth_R=new double [t_stores];
            }
            else
            {
              delete []  this->Growth_R;
              this->Growth_R=new double [t_stores];
            }
            if(this->Total_S==NULL)
            {
                this->Total_S=new double [t_stores];
            }
            else
            {
              delete [] this->Total_S;
              this->Total_S=new double [t_stores];
            }
            if(this->Profitability==NULL)
            {
                this->Profitability=new double [t_stores];
            }
            else
            {
              delete [] this->Profitability;
              this->Profitability=new double [t_stores];
            }

        for(int i=0;i<t_stores;i++)
        {
            t_opcost=0.0;
            m_sales=0.0;
            t_custom=0.0;

            for(int j=ptr[i]->getanalytics().get_Toata_M()-12;j<ptr[i]->getanalytics().get_Toata_M();j++)
            {
                t_opcost+=ptr[i]->getanalytics().getop_costs(j);

                m_sales+=ptr[i]->getanalytics().getmonthlySales(j);

                 t_custom+=ptr[i]->getanalytics().getCustomer_counts(j);

            }

            double sum=0.0;
            for(int j=ptr[i]->getanalytics().get_Toata_M()-12;j<ptr[i]->getanalytics().get_Toata_M()-1;j++)
            {
                sum+= ptr[i]->getanalytics().getmonthlySales(j+1)-ptr[i]->getanalytics().getmonthlySales(j);    
            }

            Total_S[i]=m_sales;
            Profitability[i]=Total_S[i]-t_opcost;
            Customer_C[i]=t_custom;
             Growth_R[i]= sum/11;


        }

        sub_ARR();
    }

    void Report::sub_ARR(){

        double P_min=Profitability[0],P_max=Profitability[0];
        double Total_S_min=Total_S[0],Total_S_max=Total_S[0];
        double Customer_C_min=Customer_C[0],Customer_C_max=Customer_C[0];
        double Growth_R_min=Growth_R[0],Growth_R_max=Growth_R[0];

            for(int i=0;i<t_stores;i++)//min /max
        {
            if(P_min>Profitability[i])
            {
                P_min=Profitability[i];
            }
            if(P_max<Profitability[i])
            {
                P_max=Profitability[i];
            }

            if(Total_S_min>Total_S[i])
            {
                Total_S_min=Total_S[i];
            }
            if(Total_S_max<Total_S[i])
            {
                Total_S_max=Total_S[i];
            }


            if(Customer_C_min>Customer_C[i])
            {
                Customer_C_min=Customer_C[i];
            }
            if(Customer_C_max<Customer_C[i])
            {
                Customer_C_max=Customer_C[i];
            }


            if(Growth_R_min>Growth_R[i])
            {
                Growth_R_min=Growth_R[i];
            }
            if(Growth_R_max<Growth_R[i])
            {
                Growth_R_max=Growth_R[i];
            }

        }


        for(int i=0;i<t_stores;i++)//norm ccal
        {

            double normP=(Profitability[i]-P_min)/(P_max-P_min);
             double normS=(Total_S[i]-Total_S_min) /(Total_S_max-Total_S_min);
            double normC=(Customer_C[i]-Customer_C_min) / (Customer_C_max-Customer_C_min);
            double normG=(Growth_R[i]-Growth_R_min)/(Growth_R_max-Growth_R_min);

            arr[i]=(w1*normP)+(w2*normG)+(w3* normS)+ (w4 * normC);

        }




    }

    void Report::sorter(){

        for(int i=0;i<t_stores;i++)
        {
            for(int j=0;j<t_stores-i-1;j++)
            {
                if(arr[j]<arr[j+1])
                {
                    double temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;

                    Store *Stemp=NULL;
                    Stemp=ptr[j];
                    ptr[j]=ptr[j+1];
                    ptr[j+1]=Stemp;

                }
            }
        }
        
    }

    void Report::print()
    {
        cout<<"\n                                                   TOP 10 STORES \n";
        for(int i=0;i<10;i++)
        {
            cout<<i+1<<"   "<<ptr[i]->getname()<<"     REPORT STAT: "<<arr[i]<<endl;
        }
        cout<<"\n                                                  BOTTOM  05  STORES \n";
        for(int i=t_stores-5;i<t_stores;i++)
        {
            cout<<i+1<<"   "<<ptr[i]->getname()<<"     REPORT STAT: "<<arr[i]<<endl;
        }

    }

    ostream& operator<<(ostream & obj,Report & r)
    {
        r.sorter();
        r.print();
        return obj;
    }

    Report::~Report(){

    delete[] arr;
    arr=NULL;
    delete[] Profitability;
    Profitability=NULL;
    delete[] Growth_R;
    Growth_R=NULL;
    delete[] Total_S;
    Total_S=NULL;
    delete[] Customer_C;
    Customer_C=NULL;
    ptr = NULL;  
}

//forecast

    Forecast::Forecast(){
        ptr=NULL;
        avg=NULL;
        Predicted_S=NULL;
        confidence=NULL;
        momentum=0.0;
        main_size=0.0;


    }

    void Forecast::displayer(){

      
        cout<<"\n                                                     FORCAST REPORT \n";
        for(int i=0;i<10;i++)
        {
            cout<<i+1<<"   "<<ptr[i]->getname()<<"        PREDICTED: "<<Predicted_S[i]<<"          CONFIDENCE : "<<confidence[i]<<endl;
            if(Predicted_S[i] < ptr[i]->getanalytics().getmonthlySales(ptr[i]->getanalytics().get_Toata_M()-1))
            {
                cout<<"\nALERT-----ALERT-------ALERT-----::::::DECLINE EXPECTED\n";
            }
        }


    }

    void Forecast::predict_call(Store ** obj,int size){


        main_size=size;

        if(ptr==NULL)
        {
            ptr=obj;
        }
        else
        {
            ptr=NULL;
            ptr = obj;
        }

        if(confidence==NULL)
        {
            confidence=new double[main_size];
        }
        else
        {
            delete [] confidence;
            confidence = new double[main_size];
        }


        if(avg==NULL)
        {
            avg=new double[main_size];
        }
        else
        {
            delete [] avg;
            avg=new double[main_size];
        }


        if(Predicted_S==NULL)
        {
            Predicted_S=new double[main_size];
        }
        else
        {
            delete [] Predicted_S;
            Predicted_S=new double[main_size];
        }

        for(int i=0;i<main_size;i++)
        {
            double sum=0.0;
            for (int j = ptr[i]->getanalytics().get_Toata_M()-4; j < ptr[i]->getanalytics().get_Toata_M(); j++)
            {
                sum+=ptr[i]->getanalytics().getmonthlySales(j);
            }
            avg[i]=sum/4;

            momentum=(ptr[i]->getanalytics().getmonthlySales(ptr[i]->getanalytics().get_Toata_M()-1)-ptr[i]->getanalytics().getmonthlySales(ptr[i]->getanalytics().get_Toata_M()-5))/2;
            Predicted_S[i]=avg[i]+0.35*momentum;

            sum=0.0;
            for (int j = ptr[i]->getanalytics().get_Toata_M()-6; j < ptr[i]->getanalytics().get_Toata_M(); j++)
            {
                sum+=ptr[i]->getanalytics().getmonthlySales(j);
            }
            double aavg=sum/6;
            double S_sum=0.0;
            for (int j =ptr[i]->getanalytics().get_Toata_M()-6; j < ptr[i]->getanalytics().get_Toata_M(); j++)
            {
                double diff = ptr[i]->getanalytics().getmonthlySales(j) - aavg;
                S_sum += diff*diff;
            }
            double dev=0.0;
            dev=sqrt(S_sum/6);
            confidence[i]=100 -((dev /aavg) * 100);
            if(confidence[i]<0)
            {
                confidence[i]=0.0;
            }
            else if(confidence[i]>100) {
                confidence[i]=100.0;
            }
        }


    }

    ostream& operator<<(ostream& out, Forecast& f)
    {
        f.displayer();
        return out;
    }

    Forecast::~Forecast(){

    delete[] avg;
    delete[] Predicted_S;
    delete[] confidence;
    
    ptr = NULL;
    
    avg = NULL;
    Predicted_S = NULL;
    confidence = NULL;
}

// visual bar graphs

    V_REP::V_REP(){
        PTR=NULL;
        size=0;
    }

    void V_REP::Visual_Charts(Store ** &ptr){

        PTR=ptr;

    }

    void V_REP::chart_store(int storeIndex)
    {
        double st_sum=0.0,bar_L=0.0;

        cout<<"\n                              STORE. :  "<<PTR[storeIndex]->getname()<<"          MONTHLY STATS (By each month)\n";
        for(int i=0;i<PTR[storeIndex]->getanalytics().get_Toata_M();i++)
        {
            if(st_sum<PTR[storeIndex]->getanalytics().getmonthlySales(i))
            st_sum=PTR[storeIndex]->getanalytics().getmonthlySales(i);
        }

        for(int i=0;i<PTR[storeIndex]->getanalytics().get_Toata_M();i++)
        {
         bar_L=(PTR[storeIndex]->getanalytics().getmonthlySales(i)/st_sum)*47;
            cout<<" MONTH : "<<i+1<<" ▏";
            for(int k = 0; k < bar_L; k++)
            {
                cout<<"▇";
            }
            for(int k=50-bar_L;k<50;k++)
            cout<<" ";
            cout<<PTR[storeIndex]->getanalytics().getmonthlySales(i);
            cout<<endl;
        }

    }
    void V_REP::chart_comparison(int* indices, int count){
        double p=0.0,max=0.0;
        double s=0.0,c=0.0;
        int bar_L=0;
        for(int i=0;i<count;i++)
        {
            p=0.0;
            s=0.0; c=0.0;
              for(int x=0;x<PTR[indices[i]]->getanalytics().get_Toata_M();x++)
              {
                s+=PTR[indices[i]]->getanalytics().getmonthlySales(x);
                c+=PTR[indices[i]]->getanalytics().getop_costs(x);
              }

            p=s-c;
            if(p>max)
            max=p;

        }

        cout<<"\n                              STORES  COMPARISON w.r.t PROFIT \n";



        for(int i=0;i<count;i++)
        {
            p=0.0;
            s=0.0; c=0.0;

            for(int x=0;x<PTR[indices[i]]->getanalytics().get_Toata_M();x++)
              {
                s+=PTR[indices[i]]->getanalytics().getmonthlySales(x);
                c+=PTR[indices[i]]->getanalytics().getop_costs(x);
              }

            p=s-c;
            
         bar_L=(p/max)*47;
            cout<<endl<<endl<<endl<<" "<<PTR[indices[i]]->getname()<<" ▏";
            for(int k = 0; k < bar_L; k++)
            {
                cout<<"▇";
            }
            for(int k=50-bar_L;k<50;k++)
            cout<<" ";
            
            cout<<endl;
        }


    }
    void V_REP::chart_clusters(subCLUSTER& obj){


        double profit1 = 0.0,profit02=0.0;
        for(int i=0;i<obj.getcluster01_size();i++)
        {
            double s=0.0,op=0.0;
            for(int k=0;k<obj.CLUSTr01()[i]->getanalytics().get_Toata_M();k++)
            {
                s+=obj.CLUSTr01()[i]->getanalytics().getmonthlySales(k);
                op+=obj.CLUSTr01()[i]->getanalytics().getop_costs(k);
            }
            profit1+=s-op;
        }
        for(int i=0;i<obj.getcluster02_size();i++)
        {
            double s=0.0,op=0.0;
            for(int k=0;k<obj.CLUSTr02()[i]->getanalytics().get_Toata_M();k++)
            {
                s+=obj.CLUSTr02()[i]->getanalytics().getmonthlySales(k);
                op+=obj.CLUSTr02()[i]->getanalytics().getop_costs(k);
            }
            profit02+=s-op;
        }

        double m=profit1>profit02?profit1:profit02;

        int b_l1=0,b_l2=0;
        b_l1=(profit1/m)*47;
        b_l2=(profit02/m)*47;

        cout<<"\n                                                 CLUSTER_WISE Profits\n";
        cout<<endl<<endl<<endl<<" CLUSTER 01  | ";
        for(int k = 0; k < b_l1; k++)
        {
            cout<<"▇";
        }
        cout<<endl;
        cout<<" CLUSTER 02  | ";
        for(int k = 0; k < b_l2; k++)
        {
            cout<<"▇";
        }

    }


    V_REP::~V_REP(){
        PTR=NULL;
    }




// main
/// main implemrntayon

int main()
{
    srand(time(0));
    //HELLALUJAH
    int choice = 0, flag = 0;
    int t_stores = 0;
    Store *object = NULL;

    start_menu(choice, flag);

    ifstream file("data.txt");
    if(!file.is_open())
        flag = 1;

    //data load
    if(choice == 1 && !flag)
    {
        loadfile(file, object, t_stores);
        if(object==NULL)
        {

            flag=1;
        }
        
    }
    else if(flag || choice == 2)
    {
        if(flag)
            cout << "ERROR LOADING FILE - GENERATING DATA\n";

        cout << "Please ENTER the number of stores (min 100): ";
        cin >> t_stores;

        while(t_stores < 100)
        {
            cout << "ERROR - Minimum 100 stores required. Enter again: ";
            cin >> t_stores;
        }

        object = new Store[t_stores];
        datagen(object, t_stores);
    }



    // CLSTER
    subCLUSTER obj;
    obj.get_mainarray_size(t_stores);
    obj.get_marray(object);
    obj.intitailezer();
    obj.CLUSTERER();
    obj.subCLUSTERER_CLUSTER01();
    obj.subCLUSTERER_CLUSTER02();
    cout << obj;

    cout<<"\nPRESS Enter any key to continue .\n";
    cin.ignore();
    getchar();
    system("clear");

    //MAIN ARRRRRR
    Store **storePtr = new Store*[t_stores];
    for(int i = 0; i < t_stores; i++)
        storePtr[i] = &object[i];

    //RANKER
    Report r;
    r.report_caller(storePtr, t_stores);
    cout << r;

    cout<<"\n\n\nPRESS Enter any key to continue .\n";

    getchar();
    system("clear");


    //FORECASTER
    Forecast f;
    f.predict_call(storePtr, t_stores);
    cout << f;


    cout<<"\n\n\nPRESS Enter any key to continue .\n";

    getchar();
    system("clear");
    //implementing the visuals

    V_REP objec;
    objec.Visual_Charts(storePtr);
    int storeIndex=0;




    //chart01
    cout << "Enter store index for monthly chart: ";
    int_validatoe(storeIndex);
    objec.chart_store(storeIndex);

    cout<<"\nPRESS Enter any key to continue .\n";
cin.ignore();
    getchar();
    system("clear");


//chart02
    int count = 0;
    cout << "ENTER the number of stores to compare: ";

    int_validatoe(count);

    int* indices = new int[count];

    for(int i = 0; i < count; i++)
    {
        cout << "Enter store index " << i+1 << ": ";
        
        int_validatoe(indices[i]);
        while(indices[i]>=t_stores)
        {
            cout<<"PLEASE Enter the stores within the range : "<<t_stores;
            int_validatoe(indices[i]);
        }
        
    }
    objec.chart_comparison(indices, count);
    delete[] indices;

    cout<<"\n\n\nPRESS Enter any key to continue .\n";

    cin.ignore();
    getchar();
    system("clear");
//3rd chart
    objec.chart_clusters(obj);



    cout<<"\n\n\nPRESS Enter any key to continue .\n";

    cin.ignore();
    getchar();
    system("clear");
    // ++/--



    // freeee YIPPIE
    delete[] storePtr;
    storePtr = NULL;
    delete[] object;
    object = NULL;
}



    void datagen(Store *& object, int t_stores)
    {
        //some arrays for randomized datagen

    string arr_st_name[] = {"Beretta Pakistan", "Scopes & Barrels",  "Barki Armoury",   "Tactical Arms", "Bandook Wala", "Badaruddin & Sons", "Alpiyal Enterprises",  "Buksh Elahi & Co",  "Fazal Sons", "Jan & Sons"};

    int arr_st_age[] = { 10, 25, 15, 21, 30, 50, 12, 60, 40, 35 };

    string arr_st_person_names[] = { "Ahmed Ali Mansoor", "Zubair Shahidi", "Omar Barki", "Mustafa Khan", "Abbas Bandukwala", "Faisal Badaruddin", "Wasif Ali Alpiyal", "Saeed Ahmed Buksh", "Kamran Fazal", "Jamshed Afridi" };

    double arr_st_standing_out[] = { 9.8, 9.5, 9.2, 8.9, 8.5, 9.0, 8.2, 9.4, 8.7, 9.1 };

    double arr_st_coords[][2] = { {33.6844, 73.0479}, {24.8609, 67.0261}, {34.0151, 71.5249}, {31.5204, 74.3587}, {24.8607, 67.0011}, {33.5973, 73.0479}, {33.6366, 72.9691}, {31.5622, 74.3213}, {33.5950, 73.0543}, {33.6874, 71.4933} };

    double base_monthly_sales[] = { 120.5, 132.0, 145.2, 128.8, 150.0, 175.5, 190.2, 185.0, 160.5, 155.0, 210.8, 250.0, 230.5, 245.0, 260.2, 215.8, 230.0, 285.5, 310.2, 305.0, 280.5, 275.0, 350.8, 400.0 };

    int base_customer_counts[] = { 45, 50, 55, 48, 60, 75, 82, 80, 65, 62, 95, 120, 110, 115, 125, 105, 112, 140, 155, 150, 135, 130, 180, 210 };

    string arr_emp_roles[] = { "Sales Associate", "Security Guard", "Inventory Clerk", "Technician", "Accountant" };

    double base_op_costs[] = { 80.0, 82.5, 85.0, 81.0, 88.5, 95.0, 98.2, 97.0, 92.5, 90.0, 110.8, 125.0, 115.5, 118.0, 122.2, 112.8, 118.0, 135.5, 145.2, 142.0, 138.5, 135.0, 165.8, 180.0 };

    string arr_manager_titles[] = { "Chief Executive Officer", "Senior Branch Manager", "Operations Director", "Regional Sales Manager", "Managing Director", "Chief Superintendent", "General Manager", "Principal Partner", "Executive Manager", "District Supervisor" };


                for(int i=0;i<t_stores;i++)
                {
                    //store namw
                    object[i].setname(arr_st_name[rand()%10]);
                    //store id
                    object[i].setunique_ID(i+1);
                    //coords for each store
                    object[i].getcoords().setlatitude(arr_st_coords[rand()%9][0]);
                    object[i].getcoords().setlongitude(arr_st_coords[rand()%9][1]);

                    //manager of eacg store
                    object[i].getman().setage(arr_st_age[rand()%10]);
                    object[i].getman().setEmployee_ID(t_stores+1);
                    object[i].getman().setname(arr_st_person_names[rand()%10]);
                    object[i].getman().setPersonalID(t_stores-1);
                    object[i].getman().setrole_Employee(arr_emp_roles[rand()%5]);
                    object[i].getman().setstandingout_Points(arr_st_standing_out[rand()%10]);
                    object[i].getman().setTitle(arr_manager_titles[rand()%10]);
                
                    object[i].getanalytics().set_Tot(24);
                    //store analytics
                    for(int j=0;j<object[i].getanalytics().get_Toata_M();j++)
                    {
                        object[i].getanalytics().setmonthlySales(j,base_monthly_sales[j]*0.5 + (rand()%150)/100.0);
                        object[i].getanalytics().setCustomer_counts(j,base_customer_counts[j]*0.5 + (rand()%150)/100.0);
                        object[i].getanalytics().setop_costs(j,base_op_costs[j]*0.5 + (rand()%150)/100.0);
                    }

                    //emplyee 
                    object[i].sett_staff(rand()%50+20);
                    object[i].allocate_staff();

                    for(int j=0;j<object[i].gett_staff();j++)
                    {
                        object[i].get_emp()[j].setage(arr_st_age[rand()%10]);
                        object[i].get_emp()[j].setEmployee_ID(t_stores+1);
                        object[i].get_emp()[j].setname(arr_st_person_names[rand()%10]);
                        object[i].get_emp()[j].setPersonalID(t_stores-1);
                        object[i].get_emp()[j].setrole_Employee(arr_emp_roles[rand()%5]);

                    }
                    
                }
            
                //writing to file
                    ofstream datafile("data.txt");
                    
                        datafile<<t_stores<<endl;

                        for(int x=0;x<t_stores;x++)
                        {
                            object[x].data_save(datafile);
                        }
                        cout<<"DATA SUCCESSFULLY STORED TO. \" data.txt\"";


        }

    void start_menu(int &choice, int &flag)
    {
        cout<<"1. Load from file\n\n2. Generate new data\n";
        do{
        if(flag)
        {
            cout<<"ENTER AGAIN.....       :";
            cin>>choice;
            flag=0;
        }

        else
        {
            cout<<"Please ENTER your choice : ";
            cin>>choice;
            flag=0;
        }

        if(choice>2||choice<1)
        flag=2;

         }while(flag);//va;idatomng choice

    }

    void loadfile(ifstream &file, Store *& object, int & size)
    {
             file>>size;
             
             if(size<0)

             {
                cout<<"\nCORUUPTED FILE\n";
                return;
             }
             object=new Store[size];
             for(int i=0;i<size;i++)
             object[i].load_maindata(file);
             cout<<" DATA SUCCESSFULLY LOADED FROM \"data.txt\"";
    }


  void int_validatoe(int & n)
  {
    
    int flag=0;
    do {
        cin >> n;
        if(cin.fail() || n < 0)
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\nYOU ENTERED WRONG... Enter Again: ";
        }
        else 
        break;
    } while(true);
}