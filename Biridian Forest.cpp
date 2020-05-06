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

ll pow(ll a , ll b , ll m) {
	ll ans = 1 ;
	while(b)
	{
		if (b&1) {
			ans = (ans*a) % m ;
		}
		b /= 2 ;
		a = (a*a) % m ;
	}
	return ans ;
}

bool isprime(ll n) {
    for (ll i = 2 ; i * i <= n ; ++i)
        if (n % i == 0) {
        	return false ;
		}
    return true;
}

ll gcd(ll a, ll b) {
    if (b == 0) {
    	return a ;
	}
    else {
    	return gcd (b , a % b) ;
	}
}

ll lcm(ll a, ll b) {
    return ((a / gcd(a , b)) * b) ;
}

///////////////////////////////////////////////////////////////////////////////////////

int n , m ;
int d[1100][1100] ;
char g[1100][1100] ;
char v[1100][1100] ;
int si , sj , ei , ej , ti , tj ;
pii p ;

void solve (int test_case) {
	cin >> n >> m ;
	for (int i = 1 ; i <= n ; ++i) {
		for (int j = 1 ; j <= m ; ++j) {
			cin >> g[i][j] ;
			if (g[i][j] == 'E') {
				ei = i ;
				ej = j ;
			}
			if (g[i][j] == 'S') {
				si = i ;
				sj = j ;
			}
		}
	}
	for (int i = 0 ; i <= n+1 ; ++i) {
		for (int j = 0 ; j <= m+1 ; ++j) {
			v[i][j] = 1 ;
		}
	}
	for (int i = 1 ; i <= n ; ++i) {
		for (int j = 1 ; j <= m ; ++j) {
			if (g[i][j] == 'T') {
				continue ;
			}
			v[i][j] = 0 ;
		}
	}
	v[ei][ej] = 1 ;
	queue <pii> q ;
	q.push({ei , ej}) ;
	while (q.empty() == false) {
		p = q.front() ;
		q.pop() ;
		ti = p.F ;
		tj = p.S ;
		for (int i = 0 ; i < 4 ; ++i) {
			if (v[ti + dx[i]][tj + dy[i]] == 0) {
				v[ti + dx[i]][tj + dy[i]] = 1 ;
				d[ti + dx[i]][tj + dy[i]] = d[ti][tj] + 1 ;
				q.push({ti + dx[i] , tj + dy[i]}) ;
			}
		}
	}
	int ans = 0 ;
	for (int i = 1 ; i <= n ; ++i) {
		for (int j = 1 ; j <= m ; ++j) {
			if (v[i][j] && d[i][j] <= d[si][sj] && g[i][j] >= '0' && g[i][j] <= '9') {
				ans += g[i][j] - 48 ;
			}
		}
	}
	cout << ans ;
}

int main() {
	FAST ;
	//#ifndef ONLINE_JUDGE
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//#endif
	int tc = 1 ;
//	cin >> tc ;
	while (tc--) {
		solve (tc) ;
	}
	return 0 ;
}
