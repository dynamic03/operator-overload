#ifndef __MYSTRING_H__
#define __MYSTRING_H__

#include<assert.h>
#include<iostream>//in order to input and output on the console

using namespace std;

class String{
public:
	String();
	String(const char *s);//pointer situation
	String(const String &s);//create a copy of a String Object
	~String();
	const String& operator=(const String &rhsObject);
	
	char& operator[](int index);//setter
	char operator[] (int index) const;//getter

	int Length() const;// get length

	friend String operator+ (const String &lhsObject, const String &rhsObject);	
	friend bool operator== (const String &lhsObject, const String &rhsObject);
	friend bool operator< (const String &lhsObject, const String &rhsObject);
	friend bool operator> (const String &lhsObject, const String &rhsObject);
	friend bool operator<= (const String &lhsObject, const String &rhsObject);
	friend bool operator>= (const String &lhsObject, const String &rhsObject);
	friend bool operator!= (const String &lhsObject, const String &rhsObject);
	
	const char* C_StyleString() const;
	
	friend ostream& operator<< (ostream &out, const String &obj);
    friend istream& operator>> (istream &in, char *input);
	
	String operator()(int startIndex, int Length) const;

private:
	char *rep;//for a dynamic array
	int len; //keep track 

};
#endif