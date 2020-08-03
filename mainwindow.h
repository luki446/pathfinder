#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QPushButton>
#include <QGridLayout>
#include <QLineEdit>
#include <QFrame>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QComboBox>

constexpr int WINDOW_GRID_SIZE = 6;
constexpr int BOARD_WIDTH = 25, BOARD_HEIGHT = 15, OFFSET = 80;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void resizeEvent(QResizeEvent* event);
    ~MainWindow();
private:
    QGraphicsView *graphView;
    std::vector<QGraphicsRectItem *> rects;
};
#endif // MAINWINDOW_H
