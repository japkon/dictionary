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

		Dictionary dictionary(word_length);
		dictionary.load_words(word1, word2);
		dictionary.shortest_path();
        }

	return 0;
}
