#include <iostream>
#include <iomanip>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

Node* insertNode(Node* root, int value) {
    if (root == nullptr)
        return createNode(value);

    if (value < root->data)
        root->left = insertNode(root->left, value);
    else
        root->right = insertNode(root->right, value);

    return root;
}

void preorder(Node* root) {
    if (root) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void postorder(Node* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

void printTree(Node* root, int space = 0) {
    if (root == nullptr)
        return;

    space += 6;
    printTree(root->right, space);
    cout << endl;
    for (int i = 6; i < space; i++)
        cout << " ";
    cout << root->data << "\n";
    printTree(root->left, space);
}

int main() {
    Node* root = nullptr;
    int choice, value;

    while (true) {
        cout << "\n==============================";
        cout << "\n BINARY TREE VISUALIZER MENU";
        cout << "\n==============================";
        cout << "\n1. Insert Node";
        cout << "\n2. Display Tree (Visual)";
        cout << "\n3. Preorder Traversal";
        cout << "\n4. Inorder Traversal";
        cout << "\n5. Postorder Traversal";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                root = insertNode(root, value);
                cout << "Node Inserted!\n";
                break;

            case 2:
                cout << "\n--- VISUALIZED BINARY TREE ---\n";
                printTree(root);
                break;

            case 3:
                cout << "\nPreorder Traversal: ";
                preorder(root);
                cout << endl;
                break;

            case 4:
                cout << "\nInorder Traversal: ";
                inorder(root);
                cout << endl;
                break;

            case 5:
                cout << "\nPostorder Traversal: ";
                postorder(root);
                cout << endl;
                break;

            case 6:
                cout << "\nExiting... Thank You!\n";
                return 0;

            default:
                cout << "\nInvalid Choice! Please try again.\n";
        }
    }
}
