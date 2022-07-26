#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef struct Node
{
    Node *links[26];
    int ew = 0, cp = 0; // end-with and count prefix
    bool containsKey(char ch)
    {
        return (links[ch - 'a'] != NULL);
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
        Node *curr = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!curr->containsKey(word[i]))
            {
                curr->links[word[i] - 'a'] = new Node();
            }
            curr->cp += 1;
            curr = curr->links[word[i] - 'a'];
        }
        curr->cp += 1;
        curr->ew += 1;
    }
    int countWordsStartsWith(string word)
    {
        Node *curr = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!curr->containsKey(word[i]))
            {
                return 0;
            }
            curr = curr->links[word[i] - 'a'];
        }
        return curr->cp;
    }
    int countWordsEqualsTo(string word)
    {
        Node *curr = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!curr->containsKey(word[i]))
            {
                return 0;
            }
            curr = curr->links[word[i] - 'a'];
        }
        return curr->ew;
    }
    void Erase(string word)
    {
        Node *curr = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (curr->containsKey(word[i]))
            {
                curr = curr->links[word[i] - 'a'];
            }
            else
            {
                return;
            }
        }
        if (curr->ew > 0)
        {
            curr->ew -= 1;
        }
    }
};
int main()
{

    return 0;
}