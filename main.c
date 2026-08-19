#include "raylib.h"
#include <stdbool.h>
#include <stdio.h>


#define CELL_SIZE  (320.0f / 3.0f)
#define BOARD_X  40
#define BOARD_Y  115

typedef struct{
    int board[3][3];
    int current_player;
    int game_won;
    int winning_player;
} Game;

int move_made(float x, float y, int board[3][3], int *curr_player, float cs){
                int row = -1 ,column = -1;
                if(x < BOARD_X + cs && x > BOARD_X)
                    column = 0;
                else if (x < BOARD_X + 2*(cs) && x > BOARD_X + cs)
                    column = 1;
                else if (x < BOARD_X + 3*(cs) && x > BOARD_X + 2*(cs))
                    column = 2;
                if(y > BOARD_Y  && y < BOARD_Y + cs)
                    row = 0;
                else if (y > BOARD_Y + cs  && y < BOARD_Y + 2*cs )
                    row = 1;
                else if (y > BOARD_Y + 2*cs  && y < BOARD_Y + 3*cs)
                    row = 2;

                if(row == -1 || column == -1)
                    return 0;
                if(board[row][column] != 0)
                    return 0;
                    
                board[row][column] = *curr_player;
                *curr_player *= -1;
                return  1;
                }

int win_pattern(int board[3][3], int curr_player){
    for(int i=0;i<3;i++){
        int a = board[i][0], b=board[i][1], c=board[i][2];
        if(a==b && b==c && a!=0){
            return curr_player;
        }
    for(int j=0;j<3;j++){
        int a = board[0][j], b=board[1][j], c=board[2][j];
        if(a==b && b==c && a!=0){
            return curr_player;
        }
    int d1 = board[0][0], d2 = board[1][1], d3 = board[2][2], d4 = board[2][0], d5 = board[0][2];
    if ((d1==d2 && d2==d3 && d1!=0) || (d4==d2 && d2==d5 && d4!=0))
        return curr_player;
        }
    }
    return 0;
}

int main(void){
    
    // initialize
    Game ng = {0};
    const int W_WIDTH = 400;
    const int W_HEIGHT = 450;
    ng.current_player = 1;


    InitWindow(W_WIDTH, W_HEIGHT, "Tic-Tac-Toe");

    SetTargetFPS(60);

    Texture2D cross = LoadTexture("assets/cross.png"); 
    Texture2D circle = LoadTexture("assets/circle.png");

    //main game loop
    while(!(WindowShouldClose())){
        
        Vector2 mousePos = GetMousePosition();

        // game logic
        ng.game_won = win_pattern ( ng.board, ng.current_player);

        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && ng.game_won == 0){
            move_made(mousePos.x, mousePos.y, ng.board , &ng.current_player, CELL_SIZE);
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                printf("%d ", ng.board[i][j]);
            }
            printf("\n");
                
        }}
        
        //rendering
        BeginDrawing();
            ClearBackground(RAYWHITE);
            // DrawText("New Window! ", W_WIDTH/2 - 20, W_HEIGHT/2, 20, BLACK);

            if(ng.game_won == 1){
                DrawText(TextFormat("Player 2 has won the match"), 20, 80, 20, BLACK);
                }
            if(ng.game_won == -1){
                DrawText(TextFormat("Player 1 has won the match"), 20, 80, 20, BLACK);
                }
            
            DrawText(TextFormat("Mouse X: %.0f", mousePos.x), 20, 20, 20, BLACK);
            DrawText(TextFormat("Mouse Y: %.0f", mousePos.y), 20, 50, 20, BLACK);
            DrawLine((BOARD_X+CELL_SIZE), BOARD_Y , (BOARD_X+CELL_SIZE), (BOARD_Y+3*CELL_SIZE), BLACK);
            DrawLine((BOARD_X+(2*CELL_SIZE)), BOARD_Y , (BOARD_X+2*CELL_SIZE), (BOARD_Y+3*CELL_SIZE), BLACK);
            DrawLine(BOARD_X, 115+CELL_SIZE , (BOARD_X+(3*CELL_SIZE)), (115+CELL_SIZE), BLACK);
            DrawLine(BOARD_X, BOARD_Y+(2*CELL_SIZE) , (BOARD_X+(3*CELL_SIZE)), (BOARD_Y+(2*CELL_SIZE)), BLACK);
        EndDrawing();
        
    }

    CloseWindow();

    return 0;
}