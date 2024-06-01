#ifndef STATISTICS_H
#define STATISTICS_H

#include <QHash>
#include <QByteArray>

class Statistics
{
    QHash<char, int> table;
public:
    Statistics();
    Statistics(const QByteArray&);
    void load(const QByteArray&);
    int getCharStat(char);
};

#endif // STATISTICS_H
