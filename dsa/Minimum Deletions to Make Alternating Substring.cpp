#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    struct Node
    {
        // dp[a][b]
        // maximum alternating subsequence length
        // starting with a and ending with b
        int dp[2][2];
        Node()
        {
            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < 2; j++)
                {
                    dp[i][j] = 0;
                }
            }
        }
    };

    int n;
    string s;
    vector<Node> seg;

    Node merge(Node &L, Node &R)
    {
        Node res;
        // take best from individual sides
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                res.dp[i][j] = max(L.dp[i][j], R.dp[i][j]);
            }
        }

        // combine subsequences
        for (int a = 0; a < 2; a++)
        {
            for (int b = 0; b < 2; b++)
            {

                if (L.dp[a][b] == 0)
                    continue;

                for (int c = 0; c < 2; c++)
                {
                    for (int d = 0; d < 2; d++)
                    {

                        if (R.dp[c][d] == 0)
                            continue;

                        // alternating continuation possible
                        if (b != c)
                        {
                            res.dp[a][d] =
                                max(res.dp[a][d],
                                    L.dp[a][b] + R.dp[c][d]);
                        }
                    }
                }
            }
        }

        return res;
    }

    void build(int idx, int l, int r)
    {

        if (l == r)
        {

            int ch = (s[l] == 'A' ? 0 : 1);

            seg[idx].dp[ch][ch] = 1;
            return;
        }

        int mid = (l + r) / 2;

        build(2 * idx + 1, l, mid);
        build(2 * idx + 2, mid + 1, r);

        seg[idx] = merge(seg[2 * idx + 1], seg[2 * idx + 2]);
    }

    void update(int idx, int l, int r, int pos)
    {

        if (l == r)
        {

            seg[idx] = Node();

            s[pos] = (s[pos] == 'A' ? 'B' : 'A');

            int ch = (s[pos] == 'A' ? 0 : 1);

            seg[idx].dp[ch][ch] = 1;

            return;
        }

        int mid = (l + r) / 2;

        if (pos <= mid)
            update(2 * idx + 1, l, mid, pos);
        else
            update(2 * idx + 2, mid + 1, r, pos);

        seg[idx] = merge(seg[2 * idx + 1], seg[2 * idx + 2]);
    }

    Node query(int idx, int l, int r, int ql, int qr)
    {

        if (ql <= l && r <= qr)
            return seg[idx];

        int mid = (l + r) / 2;

        if (qr <= mid)
            return query(2 * idx + 1, l, mid, ql, qr);

        if (ql > mid)
            return query(2 * idx + 2, mid + 1, r, ql, qr);

        Node left = query(2 * idx + 1, l, mid, ql, qr);
        Node right = query(2 * idx + 2, mid + 1, r, ql, qr);

        return merge(left, right);
    }

    vector<int> solve(string str, vector<vector<int>> &queries)
    {

        s = str;
        n = s.size();

        seg.resize(4 * n);

        build(0, 0, n - 1);

        vector<int> ans;

        for (auto &q : queries)
        {

            if (q[0] == 1)
            {

                int idx = q[1];

                update(0, 0, n - 1, idx);
            }
            else
            {

                int l = q[1];
                int r = q[2];

                Node cur = query(0, 0, n - 1, l, r);

                int best = 0;

                for (int i = 0; i < 2; i++)
                {
                    for (int j = 0; j < 2; j++)
                    {
                        best = max(best, cur.dp[i][j]);
                    }
                }

                int len = r - l + 1;

                ans.push_back(len - best);
            }
        }

        return ans;
    }
};