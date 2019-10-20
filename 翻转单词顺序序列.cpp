//题目：例如，“student. a am I”。
//后来才意识到，这家伙原来把句子单词的顺序翻转了，正确的句子应该是“I am a student.”

class Solution {
    public:
        string ReverseSentence(string str)
        {
            string result = str;
            int length = result.size();
            if(length == 0)
            {
                return "";
            }
            // 追加一个空格，作为反转标志位
            result += ' ';
            int mark = 0;
            // 根据空格，反转所有单词
            for(int i = 0; i < length + 1; i++)
            {
                if(result[i] == ' '){
                    Reverse(result, mark, i - 1);
                    mark = i + 1;
                }
            }
            // 去掉添加的空格
            result = result.substr(0, length);
            // 整体反转
            Reverse(result, 0, length - 1);

            return result;
        }
    private:
        void Reverse(string &str, int begin, int end)
        {
            while(begin < end)
            {
                swap(str[begin++], str[end--]);
            }
        }
};
