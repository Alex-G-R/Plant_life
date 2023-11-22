#ifndef ROOT_H
#define ROOT_H

#include <vector>
#include <iostream>

class Root {
    private:
        int root_creation_cost;
        int root_soil_minerals_production;
        int root_upkeep;
    public:
        Root();
        static int getRootMineralsProd();
        static int getRootSunConsumption();
};

#endif