#include<bits/stdc++.h>
using namespace std;

class Sol{
    public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches){
        map<int, int> m;
        for(int i=0; i<matches.size(); i++){
            if(!m.count(matches[i][0])){
                m[matches[i][0]] = 0;
            }
            m[matches[i][1]]++;
        }
        vector<int> zero, one;
        for(auto [key, val] : m){
            if(val == 0){
                zero.push_back(key);
            }
            if(val == 1){
                one.push_back(key);
            }
        }
        return {zero, one};
    }
};

int main(){
    int n;
    cout<<"Enter total number of matches: "<<endl;
    cin>>n;
    vector<vector<int>> matches;
    for(int i=0; i<n; i++){
        int a, b;
        cin>>a>>b;
        matches.push_back({a, b});
    }
    Sol s;
    vector<vector<int>> ans = s.findWinners(matches);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
