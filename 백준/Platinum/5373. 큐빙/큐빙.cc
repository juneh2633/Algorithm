#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

char CUBE[6][3][3];
string color = "wyrogb";
void cubeMemset() {
    for (int d = 0; d < 6; d++) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                CUBE[d][i][j] = color[d];
            }
        }
    }
}

void turnClock(int side) {
    char save[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            save[i][j] = CUBE[side][2 - j][i];
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            CUBE[side][i][j] = save[i][j];
        }
    }
}

void turnCountClock(int side) {
    char save[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            save[i][j] = CUBE[side][j][2 - i];
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            CUBE[side][i][j] = save[i][j];
        }
    }
}

void turnFace(int side, int right) {
    if (right) {
        turnClock(side);
        return;
    }
    turnCountClock(side);
}
void turnU() {
    int seq[4] = {2, 4, 3, 5};
    char save[3] = {CUBE[seq[3]][0][0], CUBE[seq[3]][0][1], CUBE[seq[3]][0][2]};
    for (int s = 0; s < 4; s++) {
        for (int j = 0; j < 3; j++) {
            char tmp = CUBE[seq[s]][0][j];
            CUBE[seq[s]][0][j] = save[j];
            save[j] = tmp;
        }
    }
}

void turnD() {
    int seq[4] = {5, 3, 4, 2};
    char save[3] = {CUBE[seq[3]][2][0], CUBE[seq[3]][2][1], CUBE[seq[3]][2][2]};
    for (int s = 0; s < 4; s++) {
        for (int j = 0; j < 3; j++) {
            char tmp = CUBE[seq[s]][2][j];
            CUBE[seq[s]][2][j] = save[j];
            save[j] = tmp;
        }
    }
}

void turnF() {
    char save[3] = {CUBE[0][2][0], CUBE[0][2][1], CUBE[0][2][2]};

    for (int i = 0; i < 3; i++) {
        char tmp = CUBE[5][i][0];
        CUBE[5][i][0] = save[i];
        save[i] = tmp;
    }

    for (int i = 0; i < 3; i++) {
        char tmp = CUBE[1][0][2 - i];
        CUBE[1][0][2 - i] = save[i];
        save[i] = tmp;
    }

    for (int i = 0; i < 3; i++) {
        char tmp = CUBE[4][2 - i][2];
        CUBE[4][2 - i][2] = save[i];
        save[i] = tmp;
    }

    for (int i = 0; i < 3; i++) {
        char tmp = CUBE[0][2][i];
        CUBE[0][2][i] = save[i];
        save[i] = tmp;
    }
}

void turnB() {
    char save[3] = {CUBE[0][0][0], CUBE[0][0][1], CUBE[0][0][2]};

    for (int i = 0; i < 3; i++) {
        char tmp = CUBE[4][2 - i][0];
        CUBE[4][2 - i][0] = save[i];
        save[i] = tmp;
    }
    for (int i = 0; i < 3; i++) {
        char tmp = CUBE[1][2][2 - i];
        CUBE[1][2][2 - i] = save[i];
        save[i] = tmp;
    }
    for (int i = 0; i < 3; i++) {
        char tmp = CUBE[5][i][2];
        CUBE[5][i][2] = save[i];
        save[i] = tmp;
    }

    for (int i = 0; i < 3; i++) {
        char tmp = CUBE[0][0][i];
        CUBE[0][0][i] = save[i];
        save[i] = tmp;
    }
}

void turnL() {
    char save[3] = {CUBE[0][0][0], CUBE[0][1][0], CUBE[0][2][0]};

    for (int i = 0; i < 3; i++) {
        char tmp = CUBE[2][i][0];
        CUBE[2][i][0] = save[i];
        save[i] = tmp;
    }

    for (int i = 0; i < 3; i++) {
        char tmp = CUBE[1][i][0];
        CUBE[1][i][0] = save[i];
        save[i] = tmp;
    }

    for (int i = 0; i < 3; i++) {
        char tmp = CUBE[3][2 - i][2];
        CUBE[3][2 - i][2] = save[i];
        save[i] = tmp;
    }

    for (int i = 0; i < 3; i++) {
        char tmp = CUBE[0][i][0];
        CUBE[0][i][0] = save[i];
        save[i] = tmp;
    }
}

void turnR() {
    char save[3] = {CUBE[0][0][2], CUBE[0][1][2], CUBE[0][2][2]};

    for (int i = 0; i < 3; i++) {
        char tmp = CUBE[3][2 - i][0];
        CUBE[3][2 - i][0] = save[i];
        save[i] = tmp;
    }

    for (int i = 0; i < 3; i++) {
        char tmp = CUBE[1][i][2];
        CUBE[1][i][2] = save[i];
        save[i] = tmp;
    }

    for (int i = 0; i < 3; i++) {
        char tmp = CUBE[2][i][2];
        CUBE[2][i][2] = save[i];
        save[i] = tmp;
    }

    for (int i = 0; i < 3; i++) {
        char tmp = CUBE[0][i][2];
        CUBE[0][i][2] = save[i];
        save[i] = tmp;
    }
}
void displaySide(int side) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << CUBE[side][i][j];
        }
        cout << '\n';
    }
}

void controller(char sideC, char rightC) {
    bool right = 0;
    int k = 3;
    if (rightC == '+') {
        right = 1;
        k = 1;
    }
    if (sideC == 'U') {
        turnFace(0, right);
        for (int i = 0; i < k; i++) turnU();
    }
    if (sideC == 'D') {
        turnFace(1, right);
        for (int i = 0; i < k; i++) turnD();
    }
    if (sideC == 'F') {
        turnFace(2, right);
        for (int i = 0; i < k; i++) turnF();
    }
    if (sideC == 'B') {
        turnFace(3, right);
        for (int i = 0; i < k; i++) turnB();
    }
    if (sideC == 'L') {
        turnFace(4, right);
        for (int i = 0; i < k; i++) turnL();
    }
    if (sideC == 'R') {
        turnFace(5, right);
        for (int i = 0; i < k; i++) turnR();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cubeMemset();
        while (n--) {
            string cmd;
            cin >> cmd;
            controller(cmd[0], cmd[1]);
        }
        displaySide(0);
    }
}
