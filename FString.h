//
// Created by Lev on 09.03.2026.
//

#ifndef FAST_AND_SIMPLY_MINIMALISTIC_STRING_V_0_1_FSTRING_H
#define FAST_AND_SIMPLY_MINIMALISTIC_STRING_V_0_1_FSTRING_H

#include <iostream>

class FString
{
private:
    char stringLine[256];
    unsigned char lentgh;

public:
    FString();

    template<size_t N>
    FString(const char (&other)[N])  //Initialization FString object by char array[N]
    {                                //(for example string literal)
        memcpy(stringLine,other,N);
        lentgh = N;
    }

    FString(const FString &other);     //Initialization FString object by another FString object)

    template<size_t N>
    FString& operator=(const char (&other)[N]) //Assignment the array type of char and lentgh N
    {                                          //(variable lentgh) for FString object
        memcpy(stringLine,other,N);
        lentgh = N;
        return *this;
    }

    FString& operator=(const FString& other);    //Assignment the FString object content for FString object

    template<size_t N>
    friend FString operator+(const FString& other1,const char (&other2)[N]);

    template<size_t N>
    friend FString operator+(const char(&other1)[N],const FString& other2);

    friend FString operator+(const FString& other1,const FString& other2);
    friend std::ostream& operator<<(std::ostream& os,const FString& outputStr);
    friend std::istream& operator>>(std::istream& is, FString& str);
};


template<size_t N>
FString operator+(const char (&other1)[N],const FString& other2)
{
    FString result;

    memcpy(result.stringLine,other1,N);
    memcpy(result.stringLine + N - 1,other2.stringLine,other2.lentgh);

    result.lentgh = N - 1 + other2.lentgh;
    return result;
}

template<size_t N>
FString operator+(const FString& other1,const char (&other2)[N])
{
    FString result;

    memcpy(result.stringLine,other1.stringLine,other1.lentgh);
    memcpy(result.stringLine + other1.lentgh - 1,other2,N);

    result.lentgh = other1.lentgh - 1 + N;
    return result;
}

#endif //FAST_AND_SIMPLY_MINIMALISTIC_STRING_V_0_1_FSTRING_H
