//给定一个非负整数 num，反复将各个位上的数字相加，直到结果为一位数。
//数学规律，每次减小的是9的倍数
int addDigits(int num) {
        if(num==0) return 0;
        num%=9;
        return num==0?9:num;
    }
