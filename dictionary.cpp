/*
 *  dictionary.cpp
 * 
 *  by Jacob Apkon
 *  Implements the Dictionary class. Uses Dijkstra's Algorithm for path finding 
 */

#include "dictionary.h"
#include <fstream>

Dictionary::Dictionary(size_t length)
{
	/* Only the word length needs to be set for the class */
	word_length = length;
}

/* Open the file of words. Only process a word if it's the right number of
 * letters */
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

/* Start the path finding at the correct graph vertex */
void Dictionary::shortest_path()
{
	Word_Node *start = all_words[index_word1];
	start->distance = 0;

	process_neighbors(start);

	print_shortest();
}

/* Destructor for the Dictionary class. Delete all nodes */
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
	new_node->distance = -1;
	new_node->prev = NULL;
	all_words.push_back(new_node);
	
	add_word_to_graph(new_node);
}

/* If two words only differe by one letter, add each word to the others
 * list of connected words */
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

/* Checks that words only differ by one letter */
bool Dictionary::similar_words(Word_Node *node1, Word_Node *node2)
{
	size_t str_length = (node1->word).length();
	int misses = 0;
	for (size_t i = 0; i < str_length && misses < 2; i++) {
		if ((node1->word)[i] != (node2->word)[i]) {
			misses++;
		} 
	}

	if (misses == 1) return true;
	else return false;
}

/* Dijkstra's Algorithm for finding the shortest path */
void Dictionary::process_neighbors(Word_Node *node)
{
	Word_Node *neighbor;
	size_t num_neighbors = (node->node_list).size();
	for (size_t i = 0; i < num_neighbors; i++) {
		neighbor = (node->node_list)[i];
		if (neighbor->distance == -1) {
			neighbor->distance = node->distance + 1;
			neighbor->prev = node;
			process_neighbors(neighbor);
		} else if (neighbor->distance > node->distance + 1) {
			neighbor->distance = node->distance + 1;
			neighbor->prev = node;
			process_neighbors(neighbor);
		}
	}
}

/* Iterate through the linked list to print the connecting words */
void Dictionary::print_shortest()
{
	Word_Node *final = all_words[index_word2];
	if (final->prev == NULL) {
		/* The final vertex was never reached when path finding */
		cout << "Can't get between words\n";
		return;
	} else {
		while (final != NULL) {
			cout << final->word;
			if (final->prev != NULL) {
				cout << " -> ";
			}
			final = final->prev;
		}
	}
	cout << endl;
}
