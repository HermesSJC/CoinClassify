#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QHBoxLayout>
#include <QString>
#include <QLabel>
#include <QComboBox>
#include <QPushButton>
#include <QDockWidget>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:

    void on_connectSerialButton_clicked(void);

    void on_disconnectSerialButton_clicked(void);

    void on_refreshSerialButton_clicked(void);

private:

    void ConfigureFoundationalUI(void);
    QWidget *mainWidget;
    QHBoxLayout *mainLayout;

    //设置串口
    void ConfigureSerial(void);
    QDockWidget *serialDockWidget;
    QWidget *serialWidget;
    QGridLayout *serialLaytout;
    QLabel *serialPortLabel;
    QComboBox *serialPortComboBox;
    QLabel *bandRateLabel;
    QComboBox *bandRateComboBox;
    QPushButton *connectSerialButton;
    QPushButton *disconnectSerialButton;
    QPushButton *refreshSerialButton;
    QLabel *infoSerialLabel;

    //设置布局
    void ConfigureLayout(void);

};
#endif // MAINWINDOW_H
