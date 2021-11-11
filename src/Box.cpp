#include <iostream>
#include "Box.hpp"

Box::Box(unsigned int x) {
    this->size = std::pair<unsigned int, unsigned int>(x, x);
}

Box::Box(unsigned int x, unsigned int y) {
    this->size = std::pair<unsigned int, unsigned int>(x, y);
}

void Box::resize(unsigned int x, unsigned int y) {
    this->size = std::pair<unsigned int, unsigned int>(x, y);
}

const unsigned int &Box::getHeight() const{
    return size.second;
}

void Box::setHeight(unsigned int &length) {
    Box::size.second = length;
}

const unsigned int &Box::getWidth() const{
    return size.first;
}

void Box::setWidth(unsigned int &width) {
    Box::size.first = width;
}

void Box::setSize(const std::pair<unsigned int, unsigned int> &size) {
    Box::size = size;
}

const std::pair<unsigned int, unsigned int> &Box::getSize() const {
    return size;
}
