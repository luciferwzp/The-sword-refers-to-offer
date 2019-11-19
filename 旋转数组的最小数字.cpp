class Solution {
    public:
        int minNumberInRotateArray(vector<int> rotateArray) {
            int length_vector=rotateArray.size();  //得到数组的长度
            if (length_vector==0)
                return 0;

            //查找数组中的最小值
            int low=0;
            int high=length_vector-1;

            if(low==high)
                return rotateArray[low];

            while(low<high){
                if(rotateArray[low]<rotateArray[high])    //数组中元素是有序的
                    return rotateArray[low];
                if (high==low+1)
                    return rotateArray[high];   //数组中只有两个元素，存在旋转，则后面一个元素为最小元素

                int mid=(high+low)/2;

                if(rotateArray[low]>=rotateArray[mid]&& rotateArray[high]>=rotateArray[mid]){  //此时只能顺序查找
                    int index=low;
                    for (int i=low+1;i<=high;i++){
                        if (rotateArray[index]>rotateArray[i])
                            index=i;
                    }
                    return rotateArray[index];
                }

                if(rotateArray[low]<=rotateArray[mid])         //最小元素在mid~high之间
                    low=mid;
                else if (rotateArray[high]>=rotateArray[mid])   //最小元素在low~mid之间
                    high=mid;            
            }
            return -1;                    //查找失败
        }
};
