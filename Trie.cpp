// Cyrus Straley
// Project 5

#include "Trie.h";
#include <iostream>;

// Trie: main trie constructor
Trie::Trie() {
	// sets root equal to a new leaf node and size to 1
	root = new Node();
	root->isLeaf = true;
	size = 1;
	wordCount = 0;
}

// insert: recursive insertHelper function called from insert
// Returns: bool value whether or not word was inserted
// Paramaters: 
//		word (string) - word to be inserted
//		current (Node*) - pointer to current Node
bool Trie::insertHelper(string word, Node* current) {

}


// insert: makes recursive call to insert function
// Returns: bool value whether or not word was inserted
// Paramaters: 
//		word (string) - word to be inserted
bool Trie::insert(string word) {
	return insertHelper(word, root);
}