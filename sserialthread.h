#ifndef SSERIALTHREAD_H
#define SSERIALTHREAD_H

#include <QObject>
#include <QThread>

#include <string.h>
#include <iostream>

#ifdef Q_OS_WIN
    #include <Windows.h>
#endif
#ifdef Q_OS_MAC

#endif

class SSerialThread : public QThread
{
    Q_OBJECT
public:
    explicit SSerialThread(QObject *parent = nullptr);
    ~SSerialThread();

    void run() Q_DECL_OVERRIDE;

    bool startSerial(const QString &portName, int bandRate);

    bool stopSerial(void);

    void writeSerial(const QString &msg);

    inline bool isOpen(void);

protected:

private:

    bool running;

#ifdef Q_OS_WIN
    HANDLE m_ucom;  //串口句柄
#endif
#ifdef Q_OS_MAC

#endif

signals:

    void readEnd(QString);

};

#endif // SSERIALTHREAD_H
