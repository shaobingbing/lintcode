#include<iostream>
#include<stack>
#include<vector>
using namespace std;

bool isLegalSeq(vector<int> &push, vector<int> &pop) ;

int main()
{
	vector<int> push = {1,2,4,3};
	vector<int> pop = {2,3,4,1};
	if(isLegalSeq(push,pop))
		cout << "true";
	else
		cout << "false";
	return 0;
}

bool isLegalSeq(vector<int> &push, vector<int> &pop) {
	// write your code here
	 int i = 0;
        int j = 0;
        stack<int> s;
        while(i < pop.size())
        {
            if(s.empty())
            {
                s.push(push[i]);
                i++;
            }
            if(push[j] != s.top())
            {
                i++;
                s.push(push[i]);
            }
            else
            {
                s.pop();
                j++;
            }
        }
        
        if(s.empty())
            return true;
        return false;
}