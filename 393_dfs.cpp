class Solution {
private:
    bool dfs(vector<int>& data, int start) {
        if (start >= data.size()) return true;
        for (int i = 0; i < 4 && i + start < data.size(); i++) {
            switch (i){
                case 0:{
                    if ((data[start] & 0x80) == 0 && dfs(data, start + 1)) return true;
                    break;
                }
                case 1: {
                    if ((data[start] & 0xe0) == 0xc0 && (data[start + 1] & 0xc0) == 0x80 && dfs(data, start + 2)) return true;
                    break;
                }
                    
                case 2: {
                    if ((data[start] & 0xf0) == 0xe0 && (data[start + 1] & 0xc0) == 0x80 && (data[start + 2] & 0xc0) == 0x80 && dfs(data, start + 3)) return true;
                    break;
                }
                    
                case 3:{
                    if ((data[start] & 0xf8) == 0xf0 && (data[start + 1] & 0xc0) == 0x80 && (data[start + 2] & 0xc0) == 0x80 && (data[start + 3] & 0xc0) == 0x80 && dfs(data, start + 4)) return true;
                    break;
                }
                default:
                    break;
            }
        }
        return false;
    }
public:
    bool validUtf8(vector<int>& data) {
        return dfs(data, 0);
    }
};