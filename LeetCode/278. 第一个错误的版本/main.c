
class Solution {
public:
    int firstBadVersion(int n) {
        unsigned int enter,left=1,right=n;
        while(left<right)
        {
            enter=left+((right-left)>>1);
            if(isBadVersion(enter))
                right=enter;
            else
                left=enter+1;
        }
        return right;
    }
};
