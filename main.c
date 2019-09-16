/*  Author: Fionn O Reilly
 *  Description: main file for word_game.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "word_game.h"

int main()
{
    char  current_letters[] = {'b', 'e', 'l','l'};
    char target_letters[] = {'c', 'o', 'a','t'};
    const int NUMBER_OF_LETTERS = sizeof(current_letters);
    start_game(&current_letters,&target_letters,NUMBER_OF_LETTERS);

    return 0;
}
