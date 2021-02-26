/*
N = 23
2 3 23
2 -> 2
3 -> 3
23 -> 6
this number is a COLORFUL number since product of every digit of a sub-sequence are different. 

Output : 1
*/

int Solution::colorful(int A) 
{
    string s = to_string(A);
    int n = s.size();
    
    map<long long,bool> m;
    
    for(int i=0; i<n; i++)
    {
        long long prod = 1;
        
        for(int j=i; j<n; j++)
        {
            prod *= (long long)s[j]-'0';
            
            if(m.find(prod) != m.end())
            {
                return 0;
            }
            
            m[prod] = true;
        }
    }
    
    return 1;
}
