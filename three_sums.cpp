#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

void print(vector<int> &);
void print(vector<vector<int>> &);
vector<vector<int>> three_sums(vector<int> &a);


int main()
{
	vector<int> a = {1,0,-1,-1,-1,-1,0,1,1,1};
	vector<vector<int>> res = three_sums(a);
	print(res);
	return 0;
}


vector<vector<int>> three_sums(vector<int> &a)
{	
	vector<vector<int>> res;
	sort(a.begin(), a.end());
	print(a);
	int div = 0;
	int piv = 0;
	for(int i = 0; i < a.size(); i++)
	{
		if( a[i] <= 0)
		{
			piv = i;
		}
	}
	for(int i = 0; i <= piv; i++)
	{
		if(i > 0&& a[i] == a[i-1])
			continue;
		int j = i + 1;
		int k = a.size() - 1;
		int target = 0 - a[i];
		while(j < k)
		{
			if(a[j] + a[k] == target)
			{
				cout << "i:" << i << endl;
				vector<int> temp = {a[i], a[j], a[k]};
				res.push_back(temp);
				while(a[j]==a[j+1])
				{
					j++;
				}
				j++;
				while(a[k]==a[k-1])
				{
					k--;
				}
				k--;
			}
			else 
			{
				if(a[j] + a[k] < target)
				{
					while(a[j]==a[j+1])
					{
						j++;
					}
					j++;
				}
				else
				{
					while(a[k]==a[k-1])
					{
						k--;
					}
					k--;
				}
			}
			
		}
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

void print(vector<vector<int>> &s)
{
	cout << "[" << endl;
	for(int i = 0; i < s.size(); i++)
	{
		print(s[i]);
	}
	cout << "]" << endl;
}