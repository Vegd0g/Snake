#include"snake.h"
#include"game_setup.h"

int main() {
    srand(time(NULL));
    gameStart();
    initWall();
    initSnake();
    initFood();
    playGame();
    Sleep(1000);
    gameOver();
    
    
}

//非阻塞判断用户输入kbhit   不回显getch





