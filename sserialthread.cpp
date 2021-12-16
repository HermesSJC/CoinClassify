#include "sserialthread.h"

SSerialThread::SSerialThread(QObject *parent) : QThread(parent)
{
    this->running = false;
}

SSerialThread::~SSerialThread()
{
    this->running = false;
    this->wait();
}

void SSerialThread::run()
{
#ifdef Q_OS_WIN
#endif
}

bool SSerialThread::startSerial(const QString &portName, int bandRate)
{
    if(this->running == true || this->isRunning()) {
        return false;
    }

#ifdef Q_OS_WIN
    //打开串口
    m_ucom = CreateFileA(portName.toStdString().c_str(), GENERIC_READ | GENERIC_WRITE, 0, nullptr, OPEN_EXISTING, 0, nullptr);
    //如果分配到0xffffffffffff 说明打开失败
    if (m_ucom == INVALID_HANDLE_VALUE)
    {
        return false;
    }

    //查看串口参数
    DCB dcb;
    memset(&dcb, 0, sizeof(dcb));

    //获取串口参数
    if(GetCommState(m_ucom, &dcb) == false) {
        return false;
    }

    //配置串口参数
    dcb.BaudRate = static_cast<DWORD>(bandRate);
    dcb.ByteSize = 8;
    dcb.StopBits = ONE5STOPBITS;
    dcb.fParity = FALSE;
    dcb.fNull = FALSE;
    dcb.Parity = NOPARITY;

    if(!SetCommState(m_ucom, &dcb))
    {
        return false;
    }
    //清空串口缓存
    if(!PurgeComm(m_ucom, PURGE_TXCLEAR | PURGE_RXCLEAR))
    {
        return false;
    }

    //如果线程没有运行,就运行
    if(!this->isRunning())
    {
        start();
    }

    //设置发送参数 超时延迟2s
    COMMTIMEOUTS writeCommTimeOuts;
    memset(&writeCommTimeOuts, 0, sizeof(writeCommTimeOuts));
    writeCommTimeOuts.WriteTotalTimeoutConstant= 500;
    SetCommTimeouts(m_ucom,&writeCommTimeOuts);

    running = true;
    return true;
#endif
}

bool SSerialThread::stopSerial()
{
#ifdef Q_OS_WIN
    //如果有句柄 说明应该是打开的
    if(m_ucom != INVALID_HANDLE_VALUE)
    {
        running = false;
        return CloseHandle(m_ucom);
    }
    //没有句柄说明没打开
    return true;
#endif
}

void SSerialThread::writeSerial(const QString &msg)
{
#ifdef Q_OS_WIN
    //设置实际发送大小
    DWORD dwWriteBytes = 0;

    //设置期望发送大小
    DWORD size = static_cast<DWORD>(msg.count() + 2);

    //发送数据
    WriteFile(m_ucom, msg.toStdString().append("\r\n").c_str() ,size, &dwWriteBytes, nullptr);
#endif

#ifdef Q_OS_MAC

#endif
}

