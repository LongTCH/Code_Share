#include <iostream>
using namespace std;
int getmax(int a, int b)
{
	return (a>b)?a:b;
}
int main()
{
	int n, t, lmax=1, count=0;
	cin>>n;
	int a[n+1],len[n];
	a[n]=999999;
	for (int i=0; i<n; ++i) len[i]=1;
	for (int i=0; i<n; ++i) cin>>a[i];
	for (int i=1; i<n; ++i) 
	{
		if (a[i]-a[i-1] >=1) 
		{
			len[count]++;
		}
		else
		{
			count++;
		}
	}
	t=0;
	for (int i=0; i<=count; ++i) lmax=getmax(lmax,len[t]);
	for (int i=1; i<n; ++i)
	{
		if (a[i]-a[i-1]<1)
		{
			if ((i==1)?1:((a[i]-a[i-2]) >= 2) || a[i+1]-a[i-1]>=2) 
			{
				lmax=getmax(lmax,len[t]+len[t+1]);
			} 
			else
			{
				lmax=getmax( lmax, getmax(len[t],len[t+1])+1 );
			}
			t++;
		}
	}
	cout<<lmax<<endl;
	return 0;
}
