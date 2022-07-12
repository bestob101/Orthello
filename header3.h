//
// Created by besto on 18/05/2021.
//

#ifndef COMP10050_PROJECT2_HEADER3_H
#define COMP10050_PROJECT2_HEADER3_H

#include "header1.h"
#include <stdbool.h>
#include <string.h>

/*
 * checks if a move can be made to the left of selected tile
 */
bool check_left(Board board, int row, int col)
{
    bool is_possible_move = false;

    int player_colour, opponent_colour;
    if (board.player_turn == BLACK)
    {
        player_colour = BLACK;
        opponent_colour = WHITE;
    }
    else
    {
        player_colour = WHITE;
        opponent_colour = BLACK;
    }

    int i = col-1;
    if (board.tiles[row][i] == opponent_colour && i >= 0)
    {
        i--;
        while (i >= 0 && !is_possible_move)
        {
            if (board.tiles[row][i] == player_colour)
                is_possible_move = true;

            i--;
        }
    }
    return is_possible_move;
}

/*
 * checks if a move can be made to the right of selected tile
 */
bool check_right(Board board, int row, int col)
{
    bool is_possible_move = false;

    int player_colour, opponent_colour;
    if (board.player_turn == BLACK)
    {
        player_colour = BLACK;
        opponent_colour = WHITE;
    }
    else
    {
        player_colour = WHITE;
        opponent_colour = BLACK;
    }

    int i = col+1;
    if (board.tiles[row][i] == opponent_colour && i < 8)
    {
        i++;
        while (i < 8 && !is_possible_move)
        {
            if (board.tiles[row][i] == player_colour)
                is_possible_move = true;

            i++;
        }
    }
    return is_possible_move;
}

/*
 * checks if a move can be made upwards of selected tile
 */
bool check_up(Board board, int row, int col)
{
    bool is_possible_move = false;

    int player_colour, opponent_colour;
    if (board.player_turn == BLACK)
    {
        player_colour = BLACK;
        opponent_colour = WHITE;
    }
    else
    {
        player_colour = WHITE;
        opponent_colour = BLACK;
    }

    int i = row-1;
    if (board.tiles[i][col] == opponent_colour && i >= 0)
    {
        i--;
        while (i >= 0 && !is_possible_move)
        {
            if (board.tiles[i][col] == player_colour)
                is_possible_move = true;

            i--;
        }
    }
    return is_possible_move;
}

/*
 * checks if a move can be made to the downwards of selected tile
 */
bool check_down(Board board, int row, int col)
{
    bool is_possible_move = false;

    int player_colour, opponent_colour;
    if (board.player_turn == BLACK)
    {
        player_colour = BLACK;
        opponent_colour = WHITE;
    }
    else
    {
        player_colour = WHITE;
        opponent_colour = BLACK;
    }

    int i = row+1;
    if (board.tiles[i][col] == opponent_colour && i < 8)
    {
        i++;
        while (i < 8 && !is_possible_move)
        {
            if (board.tiles[i][col] == player_colour)
                is_possible_move = true;

            i++;
        }
    }
    return is_possible_move;
}

/*
 * checks if a move can be made to diagonally down right of selected tile
 */
bool check_diag_down_right(Board board, int row, int col)
{
    bool is_possible_move = false;

    int player_colour, opponent_colour;
    if (board.player_turn == BLACK)
    {
        player_colour = BLACK;
        opponent_colour = WHITE;
    }
    else
    {
        player_colour = WHITE;
        opponent_colour = BLACK;
    }

    int i = row + 1;
    int j = col + 1;
    if (board.tiles[i][j] == opponent_colour && i < 8 && j < 8)
    {
        i++;
        j++;
        while (i < 8 && j < 8 && !is_possible_move)
        {
            if (board.tiles[i][j] == player_colour)
                is_possible_move = true;

            i++;
            j++;
        }
    }
    return is_possible_move;
}

/*
 * checks if a move can be made to diagonally down left of selected tile
 */
bool check_diag_down_left(Board board, int row, int col)
{
    bool is_possible_move = false;

    int player_colour, opponent_colour;
    if (board.player_turn == BLACK)
    {
        player_colour = BLACK;
        opponent_colour = WHITE;
    }
    else
    {
        player_colour = WHITE;
        opponent_colour = BLACK;
    }

    int i = row + 1;
    int j = col - 1;
    if (board.tiles[i][j] == opponent_colour && i < 8 && j >= 0)
    {
        i++;
        j--;
        while (i < 8 && j >= 0 && !is_possible_move)
        {
            if (board.tiles[i][j] == player_colour)
                is_possible_move = true;

            i++;
            j--;
        }
    }
    return is_possible_move;
}

/*
 * checks if a move can be made to diagonally up left of selected tile
 */
bool check_diag_up_left(Board board, int row, int col)
{
    bool is_possible_move = false;

    int player_colour, opponent_colour;
    if (board.player_turn == BLACK)
    {
        player_colour = BLACK;
        opponent_colour = WHITE;
    }
    else
    {
        player_colour = WHITE;
        opponent_colour = BLACK;
    }

    int i = row - 1;
    int j = col - 1;
    if (board.tiles[i][j] == opponent_colour && i >= 0 && j >= 0)
    {
        i--;
        j--;
        while (i >= 0 && j >= 0 && !is_possible_move)
        {
            if (board.tiles[i][j] == player_colour)
                is_possible_move = true;

            i--;
            j--;
        }
    }
    return is_possible_move;
}

/*
 * checks if a move can be made to diagonally up right of selected tile
 */
bool check_diag_up_right(Board board, int row, int col)
{
    bool is_possible_move = false;

    int player_colour, opponent_colour;
    if (board.player_turn == BLACK)
    {
        player_colour = BLACK;
        opponent_colour = WHITE;
    }
    else
    {
        player_colour = WHITE;
        opponent_colour = BLACK;
    }

    int i = row - 1;
    int j = col + 1;
    if (board.tiles[i][j] == opponent_colour && i >= 0 && j < 8)
    {
        i--;
        j++;
        while (i >= 0 && j < 8 && !is_possible_move)
        {
            if (board.tiles[i][j] == player_colour)
                is_possible_move = true;

            i--;
            j++;
        }
    }
    return is_possible_move;
}

/*
 * checks if a move can be made at all from selected tile
 */
bool is_possible_move_check(Board board, int row, int col)
{
    if ( check_left(board, row, col) || check_right(board, row, col) || check_up(board, row, col) || check_down(board, row, col) ||
         check_diag_down_left(board, row, col) || check_diag_down_right(board, row, col) || check_diag_up_left(board, row, col)  ||
         check_diag_up_right(board, row, col) )
    {
        return true;
    }
    else
        return false;
}

/*
 * Convert the string 'move' into integers to navigate a 2D-array in which the discs are stored.
 * The converted integers are assigned as rows and columns.
 */
void get_row_and_col(char move[5], int *rowp, int *colp)
{
    int row, col;
    char ch;

    ch = move[0];
    col = ch - 'a';

    ch = move[1];
    row = ch - '1';

    *rowp = row;
    *colp = col;
}

/*
 * checks if move input is valid
 */
bool is_valid_input(char move[])
{
    if (strlen(move) > 2 || strlen(move) < 1)
        return false;

    if (strcmp(move, "p") == 0)
        return true;

    char col = move[0];
    char row = move[1];

    if ( (col >= 'a' && col <= 'h') && (row >= '1' && row <= '8'))
        return true;
    else
        return false;
}

/*
 * checks if a move is valid
 */
bool is_valid_move(Board board, char move[], int *rowp, int *colp)
{
    if (is_valid_input(move))
    {
        get_row_and_col(move, rowp, colp);
        if (board.tiles[*rowp][*colp] == 0 && is_possible_move_check(board, *rowp, *colp))
            return true;
        else
            return false;
    }
    else
        return false;
}

/*
 * If player1 chooses to pass, checks if any black move is available
 */
bool is_black_move_available(Board *boardp)
{
    boardp->player_turn = BLACK;

    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            if (boardp->tiles[i][j] == 0 && is_possible_move_check(*boardp, i, j))
                return true;

    return false;
}

/*
 * If player2 chooses to pass, checks if any black move is available
 */
bool is_white_move_available(Board *boardp)
{
    boardp->player_turn = WHITE;

    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            if (boardp->tiles[i][j] == 0 && is_possible_move_check(*boardp, i, j))
                return true;

    return false;
}

/*
 * checks if any move is available for both party and ends game if no more moves available
 */
bool is_game_over(Board *boardP)
{
    int curr_player = boardP->player_turn;

    if (is_black_move_available(boardP) || is_white_move_available(boardP))
    {
        boardP->player_turn = curr_player;
        return false;
    }
    return true;
}
#endif //COMP10050_PROJECT2_HEADER3_H
