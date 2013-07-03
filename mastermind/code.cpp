/* code.cpp
 * --------
 * This is the C++ source file for the class "code."
 */

#include "code.h"

/* code::code (constructor of the class "code")
 * --------------------------------------------
 * Arguments: N/A
 * returns: N/A (Constructors cannot have a return type.)
 */
code::code() : distribution_one(0, 5) { /* "distribution_one" is a constant and therefore must be initialized with the constructor. See "code.h" for more
                                         * information.
                                         */
    for(char element = 0; element < 4; element++)
        maker_code[element] = distribution_one(generator_one); // assigns a random value between 0 and 5 to each element of "maker_code"
}

/* code::make_code_debug
 * ---------------------
 * Arguments: N/A
 * returns: a comma-seperated string of the colors of a code
 */
std::string code::make_code_debug() {
    std::string output; // the return value

    for(char element = 0; element < 4; element++) { // appends the color represented in each element of the codemaker's code to the return value
        switch(maker_code[element]) {
        case 0:
            output += "red";
            break;
        case 1:
            output += "orange";
            break;
        case 2:
            output += "yellow";
            break;
        case 3:
            output += "green";
            break;
        case 4:
            output += "blue";
            break;
        case 5:
            output += "violet";
            break;
        }

        if(element != 3)
            output += ", "; // appends a comma and space after the color unless the color represents the 4th element of the code
    }

    return(output);
}

/* code::input
 * -----------
 * Arguments: N/A
 * returns: void
 * acquires the codemaker's code from the console
 */
void code::input() {
    bool code_bad; /* Is/does the code:
                    *     - too short
                    *     - too long
                    *     - contain invalid characters?
                    */

    do {
        /*char character_buffer;
        char element = 0;*/

        std::string string_buffer; // raw input from the console

        std::getline(std::cin, string_buffer);
        
        /*do {          
            character_buffer = _getch();

            if(character_buffer != '\r')
                string_buffer += character_buffer;

            std::cout << character_buffer;
        }
        while(character_buffer != '\r');*/

        /* We check if the input is too short or long before checking for invalid characters. If it is not the right length, the loop continues from the
         * beginning.
         */
        if(string_buffer.length() < 4) {
            code_bad = true;
            std::cout << "     >> error : invalid input\n\n >> ";
            continue;
        }
        else if(string_buffer.length() > 4) {
            code_bad = true;
            std::cout << "     >> error : invalid input\n\n >> ";
            continue;
        }
        else
            code_bad = false;

        for(char element = 0; element < 4; element++) { /* We convert each letter of input to a value and assign it to the codebreaker's code unless
                                                         * there are invalid characters.
                                                         */
            if(code_bad == true)
                break;

            switch(string_buffer[element]) {
            case 'r':
                guess[element] = 0;
                break;
            case 'o':
                guess[element] = 1;
                break;
            case 'y':
                guess[element] = 2;
                break;
            case 'g':
                guess[element] = 3;
                break;
            case 'b':
                guess[element] = 4;
                break;
            case 'v':
                guess[element] = 5;
                break;
            default:
                std::cout << "     >> error : invalid input\n\n >> ";
                code_bad = true;
                continue;
            }
        }
    }
    while(code_bad == true); // The loop continues untill it is the right length and does not contain any invalid characters.
}

/* code::provide_feedback
 * ----------------------
 * Arguments: N/A
 * returns: void
 * assigns the number of black and white pegs to "feedback"
 */
void code::provide_feedback() {
    for(char element = 0; element < 2; element++) // The number of black and white pegs is reset after each guess.
        feedback[element] = 0;

    char maker_pegs[6]; /* This is an alternate method of storing the codemaker's code, with each element not representing a color, but the total amount
                         * thereof.
                         */

    for(char element = 0; element < 6; element++) // "maker_pegs" must be initialized.
        maker_pegs[element] = 0;

    char guess_pegs[6];                           // "[. . .]" "guess_pegs" "[. . .]"

    for(char element = 0; element < 6; element++) // "                              "
        guess_pegs[element] = 0;

    for(char element = 0; element < 4; element++) {
        if(maker_code[element] == guess[element]) { /* If the values (colors) within a particular element (location) are the same between "maker_code" and
                                                     * "guess," then the number of black pegs is incremented by one.
                                                     */
            ++(feedback[0]);
        }
        else {
            ++(maker_pegs[maker_code[element]]); /* The number representing a color in a code (e.g. 0 for red)
                                                * equals the element of "maker_pegs" representing the same color. (e.g. "maker_pegs[0]. . ."
                                                * . . . equals the total amount of red pegs in the codemaker's code. (e.g. 2 red pegs: "maker_pegs[0] = 2;")
                                                */
            ++(guess_pegs[guess[element]]); // "[. . . .]" "guess_pegs" "[. . . .]"
        }
    }
    
    for(char element = 0; element < 6; element++) /* for each element of "maker_pegs" and "guess_pegs" (w/ each representing the number of a color of pegs in
                                                   * "maker_code" and "guess" respectively:
                                                   */
        feedback[1] += (maker_pegs[element] < guess_pegs[element] ? maker_pegs[element] : guess_pegs[element]); /* We increase the number of white pegs by
                                                                                                                 * the lesser value of "maker_pegs" and
                                                                                                                 * "guess_pegs." (w/ the value referring
                                                                                                                 * to the number of a color of pegs)
                                                                                                                 */
}

bool code::win() {
    if(feedback[0] == 4)
        return(true);
    else
        return(false);
}

/* code::ftostr
 * ------------
 * Arguments: N/A
 * returns: a comma-seperated string containing the number of black and white pegs
 */
std::string code::ftostr() {
    std::string output = "\n"; // the return value

    for(char element = 0; element < 2; element++) {
        /* The value of each element is converted to its respective ASCII character and appended to the return
         * value.
         */
        char buffer[2]; // ASCII characters are stored here to initialize "pegs."

        sprintf_s(buffer, "%d", feedback[element]);
        std::string pegs(buffer);
        output += pegs + " ";

        switch(element) { // Each element of "feedback" represents a different color, which is appended to the return value here.
        case 0:
            output += "black";
            break;
        case 1:
            output += "white";
            break;
        }

        output += " ";

        // Following propper English grammar, pegs, the plural of peg, is appended to the return value following only 0 and plural numbers.
        if(feedback[element] == 1)
            output += "peg";
        else
            output += "pegs";

        switch(element) {
        case 0:
            output += ", ";
            break;
        case 1:
            output += "\n\n";
            break;
        }
    }

    return(output);
}