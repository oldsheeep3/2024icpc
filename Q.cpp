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
int main() {
    ofstream output("Q_out");
    while(true){
        int ans = 0;
        
        int n;
        cin >> n;
        if(n==0){
            break;
        }
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a.at(i);
            a.at(i)=2023-a.at(i);
            if(a.at(i)<0){
                a.at(i)*=-1;
            }
        }
        for(int i=0;i<n-1;i++){
            if(a.at(i)>a.at(i+1)){
                ans = i+2;
            }
        }

        //cout << ans << endl;
        output<<ans<<endl;
    }
    output.close();
    cout<<"comp"<<endl;
    return 0;
}