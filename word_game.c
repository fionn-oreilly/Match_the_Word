/*  
 *	Author: Fionn O Reilly
 *  Description: Displays a given word and a target word.
 *				 Player must move the cursor left and right and change
 *				 the letters in the given word to match the target word.
 *				 The player has a certain number of attempts to match the word.
 */

#include <stdio.h >
#include <stdbool.h>


// Display current game state to user
void display_game_state(char* pCurrent_letters,char* pTarget_letters,const int NUMBER_OF_LETTERS,
                        int* cursor_position, int number_of_letter_changes, int matches) {

        const char DASH = '-';
        const char SPACE = ' ' ;

        printf("\n--- Word Game ---\n");
        printf("Target word: ");

        int i = 0;
        while (i<NUMBER_OF_LETTERS) {
            printf("%c", *pTarget_letters);
            pTarget_letters = pTarget_letters + 1;
            i++;
        }
        printf("\nCurrent word: \n");
        i = 0;
        while (i<NUMBER_OF_LETTERS) {
            printf ("%c", *pCurrent_letters);
            pCurrent_letters = pCurrent_letters + 1;
            i++;
        }

        int j = 0;
        printf("\n");
        while (j < *cursor_position) {
            printf ("%c", SPACE);
            j++;
        }
        printf ("%c", DASH);

        printf("\nLetter matches: %d", matches);
        printf("\nCursor position: %d", *cursor_position);
        printf("\nChanges: %d", number_of_letter_changes);
}


void move_cursor_right(int* position_of_cursor, const int max){
    if (*position_of_cursor < max-1 && *position_of_cursor >= 0) {
        *position_of_cursor += 1;
    } else {
        printf("\nPosition out of bounds.\n");
    }
}

void move_cursor_left(int* position_of_cursor) {
    if (*position_of_cursor > 0 && *position_of_cursor <=sizeof(position_of_cursor)) {
         *position_of_cursor -= 1;
    } else {
        printf("\nPosition out of bounds.\n");
    }
}


// change letter at current position to letter the user entered
void change_letter(char* pLetters, int* position, char* new_letter, int max) {
    if (*position >= 0 && *position <= max-1) {
        int i = 0;
        while (i < max) {
            if (i == *position) {
                *pLetters = *new_letter;
            }
            pLetters++;
            i++;
        }
    } else {
        printf("Position out of bounds.");
    }
}


// get input from user
char get_user_char() {
    char res = getchar();
    bool finish = false;
    char dummy_char = ' ';
    while (finish == false) {
        dummy_char = getchar();
        if (dummy_char == '\n')
            finish = true;
    }
    return res;
}


// check if the word matches
bool compare_letters(char* pCurrentLetters, char* pTargetLetters, int numLetters) {
    int i = 0;
    bool match = false;
    while (i < numLetters) {
        if (*pCurrentLetters == *pTargetLetters) {
            match = true;
        } else {
            match = false;
        }
        i++;
        pCurrentLetters++;
        pTargetLetters++;
    }
    return match;
}

// check how many letters match the target word
int num_matches(char* pCurrentLetters, char* pTargetLetters, int numLetters) {
    int i = 0;
    int matches = 0;
    while (i < numLetters) {
        if (*pCurrentLetters == *pTargetLetters) {
            matches++;
        }
        i++;
        pCurrentLetters++;
        pTargetLetters++;
    }
    return matches;
}


void add_word(char* currentLetters,char* pwords,int num_letter_changes,int max) {
    int i = 0;
    pwords = pwords + (num_letter_changes*(max));
    while (i<max) {
        *pwords = *currentLetters;

        i++;
        pwords++;
        currentLetters++;
    }
}



void start_game(char* current_letters, char* target_letters, int NUMBER_OF_LETTERS) {
    int position_of_cursor = 0;
    bool game_finished = false;
    int number_of_letter_changes = 0;
    int matches = 0;
    char words[((NUMBER_OF_LETTERS*2)*(NUMBER_OF_LETTERS))];
    char* pwords = &words;

    while (game_finished == false) {
        matches = num_matches(current_letters,target_letters,NUMBER_OF_LETTERS);
        display_game_state(current_letters,target_letters, NUMBER_OF_LETTERS, &position_of_cursor, number_of_letter_changes, matches);
        printf("\nPlease enter <, > or a letter\n");
		
        char input = get_user_char();
		
        if (input == '>') {
            move_cursor_right(&position_of_cursor,NUMBER_OF_LETTERS);
        } else if (input == '<') {
            move_cursor_left(&position_of_cursor);
        } else if ((input >='a' && input<='z') || (input>='A' && input<='Z')) {
            change_letter(current_letters, &position_of_cursor, &input, NUMBER_OF_LETTERS);
            add_word(current_letters,pwords,number_of_letter_changes,NUMBER_OF_LETTERS);
            number_of_letter_changes++;
        } else {
            printf("Try again");
        }

        if (number_of_letter_changes == ((sizeof(current_letters)/sizeof(current_letters[0]))*2)) {
            printf("\n>>>>> You have reached the maximum number of allowed changes. <<<<<\n");
            game_finished = true;
        } else {
            game_finished = compare_letters(current_letters, target_letters, NUMBER_OF_LETTERS);
            if (game_finished == true) {
                printf("\n>>>> You matched the target word! <<<<<\n");
                int j = 0;
                printf("\nWords used:\n");
                while (j<(number_of_letter_changes*NUMBER_OF_LETTERS)) {
                    if (j % NUMBER_OF_LETTERS == 0 && j > 0) {
                        printf("\n");
                    }
                    printf("%c",*pwords);
                    j++;
                    pwords++;
                }
            }
        }
    }
    display_game_state(current_letters,target_letters, NUMBER_OF_LETTERS, &position_of_cursor, number_of_letter_changes,matches);
}








