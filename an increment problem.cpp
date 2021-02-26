vector<int> solution(vector<int> A)
{
	int n = A.size();
	vector<int> res = A;
	
	map<int,int> m;
	
	for(int i=0; i<n; i++)
	{
		m[A[i]]++;
	}
	
	for(int i=0; i<n; i++)
	{
		if(m[A[i]] > 1)
		{
			res[i]++;
			m[A[i]] = 1;
		}
	}
	
	return res;
}
