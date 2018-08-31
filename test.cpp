#include <iostream>
#include "djstring"
using namespace std;


int main()
{
	djstring str;

	cout<<str.size()<<endl;
	cout<<str.empty()<<endl;		
	
	djstring str2 = "abc def";
	str2.clear();
	cout<<str2.size()<<endl;
	cout<<str2.empty()<<endl;
	
	str = "12345";
	str2 = str;
	str.clear();
	cout<<str2.size()<<endl;

	djstring str3;

	str3 = djstring("abc") + "def";

	const djstring str4("hello");

	str3 = str4 + ",world";

	cin>>str3;
	cout<<str3<<endl;

	return 0;
}
