#include <bits/stdc++.h>
using namespace std;

int main() {
    ofstream output("A_out");
    while(true){
        int ans = 0;
        
        int n,M=300;
        cin >> n;
        if(n==0){
            break;
        }
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a.at(i);
            if(M>=a.at(i)){
                M -= a.at(i);
            }
        }
        ans = 300-M;
        output<<ans<<endl;
    }
    output.close();
    cout<<"comp"<<endl;
    return 0;
}