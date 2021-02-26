vector<int> distinct(vector<int> &A, int k)
{
	int n =  A.size();
	map<int,int> freq;
	vector<int> res;
	
	for(int i=0; i<k; i++)
	{
		if(freq[A[i]] == 0)
		{
			res[0]++;
		}
		
		freq[A[i]]++;
	}
	
	int wcount=0;
	
	for(int i=k; i<n; i++)
	{
		wcount++;
		res[wcount] = res[wcount-1];
		
		if(freq[A[i-k]] == 1)
		{
			res[wcount]--;
		}
		
		freq[A[i-k]]--;
		
		if(freq[A[i]] == 0)
		{
			res[wcount]++;
		}
		
		freq[A[i]]++;
	}
	
	return res;
}
