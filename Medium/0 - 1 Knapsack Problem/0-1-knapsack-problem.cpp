//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
public:
    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        // Initialize a 2D vector for memoization
        vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));

        // Function to solve knapsack problem recursively with memoization
        function<int(int, int)> solve = [&](int capacity, int numOfItems) {
            // Base cases
            if (numOfItems == 0 || capacity == 0) {
                return 0;
            }

            // Check if the subproblem is already solved
            if (dp[numOfItems][capacity] != -1) {
                return dp[numOfItems][capacity];
            }

            // If the current item can fit into the knapsack
            if (wt[numOfItems - 1] <= capacity) {
                // Two choices: include the current item or exclude it
                return dp[numOfItems][capacity] = max(val[numOfItems - 1] + solve(capacity - wt[numOfItems - 1], numOfItems - 1),
                                                       solve(capacity, numOfItems - 1));
            }
            else {
                // If the current item cannot fit into the knapsack, exclude it
                return dp[numOfItems][capacity] = solve(capacity, numOfItems - 1);
            }
        };

        // Call the solver function with the initial capacity and number of items
        return solve(W, n);
    }
};



//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends