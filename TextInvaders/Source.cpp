#include "curses.h"
#include "TIFuncs.h"
#include "TextInvaders.h"


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

    while (true)
    {
		input = getch();
        PlayerInput(player, input);
		clear();
        DrawSprite(player.sprites[0], player.pos);
    }
    
    getch();                      /* Wait for user input */
    endwin();                     /* End curses mode */

    return 0;
}

