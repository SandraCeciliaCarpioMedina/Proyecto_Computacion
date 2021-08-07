#include "registro.h"
#include "ui_registro.h"
#include "QDebug"
#include "QMessageBox"

Registro::Registro(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Registro)
{
    ui->setupUi(this);
    CrearTabla();
}

Registro::~Registro()
{
    delete ui;
}
void Registro::CrearTabla()
{
    QString consulta;
    consulta.append("CREATE TABLE IF NOT EXISTS usuario ("
                    "id INTEGER  AUTOINCREMENT,"
                    "nombre VARCHAR (50)PRIMARY KEY,"
                    "apellido VARCHAR (50),"
                    "cargo VARCHAR (50),"
                    "codigo VARCHAR (50),"
                    "pass VARCHAR (50)"
                    ");");
    QSqlQuery crear;
    crear.prepare(consulta);
    if (crear.exec())
    {
            qDebug()<<"Tabla Creada";
    }else
    {
            qDebug()<<"Tabla no creada"<<crear.lastError();
    }

}
void Registro::on_pushButton_clicked()
{
    QString user=ui -> Uname->text();
    QString user2=ui -> Uape->text();
    QString ocupacion= ui -> Cargo ->text();
    QString cod=ui ->codigo -> text();
    QString contra=ui ->contra->text();

    qDebug ()<<user;
    qDebug ()<<user2;
    qDebug ()<<ocupacion;
    qDebug ()<<cod;
    qDebug ()<<contra;

    QSqlQuery insertar_db;
    insertar_db.prepare("INSERT INTO usuario(nombre,apellido,cargo,codigo,pass)"
                        "VALUES (:nombre,:apellido,:cargo,:codigo,:pass)");

    insertar_db.bindValue(":nombre",user);
    insertar_db.bindValue(":apellido",user2);
    insertar_db.bindValue(":cargo",ocupacion);
    insertar_db.bindValue(":codigo",cod);
    insertar_db.bindValue(":pass",contra);
    if(insertar_db.exec())
    {
        qDebug()<<"Datos Ingresados a la tabla";
    }else
    {
        qDebug()<<"Error al ingresar datos"<<insertar_db.lastError();
        QMessageBox::information(this,tr("ERROR"),tr ("El usuario ya esta en uso"));
    }

}
