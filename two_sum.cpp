#include<iostream>
#include<vector>
#include<map>
using namespace std;

vector<int> two_sum(vector<int> &numbers, int target);
void print(vector<int> & num);
int main()
{
	vector<int> a{1,2,4,4,4,4, 4};
	vector<int>res = two_sum(a,8);
	print(res);
	return 0;
}

vector<int> two_sum(vector<int> &numbers, int target)
{
	map<int, int> val_index;
	for(int i = 0; i < numbers.size(); i++)
	{
		val_index.insert({numbers[i],i});
	}
	vector<int> a;
	for(int i = 0; i < numbers.size(); i++)
	{
	
		int diff = target - numbers[i];
		while(val_index.find(diff) != val_index.end())
		{	cout << val_index.find(diff)->first << endl;
			a = {i, val_index[diff]};
		}
	}
	return a;
}

void print(vector<int> & num)
{
	cout << "[";
	for(auto i = num.begin(); i != num.end(); i++)
	{
		cout << *i << " ";
	}
	cout << "]";
}