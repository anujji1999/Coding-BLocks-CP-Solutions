#include<bits/stdc++.h>
#define M1 1000000007
#define M2 998244353
#define ll long long int
#define N (int)1e6+3
#define test(t) while(t--)
#define PI acos(-1.0)
#define pll pair<ll,ll>
#define pii pair<int,int>
#define mii map<int,int>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repp(i,b,a) for(ll i=b-1;i>=a;i--)
#define clr(ar, val) memset(ar, val, sizeof(ar))
#define F first
#define S second
#define PB push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define V(a) vector<a>
#define M(a,b) map<a,b>
#define endl '\n'
#define all(x) begin(x),end(x)
#define allr(x) rbegin(x),rend(x)
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int dx[4] = { 0, -1, 0, 1 };
const int dy[4] = { -1, 0, 1, 0 };
using namespace std;

ll CalculateMex(set<ll> Set){
    ll Mex = 0;
    while(Set.find(Mex)!=Set.end()){
        Mex++;
    }
    return Mex;
}

inline void INP()
{
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);   
	    freopen("output.txt","w",stdout);
	#endif 
}
ll k,n;
ll a[102];
ll dp[102][102][102];
ll stock(ll i, ll purchase, ll sold){
    if (i==n){
        return 0;
    }

    if (dp[i][purchase][sold] != INT_MIN){
        return dp[i][purchase][sold];
    }

    //selling stock:
    if (purchase > sold){
    dp[i][purchase][sold] = max(dp[i][purchase][sold],
    stock(i+1,purchase,sold+1) + a[i]);
    }

    //purchasing stock:
    if (purchase < k && sold==purchase){
    dp[i][purchase][sold] = max(dp[i][purchase][sold],
    stock(i+1,purchase+1,sold) - a[i]);
    }

    //Leaving stock:
    dp[i][purchase][sold] = max(dp[i][purchase][sold],
    stock(i+1,purchase,sold));

    return dp[i][purchase][sold];


}

void solve()
{
    rep(i,0,102){
        rep(j,0,102){
            rep(k,0,102){
                dp[i][j][k] = INT_MIN;
            }
        }
    }
    clr(a,0);
    cin>> k>> n;
    rep(i,0,n) cin >> a[i];
    cout << stock(0,0,0) << endl;

}

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    test(t){
        solve();
    }
    return 0;
}