#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define M1 					1000000007
#define M2 					998244353
#define ll 					long long int
#define pll 				pair<ll,ll>
#define mll 				map<ll,ll>
#define F 					first
#define S 					second
#define PB 					push_back
#define mp 					make_pair
#define lb 					lower_bound
#define ub 					upper_bound
#define V(a) 				vector<a>
#define endl 				'\n'
#define test(t) 			while(t--)
#define PI 					acos(-1.0)
#define rep(i,a,b) 			for(ll i=a;i<b;i++)
#define repp(i,b,a) 		for(ll i=b-1;i>=a;i--)
#define clr(ar, val)		memset(ar, val, sizeof(ar))
#define setbits(x) 			__builtin_popcountll(x)
#define zrobits(x) 			__builtin_ctzll(x)
#define ps(y) 				fixed << setprecision(y)
#define all(x) 				begin(x),end(x)
#define allr(x) 			rbegin(x),rend(x)
const int inf= 				0x3f3f3f3f;
const ll INF= 				0x3f3f3f3f3f3f3f3f;
const int dx[4]= 			{ 0, -1, 0, 1 };
const int dy[4]= 			{ -1, 0, 1, 0 };

unsigned  int  randInt (){ 
    static  unsigned  int  tx  =  123456789 ,  ty = 362436069 ,  tz = 521288629 ,  tw = 88675123 ; 
    unsigned  int  tt  =  ( tx ^ ( tx << 11 )); 
    tx  =  ty ;  ty  =  tz ;  tz  =  tw ; 
    return  (  tw = ( tw^ ( tw >> 19 )) ^ ( tt ^ ( tt >> 8 ))  ); 
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<typename T>
#define o_set(T) tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>
//member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set

ll floor_div(ll a, ll b) {
	return a / b - (((a ^ b) < 0) and a % b);
}
ll ceil_div(ll a, ll b){
    return a / b + (((a ^ b) >= 0) and a % b);
}

inline void INP()
{
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);   
	    freopen("output.txt","w",stdout);
	#endif 
}

ll ans[4000005]={};
ll ob[4000005]={};
ll cb[4000005]={};
string s;
ll n;
void build(ll ind, ll l, ll r){

    if (l == r){
        if (s[l] == '('){
            ob[ind] = 1;
        }
        else cb[ind] = 1;
        return;
    }

    ll mid = (l+r)/2;
    build(2*ind,l,mid);
    build(2*ind+1,mid+1,r);
    ll tmp = min(ob[2*ind],cb[2*ind+1]);
    ans[ind] = ans[2*ind] + ans[2*ind+1] + tmp;
    ob[ind] = ob[2*ind] + ob[2*ind+1] - tmp;
    cb[ind] = cb[2*ind] + cb[2*ind+1] - tmp;
}

pair<ll,pll> query(ll ind, ll l, ll r, ll qs, ll qe){

    if (qs > r || qe < l){
        return {0,{0,0}};
    }

    if (qs <= l && qe>= r){
        return {ans[ind],{ob[ind],cb[ind]}};
    }

    ll mid = (l+r)/2;
    pair<ll,pll> left = query(2*ind,l,mid,qs,qe);
    pair<ll,pll> right = query(2*ind+1,mid+1,r,qs,qe);
    return {left.F+right.F + min(left.S.F,right.S.S),{
        left.S.F + right.S.F -  min(left.S.F,right.S.S),
        left.S.S + right.S.S -  min(left.S.F,right.S.S)
    }};
}

void solve()
{
    cin >> s;
    n = s.size();
    build(1,0,n-1);
    ll m;
    cin >> m;
    rep(i,0,m){
        ll x,y;
        cin >> x >> y;
        pair<ll,pll> val = query(1,0,n-1,x-1,y-1);
        cout << 2*val.F << endl;
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
    // cin>>t;
    test(t){
        solve();
    }
    return 0;
}