#include<vector>
#include<iostream>
#include<string>
using namespace std;

bool findHer(vector<string> &maze);
void isExist(vector<string> &maze,vector<vector<bool>> &mark, int x_1, int y_1, int &x_2, int &y_2,int &len, int &width);

int main()
{
	vector<string> a = {"....*",".....",".....","*S**.","T**.*"};
	
	bool x = findHer(a);
	if(x)
		cout << "True" << endl;
	else
		cout << "False" << endl;
	return 0;
}

bool findHer(vector<string> &maze) {
	// Write your code here
	int height = maze.size();
	int width = maze[0].size();
	int x_1, x_2, y_1, y_2;
	vector<vector<bool>> mark;
	for(int i = 0; i < height; i++)
	{
		vector<bool>temp;
		for(int j = 0; j < width; j ++)
		{
			if(maze[i][j] == 'S')
			{
				x_1 = i;
				y_1 = j;
			}
			if(maze[i][j] == 'T')
			{
				x_2 = i;
				y_2 = j;
			}
			bool x = false;
			temp.push_back(x);
		}
		mark.push_back(temp);
	}
	
	isExist(maze, mark, x_1, y_1, x_2, y_2, height, width);
	if(mark[x_2][y_2]) return true;
	return false;
}

void isExist(vector<string> &maze,vector<vector<bool>> &mark, int x_1, int y_1, int &x_2, int &y_2,int &len, int &width)
{
	if(x_1 < 0 || x_1 >= len || y_1 < 0 || y_1 >= width) return ;
	if(x_1 == x_2 && y_1 == y_2) 
	{	
		mark[x_1][y_1] = true;
		return;
	}
	if(maze[x_1][y_1] == '*') 
	{
		
		mark[x_1][y_1] = true;
		return;
	}
	if(mark[x_1][y_1] == true) return;
	mark[x_1][y_1] = true;
	for(int i = -1; i <= 1; i++)
		for(int j = -1; j <= 1; j ++)
			if(i !=0 || j !=0)
				isExist(maze, mark, x_1 + i, y_1 + j, x_2, y_2, len, width);
}