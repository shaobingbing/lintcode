#include<iostream>
#include<string>

using namespace std;

int main()
{
	string s1 = " ";
	//string s = reverseWords(s1);
	int k = 0;
	for (int i = 0; i < s1.length(); i++)
	{
		
		if(s1[i] == ' ')
		{
			k++;
		}
	}
	
	cout << k << "," << s1.length() <<endl;
	if(s1.empty())
	{
		cout << "true" << endl;
	}
	cout << s1.length() << endl;
	return 0;
}