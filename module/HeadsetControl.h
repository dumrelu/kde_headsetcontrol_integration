#pragma once

#include <QObject>
#include <QString>
#include <QQmlPropertyMap>

class HeadsetControl : public QObject 
{
    Q_OBJECT

    Q_PROPERTY(QQmlPropertyMap* batteryInfo READ batteryInfo NOTIFY batteryInfoChanged)
public:
    explicit HeadsetControl(QObject* parent = nullptr);

    QQmlPropertyMap* batteryInfo();

signals:
    void batteryInfoChanged();

private:
    void initializeBatteryInfo();

    QQmlPropertyMap m_batteryInfo;
};