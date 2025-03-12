//question link: https://leetcode.com/problems/pascals-triangle/description/
//QUESTION 1: PASCAL'S TRIANGLE
//CODE->
class Solution {
public:
    vector<int>generateRow(int row){
        long long ans = 1;
        vector<int> ansRow;
        ansRow.push_back(1);//inserting 1st element
        for(int j = 1;j<row;j++){
            ans=ans*(row-j);
            ans = ans/j;
            ansRow.push_back(ans);
        }
        return ansRow;

    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i = 1;i<=numRows;i++){
            ans.push_back((generateRow(i)));
        }
        return ans;
    }
};
//APPROACH->Created a function for generating rows optimally in O(n) TC and then used that for generating pascal's triangle
//TC: O(n^2),SC:O(n^2)

//question link: https://leetcode.com/problems/rotate-image/description/
//QUESTION 2: ROTATE IMAGE
//CODE->
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        //let's take transpose of matrix->row and columns are interchanged
        for(int i = 0;i<n;i++){
            for(int j = 0;j<i;j++){
                swap(matrix[i][j],matrix[j][i]);
            } 
        }
        //now reverse every row
        for(int i = 0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};
//APPROACH->Take transpose of matrix, then reverse each row
//TC: O(N^2),SC:O(1)

//question link:3: https://leetcode.com/problems/spiral-matrix/description/
//QUESTION 3: SPIRAL MATRIX
//CODE->
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int left = 0, right = cols - 1;
        int top = 0, bottom = rows - 1;
        vector<int> ans;
        while (left <= right && top <= bottom) {
            // right
            for (int i = left; i <= right; i++) {
                ans.push_back(matrix[top][i]);
            }
            top++;
            // bottom
            for (int i = top; i <= bottom; i++) {
                ans.push_back(matrix[i][right]);
            }
            right--;
            // left
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            // up
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return ans;
    }
};
//APPROACH->Took right, left, top, bottom pointers. Repeated cycle of right->bottom->left->up until there were no rows or columns left. Added check for edge cases when going left and up.
//TC: O(n*m),SC:O(n*m)
