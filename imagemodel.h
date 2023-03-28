#ifndef IMAGEMODEL_H
#define IMAGEMODEL_H

#include <QAbstractListModel>

class ImageModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit ImageModel(QObject *parent = nullptr);

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:

};

#endif // IMAGEMODEL_H