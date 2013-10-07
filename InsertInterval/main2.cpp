/*
 * =====================================================================================
 *
 *       Filename:  main2.cpp
 *
 *    Description:  Insert Interval
 *
 *        Version:  1.0
 *        Created:  2013年10月07日 10时05分18秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(intervals.size() < 1)
            return vector<Interval>(1, newInterval);
    
        vector<Interval> res;
        int idx = 0;
        int n = intervals.size();
        while(idx < n && newInterval.start > intervals[idx].end){
            res.push_back(intervals[idx++]);
        }
        
        while(idx < n && newInterval.end >= intervals[idx].start){
            newInterval.start = newInterval.start < intervals[idx].start ? newInterval.start : intervals[idx].start;
            newInterval.end = newInterval.end > intervals[idx].end ? newInterval.end : intervals[idx].end;
            ++idx;
        }
        res.push_back(newInterval);
        
        while(idx < n){
            res.push_back(intervals[idx++]);
        }

        return res;
    }
};
