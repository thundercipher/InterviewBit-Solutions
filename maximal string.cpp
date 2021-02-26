void maximal(string A, int B, string &m)
{
    if(B == 0)
    {
        return;
    }
    
    int n = A.size();
    
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n-1; j++)
        {
            if(A[j] > A[i])
            {
                swap(A[i],A[j]);
                
                if(A > m)
                {
                	m = A;
				}
                
				maximal(A,B-1,m);
                swap(A[i],A[j]);
            }
        }
    }
}

string Solution::solve(string A, int B) 
{
    string m = A;
    maximal(A,B,m);
    
    return m;
}

