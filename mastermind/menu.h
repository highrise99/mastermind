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
};

class menu {
private:
    int input;
    char MINIMUM;
    char MAXIMUM;
    struct ERRORS A_ERRORS;
public:
    menu(const char, const char, const struct ERRORS);
    void acquire();
    int return_input();
};