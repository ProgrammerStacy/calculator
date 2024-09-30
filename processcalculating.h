#ifndef PROCESSCALCULATING_H
#define PROCESSCALCULATING_H

#include <QObject>
class ProcessCalculating : public QObject
{
    Q_OBJECT
public:
    explicit ProcessCalculating(QObject *parent = nullptr);
public slots:
    void receiveFromQml(const QString& in);
private:
    int num;

};

#endif // PROCESSCALCULATING_H
