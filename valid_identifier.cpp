#include<string>
#include<iostream>

using namespace std;

bool isLegalIdentifier(string &str);
bool is_true(char s);

int main()
{
	string s = " ";
	if (isLegalIdentifier(s))
	{
		cout<<"true"<<endl;
	}
	else cout << "false" <<endl;
	return 0;
}

bool isLegalIdentifier(string &str) {
	// Write your code here.
	if(str.empty())
	{
		return false;
	}
	int n = 0;
	for(int i = 0; i < str.size(); i++)
	{
		if(str[i] == ' ') n++;
	}
	if (n == str.size()) return false;
	if(str[0] >= '0' && str[0] <='9')
		return false;
	for(int i = 0; i < str.length(); i++)
	{
		if (is_true(str[i]) == false)
		{
			//cout << str[i]<<endl;
			return false;
		}
	}
	return true;
}

bool is_true(char s)
{
	if((s >= '0' && s <= '9') || (s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z') || s == '_') return true;
	return false;
}