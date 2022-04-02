#include "HeadsetControl.h"

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
}

QQmlPropertyMap* HeadsetControl::batteryInfo()
{
    return &m_batteryInfo;
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
