#include <fstream>
#include <iostream>
using namespace std;

int main() {
    ifstream in("input.txt");
    int floor = 0;
    int pos = 0;
    int finalPos = 0;
    bool found = false;
    char c;
    while (in >> c) {
        if (!found) {
            pos++;
        }
        if (c == '(') {
            floor++;
        } else {
            floor--;
        }
        if (floor == -1) {
            finalPos = pos;
            found = true;
        }
    }
    cout << "Part 1: " << floor << endl;
    cout << "Part 2: " << finalPos << endl;
    in.close();
    return 0;
}
