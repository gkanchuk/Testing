#include "FileReading.h"
#include<QtCore>
#include<QFile>
#include<QByteArray>
#include<QStringList>

FileReading::FileReading()
{

}
void FileReading::fileRead()
{
    QString  strFileName = "D:/HarryPotter.txt";
    QFile fread(strFileName);
    iTotalDiscardedBytes = 0;
    iTotalStoredBytes = 0;

    if( !fread.open(QIODevice::ReadOnly))
    {
        qDebug()<<"not able to  open input file in read mode";
        return;
    }
    else
    {
        QByteArray buffer;
        //QByteArray buffer1;
        //QStringList sbuffer;
        qint32 read=1;

      while(!fread.atEnd()&& read>0)
      {
          buffer = fread.read(30);
          byteread.byteRead(buffer,iTotalDiscardedBytes,iTotalStoredBytes);
      }
    }
   for(int i = 0; i < byteread.sList.length(); i++)
   {
//       qDebug() << "String at  " << i << "  " << byteread.sList.at(i) << "  With the length  " << byteread.sList.at(i).length();
       if(byteread.sList.at(i).length() != 10)
           qDebug() << "String at  " << i << "  " << byteread.sList.at(i) << "  With the length  " << byteread.sList.at(i).length();
   }
   qDebug() << "Total Dicarded bytes =" << iTotalDiscardedBytes;
   qDebug() << "Total stored bytes = "  << iTotalStoredBytes;
   qint32 iFsize = fread.size();
   qDebug() << "size of the file" << iFsize;
   qDebug() << "total number of stored and discarded bytes =" << (iTotalDiscardedBytes+iTotalStoredBytes);
    fread.close();
}
