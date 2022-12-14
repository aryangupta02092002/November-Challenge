#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) { 
        int m = maze[0].size(), n = maze.size();
        queue<pair<int,int>>q;
        
        q.push({entrance[0],entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';
        int level = 0;
        int dr[4] = {1 , -1 ,  0 , 0};
        int dc[4] = {0 ,  0 , -1 , 1};
        
        while(!q.empty()){
            int sz = q.size();
            level++;
            
            for(int i=0; i<sz; i++){
                auto x = q.front();
                q.pop();
                int row = x.first;
                int col = x.second;
                for(int j=0; j<4; j++){
                    int new_row = row + dr[j];
                    int new_col = col + dc[j];
                    if(new_row >= 0 && new_col >= 0 && new_row < n && new_col < m){
                        if(maze[new_row][new_col] == '+'){
                            continue;
                        }
                        if(new_row == 0 || new_col == 0 || new_row == n-1 || new_col == m-1){
                            return level;
                        }
                        q.push({new_row, new_col});
                        maze[new_row][new_col] = '+'; 
                    }
                }
            }
        }
    return -1;   
}

int main(){
    int row, col;
    cout<<"Enter row and col: "<<endl;
    cin>>row>>col;
    vector<vector<char>> maze;
    cout<<"Enter the values for row and column: "<<endl;
    for(int i=0; i<row; i++){
        vector<char> tmp;
        for(int j=0; j<col; j++){
            char ch;    cin>>ch;
            tmp.push_back(ch);
        }
        maze.push_back(tmp);
    }
    vector<int> entrance;
    cout<<"Enter starting point value (row and col): "<<endl;
    for(int i=0; i<2; i++){
        int a;  cin>>a;
        entrance.push_back(a);
    }
    cout<<nearestExit(maze, entrance);
}
