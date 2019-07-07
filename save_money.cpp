#include<vector>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
vector<int> getAns(vector<int> &op, vector<string> &name, vector<int> &w);
void print(vector<int> &);

int main()
{
vector<int>op = {1,1,0,0,1,1,1,0,1,0,0,1,1,0,1};
	vector<string>names = {"qtz","wmc","ipr","ipr","wmc","ipr","ipr","qtz","ipr","qtz","ipr","wmc","wmc","qtz","qtz"};
vector<int>w = {132,140,31,69,107,37,48,10,78,80,143,108,118,100,51};
	
	vector<int> res = getAns(op, names, w);
	print(res);
}
vector<int> getAns(vector<int> &op, vector<string> &name, vector<int> &w) {
	// Write your code here
	unordered_map<string, int> temp;
	vector<int>res;
	for(int i = 0; i < op.size(); i++)
	{
		if(temp.find(name[i]) != temp.end())
		{
			if(op[i] == 0)
			{
				if(temp[name[i]] == -1)
					temp[name[i]] = w[i];
				else
					temp[name[i]] += w[i];
			}
			else
			{
				if(temp[name[i]] < w[i])
				{
					res.push_back(-1);
					continue;
				}
				else
					temp[name[i]] -= w[i];
			}
		}
		else
		{
			if(op[i] == 0)
				temp.insert({name[i], w[i]});
			else
				temp.insert({name[i], -1});
		}
		res.push_back(temp[name[i]]);  
	}
	return res;
}
	
void print(vector<int> &s)
{
	cout << "[" << s[0];
	for(int i = 1; i < s.size(); i++)
	{
		cout << ", " << s[i];
	}
	cout << "]" << endl;
}