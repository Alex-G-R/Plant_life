#ifndef BRANCH_H
#define BRANCH_H

#include <cmath>
#include <iostream>

class Branch {
    private:
        int age;
        double length;
        int max_leafs;
        int existing_leafs;
        double n_consumption;
        bool dead;
        double n_storage_capacity;

    public:
        Branch();

        int getAge();
        double getLength();
        int getMaxLeafs();
        int getExistingLeafs();
        double getConsumption();
        double getNutritionProduction();
        double getNutritionBalance();
        bool getPlantStatus();

        void handleDeath(double &nutritions);
        void checkIfDead(double &nutritions);
        void createLeaf();
        void updateNutritions(double &nutritions);
        void updateAge();
        void updateLength(double nutritions);
        void updateMaxLeafs();
        void updateLeafs();
        void updateConsumption();
        void updateBranch(double &nutritions);
        void showBranchStatus(double nutritions);
};

#endif
