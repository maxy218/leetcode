/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  longest consecutive sequence
 *
 *        Version:  1.0
 *        Created:  2013年09月10日 20时09分44秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */


#include	<stdlib.h>
#include 	<iostream>
#include	<vector>
#include	<boost/unordered_set.hpp>
using namespace std;
using namespace boost;

class Solution {

    int getCount(unordered_set<int> & numSet, int num, bool asc){ // asc: true: ascend, false: decrease
      int cnt = 0;
      while(numSet.find(num) != numSet.end()){
        ++cnt;
        numSet.erase(num);
        if(asc) ++num;
        else --num;
      }
      return cnt;
    }

public:
    int longestConsecutive(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        unordered_set<int> numSet;
        int len = num.size();
        int maxConSeqLen = 0;
        for(int i = 0; i < len; ++i){
          numSet.insert(num[i]);
        }
        
        for(int i = 0; i < len; ++i){
          if(numSet.find(num[i]) != numSet.end()){
            numSet.erase(num[i]);
            int curConSeqLen = 1;
            curConSeqLen += getCount(numSet, num[i]+1, true);
            curConSeqLen += getCount(numSet, num[i]-1, false);
            if(curConSeqLen > maxConSeqLen) maxConSeqLen = curConSeqLen;
          }
        }
        return maxConSeqLen;
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
        int array[] = {100, 4, 200, 1, 3, 2};
        vector<int> vec(array, array+6);
        Solution s;
        cout << s.longestConsecutive(vec) << endl;
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
