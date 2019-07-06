#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;


void print(vector<int> &s);
int getPeak(vector<int> &s);
int search_rotate_array(vector<int> &s, int target); 
int findMin(vector<int> &nums);
bool search_rotate_array_dup(vector<int>&s, int);

/**	 	玩游戏
  *		题目描述
  *		n个人在玩游戏，每局有一个裁判和n-1个玩家，数组A表示每个人都想当玩家至少Ai(0=<i<n)次。请你求出最小需要进行游戏的数量。
  *		分析：进行游戏的数量的范围在0-max(A[i]),让max(A[i])个人分别当玩家，此时最大次数为max(A[i])
  *		经过分析可知，假如进行游戏n次，那么每个人最多当裁判的次数为n-A[i],总共玩家当裁判的次数应该为n，找到使其求和等于n的值即是最优解。
 **/
long long play_games(vector<int>&);


int main()
{
	
}

int findMin(vector<int> &nums) {
        // write your code here
	if(nums[0] <= nums[nums.size() - 1]) return 0;
	int left = 0;
	int right = nums.size() - 1;
	while(left < right)
	{
		int mid = (left + right) /2;
		if(nums[mid] > nums[mid+1]) return mid + 1;
		if(nums[left] < nums[mid]) left = mid + 1;
		else right = mid-1;
	}
}
	
	
bool search_rotate_array_dup(vector<int>&A, int target)
{
	int left = 0;
	int right = A.size() -1;
	while(left <= right)
	{
		int mid = (left + right) / 2;
		if(A[mid] == target) return true;
		if(A[mid] < A[right])
		{
			if(target > A[mid] && target <= A[right])
				left = mid + 1;
			else
				right = mid - 1;
		}
		else if(A[mid] > A[left])
		{
			if(target >= A[left] &&  target < A[mid]) right = mid - 1;
			else left = mid + 1;
		}
		else --right;
	}
	return false;
}



long long play_games(vector<int> &A)
{
	int l = 0;
	int t = 0;
	for(int i = 0; i < A.size(); i++)
	{
		if(A[i] > t)
		{
			t = A[i];
		}
	}
	int r = t * 2;
	while(l <= r)
	{
		int mid = (l + r)/2;
		long long cnt = 0;
		for(int i = 0; i < A.size(); i++)
		{
			cnt += max(mid - A[i], 0);
		}
		if(cnt > mid)
		{
			l = mid + 1;
		}
		else
		{
			r = mid - 1;
		}
	}
		
		return max(l,t);
}
int search_rotate_array(vector<int> &s, int target)
{
	int left = 0;
	int right = s.size() - 1;
	while(left <= right)
	{
		int mid = (left + right) / 2;
		if(s[mid] == target) return mid;
		if(s[left] <= s[right])
		{
			if(target > s[mid])
			{
				left = mid + 1;
			}
			else
			{
				right = mid - 1;
			}
		}
		
		else
		{
			if(s[mid] == s[left])
			{
				if(s[right] == target) return right;
				else return -1;
			}
			else if(s[mid] > s[left])
			{
				if(target < s[mid])
				{
					if(target > s[right]) right = mid - 1;
					else left = mid + 1;
				}
				else
				{
					left = mid + 1;
				}
			}
			else{
				if(target < s[mid])
				{
					right = mid - 1;
				}
				else
				{
					if(target < s[left])
					{
						left = mid + 1;
					}
					else right = mid - 1;
				}
			}
		}
	}
	
	return -1;
	
}

int getPeak(vector<int> &s)
{
	if(s.empty() || s.size() < 3) return -1;
	if(s.size() == 3) return s[1];
	int left = 1;
	int right = s.size() - 2;
	while(left < right)
	{
		int mid = (left + right) / 2;
		if(s[mid] > s[mid +1])
			right = mid;
		left = mid + 1;
	}
	cout << "loc:" << left << endl;
	return s[left];
}

void print(vector<int> &s)
{
	cout << "[" << s[0];
	for(int i = 1; i < s.size(); i++)
	{
		cout << "," << s[1];
	}
	cout << "]" << endl;
}