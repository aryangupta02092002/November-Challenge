#include<bits/stdc++.h>
using namespace std;

class Sol{
    public:
    vector<int> findSubarray(int a[], int n){
        int mx = 0, curr = 0;
        vector<int> ans, tmp;
        for(int i=0; i<n; i++){
            if(a[i] < 0){
                if(curr > mx || (curr == mx && tmp.size() > ans.size())){
                    mx = curr;
                    ans = tmp;
                }
                curr = 0;
                tmp.clear();
            }
            else{
                curr += a[i];
                tmp.push_back(a[i]);
            }
        }
        if(curr > mx || (curr == mx && tmp.size() > ans.size())){
            ans = tmp;
        }
        if(ans.size() == 0){
            ans.push_back(-1);
        }
        return ans;
    }
};

int main(){
    int n;
    cout<<"Enter size of array: "<<endl;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    Sol s;
    vector<int> ans = s.findSubarray(a, n);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl; 
}