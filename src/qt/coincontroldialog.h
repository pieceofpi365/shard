#ifndef COINCONTROLDIALOG_H
#define COINCONTROLDIALOG_H

#include <QAbstractButton>
#include <QAction>
#include <QDialog>
#include <QList>
#include <QMenu>
#include <QPoint>
#include <QString>
#include <QTreeWidgetItem>
#include <QWidget>

namespace Ui {
    class CoinControlDialog;
}
class WalletModel;
class CCoinControl;
class SendCoinsDialog;

class CoinControlDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CoinControlDialog(QWidget *parent = 0);
    ~CoinControlDialog();

    void setModel(WalletModel *model);

    // static because also called from sendcoinsdialog
    void updateLabels(WalletModel*, SendCoinsDialog*);
    void updateLabelsCoinControl();

    static QList<qint64> payAmounts;
    static CCoinControl *coinControl;

private:
    Ui::CoinControlDialog *ui;
    WalletModel *model;
    int sortColumn;
    Qt::SortOrder sortOrder;

    QMenu *contextMenu;
    QTreeWidgetItem *contextMenuItem;
    QAction *copyTransactionHashAction;
    QAction *lockAction;
    QAction *unlockAction;

    QString strPad(QString, int, QString);
    void sortView(int, Qt::SortOrder);
    void updateView();

    enum
    {
        COLUMN_CHECKBOX,
        COLUMN_AMOUNT,
	    COLUMN_CONFIRMATIONS,
		COLUMN_AGE,
		COLUMN_POTENTIALSTAKE,
		COLUMN_TIMEESTIMATE,
        COLUMN_WEIGHT,        
        COLUMN_LABEL,
        COLUMN_ADDRESS,
        COLUMN_DATE,
		COLUMN_AGE_INT64,
        COLUMN_POTENTIALSTAKE_INT64,
        COLUMN_TXHASH,
        COLUMN_VOUT_INDEX,
        COLUMN_AMOUNT_INT64,
    };

private slots:
    void showMenu(const QPoint &);
    void copyAmount();
    void copyLabel();
    void copyAddress();
    void copyTransactionHash();
    void lockCoin();
    void unlockCoin();
    void clipboardQuantity();
    void clipboardAmount();
    void clipboardFee();
    void clipboardAfterFee();
    void clipboardBytes();
    void clipboardLowOutput();
    void clipboardChange();
    void radioTreeMode(bool);
    void radioListMode(bool);
    void viewItemChanged(QTreeWidgetItem*, int);
    void headerSectionClicked(int);
    void buttonBoxClicked(QAbstractButton*);
    void buttonSelectAllClicked();
    void customSelectCoins();
    void updateLabelLocked();
};

#endif // COINCONTROLDIALOG_H
