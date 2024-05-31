#ifndef CODER_H
#define CODER_H

class Coder
{
public:
    virtual void load(QByteArray&) = 0;
    virtual QByteArray& compress() = 0;
};

#endif // CODER_H
