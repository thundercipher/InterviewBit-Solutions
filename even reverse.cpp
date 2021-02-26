
	ListNode* evenRev(ListNode* A)
	{
		int n=0;
		ListNode* temp = A;
		
		while(temp != NULL)
		{
			n++;
			temp = temp->next;
		}
		
		if(n < 4)
		{
			return A;
		}
		
		else
		{
			stack<int> s;
			int count=1;
			ListNode* temp1 = A;
			
			while(temp1->next != NULL)
			{
				temp1 = temp1->next;
				count++;
				
				if(count%2 == 0)
				{
					s.push(temp1->val);
				}
			}
			
			ListNode* temp2 = A;
			int c=1;
			
			while(temp2->next != NULL)
			{
				c++;
				temp2 = temp2->next;
				
				if(c%2 == 0)
				{
					temp2->val = s.top();
					s.pop();
				}
			}
			
			return A;
		}
	}
