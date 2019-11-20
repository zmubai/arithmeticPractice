//
//  BNOther.cpp
//  数据结构算法练习
//
//  Created by zengbailiang on 2019/4/6.
//  Copyright © 2019年 zengbailiang. All rights reserved.
//

#include "BNOther.hpp"
#include "vector"
#include "map"
#include "stack"
#include "string"
/*
 292. Nim游戏
 你和你的朋友，两个人一起玩 Nim游戏：桌子上有一堆石头，每次你们轮流拿掉 1 - 3 块石头。 拿掉最后一块石头的人就是获胜者。你作为先手。
 
 你们是聪明人，每一步都是最优解。 编写一个函数，来判断你是否可以在给定石头数量的情况下赢得游戏。
 
 示例:
 
 输入: 4
 输出: false
 解释: 如果堆中有 4 块石头，那么你永远不会赢得比赛；
 因为无论你拿走 1 块、2 块 还是 3 块石头，最后一块石头总是会被你的朋友拿走。
 */
/*
 假设为n块石头，每次能拿1-m块。如果最后只剩下m+1块那么后手必赢。如果n = （m+1）*k,那么后水只需要根据先手拿的块数a，拿出m+1 - a 的块数即可。如果n = (m+1)*k + s，那么先手第一次拿走s，必胜，但如果s==0，那么先手必输。
 */
bool canWinNim(int n) {
    return n%4 == 0 ?false:true;
}

/*
 136. 只出现一次的数字
 给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
 
 说明：
 
 你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
 
 示例 1:
 
 输入: [2,2,1]
 输出: 1
 示例 2:
 
 输入: [4,1,2,1,2]
 输出: 4
 */
/*
 异或一下就可以了||排序对比，哈希表也是可以的
 */
int singleNumber(vector<int>& nums) {
    if(nums.size() == 0)
    {
        return -1;
    }
    if(nums.size() == 1)
    {
        return nums[0];
    }
    int x = nums[0];
    for (int i = 1; i < nums.size(); i ++) {
        x ^= nums[i];
    }
    return x;
}

/*
 判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
 
 示例 1:
 
 输入: 121
 输出: true
 示例 2:
 
 输入: -121
 输出: false
 解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
 示例 3:
 
 输入: 10
 输出: false
 解释: 从右向左读, 为 01 。因此它不是一个回文数。
 */
/*获取每一位放入向量容器中，然后前后指针对比，如果遇到不相等的退出返回false，如果执行到最后则为回文数*/
bool isPalindrome(int x) {
    if (x < 0) {
        return false;
    }
    vector<int> v;
    while (x > 0) {
        v.push_back(x%10);
        x /= 10;
    }
    int left = 0;
    int right = (int)v.size() - 1;
    while (left < right) {
        if (v[left] != v[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

bool isPalindromexx(int x) {
    ///跟解法一思路上完全一致，其实就是修改了判断的顺序，测试用例的集合少于0的数比较少。如果在实际编码中需要考虑输入的集合的情况来优化条件判断的顺序，这个也能提高程序的执行效率。
    if (x >= 0) {
        vector<int> v;
        while (x) {
            v.push_back(x%10);
            x /= 10;
        }
        int left = 0;
        int right = (int)v.size() - 1;
        while (left < right) {
            if (v[left] != v[right]) {
                return false;
            }
            ++left;
            --right;
        }
        return true;
    }
    return false;
}

/*别的解法，根据回文数的特点，原数的低位为回文数的高位，这样生成一个回文数，对比原数，如果相等那么原数就是回文数，反之不是*/
bool isPalindromeX(int x) {
    long long ans = 0;
    int temp = x;
    while(temp > 0) {
        ans = ans * 10 + temp % 10;
        temp /= 10;
    }
    
    return (x == ans);
}

/*
 231. 2的幂
 给定一个整数，编写一个函数来判断它是否是 2 的幂次方。
 
 示例 1:
 
 输入: 1
 输出: true
 解释: 20 = 1
 示例 2:
 
 输入: 16
 输出: true
 解释: 24 = 16
 示例 3:
 
 输入: 218
 输出: false
 */
bool isPowerOfTwo(int n) {
    if(n == 1) return true;
    int g = 2;
    bool flag = false;
    while(1)
    {
        // int pre = n ;
        while(n % g !=0 && g > 2)
        {
            //标记过高，并查找合适的g
            flag = true;
            g /= 2;
        }
        if(g  == 1 || n % 2 != 0)
        {
            return false;
        }
        else
        {
            if(n == g ) return true;
            n /= g;
        }
        //判断结果
        if(n == 2)
        {
            return true;
        }
        else if(n%2 != 0)
        {
            return false;
        }
        else if (n == 0)
        {
            return false;
        }
        ///先指数增长，如果过高标记后平缓增长
        g *= flag?2:g;
        
    }
    return true;
}

/*高端解法
 负数不是
 如果为2的幂，那么 n 与 n-1 的二进制与运算结果为0 如果 2【00000010】 1【000000001】
 */
bool isPowerOfTwox(int n) {
    return n && ((n&(n-1)) == 0);
    /*
     leetcode 编译器问题,n 为大负数的时候越界，正常来说 n 少于0不会执行&&后的条件判断的
     if(n <=0) return false;
     return ((n&(n-1)) == 0);
     */
}

//class BNOther {
//
//}

//void pop() {
//    
//}
//
//int top() {
//    
//}
//
//int getMin() {
//    
//}

/*
 436. 寻找右区间
 
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
static bool cmp0(pair<int, int> a , pair<int, int> b){
    return a.first < b.first;
}
static bool cmp1(pair<int, int> a , int b ){
    ///< 代表没有比较继续  返回true
    /// >= 表示比较结束 返回false
    return a.first < b;
}
vector<int> findRightInterval(vector<vector<int>>& intervals) {
    int n = intervals.size();
    vector<pair<int, int>> pairs(n);
    vector <int> res(n,-1);
    for (int i = 0; i < n; i ++) {
        int left = intervals[i][0];
        pairs[i] = make_pair(left,i);
    }
    sort(pairs.begin(), pairs.end(), cmp0);
    for (int i = 0; i < n; i ++) {
        int right = intervals[i][1];
        ///获取第一个大于等于right的
        /*
         auto可以在声明变量的时候根据变量初始值的类型自动为此变量选择匹配的类型，类似的关键字还有decltype
         自动匹配类型
         */
        auto it = lower_bound(pairs.begin(), pairs.end(), right, cmp1);
        if (it != pairs.end()) {
            ///(*it)获取迭代器当前的值，second 当前值的第二个元素
            res[i] = (*it).second;
        }
    }
    return res;
}

/*
 454. 四数相加 II
 给定四个包含整数的数组列表 A , B , C , D ,计算有多少个元组 (i, j, k, l) ，使得 A[i] + B[j] + C[k] + D[l] = 0。
 
 为了使问题简单化，所有的 A, B, C, D 具有相同的长度 N，且 0 ≤ N ≤ 500 。所有整数的范围在 -228 到 228 - 1 之间，最终结果不会超过 231 - 1 。
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/4sum-ii
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
    map<long, long> mmap;
    int res = 0;
    ///如果是0 的长度 会怎么办。 因为是具有相同的长度，所以如果是0的化，直接返回是0.
    for (int i = 0 ; i < A.size(); i ++) {
        for (int j = 0; j < B.size(); j ++) {
            int v = A[i] + B[j];
            auto it = mmap.find(v);
            if (it != mmap.end()) {
                mmap[v] += 1;
            }
            else{
                mmap[v] = 1;
            }
        }
    }
    
    for (int i = 0 ; i < C.size(); i ++) {
        for (int j = 0; j < D.size(); j ++) {
            auto it = mmap.find(-(C[i] + D[j]));
            if(it != mmap.end()){
                ///first 取的是key, second 取的是value
                res += (*it).second;
            }
        }
    }
    return res;
}

/*
 请你帮忙设计一个程序，用来找出第 n 个丑数。
 
 丑数是可以被 a 或 b 或 c 整除的 正整数。
 
  
 
 示例 1：
 
 输入：n = 3, a = 2, b = 3, c = 5
 输出：4
 解释：丑数序列为 2, 3, 4, 5, 6, 8, 9, 10... 其中第 3 个是 4。
 示例 2：
 
 输入：n = 4, a = 2, b = 3, c = 4
 输出：6
 解释：丑数序列为 2, 3, 4, 6, 8, 9, 12... 其中第 4 个是 6。
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/ugly-number-iii
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 **/


/*
 658. 找到 K 个最接近的元素
 给定一个排序好的数组，两个整数 k 和 x，从数组中找到最靠近 x（两数之差最小）的 k 个数。返回的结果必须要是按升序排好的。如果有两个数与 x 的差值一样，优先选择数值较小的那个数。
 
 示例 1:
 
 输入: [1,2,3,4,5], k=4, x=3
 输出: [1,2,3,4]
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/find-k-closest-elements
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

//func1
//vector<int> findClosestElements(vector<int>& arr, int k, int x) {
//    vector<int> res(k,0);
//    int len = arr.size();
//    int left = 0;
//    int right = len - 1;
//    while(len > k){
//        if(abs(arr[left] - x) > abs(arr[right] - x)){
//            left ++;
//        }
//        else{
//            right --;
//        }
//        len --;
//    }
//    ///新数值index从0开始
//    int index = 0;
//    for(int i = left; i <= right; i ++){
//        res[index++] = arr[i];
//    }
//    return res;
//}

//func2
/*
 使用二分法，查找子数组合适的起点。二分逼近
 */
vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    vector<int> res(k,0);
    int start = 0;
    //end的初始值，设定二分开始区间为(0,size -k),所以下面用到mid + k 是不会越界的;
    int end = arr.size() - k;
    int mid;
    while (start < end) {
        mid = start + (end - start)/2;
        if(abs(arr[mid] - x) > abs(arr[mid + k] - x)){
            start = mid + 1;
        }
        else{
            end = mid;
        }
    }
    int index = 0;
    for (int i = start; i < start + k; i ++) {
        res[index++] = arr[i];
    }
    return res;
}


/*
 778. 水位上升的泳池中游泳
 在一个 N x N 的坐标方格 grid 中，每一个方格的值 grid[i][j] 表示在位置 (i,j) 的平台高度。
 
 现在开始下雨了。当时间为 t 时，此时雨水导致水池中任意位置的水位为 t 。你可以从一个平台游向四周相邻的任意一个平台，但是前提是此时水位必须同时淹没这两个平台。假定你可以瞬间移动无限距离，也就是默认在方格内部游动是不耗时的。当然，在你游泳的时候你必须待在坐标方格里面。
 
 你从坐标方格的左上平台 (0，0) 出发。最少耗时多久你才能到达坐标方格的右下平台 (N-1, N-1)？
 
 示例 1:
 
 输入: [[0,2],[1,3]]
 输出: 3
 解释:
 时间为0时，你位于坐标方格的位置为 (0, 0)。
 此时你不能游向任意方向，因为四个相邻方向平台的高度都大于当前时间为 0 时的水位。
 
 等时间到达 3 时，你才可以游向平台 (1, 1). 因为此时的水位是 3，坐标方格中的平台没有比水位 3 更高的，所以你可以游向坐标方格中的任意位置
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/swim-in-rising-water
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
void dfs(int t,vector<vector<int>>& grid,int i , int j ,vector<vector<bool>> &visit){
    long size = grid.size();
    //超出范围，或者不符合条件，或者已经访问。返回。
    if(i < 0
       ||i > size - 1
       ||j < 0
       ||j > size - 1
       ||grid[i][j] > t
       ||visit[i][j]
       ||visit[size - 1][size - 1]){
        return;
    }
    visit[i][j] = true;
    dfs(t, grid, i + 1, j, visit);
    dfs(t, grid, i, j + 1, visit);
    dfs(t, grid, i - 1, j, visit);
    dfs(t, grid, i, j - 1, visit);
}

int swimInWater(vector<vector<int>>& grid) {
    int left = 0;
    int right = 0;
    for (int r = 0; r < grid.size(); ++r) {
        for (int c = 0; c < grid.size(); ++c) {
            right = max(right, grid[r][c]);
            left = min(left, grid[r][c]);
        }
    }
    long size = grid.size();
    int res = right;
    //此条件为什么是<=。 因为是查找点，而非查找区间
    while (left <= right) {
        int mid = left + (right - left)/2;
        vector<vector<bool>> visit(size,vector<bool>(size,false));
        dfs(mid, grid, 0, 0, visit);
        if(visit[size-1][size-1]){
            res = mid;
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    return res;
}


/*719. 找出第 k 小的距离对
 给定一个整数数组，返回所有数对之间的第 k 个最小距离。一对 (A, B) 的距离被定义为 A 和 B 之间的绝对差值。
 
 示例 1:
 
 输入：
 nums = [1,3,1]
 k = 1
 输出：0
 解释：
 所有数对如下：
 (1,3) -> 2
 (1,1) -> 0
 (3,1) -> 2
 因此第 1 个最小距离的数对是 (1,1)，它们之间的距离为 0。
 提示:
 
 2 <= len(nums) <= 10000.
 0 <= nums[i] < 1000000.
 1 <= k <= len(nums) * (len(nums) - 1) / 2.
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/find-k-th-smallest-pair-distance
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 
 */
int smallOrEquarK(vector<int>& nums,long mid){
    int res  = 0;
    for (int right = 0; right < nums.size(); right ++) {
        int left = 0;
        while (nums[right] - nums[left] > mid) {
            left ++;
        }
        res += right - left;
    }
    return res;
}

int smallestDistancePair(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    long left = 0;
    long right = nums[nums.size() - 1] - nums[0];
    while (left< right) {
        long  mid = left + (right - left)/2;
        int count = smallOrEquarK(nums,mid);
        if(count >= k){
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }
    return right;
}

/*
 715. Range 模块
 Range 模块是跟踪数字范围的模块。你的任务是以一种有效的方式设计和实现以下接口。

 addRange(int left, int right) 添加半开区间 [left, right)，跟踪该区间中的每个实数。添加与当前跟踪的数字部分重叠的区间时，应当添加在区间 [left, right) 中尚未跟踪的任何数字到该区间中。
 queryRange(int left, int right) 只有在当前正在跟踪区间 [left, right) 中的每一个实数时，才返回 true。
 removeRange(int left, int right) 停止跟踪区间 [left, right) 中当前正在跟踪的每个实数。
 
 addRange(10, 20): null
 removeRange(14, 16): null
 queryRange(10, 14): true （区间 [10, 14) 中的每个数都正在被跟踪）
 queryRange(13, 15): false （未跟踪区间 [13, 15) 中像 14, 14.03, 14.17 这样的数字）
 queryRange(16, 17): true （尽管执行了删除操作，区间 [16, 17) 中的数字 16 仍然会被跟踪）

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/range-module
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/**
* Your RangeModule object will be instantiated and called as such:
* RangeModule* obj = new RangeModule();
* obj->addRange(left,right);
* bool param_2 = obj->queryRange(left,right);
* obj->removeRange(left,right);
*/
//vector<pair<int,int>> rangs;
//
//   void addRange(int left, int right) {
//       vector<pair<int, int>> res;
//       int size = (int)rangs.size();
//       for(int i = 0; i < size; i ++){
//          if(rangs[i].first >= right || left >= rangs[i].second){
//               //不包含
//               res.push_back(rangs[i]);
//           }
//           else{
//               //包含或存在交集
//               left = min(left, rangs[i].first);
//               right = max(right, rangs[i].second);
//           }
//       }
//       res.insert(res.begin(), {left,right});
//       rangs = res;
//   }
//
//   bool queryRange(int left, int right) {
//       int size = (int)rangs.size();
//       for(int i = 0; i < size; i ++){
//           if(rangs[i].first <= left && rangs[i].second >= right){
//               return true;
//           }
//       }
//       return false;
//   }
//
//   void removeRange(int left, int right) {
//      vector<pair<int, int>> res;
//      int size = (int)rangs.size();
//      for(int i = 0; i < size; i ++){
//          if(rangs[i].first > right || left > rangs[i].second){
//              //不包含 并且不连续(如果 >= || >=的话，对与相连的区间就少了合成的机会。某些情况下会导致边界的重复，如果发生，那么会导致删除函数的不准确)
//              res.push_back(rangs[i]);
//          }
//          else{
//              //存在交集 或者 包含
//              if (rangs[i].first < left) {
//                  res.push_back({rangs[i].first,left});
//              }
//              if (rangs[i].second > right)
//              {
//                  res.push_back({right,rangs[i].second});
//              }
//          }
//      }
//      rangs = res;
//   }
//

   map<int,int> m;
    /*
     查找所在的范围。
     1.add. 如果不存在，直接返回原范围。否则，返回需要更新的范围
     2.remove 如果不存在，直接返回原范围。否则，返回交集的范围。
     */
    pair<int, int> find(int left,int right){
        auto l = m.upper_bound(left);
        auto r = m.upper_bound(right);
        if (l != m.begin() && (--l)->second < left) {
            //不存在交集
            l++;
        }
        if (l==r) {
            return {left,right};
        }
        int i = min(left,l->first);
        int j = max(right,(--r)->second);
        m.erase(l, ++r);
        return {i,j};
    }

   void addRange(int left, int right) {
       pair<int, int> p = find(left,right);
       //插入或调整范围
       m[p.first] = p.second;
   }
   
   bool queryRange(int left, int right) {
    //获取第一个大于left的pair,如果不是第一个，那么必然存在firs<left的pair，如果这个pair的second大于等于right,那么返回true。
       auto p = m.upper_bound(left);
       return p != m.begin() && (--p)->second >= right;
   }
   
   void removeRange(int left, int right) {
       pair<int, int> p = find(left,right);
       //去除，[left,right)。更新范围，要保留左侧或右侧的相交的部分。
       if(p.first < left) m[p.first] = left;
       if(p.second > right) m[right] = p.second;
   }


/*
 887. 鸡蛋掉落
 你将获得 K 个鸡蛋，并可以使用一栋从 1 到 N  共有 N 层楼的建筑。

 每个蛋的功能都是一样的，如果一个蛋碎了，你就不能再把它掉下去。

 你知道存在楼层 F ，满足 0 <= F <= N 任何从高于 F 的楼层落下的鸡蛋都会碎，从 F 楼层或比它低的楼层落下的鸡蛋都不会破。

 每次移动，你可以取一个鸡蛋（如果你有完整的鸡蛋）并把它从任一楼层 X 扔下（满足 1 <= X <= N）。

 你的目标是确切地知道 F 的值是多少。

 无论 F 的初始值如何，你确定 F 的值的最小移动次数是多少？

 示例 1：

 输入：K = 1, N = 2
 输出：2
 解释：
 鸡蛋从 1 楼掉落。如果它碎了，我们肯定知道 F = 0 。
 否则，鸡蛋从 2 楼掉落。如果它碎了，我们肯定知道 F = 1 。
 如果它没碎，那么我们肯定知道 F = 2 。
 因此，在最坏的情况下我们需要移动 2 次以确定 F 是多少。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/super-egg-drop
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
/*
 k个鸡蛋  N层楼
 dp[i][j] i个鸡蛋，j层楼 用的次数
 假设在 x层扔下鸡蛋
 1. 鸡蛋没有碎 dp[i][j-x]
 2. 鸡蛋碎了 dp[i-1][x-1]
 dp[i][j] = min(dp[i][j],1 + max(dp[i][j-x],dp[i-1][x-1]))
 */
// Time Limit Exceeded
//int superEggDrop(int K, int N) {
//    vector<vector<int>> dp(K + 1, vector<int>(N + 1));
//    for (int i = 1; i <= N; i ++) {
//        dp[1][i] = i;
//    }
//    //2 - K 个鸡蛋
//    for (int i = 2;i <= K; ++i){
//        // 1 - N 层
//        for (int j = 1; j <= N; ++j) {
//            //赋值最大次数
//            dp[i][j] = j;
//            //鸡蛋有可能在任何一层砸碎
//            for (int x = 1; x < j; ++x) {
//                dp[i][j] = min(dp[i][j], 1 + max(dp[i][j - x], dp[i -1][x -1]));
//            }
//        }
//    }
//    return dp[K][N];
//}


//
//int superEggDrop(int K, int N) {
//    vector<vector<int>> dp (K+1,vector<int>(N+1,0));
//    for (int i = 1; i <= N; ++i) {
//        //只有一个鸡蛋的时候，最坏的情况就是逐层测试
//        dp[1][i] = i;
//    }
//
//    for (int i = 2; i <= K; ++ i) {
//        for (int j = 2; j <= N; ++ j ) {
//            //赋值最保险的次数
//            dp[i][j] = j;
//            //鸡蛋每一层抛出的情况测试（碎/不碎）
//            int left = 1;
//            int right = j;
//            int mid = 1;
//            while (left < right) {
//                mid = left + (right - left)/2;
//                if (dp[i][j-mid] < dp[i-1][mid-1]) {
//                    left = mid + 1;
//                }
//                else{
//                    right = mid;
//                }
//            }
//            dp[i][j] = min(dp[i][j], max(dp[i][j-right], dp[i-1][right-1]));
//        }
//    }
//    return dp[K][N];
//}

// dp[i][j] i鸡蛋，j层 二分 ok
//int superEggDrop(int K, int N) {
//    vector<vector<int>> dp (K+1,vector<int>(N+1));
//    //赋基础值
//    for (int i = 1 ; i <= N; ++i) {
//        dp[1][i] = i;
//    }
//    //2 - K egg
//    for (int i = 2; i <= K; ++i) {
//        // 1 - N floor
//        for (int j = 1; j <= N; ++j) {
//            //赋保险值
//            dp[i][j] = j;
//            int left = 1;
//            int right = j;
//            //二分查找临界点
//            while (left<right) {
//                int mid = left + (right - left)/2;
//                if (dp[i - 1][mid -1] < dp[i][j - mid]) {
//                    //mid 过小 向右偏移
//                    left = mid + 1;
//                }
//                else{
//                    //mid 过大，向左偏移
//                    right = mid;
//                }
//            }
//            ///为什么最后right是临界点呢
//            dp[i][j] = min(dp[i][j], 1 + max(dp[i-1][right-1],dp[i][j-right]));
//        }
//    }
//    return dp[K][N];
//}

int superEggDrop(int K, int N) {
    vector<vector<int>> dp (K+1,vector<int>(N+1));
    //赋基础值
    for (int i = 1 ; i <= N; ++i) {
        dp[1][i] = i;
    }
    //2 - K egg
    for (int i = 2; i <= K; ++i) {
        // 1 - N floor
        int s = 1;
        for (int j = 1; j <= N; ++j) {
            //赋保险值
            dp[i][j] = j;
            //随着楼层的增加 s会变大。
            while (dp[i - 1][s -1] < dp[i][j - s]) {
                s++;
            }
            dp[i][j] = min(dp[i][j], 1 + max(dp[i-1][s-1],dp[i][j-s]));
        }
    }
    return dp[K][N];
}

/*
 1123. 最深叶节点的最近公共祖先
 */
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode*  findDeepComm(TreeNode* root,int *deep){
    if (root != nullptr) {
        *deep += 1;
    }
    int *dL = (int*)malloc(sizeof(int));
    int *dR = (int*)malloc(sizeof(int));
    *dL = *deep;
    *dR = *deep;
    TreeNode *nl = root;
    if(root->left){
        nl = findDeepComm(root->left, dL);
    }
    TreeNode *nr = root;
    if (root->right) {
        nr = findDeepComm(root->right, dR);
    }
    if (*dL == *dR) {
        *deep = *dL;
        return root;
    }
    else{
        *deep = *dL > *dR ? *dL:*dR;
        return *dL > *dR ? nl : nr;
    }
}

//如果深度最深的叶子节点，没有堂兄弟节点，且如果没有兄弟节点，那么自己就是最近公共祖先。如果有堂兄弟节点，那么需要向上查找最近公共祖先。
TreeNode* lcaDeepestLeaves(TreeNode* root) {
    int *deep = (int*)malloc(sizeof(int));;
    *deep = 0;
    return findDeepComm(root,deep);
}

/*
 807. 保持城市天际线
 */
int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
    long hSize = grid.size();
    long vSize = grid[0].size();
    vector<int> hMaxArr (hSize,0);
    vector<int> vMaxArr (vSize,0);
    //先获取 hMaxArr vMaxArr
    for (int i = 0; i < hSize ; i ++) {
        for (int j = 0 ; j < vSize; j ++) {
            if(grid[i][j]>hMaxArr[i]){
                hMaxArr[i] = grid[i][j];
            }
            if (grid[i][j]>vMaxArr[j]) {
                vMaxArr[j] = grid[i][j];
            }
        }
    }
    int res = 0;
    for (int i = 0; i < hSize ; i ++) {
        for (int j=0 ; j < vSize; j ++) {
            int minLimit = hMaxArr[i] > vMaxArr[j] ? vMaxArr[j] : hMaxArr[i];
            int mayAdd = minLimit - grid[i][j];
            if(mayAdd){
                res += mayAdd;
            }
        }
    }
    return  res;
   }

/*
 744. 寻找比目标字母大的最小字母
 */
//char nextGreatestLetter(vector<char>& letters, char target) {
//    int big = -1;
//    int bigIndex = -1;
//        for(int i = 0; i < letters.size(); i ++){
//            int len = letters[i] - target;
//            if(len >= 0)
//            {
//               if(len < big|| big == -1){
//                   big = len;
//                   bigIndex = i;
//               }
//            }
//        }
//        if(big){
//            return letters[big];
//        }
//        else{
//            return letters[0];
//        }
//}
/*
 二分法
 */
char nextGreatestLetter(vector<char>& letters, char target) {
    int left = 0;
    int right = (int)letters.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (mid> 0 && letters[mid - 1] <= target && letters[mid]> target) {
            return letters[mid];
        }
        else{
            if (letters[mid]<=target) {
                left = mid + 1;
            }
            else{
                right = mid;
            }
        }
    }
    return letters[0];
}

/*
 1249. 移除无效的括号
 */
string minRemoveToMakeValid(string s) {
    stack<int> st;
    map<int,int> map;
    for (int i = 0; i < s.length(); i ++) {
        char c = s[i];
        if (c == '(') {
            st.push(i);
        }
        else if(c == ')'){
            if (!st.empty()) {
                st.pop();
            }
            else{
                map[i] = 1;
            }
        }
    }
    while (!st.empty()) {
        int i = st.top();
        st.pop();
        map[i] = 1;
    }
    string res;
    for (int i = 0; i < s.length(); i ++) {
        if(map.find(i) == map.end()){
            res.append(s[i],1);
        }
    }
    return res;
}

/*
 303. 区域和检索 - 数组不可变 simple
 class NumArray {
 public:
     NumArray(vector<int>& nums) {
         int size = nums.size();
         sums = vector<int>(size,0);
         int currentSum = 0;
         for(int i = 0;i<size;++i){
             currentSum += nums[i];
             sums[i] = currentSum;
         }
     }
     
     int sumRange(int i, int j) {
         if(i>0){
             return sums[j] - sums[i-1];
         }
         return sums[j];
     }
     private:
         vector<int> sums;
 };
 */

/*
 435. 无重叠区间
 **/
bool intervalsComp(vector<int>a,vector<int>b){
    if (a[0]<b[0]) {
        return true;
    }
    return false;
}

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    if (intervals.size() <= 0) {
        return 0;
    }
    int len = 0;
    sort(intervals.begin(), intervals.end(), intervalsComp);
    /*贪心策略，选择区间上限更小的，为后面提供更多的空间。
     1.没有重叠，继续下一轮循环。
     2.如果有重叠，那么舍弃上限大的，选择上限小的。
     **/
    int last = 0;
    for (int i = 1 ; i < intervals.size(); ++i) {
        if (intervals[last][1]<=intervals[i][0]) {
            last = i;
            continue;
        }
        else{
            len ++;
            last = intervals[last][1] <= intervals[i][1] ? last : i;
        }
    }
    return len;
}

/*
 1262. 可被三整除的最大和
 **/
static bool compDesc(int a,int b){
    return a > b;
}

int adjustSum(int rem ,int sum,vector<int> v1,vector<int> v2){
    if (rem == 1) {
        if (v1.size() == 0) {
            return sum - v2[v2.size() - 1] - v2[v2.size() - 2];
        }
        else if(v2.size()<2){
            return sum - v1[v1.size() - 1];
        }
        else{
            int del = min(v2[v2.size() - 1] + v2[v2.size() - 2], v1[v1.size() - 1]);
            return sum - del;
        }
    }
    else if(rem == 2){
        if (v1.size()<2) {
            return sum - v2[v2.size() - 1];
        }
        else if (v2.size() == 0){
            return sum - v1[v1.size() - 1] - v1[v1.size() - 2];
        }
        else{
            int del = min(v2[v2.size() - 1],v1[v1.size() - 1] + v1[v1.size() - 2]);
            return sum - del;
        }
    }
    return 0;
}
int maxSumDivThree(vector<int>& nums) {
    vector<int> v1;
    vector<int> v2;
    int sum =0;
    for (int i = 0; i < nums.size(); ++i) {
        sum += nums[i];
        int r = nums[i] % 3;
        if(r == 1){
            v1.push_back(nums[i]);
        }
        else if (r == 2){
            v2.push_back(nums[i]);
        }
    }
    sort(v1.begin(), v1.end(), compDesc);
    sort(v2.begin(), v2.end(), compDesc);
    if (sum % 3 == 1) {
        return adjustSum(1,sum, v1, v2);
    }
    else if (sum % 3 == 2){
        return adjustSum(2,sum, v1, v2);
    }
    return sum;
 }
