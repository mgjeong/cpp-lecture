/**************************************************
 *  @file       Uilt.c
 *  @author     mg.jeong
 **************************************************/

#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include "Util.h"

int getch( void )
{
    struct termios oldt, newt;
    int ch;

    tcgetattr( STDIN_FILENO, &oldt );
    newt = oldt;
    newt.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newt );
    ch = getchar( );
    tcsetattr( STDIN_FILENO, TCSANOW, &oldt );

    return ch;
}

