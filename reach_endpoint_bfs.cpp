#include<vector>
#include<queue>
#include<iostream>

using namespace std;
bool reachEndpoint(vector<vector<int>> &map);
int main()
{
	vector<vector<int>> map = {{1,1,1,1,0,1},{0,1,0,0,0,0},{1,0,0,0,1,0},{0,0,1,1,1,0},{1,1,0,0,0,0},{1,9,1,1,0,0}};
	if(reachEndpoint(map))
		cout << "true" << endl;
	else	
		cout << "false" << endl;
}

bool reachEndpoint(vector<vector<int>> &map) {
	// Write your code here
	vector<vector<bool>> visited(map.size(), vector<bool>(map[0].size(), false));
	queue<vector<int>> q;
	q.push({0,0});
	visited[0][0] = true;
	while(!q.empty())
	{
		vector<int> temp = q.front();
		q.pop();
		vector<vector<int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};
		for(int i = 0; i < dir.size(); i++)
		{
			int a = temp[0] + dir[i][0];
			int b = temp[1] + dir[i][1];
			if(a >= map.size() || a < 0 || b >= map[0].size() || b < 0)
				continue;
			if(visited[a][b] == true) continue;
			if(map[a][b] == 9) return true;
			if(map[a][b] == 0) visited[a][b] = true;
			else
			{
				visited[a][b] = true;
				q.push({a,b});
			}
		}
	}
	
	return false;
}