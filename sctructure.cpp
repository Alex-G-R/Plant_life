#include <iostream>
#include <vector>

class Leaf {
public:
    void grow() {
        std::cout << "Leaf is growing.\n";
    }
};

class Branch {
private:
    std::vector<Leaf> leaves;

public:
    void grow() {
        std::cout << "Branch is growing.\n";
        for (auto& leaf : leaves) {
            leaf.grow();
        }
    }

    void addLeaf() {
        leaves.emplace_back();
    }
};

class Tree {
private:
    std::vector<Branch> branches;

public:
    void grow() {
        std::cout << "Tree is growing.\n";
        for (auto& branch : branches) {
            branch.grow(); 
        }
    }

    void addBranch() {
        branches.emplace_back();
    }

    void addLeafToBranch(int branchIndex) {
        if (branchIndex >= 0 && branchIndex < branches.size()) {
            branches[branchIndex].addLeaf();
        } else {
            std::cout << "Invalid branch index.\n";
        }
    }
};

int main() {
    Tree myTree;

    myTree.addBranch();
    myTree.addBranch();
    myTree.addBranch();

    myTree.addLeafToBranch(0);
    myTree.addLeafToBranch(2);

    myTree.grow();

    return 0;
}
