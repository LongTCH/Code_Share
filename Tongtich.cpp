#include <iostream>
using namespace std;
int Sum = -999999;
void Try(int i, bool dup, int a[], int n, int S)
{
		if (dup) 
		{
			S+=a[i];
			if (i == n-1)
			{
				if (Sum < S) Sum = S;
			} else Try(i+1,false,a,n,S);
		}
		else 
		{
			S+=a[i];
			if (i == n-1)
			{
				if (Sum < S) Sum = S;
			} else Try(i+1,false,a,n,S);
			S = S - a[i] - a[i-1] + a[i]*a[i-1];
			if (i == n-1)
			{
				if (Sum < S) Sum = S;
			} else Try(i+1,true,a,n,S);
		}
		
}
int main()
{
	int a[] = {6,8,8,4,3};
	int n = sizeof(a) / sizeof(int);
	int dp[n+1]; dp[0]=0; dp[1]=a[0];
	int S = a[0];
	int i = 2;
	while (i <= n)
	{
		int p = dp[i-2] + a[i-2]*a[i-1];
		int q = dp[i-1] + a[i-1];
		if (p>=q) dp[i] = p;
		else dp[i] = q;
		++i;
	}
	Try(1,false,a,n,S);
	cout<<"Sum = "<<dp[n]<<endl;
	cout<<"Sum2 = "<<Sum;
	return 0;
}
