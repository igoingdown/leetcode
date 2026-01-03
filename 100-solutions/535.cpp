class Solution {
private:
    unordered_map<string, string> url2code;
    unordered_map<string, string> code2url;
    string alphabet;
    
    void changeAlphabet(char begin, char end) {
        for (char c = begin; c <= end; c++) {
            alphabet.push_back(c);
        }
    }
public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if (alphabet == "") {
            changeAlphabet('0', '9');
            changeAlphabet('A', 'Z');
            changeAlphabet('a', 'z');
        }
        string code = "";
        while (url2code.find(longUrl) == url2code.end()) {
            code = "";
            srand((unsigned)time(NULL));
            for (int i = 0; i < 6; i++) {
                int idx = rand() % (alphabet.size());
                code.push_back(alphabet[idx]);
            }
            if (code2url.find(code) == code2url.end()) {
                code2url[code] = longUrl;
                url2code[longUrl] = code;
            }
        }
        return string("http://tinyurl.com/") += code;
    }
    
    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string code = shortUrl.substr(shortUrl.size() - 6, 6);
        return code2url[code];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
