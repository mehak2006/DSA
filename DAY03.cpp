//Question link: https://leetcode.com/problems/flipping-an-image/description/?envType=problem-list-v2&envId=array
//QUESTION 1->FLIPPING AN IMAGE
//CODE->
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        //flipping
        for(int i = 0;i<image.size();i++){
            reverse(image[i].begin(),image[i].end());
        }
        //inverting
        for(int i = 0;i<image.size();i++){
            for(int j = 0;j<image[i].size();j++){
                if(image[i][j]==1)image[i][j]=0;
                else image[i][j]=1;
            }
        }

        return image;
    }
};
//APPROACH: Used two loops, in first loop, flipped the row by simply using reverse function, in second loop inverted each element by using conditional statements
//TC: O(M*N), SC: O(1)

//Question link:https://leetcode.com/problems/number-of-equivalent-domino-pairs/?envType=problem-list-v2&envId=2030iluv
//QUESTION 2->NUMBER OF EQ. DOMINO PAIRS
//CODE->
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
      /*

            INITIAL APPROACH: however not efficient, so we use unordered maps(hash
            table)to make it more efficient

                int count = 0;
                for(int i = 0;i<dominoes.size();i++){
                    for(int j = i+1;j<dominoes.size();j++){
                        if(dominoes[i][0]==dominoes[j][0] && dominoes[i][1]==dominoes[j][1])count++; 
                        else if(dominoes[i][0]==dominoes[j][1] &&  dominoes[i][1]==dominoes[j][0])count++;
                    }
                }
                return count;
        */
        unordered_map<int, int> countMap;
        int count = 0;
        for (auto& d : dominoes) {
            // now we assign a number to each domino wich would be the same for
            // the rotated domino as well e.g.[1,2],
            // [2,1]=min(a,b)*10+max(a,b)=12 for both cases
            int key = min(d[0], d[1]) * 10 + max(d[0], d[1]);
            count = count + countMap[key];
            countMap[key]++;
        }
        return count;
    }
};

//APPROACH: Used hash table to store frequency key, where key was a decimal number that was unique for a domino and its rotated version
//TC: O(N), SC: O(N)
