//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution {
public:
    vector<int> PosNegPair(int a[], int n) {
        vector<int> ans;
        map<int, int> positiveCount, negativeCount;

        for (int i = 0; i < n; ++i) {
            if (a[i] > 0) {
                positiveCount[a[i]]++;
            } else {
                negativeCount[-a[i]]++;
            }
        }

        for (const auto& p : negativeCount) {
            int num = p.first;
            int negCount = p.second;

            if (positiveCount.count(num)) {
                int posCount = positiveCount[num];
                int pairs = min(negCount, posCount);

                for (int i = 0; i < pairs; ++i) {
                    ans.push_back(-num);
                    ans.push_back(num);
                }
            }
        }

        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> v = obj.PosNegPair(a, n);

        if (v.size() == 0) cout << "0";

        for (auto it : v) cout << it << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends