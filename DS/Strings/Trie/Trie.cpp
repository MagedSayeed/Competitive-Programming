struct Trie {
    int sz;  //// update this
    char ignore = '0';//// update this
    struct Node {
        Node *ch[10]; /// map?
        int Prefix, End;

        Node() {
            Prefix = End = 0;
            memset(ch, 0, sizeof ch);
        }
    };

    Node *root = new Node();

    void insert(string &s) {
        Node *cur = root;
        for (auto it: s) {
            int idx = it - ignore;
            if (cur->ch[idx] == 0) {
                cur->ch[idx] = new Node();
            }
            cur = cur->ch[idx];
            cur->Prefix++;
        }
        cur->End++;
    }

    int countEnd(string &s) {
        Node *cur = root;
        for (auto it: s) {
            int idx = it - ignore;
            if (cur->ch[idx] == 0) {
                return 0;
            }
            cur = cur->ch[idx];
        }
        return cur->End;
    }

    int countPrefix(string &s) {
        Node *cur = root;
        for (auto it: s) {
            int idx = it - ignore;
            if (cur->ch[idx] == 0) {
                return 0;
            }
            cur = cur->ch[idx];
        }
        return cur->Prefix;
    }
};
