//
// Created by Lev on 09.03.2026.
//

     /* FString class by Sokolov Lev 10.03.2026*/
///////////////////////////////////////////////////////////////

#include "FString.h"

FString::FString() : stringLine{},lentgh(0)
{}

FString::FString(const FString &other)   //Initialization FString by another FString
{
    memcpy(stringLine,other.stringLine,other.lentgh);
    lentgh = other.lentgh;
}

FString& FString::operator=(const FString& other)
{
    memcpy(stringLine,other.stringLine,other.lentgh);
    lentgh = other.lentgh;
    return *this;
}

FString operator+(const FString& other1,const FString& other2)
{
    FString result;

    memcpy(result.stringLine,other1.stringLine,other1.lentgh);
    memcpy(result.stringLine + other1.lentgh - 1,other2.stringLine,other2.lentgh);

    result.lentgh = other1.lentgh - 1 + other2.lentgh;
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