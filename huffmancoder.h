#ifndef HUFFMANCODER_H
#define HUFFMANCODER_H

#include <QByteArray>
#include <coder.h>
#include <statistics.h>

class HuffmanCoder : public Coder
{
    Statistics stats;
    QByteArray input;
    QByteArray output;

public:
    HuffmanCoder();
    void load(QByteArray&) override;
    QByteArray& compress() override;
};

#endif // HUFFMANCODER_H
