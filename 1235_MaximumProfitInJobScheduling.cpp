#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

class Sol{
    public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int sz = startTime.size();
        vector<vector<int>> jobs;
        for(int i=0; i<sz; i++){
            jobs.push_back({endTime[i], startTime[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end());
        map<int, int> dp = {{0, 0}};
        
        for(auto &j : jobs){
            int current = prev(dp.upper_bound(j[1]))->second + j[2];
            if(current > dp.rbegin()->second){
                dp[j[0]] = current;
            }
        }
        return dp.rbegin()->second;
    }
};

int main(){
    int t;  cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> startTime(n);
        vector<int> endTime(n);
        vector<int> profit(n);
        for(int i=0; i<n; i++){
            cin>>startTime[i];
        }
        for(int i=0; i<n; i++){
            cin>>endTime[i];
        }
        for(int i=0; i<n; i++){
            cin>>profit[i];
        }
        Sol s;
        cout<<s.jobScheduling(startTime, endTime, profit)<<endl;
    }
    
}