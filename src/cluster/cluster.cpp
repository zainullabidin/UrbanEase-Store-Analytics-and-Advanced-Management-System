#include"cluster.h"


    
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
        int i2=rand()%main_size;
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


          if(p1<p2)
          {
            
            
            CLUSTER01[i_c1]=&arr[i_mainarr];//asishning to C_!
            i_c1++;
            cluster1cen->getcoords().setlatitude((center01_new.get_latitute()+ cluster1cen->getcoords().getlatitude() *(i_c1-1))/i_c1);//updating centers
            cluster1cen->getcoords().setlongitude((center01_new.get_longitute()+ cluster1cen->getcoords().getlongitude()*(i_c1-1) )/i_c1);

         }
         else if (p2<p1)
         {
            CLUSTER02[i_c2]=&arr[i_mainarr]; //assigning to c2
            i_c2++;


            cluster2cen->getcoords().setlatitude((center01_new.get_latitute()+ cluster2cen->getcoords().getlatitude()*(i_c2-1) )/i_c2);//updating centers
            cluster2cen->getcoords().setlongitude((center01_new.get_longitute()+ cluster2cen->getcoords().getlongitude() *(i_c2-1))/i_c2);

         }else
         {
            if(rand()%2==0)
            {
                CLUSTER01[i_c1]=&arr[i_mainarr];//assigning to c1
                i_c1++;
               
               cluster1cen->getcoords().setlatitude((center01_new.get_latitute()+ cluster1cen->getcoords().getlatitude()*(i_c1-1) )/i_c1);//updating centers
              cluster1cen->getcoords().setlongitude((center01_new.get_longitute()+ cluster1cen->getcoords().getlongitude() *(i_c1-1))/i_c1);
            }
            else{
                  CLUSTER02[i_c2]=&arr[i_mainarr];//assigning to c2
                   i_c2++;

                 cluster2cen->getcoords().setlatitude((center01_new.get_latitute()+ cluster2cen->getcoords().getlatitude() *(i_c2-1))/i_c2);//updating centers
                  cluster2cen->getcoords().setlongitude((center01_new.get_longitute()+ cluster2cen->getcoords().getlongitude() *(i_c2-1))/i_c2);
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
