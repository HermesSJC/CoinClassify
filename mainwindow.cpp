#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    this->ConfigureFoundationalUI();
}

MainWindow::~MainWindow()
{
}

void MainWindow::on_connectSerialButton_clicked()
{

}

void MainWindow::on_disconnectSerialButton_clicked()
{

}

void MainWindow::on_refreshSerialButton_clicked()
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

void MainWindow::ConfigureSerial()
{
    //创建dock widget
    serialDockWidget = new QDockWidget(QStringLiteral("串口设置"), this);
    //创建内容
    serialWidget = new QWidget(this);

    //设置串口名称
    serialPortLabel = new QLabel(QStringLiteral("串口号:"));
    serialPortComboBox = new QComboBox(this);
    serialPortComboBox->clear();

    //设置串口波特率
    bandRateLabel = new QLabel(QStringLiteral("波特率:"));
    bandRateComboBox = new QComboBox(this);
    bandRateComboBox->clear();
    bandRateComboBox->addItem(tr("1200"),1200);
    bandRateComboBox->addItem(tr("2400"),2400);
    bandRateComboBox->addItem(tr("4800"),4800);
    bandRateComboBox->addItem(tr("9600"),9600);
    bandRateComboBox->addItem(tr("19200"),19200);
    bandRateComboBox->addItem(tr("38400"),38400);
    bandRateComboBox->addItem(tr("57600"),57600);
    bandRateComboBox->addItem(tr("115200"),115200);
    bandRateComboBox->setCurrentIndex(7);

    //链接
    connectSerialButton = new QPushButton(QStringLiteral("连接"));
    connectSerialButton->setIcon(QIcon(":/image/image/serialConnect.png"));
    connect(connectSerialButton,SIGNAL(clicked()),this,SLOT(on_connectSerialButton_clicked()));

    //断开
    disconnectSerialButton = new QPushButton(QStringLiteral("断开"));
    disconnectSerialButton->setDisabled(true);
    disconnectSerialButton->setIcon(QIcon(":/image/image/serialDisconnect.png"));
    connect(disconnectSerialButton,SIGNAL(clicked()),this,SLOT(on_disconnectSerialButton_clicked()));

    //刷新
    refreshSerialButton = new QPushButton(QStringLiteral("刷新"));
    refreshSerialButton->setIcon(QIcon(":/image/image/serialRefresh.png"));
    connect(refreshSerialButton,SIGNAL(clicked()),this,SLOT(on_refreshSerialButton_clicked()));

    //瞎搞点东西
    infoSerialLabel = new QLabel(QStringLiteral("广告位招商"));
    infoSerialLabel->setAlignment(Qt::AlignCenter);

    //设置布局
    serialLaytout = new QGridLayout();
    serialLaytout->addWidget(serialPortLabel, 0, 0);
    serialLaytout->addWidget(serialPortComboBox, 0, 1);
    serialLaytout->addWidget(bandRateLabel, 1, 0);
    serialLaytout->addWidget(bandRateComboBox, 1, 1);
    serialLaytout->addWidget(connectSerialButton, 2, 0);
    serialLaytout->addWidget(disconnectSerialButton, 2, 1);
    serialLaytout->addWidget(infoSerialLabel, 3, 0);
    serialLaytout->addWidget(refreshSerialButton, 3, 1);
    serialWidget->setLayout(serialLaytout);

    serialDockWidget->setWidget(serialWidget);

    //设置dock widget的位置
    this->addDockWidget(Qt::RightDockWidgetArea, serialDockWidget);
    serialDockWidget->show();
}

void MainWindow::ConfigureLayout()
{

}

