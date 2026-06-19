#include"store.h"
#include"cluster.h"

class V_REP{

private:
    Store** PTR;
    int size;
public:

    V_REP();

    void Visual_Charts(Store ** &ptr);

    void chart_store(int storeIndex);

    void chart_comparison(int* indices, int count);

    void chart_clusters(subCLUSTER& obj);

    ~V_REP();

};