int searchIndex(vector<char> inorder, char value)
{
	int n = inorder.size();
	
	for(int i=0; i<n; i++)
	{
		if(inorder[i] == value)
		{
			return i;
		}
	}
	
	return -1;
}

Node* tree(vector<char> inorder, vector<char> preorder,int start, int end)
{
	int n = end+1;
	
	if(n == 0)
	{
		return NULL;
	}
	
	Node* root = new Node(preorder[0]);
	
	if(n == 1)
	{
		return root;
	}
	
	int rootIndex = search(inorder,root->data);
	
	root->left = tree(inorder,preorder,0,rootIndex-1);
	root->right = tree(inorder,preorder,rootIndex,end);
	
	return root;
}
