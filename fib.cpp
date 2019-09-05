class Solution {
    public:
        /* 递归算法 
        //由于 fib 一般到后面会是一个大数，建议使用 long long
        int Fibonacci(int n) {
        if(n == 0)
        return 0;
        else if(n == 1 || n == 2)
        return 1;
        else 
        return Fibonacci(n - 1) + Fibonacci(n - 2);
        */


        //非递归
        int Fibonacci(int n) {
            int first = 0;
            int second = 1;
            int third = 0;

            if(n == 1)
                return 1;

            for(int i = 2; i <= n; i++)
            {
                third = first + second;
                first = second;
                second = third;
            }
            return third;
        }
};




