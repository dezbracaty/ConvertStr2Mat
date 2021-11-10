#ifndef CLIPBOARDHELPER_H
#define CLIPBOARDHELPER_H

#include <QObject>

class ClipBoardHelper : public QObject
{
    Q_OBJECT
public:
    explicit ClipBoardHelper(QObject *parent = nullptr);
    Q_INVOKABLE void copyText(QString text);
signals:

};

#endif // CLIPBOARDHELPER_H
