/* Node* minValueNode(Node* node) {

    Node* current = node;

    while (current->left != nullptr)
        current = current->left;

    return current;
}

Node* deleteNode(Node* root, int key) {

    // Normal BST deletion
    if (root == nullptr)
        return root;

    if (key < root->key) {

        root->left = deleteNode(root->left, key);
    }

    else if (key > root->key) {

        root->right = deleteNode(root->right, key);
    }

    else {

        // 0 or 1 child
        if (root->left == nullptr ||
            root->right == nullptr) {

            Node* child;

            if (root->left != nullptr)
                child = root->left;
            else
                child = root->right;

            // No child
            if (child == nullptr) {

                delete root;
                return nullptr;
            }

            // One child
            else {

                Node* temp = root;

                root = child;

                delete temp;
            }
        }

        // Two children
        else {

            Node* successor =
                minValueNode(root->right);

            root->key = successor->key;

            root->right =
                deleteNode(root->right,
                           successor->key);
        }
    }

    // Update height
    updateHeight(root);

    // Calculate balance
    int balance = getBalance(root);

    // LL
    if (balance > 1 &&
        getBalance(root->left) >= 0) {

        return rightRotate(root);
    }

    // LR
    if (balance > 1 &&
        getBalance(root->left) < 0) {

        root->left =
            leftRotate(root->left);

        return rightRotate(root);
    }

    // RR
    if (balance < -1 &&
        getBalance(root->right) <= 0) {

        return leftRotate(root);
    }

    // RL
    if (balance < -1 &&
        getBalance(root->right) > 0) {

        root->right =
            rightRotate(root->right);

        return leftRotate(root);
    }

    return root;
} */