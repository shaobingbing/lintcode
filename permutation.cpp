#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

vector<vector<int>> permutation(vector<int>&);
bool next_permutation(vector<int>&);
void reverse(vector<int>&, int);
void print(vector<int> & num);

int main()
{
	vector<int> a{1,2,3,4};
	vector<vector<int>> res = permutation(a);
	cout << "tht number of permutation is : " << res.size() << endl;
	for (auto i = res.begin(); i != res.end(); i++)
	{
		cout << "[";
		for(auto j = (*i).begin(); j != (*i).end(); j++)
		{
			if(j!=(*i).end()-1)
			{
				cout << *j << ", ";
			}
			else
				cout << *j << "]" << endl;
		}
	}
	
	vector<int> s{1,2,3,4};
	//vector<int>::iterator last = s.end();
	//cout << "The last is" << *last << endl;
//	reverse(s, 2);
//	for(auto i = s.begin(); i != s.end(); i++)
//	{
//		cout << *i << " " ;
//	}

	cout << "-----------------------" << endl;
	vector<int> test{0,-1,1};
	next_permutation(test);
	sort(test.begin(), test.end());
	print(test);
	return 0;
}

vector<vector<int>> permutation(vector<int> &nums)
{
	if (nums.empty())
		return vector<vector<int>>(1, vector<int>());
	if (nums.size() == 1)
		return vector<vector<int>>(1, vector<int>(nums));
	else{
		vector<vector<int>> res;
		res.push_back(nums);
		while (next_permutation(nums))
		{
			res.push_back(nums);
		}
		return res;
	}	
}

bool next_permutation(vector<int> &nums)
{
	int first = 0;
	int last = nums.size();
	int i = last - 1;
	for(;;)
	{
		int ii = i;
		--i;
		if(nums[i] < nums[ii])
		{
			int j = last;
			while(!(nums[i] < nums[--j]));
			swap(nums[i], nums[j]);
			reverse(nums, ii);
			return true;
		}
		if(i == 0)
		{
			print(nums);
			return false;
		}
	}
}

void print(vector<int> & num)
{
	cout << "[";
	for(auto i = num.begin(); i != num.end(); i++)
	{
		cout << *i << " ";
	}
	cout << "]" << endl;
}

void reverse(vector<int> &nums, int k)
{
	int begin = k;
	int end = nums.size() - 1;
	for(int i = begin, j = end; i <=j; i++, j--)
	{
		swap(nums[i], nums[j]);
	}
}