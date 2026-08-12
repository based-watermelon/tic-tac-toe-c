#include "raylib.h"
#include "raymath.h"
#include <stdbool.h>
#include <stdio.h>

typedef struct{
    int board[3][3];
    int current_player;
    bool game_won;
    int winning_player;
} Game;

int main(void){
    
    // initialize
    Game ng = {0};
    const int W_WIDTH = 400;
    const int W_HEIGHT = 450;
    ng.current_player = 1;


    InitWindow(W_WIDTH, W_HEIGHT, "Tic-Tac-Toe");

    SetTargetFPS(60);

    //main game loop
    while(!(WindowShouldClose())){
        
        Vector2 mousePos = GetMousePosition();

        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            if (mousePos.x < 40 + 320.0/3 && mousePos.x > 0 && mousePos.y > 115 + 320.0/3 && mousePos.y < 115 + 2*(320.0/3)){
                if(ng.current_player == 1 && ng.board[0][0] == 0){
                    ng.board[0][0] = 1;
                }
                else if(ng.current_player == -1 && ng.board[0][0] == 0){
                    ng.board[0][0] = -1;
                }
                ng.current_player *= -1;
                }


            
            }
        
        printf("pos 1 = %d player = %d\n",ng.board[0][0], ng.current_player);




        //rendering
        BeginDrawing();
            ClearBackground(RAYWHITE);
            // DrawText("New Window! ", W_WIDTH/2 - 20, W_HEIGHT/2, 20, BLACK);

            DrawText(TextFormat("Mouse X: %.0f", mousePos.x), 20, 20, 20, BLACK);
            DrawText(TextFormat("Mouse Y: %.0f", mousePos.y), 20, 50, 20, BLACK);
        EndDrawing();
        
    }

    CloseWindow();

    return 0;


}