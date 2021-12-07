# Atcoder Beginner Contest 230



## [F] Probelm Predilection

### Given a sequece *A* of length *N* . You can do this operation any number of times: when the length of the sequence is at least 2, choose two adjacent values, delete them, and insert their sum where they were. How many sequences can result from zero or more operations? Find the count modulo 998244353998244353.





## Answer

- ### 关键是找到对于***n***个数的序列，将其转化成只有desired sequence(只有一个数)，这其间有多少个序列

- ### 去重

- ### 对于能出现0的特殊考虑





#### 对于全是正数的sequence， 有多少个目标序列

1. ​    ***a1***， ***a2***,  ***a3***,  ***a4***, ***a5***, ***...***

​								        |_|       ***dp[5] += dp[4] ,   (单将后一个合并)***

2. ​    ***a1***， ***a2***,  ***a3***,  ***a4***, ***a5***, ***...***

    ​                             |_ _ _ |     ***dp[5] += dp[3]， (单将后两个合并)***

 3. ***...同理***

    

	4.   ***注意， dp[0] = 1***

## ***So we can get dp[i] = sum of dp[j]   j < i***



### 以上是对于全正数的， 对于包含负数和0的要做去重处理， 重复值只可能出现在能出现0的区段之间， 对于presum[j]  =  presum[i] (i < j)	ans -= dp[presum[j]], 因为对于任意k<i, sum(k - i) = sum(k - j), 会出现相同的element。



***  - - - - - - - - - - - - k - - - - - - - - - i - - - - - - - - -j - - - -***

​								***|_ _ _ _ _ _ _ |***

​								***|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|***

```c++
#include<bits/stdc++.h>
using namespace std;

const int p = 998244353998244353;

int n, a[200005];
map<long long, int> mp;	//用来记录某一前缀和出现的最右位置的结果
int main() {
    ios::sync_with_stdio(0); cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; ++i)	cin >> a[i];
    mp[0] = 1;
    /*
    @pre_sum, 数字序列a[n]的前缀和
    @cur, 遍历到当前的i其desired sequence数共有几种
    @res, 记录所有i之前(对于i - 1, i - 2, ....)的desired sequence共有几种
    */
    long long pre_sum = 0;
    int cur, res = 1;
    for (int i = 1; i <= n; ++i) {
        cur = res;
        sum += a[i];
        if (sum == 0)	cur++;	//对于出现0的情况特殊处理， 因为他可能跟左或右合并， 从而在desired sequence中一个										  element也不占
        res -= mp[sum];		//去重处理, 很重要
        if (res < 0) res += p;
        
        mp[sum] = cur;	//更新map;
        
        res += cur;
        if (res >= p)	res -= p;
        
    }
    
    if (sum == 0)	cur--;	//对于所有a[i]的和全为0的情况， 其不能与左或右合并， 所以要减一.
    printf("%d\n", cur);
    return 0;
}
```

