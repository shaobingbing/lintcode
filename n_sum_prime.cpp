#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> sum_n(vector<int> &a, int n);
void print(vector<int> &);
void print(vector<vector<int>> &);

int main()
{
	vector<int> a{1,2,3,4,5,6,7,8,9};
	vector<vector<int>> b = sum_n(a, 10);
	print(b);
}

vector<vector<int>> sum_n(vector<int> &a, int n)
{
	vector<vector<int>> res;
	for(int i = 0; i < a.size(); i++)
	{
		vector<int> temp = {a[i]};
		res.push_back(temp);
	}
	
	return res;
}

void print(vector<int> &a)
{
	cout << "[" << a[0];
	for(int i = 1; i < a.size(); i++)
	{
		cout << ", " << a[i];
	}
	
	cout << "]" << endl;
}

void print(vector<vector<int>> &a)
{
	cout << "[" <<endl;
	for(int i = 0; i < a.size(); i++)
	{
		print(a[i]);
	}
	cout << " ]" << endl;
}