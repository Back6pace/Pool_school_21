#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define X_AXE 80
#define Y_AXE 25
int numberOfneighbours(int matrice[][X_AXE], int y, int x);
int topNeighbour(int matrice[][X_AXE], int y, int x);
int topRightNeighbour(int matrice[][X_AXE], int y, int x);
int topLeftNeighbour(int matrice[][X_AXE], int y, int x);
int bottomNeighbour(int matrice[][X_AXE], int y, int x);
int bottomRightNeighbour(int matrice[][X_AXE], int y, int x);
int bottomLeftNeighbour(int matrice[][X_AXE], int y, int x);
int rightNeighbour(int matrice[][X_AXE], int y, int x);
int leftNeighbour(int matrice[][X_AXE], int y, int x);
void cellNextLife(int oldMatrice[][X_AXE], int newMatrice[][X_AXE], int y_cell, int x_cell);
void nextGeneratino(int oldMatrice[][X_AXE], int newMatrice[][X_AXE]);
int initialFromFile(int matrice[][X_AXE], char* filename);
void copyMatrice(int matrice[][X_AXE], int newMatrice[][X_AXE], int y_size, int x_size);
void outputMatrice(int matrice[][X_AXE], int y_axe, int x_axe);

int main(int argc, char* argv[]) {
    int firstGeneration[Y_AXE][X_AXE];
    char* filename = "fir_gen.txt";  // if no file mode chosen

    // if you add file mode after ./a.out [...]
    if (argc == 2) {
        switch ((char)(*argv[1])) {
            case '2':
                filename = "sec_gen.txt";
                break;
            case '3':
                filename = "fird_gen.txt";
                break;
            case '4':
                filename = "four_gen.txt";
                break;
            case '5':
                filename = "five_gen.txt";
                break;
        }
    }
    // if read file is true
    if (initialFromFile(firstGeneration, filename)) {
        int delay = 80000;
        initscr();
        cbreak();  // don't interrupt for user input

        clear();
        outputMatrice(firstGeneration, Y_AXE, X_AXE);
        // timeout(10);  // wait 500ms for key press
        refresh();
        char c = ' ';

        while (c != 'q') {
            int newGeneration[Y_AXE][X_AXE];
            nodelay(stdscr, true);
            c = getch();
            noecho();
            nextGeneratino(firstGeneration, newGeneration);

            if (c == '+') {
                if (delay > 10000) {
                    delay -= 10000;
                }
            }
            if (c == '-') {
                if (delay < 200000) {
                    delay += 10000;
                }
            }

            usleep(delay);

            clear();
            outputMatrice(newGeneration, Y_AXE, X_AXE);

            refresh();
            copyMatrice(newGeneration, firstGeneration, Y_AXE, X_AXE);
        }
        endwin();
    } else
        printf("n/a");

    return 0;
}

int initialFromFile(int matrice[][X_AXE], char* filename) {
    FILE* inputStream = fopen(filename, "r");
    char line[81];
    int i = 0, j = 0, valid = 1;

    while (valid && i < Y_AXE && fscanf(inputStream, "%80s", line) == 1) {
        while (line[j] != '\0' && valid) {
            if (line[j] == '1')
                matrice[i][j] = 1;
            else if (line[j] == '0')
                matrice[i][j] = 0;
            else
                valid = 0;
            j++;
        }
        if (j != 80)
            valid = 0;
        else {
            j = 0;
        }
        i++;
    }
    // if there is probleme  with the file (size not respected 25x80)
    if (fscanf(inputStream, "%80s", line) != EOF || i != 25) {
        valid = 0;
    }
    fclose(inputStream);
    return valid;
}

void nextGeneratino(int oldMatrice[][X_AXE], int newMatrice[][X_AXE]) {
    for (int i = 0; i < Y_AXE; i++)
        for (int j = 0; j < X_AXE; j++) cellNextLife(oldMatrice, newMatrice, i, j);
}

void copyMatrice(int matrice[][X_AXE], int newMatrice[][X_AXE], int y_size, int x_size) {
    for (int i = 0; i < y_size; i++)
        for (int j = 0; j < x_size; j++) newMatrice[i][j] = matrice[i][j];
}
void cellNextLife(int oldMatrice[][X_AXE], int newMatrice[][X_AXE], int y_cell, int x_cell) {
    int num_neighbours = numberOfneighbours(oldMatrice, y_cell, x_cell);
    if (oldMatrice[y_cell][x_cell] == 1 && (num_neighbours < 2 || num_neighbours > 3)) {
        newMatrice[y_cell][x_cell] = 0;
    } else if (oldMatrice[y_cell][x_cell] == 0 && num_neighbours == 3)
        newMatrice[y_cell][x_cell] = 1;
    else
        newMatrice[y_cell][x_cell] = oldMatrice[y_cell][x_cell];
}
void outputMatrice(int matrice[][X_AXE], int y_axe, int x_axe) {
    for (int i = 0; i < y_axe; i++) {
        for (int j = 0; j < x_axe; j++) {
            if (matrice[i][j])
                printw("@");
            else
                printw(" ");
        }
        if (i < y_axe - 1) printw("\n");
    }
}
int numberOfneighbours(int matrice[][X_AXE], int y, int x) {
    return topNeighbour(matrice, y, x) + topRightNeighbour(matrice, y, x) + topLeftNeighbour(matrice, y, x) +
           bottomNeighbour(matrice, y, x) + bottomRightNeighbour(matrice, y, x) +
           bottomLeftNeighbour(matrice, y, x) + rightNeighbour(matrice, y, x) + leftNeighbour(matrice, y, x);
}

int topNeighbour(int matrice[][X_AXE], int y, int x) {
    int life;
    if (y == 0) {
        life = matrice[24][x];
    } else
        life = matrice[y - 1][x];
    return life;
}

int topRightNeighbour(int matrice[][X_AXE], int y, int x) {
    int life;
    if (y == 0 || x == 79) {
        if (y == 0 && x == 79)
            life = matrice[24][0];
        else if (y == 0)
            life = matrice[24][x + 1];
        else
            life = matrice[y - 1][0];

    } else
        life = matrice[y - 1][x + 1];
    return life;
}
int topLeftNeighbour(int matrice[][X_AXE], int y, int x) {
    int life;
    if (y == 0 || x == 0) {
        if (y == 0 && x == 0)
            life = matrice[24][79];
        else if (y == 0)
            life = matrice[24][x - 1];
        else
            life = matrice[y - 1][79];

    } else
        life = matrice[y - 1][x - 1];
    return life;
}
int bottomNeighbour(int matrice[][X_AXE], int y, int x) {
    int life;
    if (y == 24) {
        life = matrice[0][x];
    } else
        life = matrice[y + 1][x];
    return life;
}
int bottomRightNeighbour(int matrice[][X_AXE], int y, int x) {
    int life;
    if (y == 24 || x == 79) {
        if (y == 24 && x == 79)
            life = matrice[0][0];
        else if (y == 24)
            life = matrice[0][x + 1];
        else
            life = matrice[y - 1][0];

    } else
        life = matrice[y + 1][x + 1];
    return life;
}
int bottomLeftNeighbour(int matrice[][X_AXE], int y, int x) {
    int life;
    if (y == 24 || x == 0) {
        if (y == 24 && x == 0)
            life = matrice[0][79];
        else if (y == 24)
            life = matrice[0][x - 1];
        else
            life = matrice[y + 1][79];

    } else
        life = matrice[y + 1][x - 1];
    return life;
}
int rightNeighbour(int matrice[][X_AXE], int y, int x) {
    int life;
    if (x == 79) {
        life = matrice[y][0];
    } else
        life = matrice[y][x + 1];
    return life;
}

int leftNeighbour(int matrice[][X_AXE], int y, int x) {
    int life;
    if (x == 0) {
        life = matrice[y][79];
    } else
        life = matrice[y][x - 1];
    return life;
}
