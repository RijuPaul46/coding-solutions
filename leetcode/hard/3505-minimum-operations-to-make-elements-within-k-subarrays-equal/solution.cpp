class Solution {
public:
    #define ll long long
    // first i have to run a sliding window which calculate number of operation needed to make all equal ... i have to carry info ei, op needed ...
    // then run a dp ... if i have selected take or skip n*k 
    // sliding window to calculate number of operation needed 
    // brute force will be n*x-x2  x=n/2 t.c=n2/4 
    // from prev median how much changed let say increased by y then operation +=(no of elm less than median)*y -= no of elm greater than median*y  operation=operation+(no of elm <median - no of elm >med)*y
    // then i have to adjust for discarded elm too ... but set cannot find median iterator 
    // B.S on answer ... because let say x is min number of operation needed ... then x+1 will also satisfy this 
    //k<=15 ... i need to select only about 15 subarray starting point
    // dp[i][k]

    long long minOperations(vector<int>& nums, int x, int k) {
              int n = nums.size();
        priority_queue<int> left;
        priority_queue<int, vector<int>, greater<int>> right;
        unordered_map<int, int> delayed;
        int leftSize = 0, rightSize = 0;
        vector<long long> ops(n);
        long long sumL = 0, sumR = 0;

        auto prune = [&](auto& heap) {
            while (!heap.empty()) {
                if (delayed[heap.top()]) {
                    --delayed[heap.top()];
                    heap.pop();
                } else {
                    break;
                }
            }
        };

        auto balance = [&]() {
            if (leftSize > rightSize + 1) {
                int num = left.top();
                right.push(num);
                sumR += num;
                sumL -= num;
                left.pop();
                ++rightSize;
                --leftSize;
                prune(left);
            } else if (rightSize > leftSize) {
                int num = right.top();
                left.push(num);
                sumL += num;
                sumR -= num;
                right.pop();
                ++leftSize;
                --rightSize;
                prune(right);
            }
        };

        for (int i = 0; i < n; i++) {
            if (left.empty() || nums[i] <= left.top()) {
                left.push(nums[i]);
                ++leftSize;
                sumL += nums[i];
            } else {
                right.push(nums[i]);
                ++rightSize;
                sumR += nums[i];
            }
            balance();
            if (i >= x) {
                int num = nums[i - x];
                if (num <= left.top()) {
                    --leftSize;
                    ++delayed[num];
                    sumL -= num;
                    if (num == left.top()) {
                        prune(left);
                    }
                } else {
                    --rightSize;
                    ++delayed[num];
                    sumR -= num;
                    if (num == right.top()) {
                        prune(right);
                    }
                }
                balance();
            }

            if (i >= x - 1) {
                long long mid = left.top();
                ops[i] = sumR - sumL + mid * (leftSize - rightSize);
            }
        }

        vector<vector<long long>> dp(n, vector<long long>(k + 1, LLONG_MAX));

        for (int i = 0; i < n; i++) {
            dp[i][0] = 0;
        }
        for (int j = 1; j <= k; j++) {
            if (j == 1) {
                dp[x - 1][j] = ops[x - 1];
            } else {
                dp[j * x - 1][j] = dp[(j - 1) * x - 1][j - 1] + ops[j * x - 1];
            }
        }
        for (int j = 1; j <= k; j++) {
            for (int i = j * x; i < n; i++) {
                dp[i][j] = min(dp[i - x][j - 1] + ops[i], dp[i - 1][j]);
            }
        }

        return dp[n - 1][k];
        
    }
};