#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int trainCompartmentProblem(vector<int> &arr);

int main()
{
	vector<int> arr = {1,2,3,5,6,7,4};
	int num = trainCompartmentProblem(arr);
	cout << "num:" << num << endl;
}

int trainCompartmentProblem(vector<int> &arr) {
	// Write your code here.
	stack<int> s;
	int n = arr.size();
	int max = 1;
	for(int i = arr.size() - 1; i >=0; --i)
	{
		if(!s.empty()&&s.top() == n)
			{
				if(s.size() > max)
				max = s.size();
				s.pop();
				n--;
			}
		if(arr[i] == n)
		{
			if(s.size() > max)
				max = s.size();
			if(s.size() > max)
			max = s.size();
			n--;
		}
		else{
			
			if(s.empty() || arr[i] > s.top())
			{
				s.push(arr[i]);
			}
			else
			{
				return -1;
			}
		}
	}
	while(!s.empty())
		s.pop();
	return max;
}