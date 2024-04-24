// #include <iostream>
// #include <stdio.h>


// class FileReaderWriter: public ReaderWriter {
//     FILE* source;

//     FileReaderWriter(std::string src_name) {
//         source = fopen_s(src_name, "w+");
//     };

//     bool is_source_open() { // ????
//         return source != nullptr;
//     }

//     bool is_eof(int pos) {
//         return !feof(source);
//     }

//     void close() {
//         fclose(source);
//     }

//     void print_source() { std::cout << source << std::endl; }

//     void write_char(char ch) {
        
//     }

//     void write_int(int i) {

//     }

//     void write_double(double d) {

//     }

//     void write_float(float f) {

//     }

//     void write_bool(bool b) {

//     }

//     void write_string(std::string string) {

//     }
// }