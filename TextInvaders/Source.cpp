#include "curses.h"
#include "TIFuncs.h"
#include "TextInvaders.h"
#include <ctime>

const int FPS = 30;
const int TPF = CLOCKS_PER_SEC / FPS;



int main()
{
    Player player;

    InitPlayer(player);
	int input;

    initscr();                            /* Start curses mode */
    keypad(stdscr, true);
	nodelay(stdscr, true);
	noecho();
	curs_set(false);

    clock_t curTime = clock();
    clock_t newTime;
    clock_t dt;

    while (true)
    {
        newTime = clock();
        dt = newTime - curTime;

        if (dt > TPF)
        {
            curTime = newTime;
            input = getch();
            PlayerInput(player, input);
            UpdateMissile(player);
			clear();
		    DrawPlayer(player);
            refresh();

        }

    }
    
    getch();                      /* Wait for user input */
    endwin();                     /* End curses mode */

    return 0;
}

