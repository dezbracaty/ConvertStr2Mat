#ifndef CONVERTTOOL_H
#define CONVERTTOOL_H

#include <QObject>

class convertTool : public QObject
{
    Q_OBJECT
public:
    explicit convertTool(QObject *parent = nullptr);
    Q_INVOKABLE bool cvtStrToMats(QString str);
    QList<QString> cvtStrToMat(QString str);

    Q_INVOKABLE QList<QString> test();
signals:
    void cppGetQQuanResult(QStringList result);
    void cppGetPossResult(QStringList result);
public slots :
    void getResult(QList<QString> result);
};

#endif // CONVERTTOOL_H
