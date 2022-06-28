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
const ll N = 5e5+10; vll a(N), prv(N), nxt(N); ll n;
// bool _(ll i, ll j){ if(i < 0 || j > n-1) return false; return a[j] == (a[i]+1)%10 ? true : false; }
int32_t main(){ fast
    T{
        auto _ = [](ll i, ll j) -> bool{ if(i < 0 || j > n-1) return false; return a[j] == (a[i]+1)%10 ? true : false; };
        string s; cin>>n>>s; f(i, 0, n) a[i] = s[i]-'0';
        vector<bool> b(n, true); us<ll> st[10];
        f(i, 0, n-1) if(_(i, i+1)) st[a[i]].insert(i);
        f(i, 0, n){ prv[i] = i-1; nxt[i] = i+1; }
        
        while(1){
            bool flag = false;
            f(i, 0, 10){
                while(st[i].size()){

                    // (l, {c,) ["r",} rr] // left(l), current(c), right(r), right_right(rr)
                    ll c = *st[i].begin(), l = prv[c], r = nxt[c], rr = nxt[r];
                                                
                    // deletion of right element & modification of left element of the i, (i+1)%10 pair  
                    st[i].erase(st[i].begin()); b[r] = false;

                    if(_(l, c)){
                        st[a[l]].erase(l);
                    }

                    if(_(r, rr)){
                        st[a[r]].erase(r);
                    }

                    prv[rr] = c;
                    nxt[c] = rr;
                    
                    a[c] += 2; a[c] %= 10;

                    if(_(l, c)){
                        st[a[l]].insert(l);
                    }

                    if(_(c, rr)){
                        st[a[c]].insert(c);
                    }
                    flag = true;
                }
            }
            if(!flag) break;
        }
        TC f(i, 0, n) if(b[i]) cout<<a[i]; cout<<"\n";
    }
}
