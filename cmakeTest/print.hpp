#ifndef PRINT_HPP
#define PRINT_HPP

#include <iostream>

class Print {
    public:
    std::string str;
    Print(std::string s);
    ~Print();
    void printSentance();
};

#endif