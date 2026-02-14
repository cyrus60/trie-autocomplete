#include "Trie.h";
#include <iostream>;
#include <vector>;
#include <fstream>;

int main() {
	ifstream wordFile("wordlist.txt");
	Trie t;

	string word;

	// inserting every word from wordlist into trie
	while (wordFile) {
		wordFile >> word;
		t.insert(word);
	}

	// main program loop 
	while (true) {
		string prefix;

		// prompting user for input and storing input in prefix
		cout << "Please enter a word prefix (or press enter to exit): ";
		cin >> prefix;

		// if prefix is equal to ascii value of enter key, break the loop
		if (prefix == "/n") {
			break;
		}

		string showCompletions;
		cout << "There are " << t.completeCount(prefix) << " completions for the prefix '" << prefix << "'.";
		cout << " Show completions? ";
		cin >> showCompletions;

		// if user chooses yes, vector of all words with given prefix are printed
		if (showCompletions == "Yes" || showCompletions == "yes") {
			cout << "Completions" << endl;
			cout << "---------" << endl;

			vector<string> vect = t.complete(prefix);

			for (string s : vect) {
				cout << s << endl;
			}
		}
		cout << endl;
	}
}