// 在线面试平台。将链接分享给你的朋友以加入相同的房间。
// Author: tdzl2003<dengyun@meideng.net>


Description
Given a maze (two dimensional array), there are 4 different characters. # - wall . - empty X - person * - exit

Please find out the shortest time needed for everyone to leave the maze. All people can move at the same time. A person can move one unit (up, down, left, right) in every time unit. It is guaranteed that every “X” is connected to exit.

#X###
*.#X.
..##.
.....
There is only one exit. Multiple people can be in the same place in the same time.






vector<int> shortest_path(vector<vector<char>> &maze) {
	vector<vector<int>> direction = {{0,1}, {0, -1}, {1, 0}, {-1, 0}};
  // find *
  int x, y;
  for (int i = 0; i < maze.size(); i++) {
  	for (int j = 0; j < maze[0].size(); j++) {
    	if (maze[i][j] == '*') {
      	x = i;
        y = j;
        break;
      }
    }
  }
  
  maze[x][y] = '#';
  
  // bfs
  vector<int> result;
  int cur_layers = 0;
  queue<pair<int, int>> cur, next;
  cur.push_back(make_pair(x, y));
  while (!cur.empty()) {
  	auto p = cur.top();
    cur.pop();
    for (vector<int> &bias : direction) {
      int i = p.first + bias[0], j = p.second + bias[1];
      if (i < 0 || i >= maze.size() || j < 0 || j >= maze[0].size() || maze[i][j] == '#') {
        continue;
      }
      
      if (maze[i][j] == '.') {
      	maze[i][j] = '#';
        next.push_back(make_pair(i, j));
      }
      
      if (maze[i][j] == 'X') {
      	result.push_back(cur_layers);
      }
    }
    if (cur.empty()) {
      ++cur_layers;
      swap(cur, next);
    }
  }
  return result;
}



Description
有一个长度是 N 的由大写字母 A-Z 组成的字符串，再给一个包含 M 个短单词的辞典，每个短单词长度不超过 10，对于每个短单词判断是否以 子序列（可以不连续）的形式出现在长字符串中。

abcd bd acd




vector<bool> sub_seq(string s, vector<string> subs) {
	vector<bool> result;
	for (string & sub : subs) {
  	result.push_back(tp(s, sub));
  }
  return result;
}

bool tp(string &s, string &sub) {
	int i, j;
  while (i < s.size() && j < sub.size()) {
  	if (s[i] == sub[j]) {
    	++i;
      ++j;
    } else {
    	++i;
    }
  }
  return j == sub.size();
}






































