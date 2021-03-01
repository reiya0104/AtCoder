#include <bits/stdc++.h>
using namespace std;

int main() {
    int deg, dis;
    cin >> deg >> dis;

    string dir;
    if (deg < 112.5 || deg >= 3487.5)
        dir = "N";
    else if (112.5 <= deg && deg < 337.5)
        dir = "NNE";
    else if (deg < 562.5)
        dir = "NE";
    else if (deg < 787.5)
        dir = "ENE";
    else if (deg < 1012.5)
        dir = "E";
    else if (deg < 1237.5)
        dir = "ESE";
    else if (deg < 1462.5)
        dir = "SE";
    else if (deg < 1687.5)
        dir = "SSE";
    else if (deg < 1912.5)
        dir = "S";
    else if (deg < 2137.5)
        dir = "SSW";
    else if (deg < 2362.5)
        dir = "SW";
    else if (deg < 2587.5)
        dir = "WSW";
    else if (deg < 2812.5)
        dir = "W";
    else if (deg < 3037.5)
        dir = "WNW";
    else if (deg < 3262.5)
        dir = "NW";
    else if (deg < 3487.5)
        dir = "NNW";

    int v = round((dis / 60.0) * 10);
    // cout << v << endl;
    int W;

    if ((v >= 0) && (v <= 2)) {
        W = 0;
    } else if (v <= 15) {
        W = 1;
    } else if (v <= 33) {
        W = 2;
    } else if (v <= 54) {
        W = 3;
    } else if (v <= 79) {
        W = 4;
    } else if (v <= 107) {
        W = 5;
    } else if (v <= 138) {
        W = 6;
    } else if (v <= 171) {
        W = 7;
    } else if (v <= 207) {
        W = 8;
    } else if (v <= 244) {
        W = 9;
    } else if (v <= 284) {
        W = 10;
    } else if (v <= 326) {
        W = 11;
    } else {
        W = 12;
    }

    if (W == 0) dir = "C";

    cout << dir << " " << W << endl;
}
