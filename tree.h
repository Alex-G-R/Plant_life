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
        double tree_sun_energy_prod;
        double tree_soil_minerals_prod;
        double tree_sun_energy;
        double tree_soil_minerals;
        double tree_sun_energy_consumption;
        bool dead;

        // Branch variables
        int number_of_branches;

        // Leaf variables
        int max_number_of_leaves;
        int number_of_leaves;

        // Root variables
        int number_of_roots;

    public:
        Tree();

        int getTreeAge();
        double getTreeSunEnergyProduction();
        double getTreeSoildMineralsProduction();
        double getTreeSunEnergy();
        double getTreeSoildMinerals();
        double getTreeSunEnergyConsumption();
        bool isTreeDead();

        int getNumberOfBranches();

        int getMaxNumberOfLeaves();
        int getNumberOfLeaves();

        int getNumberOfRoots();



        void addRoot();

        void addBranch();

        void addLeafToBranch();
        void addLeavesToBranch();

        void updateTree();

        void treeInterface();
        void showTreeInfo();
};

#endif