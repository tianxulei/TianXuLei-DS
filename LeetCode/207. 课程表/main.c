/*你这个学期必须选修 numCourses 门课程，记为 0 到 numCourses - 1 。
在选修某些课程之前需要一些先修课程。 先修课程按数组 prerequisites 给出，其中 prerequisites[i] = [ai, bi] ，表示如果要学习课程 ai 则 必须 先学习课程  bi 。
例如，先修课程对 [0, 1] 表示：想要学习课程 0 ，你需要先完成课程 1 。
请你判断是否可能完成所有课程的学习？如果可以，返回 true ；否则，返回 false 。

示例 1：
输入：numCourses = 2, prerequisites = [[1,0]]
输出：true
解释：总共有 2 门课程。学习课程 1 之前，你需要完成课程 0 。这是可能的。*/
map<int, int>course;//课程，课程前置学科的数量
    stack<int>flag;//前置学科数量为0的course下标
    map<int, vector<int>>table;//课程的前置学科，本课程

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int nums = 0;
        //学科之间的拓扑关系加入table
        for (auto it = prerequisites.begin(); it != prerequisites.end(); ++it) {
            course[(*it)[0]]++;
            if (course.find((*it)[1]) == course.end())
                course[(*it)[1]] = 0;
            table[(*it)[1]].push_back((*it)[0]);
        }
        //找到前置学科为0的学科
        for (auto it = course.begin(); it != course.end(); ++it) {
            if (it->second == 0) {
                flag.push(it->first);
            }
        }
        //只要还有前置学科为0的学科
        while (!flag.empty()) {
            int tmp = flag.top();
            flag.pop();
            ++nums;
            for (auto it = table[tmp].begin(); it != table[tmp].end(); ++it) {
                course[*it]--;
                if (course[*it] == 0)
                    flag.push(*it);
            }
        }
        //如果还有的学科没法学
        for (auto it = course.begin(); it != course.end(); ++it) {
            if (it->second)
                return false;
        }
        //如果学科数量大于能选的数量
        if (nums > numCourses)
            return false;
        return true;
    }
