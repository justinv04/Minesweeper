inline int min(int a, int b)
{
    if(a > b)
        return b;
    return a;
}

inline int clamp(int min, int val, int max)
{
    if(val < min) return min;
    if(val > max) return max;
    return val;
}

