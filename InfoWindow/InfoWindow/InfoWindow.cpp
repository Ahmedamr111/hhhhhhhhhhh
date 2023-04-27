#include <QtWidgets/QApplication>
#include "InfoWindow.h"
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include <QtWidgets/QMainWindow>

class InfoWindow : public QMainWindow
{
    Q_OBJECT

public:
    InfoWindow(QWidget* parent = nullptr);

private slots:
    void onTeamSelected(const QString& teamName);
    void onPlayerSelected(const QString& playerName);

private:
    void createTeamPage();
    void createPlayerPage();

    QComboBox* m_teamComboBox;
    QLabel* m_rankLabel;
    QLabel* m_pointsLabel;
    QLabel* m_goalsLabel;
    QLabel* m_winsLabel;
    QLabel* m_drawsLabel;
    QLabel* m_lossesLabel;

    QComboBox* m_playerComboBox;
    QLabel* m_nameLabel;
    QLabel* m_positionLabel;
    QLabel* m_ageLabel;
};

InfoWindow::InfoWindow(QWidget* parent)
    : QMainWindow(parent)
{
    m_teamComboBox = new QComboBox(this);
    connect(m_teamComboBox, QOverload<const QString&>::of(&QComboBox::activated), this, &InfoWindow::onTeamSelected);
    createTeamPage();

    setCentralWidget(m_teamComboBox);
    setWindowTitle("Football Info");
    resize(400, 300);
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

    label = new QLabel("Wins:",
