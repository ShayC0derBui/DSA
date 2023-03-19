#include <bits/stdc++.h>
#include <cstring>
#include <fstream>
using namespace std;
class WordDictionary
{
	struct TrieNode
	{
		bool endsHere;
		TrieNode *child[26];
	};
	TrieNode *root;

public:
	TrieNode *newNode(char c)
	{
		TrieNode *node = new TrieNode;
		node->endsHere = false;
		memset(node->child, 0, sizeof(node->child));
		return node;
	}
	WordDictionary()
	{
		root = newNode('/');
	}

	void addWord(string word)
	{
		int n = word.size();
		int index;
		TrieNode *currNode = root;
		for (int i = 0; i < n; i++)
		{
			index = word[i] - 'a';
			if (currNode->child[index] == NULL)
			{
				currNode->child[index] = newNode(word[i]);
			}
			currNode = currNode->child[index];
		}
		currNode->endsHere = 1;
	}
	bool helper(int j, TrieNode *currNode, string &word)
	{
		int n = word.size();
		int index;
		for (int i = j; i < n; i++)
		{
			if (word[i] == '.')
			{

				for (int k = 0; k < 26; k++)
				{
					if (currNode->child[k] != NULL)
					{
						if (helper(i + 1, currNode->child[k], word))
							return true;
					}
				}
				return false;
			}
			else
			{
				index = word[i] - 'a';
				if (currNode->child[index] == NULL)
				{
					return false;
				}
				currNode = currNode->child[index];
			}
		}
		if (currNode->endsHere > 0)
			return true;
		if (j == n)
		{
			return currNode->endsHere > 0;
		}
		return false;
	}
	bool search(string word)
	{
		int n = word.size();
		int index;
		return helper(0, root, word);
	}
};
int main()
{
	WordDictionary obj;
	ifstream file("/Users/premkumarsinha/Downloads/words.txt");
	string word;

	// Read words from file into vector
	while (getline(file, word))
	{
		cout << word << endl;
		obj.addWord(word);
	}
	while (true)
	{
		string c;
		cout << "Enter word to search: ";
		cin >> c;
		cout << obj.search(c) << endl;
	}
	return 0;
}
