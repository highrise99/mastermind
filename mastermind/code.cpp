/* code.cpp
 * --------
 * This is the C++ source file for the class "code."
 */

#include "code.h"

/* code::code
 * ----------
 * Arguments: N/A
 * returns: N/A (Constructors cannot have a return type.)
 * Initializes:
 *     - distribution w/ (0, 5)
 *     - seed w/ seed_generator()
 *     - urng w/ std::default_random_engine(seed)
 *     - each peg of the codemaker's code with a psuedo-randomly generated, randomly seeded value
 */
code::code() : distribution(0, 5) {
    seed = seed_generator();
    urng = std::default_random_engine(seed);

    for(char element = 0; element < 4; element++)
        maker_code[element] = distribution(urng);
}

/* code::output_maker_code
 * -----------------------
 * Arguments: N/A
 * returns: void
 * outputs a colored, comma-seperated ordered list of the pegs of the codemaker's code
 */
void code::output_maker_code() {
#ifdef WINDOWS
    HANDLE output_h = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    GetConsoleScreenBufferInfo(output_h, &csbi);
#endif // WINDOWS

    for(char element = 0; element < 4; element++) { // for each peg of the codemaker's code...
        switch(maker_code[element]) { // sets the output text color and outputs the respective color
        case 0:
#ifdef ANSI
            std::cout << "\033[0;31m";
#endif // ANSI

#ifdef WINDOWS
            SetConsoleTextAttribute(output_h, FOREGROUND_RED | FOREGROUND_INTENSITY);
#endif // WINDOWS

            std::cout << "red";
            break;
        case 1:
#ifdef ANSI
            std::cout << "\033[0;33m";
#endif // ANSI

#ifdef WINDOWS
            SetConsoleTextAttribute(output_h, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
#endif // WINDOWS

            std::cout << "yellow";
            break;
        case 2:
#ifdef ANSI
            std::cout << "\033[0;32m";
#endif // ANSI

#ifdef WINDOWS
            SetConsoleTextAttribute(output_h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
#endif // WINDOWS

            std::cout << "green";
            break;
        case 3:
#ifdef ANSI
            std::cout << "\033[0;36m";
#endif // ANSI

#ifdef WINDOWS
            SetConsoleTextAttribute(output_h, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
#endif // WINDOWS

            std::cout << "cyan";
            break;
        case 4:
#ifdef ANSI
            std::cout << "\033[0;34m";
#endif // ANSI

#ifdef WINDOWS
            SetConsoleTextAttribute(output_h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
#endif // WINDOWS

            std::cout << "blue";
            break;
        case 5:
#ifdef ANSI
            std::cout << "\033[0;35m";
#endif // ANSI

#ifdef WINDOWS
            SetConsoleTextAttribute(output_h, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
#endif // WINDOWS

            std::cout << "violet";
            break;
        }

        if(element != 3) // if the element doesn't point to the last peg, output a comma
            std::cout << ", ";

#ifdef ANSI
        std::cout << "\033[0m";
#endif // ANSI

#ifdef WINDOWS
        SetConsoleTextAttribute(output_h, csbi.wAttributes);
#endif // WINDOWS
    }
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

        /* We check if the input is too short or long before checking for invalid characters. If it is not the right length, the loop continues
         * from the beginning.
         */
        if(string_buffer.length() < 4) {
            code_bad = true;
            std::cout << "\nerror: input too short\n\n";
            continue;
        }
        else if(string_buffer.length() > 4) {
            code_bad = true;
            std::cout << "\nerror: input too long\n\n";
            continue;
        }
        else
            code_bad = false;

        for(char element = 0; element < 4; element++) { /* We convert each letter of input to a value and assign it to the codebreaker's code
                                                         * unless there are invalid characters.
                                                         */
            if(code_bad == true)
                break;

            switch(string_buffer[element]) {
            case 'r':
                guess[element] = 0;
                break;
            case 'y':
                guess[element] = 1;
                break;
            case 'g':
                guess[element] = 2;
                break;
            case 'c':
                guess[element] = 3;
                break;
            case 'b':
                guess[element] = 4;
                break;
            case 'v':
                guess[element] = 5;
                break;
            default:
                std::cout << "\nerror: bad input\n\n";
                code_bad = true;
                continue;
            }
        }
    }
    while(code_bad == true); // The loop continues untill it is the right length and does not contain any invalid characters.
}

/* code::compare
 * -------------
 * Arguments: N/A
 * returns: void
 * Initializes:
 *     - "comparison" w/ the number of black & white pegs
 *     - "maker_pegs" w/ 0 for each element
 *     - "guess_pegs" [. . .]
 */
void code::compare() {
    for(char element = 0; element < 2; element++)
        comparison[element] = 0; // The number of black & white pegs is reset after each guess

    char maker_pegs[6]; // the number of each color of peg in the codemaker's code

    for(char element = 0; element < 6; element++)
        maker_pegs[element] = 0;

    char guess_pegs[6]; // [. . .] the codebreaker's code

    for(char element = 0; element < 6; element++)
        guess_pegs[element] = 0;

    for(char element = 0; element < 4; element++) { // for each position in the codemaker's code
        if(maker_code[element] == guess[element]) { /* A black peg represents a peg of the correct color (value) in the correct position.
                                                     * ("element" = "element")
                                                     */
            ++(comparison[0]);
        }
        else {
            ++(maker_pegs[maker_code[element]]); /* incrementing the number of the current color of pegs (An element of "maker_pegs" equals the
                                                  * value of its color of pegs.)
                                                  */
            ++(guess_pegs[guess[element]]); // [. . .] of "guess_pegs" equals [. . . .]
        }
    }
    
    for(char element = 0; element < 6; element++) // for the number of pegs of each color
        comparison[1] += (maker_pegs[element] < guess_pegs[element] ? maker_pegs[element] : guess_pegs[element]); /* incrementing the number of
                                                                                                                   * white pegs by the lesser
                                                                                                                   * value (A peg can only occupy
                                                                                                                   * 1 position.) b/n the number
                                                                                                                   * of pegs of the color (A white
                                                                                                                   * peg represents a peg of a
                                                                                                                   * correct color in an incorrect
                                                                                                                   * position.) in the codemaker's
                                                                                                                   * code & the number of pegs in
                                                                                                                   * the codebreaker's code
                                                                                                                   */
}

bool code::won() {
    if(comparison[0] == 4)
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

        sprintf_s(buffer, "%d", comparison[element]);
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
        if(comparison[element] == 1)
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