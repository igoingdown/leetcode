void dfs(string &s, int pos, string &res) {
 if (pos >= s.size()) {
   cout << res << endl;
    return;
  }
  if (s[pos] == '0') {
   return;
  } 
  res.push_back('a' + s[pos] - '1');
  dfs(s, pos+1, res);
  res.pop_back();
  
  if (pos + 1 < s.size() && (s[pos] - '0') * 10 + s[pos] - '1' < 26) {
    res.push_back('a' + (s[pos] - '1') * 10 + (s[pos+1] - '1'))
   dfs(s, pos+2, res);
   res.pop_back();
  }  
}
