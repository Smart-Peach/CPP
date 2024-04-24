#pragma once
#include <iostream>


class IO {
public:
    virtual ~IO() {};
    virtual bool is_source_open() = 0;
    virtual bool is_eof() = 0;
    virtual void close() = 0;
};

class Reader : public virtual IO {
public:
    virtual ~Reader() {};

    virtual char read_char() = 0;
    virtual int read_int() = 0;
    virtual double read_double() = 0;
    virtual float read_float() = 0;
    virtual bool read_bool() = 0;
    virtual std::string read_string() = 0;
};

class Writer : public virtual IO {
public:
    virtual ~Writer() {};

    virtual void write_char(char ch) = 0;

    virtual void write_int(int i) = 0;
    virtual void write_double(double d) = 0;
    virtual void write_float(float f) = 0;
    virtual void write_bool(bool b) = 0;
    virtual void write_string(std::string string) = 0;
};

class ReaderWriter : public Reader, public Writer {
public:
    ReaderWriter() = default;
    virtual ~ReaderWriter() {};
};