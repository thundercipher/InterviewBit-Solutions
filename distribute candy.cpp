#include<bits/stdc++.h>
using namespace std;

int candy(vector<int> A)
{
	int n = A.size();
	vector<pair<int,int>> assign;
	
	assign.push_back(make_pair(A[0],1));
	int temp = A[0];
	
	for(int i=1; i<n; i++)
	{
		if(temp < A[i])
		{
			temp = A[i];
			assign.push_back(make_pair(A[i],assign[i-1].second+1));
		}
		
		else
		{
			assign[i-1].second += 1;
			assign.push_back(make_pair(A[i],1));
		}
	}
	
	int res=0;
	
	for(int i=0; i<n; i++)
	{
		res += assign[i].second;
	}
	
	return res;
}

int main()
{
	vector<int> A = {1,2};
	int res = candy(A);
	
	cout<<res;
	
	return 0;
}
