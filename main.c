#include "raylib.h"
#include "raymath.h"
#include <stdbool.h>

typedef struct{
    int board[3][3];
    int current_player;
    bool game_won;
    int winning_player;
} Game;

int main(void){
    
    // initialize
    Game ng;
    const int W_WIDTH = 400;
    const int W_HEIGHT = 450;
    ng.board;
    ng.current_player = 1;
    ng.game_won = false;
    ng.winning_player = 0;


    InitWindow(W_WIDTH, W_HEIGHT, "Tic-Tac-Toe");

    SetTargetFPS(60);

    //main game loop
    while(!(WindowShouldClose())){
        




        //rendering
        BeginDrawing();
            ClearBackground(RAYWHITE);
            // DrawText("New Window! ", W_WIDTH/2 - 20, W_HEIGHT/2, 20, BLACK);
        EndDrawing();
    }

    CloseWindow();

    return 0;


}