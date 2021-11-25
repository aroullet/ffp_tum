#ifndef FFP_TUM_VIRUS_H
#define FFP_TUM_VIRUS_H


class Virus {
private:
    float spreadProb;
    float radius;
    float recoveryProb;

public:
    Virus(float spread, float radius, float recovery) : spreadProb(spread), radius(radius), recoveryProb(recovery) {};
};


#endif //FFP_TUM_VIRUS_H
