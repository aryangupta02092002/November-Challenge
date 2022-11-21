#include<iostream>
#include<vector>
using namespace std;

class Calc{
    public:
    vector<vector<int>> ans;
    void helper(int n, vector<int> &tmp, int target){
        if(target == 0){
            if(!tmp.empty()){
                ans.push_back(tmp);
            }
            return;
        }
        if(n==0 || target<0){
            return;
        }
        tmp.push_back(n);
        helper(n, tmp, target-n);
        tmp.pop_back();
        helper(n-1, tmp, target);
    }
    vector<vector<int>> uniquePartition(int n){
        vector<int> tmp;
        helper(n, tmp, n);
        return ans;
    }
};
int main(){
    int t;      cin>>t;
    while(t--){
        int n;
        cin>>n;
        Calc c;
        vector<vector<int>> ans = c.uniquePartition(n);
        for(auto i : ans){
            for(auto j : i){
                cout<<j<<" ";
            }
        }
        cout<<endl;
    }
}