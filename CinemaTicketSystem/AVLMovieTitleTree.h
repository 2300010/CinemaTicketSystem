#pragma once
#include "Movie.h"
#include <string>
#include "MovieList.cpp"

using namespace std;

class AVLNode {
public:
	char value;
    Movie* movie;
	int height;
	AVLNode* left;
	AVLNode* right;
    //Value = first character of movie title
	AVLNode(Movie* movie);
};

class AVLMovieTitleTree
{
public:
	AVLMovieTitleTree();
	AVLMovieTitleTree(MovieList list);
    AVLNode* insert(AVLNode* node, Movie* value);
    AVLNode* remove(AVLNode* node, char value);
    AVLNode* search(AVLNode* node, char value);
    void inOrderSearch(AVLNode* node);
    void preOrderSearch(AVLNode* node);
    void postOrderSearch(AVLNode* node);
    int height(AVLNode* node);
    int balanceFactor(AVLNode* node);
    AVLNode* rotateRight(AVLNode* node);
    AVLNode* rotateLeft(AVLNode* node);
    AVLNode* getMinValueNode(AVLNode* node);
    int getBalance(AVLNode* node);

    AVLNode* root;


};

