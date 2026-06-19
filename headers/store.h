#pragma once

#include<string>
#include<iostream>

#include"stakeholder.h"
#include"analytics.h"

class Coordinates;

using namespace std;

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
