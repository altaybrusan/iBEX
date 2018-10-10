#ifndef STARTUP_H
#define STARTUP_H

#include <QObject>
#include "Model/databaseconnector.h"
class MainWindow;
class LoginDialog;
class DeviceMgr;
class LoginMgr;


class Startup : public QObject
{
    Q_OBJECT
public:
    explicit Startup();
    void Show() const;
    ~Startup();

private:
    MainWindow& m_mainWindow;
    LoginDialog& m_loginDlg;
    LoginMgr& m_loginMgr;
    DatabaseConnector& m_dbConnector;
    DeviceMgr& m_device;
    QString m_dbName,m_dbDriver;


    void LoadiBEXSettings();
    void FailedToLoad();
    explicit Startup(const Startup& rhs)=delete;
    Startup& operator=(const Startup& rhs)=delete;
};

#endif // STARTUP_H