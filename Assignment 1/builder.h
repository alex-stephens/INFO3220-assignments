#ifndef BUILDER_H
#define BUILDER_H

#include "config.h"

#include <QDialog>

class Builder
{
public:
    /**
     * @brief buildGame contructs a QDialog with the current configuration. The Game object inherts from QDialog, so this is
     *          used for instantiation of the main game window.
     * @return
     */
    virtual QDialog * buildGame() = 0;

    /**
     * @brief setConfig sets the configuration object - Concrete Builder classes could make use of subclassed versions of
     *          the Config base class depending what parameters are required
     * @param config object
     */
    virtual void setConfig(Config config) = 0;

};

#endif // BUILDER_H
