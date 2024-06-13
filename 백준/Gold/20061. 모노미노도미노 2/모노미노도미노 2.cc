#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

deque<int> green[4];
deque<int> blue[4];
int greenScore;
int blueScore;

void popBackGreen(int t) {
    for (int j = 0; j < 4; j++) {
        for (int x = 0; x < t; x++) {
            green[j].pop_back();
            green[j].push_front(0);
        }
    }
}
void popBackBlue(int t) {
    for (int i = 0; i < 4; i++) {
        for (int x = 0; x < t; x++) {
            blue[i].pop_back();
            blue[i].push_front(0);
        }
    }
}

bool scoreCheckGreen() {
    bool change = 0;
    for (int i = 5; i > 0;) {
        bool flag = 0;
        for (int j = 0; j < 4; j++) {
            if (green[j][i] == 0) {
                flag = 1;
                break;
            }
        }

        if (flag) {
            i--;
            continue;
        }
        greenScore++;
        change = true;
        for (int j = 0; j < 4; j++) {
            green[j].erase(green[j].begin() + i);
            green[j].push_front(0);
        }
    }
    return change;
}

bool scoreCheckBlue() {
    bool change = 0;
    for (int j = 5; j > 0;) {
        bool flag = 0;
        for (int i = 0; i < 4; i++) {
            if (blue[i][j] == 0) {
                flag = 1;
                break;
            }
        }

        if (flag) {
            j--;
            continue;
        }
        blueScore++;
        change = true;
        for (int i = 0; i < 4; i++) {
            blue[i].erase(blue[i].begin() + j);
            blue[i].push_front(0);
        }
    }
    return change;
}
void putOnGreen(int i, int j, int t) {
    int tmpI = 0;
    if (t == 1) {
        while (tmpI < 5 && green[j][tmpI + 1] == 0) {
            tmpI++;
        }
        green[j][tmpI] = 1;
        if (tmpI == 1) {
            // popBackGreen(1);
        }
    }
    if (t == 2) {
        while (tmpI < 5 && green[j][tmpI + 1] == 0 &&
               green[j + 1][tmpI + 1] == 0) {
            tmpI++;
        }
        green[j][tmpI] = 1;
        green[j + 1][tmpI] = 1;

        if (tmpI == 1) {
            // popBackGreen(1);
        }
    }
    if (t == 3) {
        while (tmpI < 5 && green[j][tmpI + 1] == 0) {
            tmpI++;
        }
        green[j][tmpI] = 1;
        green[j][tmpI - 1] = 1;
        // if (tmpI == 1) {
        //     popBackGreen(2);
        // } else if (tmpI == 2) {
        //     if (!scoreCheckGreen()) {
        //         popBackGreen(1);
        //     }
        // }
    }
}
void putOnBlue(int i, int j, int t) {
    int tmpJ = 0;
    if (t == 1) {
        while (tmpJ < 5 && blue[i][tmpJ + 1] == 0) {
            tmpJ++;
        }
        blue[i][tmpJ] = 1;
        // if (tmpJ == 1) {
        //     popBackBlue(1);
        // }
    }
    if (t == 3) {
        while (tmpJ < 5 && blue[i][tmpJ + 1] == 0 &&
               blue[i + 1][tmpJ + 1] == 0) {
            tmpJ++;
        }
        blue[i][tmpJ] = 1;
        blue[i + 1][tmpJ] = 1;
        // if (tmpJ == 1) {
        //     popBackBlue(1);
        // }
    }
    if (t == 2) {
        while (tmpJ < 5 && blue[i][tmpJ + 1] == 0) {
            tmpJ++;
        }
        blue[i][tmpJ] = 1;
        blue[i][tmpJ - 1] = 1;
        // if (tmpJ == 1) {
        //     popBackBlue(2);
        // } else if (tmpJ == 2) {
        //     popBackBlue(1);
        //     if (!scoreCheckBlue()) {
        //         popBackBlue(1);
        //     }
        // }
    }
}
void popCheck() {
    for (int j = 0; j < 4; j++) {
        if (green[j][1] == 1) {
            popBackGreen(1);
        }
        if (blue[j][1] == 1) {
            popBackBlue(1);
        }
    }
}

void controller(int t, int i, int j) {
    putOnGreen(i, j, t);
    putOnBlue(i, j, t);
    scoreCheckGreen();
    scoreCheckBlue();
    popCheck();
    popCheck();
}

void debug() {
    cout << '\n';
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 4; j++) {
            cout << green[j][i] << " ";
        }
        cout << '\n';
    }
}
void input() {
    int n;
    cin >> n;

    while (n--) {
        int t, i, j;
        cin >> t >> i >> j;
        controller(t, i, j);
    }
}
void firstSet() {
    int t = 6;
    greenScore = 0;
    blueScore = 0;
    while (t--) {
        for (int j = 0; j < 4; j++) {
            green[j].push_back(0);
            blue[j].push_back(0);
        }
    }
}
void showAns() {
    int a = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 6; j++) {
            if (green[i][j] == 1) {
                a++;
            }
            if (blue[i][j] == 1) {
                a++;
            }
        }
    }
    cout << blueScore + greenScore << '\n' << a;
    // debug();
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    firstSet();
    input();
    showAns();
}
