//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    const int mod = 1e9+7;
    const int N = 1e5+1;
    long long int numoffbt(long long int arr[], int n){
        // Your code goes here
        vector<int> dp(N, 0);
        int mx = -1e9, mn = 1e9;
        long long ans = 0;
        for(int i=0; i<n; i++){
            dp[arr[i]] = 1;
            int tmp = arr[i];
            mx = max(mx, tmp);
            mn = min(mn, tmp);
        }
        
        for(int i=mn; i<=mx; i++){
            if(dp[i] != 1 || dp[i] == 0){
                continue;
            }
            for(int j=mn; j*j<=i; j++){
                if(i%j == 0 && dp[i/j] != 0 && dp[j] != 0){
                    if(i/j != j){
                        dp[i] += 2*(dp[i/j] * dp[j]);
                    }
                    else{
                        dp[i] += dp[j] * dp[j];
                    }
                    dp[i] %= mod;
                }
            }
            ans += dp[i];
            ans %= mod;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		long long int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<<ob.numoffbt(a,n)<<endl;
		
	}
	return 0;
}


// } Driver Code Ends