
template<class T>
class SimpleUniquePointer {
public:
    SimpleUniquePointer() = default;
    SimpleUniquePointer(const SimpleUniquePointer &) = delete;
    SimpleUniquePointer &operator=(const SimpleUniquePointer &) = delete;

    SimpleUniquePointer(SimpleUniquePointer &&otherPtr) noexcept
            : _pointer{otherPtr._pointer} {
        otherPtr._pointer = nullptr;
    }

    SimpleUniquePointer &operator=(SimpleUniquePointer &&otherPtr) noexcept {
        if (_pointer)
            delete _pointer;

        _pointer = otherPtr._pointer;
        otherPtr._pointer = nullptr;

        return *this;
    }

    SimpleUniquePointer(T *pointer) {
        _pointer = pointer;
    }

    ~SimpleUniquePointer() {
        if (_pointer)
            delete _pointer;
    }

    T* Get() {
        return _pointer;
    }

private:
    T *_pointer;
};
