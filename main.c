//
// Created by besto on 18/05/2021.
//

#include <stdio.h>
#include <string.h>
#include <time.h>
#include "header1.h"
#include "header2.h"

int main(void)
{
    /* declare variables */
    char move[5];
    char curr_player[6];
    int row, col, *rowp, *colp;
    rowp = &row;
    colp = &col;

    Board board, *boardP;
    boardP = &board;

    printf("\n   *** WELCOME TO OTHELLO ***\n\n");


    get_player_names(boardP); //asks user to enter their name and stored to a stuct player
    initialise_board(boardP); //sets up the board to start game
    print_board(board); //prints the board

    /*
     * game is played until both players are unable to make moves
     */
    while (!is_game_over(boardP))
    {
        if (board.player_turn == BLACK)
            strcpy(curr_player, "Black");
        else
            strcpy(curr_player, "White");

        //asks user to enter a move
        printf("Enter move (%s): ", curr_player);
        scanf("%s", move);

        //checks if move is valid
        if (is_valid_move(board, move, rowp, colp))
        {
            update_board(boardP, row, col);
            print_board(board);
        }
        //if move is pass, then checks if conditions met for pass
        else if (strcmp(move, "p") == 0) {
            if (board.player_turn == BLACK && !is_black_move_available(boardP)) {
                boardP->player_turn = WHITE;
                continue;
            } else if (board.player_turn == WHITE && !is_white_move_available(boardP)) {
                boardP->player_turn = BLACK;
                continue;
            } else
                printf("Invalid move\n");
        }
        else
            printf("Invalid move\n");
    }

    print_winner(board); //winner is printed

    time_t t;
    time(&t);

    FILE *fp;

    //opens file for storing results of game
    if ( (fp = fopen("othello-results.txt", "a")) == NULL)
        puts("Cannot open file!");
    else
    {
        /*
         * prints score, outcome of game and date and time to file
         */
        fprintf(fp, "Score: %s (Black) %d : %d (White) %s\n", board.player1.name, board.player1.score,
                                                              board.player2.score, board.player2.name);

        if (board.player1.score > board.player2.score)
            fprintf(fp, "Winner: %s\n", board.player1.name);

        else if (board.player1.score < board.player2.score)
            fprintf(fp, "Winner: %s\n", board.player2.name);

        else
            fprintf(fp, "Draw\n");

        fprintf(fp, "%s\n\n", ctime(&t));

        fclose(fp);
    }
    return 0;
}