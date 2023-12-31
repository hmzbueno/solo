#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QSqlError>
#include <QSqlQuery>
#include <QMainWindow>
#include <QtSql/QSqlDatabase>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;


};
#endif // MAINWINDOW_H
