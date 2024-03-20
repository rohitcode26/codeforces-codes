#include<bits/stdc++.h>
 
using namespace std ;
 
#define F first
#define S second
#define R return
#define C continue 
#define pb push_back 
#define pf push_front
#define mod1 1000000007
 
#define vi vector <int>
#define vl vector <long>
#define vll vector <long long>
#define vii vector <vector <int> >
#define vs vector <string>
#define vpii vector <pair <int , int> >
#define vpll vector <pair <long , long> >
#define Fi(i,L,R) for (int i = L; i <= R; i++)
#define Fd(i,R,L) for (int i = R; i >= L; i--)
#define fast ios_base :: sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
 
void swap_int(int *a , int *b)
{
	int temp = *a ;
	*a = *b ;
	*b = temp ;
}
 
void solve (int testcase)
{
	int n , k , pos = 0 , count = 0 ;
	cin >> n >> k ;
	vi v (n+1) ;
	Fi(i , 1 , n)
	   cin >> v[i] ;
	Fi(i , k+1 , n)
	{
		if (v[i] == v[k])
			++count ;
		else 
		    break ;
	}
	if (count == n-k)
	{
		Fd(i , k-1 , 1)
		{
			if (v[i] != v[k])
			{
				pos = i ;
				break ;
			}
		}
		cout << pos ;
	}
	else
		cout << -1 ;
}
 
int main()
{
	fast 
	int t = 1 ;
//	cin>>t ;
	while (t--) 
	  solve (1) ;
	return 0 ;
}
