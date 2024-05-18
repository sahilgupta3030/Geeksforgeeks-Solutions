//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution{   
public:
    bool subsetSum(vector<int>arr, int n, int sum, vector<vector<int>>&dp){ 
        if(dp[n][sum] != -1) return dp[n][sum];
        
        if(arr[n-1] <= sum){
            return dp[n][sum] = subsetSum(arr, n-1, sum-arr[n-1], dp) || subsetSum(arr, n-1, sum, dp);
        }else{
            return dp[n][sum] = subsetSum(arr, n-1, sum, dp);
        }
    }
    
    // main function..
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
        
        
        // Base case: If no elements are included, no positive sum can be achieved
        for(int i=0; i<=sum; i++){
            dp[0][i] = false;
        }
        // Base case: If sum is 0, it can always be achieved with empty subset
        for(int i=0; i<=n; i++){
            dp[i][0] = true;
        }
        
        
        return subsetSum(arr, n, sum, dp);
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends