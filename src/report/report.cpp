#include"report.h"

    Report::Report() {

        ptr=NULL;
        arr=NULL;
        Profitability=NULL,Growth_R=NULL,Total_S=NULL,Customer_C=NULL;
        t_stores=0;


        t_opcost=0.0;
         m_sales=0.0;
         t_custom=0.0;
        
        w1 = 0.40 ; //>w3
        w2 = 0.25 ;  //holds 25% weightsge
        w3 = 0.15  ;// 
        w4 = 0.20  ;// Customer Count     (footfall trend)




    }
  
    void Report::report_caller(Store **ptr,int size){

             t_stores=size;
        
            if(this->ptr==NULL)
            {
                this->ptr=ptr;
            }
            else
            {
              this->ptr=NULL;
              this->ptr=ptr;
            }
            main_ARR_maker();

    }

    void Report::main_ARR_maker(){

           //main arr
            if(this->arr==NULL)
            {
                this->arr=new double [t_stores];
            }
            else
            {
              delete [] this->arr;
              this->arr=new double [t_stores];
            }//custom
            if(this->Customer_C==NULL)
            {
                this->Customer_C=new double [t_stores];
            }
            else
            {
              delete [] this->Customer_C;
              this->Customer_C=new double [t_stores];
            }

            if(this->Growth_R==NULL)
            {
                this->Growth_R=new double [t_stores];
            }
            else
            {
              delete []  this->Growth_R;
              this->Growth_R=new double [t_stores];
            }
            if(this->Total_S==NULL)
            {
                this->Total_S=new double [t_stores];
            }
            else
            {
              delete [] this->Total_S;
              this->Total_S=new double [t_stores];
            }
            if(this->Profitability==NULL)
            {
                this->Profitability=new double [t_stores];
            }
            else
            {
              delete [] this->Profitability;
              this->Profitability=new double [t_stores];
            }

        for(int i=0;i<t_stores;i++)
        {
            t_opcost=0.0;
            m_sales=0.0;
            t_custom=0.0;

            for(int j=ptr[i]->getanalytics().get_Toata_M()-12;j<ptr[i]->getanalytics().get_Toata_M();j++)
            {
                t_opcost+=ptr[i]->getanalytics().getop_costs(j);

                m_sales+=ptr[i]->getanalytics().getmonthlySales(j);

                 t_custom+=ptr[i]->getanalytics().getCustomer_counts(j);

            }

            double sum=0.0;
            for(int j=ptr[i]->getanalytics().get_Toata_M()-12;j<ptr[i]->getanalytics().get_Toata_M()-1;j++)
            {
                sum+= ptr[i]->getanalytics().getmonthlySales(j+1)-ptr[i]->getanalytics().getmonthlySales(j);    
            }

            Total_S[i]=m_sales;
            Profitability[i]=Total_S[i]-t_opcost;
            Customer_C[i]=t_custom;
             Growth_R[i]= sum/11;


        }

        sub_ARR();
    }

    void Report::sub_ARR(){

        double P_min=Profitability[0],P_max=Profitability[0];
        double Total_S_min=Total_S[0],Total_S_max=Total_S[0];
        double Customer_C_min=Customer_C[0],Customer_C_max=Customer_C[0];
        double Growth_R_min=Growth_R[0],Growth_R_max=Growth_R[0];

            for(int i=0;i<t_stores;i++)//min /max
        {
            if(P_min>Profitability[i])
            {
                P_min=Profitability[i];
            }
            if(P_max<Profitability[i])
            {
                P_max=Profitability[i];
            }

            if(Total_S_min>Total_S[i])
            {
                Total_S_min=Total_S[i];
            }
            if(Total_S_max<Total_S[i])
            {
                Total_S_max=Total_S[i];
            }


            if(Customer_C_min>Customer_C[i])
            {
                Customer_C_min=Customer_C[i];
            }
            if(Customer_C_max<Customer_C[i])
            {
                Customer_C_max=Customer_C[i];
            }


            if(Growth_R_min>Growth_R[i])
            {
                Growth_R_min=Growth_R[i];
            }
            if(Growth_R_max<Growth_R[i])
            {
                Growth_R_max=Growth_R[i];
            }

        }


        for(int i=0;i<t_stores;i++)//norm ccal
        {

            double normP=(Profitability[i]-P_min)/(P_max-P_min);
             double normS=(Total_S[i]-Total_S_min) /(Total_S_max-Total_S_min);
            double normC=(Customer_C[i]-Customer_C_min) / (Customer_C_max-Customer_C_min);
            double normG=(Growth_R[i]-Growth_R_min)/(Growth_R_max-Growth_R_min);

            arr[i]=(w1*normP)+(w2*normG)+(w3* normS)+ (w4 * normC);

        }




    }

    void Report::sorter(){

        for(int i=0;i<t_stores;i++)
        {
            for(int j=0;j<t_stores-i-1;j++)
            {
                if(arr[j]<arr[j+1])
                {
                    double temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;

                    Store *Stemp=NULL;
                    Stemp=ptr[j];
                    ptr[j]=ptr[j+1];
                    ptr[j+1]=Stemp;

                }
            }
        }
        
    }

    void Report::print()
    {
        cout<<"\n                                                   TOP 10 STORES \n";
        for(int i=0;i<10;i++)
        {
            cout<<i+1<<"   "<<ptr[i]->getname()<<"     REPORT STAT: "<<arr[i]<<endl;
        }
        cout<<"\n                                                  BOTTOM  05  STORES \n";
        for(int i=t_stores-5;i<t_stores;i++)
        {
            cout<<i+1<<"   "<<ptr[i]->getname()<<"     REPORT STAT: "<<arr[i]<<endl;
        }

    }

    ostream& operator<<(ostream & obj,Report & r)
    {
        r.sorter();
        r.print();
        return obj;
    }

    Report::~Report(){

    delete[] arr;
    arr=NULL;
    delete[] Profitability;
    Profitability=NULL;
    delete[] Growth_R;
    Growth_R=NULL;
    delete[] Total_S;
    Total_S=NULL;
    delete[] Customer_C;
    Customer_C=NULL;
    ptr = NULL;  
}
