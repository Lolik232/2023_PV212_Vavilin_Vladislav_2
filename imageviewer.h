#ifndef IMAGEVIEWER_H
#define IMAGEVIEWER_H

#include <QObject>
#include <Qstring>

struct Image
{
    QString fileName;
    QString fullPath;
};


class ImageViewer : public QObject
{
    Q_OBJECT
public:
    explicit ImageViewer(QObject *parent = nullptr);

    Image* currentImage;

    QVector<Image> images() const;

signals:
    void imageUpdated();
    void imagesListUpdated();

public slots:
    void openImage(int index);
    void openNewImage(Image img);

private:
    std::vector<Image> m_images = {
      {"file1.txt", "file"},
      {"file2.txt", "file"},
      {"file3.txt", "file"}
    };
};

#endif // IMAGEVIEWER_H
