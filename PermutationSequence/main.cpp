/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年10月15日 21时37分28秒
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
	void removeElemFromVector(vector<int>& vec, int k){
		int idx = k;
		while(idx < vec.size() - 1){
			vec[idx] = vec[idx + 1];
			++idx;
		}
		vec.pop_back();
	}

    string getPermutation(int n, int k) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int* prod = new int[n];
		prod[0] = 1;
		for(int i = 1; i < n; ++i){
			prod[i] = (i + 1) * prod[i - 1];
		}
		
		string ret = string(n, '0');
		vector<int> candidate = vector<int>(n);
		for(int i = 1; i <= n; ++i){
			candidate[i - 1] = i;
		}
		k = k - 1; // you can find that it's right.
		for(int i = n - 2; i >= 0; --i){
			ret[n - 2 - i] = '0' + candidate[ k / prod[i] ];
			removeElemFromVector(candidate, k / prod[i]);
			k = k % prod[i];
		}
		ret[n - 1] = '0' + candidate[0];
		return ret;
    }
};
