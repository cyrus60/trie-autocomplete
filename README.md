# Trie Autocomplete Engine

A C++ implementation of an autocomplete system using a trie (prefix tree) data structure. Supports efficient prefix-based word search and completion suggestions.

## Overview

This project implements a complete trie data structure for autocomplete functionality. The system can:
- Insert words into the trie with O(m) time complexity (where m is word length)
- Search for exact word matches
- Find all words sharing a common prefix
- Return completion suggestions based on user input

## Features

- **Efficient Prefix Search:** O(m) lookup time for prefix matching
- **Memory-Optimized Structure:** Stores shared prefixes once using tree-based architecture
- **Complete Word Suggestions:** Returns all possible completions for a given prefix

## How It Works

The trie stores words character-by-character in a tree structure where:
- Each node represents a single character
- Paths from root to leaf nodes form complete words
- Shared prefixes are stored only once, optimizing memory usage
- Leaf nodes are marked to indicate complete words

### Core Operations

**Insert:** `O(m)` - Adds word to trie by creating path of nodes for each character

**Find:** `O(m)` - Searches for exact word match by traversing character path

**Complete:** `O(n)` - Returns all words sharing given prefix (n = number of completions)

**CompleteCount:** `O(n)` - Returns count of words with given prefix

## Technical Implementation

- **Language:** C++
- **Key Concepts:** Trie data structure, recursive algorithms, dynamic memory management, prefix trees
- **Memory Management:** Custom destructor with recursive node deletion to prevent memory leaks
