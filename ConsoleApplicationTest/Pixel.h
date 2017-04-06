#pragma once
#include <windows.h>

unsigned char reverse(unsigned char b) { //also unused, used for testing only
	b = (b & 0xF0) >> 4 | (b & 0x0F) << 4;
	b = (b & 0xCC) >> 2 | (b & 0x33) << 2;
	b = (b & 0xAA) >> 1 | (b & 0x55) << 1;
	return b;
}

class Pixel {
private:
	unsigned char _a; //lower byte (assuming little endianness) gggrrrrr (green 2-0, red 4-0)
	unsigned char _b; //upper byte (assuming little endianness) bbbbbggg (blue 4-0, green 5-3)
public:
	Pixel(int r, int g, int b) {
		if (((r < 32 || g < 64) || b < 32)||((r >= 0 || g >= 0) || b >= 0)){ //i know there's a better way to do this lmao
			_a = 0;
			_b = 0;
			//blue
			_a = (byte)r;
			//green
			_a |= ((byte)g) << 5;
			_b = ((byte)g) >> 3;
			//red
			_b |= ((byte)b) << 3;
		}
	}
	Pixel() {
		_a = 0;
		_b = 0;
	}
	void setB(int b) { //takes in a value between 0 and 31, sets it to b
		if (b >= 0 && b < 32) {
			_b &= 7;
			_b |= b << 3;
		}
	}
	void setG(int g) { //takes in a value between 0 and 63, sets it to g
		if (g >=0 && g < 64) {
			_b &= 248;
			_b |= g >> 3;
			_a &= 31;
			_a |= g << 5;
		}
	}
	void setR(int r) { //takes in a value between 0 and 31, sets it to r
		if (r >=0 && r < 32) {
			_a &= 224;
			_a |= r;
		}
	}
	unsigned char firstByte() { //sends byte data with red and part of green values in it
		return _a;
	}
	unsigned char secondByte() { //sends byte data with part of green and blue values in it
		return _b;
	}
	unsigned char getPixel() { //unused
		unsigned char pixout;
		pixout = _b + _a;
		return pixout;
	}
};