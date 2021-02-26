string bin(int x)
{
	unsigned i;
	string res = "";
	
	for(i=1<<31; i>0; i=i/2)
	{
		if(x&i)
		{
			res += '1';
		}
		
		else
		{
			res += '0';
		}
	}
	
	return res;
}

int flipped(int x)
{
	string init = bin(x);
	reverse(init.begin(),init.end());
	
	int res=0;
	int n = init.length();
	int j=0;
	
	for(int i=n-1; i>=0; i--)
	{
		res += pow(2,j)*(init[i] - '0');
		j++;
	}
	
	return res;
}
