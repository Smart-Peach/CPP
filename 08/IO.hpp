#pragma once
#include <iostream>


class IO {
public:
    // IO() {};
    virtual ~IO() {};
    virtual bool is_source_open() = 0;
    // virtual bool is_eof(int pos);
    // virtual void close();
};

class Reader : public virtual IO {
public:
    // Reader() {};
    virtual ~Reader() {};
    
    // virtual bool is_source_open() override;

    // virtual bool is_eof(int pos) override;
    // virtual void close() override;

    // virtual char read_char();

    // virtual int read_int();
    // virtual double read_double();
    // virtual float read_float(); // ?????
    // virtual bool read_bool();
    // virtual std::string read_string();
};

class Writer : public virtual IO {
public:
    // Writer() {};
    virtual ~Writer() {};
    // virtual bool is_source_open() override;

    // virtual bool is_eof(int pos) override;
    // virtual void close() override;

    // virtual void write_char(char ch);

    // virtual void write_int(int i);
    // virtual void write_double(double d);
    // virtual void write_float(float f); // ?????
    // virtual void write_bool(bool b);
    // virtual void write_string(std::string string);
};

class ReaderWriter : public Reader, public Writer {
public:
    ReaderWriter() = default;
    virtual ~ReaderWriter() {};
    // virtual bool is_source_open() override;

    // virtual bool is_eof(int pos) override;
    // virtual void close() override;

    // virtual char read_char() override;
    // virtual int read_int() override;
    // virtual double read_double() override;
    // virtual float read_float() override; // ?????
    // virtual bool read_bool() override;
    // virtual std::string read_string() override;

    // virtual void write_char(char ch) override;
    // virtual void write_int(int i) override;
    // virtual void write_double(double d) override;
    // virtual void write_float(float f) override; // ?????
    // virtual void write_bool(bool b) override;
    // virtual void write_string(std::string string) override;
};