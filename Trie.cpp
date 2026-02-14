// Cyrus Straley
// Project 5

#include "Trie.h";
#include <iostream>;
#include <string>

// Trie: main trie constructor
Trie::Trie() {
	// sets root equal to a new leaf node, size to 1, wordcount to 0
	root = new Node();
	size = 1;
	wordCount = 0;
}

// Trie: copy constructor
// Parameters:
//		t (Trie&) - reference to trie being copied
Trie::Trie(Trie& t) {
	root = new Node();
	size = 1;
	wordCount = 0;

	// call recursive function to copy from trie passed in as parameter to current trie
	copy(t.root, root);
}

// operator=:
// Returns:
// Parameters
Trie& Trie::operator=(const Trie& t) {
	// deleting current trie
	nodeDestruct(root);

	// establishing new root node
	root = new Node();
	size = 1;

	// copy nodes from trie being copied into this trie
	copy(t.root, root);

	return *this;
}

// copy: recursive copy helper copying nodes from array from to array to
// Parameters:
//		from (Node*) - Node to copy from
//		to (Node*) - Node to copy too
void Trie::copy(Node* from, Node* to) {

	// loop through each position in children array
	for (int i = 0; i < 26; i++) {

		Node* child = from->children[i];
		
		if (child) {
			// if node we are copying from is a leaf, increment wordcount and create a new node at respective position
			if (child->isLeaf) {
				to->children[i] = new Node();
				size++;
				wordCount++;
			}
			// if from is not a leaf node, simply create new node and increment size only
			else {
				to->children[i] = new Node();
				size++;
			}
			// recursive call once nodes have been copied
			copy(from->children[i], to->children[i]);
		}
	}
}

// nodeDestruct: deletes all nodes in trie recursively 
void Trie::nodeDestruct(Node* current) {

	for (int i = 0; i < 26; i++) {

		// pointer to child at index i of currents children array
		Node* child = current->children[i];

		if (child) {

			// make recursive call on child node, and delete child node once returned from recurse
			nodeDestruct(child);
			delete child;
			--size;
		}
	}

	// if root is the only node delete it and set wordcount to 0
	if (size == 1) {
		delete root;
		wordCount = 0;
		--size;
	}
}

// ~: Trie destructor
Trie::~Trie() {
	nodeDestruct(root);
}

// count: total number of words in trie
// Returns: number of words in trie (int)
int Trie::count() {
	return wordCount;
}

// getSize: returns size of trie (number of nodes)
// Returns: number of nodes (int)
int Trie::getSize() {
	return size;
}


// insert: inserts given word into trie
// Returns: bool value whether or not word was inserted
// Paramaters: 
//		word (string) - word to be inserted
bool Trie::insert(string word) {

	// pointer keeping track of current node 
	Node* current = root;

	// index variable keeps track of alphabet index of current char in word
	int index;

	// looping through each index of given word
	for (int i = 0; i < word.length(); i++) { 

		// setting index equal to the alphabet index of the current char at idex i in word
		index = word[i] - 'a';

		// if there is not a node at index then create a new Node at this pointer
		if (!current->children[index]) {
			current->children[index] = new Node();

			// increments size in nodes by 1
			size += 1;
		}

		if (i == word.length() - 1) {
			// if there is a current pointer to the last index in the word and it is a leaf node, return false
			if (current->children[index]->isLeaf) {
				return false;
			}

			// if current is not a leaf, set currents isLeaf to true and increment wordCount by 1, returning true
			current->children[index]->isLeaf = true;
			wordCount += 1;
			return true;
		}

		// set current pointer equal to currents children[index] pointer
		current = current->children[index];
	}
}

// find: finds given word in trie
// Returns: whether or not word was found in trie (bool)
// Paramaters: 
//		word (string) - word to find
bool Trie::find(string word) {

	// setting pointer equal to current node
	Node* current = root;

	// index variable keeps track of alphabet index of char in word
	int index;

	// looping through indexes of given word 
	for (int i = 0; i < word.length(); i++) {

		// if current is null, return false
		if (!current) {
			return false;
		}

		// setting index equal to the alphabet index of the current char at idex i in word
		index = word[i] - 'a';

		// if at the last index of word, return true if it is a leaf node, false otherwise
		if (i == word.length() - 1) {
			if (current->isLeaf) {
				return true;
			}
			return false;
		}

		// set current pointer equal to currents children[index] pointer
		current = current->children[index];
	}
}

// completeCount: total number of words with given prefix
// Returns: number of words with given prefix (int)
// Paramaters: 
//		word (string) - prefix to be searched
int Trie::completeCount(string word) {
	return complete(word).size();
}

// complete: adds every word with given prefix to a vector
// Returns: vector containing all words with prefix (vector<string>)
// Paramaters: 
//		 word (string) prefix to be searched
vector<string> Trie::complete(string word) {

	// pointer to current node 
	Node* current = root;

	vector<string> vect = {};

	for (int i = 0; i < word.length(); i++) {

		// setting index equal to the alphabet index of the current char at idex i in word
		int index = word[i] - 'a';

		if (!current->children[index]) {
			return vect;
		}

		// if i is equal to the last index in the given prefix, call recursive countHelper on current Node
		if (i == word.length() - 1) {
			countHelper(word, "", vect, current->children[index]);
			return vect;
		}

		current = current->children[index];
	}
}

// countHelper: recursive helper function that loops through each child array of each node
// Paramaters: 
//		prefix (string) - prefix to be counted 
//		suffix (string) - suffix of word at Node
//		vector (vector<string>) - reference to vector of completed words
//		current (Node*) - pointer to current Node
void Trie::countHelper(string prefix, string suffix, vector<string> &vector, Node* current) {

	// looping through every child in current Node
	for (int i = 0; i < 26; i++) {
		
		Node* child = current->children[i];

		if (child) {
			// if child Node at index i is a leaf node, add the char at alphabet index i to the suffix, and the prefix+suffix to vector
			if (child->isLeaf) {
				suffix.push_back(char(i + 'a'));
				vector.push_back(prefix + suffix);
			}
			// if child node is not a leaf node, add the char at alphabet index i to the suffix
			else {
				suffix.push_back(char(i + 'a'));
			}

			// make recursive call with child Node and popping most recent char from suffix once recursive call returns
			countHelper(prefix, suffix, vector, child);
			suffix.pop_back();
		}
	}
}