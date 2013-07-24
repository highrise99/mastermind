/*! \file code.h
 *  \brief the header of code
 *
 *  code.h defines ANSI or WINDOWS.
 *  code is defined.
 */

// TODO: add #include guard

#include <random>

/*! \def ANSI
 *  build w/ ANSI escape sequences?
 */
//#define ANSI

/*! \def WINDOWS
 *  \brief build for Windows?
 *
 *  If this is defined, then Windows.h will be included.
 *
 *  HANDLE output_h will be initialized w/ GetStdHandle, & CONSOLE_SCREEN_BUFFER_INFO csbi will be defined & initialized w/ GetConsoleScreenBufferInfo.
 *
 *  SetConsoleTextAttribute will be called.
 */
#define WINDOWS

#ifdef WINDOWS
#include <Windows.h>
#endif // WINDOWS

#include <string>
#include <conio.h>
#include <iostream>
#include <cstdio>

/*! the codemaker's and codebreaker's codes
 */
class code {
private:
    char maker_code[4]; /* the codemaker's code
                         * An element equals a number b/n 0 & 5, is a color & a letter:
                         * Number        Color        Letter
                         * 0             red           r
                         * 1             yellow        y
                         * 2             green         g
                         * 3             cyan          c
                         * 4             blue          b
                         * 5             violet        v
                         */

    std::random_device seed_generator; // generates the seed
    std::random_device::result_type seed; // the seeding value of the uniform random number generator
    std::default_random_engine urng; // the uniform random number generator object of the distribution
    std::tr1::uniform_int_distribution<char> distribution; // the distribution, which generates a peg value
    char guess[4]; // the codebreaker's code
    char comparison[2]; // the result of a comparison b/n the codemaker & codebreaker's codes w/ the number of black & white pegs
public:

	/*! code initializes seed with seed_generator.
	 *  urng is initialized with std::default_random_engine(seed).
	 *  The elements of maker_code are initialized with distribution(urng).
	 */
    code();

	/*! \brief outputs the codemaker's code, in color and with commas
	 *
	 *  For the elements of maker_code, maker_code[element] switches to output the name of a color, in color.
	 *  If the element is not equal to 3, a comma is output.
	 *  Else, TODO:
	 */
    void output_maker_code();

	/*! acquires
	 */
    void input();
    void compare();
    bool won();
    std::string ftostr();
    void output_comparison(); // TODO: prototype & define
};