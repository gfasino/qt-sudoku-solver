#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSpinBox>
#include <iostream>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
		Q_OBJECT

	public:
		explicit MainWindow(QWidget *parent = 0);
		~MainWindow();

	private slots:
		void on_solve_clicked();
		void on_reset_clicked();

	private:
		QSpinBox* box[9][9];
		Ui::MainWindow *ui;
		void setupGridColor();
};

#endif // MAINWINDOW_H
