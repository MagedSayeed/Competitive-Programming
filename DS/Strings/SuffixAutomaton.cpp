/**
 * Suffix Automaton:
 *  - Efficient data structure to represent all substrings of a given string.
 *  - Each state represents a set of substrings that share the same end positions.
 *
 * Construction:
 *  - `addChar(c)` adds a character to the automaton and builds transitions.
 *  - Maintains suffix links to enable efficient traversal.
 *  - For a string of length N, the automaton has at most 2*N - 1 states.
 *
 * Components:
 *  - `st[i]`: Represents a state with:
 *      - `len`: Length of the longest string in this state.
 *      - `link`: Suffix link (points to the largest proper suffix state).
 *      - `cnt`: Number of occurrences of substrings ending at this state.
 *      - `next`: Transitions to other states by character.
 *  - `last`: The current last state (for appending).
 *  - `dp[i]`: Stores number of distinct substrings starting from state `i`.
 *
 * Features:
 *  - `checkForOccurrence(s)`: Checks if string `s` exists as a substring.
 *  - `numberOfSubstrings()`: Counts total number of distinct substrings.
 *  - `lengthOfSubstrings()`: Sum of lengths of all distinct substrings.
 *  - `numberOfOcc(s)`: Returns number of times string `s` occurs.
 *  - `getKthLex(k, ans)`: Returns the k-th lexicographically smallest substring.
 *
 * Preprocessing:
 *  - `numberOfOccPreProcess()`:
 *      - Prepares `cnt` and `dp` for substring occurrence queries.
 *      - Must be called before `numberOfOcc` or `getKthLex`.
 *
 * Complexity:
 *  - Time: O(N) per character during construction.
 *  - Space: O(N) states and transitions for input of length N.
 */
struct SuffixAutomaton {
#define ll long long
#define ii pair<int,int>
#define S second
#define F first
  static const int N = 1e5 + 5;
  int last = 0, cntState = 1;
  struct state {
    int len = 0, link = -1, cnt = 0;
    map<char, int> next;
  };

  state st[N * 2];
  ll dp[N * 2];

  void addChar(char c) {
    int p = last;
    int cur = cntState++;
    st[cur].len = st[last].len + 1;
    st[cur].cnt = 1;
    while (p != -1 && st[p].next.count(c) == 0) {
      st[p].next[c] = cur;
      p = st[p].link;
    }
    if (p == -1) {
      st[cur].link = 0;
    } else {
      int q = st[p].next[c];
      if (st[q].len == st[p].len + 1) {
        st[cur].link = q;
      } else {
        int clone = cntState++;
        st[clone].link = st[q].link;
        st[clone].len = st[p].len + 1;
        st[q].link = st[cur].link = clone;
        st[clone].next = st[q].next;
        st[clone].cnt = 0;
        while (p != -1 && st[p].next[c] == q) {
          st[p].next[c] = clone;
          p = st[p].link;
        }
      }
    }
    last = cur;
  }

  SuffixAutomaton() {}

  SuffixAutomaton(const string &s) { for (char c: s)addChar(c); }

  bool checkForOccurrence(const string &str) {
    int cur = 0;
    for (char i: str) {
      if (st[cur].next.count(i)) {
        cur = st[cur].next[i];
      } else {
        return false;
      }
    }
    return true;
  }

  ll numberOfSubstrings() {
    ll ans = 0;
    for (int i = 1; i < cntState; i++) {
      ans += st[i].len - st[st[i].link].len;
    }
    return ans;
  }

  ll lengthOfSubstrings() {
    auto getSum = [&](ll x) -> ll {
      return x * (x + 1) / 2;
    };
    ll ans = 0;
    for (int i = 1; i < cntState; i++) {
      ans += getSum(st[i].len) - getSum(st[st[i].link].len);
    }
    return ans;
  }

  void numberOfOccPreProcess() {
    static bool visisted = false;
    if (visisted)return;
    visisted = true;
    vector<ii > v;
    for (int i = 0; i < cntState; i++)
      v.emplace_back(st[i].len, i);
    sort(v.rbegin(), v.rend());
    for (int i = 0; i < cntState; i++) {
      if (st[v[i].S].link > 0)
        st[st[v[i].S].link].cnt += st[v[i].S].cnt;
      dp[v[i].S] = st[v[i].S].cnt;
      for (auto x: st[v[i].S].next) {
        dp[v[i].S] += dp[x.S];
      }
    }

  }

  ll numberOfOcc(const string &s) {
    numberOfOccPreProcess();
    int cur = 0;
    for (char c: s) {
      if (st[cur].next.count(c)) {
        cur = st[cur].next[c];
      } else
        return 0;
    }
    return st[cur].cnt;
  }

  void dfs(int node, ll &k, string &ans) {
    k -= st[node].cnt;
    if (k <= 0)return;
    for (auto x: st[node].next) {
      if (dp[x.S] < k) {
        k -= dp[x.S];
      } else {
        ans.push_back(x.F);
        dfs(x.S, k, ans);
        return;
      }
    }
  }

  bool getKthLex(ll k, string &ans) {
    ans = "";
    numberOfOccPreProcess();
    if (dp[0] < k) return false;
    dfs(0, k, ans);
    return true;
  }

#undef ii
#undef ll
#undef F
#undef S
};
