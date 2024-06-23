//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


typedef long long ll;
vector<ll> printFirstNegativeInteger(ll A[], ll N, ll k) {
    list<ll> dll; //You can use queue, dequeue etc as well
    vector<ll> result;
    int i = 0, j = 0;
    
    while(j < N) {
        if(A[j] < 0)
            dll.push_back(A[j]);
        
        if(j-i+1 == k) {
            ll neg = dll.empty() ? 0 : dll.front();
            result.push_back(neg);
            if(A[i] < 0 && !dll.empty()) {
                dll.pop_front();
            }
            i++;
        }
        j++;
    }
    return result;
    
 }