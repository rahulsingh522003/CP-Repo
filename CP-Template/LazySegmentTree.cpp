// This code is for lazy segment tree of finding minimum in a range

class LazySegmentTree{
    vector<int>seg;
    vector<int>lazy;
public:
    LazySegmentTree(int n)
    {
        seg.resize(4*n);
        lazy.resize(4*n);
    }
    void build(int low, int high, int ind, vector<int>&arr)
    {
        if(low == high)
        {
            seg[ind] = arr[low];
            return;
        }
        int mid = (low + high)>>1ll;
        build(low,mid,2*ind+1,arr);
        build(mid+1,high,2*ind+2,arr);
        seg[ind] = min(seg[2*ind+1],seg[2*ind+2]);
    }

    void update(int low, int high, int ind, int l, int r, int val)
    {
        // update lazy tree
        if(lazy[ind] != 0)
        {
            seg[ind] += lazy[ind];
            if(low != high)
            {
                lazy[2*ind+1] += lazy[ind];
                lazy[2*ind+2] += lazy[ind];
            }
            lazy[ind] = 0;
        }

        // no overlap low high l r low high
        if(l > high || r < low)
            return;

        // complete overlap l low high r
        if(low >= l && high <= r)
        {
            seg[ind] += val;
            if(low != high)
            {
                lazy[2*ind+1] += val;
                lazy[2*ind+2] += val;
            }
            return;
        }

        int mid = (low + high)>>1ll;
        update(low,mid,2*ind+1,l,r,val);
        update(mid+1,high,2*ind+2,l,r,val);
        seg[ind] = min(seg[2*ind+1],seg[2*ind+2]);
    }

    int query(int low, int high, int ind, int l, int r)
    {
        if(lazy[ind] != 0)
        {
            seg[ind] += lazy[ind];
            if(low != high)
            {
                lazy[2*ind+1] += lazy[ind];
                lazy[2*ind+2] += lazy[ind];
            }
            lazy[ind] = 0;
        }

        // no overlap l r low high l r
        if(r < low || high < l)
            return 1e18;

        // complete overlap l low high r
        if(low >= l && high <= r)
            return seg[ind];

        int mid = (low + high) >> 1ll;
        int left = query(low,mid,2*ind+1,l,r);
        int right = query(mid+1,high,2*ind+2,l,r);
        return min(left,right);

    }

};
