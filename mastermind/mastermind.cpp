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

/*! \class MainMenu
 *  \brief the main menu
 */

/*! \class Difficulty
 *  \brief the difficulty menu
 */

/*! \class a_Code
 *  \brief the codemaker's and codebreaker's codes
 */

/*! \var turns
 *  \brief the number of turns
 */

#include <vector>
#include <iostream>
#include "menu.h"
#include "code.h"

/*! \brief the main function
 *
 *  main constructs MainMenu.
 *
 *  While the menu::function_return_int of MainMenu is not equal to 2, or an exit has been identified, Difficulty and a_Code are constructed, the menu::acquire of MainMenu is called, and the menu::function_return_int of MainMenu switches.
 *  If it is equal to 1, or a new game has been identified, the menu::acquire of Difficulty is called and \ref turns "turns" is initialized with the menu::function_return_int of Difficulty.
 *  For turns, the code::input, code::compare, and code::won of a_Code are called.
 *  If the code::won of a_Code does not return true, or the codebreaker has not won, the code::ftostr of a_Code is output if \ref turns "turns" is not equal to 1, or it is the last turn.
 */
int main() {
    menu MainMenu("Main Menu:", "\ninput: ", "\nerror: bad input\n");
	command_struct new_game = { "1", "New Game", 1 } , exit = { "2", "Exit", 2 } , about = { "3", "About", 3 } ;
	MainMenu.list.push_back(new_game);
	MainMenu.list.push_back(exit);
	MainMenu.list.push_back(about);
    
#define VERSION "TerminalMind v0.13.3-ANSI-API\n"
    std::cout << VERSION;
#undef VERSION

    do {
        menu Difficulty("Difficulty:", "\ninput: ", "\nerror: bad input\n");
		command_struct eight_turns = { "1", "8 Turns", 8 } , ten_turns = { "2", "10 Turns", 10 } , twelve_turns = { "3", "12 Turns", 12 } ;
		Difficulty.list.push_back(eight_turns);
		Difficulty.list.push_back(ten_turns);
		Difficulty.list.push_back(twelve_turns);
        char turns;
        code a_Code;

        MainMenu.acquire();

        switch(MainMenu.function_return_int()) {
        case 1:
            Difficulty.acquire();
            turns = Difficulty.function_return_int();
            std::cout << "\nNew Game:\n";

            for(turns; turns > 0; turns--) {
                a_Code.input();
                a_Code.compare();
                if(a_Code.won() == true)
                    break;
                else {
                    if(turns != 1)
                        std::cout << a_Code.ftostr();
                }
            }

            if(a_Code.won() == true)
                std::cout << "\nYou won!\n";
            else {
                std::cout << "\nYou lost. My code was \"";
                a_Code.output_maker_code();
                std::cout << ".\"\n";
            }

            break;
        case 2:
            break;
        case 3:
            std::cout << "\nAbout\n\n    TODO:\n";
            break;
        }
    }
    while(MainMenu.function_return_int() != 2);

    return(0);
}