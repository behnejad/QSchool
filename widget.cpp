#include "widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->resize(216, 116);
    this->setMinimumSize(QSize(216, 116));
    this->setMaximumSize(QSize(216, 116));
    this->setWindowTitle(QApplication::translate("user_entrance", "user_entrance", 0));

    gridLayout = new QGridLayout(this);
    gridLayout->setSpacing(6);
    gridLayout->setContentsMargins(11, 11, 11, 11);
    gridLayout->setObjectName(QStringLiteral("gridLayout"));

    username_label = new QLabel(this);
    username_label->setObjectName(QStringLiteral("username_label"));
    username_label->setText(QApplication::translate("user_entrance", "User Name", 0));
    gridLayout->addWidget(username_label, 0, 0, 1, 1);

    username_field = new QLineEdit(this);
    username_field->setObjectName(QStringLiteral("username_field"));
    gridLayout->addWidget(username_field, 0, 1, 1, 1);

    password_label = new QLabel(this);
    password_label->setObjectName(QStringLiteral("password_label"));
    password_label->setText(QApplication::translate("user_entrance", "Passwrod", 0));
    gridLayout->addWidget(password_label, 1, 0, 1, 1);

    password_field = new QLineEdit(this);
    password_field->setObjectName(QStringLiteral("password_field"));
    password_field->setEchoMode(QLineEdit::Password);
    gridLayout->addWidget(password_field, 1, 1, 1, 1);

    horizontalLayout = new QHBoxLayout();
    horizontalLayout->setSpacing(6);
    horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
    horizontalSpacer_2 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    horizontalLayout->addItem(horizontalSpacer_2);

    submit = new QDialogButtonBox(this);
    submit->setObjectName(QStringLiteral("submit"));
    submit->setMinimumSize(QSize(141, 23));
    submit->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
    connect(submit, SIGNAL(accepted()), this, SLOT(accepted()));
    connect(submit, SIGNAL(rejected()), this, SLOT(rejected()));

    horizontalLayout->addWidget(submit);
    horizontalSpacer = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    horizontalLayout->addItem(horizontalSpacer);
    gridLayout->addLayout(horizontalLayout, 2, 0, 1, 2);

    //*******************************************************//
    db = new Schooldb;
}

Widget::~Widget()
{
    delete submit;
    delete username_field;
    delete username_label;
    delete password_field;
    delete password_label;
    delete db;
}

void Widget::rejected()
{
    this->close();
}

void Widget::accepted()
{
    db->add_user();
    QString username;
    QString password;
    username = username_field->text();
    password = password_field->text();
    if (db->authenticate(username, password))
        qDebug() << "login successful";
    else
        qDebug() << "login failed";

}
