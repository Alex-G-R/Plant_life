#include "leaf.h"

int Leaf::leaf_creation_cost = 8;
int Leaf::leaf_sun_energy_prod = 3;

int Leaf::getLeafCost(){
    return leaf_creation_cost;
}
int Leaf::getLeafEnergyProd(){
    return leaf_sun_energy_prod;
}
