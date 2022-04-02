#!/bin/bash

# Patching PopupDialog.qml to inject an icon for our headset
# Creates a backup of PopupDialog.qml before patching it

# Stop on errors
set -e

POPUP_DIALOG_QML="/usr/share/plasma/plasmoids/org.kde.plasma.battery/contents/ui/PopupDialog.qml"
if [ ! -f "$POPUP_DIALOG_QML" ]
then
    echo "PopupDialog.qml is not in the expected path. Please change POPUP_DIALOG_QML"
    echo "Expected path: $POPUP_DIALOG_QML"
    exit 1
fi

if ! command -v uuidgen &> /dev/null
then
    echo "Need uuidgen to generate unique file name for backup"
    exit 1
fi


# Get current plasma version
PLASMA_VERSION=$(plasmashell --version | awk '{ print $NF }')

echo "Plasma version: $PLASMA_VERSION"

# Check if we have a patch for this version
if [ -f "$PLASMA_VERSION.patch" ]
then
    echo "Patch found: $PLASMA_VERSION.patch"

    echo "Making a copy of the current PopupDialog.qml file"
    
    POPUP_DIALOG_QML_BACKUP=$(echo $POPUP_DIALOG_QML.bak.$(uuidgen -x))
    echo "Backing up in: $POPUP_DIALOG_QML_BACKUP"

    sudo cp $POPUP_DIALOG_QML $POPUP_DIALOG_QML_BACKUP

    echo "Applying the patch"
    sudo patch $POPUP_DIALOG_QML < $PLASMA_VERSION.patch
    echo "Patch applied. Please logout"

else
    echo "No patch found for $PLASMA_VERSION. You could try creating it"
    exit 1
fi