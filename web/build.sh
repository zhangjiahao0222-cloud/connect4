#!/bin/sh
cd "$(dirname "$0")/.."
clang --target=wasm32 -O2 -nostdlib -isystem web \
  -Wl,--no-entry -Wl,--export=main -Wl,-z,stack-size=65536 \
  UI/ui.c BasicFunction/game.c ScoreRanking/rank.c Other/main.c web/libc.c \
  -o web/connect4.wasm
echo "built web/connect4.wasm (embed it in index.html as base64)"
