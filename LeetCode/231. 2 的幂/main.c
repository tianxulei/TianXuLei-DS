bool isPowerOfTwo(int n) {
        long sum=1;
        while(sum<n)
            sum*=2;
        return sum==n;
    }
