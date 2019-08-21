#include<vector>
#include<queue>
#include<iostream>
#include<string>
using namespace std;

struct TreeNode
{
	TreeNode *left;
	TreeNode *right;
	int val;
	TreeNode(int x):val(x), left(NULL), right(NULL){}
};

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

TreeNode* init_tree(vector<string> &s);
string to_string_s(int n);
int to_int(string &s);
vector<int> print_tree(TreeNode *root);

int main()
{
	vector<string> s = {"1","2","3","4"};
	TreeNode * root = init_tree(s);
	print_tree(root);
}

TreeNode* init_tree(vector<string> &s)
{
	TreeNode* root = new TreeNode;
	if(s.empty())
		return NULL;
	queue<TreeNode*> q;
	root->val = to_int(s[0]);
	int i = 0;
	while(i < s.size())
	{
		TreeNode* t = q.front();
		q.pop();
		if(s[i] != '#')
		{
			t->left = new TreeNode;
			t->left->value = to_int(s[i]);
			q.push(t->left);
		}
		i++;
		if(i = s.size()) break;
		if(s[i] !== '#')
		{
			t->left = new TreeNode;
			t->left->value = to_int(s[i]);
			q.push(t->left);
		}
	}
	return root;
}

vector<int> print_tree(TreeNode *root)
{
	TreeNode *t = root;
	queue<TreeNode *> q;
	q.push_back(t);
	vector<int> res;
	res.push_back(t->val);
	while(!q.empty())
	{
		TreeNode * temp = q.front();
		q.pop();
		if(temp->left)
		{
			q.push_back(temp->left);
			res.push_back(temp->left->val);
		}
		else res.push_back(0);
		if(temp->right)
		{
			q.push_back(temp->right);
		}
		else res.push_back(0);
	}
	return res;
}

string to_string_s(int n)
{
	if (n == 0)
	{
		char s[2];
		s[0] = '0';
		s[1] = '\0';
		return s;
	}
	char ch[100];
	char res[100];
	int i = 0;
	int j = 0;
	if (n < 0)
	{
		n = 0 - n;
		j = 1;
		res[0] = '-';
	}
	while(n!=0)
	{
		ch[i++] = n%10 + '0';
		n = n/10;
	}
	ch[i] = '\0';
	i = i - 1;
	while(i >= 0)
	{
		res[j++] = ch[i--];
	}
	
	res[j] = '\0';
	return res;
}

int to_int(string &s)
{
	int res = 0;
	int begin = 0;
	if (s[0] == '-')
	{
		begin = 1;
	}
	for(int i = begin; i < s.size(); ++i)
	{
		res = res*10 + (s[i] - '0');
	}
	if(begin == 1)
		return 0 - res;
	return res;
		
}
