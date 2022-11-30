#include<bits/stdc++.h>
using namespace std;

class Sol{
    public:
    bool uniqueOccurrences(vector<int>& arr) {
        sort(arr.begin(),arr.end());                    
        int cnt = 1;                                    
        set<int> st;                                    
        
        if(arr.size()==2){
            return (arr[0]==arr[1]);
        }
        
        for(int i=1; i<arr.size(); i++){
            if(arr[i-1] != arr[i]){
                if(st.count(cnt) != 0){
                    return false;
                }
                else{
                    st.insert(cnt);                         
                    cnt = 1;
                }  
            }
            else{
                cnt++;                                      
            }
        }
        return true;
    }
};

int main(){
    int n;
    cout<<"Enter size of array: "<<endl;
    cin>>n;
    vector<int> a;
    for(int i=0; i<n; i++){
        int t;
        cin>>t;
        a.push_back(t);
    }
    Sol s;
    cout<<s.uniqueOccurrences(a);
     
}