#include<bits/stdc++.h>
using namespace std;
#ifndef DOCUMENT_SIMILARITY_STRINGSET_H
#define DOCUMENT_SIMILARITY_STRINGSET_H


class StringSet {
    private:
    set<string>words;
    //if find the word return true else return false
    bool findString(string word);
    public:
    StringSet();
    //constructor that takes a file name and loads the words in it (ignoring punctuation and turning text to lower case).
    StringSet(string filename);
    //function to add a string to the set.
    void AddString(string word);
    //function remove a string from the set.
    void DeleteString(string word);
    //clearSet the entire set.
    void clearString();
    //return the number of strings in the set.
    unsigned int stringSize();
    //output all strings in the set.
    void DisplaySet();
    //Overload the + operator to return the union of two StringSet objects.
    StringSet operator+(StringSet& other);
    // Overload the * operator so that it returns the intersection of two StringSet objects.
    StringSet operator*(StringSet& other);

    //calculate the similarity
    double sim(StringSet &other);
};




#endif //DOCUMENT_SIMILARITY_STRINGSET_H
