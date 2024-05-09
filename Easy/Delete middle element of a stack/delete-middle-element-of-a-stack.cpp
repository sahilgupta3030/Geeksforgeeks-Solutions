//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
        void deleteMidHelper(stack<int>&st, int count, int &pos){
        if(st.empty()) return;
        if(count == pos) {st.pop(); return;}
        
        int top = st.top(); 
        st.pop();
        deleteMidHelper(st, count+1, pos);
        
        st.push(top);
    }
    
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        // code here.. 
        int pos = ceil((sizeOfStack+1)/2.0);
        deleteMidHelper(s, 1, pos);
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);    
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
    }   
    return 0;
}

// } Driver Code Ends