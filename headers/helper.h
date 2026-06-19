#pragma once

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

void starter();