import QtQuick 2.15
import QtQuick.Window 2.15

import QtQuick.Controls
import QtQuick.Dialogs
import QtQuick.Layouts 1.15
import Qt.labs.platform as Platform

import ImageViewer 1.0



ApplicationWindow  {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello world")


    menuBar: MenuBar {
        Menu {
            title: qsTr("&File")
            MenuItem {
                text: qsTr("&Open...")
                icon.name: "document-open"
                onTriggered: fd_imageOpenDialog.open()
            }
        }



        Menu{
            id: recentFiles
            title: qsTr("&Recent files")


            Instantiator{
                model: ImageViewerModel{
                    imageViewer: mimageViewer
                }

                delegate: MenuItem{
                    text: model.fileName
                }

                onObjectAdded: recentFiles.insertItem(index, object)
                onObjectRemoved: recentFilesSubMenu.removeItem(object)
            }


        }

    }
}

