#ifndef FFP_TUM_BOX_H
#define FFP_TUM_BOX_H

constexpr unsigned ORIGIN_X = 400;
constexpr unsigned ORIGIN_Y = 50;

struct Box {
    unsigned x0;
    unsigned y0;
    unsigned x;
    unsigned y;

    Box(unsigned _x, unsigned _y) : x{_x}, y{_y} {
        x0 = ORIGIN_X;
        y0 = ORIGIN_Y;
    };
};


#endif //FFP_TUM_BOX_H