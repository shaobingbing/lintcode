#include<vector>
#include<iostream>

using namespace std;


vector<vector<int>> multiSort(vector<vector<int>> &array) {
	// Write your code here
	sort(array.begin(), array.end(), cmp);
	return array;
}

static bool cmp(vector<int> A, vector<int> B)
{
	if(A[1] != B[1])
	{
		return A[1] > B[1];
	}
	return A[0] < B[0];
}