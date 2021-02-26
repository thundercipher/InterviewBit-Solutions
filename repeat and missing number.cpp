vector<int> solution(vector<int> A)
{
	int n = A.size();
	vector<int> res;
	
	//if it wasn't read-only (const) vector
	for(int i=0; i<n; i++)
	{
		if(A[abs(A[i])-1] > 0)
		{
			A[abs(A[i]-1)] = -A[abs(A[i]-1)];
		}
		
		else
		{
			res.push_back(abs(A[i]);
		}
	}
	
	for(int i=0; i<n; i++)
	{
		if(A[i]>0)
		{
			res.push_back(i+1);
		}
	}
	
	//for read-only vector use sum and product equations
	
	return res;
}
