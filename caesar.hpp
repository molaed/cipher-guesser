#include <iostream>
#include <fstream>
#include <string>

#define CPP_ARYA_CAESAR_LIB_CONVERT

namespace arya{

	char text_cipher(const char c, unsigned int shift) {
	    if (c == '\n' || c == ' ' || c == '\"') { return c; }
	    int ascii_index = c;
	    return static_cast<char>((ascii_index + shift) % 127);
	}

	char cipher_text(const char c, unsigned int shift) {
	    if (c == '\n' || c == ' ' || c == '\"') { return c; }
	    int ascii_index = c;
	    return static_cast<char>((ascii_index + (127 - shift)) % 127);
	}

	void encode_line(std::string& src, unsigned int shift) {
	    for (char& c : src) {
		c = text_cipher(c, shift);
	    }
	}

	void decode_line(std::string& src, unsigned int shift) {
	    for (char& c : src) {
		c = cipher_text(c, shift);
	    }
	}

	unsigned int encode_to_file(const std::string& dest, const std::string& src, unsigned int shift) {
	    std::ifstream text(src);
	    std::ofstream cipher(dest);

	    if (!text.is_open() || !cipher.is_open()) { return 1; }

	    std::string read_text;
	    int counter = 0;

	    while (std::getline(text, read_text)) {
		if (read_text != "\n") {
		    encode_line(read_text, shift);
		    cipher << read_text << '\n';
		}
		counter++;
	    }

	    return counter;
	}

	unsigned int decode_to_file(const std::string& dest, const std::string& src, unsigned int shift) {
	    std::ifstream cipher(src);
	    std::ofstream text(dest);

	    if (!cipher.is_open() || !text.is_open()) { return 1; }

	    std::string read_cipher;
	    int counter = 0;

	    while (std::getline(cipher, read_cipher)) {
		if (read_cipher != "\n") {
		    decode_line(read_cipher, shift);
		    text << read_cipher << '\n';
		}
		counter++;
	    }

	    return counter;
	}

}
