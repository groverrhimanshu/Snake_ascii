#include<iostream>
#include<random>
#include<conio.h>



bool gameOver;
int width = 20;
int height = 20;


int x, y, foodx, foody, score;

int tail =1;
int tailX[100], tailY[100];

enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };

eDirection dir;

/*
setup
draw
input
logic
*/
void setup()
{
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;

    foodx = rand() % width;
    foody = rand() % height;

    score = 0;



}

void Draw()
{
    system("cls");

    for (int i = 0; i < width + 2; i++)
        std::cout << "#";
    std::cout << "\n";

    for (int i = 0; i < height; i++)
    {

        for (int j = 0; j < width; j++)
        {
            if (j == 0)
                std::cout << "#";

            if (i == y && j == x)
            {
                switch (dir)
                {
                case LEFT: std::cout << "<";
                    break;
                case RIGHT: std::cout << ">";
                    break;
                case UP: std::cout << "^";
                    break;
                case DOWN: std::cout << "V";
                    break;
                default: std::cout << "O";
                }

            }

            else if (i == foody && j == foodx)
                std::cout << "@";

            else
            {


                bool print = false;

                for (int k = 0; k < tail; k++)
                {


                    if (tailX[k] == j && tailY[k] == i)
                    {
                        std::cout << "o";
                        print = true;


                    }

                }
                if (!print)
                {
                    std::cout << " ";
                }

            }
            if (j == width - 1)
                std::cout << "#";

        }
        std::cout << "\n";
    }

    for (int i = 0; i < width; i++)
    {
        std::cout << "#";
    }

}

void Input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            dir = LEFT;
            break;

        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'x':
            gameOver = true;
            break;
        }
    }

}

void Logic()
{


    tailX[0] = x;
    tailY[0] = y;

    for (int i = tail; i >= 0; i--)
    { /*
        Prev2X= tailX[i];
        Prev2Y= tailY[i];

        tailX[i] = PrevX;
        tailY[i] = PrevY;

        PrevX = Prev2X;
        PrevY = Prev2Y;
*/
        tailX[i] = tailX[i - 1];
        tailY[i] = tailY[i - 1];

    }

    switch (dir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case DOWN:
        y++;
        break;
    case UP:
        y--;
        break;


    }


    if (x < 0)
    {
        x = width-1;

    }
    if (y < 0)
    {
        y = height - 1;

    }
    if (x > width)
    {
        x = 0;

    }
    if (y > height)
    {
        y = 0;
    }
    if (x == foodx && y == foody)
    {

        tail++;
        score += 10;
        foodx = rand() % width;
        foody = rand() % height;
    }


}

int main()
{


    setup();

    while (!gameOver)
    {
        Draw();
        Input();
        Logic();
        std::cout <<"\n"<< "Score: " << score << std::endl;
    }

    return 0;
}
