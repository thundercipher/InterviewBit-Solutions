/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::solve(ListNode* A) 
{
    ListNode* odd=A,even=A->next,prev=NULL;
    
	while(odd!=NULL && even!=NULL)
    {
     	odd->next = even->next;   
     	even->next = prev;
     	prev = even;
     	odd = odd->next;
     
	 	if(odd)
     		even=odd->next;
    }
    
	ListNode * tmp1=A,tmp2=A->next,tmp=prev;
    
	while(tmp2!=NULL)
    {
        tmp1->next = prev;
        tmp = prev->next;
        prev->next = tmp2;
        prev = tmp;
        tmp1 = tmp2;
        tmp2 = tmp2->next;
    }
    
    if(prev!=NULL)
    	tmp1->next=prev;
    
	return A;
}
