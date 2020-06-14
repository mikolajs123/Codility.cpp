int solution1(int X, int Y, int D) {
    return (Y - X + (D - 1)) / D;
}

#include <math.h>

int solution2(int X, int Y, int D) {
    double jumps = (double)(Y - X) / D;
    
    return ceil(jumps);
}
