//
// Created by besto on 18/05/2021.
//

#ifndef COMP10050_PROJECT2_HEADER2_H
#define COMP10050_PROJECT2_HEADER2_H

#include <stdio.h>
#include <stdbool.h>
#include "header1.h"
#include "header3.h"

/*
 * updates tiles to left of selected tile
 */
void update_left(Board *boardP, int row, int col)
{
    int i = col - 1;
    while (boardP->tiles[row][i] != boardP->player_turn && i >= 0)
    {
        boardP->tiles[row][i] = boardP->player_turn;

        if (boardP->player_turn == BLACK)
        {
            boardP->player1.score++;
            boardP->player2.score--;
        }
        else
        {
            boardP->player1.score--;
            boardP->player2.score++;
        }
        i--;
    }
}

/*
 * updates tiles to right of selected tile
 */
void update_right(Board *boardP, int row, int col)
{
    int i = col + 1;
    while (boardP->tiles[row][i] != boardP->player_turn && i < 8)
    {
        boardP->tiles[row][i] = boardP->player_turn;

        if (boardP->player_turn == BLACK)
        {
            boardP->player1.score++;
            boardP->player2.score--;
        }
        else
        {
            boardP->player1.score--;
            boardP->player2.score++;
        }
        i++;
    }
}

/*
 * updates tiles upwards of selected tile
 */
void update_up(Board *boardP, int row, int col)
{
    int i = row-1;
    while (boardP->tiles[i][col] != boardP->player_turn && i >= 0)
    {
        boardP->tiles[i][col] = boardP->player_turn;

        if (boardP->player_turn == BLACK)
        {
            boardP->player1.score++;
            boardP->player2.score--;
        }
        else
        {
            boardP->player1.score--;
            boardP->player2.score++;
        }
        i--;
    }
}

/*
 * updates tiles downwards of selected tile
 */
void update_down(Board *boardP, int row, int col)
{
    int i = row+1;
    while (boardP->tiles[i][col] != boardP->player_turn && i < 8)
    {
        boardP->tiles[i][col] = boardP->player_turn;

        if (boardP->player_turn == BLACK)
        {
            boardP->player1.score++;
            boardP->player2.score--;
        }
        else
        {
            boardP->player1.score--;
            boardP->player2.score++;
        }
        i++;
    }
}

/*
 * updates tiles to diagonally down right of selected tile
 */
void update_diag_down_right(Board *boardP, int row, int col)
{
    int i = row+1;
    int j = col+1;
    while (boardP->tiles[i][j] != boardP->player_turn && i < 8 && j < 8)
    {
        boardP->tiles[i][j] = boardP->player_turn;

        if (boardP->player_turn == BLACK)
        {
            boardP->player1.score++;
            boardP->player2.score--;
        }
        else
        {
            boardP->player1.score--;
            boardP->player2.score++;
        }
        i++;
        j++;
    }
}

/*
 * updates tiles to diagonally down left of selected tile
 */
void update_diag_down_left(Board *boardP, int row, int col)
{
    int i = row+1;
    int j = col-1;
    while (boardP->tiles[i][j] != boardP->player_turn && i < 8 && j >= 0)
    {
        boardP->tiles[i][j] = boardP->player_turn;

        if (boardP->player_turn == BLACK)
        {
            boardP->player1.score++;
            boardP->player2.score--;
        }
        else
        {
            boardP->player1.score--;
            boardP->player2.score++;
        }
        i++;
        j--;
    }
}

/*
 * updates tiles to diagonally up left of selected tile
 */
void update_diag_up_left(Board *boardP, int row, int col)
{
    int i = row-1;
    int j = col-1;
    while (boardP->tiles[i][j] != boardP->player_turn && i >= 0 && j >= 0)
    {
        boardP->tiles[i][j] = boardP->player_turn;

        if (boardP->player_turn == BLACK)
        {
            boardP->player1.score++;
            boardP->player2.score--;
        }
        else
        {
            boardP->player1.score--;
            boardP->player2.score++;
        }
        i--;
        j--;
    }
}

/*
 * updates tiles to diagonally up right of selected tile
 */
void update_diag_up_right(Board *boardP, int row, int col)
{
    int i = row-1;
    int j = col+1;
    while (boardP->tiles[i][j] != boardP->player_turn && i >= 0 && j < 8)
    {
        boardP->tiles[i][j] = boardP->player_turn;

        if (boardP->player_turn == BLACK)
        {
            boardP->player1.score++;
            boardP->player2.score--;
        }
        else
        {
            boardP->player1.score--;
            boardP->player2.score++;
        }
        i--;
        j++;
    }

}

/*
 * updates the board according to a players move
 */
void update_board(Board *boardP, int row, int col)
{
    if (check_left(*boardP, row, col))
        update_left(boardP, row, col);

    if (check_right(*boardP, row, col))
        update_right(boardP, row, col);

    if (check_up(*boardP, row, col))
        update_up(boardP, row, col);

    if (check_down(*boardP, row, col))
        update_down(boardP, row, col);

    if (check_diag_down_left(*boardP, row, col))
        update_diag_down_left(boardP, row, col);

    if (check_diag_down_right(*boardP, row, col))
        update_diag_down_right(boardP, row, col);

    if (check_diag_up_left(*boardP, row, col))
        update_diag_up_left(boardP, row, col);

    if (check_diag_up_right(*boardP, row, col))
        update_diag_up_right(boardP, row, col);

    boardP->tiles[row][col] = boardP->player_turn;

    /*
     * changes players turn
     */
    if (boardP->player_turn == BLACK)
    {
        boardP->player1.score++;
        boardP->player_turn = WHITE;
    }
    else
    {
        boardP->player2.score++;
        boardP->player_turn = BLACK;
    }
}
#endif //COMP10050_PROJECT2_HEADER2_H
