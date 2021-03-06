#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QDialogButtonBox>
#include <QHeaderView>
#include <QLabel>
#include <QLineEdit>
#include <QWidget>
#include <QSpacerItem>
#include <QHBoxLayout>
#include <QMainWindow>
#include "schooldb.h"
#include "schoolmasterwindow.h"
#include "teacherswindow.h"

class Login : public QWidget
{
    Q_OBJECT
    
public:
    schoolmasterwindow *smwindow;
    Teacherswindow *twindow;
    Schooldb *db;
    Login(QWidget *parent = 0);
    QGridLayout *gridLayout;
    QDialogButtonBox *submit;
    QLineEdit *username_field;
    QLineEdit *password_field;
    QLabel *username_label;
    QLabel *password_label;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    ~Login();

private slots:
    void rejected();
    void accepted();
};

#endif
