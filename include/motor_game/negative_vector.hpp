template<class T>

class negative_vector
{

public:

    negative_vector(int min, int max)
    : _zero_index(min)
    , _storage((max - min))
    {
        // assert min - max
    }

    T& operator[](int index)
    {
        assert(index >= lower_limit());
        assert(index <= upper_limit());
        return _storage[index - _zero_index];
    }

    T operator[](int index) const
    {
        assert(index >= lower_limit());
        assert(index <= upper_limit());
        return _storage[index - _zero_index];
    }

    int upper_limit() const {
        return _zero_index + int(_storage.size());
    }

    int lower_limit() const {
        return _zero_index;
    }

    unsigned int size() const {
        return upper_limit() - lower_limit();
    }

private:

    int _zero_index = 0;
    std::vector<T> _storage {};
};
