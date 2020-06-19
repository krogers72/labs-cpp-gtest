#ifndef SHIELD_H
#define SHIELD_H

namespace StarTrek
{
class Shield
{
public:
    Shield(int start_energy = 0);

    bool isUp() { return m_status; }
    void raise() { m_status = true; }
    void lower() { m_status = false; }
    int getStrength() { return m_strength; }
    int transferIn(const int energy);
    int takeDamageAndReturnOverflow(const int damage);

    static const int MAX_STRENGTH;
    static const int MIN_STRENGTH;

private:
    bool m_status{};
    int m_strength{};
};

} // StarTrek

#endif // SHIELD_H
