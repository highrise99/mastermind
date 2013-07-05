/* menu.cpp
 * --------
 * This is the C++ header file for the class "menu."
 */

#include "menu.h"

/* menu::menu
 * ----------
 * Arguments:
 *     - constructor_number_list_items: the number of list items in the menu
 *     - title: the title of the menu
 *     - input_prompt: a prompt for input after the menu (e.g. "input: ")
 *     - constructor_bad_input: the error output if the input is invalid
 *     - ... : initializes "prompt data," w/ constructor_number_list_items * 3 arguments
 * returns: N/A (Constructors cannot have a return type.)
 * Initializes:
 *     - number_list_items: w/ constructor_number_list_items
 *     - input_prompt: w/ constructor_input_prompt
 *     - bad_input: w/ constructor_invalid_input
 */
//menu::menu(int constructor_number_list_items, std::string title, std::string constructor_input_prompt, std::string constructor_bad_input, ...) {
//    va_list prompt_data; /* in the form of:
//                          *     - std::string : a handle string to the list item
//                          *     - std::string : the list item
//                          *     - int : the return value of "menu::return_input" if the input points to the respective list item
//                          */
//    number_list_items = constructor_number_list_items;
//
//    prompt += title + "\n"; // The prompt will include the title...
//    va_start(prompt_data, constructor_input_prompt);
//    a_list_item_data_ptr = new list_item_data[number_list_items]; // initializing an array of list item data w/ an element for each list item
//
//    for(int list_item = 0; list_item < number_list_items; list_item++) { // for each list item:
//        std::string buffer; // the first argument of each list item
//
//        buffer = va_arg(prompt_data, std::string);
//        prompt += "    " + buffer + ". "; // ...title, (looped) a 4-space indent, a handle string, a period, another 4-space indent...
//        a_list_item_data_ptr[list_item].string_handle = buffer; /* initializing the string handle of the list item data of the respective list
//                                                                 * item w/ the first argument
//                                                                 */
//        prompt += va_arg(prompt_data, std::string) + "\n"; // ...indent, and a list item.
//        a_list_item_data_ptr[list_item].return_value = va_arg(prompt_data, int); // [...] the return value [...] the next argument
//    }
//
//    va_end(prompt_data);
//    input_prompt = constructor_input_prompt;
//    bad_input = constructor_bad_input;
//}

menu::menu(std::string title, std::string constructor_input_prompt, std::string constructor_bad_input, std::vector<list_item_struct> constructor_list) {
    prompt += title + "\n";
    list = constructor_list;

    for(std::vector<list_item_struct>::size_type list_item = 0; list_item < list.size(); list_item++)
        prompt += "    " + list[list_item].string_handle + ". " + list[list_item].data + "\n";

    input_prompt = constructor_input_prompt;
    bad_input = constructor_bad_input;
}

/* menu::acquire
 * Arguments: N/A
 * returns: void
 */
void menu::acquire() {
    std::vector<list_item_struct>::size_type list_item;
    bool input_bad = true;

    std::cout << prompt;

    do {
        std::string buffer;

        std::cout << input_prompt;
        std::getline(std::cin, buffer);
        for(list_item = 0; list_item < list.size(); list_item++) {
            if(buffer == list[list_item].string_handle) {
                input_bad = false;
                break;
            }
            else
                input_bad = true;
        }

        if(input_bad == true)
            std::cout << bad_input;
    }
    while(input_bad == true); // The loop continues while the input is bad.

    input = list[list_item].return_value;
}

int menu::return_input() {
    return(input);
}

//menu::~menu() {
//    delete[] a_list_item_data_ptr;
//}