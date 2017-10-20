class Twitter {
private:
    unordered_map<int, vector<int> > u2p;
    unordered_map<int, unordered_set<int> > r2e;
    unordered_map<int, int> id2i;
    int total_post;
    void max_heapify(vector<int>& s, int b, int e) {
        int cur = b, child = 2 * b + 1;
        while (child < e) {
            if (child + 1 < e && (id2i[s[child]] < id2i[s[child + 1]])) {
                child++;
            }
            if (id2i[s[cur]] < id2i[s[child]]) {
                swap(s[cur], s[child]);
                cur = child;
                child = 2 * child + 1;
            } else {
                break;
            }
        }
    }
public:
    /** Initialize your data structure here. */
    Twitter() {
        total_post = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        if (u2p.find(userId) == u2p.end()) {
            u2p[userId] = vector<int> (1, tweetId);
        } else {
            u2p[userId].push_back(tweetId);
        }
        total_post++;
        id2i[tweetId] = total_post;
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> posts(u2p[userId].begin(), u2p[userId].end());
        for (int u : r2e[userId]) {
            for (int p : u2p[u]) {
                posts.push_back(p);
            }
        }
        int s = posts.size();
        for (int i = s / 2; i >= 0; i--) {
            max_heapify(posts, i, s);
        }
        vector<int> res;
        for (int i = s - 1; i >= 0 && i >= s - 10; i--) {
            swap(posts[i], posts[0]);
            res.push_back(posts[i]);
            max_heapify(posts, 0, i);
        }
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) {
            return;
        }
        if (r2e.find(followerId) == r2e.end()) {
            r2e[followerId] = unordered_set<int> (0);
        }
        r2e[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId) {
            return;
        }
        r2e[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */