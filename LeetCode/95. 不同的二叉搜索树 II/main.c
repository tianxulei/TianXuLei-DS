 vector<TreeNode*> back(int start, int end) {
        if (start > end) return {NULL};
        vector<TreeNode*>allTree;
        for (int i = start; i <= end; ++i) {
            vector<TreeNode*>Left = back(start, i - 1);
            vector<TreeNode*>Right = back(i + 1, end);
            for (auto& left : Left) {
                for (auto& right : Right) {
                    allTree.emplace_back(new TreeNode(i, left, right));
                }
            }
        }
        return allTree;
    }
    vector<TreeNode*> generateTrees(int n) {
        if (n < 1) return {};
	    return back(1, n);
    }
