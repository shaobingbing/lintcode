#include<vector>
#include<iostream>

using namespace std;

void print(vector<int> &s);
int one_quicksprt(int n, vector<int> &nums);

int main()
{
vector<int> a = {1,2,3,4,5,6,8,9,10,7};
	int x = one_quicksprt(10, a);
	cout << x;
}

int one_quicksprt(int n, vector<int> &nums)
{
	int i = -1;
	int piv = nums[nums.size() - 1];
	for(int j = 0; j < nums.size() - 1; j++)
	{
		if(nums[j] <= piv)
		{
			i++;
			swap(nums[i], nums[j]);
		}
	}
	i++;
	swap(nums[i], nums[nums.size() - 1]);
	i++;
	if(i == n)
		return nums[i-1];
	if(i > n)
	{
		vector<int> temp(nums.begin(), nums.begin() + i - 1);
		return one_quicksprt(n, temp);
	}
	else{
		vector<int> temp(nums.begin() + i, nums.end());
		return one_quicksprt(n - i, temp);
	}	
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