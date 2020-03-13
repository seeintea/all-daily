//
//  main.cpp
//
//  Created by LiweiGu on 2020/2/26.
//  Copyright © 2020 LiweiGu. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef int var;

struct Node {
    var data;
    struct Node* leftChild;
    struct Node* rightChild;
    
    // 初始化
    void init(var d) {
        data = d;
        leftChild = NULL;
        rightChild = NULL;
    }
    
    // 拷贝
    void copy(struct Node node){
        data = node.data;
        leftChild = node.leftChild;
        rightChild = node.rightChild;
    }
};

// 均通过迭代实现
// 20200313

// 前序遍历
void preorder(const struct Node* node){
    printf("%d\t", node->data);
    if(node->leftChild)
        preorder(node->leftChild);
    if(node->rightChild)
        preorder(node->rightChild);
}

// 中序遍历
void inorder(const struct Node* node){
    if(node->leftChild)
        inorder(node->leftChild);
    printf("%d\t", node->data);
    if(node->rightChild)
        inorder(node->rightChild);
    }

// 后序遍历
void postorder(const struct Node* node){
    if(node->leftChild)
        postorder(node->leftChild);
    if(node->rightChild)
        postorder(node->rightChild);
    printf("%d\t", node->data);
}

int main() {
    
    /*------------- 创建树 -------------
     *        -----7-----             *
     *       |           |            *
     *    ---6---     ---8---         *
     *   |       |   |       |        *
     *   2       1        ---9---     *
     *                   |       |    *
     *                ---4---    3    *
     *               |       |        *
     *               5                *
     *---------------------------------
     */
    
    struct Node p1;
    struct Node p2;
    struct Node p3;
    struct Node p4;
    struct Node p5;
    struct Node p6;
    struct Node p7;
    struct Node p8;
    struct Node p9;
    p1.init(7);
    p2.init(6);
    p3.init(8);
    p4.init(2);
    p5.init(1);
    p6.init(9);
    p7.init(4);
    p8.init(3);
    p9.init(5);
    
    // 第一层
    p1.leftChild = &p2;
    p1.rightChild = &p3;
    // 第二层
    p2.leftChild = &p4;
    p2.rightChild = &p5;
    p3.rightChild = &p6;
    // 第三层
    p6.leftChild = &p7;
    p6.rightChild = &p8;
    // 第四层
    p7.leftChild = &p9;
    
    // 排序算法
    // 前序遍历
    // 预测结果: 7 6 2 1 8 9 4 5 3
    printf("前序遍历结果:  ");
    preorder(&p1);
    printf("\n");
    
    // 中序遍历
    // 预测结果: 2 6 1 7 8 5 4 9 3
    printf("中序遍历结果:  ");
    inorder(&p1);
    printf("\n");
    
    // 后序遍历
    // 预测结果: 2 1 6 5 4 3 9 8 7
    printf("后续遍历结果:  ");
    postorder(&p1);
    printf("\n");
    
    return 0;
}
