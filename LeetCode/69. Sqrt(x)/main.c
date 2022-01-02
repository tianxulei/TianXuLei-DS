int mySqrt(int x) {
        int a = x; 
        long long k = 0;
        while (a != 0) {
            k++;
            a = a / 10;
        }
        k = (k - 1) / 2;
        a = 1;
        for (int i = 0; i < k; ++i) {
            a = a * 10;
        }
        k = a * a;
        while (k < x) {
            k = k + (a++<<1) + 1;
        }
        if (k == x) return a;
        return a - 1;
    }
