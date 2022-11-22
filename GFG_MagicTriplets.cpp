#include<iostream>
#include<vector>
using namespace std;

class Sol{
    public:
    int countTriplets(vector<int>nums){
	    int sz = nums.size();
	    int count = 0;
	    for(int i=1; i<sz-1; ++i){
	        int x = 0, y = 0;
	        int z1 = i-1, z2 = i+1;
	        
	        while(z1 >= 0){
	            if(nums[z1] < nums[i]){
	                x++;
	            }
	            z1--;
	        }
	        while(z2 < sz){
	            if(nums[z2] > nums[i]){
	                y++;
	            }
	            z2++;
	        }
	        if(x || y){
	            count += (x*y);
	        }
	    }
	    return count;
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
        cout<<s.countTriplets(nums)<<endl;
    }
    
}