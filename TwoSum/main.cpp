/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Two Sum
 *
 *        Version:  1.0
 *        Created:  09/12/2013 12:05:36 AM
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
#include	<map>
#include	<vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = numbers.size();
		map<int, int> numPos;
		for(int i = 0; i < len; ++i){
			numPos[ numbers[i] ] = i + 1;
		}
		
		vector<int> retVal;
		for(int i = 0; i < len; ++i){
			if(numPos.find(target - numbers[i]) != numPos.end()){
				retVal.push_back(i + 1);
				retVal.push_back(numPos[target - numbers[i]]);
				return retVal;
			}
		}
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
	int array[] = {2, 7, 11, 15};
	vector<int> vec(array, array + 4);
	Solution s;
	vector<int> indice = s.twoSum(vec, 9);
	cout << indice[0] << "\t" << indice[1] << endl;
	
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */





