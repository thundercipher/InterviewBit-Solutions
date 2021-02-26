ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) 
{
    ListNode* merged = NULL;
    
    if(A = NULL)
    {
        return B;
    }
    
    if(B = NULL)
    {
        return A;
    }
    
    if(A->val < B->val)
    {
        merged = A;
        mergeTwoLists(A->next,B);
    }
    
    else
    {
        merged = B;
        mergeTwoLists(A,B->next);
    }
    
    return merged;
}
