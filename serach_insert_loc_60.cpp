#include<iostream>
#include <vector>
using namespace std;

// Given a sorted array and a target value,
// return the index if the target is found. 
// If not, return the index where it would 
// be if it were inserted in order.
/*
 * test example
 * [1,3,5,6], 5 → 2
 * [1,3,5,6], 2 → 1
 * [1,3,5,6], 7 → 4
 * [1,3,5,6], 0 → 0
*/

int searchInsert(vector<int> &A, int target);

int main()
{
	vector<int> a = {1,3,5,6};
	int loc = searchInsert(a, 2);
	cout << loc << endl;
}

int searchInsert(vector<int> &A, int target)
{
	int low = 0;
	int high = A.size() - 1;
	int mid = (low + high)/2;
	while(low <= high)
	{
		if(target <= A[mid])
		{
			high = mid - 1;
			mid = (low + high)/2;
		}
		else{
			low = mid + 1;
			mid = (low + high)/2;
		}
	}
	return high + 1;
}