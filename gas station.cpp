int Solution::canCompleteCircuit(const vector<int> &A, const vector<int> &B) 
{
    int start = 0;
    int end = 1;
    int n = A.size();
    int gas = A[start] - B[start];
    
    if(n == 1)
    {
        if(A[0] >= B[0])
        {
            return 0;
        }
        
        else
        {
            return -1;
        }
    }
    
    while(start!=end || gas<0)
    {
        while(gas<0 && start!=end)
        {
            gas -= A[start] - B[start];
            start = (start+1)%n;
            
            if(start == 0)
            {
                return -1;
            }
        }
        
        gas += A[end] - B[end];
        end = (end+1)%n;
    }
    
    return start;
}

