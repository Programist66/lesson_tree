#include <iostream>

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree {
private:
    Node* root;

    Node* insertRecursive(Node* current, int value) {
        if (current == nullptr) {
            return new Node(value);
        }

        if (value < current->data) {
            current->left = insertRecursive(current->left, value);
        }
        else if (value > current->data) {
            current->right = insertRecursive(current->right, value);
        }

        return current;
    }

    Node* findMin(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    Node* deleteRecursive(Node* current, int value) {
        if (current == nullptr) {
            return nullptr;
        }

        if (value == current->data) {
            if (current->left == nullptr && current->right == nullptr) {
                delete current;
                return nullptr;
            }
            if (current->left == nullptr) {
                Node* temp = current->right;
                delete current;
                return temp;
            }
            if (current->right == nullptr) {
                Node* temp = current->left;
                delete current;
                return temp;
            }
            Node* temp = findMin(current->right);
            current->data = temp->data;
            current->right = deleteRecursive(current->right, temp->data);
        }
        else if (value < current->data) {
            current->left = deleteRecursive(current->left, value);
        }
        else {
            current->right = deleteRecursive(current->right, value);
        }

        return current;
    }

public:
    BinaryTree() : root(nullptr) {}

    void insert(int value) {
        root = insertRecursive(root, value);
    }

    void remove(int value) {
        root = deleteRecursive(root, value);
    }

    bool search(int value) {
        Node* current = root;
        while (current != nullptr) {
            if (value == current->data) {
                return true;
            }
            else if (value < current->data) {
                current = current->left;
            }
            else {
                current = current->right;
            }
        }
        return false;
    }

    void printInOrderTraversal(Node* node) {
        if (node != nullptr) {
            printInOrderTraversal(node->left);
            std::cout << node->data << " ";
            printInOrderTraversal(node->right);
        }
    }

    void printInOrderTraversal() {
        printInOrderTraversal(root);
    }
};

int main() {
    BinaryTree tree;

    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);

    std::cout << "In-order traversal: ";
    tree.printInOrderTraversal();
    std::cout << std::endl;

    int searchValue = 4;
    if (tree.search(searchValue)) {
        std::cout << searchValue << " found in the tree." << std::endl;
    }
    else {
        std::cout << searchValue << " not found in the tree." << std::endl;
    }

    int deleteValue = 3;
    tree.remove(deleteValue);

    std::cout << "In-order traversal after removing " << deleteValue << ": ";
    tree.printInOrderTraversal();
    std::cout << std::endl;

    return 0;
}
