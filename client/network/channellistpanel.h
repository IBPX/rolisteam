#ifndef CHANNELLISTPANEL_H
#define CHANNELLISTPANEL_H

#include <QWidget>

namespace Ui {
class ChannelListPanel;
}
#include "network/channelmodel.h"
#include "network/networkmessagereader.h"
#include "network/networkmessagewriter.h"

class ChannelListPanel : public QWidget
{
    Q_OBJECT

public:
    enum GROUP {VIEWER,ADMIN};
    explicit ChannelListPanel(QWidget *parent = 0);
    virtual ~ChannelListPanel();

    void processMessage(NetworkMessageReader* msg);
    void sendOffModel();

    ChannelListPanel::GROUP currentGRoup() const;
    void setCurrentGRoup(const GROUP &currentGRoup);

    bool isAdmin();
    template <typename T>
    T indexToPointer(QModelIndex index);

    QString serverName() const;
    void setServerName(const QString &serverName);

    void setLocalPlayerId(const QString& id);

public slots:
    void showCustomMenu(QPoint pos);
    void sendOffLoginAdmin(QString str = QString());

protected slots:
    void addChannelAsSibbling();
    void lockChannel();
    void kickUser();
    void banUser();
    void addChannel();
    void deleteChannel();
    void joinChannel();
    void editChannel();
    void logAsAdmin();
private:
    Ui::ChannelListPanel *ui;
    ChannelModel* m_model;

    QAction* m_edit;
    QAction* m_lock;
    QAction* m_join;
    QAction* m_addChannel;
    QAction* m_addSubchannel;
    QAction* m_deleteChannel;
    QAction* m_setDefault;
    QAction* m_admin;
    QAction* m_kick;

    GROUP m_currentGroup;
    QModelIndex m_index;
    QString m_serverName;
    QString m_localPlayerId;
};

#endif // CHANNELLISTPANEL_H
