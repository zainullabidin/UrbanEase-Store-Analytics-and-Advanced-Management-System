#include<ctime>
#include<fstream>

#include"store.h"
#include"report.h"
#include"helper.h"
#include"cluster.h"

using namespace std;

    void datagen(Store *& object, int t_stores)
    {
        //some arrays for randomized datagen

    string arr_st_name[] = {"Beretta Pakistan", "Scopes & Barrels",  "Barki Armoury",   "Tactical Arms", "Bandook Wala", "Badaruddin & Sons", "Alpiyal Enterprises",  "Buksh Elahi & Co",  "Fazal Sons", "Jan & Sons"};

    int arr_st_age[] = { 10, 25, 15, 21, 30, 50, 12, 60, 40, 35 };

    string arr_st_person_names[] = { "Ahmed Ali Mansoor", "Zubair Shahidi", "Omar Barki", "Mustafa Khan", "Abbas Bandukwala", "Faisal Badaruddin", "Wasif Ali Alpiyal", "Saeed Ahmed Buksh", "Kamran Fazal", "Jamshed Afridi" };

    double arr_st_standing_out[] = { 9.8, 9.5, 9.2, 8.9, 8.5, 9.0, 8.2, 9.4, 8.7, 9.1 };

    double arr_st_coords[][2] = { {33.6844, 73.0479}, {24.8609, 67.0261}, {34.0151, 71.5249}, {31.5204, 74.3587}, {24.8607, 67.0011}, {33.5973, 73.0479}, {33.6366, 72.9691}, {31.5622, 74.3213}, {33.5950, 73.0543}, {33.6874, 71.4933} };

    double base_monthly_sales[] = { 120.5, 132.0, 145.2, 128.8, 150.0, 175.5, 190.2, 185.0, 160.5, 155.0, 210.8, 250.0, 230.5, 245.0, 260.2, 215.8, 230.0, 285.5, 310.2, 305.0, 280.5, 275.0, 350.8, 400.0 };

    int base_customer_counts[] = { 45, 50, 55, 48, 60, 75, 82, 80, 65, 62, 95, 120, 110, 115, 125, 105, 112, 140, 155, 150, 135, 130, 180, 210 };

    string arr_emp_roles[] = { "Sales Associate", "Security Guard", "Inventory Clerk", "Technician", "Accountant" };

    double base_op_costs[] = { 80.0, 82.5, 85.0, 81.0, 88.5, 95.0, 98.2, 97.0, 92.5, 90.0, 110.8, 125.0, 115.5, 118.0, 122.2, 112.8, 118.0, 135.5, 145.2, 142.0, 138.5, 135.0, 165.8, 180.0 };

    string arr_manager_titles[] = { "Chief Executive Officer", "Senior Branch Manager", "Operations Director", "Regional Sales Manager", "Managing Director", "Chief Superintendent", "General Manager", "Principal Partner", "Executive Manager", "District Supervisor" };


                for(int i=0;i<t_stores;i++)
                {
                    //store namw
                    object[i].setname(arr_st_name[rand()%10]);
                    //store id
                    object[i].setunique_ID(i+1);
                    //coords for each store
                    object[i].getcoords().setlatitude(arr_st_coords[rand()%9][0]);
                    object[i].getcoords().setlongitude(arr_st_coords[rand()%9][1]);

                    //manager of eacg store
                    object[i].getman().setage(arr_st_age[rand()%10]);
                    object[i].getman().setEmployee_ID(t_stores+1);
                    object[i].getman().setname(arr_st_person_names[rand()%10]);
                    object[i].getman().setPersonalID(t_stores-1);
                    object[i].getman().setrole_Employee(arr_emp_roles[rand()%5]);
                    object[i].getman().setstandingout_Points(arr_st_standing_out[rand()%10]);
                    object[i].getman().setTitle(arr_manager_titles[rand()%10]);
                
                    object[i].getanalytics().set_Tot(24);
                    //store analytics
                    for(int j=0;j<object[i].getanalytics().get_Toata_M();j++)
                    {
                        object[i].getanalytics().setmonthlySales(j,base_monthly_sales[j]*0.5 + (rand()%150)/100.0);
                        object[i].getanalytics().setCustomer_counts(j,base_customer_counts[j]*0.5 + (rand()%150)/100.0);
                        object[i].getanalytics().setop_costs(j,base_op_costs[j]*0.5 + (rand()%150)/100.0);
                    }

                    //emplyee 
                    object[i].sett_staff(rand()%50+20);
                    object[i].allocate_staff();

                    for(int j=0;j<object[i].gett_staff();j++)
                    {
                        object[i].get_emp()[j].setage(arr_st_age[rand()%10]);
                        object[i].get_emp()[j].setEmployee_ID(t_stores+1);
                        object[i].get_emp()[j].setname(arr_st_person_names[rand()%10]);
                        object[i].get_emp()[j].setPersonalID(t_stores-1);
                        object[i].get_emp()[j].setrole_Employee(arr_emp_roles[rand()%5]);

                    }
                    
                }
            
                //writing to file
                    ofstream datafile("files/data.txt");
                    
                        datafile<<t_stores<<endl;

                        for(int x=0;x<t_stores;x++)
                        {
                            object[x].data_save(datafile);
                        }
                        cout<<"DATA SUCCESSFULLY STORED TO. \" data.txt\"";


        }

    void start_menu(int &choice, int &flag)
    {
        cout<<"1. Load from file\n\n2. Generate new data\n";
        do{
        if(flag)
        {
            cout<<"ENTER AGAIN.....       :";
            cin>>choice;
            flag=0;
        }

        else
        {
            cout<<"Please ENTER your choice : ";
            cin>>choice;
            flag=0;
        }

        if(choice>2||choice<1)
        flag=2;

         }while(flag);//va;idatomng choice

    }

    void loadfile(ifstream &file, Store *& object, int & size)
    {
             file>>size;
             
             if(size<0)

             {
                cout<<"\nCORUUPTED FILE\n";
                return;
             }
             object=new Store[size];
             for(int i=0;i<size;i++)
             object[i].load_maindata(file);
             cout<<" DATA SUCCESSFULLY LOADED FROM \"data.txt\"";
    }


  void int_validatoe(int & n)
  {
    
    int flag=0;
    do {
        cin >> n;
        if(cin.fail() || n < 0)
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\nYOU ENTERED WRONG... Enter Again: ";
        }
        else 
        break;
    } while(true);
}



void starter(){

      srand(time(0));
    //HELLALUJAH
    int choice = 0, flag = 0;
    int t_stores = 0;
    Store *object = NULL;

    start_menu(choice, flag);

    ifstream file("files/data.txt");
    if(!file.is_open())
        flag = 1;

    //data load
    if(choice == 1 && !flag)
    {
        loadfile(file, object, t_stores);
        if(object==NULL)
        {

            flag=1;
        }
        
    }
    else if(flag || choice == 2)
    {
        if(flag)
            cout << "ERROR LOADING FILE - GENERATING DATA\n";

        cout << "Please ENTER the number of stores (min 100): ";
        cin >> t_stores;

        while(t_stores < 100)
        {
            cout << "ERROR - Minimum 100 stores required. Enter again: ";
            cin >> t_stores;
        }

        object = new Store[t_stores];
        datagen(object, t_stores);
    }



    // CLSTER
    subCLUSTER obj;
    obj.get_mainarray_size(t_stores);
    obj.get_marray(object);
    obj.intitailezer();
    obj.CLUSTERER();
    obj.subCLUSTERER_CLUSTER01();
    obj.subCLUSTERER_CLUSTER02();
    cout << obj;

    cout<<"\nPRESS Enter any key to continue .\n";
    cin.ignore();
    getchar();
    system("clear");

    //MAIN ARRRRRR
    Store **storePtr = new Store*[t_stores];
    for(int i = 0; i < t_stores; i++)
        storePtr[i] = &object[i];

    //RANKER
    Report r;
    r.report_caller(storePtr, t_stores);
    cout << r;

    cout<<"\n\n\nPRESS Enter any key to continue .\n";

    getchar();
    system("clear");


    //FORECASTER
    Forecast f;
    f.predict_call(storePtr, t_stores);
    cout << f;


    cout<<"\n\n\nPRESS Enter any key to continue .\n";

    getchar();
    system("clear");
    //implementing the visuals

//    // V_REP objec;
//    // objec.Visual_Charts(storePtr);
//     int storeIndex=0;




//     //chart01
//     cout << "Enter store index for monthly chart: ";
//     int_validatoe(storeIndex);
//     objec.chart_store(storeIndex);

//     cout<<"\nPRESS Enter any key to continue .\n";
// cin.ignore();
//     getchar();
//     system("clear");


// //chart02
//     int count = 0;
//     cout << "ENTER the number of stores to compare: ";

//     int_validatoe(count);

//     int* indices = new int[count];

//     for(int i = 0; i < count; i++)
//     {
//         cout << "Enter store index " << i+1 << ": ";
        
//         int_validatoe(indices[i]);
//         while(indices[i]>=t_stores)
//         {
//             cout<<"PLEASE Enter the stores within the range : "<<t_stores;
//             int_validatoe(indices[i]);
//         }
        
//     }
//     objec.chart_comparison(indices, count);
//     delete[] indices;

//     cout<<"\n\n\nPRESS Enter any key to continue .\n";

//     cin.ignore();
//     getchar();
//     system("clear");
// //3rd chart
//     objec.chart_clusters(obj);



    cout<<"\n\n\nPRESS Enter any key to continue .\n";

    cin.ignore();
    getchar();
    system("clear");
    // ++/--



    // freeee YIPPIE
    delete[] storePtr;
    storePtr = NULL;
    delete[] object;
    object = NULL;


}