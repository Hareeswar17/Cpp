#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;

class SqrtDecomposition {
private:
    int n;
    int blockSize;
    int numBlocks;

    vector<long long> arr;
    vector<long long> blockSum;
    vector<long long> lazy;

public:
    SqrtDecomposition(vector<long long>& nums) {
        n = nums.size();

        blockSize = sqrt(n) + 1;
        numBlocks = (n + blockSize - 1) / blockSize;

        arr = nums;
        blockSum.assign(numBlocks, 0);
        lazy.assign(numBlocks, 0);

        for (int i = 0; i < n; i++) {
            blockSum[i / blockSize] += arr[i];
        }
    }

    // add val to range [l, r]
    void rangeUpdate(int l, int r, long long val) {
        int leftBlock = l / blockSize;
        int rightBlock = r / blockSize;

        if (leftBlock == rightBlock) {
            for (int i = l; i <= r; i++) {
                arr[i] += val;
                blockSum[leftBlock] += val;
            }
            return;
        }

        // left partial block
        int leftEnd = (leftBlock + 1) * blockSize - 1;
        for (int i = l; i <= min(leftEnd, n - 1); i++) {
            arr[i] += val;
            blockSum[leftBlock] += val;
        }

        // full blocks
        for (int b = leftBlock + 1; b < rightBlock; b++) {
            lazy[b] += val;
            blockSum[b] += 1LL * blockSize * val;
        }

        // right partial block
        int rightStart = rightBlock * blockSize;
        for (int i = rightStart; i <= r; i++) {
            arr[i] += val;
            blockSum[rightBlock] += val;
        }
    }

    // sum of range [l, r]
    long long rangeQuery(int l, int r) {
        long long ans = 0;

        int leftBlock = l / blockSize;
        int rightBlock = r / blockSize;

        if (leftBlock == rightBlock) {
            for (int i = l; i <= r; i++) {
                ans += arr[i] + lazy[leftBlock];
            }
            return ans;
        }

        // left partial block
        int leftEnd = (leftBlock + 1) * blockSize - 1;
        for (int i = l; i <= min(leftEnd, n - 1); i++) {
            ans += arr[i] + lazy[leftBlock];
        }

        // full blocks
        for (int b = leftBlock + 1; b < rightBlock; b++) {
            ans += blockSum[b];
        }

        // right partial block
        int rightStart = rightBlock * blockSize;
        for (int i = rightStart; i <= r; i++) {
            ans += arr[i] + lazy[rightBlock];
        }

        return ans;
    };
};