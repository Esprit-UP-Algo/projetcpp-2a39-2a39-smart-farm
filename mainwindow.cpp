#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->idfacLE->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_facturesBtnPage_clicked()
{
    ui->mainStackWidget->setCurrentIndex(1);
}

void MainWindow::on_ajouterFacturePageBtn_clicked()
{
    ui->factureStackWidget->setCurrentIndex(1);
}

void MainWindow::on_employesBtnPage_4_clicked()
{
    ui->factureTableView->setModel(f.afficherFacture());
    ui->factureStackWidget->setCurrentIndex(2);
}

void MainWindow::on_factureTableView_clicked(const QModelIndex &index)
{
    int row = index.row();
    QModelIndex sibling = index.sibling(row,0);
    QString id = ui->factureTableView->model()->data(sibling).toString();
        QSqlQuery qry;
        qry.prepare("SELECT * FROM factures WHERE id=:id" );
        qry.bindValue(":id",id);
        if(qry.exec())
        {
            while(qry.next())
            {
                ui->idfacLE->setText(qry.value(0).toString());
                ui->lineEdit_10->setText(qry.value(1).toString());
                ui->lineEdit_6->setText(qry.value(2).toString());
                ui->lineEdit_8->setText(qry.value(3).toString());
                ui->lineEdit_9->setText(qry.value(4).toString());
                ui->lineEdit_7->setText(qry.value(5).toString());
            }
        }
}

void MainWindow::on_modifierIrrBtnPage_clicked()
{
    ui->factureStackWidget->setCurrentIndex(3);
}

void MainWindow::on_addFacBtn_clicked()
{
    QString prod_dep = ui->lineEdit->text();
    float ben=ui->lineEdit_2->text().toFloat(),fr=ui->lineEdit_3->text().toFloat();
    float cout=ui->lineEdit_4->text().toFloat(),gain=ui->lineEdit_5->text().toFloat();
    Facture fac(0,prod_dep,ben,fr,cout,gain);
    if(fac.ajouterFacture()){
            ui->factureTableView->setModel(f.afficherFacture());
            ui->factureStackWidget->setCurrentIndex(2);
    }else{
        QMessageBox::critical(nullptr,QObject::tr("ERREUR!"),
                              QObject::tr("Echec de l'opération. \n"
                                          "Click me to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_addFacBtn_2_clicked()
{
    int id=ui->idfacLE->text().toInt();
    QString prod_dep = ui->lineEdit_10->text();
    float ben=ui->lineEdit_6->text().toFloat(),fr=ui->lineEdit_8->text().toFloat();
    float cout=ui->lineEdit_9->text().toFloat(),gain=ui->lineEdit_7->text().toFloat();
    Facture fac(id,prod_dep,ben,fr,cout,gain);
    if(fac.modifierFacture()){
            ui->factureTableView->setModel(f.afficherFacture());
            ui->factureStackWidget->setCurrentIndex(2);
    }else{
        QMessageBox::critical(nullptr,QObject::tr("ERREUR!"),
                              QObject::tr("Echec de l'opération. \n"
                                          "Click me to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_deleteIrrBtn_clicked()
{
    QModelIndex indexItem = ui->factureTableView->currentIndex();
    int row = indexItem.row();
    QModelIndex sibling = indexItem.sibling(row,0);
    int id = ui->factureTableView->model()->data(sibling).toInt();
    if(f.supprimerFacture(id))
    {
         ui->factureTableView->setModel(f.afficherFacture());
    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("ERREUR!"),
                              QObject::tr("Echec d'opération. \n"
                                          "Click me to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_backMenuIrr_4_clicked()
{
    ui->mainStackWidget->setCurrentIndex(0);
}

void MainWindow::on_backMenuIrr_2_clicked()
{
    ui->factureStackWidget->setCurrentIndex(0);
}

void MainWindow::on_backMenuIrr_3_clicked()
{
    ui->factureStackWidget->setCurrentIndex(0);
}

void MainWindow::on_backMenuIrr_clicked()
{
    ui->factureStackWidget->setCurrentIndex(0);
}
