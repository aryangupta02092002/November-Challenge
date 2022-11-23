#include<iostream>
#include<vector>
using namespace std;

class Sol{
    public:
    bool checkPrime(int n){
        for(int i=2; i*i<=n; i++){
            if(n%i == 0){
                return false;
            }
        }
        return true;
    }
    long long int sumLCM(int n){
        long long int ans = 0;
        for(int i=2; i*i<=n; i++){
            if(n%i == 0){
                if(i == n/i){
                    ans += i;
                }
                else{
                    ans += (i+n/i);
                }
            }
        }
        return ans+1+n;
    }
    int maxSumLCM(int n){
	    if(n == 1){
            return 1;
        }
        bool isPrime = checkPrime(n);
        if(isPrime){
            return n+1;
        }
        else{
            return sumLCM(n);
        }
	}
};

int main(){
    int t;  cin>>t;
    while(t--){
        int n;
        cin>>n;
        Sol s;
        cout<<s.maxSumLCM(n)<<endl;
    }
    
}