/*有两个容量分别为 x升 和 y升 的水壶以及无限多的水。请判断能否通过使用这两个水壶，从而可以得到恰好 z升 的水？
如果可以，最后请用以上水壶中的一或两个来盛放取得的 z升 水。
你允许：
装满任意一个水壶
清空任意一个水壶
从一个水壶向另外一个水壶倒水，直到装满或者倒空
示例 1: (From the famous "Die Hard" example)
输入: x = 3, y = 5, z = 4
输出: True*/
/*不可能有两个壶同时处于不满不空的状态
    装满只对空瓶操作，否则相当于之前操作作废
    倒水不改变水的总量
    装满操作是加法
    清空操作是减法
    二者都以操作对象容量为运算对象
    操作次数相当于系数
    运算结果为mx+ny
    验证一下对系数基本没有要求，运算结果只要在允许范围内都可以得到
    代码实现
    mx+ny的取值是最大公因数的倍数*/
    int test(int a, int b) {
        if (!(a % b))
            return b;
        return test(b, a % b);
    }

    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        if (targetCapacity<0 || targetCapacity>jug1Capacity + jug2Capacity)
            return false;
        if (!targetCapacity)
            return true;
        if (!jug1Capacity || !jug2Capacity)
            return targetCapacity == jug1Capacity + jug2Capacity;
        return !(targetCapacity % test(jug1Capacity, jug2Capacity));
    }
