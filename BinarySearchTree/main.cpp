#include <iostream>
#include "BinarySearchTree.h"

template<typename T>
int getArraySize(T arr[])
{
    return sizeof(arr);
}

int main()
{
   { BinarySearchTree bst1;
    BinarySearchTree bst2(4);

    // bst2.inorder();

    bst1.insert(8);
    bst1.insert(3);
    bst1.insert(10);
    bst1.insert(1);
    bst1.insert(6);
    bst1.insert(14);
    bst1.insert(13);
    bst1.insert(4);
    bst1.insert(7);

    // std::cout << bst1.search(2) << '\n';

    // bst1.levelOrder();

    bst1.inorder();
    bst1.preorder();
    bst1.postorder();
    }

    // bst1.deleteTree();

    //bst1.deleteTree();
    // bst1.inorder();
}