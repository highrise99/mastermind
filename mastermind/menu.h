/* menu.h
 * ------
 * This is the C++ header file for the class "menu."
 */

#include <cstdarg>
#include <string>
#include <new>
#include <vector>
#include <iostream>
#include <cstdlib>

struct list_item_struct {
    std::string string_handle;
    std::string data;
    int return_value;
};

class menu {
private:
    int number_list_items;

    struct list_item_data {
        std::string string_handle;
        int return_value;
    };

    

    list_item_data * a_list_item_data_ptr;
    std::string prompt;
    std::vector<list_item_struct> list;
    std::string input_prompt;
    std::string bad_input;
    int input;
public:
    /*menu(int, std::string, std::string, std::string, ...);*/
    menu(std::string, std::string, std::string, std::vector<list_item_struct>);
    void acquire();
    int return_input();
    /*~menu();*/
};