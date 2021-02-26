
	vector<int> func(int a[], int b, int n)
	{
		vector<int> c;
		
		if(b>n)
		{
			int maxTemp = INT_MIN;
			
			for(int i=0; i<n; i++)
			{
				int cur = a[i];
				maxTemp = max(maxTemp,cur);
			}
			
			c.push_back(maxTemp);
			
			return c;
		}
		
		deque<int> dq(b);
		int i;
		
		for(i=0; i<b; i++)
		{
			while(!dq.empty() && a[dq.back()] <= a[i])
			{
				dq.pop_back();	 				//because we just need the largest element of any window
			} 
			
			dq.push_back(i);
		}
		
		for(; i<n; i++)
		{
			c.push_back(a[dq.front()]);			//front has the largest element of a window
			
			while(!dq.empty() && dq.front() <= i-b)
			{
				dq.pop_front();					//element not in the current window
			}
			
			while(!dq.empty() && a[dq.back()] <= a[i])
			{
				dq.pop_back();
			}
		
			dq.push_back(i);
		}
		
		c.push_back(a[dq.front()]);				//largest element of the last window
		
		return c;
	}
