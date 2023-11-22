#ifndef ROOT_H
#define ROOT_H


class Root {
    private:
        static int root_creation_cost;
        static int root_soil_minerals_production;
        static int root_upkeep;
    public:
        static int getRootMineralsProd();
        static int getRootSunConsumption();
        static int getRootCost();
};

#endif