#include<iostream>
#include<vector>
using namespace std;
int singleNumber(vector<int> &A) {
	// write your code here
	int a = A[0]; 
	for (auto i = A.begin() +1; i != A.end(); i++)
	{
		a ^= *i;
	}	
	return a;
}

int main()
{
	vector<int> a{1,2,2,3,3};
	int b = singleNumber(a);
	cout << b<<endl;
	int c = 2;
	int d = 2;
	int x = c^d;
	cout << x<<endl;
	
	int y = c^0;
	cout << y << endl;
	int t = 1^2^2^3^3;
	cout << t << endl;
}
