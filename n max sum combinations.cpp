vector<int> Solution::solve(vector<int> &A, vector<int> &B) 
{
    int n = A.size();
    vector<int> res;
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            res.push_back(A[i]+B[j]);
        }
    }
    
    sort(res.begin(),res.end(),greater<int>());
    res.resize(n);
    
    return res;
}

