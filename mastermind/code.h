/* code.h
 * ------
 * This is the C++ header file for the class "code."
 */

#include <random>
#include <Windows.h>
#include <string>
#include <conio.h>
#include <iostream>
#include <cstdio>

class code {
private:
    char maker_code[4]; /* the codemaker's code
                         * Each element equals a value b/n 0 & 5, which cooresponds to a color & a letter:
                         * Value        Color       Letter
                         * 0            red         r
                         * 1            orange      o
                         * 2            yellow      y
                         * 3            green       g
                         * 4            blue        b
                         * 5            violet      v
                         */

    std::random_device seed_generator; // generates the seed
    std::random_device::result_type seed; // the seeding value of the uniform random number generator
    std::default_random_engine urng; // the uniform random number generator object of the distribution
    std::tr1::uniform_int_distribution<char> distribution; // the distribution, which generates a peg value
    char guess[4]; // the codebreaker's code
    char comparison[2]; // the result of a comparison b/n the codemaker & codebreaker's codes w/ the number of black & white pegs
public:
    code();
    void output_maker_code();
    void input(); // old
    void get();
    void provide_feedback(); // old
    void compare();
    bool win(); // old
    bool return_comparison_black();
    std::string ftostr(); // old
    void output_comparison();
};