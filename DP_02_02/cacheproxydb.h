#ifndef CACHEPROXYDB_H
#define CACHEPROXYDB_H

class CacheProxyDB : VeryHeavyDatabase
{
public:    
    explicit CacheProxyDB(VeryHeavyDatabase* &&real_object) : real_db_(std::move(real_object)) {}
    ~CacheProxyDB() { delete real_db_; real_db_ = nullptr; }
    
    std::string GetData(const std::string &key) noexcept
    {
        if (cache_.find(key) == cache_.end())
        {
            std::cout << "Get from real object\n";
            cache_[key] = real_db_->GetData(key);
        }
        else
        {
            std::cout << "Get from cache\n";
        }
        return cache_.at(key);
    }
    
private:
    std::map<std::string, std::string> cache_;
    VeryHeavyDatabase* real_db_;
};

#endif // CACHEPROXYDB_H
