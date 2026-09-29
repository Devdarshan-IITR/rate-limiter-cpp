#include "Devdarshan_IITR.hpp"
#include <iostream>
using namespace std;

int main() {
    Devdarshan_IITR::RateLimiter limiter;

     string user = "alice";
    int maxReq = 3;
    int window = 10;

     cout << "=== Devdarshan_IITR Rate Limiter ===" <<  endl;
     cout << "User: " << user << ", Max: " << maxReq << " req in " << window << " sec" <<  endl <<  endl;

    bool ok = limiter.isAllowed(user, 0, maxReq, window);
     cout << "t=0:  " << (ok ? "ALLOWED" : "BLOCKED") <<  endl;

    ok = limiter.isAllowed(user, 2, maxReq, window);
     cout << "t=2:  " << (ok ? "ALLOWED" : "BLOCKED") <<  endl;

    ok = limiter.isAllowed(user, 5, maxReq, window);
     cout << "t=5:  " << (ok ? "ALLOWED" : "BLOCKED") <<  endl;

    ok = limiter.isAllowed(user, 6, maxReq, window);
     cout << "t=6:  " << (ok ? "ALLOWED" : "BLOCKED") << " <-- rejected, not counted" <<  endl;

    ok = limiter.isAllowed(user, 7, maxReq, window);
     cout << "t=7:  " << (ok ? "ALLOWED" : "BLOCKED") << " <-- rejected, not counted" <<  endl;

    ok = limiter.isAllowed(user, 12, maxReq, window);
     cout << "t=12: " << (ok ? "ALLOWED" : "BLOCKED") << " <-- window slid" <<  endl;

     cout <<  endl << "=== Multiple Users ===" <<  endl;
    ok = limiter.isAllowed("bob", 0, maxReq, window);
     cout << "bob t=0: " << (ok ? "ALLOWED" : "BLOCKED") <<  endl;

    ok = limiter.isAllowed("bob", 1, maxReq, window);
     cout << "bob t=1: " << (ok ? "ALLOWED" : "BLOCKED") <<  endl;

    return 0;
}
