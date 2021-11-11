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

    const unsigned int &getWidth() const;

    const unsigned int &getHeight() const;

    const std::pair<unsigned int, unsigned int> &getSize() const;

    void setSize(const std::pair<unsigned int, unsigned int> &size);

    void setHeight(unsigned int &length);

    void setWidth(unsigned int &width);
};


#endif //FFP_TUM_BOX_H
