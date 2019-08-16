//此二维数组是一个从左到右，从上到下逐级递增的二维数组

//从右上角查找
bool Find(int* matrix, int rows, int columns, int number)
{
    bool found = false;

    if(matrix != NULL && rows > 0 && columns > 0)
    {
        int row = 0;
        int column = columns - 1;
        while(row < rows && column >=0)
        {
            if(matrix[row * columns + column] == number)
            {
                found = true;
                break;

            }
            else if(matrix[row * columns + column] > number)
                //查找的数比此次右上角的数小，此列排除，列减减
                --column;
            else
                //查找的数比此次右上角的数大，此行排除，行加加
                ++row;

        }

    }
    return found;

}



//同理
//使用STL容器vector实现

class Solution {
    public:
        bool Find(int target, vector<vector<int> > array) {
            int row_len = (int)array.size();//行数
            int row = 0;
            int col = (int)array[0].size()-1;//列数
            while(col >= 0 && row < row_len)
            {
                if(array[row][col] > target){
                    col--;

                }
                else if(array[row][col] < target){
                    row++;

                }
                else{
                    return true;

                }

            }
            return false;

        }

};


