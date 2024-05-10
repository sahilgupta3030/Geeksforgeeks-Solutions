//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int mod = 1000000007;
    
    int nthFibonacci(int n) {
        if (n <= 1) return n;
        
        int a = 0, b = 1, c;
        for (int i = 2; i <= n; i++) {
            c = (a + b) % mod;
            a = b;
            b = c;
        }
        return c;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends