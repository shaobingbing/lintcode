#include<vector>
#include<iostream>
using namespace std;

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
	cout << "ending............"<<endl;
}

 void dfs(vector<int> &nums, int start, vector<vector<int>> &res)
    {
        if(start == nums.size()) 
		{
			print(nums);
			res.push_back(nums);
			print(res);
		}
		cout << endl;
        
        for(int i = start; i < nums.size(); i++)
        {
            if(i != start && nums[i-1] == nums[i]) continue;
            swap(nums[i], nums[start]);
			cout << "------------";
			print(nums);
			cout << "------------" << endl;
            dfs(nums, start+1, res);
            swap(nums[i], nums[start]);
        } 
    }
	
	void permuteDFS(vector<int>& num, int start, vector<vector<int>>& res) {
        if (start >= num.size()) res.push_back(num);
        for (int i = start; i < num.size(); ++i) {
			if(i != start && num[i-1] == num[i]) continue;
			swap(num[start], num[i]);
            permuteDFS(num, start + 1, res);
            swap(num[start], num[i]);
        }
    }

	
int main()
{
	vector<int> temp{1,2,2,3,3};
	vector<vector<int>> res;
//	dfs(temp,0,res);
//	print(res);
	permuteDFS(temp, 0, res);
	print(res);
	return 0;
}

