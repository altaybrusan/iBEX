#ifndef STARTUP_H
#define STARTUP_H

#include <QObject>
#include "Model/databaseconnector.h"
class MainWindow;
class LoginDialog;
class DeviceMgr;
class LoginMgr;
class PacsSettingMgr;
class PacsSettingsDialog;
class WorklistServerSettingsMgr;
class WorklistServerSettingsDialog;
class LoadStudyDialog;
class LoadStudyMgr;
class ExaminationDialog;
class ExaminationMgr;
class WorklistMgr;
class WorklistDialog;
class WorklistModel;
class NewPatientDialog;
class NewPatientMgr;
class RegistrationFormModel;
class ImageViewer;
class LoadImageDialog;
class ToolsDialog;
class ToolsMgr;
class FiltersDialog;
class FilterPluginMgr;

class Startup : public QObject
{
    Q_OBJECT
public:
    explicit Startup();
    void Show() const;
    ~Startup();

private:
    FiltersDialog& m_filterPluginDlg;
    FilterPluginMgr& m_filterMgr;
    //FilterPluginMgr& m_filterPluginMgr;
    ImageViewer& m_imageViewer;
    LoadImageDialog& m_loadImageDlg;
    MainWindow& m_mainWindow;
    LoadStudyDialog& m_loadStudyDlg;
    LoadStudyMgr& m_loadStudyMgr;
    LoginDialog& m_loginDlg;
    LoginMgr& m_loginMgr;
    DatabaseConnector& m_dbConnector;
    QString m_dbName,m_dbDriver;
    PacsSettingsDialog& m_pacsSettingsDlg;
    PacsSettingMgr& m_pacsSettingsMgr;
    WorklistServerSettingsDialog& m_worklistSettingsDlg;
    WorklistServerSettingsMgr& m_worklistSettingsMgr;
    ExaminationDialog& m_examinationDlg;
    ExaminationMgr& m_examinationMgr;
    WorklistModel& m_worklistMdl;
    WorklistDialog& m_worklistDlg;
    WorklistMgr& m_worklistMgr;
    NewPatientDialog& m_newPatientDlg;
    RegistrationFormModel& m_registrationFormModel;
    NewPatientMgr& m_newPatientMgr;
    ToolsDialog& m_toolsDlg;
    ToolsMgr& m_toolsMgr;
    DeviceMgr& m_device;




    void LoadiBEXSettings();
    void FailedToLoad();
    explicit Startup(const Startup& rhs)=delete;
    Startup& operator=(const Startup& rhs)=delete;
};

#endif // STARTUP_H
