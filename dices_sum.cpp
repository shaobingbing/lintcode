#include<utility>
#include<vector>
#include<iostream>
using namespace std;

vector<pair<int, double>> diceSum(int n);
void print(vector<pair<int, double>> & num_prob);
void print(vector<int> & num);
void print(vector<string> & num);
void print(pair<int, double>&);
vector<pair<int,double>> next(int n, vector<pair<int, double>> &pre);


int main()
{
	vector<pair<int, double>> res = diceSum(2);
	cout << "........................"<<endl;
	print(res);
	return 0;
}

vector<pair<int, double>> diceSum(int n)
{	
	vector<pair<int, double>> a = {{1,0.17}, {2, 0.17}, {3, 0.17}, {4, 0.17}, {5, 0.17}, {6, 0.17},};
	vector<pair<int, double>> pre = a;
	vector<pair<int, double>> result;
	if (n == 1)
	{
		return a;
	}
	for(int i = 1; i < n; i++)
	{	
		result = next(i, pre);
		pre = result;
	}
	return result;
}

vector<pair<int,double>> next(int n, vector<pair<int, double>> &pre)
{
	vector<pair<int, double>> res;
	int first_bound = n+5;
	int second_bound = 6 * n + 2;
	int len = 0;
	for(int i = n+1; i <= first_bound; i++)
	{
		len++;
		double prob = 0.0;
		for(int j = 0; j < len; j++)
		{
			prob += pre[j].second*1/6.0;
		}
		pair<int,double> temp = {i, prob};
		res.push_back(temp);
	}
	
	for(int i = first_bound + 1; i < second_bound; i++)
	{
		int begin = i - n - 6;
		double prob = 0.0;
		for(int j = 0; j < 6; j ++)
		{
			prob += pre[begin+j].second *1/6.0;
		}
		pair<int,double> temp = {i, prob};
		res.push_back(temp);
	}
	print(res);
	
	cout << "-----------------"<<endl;
	for(int i = second_bound; i <= 6*(n+1); i++)
	{
		double prob = 0.0;
		int begin = pre.size() - len;
		cout << "begin:" << begin <<endl;
		cout << "len:" << len << endl;
		cout << "----------------" << endl;
		for(int i = 0; i < len; i++)
		{	
			prob += pre[begin+i].second * 1/6.0;
			cout << "prob: " << prob << endl;
		}
		cout << "-----------------" << endl;
		pair<int,double> temp = {i, prob};
		res.push_back(temp);	
		len--;
	}
	print(res);
	return res;
}



void print(vector<pair<int, double>> & num_prob){
	for (auto i: num_prob)
	{
		print(i);
	}
}

void print(pair<int, double> &one_two) 
{
	cout << one_two.first << ", " << one_two.second << endl;
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
void print(vector<string> & num)
{
	cout << "[";
	for(auto i = num.begin(); i != num.end(); i++)
	{
		cout << *i << " ";
	}
	cout << "]";
}


