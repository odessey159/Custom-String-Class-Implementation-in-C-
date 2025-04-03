#pragma once
//You are not allow to include anything in this file.
class MyString
{
public:
	#define MAXLEN 256 //define the maximum lenth of the string
	//Data members 
	char c_str[MAXLEN]; //the C-Style string 
	int strlen = 0; //string lenth

	//Constructors of the class
	MyString(); //A default constructor
	MyString(char str[]);//create a constrctor with c-style string
	int getStrlen(); // return lenth of the current string
	void toUpper(); //change the string to upper case 'A'
	void strcat(MyString& str); //add "str" to the end of the string
	MyString& operator=(MyString& str);	
	MyString& operator+=(MyString& str);

	MyString(unsigned int n);//a constructor with an integer. 
	void toLower();//change the string to lower case
	void strcpy(MyString& str); //copy the input string 
	bool equals(MyString& str); //string comparision, case-senstive.
	bool equalsIgnorCase(MyString& str); //string comparision, ignore case.
	void trim();//removing space from begining and end of the string
	bool isAlphabet(); //check if the string contain non-alphabet character

	~MyString(); //this function will be called before delete the object.
};
