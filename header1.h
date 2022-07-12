//
// Created by besto on 18/05/2021.
//

#ifndef COMP10050_PROJECT2_HEADER1_H
#define COMP10050_PROJECT2_HEADER1_H

#include <stdio.h>

#define BLACK 1
#define WHITE 2

typedef struct player {
    char name[20];
    int colour;
    int score;
}Player;

typedef struct board {
    int tiles[8][8]; //stores the discs in the game
    int player_turn; //keeps track which player is currently playing
    Player player1; //player1 is black
    Player player2; //player2 is white
}Board;

/*
 * initialises the board with two white and two black discs at center and scores set to 2:2
 */
void initialise_board(Board *boardP)
{
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            boardP->tiles[i][j] = 0;

    boardP->tiles[3][3] = 2;
    boardP->tiles[3][4] = 1;
    boardP->tiles[4][3] = 1;
    boardP->tiles[4][4] = 2;

    boardP->player_turn = BLACK;
}

/*
 * asks both players names and stored into struct player
 */
void get_player_names(Board *boardP)
{
    printf("Enter name of Player 1 (Black): ");
    scanf("%s", boardP->player1.name);
    boardP->player1.colour = BLACK;
    boardP->player1.score = 2;

    printf("\n\n");

    printf("Enter name of Player 2 (White): ");
    scanf("%s", boardP->player2.name);
    boardP->player2.colour = WHITE;
    boardP->player2.score = 2;
}

/*
 * prints the board
 */
void print_board(Board board)
{
    printf("Score: %s (Black) %d:%d (White) %s\n", board.player1.name, board.player1.score,
           board.player2.score, board.player2.name);
    int k = 0;
    for (int i = 0; i < 17; i++)
    {
        if (i % 2 == 0)
        {
            printf("   ---");
            for (int j = 0; j < 7; j++)
            {
                printf(" ---");
            }
        }
        else{
            printf("%d ", k+1);
            for (int j = 0; j < 8; j++)
            {
                printf("|");

                if (board.tiles[k][j] == 0)
                    printf("   ");

                else if (board.tiles[k][j] == 1)
                    printf(" B ");

                else
                    printf(" W ");
            }
            printf("|");
            k++;
        }
        printf("\n");
    }
    printf("  ");
    for (int i = 0; i < 8; i++){
        char ch;
        ch = 'a' + i;
        printf("  %c ", ch);
    }
    printf("\n\n");
}

/*
 * prints the winner of the game
 */
void print_winner(Board board)
{
    printf("    ***  FINAL SCORE  ***\n");
    printf(" Score: %s (Black) %d : %d (White) %s\n", board.player1.name, board.player1.score, board.player2.score, board.player2.name);

    if (board.player1.score > board.player2.score)
        printf(" WINNER: %s", board.player1.name);

    else if (board.player1.score < board.player2.score)
        printf(" WINNER: %s", board.player2.name);

    else
        printf(" IT'S A TIE");
}


#endif //COMP10050_PROJECT2_HEADER1_H
