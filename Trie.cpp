// Cyrus Straley
// Project 5

#include "Trie.h";
#include <iostream>;

// Trie: main trie constructor
Trie::Trie() {
	// sets root equal to a new leaf node, size to 1, wordcount to 0
	root = new Node();
	size = 1;
	wordCount = 0;
}


// insert: inserts given word into trie
// Returns: bool value whether or not word was inserted
// Paramaters: 
//		word (string) - word to be inserted
bool Trie::insert(string word) {

	// pointer keeping track of current node 
	Node* current = root;

	// index variable keeping track of the ascii value of char in word at index i
	int index;

	// looping through each index of given word
	for (int i = 0; i < word.length(); i++) { 

		index = word[i] - 'a';

		// if there is not a node at the index[ascii value of char at index i of word] then create a new Node at this pointer
		if (!current->children[index]) {
			current->children[index] = new Node();

			// increments size in nodes by 1
			size += 1;
		}

		if (i == word.length() - 1) {
			// if there is a current pointer to the last index in the word and it is a leaf node, return false
			if (current->isLeaf) {
				return false;
			}

			// if current is not a leaf, set currents isLeaf to true and increment wordCount by 1, returning true
			current->isLeaf = true;
			wordCount += 1;
			return true;
		}

		// set current pointer equal to currents children[index] pointer
		current = current->children[index];
	}
}