#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

char CUBE[6][3][3];

void TURNTEST() {
    for (int d = 0; d < 6; d++) {
        int tmp = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                CUBE[d][i][j] = '0' + (tmp++);
            }
        }
    }
}

void cubeMemset(string mode) {
    if (mode == "number") {
        TURNTEST();
        return;
    }

    string color = "wyrogb";
    if (mode == "dev") {
        color = "UDFBLR";
    }
    for (int d = 0; d < 6; d++) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                CUBE[d][i][j] = color[d];
            }
        }
    }
}

void turnClock(int side) {
    // 보고있는 면 회전
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
void turnU(bool right) {
    int seq[4] = {2, 4, 3, 5};
    if (!right) {
        // 반시계
        reverse(seq, seq + 4);
    }
    char save[3] = {CUBE[seq[3]][0][0], CUBE[seq[3]][0][1], CUBE[seq[3]][0][2]};
    for (int s = 0; s < 4; s++) {
        for (int j = 0; j < 3; j++) {
            char tmp = CUBE[seq[s]][0][j];
            CUBE[seq[s]][0][j] = save[j];
            save[j] = tmp;
        }
    }
}

void turnD(bool right) {
    int seq[4] = {5, 3, 4, 2};
    if (!right) {
        // 반시계
        reverse(seq, seq + 4);
    }
    char save[3] = {CUBE[seq[3]][2][0], CUBE[seq[3]][2][1], CUBE[seq[3]][2][2]};
    for (int s = 0; s < 4; s++) {
        for (int j = 0; j < 3; j++) {
            char tmp = CUBE[seq[s]][2][j];
            CUBE[seq[s]][2][j] = save[j];
            save[j] = tmp;
        }
    }
}

void turnF(bool right) {
    char save[3] = {CUBE[0][2][0], CUBE[0][2][1], CUBE[0][2][2]};
    if (!right) {
        for (int i = 0; i < 3; i++) {
            char tmp = CUBE[4][2 - i][2];
            CUBE[4][2 - i][2] = save[i];
            save[i] = tmp;
        }
        for (int i = 0; i < 3; i++) {
            char tmp = CUBE[1][0][2 - i];
            CUBE[1][0][2 - i] = save[i];
            save[i] = tmp;
        }
        for (int i = 0; i < 3; i++) {
            char tmp = CUBE[5][i][0];
            CUBE[5][i][0] = save[i];
            save[i] = tmp;
        }

        for (int i = 0; i < 3; i++) {
            char tmp = CUBE[0][2][i];
            CUBE[0][2][i] = save[i];
            save[i] = tmp;
        }
        return;
    }

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

void turnB(bool right) {
    char save[3] = {CUBE[0][0][0], CUBE[0][0][1], CUBE[0][0][2]};
    if (!right) {
        for (int i = 0; i < 3; i++) {
            char tmp = CUBE[5][i][2];
            CUBE[5][i][2] = save[i];
            save[i] = tmp;
        }

        for (int i = 0; i < 3; i++) {
            char tmp = CUBE[1][2][2 - i];
            CUBE[1][2][2 - i] = save[i];
            save[i] = tmp;
        }

        for (int i = 0; i < 3; i++) {
            char tmp = CUBE[4][2 - i][0];
            CUBE[4][2 - i][0] = save[i];
            save[i] = tmp;
        }

        for (int i = 0; i < 3; i++) {
            char tmp = CUBE[0][0][i];
            CUBE[0][0][i] = save[i];
            save[i] = tmp;
        }

        return;
    }
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

void turnL(bool right) {
    char save[3] = {CUBE[0][0][0], CUBE[0][1][0], CUBE[0][2][0]};
    if (!right) {
        for (int i = 0; i < 3; i++) {
            char tmp = CUBE[3][2 - i][2];
            CUBE[3][2 - i][2] = save[i];
            save[i] = tmp;
        }

        for (int i = 0; i < 3; i++) {
            char tmp = CUBE[1][i][0];
            CUBE[1][i][0] = save[i];
            save[i] = tmp;
        }

        for (int i = 0; i < 3; i++) {
            char tmp = CUBE[2][i][0];
            CUBE[2][i][0] = save[i];
            save[i] = tmp;
        }

        for (int i = 0; i < 3; i++) {
            char tmp = CUBE[0][i][0];
            CUBE[0][i][0] = save[i];
            save[i] = tmp;
        }
        return;
    }

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

void turnR(bool right) {
    char save[3] = {CUBE[0][0][2], CUBE[0][1][2], CUBE[0][2][2]};
    if (!right) {
        for (int i = 0; i < 3; i++) {
            char tmp = CUBE[2][i][2];
            CUBE[2][i][2] = save[i];
            save[i] = tmp;
        }

        for (int i = 0; i < 3; i++) {
            char tmp = CUBE[1][i][2];
            CUBE[1][i][2] = save[i];
            save[i] = tmp;
        }

        for (int i = 0; i < 3; i++) {
            char tmp = CUBE[3][i][0];
            CUBE[3][i][0] = save[i];
            save[i] = tmp;
        }

        for (int i = 0; i < 3; i++) {
            char tmp = CUBE[0][2 - i][2];
            CUBE[0][2 - i][2] = save[i];
            save[i] = tmp;
        }
        return;
    }

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
    // bool right = 0;
    // if (rightC == '+') {
    //     right = 1;
    // }

    // if (sideC == 'U') {
    //     turnFace(0, right);
    //     turnU(right);
    // }
    // if (sideC == 'D') {
    //     turnFace(1, right);
    //     turnD(right);
    // }
    // if (sideC == 'F') {
    //     turnFace(2, right);
    //     turnF(right);
    // }
    // if (sideC == 'B') {
    //     turnFace(3, right);
    //     turnB(right);
    // }
    // if (sideC == 'L') {
    //     turnFace(4, right);
    //     turnL(right);
    // }
    // if (sideC == 'R') {
    //     turnFace(5, right);
    //     turnR(right);
    // }
    bool right = 0;
    int k = 3;
    if (rightC == '+') {
        right = 1;
        k = 1;
    }
    if (sideC == 'U') {
        turnFace(0, right);
        for (int i = 0; i < k; i++) turnU(1);
    }
    if (sideC == 'D') {
        turnFace(1, right);
        for (int i = 0; i < k; i++) turnD(1);
    }
    if (sideC == 'F') {
        turnFace(2, right);
        for (int i = 0; i < k; i++) turnF(1);
    }
    if (sideC == 'B') {
        turnFace(3, right);
        for (int i = 0; i < k; i++) turnB(1);
    }
    if (sideC == 'L') {
        turnFace(4, right);
        for (int i = 0; i < k; i++) turnL(1);
    }
    if (sideC == 'R') {
        turnFace(5, right);
        for (int i = 0; i < k; i++) turnR(1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    /**
     * mode = "dev"
     *        "color"
     *        "number"
     */
    string mode = "dev";
    mode = "color";
    string method = "color";
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        cubeMemset(method);
        while (n--) {
            string cmd;
            cin >> cmd;
            if (mode == "dev") {
                cout << '\n' << n << " " << cmd << '\n';
            }
            controller(cmd[0], cmd[1]);
            if (mode == "dev") {
                displaySide(0);
                cout << '\n';
            }
        }
        displaySide(0);
    }
}

// 1 12 D- R+ F+ L+ U- L+ L+ D- B- B- B- B-