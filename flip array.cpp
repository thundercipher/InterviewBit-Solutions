int isSubsetSum(vector<int>& set, int n, int sum) 
{ 
    bool subset[sum + 1][n + 1]; 
    int count[sum + 1][n + 1]; 
     
    for(int i=0; i<=n; i++) 
    { 
        subset[0][i] = true; 
        count[0][i] = 0; 
    } 
        
    for(int i=1; i<=sum; i++) 
    { 
        subset[i][0] = false; 
        count[i][0] = INT_MAX/2; 
    } 
     
    for(int i=1; i<=sum; i++) 
    { 
        for(int j=1; j<=n; j++) 
        { 
            subset[i][j] = subset[i][j - 1]; 
            count[i][j] = count[i][j - 1]; 
                
			if(i >= set[j-1]) 
            { 
                subset[i][j] = subset[i][j] || 
                subset[i - set[j - 1]][j - 1]; 
 
                if(subset[i][j]) 
                    count[i][j] = min(count[i][j - 1], 
                                    
					count[i - set[j - 1]][j - 1] + 1); 
            } 
        } 
    } 
 
    return count[sum][n]; 
} 

int Solution::solve(const vector<int> &nums) 
{
    // memset(t,-1,sizeof(t));
    int sum=0;
    vector<int> a = nums;
    int n = a.size();
    
	for(int i=0;i<a.size();i++)
    	sum+=a[i];
    
	int t[n+1][sum+1];
    int count[sum + 1][n + 1]; 
    
	for(int i=0;i<=sum;i++)
  		t[0][i]=0;
  	
	for(int i=0;i<=n;i++)
  		t[i][0]=1;

  	for(int i=1;i<=n;i++)
  	{
      	for(int j=1;j<=sum;j++)
      	{
          	if(j>=a[i-1])
              	t[i][j]=t[i-1][j-a[i-1]]||t[i-1][j];
          	
			  else
          		t[i][j]=t[i-1][j];  
      	}
  	}

    int mn=INT_MAX;
    
	for(int i=sum/2;i>=0;i--)
    {
        if(t[n][i]==1)
        {
			mn=i;
        	break;        
        }
    }
    
	int ans=INT_MAX;
    int s=(sum+mn)/2;
    
    return isSubsetSum(a,n,mn);
}
