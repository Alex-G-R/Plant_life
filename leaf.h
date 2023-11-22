#ifndef LEAF_H
#define LEAF_H

#include <vector>
#include <iostream>

class Leaf {
    private:
        int leaf_creation_cost;
        int leaf_sun_energy_prod;
    public:
        Leaf();
        static int getLeafEnergyProd();
        static int getLeafCost();
};

#endif