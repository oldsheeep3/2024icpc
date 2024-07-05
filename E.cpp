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
void print() { cout << '\n'; }
template<typename T>
void print(const T &t) { cout << t << '\n'; }
template<typename Head, typename... Tail>
void print(const Head &head, const Tail &... tail) {
    cout << head << ' ';
    print(tail...);
}



int main() {
    ofstream output("E_out");
    while(true){
        int ans = 0;
        
        int n;
        cin >> n;
        if(n==0){
            break;
        }
        vector<int> a(n);
        std::vector<std::vector<int>> data(n,vector<int>(n));
        for(int i=0;i<n;i++){
            cin>>a.at(i);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                data[i][j]=0;
            }
        }
        bool s=false,t=false;
        for(int i=0;i<n/2+n%2;i++){
            if(a.at(0)==a.at(n-1-i)){
                s=true;
                for(int j=0;j<n/2+n%2;j++){
                    data[j][i] = a.at(j);
                }
                break;
            }
        }
        for(int i=0;i<n/2+n%2;i++){
            if(a.at(n-1)==a.at(i)){
                t=true;
                for(int j=0;j<n/2+n%2;j++){
                    data[i][j] = a.at(n-1-j);
                }
                break;
            }
        }

        if(s&&t){
            for(int i=0;i<n/2+n%2;i++){
                for(int j=0;j<n/2+n%2;j++){
                    if(data[i][j]!=0){
                    data[j][n-1-i] = data[i][j];
                    data[n-1-j][i] = data[i][j];
                    data[n-1-i][n-1-j] = data[i][j];
                    }
                }
            }
            
            output<<"Yes"<<endl;
            for(int i=0;i<n;i++){
                output<<data[i][0];
                for(int j=1;j<n;j++){
                    output<<" "<<data[i][j];
                }
                output<<endl;
            }

        }else{
            output<<"No"<<endl;
        }
        //cout << ans << endl;
        //output<<ans<<endl;
    }
    output.close();
    cout<<"comp"<<endl;
    return 0;
}