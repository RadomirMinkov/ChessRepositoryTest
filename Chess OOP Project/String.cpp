#include "String.h"

void String::addString(const String& other) {
    if (size == capacity) {
        resize();
    }
    if (capacity - size >= other.size) {
        size_t temp = size;
        for (int i = 0; i < other.size; i++) {
            str[temp] = other.str[i];
            ++temp;
        }
        size = size + other.size;
        str[size] = '\0';
    }
    else {
        resize();
        addString(other);
    }
}

void String::copy(const String& other) {
    capacity = other.capacity;
    size = other.size;
    str = new char[capacity + 1];

    for (int i = 0; i < size; i++) {
        str[i] = other.str[i];
    }
    str[size] = '\0';
}

void String::resize() {
    capacity = capacity * 2;
    char* temp = new char[capacity + 1];
    for (int i = 0; i < size; i++) {
        temp[i] = str[i];
    }
    delete[] str;
    str = temp;
}

void String::destroy() {
    delete[] this->str;
    // this->str = nullptr;
}

String::String() :str(nullptr), size(0), capacity(8) {}

String::String(const String& other) {
    copy(other);
}

String& String::operator=(const String& other) {
    if (this != &other) {
        destroy();
        copy(other);
    }
    return *this;
}

String::~String() {
    destroy();
}

String::String(const char* str) {
    size = strlen(str);
    capacity = size * 2;
    str = new char[capacity + 1];
    strcpy_s(this->str, capacity + 1, str);
    this->str[size] = '\0';
}

size_t String::getLen() const {
    return size;
}

const bool String::isEmpty() const {
    return size == 0;
}

bool String::contains(String characterToFind) const
{
    bool result = false;
    for (int i = 0; i < characterToFind.size; i++) {
        if (str[i] == characterToFind[i]) {
            for (int j = i; j < characterToFind.size + i; j++) {
                if (str[j] != characterToFind[j - i]) break;
                if (characterToFind.size - 1 == j - i) {
                    result = true;
                    break;
                }
            }

        }
    }

    return result;

}

char String::operator[](const size_t index) const {

    if (index >= this->size) {
        exit(-1);
    }
    return this->str[index];
}

void String::appendCharacter(const char& characterToAppend) {
    if (size == capacity - 1) {
        resize();
    }
    str[size] = characterToAppend;
    ++size;
    str[size] = '\0';
}

void String::removeChar() {
    size--;
    str[size] = '\0';
}

String& String::operator+(const String& other) {
    addString(other);
    return*this;
}

String& String::operator+=(const String& other) {
    addString(other);
    return*this;
}

bool String::operator==(const String& other) {
    return strcmp(str, other.str) == 0 ? true : false;
}

std::ostream& operator<<(std::ostream& os, const String& string) {
    for (int i = 0;i < string.size;i++) {
        os << string.str[i];
    }
    return os;
}

std::istream& operator>>(std::istream& is, String& string) {
    char* buffer = new char[128];
    is.getline(buffer, 128);
    string = String(buffer);
    delete[] buffer;

    return is;
}