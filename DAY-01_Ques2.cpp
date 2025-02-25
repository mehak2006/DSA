// question link->http://geeksforgeeks.org/problems/reverse-bits3556/1?page=1&category=Mathematical&difficulty=Easy&sortBy=submissions
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    long long reversedBits(long long x)
    {
        // code here
        long long sum = 0;
        long long t = pow(2, 31);
        while (x != 0)
        {
            int bit = x % 2;
            sum = sum + t * bit;
            x = x / 2;
            t = t / 2;
        }
        return sum;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long X;

        cin >> X;

        Solution ob;
        cout << ob.reversedBits(X) << endl;

        cout << "~" << "\n";
    }
    return 0;
}
// } Driver Code Ends
