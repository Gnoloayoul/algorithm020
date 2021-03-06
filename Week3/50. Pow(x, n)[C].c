double posPow(double x, int n) {
    if(x==1) return 1;
    if(x==0) return 0;
    if(n==0) {
        return 1;
    } else if (n==1) {
        return x;
    } else if (n%2==0) {
        double halfPow = posPow(x,n/2);
        return halfPow * halfPow;
    } else {
        return x * posPow(x,n-1);
    }
}


double myPow(double x, int n) {
    if(n>=0) return posPow(x,n);
    else if (n==INT_MIN) {
        return 1/posPow(x,INT_MAX)/x;
    } else {
        return 1/posPow(x,-1*n);
    }
}