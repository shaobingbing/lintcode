vector<ListNode*> binaryTreeToLists(TreeNode* root) {
        // Write your code here
        vector<ListNode *> result;
        if(!root) return result;
        TreeNode *t = root;
        queue<TreeNode *> q;
        q.push(t);
        vector<vector<int>> res;
        while(!q.empty())
        {
            int n = q.size();
            vector<int> temp;
            for(int i = 0; i < n; i++)
            {
                TreeNode *s = q.front();
                q.pop();
                if(s->left) q.push(s->left);
                if(s->right) q.push(s->right);
                temp.push_back(s->val);
            }
            res.push_back(temp);
        }
        

        for(int i = 0; i < res.size(); i++)
        {
            ListNode *head = new ListNode(res[i][0]);
            ListNode *l = head;
            for(int j = 1; j < res[i].size(); j ++)
            {
                ListNode *temp = new ListNode(res[i][j]);
                temp->next = l->next;
                l->next = temp;
                l = l ->next;
            }
            result.push_back(head);
        }
        return result;