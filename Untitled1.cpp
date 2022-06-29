#include <iostream>
using namespace std;
#define MAX 999999
int main()
{
	int a[] = {2,2,1,3,2,1,2,2,1,2};
	int n = sizeof(a) / sizeof(int);
	int isUse[n]={};
	int S = 0, next = 1, S1 = 0, S2 = 0;
	for (int i=0; i<n; ++i) S+=a[i];
	while (next)
	{
		next = 0;
		for (int i=0; i<n; ++i) 
		{
			if (!isUse[i] && a[i]<=a[i+1]) continue;
			else 
			{
				S1 = S - a[i] - a[i-1] + a[i]*a[i-1]; 
				S2 = S - a[i] - a[i+1] + a[i]*a[i+1]; 
				if (!isUse[i-1] && isUse[i+1] && S<=S1) 
				{
					isUse[i-1] = isUse[i] = 1;
					S = S1;
					next = 1;
					a[i] = a[i-1] = MAX;
				}
				else if (isUse[i-1] && !isUse[i+1] && S<=S2) 
				{
					isUse[i-1] = isUse[i] = 1;
					S = S2;
					next = 1;
					a[i+1] = a[i] = MAX;
				}
				else if (!isUse[i-1] && !isUse[i+1])
				{
					if (S1>=S2)
					{
						if (S<=S1) 
						{
							isUse[i-1] = isUse[i] = 1;
				        	S = S1;
			         		next = 1;
			         		a[i] = a[i-1] = MAX;
						}
					}
					else 
					{
						if (S<=S2)
						{
							isUse[i+1] = isUse[i] = 1;
				        	S = S2;
			         		next = 1;
			         		a[i+1] = a[i] = MAX;
						}
					}
				} 
			}
		}
	}
	cout<<"Sum = "<<S;
	return 0;
}
