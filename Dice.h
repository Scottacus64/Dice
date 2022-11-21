class Dice
{
public:
    Dice();
    ~Dice();
    Dice(int numberOfSides);

    int roll(void);
    
    int m_numberOfSides;
}
;