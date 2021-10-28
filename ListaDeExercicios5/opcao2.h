#include <cmath>

void calc_maxmin(int num)
{
    extern int Max;
    if (num > Max){
        Max = num;
    }

    if (num >= 0){    
        extern int Min;
        if (num < Min){
            Min = num;
        }
    }else{
        extern int Min;
        if (abs(num) > abs(Min)){
            Min = num;
        }
    }
}