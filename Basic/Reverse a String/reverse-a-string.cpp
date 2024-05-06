//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution
{
    public:
    // // Recursion..
    // string reverseWord(string str)
    // {
    //     if(str.size() == 0 || str.size()== 1) return str;
    //     return reverseWord(str.substr(1)) + str[0];
    // }
    
    string reverseWord(string str){
    
    int end = str.size()-1;
    for(int i = 0; i < str.size()/2; i++)
    {
        swap(str[i], str[end]);
        end--;
    }
    return str; 
}
};



//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
    	string s;
    	cin >> s;
    	Solution ob;
    	cout << ob.reverseWord(s) << endl;
	}
	return 0;
	
}


// } Driver Code Ends