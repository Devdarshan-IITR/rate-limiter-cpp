# Rate Limiter Library (C++)

A lightweight, header-only rate limiting library in C++ that prevents
server overload by restricting how many requests a user can make
within a time window.

## How it works
- Uses the **sliding window algorithm** — stores each user's request
  timestamps in a deque and evicts entries older than the window.
- Each check runs in constant time per request (amortized).
- Per-user isolation via an unordered_map of user_id -&gt; deque.

## Usage
```cpp
#include "Devdarshan_IITR.hpp"

Devdarshan_IITR::RateLimiter limiter;
bool ok = limiter.isAllowed("alice", timestamp, maxRequests, windowSeconds);
```

## Run the demo
```bash
g++ basic_example.cpp -o basic_example
./basic_example
```

## Author
Devdarshan — IIT Roorkee
