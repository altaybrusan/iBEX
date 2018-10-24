#include "startup.h"
#include "Model/databaseconnector.h"
#include "View/mainwindow.h"
#include "View/logindialog.h"
#include "Controller/loginmgr.h"
#include "Controller/devicemgr.h"
#include "Controller/worklistserversettingsmgr.h"
#include "Utils/logmgr.h"
#include "Utils/settingsprovider.h"
#include "View/pacssettingsdialog.h"
#include "View/worklistserversettingsdialog.h"
#include "Controller/pacssettingmgr.h"
#include "View/loadstudydialog.h"
#include "Controller/loadstudymgr.h"
#include "View/examinationdialog.h"
#include "Controller/examinationmgr.h"
#include <QtXml>
#include <QDomNode>
#include <QMessageBox>
#include <QApplication>

#define IBEX_STTINGS_FILE "./configs/_ibexsettings.xml"
#define WRKLST_SETTING_FILE "./configs/_worklist.xml"
#define LOCAL_PACS_FILE "./database/localpacs.db"
#define LOCALDB_SCHEMA_FILE "./configs/dicom-schema.sql"
Startup::Startup() : QObject(nullptr),
    m_mainWindow(*new MainWindow(nullptr)),
    m_loadStudyDlg(*new LoadStudyDialog(nullptr)),
    m_loadStudyMgr(*new LoadStudyMgr(nullptr,m_loadStudyDlg,LOCAL_PACS_FILE,LOCALDB_SCHEMA_FILE)),
    m_loginDlg(*new LoginDialog(nullptr)),
    m_loginMgr(*new LoginMgr(nullptr,m_loginDlg)),
    m_dbConnector(*new DatabaseConnector(nullptr)),
    m_pacsSettingsDlg(*new PacsSettingsDialog(nullptr)),
    m_pacsSettingsMgr(*new PacsSettingMgr(nullptr,m_pacsSettingsDlg)),
    m_worklistDlg(*new WorklistServerSettingsDialog(nullptr)),
    m_worklistMgr(*new WorklistServerSettingsMgr(nullptr,m_worklistDlg,WRKLST_SETTING_FILE)),
    m_examinationDlg(*new ExaminationDialog(nullptr)),
    m_examinationMgr(*new ExaminationMgr(nullptr,m_examinationDlg)),
    m_device(*new DeviceMgr(nullptr,m_mainWindow,m_loginMgr,
                            m_pacsSettingsDlg,m_pacsSettingsMgr,
                            m_worklistDlg,m_worklistMgr,
                            m_loadStudyDlg,m_loadStudyMgr,
                            m_examinationDlg,m_examinationMgr))

{
    m_dbConnector.setParent(this);
    LoadiBEXSettings();
    m_dbConnector.AddDatabase(m_dbDriver,m_dbName);
    if(!m_dbConnector.ConnectToDatabase())
    {
        QMessageBox::critical(nullptr,"System crashed","A database connection failed. Please check the system log file");
        LogMgr::instance()->LogSysFail(tr("failed to connect to database"));
        LogMgr::instance()->LogAppFail(tr("unsuccessful start. Database connection failed"));
        exit(1);
    }
    m_loadStudyDlg.setParent(&m_mainWindow);
    m_loadStudyDlg.setWindowFlag( Qt::Window,true);
    m_loadStudyDlg.setModal(true);
    m_loadStudyMgr.setParent(this);

      m_loginDlg.setParent(&m_mainWindow);
      m_loginDlg.setWindowFlag( Qt::Window,true);
      m_loginDlg.setModal(true);
      m_loginMgr.setParent(this);

      m_pacsSettingsDlg.setParent(&m_mainWindow);
      m_pacsSettingsDlg.setWindowFlag( Qt::Window,true);
      m_pacsSettingsDlg.setModal(true);
      m_pacsSettingsMgr.setParent(this);

      m_worklistDlg.setParent(&m_mainWindow);
      m_worklistDlg.setWindowFlag( Qt::Window,true);
      m_worklistDlg.setModal(true);
      m_worklistMgr.setParent(this);

      m_examinationDlg.setParent(&m_mainWindow);
      m_examinationDlg.setWindowFlag( Qt::Window,true);
      m_examinationDlg.setModal(true);
      m_examinationMgr.setParent(this);




      m_device.setParent(this);
      m_device.WireConnections();

}

void Startup::Show() const
{
    m_mainWindow.show();
}

Startup::~Startup()
{

}

void Startup::LoadiBEXSettings()
{
    SettingsProvider _provider(this);
    _provider.UpdateSettingFile(IBEX_STTINGS_FILE);

    if(!_provider.OpenSettingFile())
    {
        LogMgr::instance()->LogSysError(tr("Can not open iBEX setting file."));
        FailedToLoad();
        return;

    }
    if(!_provider.LoadSettingFile())
    {
        LogMgr::instance()->LogSysError(tr("iBEX Setting file is not valid."));
        FailedToLoad();
        return;
    }

    LogMgr::instance()->LogSysInfo(tr("iBEX settings are loaded successfully."));
    auto root = _provider.GetRootElement();
    m_dbName = root.childNodes().at(0).firstChild().nodeValue();
    m_dbDriver = root.childNodes().at(1).firstChild().nodeValue();

}

void Startup::FailedToLoad()
{
    QApplication::quit();
}
