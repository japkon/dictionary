/*
 *  main.cpp
 * 
 *  by Jacob Apkon
 *  Main file for determining the path between two words by only changing one
 *  letter at a time. Every time a letter is changed, the resulting word must 
 *  also be a valid word. 
 */

#include "dictionary.h"

#define NUM_WORDS 2

int main(int argc, char *argv[])
{
        string word1, word2;
	size_t word_length;

	if (argc > NUM_WORDS) {
                word1 = argv[1];
                word2 = argv[2];
		
		if ((word_length = word1.length()) != word2.length()) {
			cerr << "Word lengths don't match\n";
			return 1;
		}
		if (word1 == word2) {
			cerr << "You input the same word twice\n";
			return 1;
		}
		Dictionary dictionary(word_length);
		dictionary.load_words(word2, word1);
		dictionary.shortest_path();
        }

	return 0;
}
