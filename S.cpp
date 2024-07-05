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

int main() {
    ofstream output("S_out");
    while(true){
        int ans = 0;
        
        vector<int> a(4);
        for(int i=0;i<4;i++){
            cin>>a.at(i);
        }
        if(a.at(0)+a.at(1)+a.at(2)+a.at(3)==0){
            break;
        }
        while(true){
        sort(a.begin(),a.end());
        if(a.at(0)!=0){
            for(int i=1;i<4;i++){
                a.at(i) = a.at(i)-a.at(0);
            }
        }else if(a.at(1)!=0){
            for(int i=2;i<4;i++){
                a.at(i) = a.at(i)-a.at(1);
            }
        }else if(a.at(2)!=0){
            for(int i=3;i<4;i++){
                a.at(i) = a.at(i)-a.at(2);
            }
        }else{
            ans=a.at(3);
            break;
        }
        }

        cout << ans << endl;
        output<<ans<<endl;
    }
    output.close();
    cout<<"comp"<<endl;
    return 0;
}