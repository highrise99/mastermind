#include <string>

struct MESSAGES {
    std::string GREAT; // the error code displayed if the input is too large
    std::string LESS; // "[. . .]" small
    std::string PROMPT;
    MESSAGES();
    MESSAGES(std::string, std::string, std::string);
};