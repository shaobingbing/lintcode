#include<string>
#include<vector>
#include<string>
#include<algorithm>
#include<iostream>

using namespace std;
void print(vector<int> &a);
int leastInterval(string &tasks, int n);
int max(int a, int b);

/*
 * {'A', 'A', 'A', 'B', 'B'} 2 -> A->B->idle->A->B->idle->A
 * int leastInterval(string &tasks, int n);
*/
int main()
{
	string a = "AAABBCC";
	int res = leastInterval(a, 2);
	cout << res << endl;
}

int leastInterval(string &tasks, int n)
{
	// write your code here
	vector<int>ch(26,0);
	for(int i = 0; i < tasks.size(); i++)
	{
		ch[tasks[i] - 'A'] ++;
	}
	sort(ch.begin(), ch.end());
	int i = 25;
	while(i > 0 && ch[i] == ch[25])
	{
		i--;
	}
	return max(tasks.size(), (ch[25] - 1)*(n+1) + 25 - i); 
}

void print(vector<int> &a)
{
	cout << "[" << a[0];
	for(int i = 1; i < a.size(); i++)
	{
		cout << ", " << a[i];
	}
	
	cout << "]";
}

int max(int a, int b)
{
	cout << "a:" << a << ", b:" << b << endl;
	return a>b?a:b;
}