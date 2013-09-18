#include <iostream>
#include <vector>
#include <list>
#include <utility>
using namespace std;

class Solution {
    // this function will mark the non-surrounded 'O' with 'Y'. At the end of the "solve" function, mark the 'O' with 'X' and mark the 'Y' with 'O'
    void BFSMarkY(vector<vector<char> > &board, int i, int j, list<pair<int, int> > & queue){ 
      while(board[i][j] == 'O' || queue.size() != 0){
        if(board[i][j] == 'O'){
          board[i][j] = 'Y';
          queue.push_back(pair<int,int>(i+1, j));
          queue.push_back(pair<int,int>(i-1, j));
          queue.push_back(pair<int,int>(i, j+1));
          queue.push_back(pair<int,int>(i, j-1));
        }
        else{
          pair<int,int> tmp = queue.front();
          queue.pop_front();
          while(queue.size() > 0 && !(tmp.first >=0 && tmp.first < board.size() && tmp.second >= 0 && tmp.second < board[0].size())){
            tmp = queue.front();
            queue.pop_front();
          }
          i = tmp.first;
          j = tmp.second;
        }
      }
    }
public:
    void solve(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(board.size() == 0 || board[0].size() == 0) return;

        list<pair<int,int> > queue;
        int height = board.size(); int width = board[0].size();
        for(int i = 0; i < height; ++i){
          if(board[i][0] == 'O') { queue.clear(); BFSMarkY(board, i, 0, queue);}
          if(board[i][width - 1] == 'O') { queue.clear(); BFSMarkY(board, i, width - 1, queue);}
        }
        for(int j = 0; j < width; ++j){
          list<pair<int,int> > queue;
          if(board[0][j] == 'O') { queue.clear(); BFSMarkY(board, 0, j, queue);}
          if(board[height - 1][j] == 'O') { queue.clear(); BFSMarkY(board, height - 1, j, queue);}
        }
        for(int i = 0; i < height; ++i){
          for(int j = 0; j < width; ++j){
            if(board[i][j] == 'O') board[i][j] = 'X';
            else if(board[i][j] == 'Y') board[i][j] = 'O';
          }
        }
    }
};

void output(vector<vector<char> >& board){
  int height = board.size(); int width = board[0].size();
  for(int i = 0; i < height; ++i){
    for(int j = 0; j < width; ++j){
      cout << board[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

int main(){
  Solution s;
  vector<vector<char> > vec;
  vector<char> subVec = vector<char>(4);
  subVec[0] = 'X'; subVec[1] = 'X'; subVec[2] = 'X'; subVec[3] = 'X';
  vec.push_back(subVec);
  subVec = vector<char>(4);
  subVec[0] = 'X'; subVec[1] = 'O'; subVec[2] = 'O'; subVec[3] = 'X';
  vec.push_back(subVec);
  subVec = vector<char>(4);
  subVec[0] = 'X'; subVec[1] = 'X'; subVec[2] = 'O'; subVec[3] = 'X';
  vec.push_back(subVec);
  subVec = vector<char>(4);
  subVec[0] = 'X'; subVec[1] = 'O'; subVec[2] = 'X'; subVec[3] = 'X';
  vec.push_back(subVec);

  output(vec);
  s.solve(vec);
  output(vec);
  return 0;
}

