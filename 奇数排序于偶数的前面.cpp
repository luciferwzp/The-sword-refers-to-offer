//输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
//使得所有的奇数位于数组的前半部分，所有的偶数位于位于数组的后半部分，
//并保证奇数和奇数，偶数和偶数之间的相对位置不变。

//创建双向队列，遍历数组，奇数前插入，偶数后插入。最后使用assign方法实现不同容器但相容的类型赋值.


class Solution {
    public:
        void reOrderArray(vector<int> &array) {
            deque<int> result;
            int num = array.size();
            for(int i = 0; i < num; i++){
                if(array[num - i - 1] % 2 == 1){
                    result.push_front(array[num - i - 1]);
                }
                if(array[i] % 2 == 0){
                    result.push_back(array[i]);
                }
            }
            array.assign(result.begin(),result.end());
        }
};
