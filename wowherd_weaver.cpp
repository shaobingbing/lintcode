#include<string>
#include<vector>
#include<iostream>
using namespace std;
void print(vector<int> &a);

void findHer(vector<string> &maze, vector<vector<bool>> mark,vector<vector<int>>,int x_1, int y_1, int x_2, int y_2, int len, int width);
int main()
{
	vector<string> a = {"....*",".....",".....","*S**.","T**.*"};
	findHer(a);
	int len = a.size();
	int width = a[0].size();
	int x_1,y_1, x_2, y_2;
	vector<vector<bool>> mark;
	for(int i = 0; i < len; i++)
	{
		for(int j = 0; j < width; j++)
		{
			mark = false;
			if(a[i][j] == 'S')
			{
				x_1 = i;
				y_1 = j;
			}
			if(a[i][j] == 'T')
			{
				x_2 = i;
				y_2 = j;
			}
		}
	}
	vector<vector<int>> path;
	vector<vector<int>> res = findHer(a, mark, path, x_1, y_1, x_2, y_2, len, width); 
}

void findHer(vector<string> &maze,vector<vector<int>>path, vector<vector<bool>> mark, int x_1, int y_1, int x_2, int y_2, int len, int width)
{
	if(x_1 < 0 || x_1 >= len || y_1 < 0 || y_1 >= len) return;
	if(maze[x_1][y_1] == '*' || mark[x_1, y_1) 
	{
		mark[x_1][y_1] = true;
		return;
	}
	vector<int> a;
	a.push_back(x_1);
	a.push_back(x_2);
	path.push_back(a);
	for(int dr = -1; dr <= 1; dr++)
		for(int dc = -1; dc <= 1; dc++)
			if(dr != 0 || dc != 0)
					
}


void print(vector<int> &a)
{
	cout << "[" << a[0];
	for(int i = 1; i < a.size(); i++)
	{
		cout << ", " << a[i];
	}
	
	cout << "]" << endl;
}