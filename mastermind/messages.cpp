#include "messages.h"

MESSAGES::MESSAGES() : GREAT("    error : invalid input\n\n"), LESS("    error : invalid input\n\n"), PROMPT("input: ") {}

MESSAGES::MESSAGES(std::string CONSTRUCTOR_GREAT, std::string CONSTRUCTOR_LESS, std::string CONSTRUCTOR_PROMPT) : GREAT(CONSTRUCTOR_GREAT), LESS(CONSTRUCTOR_LESS),
        PROMPT(CONSTRUCTOR_PROMPT) {}