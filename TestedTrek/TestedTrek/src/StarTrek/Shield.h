#ifndef SHIELD_H
#define SHIELD_H

namespace StarTrek
{
class Shield
{
public:
    Shield();

    bool isUp() { return m_status; }
    void raise() { m_status = true; }
    int getStrength() { return m_strength; }
    int transferIn(const int energy);

    static const int MAX_STRENGTH;
    static const int MIN_STRENGTH;

private:
    bool m_status{};
    int m_strength{};
};

} // StarTrek

#endif // SHIELD_H
