/* code.cpp
 * --------
 * This is the main C++ source file for Mastermind.
 */

//#define MAKE_CODE_DEBUG

#include <vector>
#include <iostream>
#include "menu.h"
#include "code.h"

int main() {
    command_struct new_game = { "1", "New Game", 1 } , exit = { "2", "Exit", 2 } , about = { "3", "About", 3 } ;
    std::vector<command_struct> main_menu_list_item_data;
    main_menu_list_item_data.push_back(new_game);
    main_menu_list_item_data.push_back(exit);
    main_menu_list_item_data.push_back(about);
    menu main_menu("Main Menu:", "input: ", "error: bad input", main_menu_list_item_data); // an instance of the "menu" class for the main menu
    
#define VERSION "Mastermind v0.4.6\n"
    std::cout << VERSION;
#undef VERSION

    do {
        command_struct eight_turns = { "1", "8 Turns", 8 } , ten_turns = { "2", "10 Turns", 10 } , twelve_turns = { "3", "12 Turns", 12 } ;
        std::vector<command_struct> difficulty_list_item_data;
        difficulty_list_item_data.push_back(eight_turns);
        difficulty_list_item_data.push_back(ten_turns);
        difficulty_list_item_data.push_back(twelve_turns);
        menu difficulty("Difficulty:", "input: ", "error: bad input", difficulty_list_item_data); // [. . .] the difficulty menu
        char turns; // the number of turns (remaining)
        code a_code; // an instance of the "code" class

        main_menu.acquire(); // getting input for the main menu

        switch(main_menu.return_input()) { // As "main_menu.input" is private, "main_menu.return_input()" returns its value as an integer.
        case 1:
            difficulty.acquire(); // getting input for the difficulty menu...
            turns = difficulty.return_input(); // The return values are 8, 10, and 12. (turns)

            // If this is defined, the codemaker's code is output:
#ifdef MAKE_CODE_DEBUG
            std::cout << "My code is \"" << code_one.make_code_debug() << ".\"\n\n";
#endif // MAKE_CODE_DEBUG

            std::cout << "\nGuess my code: ";

            for(turns; turns > 0; turns--) {
                a_code.input();
                a_code.provide_feedback();
                if(a_code.win() == true) /* As "code_one.feedback[0]" (the number of black pegs, 4 of which determine a win) is private,
                                            * "code_one.win()" returns its value as a character.
                                            */
                    break; // We break out of the loop if the codebreaker wins.
                else {
                    if(turns != 1) /* If a wrong guess is made on the last turn, it is not necessary to display the feedback. (though it is
                                    * necessary to call "code_one.provide_feedback()" to determine a loss)
                                    */
                        std::cout << a_code.ftostr();
                }
            }

            // We check for a win or loss and output accordingly.
            if(a_code.win() == true)
                std::cout << "\nYou win!\n";
            else
                std::cout << "\nYou lose. My code is \"" << a_code.make_code_debug() << ".\"\n"; /* We display the codemaker's code if the
                                                                                                        * codebreaker loses.
                                                                                                        */

            break;
        case 2:
            break;
        case 3:
            std::cout << "\nAbout\n\n    TODO: insert text here\n";
            break;
        }
    }
    while(main_menu.return_input() != 2); // The loop (and program) continue unless the main menu's input is "2," in which case the program exits.

    return(0);
}