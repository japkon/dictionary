//
//  dictionary.h
//  
//
//  Created by Jacob Apkon on 11/26/14.
//
//

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
