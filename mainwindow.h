#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "culture.h"

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
    void on_culturesBtnPage_clicked();

    void on_ajouterCulturesPageBtn_clicked();

    void on_employesBtnPage_4_clicked();

    void on_modifierCultBtnPage_clicked();

    void on_cultureTableView_clicked(const QModelIndex &index);

    void on_addCultBtn_clicked();

    void on_addCultBtn_2_clicked();

    void on_deleteICultBtn_clicked();

    void on_backMenuIrr_4_clicked();

    void on_backMenuIrr_2_clicked();

    void on_backMenuIrr_3_clicked();

    void on_backMenuIrr_clicked();

private:
    Ui::MainWindow *ui;
    culture c;
};
#endif // MAINWINDOW_H
