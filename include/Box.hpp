//
// Created by antonin on 11/11/21.
//

#ifndef FFP_TUM_BOX_H
#define FFP_TUM_BOX_H


class Box {
private:
    std::pair<unsigned int, unsigned int> size;
public:
    Box(unsigned int x);

    Box(unsigned int x, unsigned int y);

    void resize(unsigned int x, unsigned int y);

    std::pair<unsigned int, unsigned int> &getSize() const;

    unsigned int &getLength() const;

    unsigned int &getWidth() const;

    void setSize(const std::pair<unsigned int, unsigned int> &size);
};


#endif //FFP_TUM_BOX_H
