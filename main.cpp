#include <iostream>
#include "branch.h"

int main() 
{
    Branch branch;

    double nutritions = 10;

    while (true)
    {   
        std::cout << "Press any key to perform one iteration. Press 'q' to quit." << std::endl;

        // Wait for a key press
        char input;
        std::cin.get(input);

        // Process the key
        branch.updateBranch(nutritions);

        // Check for an exit key, for example, 'q'
        if (input == 'q') 
        {
            break; // Exit the loop
        }
    }

    return 0;
}
