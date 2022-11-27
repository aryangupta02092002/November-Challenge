#include<bits/stdc++.h>
using namespace std;

class Sol{
    public:
    string addBinary(string A, string B)
	{
	    // your code here
	    int i=0;
	    while(i<A.size() && A[i] == '0'){
	        ++i;
	    }
	    A = A.substr(i, A.size()-i);
	    i=0;
	    while(i<B.size() && B[i] == '0'){
	        ++i;
	    }
	    B = B.substr(i, B.size()-i);
	    
	    if(A.size() < B.size()){
	        swap(A, B);
	    }
	    reverse(A.begin(), A.end());
	    reverse(B.begin(), B.end());
	    i=0;
	    int x, y, z, carry=0;
	    
	    while(i < B.size()){
	        x = A[i] - '0';
	        y = B[i] - '0';
	        z = x+y+carry;
	        A[i] = '0' + z%2;
	        carry = (z>1);
	        ++i;
	    }
	    
	    while(i < A.size()){
	        x=A[i]-'0';
	        z=x+carry;
	        A[i]='0'+z%2;
	        carry=(z>1);
	        ++i;
	    }
	    
	    if(carry){
	        A += '1';
	    }
	    reverse(A.begin(), A.end());
	    return A;
	}
};

int main(){
    string a, b;
    getline(cin, a);
    getline(cin, b);
    Sol s;
    cout<<s.addBinary(a, b)<<endl;
}