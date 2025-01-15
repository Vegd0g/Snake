#include"snake.h"
#include"game_setup.h"

void gameStart() {
	printf(
		"             ____   \n"
		"Hello       / . .\\ \n"
		"player!     \\  ---<\n"
		"             \\  /  \n"
		"   __________/ /    \n"
		"-=:___________/\n");
	printf("\nPress 'w/a/s/d' to change the direction.\n");
	printf("\nDo not eat yourself or touch the wall.\n");
	printf("\nPress 'Enter' to start the game!:");
	char input = getch();
	if (input = "\n") {
		system("cls");
		return;
	}

		
}

void initSnake() {
	snake.curSize = 4;
	snake.body[0].x = LENGTH / 2;
	snake.body[0].y = WIDE / 2;
	snake.body[1].x = LENGTH / 2 - 1;
	snake.body[1].y = WIDE / 2;
}

void initFood() {
	food.x = rand() % LENGTH;
	food.y = rand() % WIDE;
}

void initWall() {
	for (size_t i = 0; i <=WIDE; i++) {
		for (size_t j = 0; j <=LENGTH; j++) {
			if (j == LENGTH) {
				printf("|");
			}else if (i == WIDE) {
				printf("-");
			}else {
				printf(" ");
			}
		}
		printf("\n");
	}
}

void initUI() {
	COORD coord = { 0 };
	//绘制新的蛇身
	for (size_t i = 0; i < snake.curSize; i++) {
		coord.X = snake.body[i].x;
		coord.Y = snake.body[i].y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		putchar('*');
	}
	// 绘制食物
	coord.X = food.x;
	coord.Y = food.y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	putchar('#');
}





