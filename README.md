# Leetcode OJ

### 1.Two Sum

* easy

### 2.Add Two Numbers

* 两数相加，两数用链表形式表示

### 3.Longest Substring Without Repeating Characters

* 滑动窗口`[i, j]`
* 每次向右滑动`j`，当遇到之前重复出现的字符`c`时，此时`[i, j-1]`区间没有重复的，`i`定位到`max(i, 上一个c的位置+1)`，此时`[i, j]`之间消除了重复字符c

* `O(N)`

