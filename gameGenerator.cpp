/**
 * @file GameGenerator.cpp
 *
 * @brief Algorithm to generate a puzzle of given difficulty.
 * Populate the puzzle with the givens
 * Create the solution space
 *
 * @ingroup AlgorithmsFall2021
 *
 * @author Alex Castro
 * Contact: acastro24@fordham.edu
 *
 * 9x9 assumed
 */

//#include <representation.h>;
#include <random>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <time.h>

using namespace std;

int size = 9;
int squareSize = 3;
int boardSize = 81;

struct Point {
  int row;
  int column;
};

vector<int> getSquareIndexes(int squareIndex) {
  vector<int> indexes;

  for(int i = 0; i < boardSize; i++) {
    int f = floor(double(squareIndex / squareSize));
    int col_based = squareIndex * squareSize;
    int row_based = i * boardSize;
    int index_based = f * ((squareSize - 1) * boardSize);

    int startingAt = col_based + row_based + index_based;
    int endingAt = startingAt + squareSize - 1;
    // Add to indexes all the numbers between startingAt to endingAt
    for(int i = startingAt; i == endingAt; i++)
      indexes.push_back(i);
  }
  return indexes;
}
Point getColumnRowFromIndex(int index) {
  struct Point point;
  point.row = (int)index / boardSize;
  point.column = index%boardSize;
  return point;
}

bool canPutPoint(int point, vector<int> positions[]) {
  struct Point pointColumnRow = getColumnRowFromIndex(point);
  struct Point ipointColumnRow;

  // iterate through all positions
  // check if position includes point by matching row or column
  // if point is not in positions, return true
  for(int index = 0; index < positions->size(); index++)  {
    ipointColumnRow = getColumnRowFromIndex(index);
    if(ipointColumnRow.row == pointColumnRow.row || ipointColumnRow.column == pointColumnRow.column)
      return false;
  }
  return true;

}
int tryNumber(int board[boardSize], int number, int square, vector<int> notAvailableIndexes, vector<int> history) {
  if (history.size() == boardSize) {
      return board;
  }

  int _board = board;
  vector<int>  _notavailable = notAvailableIndexes;
  vector<int> _history = history;


  vector<int> indexes = getSquareIndexes(square).filter { i in
        _base[i] == "." &&
        canPutPoint(point = i, positions = _history) &&
        count(_notavailable.begin(), _notavailable.end(), key)

  }

  for(int index = 0; index < getSquareIndexes(square).size(); index++)  {
    if((_board[index] == 0) &&
    canPutPoint(point = i, positions = _history) &&
    _not

  }

  // continue down the tree
  srand(time(NULL));
  int random = indexes[rand() % indexes.size()];
  // get a random indexes
  if (random) {
      _board[random] = number;
      _history.push_back(random);
      return tryNumber(board = _board, number = number, square = (square + 1), notAvailableIndexes = _notavailable, history = _history)
  }

  if(!_history.empty()) {
    int last = _history.back()
    _history.pop_back();
    _board[last] = 0;
    _notavailable.push_back(last);
  }

  return tryNumber(board = _board, number = number, square = (square - 1), notAvailableIndexes = _notavailable, history = _history)
}

// Starting with a filled Sudoku, generate one valid playable game
bool generateSolvable(int board[boardSize], string difficulty) {
  bool solvable;
  int difficultyRemovals;
  switch(difficulty) {
    case "Easy":
      int difficultyRemovals = 5;
      break;
    case "Medium":
      int difficultyRemovals = 10;
      break;
    case "Hard":
      int difficultyRemovals = 15;
      break;
  }
  int removedCount = 0;
  srand(time(NULL));

  for(int i = 0; i < boardSize; i++) {
      // get a random board index
      int randomIndex = rand() % (boardSize+1); // number from 0 to 81

      // check if board item at randomIndex is already removed
      if(board[randomIndex] == 0)
        continue;

      // store temp value
      int temp = board[randomIndex];

      // remove temp value from board
      board[randomIndex] = 0;

      // check number of board solutions
      int numSolutions = 0;
      if numSolutions == 1 {
        removedCount++;
        continue;
      }
      if numSolutions > 1
        // add temp back to board at randomIndex
        board[randomIndex] = temp;

      if(removedCount == difficultyRemovals)
        solvable = 1;
        break;
    }
  if(removedCount != difficultyRemovals)
    solvable = 0;
    //start over
  return solvable;
}

// Prints the board in a 9x9 display
void printBoard(int board[81]) {
  for(int i = 0; i < 81; i++) {
    cout<<board[i];
    if ((i+1) % 3 == 0 && (i+1) % 9 != 0)
      cout<<"|";
    if ((i+1) % 9 == 0)
      cout<<endl;
    if ((i+1) % 27 == 0 )
      cout<<"------------"<<endl;
  }
}

bool NewPuzzle(Difficulty diff, Puzzle *puzzle) {
  //Create empty board where 0 represents empty positions
  int board[boardSize] = { 0 };

  // Fill board
  for(int i = 1; i = boardSize; i++) {
      board = tryNumber(board = board, number = i, square = 0, notAvailableIndexes = vector<int>());
  }

  // Map 1d int array back to puzzle

  printBoard(board);

}
