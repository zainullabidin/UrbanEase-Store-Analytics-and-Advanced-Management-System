#pragma once

#include<string>
#include<iostream>
#include<fstream>

using namespace std;

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
