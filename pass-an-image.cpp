#include <iostream>
#include "brightener.h"
#include <memory>

int main() {
    auto image = std::make_unique<Image>(512, 512);
	std::cout << "Brightening a 512 x 512 image\n";
    ImageBrightener brightener(std::move(image));
    const int attenuatedCount = brightener.BrightenWholeImage();
    std::cout << "Attenuated " << attenuatedCount << " pixels\n";
}
