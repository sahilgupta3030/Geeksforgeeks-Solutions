//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
public:
    queue<int> modifyQueue(queue<int> q, int k) {
        stack<int> s;

        // Step 1: Push the first k elements into a stack
        for (int i = 0; i < k; ++i) {
            s.push(q.front());
            q.pop();
        }

        // Step 2: Enqueue the elements from the stack back into the queue
        while (!s.empty()) {
            q.push(s.top());
            s.pop();
        }

        // Step 3: Move the remaining elements (n-k) to the back of the queue
        int remainingSize = q.size() - k;
        for (int i = 0; i < remainingSize; ++i) {
            q.push(q.front());
            q.pop();
        }

        return q;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        Solution ob;
        queue<int> ans = ob.modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends