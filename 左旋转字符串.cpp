//思路：
//例如：输入字符串"abcdefg"和数字2，该函数将返回左旋转2位得到的结果"cdefgab";
// 第一步：翻转字符串“ab”，得到"ba"；

// 第二步：翻转字符串"cdefg"，得到"gfedc"；

// 第三步：翻转字符串"bagfedc"，得到"cdefgab"；

// 或者：
// 第一步：翻转整个字符串"abcdefg",得到"gfedcba"

// 第二步：翻转字符串“gfedc”，得到"cdefg"

// 第三步：翻转字符串"ba",得到"ab"


class Solution {
    public:
        string LeftRotateString(string str, int n)
        {
            string result = str;
            int length = result.size();
            if(length < 0)
            {
                return NULL;
            }
            if(0 <= n <= length)
            {
                int pFirstBegin = 0, pFirstEnd = n - 1;
                int pSecondBegin = n, pSecondEnd = length - 1;
                ReverseString(result, pFirstBegin, pFirstEnd);
                ReverseString(result, pSecondBegin, pSecondEnd);
                ReverseString(result, pFirstBegin, pSecondEnd);
            }
            return result;

        }
    private:
        void ReverseString(string &str, int begin, int end)
        {
            while(begin < end)
            {
                swap(str[begin++], str[end--]);
            }
        }

};
