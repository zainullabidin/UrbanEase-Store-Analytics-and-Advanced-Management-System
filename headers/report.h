#pragma once

#include<string>
#include<iostream>
#include<cmath>
#include<fstream>

#include "store.h"

using namespace std;

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
