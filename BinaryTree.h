//
// Created by amit levi on 06/10/2022.
//

#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <algorithm>
#include <iostream>
#include <vector>



template <typename T>
class Node {
public:
    Node<T> *parent, *left, *right;
    int id{};
    [[maybe_unused]] T data;


    Node();
    explicit Node(T data);
    Node(T data, Node<T> *parent, Node<T> *left, Node<T> *right);

    static void walk(const Node<T> *tree);
    static Node<T> *find(Node<T> *tree, int value);
    static Node<T> *minimum(Node<T> *tree);
    static Node<T> *maximum(Node<T> *tree);
    static Node<T> *successor(Node<T> *node);

    // Always returns the root of the tree, whether it had to be modified
    // or not
    static Node<T> *insertNode(Node<T> *tree, Node<T> *node);
    static Node<T> *deleteNode(Node<T> *tree, Node<T> *node);

private:
    static Node<T> *transplant(Node<T> *tree, Node<T> *u, Node<T> *v);
};


template<class T>
Node<T>::Node() : parent(NULL), left(NULL), right(NULL) {
    parent = NULL;
    left = NULL;
    right = NULL;
}



template<class T>
Node<T>::Node(T data) : data(data),  parent(NULL), left(NULL), right(NULL),id(data.get_id()) {}

template<class T>
Node<T>::Node(T data, Node<T> *parent, Node<T> *left, Node<T> *right) :
        data(data), parent(parent), left(left), right(right) {
    this->id(data.get_id());
}



template<typename T>
std::ostream &operator<<(std::ostream &output, Node<T> node);



template <typename T>
void Node<T>::walk(const Node<T> *tree) {
    if (tree == NULL) return;

    walk(tree -> left);
    std::cout << tree -> id << "\n";
    walk(tree -> right);
}

template <typename T>
Node<T> *Node<T>::insertNode(Node<T> *tree, Node<T> *node) {
    if (!tree) {
        tree = node;
        node -> parent = NULL;
    } else {
        Node<T> *parent, *search = tree;
        bool left;
        while (search != NULL) {
            parent = search;
            if (node -> id <= search -> id) {
                search = search -> left;
                left = true;
            } else {
                search = search -> right;
                left = false;
            }
        }
        node -> parent = parent;
        if (left) parent -> left = node;
        else parent -> right = node;
    }

    return tree;
}

template <typename T> Node<T> *Node<T>::find(Node<T> *tree, int value) {
    if (!tree || tree -> id == value) return tree;
    if (value < tree -> id) return find(tree -> left, value);
    else return find(tree -> right, value);
}

template <typename T> Node<T> *Node<T>::minimum(Node<T> *tree) {
    if (!tree) return NULL;

    while (tree -> left) {
        tree = tree -> left;
    }

    return tree;
}

template <typename T> Node<T> *Node<T>::maximum(Node<T> *tree) {
    if (!tree) return NULL;

    while (tree -> right) {
        tree = tree -> right;
    }

    return tree;
}

template <typename T> Node<T> *Node<T>::successor(Node<T> *node) {
    if (!node) return NULL;

    if (node -> right) {
        return minimum(node -> right);
    } else {
        // We need to traverse upwards in the tree to find a node where
        // the node is the left child of a parent
        // parent is the successor

        Node<T> *parent = node -> parent;
        while(parent && node != parent -> left) {
            node = parent;
            parent = node -> parent;
        }

        return parent;
    }

}

// make node U's parent have node v has its child
template <typename T> Node<T> *Node<T>::transplant(Node<T> *tree, Node<T> *u, Node<T> *v) {
    if (!u -> parent) tree = v;
    else if (u -> parent -> left == u) {
        u -> left = v;
    } else if (u -> parent -> right == u) {
        u -> right = v;
    }
    if (v) v -> parent = u -> parent;
    return tree;
}

template <typename T> Node<T> *Node<T>::deleteNode(Node<T> *tree, Node<T> *node) {
    if (!node -> left) {
        tree = transplant(tree, node, node -> right);
    } else if (!node -> right) {
        tree = transplant(tree, node, node -> left);
    } else {
        // Has two children -- successor must be on the right
        Node <int> *successor = minimum(node -> right);
        assert(successor -> left == nullptr);
        if (successor != node -> right) {
            tree = transplant(tree, successor, successor -> right);
            successor -> right = node -> right;
            successor -> right -> parent = successor;
        }

        tree = transplant(tree, node, successor);
        successor -> left = node -> left;
        successor -> left -> parent = successor;
    }
    return tree;
}

template<typename T> std::ostream &operator<<(std::ostream &output, Node<T> node) {
    output << "Value: " << node.id;
    if (node.parent) output << " Parent: " << node.parent -> id;
    if (node.left) output << " Left: " << node.left -> id;
    if (node.right) output << " Right: " << node.right -> id;
    output << "\n";
    return output;
}








#endif//BINARYTREE_H




