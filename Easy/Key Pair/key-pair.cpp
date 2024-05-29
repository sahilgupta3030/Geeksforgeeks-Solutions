//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
public:	
    bool hasArrayTwoCandidates(int arr[], int n, int x) {
        unordered_map<int, int> umap;

        for(int i = 0; i < n; ++i) {
            int complement = x - arr[i];
            
            // check if the complement exists in the hash map
            if(umap.find(complement) != umap.end()) {
                return true;
            }
            
            // add the current element to the hash map
            umap[arr[i]]++;
        }
        
        return false;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.hasArrayTwoCandidates(arr, n, x);
        cout << (ans ? "Yes\n" : "No\n");
    }
    return 0;
}

// } Driver Code Ends