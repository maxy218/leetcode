#include	<iostream>
#include	<vector>
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
	vector<int> result;
	if(n == 0) {
		result.push_back(0);
		return result;	
	}
        if(n == 1){
		result.push_back(0);
		result.push_back(1);
		return result;
	}
	
	vector<int> subResult = grayCode(n - 1);
	result = subResult;
	int mostSigBit = 1 << (n - 1);
	int len = subResult.size();
	for(int i = len - 1; i >= 0; --i){
		result.push_back(mostSigBit + subResult[i]);
	}
	return result;
    }
};

void output(const vector<int> & vec){
	int len = vec.size();
	for(int i = 0; i < len; ++i){
		cout << vec[i] << ", ";
	}
	cout << endl;
}

int main(){
	Solution s;
	vector<int> vec = s.grayCode(4);
	output(vec);
}
