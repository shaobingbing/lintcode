#include<vector>
#include<iostream>
#include<queue>
#include<stack>
#include<sstream>
#include<string>

using namespace std;

/*
 *	test demo:{1,3,#} -> {1,#,3}
 *	{1,2,3,#,#,4} -> {1,3,2,#,4}
 *	{99,1,88,1,1,88,7,#,#,#,91,#,#,#,6,77,#,#,5} ->{99,88,1,7,88,1,1,6,#,#,#,91,#,#,#,5,#,#,77}
 *   在此假设所有节点的值均大于0，以值为0代表空节点
*/
struct Node
{
	int val;
	Node *left;
	Node *right;
};

Node *build_tree(vector<int> &nums);
void bfs(Node *root);
void print(Node *root);
//交换左右子树位置
void invertBinaryTree(Node * root);
void invertBinaryTree_iterative(Node * root);
//中序遍历
void inOrderTraversal(Node *root, vector<int> &res);
void inOrderTraversal_iterative(Node *root, vector<int> &res);

//前序遍历
void preOrderTraversal(Node *root, vector<int> &res);
void preOrderTraversal_iterative(Node *root, vector<int> &res);

//最大深度
int max_depth(Node*);
int max_depth_iterative(Node*);

//路径搜索
void binaryTreePathSum(Node *root, vector<vector<int>> &res, vector<int>&path, int sum, int &target);
vector<string> binaryTreePaths(Node *);

//辅助函数
void print(vector<int> &s);
void print(vector<vector<int>> &s);
void print(vector<string> &s);
string vec_str(vector<int> &s);

int main()
{
	vector<int> a = {1,2,4,2,3};
	Node *root = build_tree(a);
	bfs(root);
	
	//cout << "------------before-----------" <<endl;
	//print(root);
	//cout << "------------inverse----------" << endl;
	//invertBinaryTree_iterative(root);
	//invertBinaryTree(root);
	
	//vector<int> inOrder;
	//inOrderTraversal(root, inOrder);
	//inOrderTraversal_iterative(root, inOrder);
	
	//vector<int> preOrder;
	//preOrderTraversal(root, preOrder);
	//preOrderTraversal_iterative(root, preOrder);
	//print(preOrder);
	
	//int depth = max_depth_iterative(root);
	//cout << depth << endl;
	vector<vector<int>> res;
	vector<int>path;
	int sum = 0;
	int target = 5;
	binaryTreePathSum(root, res, path, sum, target);
	print(res);
	
	//vector<string> s = binaryTreePaths(root);
	//print(s);
	
}

// 建树
Node *build_tree(vector<int> &nums)
{
	Node *root = new Node;
	root->val = 0;
	if(nums.empty())
	{
		root->left = NULL;
		root->right = NULL;
		return root;
	}
	int i = 0;
	queue <Node*> q;

	root->val = nums[i++];
	root->left = NULL;
	root->right = NULL;
	q.push(root);
	
	while(!q.empty())
	{
		Node *x = q.front();
		q.pop();
		if(i < nums.size())
		{
			int a = nums[i++];
			if(a != 0)
			{
				Node *left_node = new Node;
				left_node->left = NULL;
				left_node->right = NULL;
				left_node->val = a;
				x->left = left_node;
				q.push(left_node);
			}
		}
		if(i < nums.size())
		{
			int b = nums[i++];
			if( b!=0)
			{
				Node *right_node = new Node;
				right_node->left = NULL;
				right_node->right = NULL;
				right_node->val = b;
				x->right = right_node;
				q.push(right_node);
			}
		}
	}
	return root;
}

//bfs
void bfs(Node *root)
{
	Node *p = root;
	queue<Node*> q;
	cout << "{";
	if(root -> val == 0)
	{
		cout << "#";
		cout << "}" << endl;
		return;
	}
	q.push(p);
	Node *t = q.front();
	q.pop();
	cout << p->val;
	if(t->left)
	{
		q.push(t->left);
	}
	if(t->right)
	{
		q.push(t->right);
	}
	while(!q.empty())
	{
		t = q.front();
		q.pop();
		cout << ", " << t->val;
		if(t->left)
		{
			q.push(t->left);
		}
		if(t->right)
		{
			q.push(t->right);
		}
	}
	cout << "}"<<endl;
}	

void print(Node * root)
{
	Node *temp = root;
	if(temp->val == 0)
	{
		cout << "{#}"<<endl;
		return;
	}
	cout << "{";
	cout << temp->val;
	queue<Node*> q;
	q.push(temp);
	while(!q.empty())
	{
		Node *p = q.front();
		q.pop();
		if(p->left)
		{
			cout << ", " <<p->left->val;
			q.push(p->left);
		}
		else
		{
			cout << ", #";
		}
		if(p->right)
		{
			cout << ", " <<p->right->val;
			q.push(p->right);
		}
		else
		{
			cout << ", #";
		}
	}
}

//迭代算法,借助队列实现
void invertBinaryTree_iterative(Node * root)
{
	Node *temp = root;
	if(temp->val == 0)
	{
		return;
	}
	queue<Node*>q;
	q.push(temp);
	while(!q.empty())
	{
		Node *p = q.front();
		q.pop();
		Node *p_left = p->left;
		Node *p_right = p->right;
		if(p_left)
		{
			q.push(p_left);
		}
		if(p_right)
		{
			q.push(p_right);
		}
		Node *p_temp = p_left;
		p->left = p->right;
		p->right = p_temp;
	}
}

//递归实现
void invertBinaryTree(Node * root)
{
	Node *t = root;
	if(t->val == 0)
		return;
	if(t->left || t->right)
	{
		Node *temp = t->left;
		t->left = t->right;
		t->right = temp;
	}
	if(t->left)
	{
		invertBinaryTree(t->left);
	}
	if(t->right)
	{
		invertBinaryTree(t->right);
	}
}

void inOrderTraversal(Node *root, vector<int> &res)
{
	Node *t = root;
	if(t->val == 0)
		return;
	if(root->left)
	{
		inOrderTraversal(root->left,res);
	}
	res.push_back(root->val);
	if(root->right)
	{
		inOrderTraversal(root->right, res);
	}
}

//迭代实现，需要借助栈来实现
void inOrderTraversal_iterative(Node *root, vector<int>&res)
{
	stack<Node *>s;
	if(root->val == 0)
		return;
	Node *x = root;
	while(x || !s.empty())
	{
		while(x)
		{
			s.push(x);
			x = x->left;
		}
		if(!s.empty())
		{
			res.push_back(s.top()->val);
			x = s.top()->right;
			s.pop();
		}
	}
}

void preOrderTraversal(Node *root, vector<int> &num)
{
	Node *temp = root;
	if(temp->val == 0) return;
	num.push_back(temp->val);
	if(temp->left) preOrderTraversal(temp->left, num);
	if(temp->right) preOrderTraversal(temp->right, num);
}

void preOrderTraversal_iterative(Node *root, vector<int> &num)
{
	stack<Node *>s;
	if(root->val == 0)
		return;
	Node *x = root;
	while(x || !s.empty())
	{
		while(x)
		{
			num.push_back(x->val);
			s.push(x);
			x = x->left;
		}
		if(!s.empty())
		{
			x = s.top()->right;
			s.pop();
		}
	}
}

int max_depth(Node * root)
{
	if (!root || root->val == 0) return 0;
    return 1 + max(max_depth(root->left), max_depth(root->right));
}

int max_depth_iterative(Node *root)
{
	if(root->val == 0) return 0;
	queue<Node*> q;
	int depth = 0;
	q.push(root);
	while(!q.empty())
	{
		depth++;
		for(int i = 0; i < q.size(); i++)
		{
			Node *t = q.front();
			if(t->left)
			{
				q.push(t->left);
			}
			if(t->right)
			{
				q.push(t->right);
			}
			q.pop();
		}
	}
	return depth;
}

void binaryTreePathSum(Node *root, vector<vector<int>> &res, vector<int>&path, int sum, int &target)
{
	if(!root || root->val == 0) return;
	path.push_back(root->val);
	sum = sum + root->val;
	if(root->left == NULL && root->right == NULL && sum == target)
	{
		res.push_back(path);
	}

	if(root->left)
		binaryTreePathSum(root->left, res, path, sum, target);		
	if(root->right)
		binaryTreePathSum(root->right, res, path, sum, target);
	
	path.pop_back();
}

//可根据前序遍历的思想来解答本地,(没有完成该部分，因为前序遍历保证不重复，如何将这部分数据保存下来，将其存放到path里，
vector<string> binaryTreePaths(Node* root)
{
	vector<string> res;
	Node *t = root;
	if(t->val == 0) return res; 
	stack<Node *> s;
	Node *pre;
	vector<int> path;
	while(t || !s.empty())
	{
		Node *pre = t;
		while(t)
		{
			path.push_back(t->val);
			s.push(t);
			t = t->left;
		}
		
		string temp = vec_str(path);
		cout << temp << endl;
		res.push_back(temp);
		
		if(!s.empty())
		{
			t = s.top()->right;
			path.pop_back();
			s.pop();
		}
	}
	return res;	
}

void print(vector<int> &s)
{
	if(s.empty())
	{
		cout << "[]" << endl;
	}
	cout <<"[" << s[0];
	for(int i = 1; i < s.size(); i++)
	{
		cout << ", " << s[i];
	}
	cout << "]" << endl;
}

void print(vector<vector<int>> &num)
{
	cout << "[";
	for (int i =0; i < num.size(); i++)
	{
		print(num[i]);
	}
	cout << "]";
}	

void print(vector<string> &s)
{
	cout << "[";
	for(int i = 0; i < s.size(); i++)
		cout << "\"" << s[i] << "\"";
	cout << "]";
}

string vec_str(vector<int> &s)
{
	ostringstream oos;
	oos << s[0];
	for(int i = 1; i < s.size(); i++)
	{
		oos << "->" << s[i];
	}
	return oos.str();
}
