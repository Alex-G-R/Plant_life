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

int Tree::getNumberOfBranches(){ return number_of_branches; }

int Tree::getMaxNumberOfLeaves(){ return max_number_of_leaves; }

int Tree::getNumberOfLeaves(){ return number_of_leaves; }

int Tree::getNumberOfRoots(){ return number_of_roots; }


void Tree::addRoot(){
    if(tree_soil_minerals < Root::getRootCost()){
        std::cout << "You don't have enough soil minerals (root cost = " << Root::getRootCost() << "sm) \n";
    } else {
        tree_soil_minerals = tree_soil_minerals - Root::getRootCost();
        roots.emplace_back();
    }
}
void Tree::addBranch(){
    if(tree_soil_minerals < Branch::getBranchCost()){
        std::cout << "You don't have enough soil minerals (branch cost = " << Branch::getBranchCost() << "sm) \n";
    } else {
        tree_soil_minerals = tree_soil_minerals - Branch::getBranchCost();
        branches.emplace_back();
    }
}
void Tree::addLeaf(){
    if(tree_soil_minerals < Leaf::getLeafCost()){
        std::cout << "You don't have enough soil minerals (leaf cost = " << Leaf::getLeafCost() << "sm) \n";
    } else {
        tree_soil_minerals = tree_soil_minerals - Leaf::getLeafCost();
        leaves.emplace_back();
    }
}
void Tree::addLeaves(int n){
    if(tree_soil_minerals < Leaf::getLeafCost() * n){
        std::cout << "You don't have enough soil minerals to grow "<< n << " leaves, this will cost: " << Leaf::getLeafCost() * n << "sm) \n";
    } else {
        for(int i = 0; i < n; i++){
            leaves.emplace_back();
        }
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
    tree_soil_minerals = tree_soil_minerals + tree_soil_minerals_prod;

    // check if tree died by accident xD
    if(tree_sun_energy < 0){
        dead = true;
    } else if (tree_soil_minerals < 0){
        dead = true;
    } else {
        dead = false;
    }
}

void Tree::showTreeInfo(){
    std::cout << "|------------- Tree stats ---------- \n";
    std::cout << "|--- Tree age: " << getTreeAge() << "\n";
    std::cout << "|--- Tree sun energy production: " << getTreeSunEnergyProduction() << "\n";
    std::cout << "|--- Tree soil minerals(sm) production: " << getTreeSoildMineralsProduction() << "\n";
    std::cout << "|--- Tree sun energy consumption: " << getTreeSunEnergyConsumption() << "\n";
    std::cout << "|--- Number of branches: " << getNumberOfBranches() << "\n";
    std::cout << "|--- Max number of leaves: " << getMaxNumberOfLeaves() << "\n";
    std::cout << "|--- Number of leaves: " << getNumberOfLeaves() << "\n";
    std::cout << "|--- Number of roots: " << getNumberOfRoots() << "\n";
    std::cout << "|--- Current sun energy(se): " << getNumberOfRoots() << "\n";
    std::cout << "|--- Current soil minerals(sm): " << getNumberOfRoots() << "\n";
    std::cout << "|--- Is tree dead: " << isTreeDead() << "\n";
    std::cout << "|----------------------- \n";
}

/*
void Tree::treeInterface()
*/



