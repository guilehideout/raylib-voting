#include "include/raylib.h"
#include <stdio.h>
#include <stdlib.h>

void makehomepage(void);
void makevotepage(void);
void makeresultpage(void);

bool mouseonbutton(Vector2 mousepos, Rectangle button)
{

    return (mousepos.x >= button.x && mousepos.x <= (button.x + button.width)
            && mousepos.y >= button.y && mousepos.y <= (button.y + button.height));

}

int max3(int a, int b, int c)
{

    if (a > b)
    {
        if (a > c)
            return a;
        else
            return c;
    }
    else
    {
        if (b > c)
            return b;
        else
            return c;
    }

}

int same(int a, int b, int c)
{
    
    int count = 0;
    if (max3(a, b, c) == a)
    {
        count++;
    }
    if (max3(a, b, c) == b)
    {
        count++;
    }
    if (max3(a, b, c) == c)
    {
        count++;
    }
    return count;

}

void makevotepage()
{
    
    InitWindow(1366, 768, "Voting Window");

    Rectangle vjp = {145, 300, 153, 200};
    Rectangle cnc = {570, 300, 200, 195};
    Rectangle gnp = {990, 300, 175, 175};
    Rectangle nota = {605, 600, 100, 35};
    Texture2D vjpsymbol = LoadTexture("symbols\\vjp.png");
    Texture2D cncsymbol = LoadTexture("symbols\\cnc.png");
    Texture2D gnpsymbol = LoadTexture("symbols\\gnp.png");
    Font font = LoadFont("text\\BOOKOS.TTF");
    Vector2 mousepos;

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(BEIGE);
            
            DrawTextEx(font,"WELCOME TO VOTING PAGE!!", (Vector2) { 375, 100}, 50, 1, BLACK);
            DrawTextEx(font,"Select your candidate below: ", (Vector2) { 100, 200 }, 25, 1, BLACK);
            
            DrawTexture(vjpsymbol, 145, 345, WHITE);    
            DrawTextEx(font,"Vishwakarma\n  Janta Party", (Vector2) {150, 300}, 25, 1, BLACK);
            
            DrawTexture(cncsymbol, 589, 345, WHITE);    
            DrawTextEx(font,"   Chandkheda \nNational Congress", (Vector2) {570, 300}, 25, 1, BLACK);

            DrawTexture(gnpsymbol, 990, 365, WHITE);    
            DrawTextEx(font,"      GEC\nNagrik Party", (Vector2) {990, 300}, 25, 1, BLACK);

            DrawRectangleRec(nota, GRAY);
            DrawTextEx(font,"N O T A", (Vector2) {611, 605}, 25, 1, BLACK);

            mousepos = GetMousePosition();
            if (mouseonbutton(mousepos, vjp) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                FILE *vjpvote = fopen("votes\\vjp.txt","r");

                int vote;
                fscanf(vjpvote, "%d", &vote);
                vote++;
                fclose(vjpvote);

                FILE *vjpvote1 = fopen("votes\\vjp.txt","w");
                fprintf(vjpvote1, "%d", vote);
                fclose(vjpvote1);

                CloseWindow();
                makehomepage();
            }
            if (mouseonbutton(mousepos, cnc) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                FILE *cncvote = fopen("votes\\cnc.txt","r");

                int vote;
                fscanf(cncvote, "%d", &vote);
                vote++;
                fclose(cncvote);

                FILE *cncvote1 = fopen("votes\\cnc.txt","w");
                fprintf(cncvote1, "%d", vote);
                fclose(cncvote1);
                
                CloseWindow();
                makehomepage();
            }
            if (mouseonbutton(mousepos, gnp) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                FILE *gnpvote = fopen("votes\\gnp.txt","r");

                int vote;
                fscanf(gnpvote, "%d", &vote);
                vote++;
                fclose(gnpvote);

                FILE *gnpvote1 = fopen("votes\\gnp.txt","w");
                fprintf(gnpvote1, "%d", vote);
                fclose(gnpvote1);
                
                CloseWindow();
                makehomepage();
            }
            if (mouseonbutton(mousepos, nota) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                CloseWindow();
                makehomepage();
            }

            DrawTextEx(font,"Press ESC to exit.", (Vector2) {100, 668}, 25, 1, RED);

        EndDrawing();
    }

    UnloadTexture(vjpsymbol);
    UnloadTexture(cncsymbol);
    UnloadTexture(gnpsymbol);
    UnloadFont(font);
    CloseWindow();

}

void makeresultpage()
{

    InitWindow(1366, 768, "Result Window");
    
    char vote1[10], vote2[10], vote3[10];
    int intvote1, intvote2, intvote3, count = 0;
    Font font = LoadFont("text\\BOOKOS.ttf");
    FILE *vjpvote = fopen("votes\\vjp.txt","r");
    FILE *cncvote = fopen("votes\\cnc.txt","r");
    FILE *gnpvote = fopen("votes\\gnp.txt","r");
    Texture2D vjpsymbol = LoadTexture("symbols\\vjp.png");
    Texture2D cncsymbol = LoadTexture("symbols\\cnc.png");
    Texture2D gnpsymbol = LoadTexture("symbols\\gnp.png");

    fscanf(vjpvote, "%s", vote1);
    fscanf(cncvote, "%s", vote2);
    fscanf(gnpvote, "%s", vote3);

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(BEIGE);

            DrawTextEx(font, "RESULTS!!", (Vector2) { 375, 50 }, 50, 1, BLACK);
            
            DrawTextEx(font, "Number of Votes for 'Vishwakarma Janta Party' : ", (Vector2) { 345, 150 }, 25, 1, BLACK);
            DrawTextEx(font, vote1 , (Vector2) { 365, 180 }, 30, 1, BLACK);
           
            DrawTextEx(font, "Number of Votes for 'Chandkheda National Congress' : ", (Vector2) { 345, 250 }, 25, 1, BLACK);
            DrawTextEx(font, vote2 , (Vector2) { 365, 280 }, 30, 1, BLACK);
           
            DrawTextEx(font, "Number of Votes for 'GEC Nagrik Party' : ", (Vector2) { 345, 350 }, 25, 1, BLACK);
            DrawTextEx(font, vote3 , (Vector2) { 365, 380 }, 30, 1, BLACK);

            intvote1 = atoi(vote1);
            intvote2 = atoi(vote2);
            intvote3 = atoi(vote3);

            count = same(intvote1, intvote2, intvote3);

            if (count > 1)
            {
                DrawTextEx(font, "RESULT IS TIED!", (Vector2) {305, 450}, 50, 1, RED);
            }
            else
            {
                DrawTextEx(font, "THE WINNER IS: ", (Vector2) { 305, 450 }, 50, 1, BLACK);

                if (max3(intvote1, intvote2, intvote3) == intvote1)
                {
                    DrawTexture(vjpsymbol, 755, 450, WHITE);
                }
                if (max3(intvote1, intvote2, intvote3) == intvote2)
                {
                    DrawTexture(cncsymbol, 755, 450, WHITE);
                }
                if (max3(intvote1, intvote2, intvote3) == intvote3)
                {
                    DrawTexture(gnpsymbol, 755, 450, WHITE);
                }
            }

            DrawTextEx(font,"Press ESC to exit.\n\nPress ENTER to return to Home Page", (Vector2) {100, 668}, 25, 1, RED);

            if (IsKeyPressed(KEY_ENTER))
            {
                CloseWindow();
                makehomepage();
            }
            
        EndDrawing();
    }

    fclose(vjpvote);
    fclose(cncvote);
    fclose(gnpvote);
    UnloadTexture(vjpsymbol);
    UnloadTexture(cncsymbol);
    UnloadTexture(gnpsymbol);
    UnloadFont(font);

}

void makehomepage()
{

    InitWindow(1366, 768, "Welcome to Elections!");

    SetTargetFPS(24);

    Texture2D background = LoadTexture("symbols\\flag.png");
    Font font = LoadFont("text\\BOOKOS.TTF");
    Rectangle vote = {525, 250, 300, 50};
    Rectangle result = {525, 500, 300, 50};

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(BEIGE);
            DrawTexture(background, 0, 0, WHITE);
            DrawTextEx(font,"WELCOME TO ELECTIONS!!", (Vector2) { 375, 100}, 50, 1, BLACK);
            
            DrawRectangleRec(vote, GRAY);
            DrawTextEx(font, "Click here to vote", (Vector2) { 575, 262}, 25, 1, BLACK);

            DrawRectangleRec(result, GRAY);
            DrawTextEx(font, "Click here to see results", (Vector2) { 540, 512}, 25, 1, BLACK);

            DrawTextEx(font,"Press ESC to exit.", (Vector2) {100, 668}, 25, 1, RED);
        EndDrawing();

        Vector2 mousepos = GetMousePosition();
        if (mouseonbutton(mousepos, vote) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            CloseWindow();
            makevotepage();
            
        }
        if (mouseonbutton(mousepos, result) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            CloseWindow();
            makeresultpage();
        }
    }

    UnloadTexture(background);
    UnloadFont(font);
    CloseWindow();

}

int main()
{

    makehomepage();

    return 0;

}