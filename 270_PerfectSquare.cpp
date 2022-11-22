#include<iostream>
#include<vector>
using namespace std;

class Sol{
    public:
    int numSquares(int n){
        vector<int> dp(n+1);
        dp[0] = 0;
        dp[1] = 0;
        for(int i=2; i<=n; i++){
            int mn = INT_MAX;

            for(int j=1; j*j<=i; j++){
                int rem = i-j*j;
                if(dp[rem] < mn){
                    mn = dp[rem];
                }
            }
            dp[i] = mn+1;
        }
        return dp[n];
    }
};

int main(){
    int n;
    cin>>n;
    Sol s;
    cout<<s.numSquares(n)<<endl;
}