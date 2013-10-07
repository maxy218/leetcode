/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Insert Interval
 *
 *        Version:  1.0
 *        Created:  2013年10月07日 09时11分27秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include	<iostream>
#include	<vector>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}

    friend ostream& operator<< (ostream& out, Interval it);
};

ostream& operator<< (ostream& out, Interval it){
  out << "[" << it.start << ", " << it.end << "]";
}

class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(intervals.size() < 1)
            return vector<Interval>(1, newInterval);
        
        int l = 0, r = intervals.size() - 1;
        int searchRes1 = -1;
        bool ifSuc1 = false;
        //search the start point at first
        while(r >= l){
          int mid = l + ((r - l) >> 1);
          if(newInterval.start >= intervals[mid].start && newInterval.start <= intervals[mid].end){
            ifSuc1 = true;
            searchRes1 = mid;
            break;
          }
          else if(newInterval.start > intervals[mid].end){
            l = mid + 1;
          }
          else{
            r = mid - 1;
          }
        }
        if(!ifSuc1)
          searchRes1 = r;

        int searchRes2 = -1;
        bool ifSuc2 = false;
        //search the end point at first
        l = 0; r = intervals.size() - 1;
        while(r >= l){
          int mid = l + ((r - l) >> 1);
          if(newInterval.end>= intervals[mid].start && newInterval.end <= intervals[mid].end){
            ifSuc2 = true;
            searchRes2 = mid;
            break;
          }
          else if(newInterval.end > intervals[mid].end){
            l = mid + 1;
          }
          else{
            r = mid - 1;
          }
        }
        if(!ifSuc2)
          searchRes2 = r;
        
        int removedItvStart = ifSuc1 ? searchRes1 : searchRes1 + 1;
        int removedItvEnd = searchRes2;
        int newItvStart = ifSuc1 ? intervals[removedItvStart].start : newInterval.start;
        int newItvEnd = ifSuc2 ? intervals[removedItvEnd].end : newInterval.end;

        vector<Interval> res;
        int idx = 0;
        while(idx < removedItvStart){
          res.push_back(intervals[idx++]);
        }

        res.push_back(Interval(newItvStart, newItvEnd));

        idx = removedItvEnd + 1;
        while(idx < intervals.size()){
          res.push_back(intervals[idx++]);
        }
        return res;
    }
};

void output(const vector<Interval>& itvs){
  for(int i = 0; i < itvs.size(); ++i){
    cout << itvs[i] << ", ";
  }
  cout << endl;
}

int main(){
  Solution s;
  vector<Interval> itvs;
  itvs.push_back(Interval(1,2));
  itvs.push_back(Interval(3,5));
  itvs.push_back(Interval(6,7));
  itvs.push_back(Interval(8,10));
  itvs.push_back(Interval(12,16));
  vector<Interval> res = s.insert(itvs,Interval(4, 9));
  output(res);
}

