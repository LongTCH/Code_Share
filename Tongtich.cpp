#include <iostream>
using namespace std;
int getMaxIndex(int a[], bool isUse[], int n)
{
	int iMax = -1;
	for (int i=0; i<n; i++) if (!isUse[i])
	{
		iMax=i; break;
	}
	for (int i=iMax+1; i<n; i++) if (!isUse[i] && a[i]>a[iMax]) iMax = i;
	return iMax;
}
int main()
{
	int a[] = {6,7,5,3,5};
	int n = sizeof(a) / sizeof(int);
	bool isUse[n]={};
	bool next = true;
	int S = 0, S1 = 0, S2 = 0;
	for (int i=0; i<n; ++i) S+=a[i];
	while (next)
	{
		next = false;
		int i = getMaxIndex(a,isUse,n);
		if (i != -1)
		{
			if (i == 0) 
			{
			    if (!isUse[1] && S>=S-a[0]-a[1]+a[0]*a[1]) 
				{
					S = S-a[0]-a[1]+a[0]*a[1];
					isUse[0] = isUse[1] = true;
					next = true;
				}	
			}
			else if (i == n-1)
			{
				if (!isUse[n-2] && S>=S-a[n-1]-a[n-2]+a[n-1]*a[n-2]) 
				{
					S = S-a[n-1]-a[n-2]+a[n-1]*a[n-2];
					isUse[n-1] = isUse[n-2] = true;
					next = true;
				}	
			}	
			else
			{
				S1 = S - a[i] - a[i-1] + a[i]*a[i-1]; 
				S2 = S - a[i] - a[i+1] + a[i]*a[i+1]; 
				if (!isUse[i-1] && isUse[i+1] && S<=S1) 
				{
					isUse[i-1] = isUse[i] = true;
					S = S1;
					next = true;
				}
				else if (isUse[i-1] && !isUse[i+1] && S<=S2) 
				{
					isUse[i-1] = isUse[i] = true;
					S = S2;
					next = true;
				}
				else if (!isUse[i-1] && !isUse[i+1])
				{
					if (S1>=S2)
					{
						if (S<=S1) 
						{
							isUse[i-1] = isUse[i] = true;
				        	S = S1;
			         		next = true;
						}
					}
					else 
					{
						if (S<=S2)
						{
							isUse[i+1] = isUse[i] = true;
				        	S = S2;
			         		next = true;
						}
					}
				} 
			}
		}
	}
	cout<<"Sum = "<<S;
	return 0;
}
