# Snake
                     ____   
            Hey!    / . .\\ 
                    \\  ---<
                     \\  /  
           __________/ /    
        -=:___________/
基于Brown csci0300课程的project1，实现贪吃蛇游戏
### 项目结构
`snake.h`: 包含结构体蛇，蛇身，食物的定义等.  
`game_setup.h`: 包含头文件引用以及用于初始化游戏的函数声明.  
`game_setup.c`: 游戏墙，食物，蛇等的初始化以及绘制函数.  
`game.c`: 游戏逻辑函数.   
`main.c`:执行程序.  
### 实现细节  
1，使用`COORD`和函数`SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord)`来控制光标位置,进行蛇的重画与移动.  
2，使用`kbhit`非阻塞判断用户输入，`getch`不回显获取用户输入.  
3，使用`Sleep()`控制蛇移动速度.

[注]没有全按照课程给出的结构来实现程序，有DTY
