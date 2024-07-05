// 

// Ctrl + Shift + B                => Build
// Terminal : "./a.out"            => Run
// Terminal : "./a.out < ./in.txt" => Run

#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n+1); i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define YesNo(bool) if(bool){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}
#define substring(s,l,r) s.substr(l,r-l)
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
// using mint = modint1000000007;
// using mint = modint998244353;

template<typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    for(int i = 0; i < (int) v.size(); i++) {
    os << v[i] << (i + 1 != (int) v.size() ? " " : "");
    }
    return os;
}
template<typename T>
istream &operator>>(istream &is, vector<T> &v) {
    for(T &in : v) is >> in;
    return is;
}


pair<ll,ll> N(0,1);
pair<ll,ll> E(1,0);
pair<ll,ll> W(-1,0);
pair<ll,ll> S(0,-1);
pair<ll,ll> turnLeft(pair<ll,ll> V) {
    if (V==E)
    {
        return N;
    }
    if (V==N)
    {
        return W;
    }
    if (V==W)
    {
        return S;
    }
    if (V==S)
    {
        return E;
    }
    return V;
}



int main() {
    ofstream output("D_out");
    while(true){
        ll n;
        cin >> n;
        if(n==0){
            break;
        }
        pair<ll,ll> p;
        ll d;
        cin >> p.first >> p.second >> d;
        pair<ll,ll> v = E;

        set<pair<ll,ll>> c;
        rep1(i,n) {
            pair<ll,ll> newC;
            cin >> newC.first >> newC.second;
            c.insert(newC);
        }

        while (d > 0) {
            p.first += v.first;
            p.second += v.second;
            if (c.find(p) != c.end())
            {
                p.first -= v.first;
                p.second -= v.second;
                v = turnLeft(v);
            } else {
                d--;
            }
        }

        output<< p.first << ' ' << p.second <<endl;
    }
    output.close();
    cout<<"comp"<<endl;
    return 0;
}