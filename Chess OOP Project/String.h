#pragma once
#include <iostream>
#include <cstring>
class String {

private:

    char* str;
    size_t size;
    size_t capacity;

    void addString(const String& other);
    void copy(const String& other);
    void resize();
    void destroy();

public:

    String();
    String(const String& other);
    String& operator=(const String& other);
    ~String();

    String(const char* str);

    size_t getLen() const;

    const bool isEmpty() const;
    bool contains(String characterToFind) const;
    void appendCharacter(const char& characterToAppend);
    void removeChar();

    String& operator+(const String& other);
    String& operator+=(const String& other);
    char operator[](const size_t) const;
    bool operator==(const String& other);

    friend std::ostream& operator<<(std::ostream& os, const String& string);
    friend std::istream& operator>>(std::istream& is, String& string);
};

