/*
Given a string A, find the common palindromic sequence 
( A sequence which does not need to be contiguous and is a pallindrome), which is common in itself.

You need to return the length of longest palindromic subsequence in A.
*/

int sublen(string A)
{
	int n = A.length();
	int subL;
	int L[n][n];
	
	for(int i=0; i<n; i++)
	{
		L[i][i] = 1;
	}
	
	for(subL=2; subL<=n; subL++)
	{
		for(int i=0; i<n-subL+1; i++)
		{
			int j = i+subL-1;
			
			if(A[i]==A[j] && subL==2)
			{
				L[i][j] = 2;
			}
			
			else if(A[i] == A[j])
			{
				L[i][j] = L[i+1][j-1]+2;
			}
			
			else
			{
				L[i][j] = max(L[i+1][j],L[i][j-1]);
			}
		}
	}
	
	return L[0][n-1];
}
