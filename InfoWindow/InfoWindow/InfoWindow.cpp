#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QApplication>
#include "qlabel.h"
#include "qpushbutton.h"
#include "qpixmap.h"
#include "qdialog.h"
#include "qlayout.h"
#include "QVBoxLayout"
#include "QHBoxLayout"
#include "QGroupBox"
#include "qlineedit.h"
#include "qgridlayout.h"
#include "qmessagebox.h"
#include <fstream>
#include "string"
#include "iostream"
#include <QFile>
#include <QTextStream>
#include <algorithm>
#include <ctime>
#include <chrono>
#include <iomanip>
#include <QtWidgets/QScrollArea>

using namespace std;
using namespace std::chrono;

class InfoWindow : public QMainWindow
{
    Q_OBJECT


    public:
        InfoWindow(QWidget* parent = nullptr) : QMainWindow (parent)
        {
            m_teamComboBox = new QComboBox(this);
            connect(m_teamComboBox, QOverload<const QString&>::of(&QComboBox::activated), this, &InfoWindow::onTeamSelected);
            createTeamPage();

            setCentralWidget(m_teamComboBox);
            setWindowTitle("league info");
            setGeometry(0, 0, 1920, 1080);
            QPixmap background(":/images/images/vvZQmlz-football-field-wallpapers.jpg");
            backgroundlabel = new QLabel(this);
            backgroundlabel->setPixmap(background);
            backgroundlabel->setFixedSize(width(), height());
            gridlayout = new QGridLayout();
            grouplayout = new QGroupBox();
            mainlayout = new QVBoxLayout(this);
            setLayout(mainlayout);
            grouplayout->setTitle(" ASU Football League ");
            grouplayout->setStyleSheet("background: rgb(238, 255, 238);	font:  Bold 14pt Segoe UI;color: rgb(255, 0, 127);");
            grouplayout->setFixedSize(880, 550);
            m_rankLabel = new QLabel("  rank ", this);
            m_pointsLabel = new QLabel(" points ", this);
            m_goalsLabel = new QLabel(" the goal ", this);
            m_winsLabel = new QLabel(" wins ", this);
            m_drawsLabel = new QLabel("  draws ", this);
            m_lossesLabel = new QLabel("  losses ", this);

            gridlayout->addWidget(m_rankLabel, 0, 1);
            gridlayout->addWidget(m_pointsLabel, 0, 2);
            gridlayout->addWidget(m_goalsLabel, 0, 3);
            gridlayout->addWidget(m_winsLabel, 0, 4);
            gridlayout->addWidget(m_drawsLabel, 0, 5);
            gridlayout->addWidget(m_lossesLabel, 0, 6);
            grouplayout->setLayout(gridlayout);
        }

    private slots:
        void onTeamSelected(const QString& teamName);
        void onPlayerSelected(const QString& playerName);
        void onSwitchButtonClicked();

    private:
        void createTeamPage();
        void createPlayerPage();

        QComboBox* m_teamComboBox;
        QLabel* backgroundlabel;
        QLabel* m_rankLabel;
        QLabel* m_pointsLabel;
        QLabel* m_goalsLabel;
        QLabel* m_winsLabel;
        QLabel* m_drawsLabel;
        QLabel* m_lossesLabel;
        QGridLayout* gridlayout;
        QGroupBox* grouplayout;
        QVBoxLayout * mainlayout;

        QComboBox* m_playerComboBox;
        QLabel* m_nameLabel;
        QLabel* m_positionLabel;
        QLabel* m_ageLabel;
        
        QPushButton* m_switchButton;
        bool m_isTeamPage;
    };
    void InfoWindow::createTeamPage()
    {
        QWidget* teamPage = new QWidget(this);
        QVBoxLayout* layout = new QVBoxLayout(teamPage);

        QLabel* label = new QLabel("Select a team:", teamPage);
        layout->addWidget(label);

        m_teamComboBox = new QComboBox(teamPage);
        m_teamComboBox->addItem("Real Madrid");
        m_teamComboBox->addItem("Barcelona");
        m_teamComboBox->addItem("Liverpool");
        m_teamComboBox->addItem("Manchester United");
        m_teamComboBox->addItem("Bayern Munich");
        layout->addWidget(m_teamComboBox);

        label = new QLabel("Rank:", teamPage);
        layout->addWidget(label);
        m_rankLabel = new QLabel(teamPage);
        layout->addWidget(m_rankLabel);

        label = new QLabel("Points:", teamPage);
        layout->addWidget(label);
        m_pointsLabel = new QLabel(teamPage);
        layout->addWidget(m_pointsLabel);

        label = new QLabel("Goals:", teamPage);
        layout->addWidget(label);
        m_goalsLabel = new QLabel(teamPage);
        layout->addWidget(m_goalsLabel);

        label = new QLabel("Wins:", teamPage);
        layout->addWidget(label);
        m_winsLabel = new QLabel(teamPage);
        layout->addWidget(m_winsLabel);

        label = new QLabel("Draws:", teamPage);
        layout->addWidget(label);
        m_drawsLabel = new QLabel(teamPage);
        layout->addWidget(m_drawsLabel);

        label = new QLabel("Losses:", teamPage);
        layout->addWidget(label);
        m_lossesLabel = new QLabel(teamPage);
        layout->addWidget(m_lossesLabel);

        teamPage->setLayout(layout);
        setCentralWidget(teamPage);
    }

    void InfoWindow::createPlayerPage()
    {
        QWidget* playerPage = new QWidget(this);
        QVBoxLayout* layout = new QVBoxLayout(playerPage);

        QLabel* label = new QLabel("Select a player:", playerPage);
        layout->addWidget(label);

        m_playerComboBox = new QComboBox(playerPage);
        m_playerComboBox->addItem("Cristiano Ronaldo");
        m_playerComboBox->addItem("Lionel Messi");
        m_playerComboBox->addItem("Mohamed Salah");
        m_playerComboBox->addItem("Neymar Jr.");
        m_playerComboBox->addItem("Robert Lewandowski");
        layout->addWidget(m_playerComboBox);


        label = new QLabel("Name:", playerPage);
        layout->addWidget(label);
        m_nameLabel = new QLabel(playerPage);
        layout->addWidget(m_nameLabel);

        label = new QLabel("Position:", playerPage);
        layout->addWidget(label);
        m_positionLabel = new QLabel(playerPage);
        layout->addWidget(m_positionLabel);

        label = new QLabel("Age:", playerPage);
        layout->addWidget(label);
        m_ageLabel = new QLabel(playerPage);
        layout->addWidget(m_ageLabel);

        connect(m_playerComboBox, QOverload<const QString&>::of(&QComboBox::activated), this, &InfoWindow::onPlayerSelected);

        setCentralWidget(playerPage);
    }
    void InfoWindow::onTeamSelected(const QString& teamName)
    {
        m_rankLabel->setText(QString::number(qrand() % 20 + 1));
        m_pointsLabel->setText(QString::number(qrand() % 50 + 1));
        m_goalsLabel->setText(QString::number(qrand() % 100 + 1));
        m_winsLabel->setText(QString::number(qrand() % 20 + 1));
        m_drawsLabel->setText(QString::number(qrand() % 10 + 1));
        m_lossesLabel->setText(QString::number(qrand() % 20 + 1));

        createPlayerPage();
        setCentralWidget(m_playerComboBox);
        setWindowTitle("Football Players");
        resize(400, 300);
    }

    void InfoWindow::onPlayerSelected(const QString& playerName)
    {
        m_nameLabel->setText(playerName);
        m_positionLabel->setText(QString::number(qrand() % 4 + 1));
        m_ageLabel->setText(QString::number(qrand() % 25 + 18));

        setWindowTitle("Player Info");
        setCentralWidget(m_nameLabel);
        resize(400, 300);
    }

