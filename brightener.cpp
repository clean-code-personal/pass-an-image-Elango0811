#include "brightener.h"

ImageBrightener::ImageBrightener(std::unique_ptr<Image> inputImage) : m_inputImage(std::move(inputImage)) {
}

int ImageBrightener::BrightenWholeImage() {
	// For brightening, we add a certain grayscale (25) to every pixel.
	// While brightening, some pixels may cross the max brightness. They are
	// called 'attenuated' pixels
	int attenuatedPixelCount = 0;
	for (int x = 0; x < m_inputImage->rows; x++) {
		for (int y = 0; y < m_inputImage->columns; y++) {
			if (m_inputImage->pixels[x * m_inputImage->columns + y] > (255 - 25)) {
				++attenuatedPixelCount;
				// m_inputImage.pixels[x * m_inputImage.rows + 1 + y] = 255;
				m_inputImage->pixels[x * m_inputImage->columns + y] = 255;
			}
			else {
				// --attenuatedPixelCount;
				// m_inputImage.pixels[x * m_inputImage.columns + y] += 25;
				int pixelIndex = x * m_inputImage->columns + y;
				m_inputImage->pixels[pixelIndex] += 25;
				// m_inputImage.pixels[x * m_inputImage.rows + 1 + y] += 25;
			}
		}
	}
	return attenuatedPixelCount;
}

Image* ImageBrightener::GetImage() const {
	return m_inputImage.get();
}
