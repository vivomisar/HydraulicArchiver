#ifndef HUFFMANCODER_H
#define HUFFMANCODER_H

class HuffmanCoder : public Coder
{
    Statistics stats;
    QByteArray input;
    QByteArray output;

public:
    HuffmanCoder();
    void load(QByteArray&);
    QByteArray& compress();
};

#endif // HUFFMANCODER_H
