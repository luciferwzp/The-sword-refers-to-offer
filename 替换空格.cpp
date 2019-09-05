#include<iostream>
using namespace std;

class Solution{
public:
    void replaceSpace(char *str, int length){
        //此处的length不是str的实际长度
        if(str == NULL || length <= 0)
            return;

        int Reallength = 0;//字符串实际长度
        int blank = 0; //空格个数
        int i = 0;
        //计算空格个数
        while(str[i] != '\0')
        {
            ++Reallength;
            if(str[i] == ' ')
                ++blank;
            i++;
        }

        //重新计算新字符串的长度
        int Newlength = Reallength + 2 * blank;
        if(Newspace > length)
            return;

        //从后往前开始替换
        while(Reallength >= 0 && Newspace > Reallength)
        {
            if(str[Reallength] == ' ')//是空格，开始替换
            {
                str[Newlength--] = '0';
                str[Newlength--] = '2';
                str[Newlength--] = '%';
            }
            else 
            {
                str[Newlength--] = str[Reallength];
            }
            Reallength--;
        }
    }
};
