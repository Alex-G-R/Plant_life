#include "branch.h"

int Branch::branch_creation_cost = 100;
int Branch::branch_upkeep_cost = 2;
int Branch::branch_leaf_capacity = 30;

int Branch::getBranchCost(){
    return branch_creation_cost;
}
int Branch::getBranchLeafCapacity(){
    return branch_leaf_capacity;
}
int Branch::getBranchSunConsumption(){
    return branch_upkeep_cost;
}
