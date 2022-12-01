#ifndef BLOCKNOTE_H
#define BLOCKNOTE_H

#include <QMainWindow>

namespace Ui {
class blocknote;
}

class blocknote : public QMainWindow
{
    Q_OBJECT

public:
    explicit blocknote(QWidget *parent = nullptr);
    ~blocknote();

private slots:
    void on_actionnew_triggered();

    void on_actionopen_triggered();

    void on_actionsave_triggered();

    void on_actioncut_triggered();

    void on_actionundo_triggered();

    void on_actionredo_triggered();

    void on_actionpaste_triggered();

    void on_actionsave_as_triggered();

    void on_actioncopy_triggered();

private:
    Ui::blocknote *ui;
    QString mFilename;
};

#endif // BLOCKNOTE_H
