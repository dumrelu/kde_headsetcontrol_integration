#pragma once

#include <QObject>
#include <QString>
#include <QQmlPropertyMap>
#include <QProcess>
#include <QTimer>

class HeadsetControl : public QObject 
{
    Q_OBJECT

    Q_PROPERTY(int pollingIntervalSeconds READ pollingIntervalSeconds WRITE setPollingIntervalSeconds NOTIFY pollingIntervalSecondsChanged)
    Q_PROPERTY(QQmlPropertyMap* batteryInfo READ batteryInfo NOTIFY batteryInfoChanged)
public:
    explicit HeadsetControl(QObject* parent = nullptr);

    int pollingIntervalSeconds() const;
    QQmlPropertyMap* batteryInfo();

    void setPollingIntervalSeconds(int pollingIntervalSeconds);

signals:
    void batteryInfoChanged();
    void pollingIntervalSecondsChanged();

private:
    void initializeBatteryInfo();
    void initializeHeadsetControlProcess();
    void initializePollingTimer();

    void onPollingTimerTimeout();
    void onProcessFinished(int exitCode, QProcess::ExitStatus exitStatus);

    QTimer m_pollingTimer;
    QProcess m_headsetControlProcess;
    QQmlPropertyMap m_batteryInfo;
    int m_pollingIntervalSeconds = 10;
};