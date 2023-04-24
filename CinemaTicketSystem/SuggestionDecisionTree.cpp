#include "SuggestionDecisionTree.h"

SuggestionDecisionTree::SuggestionDecisionTree() 
{
    root = NULL;
}

SuggestionDecisionTree::~SuggestionDecisionTree()
{
    // Start at the root node
    Node* currentNode = root;

    // Recursively delete all nodes in the tree
    destroySubtree(currentNode);
}

void SuggestionDecisionTree::destroySubtree(Node* node)
{
    if (node == NULL) {
        return;
    }

    // Recursively delete the left and right subtrees
    destroySubtree(node->yesChild);
    destroySubtree(node->noChild);

    // Delete the current node
    delete node;
}

void SuggestionDecisionTree::addMovie(string title, vector<string> keywords) {
    // Start at the root of the tree
    SuggestionDecisionTree::SuggestionTreeNode* current = root; //Need to add SuggestionTreeNode in .h

    // Traverse the tree until a leaf node is found
    while (!current->isLeafNode()) {
        bool matchFound = false;
        for (SuggestionTreeNode* child : current->getChildren()) {
            if (child->matches(keywords)) {
                current = child;
                matchFound = true;
                break;
            }
        }
        if (!matchFound) {
            break;
        }
    }

    // Add the new movie to the leaf node
    current->addMovie(title, keywords);
}

 void SuggestionDecisionTree::buildTree()
 {
     //TODO Implement buildTree
 }

void SuggestionDecisionTree::traverse(Node* node) 
{
    // TODO: Implement traverse
}

vector<Movie> SuggestionDecisionTree::suggestMovies(Genre genre, float length, string director, string actor, int rating) 
{
    vector<Movie> suggestions;

    // Start at the root node
    Node* currentNode = root;

    // Traverse the tree until we reach a leaf node (i.e. a node with a movie list)
    while (currentNode->yesChild != NULL || currentNode->noChild != NULL) 
    {
        // If the client's preference matches the question at the current node, move to the yes child
        if (currentNode->question == "Is the genre " + to_string(genre) + "?") 
        {
            currentNode = currentNode->yesChild;
        }
        else if (currentNode->question == "Is the length less than " + to_string(length) + "?") 
        {
            currentNode = currentNode->yesChild;
        }
        else if (currentNode->question == "Is the director " + director + "?") 
        {
            currentNode = currentNode->yesChild;
        }
        else if (currentNode->question == "Is the main actor " + actor + "?") 
        {
            currentNode = currentNode->yesChild;
        }
        else if (currentNode->question == "Is the rating greater than " + to_string(rating) + "?") 
        {
            currentNode = currentNode->yesChild;
        }
        // If the client's preference doesn't match the question at the current node, move to the no child
        else 
        {
            currentNode = currentNode->noChild;
        }
    }

    // We have reached a leaf node, so the movie list at this node is our suggestion
    suggestions = currentNode->movieList;

    return suggestions;
}