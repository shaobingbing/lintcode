#include<iostream>

using namespace std;

int reachNumber(int target);
int main()
{
	int res = reachNumber(5);
	cout << res << endl;
}
int reachNumber(int target) {
	// Write your code here
	if (target == 0) return 0;
	if(target < 0) target = 0 - target;
	 int i = 1;
    	int sum = 1;
    	while(sum < target)
    	{
    		i++;
    		sum += i;
    	}
    	if(sum == target)
    	{
    	    return i;
    	}
        
        int diff = sum - target;
        int b = diff%2;
        if(b == 0)
            return i;
        sum = sum - i;
        if((target - sum)%2 == 1) return i + 1;
        return i + 2;
}