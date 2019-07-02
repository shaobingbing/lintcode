#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int deduplication(vector<int> &nums);
void print(vector<int> &);
vector<int>::iterator loc(vector<int> &, int, int);

int main()
{
	vector<int> nums = {1,3,1,4,2,2};
	int a = deduplication(nums);
	print(nums);
	cout << a << endl;
}

int deduplication(vector<int> &nums)
{
	sort(nums.begin(), nums.end());
    	vector<int>::iterator i = nums.begin();
    	vector<int>::iterator ii = i + 1;
    	vector<int>a;
    	while(i != nums.end())
    	{
    		if((*i) == (*ii))
    			ii++;
    		else
    		{
    		    a.push_back(*i);
    			i = ii;;
    			ii ++;
    		}
    	}
    	nums = a;
    	return a.size();
}

void print(vector<int> & nums)
{
	cout << "[";
	for (auto i = nums.begin(); i !=nums.end(); i ++)
	{
		if(i == nums.begin())
		{
			cout << *i;
		}
		else cout << ", " << *i;
	}
	cout << "]" << endl;
}