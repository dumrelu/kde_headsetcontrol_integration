#include "headsetcontrol_plugin.h"

#include <QQmlEngine>

void HeadsetControlPlugin::registerTypes(const char* uri)
{
    qmlRegisterModule(uri, 1, 0);
}
