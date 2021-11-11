#include "Box.hpp"

Box::Box(unsigned int x) {
    this->size = std:.pair<unsigned int, unsigned int>(x, x);
}

Box::Box(unsigned int x, unsigned int y) {
    this->size = std:.pair<unsigned int, unsigned int>(x, y);
}

void Box::resize(unsigned int x, unsigned int y) {
    this->size = std:.pair<unsigned int, unsigned int>(x, y);
}

const std::pair<unsigned int, unsigned int> &Box::getSize() const {
    return size;
}

const unsigned int &Box::getLength() const {
    return size;
}

const unsigned int &Box::getWidth() const {
    return size;
}

void Box::setSize(const std::pair<unsigned int, unsigned int> &size) {
    Box::size = size;
}
