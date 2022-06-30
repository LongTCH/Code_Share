#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<string> number{"khong ","mot ","hai ","ba ","bon ","nam ","sau ","bay ","tam ","chin "};
vector<string> res{""};
vector<string> dot{"nghin ","trieu ","ti "};
string readNumOf3(int n)
{
	int a = n%10;
	n/= 10;
	int b = n%10;
	n/= 10;
	if (a == 0)
	{
		if (b == 0) return number[n]+"tram ";
		if (b == 1) return number[n]+"tram muoi ";
		return number[n]+"tram "+number[b]+"muoi ";
	}
	else if (a == 5)
	{
		if (b == 0) return number[n]+"tram le nam";
		if (b == 1) return number[n]+"tram muoi lam";
		return number[n]+"tram "+number[b]+"muoi lam ";
	}
	else
	{
		if (b == 0) return number[n]+"tram le "+number[a];
		if (b == 1) return number[n]+"tram muoi "+number[a];
		return number[n]+"tram "+number[b]+"muoi "+number[a];
	}
}
string readFirst(int n)
{
	if (n > 99) return readNumOf3(n);
	int a = n%10;
	n/=10;
	if (n > 0)
	{
		if (a == 0) 
		{
			if (n == 1) return "muoi ";
			return number[n]+"muoi ";
		}
		if (a == 5)
		{
			if (n == 1) return "muoi lam ";
			return number[n]+"muoi lam";
		}
		if (n == 1) return "muoi "+number[a];
		return number[n]+"muoi "+number[a];
	}
	return number[a];
}
string n;
int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	int temp, checkPre = 0;
    cin>>n;
    int dotIndex = 0;
    while (n.size()>3)
    {
		temp = 0;
		for (int i=0; i<3; ++i)
    	{
    		temp+= (n.back()-'0')*pow(10,i);
    		n.pop_back();
		}
		if (!temp && (res.back()).compare("ti ") != 0) 
		{
			res.pop_back();
		} else if (temp) res.push_back(readNumOf3(temp));
		res.push_back(dot[dotIndex]);
		dotIndex=(dotIndex+1)%3;
	}
	temp = 0;
	for (int i=0; i<3; ++i)
   	{
    	temp+= (n.back()-'0')*pow(10,i);
    	n.pop_back();
    	if (n.size() == 0) break;
	}
	res.push_back(readFirst(temp));
	for (auto i = res.rbegin(); i != res.rend(); ++i)
	{
		cout<<*i;
	}
	return 0;
}
