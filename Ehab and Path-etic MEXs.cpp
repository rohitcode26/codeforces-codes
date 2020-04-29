#include<bits/stdc++.h>
 
using namespace std ;
 
typedef double D ;
typedef long long ll ;
typedef long double ld ;
typedef unsigned int ui ;
typedef unsigned long long ull ;
 
# define F first
# define S second
# define R return
# define C continue 
# define pb push_back 
# define pf push_front
# define mp make_pair
 
# define vi vector <int>
# define vb vector <bool>
# define vc vector <char>
# define vll vector <ll>
# define vs vector <string>
 
# define vvi vector < vector < int > >
# define vvb vector < vector < bool > >
# define vvc vector < vector < char > >
# define vvll vector < vector < ll > >
# define vvd vector < vector < D > >
# define vvld vector < vector < ld > >
 
# define pii pair < int , int >
# define pll pair < ll , ll >
# define pld pair < ld , ld >
# define pDD pair < D , D >
 
# define vpld vector < pld >
# define vpii vector < pii >
# define vpll vector < pll >
# define vpDD vector < pDD >
# define vvpii vector < vector < pii > >
 
# define all(v) (v).begin() , (v).end()
# define allrev(v) (v).rbegin() , (v).rend()
# define allcomp(v) v.begin() , v.end() , comp
# define allrevcomp(v) v.rbegin() , v.rend() , comp

# define dist(a,b,p,q) sqrt((p-a)*(p-a) + (q-b)*(q-b))

# define FAST ios_base :: sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0)
 
const ll MOD = 1e9 + 7 ;
const int infi =  INT_MAX ;
const ll infll =  LLONG_MAX ;
const ld PI = 3.1415926535897932384626 ;

const int dx[] = {-1 , 0 , 1 , 0} ;
const int dy[] = {0 , 1 , 0 , -1} ;
 
///////////////////////////////////////////////////////////////////////////////////////

void solve (int test_case){
	int n ;
	cin >> n;
	vi u(n - 1) , v(n - 1) , deg(n + 1, 0) ;
	for (int i = 0; i < n - 1; ++i){
		cin >> u[i] >> v[i] ;
		++deg[u[i]] ;
		++deg[v[i]] ;
	}
	int nxt = 0 ;
	auto it = max_element(deg.begin() + 1 , deg.end()) ;
	vi ans(n - 1, -1) ;
	if (*it >= 3){
		for (int i = 0 ; i < n - 1 ; ++i){
			if (u[i] == (it - deg.begin()) || v[i] == (it - deg.begin())) {
				ans[i] = nxt++ ;
			}
		}
	}
	for (int i = 0 ; i < n - 1 ; ++i){
		if (ans[i] == -1){
			ans[i] = nxt++ ;
		}
		cout << ans[i] << '\n' ;
	}
}
 
int main(){
	//freopen ("input.txt","r",stdin) ;
	//freopen ("output.txt","w",stdout) ;
	FAST ;
	int tc = 1 ;
//	cin >> tc ;
	while (tc--){
		solve (tc) ;
	}
	return 0 ;
}
