#include<vector>
#include<iostream>
#include<cmath>

using namespace std;

bool isPrime(int n);
int getways(vector<int>&a, int k);
void print(vector<int>&);
void print(vector<vector<int>>&);

void generation_combination(vector<vector<int>> &res,vector<int> &nums,int n, int k, int start, vector<int>&a);
int sum(vector<int> &s);
void getWays(vector<int> &a, int k);
vector<int> add_all(vector<vector<int>> &s);

int main()
{
	vector<int> a = {1,2,3,4,5,6,7,8,9};
	getWays(a, 3);
}

void getWays(vector<int> &a, int k)
{
	vector<vector<int>> res;
	vector<int> nums;
	int n = a.size();
	generation_combination(res, nums,n, k, 0, a);
	//print(res);
	vector<int> sums = add_all(res);
	for(int i = 0; i < sums.size(); i ++)
	{
		if(isPrime(sums[i]))
		{
			cout << sums[i] << " " << endl;;
		}
	}
	print(sums);
}

void generation_combination(vector<vector<int>> &res,vector<int> &nums,int n, int k, int start, vector<int>&a)
{
	if(nums.size() == k)
	{
		res.push_back(nums);
		return;
	}
	
	for(int i = start; i < n - (k - nums.size()) + 1 ; i++)
	{	
		nums.push_back(a[i]);
		generation_combination(res, nums, n, k, i + 1, a);
		nums.pop_back();
	}
}

vector<int> add_all(vector<vector<int>> &s)
{
	vector<int> t;
	for(int i = 0; i < s.size(); i++)
	{
		int x = sum(s[i]);
		t.push_back(x);
	}
	return t;
}
int sum(vector<int> &s)
{
	int sum = 0;
	for(int i = 0; i < s.size(); i++)
	{
		sum += s[i];
	}

	return sum;
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

void print(vector<vector<int>> &s)
{
	cout << "[" << endl;
	for(int i = 0; i < s.size(); i++)
	{
		print(s[i]);
	}
	cout << "]" << endl;
}

bool isPrime(int n)
{
	if(n < 2) return false;
	for(int i = 2; i <= sqrt(n); i++)
	{
		if( n%i ==0) return false;
	}
	return true;
}