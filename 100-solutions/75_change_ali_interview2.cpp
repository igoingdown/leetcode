#include <iostream>
#include <string>

using namespace std;

string colors = "RRRRGGGGBBBBGRB";

void swapColors(int i, int j);
int getColor(int i);
int main() {
    int i = 0, rIndex = 0, gIndex = 1, bIndex = 2;
    // r/g/bindex分别表示当前放错位置的R,G,B应该放到的最前面的位置。
    while (i < colors.size()) {
        // 当前格子颜色正确，表明前面的所有格子已经排好序，i向后移动即可。
        if (i % 3 == 0 && getColor(i) == 'R') ++i;
        else if (i % 3 == 1 && getColor(i) == 'G') ++i;
        else if (i % 3 == 2 && getColor(i) == 'B') ++i;
        else {
            // 当前格子颜色不对, 往后跳格子，将当前颜色挪到正确的格子。
            if (getColor(i) == 'R') {
                while (rIndex < colors.size() && getColor(rIndex) == 'R') rIndex += 3;
                if (rIndex < colors.size()) swapColors(i, rIndex);
            } else if (getColor(i) == 'G') {
                while (gIndex < colors.size() && getColor(gIndex) == 'G') gIndex += 3;
                if (gIndex < colors.size()) swapColors(i, gIndex);
            } else if (getColor(i) == 'B') {
                while (bIndex < colors.size() && getColor(bIndex) == 'B') bIndex += 3;
                if (gIndex < colors.size()) swapColors(i, bIndex);
            }
        }
    }
    cout << colors << endl;
}

int getColor(int i) {
    return colors[i];
}

void swapColors(int i, int j) {
    swap(colors[i], colors[j]);
}



