#include <iostream>
#include <string>
#include <bitset>
#include <limits>
#include <vector>

using namespace std;
typedef vector<unsigned char> vu;

int encodeLen(unsigned int codepoint) {
    if (codepoint < 0x80) {
        return 1;
    } else if (codepoint < 0x800) {
        return 2;
    } else if (codepoint < 0xFFFF) {
        return 3;
    } else if (codepoint < 0x1FFFFF) {
        return 4;
    } else {
        return -1;
    }
}

void encode(unsigned int codepoint, vu &v) {
    int len = encodeLen(codepoint);
    int size = v.size();

    for (int i = 0; i < len; i++) {
        v.push_back(0);
    }
    unsigned char *ptr = &v[size];
    if (len == 1) {
        ptr[0] |= codepoint;
    } else if (len == 2) {
        ptr[0] |= 0xC0;
        ptr[1] |= 0x80;
        ptr[1] |= (codepoint & 0x3F);
        ptr[0] |= (codepoint >> 6) & (0x1F);
    } else if (len == 3) {
        ptr[0] |= 0xE0;
        ptr[1] |= 0x80;
        ptr[2] |= 0x80;
        ptr[2] |= (codepoint & 0x3F);
        ptr[1] |= ((codepoint >> 6) & (0x3F));
        ptr[0] |= ((codepoint >> 12) & (0x0F));
    } else if (len == 4) {
        ptr[0] |= 0xF0;
        ptr[1] |= 0x80;
        ptr[2] |= 0x80;
        ptr[3] |= 0x80;

        ptr[3] |= (codepoint &0x3F);
        ptr[2] |= (codepoint >> 6) & (0x3F);
        ptr[1] |= (codepoint >> 12) & (0x3F);
        ptr[0] |= (codepoint >> 18) & (0x05);
    }
    return;
}

int decodeLen(unsigned int c) {
    if ((c & 0xF8) == 0xF0) {
        return 4;
    } else if ((c & 0xF0) == 0xE0) {
        return 3;
    } else if ((c & 0xE0) == 0xC0) {
        return 2;
    } else if ((c & 0x80) == 0) {
        return 1;
    } else {
        cout << "Encoding is wrong " << endl;
        return -1;
    }
}

int decode(vu &v) {
    int idx = 0;
    char *ptr;
    int len;
    unsigned int result = 0;
    while (idx < v.size()) {
        unsigned char *ptr = &v[idx];
        len = decodeLen(ptr[0]);
        if (len <= 0) {
            cout << "Decoding wrong for byte " << (int) ptr[0] << endl;
            break;
        }
        result = 0;
        if (len == 1) {
            result |= ptr[0];
        } else if (len == 2) {
            result |= (ptr[0] & 0x1F);
        } else if (len == 3) {
            result |= (ptr[0] & 0x0F);
        } else if (len == 4) {
            result |= (ptr[0] & 0x07);
        }

        for (int i = 1; i < len; i++) {
            result = ((result << 6) | (ptr[i]&0x3F));
        }
        idx += len;
        cout << hex << result << "\t";
    }
    cout << endl;
}

int main() {
    unsigned int codepoint;
    bitset<32> tmp(codepoint);
    vu v;
    while (cin >> hex >> codepoint) {
        cout << "Length in unicode " << encodeLen(codepoint) << endl;
        encode(codepoint,v);
        for (int i = 0; i < v.size(); i++) {
            bitset<8> bits(v[i]);
            cout << bits << "\t";
        }
        cout << endl;
        for (int i = 0; i < v.size(); i++) {
            cout << hex << (int) v[i] << "\t";
        }
        cout << endl;
    }
    decode(v);
}
