#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// 创建新节点
TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// 查找节点的双亲节点
TreeNode* findParent(TreeNode* root, int n, TreeNode* parent) {
    if (root == NULL) {
        return NULL;  // 找不到，返回NULL
    }

    if (root->data == n) {
        return parent;  // 找到节点n，返回父节点
    }

    // 递归查找左子树
    TreeNode* leftResult = findParent(root->left, n, root);
    if (leftResult != NULL) {
        return leftResult;
    }

    // 递归查找右子树
    return findParent(root->right, n, root);
}

// 主函数：查找节点n的双亲节点
void findNodeParent(TreeNode* root, int n) {
    if (root == NULL) {
        printf("树为空\n");
        return;
    }

    if (root->data == n) {
        printf("根节点没有父节点\n");
        return;
    }

    // 查找节点n的父节点
    TreeNode* parent = findParent(root, n, NULL);

    if (parent == NULL) {
        printf("节点n不存在\n");
    }
    else {
        printf("节点n的双亲节点值是：%d\n", parent->data);
    }
}

// 测试函数
int main() {
    TreeNode* root = createNode(1);  // 创建根节点
    root->left = createNode(2);       // 左子节点
    root->right = createNode(3);      // 右子节点
    root->left->left = createNode(4); // 左子节点的左子节点
    root->left->right = createNode(5); // 左子节点的右子节点

    // 查找不同节点的双亲节点
    findNodeParent(root, 1); // 测试根节点
    findNodeParent(root, 2); // 测试节点2
    findNodeParent(root, 5); // 测试节点5
    findNodeParent(root, 6); // 测试不存在的节点

    return 0;
}
