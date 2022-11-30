#include<bits/stdc++.h>
using namespace std;

class RandomizedSet {
private:
  vector<int> v;
  unordered_map<int, int> u;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(u.find(val) != u.end())
          return false;
      v.push_back(val);
      u[val] = v.size()-1;
      return true;
    }
    
    bool remove(int val) {
        if(u.find(val) == u.end()){
          return false;
        }
      int end = v.back();
      u[end] = u[val];
      v[u[val]] = end;
      v.pop_back();
      u.erase(val);
      return true;
    }
    
    int getRandom() {
        return v[rand() % v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
int main(){
    RandomizedSet s;
    bool i1 = s.insert(2);
    bool i2 = s.insert(3);
    // bool i3 = s.insert(2);
    // bool i4 = s.insert(7);

    cout<<"Get random "<<s.getRandom()<<endl;
    bool r1 = s.remove(2);
    cout<<"Get random "<<s.getRandom()<<endl;
}