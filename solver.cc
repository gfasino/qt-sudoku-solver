#include "solver.h"
#include <queue>

sudokumatrix solver::solve(sudokumatrix* start){
  std::queue<sudokumatrix*> work;
  work.push(start);
  do {
    std::vector<sudokumatrix*> get = work.front()->getNewMatices();
    for (const auto& e: get)
      work.push(e);
    if(!work.front()->isFree()){
      return sudokumatrix(*work.front());
    }
    //delete work.front() //does give error
    work.pop();
  }while(work.front());

  return sudokumatrix(*start);
}
