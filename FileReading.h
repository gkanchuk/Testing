#ifndef FileReading_H
#define FileReading_H
#include "ByteReading.h"
#include<QByteArray>

class FileReading
{
public:
    qint32 iTotalDiscardedBytes;
    qint32 iTotalStoredBytes;
    FileReading();
    void fileRead();
private:
    ByteReading byteread;
};

#endif // FileReading_H
