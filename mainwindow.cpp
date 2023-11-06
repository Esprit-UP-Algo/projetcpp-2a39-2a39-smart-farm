#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->idCultureLE->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_culturesBtnPage_clicked()
{
    ui->mainStackWidget->setCurrentIndex(1);
}

void MainWindow::on_ajouterCulturesPageBtn_clicked()
{
    ui->culturesStackWidget->setCurrentIndex(1);
}

void MainWindow::on_employesBtnPage_4_clicked()
{
    ui->cultureTableView->setModel(c.afficherCulture());
    ui->culturesStackWidget->setCurrentIndex(2);
}

void MainWindow::on_modifierCultBtnPage_clicked()
{
    ui->culturesStackWidget->setCurrentIndex(3);
}

void MainWindow::on_cultureTableView_clicked(const QModelIndex &index)
{
    int row = index.row();
    QModelIndex sibling = index.sibling(row,0);
    QString id = ui->cultureTableView->model()->data(sibling).toString();
        QSqlQuery qry;
        qry.prepare("SELECT * FROM cultures WHERE id=:id" );
        qry.bindValue(":id",id);
        if(qry.exec())
        {
            while(qry.next())
            {
                ui->idCultureLE->setText(qry.value(0).toString());
                ui->lineEdit_9->setText(qry.value(1).toString());
                ui->lineEdit_6->setText(qry.value(2).toString());
                ui->lineEdit_7->setText(qry.value(3).toString());
                ui->lineEdit_10->setText(qry.value(4).toString());
                ui->lineEdit_8->setText(qry.value(5).toString());
            }
        }
}

void MainWindow::on_addCultBtn_clicked()
{
    float qual=ui->lineEdit->text().toFloat();
    float pl=ui->lineEdit_2->text().toFloat();
    float hum=ui->lineEdit_3->text().toFloat();
    float ten=ui->lineEdit_4->text().toFloat();
    float temp=ui->lineEdit_5->text().toFloat();
    culture cult(0,qual,pl,hum,ten,temp);
    if(cult.ajouterCulture()){
            ui->cultureTableView->setModel(c.afficherCulture());
            ui->culturesStackWidget->setCurrentIndex(2);
    }else{
        QMessageBox::critical(nullptr,QObject::tr("ERREUR!"),
                              QObject::tr("Echec de l'opération. \n"
                                          "Click me to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_addCultBtn_2_clicked()
{
    int id = ui->idCultureLE->text().toInt();
    float qual=ui->lineEdit_9->text().toFloat();
    float pl=ui->lineEdit_6->text().toFloat();
    float hum=ui->lineEdit_7->text().toFloat();
    float ten=ui->lineEdit_10->text().toFloat();
    float temp=ui->lineEdit_8->text().toFloat();
    culture cult(id,qual,pl,hum,ten,temp);
    if(cult.modifierCulture()){
            ui->cultureTableView->setModel(c.afficherCulture());
            ui->culturesStackWidget->setCurrentIndex(2);
    }else{
        QMessageBox::critical(nullptr,QObject::tr("ERREUR!"),
                              QObject::tr("Echec de l'opération. \n"
                                          "Click me to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_deleteICultBtn_clicked()
{
    QModelIndex indexItem = ui->cultureTableView->currentIndex();
    int row = indexItem.row();
    QModelIndex sibling = indexItem.sibling(row,0);
    int id = ui->cultureTableView->model()->data(sibling).toInt();
    if(c.supprimerCulture(id))
    {
         ui->cultureTableView->setModel(c.afficherCulture());
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
    ui->culturesStackWidget->setCurrentIndex(0);
}

void MainWindow::on_backMenuIrr_3_clicked()
{
    ui->culturesStackWidget->setCurrentIndex(0);
}

void MainWindow::on_backMenuIrr_clicked()
{
    ui->culturesStackWidget->setCurrentIndex(0);
}
