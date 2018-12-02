#ifndef RESIZER_H
#define RESIZER_H

#include <QStringList>
#include <arrayfire.h>

class Resizer
{
    void reSize(af::array pictures,int width,int height);
    void saveImages(af::array pictures);

public:
    Resizer();
    void start(QStringList fileNames, int width, int height);
};

#endif // RESIZER_H
