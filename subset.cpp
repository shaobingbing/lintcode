#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> iteration_dup_method(vector<int> &nums);
vector<vector<int>> iteration_method(vector<int> &nums);
void recursive_method(vector<int> &nums,vector<int>&path, int step, vector<vector<int>> &res);
void recursive_dup_method(vector<int> &nums,vector<int>&path, vector<int>::iterator start, vector<vector<int>> &res);

void print(const vector<vector<int>> &res);
void print(vector<int> & num);

int main()
{
	vector<vector<int>> res;
	vector<int> nums{1,2};
	//res = iteration_dup_method(nums);
	vector<int> path;
	recursive_dup_method(nums,path, nums.begin(),res); 
	print(res);
}

vector<vector<int>> iteration_dup_method(vector<int> &nums)
{
	vector<vector<int>> res(1, vector<int>());
	if (nums.empty()) return res;

	int loc = 0;
	for(auto i = nums.begin(); i != nums.end(); i++)
	{
		int len = res.size();
		if(i != nums.begin() && ((*i) == (*(i-1))))
		{
			for(int j = loc; j < len; j ++)
			{
				vector<int> temp = res[j];
				temp.push_back(*i);
				//print(temp);
				res.push_back(temp);
			}
		}
		else
		{   
			for(int j = 0; j < len; j ++)
			{
				vector<int> temp = res[j];
				temp.push_back(*i);
				//print(temp);
				res.push_back(temp);
			}
		}
		loc = len;
	}
	return res;
}

vector<vector<int>> iteration_method(vector<int> &nums)
{
	vector<vector<int>> res(1, vector<int>());
	if (nums.empty()) return res;
	for(auto i = nums.begin(); i!= nums.end(); i++)
	{	
		//cout << *i<< endl;;
		int len = res.size();
		for(int j = 0; j < len; j ++)
		{
			vector<int> temp = res[j];
			
			temp.push_back(*i);
			//print(temp);
			res.push_back(temp);
		}
	}
	return res;
}

void recursive_method(vector<int> &nums,vector<int>&path, int step, vector<vector<int>> &res)
{
	if (step == nums.size()) {
		res.push_back(path);
		return;
	}
	recursive_method(nums, path, step + 1, res);
	path.push_back(nums[step]);
	recursive_method(nums,path, step + 1, res);
	path.pop_back();
}

void recursive_dup_method(vector<int> &nums,vector<int>&path, vector<int>::iterator start, vector<vector<int>> &res)
{
	res.push_back(path);

	for(auto i = start; i != nums.end(); i++)
	{
		if (i!= start && *i == *(i-1)) continue;
	
		path.push_back(*i);
		recursive_dup_method(nums,path, i+1, res);
		path.pop_back();
	}
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

void print(const vector<vector<int>> &res)
{
	cout << "The res:" << endl;
	for (auto i = res.begin(); i!= res.end() ; i++)
	{
		for(auto j = (*i).begin(); j != (*i).end(); j++)
		{
			cout << *j << " ";
		}
		cout << endl;
	}
}