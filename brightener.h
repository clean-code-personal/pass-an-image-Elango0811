#pragma once
#include <cstdint>
#include <memory>

struct Image {
	int rows;
	int columns;
	uint8_t* pixels; // max 1k x 1k image

	Image(int rows, int columns) : rows(rows), columns(columns)
	{
		pixels = new uint8_t[rows * columns];
		memset(pixels, NULL, rows * columns);
	}

	Image() = delete;
};

class ImageBrightener {
private:
	std::unique_ptr<Image> m_inputImage;
public:
	ImageBrightener(std::unique_ptr<Image> inputImage);
	int BrightenWholeImage();
	Image* GetImage() const;
};
