#include "login.h"
#include "ui_login.h"
#include "QMessageBox"

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_commandLinkButton_clicked()
{
        QString user= ui -> Uname -> text ();
        QString contra= ui -> contra -> text ();
        QSqlQuery buscar;
        QString Consulta;
        Consulta.append("SELECT * FROM usuario where user='"+user+"'");
        buscar.prepare(Consulta);
        if (buscar.exec())
        {
            qDebug () <<"Consulta Realizada";
            while(buscar.next())
            {
               pass2=buscar.value(0).toByteArray().constData();
            }
        }else
        {
            qDebug () <<"Error de consulta";
            QMessageBox::critical(this,tr("ERROR"),tr ("Usuario no existe"));
        }


}

