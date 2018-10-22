#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPaintEvent>
#include <QPainter>
#include <QBrush>
#include <QPen>
#include <QTime>
#include <QColor>

#include <iostream>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void paintEvent(QPaintEvent *event);
    int  randgenerate();		// rand generate num 1-7
    void nextblockgenerate();	// generate next block
    bool bordercheck();			// check weather the rotation out of the border
    bool rotateandcheck();
    ~MainWindow();

public:
    int  leftmargin,topmargin;
    int  boxwidth,	boxheight;
    bool boxrecord[15][10];
    bool tempbox[15][10];
    bool currBlock[4][4];		// current block 2D array
    bool nextBox[4][4];			// next block 2D array
    int  bordercheckbox[15][14];
    int  currentposition[2];	// the left-top corner of the current block
    int  currentblocktype;
    int  nextblocktype;



    QColor randcolor;

    bool O[4][4] = {{0,1,1,0},
                    {0,1,1,0},
                    {0,0,0,0},
                    {0,0,0,0}};

    bool S[4][4] = {{0,1,0,0},
                    {0,1,1,0},
                    {0,0,1,0},
                    {0,0,0,0}};

    bool Z[4][4] = {{0,0,1,0},
                    {0,1,1,0},
                    {0,1,0,0},
                    {0,0,0,0}};

    bool L[4][4] = {{0,1,0,0},
                    {0,1,0,0},
                    {0,1,1,0},
                    {0,0,0,0}};

    bool J[4][4] = {{0,0,1,0},
                    {0,0,1,0},
                    {0,1,1,0},
                    {0,0,0,0}};

    bool T[4][4] = {{0,0,0,0},
                    {0,1,0,0},
                    {1,1,1,0},
                    {0,0,0,0}};

    bool I[4][4] = {{0,0,1,0},
                    {0,0,1,0},
                    {0,0,1,0},
                    {0,0,1,0}};


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
