#ifndef VERYHEAVYDATABASE_H
#define VERYHEAVYDATABASE_H

class VeryHeavyDatabase
{
public:
    std::string GetData(const std::string &key) const noexcept
    {
        return "Very Big Data String: value(" + key + ")";
    }
};

#endif // VERYHEAVYDATABASE_H
