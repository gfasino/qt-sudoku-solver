#include "sudokumatrix.h"

sudokumatrix::sudokumatrix(const short int mat_[9][9]) {
  for(int i=0;i<9;i++)
    for (int j = 0; j < 9; j++)
      mat[i][j] = mat_[i][j];
}

sudokumatrix::sudokumatrix() {
}

sudokumatrix::sudokumatrix(const sudokumatrix& obj) {
  for(int i=0;i<9;i++)
    for (int j = 0; j < 9; j++)
      mat[i][j] = obj.mat[i][j];
}

sudokumatrix::sudokumatrix(const sudokumatrix* obj, int x, int y, short int val){
  for(int i=0;i<9;i++)
    for (int j = 0; j < 9; j++)
      mat[i][j] = obj->mat[i][j];
  setCell(x,y,val);
}

sudokumatrix::~sudokumatrix() {
}

void sudokumatrix::printall(){
  for(int i=0;i<9;i++){
    if(i%3==0)
      std::cout<<"\n";
    for (int j = 0; j < 9; j++){
      if(j%3==0) std::cout<<" ";
      std::cout<<mat[i][j];
    }
    std::cout<<"\n";
  }
}

std::vector<int> sudokumatrix::getFirstFreeCell() const{
  std::vector<int> v = {9, 9};
  for (int i = 0; i < 9; i++)
    for (int j = 0; j < 9; j++)
      if(mat[i][j] == 0){
        v[0] = i;
        v[1] = j;
        return v;
      }
  return v;
}

std::vector<sudokumatrix*> sudokumatrix::getNewMatices(int x, int y) const{
  std::vector<sudokumatrix*> arr;
  for (int i = 1; i < 10; i++)
    if(isValid(x,y,i)){
      arr.push_back(new sudokumatrix(this, x, y, i));
    }
  return arr;
}

std::vector<sudokumatrix*> sudokumatrix::getNewMatices() const{
  std::vector<int> coor = getFirstFreeCell();
  return getNewMatices(coor[0], coor[1]);
}

void sudokumatrix::setCell(int x, int y, short int val){
  if(x <9 && y < 9)
    mat[x][y] = val;
}

std::vector<int> sudokumatrix::getBound(const int v) const{
  if(v < 3){
    std::vector<int> r = {0, 3};
    return r;
  }
  if(v > 2 && v < 6){
    std::vector<int> r = {3, 6};
    return r;
  }
  std::vector<int> r = {6, 9};
  return r;
}

int sudokumatrix::getCell(int x, int y){
  return mat[x][y];
}


bool sudokumatrix::isValid(int x, int y, short int val) const{
  if(x > 8 || y > 8)
    return false;
  for (int i = 0; i < 9; i++)
    if(mat[x][i] == val)
      return false;
  for (int i = 0; i < 9; i++)
    if(mat[i][y] == val)
      return false;
  std::vector<int> xbound = getBound(x);
  std::vector<int> ybound = getBound(y);
  for (int i = xbound[0]; i < xbound[1]; i++)
    for (int j = ybound[0]; j < ybound[1]; j++)
      if(mat[i][j] == val)
        return false;
  return true;
}

bool sudokumatrix::isFree(){
  for (int i = 0; i < 9; i++)
    for (int j = 0; j < 9; j++)
      if(mat[i][j] == 0)
        return true;
  return false;
}
