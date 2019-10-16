class Solution {
    public:
        int FindGreatestSumOfSubArray(vector<int> array) {
            if(array.empty()){
                return 0;
            }
            // 初始化变量，maxSum为最大和，curSum为当前和
            int maxSum = array[0];
            int curSum = array[0];
            // 遍历所有元素
            for(int i = 1; i < array.size(); i++){
                // 如果当前和小于等于0，说明之前的是负数，则抛弃前面的和，重新计算
                if(curSum <= 0){
                    curSum = array[i];
                }
                // 如果没有问题，直接累加
                else{
                    curSum += array[i];
                }
                // 更新最大和
                if(curSum > maxSum){
                    maxSum = curSum;
                }
            }
            return maxSum;
        }
};
