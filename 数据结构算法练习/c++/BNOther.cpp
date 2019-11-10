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


