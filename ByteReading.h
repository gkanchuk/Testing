#ifndef BYTEREAD_H
#define BYTEREAD_H
#include<QByteArray>
#include<QDebug>
#include<QStringList>
#include<QString>


class ByteReading
{
public:
    ByteReading();
    void byteRead(QByteArray,qint32&,qint32&);
    bool extraBytes;
    qint32 iRemainingBytes;
    QStringList sList;
    QString sCopy;
};

#endif // BYTEREAD_H
