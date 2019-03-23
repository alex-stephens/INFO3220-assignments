#include "config.h"

Config::Config(QString path) {

    QDomDocument dom;

    QFile f("/Users/alex/Dropbox/University/2019 Semester 1/INFO3220/INFO3220-assignment1/config.xml");

    // Set data into the QDomDocument before processing
    dom.setContent(&f);
    f.close();

    // Extract the root markup
    QDomElement root = dom.documentElement();

    for (int i = 0; i < root.childNodes().count(); i++){

        QDomNode child = root.childNodes().at(i);

        if (child.nodeName() == "size"){
            QString s = child.firstChild().toText().data();
            size = SIZE[s];
        }

        else if (child.nodeName() == "position") {
            position = child.firstChild().toText().data().toInt();
        }

        else if (child.nodeName() == "velocity") {
            velocity = child.firstChild().toText().data().toInt();
        }

        else if (child.nodeName() == "background") {
            background_file = child.firstChild().toText().data();
        }

        else {
            throw std::invalid_argument("Invalid configuration parameters");
        }
    }

    qDebug() << "";
    qDebug() << "";

    qDebug() << position;
    qDebug() << velocity;
    qDebug() << size;
    qDebug() << background_file;
}
