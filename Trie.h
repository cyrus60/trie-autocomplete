#pragma once
// FILE: Trie.h
// CLASS INCLUDED: Alphabet trie class

#include <iostream>;
#include <vector>;

using namespace std;

class Trie {

private:
	class Node {
	public:
		Node* children[26] = { nullptr };
		bool isLeaf = false;
		Node() {}
	};

	// fields for class Trie
	Node* root;
	int size;
	int wordCount;


public:
	/// @brief main constructor
	Trie();

	/// @brief copy constructor
	Trie(Trie& t);

	/// @brief destructor
	~Trie();

	/// @brief recursively deletes nodes in trie
	/// @param current pointer to current node
	void nodeDestruct(Node* current);

	/// @brief recursive copy function to help copy nodes from one trie to another
	/// @param from node to copy from
	/// @param to node to copy to
	void copy(Node* from, Node* to);

	/// @brief sets one trie equal to another, copies all nodes
	/// @param t reference to trie to be copied
	/// @return reference to trie 
	Trie& operator=(const Trie& t);

	/// @brief insert function. Calls recursive insertHelper
	/// @param word to be inserted 
	/// @return bool value whether or not the word was inserted
	bool insert(string word);

	/// @brief total count of all words in trie
	/// @return total number of words in trie
	int count();

	/// @brief total number of Nodes in trie
	/// @return number of Nodes in trie
	int getSize();

	/// @brief finds given word in trie
	/// @param word the word to search for
	/// @return whether or not word was found in trie
	bool find(string word);

	/// @brief total number of words with given prefix
	/// @param word prefix to be searched
	/// @return total number of words with prefix
	int completeCount(string word);

	/// @brief adds all words with given prefix to a vector
	/// @param word prefix to be searched for
	/// @return vector containing all words with prefix 
	vector<string> complete(string word);

	/// @brief recursive countHelper function that navigates through trie to find words with prefix
	/// @param prefix to be searched for
	/// @param suffix of word
	/// @param reference to vector to add words to
	/// @param pointer to current Node
	void countHelper(string prefix, string suffix, vector<string>& vector, Node* current);
};