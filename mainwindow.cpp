#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    this->ConfigureFoundationalUI();
}

MainWindow::~MainWindow()
{
}

void MainWindow::ConfigureFoundationalUI()
{
    //重置主界面
    mainWidget = new QWidget(this);
    this->setCentralWidget(mainWidget);

    //加载布局
    mainLayout = new QHBoxLayout();
    this->centralWidget()->setLayout(mainLayout);

    //允许浮动窗口
    this->setDockNestingEnabled(true);

    //设置标题
    this->setWindowTitle(QStringLiteral("钱币分类整理机"));
}

