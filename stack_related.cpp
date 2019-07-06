#include<stack>
#include<vector>
#include<iostream>

using namespace std;

void print(stack<int> s);
// 对栈进行排序，可以将其放入到另外一个栈中，但不可以借助数组实现
void stackSorting(stack<int> &stk);
int main()
{
	vector<int> v = {4,2,1,3};
	stack<int> s;
	for(int i = 0; i < v.size(); i++)
	{
		s.push(v[i]);
	}
	stackSorting(s);
	print(s);
	return 0;
}

void stackSorting(stack<int> &stk)
{
	stack<int> stk_temp;
	if (stk.empty()) return;
	while(!stk.empty())
	{
		int temp = stk.top();
		stk.pop();
		if(stk_temp.empty() || temp <= stk_temp.top())
		{
			stk_temp.push(temp);
		}
		else
		{
			while(!stk_temp.empty()&&stk_temp.top() < temp)
			{
				int x = stk_temp.top();
				stk_temp.pop();
				stk.push(x);
			}
			stk_temp.push(temp);
		}

	};
	while(!stk_temp.empty())
	{
		int x = stk_temp.top();
		stk_temp.pop();
		stk.push(x);
	}
}

void print(stack<int>s)
{
	cout << "| |" << endl;
	while(!s.empty())
	{
		cout << "|" << s.top() << "|" << endl;
		s.pop();
	}
	cout << " - " << endl;
}