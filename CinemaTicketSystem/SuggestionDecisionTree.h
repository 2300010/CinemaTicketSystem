#pragma once
#include "Movie.h"
#include "EGenre.h"
#include <string>
#include <vector>


class SuggestionDecisionTree
{
private:
    struct Node
    {
        string question;
        Node* yesChild;
        Node* noChild;
        vector<Movie> movieList;

        Node(string q, Node* yes, Node* no)
        {
            question = q;
            yesChild = yes;
            noChild = no;
        }

        Node(vector<Movie> list)
        {
            movieList = list;
            yesChild = NULL;
            noChild = NULL;
        }
    };
    Node* root;

    void destroySubtree(Node* node);

public:
    SuggestionDecisionTree();
    ~SuggestionDecisionTree();
    void addMovie(Movie m);
    void buildTree();
    void traverse(Node* node);
    vector<Movie> suggestMovies(Genre genre, float length, string director, string actor, int rating);
};