#ifndef SOUNDTRACK_H
#define SOUNDTRACK_H

#include <QString>
#include <QSound>

class Soundtrack : public QSound
{
public:
    Soundtrack(QString filename);

    static void play();


private:
    QString filename;
};

#endif // SOUNDTRACK_H
