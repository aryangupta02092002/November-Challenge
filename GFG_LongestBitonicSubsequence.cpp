#include<iostream>
#include<vector>
using namespace std;

class Sol{
    public:
    int LongestBitonicSequence(vector<int>nums)
	{
	    // code here
	    int sz = nums.size();
	    vector<int> lis(sz, 1);
	    vector<int> lds(sz, 1);
	    
	    for(int i=1; i<sz; i++){
	        for(int j=0; j<i; j++){
	            if(nums[i] > nums[j] && lis[i] < lis[j]+1){
	                lis[i] = lis[j]+1;
	            }
	        }
	    }
	    for(int i=sz-2; i>=0; i--){
	        for(int j=sz-1; j>i; j--){
	            if(nums[i]>nums[j] && lds[i] < lds[j]+1){
	                lds[i] = lds[j]+1;
	            }
	        }
	    }
	    int ans = lis[0] + lds[0] - 1;
	    for(int i=0; i<sz; i++){
	        ans = max((lis[i] + lds[i]-1), ans);
	    }
	    return ans;
	}
};

int main(){
    int t;  cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> nums(n);
        for(int i=0; i<n; i++){
            cin>>nums[i];
        }
        Sol s;
        cout<<s.LongestBitonicSequence(nums)<<endl;
    }
    
}