#include<iostream>
#include<vector>

using namespace std;

void merge_sort(vector<int> &, int, int);
void quick_sort(vector<int> &, int, int);
void heap_sort(vector<int> &);
int partion(vector<int> &, int start, int end);
void merge(vector<int>&nums, int start, int mid, int end);

void print(vector<int> &);

int main()
{
	vector<int> a = {3,2,1,4,5};
	print(a);
	merge_sort(a, 0, 4);
	print(a);
}

void merge_sort(vector<int> &nums, int begin,int end)
{	if(begin == end|| nums.empty()) return;
	int mid = (begin + end)/2;
	merge_sort(nums, begin, mid);
	merge_sort(nums, mid+1, end);
	merge(nums, begin, mid, end);
}

void merge(vector<int>&nums, int start, int mid, int end)
{
	vector<int> left(nums.begin() + start, nums.begin() + mid + 1);
	vector<int> right(nums.begin() + mid + 1, nums.begin() + end + 1);
	int i = 0;
	int j = 0;
	int k = start;
	while(i < left.size() || j < right.size())
	{
		if(i == left.size())
		{
			nums[k++] = right[j++];
			continue;
		}
		if(j == right.size())
		{
			nums[k++] = left[i++];
			continue;
		}
		if(left[i] <= right[j])
		{
			nums[k++] = left[i++];
			continue;
		}
		if(left[i] > right[j])
		{
			nums[k++] = right[j++];
			continue;
		}
	}
}


void quick_sort(vector<int> &sum, int start,int end)
{
	if (start < end)
	{
		int q = partion(sum, start, end);
		quick_sort(sum, start, q - 1);
		quick_sort(sum, q + 1, end);
	}
}

int partion(vector<int> &nums, int start, int end)
{
	int i = start - 1;
	int piv = nums[end];
	for(int j = start; j < end; j++)
	{
		if(nums[j] <= piv)
		{
			i++;
			swap(nums[j], nums[i]);
		}
	}
	swap(nums[i+1], nums[end]);
	return i + 1;
}

void heap_sort(vector<int>&)
{
	return;
}

void print(vector<int> &s)
{
	cout << "[" << s[0];
	for(int i = 1; i < s.size(); i++)
	{
		cout << ", " << s[i];
	}
	cout << "]" << endl;
}