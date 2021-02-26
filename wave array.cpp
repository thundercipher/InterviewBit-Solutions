vector<int> solution(vector<int> &A)
{
	int n = A.size();	
	vector<int> temp = A;
	sort(temp.begin(),temp.end());
	
	int count=0;
	
	for(int i=0; i<n-1; i++)
	{
		if(count%2 == 0)
		{
			int t = temp[i];
			temp[i] = temp[i+1];
			temp[i+1] = t;
		}
		
		count++;
	}
	
	return temp;
}
