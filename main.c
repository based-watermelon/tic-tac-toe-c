#include "raylib.h"
#include "raymath.h"
#include <stdbool.h>
#include <stdio.h>


#define CELL_SIZE  (320.0f / 3.0f)
typedef struct{
    int board[3][3];
    int current_player;
    bool game_won;
    int winning_player;
} Game;

int move_made(float x, float y, int board[3][3], int *curr_player, float cs){
                int row = -1 ,column = -1;
                if(x < 40 + cs && x > 40)
                    column = 0;
                else if (x < 40 + 2*(cs) && x > 40 + cs)
                    column = 1;
                else if (x < 40 + 3*(cs) && x > 40 + 2*(cs))
                    column = 2;
                if(y > 115  && y < 115 + cs)
                    row = 0;
                else if (y > 115 + cs  && y < 115 + 2*cs )
                    row = 1;
                else if (y > 115 + 2*cs  && y < 115 + 3*cs)
                    row = 2;

                if(row == -1 || column == -1)
                    return 0;
                if(board[row][column] != 0)
                    return 0;
                    
                board[row][column] = *curr_player;
                *curr_player *= -1;
                return  1;
                }


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

        // game logic
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            move_made(mousePos.x, mousePos.y, ng.board , &ng.current_player, CELL_SIZE);
        
        printf("player = %d\n",ng.current_player);
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                printf("%d ", ng.board[i][j]);
            }
            printf("\n");
        }
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