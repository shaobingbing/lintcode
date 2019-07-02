#include<iostream>
#include<vector>
using namespace std;

struct ListNode
{
	ListNode * next;
	int value;
};

ListNode* input_linkedList(ListNode*, vector<int>&);
void print(ListNode *);
ListNode *find_mid_listNode(ListNode*head);

int main()
{
	vector<int> a{};
	ListNode *head = new ListNode;
	input_linkedList(head, a);
	if(head -> next == NULL)
	{
		cout << "-1";
		return 0;
	}
	print(head);
	ListNode* mid = find_mid_listNode(head);
	cout << "--------------" << endl;
	cout << mid->value << endl;
	return 0;
}

ListNode* input_linkedList(ListNode *head, vector<int> &nums)
{
	ListNode *p = head;
	head->next = NULL;
	for(int i = 0; i < nums.size(); i++)
	{
		ListNode* q = new ListNode;
		q->value = nums[i];
		q->next = p->next;
		p->next = q;
		p = q;
	}
	
	return head;
}

void print(ListNode* head)
{
	ListNode *q = head->next;
	if(q!=NULL)
	{
		cout << q->value;
		q = q->next;
	}
	while(q!=NULL)
	{
		cout << " -> " << q->value;
		q = q->next;
	}
	cout << endl;
}

ListNode* find_mid_listNode(ListNode*head)
{
	ListNode * low = head;
	ListNode * fast = head;
	while(low!= NULL && fast!=NULL)
	{
		if(fast->next == NULL)
		{
			return low;
		}
		low = low->next;
		fast = fast->next->next;
	}
	return low;
}
