#include<vector>
#include<iostream>

using namespace std;
void print(vector<int> &);
void print(vector<vector<int>> &);

void sortColors2(vector<int> &colors, int k);

int main()
{
	vector<int>colors = {3,2,2,1,4};
	sortColors2(colors, 4);
	print(colors);
}

void sortColors2(vector<int> &colors, int k)
{
	int len = colors.size();
	int index = 0;
	while(index < len)
	{
		int temp = colors[index] - 1;
		if(colors[index] > 0)
		{
			if(colors[temp] <= 0)
			{
				colors[index] = 0;
				colors[temp]--;
				index++;
				continue;
			}
			else
			{	swap(colors[temp], colors[index]);
				colors[temp] = -1;
				continue;
			}
		}
		else{
			index++;
		}	
	}
	
	for(int i = k - 1; i >= 0; --i)
	{
		int t = 0 - colors[i];
		for(int j = len - 1; j >= len - t; --j)
		{
			colors[j] = i + 1;
		}
		len = len - t;
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

void print(vector<vector<int>> &s)
{
	cout << "[" << endl;
	for(int i = 0; i < s.size(); i++)
	{
		print(s[i]);
	}
	cout << "]" << endl;
}