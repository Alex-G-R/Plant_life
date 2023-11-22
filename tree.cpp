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
        std::cout << "Success, you grew a root, your SM balance is now equal to: " << getTreeSoilMinerals() << "sm \n";
    }
}
void Tree::addBranch(){
    if(tree_soil_minerals < Branch::getBranchCost()){
        std::cout << "You don't have enough soil minerals (branch cost = " << Branch::getBranchCost() << "sm) \n";
    } else {
        tree_soil_minerals = tree_soil_minerals - Branch::getBranchCost();
        branches.emplace_back();
        std::cout << "Success, you grew a branch, your SM balance is now equal to: " << getTreeSoilMinerals() << "sm \n";
    }
}
void Tree::addLeaf(){
    if(tree_soil_minerals < Leaf::getLeafCost()){
        std::cout << "You don't have enough soil minerals (leaf cost = " << Leaf::getLeafCost() << "sm) \n";
    } else {
        tree_soil_minerals = tree_soil_minerals - Leaf::getLeafCost();
        leaves.emplace_back();
        std::cout << "Success, you grew a leaf, your SM balance is now equal to: " << getTreeSoilMinerals() << "sm \n";
    }
}
void Tree::addLeaves(int n){
    if(tree_soil_minerals < Leaf::getLeafCost() * n){
        std::cout << "You don't have enough soil minerals to grow "<< n << " leaves, this will cost: " << Leaf::getLeafCost() * n << "sm) \n";
    } else {
        for(int i = 0; i < n; i++){
            leaves.emplace_back();
        }
        tree_soil_minerals = tree_soil_minerals - n * Leaf::getLeafCost();
        std::cout << "Success, you grew "<< n <<" leaves, your SM balance is now equal to: " << getTreeSoilMinerals() << "sm \n";
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
    std::cout << "|------------- Tree stats -------------------------- \n";
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
    std::cout << "|---------------------------------------------------- \n";
}

int Tree::treeMenu(){
    std::cout << "|------------- Tree action menu ---------------------\n";
    std::cout << "|-1- Next turn.\n";
    std::cout << "|-2- Grow a branch (cost: "<< Branch::getBranchCost() <<"sm).\n";
    std::cout << "|-3- Grow a root (cost: "<< Root::getRootCost() <<"sm).\n";
    std::cout << "|-4- Grow a leaf (cost: "<< Leaf::getLeafCost() <<"sm).\n";
    std::cout << "|-5- Grow multiple leaves (cost: "<< Leaf::getLeafCost() <<"sm p/leaf).\n";
    std::cout << "|-6- Informations for dummies.\n";
    std::cout << "|----------------------------------------------------\n";
    std::cout << "Choose one option: ";
    int option;
    std::cin >> option;
    return option;
}

void Tree::dummyInfo(){
    std::cout << "|------------- Plant_life for dummies -------------------------- \n";
    std::cout << "|-I- You simulate a growing tree, try to not make it die. \n";
    std::cout << "|-I- If you SM (soil minerals) or SM (sun energy) go below 0, you die. \n";
    std::cout << "|-I- In the simulation you have 3 elements, branch, leaf, root \n";
    std::cout << "|-I- To grow parts you spend SM, to keep them alive you spend SE as an unkeep per turn \n";
    std::cout << "|-R- Roots produce SM(soil minerals) at a rate of: "<< Root::getRootMineralsProd() << "sm per turn \n";
    std::cout << "|-R- Roots also cost you SE(sun energy) as unkeep, to be exact " << Root::getRootSunConsumption()<<"se per turn \n";
    std::cout << "|-R- To create a root you need to spend "<< Root::getRootCost()<< "sm \n";
    std::cout << "|-B- Branches have a unkeep of: "<< Branch::getBranchSunConsumption()<<"se per turn \n";
    std::cout << "|-B- Branches let you have more leaves, to be exact "<< Branch::getBranchLeafCapacity() << " leaves per branch \n";
    std::cout << "|-B- Branch costs you exacly "<< Branch::getBranchCost()<<"sm to grow \n";
    std::cout << "|-L- Leaves produce SE (sun energy) and they don't have an unkeep \n";
    std::cout << "|-L- Each leaf costs you "<< Leaf::getLeafCost<<"sm to grow, and will produce "<< Leaf::getLeafEnergyProd()<<"se per turn\n";
    std::cout << "|---------------------------------------------------- \n";
}


void Tree::treeInterface(){
    updateTree();
    showTreeInfo();
    std::cout << "\n\n";
    int option = treeMenu();

    switch (option)
    {
    case 1:
        treeInterface();
        break;
    case 2:
        addBranch();
        break;
    case 3:
        addRoot();
        break;
    case 4:
        addLeaf();
        break;
    case 5:
        int n;
        std::cout << "How many leaves do you want to grow: ";
        std::cin >> n;
        addLeaves(n);
        break;
    case 6:
        dummyInfo();
        break;
    default:
        std::cout << "Error, try again \n";
        treeMenu();
        break;
    }
}






