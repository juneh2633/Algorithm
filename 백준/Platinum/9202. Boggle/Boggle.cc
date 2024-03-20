#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
const ll N = 1e5 + 1;
const ll MAX = 1e9;
int scoreRank[9] = {0, 0, 0, 1, 1, 2, 3, 5, 11};
int di[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dj[8] = {0, 1, 1, 1, 0, -1, -1, -1};

string board[4];
struct Trie {
    struct node {
        bool exist = 0;
        node *nxt[26] = {};

        node() {}
        ~node() {
            for (int i = 0; i < 26; i++) {
                if (nxt[i]) delete nxt[i];
            }
        }
    };

    node *head;
    Trie() { head = new node(); }
    ~Trie() { delete head; }

    void insert(string &s) {
        node *cur = head;
        for (char c : s) {
            int idx = c - 'A';
            if (!cur->nxt[idx]) cur->nxt[idx] = new node();
            cur = cur->nxt[idx];
        }
        cur->exist = 1;
    }

    bool find(string &s) {
        node *cur = head;
        for (char c : s) {
            int idx = c - 'A';
            if (!cur->nxt[idx]) return false;
            cur = cur->nxt[idx];
        }
        return cur->exist;
    }

    bool erase(string &s) {
        node *cur = head;
        for (char c : s) {
            int idx = c - 'A';
            if (!cur->nxt[idx]) return false;
            cur = cur->nxt[idx];
        }
        bool exist = cur->exist;
        cur->exist = 0;
        return exist;
    }
    bool havePrefix(string &s) {
        node *cur = head;
        for (char c : s) {
            int idx = c - 'A';
            if (!cur->nxt[idx]) return false;
            cur = cur->nxt[idx];
        }
        return true;
    }
};

Trie trie;
bool vst[4][4] = {
    0,
};
map<string, int> mp;
bool in_range(int i, int j) {
    if (i < 0 || i >= 4) {
        return false;
    }
    if (j < 0 || j >= 4) {
        return false;
    }
    if (vst[i][j]) {
        return false;
    }
    return true;
}

void dfs(int i, int j, string &cur) {
    if (cur.length() >= 9) {
        return;
    }
    if (trie.find(cur)) {
        mp[cur]++;
    }
    if (!trie.havePrefix(cur)) {
        return;
    }
    for (int d = 0; d < 8; d++) {
        int ii = i + di[d];
        int jj = j + dj[d];
        if (!in_range(ii, jj)) {
            continue;
        }
        vst[ii][jj] = 1;
        cur += board[ii][jj];
        dfs(ii, jj, cur);
        vst[ii][jj] = 0;
        cur.pop_back();
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int w;
    cin >> w;

    for (int i = 0; i < w; i++) {
        string s;
        cin >> s;
        trie.insert(s);
    }

    int t;
    cin >> t;
    while (t--) {
        mp.clear();
        for (int i = 0; i < 4; i++) {
            cin >> board[i];
        }
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                string s(1, board[i][j]);
                memset(vst, 0, sizeof(vst));
                vst[i][j] = 1;
                dfs(i, j, s);
                vst[i][j] = 0;
            }
        }
        int score = 0;
        string maxStr = "";
        int curSize = 0;
        for (auto &i : mp) {
            score += scoreRank[i.first.length()];
            if (curSize < i.first.length()) {
                curSize = i.first.length();
                maxStr = i.first;
            }
        }

        cout << score << " " << maxStr << " " << mp.size() << '\n';
    }
}