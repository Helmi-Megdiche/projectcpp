#include "blocknote.h"
#include "ui_blocknote.h"
#include <QFileDialog>
#include <QTextStream>
blocknote::blocknote(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::blocknote)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

blocknote::~blocknote()
{
    delete ui;
}

void blocknote::on_actionnew_triggered()
{
    mFilename ="" ;
      ui->textEdit->setPlainText("");
}
void blocknote::on_actionsave_triggered()
{
    QFile sFile(mFilename);
     if(sFile.open(QFile::WriteOnly | QFile::Text))
     {
         QTextStream out(&sFile);
         out << ui->textEdit->toPlainText();

       sFile.flush();
       sFile.close();

     }
}
void blocknote::on_actionsave_as_triggered()
{
    QString file= QFileDialog::getSaveFileName(this,"Open a file");
        if(!file.isEmpty())
        {
          QFile sFile(file);
          mFilename =file;
          on_actionsave_triggered();

        }
}

void blocknote::on_actionopen_triggered()
{
    QString file= QFileDialog::getOpenFileName(this,"Open a file");
     if(!file.isEmpty())
     {
       QFile sFile(file);
       if(sFile.open(QFile::ReadOnly | QFile::Text))
       {
         QTextStream in (&sFile);
         QString text = in.readAll();
         sFile.close();
         ui->textEdit->setPlainText(text);


       }

     }
}

void blocknote::on_actioncopy_triggered()
{
    ui->textEdit->copy();
}

void blocknote::on_actioncut_triggered()
{
     ui->textEdit->cut();
}


void blocknote::on_actionundo_triggered()
{
     ui->textEdit->undo();
}

void blocknote::on_actionredo_triggered()
{
     ui->textEdit->redo();
}

void blocknote::on_actionpaste_triggered()
{
     ui->textEdit->paste();
}
