//
// Created by Lev on 09.03.2026.
//

#ifndef UNTITLED23_FSTRING_H
#define UNTITLED23_FSTRING_H

#include <cstddef>
#include <iostream>


struct SmartArray       // SmartArray struct is wrapper structure which needs to return
{                       // default char array with lentgh of menable string
    char array[256];
    char * ptr = array;
    unsigned char lentgh = 0;
};

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
    FString(const SmartArray &other);  //Initialization FString object by SmartArray object (SmartArray object is result of operator+ operation)

    template<size_t N>
    FString& operator=(const char (&other)[N]) //Assignment the array type of char and lentgh N
    {                                          //(variable lentgh) for FString object
        memcpy(stringLine,other,N);
        lentgh = N;
        return *this;
    }

    FString& operator=(const FString& other);    //Assignment the FString object content for FString object
    FString& operator=(const SmartArray& other); //Assignment the SmartArray object (result of operator+) for FString object

    template<size_t N>
    friend SmartArray operator+(const FString& other1,const char (&other2)[N]);

    template<size_t N>
    friend SmartArray operator+(const char(&other1)[N],const FString& other2);

    friend SmartArray operator+(const FString& other1,const FString& other2);
    friend std::ostream& operator<<(std::ostream& os,const FString& outputStr);
    friend std::istream& operator>>(std::istream& is, FString& str);
};


template<size_t N>
SmartArray operator+(const char (&other1)[N],const FString& other2)
{
    SmartArray result;

    memcpy(result.ptr,other1,N);
    memcpy(result.ptr + N - 1,other2.stringLine,other2.lentgh);

    result.lentgh = N - 1 + other2.lentgh;
    return result;
}

template<size_t N>
SmartArray operator+(const FString& other1,const char (&other2)[N])
{
    SmartArray result;

    memcpy(result.ptr,other1.stringLine,other1.lentgh);
    memcpy(result.ptr + other1.lentgh - 1,other2,N);

    result.lentgh = other1.lentgh - 1 + N;
    return result;
}

#endif //UNTITLED23_FSTRING_H
