/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Distinct Subsequences
 *
 *        Version:  1.0
 *        Created:  2013年09月11日 13时41分01秒
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
using namespace std;

void outputCharPos(const vector<vector<int> > & charPos){
	for(int i = 0; i < 256; ++i){
		int len = charPos[i].size();
		if(len != 0){
			cout << (char) i << ":\t" ;
			for(int j = 0; j < len; ++j){
				cout << charPos[i][j] << ", ";
			}
			cout << endl;
		}
	}
}

void output2DVector(const vector<vector<int> > & charPos){
	int len1 = charPos.size(); int len2 = charPos[0].size();
	for(int i = 0; i < len1; ++i){
		for(int j = 0; j < len2; ++j){
			cout << charPos[i][j] << ", ";
		}
		cout << endl;
	}
}

class Solution {
	vector<vector<int> > charPos;
	int numDist;
/*	
	int search(const vector<int>& vec, int n){
		int l = 0; int r = vec.size() - 1;
		if(vec.size() == 0 || r == 0) return 0; // in fact, size = 0 is error.
		while(l != r){
			int m = l + (r-l)/2;
			if(vec[m] == n) return m;
			else if(vec[m] > n) r = m - 1;
			else l = m + 1;
		}
		if(vec[l] > n) --l;
		return l;
	}
*/
	
	void r_numDistinct(const string & S, const string & T, int idxS, int idxT){
		if(idxT >= T.size()) {++numDist; return;}
		int posCnt = charPos[T[idxT]].size();
		if(posCnt <= 0) return;
		for(int i = posCnt - 1; i >= 0; --i){ // from large to small: speed up. no vain in trying
			if(charPos[T[idxT]][i] > idxS){
				r_numDistinct(S, T, charPos[T[idxT]][i], idxT+1);
			}
			else
				break;
		}
	}
	
public:
    int numDistinct(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    	int len_s = S.size();
		int len_t = T.size();
		vector <vector <int> > f(len_s+1,vector<int>(len_t+1));
		if(len_s < len_t)
			return 0;
		for(int i = 0 ; i <= len_s ; i++)
			f[i][0] = 0;
		for(int j = 0 ; j <= len_t ; j++)
			f[0][j] = 0;

		for(int i = 1 ; i <= len_s ;i++)
			if(S[i-1]==T[0])
				f[i][1] = f[i-1][1] + 1;
			else
				f[i][1] = f[i-1][1];			
		for(int i = 2;  i <= len_s ; i++)
			for(int j = 2; j <= len_t ; j++)
				if(S[i-1]==T[j-1])
					f[i][j] = f[i-1][j-1] + f[i-1][j];
				else
					f[i][j] = f[i-1][j];

		output2DVector(f);
		return f[len_s][len_t];
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
	string S = "rabbbit";
	string T = "rabbit";
	// string S = "aabdbaabeeadcbbdedacbbeecbabebaeeecaeabaedadcbdbcdaabebdadbbaeabdadeaabbabbecebbebcaddaacccebeaeedababedeacdeaaaeeaecbe";
	// string T = "bddabdcae";
	// string S = "daacaedaceacabbaabdccdaaeaebacddadcaeaacadbceaecddecdeedcebcdacdaebccdeebcbdeaccabcecbeeaadbccbaeccbbdaeadecabbbedceaddcdeabbcdaeadcddedddcececbeeabcbecaeadddeddccbdbcdcbceabcacddbbcedebbcaccac";
	// string T = "ceadbaa";
	Solution s;
	cout << "num:\t" << s.numDistinct(S, T) << endl;

	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
