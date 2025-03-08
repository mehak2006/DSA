// question link->https://leetcode.com/problems/ugly-number/submissions/1555376013/?envType=problem-list-v2&envId=math

class Solution
{
public:
    bool isUgly(int n)
    {
        if (n < 0)
            return false;
        while (n > 1)
        {
            if (n % 2 == 0)
                n = n / 2;
            else if (n % 3 == 0)
                n = n / 3;
            else if (n % 5 == 0)
                n = n / 5;
            else
                break;
        }
        return (n == 1);
    }
};

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
