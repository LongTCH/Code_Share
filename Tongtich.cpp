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
	int a[] = {6, 7, 5, 3, 5};
	int n = sizeof(a) / sizeof(int);
	bool isUse[n]={};
	int S = 0, S1 = 0, S2 = 0, i;
	for (i=0; i<n; ++i) S+=a[i];
	do
	{
		i = getMaxIndex(a,isUse,n);
		cout<<i<<endl;
		if (i != -1)
		{
			isUse[i] = true;
			if (i == 0) 
			{
			    if (!isUse[1] && S<=S-a[0]-a[1]+a[0]*a[1]) 
				{
					S = S-a[0]-a[1]+a[0]*a[1];
					isUse[1] = true;
				}	
			}
			else if (i == n-1)
			{
				if (!isUse[n-2] && S<=S-a[n-1]-a[n-2]+a[n-1]*a[n-2]) 
				{
					S = S-a[n-1]-a[n-2]+a[n-1]*a[n-2];
					isUse[n-2] = true;
				}	
			}	
			else
			{
				S1 = S - a[i] - a[i-1] + a[i]*a[i-1]; 
				S2 = S - a[i] - a[i+1] + a[i]*a[i+1]; 
				if (!isUse[i-1] && isUse[i+1] && S<=S1) 
				{
					isUse[i-1] =true;
					S = S1;
				}
				else if (isUse[i-1] && !isUse[i+1] && S<=S2) 
				{
					isUse[i+1] = true;
					S = S2;
				}
				else if (!isUse[i-1] && !isUse[i+1])
				{
					if (S1>=S2)
					{
						if (S<=S1) 
						{
							isUse[i-1] = true;
				        	S = S1;
						}
					}
					else 
					{
						if (S<=S2)
						{
							isUse[i+1] = true;
				        	S = S2;
						}
					}
				} 
			}
		}
	} while (i!=-1);
	cout<<"Sum = "<<S;
	return 0;
}
