#ifndef BRANCH_H
#define BRANCH_H

#include <vector>
#include <iostream>
#include "leaf.h"

class Branch {
    private:
        std::vector<Leaf> leaves;
        int branch_creation_cost;
        int branch_upkeep_cost;
        int branch_leaf_capacity;

    public:
        Branch();

        void addLeaf();
        void addLeaves();
};

#endif