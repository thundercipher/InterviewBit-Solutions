vector<int> cousins(Node* root, int key)
{
	vector<int> res;
	queue<Node*> q;
	
	q.push(root);
	int level=INT_MAX, curr=0;
	
	while(!q.empty())
	{
		int n = q.size();
		
		while(x--)
		{
			Node* temp = q.front();
			q.pop();
			
			if(temp>left&&temp->left->data==key || temp->right&&temp->right->data==key)
			{
				level = curr+1;
			}
			
			else
			{
				if(temp->left)
				{
					q.push(temp->left);
				}
				
				if(temp->right)
				{
					q.push(temp->right);
				}
			}
		}
		
		curr++;
		
		if(curr >= level)
		{
			break;
		}
	}
	
	while(!q.empty())
	{
		Node* temp = q.front();
		q.pop();
		
		res.push_back(temp->data);
	}
	
	return res;
}
