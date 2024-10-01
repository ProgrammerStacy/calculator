#ifndef PROCESSCALCULATING_H
#define PROCESSCALCULATING_H
#include <QString>
#include <QTimer>
#include <QObject>
class ProcessCalculating : public QObject
{
    Q_OBJECT
public:
    explicit ProcessCalculating(QObject *parent = 0);
signals:
    void sendToQml(double resultNum); //отправка результата на дисплей калькулятора
    void sendToBeforeNum(QString bN); //отправка предыдущего числа на дисплей калькулятора
    void sendToNowNum(QString nN); //отправка вводимого числа на дисплей калькулятора
    void secretMenuActive();
public slots:
    void receiveFromQml(QString str); // получение вводимых символов с клавиатуры калькулятора
    void itIsSecret(QString str);
private:
    double resultNum;
    QString nN; // сюда записывается вводимое число
    QString bN; // здесь хранится предыдущее число или предыдущий результат
    QString operation; //здесь хранится символ означающий операцию
    QTimer timer;
    QString secretCode;


};

#endif // PROCESSCALCULATING_H
