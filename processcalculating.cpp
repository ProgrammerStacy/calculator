#include "processcalculating.h"
#include <QDebug>

ProcessCalculating::ProcessCalculating(QObject *parent)
    : QObject{parent}
{
    num = 0;
}

void ProcessCalculating::receiveFromQml(const QString &in)
{
    //QString temp = in;
    if (in == "0" || in == "1" || in == "2" || in == "3" || in == "4" || in == "5" || in == "6" ||
        in == "7" || in == "8" || in == "9")
    {
        //num += 1;
        qDebug() << "c++: HandleTextField::handleSubmitTextField:" << in;
    }

}
