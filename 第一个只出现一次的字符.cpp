//思路：建立一个哈希表，第一次扫描的时候，统计每个字符的出现次数。
//第二次扫描的时候，如果该字符出现的次数为1，则返回这个字符的位置。

class Solution {
    public:
        int FirstNotRepeatingChar(string str) {
            int length = str.size();
            if(length == 0){
                return -1;
            }
            map<char, int> item;
            for(int i = 0; i < length; i++){
                item[str[i]]++;
            }
            for(int i = 0; i < length; i++){
                if(item[str[i]] == 1){
                    return i;
                }
            }
            return -1;
        }
};
