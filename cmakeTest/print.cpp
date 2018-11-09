#include "print.hpp"

Print::Print(std::string s){
    str = s;
    return;
}

void
Print::printSentance(){
    std::cout << str << std::endl;
    return;
}

Print::~Print(){
    return;
}
