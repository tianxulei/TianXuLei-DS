给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

示例 1：
输入：nums = [2,0,2,1,1,0]
输出：[0,0,1,1,2,2]

void sortColors(vector<int>& nums) {
        int red=-1,blue=nums.size(),i=0;
        while(i<blue){
            if(nums[i]==0)
                swap(nums[++red],nums[i++]);
            else if(nums[i]==1)
                ++i;
            else if(nums[i]==2)
                swap(nums[--blue],nums[i]);
        }
    }
