#include"store.h"


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
