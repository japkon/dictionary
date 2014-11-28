/*
 *  dictionary.h
 *  
 *  by Jacob Apkon
 *  Header file for the Dictionary class. The Dictionary Class takes 2 words as
 * input, and finds the shortest path between the two words by changing one
 * letter at a time. Every time a letter is changed, the resulting word must
 * also be a valid word in the dictionary. The shortest path between the two
 * words is printed.   
 */

#ifndef _dictionary_h
#define _dictionary_h

#include <iostream>
#include <vector>

using namespace std;

#define INIT_SIZE 10

struct Word_Node {
	string word;
	int distance;
	Word_Node *prev;
	vector<Word_Node *> node_list;
};	

class Dictionary {
public:
        Dictionary(size_t word_length); //Constructor function
        void load_words(string word1, string word2);
	void shortest_path();
	~Dictionary();
private:
	size_t word_length;
	vector<Word_Node *> all_words;
	size_t index_word1, index_word2;
	void make_node(string word);
        void add_word_to_graph(Word_Node *word);
	bool similar_words(Word_Node *node1, Word_Node *node2);
        void process_neighbors(Word_Node *node);
	void print_shortest();
};

#endif
