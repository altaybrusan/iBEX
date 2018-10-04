#include <vtkAutoInit.h>
VTK_MODULE_INIT(vtkRenderingOpenGL2)
VTK_MODULE_INIT(vtkInteractionStyle)

#include <vtkObject.h>
#include "View/mainwindow.h"
#include <QApplication>
//#include <QSettings>
#include <Utils/logmgr.h>

int main(int argc, char *argv[])
{
    vtkObject::GlobalWarningDisplayOff();
    //QSettings::setDefaultFormat(QSettings::IniFormat);
    QCoreApplication::setOrganizationName("Bogazici-University");
    QCoreApplication::setApplicationName("iBEX");
    QApplication a(argc, argv);

    LogMgr::instance()->Initialize();
    LogMgr::instance()->LogAppInfo("*** SYSTEM LOGIN");


    //MainWindow w;
    //w.show();
    return a.exec();

}
