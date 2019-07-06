#include<vector>
#include<iostream>

using namespace std;

void print(vector<int> &);
int search(vector<int> sums, int target);
long long doing_homework(vector<int> &cost, vector<int> &val);

int main()
{
	int sum = 0;
	vector<int> cost = {3,3,3};
	vector<int> val = {7,15,11,13,1,6,11,15,11,1,8,9,13,9,1};
	long long res = doing_homework(cost, val);
	cout << res << endl;
	
}

long long doing_homework(vector<int> &cost, vector<int> &val)
{
	int sum = 0;
	vector<int> sums;
	for(int i = 0; i < cost.size(); i++)
	{
		sum += cost[i];
		sums.push_back(sum);
	}
	
	long long res = 0;
	for(int i = 0; i < val.size(); i++)
	{
		int value = search(sums, val[i]);
		res += value;
	}
	return res;
}

int search(vector<int> sums, int target)
{
	int left = 0;
	int right = sums.size() - 1;
	while(left <= right)
	{
		int mid = (left + right) /2;
		if(target == sums[mid]) return target;
		if(target < sums[mid]) right = mid - 1;
		else left = mid + 1;
	}
	if(right == -1) return 0;
	return sums[right];
}

void print(vector<int>&s)
{
	cout << "[" << s[0];
	for(int i = 1; i < s.size(); i++)
	{
		cout << ", " << s[i];
	}
	cout << "]" << endl;
}