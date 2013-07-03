/* code.cpp
 * --------
 * This is the main C++ source file for Mastermind.
 */

//#define MAKE_CODE_DEBUG

#include <iostream>
#include "menu.h"
#include "code.h"

int main() {
    menu main_menu(1, 3); // an object of "menu" for the main menu
    
#define VERSION "Mastermind Alpha 1.0.2.1\n\n"
    std::cout << VERSION;
#undef VERSION

    do {
        menu difficulty(1, 3);
        char turns;
        code code_one;

        std::cout << "Main Menu:\n    1.    New Game\n    2.    Exit\n    3.    About\n\n";
        main_menu.acquire(); // acquires input for the main menu

        switch(main_menu.return_input()) { // As "main_menu.input" is private, "main_menu.return_input()" returns its value as an integer.
        case 1:
            std::cout << "\n\nDifficulty:\n    1.    8 Turns\n    2.    10 Turns\n    3.    12 Turns\n\n";
            difficulty.acquire();
            turns = 6 + 2 * difficulty.return_input(); // getting the respective number of turns from 1, 2, or 3

            // If this is defined, the codemaker's code is displayed:
#ifdef MAKE_CODE_DEBUG
            std::cout << "My code is \"" << code_one.make_code_debug() << ".\"\n\n";
#endif // MAKE_CODE_DEBUG

            std::cout << "Guess my code: ";

            for(turns; turns > 0; turns--) { // TODO: add difficulty w/ 8, 10, and 12 turn games
                code_one.input();
                code_one.provide_feedback();
                if(code_one.win() == true) /* As "code_one.feedback[0]" (the number of black pegs, 4 of which determine a win) is private,
                                            * "code_one.win()" returns its value as a character.
                                            */
                    break; // We break out of the loop if the codebreaker wins.
                else {
                    if(turns != 1) /* If a wrong guess is made on the last turn, it is not necessary to display the feedback. (though it is
                                    * necessary to call "code_one.provide_feedback()" to determine a loss)
                                    */
                        std::cout << code_one.ftostr();
                }
            }

            // We check for a win or loss and display a message accordingly.
            if(code_one.win() == true)
                std::cout << "\nYou win!\n\n\n";
            else
                std::cout << "\nYou lose. My code is \"" << code_one.make_code_debug() << ".\"\n\n\n"; /* We display the codemaker's code if the
                                                                                                        * codebreaker loses.
                                                                                                        */

            break;
        case 2:
            break;
        case 3:
            std::cout << "\n\nAbout\n\n    TODO: insert text here\n\n\n";
            break;
        }
    }
    while(main_menu.return_input() != 2); // The loop (and program) continue unless the main menu's input is "2," in which case the program exits.

    return(0);
}