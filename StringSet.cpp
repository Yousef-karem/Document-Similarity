// File name:A3_SheetPb2_20220402.cpp
// Purpose: class to store some strings and do some operations like similarity
// Author(s):youssef karem wiliam
// ID(s):20220402
// Section:20
// Date:4/12/2023
#include "StringSet.h"
StringSet::StringSet(string filename) {
    if(filename.size()<3||filename.substr(filename.size()-3)!="txt")
        filename+=".txt";
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cout << "Unable to open the file." << endl;
        return;
    }
    string word;
    while (inputFile >> word) {
        string tmp="";
        for(char c:word)
        {
            if(isalpha(c))
                tmp.push_back(tolower(c));
        }
        if(!tmp.empty())
            words.insert(tmp);
    }
    inputFile.close();
}
void StringSet::AddString(string word) {
    words.insert(word);
}

void StringSet::DeleteString(string word) {
    if(words.find(word)!=words.end())
         words.erase(word);
}

void StringSet::clearString() {
    words.clear();
}

unsigned int StringSet::stringSize() {
    return words.size();
}

void StringSet::DisplaySet() {
    for(string s:words)
        cout<<s<<'\n';
}

StringSet StringSet::operator+(StringSet &other) {
    StringSet tmp(other);
    for(string s:words)
        tmp.AddString(s);
    return tmp;
}

StringSet StringSet::operator*(StringSet &other) {
    StringSet tmp;
    for(string s:words)
        if(other.findString(s))
            tmp.AddString(s);
    return tmp;
}

bool StringSet::findString(string word) {
    return (words.find(word)!=words.end());
}

StringSet::StringSet() {

}

double StringSet::sim(StringSet &other) {
    int cnt=0;
    if(!this->stringSize()&&!other.stringSize())
        return 1;
    if(!this->stringSize()||!other.stringSize())
        return 0;
    for(string s:words)
    {
        if(other.findString(s))
            cnt++;
    }
    return cnt/ (sqrt(this->stringSize())*sqrt(other.stringSize()));
}


//  test all functions.
int main()
{
    string filename;cin>>filename;
    StringSet s1(filename);
    s1.DisplaySet();
    StringSet s2;
    s1.AddString("hello");
    s2.AddString("hello");
    s2.AddString("h");
    s2.DeleteString("h");
    cout<<"-----------------------\n";
    cout<<"the union between s1 and s2:\n";
    (s1+s2).DisplaySet();
    cout<<"-----------------------\n";
    cout<<"the intersection between s1 and s2:\n";
    (s1*s2).DisplaySet();
    cout<<"-----------------------\n";
    cout<<"the similarity between s1 and s1:\n";
    cout<<s1.sim(s1)<<'\n';
    cout<<"-----------------------\n";
    cout<<"the similarity between s1 and s2:\n";
    cout<<s1.sim(s2)<<'\n';
}

