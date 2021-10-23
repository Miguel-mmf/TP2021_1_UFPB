void calc_maxmin(int num)
{
    extern int Max;
    if (num > Max){
        Max = num;
    }

    extern int Min;
    if (num < Min){
        Min = num;
    }
}