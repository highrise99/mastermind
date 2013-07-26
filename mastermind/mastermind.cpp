/*! \file mastermind.cpp
 *  \brief the main source
 *
 *  mastermind.cpp defines VERSION and calls main.
 */

/*! \def VERSION
 *  \brief using Semantic Versioning 2.0.0
 *
 *  the name, the version, and a newline
 */

#include <vector>
#include <iostream>
#include "menu.h"
#include "code.h"

/*! main constructs main_menu.
 *
 *  While the function_return_int of main_menu is not equal to 2, difficulty and a_code are constructed, main_menu.acquire is called, and the function_return_int of main_menu calls a switch.
 *  If the new game command is identified, the acquire of difficulty is called and turns is initialized with difficulty.function_return_int.
 *  For turns, the input of a_code and a_code.compare, and the win of a_code are called.
 *  If a_code.win is not true, the ftostr of a_code is output if turns is not equal to 1.
 */
int main() {
    command_struct new_game = { "1", "New Game", 1 } , exit = { "2", "Exit", 2 } , about = { "3", "About", 3 } ;
    std::vector<command_struct> main_menu_list_item_data;
    main_menu_list_item_data.push_back(new_game);
    main_menu_list_item_data.push_back(exit);
    main_menu_list_item_data.push_back(about);

	/*! the main menu
	 */
    menu main_menu("Main Menu:", "input: ", "error: bad input", main_menu_list_item_data);
    
#define VERSION "TerminalMind v0.12.0-ansi-API\n"
    std::cout << VERSION;
#undef VERSION

    do {
        command_struct eight_turns = { "1", "8 Turns", 8 } , ten_turns = { "2", "10 Turns", 10 } , twelve_turns = { "3", "12 Turns", 12 } ;
        std::vector<command_struct> difficulty_list_item_data;
        difficulty_list_item_data.push_back(eight_turns);
        difficulty_list_item_data.push_back(ten_turns);
        difficulty_list_item_data.push_back(twelve_turns);

		/*! the difficulty menu
		 */
        menu difficulty("Difficulty:", "input: ", "error: bad input", difficulty_list_item_data);
        char turns;

		/*! the codemaker's and codebreaker's codes
		 */
        code a_code;

        main_menu.acquire();

        switch(main_menu.function_return_int()) {
        case 1:
            difficulty.acquire();
            turns = difficulty.function_return_int();
            std::cout << "\nNew Game:\n";

            for(turns; turns > 0; turns--) {
                a_code.input();
                a_code.compare();
                if(a_code.won() == true)
                    break;
                else {
                    if(turns != 1)
                        std::cout << a_code.ftostr();
                }
            }

            if(a_code.won() == true)
                std::cout << "\nYou won!\n";
            else {
                std::cout << "\nYou lost. My code was \"";
                a_code.output_maker_code();
                std::cout << ".\"\n";
            }

            break;
        case 2:
            break;
        case 3:
            std::cout << "\nAbout\n\n    TODO: insert text here\n";
            break;
        }
    }
    while(main_menu.function_return_int() != 2);

    return(0);
}