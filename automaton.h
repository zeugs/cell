class Automaton {
    virtual void initialize(int initMethod) = 0;
    virtual void evaluate() = 0;
    virtual bool shouldLive(int posX, int posY) = 0;
    virtual void render() = 0;
};
