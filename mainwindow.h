#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QHBoxLayout>
#include <QString>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:


private:

    void ConfigureFoundationalUI(void);
    QWidget *mainWidget;
    QHBoxLayout *mainLayout;

};
#endif // MAINWINDOW_H
