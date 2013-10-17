/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/16/2013 08:04:32 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <string>
#include <vector>
#include <boost/unordered_set.hpp>
using namespace std;
using namespace boost;

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> pos;
        int len = s.length();
        for(int idx = len - 1; idx >= 0; --idx){
          string sub = s.substr(idx, len - idx);
          if(dict.find(sub) != dict.end()){
            pos.push_back(idx);
          }
          else{
            for(int i = 0; i < pos.size(); ++i){
              string sub2 = s.substr(idx, pos[i] - idx);
              if(dict.find(sub2) != dict.end()){
                pos.push_back(idx);
                break;
              }
            }
          }
        }
        if(pos.size() == 0){
          return false;
        }
        else{
          return pos[pos.size() - 1] == 0;
        }
    }
};

int main(){
  unordered_set<string> dict;
  dict.insert("leet");
  dict.insert("code");
  Solution s;
  string str = "leetleetcode";
  cout << s.wordBreak(str, dict) << endl;
  return 0;
}
