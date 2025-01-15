#pragma once

#define WIDE 30
#define LENGTH 50

struct BODY {
    int x, y;
};

struct SNAKE {
    struct BODY body[LENGTH * WIDE];
    int curSize;
} snake;

struct FOOD {
    int x, y;
} food;

 