#ifndef ONESHOTDB_H
#define ONESHOTDB_H

class OneShotDB : VeryHeavyDatabase
{
public:
    explicit OneShotDB(VeryHeavyDatabase* real_object, size_t shots = 1) : real_db_(real_object) , shots_(shots) {}
    ~OneShotDB() = default;
    
    std::string GetData(const std::string &key) noexcept
    {
        if (times_shooted.find(key) == times_shooted.end())
        {
            times_shooted.insert( {key, 0} );
        }
        
        if (times_shooted.at(key) < shots_)
        {
            ++times_shooted[key];
            return real_db_->GetData(key);
        }
        return err_msg;
    }
    
private:
    VeryHeavyDatabase* real_db_;
    size_t shots_;
    std::map<std::string, size_t> times_shooted;
    const std::string err_msg = "error";
    
};

#endif // ONESHOTDB_H
