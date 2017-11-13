#include <iostream>
#include <vector>
#include <string>

using namespace std;

string predictPartyVictory(string senate);

int main(int argc, char const *argv[])
{
	/* code */
	cout << predictPartyVictory("DDDDRRDDDRDRDRRDDRDDDRDRRRRDRRRRRDRDDRDDRRDDRRRDDRRRDDDDRRRRRRRDDRRRDDRDDDRRRDRDDRDDDRRDRRDRRRDRDRDR") << endl;
	return 0;
}

string predictPartyVictory(string senate) {
    int d_count = 0, r_count = 0, d_skip = 0, r_skip = 0;
    for (int i = 0; i < senate.size(); i++) {
        char c = senate[i];
        if (c == 'D') {
            if (d_skip == 0) {
                d_count++;
                r_skip++;
            } else {
                d_skip--;
            }
        } else {
            if (r_skip == 0) {
                r_count++;
                d_skip++;
            } else {
                r_skip--;;
            }
        }
        cout << i + 1 << ": "<< c << " " << d_count << " " << d_skip << " " << r_count << " " << r_skip << endl;
        if ((i + 1 )% 5 == 0) cout << "" << endl;
    }
    
    if (r_count != d_count) return r_count > d_count ? "Radiant" : "Dire";
    else return senate[senate.size() - 1] == 'D' ? "Dire" : "Radiant";
}