#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Interval{
	int begin;
	int end;
};

int getAns(vector<Interval> &a);
static bool cmp(Interval a, Interval b);
void print(vector<Interval> &);
void print(vector<int> &);

// test demo
// {{27,74},{25,65},{8,36},{21,63},{18,20},{35,51},{55,86},{49,69},{79,89}} ==> 3
// {{1,5}, {4,8}, {10, 12}} ==> 2
// {{1,5}, {4,8}, {5,12}} ==> 1
// [(7015,30303),(17382,25492),(22843,22946),(17141,22025),(1273,22271),(9911,16742)]
int main()
{
	vector<Interval> a = {{2,12},{6,11},{9,10},{5,7},{1,8},{3,4}};
	sort(a.begin(), a.end(), cmp);
	int num = getAns(a);
	cout << num << endl;
	vector<int> b = {7015,30303,17382,25492,22843,22946,17141,22025,1273,22271,9911,16742};
	sort(b.begin(), b.end());
	print(a);
	print(b);
}
int getAns(vector<Interval> &a) {
	// write your code here
	sort(a.begin(), a.end(), cmp);
	int left = 0;
	int right = 0;
	int sum_of_point = 0;
	while(right < a.size())
	{
		if(right == left)
		{
			sum_of_point += 1;
			right++;
			continue;
		}
		if(a[left].begin <= a[right].begin && a[left].end >= a[right].end)
		{
			left = right;
			right++;
			continue;
		}
		if(a[left].end < a[right].begin)
		{
			left = right;
			continue;
		}
		if(a[left].end >= a[right].begin)
		{
			right++;
		}
	}
	return sum_of_point;
}

static bool cmp(Interval a, Interval b)
{
	if (a.begin != b.begin)
		return a.begin < b.begin;
	return a.end < b.end;
}

void print(vector<Interval> &s)
{
	cout << "[" << "(" << s[0].begin << "," << s[0].end << ")";
	for(int i = 1; i < s.size(); i++)
	{
		cout << ", " << "(" << s[i].begin << "," << s[i].end << ")";
	}
	cout << "]" << endl;
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