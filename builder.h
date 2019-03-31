#ifndef BUILDER_H
#define BUILDER_H

#include "config.h"

#include <QDialog>

class Builder
{
public:
    /**
     * @brief buildGame contructs a QDialog
     * @return
     */
    virtual QDialog * buildGame() = 0;

    virtual void setConfig(Config c) = 0;

};

#endif // BUILDER_H
