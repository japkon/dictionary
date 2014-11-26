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

void Dictionary::load_words(string word1, string word2)
{
	string word;

	ifstream input("words.txt");
	
	while (!input.eof()) {
		getline(input, word);
		if (word == word1) {
			index_word1 = all_words.size();	
		}
		if (word == word2) {
			index_word2 = all_words.size();
		}
		if (word.length() == word_length) {
			make_node(word);
		}
	}
}

void Dictionary::shortest_path()
{
	Word_Node *node;
	Word_Node *node2;
	size_t length;

	node = all_words[index_word1];
	cout << "WORD 1: " << node->word << endl;
	length = (node->node_list).size();
	for (size_t i = 0; i < length; i++) {
		node2 = (node->node_list)[i];
		cout << node2->word << endl;
	}

	cout << endl;

	node = all_words[index_word2];
	cout << "WORD 2: " << node->word << endl;
	length = (node->node_list).size();
	for (size_t i = 0; i < length; i++) {
		node2 = (node->node_list)[i];
		cout << node2->word << endl;
	}
}

Dictionary::~Dictionary()
{
	Word_Node *node;
	size_t vector_length = all_words.size();
	for (size_t i = 0; i < vector_length; i++) {
		node = all_words[i];
		delete node;
	}
}

void Dictionary::make_node(string word)
{
	Word_Node *new_node = new Word_Node;
	new_node->word = word;
	all_words.push_back(new_node);
	
	add_word_to_graph(new_node);
}

void Dictionary::add_word_to_graph(Word_Node *word)
{
	size_t vector_length = all_words.size();
	Word_Node *node;
	for (size_t i = 0; i < vector_length; i++) {
		node = all_words[i];
		if (similar_words(word, node)) {
			(word->node_list).push_back(node);
			(node->node_list).push_back(word);
		}
	}
}

bool Dictionary::similar_words(Word_Node *node1, Word_Node *node2)
{
	size_t str_length = (node1->word).length();
	int misses = 0;
	for (size_t i = 0; i < str_length && misses < 2; i++) {
		if ((node1->word)[i] != (node2->word)[i]) {
			misses++;
		} 
	}

	if (misses < 2) return true;
	else return false;
}
