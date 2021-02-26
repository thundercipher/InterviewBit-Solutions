

	int n=B.size();
  	vector<int> a=A, b=B, c=C;
  	
  	int mx = *max_element(a.begin(),a.end());
  	int t[n+1][mx+1];			//table t stores cost
  
    for(int i=0;i<=mx;i++)
  		t[0][i]=INT_MAX/2;		//for a plate with 0 capacity, infinite no. of such plates will be required for each person
  
  	for(int i=0;i<=n;i++)		//for a person with 0 capacity req, 0 capacity plates will suffice
  		t[i][0]=0;
  
  	for(int i=1;i<=n;i++)		
  	{
      	for(int j=1;j<=mx;j++)
      	{
          	if(j >= b[i-1])
          	{
              	t[i][j] = min(c[i-1]+t[i][j-b[i-1]], t[i-1][j]);
          	}
          	
			else
          		t[i][j] = t[i-1][j];
      	}
  	}
  	
  	int ans=0;
  
  	for(int i=0; i<a.size(); i++)
  		ans += t[n][a[i]];
  
  	return ans;
