#include<vector>
#include<iostream>

using namespace std;

void reachEndpoint(vector<vector<int>> &map, int l, int h,vector<vector<bool>> &mark, bool &res);

int main()
{
	vector<vector<int>> map = {{1,1,1},{1,1,1},{1,1,9}};
	int height = map.size();
	int width = map[0].size();
	vector<vector<bool>> mark;
	for(int i = 0; i < height; i++)
	{
		vector<bool> temp;
		for(int j = 0; j < width; j++)
		{	
			temp.push_back(false);
		}
		mark.push_back(temp);
	}
	bool res = false;
	reachEndpoint(map, 0, 0, mark, res);
	if(res)
		cout << "can reach" << endl;
	else
		cout << "don't reach" << endl;
}

void reachEndpoint(vector<vector<int>> &map, int l, int h,vector<vector<bool>> &mark, bool &res)
{
	cout << "map[" << l << "]" << "[" << h << "]:" << endl;	
	int width = map[0].size();
	int height = map.size();
	if(l >= width || l < 0 || h >= height || h < 0) 
		return;
	if(mark[l][h] == true) 
	{
 		return;
	}
	if(map[l][h] == 0) 
	{
		mark[l][h] = true;
		return;
	}
	mark[l][h] = true;
	if(map[l][h] == 9) res = true;
	reachEndpoint(map, l + 1, h, mark,res);
	reachEndpoint(map, l - 1, h, mark,res);
	reachEndpoint(map, l, h + 1, mark,res);
	reachEndpoint(map, l, h - 1, mark,res);
	return;
}

