class TreeNode {
    val: number
    left: TreeNode | null
    right: TreeNode | null

    constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
        this.val = (val === undefined ? 0 : val)
        this.left = (left === undefined ? null : left)
        this.right = (right === undefined ? null : right)
    }
}

function minDepth(root: TreeNode | null): number {
    let min = Infinity;

    function dfs(node: TreeNode, currentDepth: number) {
        if (!node.left && !node.right) {
            min = Math.min(min, currentDepth);
        }

        if (node.left) {
            dfs(node.left, currentDepth + 1)
        }

        if (node.right) {
            dfs(node.right, currentDepth + 1)
        }
    }


    if (root) {
        dfs(root, 1)
        return min
    } else {
        return 0
    }
}