#include <iostream>

#include "cluster.h"


int main()
{   
    srand(time(NULL));

    Cluster cluster(100, 500, 100, 1, 1);
    cluster.EnableLogging(true);

    Statistics stats = cluster.RunSimulation();

    std::cout << stats;
    
    return 0;
}


