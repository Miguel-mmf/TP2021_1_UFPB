//minmax.h

template <class T> T Max(T a, T b)
{
    if (a > b)
        return a;
    else
        return b;
}

template <class T> T Min(T a, T b)
{
    if (a < b)
        return a;
    return b;
}