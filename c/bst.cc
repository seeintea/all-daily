//
//  main.cpp
//
//  Created by LiweiGu on 2020/2/26.
//  Copyright © 2020 LiweiGu. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

// 二叉搜索树
typedef int var;

struct Node {
    var data;
    struct Node* leftChild;
    struct Node* rightChild;
};

// 先序遍历
void preorder(const struct Node* node){
    printf("%d\t", node->data);
    if(node->leftChild)
        preorder(node->leftChild);
    if(node->rightChild)
        preorder(node->rightChild);
}

struct Node* crateNode(var data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->leftChild = nullptr;
    node->rightChild = nullptr;
    return node;
}

// 递归
void insert_bad(struct Node* node, var data){
    bool cp;
    // 判断需要插入的节点位置
    node->data > data ? cp = true : cp = false;
    // 寻找空槽
    if(cp && node->leftChild)
        insert_bad(node->leftChild, data);
    else if(cp && !(node->leftChild))
        node->leftChild = crateNode(data);
    if(!cp && node->rightChild)
        insert_bad(node->rightChild, data);
    else if(!cp && !(node->rightChild))
        node->rightChild = crateNode(data);
}

// 非递归
void insert(struct Node* node, var data){
    bool cp = false, state = true;
    while(state){
        state = false;
        node->data > data ? cp = true : cp = false;
        if(cp && node->leftChild){
            node = node->leftChild;
            state = true;
        } else if(!cp && node->rightChild){
            node = node->rightChild;
            state = true;
        }
    }
    if(cp)
        node->leftChild = crateNode(data);
    else
        node->rightChild = crateNode(data);
}

// 二叉搜索树查询 与插入类似
// 仅给出递归版本
// 返回值与查询值相同则suc，否则返回接近最大值
var search(const struct Node* node, var data){
    bool cp;
    var bup = node->data;
    if (bup == data) return bup;
    node->data >= data ? cp = true : cp = false;
    if(cp && node->leftChild){
        bup = search(node->leftChild, data);
    } else if(!cp && node->rightChild){
        bup = search(node->rightChild, data);
    }
    return bup;
}

// 二叉搜索树删除
// consider: 删除节点后, 剩下节点的操作
// 删除成功 返回删除值, 失败返回-1
var delete_node(struct Node &node, var data) {
    var bup = -1;
    // 判断是否为首节点
    if(node.data == data){
        bup = node.data;
        struct Node* n_node = node.rightChild;
        struct Node* bup_node = n_node;
        while (n_node->leftChild) {
            n_node = n_node->leftChild;
        }
        n_node->leftChild = node.leftChild;
        node = *bup_node;
        return  bup;
    }
    // 确定删除节点所在位置
    // 备份BST
    struct Node* n_node = &node;
    struct Node* bup_node = n_node;
    bool cp = false, flag = true, state = true;
    // Tip: 删除此节点需要寻找被删除节点的父节点
    // 不使用 search 函数的原因: 使用额外的时间仅用来确定是否存在
    // 需要进行分树操作
    while(state){
    	state = false;
    	// 确定节点的走向
        n_node->data > data ? cp = true : cp = false;
        // 判断节点的值是否与所需要匹配的值相等
        // 短路求值
        if((n_node->leftChild && n_node->leftChild->data == data) || (n_node->rightChild && n_node->rightChild->data == data))
            flag = false;
        // 确定节点
        if(cp && flag && n_node->leftChild){
        	n_node = n_node->leftChild;
            state = true;
        } else if(!cp && flag && n_node->rightChild){
        	n_node = n_node->rightChild;
            state = true;
        }
    }
    struct Node* next_node = nullptr;
    // 查看此时节点是否符合要求
    if(cp && (n_node->leftChild && n_node->leftChild->data == data)){
        next_node = n_node->leftChild;
        state = true;
    }
    else if(!cp && (n_node->rightChild && n_node->rightChild->data == data)){
        next_node = n_node->rightChild;
        state = true;
    }
    // 删除节点
    // 被删除节点恰好是叶节点
    if(state && !next_node->leftChild && !next_node->rightChild){
        bup = next_node->data;
        cp ? n_node->leftChild = nullptr : n_node->rightChild = nullptr;
        node = *bup_node;
        return bup;
    }
    // 完成删除
    if(state){
        struct Node* bit_tree = nullptr;
        cp ? bit_tree = n_node->leftChild : bit_tree = n_node->rightChild ;
        bup = bit_tree->data;
        delete_node(*bit_tree ,bit_tree->data);
        cp ? n_node->leftChild = bit_tree : n_node->rightChild = bit_tree;
        node = *bup_node;
        return bup;
    }
    return bup;
}


int main() {
    
    /*------------------------ 创建树 ----------------------- *
     *              ---------- 10 ----------                 *
     *             |                        |                *
     *       ------8------            ------17------         *
     *      |             |          |              |        *
     *   ---6---          9       ---15---       ---20---    *
     *  |       |                |        |     |        |   *
     *  2       7                11       16    18       21  *
     *------------------------------------------------------ *
     */
    
    struct Node* node = crateNode(10);
    insert(node, 8);
    insert(node, 17);
    insert(node, 6);
    insert(node, 9);
    insert(node, 7);
    insert(node, 2);
    insert(node, 20);
    insert(node, 15);
    insert(node, 11);
    insert(node, 16);
    insert(node, 18);
    insert(node, 21);
    
//    insert_bad(node, 3);
//    insert_bad(node, 6);
//    insert_bad(node, 4);
//    insert_bad(node, 1);
//    insert_bad(node, 8);
//    insert_bad(node, 7);
//    insert_bad(node, 9);
    
    preorder(node);
    printf("\n");
    
    printf("查询值:%d, 查询结果: %d\n", 13, search(node, 13));
    printf("查询值: %d, 查询结果: %d\n", 1, search(node, 1));
    printf("查询值: %d, 查询结果: %d\n", 8, search(node, 8));
    printf("查询值:%d, 查询结果: %d\n", 10, search(node, 10));
    printf("查询值:%d, 查询结果: %d\n", 21, search(node, 21));
    
    printf("%d\n",delete_node(*node, 17));
    preorder(node);
    printf("\n");
    
    return 0;
}
