#include "tree.h"

Tree::Tree(double startring_sun_energy, double starting_soil_minerals) : roots(), branches(), leaves(),
tree_age(0), tree_sun_energy_prod(0), tree_soil_minerals_prod(0), tree_sun_energy(startring_sun_energy),
tree_soil_minerals(starting_soil_minerals), tree_sun_energy_consumption(0), dead(false), number_of_branches(0),
max_number_of_leaves(0), number_of_leaves(0), number_of_roots(0){}

int Tree::getTreeAge(){ return tree_age; }

double Tree::getTreeSunEnergyProduction(){ return tree_sun_energy_prod; }

double Tree::getTreeSoildMineralsProduction(){ return tree_soil_minerals_prod; }

double Tree::getTreeSunEnergy(){ return tree_sun_energy; }

double Tree::getTreeSoilMinerals(){ return tree_soil_minerals; }

double Tree::getTreeSunEnergyConsumption(){ return tree_sun_energy_consumption; }

bool Tree::isTreeDead(){ return dead; }


int Tree::getNumberOfBranches(){
    return number_of_branches;
}
int Tree::getMaxNumberOfLeaves(){
    return max_number_of_leaves;
}
int Tree::getNumberOfLeaves(){
    return number_of_leaves;
}
int Tree::getNumberOfRoots(){
    return number_of_roots;
}


void Tree::addRoot(){
    roots.emplace_back();
}
void Tree::addBranch(){
    branches.emplace_back();
}
void Tree::addLeaf(){
    leaves.emplace_back();
}
void Tree::addLeaves(int number_of_leaves){
    for(int i = 0; i < number_of_leaves; i++){
        leaves.emplace_back();
    }
}


void Tree::updateTree(){
    tree_age++;
    tree_sun_energy_prod = leaves.size() * Leaf::getLeafEnergyProd();
    tree_soil_minerals_prod = roots.size() * Root::getRootMineralsProd();
    tree_sun_energy_consumption = ((roots.size() * Root::getRootSunConsumption()) + (branches.size() * Branch::getBranchSunConsumption()));
    number_of_branches = branches.size();
    max_number_of_leaves = branches.size() * Branch::getBranchLeafCapacity();
    number_of_leaves = leaves.size();
    number_of_roots = roots.size();

    tree_sun_energy = ((tree_sun_energy + tree_sun_energy_prod) - tree_sun_energy_consumption);
    tree_soil_minerals = tree_soil_minerals;
    if(tree_sun_energy < 0){
        dead = true;
    } else if (tree_soil_minerals < 0){
        dead = true;
    } else {
        dead = false;
    }
}

/*
void Tree::treeInterface()
void Tree::showTreeInfo()
*/

