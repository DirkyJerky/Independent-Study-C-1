#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_BUF 512

int kbhit(void) { // http://cboard.cprogramming.com/c-programming/63166-kbhit-linux.html#post449301
    struct termios oldt, newt;
    int ch;
    int oldf;
 
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
 
    ch = getchar();
 
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);  
    fcntl(STDIN_FILENO, F_SETFL, oldf);
 
    if(ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }
 
    return 0;
}

int main(int argc, char *argv[]) {
    while(!kbhit()) { 
	  printf(".");
          usleep(100 * 1000);
    }
    printf("\n");
}
