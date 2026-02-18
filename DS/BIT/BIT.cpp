/// notes -> make sure to use struct node to flexability to change in struct node only 
/// this version to get summtion of all number less or equal to x in range l , r 
/// but it mandatory to take all elmenats less than or equal to x and all x's 

struct MergeSortTree {
#define md (lx+rx)/2

    struct node {
        vector<int> arr, pre;

        node() {
            arr = vector<int>();
            pre = vector<int>();
        };
    };

    vector<node> seg;
    int sz;

    MergeSortTree(int n) {
        sz = 1;
        while (sz < n) sz *= 2;
        seg = vector<node>(2 * sz);
        build(0, 0, sz - 1);
    }

    void merge(node &parent, node &lf, node &rt) {
        int i = 0; /// idx for lf node
        int j = 0; //// idx for rt node
//        parent.arr.reserve(lf.arr.size() + rt.arr.size());
//        parent.pre.reserve(lf.arr.size() + rt.arr.size());
        int sum{};
        while (i < lf.arr.size() and j < rt.arr.size()) {
            if (lf.arr[i] < rt.arr[j]) {
                sum += lf.arr[i];
                parent.arr.push_back(lf.arr[i]);
                parent.pre.push_back(sum);
                i++;
            } else {
                sum += rt.arr[j];
                parent.arr.push_back(rt.arr[j]);
                parent.pre.push_back(sum);
                j++;
            }
        }
        while (i < lf.arr.size()) {
            sum += lf.arr[i];
            parent.arr.push_back(lf.arr[i]);
            parent.pre.push_back(sum);
            i++;
        }
        while (j < rt.arr.size()) {
            sum += rt.arr[j];
            parent.arr.push_back(rt.arr[j]);
            parent.pre.push_back(sum);
            j++;
        }
    }

    void build(int x, int lx, int rx) {
        if (lx == rx) {
            seg[x] = node();
            if (lx < a.size()) {
                seg[x].arr.push_back(a[lx]);
                seg[x].pre.push_back(a[lx]);
            }
            return;
        }
        build(2 * x + 1, lx, md);
        build(2 * x + 2, md + 1, rx);
        merge(seg[x], seg[2 * x + 1], seg[2 * x + 2]);
    }

    int query(int l, int r, int v, int x, int lx, int rx) {
        if (r < lx or rx < l)return 0;
        if (l <= lx and rx <= r) {  //// here do what you want
            if (seg[x].arr.back() <= v)return seg[x].pre.back();
            auto it = std::upper_bound(seg[x].arr.begin(), seg[x].arr.end(), v);
            if (it == seg[x].arr.begin())return 0;
            int idx = it - seg[x].arr.begin();

            return seg[x].pre[idx - 1];
        }
        return query(l, r, v, 2 * x + 1, lx, md) + query(l, r, v, 2 * x + 2, md + 1, rx);
    }

    int query(int l, int r, int v) {
        return query(l, r, v, 0, 0, sz - 1);
    }

#undef md
};
