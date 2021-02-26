Node* preorder(Node* root)
{	
	if(root->left==NULL && root->right==NULL)
	{
		return root;
	}

	else if(root->left!=NULL && root->right==NULL)
	{
		root = root->left;
		root->left = NULL;
		
		return root;
	}
	
	else if(root->left==NULL && root->right!=NULL)
	{
		root = root->right;
		root->right = NULL;
		
		return root;
	}
	
	else
	{
		preorder(root->left);
		preorder(root->right);
	}
	
	return root;
}

Node* solution(Node* root, int n)
{	
	return preorder(root);
}
