/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/16/2013 07:10:20 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include	<iostream>
#include	<string>
#include	<vector>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(path.length() == 0)
          return "";
        int idx = 0;
        vector<string> stack;
        for(; idx < path.length(); ++idx){
          if(path[idx] == '/')
            continue;
          if(path[idx] == '.'){
            if( (idx + 2 < path.length() && path[idx + 1] == '.' && path[idx + 2] == '/') || (idx + 2 == path.length() && path[idx + 1] == '.')){// "/../".   if not "..", check whether it's "/./"
              idx += 2;
              if(stack.size() > 0)
                stack.pop_back();
              continue;
            }
            else if((idx + 1 < path.length() && path[idx + 1] == '/') || (idx + 1 == path.length())){ // if "/./", do nothing. else, if ".hidden" or something, return ".hidden"
              ++idx;
              continue;
            }
          }
          int r = idx + 1;
          while(r < path.length() && path[r] != '/')
            ++r;
          stack.push_back(path.substr(idx, r - idx));
          idx = r - 1;
        }
        if(stack.size() == 0)
          return "/";
        string ret = "";
        for(int i = 0; i < stack.size(); ++i){
          ret += "/" + stack[i];
        }
        return ret;
    }
};

int main(){
  Solution s;
  cout << s.simplifyPath("/home/") << endl;
  cout << s.simplifyPath("/a/./b/../../c/") << endl;
  cout << s.simplifyPath("/../") << endl;
  cout << s.simplifyPath("/home//foo/") << endl;
  cout << s.simplifyPath("/.hidden") << endl;
  cout << s.simplifyPath("/.") << endl;
  cout << s.simplifyPath("/..") << endl;
  cout << s.simplifyPath("/a/..") << endl;
}

