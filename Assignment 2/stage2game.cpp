#include "stage2game.h"

Stage2Game::Stage2Game(QWidget *parent) :
    GameDialog(parent),
    background(Background(Coordinate(0, this->height(), this->height(), this->width()))),
    stickman_frame(1),
    counter(0) {

    background.setVelocity(Config::config()->getBackgroundVelocity());
    this->setFixedSize(Config::config()->getWorldWidth(), Config::config()->getWorldHeight());

    if (Config::config()->getBackgroundNumber() == 2) {
        this->setStyleSheet("background-color: #002855;"); //Dark Blue
    } else {
        this->setStyleSheet("background-color: #14ACF6;"); //Light Blue
    }

    // make obstacles
    int width = Config::config()->getObstacleWidth();
    int height = Config::config()->getObstacleHeight();
    int spacing = Config::config()->getObstacleSpacing();
    QString color = Config::config()->getObstacleColor();
    std::vector<int> int_obstacles = Config::config()->getObstacles();

    int repeat_span = (width + spacing) * int_obstacles.size();
    int obstacle_x = 1000; // starting position for first obstacle

    for (int o : int_obstacles) {
        Coordinate c(obstacle_x, o, Config::config()->getWorldHeight(), Config::config()->getWorldWidth());
        obstacles.push_back(Obstacle(c, height, width, repeat_span, Config::config()->getBackgroundVelocity(),color));
        obstacle_x += spacing + width;
    }

    //Initially have pause as false;
    paused = false;

    //Timer is used to have a continous loop
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(nextFrame()));
    timer->start(32);

}

Stage2Game::~Stage2Game() {
    delete timer;
}

void Stage2Game::paintEvent(QPaintEvent *event) {

    QPainter painter(this);

    background.render(painter, paused);

    for (auto& obs : obstacles) {
        obs.render(painter, paused);
    }

    // update the obstacles in the collision detector and check for upcoming collisions
    CollisionDetector detector(obstacles);
    detector.checkCollisions();
    detector.applyCollisions();

    // stickman dynamics update
    Config::config()->getStickman()->update();

    //Once the frame is the last, reset
    if (stickman_frame > 9) {
        stickman_frame = 1;
    }

    //Get the Pixmap of the respective frame
    QPixmap stickman = Config::config()->getStickman()->getPixmap(stickman_frame);

    //Used to slow down the animation
    if (counter == 2) {
        stickman_frame++;
        counter = 0;
    }

    //Only increment the counter if its not paused
    if (!paused) {
        counter++;
    }

    Coordinate stickman_coordinate(Config::config()->getStickman()->getXPosition() - (Config::config()->getStickman()->getWidth()*0.5),
                                   Config::config()->getStickman()->getYPosition() + Config::config()->getStickman()->getHeight(),
                                   this->height(),
                                   this->width());

    //Draw the stickman to the screen
    painter.drawPixmap(stickman_coordinate.getQtRenderingXCoordinate(),
                       stickman_coordinate.getQtRenderingYCoordinate(),
                       Config::config()->getStickman()->getWidth(),
                       Config::config()->getStickman()->getHeight(),
                       stickman);
}

void Stage2Game::keyPressEvent(QKeyEvent *event) {

    //See if a key on the keyboard has been pressed
    if (event->type()==QEvent::KeyPress) {

        QKeyEvent* key = static_cast<QKeyEvent*>(event);

        if ( key->key() == Qt::Key_Space) { // space was pressed
            int v = Config::config()->getStickman()->getYVelocity();
            Config::config()->getStickman()->jump();
        }

        if ( (key->key()==Qt::Key_P) ) { //P was pressed

            /*
             * Pause the screen
             * Show the pause dialog
            */
            pause();

            PauseDialog pause_dialog(&this->paused);
            pause_dialog.setModal(true);
            pause_dialog.setWindowTitle("Pause Screen");
            pause_dialog.exec();

        }

        if ( (key->key()==Qt::Key_Q) ) { //Q was pressed

            /*
             * Close the game dialog
             * Show the main menu dialog
            */

            close();

        }

    }

}

