#include <iostream>
#include <vector>

class sudokumatrix{

  protected:
    short int mat[9][9];
    std::vector<int> getFirstFreeCell() const;
    std::vector<sudokumatrix*> getNewMatices(int x, int y) const;
    bool isValid(int x, int y, short int val) const;
    void setCell(int x, int y, short int val);
    std::vector<int> getBound(const int v) const; //static

  public:
    sudokumatrix(const sudokumatrix* obj, int x, int y, short int val);
    sudokumatrix();
    sudokumatrix(const short int mat_[9][9]);
    sudokumatrix(const sudokumatrix& obj);
    ~sudokumatrix();
    std::vector<sudokumatrix*> getNewMatices() const;
    bool isFree();
    void printall();
    int getCell(int x, int y);
};
