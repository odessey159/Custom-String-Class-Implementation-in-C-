#include "MyString.h"

MyString::MyString() {
	c_str[0] = 0;
	strlen = 0;
}

MyString::MyString(char str[]) {
	int len = 0;
	char ch = str[len];
	//get the string length from the input array str
	while (ch != 0 && len < MAXLEN) {
		len++;
		ch = str[len];
	}
	//copy the charater sequence
	for (int i = 0; i < len; i++) c_str[i] = str[i];
	//add the 0 to the end and update the string length
	c_str[len] = 0;
	strlen = len;
}
//get the string length
int MyString::getStrlen() { return strlen; }

//covert the strig to upper case
void MyString::toUpper() {
	int i = 0;
	char tmp = 0;
	while (i < strlen) {
		tmp = c_str[i];
		//convert aphabet letters only, other letters, no change
		tmp = (tmp > 96 && tmp < 123) ? (tmp - 32) : tmp;
		c_str[i] = tmp;
		i++;
	}
}
// add a string to the end of anothr string.
void MyString::strcat(MyString& str) {
	int len = str.strlen;
	int k = 0;
	int j = strlen;
	while (j < MAXLEN && k<len) c_str[j++] = str.c_str[k++];	
	strlen += k;
	c_str[strlen] = 0;
}

MyString& MyString::operator=(MyString& str) {
	strlen = str.getStrlen();
	for (int i = 0; i <= strlen; i++) c_str[i] = str.c_str[i];
	return *this;
}

MyString& MyString::operator+=(MyString& str) {
	this->strcat(str);
	return *this;
}

MyString::MyString(unsigned int n)//a constructor with an integer.
{
    int temp=n;
    if(n==0)c_str[strlen++]='0';//check if the integer is 0, then just set the str be '0'
    while(temp>0)//get the reverse order of integer
    {
        c_str[strlen++]=temp%10+'0';
        temp/=10;
    }
    for(int i=0;i<strlen/2;++i)//turn the  order right
    {
        temp=c_str[i];
        c_str[i]=c_str[strlen-i-1];
        c_str[strlen-i-1]=temp;
    }
}

void MyString::toLower()//change the string to lower case
{
    int i = 0;
	char tmp = 0;
	while (i < strlen)
    {
		tmp = c_str[i];
		//convert aphabet letters only, other letters, no change
		tmp = (tmp > 64 && tmp < 91) ? (tmp + 32) : tmp;
		c_str[i] = tmp;
		i++;
	}
}

void MyString::strcpy(MyString& str)
{
    while(strlen>0)//clean the strlen first
    {
        strlen--;
        c_str[strlen]=0;
    }
    int len = 0;
	char ch = str.c_str[len];
	//get the string length from the input array str
	while (ch != 0 && len < MAXLEN) {
		len++;
		ch = str.c_str[len];
	}
	//copy the charater sequence
	for (int i = 0; i < len; i++) c_str[i] = str.c_str[i];
	//add the 0 to the end and update the string length
	c_str[len] = 0;
	strlen = len;
}

bool MyString::equals(MyString& str)//string comparision, case-senstive.
{
    if(strlen!=str.strlen) return false;//check if the length of two str is the same
    for(int i=0;i<strlen;++i)
    {
        if(c_str[i]!=str.c_str[i])//if anny letter is distinct,return false
        return false;
    }
    return true;
}

bool MyString::equalsIgnorCase(MyString& str)//string comparision, ignore case.
{
    if(strlen!=str.strlen) return false;
    for(int i=0;i<strlen;++i)
    {
        if(c_str[i]!=str.c_str[i] && c_str[i]!=(str.c_str[i]+32) && c_str[i]!=(str.c_str[i]-32))//return false only the letter is not case different
        return false;
    }
    return true;
}

void MyString::trim()//removing space from begining and end of the string
{
    int len=0;
    while(len<=strlen && c_str[len]==' ')
        len++;
    for(int i=0;i<strlen-len;++i)
        c_str[i]=c_str[i+len];
    strlen-=len;
    while(strlen>0 && c_str[strlen-1]==' ')
        c_str[--strlen]=0;
}

bool MyString::isAlphabet()//check if the string contain non-alphabet character
{
    for(int i=0;i<strlen;++i)
        if (c_str[i]<65 || (c_str[i]>90 && c_str[i]<97) || c_str[i]>122)
            return false;
    return true;
}

MyString::~MyString() {
	//typically clean up memory in class
}

