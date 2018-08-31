#include <iostream>
#include <cstring>
#include "djstring"
using namespace std;



djstring::djstring()
{
	buff = new char[2];
	buff[0] = '\0';
}

djstring::djstring(const char* str)
{
	buff = new char[strlen(str) + 2];
	strcpy(buff, str);
}

djstring::djstring(const djstring& str)
{
	buff = new char[strlen(str.buff) + 2];
	strcpy(buff, str.buff);
}

djstring::~djstring()
{
	delete []buff;
}


int djstring::size() const
{
	return strlen(buff);
}

bool djstring::empty() const
{
	return (buff[0] == '\0');
}


void djstring::clear()
{
	buff[0] = '\0';
}


djstring& djstring::operator=(const djstring& str)
{
	delete []buff;
	buff = new char[strlen(str.buff) + 2];
	strcpy(buff, str.buff);

	return *this;
}


djstring djstring::operator+(const djstring& str) const
{
	djstring tmp;
	delete tmp.buff;
	tmp.buff = new char[strlen(this->buff) + strlen(str.buff) + 2];
	strcpy(tmp.buff, this->buff);
	strcat(tmp.buff, str.buff);
	
	return tmp;
}


ostream& operator<<(ostream& out, const djstring& str)
{
	out<<str.buff;
	return out;
}


istream& operator>>(istream& in, djstring& str)
{
	char* input_buff = NULL;
	int size = 1000;
	int cnt = 0;
	char chr;

	input_buff = new char[size + 1];

	while(1)
	{
		chr = in.get();
		
		if('\n' == chr) break;

		input_buff[cnt++] = chr;

		if(size == cnt)
		{
			size += 100;	
			char* temp_buff = new char[size + 1];
			memcpy(temp_buff, input_buff, cnt);
			delete []input_buff;
			input_buff = temp_buff;		
		}
	}
	
	input_buff[cnt] = '\0';
	
	delete []str.buff;
	str.buff = input_buff;

	return in;
}

