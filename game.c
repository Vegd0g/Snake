#include"snake.h"
#include"game_setup.h"

int score = 0;
int kx = 0;
int ky = 0;

void playGame() {
    char key = 'd';
    while (snake.body[0].x >= 0 && snake.body[0].x < LENGTH &&
        snake.body[0].y >= 0 && snake.body[0].y < WIDE) {
        Sleep(100);  // 控制蛇的移动速度
        if (_kbhit()) {
            key = _getch();
        }
        switch (key) {
        case 'w': kx = 0; ky = -1; break;
        case 's': kx = 0; ky = +1; break;
        case 'd': kx = +1; ky = 0; break;
        case 'a': kx = -1; ky = 0; break;
        default: break;
        }

        // 保存旧的蛇尾位置
        int oldTailX = snake.body[snake.curSize - 1].x;
        int oldTailY = snake.body[snake.curSize - 1].y;

        for (size_t i = snake.curSize - 1; i > 0; i--) {
            snake.body[i].x = snake.body[i - 1].x;
            snake.body[i].y = snake.body[i - 1].y;
        }

        snake.body[0].x += kx;
        snake.body[0].y += ky;

        // 检查是否吃到食物
        if (snake.body[0].x == food.x && snake.body[0].y == food.y) {
            snake.curSize++;
            initFood();
            score += 10;
            // 添加新的蛇尾位置
            snake.body[snake.curSize - 1].x = oldTailX;
            snake.body[snake.curSize - 1].y = oldTailY;
        }
        else {
            // 用空格覆盖旧的蛇尾位置
            COORD oldTailCoord = { oldTailX, oldTailY };
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), oldTailCoord);
            putchar(' ');
        }

        // 绘制新的蛇头和食物
        initUI();

        // 检查是否撞到自己
        for (size_t i = 1; i < snake.curSize; i++) {
            if (snake.body[0].x == snake.body[i].x && snake.body[0].y == snake.body[i].y) {
                return;
            }
        }

        // 检查是否撞到边界
        if (snake.body[0].x < 0 || snake.body[0].x >= LENGTH || snake.body[0].y < 0 || snake.body[0].y >= WIDE) {
            return;
        }
    }
}


void gameOver() {
    system("cls");
    printf
       ("             ____   \n"
        "Game over!  / . .\\ \n"
        "            \\  ---<\n"
        "             \\  /  \n"
        "   __________/ /    \n"
        "-=:___________/\n");
    printf("\nYour scores:%d\n", score);
     
}