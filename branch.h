#ifndef BRANCH_H
#define BRANCH_H

class Branch {
    private:
        static int branch_creation_cost;
        static int branch_upkeep_cost;
        static int branch_leaf_capacity;

    public:
        static int getBranchLeafCapacity();
        static int getBranchSunConsumption();
        static int getBranchCost();
};

#endif