#include <iostream>
#include <string>
#include <map>
#include <memory>

#include "veryheavydatabase.h"
#include "cacheproxydb.h"
#include "oneshotdb.h"

int main()
{
    auto real_db = VeryHeavyDatabase();
    auto limit_db = OneShotDB(std::addressof(real_db), 2);
    
    std::cout << limit_db.GetData("key") << std::endl;
    std::cout << limit_db.GetData("key") << std::endl;
    std::cout << limit_db.GetData("key") << std::endl;
    
    return 0;
}
