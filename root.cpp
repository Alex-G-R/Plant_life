#include "root.h"

int Root::root_soil_minerals_production = 15;
int Root::root_creation_cost = 100;
int Root::root_upkeep = 5;

int Root::getRootMineralsProd(){
    return root_soil_minerals_production;
}
int Root::getRootCost(){
    return root_creation_cost;
}
int Root::getRootSunConsumption(){
    return root_upkeep;
}
