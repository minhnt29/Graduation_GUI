#ifndef OPENDOORCOUNTER_H
#define OPENDOORCOUNTER_H

#include <QDialog>
#include <QTableWidget>
#include <QTableWidgetItem>

typedef struct {
    QTableWidgetItem* id;
    QTableWidgetItem* name;
    QTableWidgetItem* time;
    QTableWidgetItem* date;
} OpenDoorView;

typedef enum {
    kId,
    kName,
    kTime,
    kDate
} TableColumn;

namespace Ui {
class OpenDoorCounter;
}

class OpenDoorCounter : public QDialog
{
    Q_OBJECT

public:
    explicit OpenDoorCounter(QWidget *parent = nullptr);
    ~OpenDoorCounter();
    void showOpenDoorCounter(void);
    void closeOpenDoorCounter(void);
    void clickReload(void);
    Ui::OpenDoorCounter *ui;
private:

};

#endif // OPENDOORCOUNTER_H
