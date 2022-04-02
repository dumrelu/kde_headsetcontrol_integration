#pragma once

#include <QObject>
#include <QString>

class HeadsetControl : public QObject 
{
    Q_OBJECT

    Q_PROPERTY(QString testMessage READ testMessage CONSTANT)
public:
    explicit HeadsetControl(QObject* parent = nullptr);

    QString testMessage() const { return "Hello From C++!"; }

private:

};