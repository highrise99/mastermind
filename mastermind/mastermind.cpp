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
    
#define VERSION "Mastermind v0.10.7-alpha-api\n"
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

        switch(main_menu.function_return_int()) { // As "main_menu.input" is private, "main_menu.return_input()" returns its value as an integer.
        case 1:
            difficulty.acquire(); // getting input for the difficulty menu...
            turns = difficulty.function_return_int(); // The return values are 8, 10, and 12. (turns)

            // If this is defined, then the codemaker's code is output:
#ifdef MAKE_CODE_DEBUG
            std::cout << "My code is \"";
            a_code.output_maker_code();
            std::cout << ".\"\n";
#endif // MAKE_CODE_DEBUG

            std::cout << "\nNew Game:\n";

            for(turns; turns > 0; turns--) {
                a_code.input();
                a_code.compare();
                if(a_code.won() == true) /* As "a_code.comparison[0]" (the number of black pegs, 4 of which indicate a win) is private,
                                          * "a_code.won()" returns "true" if "a_code.comparison[0]" equals 4. (the codebreaker wins)
                                          */
                    break;
                else {
                    if(turns != 1) /* If an incorrect guess is entered on the last turn, it is not necessary to display the result of the
                                    * comparison. (However, it is necessary to call "code_one.compare()" to determine a loss.)
                                    */
                        std::cout << a_code.ftostr();
                }
            }

            if(a_code.won() == true)
                std::cout << "\nYou won!\n";
            else {
                std::cout << "\nYou lost. My code was \"";
                a_code.output_maker_code();
                std::cout << ".\"\n"; // If the codebreaker loses, then the codemaker's code is output.
            }

            break;
        case 2:
            break;
        case 3:
            std::cout << "\nAbout\n\n    TODO: insert text here\n";
            break;
        }
    }
    while(main_menu.function_return_int() != 2); // loops while the main menu input is not 2 (which determines the exit)

    return(0);
}