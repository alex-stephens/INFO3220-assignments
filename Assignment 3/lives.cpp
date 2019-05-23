#include "lives.h"
#include <iostream>

Lives::Lives() {
    for (int i = 0; i < 10; i++) {
        std::string spritePath = ":sprites/" + std::to_string(i) + ".png";
        QPixmap sprite(QString::fromStdString(spritePath));
        digits[i] = sprite;
    }
}

void Lives::decrement() {
    if (numLives > 0) {
        numLives--;
        std::cout << "lives reduced to: " << numLives << std::endl;
    }
}

// Render score from left to right. Requires FILO reading of integer
void Lives::render(Renderer &renderer) {
    std::stack<int> number;
    unsigned int lives = numLives;
    while (lives > 0) {
        number.push(lives % 10);
        lives = lives / 10;
    }

    int length = number.size();
    for (int i = 0; i < length; i++) {
        renderer.draw(700+i*10, 40, digits[number.top()]);
        number.pop();
    }
}
