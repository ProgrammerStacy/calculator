#include "processcalculating.h"
#include <QDebug>

ProcessCalculating::ProcessCalculating(QObject *parent) : QObject(parent)
{
    resultNum = 0; //обнуляем все в конструкторе
    bN = "";
    nN = "";
    timer.setInterval(5000);
    secretCode = "";
}
void ProcessCalculating::itIsSecret(QString str)
{
    if (str == "=")
    {
        timer.start();
        qDebug() << true;
    }

}

void ProcessCalculating::receiveFromQml(QString str)
{
    if (timer.isActive())
    {
        secretCode += str;
        if (secretCode == "123")
        {
            qDebug() << "Right";
            emit secretMenuActive();
        }
    }
    if (str == "0" || str == "1" || str == "2" || str == "3" || // если была нажата кнопка с цифрой, то мы продолжаем запись числа
        str == "4" || str == "5" || str == "6" || str == "7" ||
        str == "8" || str == "9" || str == ".")
    {
        if (nN == "")
        {
            nN = str;
        }
        else
        {
            nN += str;
        }
        emit sendToNowNum(nN);

    }
    else if (str == "+" || str == "-" || str == "/" || str == "x") // сохраняем символ соответствуеющей операции
    {
        operation = str;
        bN = nN;
        nN = "";
        emit sendToBeforeNum(bN); // обновляем дисплей
        emit sendToNowNum("0");
    }
    else if (str == "+/-")
    {
        if (nN != 0)
        {
            nN = QString::number(nN.toInt() * -1);
            emit sendToNowNum(nN);
        }
    }
    else if (str == "%")
    {
        nN = QString::number(nN.toInt() * 0.01);
        emit sendToNowNum(nN);
    }
    else if (str == "C")
    {
        bN = "";
        nN = "";
        emit sendToBeforeNum("0");
        emit sendToNowNum("0");
    }
    else // если было нажата кнопка "равно", то проверяем какие числа записали и какая операция была введена
    {
        if (operation == "+")
            resultNum = bN.toDouble() + nN.toDouble();
        else if (operation == "-")
            resultNum = bN.toDouble() - nN.toDouble();
        else if (operation == "x")
            resultNum = bN.toDouble() * nN.toDouble();

        else
        {
            if (nN.toDouble() == 0) resultNum = 0; //проверка деления на 0
            else resultNum = bN.toDouble() / nN.toDouble();
        }
        bN = "" ; // результат сохраняем как предыдущее число, чтобы продолжить вычисления
        nN = QString::number(resultNum);
        emit sendToBeforeNum(""); //если нужно начать вычисления с начала, пользователь должен нажать кнопку "C"
        emit sendToQml(resultNum);
    }

}
