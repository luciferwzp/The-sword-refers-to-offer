//题目一：找出数组中重复出现的数字（可修改数组）
//数组：{2, 3, 1, 0, 2, 5, 3}
//思路：
//以数组{2，3，1, 0, 2, 5, 3}为例，数组第0个数字是2，而下标是0，即下标不相等，于是把它和下标为2的数字1交换，
//交换后的数组是{1，2, 3, 0, 2, 5, 3}。此时第0个数字是1，仍然与下标不相等，继续把它和下标为1的数字3交换，
//交换后的数组是{3, 1, 2，0, 2, 5, 3}。接下来继续交换第0个数字3和第三个数字0，数组变为{0, 1，2，3，2，5，3}，
//因此0,1,2,3下标与数都匹配上了，那就不需要执行任何操作了。而接下来就是下标为4的数2，下标为4的数2又与下标为2的数2相同，
//由此，找到了重复的数字


bool duplicate(int number[], int length, int* duplication)
{
    if(number == nullptr || length <= 0)
    {
        return false;
    }

    for(int i = 0; i < length; i++)
    {
        if(number[i] < 0 || number[i] > length - 1)
        {
            return false;
        }
    }

    for(int i = 0; i < lengthl; i++)
    {
        while(number[i] != i)
        {
            if(number[i] == number[number[i]])
            {
                *duplication = number[i];
                return true;
            }

            //swap number[i] and number[number[i]]
            int tmp = number[i];
            number[i] = number[number[i]];
            number[number[i]] = tmp;
        }
    }
    return false;
}





//题目二：不修改数组找出重复的数字
//数组{2, 3, 5, 4, 3, 2, 6, 7}
//思路：二分查找思路
//以数组{2, 3, 5, 4, 3, 2, 6, 7}为例， 这个长度为8的数组所有数字都在1~7的范围内。
//中间的数字4将1~7分为两部分，一部分1~4，一部分是5~7。
//接下来统计1~4范围内这4个数字在数组中出现的次数，出现了5次，由此一定有重复的数字。
//由此再将1~4分为两部分，一部分1~2，另一部分为3~4。
//1和2出现了两次，由此没有出现重复。而数字在3和4数组中出现的次数为3次。
//由此，再分组。最后找出出现的重复数字
//缺点：
//不能找出所有的重复数字


int getDuplication(const int*number, int length)
{
    if(number == nullptr || length < 0)
    {
        return -1;
    }

    int start = 1;
    int end = length - 1;
    while(end >= start)
    {
        int middle = ((end - start) >> 1) + start;
        int count = countRange(number, length, start, middle)
        if(end == start)
        {
            if(count > 1)
                return start;
            else
                return break;
        }

        if(count > (middle - start + 1))
            end == middle;
        else 
            start = middle + 1;
    }
    return -1;
}

int countRange(const int* number, int length, int start, int end)
{
    if(number == nullptr)
    {
        return 0;
    }

    int count = 0;
    for(int i = 0; i < length; i++)
    {
        if(number[i] >= start && number[i] <= end)
            ++count;
    }
    return count;
}
