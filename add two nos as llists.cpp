
	ListNode *res, *prev, *temp = NULL;
	int carry=0, sum;
	
	while(A!=NULL && B!=NULL)
	{
		sum = carry + (A ? A->val : 0) + (B ? B->val : 0);
		carry = (sum>=10 ? 1 : 0);
		
		sum %= 10;
		
		temp = newNode(sum);
		
		if(!res)
		{
			res = temp;
		}
		
		else
		{
			prev->next = temp;
		}
		
		prev = temp;
		
		if(A)
		{
			A = A->next;
		}
		
		if(B)
		{
			B = B->next;
		}
	}
	
	if(carry>0)
	{
		temp->next = newNode(carry);
	}
	
	return res;
