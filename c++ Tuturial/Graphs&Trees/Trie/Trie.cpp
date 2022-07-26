#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Trie Node structure
typedef struct Node
{
    struct Node *links[26];
    bool flag = false;

    bool containsKey(char ch)
    {
        return (links[ch - 'a'] != NULL); // which means it exists
    }

    void put(char ch, Node *node) // putting new character
    {
        links[ch - 'a'] = node;
    }
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }
    void setEnd()
    {
        flag = true;
    }

    bool isEnd() // checking if the word exists or not[search]
    {
        return flag;
    }

} Node;

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }
    void insert(string word)
    {
        Node *curr = root; // dummy variable node
        for (int i = 0; word.size(); i++)
        {
            if (!curr->containsKey(word[i])) // curr->link[word[i]-'a']!=NULL
            {                                // if character of a word does there then make it put next refernece node
                // curr->links[word[i] - 'a'] = new Node();
                curr->put(word[i], new Node());
            }
            // curr = curr->links[word[i]-'a'];
            curr = curr->get(word[i]);
        }
        // curr->flag = true;
        curr->setEnd(); // this will mark flag as true this means particular word end
    }
    bool search(string word)
    {
        Node *curr = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (curr->links[word[i] - 'a'] != NULL)
                return false;
            curr = curr->links[word[i] - 'a']; // move to next reference link of char
        }
        // lastly check the reference where we are standin is having a flag true or not.
        // if flag=true means word exists if false means its just a part of some other word.
        // return curr->flag;
        return curr->isEnd();
    }

    bool startsWith(string word)
    {
        Node *curr = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!curr->containsKey(word[i]))
                return false;
            curr = curr->get(word[i]); // get me the reference-link for the next char
        }
        // if we were able to find the reference node for each char in word thats we are successfully able to complete the loop.
        return true;
    }
};

/*
//leetcode question
typedef struct Node{
    struct Node* links[26];
    bool flag = false;
}Node;

class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* curr = root;
        for(int i=0;i<word.length();i++){
            if(curr->links[word[i]-'a']==NULL){
                curr->links[word[i]-'a'] = new Node();
            }
            curr = curr->links[word[i]-'a'];
        }
        curr->flag = true;
    }

    bool search(string word) {
        Node* curr = root;
        for(int i=0;i<word.size();i++){
            if(curr->links[word[i]-'a']==NULL) return false;
            curr = curr->links[word[i]-'a'];
        }
        return curr->flag;
    }

    bool startsWith(string prefix) {
        Node* curr = root;
        for(int i=0;i<prefix.length();i++){
            if(curr->links[prefix[i]-'a']==NULL) return false;
            curr = curr->links[prefix[i]-'a'];
        }
        return true;
    }
};
*/