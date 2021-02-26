int depth(Node* root)
{
	if(root == NULL)
	{
		return 0;
	}
	
	else
	{
		int lheight = depth(root->left);
		int rheight = depth(root->right);
	
		if(lheight < rheight)
		{
			return (lheight+1);
		}
	
		else
		{
			return (rheight+1);
		}	
	}
}

int solution(Node* root)
{
	return depth(root);
}
