#ifndef BRANCH_H
#define BRANCH_H

#include <vector>
#include <iostream>

class Branch {
    private:
        int branch_creation_cost;
        int branch_upkeep_cost;
        int branch_leaf_capacity;

    public:
        Branch();
        
        static int getBranchLeafCapacity();
        static int getBranchSunConsumption();
};

#endif