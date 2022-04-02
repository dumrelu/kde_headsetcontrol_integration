#include "HeadsetControl.h"

#include <QDebug>

namespace keys
{
static const QString PRETTY_NAME = "Pretty Name";
static const QString PERCENT = "Percent";
static const QString CAPACITY = "Capacity";
static const QString STATE = "State";
static const QString TYPE = "Type";
static const QString PLUGGED_IN = "Plugged in";
static const QString IS_POWER_SUPPLY = "Is Power Supply";
}

namespace state
{
static const QString CHARGING = "Charging";
static const QString DISCHARGING = "Discharging";
}

HeadsetControl::HeadsetControl(QObject* parent)
    : QObject{ parent }
{
    initializeBatteryInfo();
    initializeHeadsetControlProcess();
    initializePollingTimer();
}

int HeadsetControl::pollingIntervalSeconds() const
{
    return m_pollingIntervalSeconds;
}

QQmlPropertyMap* HeadsetControl::batteryInfo()
{
    return &m_batteryInfo;
}

void HeadsetControl::setPollingIntervalSeconds(int pollingIntervalSeconds)
{
    if(pollingIntervalSeconds != m_pollingIntervalSeconds)
    {
        m_pollingIntervalSeconds = pollingIntervalSeconds;
        m_pollingTimer.setInterval(std::chrono::seconds{ m_pollingIntervalSeconds });
        pollingIntervalSecondsChanged();
    }
}

void HeadsetControl::initializeBatteryInfo()
{
    m_batteryInfo[keys::PRETTY_NAME] = "N/A";
    m_batteryInfo[keys::PERCENT] = 0;
    m_batteryInfo[keys::CAPACITY] = 100;
    m_batteryInfo[keys::STATE] = state::CHARGING;
    m_batteryInfo[keys::TYPE] = ""; //TODO
    m_batteryInfo[keys::PLUGGED_IN] = true;
    m_batteryInfo[keys::IS_POWER_SUPPLY] = false;
}

void HeadsetControl::initializeHeadsetControlProcess()
{
    m_headsetControlProcess.setProgram("sleep");
    m_headsetControlProcess.setArguments(QStringList{} << "3s");
    m_headsetControlProcess.setProcessChannelMode(QProcess::MergedChannels);

    connect(&m_headsetControlProcess, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished), 
        this, &HeadsetControl::onProcessFinished);
}

void HeadsetControl::initializePollingTimer()
{
    m_pollingTimer.setInterval(std::chrono::seconds{ m_pollingIntervalSeconds });
    connect(&m_pollingTimer, &QTimer::timeout, this, &HeadsetControl::onPollingTimerTimeout);

    onPollingTimerTimeout();
    m_pollingTimer.start();
}

void HeadsetControl::onPollingTimerTimeout()
{
    if(m_headsetControlProcess.state() != QProcess::NotRunning)
    {
        qDebug() << "Process is already running, returning.";
        return;
    }

    qDebug() << "Starting process";
    m_headsetControlProcess.start();
}

void HeadsetControl::onProcessFinished(int exitCode, QProcess::ExitStatus exitStatus)
{
    qDebug() << "Process finished: exitCode=" << exitCode << ", exitStatus=" << exitStatus;

    if(exitStatus != QProcess::NormalExit)
    {
        qDebug() << "Process crashed.";
        return;
    }

    if(exitCode != 0)
    {
        qDebug() << "Exit code not 0, probably headset is disconnected";
        //TODO: set state

        return;
    }
    

}
