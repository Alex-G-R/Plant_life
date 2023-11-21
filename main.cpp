#include <iostream>


void show_main_menu();
void handle_menu_navigation(int choice);
void game_setup();
std::string get_the_game_name();
int select_game_type();

int main()
{
    show_main_menu();

    return 0;
}

void show_main_menu()
{
    std::cout << "Plant life - main menu: \n";
    std::cout << "\t 1 - start the plant life \n";
    std::cout << "\t 2 - show a game report \n";
    std::cout << "\t 3 - clear all game raports \n";
    std::cout << "\t 4 - informations \n";
    std::cout << "\t 5 - shutdown the program \n";
    std::cout << "Choose one option: ";

    int choice;
    std::cin >> choice;

    handle_menu_navigation(choice);
}

void handle_menu_navigation(int choice)
{
    switch (choice)
    {
    case 1:
        /* start sim */
        game_setup();
        break;
    case 2:
        /* show a game report */
        break;
    case 3:
        /* clear game reports */
        break;
    case 4:
        /* show info */
        break;
    case 5:
        /* shutdown */
        break;
    default:
        std::cout << "This option doesn't exist, try again \n";
        show_main_menu();
        break;
    }
}

void game_setup()
{
    std::string save_name = get_the_game_name();

    int game_type = select_game_type();

    if(game_type == 1)
    {
        /* start default game*/
    }
    else if (game_type == 2)
    {
        /* create custom game */
    }

    int nutritions = 1000;

    int sun_energy = 0;
    int soil_minerals = 0;

    int branches = 0;
    int leafs = 0;
    int roots = 1;
    int roots_lenght = 1;

}

int select_game_type()
{
    std::cout << "1 - default game, as god intended. \n";
    std::cout << "2 - custom game, create your own experience. \n";

    int choice;
    std::cin >> choice;

    return choice;
}

std::string get_the_game_name()
{
    std::cout << "Please provide a save name: ";
    std::string save_name;
    std::cin >> save_name;

    return save_name;
}