/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年10月15日 21时40分07秒
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
	void assignLine(vector<vector<int> > & mat, int r, int c, int num, int len, int dir){
		if(dir == 1){ // left to right
			for(int i = 0; i < len; ++i){
				mat[r][c + i] = num + i;
			}
		}
		else if(dir == 2){ // up to down
			for(int i = 0; i < len; ++i){
				mat[r + i][c] = num + i;
			}
		}
		else if(dir == 3){ // right to left
			for(int i = 0; i < len; ++i){
				mat[r][c - i] = num + i;
			}
		}
		else{ // down to up
			for(int i = 0; i < len; ++i){
				mat[r - i][c] = num + i;
			}
		}
	}

    vector<vector<int> > generateMatrix(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector<int> > ret = vector<vector<int> >(n, vector<int>(n, 0)); // initialized by zero
		int curLen = n;
		int r = 0;
		int c = 0;
		int startNum = 1;
		for(; curLen > 1; curLen -= 2){
			assignLine(ret, r, c, startNum, curLen - 1, 1);
			startNum += curLen - 1;
			assignLine(ret, r, c + curLen - 1, startNum, curLen - 1, 2);
			startNum += curLen - 1;
			assignLine(ret, r + curLen - 1, c + curLen - 1, startNum, curLen - 1, 3);
			startNum += curLen - 1;
			assignLine(ret, r + curLen - 1, c, startNum, curLen - 1, 4);
			startNum += curLen - 1;
			++r, ++c;
		}
		if(curLen == 1){
			ret[n/2][n/2] = n*n;
		}
		return ret;
    }
};
