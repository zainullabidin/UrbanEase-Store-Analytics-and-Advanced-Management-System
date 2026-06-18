#pragma once

#include<string>
#include<iostream>
#include <fstream>


using namespace std;

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
