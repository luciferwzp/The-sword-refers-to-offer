//输入一个字符串,按字典序打印出该字符串中字符的所有排列。
//例如输入字符串abc，则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。


class Solution {
    public:
        vector<string> Permutation(string str) {
            //判断输入
            if(str.length() == 0){
                return result;
            }
            PermutationCore(str, 0);
            //对结果进行排序
            sort(result.begin(), result.end());
            return result;
        }

    private:
        void PermutationCore(string str, int begin){
            //递归结束的条件：第一位和最后一位交换完成
            if(begin == str.length()){
                result.push_back(str);
                return;
            }
            for(int i = begin; i < str.length(); i++){
                //如果字符串相同，则不交换
                if(i != begin && str[i] == str[begin]){
                    continue;
                }
                //位置交换
                swap(str[begin], str[i]);
                //递归调用，前面begin+1的位置不变，后面的字符串全排列
                PermutationCore(str, begin + 1);
            }
        }
        vector<string> result;
};
