#include <bits/stdc++.h>
using namespace std;
#define ll        long long
#define ll0(x)        ll x = 0;
#define ld        long double
#define ld0(x)        ld x = 0;
const ll M = 1e9+7;
const ll M2 = 998244353;
ll binexp(ll a, ll b)        { ll ans = 1; while(b){ if(b&1) ans = ans*a; a = a*a; b >>= 1; } return ans; }
ll binmul(ll a, ll b, ll m)        { a %= m; ll ans = 0; while(b){ if(b&1) ans = (ans+a)%m; a = (a+a)%m; b >>= 1; } return ans; }
ll binexpmod(ll a, ll b, ll m)        { a %= m; ll ans = 1; while(b){ if(b&1) ans = binmul(ans, a, m); a = binmul(a, a, m); b >>= 1; } return ans; }
#define T        ll0(no_of_testcases) cin>>no_of_testcases; f(curr_testcase, 1, no_of_testcases+1)
#define fast        ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define info        cout<<__DATE__<<" "<<__TIME__<<"\n";
#define TC        cout<<"Case #"<<curr_testcase<<": ";
ll gcd(ll x, ll y)        { if(y == 0) return x; return gcd(y, x%y); }
ll lcm(ll x, ll y)        { ll g = gcd(x, y); return (x/g)*(y/g); }
#define f(i, m, n)        for(ll i = (ll)m; i < (ll)n; i++)
#define f_(i, n, m)        for(ll i = (ll)n; i >= (ll)m; i--)
#define fa(i, x)        for(auto i:x)
ll max(ll x, ll y)        { return x > y ? x : y; }
ll min(ll x, ll y)        { return x < y ? x : y; }
#define inf        (ll)LLONG_MAX-(ll)INT_MAX
#define inf_        (ll)LLONG_MIN-(ll)INT_MIN
#define all(x)        x.begin(), x.end()
#define bp        __builtin_popcountll
#define bclz        __builtin_clzll
#define bctz        __builtin_ctzll
#define vll        vector<ll> 
#define pll        pair<ll, ll>
#define vpll        vector<pll>
#define vvll        vector<vll>
#define um        unordered_map 
#define us        unordered_set 
#define ms        multiset
#define ub        upper_bound
#define lb        lower_bound
#define pb        push_back
#define mp        make_pair
#define ff        first
#define ss        second
const ll K = 1e5+10; vll g[K], cc[K], kis_cc(K); vector<bool> vis(K, false); ll idx = 0;

void dfs(ll v){
    vis[v] = true;
    cc[idx].pb(v);
    kis_cc[v] = idx;
    for(ll child:g[v]){
        if(!vis[child]) dfs(child);
    }
}

int32_t main(){ fast
    ll n, k, ans = 0; cin>>n>>k; vll p(n), c(n); f(i, 0, n) cin>>p[i]; f(i, 0, n) cin>>c[i]; us<ll> st;
    f(i, 0, k){
        ll x, y; cin>>x>>y; g[x].pb(y); g[y].pb(x); st.insert(x); st.insert(y);
    }
    fa(&i, st){
        if(!vis[i]){
            dfs(i); idx++;
        }
    }

    f(i, 0, idx){
        vll a, b;
        fa(&j, cc[i]){ 
            j--; a.pb(p[j]); b.pb(c[j]);
            p[j] = 0; c[j] = 0;
        }
        ll n_ = a.size();
        sort(all(a), [](ll x, ll y)->bool{ return x > y; });
        sort(all(b));
        f(i, 0, n_){
            ans += a[i]*b[i];
        }
    }
    f(i, 0, n){
        ans += p[i]*c[i];
    }

    cout<<ans;
}
