#include <cstddef>
#include <hstring.h>
#include <new>

struct Bucket {
    const static size_t dataSize { 4096 };
    byte data[dataSize];
};

struct Heap {
    void* Allocate(size_t bytes) {
        if (bytes > Bucket::dataSize)
            throw std::bad_alloc {};

        for (size_t i{}; i < _countHeapBuckets; ++i) {
            if (!_bucketsUsed[i])
            {
                _bucketsUsed[i] = true;
                return _buckets[i].data;
            }
        }

        throw std::bad_alloc {};
    }

    void Free(void* pointer) {
        for (size_t i {}; i < _countHeapBuckets; ++i) {
            if (_buckets[i].data == pointer)
                _bucketsUsed[i] = false;
        }
    }

private:
    static const size_t _countHeapBuckets {10};
    Bucket _buckets[_countHeapBuckets] {};
    bool _bucketsUsed[_countHeapBuckets] {};
};
