#ifndef TREE_H
#define TREE_H

#include <vector>
#include <iostream>
#include "branch.h"
#include "root.h"

class Tree {
    private:

        std::vector<Root> roots;
        std::vector<Branch> branches;

        // Tree variables
        int tree_age;
        int tree_height;
        double tree_sun_energy;
        double tree_soil_minerals;
        double tree_sun_energy_consumption;
        bool dead;

        // Branch variables
        int max_number_of_branches;
        int number_of_branches;
        double combined_branches_length;

        // Leaf variables
        int max_number_of_leaves;
        int number_of_leaves;

        // Root variables
        int number_of_roots;
        double combined_roots_length;

    public:
        Tree();

        int getTreeAge();
        int getTreeHeight();
        double 
};

#endif