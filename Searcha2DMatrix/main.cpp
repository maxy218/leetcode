/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Search a 2D Matrix
 *
 *        Version:  1.0
 *        Created:  2013年10月07日 08时10分30秒
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
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int rowNum = matrix.size(), colNum = matrix[0].size();
        if(rowNum < 1 || colNum < 1)
            return false;
        
        int lrow = 0, lcol = 0;
        int rrow = rowNum - 1, rcol = colNum - 1;
        while(rrow > lrow || (rrow == lrow && rcol >= lcol) ){
            // get the mid point
            int len = colNum * (rrow - lrow) + rcol - lcol;
            int lFromStart = colNum * lrow + lcol;
            int midFromStart = lFromStart + (len >> 1);
            int midrow = midFromStart / colNum;
            int midcol = midFromStart - midrow * colNum;
            
            if(matrix[midrow][midcol] == target)
                return true;
            else if(matrix[midrow][midcol] > target){
                //get the previous point of mid point.
                if(midcol > 0){
                    rrow = midrow;
                    rcol = midcol - 1;
                }
                else{
                    rrow = midrow - 1;
                    rcol = colNum - 1;
                }
            }
            else{
                //get the previous point of mid point.
                if(midcol < colNum - 1){
                    lrow = midrow;
                    lcol = midcol + 1;
                }
                else{
                    lrow = midrow + 1;
                    lcol = 0;
                }
            }
        }
        return false;
    }
};
