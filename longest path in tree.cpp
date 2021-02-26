#include<bits/stdc++.h>

class graph
{
    int v;
    list<int> *adj;
    
    public: 
        
        graph(int n)
        {
            v = n;
            adj = new list<int>[n];
        }
        
        void addEdge(int a, int b)
        {
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
        pair<int,int> bfs(int s)
        {
            int dist[v];
            memset(dist,-1,sizeof(dist));
            
            dist[s] = 0;
            
            queue<int> q;
            q.push(s);
            
            while(!q.empty())
            {
                int node = q.front();
                q.pop();
                
                for(auto it = adj[node].begin(); it != adj[node].end(); it++)
                {
                    if(dist[*it] == -1)
                    {
                        q.push(*it);
                        dist[*it] = dist[node] + 1; 
                    }
                }
            }
            
            int longestpath=INT_MIN;
            int index;
            
            for(int i=0; i<v; i++)
            {
                int path = dist[i];
                
                if(path > longestpath)
                {
                    longestpath = path;
                    index = i;
                }
            }
            
            return make_pair(index,longestpath);
        }
        
        int findPath(int root)
        {
            pair<int,int> p1, p2;
            
            p1 = bfs(root);				//this will give the farthest node from the root and its distance
            p2 = bfs(p1.first);			//first is index, second is the longest path for that index
            
            return p2.second;
        }
};

int Solution::solve(vector<int> &A) 
{
    int n = A.size();
    
    if(n == 1)
    {
        return 0;    
    }
    
    int root;
    
    for(int i=0; i<n; i++)
    {
        if(A[i] == -1)
        {
            root = i;
        }
    }
    
    graph g(n);
    
    for(int i=0; i<n; i++)
    {
        if(A[i] != -1)
        {
            g.addEdge(i,A[i]);
        }
    }
    
    int path = g.findPath(root);
    
    return path;
}

