//Fionn O'Reilly

#ifndef WORD_GAME_H_INCLUDED
#define WORD_GAME_H_INCLUDED

void display_game_state(char* pCurrent_letters, const int NUMBER_OF_LETTERS,
                       const int cursor_position, const int number_of_letter_changes);

void move_cursor_right(int* position_of_cursor, const int max);

void move_cursor_left(int* position_of_cursor);

void print_cursor_pos(int* cursor_pos,char space,char dash);

void change_letter(char* pLetters, int position, char new_letter, int max);

#endif WORD_GAME_H_INCLUDED
