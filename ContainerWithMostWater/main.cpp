/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Container With Most Water
 *
 *        Version:  1.0
 *        Created:  10/02/2013 07:23:27 PM
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
using namespace std;

class Solution {
public:

    int min(int a, int b){
      return a < b ? a : b;
    }

    int maxArea(vector<int> &height) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int maxS = 0;
        int i = 0, j = height.size() - 1;
        while(i != j){
          int h = min(height[i], height[j]);
          int tmpS = h * (j - i);
          if(tmpS > maxS)
          maxS = tmpS;
          if(height[i] > height[j])
            --j;
          else
            ++i;
        }
        return maxS;
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
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
