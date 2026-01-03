class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        vector<pair<string, int>> source_map, target_map;
        for (int i = 0; i < indexes.size(); i++) {
            source_map.push_back({sources[i], indexes[i]});
            target_map.push_back({targets[i], indexes[i]});
        }
        sort(source_map.begin(), source_map.end(), [](pair<string, int> &a, pair<string, int> &b) ->bool {return a.second < b.second;});
        sort(target_map.begin(), target_map.end(), [](pair<string, int> &a, pair<string, int> &b) ->bool {return a.second < b.second;});
        sort(indexes.begin(), indexes.end(), [] (int &a, int &b)->bool {return a < b;});
        int bias = 0;
        for (int i  = 0; i < indexes.size(); i++) {
            int ss = source_map[i].first.size(), ts = target_map[i].first.size(), raw_pos = indexes[i], pos = raw_pos + bias;
            if (S.substr(pos, ss) == source_map[i].first) {
                S = S.substr(0, pos) + target_map[i].first + S.substr(pos + ss);
                bias += ts - ss;
            }
        }
        return S;
    }
};

