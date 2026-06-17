#include"analytics.h"

    analytics::analytics(){

        current_month=0;

        total_months=0;

        monthlySales=NULL;;

        Customer_counts=NULL;;
       
        op_costs=NULL;;
        
        
    }
  
    void analytics::set_Tot(int n)
    {

        total_months = n;
        if(monthlySales!=NULL)
        delete[] monthlySales;

        if(Customer_counts!=NULL)
        delete[] Customer_counts;

        if(op_costs!=NULL)
        delete[] op_costs;

        monthlySales = new double[total_months];
        Customer_counts = new int[total_months];
        op_costs = new double[total_months];

        for(int i=0;i<total_months;i++)
        {
            monthlySales[i]=0.0;
            Customer_counts[i]=0;
            op_costs[i]=0.0;
        }
        
}
    
    analytics::~analytics(){

        delete[] monthlySales;
        delete [] Customer_counts;
        delete [] op_costs;

        monthlySales=NULL;
        Customer_counts=NULL;
        op_costs=NULL;

    }

    analytics::analytics(const analytics &object){

        monthlySales = NULL;
        Customer_counts = NULL;
        op_costs = NULL;
        
        set_Tot(object.get_Toata_M());

        for(int i=0; i<total_months; i++){

        monthlySales[i] = object.monthlySales[i];

        Customer_counts[i] = object.Customer_counts[i];

        op_costs[i] = object.op_costs[i];
        }


    }

    int analytics::get_Toata_M()const
    {
        return  total_months; 
    }

    void analytics::setToata_M(int n)
    {
        total_months=n;
    }

    void analytics::add_months_stats(double m_sals,double op_cst, int C_C)
    {
        analytics temp=*this;
        delete [] monthlySales;
        monthlySales=new double[temp.get_Toata_M()+1];
        delete [] Customer_counts;
        Customer_counts=new int[temp.get_Toata_M()+1];
        delete [] op_costs;
        op_costs=new double[temp.get_Toata_M()+1];

        for(int i=0;i<temp.get_Toata_M();i++)
        {
            monthlySales[i]=temp.getmonthlySales(i);
            Customer_counts[i]=temp.getCustomer_counts(i);
            op_costs[i]=temp.getop_costs(i);
        }
        
        monthlySales[temp.get_Toata_M()]=m_sals;
        Customer_counts[temp.get_Toata_M()]=C_C;
        op_costs[temp.get_Toata_M()]=op_cst;

         total_months=temp.get_Toata_M()+1;
        /// call file genrator for latest updates

    }

    double analytics::getmonthlySales(int i)const
    {
        return monthlySales[i];
    }

    void analytics::setmonthlySales(int i,double n)
    {
        monthlySales[i]=n;
    }

    double analytics::getop_costs(int i)const
    {
        return op_costs[i];
    }

    void analytics::setop_costs(int i,double n)
    {
        op_costs[i]=n;
    }

    double analytics::getCustomer_counts(int i)const
    {
        return Customer_counts[i];
    }

    void analytics::setCustomer_counts(int i,int n)
    {
        Customer_counts[i]=n;
    }

    double analytics::operator[](int i){

        return getmonthlySales(i);
    }

    void analytics::loaddata_analytics(ifstream &datafile)
    {
        datafile >> total_months;


        set_Tot(total_months);

        for(int i=0;i<total_months;i++)
        {
            datafile>> monthlySales[i];
        }
        for(int i=0;i<total_months;i++)
        {
            datafile>> Customer_counts[i];
        }
        for(int i=0;i<total_months;i++)
        {
            datafile>> op_costs[i];
        }
    }

    ostream& operator << (ostream& out, const analytics& object)
    {
        for(int i=0;i<object.get_Toata_M();i++)
        {
            out<<object.monthlySales[i]<<" ";
        }
        out<<endl;
        return out;
    }

    analytics& analytics::operator=(const analytics& object){

    if(this == &object) 
    return *this;
    set_Tot(object.get_Toata_M());

    for(int i = 0; i < total_months; i++)
    {
        monthlySales[i] = object.monthlySales[i];
        Customer_counts[i] = object.Customer_counts[i];
        op_costs[i] = object.op_costs[i];
    }
    return *this;
    }

    analytics analytics::operator +(const analytics &object)
    {
        analytics temp=*this;

        for(int i=0;i<object.get_Toata_M();i++)
        {
            temp.monthlySales[i]+=object.monthlySales[i];

            temp.Customer_counts[i]+=object.Customer_counts[i];

            temp.op_costs[i]+=object.op_costs[i];
        }
        return temp;
        
    }

    analytics analytics::operator -(const analytics &object)
    {
        analytics temp=*this;

        for(int i=0;i<total_months;i++)
        {
            temp.monthlySales[i]-=object.monthlySales[i];

            temp.Customer_counts[i]-=object.Customer_counts[i];
            
            temp.op_costs[i]-=object.op_costs[i];
        }
        
        return temp;
    }

    analytics analytics::operator *(const analytics &object)
    {

        analytics temp=*this;

        for(int i=0;i<total_months;i++)
        {
            temp.monthlySales[i]*=object.monthlySales[i];

            temp.Customer_counts[i]*=object.Customer_counts[i];
            
            temp.op_costs[i]*=object.op_costs[i];
        }
        
        return temp;
    }

    bool analytics::operator >(const analytics & object){

        double sum01=0.0,sum02=0.0;
        for(int i=0;i<total_months;i++)
        {
            sum01+=this->monthlySales[i];
            sum02+=object.monthlySales[i];
            
        }
        if(sum01<sum02)
            {
                return false;
            }
        return true;
    }

    bool analytics::operator <(const analytics & object){

        double sum01=0.0,sum02=0.0;
        for(int i=0;i<total_months;i++)
        {
            sum01+=this->monthlySales[i];
            sum02+=object.monthlySales[i];
            
        }
        if(sum01>sum02)
            {
                return false;
            }
        return true;
       
    }

    analytics & analytics::operator ++ (){

        if(current_month<total_months - 1)
        ++current_month;
        return *this;
    }

    analytics  analytics::operator ++ (int){
        
        analytics temp=*this;
        if(temp.current_month<total_months - 1)
        ++current_month;
        return temp;
    }

    analytics & analytics::operator --(){

        if(current_month>0)
        --current_month;
        return *this;
    }

    analytics  analytics::operator -- (int){
        
        analytics temp=*this;
        if(temp.current_month>0)
        --current_month;
        return temp;
    }
