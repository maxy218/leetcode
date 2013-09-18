#include <iostream>
#include <string>
#include <list>
#include <map>
#include <vector>
using namespace std;

// key:(start, end), value: 1->true, -1->false; 0->not set
map<pair<int, int>, int> ifPalMap;

bool ifPalindrome(const string & str, int s, int e){
  if(ifPalMap[pair<int, int>(s,e)] == 1){
    return true;
  }
  else if(ifPalMap[pair<int, int>(s,e)] == -1){
    return false;
  }

  while(s < e){
    if(str[s] != str[e]) {
      ifPalMap[pair<int, int>(s, e)] = -1;
      return false;
    }
    ++s; --e;
  }
  ifPalMap[pair<int,int>(s, e)] = 1;
  return true;
}

void r_getPalindrome(const string& str, int start, int end, vector<string>& l_str, vector<vector<string> >& result){
  int len = str.length();
  if(start == 0 && end == 0){// inintialize the ifPalMap
    for(int i = 0; i < len; ++i)
      ifPalMap = map<pair<int, int> , int>();
    for(int i = 0; i < len; ++i){
      for(int j = i; j < len; ++j){
        ifPalMap[pair<int,int>(i, j)] = 0;
      }
    }
  }

  if(end == len){
    result.push_back(l_str);
    return;
  }

  bool ifLastPal = false;
  while(end < len){
    if(ifPalindrome(str, start, end)){
      ifLastPal = true;
      l_str.push_back(str.substr(start, end-start+1));
      r_getPalindrome(str, end+1, end+1, l_str, result);
      l_str.pop_back();
    }
    else{
      ifLastPal = false;
    }
    ++end;
  }
}

vector<vector<string> > partition(string s){
  vector<vector<string> > result;
  vector<string> v_str;
  r_getPalindrome(s, 0, 0, v_str, result);
  return result;
}

int main(){
  map<pair<int, int>, int> ifPalMap;
  string str = "aab";
  vector<vector<string> > r = partition(str);
  for(int i = 0; i < r.size(); ++i){
    for(int j = 0; j < r[i].size(); ++j){
      cout << r[i][j] << ", ";
    }
    cout << endl;
  }

  return 0; 
}

