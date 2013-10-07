/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Edit Distance
 *
 *        Version:  1.0
 *        Created:  10/07/2013 09:52:31 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

class Solution {
public:
    int min(int a1, int a2, int a3){
        int min = a1 < a2 ? a1 : a2;
        return min < a3 ? min : a3;
    }

    int minDistance(string word1, string word2) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int len1 = word1.length(), len2 = word2.length();
        if(len1 == 0 || len2 == 0)
            return len1 + len2;
        
        vector<vector<int> > mat = vector<vector<int> >(len1 + 1, vector<int>(len2 + 1, 0));
        for(int i = 1; i <= len1; ++i)
            mat[i][0] = i;
        for(int i = 1; i <= len2; ++i)
            mat[0][i] = i;
        
        for(int i = 1; i <= len1; ++i){
            for(int j = 1; j <= len2; ++j){
                if(word1[i - 1] == word2[j - 1]){
                    mat[i][j] = mat[i - 1][j - 1];
                }
                else{
                    mat[i][j] = min(mat[i - 1][j - 1], mat[i - 1][j], mat[i][j - 1]) + 1;
                }
            }
        }
        return mat[len1][len2];
    }
};
