#include "AVLMovieTitleTree.h"
#include <iostream>


AVLNode::AVLNode(Movie movie) {
    this->value = tolower(movie.GetTitle().at(0));
	this->height = 1;
	this->left = NULL;
	this->right = NULL;
    this->movie = movie;

}

 
AVLMovieTitleTree::AVLMovieTitleTree() {
    root = NULL;
}

AVLMovieTitleTree::AVLMovieTitleTree(MovieList list) {
    root = NULL;
    for (int i = 0; i < list.getLength(); i++) {
        cout << list.getNodeAtPosition(i)->GetTitle().at(0);
        root = insert(root, tolower(list.getNodeAtPosition(i)->GetTitle().at(0)));
    }
}

int AVLMovieTitleTree::height(AVLNode* node) {
    if (node == NULL) {
        return 0;
    }
    return node->height;
}

int AVLMovieTitleTree::balanceFactor(AVLNode* node) {
    if (node == NULL) {
        return 0;
    }
    return height(node->left) - height(node->right);
}

AVLNode* AVLMovieTitleTree::rotateRight(AVLNode* node) {
    AVLNode* newRoot = node->left;
    node->left = newRoot->right;
    newRoot->right = node;
    node->height = 1 + max(height(node->left), height(node->right));
    newRoot->height = 1 + max(height(newRoot->left), height(newRoot->right));
    return newRoot;
}

AVLNode* AVLMovieTitleTree::rotateLeft(AVLNode* node) {
    AVLNode* newRoot = node->right;
    node->right = newRoot->left;
    newRoot->left = node;
    node->height = 1 + max(height(node->left), height(node->right));
    newRoot->height = 1 + max(height(newRoot->left), height(newRoot->right));
    return newRoot;
}

AVLNode* AVLMovieTitleTree::getMinValueNode(AVLNode* node) {
    AVLNode* current = node;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

int AVLMovieTitleTree::getBalance(AVLNode* node) {
    if (node == NULL) {
        return 0;
    }
    return height(node->left) - height(node->right);
}

//Value = first character of movie title
AVLNode* AVLMovieTitleTree::insert(AVLNode* node, Movie movie) {
    if (node == NULL) {
        return new AVLNode(movie);
    }
    if (movie.GetTitle().at(0) < node->value) {
        node->left = insert(node->left, movie);
    }
    else if (movie.GetTitle().at(0) > node->value) {
        node->right = insert(node->right, movie);
    }
    else {
        return node;
    }
    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);
    if (balance > 1 && movie.GetTitle().at(0) < node->left->value) {
        return rotateRight(node);
    }
    if (balance < -1 && movie.GetTitle().at(0) > node->right->value) {
        return rotateLeft(node);
    }
    if (balance > 1 && movie.GetTitle().at(0) > node->left->value) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    if (balance < -1 && movie.GetTitle().at(0) < node->right->value) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }
    return node;
}


AVLNode* AVLMovieTitleTree::search(AVLNode* node, char value) {
    if (node == NULL || node->value == value) {
        return node;
    }
    if (value < node->value) {
        return search(node->left, value);
    }
    else {
        return search(node->right, value);
    }
}

AVLNode* AVLMovieTitleTree::remove(AVLNode* node, char value) {
    if (node == NULL) {
        return node;
    }
    if (value < node->value) {
        node->left = remove(node->left, value);
    }
    else if (value > node->value) {
        node->right = remove(node->right, value);
    }
    else {
        if (node->left == NULL || node->right == NULL) {
            AVLNode* temp = node->left ? node->left : node->right;
            if (temp == NULL) {
                temp = node;
                node = NULL;
            }
            else {
                *node = *temp;
            }
            delete temp;
        }
        else {
            AVLNode* temp = getMinValueNode(node->right);
            node->value = temp->value;
            node->right = remove(node->right, temp->value);
        }
    }
    if (node == NULL) {
        return node;
    }
    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);
    if (balance > 1 && getBalance(node->left) >= 0) {
        return rotateRight(node);
    }
    if (balance > 1 && getBalance(node->left) < 0) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    if (balance < -1 && getBalance(node->right) <= 0) {
        return rotateLeft(node);
    }
    if (balance < -1 && getBalance(node->right) > 0) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }
    return node;
}


void AVLMovieTitleTree::inOrderSearch(AVLNode* node) {
    if (node == NULL) {
        return;
    }
    inOrderSearch(node->left);
    cout << node->value << " ";
    inOrderSearch(node->right);
}
void AVLMovieTitleTree::preOrderSearch(AVLNode* node) {
    if (node != NULL) {
        cout << node->value << " ";
        preOrderSearch(node->left);
        preOrderSearch(node->right);
    }
}
void AVLMovieTitleTree::postOrderSearch(AVLNode* node) {
    if (node == NULL) {
        return;
    }
    postOrderSearch(node->left);
    postOrderSearch(node->right);
    cout << node->value << " ";
}

/*
int main() {
    MovieList m;
    m.insert("Back to the future", 2, Action, "john doe", "marty mcfly", 10);
    m.insert("Zizi", 2, Fantasy, "john doe", "marty mcfly", 10);
    m.insert("Star wars", 2, Fantasy, "john doe", "marty mcfly", 10);
    AVLMovieTitleTree tree = AVLMovieTitleTree(m);

    cout << "Inorder traversal of the constructed AVL tree is \n";
    tree.inOrderSearch(tree.root);
    cout << endl;
    cout << "Preorder traversal of the constructed AVL tree is \n";
    tree.preOrderSearch(tree.root);
    cout << endl;
    cout << "Postorder traversal of the constructed AVL tree is \n";
    tree.postOrderSearch(tree.root);
    cout << endl;

    tree.remove(tree.root, 's');

    cout << "\nInorder traversal of the AVL tree after deletion of 30 \n";
    tree.inOrderSearch(tree.root);
    cout << endl;
    cout << "Preorder traversal of the constructed AVL tree is \n";
    tree.preOrderSearch(tree.root);
    cout << endl;
    cout << "Postorder traversal of the constructed AVL tree is \n";
    tree.postOrderSearch(tree.root);
    cout << endl;
    cout << "\n\n";
    return 0;
}
*/