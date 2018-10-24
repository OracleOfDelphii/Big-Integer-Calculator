#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<iostream>
#include <QRegExp>
#include <QMessageBox>
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
    string flag = "+"; // by-default
    /* Private constructor to prevent instancing. */
    operation(){
        result = "0";
    }

public:
    string getResult(){
        return this->result;
    }
    void setResult(string result){
        this->result = this->flag + result;
    }
    void setFlag(string flag){
        this->flag = flag;
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
    if (!numericFormatException()){
        QLineEdit* t1 =  ui->lineEdit;
        QLineEdit* t2 = ui->lineEdit_2;
        std::string t1_string =  t1->text().toStdString();
        std::string t2_string = t2->text().toStdString();
        big_integer a(t1_string) , b(t2_string); // two variables a and b
        std::string t3_string = a + b;
        operation::getInstance()->setFlag("+");
        operation::getInstance()->setResult(t3_string);
    }
}

void MainWindow::on_pushButton_5_clicked()
{
    operation *op = operation::getInstance();
    ui->plainTextEdit->setPlainText(QString::fromStdString(op->getResult()));
}

bool MainWindow::numericFormatException(){
    QString t1 = ui->lineEdit->text().replace(0 , 1);
    QString t2 = ui->lineEdit_2->text().replace(0 , 1);
    QRegExp re("\\d*");  // a digit (\d), zero or more times (*)
    if (!re.exactMatch(t1) || !re.exactMatch(t2)){
        QMessageBox msgBox;
        msgBox.setText("ill-formed entry");
        msgBox.setInformativeText("Do you want to save your changes?");
        msgBox.setStandardButtons(QMessageBox::Close);
        msgBox.exec();
        return true;
    }
    return false;
}
void MainWindow::on_pushButton_2_clicked()
{
    std::string t1 = ui->lineEdit->text().toStdString() , t2 = ui->lineEdit_2->text().toStdString();
    if (!numericFormatException()){
        big_integer a(t1) , b(t2);
        operation::getInstance()->setFlag("+");
        operation::getInstance()->setResult(a*b);
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    std::string t1 = ui->lineEdit->text().toStdString() , t2 = ui->lineEdit_2->text().toStdString();
    if (!numericFormatException()){
        big_integer a(t1) , b(t2);

        operation::getInstance()->setFlag("+");
        if(big_integer::cmp(t1,t2)<0){
            operation::getInstance()->setFlag("-");
        }
        operation::getInstance()->setResult(a-b);
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    std::string t1 = ui->lineEdit->text().toStdString() , t2 = ui->lineEdit_2->text().toStdString();
    if (!numericFormatException()){
        big_integer a(t1) , b(t2);
        operation::getInstance()->setFlag("+");
        operation::getInstance()->setResult(a/b);
    }
}
