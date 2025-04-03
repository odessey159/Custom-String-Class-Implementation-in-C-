#include <iostream>
#include "MyString.h"

//  << operator for MyString class
std::ostream& operator<<(std::ostream& os, const MyString& str);

int main() {
    char str[] = "This is a test string 654321";
    char sp[] = " + ";
    int num=123456;
    MyString str1(str);//create an object with "str"
    MyString str2;//create an empty MyString object (no string content)
    MyString str3(str);//create an object with "str"
    MyString strnum(num);//create an object with number 123456

    std::cout << "str1 = " << str1 << std::endl;
    std::cout << "str2 = " << str2 << std::endl;
    std::cout << "str3 = " << str3 << std::endl;
    std::cout << "strnum = " << strnum << std::endl;
    str2=strnum;    

    //test if the project can get the length of str1 correctly  
    std::cout << "getStrlen      " << str1 <<"     "<<str1.getStrlen()<< std::endl;
    //test if the project can turn every letter in str1 to uppercase correctly  
    std::cout << "toUpper      " << str1 <<"     ";
    str1.toUpper();
    std::cout<<str1<< std::endl;
    //test if the project can add strnum to the end of the str1 correctly
    std::cout << "strcat      " << str1 <<" "<<strnum<<"     ";
    str1.strcat(strnum);
    std::cout<<str1<< std::endl;
    str1=str3;
    //test if the project can turn every letter in str1 to uppercase correctly
    std::cout << "toLower      " << str1 <<"     ";
    str1.toLower();
    std::cout<<str1<< std::endl;
    //test if the project can copy the str3 to str2 correctly
    std::cout << "strcpy      " << str2 <<"     ";
    str2.strcpy(str3);
    std::cout<<str2<< std::endl;
    //test if the project can compare str1 to str2 correctly
    std::cout << "equals      " << str1 <<"     "<< str2 <<"     "<<str1.equals(str2)<< std::endl;
    //test if the project can compare str1 to str2(case ignored) correctly
    std::cout << "equalsIgnoreCase      " << str1 <<"     "<< str2 <<"     "<<str1.equalsIgnorCase(str2)<< std::endl;
    //test if the project can check if the string contain non-alphabet character correctly
    std::cout << "isAlphabet      " << str1 <<"     "<<str1.isAlphabet()<< std::endl;
    
}

// Overload the << operator for the MyString class, so that you can 
// use cout << MyString
std::ostream& operator<<(std::ostream& os, const MyString& str) {
    os << str.c_str;
    return os;
}