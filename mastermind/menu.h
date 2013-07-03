/* menu.h
 * ------
 * This is the C++ header file for the class "menu."
 */

#include "messages.h"
#include <string>
#include <iostream>
#include <cstdlib>

class menu {
private:
    int input;
    int MINIMUM;
    int MAXIMUM;
    MESSAGES A_MESSAGES;
public:
    menu(const int CONSTRUCTOR_MINIMUM, const int CONSTRUCTOR_MAXIMUM, MESSAGES CONSTRUCTOR_MESSAGES = MESSAGES()) {
        MINIMUM = CONSTRUCTOR_MINIMUM;
        MAXIMUM = CONSTRUCTOR_MAXIMUM;
        A_MESSAGES = CONSTRUCTOR_MESSAGES;
    }
    
    void acquire();
    int return_input();
};