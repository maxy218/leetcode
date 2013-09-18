/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  triangle
 *
 *        Version:  1.0
 *        Created:  2013年09月11日 13时06分10秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */



#include	<stdlib.h>
#include	<iostream>
#include	<vector>
#include	<string>
using namespace std;


class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int layerNum = triangle.size();

        if(layerNum < 2) return triangle[0][0];

        for(int l = layerNum - 2; l >= 0; --l){
          for(int i = 0; i <= l; ++i){
            int minChild = triangle[l+1][i] < triangle[l+1][i+1] ? triangle[l+1][i] : triangle[l+1][i+1];
            triangle[l][i] += minChild;
          }
        }
        return triangle[0][0];
    }
};


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{
        vector<vector<int> > triangle(4);
        triangle[0].push_back(2);
        triangle[1].push_back(3);
        triangle[1].push_back(4);
        triangle[2].push_back(6);
        triangle[2].push_back(5);
        triangle[2].push_back(7);
        triangle[3].push_back(4);
        triangle[3].push_back(1);
        triangle[3].push_back(8);
        triangle[3].push_back(3);

        Solution s;
        cout << s.minimumTotal(triangle) << endl;

	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
