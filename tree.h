#ifndef TREE_H
#define TREE_H

#include <vector>
#include <iostream>
#include "branch.h"
#include "root.h"

class Tree {
    private:

        std::vector<Root> roots;
        std::vector<Branch> branches;

        // Tree variables
        int tree_age;
        int tree_height;

        // Branch variables
        int number_of_branches;

        // Leaf variables
        int number_of_leaves;

        // Root variables
        


    public:

};

#endif