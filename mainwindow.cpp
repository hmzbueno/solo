#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    // instanciation de la variable db
     db = QSqlDatabase::addDatabase("QMYSQL");
    // définition des paramètres de connexion à la base de données
    db.setHostName("10.10.10.1"); // @ip serveur mysql
    db.setDatabaseName("nomBDD"); // nom de la base
    db.setUserName("nomUtilisateur"); // nom utilisateur
    db.setPassword("password"); // mot de passe


    if(db.open())   {
        qDebug()<< "ok - ouverture de la base de donnée";
        QSqlQuery requete;
    if(requete.next()){
        float resultat = requete.value(0).toFloat();
        qDebug()<<"voila le resultat : " << resultat;
        db.close();
        this->ui->lcdNumber->display(resultat);
    }

    else {
        qDebug();
            qDebug()<< requete.lastError();
            db.close();
            this->ui->lcdNumberdisplay(-1000);
    }
}
    else {
        qDebug() << "echec d'ouverture de la base de donnée";
        qDebug() << db.lastError();
        this->ui->lcdNumber->display(-1000);
}
    }
MainWindow::~MainWindow()
{
    delete ui;
}

