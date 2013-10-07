/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Minimum Path Sum
 *
 *        Version:  1.0
 *        Created:  2013年10月07日 08时42分09秒
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
    int minPathSum(vector<vector<int> > &grid) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int row = grid.size(), col = grid[0].size();
        vector<vector<int> > minSum  = vector<vector<int> >(row, vector<int>(col, 0));
        
        minSum[0][0] = grid[0][0];
        for(int i = 1; i < col; ++i){
            minSum[0][i] = minSum[0][i - 1] + grid[0][i];
        }
        for(int i = 1; i < row; ++i){
            minSum[i][0] = minSum[i - 1][0] + grid[i][0];
        }
        
        for(int i = 1; i < row; ++i){
            for(int j = 1; j < col; ++j){
                int min = minSum[i][j - 1] < minSum[i - 1][j] ? minSum[i][j - 1] : minSum[i - 1][j];
                minSum[i][j] = grid[i][j] + min;
            }
        }
        return minSum[row - 1][col - 1];
    }
};
