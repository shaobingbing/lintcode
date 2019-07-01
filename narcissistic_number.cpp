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

vector<int> split(int num)
{
	vector<int> res;
	do
	{
		int a = num%10;
		res.push_back(a);
		num /=10;
	}while(num !=0);
	return res;
}

int pow(int x, int n)
{
	int result = 1;
	for(int i = 0; i < n; i++)
	{
		result *= x;
	}
	return result;
}

vector<int> narcissistic_number(int n)
{
	vector<int> res;
	if (n == 0)
	{ 	res = {0};
		return res;
	}
	int end = pow(10,n);
	int begin = pow(10, n-1);
	for(int i = begin; i < end; i++)
	{
		vector<int> t = split(i);
		int sum = 0;
		for(int j = 0; j < t.size(); j++)
		{
			sum += pow(t[j], n);
		}
		if(sum == i)
		{
			res.push_back(i);
		}
	}
	return res;
}
int main()
{
	vector<int> x = split(1634);
	vector<int> res = narcissistic_number(4);
	print(res);
}