//     $Date: 2018-03-11 05:18:25 +1100 (Sun, 11 Mar 2018) $
// $Revision: 1206 $
//   $Author: Peter $

#include "Ass-01.h"


/*
 * string with words seperated by space char
 * allocate memory for pointer size of number of words 		(char*) malloc(sizeof(char*) * num_words);
 * allocate memory for each word 							(char) malloc(sizeof(word) + char)
 *
 * array_of_words_p[word[0], word[1], word[2]]
 * char* word[0] = malloc(sizeof(char) * wordlen[0]);
 *
 * return max index of word[index]
 *
 * case - 1 word
 * case - no words - space
 * 				   - null
 * case - multiple spaces
 *
 *
 */

/*for (two times){
 * if second time(){malloc array of words}
 * 	token = strchr(inp, delim)
 * 	if token == prevtoken +1 //only moved by one must be another space
 * 	if token > prevtoken+1 {length of word = token - previous token
 * 							numwords++
 * 							if second time { arrayofwords[numwords] = malloc length of word }
 * 							}
 *
 * 	}
 */


int string_parser(char *inp, char **array_of_words_p[]){
    char curr_char;
    char prev_char = ' ';
    int num_words = 0;
    int len_word = 0;

    printf("\n");

    for(int i=0; i<strlen(inp); i++){
        curr_char = inp[i];

        if(curr_char == '\0') return 0;  //No words in string
        else if(curr_char == ' ' && prev_char == ' '){
            //Multiple spaces in a row
        }
        else if(curr_char != ' ' && prev_char == ' '){
            //Found new word
            num_words++;
        }
        else{
            //Currently in word, don't do anything
        }
        prev_char = curr_char;
    }

    *array_of_words_p = (char**) calloc(num_words, sizeof(char*));

    prev_char = ' ';
    num_words     = 0;
    for (int i = 0; i < strlen(inp);) {
        curr_char = inp[i];

        if (curr_char == '\0' && len_word == 0){
            return num_words;
        }
        else if (curr_char == ' ' && prev_char == ' ') {
            // Multiple spaces in a row
        }
        else if (curr_char != ' ' && prev_char == ' ') {
            // Found new word
            num_words++;
            len_word = 1;
            // printf("Found new word\n");
        }
        else if (curr_char == ' ' && prev_char != ' ') {
            // Found end of word
            (*array_of_words_p)[num_words - 1] = (char*) calloc(len_word + 1, sizeof(char));
            strncpy((*array_of_words_p)[num_words - 1], (inp + (i - len_word)), len_word);
            //printf("Found Whole Word: %s\n", (*array_of_words_p)[num_words - 1]);
            len_word = 0;
        }
        else {
            // Currently in word
            len_word++;
        }
        prev_char = curr_char;
        // No words in string
        i++;
    }
    if(len_word != 0){
         (*array_of_words_p)[num_words - 1] = (char*) calloc(len_word + 1, sizeof(char));
         strncpy((*array_of_words_p)[num_words - 1], (inp + (strlen(inp) - len_word)), len_word);
         //printf("Found Whole Word: %s\n", (*array_of_words_p)[num_words - 1]);
         len_word = 0;
    }
    return num_words;
}


/*typedef struct{
	unsigned char num_words;
	char** str;
} string_t;

char* spacefinder(char* str2, char delim){
	int k;
	if(strlen(str2) < 1){
		return 0;
	}
	for(int i=0; i<strlen(str2)-1; i++){
		if(str2[i] == delim && str2[i+1] != delim){
			//a
			if(i>1) return &str2[i];
			else return &str2[i+1];

			for(k=i; k<strlen(str2); k++){
				//' '
				if(str2[k] == delim){
					for(int j=k; j<strlen(str2); j++){
						if(str2[j] != delim){
							return &str2[j-1];
						}
					}
				}
			}
		}
		else{

		}
	}
	return NULL; //This probably needs to be somethig
}

string_t tokeniser(char* str, char delim, unsigned char index){
	char* token = spacefinder(str, delim);
	//if(token) *token = '\0';
	string_t mem = (token == NULL)
				 ? (string_t){index + 1, malloc((index + 1) * sizeof(char*))}
				 : tokeniser(token+1, delim, index+1);
	mem.str[index] = str;
	return mem;
}

int string_parser(char *inp, char **array_of_words_p[]){

	string_t result = tokeniser(inp, ' ', 0);
	*array_of_words_p = result.str;
	return result.num_words;
}*/