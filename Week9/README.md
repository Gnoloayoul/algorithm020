学习笔记


关键部分
基准情况：
T[-1][k][0] = 0
T[-1][k][1] = -Infinity
T[i][0][0] = 0
T[i][0][1] = -Infinity
基准状态转移方程：
T[i][k][0] = max(T[i - 1][k][0], T[i - 1][k][1] + prices[i])
T[i][k][1] = max(T[i - 1][k][1], T[i - 1][k - 1][0] - prices[i]) 

121. 买卖股票的最佳时机
时间复杂度：O(n)
空间复杂度：O(n)
//C
int max(int a, int b){
    return (a > b) ? a : b;
}
int maxProfit(int* prices, int pricesSize){
    if(prices == NULL || pricesSize == 0){
        return 0;
    }
    int dp[pricesSize + 1][2];
    dp[0][0] = 0;
    dp[0][1] = -prices[0];
    for (int i = 1; i < pricesSize; i++){
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
        dp[i][1] = max(dp[i - 1][1], -prices[i]);
    }
    return dp[pricesSize - 1][0];
}
#python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if prices is None or len(prices) == 0 :
            return 0
        L = len(prices)
        dp = [[0] * 2 for _ in range(L)]
        dp[0][0], dp[0][1] = 0, -prices[0]
        for i in range(1, L) :
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i])
            dp[i][1] = max(dp[i - 1][1], -prices[i])
        return dp[L - 1][0] 

122. 买卖股票的最佳时机 II
时间复杂度：O(n)
空间复杂度：O(n)
//C
int max(int a, int b){
    return (a > b) ? a : b;
}
int maxProfit(int* prices, int pricesSize){
    if (prices == NULL || pricesSize == 0){
        return 0;
    }
    int dp[pricesSize + 1][2];
    dp[0][0] = 0;
    dp[0][1] = -prices[0];
    for (int i = 1; i < pricesSize; i++){
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
    }
    return dp[pricesSize - 1][0];
}
#python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if prices is None or len(prices) == 0 :
            return 0
        L = len(prices)
        dp = [[0] * 2 for _ in range(L)]
        dp[0][0], dp[0][1] = 0, -prices[0]
        for i in range(1, L) :
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i])
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i])
        return dp[L - 1][0] 

123. 买卖股票的最佳时机 III
时间复杂度：O(n)
空间复杂度：O(n)
//C
int max(int a, int b){
    return (a > b) ? a : b;
}
int maxProfit(int* prices, int pricesSize){
    if (prices == NULL || pricesSize == 0){
        return 0;
    }
    int dp[pricesSize + 1][3][2];
    dp[0][2][0] = 0;
    dp[0][2][1] = -prices[0];
    dp[0][1][0] = 0;
    dp[0][1][1] = -prices[0];
    for (int i = 1; i < pricesSize; i++){
        dp[i][2][0] = max(dp[i - 1][2][0], dp[i - 1][2][1] + prices[i]);
        dp[i][2][1] = max(dp[i - 1][2][1], dp[i - 1][1][0] - prices[i]);
        dp[i][1][0] = max(dp[i - 1][1][0], dp[i - 1][1][1] + prices[i]);
        dp[i][1][1] = max(dp[i - 1][1][1], -prices[i]);
    }
    return dp[pricesSize - 1][2][0];
}
#python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if prices is None or len(prices) == 0 :
            return 0
        L = len(prices)
        temp = [[0] * 2 for _ in range(3)]
        dp = [temp for _ in range(L)]
        dp[0][2][0], dp[0][2][1], dp[0][1][0], dp[0][1][1] = 0, -prices[0], 0, -prices[0]
        for i in range(1, L) :
            dp[i][2][0] = max(dp[i - 1][2][0], dp[i - 1][2][1] + prices[i])
            dp[i][2][1] = max(dp[i - 1][2][1], dp[i - 1][1][0] - prices[i])
            dp[i][1][0] = max(dp[i - 1][1][0], dp[i - 1][1][1] + prices[i])
            dp[i][1][1] = max(dp[i - 1][1][1], dp[i - 1][0][0] - prices[i])
        return dp[L - 1][2][0] 

188. 买卖股票的最佳时机 IV
时间复杂度：O（nk）
空间复杂度：O（nk）
//C（存在不明BUG）
int max(int a, int b){
    return (a > b) ? a : b;
}
int maxProfitEX(int* prices, int pricesSize){
    if (prices == NULL || pricesSize == 0){
        return 0;
    }
    int dp[pricesSize + 1][2];
    dp[0][0] = 0;
    dp[0][1] = -prices[0];
    for (int i = 1; i < pricesSize; i++){
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
    }
    return dp[pricesSize - 1][0];
}
int maxProfit(int k, int* prices, int pricesSize){
    if (prices == NULL || pricesSize == 0){
        return 0;
    }
    if (k >= (pricesSize / 2)){
        return maxProfitEX(prices, pricesSize);
    }
    else{
        int dp[pricesSize + 1][k + 1][2];
        for (int i = 1; i <= k; i++){
            dp[0][i][0] = 0;
            dp[0][i][1] = -prices[0];
        }
        for (int i = 1; i < pricesSize; i++){
            for (int j = k ; j > 0; j--){
                dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);
                dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
            }
        }
        return dp[pricesSize - 1][k][0];
    }
}
#python3
#要小心是否需要K + 1
class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        if prices is None or len(prices) == 0 :
            return 0
        L = len(prices)
        if k >= L/2 :
            return self.maxProfitOT(prices)
        temp = [[0] * 2 for _ in range(k + 1)]
        dp = [temp for _ in range(L)]
        for i in range(1, k + 1) :
            dp[0][i][0], dp[0][i][1] = 0, -prices[0]
        for i in range(1, L) :
            for j in range(k, 0, -1) :
                dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i])
                dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i])
        return dp[L - 1][k][0]
    def maxProfitOT(self, prices: List[int]) ->int:
        if prices is None or len(prices) == 0 :
            return 0
        L = len(prices)
        dp = [[0] * 2 for _ in range(L)]
        dp[0][0], dp[0][1] = 0, -prices[0]
        for i in range(1, L) :
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i])
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i])
        return dp[L - 1][0] 

309. 最佳买卖股票时机含冷冻期
时间复杂度：O(n)
空间复杂度：O(n)
//C
int max(int a, int b){
    return (a > b) ? a : b;
}
int maxProfit(int* prices, int pricesSize){
    if (prices == NULL || pricesSize == 0){
        return 0;
    }
    int dp[pricesSize + 1][2];
    dp[0][0] = 0;
    dp[0][1] = -prices[0];
    for (int i = 1; i < pricesSize; i++){
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
        if (i > 2){
            dp[i][1] = max(dp[i - 1][1], dp[i - 2][0] - prices[i]);
        }
        else{
            dp[i][1] = max(dp[i - 1][1], -prices[i]);
        }
    }
    return dp[pricesSize - 1][0];
}
#python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if prices is None or len(prices) == 0 :
            return 0
        L = len(prices)
        dp = [[0] * 2 for _ in range(L)]
        dp[0][0], dp[0][1] = 0, -prices[0]
        for i in range(1, L) :
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i])
            dp[i][1] = max(dp[i - 1][1], dp[i - 2][0] - prices[i])
        return dp[L - 1][0] 

714. 买卖股票的最佳时机含手续费
时间复杂度：O(n)
空间复杂度：O(n)
//C
int max(int a, int b){
    return (a > b) ? a : b;
}
int maxProfit(int* prices, int pricesSize, int fee){
    if (prices == NULL || pricesSize == 0){
        return 0;
    }
    int dp[pricesSize + 1][2];
    dp[0][0] = 0;
    dp[0][1] = -prices[0];
    for (int i = 1; i < pricesSize; i++){
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i] - fee);
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
    }
    return dp[pricesSize - 1][0];
}
#python3
class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        if prices is None or len(prices) == 0 :
            return 0
        L = len(prices)
        dp = [[0] * 2 for _ in range(L)]
        dp[0][0], dp[0][1] = 0, -prices[0]
        for i in range(1, L) :
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i] - fee)
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i])
        return dp[L - 1][0] 
