#include "ByteReading.h"



ByteReading::ByteReading()
{
 extraBytes = false;
 iRemainingBytes = 0;
}

void ByteReading::byteRead(QByteArray buffer,qint32 &iTotalDiscardedBytes,qint32 &iTotalStoredBytes)
{
    qint32 iSize = buffer.size();
    qint32 iByte,iTemp,iAddedBytes=0;
    QString sChar;
//    qDebug() << "check remaining bytes"<<iRemainingBytes;


    for(iByte = 0; iByte < iSize; iByte++)
    {
        if(extraBytes)
        {
            for(iTemp = 0; iTemp < sCopy.size();iTemp++)
            {
                sChar.append(sCopy[iTemp]);
            }
            for(iTemp = 0; iTemp < iRemainingBytes ; iTemp++)
            {
               // qDebug() <<"remaining bytes added" << sChar.append(buffer.mid(iByte, 1));
                sChar.append(buffer.mid(iByte, 1));
                iByte++;
                iTotalStoredBytes++;
            }
            sList.append(sChar);
            sChar = "";
//            qDebug() << sList;
            sCopy = QString();
            extraBytes = false;
            //qDebug() << "remaining data appended="<< buffer1;
        }
        if(buffer[iByte]=='a')
        {
            for(iTemp = 0; iTemp < 10 && buffer[iByte] != NULL ; iTemp++,iByte++)
            {
                iAddedBytes = iAddedBytes+1;
                sChar.append(buffer.mid(iByte, 1));
                iTotalStoredBytes++;
//                qDebug() << "no of added bytes : " << iAddedBytes<<"added bytes ="<<sChar;
            }
            iByte =iByte-1;

            if(iAddedBytes!=10)
            {
                iRemainingBytes = 10-iAddedBytes;
//                qDebug() << "Remaining bytes=" << iRemainingBytes;
                extraBytes = true;
                for (int iTemp = 0; iTemp < sChar.size(); ++iTemp)
                {
                    sCopy.append(sChar[iTemp]);
                }

            }
            else
            {
//                qDebug() << "total buffer addedbyes = "<< iAddedBytes <<"which is"<< sChar;
                iAddedBytes = 0;
                extraBytes = false;
                sList.append(sChar);
                sChar = "";
//                qDebug()<< sList;
            }
        }
        else
        {
            iTotalDiscardedBytes++;
        }
    }
//    qDebug() << "buffer size"<< iByte;
}
