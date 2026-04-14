//
// Created by Lev on 09.03.2026.
//

     /* FString class by Sokolov Lev 10.03.2026*/
///////////////////////////////////////////////////////////////

#include "FString.h"

FString::FString() : stringLine{},length(0)
{}

FString::FString(const FString &other)    //Initialization FString by another FString
{
    memcpy(stringLine,other.stringLine,other.length);
    length = other.length;
}

FString& FString::operator=(const FString& other)
{
    memcpy(stringLine,other.stringLine,other.length);
    length = other.length;
    return *this;
}

FString operator+(const FString& other1,const FString& other2)
{
    FString result;

    memcpy(result.stringLine,other1.stringLine,other1.length);
    memcpy(result.stringLine + other1.length - 1,other2.stringLine,other2.length);

    result.length = other1.length - 1 + other2.length;
    return result;
}

std::ostream& operator<<(std::ostream& os,const FString& outputStr)
{
    os << outputStr.stringLine;
    return os;
}
std::istream& operator>>(std::istream& is, FString& str)
{
    is >> str.stringLine;
    return is;
}