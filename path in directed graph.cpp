#include<bits/stdc++.h>

void dfsUtil(int s, bool visited[], list<int> *adj)
{
    visited[s] = true;
	list<int>::iterator it;
			
	for(it = adj[s].begin(); it != adj[s].end(); ++it)
	{
	    if(visited[*it] == false)
		{
			dfsUtil(*it,visited,adj);
		}
	}
}

int dfs(int s, list<int> *adj, int n)
{
    bool *visited = new bool[n];
			
	for(int i=0; i<n; i++)
	{
		visited[i] = false;
	}
			
	dfsUtil(s,visited,adj);
	
	if(visited[n-1])
	{
	    return 1;
	}
	
	return 0;
}

int Solution::solve(int A, vector<vector<int> > &B) 
{
    list<int> *adj = new list<int>[A];
    int e = B.size();
    
    for(int i=0; i<e; i++)
    {
        adj[B[i][0]-1].push_back(B[i][1]-1);
    }
    
    int res = dfs(0,adj,A);
    
    if(res)
    {
        return 1;
    }
    
    return 0;
}

