
	if(root == NULL || (root->left == NULL && root->right == NULL))
	{
		return root;
	}
	
	if(root->left != NULL)
	{
		flatten(root->left);
	
		Node* temp = root->right;
		root->right = root->left;
		root->left = NULL;
	
		Node* t = root->right;
	
		while(t->right != NULL)	
		{
			t = t->right;
		}
	
		t->right = temp;
	
	}
	
	flatten(root->right);
