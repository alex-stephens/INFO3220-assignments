#include "game.h"

Game::Game(Background background, Sprite sprite)
    : QDialog(),
      ui(new Ui::Dialog),
      background(background),
      sprite(sprite)
{
    ui->setupUi(this);
    this->resize(WINDOW_WIDTH, WINDOW_HEIGHT);
    backgroundOffset = 0;


    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(nextFrame()));
    timer->start(16);
}

Game::Game(Config config)
    : QDialog(),
      ui(new Ui::Dialog),
      background(config.getBackgroundFile(), config.getVelocity()),
      sprite(Coordinate(config.getPosition(), config.getSize()/2, WINDOW_HEIGHT), config.getSize(),"sprite_", ".gif", 3)
{
    ui->setupUi(this);
    this->resize(WINDOW_WIDTH, WINDOW_HEIGHT);
    backgroundOffset = 0;


    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(nextFrame()));
    timer->start(16);
}

void Game::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_P){
        paused = !paused;
    }
    else if(event->key() == Qt::Key_N){
        background.toggleNightMode();
    }
}

Game::~Game()
{
    delete ui;
}

void Game::paintEvent(QPaintEvent *event) {

    QPainter painter(this);

    if (paused){
        Pause pause("pause_img.png");
        pause.render(painter);
    }
    else {
        background.render(painter);
        sprite.render(painter);
    }

}

void Game::nextFrame() {
    update();
}
