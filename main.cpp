#include <QCoreApplication>
#include "FileReading.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    FileReading fileread;
    fileread.fileRead();

    return a.exec();
}
