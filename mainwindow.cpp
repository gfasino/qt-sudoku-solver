#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	for(int i=0;i<9;i++)
		for(int j=0;j<9;j++){
			box[i][j] = new QSpinBox(0);
			ui->gridLayout->addWidget(box[i][j], i, j);
		}
	setupGridColor();
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::setupGridColor()
{
	for(int i=0;i<9;i++)
		for(int j=0;j<9;j++){
			box[i][j]->setRange(0,9);
			if(((int)(i/3)+(int)(j/3))%2==0 && box[i][j]->value())
				box[i][j]->setStyleSheet("QSpinBox { background-color: yellow; color : blue; }");
			if(((int)(i/3)+(int)(j/3))%2==0 && !box[i][j]->value())
				box[i][j]->setStyleSheet("QSpinBox { background-color: yellow; color : black; }");
			if(((int)(i/3)+(int)(j/3))%2!=0 && box[i][j]->value())
				box[i][j]->setStyleSheet("QSpinBox { background-color: white; color : blue; }");
			if(((int)(i/3)+(int)(j/3))%2!=0 && !box[i][j]->value())
				box[i][j]->setStyleSheet("QSpinBox { background-color: white; color : black; }");
		}
}

#include "solver.h"

void MainWindow::on_solve_clicked()
{
	setupGridColor();
	short int mat[9][9];
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			mat[i][j] = box[i][j]->value();
		}
	}
	sudokumatrix s(mat);
	sudokumatrix ret = solver::solve(&s);
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			box[i][j]->setValue(ret.getCell(i,j));
		}
	}
}

void MainWindow::on_reset_clicked()
{
	for(int i=0;i<9;i++)
		for(int j=0;j<9;j++){
			box[i][j]->setValue(0);
		}
	setupGridColor();
}
