#include "resizer.h"
#include <QDebug>
#include <string>
using namespace af;



Resizer::Resizer(){}

void Resizer::start(QStringList fileNames, int width, int height){
    array pictures;
    array pic;

    for(int i=0;i<fileNames.length();i++){
        pic=loadImage(fileNames[i].toStdString().c_str(),true);// nacitanie obrazku
        pic=resize(pic,height,width); // zmensenie na zadany rozmer
        pictures=join(2,pictures,pic); // pridanie  k ostatnym
    }
    this->saveImages(pictures);

}


void Resizer::saveImages(array pictures){

    for(int i=0;i<pictures.dims(2);i++){
        std::string number=std::to_string(i)+".jpg";
        saveImage(number.c_str(),pictures(span,span,i));
    }
}
