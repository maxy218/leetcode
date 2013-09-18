/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  word ladder II
 *
 *        Version:  1.0
 *        Created:  2013年09月10日 21时45分25秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */


#include	<stdlib.h>
#include	<string>
#include	<boost/unordered_set.hpp>
#include	<boost/unordered_map.hpp>
#include	<iostream>
#include	<utility>
using namespace std;
using namespace boost;

class Solution {
    unordered_map<string, bool> ifWordUsed;

    // queue: pair of int and string. int means the layer, for it require to get all the ladders with the same shortest length.
    void getNeighbor(const string& str, int layer, const unordered_set<string> & dict, list<pair<int, string> > & queue){
      string nb = str;
      int len = nb.length();
      for(int i = 0 ; i < len; ++i){
        char tmp = nb[i];
        for(int j = 0; j < 26; ++j){
          nb[i] = 'a' + j;
          if(nb[i] != tmp && dict.find(nb) != dict.end() && !ifWordUsed[nb]){
            queue.push_back(pair<int, string>(layer+1, nb));
            ifWordUsed[nb] = true;
          }
        }
        nb[i] = tmp;
      }
    }

public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(start == end){
          return 2;
        }

        dict.insert(end);
        for(unordered_set<string>::iterator it = dict.begin(); it != dict.end(); ++it){
          ifWordUsed[*it] = false;
        }
        ifWordUsed[start] = true;

        bool ifExistPath = false;
        int destLayer = 0x7fffffff;
        list<pair<int, string> > queue;
        getNeighbor(start, 1, dict, queue);
        while(!queue.empty()){
          pair<int, string> next = queue.front();
          queue.pop_front();
          // if the layer is larger than the dest layer, or the current point is the dest, there'll be no neighbors to be added.
          if(next.first > destLayer) break; // it's not the shortest ladder.
          if(next.second == end){
            ifExistPath = true;
            return next.first;
          }
          //
          else{
            getNeighbor(next.second, next.first, dict, queue);
          }
        }
        if(!ifExistPath) return 0;
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
        string start = "hit";
        string end = "cog";
        unordered_set<string> dict;
        dict.insert("hot");
        dict.insert("dot");
        dict.insert("dog");
        dict.insert("lot");
        dict.insert("log");

        dict.insert("hit");
        dict.insert("cog");

        Solution s;
        int retVal = s.ladderLength(start, end, dict);
        cout << retVal << endl;

	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
