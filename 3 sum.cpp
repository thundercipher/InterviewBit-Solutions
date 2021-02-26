int Solution::threeSumClosest(vector<int> &A, int B) 
{
    int l, r, temp, mindiffsum, mindiff=INT_MAX;
    vector<int> a = A;
    int n = A.size();
    
    sort(a.begin(),a.end());
    
    for(int i=0; i<n-2; i++)
    {
        l = i+1;
        r = n-1;
        int sum;
        
        while(l<r)
        {
            sum = a[i] + a[l] + a[r];
            
            if(sum < B)
            {
                l++;
                temp = abs(B-sum);
            }
            
            else if(sum > B)
            {
                r--;
                temp = abs(sum-B);
            }
            
            else if(sum == B)
            {
                return B;
            }
        }
        
        if(temp < mindiff)
        {
        	mindiff = temp;
        	mindiffsum = sum;
		}
    }
    
    return mindiffsum;
}

