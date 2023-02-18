#include <fstream>
#include <iostream>
using namespace std;

int main() {
    ifstream in("input.txt");
    int totalPaper = 0;
    int totalRibbon = 0;
    int l, w, h;
    char c;
    while (in >> l >> c >> w >> c >> h) {
        totalPaper +=
            2 * l * w + 2 * w * h + 2 * h * l + min(l * w, min(w * h, h * l));
        totalRibbon += 2 * min(l + w, min(w + h, h + l)) + l * w * h;
    }
    cout << "Part 1: " << totalPaper << endl;
    cout << "Part 2: " << totalRibbon << endl;
    in.close();
    return 0;
}
