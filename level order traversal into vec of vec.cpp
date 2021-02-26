 
 	vector<vector<int>> ans;
 	queue<TreeNode*> q;
 	
 	if(!root)
 	{
 		return ans;	
	}
	
	q.push(root);
	
	int i=0,s;
	
	while(!q.empty())
	{
		s = q.size();
		vector<int> row;
		
		while(s--)
		{
			TreeNode *temp = q.front();
			row.push_back(temp->val);
			
			q.pop();
			
			if(temp->left != NULL)
			{
				q.push_back(temp->left);
			}
			
			if(temp->right != NULL)
			{
				q.push_back(temp->right);
			}
		}
		
		ans.push_back(row);
		i++;
	}
	
	return ans;
