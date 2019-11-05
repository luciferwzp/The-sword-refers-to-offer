//还可以把当前序列当成是一个下标和下标对应值是相同的数组（时间复杂度为O(n),空间复杂度为O(1)）； 遍历数组，判断当前位的值和下标是否相等：

//若相等，则遍历下一位；
//若不等，则将当前位置i上的元素和a[i]位置上的元素比较：若它们相等，则找到了第一个相同的元素；
//若不等，则将它们两交换。换完之后a[i]位置上的值和它的下标是对应的，但i位置上的元素和下标并不一定对应；
//重复2的操作，直到当前位置i的值也为i，将i向后移一位，再重复2。

//举例说明：{2,3,1,0,2,5,3}

//0(索引值)和2(索引值位置的元素)不相等，并且2(索引值位置的元素)和1(以该索引值位置的元素2为索引值的位置的元素)不相等，则交换位置，数组变为：{1,3,2,0,2,5,3}；
//0(索引值)和1(索引值位置的元素)仍然不相等，并且1(索引值位置的元素)和3(以该索引值位置的元素1为索引值的位置的元素)不相等，则交换位置，数组变为：{3,1,2,0,2,5,3}；
//0(索引值)和3(索引值位置的元素)仍然不相等，并且3(索引值位置的元素)和0(以该索引值位置的元素3为索引值的位置的元素)不相等，则交换位置，数组变为：{0,1,2,3,2,5,3}；
//0(索引值)和0(索引值位置的元素)相等，遍历下一个元素；
//1(索引值)和1(索引值位置的元素)相等，遍历下一个元素；
//2(索引值)和2(索引值位置的元素)相等，遍历下一个元素；
//3(索引值)和3(索引值位置的元素)相等，遍历下一个元素；
//4(索引值)和2(索引值位置的元素)不相等，但是2(索引值位置的元素)和2(以该索引值位置的元素2为索引值的位置的元素)相等，则找到了第一个重复的元素。

class Solution {
    public:
        bool duplicate(int numbers[], int length, int* duplication) {
            // 非法输入
            if(numbers == NULL || length <= 0){
                return false;
            }
            // 非法输入
            for(int i = 0; i < length; i++){
                if(numbers[i] < 0 || numbers[i] > length - 1){
                    return false;
                }
            }
            // 遍历查找第一个重复的数
            for(int i = 0; i < length; i++){
                while(numbers[i] != i){
                    if(numbers[i] == numbers[numbers[i]]){
                        *duplication = numbers[i];
                        return true;
                    }
                    swap(numbers[i], numbers[numbers[i]]);
                }
            }
            return false;
        }
};
