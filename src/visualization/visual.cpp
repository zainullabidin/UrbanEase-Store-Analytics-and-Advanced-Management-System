#include"visual.h"
#include"cluster.h"


V_REP::V_REP(){
        PTR=NULL;
        size=0;
    }

    void V_REP::Visual_Charts(Store ** &ptr){

        PTR=ptr;
        system("mkdir -p output");

    }

    void V_REP::chart_store(int storeIndex)
    {
        ofstream html("output/chart_store.html");

        html<<"<!DOCTYPE html><html><head><script src='https://cdn.jsdelivr.net/npm/chart.js'></script></head><body>";
        html<<"<h2>"<<PTR[storeIndex]->getname()<<" - Monthly Sales</h2>";
        html<<"<canvas id='c'></canvas><script>";
        html<<"new Chart(document.getElementById('c'),{type:'bar',data:{labels:[";

        for(int i=0;i<PTR[storeIndex]->getanalytics().get_Toata_M();i++)
        {
            html<<"'Month "<<i+1<<"',";
        }

        html<<"],datasets:[{label:'Sales',backgroundColor:'rgba(255,165,0,0.7)',data:[";

        for(int i=0;i<PTR[storeIndex]->getanalytics().get_Toata_M();i++)
        {
            html<<PTR[storeIndex]->getanalytics().getmonthlySales(i)<<",";
        }

        html<<"]}]}});</script></body></html>";
        html.close();

        cout<<"\n Chart saved to output/chart_store.html\n";
    }

    void V_REP::chart_comparison(int* indices, int count){
        double p=0.0;
        double s=0.0,c=0.0;

        ofstream html("output/chart_comparison.html");

        html<<"<!DOCTYPE html><html><head><script src='https://cdn.jsdelivr.net/npm/chart.js'></script></head><body>";
        html<<"<h2>Store Profit Comparison</h2>";
        html<<"<canvas id='c'></canvas><script>";
        html<<"new Chart(document.getElementById('c'),{type:'bar',data:{labels:[";

        for(int i=0;i<count;i++)
        {
            html<<"'"<<PTR[indices[i]]->getname()<<"',";
        }

        html<<"],datasets:[{label:'Profit',backgroundColor:'rgba(255,200,0,0.7)',data:[";

        for(int i=0;i<count;i++)
        {
            p=0.0;
            s=0.0; c=0.0;
              for(int x=0;x<PTR[indices[i]]->getanalytics().get_Toata_M();x++)
              {
                s+=PTR[indices[i]]->getanalytics().getmonthlySales(x);
                c+=PTR[indices[i]]->getanalytics().getop_costs(x);
              }
            p=s-c;
            html<<p<<",";
        }

        html<<"]}]}});</script></body></html>";
        html.close();

        cout<<"\n Chart saved to output/chart_comparison.html\n";
    }
  
    void V_REP::chart_clusters(subCLUSTER& obj){

        double profit1=0.0,profit02=0.0;
        for(int i=0;i<obj.getcluster01_size();i++)
        {
            double s=0.0,op=0.0;
            for(int k=0;k<obj.CLUSTr01()[i]->getanalytics().get_Toata_M();k++)
            {
                s+=obj.CLUSTr01()[i]->getanalytics().getmonthlySales(k);
                op+=obj.CLUSTr01()[i]->getanalytics().getop_costs(k);
            }
            profit1+=s-op;
        }
        for(int i=0;i<obj.getcluster02_size();i++)
        {
            double s=0.0,op=0.0;
            for(int k=0;k<obj.CLUSTr02()[i]->getanalytics().get_Toata_M();k++)
            {
                s+=obj.CLUSTr02()[i]->getanalytics().getmonthlySales(k);
                op+=obj.CLUSTr02()[i]->getanalytics().getop_costs(k);
            }
            profit02+=s-op;
        }

        ofstream html("output/chart_clusters.html");

        html<<"<!DOCTYPE html><html><head><script src='https://cdn.jsdelivr.net/npm/chart.js'></script></head><body>";
        html<<"<h2>Cluster-wise Profits</h2>";
        html<<"<canvas id='c'></canvas><script>";
        html<<"new Chart(document.getElementById('c'),{type:'bar',data:{labels:['Cluster 01','Cluster 02'],";
        html<<"datasets:[{label:'Profit',backgroundColor:['rgba(255,165,0,0.7)','rgba(255,200,0,0.7)'],data:[";
        html<<profit1<<","<<profit02;
        html<<"]}]}});</script></body></html>";
        html.close();

        cout<<"\n Chart saved to output/chart_clusters.html\n";
    }

    V_REP::~V_REP(){
        PTR=NULL;
    }