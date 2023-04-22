#pragma once
#include "Movie.h"
#include "EGenre.h"
#include <string>
#include <iostream>

class MovieList
{
private:
    Movie* head;
public:
    MovieList() {
        head = NULL;
    }
    void insert(string title, float length, Genre genre, string director, string mainActor, int rating) {
        Movie* new_node = new Movie(title, length, genre, director, mainActor, rating);
        if (head == NULL) {
            head = new_node;
        }  
        else {
            Movie* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = new_node;
        }
    }
    void remove(Movie data) {
        Movie* temp = head;
        Movie* prev = NULL;
        while (temp != NULL && temp->GetTitle() != data.GetTitle()) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL) {
            return;
        }
        if (prev == NULL) {
            head = temp->next;
        }
        else {
            prev->next = temp->next;
        }
        delete temp;
    }

    void display() {
        Movie* temp = head;
        while (temp != NULL) {
            cout << temp->toString() << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    //Insert at Beginning: This function is used to insert a new node
    //at the beginning of the list.
    void insertAtBeginning(Movie data) {
        Movie* new_node = new Movie(data);
        if (head == NULL) {
            head = new_node;
        }
        else {
            new_node->next = head;
            head = new_node;
        }
    }
    //Insert at Position: This function is used to insert a new node 
    //at a specific position in the list.
    void insertAtPosition(Movie data, int position) {
        Movie* new_node = new Movie(data);
        if (head == NULL) {
            head = new_node;
        }
        else {
            Movie* temp = head;
            Movie* prev = NULL;
            int count = 0;
            while (temp != NULL && count < position) {
                prev = temp;
                temp = temp->next;
                count++;
            }
            if (prev == NULL) {
                new_node->next = head;
                head = new_node;
            }
            else {
                prev->next = new_node;
                new_node->next = temp;
            }
        }
    }
    //Get Node at Position: This function is used to get the node at
    //a specific position in the list.
    Movie* getNodeAtPosition(int position) {
        Movie* temp = head;
        int count = 0;
        while (temp != NULL && count < position) {
            temp = temp->next;
            count++;
        }
        return temp;
    }
    //Get Length: This function is used to get the number of nodes in the list.
    int getLength() {
        Movie* temp = head;
        int count = 0;
        while (temp != NULL) {
            temp = temp->next;
            count++;
        }
        return count;
    }
    //Clear List: This function is used to delete all the nodes in the list.
    void clear() {
        Movie* temp = head;
        while (temp != NULL) {
            Movie* next = temp->next;
            delete temp;
            temp = next;
        }
        head = NULL;
    }

};

