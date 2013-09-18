/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Interleaving String
 *
 *        Version:  1.0
 *        Created:  09/15/2013 22:45:36 AM
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
#include	<string>
#include	<vector>
using namespace std;

class Solution {
	// bool r_isInterleave()

public:
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
		int len1 = s1.size();
		int len2 = s2.size();
		int len3 = s3.size();
		if(len3 != len1 + len2) return false;
		
		bool** mat = new bool*[len1+1];
		for(int i = 0; i < len1+1; ++i){
			mat[i] = new bool[len2+1];
			for(int j = 0; j < len2+1; ++j){
				mat[i][j] = false;
			}
		}
		
		mat[0][0] = true;
		for(int i = 0; i < len1; ++i){
			if(s1[i] == s3[i]) mat[i + 1][0] = true;
			else break;
		}
		for(int i = 0; i < len2; ++i){
			if(s2[i] == s3[i]) mat[0][i + 1] = true;
			else break;
		}
		// for(int j = 0; j < len2; ++j){
			// if(s2[j] == s3[len1 + j]) mat[len1][j+1] |= mat[len1][j];
		// }
		for(int i = 0; i < len1; ++i){
			for(int j = 0; j < len2; ++j){
				if(s1[i] == s3[i + j + 1]) mat[i+1][j+1] |= mat[i][j+1];
				if(s2[j] == s3[i + j + 1]) mat[i+1][j+1] |= mat[i+1][j];
			}
		}
		
		return mat[len1][len2];
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
	string s1 = "aabcc";
	string s2 = "dbbca";
	string str1 = "aadbbcbcac";
	string str2 = "aadbbbaccc";
	
	Solution s;
	cout << s.isInterleave(s1,s2,str1) << endl;
	cout << s.isInterleave(s1,s2,str2) << endl;
	
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */





