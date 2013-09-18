/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Binary Tree Inorder Traversal
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
#include	<list>
#include	<vector>
#include	<string>
using namespace std;

class Solution {
	bool ifValidIPFrag(const string& ipFrag){
		// int ip = atoi(ipFrag.c_str());
		// return (ip >= 0 && ip <= 255);
		if(ipFrag.size() == 1) return ipFrag >= "0" && ipFrag <= "9";
		if(ipFrag.size() == 2) return ipFrag >= "10" && ipFrag <= "99";
		if(ipFrag.size() == 3) return ipFrag >= "100" && ipFrag <= "255";
		return false;
	}
	
	void r_srestoreIpAddresses(string& s, int startPos, int fragIdx, vector<string> & solution, vector<string>& solutions){
		if(fragIdx == 4){
			if(startPos == s.length()){
				string solutionStr;
				for(int i = 0; i < solution.size() - 1; ++i){ //solution.size() should be 4
					solutionStr += solution[i] + ".";
				}
				solutionStr += solution[solution.size() - 1];
				solutions.push_back(solutionStr);
			}
			return;
		}
		for(int i = startPos; i < s.length() && i < startPos + 3; ++i){
			string frag = s.substr(startPos, i - startPos + 1);
			if(!ifValidIPFrag(frag)) continue; // if not valid, next iteration.
			solution.push_back(frag);
			r_srestoreIpAddresses(s, i + 1, fragIdx + 1, solution, solutions);
			solution.pop_back();
		}
	}
	
public:
    vector<string> restoreIpAddresses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> solutions;
		vector<string> solution;
		r_srestoreIpAddresses(s, 0, 0, solution, solutions);
		return solutions;
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
	Solution s;
	string ipStr = "25525511135";
	vector<string> ips = s.restoreIpAddresses(ipStr);
	
	for(int i = 0; i < ips.size(); ++i){
		cout << ips[i] << endl;
	}
	
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */





