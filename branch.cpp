#include "branch.h"

Branch::Branch() : length(0), max_leafs(0), existing_leafs(0), age(0), n_consumption(0), dead(false) {}

int Branch::getAge() {
    return age;
}

double Branch::getLength() {
    return length;
}

int Branch::getMaxLeafs() {
    return max_leafs;
}

int Branch::getExistingLeafs() {
    return existing_leafs;
}

double Branch::getConsumption() {
    return n_consumption;
}

bool Branch::getPlantStatus() {
    return dead;
}

double Branch::getNutritionProduction() {
    return existing_leafs * 3;
}

double Branch::getNutritionBalance() {
    return getNutritionProduction() - getConsumption();
}


void Branch::createLeaf() {
    if (max_leafs > existing_leafs) {
        existing_leafs++;
    }
}

void Branch::updateNutritions(double &nutritions) {
    if (existing_leafs > 0) {
        nutritions = nutritions + getNutritionBalance();
    }
}

void Branch::updateAge() {
    age++;
}

void Branch::updateLength(double nutritions) {
    if (nutritions > 0) {
        if(length < 60){
            length = length + 0.66;
        }
        else if(length > 200){
            length = length + (length * 0.01);
        }
        else{
            length = length + (length + 0.1);
        }
    } else if (nutritions < 0) {
        length = length - (length * 0.1);
    }
}

void Branch::updateMaxLeafs() {
    max_leafs = static_cast<int>(std::round(length/3));
}

void Branch::updateLeafs() {
    if(max_leafs < existing_leafs){
        existing_leafs = max_leafs;
    }
}

void Branch::updateConsumption() {
    n_consumption = (length * 0.2) + (existing_leafs * 0.4);
}

void Branch::checkIfDead(double &nutritions) {
    if(length < 0.01){
        handleDeath(nutritions);
    }
}

void Branch::handleDeath(double &nutritions) {
    nutritions = 0;
    length = 0;
    max_leafs = 0;
    existing_leafs = 0;
    n_consumption = 0;
    dead = true;
}

void Branch::updateBranch(double &nutritions) {
    nutritions = nutritions - getConsumption();
    updateConsumption();
    updateAge();
    updateLength(nutritions);
    updateMaxLeafs();
    createLeaf();
    updateLeafs();
    updateNutritions(nutritions);
    checkIfDead(nutritions);

    showBranchStatus(nutritions);
}

void Branch::showBranchStatus(double nutritions) {
    std::cout << "age: " << getAge() << "\n";
    std::cout << "length: " << getLength() << "\n";
    std::cout << "max-leafs: " << getMaxLeafs() << "\n";
    std::cout << "existing leafs : " << getExistingLeafs() << "\n";
    std::cout << "nutrition consumption: " << getConsumption() << "\n";
    std::cout << "nutrition production: " << getNutritionProduction() << "\n";
    std::cout << "nutrition balace: " << getNutritionBalance() << "\n";
    std::cout << "current nutritions: " << nutritions << "\n";
    std::cout << "dead: " << getPlantStatus() << "\n";
}
