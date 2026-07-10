# Console Tic-Tac-Toe Game (C++)

A lightweight, feature-rich terminal implementation of the classic Tic-Tac-Toe game written in modern C++. The application offers local head-to-head matching as well as an autonomous single-player engine.

---

## Features

- **Dual Gameplay Modes**:
  - **Two-Player Local Mode**: Pass the keyboard back and forth to compete with a friend locally.
  - **Single-Player Mode**: Pit your skills against a randomized AI opponent.
- **Smart Turn Validation**: Complete bound-checking and spot-occupancy validation prevents accidental overwrites or invalid moves.
- **Persistent Game Cycle**: Includes an endgame loop prompt asking users if they would like to exit or restart a fresh session without restarting the application.
- **No-Disappear Close Protection**: Configured with explicit input-buffer tracking so that compiled binaries (`.exe`) won't snap-shut immediately upon game termination.

---

## Code Architecture

The source code is modularly structured around deterministic operational states:

* `initializeBoard()`: Resets the $3 \times 3$ matrix dynamically using empty character space arrays (`' '`).
* `printBoard()`: Draws an interactive grid UI directly into the console boundary map using custom layout borders.
* `isWinner(char player)`: Sequentially monitors horizontal rows, vertical columns, and intersecting diagonal nodes to detect a winning pattern match.
* `isBoardFull()`: Analyzes if all 9 cells are filled to catch a clean stalemate draw.
* `playerMove(char player)`: Manages input loop traps validation for coordinates $(0-2)$ from a human user.
* `aiMove()`: Seeds time-randomized integers to trigger computational board decisions.

---

## How to Run

Just download the exe and you are good to go !
