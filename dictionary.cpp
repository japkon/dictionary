//
//  dictionary.cpp
//  
//
//  Created by Jacob Apkon on 11/26/14.
//  Implements dictionary.h
//

#include "dictionary.h"
#include <fstream>

Dictionary::Dictionary(size_t length)
{
	word_length = length;
}

void Dictionary::load_words()
{
	string word;

	ifstream input("words.txt");
	
	while (!input.eof()) {
		getline(input, word);
		if (word.length() == word_length) {
			make_node(word);
		}
	}
}

void Dictionary::shortest_path(string word1, string word2)
{
	cerr << "Initial words " << word1 << ", " << word2 << endl;
	size_t length = all_words.size();
	for (size_t i = 0; i < length; i++) {
		cout << all_words[i]->word;
	}	
}

Dictionary::~Dictionary()
{
	size_t vector_length = all_words.size();
	for (size_t i = 0; vector_length; i++) {
		free(all_words[i]);
	}
}

void Dictionary::make_node(string word)
{
	size_t i = all_words.size();
	Word_Node *new_node = new Word_Node;
	new_node->word = word;
	all_words[(unsigned)i] = new_node;
	cerr << "56\n";
}
