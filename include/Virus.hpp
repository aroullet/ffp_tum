#ifndef FFP_TUM_VIRUS_H
#define FFP_TUM_VIRUS_H


class Virus {
private:
    float spreadProb;
    float radius;

public:
    Virus(float p, float r) : spreadProb(p), radius(r) {};
};


#endif //FFP_TUM_VIRUS_H
