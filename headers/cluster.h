#pragma once

#include<string>
#include<iostream>
#include<cmath>

#include "stores.h"

using namespace std;

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
