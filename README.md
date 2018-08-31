# 自己实现的字符串类djstring

``` C++
class djstring
{
private:
        char* buff;

public:
        djstring();
        djstring(const char* str);
        djstring(const djstring& str);
        ~djstring();

        int size() const;
        bool empty() const;

        void clear();
        void append(const char* str);
        void insert(int index, const char* str);
        void remove(const char* str);
        void replace(const char* oldstr, const char* newstr);
        const char* c_str() const;
        int to_int() const;
        float to_float() const;

        djstring operator+(const djstring& str) const;
        djstring& operator=(const djstring& str);
        char operator[](int index);
        bool operator==(const djstring& str);
        bool operator!=(const djstring& str);
        bool operator>(const djstring& str);
};
```
