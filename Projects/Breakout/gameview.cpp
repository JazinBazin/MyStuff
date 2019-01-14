#include "gameview.h"
#include "ball.h"
#include "brick.h"
#include <QKeyEvent>
#include <QMouseEvent>
#include <QGraphicsPixmapItem>
#include <QIcon>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include "gameresultwidget.h"

void GameView::keyPressEvent(QKeyEvent *event)
{
    if(ball->isBallMoving()) {
        qreal shift = scene->width() * 0.05;
        if(event->key() == Qt::Key_Left)
            platform->moveLeft(shift);
        else if(event->key() == Qt::Key_Right)
            platform->moveRight(shift);
    }
    else if(event->key() == Qt::Key_Space)
        ball->startMoving();
}

void GameView::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::MouseButton::LeftButton) {
        if(ball->isBallMoving())
            platform->moveCenterToX(event->pos().x());
        else
            ball->startMoving();
    }
}

void GameView::mouseMoveEvent(QMouseEvent *event) {
    platform->moveCenterToX(event->pos().x());
}

void GameView::slotBallReachedTheLowerBorder() {
    moveBallEndPlatformToCenter();
    // remove one image of the user's life from the scene
    scene->removeItem(userLifes.back());
    userLifes.pop_back();
}

void GameView::slotGameEnds(bool isVictory, quint32 score) {
    QPointF centerPosition(this->pos().x() + this->rect().width() / 2,
                           this->pos().y() + this->rect().height() / 2);
    GameResultWidget *gameResults = new GameResultWidget(isVictory, score, highscore, centerPosition);
    QObject::connect(gameResults, &GameResultWidget::signalCloseWindow,
                     this, &GameView::slotCloseGameResults);
    gameResults->show();
}

void GameView::slotCloseGameResults(quint32 score, bool levelComplete) {
    if(levelComplete && isNextLevelExists()) {
        ++levelID;
        moveBallEndPlatformToCenter();
        loadLevel(levelID);
    }
    else {
        emit signalGameEnds(score);
        this->close();
    }
}

void GameView::moveBallEndPlatformToCenter() {
    ball->setPos((scene->width() - ball->pixmap().width()) / 2,
                 scene->height() - ball->pixmap().height() - platform->rect().height() - platform->borderWidth() * 2);
    platform->setPos((scene->width() - platform->rect().width() - platform->borderWidth() * 2) / 2,
                     scene->height() - platform->rect().height() - platform->borderWidth() * 2);
}

bool GameView::isNextLevelExists() const {
    QSqlDatabase db = QSqlDatabase::database("breakout");
    db.setDatabaseName("breakout.db");
    db.open();
    QSqlQuery query(db);
    query.prepare("select id_level from level where id_level = :id_level;");
    query.bindValue(":id_level", QString::number(levelID + 1));
    query.exec();
    bool exists = query.next();
    db.close();
    return exists;
}

void GameView::loadLevel(quint32 levelNumber) {
    QSqlDatabase db = QSqlDatabase::database("breakout");
    db.setDatabaseName("breakout.db");
    db.open();
    QSqlQuery query(db);
    query.prepare("select width, height, x, y, color, border_color " \
                  "from brick " \
                  "where id_brick in " \
                  "( " \
                  "select id_brick " \
                  "from level_content " \
                  "where id_level = :id_level " \
                  ");"
                  );
    query.bindValue(":id_level", QString::number(levelNumber));
    query.exec();

    qreal width, height, x, y;
    QString color, borderColor;
    QSqlRecord record = query.record();
    while(query.next()) {
        width = query.value(record.indexOf("width")).toReal();
        height = query.value(record.indexOf("height")).toReal();
        x = query.value(record.indexOf("x")).toReal();
        y = query.value(record.indexOf("y")).toReal();
        color = query.value(record.indexOf("color")).toString();
        borderColor = query.value(record.indexOf("border_color")).toString();

        Brick *brick = new Brick();
        brick->setRect(0, 0, width, height);
        brick->setPos(x, y);
        brick->setColor(QColor(color));
        brick->setBorderColor(QColor(borderColor));

        scene->addItem(brick);
    }

    db.close();
}

GameView::GameView(quint32 levelNumber, quint32 Highscore) :
    QGraphicsView(), levelID(levelNumber), highscore(Highscore)
{
    this->setFixedSize(800, 600);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setWindowIcon(QIcon("ball25x25.png"));

    // create graphics scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 800, 600);
    this->setScene(scene);

    // create platform
    platform = new Platform();
    qreal platformWidth = scene->width() * 0.25;
    qreal platformHeight = scene->height() * 0.05;
    platform->setRect(0, 0, platformWidth, platformHeight);
    scene->addItem(platform);

    // create ball
    ball = new Ball(this->sceneRect());
    scene->addItem(ball);

    QObject::connect(ball, &Ball::signalBallReachedTheLowerBorder,
                     this, &GameView::slotBallReachedTheLowerBorder);
    QObject::connect(ball, &Ball::signalGameEnds,
                     this, &GameView::slotGameEnds);

    moveBallEndPlatformToCenter();

    // create user lifes;
    for(int i = 0; i < 3; ++i) {
        QGraphicsPixmapItem *userLife = new QGraphicsPixmapItem(QPixmap("life25x25.png"));
        userLife->setPos(scene->width() - userLife->pixmap().width() * (i + 1), scene->height() - userLife->pixmap().height());
        userLifes.push_back(userLife);
        scene->addItem(userLife);
    }

    //load level
    loadLevel(levelNumber);
}

GameView::~GameView() {
    delete scene;
}

