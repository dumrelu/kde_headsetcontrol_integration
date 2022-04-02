#include "headsetcontrol_plugin.h"

#include "HeadsetControl.h"

#include <QQmlEngine>

void HeadsetControlPlugin::registerTypes(const char* uri)
{
    qmlRegisterType<HeadsetControl>(uri, 1, 0, "HeadsetControl");
}
