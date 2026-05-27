#include <stdio.h>
#include <stdlib.h>

// 二叉树节点结构体定义
struct TreeNode {
    int val;          // 节点的值
    struct TreeNode* left;   // 左子节点
    struct TreeNode* right;  // 右子节点
};

// 交换二叉树左右子树的函数
void swapSubtrees(struct TreeNode* root) {
    if (root == NULL) {
        return;  // 如果节点为空，直接返回
    }

    // 交换当前节点的左右子树
    struct TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // 递归交换左右子树
    swapSubtrees(root->left);
    swapSubtrees(root->right);
}

// 辅助函数：创建一个新节点
struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 辅助函数：前序遍历打印二叉树
void preorderTraversal(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }

    printf("%d ", root->val);  // 打印当前节点
    preorderTraversal(root->left);  // 递归遍历左子树
    preorderTraversal(root->right); // 递归遍历右子树
}

// 主函数
int main() {
    // 构建一个简单的二叉树
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->right = createNode(6);

    printf("原始二叉树的前序遍历: ");
    preorderTraversal(root);
    printf("\n");

    // 交换二叉树的左右子树
    swapSubtrees(root);

    printf("交换后二叉树的前序遍历: ");
    preorderTraversal(root);
    printf("\n");

    return 0;
}
