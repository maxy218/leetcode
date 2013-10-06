/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Set Matrix Zeroes
 *
 *        Version:  1.0
 *        Created:  2013年10月07日 07时47分54秒
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
    void setZeroes(vector<vector<int> > &matrix) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int rowNum = matrix.size(), colNum = matrix[0].size();
        if(rowNum < 1 || colNum < 1)
            return;
            
        bool ifFirstRowZero = false, ifFirstColZero = false;
        for(int i = 0; i < colNum; ++i){
            if(matrix[0][i] == 0){
                ifFirstRowZero = true;
                break;
            }
        }
        for(int i = 0; i < rowNum; ++i){
            if(matrix[i][0] == 0){
                ifFirstColZero = true;
                break;
            }
        }
        
        for(int i = 1; i < rowNum; ++i){
            for(int j = 1; j < colNum; ++j){
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        
        for(int i = 1; i < rowNum; ++i){
            if(matrix[i][0] == 0){
                for(int j = 1; j < colNum; ++j){
                    matrix[i][j] = 0;
                }
            }
        }
        for(int j = 1; j < colNum; ++j){
            if(matrix[0][j] == 0){
                for(int i = 1; i < rowNum; ++i){
                    matrix[i][j] = 0;
                }
            }
        }
        
        if(ifFirstRowZero){
            for(int j = 0; j < colNum; ++j){
                matrix[0][j] = 0;
            }
        }
        if(ifFirstColZero){
            for(int i = 0; i < rowNum; ++i){
                matrix[i][0] = 0;
            }
        }
    }
};
