#include<stdio.h>
#include<string.h>
#include <stdbool.h>

// ボードの状態を表すenum
typedef enum Cell {
  Blank,
  Black,
  White,
} Cell;

void getEnableCells(bool, Cell[2][2], int[2][81]);
bool existEnableCells(int[2][81]);
bool fillBoard(Cell[2][2]);
void finishGame(Cell[2][2]);
bool isOneColor(Cell[2][2]);
void inputCell(int[2]);
bool canPut(int[2], int[2][81]);
void reverse(bool, int[2], Cell[2][2]);
void displayBoard(Cell[2][2]);

int main() {
  // ボードの初期状態
  Cell board[2][2] = {
    {Blank, Blank},
    {Black, White}
  };

  // TODO: 初期状態の表示

  // TODO: 先行後攻の選択の処理
  bool isFirst = true;
  bool isAI = true;

  while(true) {
    // TODO: enableCellsの初期化
    int enableCells[2][81];
    getEnableCells(isFirst, board, enableCells);

    if(!existEnableCells(enableCells)) {
      if(fillBoard(board)){
        finishGame(board);
        return 0;
      }
      if (isOneColor(board)) {
        finishGame(board);
        return 0;
      }
      // passの処理
      isAI = !isAI;
      isFirst = !isFirst;
    }

    int selectedCell[2] = {-1, -1};
    if(isAI){
      //sugoiAlgorithm();
      isAI = !isAI;
      isFirst = !isFirst;
    } else {
      inputCell(selectedCell);
      if (canPut(selectedCell, enableCells)) { // 置けない場所を選択していたらisAIフラグを変えずにもう一回ループしてもらう
        isAI = !isAI;
        isFirst = !isFirst;
      } 
    }

    reverse(isFirst, selectedCell, board);
    displayBoard(board);
  }

  return 0;
}

void getEnableCells(bool isFirst, Cell board[2][2], int enableCells[2][81]) {
  // TODO: 置くことのできるcellのindexを返す
  // e.g. (1, a), (2, d) のマスが置けるなら[[2, 0], [3, 3]]
}

bool existEnableCells(int enableCells[2][81]) {
  // TODO: 置ける場所が存在したらtrue
  return true;
}

bool fillBoard(Cell board[2][2]) {
  // TODO: ボードが埋まっていたらtrue
  return true;
}

void finishGame(Cell board[2][2]) {
  // TODO: ゲームの勝敗判定を行う
}

bool isOneColor(Cell board[2][2]) {
  // TODO: cellが一色だけのときtrue
  return true;
}

void inputCell(int selectedCell[2]){
  // TODO: ユーザから標準入力でcellのindexを受け取る
  // e.g. (3, b)を選択したなら[4, 3]
  selectedCell[0] = 4;
  selectedCell[1] = 3;
}

bool canPut(int selectedCell[2], int enableCells[2][81]) {
  // TODO: enableCellsにselectedCellが含まれていたらtrue
  return true;
}

void reverse(bool isFirst, int selectedCell[2], Cell board[2][2]) {
  // TODO: selectedCellの場所に置き、boardを更新する
}

void displayBoard(Cell board[2][2]) {
  // TODO: 盤面を標準出力する
}
