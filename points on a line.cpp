int collinear(int x[], int y[], int n)
{
	if(n < 2)
	{
		return 1;
	}
	
	int res=0, parallel, overlap, temp;
	
	for(int i=0; i<n; i++)
	{
		unordered_map<pair<int,int>> s;
		parallel = temp = overlap = 0;
		
		for(int j=i+1; i<n; j++)
		{	
			if(x[i]==x[j] && y[i]==y[j])
			{
				overlap++;
			}
			
			if(x[i] == x[j])
			{
				parallel++;
			}
			
			else
			{
				int x_ = x[j]-x[i];
				int y_ = y[j]-y[i];
			
				int X = x_/_gcd(x_,y_);
				int Y = y_/_gcd(x_,y_);
			
				s[make_pair(Y,X)]++;
				temp = max(temp, s[make_pair(Y,X)]);	
			}
			
			temp = max(temp,parallel);
		}
		
		res = max(res,temp+overlap+1);
		s.clear();
	}
	
	return res;
}
