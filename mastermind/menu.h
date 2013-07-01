/* menu.h
 * ------
 * This is the C++ header file for the class "menu."
 */

#include <string>
#include <iostream>
#include <cstdlib>

struct ERRORS {
    std::string GREAT; // the error code displayed if the input is too large
    std::string LESS; // "[. . .]" small
    ERRORS() : GREAT("     >> error : invalid input\n\n >> "), LESS("     >> error : invalid input\n\n >> ") {};
    ERRORS(std::string CONSTRUCTOR_GREAT, std::string CONSTRUCTOR_LESS) : GREAT(CONSTRUCTOR_GREAT), LESS(CONSTRUCTOR_LESS) {};
};

class menu {
private:
    int input;
    char MINIMUM;
    char MAXIMUM;
    struct ERRORS A_ERRORS;
public:
    menu(const char, const char);
    menu(const char, const char, const struct ERRORS);
    void acquire();
    int return_input();
};