#include"report.h"
   
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
