/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Unique Paths II
 *
 *        Version:  1.0
 *        Created:  2013年10月07日 08时28分34秒
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
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int row = obstacleGrid.size(), col = obstacleGrid[0].size();
        vector<vector<int> > mat = vector<vector<int> >(row, vector<int>(col, 0));
        if(obstacleGrid[0][0] == 1)
            return 0;
        mat[0][0] = 1;
        for(int i = 0; i < col; ++i){
            if(obstacleGrid[0][i] == 1)
                break;
            else{
                mat[0][i] = 1;
            }
        }
        for(int i = 0; i < row; ++i){
            if(obstacleGrid[i][0] == 1)
                break;
            else{
                mat[i][0] = 1;
            }
        }
        
        for(int i = 1; i < row; ++i){
            for(int j = 1; j < col; ++j){
                if(obstacleGrid[i][j] == 1){
                    mat[i][j] = 0;
                    continue;
                }
                else{
                    mat[i][j] = mat[i - 1][j] + mat[i][j - 1];
                }
            }
        }
        return mat[row - 1][col - 1];
    }
};
