/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Unique Paths
 *
 *        Version:  1.0
 *        Created:  2013年10月07日 08时15分18秒
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
    int uniquePaths(int m, int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector<int> > mat = vector<vector<int> >(m, vector<int>(n, 1));
        for(int i = 1; i < m; ++i){
            for(int j = 1; j < n; ++j){
                mat[i][j] = mat[i - 1][j] + mat[i][j - 1];
            }
        }
        return mat[m -1][n - 1];
    }
};
