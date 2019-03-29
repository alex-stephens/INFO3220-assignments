#include "soundtrack.h"

Soundtrack::Soundtrack(QString filename)
    : filename(filename) { }


void Soundtrack::play() {
    QSound::play(filename);
}
