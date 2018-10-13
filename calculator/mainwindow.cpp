#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<array>
#include<iostream>
#include <string>
#include"biginteger.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
class operation
{
    private:
        /* Here will be the instance stored. */
        static operation* instance;
        string result;
        /* Private constructor to prevent instancing. */
        operation(){
            result = "0";
        }

    public:
        string getResult(){
            return this->result;
        }
        void setResult(string result){
            this->result = result;
        }
        /* Static access method. */
        static operation* getInstance();
};

/* Null, because instance will be initialized on demand. */
operation* operation::instance = nullptr;

operation* operation::getInstance()
{
    if (instance == nullptr)
    {
        instance = new operation();
    }
    return instance;
}


void MainWindow::on_pushButton_clicked()
{
    QLineEdit* t1 =  ui->lineEdit;
    QLineEdit* t2 = ui->lineEdit_2;
    QPlainTextEdit* t3 = ui->plainTextEdit;
    std::string t1_string =  t1->text().toStdString();
    std::string t2_string = t2->text().toStdString();
    big_integer a(t1_string) , b(t2_string); // two variables a and b
    std::string t3_string = a + b;
    operation::getInstance()->setResult(t3_string);
}

void MainWindow::on_pushButton_5_clicked()
{
    operation *op = operation::getInstance();
    ui->plainTextEdit->setPlainText(QString::fromStdString(op->getResult()));
}

void MainWindow::on_pushButton_2_clicked()
{
    std::string t1 = ui->lineEdit->text().toStdString() , t2 = ui->lineEdit_2->text().toStdString();
    big_integer a(t1) , b(t2);
    operation::getInstance()->setResult(a*b);
}

void MainWindow::on_pushButton_3_clicked()
{
    std::string t1 = ui->lineEdit->text().toStdString() , t2 = ui->lineEdit_2->text().toStdString();
    big_integer a(t1) , b(t2);
    operation::getInstance()->setResult(a-b);
}

void MainWindow::on_pushButton_4_clicked()
{
    std::string t1 = ui->lineEdit->text().toStdString() , t2 = ui->lineEdit_2->text().toStdString();
    big_integer a(t1) , b(t2);
    operation::getInstance()->setResult(a/b);
}
