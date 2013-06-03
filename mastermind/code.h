/* code.h
 * ------
 * This is the C++ header file for the class "code."
 */

#include <random>
#include <string>
#include <conio.h>
#include <iostream>
#include <cstdio>

class code {
private:
    char maker_code[4]; /* the codemaker's code
                         * Each character contains a value between 0 and 5, which cooresponds to a color and letter:
                         * Value        Color       Letter
                         * 0            red         r
                         * 1            orange      o
                         * 2            yellow      y
                         * 3            green       g
                         * 4            blue        b
                         * 5            violet      v
                         */
    std::random_device generator_one;
    std::tr1::uniform_int_distribution<char> distribution_one;
    char guess[4]; // the codebreaker's code
    char feedback[2]; /* an assesment of the differences between the codemaker and codebreakers' codes which contains the total number of black
                       * and white pegs
                       */
public:
    code();
    std::string make_code_debug();
    void input();
    void provide_feedback();
    bool win();
    std::string ftostr(); 
};