#pragma once
// FILE: Trie.h
// CLASS INCLUDED: Alphabet trie class

#include <iostream>;

using namespace std;

class Trie {

private:
	class Node {
	public:
		Node* children[26] = { nullptr };
		bool isLeaf;
		Node() {}
	};

	// fields for class Trie
	Node* root;
	int size;
	int wordCount;


public:
	/// @brief main constructor
	Trie();

	/// @brief insert function. Calls recursive insertHelper
	/// @param
	/// @return bool value whether or not the word was inserted
	bool insert(string word);

	/// @brief recursive insertHelper function. recurses through trie inserting word given
	/// @param string word word to be inserted
	/// @param Node* current pointer to current Node
	/// @return bool value whether or not the word was inserted
	bool insertHelper(string word, Node* current);
};