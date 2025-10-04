#include "../../../include/Base/Crypto/SBox.h"

namespace MyBase {
    namespace Crypto {
        namespace SBox {
            char get(char c) {
                return get((unsigned char)c);
            }
            unsigned char get(unsigned char c) {
                switch (c>>4) {
                    case 0: {
                        switch (c & 0x0F) {
                            case 0: return 0x63;
                            case 1: return 0x7C;
                            case 2: return 0x77;
                            case 3: return 0x7B;
                            case 4: return 0xF2;
                            case 5: return 0x6B;
                            case 6: return 0x6F;
                            case 7: return 0xC5;
                            case 8: return 0x30;
                            case 9: return 0x01;
                            case 10: return 0x67;
                            case 11: return 0x2B;
                            case 12: return 0xFE;
                            case 13: return 0xD7;
                            case 14: return 0xAB;
                            default: return 0x76;
                        }
                    } break;
                    case 1: {
                        switch (c & 0x0F) {
                            case 0: return 0xCA;
                            case 1: return 0x82;
                            case 2: return 0xC9;
                            case 3: return 0x7D;
                            case 4: return 0xFA;
                            case 5: return 0x59;
                            case 6: return 0x47;
                            case 7: return 0xF0;
                            case 8: return 0xAD;
                            case 9: return 0xD4;
                            case 10: return 0xA2;
                            case 11: return 0xAF;
                            case 12: return 0x9C;
                            case 13: return 0xA4;
                            case 14: return 0x72;
                            default: return 0xC0;
                        }
                    } break;
                    case 2: {
                        switch (c & 0x0F) {
                            case 0: return 0xB7;
                            case 1: return 0xFD;
                            case 2: return 0x93;
                            case 3: return 0x26;
                            case 4: return 0x36;
                            case 5: return 0x3F;
                            case 6: return 0xF7;
                            case 7: return 0xCC;
                            case 8: return 0x34;
                            case 9: return 0xA5;
                            case 10: return 0xE5;
                            case 11: return 0xF1;
                            case 12: return 0x71;
                            case 13: return 0xD8;
                            case 14: return 0x31;
                            default: return 0x15;
                        }
                    } break;
                    case 3: {
                        switch (c & 0x0F) {
                            case 0: return 0x04;
                            case 1: return 0xC7;
                            case 2: return 0x23;
                            case 3: return 0xC3;
                            case 4: return 0x18;
                            case 5: return 0x96;
                            case 6: return 0x05;
                            case 7: return 0x9A;
                            case 8: return 0x07;
                            case 9: return 0x12;
                            case 10: return 0x80;
                            case 11: return 0xE2;
                            case 12: return 0xEB;
                            case 13: return 0x27;
                            case 14: return 0xB2;
                            default: return 0x75;
                        }
                    } break;
                    case 4: {
                        switch (c & 0x0F) {
                            case 0: return 0x09;
                            case 1: return 0x83;
                            case 2: return 0x2C;
                            case 3: return 0x1A;
                            case 4: return 0x1B;
                            case 5: return 0x6E;
                            case 6: return 0x5A;
                            case 7: return 0xA0;
                            case 8: return 0x52;
                            case 9: return 0x3B;
                            case 10: return 0xD6;
                            case 11: return 0xB3;
                            case 12: return 0x29;
                            case 13: return 0xE3;
                            case 14: return 0x2F;
                            default: return 0x84;
                        }
                    } break;
                    case 5: {
                        switch (c & 0x0F) {
                            case 0: return 0x53;
                            case 1: return 0xD1;
                            case 2: return 0x00;
                            case 3: return 0xED;
                            case 4: return 0x20;
                            case 5: return 0xFC;
                            case 6: return 0xB1;
                            case 7: return 0x5B;
                            case 8: return 0x6A;
                            case 9: return 0xCB;
                            case 10: return 0xBE;
                            case 11: return 0x39;
                            case 12: return 0x4A;
                            case 13: return 0x4C;
                            case 14: return 0x58;
                            default: return 0xCF;
                        }
                    } break;
                    case 6: {
                        switch (c & 0x0F) {
                            case 0: return 0xD0;
                            case 1: return 0xEF;
                            case 2: return 0xAA;
                            case 3: return 0xFB;
                            case 4: return 0x43;
                            case 5: return 0x4D;
                            case 6: return 0x33;
                            case 7: return 0x85;
                            case 8: return 0x45;
                            case 9: return 0xF9;
                            case 10: return 0x02;
                            case 11: return 0x7F;
                            case 12: return 0x50;
                            case 13: return 0x3C;
                            case 14: return 0x9F;
                            default: return 0xA8;
                        }
                    } break;
                    case 7: {
                        switch (c & 0x0F) {
                            case 0: return 0x51;
                            case 1: return 0xA3;
                            case 2: return 0x40;
                            case 3: return 0x8F;
                            case 4: return 0x92;
                            case 5: return 0x9D;
                            case 6: return 0x38;
                            case 7: return 0xF5;
                            case 8: return 0xBC;
                            case 9: return 0xB6;
                            case 10: return 0xDA;
                            case 11: return 0x21;
                            case 12: return 0x10;
                            case 13: return 0xFF;
                            case 14: return 0xF3;
                            default: return 0xD2;
                        }
                    } break;
                    case 8: {
                        switch (c & 0x0F) {
                            case 0: return 0xCD;
                            case 1: return 0x0C;
                            case 2: return 0x13;
                            case 3: return 0xEC;
                            case 4: return 0x5F;
                            case 5: return 0x97;
                            case 6: return 0x44;
                            case 7: return 0x17;
                            case 8: return 0xC4;
                            case 9: return 0xA7;
                            case 10: return 0x7E;
                            case 11: return 0x3D;
                            case 12: return 0x64;
                            case 13: return 0x5D;
                            case 14: return 0x19;
                            default: return 0x73;
                        }
                    } break;
                    case 9: {
                        switch (c & 0x0F) {
                            case 0: return 0x60;
                            case 1: return 0x81;
                            case 2: return 0x4F;
                            case 3: return 0xDC;
                            case 4: return 0x22;
                            case 5: return 0x2A;
                            case 6: return 0x90;
                            case 7: return 0x88;
                            case 8: return 0x46;
                            case 9: return 0xEE;
                            case 10: return 0xB8;
                            case 11: return 0x14;
                            case 12: return 0xDE;
                            case 13: return 0x5E;
                            case 14: return 0x0B;
                            default: return 0xDB;
                        }
                    } break;
                    case 10: {
                        switch (c & 0x0F) {
                            case 0: return 0xE0;
                            case 1: return 0x32;
                            case 2: return 0x3A;
                            case 3: return 0x0A;
                            case 4: return 0x49;
                            case 5: return 0x06;
                            case 6: return 0x24;
                            case 7: return 0x5C;
                            case 8: return 0xC2;
                            case 9: return 0xD3;
                            case 10: return 0xAC;
                            case 11: return 0x62;
                            case 12: return 0x91;
                            case 13: return 0x95;
                            case 14: return 0xE4;
                            default: return 0x79;
                        }
                    } break;
                    case 11: {
                        switch (c & 0x0F) {
                            case 0: return 0xE7;
                            case 1: return 0xC8;
                            case 2: return 0x37;
                            case 3: return 0x6D;
                            case 4: return 0x8D;
                            case 5: return 0xD5;
                            case 6: return 0x4E;
                            case 7: return 0xA9;
                            case 8: return 0x6C;
                            case 9: return 0x56;
                            case 10: return 0xF4;
                            case 11: return 0xEA;
                            case 12: return 0x65;
                            case 13: return 0x7A;
                            case 14: return 0xAE;
                            default: return 0x08;
                        }
                    } break;
                    case 12: {
                        switch (c & 0x0F) {
                            case 0: return 0xBA;
                            case 1: return 0x78;
                            case 2: return 0x25;
                            case 3: return 0x2E;
                            case 4: return 0x1C;
                            case 5: return 0xA6;
                            case 6: return 0xB4;
                            case 7: return 0xC6;
                            case 8: return 0xE8;
                            case 9: return 0xDD;
                            case 10: return 0x74;
                            case 11: return 0x1F;
                            case 12: return 0x4B;
                            case 13: return 0xBD;
                            case 14: return 0x8B;
                            default: return 0x8A;
                        }
                    } break;
                    case 13: {
                        switch (c & 0x0F) {
                            case 0: return 0x70;
                            case 1: return 0x3E;
                            case 2: return 0xB5;
                            case 3: return 0x66;
                            case 4: return 0x48;
                            case 5: return 0x03;
                            case 6: return 0xF6;
                            case 7: return 0x0E;
                            case 8: return 0x61;
                            case 9: return 0x35;
                            case 10: return 0x57;
                            case 11: return 0xB9;
                            case 12: return 0x86;
                            case 13: return 0xC1;
                            case 14: return 0x1D;
                            default: return 0x9E;
                        }
                    } break;
                    case 14: {
                        switch (c & 0x0F) {
                            case 0: return 0xE1;
                            case 1: return 0xF8;
                            case 2: return 0x98;
                            case 3: return 0x11;
                            case 4: return 0x69;
                            case 5: return 0xD9;
                            case 6: return 0x8E;
                            case 7: return 0x94;
                            case 8: return 0x9B;
                            case 9: return 0x1E;
                            case 10: return 0x87;
                            case 11: return 0xE9;
                            case 12: return 0xCE;
                            case 13: return 0x55;
                            case 14: return 0x28;
                            default: return 0xDF;
                        }
                    } break;
                    default: {
                        switch (c & 0x0F) {
                            case 0: return 0x8C;
                            case 1: return 0xA1;
                            case 2: return 0x89;
                            case 3: return 0x0D;
                            case 4: return 0xBF;
                            case 5: return 0xE6;
                            case 6: return 0x42;
                            case 7: return 0x68;
                            case 8: return 0x41;
                            case 9: return 0x99;
                            case 10: return 0x2D;
                            case 11: return 0x0F;
                            case 12: return 0xB0;
                            case 13: return 0x54;
                            case 14: return 0xBB;
                            default: return 0x16;
                        }
                    } break;
                }
            }
            unsigned char rev(unsigned char c) {
                switch (c >> 4) {
                    case 0: {
                        switch (c & 0x0f) {
                            case 0: return 0x52;
                            case 1: return 0x09;
                            case 2: return 0x6a;
                            case 3: return 0xd5;
                            case 4: return 0x30;
                            case 5: return 0x36;
                            case 6: return 0xa5;
                            case 7: return 0x38;
                            case 8: return 0xbf;
                            case 9: return 0x40;
                            case 10: return 0xa3;
                            case 11: return 0x9e;
                            case 12: return 0x81;
                            case 13: return 0xf3;
                            case 14: return 0xd7;
                            default: return 0xfb;
                        } 
                        }
                    case 1: {
                        switch (c & 0x0f) {
                            case 0: return 0x7c;
                            case 1: return 0xe3;
                            case 2: return 0x39;
                            case 3: return 0x82;
                            case 4: return 0x9b;
                            case 5: return 0x2f;
                            case 6: return 0xff;
                            case 7: return 0x87;
                            case 8: return 0x34;
                            case 9: return 0x8e;
                            case 10: return 0x43;
                            case 11: return 0x44;
                            case 12: return 0xc4;
                            case 13: return 0xde;
                            case 14: return 0xe9;
                            default: return 0xcb;
                        } 
                        }
                    case 2: {
                        switch (c & 0x0f) {
                            case 0: return 0x54;
                            case 1: return 0x7b;
                            case 2: return 0x94;
                            case 3: return 0x32;
                            case 4: return 0xa6;
                            case 5: return 0xc2;
                            case 6: return 0x23;
                            case 7: return 0x3d;
                            case 8: return 0xee;
                            case 9: return 0x4c;
                            case 10: return 0x95;
                            case 11: return 0x0b;
                            case 12: return 0x42;
                            case 13: return 0xfa;
                            case 14: return 0xc3;
                            default: return 0x4e;
                        } 
                        }
                    case 3: {
                        switch (c & 0x0f) {
                            case 0: return 0x08;
                            case 1: return 0x2e;
                            case 2: return 0xa1;
                            case 3: return 0x66;
                            case 4: return 0x28;
                            case 5: return 0xd9;
                            case 6: return 0x24;
                            case 7: return 0xb2;
                            case 8: return 0x76;
                            case 9: return 0x5b;
                            case 10: return 0xa2;
                            case 11: return 0x49;
                            case 12: return 0x6d;
                            case 13: return 0x8b;
                            case 14: return 0xd1;
                            default: return 0x25;
                        } 
                        }
                    case 4: {
                        switch (c & 0x0f) {
                            case 0: return 0x72;
                            case 1: return 0xf8;
                            case 2: return 0xf6;
                            case 3: return 0x64;
                            case 4: return 0x86;
                            case 5: return 0x68;
                            case 6: return 0x98;
                            case 7: return 0x16;
                            case 8: return 0xd4;
                            case 9: return 0xa4;
                            case 10: return 0x5c;
                            case 11: return 0xcc;
                            case 12: return 0x5d;
                            case 13: return 0x65;
                            case 14: return 0xb6;
                            default: return 0x92;
                        } 
                        }
                    case 5: {
                        switch (c & 0x0f) {
                            case 0: return 0x6c;
                            case 1: return 0x70;
                            case 2: return 0x48;
                            case 3: return 0x50;
                            case 4: return 0xfd;
                            case 5: return 0xed;
                            case 6: return 0xb9;
                            case 7: return 0xda;
                            case 8: return 0x5e;
                            case 9: return 0x15;
                            case 10: return 0x46;
                            case 11: return 0x57;
                            case 12: return 0xa7;
                            case 13: return 0x8d;
                            case 14: return 0x9d;
                            default: return 0x84;
                        } 
                        }
                    case 6: {
                        switch (c & 0x0f) {
                            case 0: return 0x90;
                            case 1: return 0xd8;
                            case 2: return 0xab;
                            case 3: return 0x00;
                            case 4: return 0x8c;
                            case 5: return 0xbc;
                            case 6: return 0xd3;
                            case 7: return 0x0a;
                            case 8: return 0xf7;
                            case 9: return 0xe4;
                            case 10: return 0x58;
                            case 11: return 0x05;
                            case 12: return 0xb8;
                            case 13: return 0xb3;
                            case 14: return 0x45;
                            default: return 0x06;
                        } 
                        }
                    case 7: {
                        switch (c & 0x0f) {
                            case 0: return 0xd0;
                            case 1: return 0x2c;
                            case 2: return 0x1e;
                            case 3: return 0x8f;
                            case 4: return 0xca;
                            case 5: return 0x3f;
                            case 6: return 0x0f;
                            case 7: return 0x02;
                            case 8: return 0xc1;
                            case 9: return 0xaf;
                            case 10: return 0xbd;
                            case 11: return 0x03;
                            case 12: return 0x01;
                            case 13: return 0x13;
                            case 14: return 0x8a;
                            default: return 0x6b;
                        } 
                        }
                    case 8: {
                        switch (c & 0x0f) {
                            case 0: return 0x3a;
                            case 1: return 0x91;
                            case 2: return 0x11;
                            case 3: return 0x41;
                            case 4: return 0x4f;
                            case 5: return 0x67;
                            case 6: return 0xdc;
                            case 7: return 0xea;
                            case 8: return 0x97;
                            case 9: return 0xf2;
                            case 10: return 0xcf;
                            case 11: return 0xce;
                            case 12: return 0xf0;
                            case 13: return 0xb4;
                            case 14: return 0xe6;
                            default: return 0x73;
                        } 
                        }
                    case 9: {
                        switch (c & 0x0f) {
                            case 0: return 0x96;
                            case 1: return 0xac;
                            case 2: return 0x74;
                            case 3: return 0x22;
                            case 4: return 0xe7;
                            case 5: return 0xad;
                            case 6: return 0x35;
                            case 7: return 0x85;
                            case 8: return 0xe2;
                            case 9: return 0xf9;
                            case 10: return 0x37;
                            case 11: return 0xe8;
                            case 12: return 0x1c;
                            case 13: return 0x75;
                            case 14: return 0xdf;
                            default: return 0x6e;
                        } 
                        }
                    case 10: {
                        switch (c & 0x0f) {
                            case 0: return 0x47;
                            case 1: return 0xf1;
                            case 2: return 0x1a;
                            case 3: return 0x71;
                            case 4: return 0x1d;
                            case 5: return 0x29;
                            case 6: return 0xc5;
                            case 7: return 0x89;
                            case 8: return 0x6f;
                            case 9: return 0xb7;
                            case 10: return 0x62;
                            case 11: return 0x0e;
                            case 12: return 0xaa;
                            case 13: return 0x18;
                            case 14: return 0xbe;
                            default: return 0x1b;
                        } 
                        }
                    case 11: {
                        switch (c & 0x0f) {
                            case 0: return 0xfc;
                            case 1: return 0x56;
                            case 2: return 0x3e;
                            case 3: return 0x4b;
                            case 4: return 0xc6;
                            case 5: return 0xd2;
                            case 6: return 0x79;
                            case 7: return 0x20;
                            case 8: return 0x9a;
                            case 9: return 0xdb;
                            case 10: return 0xc0;
                            case 11: return 0xfe;
                            case 12: return 0x78;
                            case 13: return 0xcd;
                            case 14: return 0x5a;
                            default: return 0xf4;
                        } 
                        }
                    case 12: {
                        switch (c & 0x0f) {
                            case 0: return 0x1f;
                            case 1: return 0xdd;
                            case 2: return 0xa8;
                            case 3: return 0x33;
                            case 4: return 0x88;
                            case 5: return 0x07;
                            case 6: return 0xc7;
                            case 7: return 0x31;
                            case 8: return 0xb1;
                            case 9: return 0x12;
                            case 10: return 0x10;
                            case 11: return 0x59;
                            case 12: return 0x27;
                            case 13: return 0x80;
                            case 14: return 0xec;
                            default: return 0x5f;
                        } 
                        }
                    case 13: {
                        switch (c & 0x0f) {
                            case 0: return 0x60;
                            case 1: return 0x51;
                            case 2: return 0x7f;
                            case 3: return 0xa9;
                            case 4: return 0x19;
                            case 5: return 0xb5;
                            case 6: return 0x4a;
                            case 7: return 0x0d;
                            case 8: return 0x2d;
                            case 9: return 0xe5;
                            case 10: return 0x7a;
                            case 11: return 0x9f;
                            case 12: return 0x93;
                            case 13: return 0xc9;
                            case 14: return 0x9c;
                            default: return 0xef;
                        } 
                        }
                    case 14: {
                        switch (c & 0x0f) {
                            case 0: return 0xa0;
                            case 1: return 0xe0;
                            case 2: return 0x3b;
                            case 3: return 0x4d;
                            case 4: return 0xae;
                            case 5: return 0x2a;
                            case 6: return 0xf5;
                            case 7: return 0xb0;
                            case 8: return 0xc8;
                            case 9: return 0xeb;
                            case 10: return 0xbb;
                            case 11: return 0x3c;
                            case 12: return 0x83;
                            case 13: return 0x53;
                            case 14: return 0x99;
                            default: return 0x61;
                        } 
                        }
                    default: {
                        switch (c & 0x0f) {
                            case 0: return 0x17;
                            case 1: return 0x2b;
                            case 2: return 0x04;
                            case 3: return 0x7e;
                            case 4: return 0xba;
                            case 5: return 0x77;
                            case 6: return 0xd6;
                            case 7: return 0x26;
                            case 8: return 0xe1;
                            case 9: return 0x69;
                            case 10: return 0x14;
                            case 11: return 0x63;
                            case 12: return 0x55;
                            case 13: return 0x21;
                            case 14: return 0x0c;
                            default: return 0x7d;
                        } 
                        }
                }
            }
            unsigned int get(const unsigned int& value) {
                unsigned int val = value;
                unsigned char* c = (unsigned char*)&val;
                c[0] = get(c[0]);
                c[1] = get(c[1]);
                c[2] = get(c[2]);
                c[3] = get(c[3]);
                return val;
            }
        }
    }
}