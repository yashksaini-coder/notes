#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <locale.h>
#include <string.h>

#define DEFAULT_AGENTS 5
#define DELAY_US 25000
#define COVER_THRESHOLD 0.5

typedef struct {
    int y, x;
    int dy, dx;
    int color;
} Agent;

static const int dirs[4][2] = {
    {1, 0}, {-1, 0}, {0, 1}, {0, -1}
};

const char *pick_char(int dy, int dx, int ndy, int ndx) {
    if ((dy == 0 && dx == 1 && ndy == 0 && ndx == 1) ||
        (dy == 0 && dx == -1 && ndy == 0 && ndx == -1))
        return "─";

    if ((dy == 1 && dx == 0 && ndy == 1 && ndx == 0) ||
        (dy == -1 && dx == 0 && ndy == -1 && ndx == 0))
        return "│";

    if ((dy == 0 && dx == 1 && ndy == 1 && ndx == 0) ||
        (dy == -1 && dx == 0 && ndy == 0 && ndx == -1))
        return "┐";

    if ((dy == 0 && dx == 1 && ndy == -1 && ndx == 0) ||
        (dy == 1 && dx == 0 && ndy == 0 && ndx == -1))
        return "┘";

    if ((dy == 0 && dx == -1 && ndy == 1 && ndx == 0) ||
        (dy == -1 && dx == 0 && ndy == 0 && ndx == 1))
        return "┌";

    if ((dy == 0 && dx == -1 && ndy == -1 && ndx == 0) ||
        (dy == 1 && dx == 0 && ndy == 0 && ndx == 1))
        return "└";

    return dy ? "│" : "─";
}

void reset_screen(Agent *agents, int AGENTS, int *h, int *w,
                  int *cy, int *cx, char **visited,
                  int *filled, int *total_cells,
                  int color_count)
{
    clear();
    getmaxyx(stdscr, *h, *w);

    *total_cells = (*h) * (*w);

    char *tmp = realloc(*visited, *total_cells);
    if (!tmp) return;
    *visited = tmp;

    memset(*visited, 0, *total_cells);
    *filled = 0;

    *cy = *h / 2;
    *cx = *w / 2;

    for (int i = 0; i < AGENTS; i++) {
        agents[i].y = *cy;
        agents[i].x = *cx;

        const int *d = dirs[rand() % 4];
        agents[i].dy = d[0];
        agents[i].dx = d[1];
        agents[i].color = (i % color_count) + 1;
    }
}

int main(int argc, char **argv) {
    setlocale(LC_ALL, "");

    int AGENTS = DEFAULT_AGENTS;
    if (argc > 1) {
        int n = atoi(argv[1]);
        if (n > 0 && n <= 2000)
            AGENTS = n;
    }

    initscr();
    noecho();
    curs_set(0);
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);

    start_color();
    use_default_colors();

    int colors[] = {
        COLOR_RED, COLOR_GREEN, COLOR_YELLOW,
        COLOR_BLUE, COLOR_MAGENTA, COLOR_CYAN,
        COLOR_WHITE
    };

    int color_count = sizeof(colors) / sizeof(colors[0]);

    for (int i = 0; i < color_count; i++)
        init_pair(i + 1, colors[i], -1);

    int h, w;
    int cy, cx;
    int total_cells;
    int filled = 0;

    char *visited = NULL;

    Agent *agents = malloc(sizeof(Agent) * AGENTS);
    if (!agents) {
        endwin();
        return 1;
    }

    srand(time(NULL));

    reset_screen(
        agents, AGENTS,
        &h, &w,
        &cy, &cx,
        &visited,
        &filled,
        &total_cells,
        color_count
    );

    while (1) {
        int ch = getch();
        if (ch != ERR)
            break;

        for (int i = 0; i < AGENTS; i++) {
            Agent *a = &agents[i];

            int ndy, ndx;
            while (1) {
                const int *d = dirs[rand() % 4];
                ndy = d[0];
                ndx = d[1];
                if (!(ndy == -a->dy && ndx == -a->dx))
                    break;
            }

            const char *pipe = pick_char(a->dy, a->dx, ndy, ndx);

            attron(COLOR_PAIR(a->color));
            mvaddstr(a->y, a->x, pipe);
            attroff(COLOR_PAIR(a->color));

            int idx = a->y * w + a->x;
            if (!visited[idx]) {
                visited[idx] = 1;
                filled++;
            }

            if (filled >= (int)(total_cells * COVER_THRESHOLD)) {
                reset_screen(
                    agents, AGENTS,
                    &h, &w,
                    &cy, &cx,
                    &visited,
                    &filled,
                    &total_cells,
                    color_count
                );
                break;
            }

            a->y = (a->y + ndy + h) % h;
            a->x = (a->x + ndx + w) % w;

            a->dy = ndy;
            a->dx = ndx;
        }

        refresh();
        usleep(DELAY_US);
    }

    free(visited);
    free(agents);
    endwin();
    return 0;
}
