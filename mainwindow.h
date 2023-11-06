#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMessageBox>
#include <QMainWindow>
#include "facture.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_facturesBtnPage_clicked();

    void on_ajouterFacturePageBtn_clicked();

    void on_employesBtnPage_4_clicked();

    void on_factureTableView_clicked(const QModelIndex &index);

    void on_modifierIrrBtnPage_clicked();

    void on_addFacBtn_clicked();

    void on_addFacBtn_2_clicked();

    void on_deleteIrrBtn_clicked();

    void on_backMenuIrr_4_clicked();

    void on_backMenuIrr_2_clicked();

    void on_backMenuIrr_3_clicked();

    void on_backMenuIrr_clicked();

private:
    Ui::MainWindow *ui;
    Facture f;
};
#endif // MAINWINDOW_H
