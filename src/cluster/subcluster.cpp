#include"cluster.h"


    int subCLUSTER::getC1_K1_size() const{
        return k1_size;
    }

    int subCLUSTER::getC1_K2_size() const{
        return k2_size;
    }

    int subCLUSTER::getC2_K1_size() const{
        return k1_size_2nd;
    }

    int subCLUSTER::getC2_K2_size() const{
        return k2_size_2nd;
    }

    Store** subCLUSTER::getK_1() const{
        return K_1;
    }

    Store** subCLUSTER::getK_2() const{
        return K_2;
    }

    Store** subCLUSTER::getK_1_2nd() const{
        return K_1_2nd;
    }

    Store** subCLUSTER::getK_2_2nd() const{
        return K_2_2nd;
    }

    subCLUSTER::subCLUSTER(){

        //sub cluster 01 things
        K_1=NULL;
        K_2=NULL;
        m_salesC1=0.0,m_opccostC1=0.0;
        m_salesC2=0.0,m_opccostC2=0.0;
        m_salesS=0.0,m_opccostS=0.0;

    
        st_prof=0.0,center1_prof=0.0;
        center01=NULL,center02=NULL;

        k1_size=0,k2_size=0;

        newcenter1_prof=0.0,newcenter2_prof=0.0;

        //sub clsuter 02 things

        K_1_2nd=NULL;
        K_2_2nd=NULL;
        m_salesC1_2nd=0.0,m_opccostC1_2nd=0.0;
        m_salesC2_2nd=0.0,m_opccostC2_2nd=0.0;
        m_salesS_2nd=0.0,m_opccostS_2nd=0.0;

    
        st_prof_2nd=0.0,center1_prof_2nd=0.0;
        center01_2nd=NULL,center02_2nd=NULL;

        k1_size_2nd=0,k2_size_2nd=0;

        newcenter1_prof_2nd=0.0,newcenter2_prof_2nd=0.0;

    }

    subCLUSTER::~subCLUSTER(){


    delete[] K_1;
    delete[] K_2;
    delete[] K_1_2nd;
    delete[] K_2_2nd;
    
    K_1 = NULL;
    K_2 = NULL;
    K_1_2nd = NULL;
    K_2_2nd = NULL;
    
    //aggregation ptrssss
    center01 = NULL;
    center02 = NULL;
    center01_2nd = NULL;
    center02_2nd = NULL;
}

    void subCLUSTER::subCLUSTERER_CLUSTER01(){
          ///


        centerpivker_Cluster01();

        int max_iter=100;

            k1_size=0,k2_size=0;

            for(int j=0;j<Cluster::getcluster01_size();j++)
            {
                m_salesC1=0.0,m_opccostC1=0.0;
                m_salesC2=0.0,m_opccostC2=0.0;
                m_salesS=0.0,m_opccostS=0.0;
                for(int x=0;x<center01->getanalytics().get_Toata_M();x++)
                {
                    m_salesC1+=center01->getanalytics().getmonthlySales(x);
                    m_opccostC1+=center01->getanalytics().getop_costs(x);
                }
                center1_prof=abs(m_salesC1-m_opccostC1);

                for(int x=0;x<center02->getanalytics().get_Toata_M();x++)
                {
                    m_salesC2+=center02->getanalytics().getmonthlySales(x);
                    m_opccostC2+=center02->getanalytics().getop_costs(x);
                }

                center2_prof=abs(m_salesC2-m_opccostC2);
                

                for(int x=0;x<CLUSTr01()[j]->getanalytics().get_Toata_M();x++)
                {
                    m_salesS+=Cluster::CLUSTr01()[j]->getanalytics().getmonthlySales(x);
                    m_opccostS+=Cluster::CLUSTr01()[j]->getanalytics().getop_costs(x); 
                }
                
                st_prof=abs(m_salesS-m_opccostS);
                
                if(abs(st_prof - center1_prof)<abs(st_prof - center2_prof))
                {
                    K_1[k1_size]=Cluster::CLUSTr01()[j];
                    k1_size++;


                    newcenter1_prof=((center1_prof)*(k1_size-1)+st_prof)/k1_size;


                }
                else if(abs(st_prof - center1_prof)>abs(st_prof - center2_prof))
                {
                    K_2[k2_size]=Cluster::CLUSTr01()[j];
                    k2_size++;

                    newcenter2_prof=((center2_prof)*(k2_size-1)+st_prof)/k2_size;
                }

            }
            //(abs(center1_prof - newcenter1_prof)< 100.0&&abs(center2_prof - newcenter2_prof)<  100.0)|| for better accurqacy
            
        
    
    }

    void subCLUSTER::subCLUSTERER_CLUSTER02(){
          ///

        centerpivker_Cluster02();
                      int  max_iter=100;


            k1_size_2nd=0,k2_size_2nd=0;
            for(int j=0;j<Cluster::getcluster02_size();j++)
            {
                m_salesC1_2nd=0.0,m_opccostC1_2nd=0.0;
                m_salesC2_2nd=0.0,m_opccostC2_2nd=0.0;
                m_salesS_2nd=0.0,m_opccostS_2nd=0.0;
                for(int x=0;x<center01_2nd->getanalytics().get_Toata_M();x++)
                {
                    
                    m_salesC1_2nd+=center01_2nd->getanalytics().getmonthlySales(x);
                    m_opccostC1_2nd+=center01_2nd->getanalytics().getop_costs(x);
                }
                center1_prof_2nd=abs(m_salesC1_2nd-m_opccostC1_2nd);

                for(int x=0;x<center02_2nd->getanalytics().get_Toata_M();x++)
                {
                    m_salesC2_2nd+=center02_2nd->getanalytics().getmonthlySales(x);
                    m_opccostC2_2nd+=center02_2nd->getanalytics().getop_costs(x);
                }

                center2_prof_2nd=abs(m_salesC2_2nd-m_opccostC2_2nd);
                

                for(int x=0;x<CLUSTr02()[j]->getanalytics().get_Toata_M();x++)
                {
                    m_salesS_2nd+=Cluster::CLUSTr02()[j]->getanalytics().getmonthlySales(x);

                    m_opccostS_2nd+=Cluster::CLUSTr02()[j]->getanalytics().getop_costs(x); 
                }
                
                st_prof_2nd=abs(m_salesS_2nd-m_opccostS_2nd);
                
                if(abs(st_prof_2nd - center1_prof_2nd)<abs(st_prof_2nd - center2_prof_2nd))
                {
                    K_1_2nd[k1_size_2nd]=Cluster::CLUSTr02()[j];
                    k1_size_2nd++;


                    newcenter1_prof_2nd=((center1_prof_2nd)*(k1_size_2nd-1)+st_prof_2nd)/k1_size_2nd;


                }
                else if(abs(st_prof_2nd - center1_prof_2nd)>abs(st_prof_2nd - center2_prof_2nd))
                {
                    K_2_2nd[k2_size_2nd]=Cluster::CLUSTr02()[j];
                    k2_size_2nd++;

                    newcenter2_prof_2nd=((center2_prof_2nd)*(k2_size_2nd-1)+st_prof_2nd)/k2_size_2nd;
                }

            }
            //(abs(center1_prof_2nd - newcenter1_prof_2nd)< 100.0&&abs(center2_prof_2nd - newcenter2_prof_2nd)< 100.0)|| for better accuracy

    
    }

    void subCLUSTER::centerpivker_Cluster01()
    {
        int i=0,i2=0;

        if(K_1==NULL)
        K_1=new Store*[Cluster::getcluster01_size()];
        K_2=new Store*[Cluster::getcluster01_size()];
        
        i=rand()%Cluster::getcluster01_size();
        center01=(Cluster::CLUSTr01()[i]);
        i2=i;
        while(i==i2)
        i2=rand()%Cluster::getcluster01_size();
        center02=(Cluster::CLUSTr01()[i2]);

    }

    void subCLUSTER::centerpivker_Cluster02()
    {
        int i=0,i2=0;

        if(K_1_2nd==NULL)
        K_1_2nd=new Store*[Cluster::getcluster02_size()];
        K_2_2nd=new Store*[Cluster::getcluster02_size()];
        
        i=rand()%Cluster::getcluster02_size();
        center01_2nd=(Cluster::CLUSTr02()[i]);
        i2=i;
        while(i==i2)
        i2=rand()%Cluster::getcluster02_size();
        center02_2nd=(Cluster::CLUSTr02()[i2]);

    }

    ostream& operator<<(ostream & out,const subCLUSTER & object )
    {
        out<< "\n                                      SUB_CLUSTERING REPORT\n\n";
        out<<" CLUSTER_MAIN_01 SUB_CLUSTER 01 :\n";
        out<<" TOTAL STORES :"<< object.getC1_K1_size()<<endl<<endl;

        out<<" CLUSTER_MAIN_01 SUB_CLUSTER 02 :\n";
        out<<" TOTAL STORES :"<< object.getC1_K2_size()<<endl<<endl;

        out<<" CLUSTER_MAIN_02 SUB_CLUSTER 01 :\n";
        out<<" TOTAL STORES :"<< object.getC2_K1_size()<<endl<<endl;

        out<<" CLUSTER_MAIN_02 SUB_CLUSTER 02 :\n";
        out<<" TOTAL STORES :"<< object.getC2_K2_size()<<endl<<endl;

        return out;
        
    }
