struct BinaryTrie {
    struct Node {
        Node *ch[2];
        int frq[2];

        Node() {
            memset(ch, 0, sizeof ch);
            memset(frq, 0, sizeof frq);
        }
    };

    Node *root = new Node();
    int mxBit;

    BinaryTrie(int bt) {
        mxBit = bt;
    }

    void insert(int n) {
        Node *curr = root;
        for (int i = mxBit; ~i; --i) {
            int idx = ((1ll << i) & n ? 1 : 0);
            if (curr->ch[idx] == 0) {
                curr->ch[idx] = new Node();
            }
            curr->frq[idx]++;
            curr = curr->ch[idx];
        }
    }

    void del(int n) {
        Node *curr = root;
        del(n, mxBit, curr);;
    }

    void del(int n, int i, Node *cur) {
        if (i == -1)return;
        int idx = ((1ll << i) & n ? 1 : 0);
        del(n, i - 1, cur->ch[idx]);
        cur->frq[idx]--;
        if (cur->frq[idx] == 0) {
            delete cur->ch[idx];
            cur->ch[idx] = nullptr;
        }
    }

    int Query(int x) {
        /// make sure of ur operation Xor? ur goal to find the opposite of ur self : And ? ur goal to find ur self
        Node *curr = root;
        int res{};
        for (int i = mxBit; ~i; --i) {
            int idx = ((1ll << i) & x ? 1 : 0);
            if (curr->ch[!idx] != 0) {
                curr = curr->ch[!idx];
                res |= (1ll << i);
            } else {
                curr = curr->ch[idx];
            }
        }
        return res;
    }
};
