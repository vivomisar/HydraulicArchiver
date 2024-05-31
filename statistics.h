#ifndef STATISTICS_H
#define STATISTICS_H

class Statistics
{
    QHash<char, int> table;
public:
    Statistics(const QByteArray&);
    int getCharStat(char);
};

#endif // STATISTICS_H
