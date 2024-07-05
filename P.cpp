#include <iostream>
#include <vector>
#include <algorithm> // std::max_element
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int,int>;

int main() {
    ofstream output("P-out");
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

        }
        ans = *std::max_element(a.begin(), a.end());




        cout << ans << endl;
        output<<ans<<endl;
    }
    output.close();
    cout<<"comp"<<endl;
    return 0;
}