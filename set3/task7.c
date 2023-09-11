#include <assert.h>
#include <stdio.h>

void drawField(unsigned int n,unsigned int pacman_x,unsigned int pacman_y) {
    assert(n >= 2);
    assert(0 <= pacman_x && pacman_x <= n);
    assert(0 <= pacman_y && pacman_y <= n);

    for (unsigned int y = 1; y <= n; y++) {
        for (unsigned int x = 1; x <= n; x++)
            if (x == pacman_x && y == pacman_y)
                printf("<");
            else if (x == n && y == n )
                printf("#");
            else
                printf(".");
        printf("\n");
    }
};

int constrain(int n, int l, int r) {
    if (n < l)
        n = l;
    if (n > r)
        n = r;
    return n;
}

int main() {
    unsigned int n;
    scanf("%u", &n);
    if (n < 2) {
        printf("invalid field size\n");
        return 1;
    }
    unsigned int pacman_x = 1, pacman_y = 1, score = 0;
    do {
        drawField(n, pacman_x, pacman_y);
        unsigned int command;
        scanf("%u", &command);
        if (command == 4) 
            pacman_x = constrain(pacman_x - 1, 1, n);
        else if (command == 6) 
            pacman_x = constrain(pacman_x + 1, 1, n);
        else if (command == 5) 
            pacman_y = constrain(pacman_y + 1, 1, n);
        else if (command == 8) 
            pacman_y = constrain(pacman_y - 1, 1, n);
        else {
            printf("invalid command");
            return 1;
        }
        score += 1;
    } while (!(pacman_x == n && pacman_y == n));
    printf("Your score: %u\n", score);
    return 0;
}
