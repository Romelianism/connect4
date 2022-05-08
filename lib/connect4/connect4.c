#include "connect4.h"
#include <stdio.h>

/**
 * @brief Prints the connect4 board on the console.
 *
 * @param connect4 The connect4 that will be printed.
 */
void connect4_print(const struct Connect4 *connect4)
{
    // Reverse loop cause we want y index 0 to be ground
    for (size_t y = CONNECT4_HEIGHT; y-- > 0;)
    {
        for (size_t x = 0; x < CONNECT4_WIDTH; x++)
        {
            char tile;

            switch (connect4->board[x][y])
            {
            case empty:
                tile = '_';
                break;
            case player1:
                tile = 'X';
                break;
            case player2:
                tile = 'O';
                break;
            }
            printf("%c", tile);
        }
        printf("\n");
    }
}

/**
 * @brief Add a tile on the highest empty point at the selected row of the Connect4 struct.
 *
 * @param connect4 The Connect4 struct that a tile will be dropped on.
 * @param drop_position Which row the tile will be dropped on.
 * @param switch_turn Automatically switches the player's turn.
 */
void connect4_drop(struct Connect4 *connect4, const size_t drop_position, const bool switch_turn)
{
    for (size_t y = 0; y < CONNECT4_HEIGHT; y++)
    {
        // Check if current tile is empty.
        if (connect4->board[drop_position][y] == empty)
        {
            // Add current player to the current tile.
            connect4->board[drop_position][y] = connect4->turn ? player1 : player2;

            // Automatically switches the player's turn.
            if (switch_turn)
                connect4->turn = !connect4->turn;

            // End the function
            return;
        }
    }
}