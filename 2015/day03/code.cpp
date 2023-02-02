#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct coordinate {
    int x;
    int y;
};

bool alreadyPresent(vector<coordinate> visited, coordinate element) {
    for(int i = 0; i < visited.size(); i++) {
        if(visited[i].x == element.x && visited[i].y == element.y)
            return true;
    }
    return false;
}

int main() {
    ifstream in("input.txt");
    int x = 0, y = 0, xSanta = 0, ySanta = 0, xRobo = 0, yRobo = 0, result1 = 1, result2 = 1;
    bool santaTurn = true;
    vector<coordinate> visited1, visited2;
    visited1.push_back({0,0});
    visited2.push_back({0,0});
    char c;
    while(in >> c) {
        if(c == '^') {
            y++;
            if(santaTurn)
                ySanta++;
            else
                yRobo++;
        }
        else if(c == 'v') {
            y--;
            if(santaTurn)
                ySanta--;
            else
                yRobo--;
        }
        else if(c == '>') {
            x++;
            if(santaTurn)
                xSanta++;
            else
                xRobo++;
        }
        else if(c == '<') {
            x--;
            if(santaTurn)
                xSanta--;
            else
                xRobo--;
        }
        if(!alreadyPresent(visited1, {x,y})) {
            visited1.push_back({x,y});
            result1++;
        }
        if(santaTurn && !alreadyPresent(visited2, {xSanta,ySanta})) {
            visited2.push_back({xSanta,ySanta});
            result2++;
        }
        else if(!santaTurn && !alreadyPresent(visited2, {xRobo,yRobo})) {
            visited2.push_back({xRobo,yRobo});
            result2++;
        }
        santaTurn = !santaTurn;
    }
    cout << "Part 1: " << result1 << endl;
    cout << "Part 2: " << result2 << endl;
    in.close();
    return 0;
}
