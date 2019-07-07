#include<string>
#include<iostream>

using namespace std;

int longest_substring(string &s);

int main()
{
	string s = "dqirnnnchguccmkluloyzunslxhgxjyazitnxgreplhrzreuessdofxacgicpgcpqyengvrvjamitsc";
	int res = longest_substring(s);
	cout << res << endl;
}

int longest_substring(string &s)
{
	if(s.size() == 1) return 1;
	int a[256];
	for(int i = 0; i < 256; i++)
		a[i] = -1;
	a[s[0]] = 0;
	int left = 0;
	int right = 1;
	int max = 1;
	while(right != s.size())
	{
		if(a[s[right]] > left)
			left = a[s[right]] + 1;
		a[s[right]] = right;
		if(right - left + 1 > max)
			max = right - left + 1;
		right ++;
	}
	return max;   
}