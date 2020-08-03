#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QGridLayout * layout = new QGridLayout();

    auto * but1 = new QPushButton("Start");
    auto * but2 = new QPushButton("Wall");
    auto * but3 = new QPushButton("End");
    auto * but4 = new QPushButton("Find");

    auto * list = new QComboBox(this);
    list->addItem("Dijkstra's algorithm");
    list->addItem("A* algorithm");
    list->addItem("Sample algorithm");

    this->graphView = new QGraphicsView();
    auto * graphScene = new QGraphicsScene(this);

    int rect_width = (graphView->width() - OFFSET) / BOARD_WIDTH, rect_height = ( graphView->height() - OFFSET ) / BOARD_HEIGHT;

    for(int i = 0; i < BOARD_WIDTH; ++i) {
        for(int j = 0; j < BOARD_HEIGHT; ++j) {
            auto * rect = new QGraphicsRectItem(rect_width * i, rect_height * j, rect_width, rect_height);
            rect->setBrush(QBrush(Qt::white));
            rects.push_back(rect);
            graphScene->addItem(rect);
        }
    }

    graphView->setStyleSheet("background-color: rgb(128, 128, 128)");
    graphView->setScene(graphScene);

    graphView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    graphView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    layout->addWidget(but1, WINDOW_GRID_SIZE, 1);
    layout->addWidget(but2, WINDOW_GRID_SIZE, 2);
    layout->addWidget(but3, WINDOW_GRID_SIZE, 3);
    layout->addWidget(but4, WINDOW_GRID_SIZE, 6);

    layout->addWidget(list, WINDOW_GRID_SIZE, 4, 1, 2);

    layout->addWidget(graphView, 1, 1, WINDOW_GRID_SIZE - 1, WINDOW_GRID_SIZE);

    QWidget * widget = new QWidget();
    widget->setLayout(layout);

    setCentralWidget(widget);

    //graphView->fitInView(graphView->scene()->sceneRect(), Qt::KeepAspectRatio);
    graphView->ensureVisible(graphView->scene()->sceneRect());
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);

//    int rect_width = (this->graphView->width() - OFFSET) / BOARD_WIDTH, rect_height = ( this->graphView->height() - OFFSET ) / BOARD_HEIGHT;

//    for(int i = 0; i < BOARD_WIDTH; ++i) {
//        for(int j = 0; j < BOARD_HEIGHT; ++j) {
//            rects[(j * BOARD_WIDTH) + i]->setRect(rect_width * i, rect_height * j, rect_width, rect_height);
//        }
//    }

    this->graphView->fitInView(this->graphView->scene()->sceneRect(), Qt::KeepAspectRatio);
//    this->graphView->scene()->sceneRect().center();
}

MainWindow::~MainWindow()
{

}

