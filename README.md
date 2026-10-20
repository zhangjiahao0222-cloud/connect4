# Connect 4 in C

A two-player Connect 4 game written in plain C for CSCE Laboratory A
(Algorithms and Data Structures PBL). Four people, one part each.

**Play it in the browser:** open `index.html`, or visit the GitHub Pages site of this repository.

## Run it in a terminal

```
gcc */*.c -o connect4 && ./connect4
```

`*/*.c` compiles every `.c` file in every folder, so all four parts are built together.

## Folders = team parts

| Folder | File | Part | What it does |
|---|---|---|---|
| `UI/` | `ui.c` | Part 1: UI | menu, printing the board, reading numbers and names, checking the column input |
| `BasicFunction/` | `game.c` | Part 2: Basic Function | the board, dropping a piece, checking four in a row, full board |
| `ScoreRanking/` | `rank.c` | Part 3: Score Ranking | win = 3 points, draw = 1 point, bubble sort, printing the ranking |
| `Other/` | `main.c`, `common.h` | Part 4: Other | main menu, game loop, shared definitions |

## Rules

- 7 columns × 6 rows. Player 1 is `O`, player 2 is `X`.
- Choose a column; the piece falls to the lowest empty cell.
- Four in a row horizontally, vertically or diagonally wins. A full board is a draw.
- Wrong input (letters, numbers outside 1–7, a full column) is rejected and asked again.

## How the web version works

`index.html` runs the same four C files compiled to WebAssembly (see `web/build.sh`).
`web/libc.c` supplies only `printf`, `scanf` and `getchar` for the browser, so all game
rules, messages and scores come from the C code.
