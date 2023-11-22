#ifndef LEAF_H
#define LEAF_H

class Leaf {
    private:
        static int leaf_creation_cost;
        static int leaf_sun_energy_prod;
    public:
        static int getLeafEnergyProd();
        static int getLeafCost();
};

#endif