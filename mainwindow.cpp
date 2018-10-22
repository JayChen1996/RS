#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    boxwidth   = 200;
    boxheight  = 300;
    leftmargin = 10;
    topmargin  = 10;

    for(int i=0;i<15;i++)
        for(int j=0;j<10;j++)
            boxrecord[i][j] = false;

    for(int i=0;i<15;i++)
    {
        for(int j=0;j<3;j++)
        {
            bordercheckbox[i][j]  = true;
        }
        bordercheckbox[i][13] = true;
    }

    nextblockgenerate();
    currentblocktype = nextblocktype;
    memcpy(currBlock,nextBox,sizeof(bool[4][4]));
    nextblockgenerate();
    update();
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::randgenerate()
{
    static bool seed;
    if(!seed)
    {
        qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
        seed = true;
    }
    return qrand()%7+1;
}

bool MainWindow::bordercheck()
{
    int i = currentposition[0];	// current block top-left cell row in box
    int j = currentposition[1];	// current block top-left cell column in box

    for(int row = i;row<i+4;row++)
    {
        for(int col = j+3;j<j+7;col++)
        {
            if(bordercheckbox[row][col] && currBlock[row-i][col-j])
                return 0;
        }
    }
}

bool MainWindow::rotateandcheck()
{
    int temp[4][4];
    memcpy(temp,currBlock,sizeof(bool[4][4]));

    // rotate
    switch (currentblocktype) {
    case 1:
        break;
    case 2:

    default:
        break;
    }



}

void MainWindow::nextblockgenerate()
{
    int blocktype = randgenerate();
    switch (blocktype) {
    case 1:
        memcpy(nextBox,O,sizeof(bool[4][4]));
        break;
    case 2:
        memcpy(nextBox,S,sizeof(bool[4][4]));
        break;
    case 3:
        memcpy(nextBox,Z,sizeof(bool[4][4]));
        break;
    case 4:
        memcpy(nextBox,L,sizeof(bool[4][4]));
        break;
    case 5:
        memcpy(nextBox,J,sizeof(bool[4][4]));
        break;
    case 6:
        memcpy(nextBox,T,sizeof(bool[4][4]));
        break;
    case 7:
        memcpy(nextBox,I,sizeof(bool[4][4]));
        break;
    default:
        break;
    }
    nextblocktype = blocktype;
    randcolor = QColor(qrand()%100+156,qrand()%100+156,qrand()%100+156);
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setBrush(QBrush(Qt::white,Qt::SolidPattern));
    painter.setPen(QPen(Qt::black));
    painter.drawRect(10,10,200,300);

    // draw Box
    painter.setPen(QPen(Qt::gray));
    int i,j;
    for(i=leftmargin+20;i<leftmargin+200;i+=20)
        painter.drawLine(QPointF(i,topmargin),QPointF(i,topmargin+300));
    for(i=topmargin+20;i<topmargin+300;i+=20)
        painter.drawLine(QPointF(leftmargin,i),QPointF(leftmargin+200,i));


    // draw next block prompt box
    painter.setPen(QPen(Qt::gray));
    painter.drawRect(250,10,80,80);
    for(i=250+20;i<250+80;i+=20)
        painter.drawLine(QPointF(i,topmargin),QPointF(i,topmargin+80));
    for(i=topmargin+20;i<topmargin+80;i+=20)
        painter.drawLine(QPointF(250,i),QPointF(250+80,i));
    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
        {
            if(nextBox[i][j])
            {
                painter.setBrush(randcolor);
                painter.drawRect(250+j*20,10+i*20,20,20);
            }
        }
}















