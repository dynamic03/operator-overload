#include "Assignment1.h"


String::String()//default constructor
{
	rep=new char[1];
	rep[0]='\0';
	len=0;
}

String::String(const char *s)//converting a char* object to a String object
{
len=0;
const char *tmp=s;
while(*tmp)
{
	++len;
	++tmp;
}
rep=new char[len+1];
for(int i=0;i<=len;++i)
	rep[i]=s[i];
}

String::String(const String &obj)//copy constructor
{
	len=0;
	char *tmp=obj.rep;
	while(*tmp)
	{
		++len;
		++tmp;
	}
	rep=new char[len+1];
	for(int i=0;i<=len;++i)
		rep[i]=obj.rep[i];
}

String::~String()//destructor
{
delete []rep;
len=0;
}

const String& String::operator=(const String &rhs)//assignment operator
{
	if(this != &rhs)
	{
		len=0;
		char *tmp=rhs.rep;
		while (*tmp)
		{
			++len;
			++tmp;
		}
		delete [] rep;
		rep=new char[len+1];
		for(int i=0; i<=len; ++i)
		{
			rep[i]=rhs.rep[i];
		}
	}
	return *this;
}

char& String::operator[](int index)//setter
{
	assert(index<len &&index>=0);
	return rep[index];
}

char String::operator[](int index) const// getter
{
	assert(index<len && index>=0);
	return rep[index];
}

int String::Length() const
{
	return len;
}

bool operator==(const String &lhs, const String &rhs)
{
	if(lhs.Length()==0)
	{
		if(rhs.Length()==0) return true;
		else return false;
	}
	else
	{
		int shorter=lhs.Length();
		if(rhs.Length()<shorter)
			shorter=rhs.Length();
		for(int i=0;i<shorter;i++)
		{
			if(lhs.rep[i]==rhs.rep[i])
				continue;
			else
				return false;
		}
		if(lhs.Length()==rhs.Length()) return true;
		else return false;
	}		
} 

bool operator!=(const String &lhs, const String &rhs) // operators !=
{

		int shorter=lhs.Length();
		if(rhs.Length()<shorter) shorter=rhs.Length();
		for(int i=0; i<shorter;i++)
			if(lhs.rep[i]==rhs.rep[i]) continue;
			else return true;
			if(lhs.Length()==rhs.Length()) return false;
			else return true;
	
}//operator !=

bool operator>(const String &lhs,const String &rhs)//overload operators >
{
	int shorter=lhs.Length();
	if(rhs.Length()<shorter) shorter=rhs.Length();
	for(int i=0;i<shorter;i++)
	{
		if(lhs.rep[i]==rhs.rep[i]) continue;
		else
		{
			if(lhs.rep[i]>rhs.rep[i]) return true;
			else return false;
		}
	}
	if(lhs.Length()>rhs.Length()) return true;
	else return false;
}

bool operator<=(const String &lhs,const String &rhs)//overload operators <=
{
	int shorter=lhs.Length();
	if(rhs.Length()<shorter) shorter=rhs.Length();
	for(int i=0;i<shorter;i++)
	{
		if(lhs.rep[i]==rhs.rep[i]) continue ;
		else
		{
			if(lhs.rep[i]>rhs.rep[i]) return false;
			else return true;
		}
		
	}
	if(lhs.Length()==rhs.Length()) return true;
	else //after ruling out the first same char
	{
		if(lhs.Length()>rhs.Length()) return false;
		else return true;
	}
}

bool operator>=(const String &lhs,const String &rhs)//overload operators >=
{
	int shorter=lhs.Length();
	if(rhs.Length()<shorter) shorter=rhs.Length();
	for(int i=0;i<shorter;i++)
	{
		if(lhs.rep[i]==rhs.rep[i]) continue ;
		else
		{
			if(lhs.rep[i]<rhs.rep[i]) return false;
			else return true;
		}
		
	}
	if(lhs.Length()==rhs.Length()) return true;
	else //after ruling out the first same char,
	{
		if(lhs.Length()<rhs.Length()) return false;
		else return true;
	}
}

ostream& operator<< (ostream &out, const String &obj)// overload oprator << in order to cout
{
	out<<obj.rep;
	return out;
	
}

istream& operator>> (istream &in, char *input)// overload oprator >> in order to cin
{
       
        int i = 0;
       input[i]=getchar();
                        while (input[i] != '\n')
                        {
                              
							i++;
								input[i]=getchar();
                        }
						 return in;
}

String String::operator() (int startIndex, int Length) const// overload operator ()
{
	 assert(startIndex<len && startIndex>=0 &&Length<=len);
	 char *result=new char[Length];	
	 for(int i=0;i<Length;i++)
		 result[i]=rep[startIndex+i];
	 result[Length]='\0';
	 return String(result); 
 }

char* transEnterToZero(char *str)// initial input ends with '\n', we need to change '\n' into '\0'
{
	int i=0;
	while(str[i]!='\n')i++;
	str[i]='\0';
	return str;
}


int main()//test function
{

	//........................Implement the four comparison operators !=, >;<=;>= for the String class:........................	
	char *first=new char();
	char *second=new char();	
	int tFirst=0,tSecond=0;
	cout<<"(1) Implement the four comparison operators !=, >;<=;>= for the String class "<<endl<<endl;
	cout<<"Please input two strings: (input ENTER to end)"<<endl;
	cin>>first>>second;	
	String strFirst=String(transEnterToZero(first));//input strings
	String strSecond=String(transEnterToZero(second));

	cout<<"test the CORRECTNESS of operators !=; >; <=; >= "<<endl;

	if(strFirst != strSecond) cout<<strFirst <<" is not equal to "<< strSecond <<endl;
	else cout<<strFirst <<" is equal to "<< strSecond <<endl;
	
	if(strFirst > strSecond) cout<<strFirst <<" is greater than "<< strSecond <<endl;
	else cout<<strFirst <<" is smaller than or equal to "<< strSecond <<endl;

	if(strFirst <= strSecond) cout<<strFirst <<" is smaller than or equal to "<< strSecond <<endl;
	else cout<<strFirst <<" is greater than "<< strSecond <<endl;

	if(strFirst >= strSecond) cout<<strFirst <<" is greater than or equal to "<< strSecond <<endl;
	else cout<<strFirst <<" is smaller than "<< strSecond <<endl;
	

	//........................Define operator():........................	
	cout<<endl<<endl;
	cout<<"(2)  Define operator() "<<endl<<endl;
	cout<<"Please input the original string:"<<endl;
	char* originalCString= new char();
	cin>>originalCString;
	String originalSTR=String(transEnterToZero(originalCString));
	cout<<"Please input two parameters(start index and the length of substring) to get the substring:"<<endl;

	char *CstartIndex=new char();
	char *Clength=new char();
	int startIndex,length;
	cin>>CstartIndex>>Clength;
	startIndex = atoi(transEnterToZero(CstartIndex));//convert char into int 
	length= atoi(transEnterToZero(Clength));
	String subString,obj;
	obj=originalSTR;
	subString=obj(startIndex,length);
	cout<<originalSTR<<"("<<CstartIndex<<","<<Clength<<")"<<" = "<< subString<<endl;	

	return 0;
}