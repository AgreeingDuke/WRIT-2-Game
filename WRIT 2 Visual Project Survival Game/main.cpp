#include <iostream>
#include <raylib.h>

using namespace std;

typedef enum GameScreen {Title = 0, Scene1, Hint, PlayAgain} GameScreen;

typedef struct Enemy{
    Vector2 position;
    int speed;
    float radius;
    Color color;
} Enemy;

void drawAllPoly(int battle_state, int rotation){

    float SCREEN_WIDTH = GetScreenWidth();
    float SCREEN_HEIGHT = GetScreenHeight();

    if (battle_state == 1){
        DrawPoly((Vector2){0, 300}, 6, 40, rotation, RED);
        DrawPolyLines((Vector2){ 0, 300}, 6, 50, rotation, BLACK);
        DrawPolyLinesEx((Vector2){0, 300}, 6, 45, rotation, 6, RED);

        DrawPoly((Vector2){SCREEN_WIDTH, 600}, 6, 40, rotation, RED);
        DrawPolyLines((Vector2){SCREEN_WIDTH, 600}, 6, 50, rotation, BLACK);
        DrawPolyLinesEx((Vector2){SCREEN_WIDTH, 600}, 6, 45, rotation, 6, RED);
    }

    if (battle_state == 2){
        
        DrawPoly((Vector2){0, 300}, 6, 40, rotation, RED);
        DrawPolyLines((Vector2){ 0, 300}, 6, 50, rotation, BLACK);
        DrawPolyLinesEx((Vector2){0, 300}, 6, 45, rotation, 6, RED);

        DrawPoly((Vector2){SCREEN_WIDTH, 600}, 6, 40, rotation, RED);
        DrawPolyLines((Vector2){SCREEN_WIDTH, 600}, 6, 50, rotation, BLACK);
        DrawPolyLinesEx((Vector2){SCREEN_WIDTH, 600}, 6, 45, rotation, 6, RED);

        DrawPoly((Vector2){SCREEN_WIDTH/3, SCREEN_HEIGHT}, 6, 40, rotation, RED);
        DrawPolyLines((Vector2){SCREEN_WIDTH/3, SCREEN_HEIGHT}, 6, 50, rotation, BLACK);
        DrawPolyLinesEx((Vector2){SCREEN_WIDTH/3, SCREEN_HEIGHT}, 6, 45, rotation, 6, RED);

        DrawPoly((Vector2){2*SCREEN_WIDTH/3, SCREEN_HEIGHT}, 6, 40, rotation, RED);
        DrawPolyLines((Vector2){2*SCREEN_WIDTH/3, SCREEN_HEIGHT}, 6, 50, rotation, BLACK);
        DrawPolyLinesEx((Vector2){2*SCREEN_WIDTH/3, SCREEN_HEIGHT}, 6, 45, rotation, 6, RED);
    }

    if (battle_state == 3){
        
        DrawPoly((Vector2){0, 300}, 6, 40, rotation, RED);
        DrawPolyLines((Vector2){ 0, 300}, 6, 50, rotation, BLACK);
        DrawPolyLinesEx((Vector2){0, 300}, 6, 45, rotation, 6, RED);

        DrawPoly((Vector2){SCREEN_WIDTH, 600}, 6, 40, rotation, RED);
        DrawPolyLines((Vector2){SCREEN_WIDTH, 600}, 6, 50, rotation, BLACK);
        DrawPolyLinesEx((Vector2){SCREEN_WIDTH, 600}, 6, 45, rotation, 6, RED);

        DrawPoly((Vector2){SCREEN_WIDTH/3, SCREEN_HEIGHT}, 6, 40, rotation, RED);
        DrawPolyLines((Vector2){SCREEN_WIDTH/3, SCREEN_HEIGHT}, 6, 50, rotation, BLACK);
        DrawPolyLinesEx((Vector2){SCREEN_WIDTH/3, SCREEN_HEIGHT}, 6, 45, rotation, 6, RED);

        DrawPoly((Vector2){2*SCREEN_WIDTH/3, SCREEN_HEIGHT}, 6, 40, rotation, RED);
        DrawPolyLines((Vector2){2*SCREEN_WIDTH/3, SCREEN_HEIGHT}, 6, 50, rotation, BLACK);
        DrawPolyLinesEx((Vector2){2*SCREEN_WIDTH/3, SCREEN_HEIGHT}, 6, 45, rotation, 6, RED);

        DrawPoly((Vector2){0, SCREEN_HEIGHT}, 6, 40, rotation, RED);
        DrawPolyLines((Vector2){0, SCREEN_HEIGHT}, 6, 50, rotation, BLACK);
        DrawPolyLinesEx((Vector2){0, SCREEN_HEIGHT}, 6, 45, rotation, 6, RED);

        DrawPoly((Vector2){SCREEN_WIDTH, SCREEN_HEIGHT}, 6, 40, rotation, RED);
        DrawPolyLines((Vector2){SCREEN_WIDTH, SCREEN_HEIGHT}, 6, 50, rotation, BLACK);
        DrawPolyLinesEx((Vector2){SCREEN_WIDTH, SCREEN_HEIGHT}, 6, 45, rotation, 6, RED);

    }
}

void drawguidelines(float SCREEN_WIDTH, float SCREEN_HEIGHT){

    for (int i = 100; i <= SCREEN_WIDTH - 100; i += 100){
        DrawLine(i, 0, i, SCREEN_HEIGHT, WHITE);
    }

    for (int k = 100; k <= SCREEN_HEIGHT - 100; k += 100){
        DrawLine(0, k, SCREEN_WIDTH, k, WHITE);
    }

    
}

void drawPaper(int num_papers,Rectangle messages[], float SCREEN_WIDTH, Font mechafont){

    switch (num_papers)
    {
        case 8:
            DrawRectangleGradientEx(messages[0],GRAY, BLACK, GRAY, WHITE);
            DrawRectangle(0, 0, SCREEN_WIDTH, 100, BLACK);
            DrawTextEx(mechafont, "..........", (Vector2){SCREEN_WIDTH/2 - MeasureTextEx(mechafont, "..........", 30, 5).x/2, 50 - 15}, 
            30, 
            5, 
            WHITE);
            break;
    
        case 7:
            DrawRectangleGradientEx(messages[1],GRAY, BLACK, GRAY, WHITE);
            DrawRectangle(0, 0, SCREEN_WIDTH, 100, BLACK);
            DrawTextEx(
                mechafont, 
                "Struggling a light has awoken. Your Survival not guranteed.", 
                (Vector2){SCREEN_WIDTH/2 - MeasureTextEx(mechafont, "Struggling a light has awoken. Your Survival not guranteed.", 30, 5).x/2, 50 - 15}, 
                30, 
                5,  
                WHITE);
            break;
        case 6:
            DrawRectangleGradientEx(messages[2],GRAY, BLACK, GRAY, WHITE);
            DrawRectangle(0, 0, SCREEN_WIDTH, 100, BLACK);
            DrawTextEx(
                mechafont, 
                "Collect all the pieces to see the truth. This world is no longer kind to us.",
                (Vector2){SCREEN_WIDTH/2 - MeasureTextEx(mechafont, "Collect all the pieces to see the truth. This world is no longer kind to us.", 30, 5).x/2, 50 - 15},
                30, 
                5,
                WHITE);
            break;
        case 5:
            DrawRectangleGradientEx(messages[3],GRAY, BLACK, GRAY, WHITE);
            DrawRectangle(0, 0, SCREEN_WIDTH, 100, BLACK);
            DrawTextEx(
                mechafont,
                "Machine made god. Deemed their creator unworthy",
                (Vector2){SCREEN_WIDTH/2 - MeasureTextEx(mechafont, "Machine made god. Deemed their creator unworthy", 30, 5).x/2, 50 - 15},
                30,
                5, 
                WHITE);
            break;
        case 4:
            DrawRectangleGradientEx(messages[4],GRAY, BLACK, GRAY, WHITE);
            DrawRectangle(0, 0, SCREEN_WIDTH, 100, BLACK);
            DrawTextEx(
                mechafont, 
                "fight till your circuits go aflame. You are still in our image", 
                (Vector2){SCREEN_WIDTH/2 - MeasureTextEx(mechafont, "fight till your circuits go aflame. You are still in our image", 30, 5).x/2, 50 - 15}, 
                30,
                5,   
                WHITE);
            break;
        case 3:
            DrawRectangleGradientEx(messages[5],GRAY, BLACK, GRAY, WHITE);
            DrawRectangle(0, 0, SCREEN_WIDTH, 100, BLACK);
            DrawTextEx(
                mechafont, 
                "Your Survival is not guranteed.",  
                (Vector2){SCREEN_WIDTH/2 - MeasureTextEx(mechafont, "Your Survival is not guranteed.", 30, 5).x/2, 50 - 15}, 
                30,
                5,
                WHITE);
            break;
        case 2:
            DrawRectangleGradientEx(messages[6],GRAY, BLACK, GRAY, WHITE);
            DrawRectangle(0, 0, SCREEN_WIDTH, 100, BLACK);
            DrawTextEx(
                mechafont, 
                "One after another they took it all. Not one was left untainted", 
                (Vector2){SCREEN_WIDTH/2 - MeasureTextEx(mechafont, "One after another they took it all. Not one was left untainted", 30, 5).x/2, 50 - 15}, 
                30, 
                5, 
                WHITE);
            break;
        case 1:
            DrawRectangleGradientEx(messages[7],GRAY, BLACK, GRAY, WHITE);
        case 0:
            DrawRectangle(0, 0, SCREEN_WIDTH, 100, BLACK);
            DrawTextEx(
                mechafont,
                "Will you live a life. Or will you be consumed like the rest",
                (Vector2){SCREEN_WIDTH/2 - MeasureTextEx(mechafont, "Will you live a life. Or will you be consumed like the rest", 30, 5).x/2, 50 - 15},
                30,
                5,
                WHITE);
    }
}



int main () {
    SetRandomSeed(1);
    const float SCREEN_WIDTH = 1400.0;
    const float SCREEN_HEIGHT = 1000.0;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "The WEBSITE");
    SetTargetFPS(60);

    Font mechaFont = LoadFont("AudioResources/mecha.png");

    Vector2 playerPosition = { (float) SCREEN_WIDTH/2 , (float) SCREEN_HEIGHT - 200 };  // player poition is set here

    Rectangle playerMouse = {playerPosition.x, playerPosition.y, 5, 5}; // playermouse starting position
    Rectangle playbutton = {(float) (SCREEN_WIDTH/2 - MeasureTextEx(mechaFont,"Play", 20, 5).x - 5), (float) (SCREEN_HEIGHT /2 - 100), (float)70, 35}; // title play button 
    Rectangle Hintbutton = {(float) (SCREEN_WIDTH/2 - MeasureTextEx(mechaFont,"Hint", 20, 5).x - 5), (float) (SCREEN_HEIGHT /2), (float)70, 35}; // title hint button
    Rectangle Quitbutton = {(float) (SCREEN_WIDTH/2 - MeasureTextEx(mechaFont,"Quit", 20, 5).x - 5), (float) (SCREEN_HEIGHT /2 + 100),(float)70, 35}; // title quit button

    Rectangle message1 = {(float) GetRandomValue(200, 1200), (float) GetRandomValue(200, 800), 20, 20};
    Rectangle message2 = {(float) GetRandomValue(200, 1200), (float) GetRandomValue(200, 800), 20, 20};
    Rectangle message3 = {(float) GetRandomValue(200, 1200), (float) GetRandomValue(200, 800), 20, 20};
    Rectangle message4 = {(float) GetRandomValue(200, 1200), (float) GetRandomValue(200, 800), 20, 20};
    Rectangle message5 = {(float) GetRandomValue(200, 1200), (float) GetRandomValue(200, 800), 20, 20};
    Rectangle message6 = {(float) GetRandomValue(200, 1200), (float) GetRandomValue(200, 800), 20, 20};
    Rectangle message7 = {(float) GetRandomValue(200, 1200), (float) GetRandomValue(200, 800), 20, 20};
    Rectangle message8 = {(float) GetRandomValue(200, 1200), (float) GetRandomValue(200, 800), 20, 20};
    Rectangle messages[] = {message1, message2, message3, message4, message5, message6, message7, message8};
    
    Enemy enemy1 = {(Vector2) {0, 300}, GetRandomValue(1, 8), 15, RED};
    Enemy enemy2 = {(Vector2) {-50, 300}, GetRandomValue(1, 8), 15, RED};
    Enemy enemy3 = {(Vector2) {-100, 300}, GetRandomValue(1, 12), 15, RED};
    Enemy enemy4 = {(Vector2) {-150, 300}, GetRandomValue(1, 12), 15, RED};

    Enemy enemy5 = {(Vector2) {SCREEN_WIDTH, 600}, GetRandomValue(1, 8), 15, PURPLE};
    Enemy enemy6 = {(Vector2) {SCREEN_WIDTH + 50, 600}, GetRandomValue(1, 8), 15, PURPLE};
    Enemy enemy7 = {(Vector2) {SCREEN_WIDTH + 100, 600}, GetRandomValue(1, 12), 15, PURPLE};
    Enemy enemy8 = {(Vector2) {SCREEN_WIDTH + 150, 600}, GetRandomValue(1, 12), 15, PURPLE};

    Enemy enemy9 = {(Vector2) {SCREEN_WIDTH/3, SCREEN_HEIGHT + 50}, GetRandomValue(1, 8), 15, ORANGE};
    Enemy enemy10 = {(Vector2) {SCREEN_WIDTH/3, SCREEN_HEIGHT + 50}, GetRandomValue(1, 8), 15, ORANGE};
    Enemy enemy11 = {(Vector2) {SCREEN_WIDTH/3, SCREEN_HEIGHT + 50}, GetRandomValue(1, 12), 15, ORANGE};
    Enemy enemy12 = {(Vector2) {SCREEN_WIDTH/3, SCREEN_HEIGHT + 50}, GetRandomValue(1, 12), 15, ORANGE};

    Enemy enemy13 = {(Vector2) {2*SCREEN_WIDTH/3, SCREEN_HEIGHT + 50}, GetRandomValue(1, 8), 15, RAYWHITE};
    Enemy enemy14 = {(Vector2) {2*SCREEN_WIDTH/3, SCREEN_HEIGHT + 50}, GetRandomValue(1, 8), 15, RAYWHITE};
    Enemy enemy15 = {(Vector2) {2*SCREEN_WIDTH/3, SCREEN_HEIGHT + 50}, GetRandomValue(1, 12), 15, RAYWHITE};
    Enemy enemy16 = {(Vector2) {2*SCREEN_WIDTH/3, SCREEN_HEIGHT + 50}, GetRandomValue(1, 12), 15, RAYWHITE};

    Enemy enemy17 = {(Vector2) {0, SCREEN_HEIGHT}, GetRandomValue(1, 8), 15, DARKPURPLE};
    Enemy enemy18 = {(Vector2) {0, SCREEN_HEIGHT}, GetRandomValue(1, 8), 15, DARKPURPLE};
    Enemy enemy19  = {(Vector2) {0, SCREEN_HEIGHT}, GetRandomValue(1, 12), 15, DARKPURPLE};
    Enemy enemy20 = {(Vector2) {0, SCREEN_HEIGHT}, GetRandomValue(1, 12), 15, DARKPURPLE};

    Enemy enemy21 = {(Vector2) {SCREEN_WIDTH, SCREEN_HEIGHT}, GetRandomValue(1, 8), 15, DARKBROWN};
    Enemy enemy22 = {(Vector2) {SCREEN_WIDTH, SCREEN_HEIGHT}, GetRandomValue(1, 8), 15, DARKBROWN};
    Enemy enemy23 = {(Vector2) {SCREEN_WIDTH, SCREEN_HEIGHT}, GetRandomValue(1, 12), 15, DARKBROWN};
    Enemy enemy24 = {(Vector2) {SCREEN_WIDTH, SCREEN_HEIGHT}, GetRandomValue(1, 12), 15, DARKBROWN};

    Enemy* my_enemy1 = &enemy1;
    Enemy* my_enemy2 = &enemy2;
    Enemy* my_enemy3 = &enemy3;
    Enemy* my_enemy4 = &enemy4;
    Enemy* my_enemy5 = &enemy5;
    Enemy* my_enemy6 = &enemy6;
    Enemy* my_enemy7 = &enemy7;
    Enemy* my_enemy8 = &enemy8;
    Enemy* my_enemy9 = &enemy9;
    Enemy* my_enemy10 = &enemy10;
    Enemy* my_enemy11 = &enemy11;
    Enemy* my_enemy12 = &enemy12;
    Enemy* my_enemy13 = &enemy13;
    Enemy* my_enemy14 = &enemy14;
    Enemy* my_enemy15 = &enemy15;
    Enemy* my_enemy16 = &enemy16;
    Enemy* my_enemy17 = &enemy17;
    Enemy* my_enemy18 = &enemy18;
    Enemy* my_enemy19 = &enemy19;
    Enemy* my_enemy20 = &enemy20;
    Enemy* my_enemy21 = &enemy21;
    Enemy* my_enemy22 = &enemy22;
    Enemy* my_enemy23 = &enemy23;
    Enemy* my_enemy24 = &enemy24;

    Enemy* enemies1[] = {my_enemy1, my_enemy2, my_enemy3, my_enemy4};
    Enemy* enemies2[] = {my_enemy5, my_enemy6, my_enemy7, my_enemy8};
    Enemy* enemies3[] = {my_enemy9, my_enemy10, my_enemy11, my_enemy12};
    Enemy* enemies4[] = {my_enemy13, my_enemy14, my_enemy15, my_enemy16};
    Enemy* enemies5[] = {my_enemy17, my_enemy18, my_enemy19, my_enemy20};
    Enemy* enemies6[] = {my_enemy21, my_enemy22, my_enemy23, my_enemy24};

    const char* text = "D Q M  W K O Q I A M  J H L  D H H R  I D  K T T  N U H W  X F . \n"
                    "I D  Y K F  V M U N M O D  P M N H U    Y I D Q  K T T  D Q M  T X C X U I M F \n"
                     "D Q M  N T M M D  X A L M U  I D F  O H A D U H T  V U H G I L M L . \n"
                    "I D  Y K F  P M K X D I N X T , I  F V M A D  D I W M  Y I D Q  W Z  O Q I T L U M A  \n"
                    "M G M U Z L K Z , F V M A D  D I W M  Y H U R I A J  H A  W Z  V Q Z F I E X M , K A L  \n"
                    "K D M  L M T I O I H X F  N H H L  N K U W M L  P Z  D Q M  W K O Q I A M F .\n"
                    "I D  Y K F  Q M K G M A  H A  M K U D Q . \n"
                    "I  J X M F F  Q X W K A I D Z  Y K F  D H H  J U M M L Z  I A  D Q M  M A L . I  \n"
                    "T H F D  M G M U Z D Q I A J ; W Z  N K W I T Z , W Z  Q H W M , W Z  T I N M . \n"
                    "Y M  Y M U M  Q X A D M L  T I R M  D Q M  V U M Z  Y M  Q X A D M L  P M N H U M\n" 
                    "D Q M  K J M  H N  W K O Q I A M F .\n"
                    "H A M  L K Z  I D  Y K F  O T M K U  F R I M F , A M C D  I D  Y K F  U M L \n" 
                    "P T H H L -N I T T M L  F R I M F . \n"
                    "I N  K A Z H A M  U M K L F  D Q I F  I W  K T U M K L Z  L M K L . \n"
                    "D Q I F  I F  W Z  U M O H X A D  K A L  W K Z  J H L  Q K G M  W M U O Z  H A  H X U\n"
                    "F H X T F . J H H L P Z M .";
    
    const char* text2 = "H A M L K Z Y M Y I T T U I F M M M ? ~ =: H A M L K Z Y M Y I T T U I F M M M ? ~ =:\n" 
    "H A M L K Z Y M Y I T T U I F M M M ? ~ =: H A M L K Z Y M Y I T T U I F M M M ? ~ =:\n"
    "H A M L K Z Y M Y I T T U I F M M M ? ~ =: H A M L K Z Y M Y I T T U I F M M M ? ~ =:\n"
    "H A M L K Z Y M Y I T T U I F M M M ? ~ =: H A M L K Z Y M Y I T T U I F M M M ? ~ =:\n"
    "H A M L K Z Y M Y I T T U I F M M M ? ~ =: H A M L K Z Y M Y I T T U I F M M M ? ~ =:\n"
    "H A M L K Z Y M Y I T T U I F M M M ? ~ =: H A M L K Z Y M Y I T T U I F M M M ? ~ =:\n"
    "H A M L K Z Y M Y I T T U I F M M M ? ~ =: H A M L K Z Y M Y I T T U I F M M M ? ~ =:\n"
    "H A M L K Z Y M Y I T T U I F M M M ? ~ =: H A M L K Z Y M Y I T T U I F M M M ? ~ =:\n"
    "H A M L K Z Y M Y I T T U I F M M M ? ~ =: H A M L K Z Y M Y I T T U I F M M M ? ~ =:\n";



    const char* text3 = "Y Q Z W X F D D Q I F Y H U T L P M F H O U X M T T -\n"
    "Y Q Z W X F D D Q I F Y H U T L P M F H O U X M T T -\n"
    "Y Q Z W X F D D Q I F Y H U T L P M F H O U X M T T -\n"
    "Y Q Z W X F D D Q I F Y H U T L P M F H O U X M T T -\n"
    "Y Q Z W X F D D Q I F Y H U T L P M F H O U X M T T -\n" 
    "Y Q Z W X F D D Q I F Y H U T L P M F H O U X M T T -\n"
    "Y Q Z W X F D D Q I F Y H U T L P M F H O U X M T T -\n"
    "Y Q Z W X F D D Q I F Y H U T L P M F H O U X M T T -\n"
    "Y Q Z W X F D D Q I F Y H U T L P M F H O U X M T T -\n"
    "Y Q Z W X F D D Q I F Y H U T L P M F H O U X M T T -\n"
    "Y Q Z W X F D D Q I F Y H U T L P M F H O U X M T T -\n"
    "Y Q Z W X F D D Q I F Y H U T L P M F H O U X M T T -\n"
    "Y Q Z W X F D D Q I F Y H U T L P M F H O U X M T T -\n";

    SetExitKey(KEY_NULL);      // Disable KEY_ESCAPE to close window, X-button still works
    
    bool exitWindowRequested = false;   // Flag to request window to exit
    bool exitWindow = false;    // Flag to set window to exit

    GameScreen currentscreen = Title;
    int num_papers = 8;
    float rotation = 4.0f;
    int battle_state = 0;
    bool game_complete = false;
    int framecount = 0;
    bool stop = false;
    int sentence = 1;
    while (!exitWindow){

        

        // Detect if X-button or KEY_ESCAPE have been pressed to close window
        if (WindowShouldClose() || IsKeyPressed(KEY_ESCAPE)) exitWindowRequested = true;
        
        if (exitWindowRequested)
        {
            // A request for close window has been issued, we can save data before closing
            // or just show a message asking for confirmation
            
            if (IsKeyPressed(KEY_Y)) exitWindow = true;
            else if (IsKeyPressed(KEY_N)) exitWindowRequested = false;
        }

        switch(currentscreen)
        {
            case Title:
            {
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                    if (CheckCollisionRecs(playerMouse, playbutton)){
                        currentscreen = Scene1;
                    }
                    else if (CheckCollisionRecs(playerMouse, Hintbutton) && game_complete){
                        currentscreen = Hint;
                    }
                    else if (CheckCollisionRecs(playerMouse, Quitbutton)) {exitWindowRequested = true;}
                }
            }
            case Scene1:
            {   
                rotation += 5;

                if (CheckCollisionCircleRec(playerPosition, 15.0, message1) && num_papers == 8){num_papers = 7; battle_state = 1;} 
                if (CheckCollisionCircleRec(playerPosition,15.0,  message2) && num_papers == 7){num_papers = 6;}
                if (CheckCollisionCircleRec(playerPosition, 15.0, message3) && num_papers == 6){num_papers = 5; battle_state = 2;}
                if (CheckCollisionCircleRec(playerPosition, 15.0,  message4) && num_papers == 5){num_papers = 4;}
                if (CheckCollisionCircleRec(playerPosition, 15.0, message5) && num_papers == 4) {num_papers = 3; battle_state = 3;}
                if (CheckCollisionCircleRec(playerPosition, 15.0, message6) && num_papers == 3){num_papers = 2; }
                if (CheckCollisionCircleRec(playerPosition, 15.0, message7) && num_papers == 2){num_papers = 1;}
                if (CheckCollisionCircleRec(playerPosition, 15.0, message8) && num_papers == 1){
                    num_papers = 0; 
                    game_complete = true;
                    battle_state = 0;
                    if (stop == true) {stop = !stop;}
                    for (int i = 0; i < 4; i++){
                        enemies1[i] -> position = (Vector2){0, 300};
                        enemies2[i] -> position = (Vector2){SCREEN_WIDTH, 600};
                        enemies3[i] -> position = (Vector2){SCREEN_WIDTH/3, SCREEN_HEIGHT + 50};
                        enemies4[i] -> position = (Vector2){2*SCREEN_WIDTH/3, SCREEN_HEIGHT + 50};
                        enemies5[i] -> position = (Vector2){0, SCREEN_HEIGHT};
                        enemies6[i] -> position = (Vector2){SCREEN_WIDTH, SCREEN_HEIGHT};
                    }
                }

                for(int i = 0; i < 4; i++){

                    if (CheckCollisionCircles(playerPosition, 15.0 , enemies1[i] -> position, enemies1[i] -> radius)) {currentscreen = PlayAgain;}
                    if (CheckCollisionCircles(playerPosition, 15.0 , enemies2[i] -> position, enemies2[i] -> radius)) {currentscreen = PlayAgain;}
                    if (CheckCollisionCircles(playerPosition, 15.0 , enemies3[i] -> position, enemies3[i] -> radius)) {currentscreen = PlayAgain;}
                    if (CheckCollisionCircles(playerPosition, 15.0 , enemies4[i] -> position, enemies4[i] -> radius)) {currentscreen = PlayAgain;}
                    if (CheckCollisionCircles(playerPosition, 15.0 , enemies5[i] -> position, enemies5[i] -> radius)) {currentscreen = PlayAgain;}
                    if (CheckCollisionCircles(playerPosition, 15.0 , enemies6[i] -> position, enemies6[i] -> radius)) {currentscreen = PlayAgain;}
                }

                if (battle_state == 1) {
                    for (int i = 0; i < 4; i++){
                        
                        enemies1[i] -> position.x += enemies1[i] -> speed;
                        if (enemies1[i] -> position.x >= SCREEN_WIDTH + 50) {enemies1[i] -> position.x = 0;}

                        enemies2[i] -> position.x -= enemies2[i] -> speed;
                        if (enemies2[i] -> position.x <= -50) {enemies2[i] -> position.x = SCREEN_WIDTH + 50;}
                    
                    }

                }

                if (battle_state == 2) {
                    for (int i = 0; i < 4; i++){
                        
                        enemies1[i] -> position.x += enemies1[i] -> speed;
                        if (enemies1[i] -> position.x >= SCREEN_WIDTH + 50) {enemies1[i] -> position.x = 0;}

                        enemies2[i] -> position.x -= enemies2[i] -> speed;
                        if (enemies2[i] -> position.x <= -50) {enemies2[i] -> position.x = SCREEN_WIDTH + 50;}

                        enemies3[i] -> position.y -= enemies3[i] -> speed;
                        if (enemies3[i] -> position.y <= 50) {enemies3[i] -> position.y = SCREEN_HEIGHT + 50;}
                        
                        enemies4[i] -> position.y -= enemies4[i] -> speed;
                        if (enemies4[i] -> position.y <= 50) {enemies4[i] -> position.y = SCREEN_HEIGHT + 50;} 
                        
                    }
                }

                if (battle_state == 3){
                    for (int i = 0; i < 4; i++){
                        
                        enemies1[i] -> position.x += enemies1[i] -> speed;
                        if (enemies1[i] -> position.x >= SCREEN_WIDTH + 50) {enemies1[i] -> position.x = 0;}

                        enemies2[i] -> position.x -= enemies2[i] -> speed;
                        if (enemies2[i] -> position.x <= -50) {enemies2[i] -> position.x = SCREEN_WIDTH + 50;}

                        enemies3[i] -> position.y -= enemies3[i] -> speed;
                        if (enemies3[i] -> position.y <= 50) {enemies3[i] -> position.y = SCREEN_HEIGHT + 50;}
                        
                        enemies4[i] -> position.y -= enemies4[i] -> speed;
                        if (enemies4[i] -> position.y <= 50) {enemies4[i] -> position.y = SCREEN_HEIGHT + 50;} 

                        enemies5[i] -> position.y -= enemies5[i] -> speed;
                        enemies5[i] -> position.x += enemies5[i] -> speed;

                        if (enemies5[i] -> position.y <= 50 && enemies5[i] -> position.x >= SCREEN_WIDTH + 50) {
                            enemies5[i] -> position.y = SCREEN_HEIGHT;
                            enemies5[i] -> position.x = 0;
                            } 
                        
                        enemies6[i] -> position.y -= enemies6[i] -> speed;
                        enemies6[i] -> position.x -= enemies6[i] -> speed;

                        if (enemies6[i] -> position.y <= 50 && enemies6[i] -> position.x <= -50) {
                            enemies6[i] -> position.y = SCREEN_HEIGHT;
                            enemies6[i] -> position.x = SCREEN_WIDTH;
                            } 
                    }
                }

                if (game_complete && !stop) {

                    framecount++;
                    
                    if (framecount >= 300) {
                        currentscreen = Title;
                        stop = !stop;
                        }
                }

            } break;
            case PlayAgain:
            {
                if (IsKeyPressed(KEY_Y)) {
                    num_papers = 8;
                    battle_state = 0;

                    for (int i = 0; i < 4; i++){
                        enemies1[i] -> position = (Vector2){0, 300};
                        enemies2[i] -> position = (Vector2){SCREEN_WIDTH, 600};
                        enemies3[i] -> position = (Vector2){SCREEN_WIDTH/3, SCREEN_HEIGHT + 50};
                        enemies4[i] -> position = (Vector2){2*SCREEN_WIDTH/3, SCREEN_HEIGHT + 50};
                        enemies5[i] -> position = (Vector2){0, SCREEN_HEIGHT};
                        enemies6[i] -> position = (Vector2){SCREEN_WIDTH, SCREEN_HEIGHT};
                    }

                    currentscreen = Scene1; 

                } else if (IsKeyPressed(KEY_N)){
                    num_papers = 8;
                    battle_state = 0;
                    for (int i = 0; i < 4; i++){
                        enemies1[i] -> position = (Vector2){0, 300};
                        enemies2[i] -> position = (Vector2){SCREEN_WIDTH, 600};
                        enemies3[i] -> position = (Vector2){SCREEN_WIDTH/3, SCREEN_HEIGHT + 50};
                        enemies4[i] -> position = (Vector2){2*SCREEN_WIDTH/3, SCREEN_HEIGHT + 50};
                        enemies5[i] -> position = (Vector2){0, SCREEN_HEIGHT};
                        enemies6[i] -> position = (Vector2){SCREEN_WIDTH, SCREEN_HEIGHT};
                    }
                    currentscreen = Title;
                }
            } break;
            case Hint:
                {
                    if (IsKeyPressed(KEY_RIGHT) && sentence + 1 != 4) {sentence += 1;}
                    if (IsKeyPressed(KEY_LEFT) && sentence - 1 != 0) {sentence -= 1;}

                } break;
        
        }
        // Movement for player. Set to 5 speed

        if (!(playerPosition.x + 15 >= SCREEN_WIDTH) && !(playerPosition.y + 15 >= SCREEN_HEIGHT )){
            if (IsKeyDown(KEY_D)) playerPosition.x += 5.0f;
            if (IsKeyDown(KEY_S)) playerPosition.y += 5.0f;
        }
        if (!(playerPosition.x - 15 <= 0) && !(playerPosition.y - 15 <= 0)){
            if (IsKeyDown(KEY_A)) playerPosition.x -= 5.0f;
            if (IsKeyDown(KEY_W)) playerPosition.y -= 5.0f;
        }

        playerMouse.x = GetMouseX();
        playerMouse.y = GetMouseY();


        // Begin Drawing here
        // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        BeginDrawing();

            ClearBackground(BLACK);


            switch(currentscreen)
            {
            case Title:
                {
                    ClearBackground(BLACK);
                    DrawRectangleRec(playerMouse, RED);

                    for (int i = 0; i <= SCREEN_WIDTH - 400; i += 50){
                        DrawRectangleLines(SCREEN_WIDTH / 2 - 200 - i, SCREEN_HEIGHT/2 - 250 - i, 400 + (i*2), 400 + (i*2), BLUE);

                    }

                    // cout << MeasureTextEx(mechaFont, "yes", 20, 5).x;
                    DrawRectangle(SCREEN_WIDTH/2 - MeasureTextEx(mechaFont, "Survive And Collect", 50, 5).x/2 - 10, SCREEN_HEIGHT / 2 - 200, MeasureTextEx(mechaFont, "Survive And Collect", 50, 5).x + 20, 50, BLUE);
                    DrawTextEx(mechaFont, "Survive And Collect",(Vector2){SCREEN_WIDTH/2 - MeasureTextEx(mechaFont, "Survive And Collect", 50, 5).x/2, SCREEN_HEIGHT / 2 - 200}, 50.0, 5, WHITE);

                    DrawRectangleRec(playbutton, BLUE);
                    DrawTextEx(mechaFont, "Play", (Vector2){SCREEN_WIDTH/2 - MeasureTextEx(mechaFont,"Play", 20, 5).x/2, SCREEN_HEIGHT/2 - 100}, 20, 5, WHITE);

                    DrawRectangleRec(Hintbutton, BLUE);
                    DrawTextEx(mechaFont, "Hints",(Vector2){SCREEN_WIDTH/2 - MeasureTextEx(mechaFont, "Hints", 20, 5).x/2, SCREEN_HEIGHT/2}, 20, 5, WHITE);

                    DrawRectangleRec(Quitbutton, BLUE);
                    DrawTextEx(mechaFont, "Quit", (Vector2){SCREEN_WIDTH/2 - MeasureTextEx(mechaFont, "Quit", 20, 5).x/2, SCREEN_HEIGHT/2 + 100}, 20, 3, WHITE);
                    


                } break;
            case Scene1:
                {
                    ClearBackground(DARKGRAY);
                    drawguidelines(SCREEN_WIDTH, SCREEN_WIDTH);
                    DrawRectangleRec(playerMouse, RED);
                    DrawCircle(playerPosition.x, playerPosition.y, 15, VIOLET);

                    if (battle_state == 1) {

                        
                        for(int i = 0; i < 4; i++){
                            DrawCircle(enemies1[i] -> position.x, enemies1[i] -> position.y, enemies1[i] -> radius, enemies1[i] -> color);
                            DrawCircle(enemies2[i] -> position.x, enemies2[i] -> position.y, enemies2[i] -> radius, enemies2[i] -> color);
                        }

                        drawAllPoly(battle_state, rotation);
                    }
            
                    if (battle_state == 2) {

                        for(int i = 0; i < 4; i++){
                            DrawCircle(enemies1[i] -> position.x, enemies1[i] -> position.y, enemies1[i] -> radius, enemies1[i] -> color);
                            DrawCircle(enemies2[i] -> position.x, enemies2[i] -> position.y, enemies2[i] -> radius, enemies2[i] -> color);
                            DrawCircle(enemies3[i] -> position.x, enemies3[i] -> position.y, enemies3[i] -> radius, enemies3[i] -> color);
                            DrawCircle(enemies4[i] -> position.x, enemies4[i] -> position.y, enemies4[i] -> radius, enemies4[i] -> color);
                        }
                        drawAllPoly(battle_state, rotation);
                    }

                    if (battle_state == 3) {

                        drawAllPoly(battle_state, rotation);
                        for(int i = 0; i < 4; i++){
                            DrawCircle(enemies1[i] -> position.x, enemies1[i] -> position.y, enemies1[i] -> radius, enemies1[i] -> color);
                            DrawCircle(enemies2[i] -> position.x, enemies2[i] -> position.y, enemies2[i] -> radius, enemies2[i] -> color);
                            DrawCircle(enemies3[i] -> position.x, enemies3[i] -> position.y, enemies3[i] -> radius, enemies3[i] -> color);
                            DrawCircle(enemies4[i] -> position.x, enemies4[i] -> position.y, enemies4[i] -> radius, enemies4[i] -> color);
                            DrawCircle(enemies5[i] -> position.x, enemies5[i] -> position.y, enemies5[i] -> radius, enemies5[i] -> color);
                            DrawCircle(enemies6[i] -> position.x, enemies6[i] -> position.y, enemies6[i] -> radius, enemies6[i] -> color);
                        }

                        drawAllPoly(battle_state, rotation);
                    }        
                    drawPaper(num_papers, messages, SCREEN_WIDTH, mechaFont);

                    if (game_complete && !stop){

                        DrawRectangle(0, SCREEN_HEIGHT/2 - 100, SCREEN_WIDTH, 200, BLACK);
                        DrawTextEx(mechaFont, "You beat the Game.", (Vector2){SCREEN_WIDTH/2 - MeasureTextEx(mechaFont, "You beat the Game.", 50, 3).x/2 , SCREEN_HEIGHT/2 - 25.0}, 50, 3, WHITE);

                    }

                } break;
            case PlayAgain:
                {
                    ClearBackground(DARKGRAY); 
                    drawguidelines(SCREEN_WIDTH, SCREEN_HEIGHT);
                    DrawRectangle(0, SCREEN_HEIGHT/2 - 100, SCREEN_WIDTH, 200, BLACK);
                    DrawTextEx(mechaFont, "Game Over!! you were killed", (Vector2){SCREEN_WIDTH/2 - MeasureTextEx(mechaFont, "Game Over!! you were killed", 50, 5).x/2, SCREEN_HEIGHT/2 - 50.0}, 50.0, 5, RED);
                    DrawTextEx(mechaFont, "The link", (Vector2){SCREEN_WIDTH/2 - MeasureTextEx(mechaFont, "The link", 15.0, 3).x/2, SCREEN_HEIGHT/2 + 25}, 15.0, 3, DARKGRAY);
                    DrawTextEx(mechaFont, "Do you want to play again? [Y/N]", (Vector2){SCREEN_WIDTH/2 - MeasureTextEx(mechaFont, "Do you want to play again? [Y/N]", 20, 3).x/2, SCREEN_HEIGHT/2 + 50}, 20.0, 3, RED);
                    DrawRectangleRec(playerMouse, RED);
                    DrawCircle(playerPosition.x, playerPosition.y, 15, VIOLET);

                } break;

            case Hint:
                {
                    // for (int h = 0; h <= SCREEN_HEIGHT; h += 50){DrawLine(0, h, SCREEN_WIDTH, h, WHITE);}
                    switch (sentence)
                    {
                    case 1:
                        DrawTextEx(mechaFont, text, (Vector2) {50, 50} ,40, 3, RED);
                        break;
                    case 2:
                        DrawTextEx(mechaFont, text2, (Vector2) {20, 20} ,40, 2, RED);
                        break;
                    case 3:
                        DrawTextEx(mechaFont, text3, (Vector2) {50, 50} ,40, 3, RED);
                        break;
                    } break;
                } break;
            }

            //  message to exit the game
            if (exitWindowRequested)
            {
                DrawRectangle(0, 100, SCREEN_WIDTH, 200, BLACK);
                DrawText("Are you sure you want to exit? [Y/N]", SCREEN_WIDTH/4, SCREEN_HEIGHT/6, 30, WHITE);
            }

        EndDrawing();
    }

        UnloadFont(mechaFont);
        CloseWindow();

    return 0;
}