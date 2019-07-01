#include<vector>
#include<string>
#include<iostream>
#include<sstream>
using namespace std;

void print(vector<string> & num);
string reverseWords(string &s);

int main()
{
	string s1 = "    ";
	string s = reverseWords(s1);
	cout << s;
	return 0;
}



string reverseWords(string &s) {
	// write your code here
if(s.empty())
{
	return "";
}
int k = 0;
for (int i = 0; i < s.length(); i++)
{
	if(i == ' ') k++;
}
cout << "k:" << k << ",len:" << s.length() <<endl;
if(k == s.length())
return "";
istringstream iss(s);
string val;
vector<string> s1;
while(iss >> val)
{
	cout << val<<endl;;
	s1.push_back(val);
}
string t = s1[s1.size() -1];
for(int i = s1.size() - 2; i >= 0; --i)
{
	t += " ";
	t += s1[i];
}
return t;
}


void print(vector<string> & num)
{
	cout << "[";
	for(auto i = num.begin(); i != num.end(); i++)
	{
		cout << *i << " ";
	}
	cout << "]";
}
