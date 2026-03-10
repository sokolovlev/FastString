#include <iostream>
#include "FString.h"
#include <cstring>

int main()
{
    FString a = "d";
    FString b = "m";
    FString c;
    c = a  + a + b;
    std::cout << c <<std::endl;
    return 0;
}