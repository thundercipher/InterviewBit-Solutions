Tnode* listtobstrecur(Lnode** head, int n)
{
	if(n <= 0)
	{
		return NULL;
	}
	
	Tnode* l = listtobstrecur(head,n/2);
	
	Tnode* root = new Tnode(*head->data);
	root->left = l;
	*head = *head->next;
	root->right = listtobstrecur(head,n-n/2-1);
	
	return root;
}

Tnode* listtobst(Lnode* head)
{
	Lnode* t = head;
	int n=0;
	
	while(t->next != NULL)
	{
		n++;
		t = t->next;
	}
	
	return listtobstrecur(&head,n);
}
