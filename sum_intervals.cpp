#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long sum_intervals(vector<int> &s, int k);
void print(vector<int> &);

int main()
{
	vector<int> a{1,1,1,0,0,1};
	int k = 2;
	int num = sum_intervals(a, k);
	cout << num << endl;
	sort(a.begin(), a.end());
	print(a);
}

long long sum_intervals(vector<int> &a, int k)
{
	long long sum = 0;
	if(a.empty()) return 0;
	int left = 0;
	int right = 0;
	int sum_ones = 0;
	while(right < a.size())
	{
		if(a[right] == 1)
		{
			sum_ones ++;
			right++;
			continue;
		}
		if(a[left] == 1)
		{
			sum_ones --;
			left++;
			continue;
		}
		
		while(sum_ones > k)
		{
			if(a[left] == 1)
			{
				sum_ones--;
			}
			left++;
		}
		sum += right - left + 1 - sum_ones;
		right++;
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