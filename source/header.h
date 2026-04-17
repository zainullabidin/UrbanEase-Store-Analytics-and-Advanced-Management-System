#ifndef MAIN_H
#define MAIN_H

#include<iostream>
#include<string>
#include<ctime>
#include<fstream>
#include<cmath>
using namespace std;

class Store;

void datagen(Store *& object, int t_stores);

void int_validatoe(int & n);

void start_menu(int &choice, int &flag);

void loadfile(ifstream &file, Store *& object, int &size);

class Person{

private:
    string name;
    int age;
    int PersonalID;
public:

Person();

virtual ~Person(){}
    string getname()const;
    void setname(string a);
    int getage()const;
    void setage(int n);
    int getPersonalID()const;
    void setPersonalID(int n);
    void loaddatafromfile(ifstream&datafile);

    virtual void display();

};//parent

class Employee: public Person{

private:

    int Employee_ID;
    string role_Employee;


public:

    Employee();

    int getEmployee_ID()const;

    void setEmployee_ID(int n);

    string getrole_Employee()const;

    void setrole_Employee(string a);
    
    void loaddata_employee(ifstream& datafile);

    void display() override;

};//childEmployee_ID

class Manager :public Employee{
private:

    string title;
    double standingout_Points;

public:

    Manager();

    string getTitle()const;

    void setTitle(string a);

    double getstandingout_Points()const;

    void setstandingout_Points(double n);

    void loaddata_man(ifstream &datafile);
   
    void display() override;

};//child ka child

class Coordinates{

private:
    double latitude;
    double longitude;

public:
    Coordinates();

    double getlatitude()const;

    void setlatitude(double n);

    double getlongitude()const;

    void setlongitude(double n);

    void loaddata_coords(ifstream &datafile);

};

class analytics{

private:

    int current_month;

   double *op_costs;
   int *Customer_counts;
   double* monthlySales; 
   int total_months;

public:

    analytics();

    void set_Tot(int n);
    
    ~analytics();

    analytics(const analytics &object);

    int get_Toata_M()const;

    void setToata_M(int n);

    void add_months_stats(double m_sals,double op_cst, int C_C);

    double getmonthlySales(int i)const;

    void setmonthlySales(int i,double n);

    double getop_costs(int i)const;

    void setop_costs(int i,double n);

    double getCustomer_counts(int i)const;

    void setCustomer_counts(int i,int n);

    double operator[](int i);

    void loaddata_analytics(ifstream &datafile);

    friend ostream& operator << (ostream& out, const analytics& object);

    analytics& operator=(const analytics& object);

    analytics operator +(const analytics &object);

    analytics operator -(const analytics &object);

    analytics operator *(const analytics &object);

    bool operator >(const analytics & object);

    bool operator <(const analytics & object);

    analytics & operator ++ ();

    analytics  operator ++ (int);

    analytics & operator --();

    analytics  operator -- (int);

};

class Store{

private:

    string name;
    int unique_ID;
    Coordinates position;
    Manager manager;
    analytics data;
    Employee *staff;
    int t_staff;


public:

    Store();

    ~Store();

     Store(const Store&object);

    void setname(string n);

    string getname()const;

    void setunique_ID(int n);

    int getunique_ID()const;

    void sett_staff(int n);

    int gett_staff()const;

    analytics& getanalytics();

    void allocate_staff();

    Manager& getman();

    Employee*& get_emp();

    Coordinates& getcoords();

    void load_maindata(ifstream & datafile);

    bool operator==(const Store&object);

    Store& operator=(const Store& object);
     
    friend ostream& operator << (ostream& out, const Store& object);

    void data_save(ofstream& data_file);

};

class Centroid{

private:

    double latitute;
    double longitute;

public:

    Centroid();

    double get_latitute() const;

    void set_latitute(double n);

    double get_longitute() const;

    void set_longitute(double n);

    bool operator==(const Centroid &object);

};

class Cluster{

private:
    Store *cluster1cen;

    Store **CLUSTER01,**CLUSTER02;

    Centroid center01_old,center01_new;

    Centroid center02_old,center02_new;

    double p1,p2;

    int i_c1;
    int i_c2;


    Store *cluster2cen;
    int main_size;
    Store *arr;
public:

    Cluster();
    
    ~Cluster();

    void intitailezer();

    void center_picker();

    void CLUSTERER();

    void get_mainarray_size(int x);

    void get_marray(Store *ptr);

    int getcluster01_size()const;

    int getcluster02_size()const;

    Store** CLUSTr01() const;

    Store** CLUSTr02() const;

    Cluster operator+(const Cluster &object);

    friend ostream& operator<<(ostream& out,const Cluster & object);

};

class subCLUSTER:public Cluster{

private:

    /// @sub cluster sub cluster 01 data mems
    Store **K_1;
    Store **K_2;

    Store *center01,*center02;
    double m_salesC1,m_opccostC1;
     double m_salesC2,m_opccostC2;
    double m_salesS,m_opccostS;

    double st_prof,center1_prof,center2_prof;
    double newcenter1_prof,newcenter2_prof;

    int k1_size,k2_size;


    //subcluster02 datamebers

    Store **K_1_2nd;
    Store **K_2_2nd;

    Store *center01_2nd,*center02_2nd;
    double m_salesC1_2nd,m_opccostC1_2nd;
     double m_salesC2_2nd,m_opccostC2_2nd;
    double m_salesS_2nd,m_opccostS_2nd;

    double st_prof_2nd,center1_prof_2nd,center2_prof_2nd;
    double newcenter1_prof_2nd,newcenter2_prof_2nd;

    int k1_size_2nd,k2_size_2nd;



public:

    int getC1_K1_size() const;

    int getC1_K2_size() const;

    int getC2_K1_size() const;

    int getC2_K2_size() const;

    Store** getK_1() const;

    Store** getK_2() const;

    Store** getK_1_2nd() const;

    Store** getK_2_2nd() const;

    subCLUSTER();

    ~subCLUSTER();

    void subCLUSTERER_CLUSTER01();

    void subCLUSTERER_CLUSTER02();

    void centerpivker_Cluster01();

    void centerpivker_Cluster02();

    friend ostream& operator<<(ostream & out,const subCLUSTER & object);

};

class Report{

private:

    int t_stores;
    Store **ptr;

    double *arr;

    double t_opcost;
    double m_sales;
    double t_custom;
     
    double w1,w2,w3,w4;

    double* Profitability,*Growth_R,*Total_S,*Customer_C;

public:

    Report();
  
    void report_caller(Store **ptr,int size);

    void main_ARR_maker();

    void sub_ARR();

    void sorter();

    void print();

    friend ostream& operator<<(ostream & obj,Report & r);

    ~Report();

};

class Forecast{

private:

    Store **ptr;
    double *avg;
    int main_size;
    double momentum;
    double *Predicted_S;
    double *confidence;

public:

    Forecast();

    void displayer();

    void predict_call(Store ** obj,int size);

    friend ostream& operator<<(ostream& out, Forecast& f);

    ~Forecast();

};

class V_REP{

private:
    Store** PTR;
    int size;
public:

    V_REP();

    void Visual_Charts(Store ** &ptr);

    void chart_store(int storeIndex);

    void chart_comparison(int* indices, int count);

    void chart_clusters(subCLUSTER& obj);

    ~V_REP();

};

#endif