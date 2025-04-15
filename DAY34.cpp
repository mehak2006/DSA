//question link: https://leetcode.com/problems/count-good-numbers/
//QUESTION 1: COUNT GOOD NUMBERS
//CODE->
class Solution {

public:
    const long long MOD = 1e9 + 7;
    // iterative method
    long long power(long long base, long long exp) {
        if (exp == 0)
            return 1;

        long long half = power(base, exp / 2);
        long long result = (half * half) % MOD;

        if (exp % 2 == 1)
            result = (result * base) % MOD;

        return result;
    }
    int countGoodNumbers(long long n) {
        long long even = (n + 1) / 2;
        long long odd = n / 2;
        long long goodNums = (power(5, even) * power(4, odd)) % MOD;
        return goodNums;
    }
};

// for iterative SC:O(1)

//APPROACH->Used modular exponentiation to reduce TC, used count good nnumbers formula->(power(5, even) * power(4, odd)) % MOD;
// TC:O(logN)SC:O(logN)(:- due to call to stack during recursion)

//question link: https://www.geeksforgeeks.org/problems/sort-a-stack/1 
//QUESTION 2: SORT A STACK
//CODE->
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);

cout << "~" << "\n";
}
}
// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */

/*The idea of the solution is to hold all values in Function Call Stack until the stack becomes empty.
When the stack becomes empty, insert all held items one by one in sorted order. 
and then print the stack
Follow the steps mentioned below to implement the idea:

->Base Case: If the stack is empty, return.
->Pop & Recur: Remove the top element, recursively sort the remaining stack.                           
->Temporary Storage: Use a temporary stack to hold elements greater than the popped element.
->Insert Correctly: Push the popped element back into the stack at its correct position.
->Restore Order: Move elements from the temporary stack back to the original stack.
*/

void insertSorted(stack<int>& st, int x) {
    // Base case: if stack is empty or top is less than or equal to x, push x
    if (st.empty() || st.top() <= x) {
        st.push(x);
        return;
    }

    // If top is greater, pop and recurse
    int temp = st.top();
    st.pop();
    insertSorted(st, x);
    st.push(temp); // Push the popped item back after inserting x
}

void SortedStack::sort() {
    // Base case: stack is empty
    if (s.empty()) return;

    // Pop the top element
    int topElement = s.top();
    s.pop();

    // Recursively sort the remaining stack
    sort();

    // Insert the popped element back in sorted order
    insertSorted(s, topElement);
}
//How do we keep track of popped elements?
/*Let’s say we’re sorting the stack:
[11, 2, 32, 3, 41]

Each time we call sort(), we pop the top element. 
We don’t lose it because of how function calls are stacked in memory — the call stack of recursion acts like a temporary holding area!

*/

//APPROACH->We recursively pop all elements of the stack until it's empty.
            //Then we insert each element back in sorted order using a helper function insertSorted(), which ensures every new element finds its correct position by popping larger elements and pushing them back after insertion.
            //This way, the recursion call stack temporarily holds the popped elements for us, acting like a helper memory.
            //It simulates the behavior of insertion sort using stack operations only, with no extra data structures.
//TC:O(n^2),SC:O(n)
