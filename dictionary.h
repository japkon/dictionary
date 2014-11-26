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

struct Word_Node {
	string word;
	vector<Word_Node *> node_list;
};	

class Dictionary {
public:
        Dictionary(size_t word_length); //Constructor function
        void load_words();
	void shortest_path(string word1, string word2);
	~Dictionary();
private:
	size_t word_length;
	vector<Word_Node *> all_words;
	void make_node(string word);
        void dijkstra();
        void print_shortest();
};

#endif
