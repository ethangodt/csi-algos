#include <limits.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void dfs(struct TreeNode *node, int current_depth, int *min) {
    if (!node->left && !node->right) {
        if (current_depth < *min) {
            *min = current_depth;
        }
    }

    if (node->left) {
        dfs(node->left, current_depth + 1, min);
    }

    if (node->right) {
        dfs(node->right, current_depth + 1, min);
    }
}

int minDepth(struct TreeNode *root) {
    int min = INT_MAX;

    if (!root) {
        return 0;
    }

    dfs(root, 1, &min);

    return min;
}