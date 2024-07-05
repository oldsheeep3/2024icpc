// 
#include <bits/stdc++.h>
using namespace std;

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


int main() {
    ofstream output("B_out");
    while(true){
        int ans = 0;
        
        int n;
        cin >> n;
        if(n==0){
            break;
        }
        vector<int> a(n),b(n);
        cin >> a >> b;
        int d = 0;
        int pd = 0;
        rep(i,n) {
            if (a[i] != b[i])
            {
                d += (b[i]-a[i]);
                if (d != 0)
                {
                    if (pd*d < 0)
                    {
                        ans++;
                    }
                    pd = d;
                }
            } 
        }

        output<<ans<<endl;
    }
    output.close();
    cout<<"comp"<<endl;
    return 0;
}