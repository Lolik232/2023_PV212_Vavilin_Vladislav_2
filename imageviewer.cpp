#include "imageviewer.h"

ImageViewer::ImageViewer(QObject *parent)
    : QObject{parent}
{

}

QVector<Image> ImageViewer::images() const
{
    return QVector<Image>(m_images.begin(), m_images.end());
}

void ImageViewer::openImage(int index)
{
    auto& img = m_images.at(index);


    if(currentImage != &img){
        currentImage = &img;
        emit imageUpdated();
    }
}

void ImageViewer::openNewImage(Image img)
{
    m_images.push_back(img);
    emit imagesListUpdated();

    // image setter
    currentImage = &m_images.back();
    emit imageUpdated();
}
